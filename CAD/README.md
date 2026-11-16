# Mechanical CAD and printable files

The robotic arm was modeled in **Onshape**. Use the [Onshape source page](Onshape/) to open the assembly and the [CAD Design Gallery](../README.md#cad-design-gallery) to view assembly screenshots and drawing RA-ASM-001.

## Directory layout

```text
CAD/
├── Onshape/             # Link to the source document and assembly
├── STEP/                # Optional neutral CAD exports
├── STL/                 # Meshes positioned/oriented as documented
├── Drawings/            # Assembly drawing and drawing documentation
└── README.md
```

## Publishing checklist

- Keep the Onshape document link with any exported models.
- Name exports by component and function, such as `shoulder_bracket.step` or `gripper_gear_left.stl`.
- Keep printable mesh exports associated with the corresponding Onshape version.
- State revision, unit system, and orientation for each export.
- Add mating/fastener details when known; do not claim unmeasured clearances.
- Remove private institutional information and unrelated files before publishing.

See [Mechanical Design](../Documentation/MECHANICAL_DESIGN.md) and [Manufacturing & Assembly](../Documentation/MANUFACTURING_AND_ASSEMBLY.md).
