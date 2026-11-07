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

/// A pattern that finds one of the game's global addresses: the
/// instruction that uses it, with `|` on its 4-byte RIP-relative
/// operand. Both tools write `^` there; it is `|` here because that is
/// patternsleuth's mark.
pub struct StaticPattern {
    pub name: &'static str,
    /// The tool it was copied from, and where.
    pub source: &'static str,
    pub sig: &'static str,
}

/// From GameHelper2 GameOffsets/StaticOffsetsPatterns.cs, and ExileCore2
/// PoEMemory.Offsets..cctor (read from its disassembly). The two tools
/// match different instructions for some of the same globals, so a name
/// found by both is a check that we read the right place.
pub const STATIC_PATTERNS: &[StaticPattern] = &[
    StaticPattern {
        name: "Game States",
        source: "GameHelper2 StaticOffsetsPatterns.cs",
        sig: "48 39 2D | ?? ?? ?? ?? 0F 85 ?? ?? ?? ?? B9 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 8B F8 48 89 44 24 50",
    },
    StaticPattern {
        name: "Game States",
        source: "ExileCore2 Offsets \"Game State\"",
        sig: "83 ?? ?? ?? 8B ?? 33 ?? ?? 39 ?? | ?? ?? ?? ?? 0F 85 ?? ?? ?? ?? ?? ?? ?? ?? ?? E8 ?? ?? ?? ??",
    },
    StaticPattern {
        name: "File Root",
        source: "GameHelper2 StaticOffsetsPatterns.cs",
        sig: "48 8D 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 8B 05 | ?? ?? ?? ?? 48 83 C4 28",
    },
    StaticPattern {
        name: "File Root",
        source: "ExileCore2 Offsets \"File Root\"",
        sig: "33 ?? ?? 89 ?? | ?? ?? ?? ?? ?? 8B ?? ?? 8B ?? ?? ?? ?? 8B ?? ?? ?? ?? 8B ?? ?? ?? 0F 28 ?? ?? ?? ?? 83",
    },
    StaticPattern {
        name: "AreaChangeCounter",
        source: "GameHelper2 StaticOffsetsPatterns.cs",
        sig: "FF 05 | ?? ?? ?? ?? 4D 8B 06",
    },
    StaticPattern {
        name: "AreaChangeCounter",
        source: "ExileCore2 Offsets \"Area change\"",
        sig: "E8 ?? ?? ?? ?? FF ?? | ?? ?? ?? ?? ?? 8B ?? ?? 8D ?? ?? ?? 0F B6 ?? ?? ?? ?? ??",
    },
    StaticPattern {
        name: "Terrain Rotator Helper",
        source: "GameHelper2 StaticOffsetsPatterns.cs",
        sig: "48 83 EC 38 41 0F B6 C0 4C 8B D1 4C 8B CA 48 8D 0D ?? ?? ?? ?? 44 0F B6 04 08 B8 08 00 00 00 8B 0A 44 3B C0 89 4C 24 24 BA 16 00 00 00 44 0F 47 C0 48 8D 05 | ?? ?? ?? ??",
    },
    StaticPattern {
        name: "Terrain Rotation Selector",
        source: "GameHelper2 StaticOffsetsPatterns.cs",
        sig: "48 83 EC 38 41 0F B6 C0 4C 8B D1 4C 8B CA 48 8D 0D | ?? ?? ?? ??",
    },
    StaticPattern {
        name: "GameCullSize",
        source: "GameHelper2 StaticOffsetsPatterns.cs",
        sig: "2B 0D ?? ?? ?? ?? 8B 05 ?? ?? ?? ?? 2B 05 | ?? ?? ?? ?? 0F 57 FF",
    },
];

/// Game states, from GameHelper2 GameOffsets/Objects/GameStateOffsets.cs
/// and RemoteObjects/GameStates.cs. The "Game States" global holds a
/// pointer to this object.
pub mod game_states {
    /// A std::vector of state pointers; the current state is the one
    /// 0x10 before its end (GameHelper2 reads `Last - 0x10`).
    pub const CURRENT_STATE_VECTOR: u64 = 0x10;
    pub const CURRENT_STATE_FROM_END: u64 = 0x10;
    /// Thirteen (state pointer, second pointer) pairs, 16 bytes each.
    pub const STATES: u64 = 0x50;
    pub const STATE_STRIDE: u64 = 0x10;

    /// In the order the STATES array holds them (GameHelper2
    /// RemoteEnums/GameStateTypes.cs).
    pub const NAMES: [&str; 13] = [
        "AreaLoadingState",
        "ChangePasswordState",
        "CreditsState",
        "EscapeState",
        "InGameState",
        "PreGameState",
        "LoginState",
        "WaitingState",
        "CreateCharacterState",
        "SelectCharacterState",
        "DeleteCharacterState",
        "LoadingState",
        "UnknownState",
    ];
}
