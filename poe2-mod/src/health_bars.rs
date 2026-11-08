//! Health bars over entities after GameHelper2's HealthBars plugin
//! (HealthBars.cs DrawUI, DrawHealthbar, CombinedHealthPercent;
//! HealthBarsSettings.cs): which entities get a bar, which style, where
//! it sits and how full it is.

use crate::entities::{Entity, Life};
use crate::kinds::{Kind, State, Subtype, Type};
use crate::model::Rarity;
use serde::Serialize;

/// HealthBarsSettings.CullingStrikeRangePerRarity, percent of health by
/// rarity (normal, magic, rare, unique).
pub const CULL_PERCENT: [i32; 4] = [30, 20, 10, 5];

/// The settings entry a bar is drawn with (Settings.Player and
/// Settings.Monster keys).
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize)]
pub enum Style {
    PlayerSelf,
    PlayerLeader,
    PlayerMember,
    Friendly,
    White,
    Magic,
    Rare,
    Unique,
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Bar {
    pub address: u64,
    pub id: u32,
    pub style: Style,
    /// The world point the bar is centred on: above the model's head.
    pub anchor: [f32; 3],
    /// Health and ward together, percent of the unreserved part.
    pub health_percent: i32,
    /// Energy shield percent, or mana on the player's own bar.
    pub second_percent: Option<i32>,
    /// Health is within culling strike range for its rarity.
    pub cullable: bool,
    /// Health, ward and energy shield, as the bar's text.
    pub total: i32,
}

/// The rarity index GameHelper2 passes for the cull range.
fn rarity_index(r: Rarity) -> usize {
    match r {
        Rarity::Normal => 0,
        Rarity::Magic => 1,
        Rarity::Rare => 2,
        Rarity::Unique => 3,
    }
}

/// CombinedHealthPercent: health and ward as one pool.
pub fn combined_percent(life: &Life) -> i32 {
    let total = life.health.unreserved() + life.ward.unreserved();
    if total <= 0 {
        return 0;
    }
    (100.0 * f64::from(life.health.current + life.ward.current) / f64::from(total)).round() as i32
}

/// The style and cull rarity for an entity of `kind`, None when it gets
/// no bar (DrawUI's switch).
pub fn style(e: &Entity, kind: &Kind) -> Option<(Style, usize)> {
    if !e.valid || kind.state == State::Useless {
        return None;
    }
    let rare = rarity_index(Rarity::Rare);
    match kind.kind {
        Type::Player => Some(match (kind.subtype, kind.state) {
            (Subtype::PlayerOther, State::PlayerLeader) => (Style::PlayerLeader, rare),
            (Subtype::PlayerOther, _) => (Style::PlayerMember, rare),
            _ => (Style::PlayerSelf, rare),
        }),
        Type::Monster if kind.state == State::MonsterFriendly => Some((Style::Friendly, rare)),
        Type::Monster => {
            let r = e.rarity?;
            let s = match r {
                Rarity::Normal => Style::White,
                Rarity::Magic => Style::Magic,
                Rarity::Rare => Style::Rare,
                Rarity::Unique => Style::Unique,
            };
            Some((s, rarity_index(r)))
        }
        _ => None,
    }
}

/// The bar for one entity, None when it gets none or lacks a position
/// or life (DrawHealthbar).
pub fn bar(e: &Entity, kind: &Kind) -> Option<Bar> {
    let (style, rarity) = style(e, kind)?;
    let [x, y, z] = e.position?;
    let life = e.life?;
    let up = e.model_bounds.map_or(0.0, |b| b[2]);
    let health_percent = combined_percent(&life);
    let second_percent = if style == Style::PlayerSelf {
        Some(life.mana.percent())
    } else {
        (life.energy_shield.total > 0).then(|| life.energy_shield.percent())
    };
    Some(Bar {
        address: e.address,
        id: e.id,
        style,
        anchor: [x, y, z - up],
        health_percent,
        second_percent,
        cullable: health_percent <= CULL_PERCENT[rarity],
        total: life.health.current + life.ward.current + life.energy_shield.current,
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::Vital;
    use crate::kinds::tests::{alive, with_parts};
    use crate::kinds::{Settings, classify};

    #[test]
    fn a_rare_monster_bar_folds_ward_into_health() {
        let mut wolf = with_parts(
            "Metadata/Monsters/Wolf/Wolf",
            &["Render", "Life", "Positioned", "ObjectMagicProperties"],
        );
        wolf.rarity = Some(Rarity::Rare);
        wolf.position = Some([100.0, 200.0, -10.0]);
        wolf.model_bounds = Some([5.0, 5.0, 80.0]);
        let mut life = alive(5).unwrap();
        life.ward = Vital {
            current: 4,
            total: 100,
            ..Vital::default()
        };
        life.energy_shield = Vital {
            current: 25,
            total: 50,
            ..Vital::default()
        };
        wolf.life = Some(life);
        let k = classify(&wolf, 0, &Settings::default()).unwrap();
        let b = bar(&wolf, &k).unwrap();
        assert_eq!(b.style, Style::Rare);
        assert_eq!(b.anchor, [100.0, 200.0, -90.0]);
        // (5 + 4) of 200 rounds to 5 percent: under the rare cull of 10.
        assert_eq!((b.health_percent, b.cullable), (5, true));
        assert_eq!(b.second_percent, Some(50));
        assert_eq!(b.total, 34);

        wolf.life = alive(0);
        let k = classify(&wolf, 0, &Settings::default()).unwrap();
        assert_eq!(bar(&wolf, &k), None);
    }

    #[test]
    fn the_players_own_bar_shows_mana() {
        let mut me = with_parts("Metadata/Characters/Int", &["Render", "Player", "Life"]);
        me.id = 7;
        me.position = Some([0.0, 0.0, 0.0]);
        let mut life = alive(100).unwrap();
        life.mana = Vital {
            current: 30,
            total: 120,
            reserved_percent: 5000,
            ..Vital::default()
        };
        me.life = Some(life);
        let k = classify(&me, 7, &Settings::default()).unwrap();
        let b = bar(&me, &k).unwrap();
        assert_eq!(b.style, Style::PlayerSelf);
        // 30 of the 60 unreserved.
        assert_eq!(b.second_percent, Some(50));
        assert!(!b.cullable);
    }
}
