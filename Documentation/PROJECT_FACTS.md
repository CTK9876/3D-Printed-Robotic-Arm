# Verified vs. Pending Project Specifications

## Source-verified firmware facts

- Four PCA9685 output channels: 0 shoulder, 1 base, 2 elbow, 3 gripper.
- Arduino analog inputs: A0 shoulder, A1 base, A2 gripper, A3 elbow.
- PWM frequency: 50 Hz; pulse mapping window: 100–650 driver counts.
- Start commands: base 135°, shoulder 90°, elbow 90°, gripper 90°.
- Software clamps: base 10–260°, shoulder 20–160°, elbow 20–160°, gripper 30–120°.
- Deadzones: 70 ADC counts for arm axes, 50 for gripper.
- Loop `delay(10)`; `Serial.begin(9600)`.
- Current startup `slowMove...()` calls do **not** create a multi-step ramp (start equals target).

## Project facts observed or described

- Custom CAD developed in SolidWorks.
- Printed components produced using a Bambu Lab P1S.
- Assembled physical robotic arm with base, mechanical links, gripper, and separate two-joystick controller.
- Real assembled-prototype photos are in [`Images/Final-Assembly`](../Images/Final-Assembly/).

## Still needs confirmation

- [ ] Exact MCU and actuator models, torque/rated voltage
- [ ] Servo PSU voltage/current and verified as-built schematic
- [ ] Physical joint axis count and usable rotation ranges
- [ ] Overall dimensions, reach, total mass, gripper jaw opening
- [ ] Filament type and slicer profiles
- [ ] Native CAD/STEP/STL source and revisions
- [ ] Formal startup, joint travel, gripper and stability test results
- [ ] Demo video demonstrating actual operation

**Fill the linked [Excel workbook](Robotic_Arm_Engineering_Information_Checklist.xlsx)** to supply these in a structured, verifiable format. Avoid guessing numerical specifications.