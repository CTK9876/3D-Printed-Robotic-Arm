# Mechanical design

## Objective

Create a custom printable arm structure that integrates commercial servo motors, permits assembly/maintenance, and supports manually controlled multi-joint movement and gripper actuation.

## CAD environment

- **Platform:** SolidWorks
- **Fabrication method:** FDM 3D printing (Bambu Lab P1S)
- **Design approach:** Components modeled for assembly, mounting interfaces, and later adjustment

## Subassemblies

| Subassembly | Function | Design considerations |
| --- | --- | --- |
| Base | Supports arm and rotation interface | Stability, joint clearance, attachment to base |
| Shoulder / bracket | Transfers load from base to arm | Servo placement, mounting-hole access, alignment |
| Arm / forearm links | Connect actuated joints | Link stiffness, weight, fasteners, print orientation |
| Gripper | Opens/closes end-effector jaws with gears | Gear meshing, finger attachment, servo alignment |
| Spacers / standoffs | Establish assembly spacing | Correct hole alignment and fastener length |
| Controller box + lid | Encloses user controls/electronics | Joystick clearance, standoffs, service access |

## Mechanical engineering choices

### Modularity and assembly

Separate structural components and fasteners allow parts to be printed individually and replaced after fit checks. Shoulder mounting and multi-plate link concepts were explored during CAD development. The detailed final geometry must be confirmed against the published CAD.

### Actuator alignment

For servo-mounted components, the position of the output shaft relative to the case and bracket matters. CAD placement was checked using servo reference geometry, with physical hole/shaft location validation part of the prototyping process.

### Gripper actuation

The design uses a servo-driven geared gripper. Gear alignment, finger fixation, and motion clearance are essential assembly considerations. Tooth counts, ratios, travel, and gripping force are **not measured here**.

### Design for FDM

Consider each part's build orientation, support accessibility, wall strength, holes, and fitting surfaces before slicing. Avoid treating printer default tolerances as guaranteed fits.

## Engineering evidence to add

- Native SolidWorks assembly and parts, plus a full assembly screenshot
- Dimensioned drawings of the base, shoulder bracket, linkages, and gripper
- Exploded view and actual fastener table
- Joint-axis locations and range of motion (measured)
- Mass/center-of-gravity assessment (if performed)

## Current limitations

Without released CAD and measurements, this document does **not** claim exact dimensions, structural factors of safety, payload capacity, joint torques, or gripper force.

[Back to project homepage](../README.md)
