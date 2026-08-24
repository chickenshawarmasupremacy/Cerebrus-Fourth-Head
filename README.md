<img width="2194" height="1380" alt="circuit_image" src="https://github.com/user-attachments/assets/051b389d-34d8-4586-a878-e5041f019118" />
Cerebrus-Fourth-Head

A multi-servo robotic arm/head platform built around an ESP32, with a separate high-current power rail for driving seven mixed-type servos. Built for learning, and as a base for later work with AI models, ROS 2, and Gazebo.

Table of Contents
Hardware
Power Architecture
Bill of Materials
Wiring Diagram
CAD
Firmware
Repository Notes
Status
Roadmap
License
Hardware
Controller: ESP32
Actuators: 7 servos (mixed types) — 3x MG90S, 3x MG996R, 1x DS3218
Power supply: Toshiba buck converter (servo rail), separate from the ESP32 logic rail
Wiring: Hand-wired on perf board, AWG gauge selected per rail current draw
Previous revision: HW-131 buck converter. Replaced because its input voltage headroom was too low, which caused rail sag under load and torque loss during current spikes.
Power Architecture

The ESP32 logic supply is electrically separate from the servo power rail. This avoids brownouts and logic glitches when servos draw current spikes.

Traced the original torque loss to insufficient regulator headroom (AMS1117 limitations) on the old power path.
Evaluated parallel buck converter configurations with current-sharing resistors to cover peak current across all seven servos.
Sized wire gauge (AWG) per branch based on expected continuous and peak current, not total system current.
Bill of Materials

Full BOM with purchase links: BOM.csv. A few rows (buck converter part number, connector types, wire gauge) are still being finalized.

Wiring Diagram

https://app.cirkitdesigner.com/project/4b6c4f35-8d81-41e9-b8f0-a50af25d7959

An interactive version of this circuit is also maintained on Cirkit Designer.

CAD
Native CAD source (Fusion 360): https://a360.co/4wOWuL7
Shapr3D: https://app.shapr3d.com/p/7f951f56-316d-4975-8dc6-9f119cc89c82
STEP exports: models/
Firmware

Targets the ESP32, built with PlatformIO and the Arduino framework.

Requirements
PlatformIO Core or the PlatformIO IDE extension for VS Code
USB cable capable of data transfer (not charge-only)
ESP32 board drivers installed (CP210x or CH340, depending on the board)
Build
bash
# from the firmware project root (where platformio.ini lives)
pio run
Flash
bash
# connect the ESP32 via USB, then:
pio run --target upload

# if the port isn't auto-detected, specify it explicitly:
pio run --target upload --upload-port /dev/ttyUSB0   # Linux
pio run --target upload --upload-port COM5            # Windows
Monitor serial output
bash
pio device monitor

If upload fails, hold the BOOT button on the ESP32 while the upload starts. Some boards need this to enter flashing mode.

Repository Notes
.gitignore excludes VS Code IntelliSense cache files (browse.vc.db and related).
Git history was cleaned via interactive rebase to remove previously committed cache bloat.
