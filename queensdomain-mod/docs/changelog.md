# queensdomain-mod changelog

## 2026-11-05

- New mod for Queens' Domain (Steam app 1799840, UE 4.27, the first UE4 game in the workspace). Minimal: UE4SS loader, control plane on port 31310, builtin ops, no tabs, no watchers.
- `scripts/restart.ps1` builds, installs UE4SS from Alchemy Factory with every hook off except EngineTick, deploys and launches.
- `tests/research_ustruct_layout.rs` measures the UE 4.27 UStruct and FProperty offsets.
- First launch: UE4SS finds EngineVersion 4.27, patternsleuth resolves, discovery walks 52699 objects (9 data tables, 2600 classes, 1829 structs), control plane answers. Measured PropertiesSize +0x58, ChildProperties +0x50, ArrayDim +0x38, ElementSize +0x3C, Offset_Internal +0x4C, all matching UE4SS's tables. Added to ueforge as `StructLayout::UE4_27`.
