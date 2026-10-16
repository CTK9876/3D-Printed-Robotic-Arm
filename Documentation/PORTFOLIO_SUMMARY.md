# Résumé and Portfolio Summary

## Project: 3D-Printed Robotic Arm

**Mechanical Design · FDM Additive Manufacturing · Embedded Servo Control**

Developed a custom-designed joystick-controlled robotic arm, integrating SolidWorks CAD, printed mechanical components, servo-driven joints, a gear-driven gripper and a PCA9685-based Arduino/C++ control system. The work combined modeling, fabrication, assembly, control mapping and troubleshooting in an iterative prototype.

### Résumé bullets

- Designed a custom robotic arm with a geared gripper in **SolidWorks**, considering servo-shaft alignment, printed mounting structures, link geometry and assembly clearance.
- Fabricated mechanical components using a **Bambu Lab P1S FDM printer** and assembled a servo-driven robotic arm with a separate, custom two-joystick controller.
- Implemented **Arduino/C++ joystick-based servo control** through a **PCA9685 PWM driver**, including four servo channels, per-axis software limits and deadzone/sensitivity tuning.
- Investigated joystick direction mapping, startup movement and component integration through hands-on prototyping and functional observations.

### Evidence links

- [Project homepage and prototype photos](../README.md)
- [Original Arduino firmware](../Firmware/Robotic_Arm_Porject_2.ino)
- [Control mappings and source review](CODE_REVIEW.md)
- [Mechanical design and assembly documentation](MECHANICAL_DESIGN.md)
- [Build/test records and verification checklist](Robotic_Arm_Engineering_Information_Checklist.xlsx)

### What to add before claiming engineering performance

Physical dimensions, payload, range of motion, gripper force and repeatability should be measured and recorded before appearing as quantified achievement bullets. Do not claim successful startup smoothing until a corrected version has been tested.

### Suggested interview narrative

Explain the design intent; show the full CAD assembly and one critical mechanical bracket; discuss print orientation/fit tradeoffs; walk through the joystick-to-servo firmware mapping; describe a control or startup problem and how you validated the change.