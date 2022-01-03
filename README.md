# gui

The **gui** project is graphical user interface template project. It is has the following features:

- Lightweight: distributable application binaries are as small as 5MB
- C and C++: the application code is C++ with various supporting libraries written in C and C++
- No changes to any system files (all build files and dependencies are contained)
- Cross-platform with support for macOS, windows, ubuntu and [StratifyOS](https://github.com/StratifyLabs/StratifyOS).
- Permissive licenses for all libraries (MIT, BSD, zlib, apache)

## API Features

The **gui** project contains built-in support for:

- [InetAPI](https://github.com/StratifyLabs/InetAPI): `HTTP`, `HTTPS`, `TLS` based on `mbedtls`, and BSD sockets
- [JsonAPI](https://github.com/StratifyLabs/JsonAPI): based on [jansson library](https://github.com/akheron/jansson)
- [CryptoAPI](https://github.com/StratifyLabs/CryptoAPI): AES, ECDSA, ECDH, and SHA256
- [Graphics API](https://github.com/StratifyLabs/LvglAPI): based on [lvgl](https://lvgl.io)
- [WindowAPI](https://github.com/StratifyLabs/WindowAPI): based on [libsdl](https://www.libsdl.org/)
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
ninja sdl
rm -Rf *
cmake .. -GNinja
ninja
```

## Anatomy of a GUI Application

![Overview](docs/overview.svg)

The `gui` application executes and lvgl runtime loop in the main thread. All operations in 
the main thread should return quickly to avoid a sluggish user interface. The `View` classes
create objects on the gui and use the lvgl event handler system to process user input. The `View`
classes are purely static functions. They do not retain any data. They turn the memory management
of the GUI over to the lvgl memory system. The `LvglAPI` allows you to attach user data to a specific
object. Any data that is shared among objects is placed in the `Model`.

The `Model` is a C++ singleton class that can be accessed from anywhere in the program. All access 
is assumed to be in a multi-threaded environment. The `Model::Scope` class locks the `Model`
and allows for access to the model with the model scope.

```cpp
int my_function(){
 Model::Scope model_scope;
 model().is_dark_theme = false;
}
```

If the user input requires processing that cannot be completed quickly, a `Worker` is used to 
create a separate thread for processing the request. The `Worker` code should act as a
go-between for the `Logic` and the `Model`/`View`. The `Logic` can and should be written
to be completely decoupled from the graphical portion. The GUI cannot be updated from a background
thread. The `design::Worker` class provides a mechanism to push tasks into the LVGL runtime
and to maintain thread safety while doing so.



