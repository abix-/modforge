//! Mod-wide persistent settings, backed by
//! `<DLL_dir>/tweaks.json`. Each feature gets its own nested
//! struct under `TweaksSettings`. Schema is forward-compatible
//! via `#[serde(default)]` on every field, so adding new fields
//! in later versions doesn't break existing user files.

use std::sync::OnceLock;

use serde::{Deserialize, Serialize};

use uespy::settings::Settings;

#[derive(Debug, Clone, Default, Serialize, Deserialize)]
pub struct TweaksSettings {
    #[serde(default)]
    pub stacks: StacksSettings,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct StacksSettings {
    #[serde(default = "default_multiplier")]
    pub multiplier: i32,
}

impl Default for StacksSettings {
    fn default() -> Self {
        Self {
            multiplier: default_multiplier(),
        }
    }
}

fn default_multiplier() -> i32 {
    crate::stacks::DEFAULT_MULTIPLIER
}

const SETTINGS_FILE: &str = "settings.json";

static SETTINGS: OnceLock<Settings<TweaksSettings>> = OnceLock::new();

pub fn get() -> &'static Settings<TweaksSettings> {
    SETTINGS.get_or_init(|| Settings::load(SETTINGS_FILE))
}
