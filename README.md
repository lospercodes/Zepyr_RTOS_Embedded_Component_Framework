# Zephyr RTOS Simple Embedded component Framework
C++ wrapper for ZephyrOS with Publish and subscribe methods

## Installation

Zephyr OS is a real-time operating system (RTOS) for resource-constrained devices, particularly IoT devices. It provides a rich set of features and is built with a focus on efficiency and flexibility. If you're interested in working with Zephyr OS from the command line, you'll need to set up the Zephyr development environment, which typically involves using the **Zephyr SDK** along with **West**, the Zephyr project management tool.

Here's how to get started with **Zephyr OS** and its command-line tools:

### Step-by-Step Guide to Setting Up Zephyr OS Command Line

#### 1. **Install Prerequisites**

- **Python** (version 3.7 or later)  
- **Git**  
- **CMake** (version 3.13 or later)  
- **Ninja** (for fast builds)  
- **Zephyr SDK** (to get cross-compilation tools)

##### On Ubuntu or Debian-based systems:
```bash
sudo apt update
sudo apt install python3 python3-pip git cmake ninja-build gperf ccache dfu-util device-tree-compiler
```

#### 2. **Install Zephyr SDK**
The Zephyr SDK provides the necessary cross-compilation tools for various architectures. You can download and install it from the official Zephyr website:  
[Download Zephyr SDK](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/zephyr/zephyr_sdk.html).

After downloading the SDK, follow the installation instructions for your operating system.

#### 3. **Install `west` Tool**

`west` is the command-line tool used to manage Zephyr projects, perform builds, and interact with the Zephyr environment. To install it, use Python's package manager `pip`:

```bash
pip install west
```

#### 4. **Set Up Zephyr Project Workspace**

1. **Initialize your workspace**:
   - Create a directory for your Zephyr projects and initialize it as a Zephyr workspace.
   ```bash
   mkdir zephyr-workspace
   cd zephyr-workspace
   west init -m https://github.com/zephyrproject-rtos/zephyr --mr main
   ```

   - This will download the Zephyr project into your workspace.

2. **Install required modules**:
   After initializing, you need to fetch all the modules and libraries used by Zephyr.

   ```bash
   west update
   ```

#### 5. **Set Up the Environment**

Before building your projects, you need to set up the environment to ensure that the toolchain and build system are properly configured. You can use the `zephyr-env.sh` script, which is provided in the Zephyr repository:

```bash
source zephyr/zephyr-env.sh
```

This script sets up environment variables for your shell session, pointing to the Zephyr SDK and other tools needed for building.

#### 6. **Build a Zephyr Application**

1. **Create a sample application**:
   You can create a Zephyr application, or use one of the many sample applications provided by Zephyr.

   For example, you can use the "hello_world" sample that comes with Zephyr:
   ```bash
   west build -b <board> samples/hello_world
   ```

   Replace `<board>` with your target board (e.g., `nrf52840dk_nrf52840`, `x86_64`, etc.).

2. **Build the project**:
   After setting up the board and the project, you can build your application using the `west build` command:

   ```bash
   west build -b <board> path/to/your/application
   ```

   This command will compile the application for your target board.

#### 7. **Flash the Application to the Device**

To flash your application to the device, you can use the `west flash` command. This command depends on the hardware interface (e.g., USB, JTAG, or SWD) and the device you're flashing.

For example:
```bash
west flash
```

This will upload the built application to the connected device.

#### 8. **Monitoring the Output**

Zephyr also includes a simple command for monitoring serial output from your device. You can use the `west monitor` command to start the serial monitor.

```bash
west monitor
```

This will start displaying logs and output from the device via its serial interface.

### Example Workflow

Here’s a full workflow to build and flash an application:

1. Set up the Zephyr workspace:
   ```bash
   mkdir zephyr-workspace
   cd zephyr-workspace
   west init -m https://github.com/zephyrproject-rtos/zephyr --mr main
   west update
   source zephyr/zephyr-env.sh
   ```

2. Build the `hello_world` example for a specific board:
   ```bash
   west build -b nrf52840dk_nrf52840 samples/hello_world
   ```

3. Flash the application to the connected board:
   ```bash
   west flash
   ```

4. Monitor the serial output:
   ```bash
   west monitor
   ```

### Useful `west` Commands

- `west init`: Initializes a new Zephyr project workspace.
- `west update`: Fetches and updates all repositories in the workspace.
- `west build`: Builds the project for the specified board.
- `west flash`: Flashes the application to the connected device.
- `west monitor`: Monitors the serial output of the device.
- `west help`: Shows a list of available `west` commands.

### Additional Resources

- **Zephyr Documentation**:  
  [Zephyr Documentation](https://docs.zephyrproject.org/)
  
- **Zephyr GitHub Repository**:  
  [Zephyr GitHub](https://github.com/zephyrproject-rtos/zephyr)

This is a basic overview to get started with Zephyr OS and the command-line tools. If you need more specific instructions or run into any issues, feel free to ask!

## Type of zephyr Project

This Zephyr application is a "Zephyr repository application, i.e. you build from the zephyrproject/zephyr directory"


