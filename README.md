# BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy

This repository contains the artifact for BlueSWAT, a Bluetooth security framework for IoT devices based on eBPF. For more information about BlueSWAT, please check out our paper "BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy" (To appear in CCS 2024).

## Table for Artifact Evaluation

0. Requirements.
1. Set up ZephyrOS and Nordic 52840 Development Kit.
2. Defense capability.
3. Memory consumption.
4. Runtime latency.
5. Power assess.

## 0. Requirements

Software
- Ubuntu 20.04 or WSL2.
- Segger JLINK.
- A mobile BLE app, e.g., nRF Connect, BLEscanner.

Hardware
- Nordic 52840 Development Kit.
- Nordic 52840 Dongle.
- A power assess tool, e.g., ChargerLAB POWER-Z KT002.

## 1. Environment Setup

BlueSWAT is tested under Ubuntu 20.04 on WSL2. This artifact contains implementation on two embedded OS with open-source BLE stacks, i.e., [ZephyrOS](https://zephyrproject.org/) and [MynewtOS](https://mynewt.apache.org/). This artifact is tested on the Nordic 52840 Development Kit.

To flash USB device from WSL2, please install [usbipd](https://learn.microsoft.com/en-us/windows/wsl/connect-usb). Besides, Install the [Segger JLINK Software and documentation pack](https://www.segger.com/downloads/jlink/). 

Download the source code and required submodules of MynewtOS:
```
git clone --recursive https://github.com/RayCxggg/BlueSWAT-Artifact.git
```

In a Windows shell, connect the board and attach it to WSL2:
```
usbipd list 
usbipd bind --busid <busid>
usbipd attach --wsl --busid <busid>
```

### Set up Zephyr BLE stack

Please follow STEP ONE and TWO in the [doc](https://docs.zephyrproject.org/2.2.0/getting_started/index.html) to install dependencies.

Install needed Python packages:
```
pip3 install --user -r ~/BlueSWAT/ZephyrOS/zephyr/scripts/requirements.txt
```

Install Zephyr Software Development Toolchain:
```
cd ~
wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.11.2/zephyr-sdk-0.11.2-setup.run
chmod +x zephyr-sdk-0.11.2-setup.run
./zephyr-sdk-0.11.2-setup.run -- -d ~/SDK/zephyr-sdk-0.11.2
rm zephyr-sdk-0.11.2-setup.run
```

Clone required remote repositories:
```
cd BlueSWAT/ZephyrOS/zephyr
west update
```

Set build environment variables:
```
cd BlueSWAT/ZephyrOS/zephyr
source zephyr-env.sh
```

BlueSWAT is added a subsystem of the kernel and locates at `ZephyrOS/zephyr/firewall`.

### Build and Flash

Now, we build the BLE peripheral application for Nordic 52840 DK:
```
cd BlueSWAT/ZephyrOS
source scripts/config.sh
source scripts/build.sh
```

Everything is settled! Flash the board:
```
source scripts/flash.sh
```

After flashing the firmware, press the RESET button on the board and you should find an advertising BLE device called "Zephyr Peripheral Sample Long Name".

### Monitor

You can use minicom to monitor the output:
```
sudo minicom -D /dev/ttyACM0
```

## 2. Defense capability 

### Adversary

We use the nRF52840 dongle as the adversary. Follow [SweynTooth](https://github.com/Matheus-Garbelini/sweyntooth_bluetooth_low_energy_attack) to install the firmware. 

### Victim

We integrat BlueSWAT with Zephyr and use the nRF52840 DK as the victim device.

BlueSWAT inspection rules are at `ZephyrOS/zephyr/firewall/policy/ebpf_C_code`. To compile them into eBPF programs, e.g., to compile `conn_chan_map.ebpf.c`, run `./compile.sh conn_chan_map`. We have provided some eBPF transition rules at `ZephyrOS/zephyr/firewall/policy/ebpf_bytecode`.

1. Test the vulnerability without BlueSWAT. 

After flash the ZephyrOS to the board, use SweynTooth *Invalid Channel Map* to launch the attack. 

The *Invalid Channel Map* attack will trigger a kernel panic and crash the device.

2. Load the defense rules into BlueSWAT and relaunch the attacks. 

In `ZephyrOS/zephyr/firewall/policy/include/fsm_policy_cache.h`, add 
```
enum fsm_policy_tag {
	PID_conn_chan_map,

	// FSM policy num
	PID_NUM,
};
```

In `ZephyrOS/zephyr/firewall/policy/src/fsm_policy_cache.c`, add
```
#include "ebpf_bytecode/conn_chan_map.h"

void load_all_policies()
{
	ADD_POLICY(conn_chan_map, CONN, CHANNEL_MAP);
}
```

Recompile the firmware and flash the nRF52840 DK board. Then, relaunch the attack with the dongle and the victim device should successfully mitigate the attack.

## 3. Memory consumption

Remove the above rules and compile the firmware, you should see the firmware size at the end of the compilation. Then, add ten rules
```
// ZephyrOS/zephyr/firewall/policy/include/fsm_policy_cache.h
enum fsm_policy_tag {
	PID_conn_chan_map,
	PID_conn_chan_hop,
	PID_ebpf_helper_test,
	PID_dc_nesn,
	PID_spi_acl_len,
	PID_spi_evt_len,
	PID_scan_rsp_len,
	PID_llcp_len_req,
	PID_llcp_conn_param_req,
	PID_lll_interval,

	// FSM policy num
	PID_NUM,
};

// ZephyrOS/zephyr/firewall/policy/src/fsm_policy_cache.c:
#include "ebpf_bytecode/conn_chan_map.h"
#include "ebpf_bytecode/conn_chan_hop.h"
#include "ebpf_bytecode/dc_nesn.h"
#include "ebpf_bytecode/spi_evt_len.h"
#include "ebpf_bytecode/spi_acl_len.h"
#include "ebpf_bytecode/scan_rsp_len.h"
#include "ebpf_bytecode/llcp_len_req.h"
#include "ebpf_bytecode/llcp_conn_param_req.h"
#include "ebpf_bytecode/lll_interval.h"
#include "ebpf_bytecode/smp_ident_check.h"

void load_all_policies()
{
	ADD_POLICY(conn_chan_map, CONN, CHANNEL_MAP);
	ADD_POLICY(conn_chan_hop, CONN, CHANNEL_HOP);
	ADD_POLICY(dc_nesn, DC, NESN);
	ADD_POLICY(spi_acl_len, SPI, HCI_ACL_LEN);
	ADD_POLICY(spi_evt_len, SPI, HCI_EVT_LEN);
	ADD_POLICY(scan_rsp_len, CONN, SCAN_RSP_LEN);
	ADD_POLICY(llcp_len_req, DC, LLCP_LEN_REQ);
	ADD_POLICY(llcp_conn_param_req, DC, LLCP_CONN_PARAM_REQ);
	ADD_POLICY(lll_interval, CONN, LLL_INTERVAL);
	ADD_POLICY(smp_ident_check, DC, SMP_KEYS);
}
```

Recompile the firmware and check the size of ten eBPF programs.

## 4. Runtime latency

Our artifact provides two BLE applications, which are *Battery Level Service (BAS)* and *Heart Rate Service (HRS)*.

Mobile BLE apps can connect to our device and access these applications. The evaluation process is similar to the above:

1. Load no rules and activate the HRS for 100 rounds. Record the time comsumption.
2. Load one and ten rules and activate the HRS for 100 rounds. Record the time comsumption.
3. Calculate the runtime latency introduced by BlueSWAT.

## 5. Power assess.

We access the power and energy performance of BlueSWAT over a 120-second window, encompassing four phases: 20s of connection, 40s of BAS, another 20s of connection, and 40s of HRS.

ChargerLAB POWER-Z KT002 can record the Voltage, Current, and Power values during the testing window, and we can compare the power increase introduced by BlueSWAT with baseline.