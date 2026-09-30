//! The mod's one settings file, thewalkingtrade.json next to the DLL.
//! Written with defaults on first run so it can be edited; watched,
//! so an edit takes effect without a restart.

use std::collections::BTreeMap;
use std::sync::{Arc, OnceLock};
use std::time::Duration;

use modforge::settings::Settings;
use serde::{Deserialize, Serialize};
use unityforge::mono::{LogLevel, log};

#[derive(Serialize, Deserialize, Clone)]
#[serde(default)]
pub struct ModSettings {
    /// How many times its normal area a crafting bench takes materials
    /// from (craft_bench).
    pub craft_bench_multiplier: f64,
    /// Times each skill upgrade was bought again after its first
    /// unlock, keyed "<class>|<upgrade name>" (skill_repeat). One set
    /// for every save.
    pub skill_repeats: BTreeMap<String, u32>,
}

impl Default for ModSettings {
    fn default() -> Self {
        Self {
            craft_bench_multiplier: 50.0,
            skill_repeats: BTreeMap::new(),
        }
    }
}

static SETTINGS: OnceLock<Arc<Settings<ModSettings>>> = OnceLock::new();

pub fn settings() -> &'static Arc<Settings<ModSettings>> {
    SETTINGS.get_or_init(|| Arc::new(Settings::load("thewalkingtrade.json")))
}

pub fn install() {
    let s = settings();
    if let Err(e) = s.save() {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: save settings: {e}"));
    }
    std::mem::forget(s.watch(Duration::from_secs(2), |_| {}));
}
