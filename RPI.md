# Building on Raspberry Pi


## Prerequisites

From a clean image of Raspberry Pi OS (32-bit):

```sh
sudo apt update
sudo apt upgrade
sudo apt install ninja-build
sudo apt install libssl-dev
sudo apt install libsdl2-dev


mkdir build_cmake
cd build_cmake
wget https://github.com/Kitware/CMake/releases/download/v3.21.2/cmake-3.21.2.tar.gz
cd cmake-3.21.2
./bootstrap -- -DCMAKE_BUILD_TYPE:STRING=Release
make -j2
sudo make install

cd ~
mkdir projects
cd projects
git clone https://github.com/StratifyLabs/gui
cd gui
cmake -P bootstrap.cmake
source profile.sh
cd cmake_link
cmake .. -GNinja
ninja sdl
rm -Rf *
cmake .. -GNinja
ninja
```

From a clean image of Raspberry Pi OS (32-bit no desktop env):

```sh
sudo apt update
sudo apt upgrade
sudo apt install ninja-build git cmake

#sudo apt install libssl-dev

sudo nano /etc/apt/sources.list
# uncomment sources line
sudo apt build-dep libsdl2
sudo apt install libdrm-dev libgbm-dev


```

sudo nano /etc/apt/sources.list
uncomment sources
sudo apt update

Installing `gh`: [here](https://lindevs.com/install-github-cli-on-raspberry-pi/) 

[MAME](https://github.com/keilmillerjr/Raspberry-Pi-MAME-Setup-Guide)

https://stackoverflow.com/questions/57672568/sdl2-on-raspberry-pi-without-x

Then:

```shell
gh auth setup-git
```

SDL Configure results:

```sh
SDL2 Configure Summary:
Building Shared Libraries
Building Static Libraries
Enabled modules : atomic audio video render events joystick haptic hidapi sensor power filesystem threads timers file loadso cpuinfo assembly
Assembly Math   :
Audio drivers   : disk dummy oss alsa(dynamic) pulse(dynamic) sndio(dynamic)
Video drivers   : dummy x11(dynamic) kmsdrm(dynamic) opengl opengl_es1 opengl_es2 vulkan wayland(dynamic)
X11 libraries   : xcursor xdbe xinerama xinput2 xinput2_multitouch xfixes xrandr xscrnsaver xshape xvidmode
Input drivers   : linuxev linuxkd
Enable virtual joystick APIs : YES
Using libsamplerate : YES
Using libudev       : YES
Using dbus          : YES
Using ime           : YES
Using ibus          : YES
Using fcitx         : YES
```