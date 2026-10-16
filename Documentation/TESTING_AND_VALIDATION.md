# Testing and validation

This file separates **observed prototype behavior** from **formal test results**. No numeric performance claim should be published until it has been measured.

## Qualitative observations from development

| Topic | Observation | Result status |
| --- | --- | --- |
| Joystick-to-joint mapping | Initial mapping did not match desired up/down and left/right motion | Software adjustment discussed; retest against latest sketch |
| Startup behavior | Rapid initial servo movement could disturb stability | Needs documented retest / confirmation |
| Servo placement | Mechanical fit and shaft location affected mounting decisions | Verify against CAD and final assembly |
| 3D-printed parts | Print orientation, supports, and fit influenced iterations | Record final profile and part revisions |

## Recommended acceptance tests

| Test ID | Test method | Evidence to collect | Status |
| --- | --- | --- | --- |
| T01 | Power up with the arm clear of obstacles | Video, final initial pose, unexpected motion | Not documented |
| T02 | Move right joystick in all four directions | Video and observed joint direction | Not documented |
| T03 | Sweep each joint across intended motion range | Angle readings and interference notes | Not documented |
| T04 | Open and close gripper repeatedly, unloaded | Smooth motion, sticking, gear engagement | Not documented |
| T05 | Repeat movement sequence several times | Consistency observations / measured variation | Not documented |
| T06 | Check wiring during full movement | Snagging, connector strain, loose cables | Not documented |
| T07 | Observe base stability during fast/extended poses | Tilt, slip, mounting issues | Not documented |
| T08 | Optional payload trials with measured masses | Maximum repeatably handled mass and conditions | Not documented |

## Test log template

Create a new row in [test-log.csv](test-log.csv) for each test run. Use dates, the actual firmware revision, and any relevant print/assembly configuration.

For every test, write *PASS*, *FAIL*, or *NOT RUN* only after completing the procedure. Do not use an empty status as proof of passing.

## Quantitative data currently unavailable

Joint travel, robot reach, payload, servo torque margin, gripper force, electrical draw, repeatability, and startup time are not presently measured for the public documentation.

[Back to README](../README.md)
