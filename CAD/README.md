# Mechanical CAD and printable files

The robotic arm was modeled in **SolidWorks**. Add the original design and exports here when available.

## Suggested directory layout

```text
CAD/
├── SolidWorks/          # .SLDPRT and .SLDASM, plus referenced components
├── STEP/                # Optional neutral CAD exports
├── STL/                 # Meshes positioned/oriented as documented
├── Drawings/            # PDF drawings with dimensions/tolerances
└── README.md
```

> Git does not track empty directories. These subdirectories will appear after the first relevant file is uploaded.

## Publishing checklist

- Preserve original assembly-to-part references; use **Pack and Go** if the assembly references files in multiple local directories.
- Make part names self-explanatory (e.g. `shoulder_bracket.SLDPRT`, `gripper_gear_left.stl`).
- Keep editable source CAD as well as printer-ready exports.
- State revision, unit system, and orientation for each export.
- Add mating/fastener details when known; do not claim unmeasured clearances.
- Remove private institutional information and unrelated files before publishing.

See [Mechanical Design](../Documentation/MECHANICAL_DESIGN.md) and [Manufacturing & Assembly](../Documentation/MANUFACTURING_AND_ASSEMBLY.md).
