# queensdomain-mod todo

- First launch with UE4SS and the mod (`scripts/restart.ps1`). Needs the operator's go, the game restarts.
- Check the boot layout in `src/lib.rs` against the lines UE4SS.log prints at startup: `Found EngineVersion`, `UStruct::PropertiesSize`, `FProperty::ElementSize`, `FProperty::Offset_Internal`, `FUObjectItem::Object`.
- Run `tests/research_ustruct_layout.rs` and record the measured offsets.
- Once measured, add the UE 4.27 layout to `ueforge/src/ue/offsets.rs` next to the UE5 ones.
- `ueforge/src/ue/transform.rs` reads UE5 doubles; UE4 positions are floats at other offsets. Needed before anything places or moves actors.
