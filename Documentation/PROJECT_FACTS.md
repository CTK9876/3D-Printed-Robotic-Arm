# Project fact verification checklist

This document prevents invented specifications and helps complete the public engineering report.

## Identity and electronics

- [ ] Exact microcontroller board/model
- [ ] Exact servo model(s), individual count, torque and voltage rating
- [ ] PCA9685 board model/address/channel assignments
- [ ] Analog joystick input pins and calibration details
- [ ] Power supply output voltage and max current; wiring topology
- [ ] Complete final Arduino `.ino` source and required libraries

## Mechanical

- [ ] Dimensions (overall height, base footprint, link lengths, total reach)
- [ ] Number of actuated degrees of freedom (count actual independent axes)
- [ ] Gear geometry / ratio, finger travel, joint angular ranges
- [ ] Printed material (PLA/PETG/etc.), assembly mass
- [ ] Fastener, spacer, and bearing details
- [ ] Final SolidWorks source assembly and export set

## Manufacturing

- [ ] Nozzle diameter, layer height, walls, infill and print orientation per part
- [ ] Support settings; any post-processing steps
- [ ] Total material consumption and print time, if recorded
- [ ] Design revision notes linked to changed files

## Verification results

- [ ] Latest working joystick mapping
- [ ] Startup motion approach and observed time
- [ ] Joint movement test video
- [ ] Gripper repeated-cycle observation
- [ ] Joint limits, reach, payload and repeatability (only if measured)

## Media and publication

- [ ] Photos of current assembled prototype
- [ ] CAD assembly/exploded screenshots
- [ ] As-built wiring photograph and diagram
- [ ] Optional demonstration video
- [ ] Review files for personal data / private course details

Use [test-log.csv](test-log.csv) and [Electronics/COMPONENTS.md](../Electronics/COMPONENTS.md) to convert these TBD entries into evidence-backed specifications.

[Back to README](../README.md)
