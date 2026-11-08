//! Loot value: a price for an item, from poe.ninja, in exalted orbs.
//! Copies GameHelper2's LootValue (PoeNinjaPriceFetcher.cs): the same
//! poe.ninja PoE2 endpoints and types, prices kept by item name, uniques
//! by name and base.

use crate::model::{Item, Rarity};
use serde_json::Value;
use std::collections::HashMap;

/// poe.ninja exchange overview types (GameHelper2 NinjaExchangeTypes).
pub const EXCHANGE_TYPES: &[&str] = &[
    "Ritual",
    "Currency",
    "Runes",
    "Idols",
    "Essences",
    "Fragments",
    "Abyss",
    "Breach",
    "Delirium",
    "Expedition",
    "Ultimatum",
    "UncutGems",
];

/// poe.ninja stash item overview types (GameHelper2 NinjaStashTypes).
pub const STASH_TYPES: &[&str] = &[
    "UniqueArmours",
    "UniqueAccessories",
    "UniqueCharms",
    "UniqueWeapons",
];

pub fn exchange_url(league: &str, kind: &str) -> String {
    format!(
        "https://poe.ninja/poe2/api/economy/exchange/current/overview?league={}&type={kind}",
        league_param(league)
    )
}

pub fn stash_url(league: &str, kind: &str) -> String {
    format!(
        "https://poe.ninja/poe2/api/economy/stash/current/item/overview?league={}&type={kind}",
        league_param(league)
    )
}

/// GameHelper2 escapes the league and writes spaces as `+`.
fn league_param(league: &str) -> String {
    league
        .chars()
        .map(|c| match c {
            ' ' => "+".to_string(),
            c if c.is_ascii_alphanumeric() || "-_.~".contains(c) => c.to_string(),
            c => {
                let mut buf = [0u8; 4];
                c.encode_utf8(&mut buf)
                    .bytes()
                    .map(|b| format!("%{b:02X}"))
                    .collect()
            }
        })
        .collect()
}

/// GameHelper2 PoeNinjaPriceFetcher.NormalizeKey: lower case, letters
/// and digits only.
fn key(text: &str) -> String {
    text.to_lowercase()
        .chars()
        .filter(|c| c.is_ascii_lowercase() || c.is_ascii_digit())
        .collect()
}

/// GameHelper2 ExtractIconBasename and ExtractArtBasename: the file name
/// without folder, query or extension.
pub fn file_basename(path: &str) -> &str {
    let path = path.split('?').next().unwrap_or_default();
    let file = path.rsplit(['/', '\\']).next().unwrap_or_default();
    match file.rfind('.') {
        Some(dot) if dot > 0 => &file[..dot],
        _ => file,
    }
}

/// GameHelper2 ArtKeyVariants: art names and poe.ninja disagree on a
/// leading "The", both ways.
fn art_variants(art: &str) -> [String; 2] {
    let other = match art.get(..3) {
        Some(the) if the.eq_ignore_ascii_case("the") && art.len() > 3 => art[3..].to_string(),
        _ => format!("The{art}"),
    };
    [art.to_string(), other]
}

fn unique_key(name: &str, base: &str) -> String {
    format!("{}|{}", key(name), key(base))
}

/// One poe.ninja answer's value in exalted orbs. Values are in the
/// answer's `core.primary` currency; `core.rates.exalted` is exalted
/// orbs per one of it.
fn to_exalted(value: f64, data: &Value) -> Option<f64> {
    let primary = data["core"]["primary"].as_str().unwrap_or("exalted");
    if primary.eq_ignore_ascii_case("exalted") {
        return Some(value);
    }
    data["core"]["rates"]["exalted"]
        .as_f64()
        .filter(|r| *r > 0.0)
        .map(|r| value * r)
}

/// Prices by item, in exalted orbs.
#[derive(Debug, Default)]
pub struct PriceList {
    prices: HashMap<String, f64>,
    /// A unique's name by its icon's file name (GameHelper2 pathNames).
    unique_by_art: HashMap<String, String>,
}

impl PriceList {
    fn add(&mut self, key: String, exalted: f64) {
        if exalted <= 0.0 {
            return;
        }
        let entry = self.prices.entry(key).or_insert(0.0);
        if *entry < exalted {
            *entry = exalted;
        }
    }

    /// An exchange overview: `items` names each `id`, `lines` prices it.
    pub fn add_exchange(&mut self, data: &Value) {
        let names: HashMap<&str, &str> = data["items"]
            .as_array()
            .into_iter()
            .flatten()
            .filter_map(|i| Some((i["id"].as_str()?, i["name"].as_str()?)))
            .collect();
        for line in data["lines"].as_array().into_iter().flatten() {
            let (Some(id), Some(value)) = (line["id"].as_str(), line["primaryValue"].as_f64())
            else {
                continue;
            };
            if let (Some(name), Some(exalted)) = (names.get(id), to_exalted(value, data)) {
                self.add(key(name), exalted);
            }
        }
    }

    /// A stash item overview of uniques: each line has its name and base.
    pub fn add_stash(&mut self, data: &Value) {
        for line in data["lines"].as_array().into_iter().flatten() {
            let (Some(name), Some(value)) = (line["name"].as_str(), line["primaryValue"].as_f64())
            else {
                continue;
            };
            let base = line["baseType"].as_str().unwrap_or_default();
            if let Some(icon) = line["icon"].as_str() {
                let art = key(file_basename(icon));
                if !art.is_empty() {
                    self.unique_by_art.insert(art, name.to_string());
                }
            }
            if let Some(exalted) = to_exalted(value, data) {
                self.add(unique_key(name, base), exalted);
                self.add(key(name), exalted);
            }
        }
    }

    /// A unique's name from its art file's name, trying it with and
    /// without a leading "The" (GameHelper2 LootValue TryPriceItem).
    pub fn unique_name(&self, art: &str) -> Option<&str> {
        art_variants(art)
            .iter()
            .find_map(|a| self.unique_by_art.get(&key(a)))
            .map(String::as_str)
    }

    /// Price of one of `item`, in exalted orbs. A unique is looked up by
    /// its name (or the name its art gives) and base, then that name;
    /// anything else by its base.
    pub fn each(&self, item: &Item) -> Option<f64> {
        if item.rarity == Some(Rarity::Unique) {
            let name = if item.name.is_empty() {
                self.unique_name(&item.art)?
            } else {
                item.name.as_str()
            };
            return self
                .prices
                .get(&unique_key(name, &item.base))
                .or_else(|| self.prices.get(&key(name)))
                .copied();
        }
        self.prices.get(&key(&item.base)).copied()
    }

    /// Price of the whole stack.
    pub fn stack(&self, item: &Item) -> Option<f64> {
        self.each(item).map(|p| p * f64::from(item.stack.max(1)))
    }

    /// How many items have a price.
    pub fn count(&self) -> usize {
        self.prices.len()
    }
}

/// Fetch every exchange and stash overview for `league`. A type that
/// fails is skipped and named in the second value.
pub fn fetch(league: &str) -> (PriceList, Vec<String>) {
    let mut list = PriceList::default();
    let mut failed = Vec::new();
    let get = |url: &str| -> Result<Value, String> {
        let mut response = ureq::get(url).call().map_err(|e| e.to_string())?;
        let text = response
            .body_mut()
            .read_to_string()
            .map_err(|e| e.to_string())?;
        serde_json::from_str(&text).map_err(|e| e.to_string())
    };
    for kind in EXCHANGE_TYPES {
        match get(&exchange_url(league, kind)) {
            Ok(data) => list.add_exchange(&data),
            Err(e) => failed.push(format!("exchange {kind}: {e}")),
        }
    }
    for kind in STASH_TYPES {
        match get(&stash_url(league, kind)) {
            Ok(data) => list.add_stash(&data),
            Err(e) => failed.push(format!("stash {kind}: {e}")),
        }
    }
    (list, failed)
}

#[cfg(test)]
mod tests {
    use super::*;
    use serde_json::json;

    fn item(name: &str, base: &str, rarity: Rarity, stack: u32) -> Item {
        Item {
            name: name.into(),
            base: base.into(),
            rarity: Some(rarity),
            stack,
            ..Item::default()
        }
    }

    #[test]
    fn exchange_prices_convert_from_divine() {
        let mut list = PriceList::default();
        list.add_exchange(&json!({
            "core": {"primary": "divine", "rates": {"exalted": 80.0}},
            "items": [{"id": "div", "name": "Divine Orb"}, {"id": "ex", "name": "Exalted Orb"}],
            "lines": [{"id": "div", "primaryValue": 1.0}, {"id": "ex", "primaryValue": 0.0125}],
        }));
        let divine = item("", "Divine Orb", Rarity::Normal, 3);
        assert_eq!(list.each(&divine), Some(80.0));
        assert_eq!(list.stack(&divine), Some(240.0));
        assert_eq!(
            list.each(&item("", "exalted orb", Rarity::Normal, 1)),
            Some(1.0)
        );
        assert_eq!(list.each(&item("", "Chaos Orb", Rarity::Normal, 1)), None);
    }

    #[test]
    fn divine_answer_without_rate_is_skipped() {
        let mut list = PriceList::default();
        list.add_exchange(&json!({
            "core": {"primary": "divine"},
            "items": [{"id": "div", "name": "Divine Orb"}],
            "lines": [{"id": "div", "primaryValue": 1.0}],
        }));
        assert_eq!(list.count(), 0);
    }

    #[test]
    fn uniques_by_name_and_base_then_name() {
        let mut list = PriceList::default();
        list.add_stash(&json!({
            "core": {"primary": "exalted"},
            "lines": [
                {"name": "Headhunter", "baseType": "Heavy Belt", "primaryValue": 500.0},
                {"name": "Headhunter", "baseType": "Other Belt", "primaryValue": 300.0},
            ],
        }));
        assert_eq!(
            list.each(&item("Headhunter", "Heavy Belt", Rarity::Unique, 1)),
            Some(500.0)
        );
        assert_eq!(
            list.each(&item("Headhunter", "Other Belt", Rarity::Unique, 1)),
            Some(300.0)
        );
        // Unknown base: falls back to the name, which keeps the highest.
        assert_eq!(
            list.each(&item("Headhunter", "New Belt", Rarity::Unique, 1)),
            Some(500.0)
        );
        // A rare with that base is not priced as the unique.
        assert_eq!(list.each(&item("", "Heavy Belt", Rarity::Rare, 1)), None);
    }

    #[test]
    fn unidentified_unique_named_by_its_art() {
        let mut list = PriceList::default();
        list.add_stash(&json!({
            "core": {"primary": "exalted"},
            "lines": [{
                "name": "The Road Warrior",
                "baseType": "Leather Vest",
                "primaryValue": 12.0,
                "icon": "https://web.poecdn.com/gen/image/abc/RoadWarrior.png?scale=1",
            }],
        }));
        assert_eq!(list.unique_name("TheRoadWarrior"), Some("The Road Warrior"));
        assert_eq!(list.unique_name("RoadWarrior"), Some("The Road Warrior"));
        let item = Item {
            base: "Leather Vest".into(),
            rarity: Some(Rarity::Unique),
            stack: 1,
            art: "TheRoadWarrior".into(),
            ..Item::default()
        };
        assert_eq!(list.each(&item), Some(12.0));
    }

    #[test]
    fn keys_and_basenames_like_gamehelper2() {
        assert_eq!(key("  Orb of  Alchemy's! "), "orbofalchemys");
        assert_eq!(
            file_basename("Art/2DItems/Armours/RoadWarrior.dds"),
            "RoadWarrior"
        );
        assert_eq!(file_basename("a\\b\\c.png?x=1"), "c");
    }

    #[test]
    fn league_is_escaped_like_gamehelper2() {
        assert_eq!(
            exchange_url("Forbidden Rites", "Currency"),
            "https://poe.ninja/poe2/api/economy/exchange/current/overview?league=Forbidden+Rites&type=Currency"
        );
        assert_eq!(league_param("A&B"), "A%26B");
    }
}
