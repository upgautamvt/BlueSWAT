# Lines added by author
# BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy
If you are interested in using our works for academic research, please cite the paper:

keywords = {EBPF, bluetooth low energy, cross-platform defense, state-aware security},
This repository contains the artifact for BlueSWAT, a Bluetooth security framework for IoT devices based on eBPF. For more information about BlueSWAT, please consult our paper "BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy" (To appear in CCS 2024).
@article{che2024blueswat,
  title={BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy},
  author={Che, Xijia and He, Yi and Feng, Xuewei and Sun, Kun and Xu, Ke and Li, Qi},
  journal={arXiv preprint arXiv:2405.17987},
  year={2024}
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
- *Victim*: Nordic 52840 Development Kit.
- *Attacker*: Nordic 52840 Dongle.
- A power assess tool, e.g., ChargerLAB POWER-Z KT002.

## 1. Environment Setup

BlueSWAT is tested under Ubuntu 20.04 on WSL2. This artifact contains implementation on two embedded OS with open-source BLE stacks, i.e., [ZephyrOS](https://zephyrproject.org/) and [MynewtOS](https://mynewt.apache.org/). For artifact evaluation, we introduce the testing procedure for ZephyrOS.

To flash USB device from WSL2, please install [usbipd](https://learn.microsoft.com/en-us/windows/wsl/connect-usb). Besides, install the [Segger JLINK Software and documentation pack](https://www.segger.com/downloads/jlink/). 

Download the source code:
git clone https://github.com/RayCxggg/BlueSWAT.git
### Set up Zephyr BLE stack
Install required Python packages:
BlueSWAT is added a subsystem of the kernel and locates at `ZephyrOS/zephyr/firewall`.

After flashing the firmware, press the RESET button on the board and you should find an advertising BLE device called "Zephyr Peripheral Sample Long Name".

You can use minicom to monitor the output in WSL:
## 2. Defense capability 
### Adversary
We use the nRF52840 dongle as the adversary. Follow [SweynTooth](https://github.com/Matheus-Garbelini/sweyntooth_bluetooth_low_energy_attack) to install the firmware. 
### Victim
We integrate BlueSWAT with ZephyrOS and use the nRF52840 DK as the victim device.
BlueSWAT inspection rules are at `ZephyrOS/zephyr/firewall/policy/ebpf_C_code`. To compile them into eBPF programs, e.g., to compile `conn_chan_map.ebpf.c`, run `./compile.sh conn_chan_map`. We have provided some compiled eBPF transition rules at `ZephyrOS/zephyr/firewall/policy/ebpf_bytecode`.
1. Test the vulnerability without BlueSWAT. 
After flash the ZephyrOS to the board, use SweynTooth *Invalid Channel Map* to launch the attack. 

The *Invalid Channel Map* attack will trigger a kernel panic and crash the device.
2. Load the defense rules into BlueSWAT and relaunch the attacks. 
In `ZephyrOS/zephyr/firewall/policy/include/fsm_policy_cache.h`, add 
enum fsm_policy_tag {
	PID_conn_chan_map,

	// FSM policy num
	PID_NUM,
};
In `ZephyrOS/zephyr/firewall/policy/src/fsm_policy_cache.c`, add
```
#include "ebpf_bytecode/conn_chan_map.h"
void load_all_policies()
{
	ADD_POLICY(conn_chan_map, CONN, CHANNEL_MAP);
}

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
Recompile the firmware and check the size of ten eBPF programs.
## 4. Runtime latency
Our artifact provides two BLE applications, which are *Battery Level Service (BAS)* and *Heart Rate Service (HRS)*.

Mobile BLE apps can connect to our device and access these applications. The evaluation process is similar to the above:

1. Load no rules and activate the HRS for 100 rounds. Record the time comsumption.
2. Load one and ten rules and activate the HRS for 100 rounds. Record the time comsumption.
3. Calculate the runtime latency introduced by BlueSWAT.

## 5. Power assess

We access the power and energy performance of BlueSWAT over a 120-second window, encompassing four phases: 20s of connection, 40s of BAS, another 20s of connection, and 40s of HRS.

We use ChargerLAB POWER-Z KT002 can record the Voltage, Current, and Power values during the testing window, and then compare the power increase introduced by BlueSWAT with baseline.
- Nordic 52840 Development Kit.
- Nordic 52840 Dongle.
BlueSWAT is tested under Ubuntu 20.04 on WSL2. This artifact contains implementation on two embedded OS with open-source BLE stacks, i.e., [ZephyrOS](https://zephyrproject.org/) and [MynewtOS](https://mynewt.apache.org/). This artifact is tested on the Nordic 52840 Development Kit.
To flash USB device from WSL2, please install [usbipd](https://learn.microsoft.com/en-us/windows/wsl/connect-usb). Besides, Install the [Segger JLINK Software and documentation pack](https://www.segger.com/downloads/jlink/). 
Download the source code and required submodules of MynewtOS:
git clone --recursive https://github.com/RayCxggg/BlueSWAT-Artifact.git
Install needed Python packages:
You can use minicom to monitor the output:
We integrat BlueSWAT with Zephyr and use the nRF52840 DK as the victim device.
BlueSWAT inspection rules are at `ZephyrOS/zephyr/firewall/policy/ebpf_C_code`. To compile them into eBPF programs, e.g., to compile `conn_chan_map.ebpf.c`, run `./compile.sh conn_chan_map`. We have provided some eBPF transition rules at `ZephyrOS/zephyr/firewall/policy/ebpf_bytecode`.
## 5. Power assess.
ChargerLAB POWER-Z KT002 can record the Voltage, Current, and Power values during the testing window, and we can compare the power increase introduced by BlueSWAT with baseline.
## Requirements
- Mobile BLE apps, e.g., nRF Connect, BLEscanner.
## Environment Setup
## Defense capability 
We integrat BlueWAT with Zephyr and use nRF52840 DK as the victim device.
1. Test the vulnerability without BlueSWAT. After flash the ZephyrOS to the board, use SweynTooth *Invalid Channel Map* to launch the attack. 
2. Load the defense rules into BlueSWAT and relaunch the attacks. In `ZephyrOS/zephyr/firewall/policy/include/fsm_policy_cache.h`, add 
This repository contains the artifact for BlueSWAT, a Bluetooth security framework for IoT devices based on eBPF. For more information about BlueSWAT, please consult our paper "BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy" (To appear in CCS 2024).
1. Environment Setup for ZephyrOS and Nordic 52840 Development Kit.
2. Evaluate defense capability artifact.
3. Evaluate memory consumption artifact.
4. Evaluate runtime latency artifact.
5. Evaluate power assess artifact.
### Setup Zephyr BLE stack
## Evaluate defense capability artifact
This repository contains the artifact for BlueSWAT, a Bluetooth security framework for IoT devices based on eBPF. For more information about BlueSWAT, please consult our paper "BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy" (Published in CCS 2024).
Download our code and required submodules of MynewtOS:
## Zephyr BLE stack

We are using ZephyrOS v2.2.0 for vulnerability reproduction.

### Setup
## Mynewt NimBLE stack

### Setup

Follow the [doc](https://mynewt.apache.org/latest/get_started/index.html) native installation mode to install the dependencies.

### Build and Flash

Now, build the bootloader and BLE targets:

```
cd BlueSWAT/Mynewt
newt build nrf52_boot
newt build peripheral
```

Run the `newt create-image` command to create and sign the application image. You may assign an arbitrary version (e.g. 1.0.0) to the image:
```
newt create-image peripheral 1.0.0
```

Connect a micro-USB cable from your computer to the micro-USB port on the nRF52-DK board. 

Then, load the bootloader and the BLE application image onto the board:
```
newt load nrf52_boot
newt load peripheral
```

### Monitor

You can use minicom to monitor the output:
```
sudo minicom -D /dev/ttyACM0
```

## Reference

If you are interested in using our works for academic research, please cite the paper:

```
@article{che2024blueswat,
  title={BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy},
  author={Che, Xijia and He, Yi and Feng, Xuewei and Sun, Kun and Xu, Ke and Li, Qi},
  journal={arXiv preprint arXiv:2405.17987},
  year={2024}
}
```
BlueSWAT is tested under Ubuntu 20.04 on WSL2. This artifact contains implementation on two embedded OS with open-source BLE stacks, i.e. [ZephyrOS](https://zephyrproject.org/) and [MynewtOS](https://mynewt.apache.org/). All the experiments are carried out on Nordic 52840 Development Kit.
BlueSWAT is tested under Ubuntu 20.04 on WSL2. This artifact contains implementation on [ZephyrOS](https://zephyrproject.org/) and [MynewtOS](https://mynewt.apache.org/), which provide open-source BLE stacks. All the experiments are carried out on Nordic 52840 Development Kit.
git clone --recursive https://github.com/RayCxggg/BlueSWAT_BLE.git
BlueSWAT is tested under Ubuntu 20.04 on WSL2. We implement BlueSWAT on [ZephyrOS](https://zephyrproject.org/) and [MynewtOS](https://mynewt.apache.org/), which provide open-source BLE stacks. All the experiments are carried out on Nordic 52840 Development Kit.
usbipd wsl list 
usbipd wsl attach --busid <busid> 
# BlueSWAT: A State-Aware Firewall for Bluetooth Low Energy
```
## ZephyrOS
## Mynewt
Download our code:
Clone related remote repositories:
newt build ble_tgt
newt create-image ble_tgt 1.0.0
newt load ble_tgt
git clone https://github.com/RayCxggg/BlueSWAT_BLE.git
To flash USB device from WSL2, please install [usbipd](https://learn.microsoft.com/en-us/windows/wsl/connect-usb). Besides, Install the [Segger JLINK Software and documentation pack](https://www.segger.com/downloads/jlink/).
### Build and flash
In a Windows shell, connect the board and attach it to WSL2:
usbipd wsl list 
usbipd wsl attach --busid <busid> 
Everything is settled! Flash the board:
source scripts/flash.sh
### Create targets
Run the following newt target commands, from your project directory, to create a bootloader target. We name the target nrf52_boot:
$ newt target create nrf52_boot
$ newt target set nrf52_boot app=@mcuboot/boot/mynewt
$ newt target set nrf52_boot bsp=@apache-mynewt-core/hw/bsp/nordic_pca10040
$ newt target set nrf52_boot build_profile=optimized
Run the following newt target commands to create a target for the BLE application. We name the target `ble_tgt`:
$ newt target create ble_tgt
$ newt target set ble_tgt     \
    app=apps/ble_app                        \
    bsp=@apache-mynewt-core/hw/bsp/nordic_pca10040  \
    build_profile=optimized
BlueSWAT is tested under Ubuntu 20.04 on WSL2. 
To flash USB device from WSL2, please install [usbipd](https://learn.microsoft.com/en-us/windows/wsl/connect-usb).
Download our code:
```
git clone https://github.com/RayCxggg/BlueSWAT_BLE.git
```

