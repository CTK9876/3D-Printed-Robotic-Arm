# Firmware & Controls

## Verified source

The full uploaded source is available at [Firmware/Robotic_Arm_Porject_2.ino](../Firmware/Robotic_Arm_Porject_2.ino). This document describes that source, not a simulation or verified physical measurement.

## Control path

```mermaid
flowchart LR
  A[Joystick analogRead A0–A3] --> B[joystickToSpeed]
  B --> C[Update angle commands]
  C --> D[constrain angle limits]
  D --> E[map angle into PCA9685 counts]
  E --> F[setPWM to four channels]
```

The firmware calls `analogRead()` four times each loop, then updates the four servo setpoints. Joystick inputs outside the configured deadzone generate increments whose magnitude increases with distance from center. Loop pacing includes `delay(10)` and serial output.

## Exact source mapping

| Joystick code variable | Arduino analog pin | Servo commanded | Sign | Deadzone | Max angle increment / loop |
| --- | --- | --- | --- | ---: | ---: |
| `joy1X` | A0 | Shoulder | + | 70 | 2° |
| `joy1Y` | A1 | Base | + | 70 | 3° |
| `joy2X` | A2 | Gripper | + | 50 | 5° |
| `joy2Y` | A3 | Elbow | − | 70 | 3° |

The comments in the sketch associate joystick 1 with the right stick and joystick 2 with the left, but the actual physical mapping and signs need confirmation by testing.

## Hardware and software commands

| Axis | Output channel | Nominal type in code | Starting command | Software limit |
| --- | ---: | --- | ---: | --- |
| Shoulder | 0 | 180° | 90° | 20–160° |
| Base | 1 | 270° | 135° | 10–260° |
| Elbow | 2 | 180° | 90° | 20–160° |
| Gripper | 3 | 180° | 90° | 30–120° |

The code uses `SERVOMIN=100`, `SERVOMAX=650`, a 50 Hz PWM frequency, joystick center 512, and serial output at 9600 baud.

## Startup and safety

`setup()` delays 500 ms and then 2000 ms before commanding the servos. The installed `slowMove` function calls use the same initial and target positions, so they produce only a single commanded setpoint and do **not** confirm a slow physical motion. Resolve this only after calibrating the actual servo models and verifying the mechanical assembly.

At 50 Hz, the 100–650 driver-count window corresponds to approximately 488–3174 microseconds. These are **code-derived pulse widths, not verified safe actuator endpoints**. Calibrate using part-specific datasheets and unloaded tests.

## Validation checklist

- [ ] Confirm actual installed microcontroller board and library version.
- [ ] Verify joystick 1 and 2 positions physically and test all directions.
- [ ] Verify servo type, powered supply and per-servo PWM pulse limits.
- [ ] Confirm physical joint clearances across the intended motion.
- [ ] Observe repeated startup and document the actual motion.
- [ ] Test gripper open/close without loading the gears.

See [code review](CODE_REVIEW.md), [testing plan](TESTING_AND_VALIDATION.md), and [engineering checklist](Robotic_Arm_Engineering_Information_Checklist.xlsx).