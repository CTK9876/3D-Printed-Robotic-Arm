# 3D-Printed Robotic Arm

### Mechanical Design | Additive Manufacturing | Electronics | Embedded Programming

## Project Overview

This project involves the design, manufacturing, assembly, and programming of a custom 3D-printed robotic arm controlled using analog joysticks.

The robotic arm was designed in **SolidWorks**, manufactured using a **Bambu Lab P1S 3D printer**, and integrated with servo motors and an Arduino-based control system.

The main objective was to develop a functional robotic arm from the ground up while gaining hands-on experience in mechanical design, electronics integration, additive manufacturing, and embedded programming.

Rather than using a pre-existing robotic arm kit, the mechanical structure was custom-designed, allowing greater flexibility in component placement, assembly, and future modifications.

## Key Features

- Custom-designed mechanical components modeled in SolidWorks
- FDM 3D-printed structural components
- Servo-driven robotic arm joints
- Gear-driven mechanical gripper
- Dual-joystick manual control
- PCA9685 PWM servo driver integration
- Custom control software written in Arduino/C++
- Dedicated enclosure for electronic components
- Iterative mechanical and software improvements

## Mechanical Design

The mechanical structure was developed using SolidWorks, with an emphasis on manufacturability, assembly, and integration with electronic components.

Major components include:

- **Base:** Supports the robotic arm and its rotational movement.
- **Shoulder Assembly:** Connects the base to the main arm structure.
- **Arm and Forearm:** Custom-designed structural components.
- **Gripper:** Gear-driven mechanism designed to open and close using a servo motor.
- **Mounting Brackets:** Custom brackets for servo placement and mechanical connections.
- **Control Enclosure:** Houses the electronic components and user controls.

The design process involved considering component dimensions, mounting positions, mechanical clearances, and the limitations of FDM 3D printing.

## Electronics and Control System

The electronic system uses a microcontroller and a PCA9685 PWM servo driver to control the servo motors.

Two analog joysticks provide manual input, allowing the user to control different movements of the robotic arm.

The control software converts joystick inputs into servo position commands.

The system also incorporates startup positioning and movement-control adjustments.

## Manufacturing and Assembly

The mechanical components were manufactured using a Bambu Lab P1S FDM 3D printer.

During the manufacturing process, multiple considerations influenced the final design:

- Print orientation and support requirements
- Structural integrity of printed components
- Screw holes and mechanical fastening
- Servo mounting and shaft alignment
- Component fit and assembly accessibility
- Reprinting and modifying components when necessary

The project required translating CAD models into physical components and evaluating how well the designs performed after manufacturing.

## Engineering Challenges and Design Improvements

### Servo Movement and Startup Behavior

Initial testing revealed that rapid servo positioning during startup could affect the stability of the robotic arm.

This motivated adjustments to the control software to improve movement behavior.

### Joystick Direction Mapping

The initial joystick configuration did not correspond intuitively to the desired robotic arm movements.

The software was adjusted to improve the relationship between joystick directions and arm movement.

### Mechanical Integration

Integrating servo motors into custom-designed structures required attention to mounting geometry, mechanical alignment, and available clearances.

### Design for Additive Manufacturing

Several components required consideration of printing orientation, support structures, and assembly limitations.

These challenges provided opportunities to improve the design through iterative prototyping.

## Tools and Technologies

| Category | Tools / Technologies |
|---|---|
| CAD Software | SolidWorks |
| Manufacturing | Bambu Lab P1S, FDM 3D Printing |
| Programming | Arduino / C++ |
| Motor Control | PCA9685 PWM Servo Driver |
| Actuators | Servo Motors |
| User Input | Analog Joysticks |
| Mechanical Design | Custom Brackets, Joints, Gears |
| Prototyping | Iterative Design and Testing |

## Project Documentation

This repository is intended to contain:

- SolidWorks CAD models and assembly files
- STL files for 3D printing
- Arduino source code
- Electronics wiring documentation
- Mechanical design images
- Manufacturing and assembly photographs
- Engineering design report
- Testing observations and design revisions

## Future Improvements

Potential future developments include:

- Further optimization of mechanical components
- Improved servo movement and control smoothness
- Additional testing of mechanical performance
- Improvements to the gripper mechanism
- Exploration of automated movement sequences

## Project Skills Demonstrated

This project demonstrates practical experience in:

- Mechanical Design and 3D CAD Modeling
- Design for Additive Manufacturing (DfAM)
- Rapid Prototyping
- Mechanical Assembly
- Electronics Integration
- Embedded Programming
- Troubleshooting and Design Iteration
- Mechatronics System Development
