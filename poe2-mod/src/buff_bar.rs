//! The player buff bar after GameHelper2's PlayerBuffBar plugin
//! (PlayerBuffBarCore.cs BuildActiveBuffLookup, BuildDisplayEntriesForBar,
//! ToActiveBuffInfo, BuildChargeIconEntries; PlayerBuffBarCore.Totems.cs;
//! BuffIconCatalog.cs MatchesBuffKey; PlayerBuffBarSettings.cs): which
//! watched buffs are on with stacks and time left, the charges and rage,
//! and the player's own totems.

use crate::entities::{Buff, Entity, Stats, stat};
use serde::Serialize;
use std::collections::BTreeMap;

/// PlayerBuffBarSettings.DefaultWatchlist.
pub const DEFAULT_WATCHLIST: [&str; 9] = [
    "blood_rage",
    "fortify",
    "adrenaline",
    "berserk",
    "molten",
    "granite",
    "grace",
    "haste",
    "herald",
];

/// BuffIconCatalog.ReservedResourceWatchIds: shown from stats, not buffs.
pub const RESOURCES: [&str; 4] = ["power_charge", "frenzy_charge", "endurance_charge", "rage"];

/// BuffIconCatalog.SkillBuffKeyAliases.
const ALIASES: [(&str, &[&str]); 1] = [("refutation", &["runic_fortress"])];

/// PlayerBuffBarCore.Totems: the player's totems start with this.
pub const TOTEM_PATH: &str = "metadata/monsters/totems/";

/// ExpandWatchPatterns: the id, with spaces as underscores, without
/// "of", and its aliases, all lower case.
fn patterns(watch: &str) -> Vec<String> {
    let watch = watch.trim().to_lowercase();
    let underscored = watch.replace(' ', "_");
    let without_of = underscored
        .replace("_of_", "_")
        .replace("of_", "")
        .replace("_of", "");
    let mut out = vec![watch.clone(), underscored, without_of];
    if let Some((_, aliases)) = ALIASES.iter().find(|(k, _)| *k == watch) {
        out.extend(aliases.iter().map(|a| a.to_string()));
    }
    out.dedup();
    out
}

/// MatchesBuffKey: the buff's id holds any of the watch id's patterns,
/// ignoring case.
pub fn matches(buff: &str, watch: &str) -> bool {
    if buff.trim().is_empty() || watch.trim().is_empty() {
        return false;
    }
    let buff = buff.to_lowercase();
    patterns(watch).iter().any(|p| buff.contains(p.as_str()))
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Entry {
    pub watch: String,
    pub active: bool,
    /// The buff that matched.
    pub buff: Option<String>,
    pub stacks: i32,
    /// Seconds left, None for buffs that do not run out.
    pub time_left: Option<f32>,
}

/// ToActiveBuffInfo: stacks never below 0, a time only when both times
/// are finite and some is left.
fn active(watch: &str, b: &Buff) -> Entry {
    let finite = b.time_left.is_finite() && b.total_time.is_finite();
    Entry {
        watch: watch.to_string(),
        active: true,
        buff: Some(b.name.clone()),
        stacks: i32::from(b.charges).max(0),
        time_left: (finite && b.time_left > 0.0).then_some(b.time_left),
    }
}

/// One entry per watched id, in watch order: the matching buff with the
/// most stacks, then the most time left; with `show_inactive` the ones
/// not on too. Resource ids are left out.
pub fn entries(buffs: &[Buff], watchlist: &[&str], show_inactive: bool) -> Vec<Entry> {
    let mut out = Vec::new();
    for watch in watchlist {
        let watch = watch.trim();
        if watch.is_empty() || RESOURCES.iter().any(|r| r.eq_ignore_ascii_case(watch)) {
            continue;
        }
        let best = buffs
            .iter()
            .filter(|b| matches(&b.name, watch))
            .map(|b| active(watch, b))
            .reduce(|best, e| {
                let more = e.stacks > best.stacks
                    || (e.stacks == best.stacks
                        && e.time_left.unwrap_or(0.0) > best.time_left.unwrap_or(0.0));
                if more { e } else { best }
            });
        match best {
            Some(e) => out.push(e),
            None if show_inactive => out.push(Entry {
                watch: watch.to_string(),
                active: false,
                buff: None,
                stacks: 0,
                time_left: None,
            }),
            None => {}
        }
    }
    out
}

/// BuildChargeIconEntries: power, frenzy and endurance charges and rage
/// from the stats, the empty ones left out when `hide_empty`.
pub fn resources(stats: &Stats, hide_empty: bool) -> Vec<(&'static str, i32)> {
    [
        ("power_charge", stat::CURRENT_POWER_CHARGES),
        ("frenzy_charge", stat::CURRENT_FRENZY_CHARGES),
        ("endurance_charge", stat::CURRENT_ENDURANCE_CHARGES),
        ("rage", stat::CURRENT_RAGE),
    ]
    .into_iter()
    .map(|(id, s)| (id, stats.get(s).unwrap_or(0)))
    .filter(|(_, n)| !hide_empty || *n > 0)
    .collect()
}

/// A totem's id from its path: the last part before any "@", camel case
/// turned to snake case.
pub fn totem_id(path: &str) -> String {
    let name = path.rsplit('/').next().unwrap_or(path);
    let name = name.split('@').next().unwrap_or(name);
    let mut out = String::new();
    let mut prev: Option<char> = None;
    for c in name.chars() {
        if c.is_ascii_uppercase()
            && prev.is_some_and(|p| p.is_ascii_lowercase() || p.is_ascii_digit())
        {
            out.push('_');
        }
        out.push(c.to_ascii_lowercase());
        prev = Some(c);
    }
    out
}

/// UpdateTotemEntries: the player's living totems among `entities`
/// (those whose id is in `deployed`), counted by totem id.
pub fn totems(deployed: &[u32], entities: &[Entity]) -> BTreeMap<String, u32> {
    let mut out = BTreeMap::new();
    for e in entities {
        if !e.valid
            || !deployed.contains(&e.id)
            || !e.path.to_lowercase().starts_with(TOTEM_PATH)
            || !e.life.is_some_and(|l| l.alive())
        {
            continue;
        }
        *out.entry(totem_id(&e.path)).or_insert(0) += 1;
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::kinds::tests::alive;

    fn buff(name: &str, charges: i16, time_left: f32) -> Buff {
        Buff {
            name: name.into(),
            total_time: 10.0,
            time_left,
            charges,
            flask_slot: -1,
        }
    }

    #[test]
    fn watch_ids_match_like_gamehelper2() {
        assert!(matches("herald_of_ice", "herald"));
        assert!(matches("Blood_Rage", "blood rage"));
        assert!(matches("runic_fortress_buff", "refutation"));
        assert!(!matches("ice_herald", "herald of ice"));
        assert!(matches("grace_period", "grace"));
        assert!(!matches("", "grace"));
    }

    #[test]
    fn the_best_buff_per_watch_and_the_inactive_ones() {
        let buffs = [
            buff("herald_of_ice", 0, f32::INFINITY),
            buff("fortify", 2, 3.0),
            buff("fortify_extra", 2, 5.5),
            buff("power_charge", 3, 9.0),
        ];
        let list = ["fortify", "herald", "haste", "power_charge"];
        let e = entries(&buffs, &list, true);
        assert_eq!(e.len(), 3);
        assert_eq!(
            (e[0].buff.as_deref(), e[0].stacks, e[0].time_left),
            (Some("fortify_extra"), 2, Some(5.5))
        );
        assert_eq!((e[1].active, e[1].time_left), (true, None));
        assert_eq!((e[2].watch.as_str(), e[2].active), ("haste", false));
        assert_eq!(entries(&buffs, &list, false).len(), 2);
    }

    #[test]
    fn charges_rage_and_totems() {
        let mut s = Stats::default();
        s.by_items.insert(stat::CURRENT_FRENZY_CHARGES, 2);
        s.by_buffs_and_actions
            .insert(stat::CURRENT_POWER_CHARGES, 3);
        assert_eq!(
            resources(&s, true),
            [("power_charge", 3), ("frenzy_charge", 2)]
        );
        assert_eq!(resources(&s, false).len(), 4);

        assert_eq!(
            totem_id("Metadata/Monsters/Totems/ShockwaveTotem@3"),
            "shockwave_totem"
        );
        let totem = |id: u32, health: i32| Entity {
            id,
            valid: true,
            path: "Metadata/Monsters/Totems/AncestralWarchief2".into(),
            life: alive(health),
            ..Entity::default()
        };
        let found = totems(
            &[1, 2, 3],
            &[totem(1, 10), totem(2, 0), totem(3, 5), totem(9, 5)],
        );
        assert_eq!(
            found,
            BTreeMap::from([("ancestral_warchief2".to_string(), 2)])
        );
    }
}
