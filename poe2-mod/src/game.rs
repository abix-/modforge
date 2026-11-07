//! Facts about Path of Exile 2 itself.

/// Exe names the game ships under, from GameHelper2's
/// GameOffsets/GameProcessName.cs (Garena uses the plain name).
/// ExileCore2 checks PathOfExile, PathOfExileSteam and PathOfExileEGS.
pub const EXE_NAMES: &[&str] = &[
    "PathOfExile.exe",
    "PathOfExile_KG.exe",
    "PathOfExileSteam.exe",
    "PathOfExile_x64.exe",
    "PathOfExileEGS.exe",
];

/// Control server port, next free after the other mods (17172..17184).
pub const PORT: u16 = 17185;
