# sana

3D second brain — knowledge graph desktop application written in C++17.
Currently MVP in development.

## Status

Pre-alpha. Basic OpenGL window working. Active development.

## Tech stack

- **C++17** with g++ 13.2+ (or clang/MSVC equivalent)
- **CMake 3.20+** with Ninja generator
- **OpenGL 3.3 core profile** for rendering
- **GLFW 3.4** — windowing and input
- **GLAD 2** — OpenGL function loader

All C++ dependencies are fetched automatically via CMake `FetchContent`.
No vcpkg / conan / pacman setup needed.

## Prerequisites

Before building, install these on your machine:

| Tool | Minimum version | Purpose |
|---|---|---|
| C++ compiler | g++ 11+ / clang 13+ / MSVC 19.30+ | builds the project and dependencies |
| CMake | 3.20+ | build system generator |
| Ninja | any recent | actual build tool |
| Python | 3.8+ | runs glad code generator at build time |
| `glad2` Python package | latest | OpenGL function loader codegen |
| git | any | required by CMake FetchContent |

### Installing prerequisites on Windows

(write here exact commands you used: MSYS2 install, ninja install, glad2 install)

### Installing prerequisites on Linux

(skip for now, fill in if/when tested)

## Building

```bash
git clone https://github.com/<your-username>/sana.git
cd sana
cmake -B build -G "Ninja"
cmake --build build
./build/sana          # or build\sana.exe on Windows