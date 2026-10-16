# Firmware — Arduino Robotic Arm Controller

**Source:** [`Robotic_Arm_Porject_2.ino`](Robotic_Arm_Porject_2.ino) (original user-provided sketch, unmodified)

This sketch implements joystick-based incremental control of a 3-joint robotic arm plus a geared gripper, sending position commands to a PCA9685 PWM servo driver.

## Code dependencies

- Arduino `Wire.h`
- Adafruit `Adafruit_PWMServoDriver.h` library (install through Arduino IDE Library Manager)
- Arduino-compatible board with analog inputs A0–A3 and I²C support (exact board not yet verified)

## Channel and joystick map

| Output | PCA9685 channel | Analog input | Software command limits |
| --- | ---: | --- | --- |
| Shoulder | 0 | A0 (`joy1X`) | 20–160° |
| Base | 1 | A1 (`joy1Y`) | 10–260° |
| Elbow | 2 | A3 (`joy2Y`, inverted command) | 20–160° |
| Gripper | 3 | A2 (`joy2X`) | 30–120° |

The sketch's joystick labels do not establish the physical orientation; verify the actual assembly. The code uses PWM at 50 Hz and 100–650 counts for pulse mapping. Servo hardware and actual pulse ratings **must be confirmed** before operating.

## Known limitation: startup smoothing

The defined `slowMove180`/`slowMove270` routines are currently called with identical starting and target values; as written, they do **not** ramp from the unknown actual shaft positions at power-on. Do not claim smooth startup is already validated.

Read [detailed firmware explanation](../Documentation/FIRMWARE_AND_CONTROLS.md), [source-code review and safety caveats](../Documentation/CODE_REVIEW.md), and [electronics architecture](../Documentation/ELECTRONICS_AND_CONTROL.md).

**Publication note:** The sketch filename preserves the original uploaded spelling (`Porject`).