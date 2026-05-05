// Spike B: persisted player RPG state.
//
// Minimal placeholder schema for the spike. Real schema (level, xp,
// perk_ranks, etc.) lands when the level math + perk catalog ship.
//
// Storage: <DLL_dir>/saves/<playthrough-guid>.json. One file per save
// slot, keyed by the stable PlaythroughGuid from USaveGameHeaderData.

use std::fs;
use std::path::PathBuf;

use serde::{Deserialize, Serialize};

use crate::bbp_log;
use crate::log;

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
    /// Unspent perk points.
    #[serde(default)]
    pub perk_points: u32,
    /// Map of perk_id -> rank. Open-shape so we can add perks without
    /// breaking existing save files.
    #[serde(default)]
    pub perk_ranks: std::collections::BTreeMap<String, u32>,

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
                bbp_log!(
                    "rpg/state: parse failed for {} ({}); starting fresh",
                    path.display(),
                    e
                );
                PlayerState::default()
            }
        },
        Err(_) => {
            bbp_log!("rpg/state: no prior save for slot={}; starting fresh", short(slot));
            PlayerState::default()
        }
    }
}

pub fn save(slot: &str, state: &PlayerState) {
    let path = state_path(slot);
    if let Some(parent) = path.parent()
        && let Err(e) = fs::create_dir_all(parent)
    {
        bbp_log!("rpg/state: mkdir {} failed: {}", parent.display(), e);
        return;
    }
    let json = match serde_json::to_string_pretty(state) {
        Ok(j) => j,
        Err(e) => {
            bbp_log!("rpg/state: serialize failed: {}", e);
            return;
        }
    };
    if let Err(e) = fs::write(&path, json) {
        bbp_log!("rpg/state: write {} failed: {}", path.display(), e);
    }
}

fn state_path(slot: &str) -> PathBuf {
    let mut p = log::dll_dir().unwrap_or_else(|| PathBuf::from("."));
    p.push("saves");
    p.push(format!("{slot}.json"));
    p
}

fn short(slot: &str) -> &str {
    if slot.len() >= 8 { &slot[..8] } else { slot }
}
