# Building on Raspberry Pi

## Prerequisites

From a clean image of Raspberry Pi OS Lite (32-bit no desktop env), run the following commands.

```sh
sudo apt update
sudo apt upgrade
sudo apt install ninja-build git cmake
sudo nano /etc/apt/sources.list
# uncomment sources line
sudo apt update
sudo apt build-dep libsdl2
sudo apt install libdrm-dev libgbm-dev
```

## Building

Once the prerequisites are complete, use the normal [build instructions](README.md#building).