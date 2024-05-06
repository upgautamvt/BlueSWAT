# BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy

This repository contains the artifact for BlueSWAT, a Bluetooth security framework for IoT devices based on eBPF.

## Environment Setup

BlueSWAT is tested under Ubuntu 20.04 on WSL2. This artifact contains implementation on two embedded OS with open-source BLE stacks, i.e., [ZephyrOS](https://zephyrproject.org/) and [MynewtOS](https://mynewt.apache.org/). This artifact is tested on the Nordic 52840 Development Kit.

To flash USB device from WSL2, please install [usbipd](https://learn.microsoft.com/en-us/windows/wsl/connect-usb). Besides, Install the [Segger JLINK Software and documentation pack](https://www.segger.com/downloads/jlink/). 

Download our code and required submodules of MynewtOS:
```
git clone --recursive https://github.com/RayCxggg/BlueSWAT-Artifact.git
```

In a Windows shell, connect the board and attach it to WSL2:
```
usbipd list 
usbipd bind --busid <busid>
usbipd attach --wsl --busid <busid>
```

## Zephyr BLE stack

We are using ZephyrOS v2.2.0 for vulnerability reproduction.

### Setup

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
