// Persisted player RPG state.
//
// Schema: xp / level / skill_points / skill_levels plus diagnostic
// counters (kill_count, last_killed). "Skill" / "skill point" /
// "skill level" naming follows the dominant Factorio-RPG convention
// (RPG System mod) and matches Diablo expectations.
//
// Storage: <DLL_dir>/saves/<playthrough-guid>.json. One file per save
// slot, keyed by the stable PlaythroughGuid from AInGameGameState.

use std::fs;
use std::path::PathBuf;

use serde::{Deserialize, Serialize};


#[derive(Debug, Clone, Default, Serialize, Deserialize)]
pub struct PlayerState {
    /// Cumulative XP earned. Levels are derived from this via the
    /// curve in `rpg::xp`.
    #[serde(default)]
    pub xp: u64,
    /// Highest level granted so far. Stored separately from `xp` so a
    /// curve change doesn't retroactively de-level the player.
    #[serde(default)]
    pub level: u32,
    /// Unspent skill points. (Naming follows Diablo / Factorio's
    /// `RPG System` convention.)
    #[serde(default)]
    pub skill_points: u32,
    /// Map of skill_id -> level (how many points the player has spent
    /// on this skill). Open-shape so we can add skills without
    /// breaking existing save files.
    #[serde(default)]
    pub skill_levels: std::collections::BTreeMap<String, u32>,

    /// Total kills (any source: player + Buggy). Diagnostic only.
    #[serde(default)]
    pub kill_count: u64,
    /// Last creature class killed -- diagnostic, lets a reload show
    /// persistence without grepping for an exact count.
    #[serde(default)]
    pub last_killed: String,
}

/// Reads PlayerState for `slot` from disk. Returns default if the file
/// is missing or unparseable. Logs the outcome.
pub fn load_one(slot: &str) -> PlayerState {
    let path = state_path(slot);
    match fs::read_to_string(&path) {
        Ok(text) => match serde_json::from_str::<PlayerState>(&text) {
            Ok(s) => s,
            Err(e) => {
                ueforge::log!(
                    "rpg/state: parse failed for {} ({}); starting fresh",
                    path.display(),
                    e
                );
                PlayerState::default()
            }
        },
        Err(_) => {
            ueforge::log!(
                "rpg/state: no prior save for slot={}; starting fresh",
                short(slot)
            );
            PlayerState::default()
        }
    }
}

pub fn save(slot: &str, state: &PlayerState) {
    let path = state_path(slot);
    if let Some(parent) = path.parent()
        && let Err(e) = fs::create_dir_all(parent)
    {
        ueforge::log!("rpg/state: mkdir {} failed: {}", parent.display(), e);
        return;
    }
    let json = match serde_json::to_string_pretty(state) {
        Ok(j) => j,
        Err(e) => {
            ueforge::log!("rpg/state: serialize failed: {}", e);
            return;
        }
    };
    if let Err(e) = fs::write(&path, json) {
        ueforge::log!("rpg/state: write {} failed: {}", path.display(), e);
    }
}

fn state_path(slot: &str) -> PathBuf {
    let mut p = ueforge::log::dll_dir().unwrap_or_else(|| PathBuf::from("."));
    p.push("saves");
    p.push(format!("{slot}.json"));
    p
}

fn short(slot: &str) -> &str {
    if slot.len() >= 8 { &slot[..8] } else { slot }
}
