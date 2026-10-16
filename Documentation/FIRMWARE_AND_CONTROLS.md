# Firmware and manual control

## Purpose

The Arduino-based firmware turns joystick readings into movement commands for the robotic arm's servos via the PCA9685 PWM driver.

**Source availability:** The original working `.ino` sketch must be uploaded before code-level documentation can be verified.

## Control pipeline (conceptual)

1. Read joystick analog inputs.
2. Interpret horizontal/vertical axes for the desired joint motion.
3. Apply any implemented calibration, deadband, direction inversion, and limits.
4. Convert desired movement into servo positions / pulse commands.
5. Send updated commands through PCA9685.

The above is an **architectural description**, not a claim that every step already exists in the sketch.

## Controls to document from the working build

| Input | Intended behavior / verification |
| --- | --- |
| Right joystick up | Raise arm |
| Right joystick down | Lower arm |
| Right joystick right | Turn right |
| Right joystick left | Turn left |
| Other joystick axes | Verify from original code and physical test |
| Startup | Move toward initial positions without sudden destabilizing jumps |

The right-joystick directions reflect the desired control mapping described during prototype testing. Verify that the latest uploaded sketch actually implements them.

## Startup behavior

An early observation was a rapid movement toward the starting position when power was applied, with a possible stability impact. A common remedy is ramping servo targets over time, but the installed implementation should be determined from the actual source code. Do not claim smoothing was successfully implemented without verification.

## Suggested software validation

- [ ] Record analog pin constants and PCA9685 channel constants.
- [ ] Confirm neutral joystick readings.
- [ ] Confirm correct axes and signs for each movement.
- [ ] Verify physical joint limits and any software angle limits.
- [ ] Check startup position and movement rate.
- [ ] Verify behavior after power cycling.
- [ ] Test gripper actuation independently from arm movement.
- [ ] Record exact board and library versions.

## Change control

Save a copy of the known-working sketch before experimenting. Test modified control mappings and servo limits in a safe, unloaded position.

[Arduino source directory](../Firmware/) · [Back to README](../README.md)
