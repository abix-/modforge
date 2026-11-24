//! Events (topside-town "Storms and events are different", operator,
//! 2026-11-24: "events can occur in the middle of an episode to do
//! something strangers coming in, some sort of loot drop"): what happens
//! between storms, inside an episode, read from a game's content. A storm
//! ends an episode (`storm`); an event happens in one. What an event does
//! is a `storm::Effect`, carried out by the game the same way as a
//! storm's.

use crate::storm::Effect;

/// One kind of event: its name, what it does, the least episode it can
/// come in (0 the first), and how likely against the others (100 when
/// left out).
#[derive(Clone, Debug, PartialEq, serde::Deserialize)]
#[serde(deny_unknown_fields)]
pub struct EventDef {
    pub name: String,
    pub does: Vec<Effect>,
    #[serde(default)]
    pub from_episode: u32,
    #[serde(default = "usual_weight")]
    pub weight: u32,
}

fn usual_weight() -> u32 {
    100
}

/// How often events come: the gap between two, in game days, rolled
/// within this range.
#[derive(Clone, Copy, Debug, PartialEq, serde::Deserialize)]
#[serde(deny_unknown_fields)]
pub struct EventPace {
    pub gap_days: (f32, f32),
}

/// A game's events, as its content holds them: how often they come and
/// each kind.
#[derive(Clone, Debug, PartialEq, serde::Deserialize)]
#[serde(deny_unknown_fields)]
pub struct EventsDef {
    pub pace: EventPace,
    pub kinds: Vec<EventDef>,
}

/// The second the next event comes, `from` the last one: a gap within
/// `pace`, a game day being `day_secs`, rolled from `seed`.
pub fn next_at(pace: &EventPace, from: f32, day_secs: f32, seed: u64) -> f32 {
    let (lo, hi) = (pace.gap_days.0.min(pace.gap_days.1), pace.gap_days.0.max(pace.gap_days.1));
    let share = crate::roll::salted_index(seed, 0xE7E7_0100, 10_001) as f32 / 10_000.0;
    from + (lo + (hi - lo) * share) * day_secs
}

/// The event that comes `n`th in episode `episode`, rolled from `seed`
/// among those that can come by their weights; none when none can.
pub fn pick(events: &[EventDef], episode: u32, n: u32, seed: u64) -> Option<&EventDef> {
    let can: Vec<&EventDef> = events.iter().filter(|e| e.from_episode <= episode && e.weight > 0).collect();
    let total: u64 = can.iter().map(|e| u64::from(e.weight)).sum();
    if total == 0 {
        return None;
    }
    let mut left = crate::roll::salted_index(seed ^ u64::from(episode) << 32 ^ u64::from(n), 0xE7E7_0200, total);
    for e in &can {
        let w = u64::from(e.weight);
        if left < w {
            return Some(e);
        }
        left -= w;
    }
    can.last().copied()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn def(name: &str, from_episode: u32) -> EventDef {
        EventDef {
            name: name.to_string(),
            does: vec![Effect::Bounty],
            from_episode,
            weight: 100,
        }
    }

    #[test]
    fn an_event_comes_within_its_gap_and_only_once_it_can() {
        let pace = EventPace { gap_days: (0.5, 1.0) };
        let at = next_at(&pace, 100.0, 1200.0, 7);
        assert!((700.0..=1300.0).contains(&at), "{at}");
        let events = [def("early", 0), def("late", 3)];
        for n in 0..20 {
            assert_eq!(pick(&events, 0, n, 9).map(|e| e.name.as_str()), Some("early"));
        }
        assert!((0..50).any(|n| pick(&events, 3, n, 9).is_some_and(|e| e.name == "late")));
    }
}
