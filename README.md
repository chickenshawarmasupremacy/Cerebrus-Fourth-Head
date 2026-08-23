# Cerebrus-Fourth-Head
A super simple robot arm that took a lot of patience and even more effort
Cerebrus-Fourth-Head

A multi-servo robotic arm/head platform built around an ESP32, with a dedicated high-current power architecture for driving seven mixed-type servos independently from the logic rail.

Overview

Cerebrus-Fourth-Head is a hands-on embedded robotics project focused on solving real power-delivery problems in multi-servo systems — not just wiring servos to a microcontroller, but making sure they get clean, sufficient current under load without brownouts, torque loss, or logic-level glitches.

Hardware
Controller: ESP32
Actuators: 7 servos (mixed types)
Power supply: Toshiba buck converter (servo rail), separated from ESP32 logic rail
Wiring: Hand-wired on perf board, AWG gauge selected per rail current draw
Previous revision: HW-131 buck converter (replaced due to insufficient input voltage headroom, which caused rail sag under load and torque loss on transient current spikes)
Power Architecture

The project keeps the ESP32 logic supply electrically separate from the servo power rail to avoid brownouts and logic glitches caused by servo current spikes. Key design points:

Servo current spikes were traced to inadequate regulator headroom (AMS1117 limitations) on the original power path.
Parallel buck converter configurations with current-sharing resistors were evaluated to handle peak current across all seven servos.
Wire gauge (AWG) was selected per branch based on expected continuous and peak current draw, not just total system current.
Repository Notes
.gitignore is configured to exclude VS Code IntelliSense cache files (browse.vc.db and related) to keep the repo clean.
Git history was cleaned via interactive rebase to remove previously committed cache bloat.
Status

Actively in development — current focus is finalizing the servo power rail (converter topology, current sharing, wiring) before moving to full motion control / firmware integration.

Roadmap
 Finalize power rail (single vs. parallel buck converters)
 Validate current-sharing under full 7-servo load
 Firmware: servo control loop on ESP32
