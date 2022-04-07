# Building on Raspberry Pi


## Prerequisites

From a clean image of Raspberry Pi OS (32-bit):

```sh
sudo apt update
sudo apt upgrade
sudo apt install ninja-build
sudo apt install libsdl-dev
sudo apt install libssl-dev

mkdir build_cmake
cd build_cmake
wget https://github.com/Kitware/CMake/releases/download/v3.21.2/cmake-3.21.2.tar.gz
cd cmake-3.21.2
./bootstrap -- -DCMAKE_BUILD_TYPE:STRING=Release


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