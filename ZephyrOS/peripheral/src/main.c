/* main.c - Application main entry point */

/*
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/printk.h>
#include <sys/byteorder.h>
#include <zephyr.h>

#include <settings/settings.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>
#include <bluetooth/services/bas.h>
#include <bluetooth/services/hrs.h>

#include "cts.h"

// IFW below
#include "fsm_handle.h"
// #include "fsm_test.h"
// IFW above

/*
They generated these UUID as
(venv) upgautam@amd:~/Downloads/BlueSWAT-Artifact$ python
Python 3.12.3 (main, Jun 18 2025, 17:59:45) [GCC 13.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import uuid;
>>> print(uuid.uuid4())
ef785d4d-b961-4810-af5e-a5d5ac2a24b0

And then for other two UUIDs, they didn't generate they only change the second value (see 0/1/2)
This is not globally unique but okay for local development/testing

vnd_uuid:     f0debc9a-7856-3412-7856-341278563412
vnd_enc_uuid: f1debc9a-7856-3412-7856-341278563412
vnd_auth_uuid:f2debc9a-7856-3412-7856-341278563412

*/

/* Custom Service Variables */
//these variables are used in BT GATT Service object
static struct bt_uuid_128 vnd_uuid = BT_UUID_INIT_128(
    0xf0, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
    0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);

static struct bt_uuid_128 vnd_enc_uuid = BT_UUID_INIT_128(
    0xf1, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
    0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);

static struct bt_uuid_128 vnd_auth_uuid = BT_UUID_INIT_128(
    0xf2, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
    0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);

//[0x56, 0x65, 0x6E, 0x64, 0x6F, 0x72]. This vnd_value array is used in BT GATT Characteristic object
static u8_t vnd_value[] = {'V', 'e', 'n', 'd', 'o', 'r'};

//used to read attr value up to length offset and paste it into buf up to length len
// conn is not used here.
static ssize_t read_vnd(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                        void *buf, u16_t len, u16_t offset)
{
    const char *value = attr->user_data;

    return bt_gatt_attr_read(conn, attr, buf, len, offset, value,
                             strlen(value));
}

static ssize_t write_vnd(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                         const void *buf, u16_t len, u16_t offset,
                         u8_t flags)
{
    u8_t *value = attr->user_data;

    //vnd_value is the large storage buffer that is filled by several write_vnd()
    //value here means the address because this is pointer.
    //offset starts from value, writes up to value+len, in next write, it writes from value+offset upto value+offset+len
    if (offset + len > sizeof(vnd_value))
    {
        return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
    }

    memcpy(value + offset, buf, len);

    return len;
}

static u8_t simulate_vnd; //true/false flag
static u8_t indicating; //true/false flag
static struct bt_gatt_indicate_params ind_params;

//this is a callback when Client Characteristics Configuration (CCC) values change
// Called when client enables/disables indications; sets flag to start/stop indication simulation
// simulate_vnd = 1 means indications enabled, 0 means disabled
static void vnd_ccc_cfg_changed(const struct bt_gatt_attr *attr, u16_t value)
{
    simulate_vnd = (value == BT_GATT_CCC_INDICATE) ? 1 : 0;
}

// Callback called when a GATT indication is confirmed by the client or fails
// Prints success/fail message and clears the 'indicating' flag to allow next indication

// This function is passed to bt_gatt_indicate() and invoked when the BLE client acknowledges (or rejects) the indication.
// Setting indicating = 0U marks that the indication is done, so your code can send another one.

//Indication is a way for a BLE server (like your device) to send reliable, confirmed asynchronous messages to a connected client.
//Unlike notifications, which are unacknowledged and "fire-and-forget," indications require the client to acknowledge receipt.
static void indicate_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                        u8_t err)
{
    printk("Indication %s\n", err != 0U ? "fail" : "success");
    indicating = 0U;
}


//reading large logic
#define MAX_DATA 74
static u8_t vnd_long_value[] = {
    'V', 'e', 'n', 'd', 'o', 'r', ' ', 'd', 'a', 't', 'a', '1',
    'V', 'e', 'n', 'd', 'o', 'r', ' ', 'd', 'a', 't', 'a', '2',
    'V', 'e', 'n', 'd', 'o', 'r', ' ', 'd', 'a', 't', 'a', '3',
    'V', 'e', 'n', 'd', 'o', 'r', ' ', 'd', 'a', 't', 'a', '4',
    'V', 'e', 'n', 'd', 'o', 'r', ' ', 'd', 'a', 't', 'a', '5',
    'V', 'e', 'n', 'd', 'o', 'r', ' ', 'd', 'a', 't', 'a', '6',
    '.', ' '};

static ssize_t read_long_vnd(struct bt_conn *conn,
                             const struct bt_gatt_attr *attr, void *buf,
                             u16_t len, u16_t offset)
{
    const char *value = attr->user_data;

    return bt_gatt_attr_read(conn, attr, buf, len, offset, value,
                             sizeof(vnd_long_value));
}

static ssize_t write_long_vnd(struct bt_conn *conn,
                              const struct bt_gatt_attr *attr, const void *buf,
                              u16_t len, u16_t offset, u8_t flags)
{
    u8_t *value = attr->user_data;

    if (flags & BT_GATT_WRITE_FLAG_PREPARE)
    {
        return 0;
    }

    if (offset + len > sizeof(vnd_long_value))
    {
        return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
    }

    memcpy(value + offset, buf, len);

    return len;
}

static const struct bt_uuid_128 vnd_long_uuid = BT_UUID_INIT_128(
    0xf3, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
    0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);

static struct bt_gatt_cep vnd_long_cep = {
    .properties = BT_GATT_CEP_RELIABLE_WRITE,
};

static int signed_value;

static ssize_t read_signed(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                           void *buf, u16_t len, u16_t offset)
{
    const char *value = attr->user_data;

    return bt_gatt_attr_read(conn, attr, buf, len, offset, value,
                             sizeof(signed_value));
}

static ssize_t write_signed(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                            const void *buf, u16_t len, u16_t offset,
                            u8_t flags)
{
    u8_t *value = attr->user_data;

    if (offset + len > sizeof(signed_value))
    {
        return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
    }

    memcpy(value + offset, buf, len);

    return len;
}

static const struct bt_uuid_128 vnd_signed_uuid = BT_UUID_INIT_128(
    0xf3, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x13,
    0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x13);

static const struct bt_uuid_128 vnd_write_cmd_uuid = BT_UUID_INIT_128(
    0xf4, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
    0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12);

static ssize_t write_without_rsp_vnd(struct bt_conn *conn,
                                     const struct bt_gatt_attr *attr,
                                     const void *buf, u16_t len, u16_t offset,
                                     u8_t flags)
{
    u8_t *value = attr->user_data;

    /* Write request received. Reject it since this char only accepts
     * Write Commands.
     */
    if (!(flags & BT_GATT_WRITE_FLAG_CMD))
    {
        return BT_GATT_ERR(BT_ATT_ERR_WRITE_REQ_REJECTED);
    }

    if (offset + len > sizeof(vnd_value))
    {
        return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
    }

    memcpy(value + offset, buf, len);

    return len;
}

//large value logic finished

/* Vendor Primary Service Declaration */
/*
 This snippet defines a complete custom Bluetooth Low Energy (BLE) service using Zephyr’s GATT API macros. It creates a Vendor Primary Service identified by a custom 128-bit UUID (vnd_uuid). Inside this service, multiple characteristics are declared — each representing a piece of data or functionality exposed to connected BLE clients.

Each characteristic has its own UUID and supports different operations like read, write, indicate,
 or write without response, and each enforces specific security permissions such as encryption or
authentication for accessing or modifying the data. For example, one characteristic supports encrypted
read/write with indication capability, allowing the server to notify clients reliably; another supports
long writes with extended properties, which handle large data transfers in chunks. The service also includes
CCC (Client Characteristic Configuration) descriptors,
which let clients enable or disable notifications or indications dynamically.
*/
BT_GATT_SERVICE_DEFINE(vnd_svc,
                       BT_GATT_PRIMARY_SERVICE(&vnd_uuid),
                       BT_GATT_CHARACTERISTIC(&vnd_enc_uuid.uuid,
                                              BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE |
                                                  BT_GATT_CHRC_INDICATE,
                                              BT_GATT_PERM_READ_ENCRYPT |
                                                  BT_GATT_PERM_WRITE_ENCRYPT,
                                              read_vnd, write_vnd, vnd_value),
                       BT_GATT_CCC(vnd_ccc_cfg_changed,
                                   BT_GATT_PERM_READ | BT_GATT_PERM_WRITE_ENCRYPT),
                       BT_GATT_CHARACTERISTIC(&vnd_auth_uuid.uuid,
                                              BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
                                              BT_GATT_PERM_READ_AUTHEN |
                                                  BT_GATT_PERM_WRITE_AUTHEN,
                                              read_vnd, write_vnd, vnd_value),
                       BT_GATT_CHARACTERISTIC(&vnd_long_uuid.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE | BT_GATT_CHRC_EXT_PROP,
                                              BT_GATT_PERM_READ | BT_GATT_PERM_WRITE |
                                                  BT_GATT_PERM_PREPARE_WRITE,
                                              read_long_vnd, write_long_vnd, &vnd_long_value),
                       BT_GATT_CEP(&vnd_long_cep),
                       BT_GATT_CHARACTERISTIC(&vnd_signed_uuid.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE | BT_GATT_CHRC_AUTH,
                                              BT_GATT_PERM_READ | BT_GATT_PERM_WRITE,
                                              read_signed, write_signed, &signed_value),
                       BT_GATT_CHARACTERISTIC(&vnd_write_cmd_uuid.uuid,
                                              BT_GATT_CHRC_WRITE_WITHOUT_RESP,
                                              BT_GATT_PERM_WRITE, NULL,
                                              write_without_rsp_vnd, &vnd_value), );



/*
This code snippet defines a Bluetooth Low Energy (BLE) advertising data array named ad[], which specifies
information broadcasted by the device to nearby scanners. The first entry sets the advertising flags,
indicating that the device is in general discoverable mode and does not support classic Bluetooth (BR/EDR),
signaling it is a BLE-only device. The second entry advertises a list of standard 16-bit service UUIDs,
representing common BLE services such as heart rate and battery services, which helps clients identify
the device’s capabilities quickly. The third entry includes a custom 128-bit service UUID, indicating
that the device offers a vendor-specific service beyond the standard profiles. Together, this advertising data
allows other BLE-enabled devices or applications to discover and recognize
the device’s supported services and its BLE-only nature before establishing a connection.
*/
static const struct bt_data ad[] = {
    BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
    BT_DATA_BYTES(BT_DATA_UUID16_ALL,
                  0x0d, 0x18, 0x0f, 0x18, 0x05, 0x18),
    BT_DATA_BYTES(BT_DATA_UUID128_ALL,
                  0xf0, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12,
                  0x78, 0x56, 0x34, 0x12, 0x78, 0x56, 0x34, 0x12),
};

/*
This function connected is a callback that runs when a Bluetooth connection attempt completes. It receives a connection
object and an error code. If err is nonzero, it means the connection failed, so it prints an error message
with the error code. Otherwise, if err is zero, it indicates a successful connection, and the function prints
 "Connected". Essentially, it notifies whether the BLE device successfully connected or encountered an error
during the connection process.
*/
static void connected(struct bt_conn *conn, u8_t err)
{
    if (err)
    {
        printk("Connection failed (err 0x%02x)\n", err);
    }
    else
    {
        printk("Connected\n");
    }
}

static void disconnected(struct bt_conn *conn, u8_t reason)
{
    printk("Disconnected (reason 0x%02x)\n", reason);
}

static struct bt_conn_cb conn_callbacks = {
    .connected = connected,
    .disconnected = disconnected,
};

static void bt_ready(void)
{
    int err;

    cts_init();

    if (IS_ENABLED(CONFIG_SETTINGS))
    {
        settings_load();
    }

    err = bt_le_adv_start(BT_LE_ADV_CONN_NAME, ad, ARRAY_SIZE(ad), NULL, 0);

    if (err)
    {
        printk("Advertising failed to start (err %d)\n", err);
        return;
    }

    printk("(DEBUG_LOG) Advertising successfully started\n");
}

static void auth_passkey_display(struct bt_conn *conn, unsigned int passkey)
{
    char addr[BT_ADDR_LE_STR_LEN];

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    printk("Passkey for %s: %06u\n", addr, passkey);
}

static void auth_cancel(struct bt_conn *conn)
{
    char addr[BT_ADDR_LE_STR_LEN];

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    printk("Pairing cancelled: %s\n", addr);
}

static struct bt_conn_auth_cb auth_cb_display = {
    .passkey_display = auth_passkey_display,
    .passkey_entry = NULL,
    .cancel = auth_cancel,
};

//battery service related -- this is a type of BLE GATT service
static void bas_notify(void)
{
    u8_t battery_level = bt_gatt_bas_get_battery_level();

    battery_level--;

    if (!battery_level)
    {
        battery_level = 100U;
    }

    bt_gatt_bas_set_battery_level(battery_level);
}

//heart rate related  -- this is a type of BLE GATT service
static void hrs_notify(void)
{
    static u8_t heartrate = 90U;

    /* Heartrate measurements simulation */
    heartrate++;
    if (heartrate == 160U)
    {
        heartrate = 90U;
    }

    bt_gatt_hrs_notify(heartrate);
}

void main(void)
{
    int err;

    // LL init here
    //entry point to initialize zephyr bluetooth subsystem (i.e., controller+host stacks)
    err = bt_enable(NULL); //init

    // BlueSWAT: IFW below
    // BlueSWAT:  enable IoT firewall Finite State Machine
    //Look here: /home/upgautam/Downloads/BlueSWAT-Artifact/ZephyrOS/zephyr/firewall/core
/*
# eBPF Firewall Library

This directory contains eBPF programs and tools of BleFSM.

## eBPF library

IoTFirewallCore/ZephyrOS/zephyr/firewall/libebpf/ebpf-src

## eBPF C source code

IoTFirewallCore/ZephyrOS/zephyr/firewall/policy/ebpf_code

## eBPF bytecode

IoTFirewallCore/ZephyrOS/zephyr/firewall/policy/include

## Build

Run the following command to build eBPF C program:

```
# IoTFirewallCore/ZephyrOS/zephyr/firewall/policy
$ ./compile.sh cve_2020_10069
```

The generated bytecode will be written to C head files in policy/include. The script is tested under WSL, so don't forget to set line termination characters to LF.

## Reference

https://github.com/uw-unsat/jitterbug
*/
    ifw_fsm_enable(JIT_OFF);

    // run test
    // test_local_conn_chan_hop();
    // test_all_mem();
    // test_runtime_overhead();
    // IFW above

    if (err)
    {
        printk("Bluetooth init failed (err %d)\n", err);
        return;
    }

    printk("Bluetooth init Here\n");

    //Logic after init is done
    //Logic can include starting advertising, logging, setting up GATT services etc.
    bt_ready();

    //registers connection and authentication related callbacks
    bt_conn_cb_register(&conn_callbacks);
    bt_conn_auth_cb_register(&auth_cb_display);

    /* Implement notification. At the moment there is no suitable way
     * of starting delayed work so we do it here
     */

    /*
	This main loop periodically send GATT notifications and indications for various simulated BLE services.

	*/
    while (1)
    {
        k_sleep(MSEC_PER_SEC);

        /* Current Time Service updates only when time is changed */
        cts_notify(); //Current Time Service

        /* Heartrate measurements simulation */
        hrs_notify(); // Heart Rate Service

        /* Battery level simulation */
        bas_notify(); // Battery Service

        /* Vendor indication simulation */
        // after client enables indication, this simulate_vnd is turned on (i.e., true or 1)
        if (simulate_vnd) //if(1) means true in C
        {
            if (indicating)
            {
                continue;
            }

            ind_params.attr = &vnd_svc.attrs[2];
            ind_params.func = indicate_cb;
            ind_params.data = &indicating;
            ind_params.len = sizeof(indicating);

            if (bt_gatt_indicate(NULL, &ind_params) == 0)
            {
                indicating = 1U;
            }
        }
    }
}
