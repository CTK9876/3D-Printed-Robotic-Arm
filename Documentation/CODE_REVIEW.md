# Arduino Firmware — Code Review and Engineering Notes

**Reviewed file:** [`Firmware/Robotic_Arm_Porject_2.ino`](../Firmware/Robotic_Arm_Porject_2.ino)

This review documents what the uploaded source **actually implements**. It is not a hardware validation report, and the original sketch has been preserved unchanged.

## Main components

- `Wire.h` — Arduino I²C support.
- `Adafruit_PWMServoDriver.h` — PCA9685 servo PWM output.
- `analogRead(A0..A3)` — four analog joystick channels.
- `pwm.setPWMFreq(50)` — nominal 50 Hz PWM.
- `Serial.begin(9600)` — serial debugging/output.

## Outputs and mapping

| Actuator | Channel | Servo domain as labeled | Code initial angle | Software clamp | Analog input | Command sign | Deadzone | Max increment / loop |
| --- | ---: | --- | ---: | --- | --- | --- | ---: | ---: |
| Base | 1 | 270° | 135° | 10–260° | A1 (`joy1Y`) | positive | 70 | 3° |
| Shoulder | 0 | 180° | 90° | 20–160° | A0 (`joy1X`) | positive | 70 | 2° |
| Elbow | 2 | 180° | 90° | 20–160° | A3 (`joy2Y`) | **negative** | 70 | 3° |
| Gripper | 3 | 180° | 90° | 30–120° | A2 (`joy2X`) | positive | 50 | 5° |

Notes:
- Sketch comments label `joy1` as the **right joystick** and `joy2` as the **left joystick**. These labels depend on physical assembly and are **not independently verified**.
- `maxSpeed` names in the sketch are maximum **angle increments per loop**, not angular velocity in °/s. Actual loop period includes I²C writes, `Serial.print()` and `delay(10)`.
- The joystick center constant is 512. Outside each deadzone, `joystickToSpeed()` scales command increments approximately between ±1 and the axis-specific maximum.

## Startup motion: important limitation

Code excerpt (from the uploaded original sketch):

```cpp
int baseAngle = 135;
int shoulderAngle = 90;
int elbowAngle = 90;
int gripperAngle = 90;

slowMove270(baseCh, 135, baseAngle, 20);
slowMove180(shoulderCh, 90, shoulderAngle, 25);
slowMove180(elbowCh, 90, elbowAngle, 25);
slowMove180(gripperCh, 90, gripperAngle, 20);
```

Because each initial variable equals the matching hard-coded `startAngle`, these calls **iterate once**, despite the `slowMove...()` function names. The script therefore does not know the servo's actual initial shaft position and cannot guarantee a gradual physical transition from it.

The sketch also waits about 2.5 seconds after initializing PWM before issuing these first setpoints. A delay before a position command is **not** the same as a ramp to that position.

**Recommended change, subject to physical calibration:** Implement tested progressive movement from a known safe reference or an appropriate power-up/homing strategy. Avoid assuming the servo can report its true mechanical position — standard hobby servos usually cannot.

## PWM pulse range: calibration before use

The sketch maps 0–180° or 0–270° into a common **100–650 PCA9685-count range**, with a 50 Hz PWM frequency.

Nominal 50 Hz period ≈ 20,000 μs and one PCA9685 count ≈ 20,000 / 4096 ≈ 4.883 μs:

| Constant | Counts | Approx. pulse width |
| --- | ---: | ---: |
| `SERVOMIN` | 100 | 488 μs |
| `SERVOMAX` | 650 | 3174 μs |

This span may lie outside the rated safe PWM pulse widths of some servo models. It must be checked with the specific actuator datasheets and then calibrated to avoid stall, excess current and mechanical hard-stop contact. No adjustment was made to the published original sketch.

## Software angle limits vs. mechanical limits

`constrain()` protects **commanded angles** in software but cannot prove that a joint is physically free of interference. Verify the real travel range, servo horn orientation and gripper gear travel under no load.

## Items to improve after verification

1. Confirm board model, PWM board address, servo hardware and actual power topology.
2. Identify which physical joystick controls each axis and its desired direction.
3. Calibrate joystick center per axis if drift occurs, and consider noise filtering.
4. Calibrate pulse endpoints **per servo** (especially different 180° vs 270° models).
5. Implement and physically validate safe startup behavior.
6. Consider non-blocking motion timing instead of relying on a fixed `delay(10)`.
7. Record physical angular ranges, payload observations and power behavior with dated tests.

**Status:** Reviewed statically from source; compiling, flashing and hardware testing were not performed as part of this publication.