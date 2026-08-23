<img width="2194" height="1380" alt="circuit_image (1)" src="https://github.com/user-attachments/assets/051b389d-34d8-4586-a878-e5041f019118" />Cerebrus-Fourth-Head

A multi-servo robotic arm/head platform built around an ESP32, with a dedicated high-current power architecture for driving seven mixed-type servos independently from the logic rail.

Table of Contents
Overview
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
Overview

Cerebrus-Fourth-Head is a hands-on embedded robotics project focused on solving real power-delivery problems in multi-servo systems — not just wiring servos to a microcontroller, but making sure they get clean, sufficient current under load without brownouts, torque loss, or logic-level glitches.

Hardware
Controller: ESP32
Actuators: 7 servos (mixed types) — 3x MG90S, 3x MG996R, 1x DS3218
Power supply: Toshiba buck converter (servo rail), separated from ESP32 logic rail
Wiring: Hand-wired on perf board, AWG gauge selected per rail current draw
Previous revision: HW-131 buck converter (replaced due to insufficient input voltage headroom, which caused rail sag under load and torque loss on transient current spikes)
Power Architecture

The project keeps the ESP32 logic supply electrically separate from the servo power rail to avoid brownouts and logic glitches caused by servo current spikes. Key design points:

Servo current spikes were traced to inadequate regulator headroom (AMS1117 limitations) on the original power path.
Parallel buck converter configurations with current-sharing resistors were evaluated to handle peak current across all seven servos.
Wire gauge (AWG) was selected per branch based on expected continuous and peak current draw, not just total system current.
Bill of Materials

A full BOM with purchase links is in BOM.csv. A few rows (current buck converter part number, connector types, wire gauge) are still marked to fill in as the build is finalized.

Wiring Diagram

https://app.cirkitdesigner.com/project/4b6c4f35-8d81-41e9-b8f0-a50af25d7959

Source file: wiring_diagram.svg — edit directly in any vector editor (Inkscape, Illustrator) or a text editor since it's plain SVG.

An interactive version of this circuit is also maintained on Cirkit Designer.

CAD
Native CAD source: View/download on Fusion 360
STEP exports: in progress — individual .STEP files for each designed part will be added to /cad/step/. Until then, refer to the native Fusion 360 link above.


Firmware

Firmware targets the ESP32 using PlatformIO with the Arduino framework.

Requirements
PlatformIO Core or the PlatformIO IDE extension for VS Code
USB cable capable of data transfer (not charge-only)
ESP32 board drivers installed (CP210x or CH340, depending on your board)
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

If upload fails, hold the BOOT button on the ESP32 while the upload starts (some boards need this to enter flashing mode).

Repository Notes
.gitignore is configured to exclude VS Code IntelliSense cache files (browse.vc.db and related) to keep the repo clean.
Git history was cleaned via interactive rebase to remove previously committed cache bloat.
Status

Actively in development — current focus is finalizing the servo power rail (converter topology, current sharing, wiring) before moving to full motion control / firmware integration.

Roadmap
 Finalize power rail (single vs. parallel buck converters)
 Validate current-sharing under full 7-servo load
 Export individual .STEP files for each designed CAD part
 Firmware: servo control loop on ESP32
