// inject.json next to inject.exe. Drives auto-launch behavior.
//
// Schema:
//   {
//     "launch": {
//       "steam_app_id": 3104110,
//       "fallback_exe": "",
//       "poll_interval_ms": 500,
//       "poll_timeout_sec": 120
//     }
//   }
//
// All keys optional. Missing or malformed file -> hardcoded defaults.

use std::env;
use std::fs;
use std::path::PathBuf;

use serde::Deserialize;

use crate::log_line;

#[derive(Debug, Clone, Deserialize, Default)]
pub struct Config {
    #[serde(default)]
    pub launch: LaunchConfig,
}

#[derive(Debug, Clone, Deserialize)]
pub struct LaunchConfig {
    /// Grounded 2 Steam app id. Default is the public Steam app id.
    /// Set to 0 to disable Steam launch.
    #[serde(default = "default_steam_app_id")]
    pub steam_app_id: u32,
    /// Optional direct path to the game exe. Used as a fallback if Steam
    /// launch fails or steam_app_id is 0.
    #[serde(default)]
    pub fallback_exe: String,
    /// How often to check whether the game process appeared.
    #[serde(default = "default_poll_interval")]
    pub poll_interval_ms: u64,
    /// How long to wait before giving up on the launch.
    #[serde(default = "default_poll_timeout")]
    pub poll_timeout_sec: u64,
}

impl Default for LaunchConfig {
    fn default() -> Self {
        Self {
            steam_app_id: default_steam_app_id(),
            fallback_exe: String::new(),
            poll_interval_ms: default_poll_interval(),
            poll_timeout_sec: default_poll_timeout(),
        }
    }
}

fn default_steam_app_id() -> u32 {
    // Grounded 2 on Steam. Override in inject.json if this is ever wrong.
    3_104_110
}

fn default_poll_interval() -> u64 {
    500
}

fn default_poll_timeout() -> u64 {
    120
}

const CONFIG_FILE: &str = "inject.json";

pub fn load() -> Config {
    let Some(path) = config_path() else {
        return Config::default();
    };
    match fs::read_to_string(&path) {
        Ok(text) => match serde_json::from_str::<Config>(&text) {
            Ok(c) => {
                log_line("[+] ", &format!("config: loaded {}", path.display()));
                c
            }
            Err(e) => {
                log_line(
                    "[!] ",
                    &format!(
                        "config: parse error in {}: {} -- using defaults",
                        path.display(),
                        e
                    ),
                );
                Config::default()
            }
        },
        Err(_) => Config::default(),
    }
}

fn config_path() -> Option<PathBuf> {
    let mut p = env::current_exe().ok()?;
    p.pop();
    p.push(CONFIG_FILE);
    Some(p)
}
