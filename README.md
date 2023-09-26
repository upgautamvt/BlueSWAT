# BlueSWAT: A State-Aware Firewall for Bluetooth Low Energy

This repository contains the artifact for BlueSWAT, a Bluetooth security framework for IoT devices based on eBPF.

## Environment Setup

BlueSWAT is tested under Ubuntu 20.04 on WSL2. 

To flash USB device from WSL2, please install [usbipd](https://learn.microsoft.com/en-us/windows/wsl/connect-usb).

## ZephyrOS

We are using ZephyrOS v2.2.0 for vulnerability reproduction.

### Setup

Please follow STEP ONE and TWO in the [doc](https://docs.zephyrproject.org/2.2.0/getting_started/index.html) to install dependencies.

Download our code:
```
git clone https://github.com/RayCxggg/BlueSWAT_BLE.git
```

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

Set build environment variables:
```
cd BlueSWAT/ZephyrOS/zephyr
source zephyr-env.sh
```

### Build and flash

Now, we build the BLE peripheral application for Nordic 52840 DK:
```
cd BlueSWAT/ZephyrOS
source scripts/config.sh
source scripts/build.sh
```

In a Windows shell, connect the board and attach it to WSL2:
```
usbipd wsl list 
usbipd wsl attach --busid <busid> 
```

Everything is settled! Flash the board:
```
source scripts/flash.sh
```

