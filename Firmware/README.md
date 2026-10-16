# Arduino firmware

The current robotic-arm controller is written in the Arduino/C++ environment and processes **dual analog joystick inputs** to command servo positions using a **PCA9685 PWM driver**.

## Firmware status

The source `.ino` file has not been uploaded yet. No replacement or fabricated code is included here.

## Add the real source code

1. Upload the original Arduino sketch (or sketch folder) into `Firmware/`.
2. Document the exact microcontroller board, PCA9685 library, pin mapping, I²C address, servo channels, and supply requirements after reading the uploaded sketch.
3. Preserve the tested control limits and startup behavior.
4. Keep untested refactors on a separate branch or label them experimental.

## Control behavior to verify

- The joystick's physical right/left axis maps to the expected arm rotation.
- The joystick's up/down axis maps to the expected arm lifting movement.
- The startup position is approached at a suitable speed and does not cause abrupt movement.
- Servo angles remain within safe mechanical limits.
- Controls are stable around joystick center / deadband, if implemented.

See [Firmware and Controls](../Documentation/FIRMWARE_AND_CONTROLS.md).
