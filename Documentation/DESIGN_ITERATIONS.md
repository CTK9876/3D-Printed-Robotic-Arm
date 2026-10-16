# Engineering challenges and design iterations

A credible portfolio includes **what changed and why**, not only pictures of the finished device. The following entries summarize development topics already discussed; mark any implemented fixes as validated only after inspecting the current code and hardware.

## 1 — Control-axis remapping

**Observation:** A joystick originally made the arm move vertically when commanded sideways, and rotate when commanded vertically.

**Target behavior:** Right/left inputs rotate the arm; up/down inputs raise/lower it.

**Engineering response:** Change the joystick-to-servo axis association and directions in the control program. Verify each physical direction using the latest build.

**Evidence still needed:** Before/after code diff and short demonstration.

## 2 — Rapid startup repositioning

**Observation:** On power-up, the servos moved quickly toward initial commanded positions, disturbing stability.

**Investigation:** Examine startup target assignment and command update rates. If the sketch has no smooth transition, test a bounded ramp while respecting servo operating limits.

**Evidence still needed:** Current code and a power-on video. Do not state the issue was fully resolved without retesting.

## 3 — Servo placement and shaft location

**Observation:** Accurate servo-output-shaft location was important for arm component alignment. Reference servo geometry was used during CAD layout, with some final hole positions planned for physical verification.

**Design lesson:** Confirm commercial-component interface dimensions before finalizing printed mating features.

**Evidence still needed:** Model drawing, measured shaft datum, and assembly close-up.

## 4 — FDM manufacturability and reprints

**Observation:** Multiple printed parts were reviewed for build orientation/support and fit, including the gripper gear, arm plate, spacers, shoulder bracket, controller box, and lid.

**Design lesson:** Part orientation and printer constraints affect assembly quality and repeatability; iterative fabrication is part of the engineering process.

**Evidence still needed:** Slicer profiles, revision photos, and final component list.

## Recommended log format

For each new modification, record:

- **Problem:** What failed or was inadequate?
- **Root cause / hypothesis:** What evidence supports it?
- **Change:** CAD dimensions, hardware adjustment, or code change
- **Test:** How was the change evaluated?
- **Result:** What improved, remained unchanged, or regressed?
- **Artifact:** CAD revision, commit, image, or test video

[Back to README](../README.md)
