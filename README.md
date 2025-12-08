# README #

### What is this repository for? ###
This repository contains a small bare‑metal temperature monitoring project.  
It periodically samples a temperature sensor and classifies the value into OK / Warning / Critical ranges, and drives three LEDs to visualize the current state.

It is implemented in both C and C++ and is structured to be portable across Windows, macOS, and Linux.

### Project Structure ###

```
tempmon/
├── arch/                    # Architecture documentation
│   ├── ddd/                 # Design decision documents
│   ├── ea/                  # Enterprise Architect diagrams
│   ├── swe2/                # SWE.2 Software Architectural Design diagrams
│   ├── swe3/                # SWE.3 Software Unit Design diagrams
├── core/                    # Core application code
│   ├── app/                 # Application layer
│   ├── mcal/                # MCAL (Microcontroller Abstraction Layer)
│   │   ├── adc/            # ADC driver
│   │   ├── gpio/           # GPIO driver
│   │   ├── gpt/            # General Purpose Timer driver
│   │   ├── i2c/            # I2C driver
│   │   └── wdg/            # Watchdog driver
│   └── services/           # Service layer
│       ├── mon/            # Monitoring service
│       ├── nvm/            # Non-Volatile Memory service
│       └── time/           # Time service
├── docs/                    # Documentation source (Sphinx)
├── reqs/                    # Requirements documentation
│   ├── hardware/           # Hardware requirements
│   ├── software/           # Software requirements
│   └── system/             # System requirements
├── tests/                   # Test files
├── tools/                   # Build and utility scripts
│   └── scripts/
│       └── build_docs.sh   # Documentation build script
├── build.sh                 # Main build script
├── CMakeLists.txt          # Root CMake configuration
└── README.md               # This file
```

### Pre-Reqs ###

**CMake installation**
- **Linux / WSL**: `sudo apt-get update && sudo apt-get install cmake`
- **macOS** (Homebrew): `brew install cmake`
- **Windows**:
  - Download from `https://cmake.org`, run the installer, and select "Add CMake to system PATH", or
  - Use Chocolatey (Admin PowerShell): `choco install cmake`

**Python and Sphinx (for documentation)**
- **Linux / WSL**: `sudo apt-get install python3 python3-pip`
- **macOS** (Homebrew): `brew install python3`
- **Windows**: Download from `https://www.python.org/downloads/`
- Install Sphinx: `pip install -r docs/requirements.txt`

### Setup ###

### Compilation ###
From the repo root:
- **C version**: `./build.sh -l C99`
- **C++ version**: `./build.sh -l Cpp`

### Run ###
- **C version**: `./build/tempmon_c`
- **C++ version**: `./build/tempmon_cpp`

### Building Documentation ###

**Using the build script:**
```bash
./build.sh docs
```

**View documentation:**
Open `build/docs/index.html` in your web browser.
