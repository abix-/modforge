# terrainvicta-mod research

Game: Terra Invicta (Pavonis Interactive, Steam AppID 1176470).

## install facts

Read from the install at `C:\Games\Steam\steamapps\common\Terra Invicta`.

| Fact | Value | Source |
|---|---|---|
| Engine | Unity 2020.3.49f1 | version string in `TerraInvicta_Data/globalgamemanagers` |
| Runtime | Mono | `MonoBleedingEdge/` folder, `TerraInvicta_Data/Managed/Assembly-CSharp.dll` |
| Exe | `TerraInvicta.exe` | install root |
| Mod loader | none installed | no `BepInEx/` folder, no `winhttp.dll` |
| Game mod folder | `Mods/Enabled`, `Mods/Disabled` (both empty) | install root |
| Control plane port | 17179 | `src/lib.rs` |

## type system

Not probed yet. See todo 4.
