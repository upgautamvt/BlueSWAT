/** @file
 *  @brief CTS Service sample
 */

/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
The cts.c file implements a simple example of the Bluetooth Low Energy (BLE) Current Time Service (CTS) using the Zephyr RTOS. This service allows a BLE peripheral to expose the current time to a connected central device such as a phone or tablet. At the top of the file, several headers from Zephyr’s core, Bluetooth stack, and system utilities are included to provide the necessary types, macros, and functions.

The service uses two global static variables: ct, a 10-byte array that stores the current time information in a specific format defined by the Bluetooth CTS specification; and ct_update, a flag used to indicate whether the time value has been updated and needs to be notified to the client. The time format stored in ct includes fields for year, month, day, hour, minute, second, day of the week, fractions of a second, and an adjustment reason, making it compliant with the Bluetooth specification for the "Exact Time 256" structure.

The function read_ct allows a connected client to read the current time by copying data from ct into the response buffer using Zephyr's bt_gatt_attr_read. Meanwhile, write_ct permits a client to write new time data into the buffer. It validates the write by checking that the offset and length do not exceed the buffer’s size and sets the ct_update flag, which marks the time as changed and eligible for notification. There's also a function ct_ccc_cfg_changed that is meant to handle changes to the Client Characteristic Configuration descriptor (CCC), such as when a client enables or disables notifications, but in this code it's just a placeholder and does nothing yet.

The actual BLE service is defined with BT_GATT_SERVICE_DEFINE, which registers a primary CTS service and its associated characteristic. The characteristic supports read, write, and notify operations and is backed by the ct buffer. Additionally, a CCC descriptor is defined so clients can subscribe to notifications when the time value changes.

To populate the ct buffer, the function generate_current_time is used. It hardcodes a specific timestamp — year 2015, May 30th, 12:45:30 — along with day of the week, fractional seconds, and adjustment reason. This simulated time is set during initialization by the cts_init function.

The cts_notify function is used to send notifications to clients but only if the ct_update flag is set, which happens when the client writes new time data. After notifying, the flag is cleared. This ensures notifications are only sent when there’s actually a change to report. The notification itself is sent using Zephyr’s bt_gatt_notify, targeting the correct attribute inside the CTS service definition.

Overall, this file offers a minimal but complete implementation of a standard BLE service in Zephyr. While it uses a hardcoded time for simplicity, it correctly demonstrates how to define GATT services, characteristics, and descriptors; handle read/write requests; and push notifications to BLE clients. This structure can be extended by adding real-time clock integration or dynamically updating the time fields based on system state.
**/

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/printk.h>
#include <sys/byteorder.h>
#include <zephyr.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>

static u8_t ct[10];
static u8_t ct_update;

static void ct_ccc_cfg_changed(const struct bt_gatt_attr *attr, u16_t value)
{
	/* TODO: Handle value */
}

static ssize_t read_ct(struct bt_conn *conn, const struct bt_gatt_attr *attr,
		       void *buf, u16_t len, u16_t offset)
{
	const char *value = attr->user_data;

	return bt_gatt_attr_read(conn, attr, buf, len, offset, value,
				 sizeof(ct));
}

static ssize_t write_ct(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			const void *buf, u16_t len, u16_t offset,
			u8_t flags)
{
	u8_t *value = attr->user_data;

	if (offset + len > sizeof(ct)) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}

	memcpy(value + offset, buf, len);
	ct_update = 1U;

	return len;
}

/* Current Time Service Declaration */
BT_GATT_SERVICE_DEFINE(cts_cvs,
	BT_GATT_PRIMARY_SERVICE(BT_UUID_CTS),
	BT_GATT_CHARACTERISTIC(BT_UUID_CTS_CURRENT_TIME, BT_GATT_CHRC_READ |
			       BT_GATT_CHRC_NOTIFY | BT_GATT_CHRC_WRITE,
			       BT_GATT_PERM_READ | BT_GATT_PERM_WRITE,
			       read_ct, write_ct, ct),
	BT_GATT_CCC(ct_ccc_cfg_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
);

static void generate_current_time(u8_t *buf)
{
	u16_t year;

	/* 'Exact Time 256' contains 'Day Date Time' which contains
	 * 'Date Time' - characteristic contains fields for:
	 * year, month, day, hours, minutes and seconds.
	 */

	year = sys_cpu_to_le16(2015);
	memcpy(buf,  &year, 2); /* year */
	buf[2] = 5U; /* months starting from 1 */
	buf[3] = 30U; /* day */
	buf[4] = 12U; /* hours */
	buf[5] = 45U; /* minutes */
	buf[6] = 30U; /* seconds */

	/* 'Day of Week' part of 'Day Date Time' */
	buf[7] = 1U; /* day of week starting from 1 */

	/* 'Fractions 256 part of 'Exact Time 256' */
	buf[8] = 0U;

	/* Adjust reason */
	buf[9] = 0U; /* No update, change, etc */
}

void cts_init(void)
{
	/* Simulate current time for Current Time Service */
	generate_current_time(ct);
}

void cts_notify(void)
{	/* Current Time Service updates only when time is changed */
	if (!ct_update) {
		return;
	}

	ct_update = 0U;
	bt_gatt_notify(NULL, &cts_cvs.attrs[1], &ct, sizeof(ct));
}
