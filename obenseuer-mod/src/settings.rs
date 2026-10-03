use std::sync::OnceLock;

use serde::{Deserialize, Serialize};

use modforge::settings::Settings;

#[derive(Debug, Clone, Default, Serialize, Deserialize)]
pub struct TweaksSettings {
    #[serde(default)]
    pub inventory: InventorySettings,
    #[serde(default)]
    pub stacks: StacksSettings,
    #[serde(default)]
    pub deposit: DepositSettings,
    #[serde(default)]
    pub kept_loaded: KeptLoadedSettings,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct KeptLoadedSettings {
    /// Load the areas the current area's doors lead to alongside it.
    #[serde(default = "default_true")]
    pub auto: bool,
    /// Most areas kept loaded besides the one the player is in.
    #[serde(default = "default_max_areas")]
    pub max_areas: usize,
}

impl Default for KeptLoadedSettings {
    fn default() -> Self {
        Self {
            auto: true,
            max_areas: default_max_areas(),
        }
    }
}

fn default_true() -> bool {
    true
}

fn default_max_areas() -> usize {
    10
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct DepositSettings {
    /// Metres from the player a box may be to receive items.
    #[serde(default = "default_deposit_range")]
    pub range: f64,
}

impl Default for DepositSettings {
    fn default() -> Self {
        Self {
            range: default_deposit_range(),
        }
    }
}

fn default_deposit_range() -> f64 {
    crate::deposit::DEFAULT_RANGE
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
