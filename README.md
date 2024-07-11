# BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy

This repository contains the artifact for BlueSWAT, a Bluetooth security framework for IoT devices based on eBPF. For more information about BlueSWAT, please check out our paper "BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy" (To appear in CCS 2024).

## Table for Artifact Evaluation

0. Requirements.
1. Set up ZephyrOS and Nordic 52840 Development Kit.
2. Defense capability.
3. Memory consumption.
4. Runtime latency.
5. Power assess.

## Requirements

Software
- Ubuntu 20.04 or WSL2.
- Segger JLINK.
- Mobile BLE apps, e.g., nRF Connect, BLEscanner.

Hardware
- Nordic 52840 Development Kit.
- Nordic 52840 Dongle.

## Environment Setup

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

### Monitor

You can use minicom to monitor the output:
```
sudo minicom -D /dev/ttyACM0
```

## Defense capability 

### Adversary

We use the nRF52840 dongle as the adversary. Follow [SweynTooth](https://github.com/Matheus-Garbelini/sweyntooth_bluetooth_low_energy_attack) to install the firmware. 

### Victim

We integrat BlueWAT with Zephyr and use nRF52840 DK as the victim device.

BlueSWAT inspection rules are at `ZephyrOS/zephyr/firewall/policy/ebpf_C_code`. To compile them into eBPF programs, e.g., to compile `conn_chan_map.ebpf.c`, run `./compile.sh conn_chan_map`. We have provided some eBPF transition rules at `ZephyrOS/zephyr/firewall/policy/ebpf_bytecode`.

1. Test the vulnerability without BlueSWAT. After flash the ZephyrOS to the board, use SweynTooth *Invalid Channel Map* to launch the attack. 

The *Invalid Channel Map* attack will trigger a kernel panic and crash the device.

2. Load the defense rules into BlueSWAT and relaunch the attacks. In `ZephyrOS/zephyr/firewall/policy/include/fsm_policy_cache.h`, add 
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
