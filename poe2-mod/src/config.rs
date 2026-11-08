//! The operator's settings in `config.yaml`, as jbot keeps its own
//! (lotj/jbot config.yaml read with serde_yaml): attack and pickup
//! settings, the item rules and which chests to open. The file is read
//! again whenever it changes, so edits need no rebuild or restart; a
//! file that does not parse leaves the last good settings in place.
//!
//! The file is `POE2_MOD_CONFIG` when that is set, else `config.yaml`
//! in this crate's folder.

use crate::{attack, item_rules::ItemRule, pickup};
use anyhow::{Context, Result};
use parking_lot::Mutex;
use serde::{Deserialize, Serialize};
use std::path::PathBuf;
use std::time::SystemTime;

#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
#[serde(default)]
pub struct Config {
    pub attack: attack::Settings,
    pub pickup: pickup::Settings,
    pub rules: Vec<ItemRule>,
    pub chests: Chests,
}

/// Which closed chests pickup opens (ExileCore2 PickIt UpdateChestList).
#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
#[serde(default)]
pub struct Chests {
    pub open: bool,
    pub path_starts: Vec<String>,
    pub path_contains: Vec<String>,
}

impl Chests {
    /// Should a closed chest at `path` be opened?
    pub fn wants(&self, path: &str) -> bool {
        self.open
            && (self
                .path_starts
                .iter()
                .any(|p| path.starts_with(p.as_str()))
                || self.path_contains.iter().any(|p| path.contains(p.as_str())))
    }
}

pub fn path() -> PathBuf {
    std::env::var_os("POE2_MOD_CONFIG")
        .map(PathBuf::from)
        .unwrap_or_else(|| PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("config.yaml"))
}

pub fn parse(text: &str) -> Result<Config> {
    Ok(serde_yaml::from_str(text)?)
}

struct Kept {
    config: Config,
    changed: Option<SystemTime>,
    error: Option<String>,
}

static KEPT: Mutex<Option<Kept>> = Mutex::new(None);

fn modified(p: &PathBuf) -> Option<SystemTime> {
    std::fs::metadata(p).and_then(|m| m.modified()).ok()
}

fn load(p: &PathBuf) -> Result<Config> {
    let text = std::fs::read_to_string(p).with_context(|| format!("read {}", p.display()))?;
    parse(&text).with_context(|| format!("parse {}", p.display()))
}

/// The settings now, read again when the file changed since the last
/// read; with the last read's error, if it failed.
pub fn current() -> (Config, Option<String>) {
    let p = path();
    let stamp = modified(&p);
    let mut g = KEPT.lock();
    let fresh = g
        .as_ref()
        .is_some_and(|k| k.changed == stamp && stamp.is_some());
    if !fresh {
        let read = load(&p);
        let k = g.get_or_insert_with(|| Kept {
            config: Config::default(),
            changed: None,
            error: None,
        });
        k.changed = stamp;
        match read {
            Ok(c) => {
                k.config = c;
                k.error = None;
            }
            Err(e) => k.error = Some(format!("{e:#}")),
        }
    }
    let k = g.as_ref().expect("kept settings");
    (k.config.clone(), k.error.clone())
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::model::{Item, Rarity};

    /// The shipped file parses and its rules take what the operator
    /// asked for (2026-11-07).
    #[test]
    fn the_shipped_file_takes_currency_scrolls_waystones_dear_uniques_and_chests() {
        let c = parse(include_str!("../config.yaml")).expect("config.yaml");
        let take = |path: &str, name: &str, rarity: Option<Rarity>, price: Option<f64>| {
            let i = Item {
                path: path.into(),
                name: name.into(),
                rarity,
                ..Default::default()
            };
            c.rules.iter().any(|r| r.matches(&i, price))
        };
        assert!(take(
            "Metadata/Items/Currency/CurrencyRerollRare",
            "",
            Some(Rarity::Normal),
            None
        ));
        assert!(take(
            "Metadata/Items/Other/Scroll",
            "Scroll of Wisdom",
            Some(Rarity::Normal),
            None
        ));
        assert!(take(
            "Metadata/Items/Waystones/Waystone5",
            "",
            Some(Rarity::Magic),
            None
        ));
        assert!(take(
            "Metadata/Items/Rings/Ring1",
            "",
            Some(Rarity::Unique),
            Some(6.0)
        ));
        assert!(!take(
            "Metadata/Items/Rings/Ring1",
            "",
            Some(Rarity::Unique),
            Some(2.0)
        ));
        assert!(!take(
            "Metadata/Items/Rings/Ring1",
            "",
            Some(Rarity::Unique),
            None
        ));
        assert!(!take(
            "Metadata/Items/Rings/Ring1",
            "",
            Some(Rarity::Rare),
            Some(50.0)
        ));
        assert!(c.chests.wants("Metadata/Chests/Barrel1"));
        assert!(c.chests.wants("Metadata/Terrain/CampsiteChest"));
        assert!(!c.chests.wants("Metadata/Monsters/Wolves/RottenWolf1_"));
        assert_eq!(c.attack.range, 120.0);
        assert_eq!(c.pickup.range, 120.0);
        assert_eq!(c.pickup.margin, [5.0, 3.0]);
    }

    #[test]
    fn a_left_out_field_takes_its_default() {
        let c = parse("pickup: {tries: 5}").expect("parse");
        assert_eq!(c.pickup.tries, 5);
        assert_eq!(
            c.pickup.same_item_ms,
            pickup::Settings::default().same_item_ms
        );
        assert!(c.rules.is_empty());
    }
}
