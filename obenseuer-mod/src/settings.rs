use std::sync::OnceLock;

use serde::{Deserialize, Serialize};

use modforge::settings::Settings;

#[derive(Debug, Clone, Default, Serialize, Deserialize)]
pub struct TweaksSettings {
    #[serde(default)]
    pub inventory: InventorySettings,
    #[serde(default)]
    pub stacks: StacksSettings,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct InventorySettings {
    #[serde(default = "default_slot_count")]
    pub slot_count: i32,
}

impl Default for InventorySettings {
    fn default() -> Self {
        Self {
            slot_count: default_slot_count(),
        }
    }
}

fn default_slot_count() -> i32 {
    crate::tweaks::DEFAULT_SLOT_COUNT
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct StacksSettings {
    #[serde(default = "default_stack_multiplier")]
    pub multiplier: i32,
}

impl Default for StacksSettings {
    fn default() -> Self {
        Self {
            multiplier: default_stack_multiplier(),
        }
    }
}

fn default_stack_multiplier() -> i32 {
    crate::tweaks::DEFAULT_STACK_MULTIPLIER
}

const SETTINGS_FILE: &str = "settings.json";

static SETTINGS: OnceLock<Settings<TweaksSettings>> = OnceLock::new();

pub fn get() -> &'static Settings<TweaksSettings> {
    SETTINGS.get_or_init(|| Settings::load(SETTINGS_FILE))
}
