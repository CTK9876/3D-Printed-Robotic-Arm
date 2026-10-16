# Testing, Validation and Engineering Evidence

## Evidence level

The prototype has been assembled and manual movement has been discussed/tested qualitatively. The **published documentation does not yet contain dated quantitative test runs**, so neither the maximum payload nor joint repeatability nor observed smooth-start time is claimed.

## Engineering tests to perform

| ID | Test | Procedure / data to record | Status |
| --- | --- | --- | --- |
| T01 | Safe initial position | Power on unloaded, observe actual first motion and any sudden jump; video and setup version | Not documented |
| T02 | Base motion mapping | Move physical right joystick left/right; note command direction and base response | Not documented |
| T03 | Shoulder motion mapping | Move physical joystick; compare commanded up/down direction with real joint | Not documented |
| T04 | Elbow motion mapping | Move the corresponding stick up/down; verify sign and clearance | Not documented |
| T05 | Gripper cycles | Run ten no-load open/close cycles; record missed engagement or slipping | Not documented |
| T06 | End-stop clearance | Test each software-limited range in safe steps; check for stall/collision | Not documented |
| T07 | Wire routing and base stability | Move through typical poses; observe snags, tilt and cable tension | Not documented |
| T08 | Optional known-mass payload | Log load, extension, controlled pose and success/failure | Not documented |
| T09 | Optional repeatability | Repeat reference pose 5–10 times, record displacement variability | Not documented |

Never substitute source-code angles for measured joint travel. A 270° servo label does not prove 270° of usable arm rotation.

## Existing qualitative engineering observations

- Joystick direction did not initially match the intended physical motions; remapping was investigated.
- On power-up, rapid initial servo motion was reported to disturb balance; code requires correction/validation before claiming smooth startup.
- Servo shaft alignment and printed bracket fitting were design concerns.
- Part orientation, support selection and reprints were considered during FDM fabrication.

## Data collection

Use [`test-log.csv`](test-log.csv) for dated results and the [Engineering Information Checklist](Robotic_Arm_Engineering_Information_Checklist.xlsx) for measurements, verification of hardware specifications and printing settings.

Every claimed metric in the public résumé should have a test method, measurement and associated evidence (photo/video, log or CAD model).