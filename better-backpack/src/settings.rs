// User-editable settings, read once from <DLL_dir>/settings.json at
// worker init. Missing/malformed file falls back to defaults with a log
// line explaining why.

use std::fs;
use std::path::PathBuf;

use serde::Deserialize;

use crate::bbp_log;
use crate::log::dll_dir;

#[derive(Debug, Clone, Default, Deserialize)]
pub struct Settings {
    #[serde(default)]
    pub inventory: InventorySettings,
    #[serde(default)]
    pub survival: SurvivalSettings,
    #[serde(default)]
    pub rpg: RpgSettings,
}

#[derive(Debug, Clone, Deserialize)]
pub struct InventorySettings {
    #[serde(default = "default_slot_count")]
    pub slot_count: i32,
}

#[derive(Debug, Clone, Deserialize)]
pub struct SurvivalSettings {
    #[serde(default = "default_survival_multiplier")]
    pub thirst_multiplier: f32,
    #[serde(default = "default_survival_multiplier")]
    pub hunger_multiplier: f32,
}

#[derive(Debug, Clone, Deserialize)]
pub struct RpgSettings {
    /// Fraction of base XP awarded when the player's Buggy mount makes
    /// the killing blow. 1.0 = full XP (default per user spec). Set to
    /// 0.5 if you want Buggy kills to count for half, or 0.0 to ignore
    /// them entirely.
    #[serde(default = "default_buggy_kill_xp_multiplier")]
    pub buggy_kill_xp_multiplier: f32,
}

fn default_slot_count() -> i32 {
    // Vanilla baseline. Skills layer additive on top (backpack rank 12
    // adds +60 -> 100). User can set this higher in settings.json for
    // a starter buff.
    40
}

fn default_survival_multiplier() -> f32 {
    // Vanilla baseline (no slowdown). Skills further multiply (hunger/
    // thirst rank 10 -> 0.25x). User can set lower in settings.json
    // for a starter easy mode.
    1.0
}

fn default_buggy_kill_xp_multiplier() -> f32 {
    1.0
}

impl Default for InventorySettings {
    fn default() -> Self {
        Self {
            slot_count: default_slot_count(),
        }
    }
}

impl Default for SurvivalSettings {
    fn default() -> Self {
        Self {
            thirst_multiplier: default_survival_multiplier(),
            hunger_multiplier: default_survival_multiplier(),
        }
    }
}

impl Default for RpgSettings {
    fn default() -> Self {
        Self {
            buggy_kill_xp_multiplier: default_buggy_kill_xp_multiplier(),
        }
    }
}

const SETTINGS_FILE: &str = "settings.json";

pub fn load() -> Settings {
    let Some(path) = settings_path() else {
        bbp_log!("settings: DLL dir unknown, using defaults");
        return Settings::default();
    };
    match fs::read_to_string(&path) {
        Ok(text) => match serde_json::from_str::<Settings>(&text) {
            Ok(s) => {
                bbp_log!("settings: loaded {}", path.display());
                s
            }
            Err(e) => {
                bbp_log!(
                    "settings: parse error in {}: {} -- using defaults",
                    path.display(),
                    e
                );
                Settings::default()
            }
        },
        Err(_) => {
            bbp_log!(
                "settings: {} not found, using defaults",
                path.display()
            );
            Settings::default()
        }
    }
}

fn settings_path() -> Option<PathBuf> {
    let dll_dir = dll_dir()?;
    let local = dll_dir.join(SETTINGS_FILE);
    if local.is_file() {
        return Some(local);
    }

    // Back-compat for installs created before settings.json was moved
    // next to main.dll.
    let legacy = dll_dir.parent()?.join(SETTINGS_FILE);
    if legacy.is_file() {
        bbp_log!(
            "settings: using legacy path {} (move it next to main.dll to match current layout)",
            legacy.display()
        );
        return Some(legacy);
    }

    Some(local)
}

impl Settings {
    pub fn log_summary(&self) {
        bbp_log!(
            "settings: slot_count={}, thirst_mult={:.3}, hunger_mult={:.3}, buggy_xp_mult={:.3}",
            self.inventory.slot_count,
            self.survival.thirst_multiplier,
            self.survival.hunger_multiplier,
            self.rpg.buggy_kill_xp_multiplier
        );
    }
}
