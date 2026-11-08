//! Picking up items that match the operator's rules, after ExileCore2's
//! PickIt (nearest matching label in range, at most three tries an
//! item, a pause between clicks) and GameHelper2's PickupHelper
//! (MaxPickupDistance 50, ClickCooldownMs 120, SameItemCooldownMs 600,
//! no pickup while a large panel is open). Unlike both it needs no key
//! held: it picks whenever something matches (operator, 2026-11-07).
//! The pause between clicks is drawn from a range so clicks do not
//! come at a regular beat; the move and click are
//! modforge::input::human's.

use crate::item_rules::ItemRule;
use crate::model::Rarity;
use modforge::input::human::{Timing, Wait};
use serde::{Deserialize, Serialize};
use std::collections::HashMap;
use std::time::{Duration, Instant};

#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
#[serde(default)]
pub struct Settings {
    /// Grid cells from the player an item may be.
    pub range: f32,
    /// Between any two clicks; at least ClickCooldownMs.
    pub pause: Wait,
    /// Before the same item is clicked again.
    pub same_item_ms: u64,
    /// Clicks on one item before it is left alone.
    pub tries: u32,
    /// PickIt ClickRandom(5, 3): how far in from the label's edges the
    /// click lands.
    pub margin: [f32; 2],
    pub timing: Timing,
}

impl Default for Settings {
    fn default() -> Self {
        Self {
            range: 50.0,
            pause: Wait::new(120, 260),
            same_item_ms: 600,
            tries: 3,
            margin: [5.0, 3.0],
            timing: Timing::default(),
        }
    }
}

/// The first rules (operator, 2026-11-07): all currency, waystones,
/// and uniques whose price is 5 exalted or more.
pub fn default_rules() -> Vec<ItemRule> {
    vec![
        ItemRule {
            name: "currency".into(),
            path_contains: Some("Metadata/Items/Currency".into()),
            ..Default::default()
        },
        ItemRule {
            name: "waystones".into(),
            path_contains: Some("Metadata/Items/Waystones".into()),
            ..Default::default()
        },
        ItemRule {
            name: "uniques 5 ex".into(),
            rarity: vec![Rarity::Unique],
            min_exalted: Some(5.0),
            ..Default::default()
        },
    ]
}

/// An item on the ground with its label on the screen.
#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Candidate {
    /// The ground entity's address: one item's lasting key.
    pub key: u64,
    pub name: String,
    /// Grid cells from the player.
    pub distance: f32,
    /// The label: x, y, width, height in screen pixels.
    pub label: [f32; 4],
    /// The rule it passed, none when it passed none.
    pub rule: Option<String>,
}

/// What pickup remembers between frames.
#[derive(Debug, Default)]
pub struct State {
    last_click: Option<Instant>,
    /// This pause, drawn after each click.
    pause: Duration,
    /// Each item's clicks so far and when the last was.
    clicks: HashMap<u64, (u32, Instant)>,
}

impl State {
    /// The item to click now: the nearest that passed a rule, is in
    /// range, has tries left and was not clicked within the same-item
    /// wait; none while the pause after the last click runs.
    pub fn choose<'a>(&self, s: &Settings, items: &'a [Candidate], now: Instant) -> Option<&'a Candidate> {
        if self.last_click.is_some_and(|t| now.duration_since(t) < self.pause) {
            return None;
        }
        let same = Duration::from_millis(s.same_item_ms);
        items
            .iter()
            .filter(|c| c.rule.is_some() && c.distance <= s.range)
            .filter(|c| match self.clicks.get(&c.key) {
                Some((n, at)) => *n < s.tries && now.duration_since(*at) >= same,
                None => true,
            })
            .min_by(|a, b| a.distance.total_cmp(&b.distance))
    }

    /// A click on `key` happened at `now`; the next pause is drawn.
    pub fn clicked(&mut self, s: &Settings, key: u64, now: Instant, rng: &mut fastrand::Rng) {
        let e = self.clicks.entry(key).or_insert((0, now));
        e.0 += 1;
        e.1 = now;
        self.last_click = Some(now);
        self.pause = Duration::from_millis(u64::from(s.pause.draw(rng)));
    }

    /// A new zone: forget every item.
    pub fn clear(&mut self) {
        self.clicks.clear();
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::model::Item;

    fn item(key: u64, distance: f32, rule: bool) -> Candidate {
        Candidate {
            key,
            name: format!("item {key}"),
            distance,
            label: [0.0, 0.0, 80.0, 20.0],
            rule: rule.then(|| "currency".to_string()),
        }
    }

    #[test]
    fn picks_the_nearest_match_in_range_with_tries_left() {
        let s = Settings::default();
        let mut st = State::default();
        let mut rng = fastrand::Rng::with_seed(5);
        let t0 = Instant::now();
        let items = [item(1, 30.0, true), item(2, 10.0, false), item(3, 20.0, true), item(4, 60.0, true)];
        assert_eq!(st.choose(&s, &items, t0).map(|c| c.key), Some(3));
        st.clicked(&s, 3, t0, &mut rng);
        // The pause after a click: nothing.
        assert_eq!(st.choose(&s, &items, t0 + Duration::from_millis(100)), None);
        // After the pause but within the same-item wait: the next one.
        let t1 = t0 + Duration::from_millis(300);
        assert_eq!(st.choose(&s, &items, t1).map(|c| c.key), Some(1));
        // Three tries and item 3 is left alone.
        let mut t = t1;
        for _ in 0..2 {
            t += Duration::from_millis(700);
            assert_eq!(st.choose(&s, &[item(3, 20.0, true)], t).map(|c| c.key), Some(3));
            st.clicked(&s, 3, t, &mut rng);
        }
        t += Duration::from_millis(700);
        assert_eq!(st.choose(&s, &[item(3, 20.0, true)], t), None);
        st.clear();
        assert!(st.choose(&s, &[item(3, 20.0, true)], t).is_some());
    }

    #[test]
    fn pauses_vary_within_their_range() {
        let s = Settings::default();
        let mut st = State::default();
        let mut rng = fastrand::Rng::with_seed(9);
        let mut seen = std::collections::HashSet::new();
        for _ in 0..50 {
            st.clicked(&s, 1, Instant::now(), &mut rng);
            assert!((120..=260).contains(&st.pause.as_millis()));
            seen.insert(st.pause);
        }
        assert!(seen.len() > 10);
    }

    #[test]
    fn the_first_rules_take_currency_waystones_and_dear_uniques() {
        let rules = default_rules();
        let take = |path: &str, rarity: Option<Rarity>, price: Option<f64>| {
            let i = Item {
                path: path.into(),
                rarity,
                ..Default::default()
            };
            rules.iter().any(|r| r.matches(&i, price))
        };
        assert!(take("Metadata/Items/Currency/CurrencyRerollRare", Some(Rarity::Normal), None));
        assert!(take("Metadata/Items/Waystones/Waystone5", Some(Rarity::Magic), None));
        assert!(take("Metadata/Items/Rings/Ring1", Some(Rarity::Unique), Some(6.0)));
        assert!(!take("Metadata/Items/Rings/Ring1", Some(Rarity::Unique), Some(2.0)));
        assert!(!take("Metadata/Items/Rings/Ring1", Some(Rarity::Unique), None));
        assert!(!take("Metadata/Items/Rings/Ring1", Some(Rarity::Rare), Some(50.0)));
    }
}
