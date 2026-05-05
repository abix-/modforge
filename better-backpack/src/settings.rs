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
}

#[derive(Debug, Clone, Deserialize)]
pub struct InventorySettings {
    #[serde(default = "default_slot_count")]
    pub slot_count: i32,
}

#[derive(Debug, Clone, Deserialize)]
pub struct SurvivalSettings {
    #[serde(default = "default_one")]
    pub thirst_multiplier: f32,
    #[serde(default = "default_one")]
    pub hunger_multiplier: f32,
}

fn default_slot_count() -> i32 {
    100
}

fn default_one() -> f32 {
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
            thirst_multiplier: default_one(),
            hunger_multiplier: default_one(),
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
    Some(dll_dir()?.join(SETTINGS_FILE))
}

impl Settings {
    pub fn log_summary(&self) {
        bbp_log!(
            "settings: slot_count={}, thirst_mult={:.3}, hunger_mult={:.3}",
            self.inventory.slot_count,
            self.survival.thirst_multiplier,
            self.survival.hunger_multiplier
        );
    }
}
