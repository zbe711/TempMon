# README #

### What is this repository for? ###
This repository contains a small bare‑metal temperature monitoring project.  
It periodically samples a temperature sensor and classifies the value into OK / Warning / Critical ranges, and drives three LEDs to visualize the current state.

It is implemented in both C and C++ and is structured to be portable across Windows, macOS, and Linux.

### Pre-Reqs ###

**CMake installation**
- **Linux / WSL**: `sudo apt-get update && sudo apt-get install cmake`
- **macOS** (Homebrew): `brew install cmake`
- **Windows**:
  - Download from `https://cmake.org`, run the installer, and select “Add CMake to system PATH”, or
  - Use Chocolatey (Admin PowerShell): `choco install cmake`

### Setup ###

### Compilation ###
From the repo root:
- **C version**: `./build.sh -l C99`
- **C++ version**: `./build.sh -l Cpp`

### Run ###
- **C version**: `./build/tempmon_c`
- **C++ version**: `./build/tempmon_cpp`
