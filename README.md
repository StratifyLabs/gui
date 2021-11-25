# gui

The **gui** project is graphical user interface template project. It is has the following features:

- Lightweight: distributable application binaries are as small as 5MB
- C and C++: the application code is C++ with various supporting libraries written in C and C++
- No changes to any system files (all build files and dependencies are contained)
- Cross-platform with support for macOS, windows, ubuntu and [StratifyOS](https://github.com/StratifyLabs/StratifyOS).

## API Features

The **gui** project contains built-in support for:

- [InetAPI](https://github.com/StratifyLabs/InetAPI): `HTTP`, `HTTPS`, `TLS` based on `mbedtls`, and BSD sockets
- [JsonAPI](https://github.com/StratifyLabs/JsonAPI): based on [jansson library]()
- [CryptoAPI](https://github.com/StratifyLabs/CryptoAPI): AES, ECDSA, ECDH, and SHA256
- [Graphics API](https://github.com/StratifyLabs/LvglAPI): based on [lvgl]()
- [WindowAPI](https://github.com/StratifyLabs/WindowAPI): based on [libsdl]()
- [Filesystems, Threads, Data Management, Timers, Testing, Printing](https://github.com/StratifyLabs/API): Stratify Labs API
  framework

## Prerequisites

To build `gui` on your computer you need to install:

- `git`
- `cmake`: 3.19 or higher

All library dependencies are automatically cloned and built with your application.

## Building

You can build the project with the following commands:

```bash
git clone https://github.com/StratifyLabs/gui.git
cd gui
cmake -P bootstrap.cmake
cd cmake_link
cmake .. -GNinja
ninja
```


