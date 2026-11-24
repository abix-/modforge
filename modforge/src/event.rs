//! Events and the alien director (topside-town "Storms and events are
//! different"; topside-show "The alien director"; operator, 2026-11-24:
//! "we should just call it the alien director, because they're going to
//! take into account all the reviewer stats and the ratings and all of
//! that in order to figure out what to do in order to make the episode as
//! entertaining as possible for the viewers").
//!
//! A storm ends an episode (`storm`); an event happens in one. Every
//! event is rolled in layers, as Diablo 2 rolls an item (a base, its
//! affixes, its level): the base event (`EventDef`), who comes or what
//! drops, how big (the director's budget), where (`Place`), 0 to 2 twists
//! (`TwistDef`) and how it is foretold (`Warning`). The director picks
//! which (`choose`), from how bored and how tense the show is, as Left 4
//! Dead's director paces by tension and RimWorld's storytellers spend
//! threat points; the same base or group just seen is less likely (State
//! of Decay 2's curveball pacing). Game-agnostic: the game carries out
//! each `Does`, feeds the director what it sees (`Director::feel`) and
//! holds the content. Every number here is Claude's, for the operator to
//! change.

use crate::storm::Effect;

/// What an event is for, the director's lever: trouble when the show is
/// dull, a gift when it is too tense, the strange any time.
#[derive(Clone, Copy, Debug, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub enum Mood {
    Trouble,
    Gift,
    Strange,
}

/// Where an event happens, rolled from the event's list.
#[derive(Clone, Copy, Debug, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub enum Place {
    /// Far out, coming in.
    Edge,
    /// Somewhere in the town around the bunker.
    Town,
    /// At the player's bunker door.
    Door,
    /// Inside the player's bunker.
    Inside,
    /// Below the player's bunker's lowest level.
    Under,
}

/// How long what an event brings stays.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub enum Leaves {
    /// Until killed.
    #[default]
    Stays,
    /// The first morning after.
    Morning,
}

/// Something in the air that lasts a while: a weather (`weather`, which
/// already decides what it does to those outside and to sight), or the
/// day gone dark.
#[derive(Clone, Copy, Debug, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub enum Lasting {
    Weather(crate::weather::Weather),
    Dark,
}

/// One thing an event does, carried out by the game.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
#[serde(deny_unknown_fields)]
pub enum Does {
    /// People or animals come: one kind rolled from `who` (the game's
    /// actor kinds), `count` of them (low, high), at the event's place.
    Arrive {
        who: Vec<String>,
        count: (u32, u32),
        #[serde(default)]
        leaves: Leaves,
    },
    /// Things drop: `item` (a filled loot box when left out), `count`
    /// (low, high), the loot's `danger` (higher, better).
    Drop {
        #[serde(default)]
        item: Option<String>,
        count: (u32, u32),
        #[serde(default = "usual_danger")]
        danger: u32,
    },
    /// Something lasts in the air for `hours` (low, high) of game time.
    Last { what: Lasting, hours: (f32, f32) },
    /// The food in the player's store goes bad.
    Spoil,
    /// What a storm can do, done now.
    Storm(Effect),
    /// Trouble at home, inside the player's own walls (topside todo
    /// Events 5).
    Home(Home),
    /// The show's own doings (topside todo Events 6).
    Aliens(Aliens),
}

/// What the aliens do for their show (topside todo Events 6, Claude's
/// list the operator took, 2026-11-24). A rule changed for a day is a
/// `Last` (the dark all day), no doing of its own.
#[derive(Clone, Copy, Debug, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub enum Aliens {
    /// A challenge: a kill before the day is out, a reward paid when done.
    Challenge,
    /// A special guest from another channel's bunker, at the door.
    Guest,
    /// A cliffhanger: the storm brought near.
    Cliffhanger,
    /// A sound that pulls the enemies near to the player's door.
    Lure,
    /// A rumor of a place: a secret the player has not found, told.
    Rumor,
}

/// The trouble at home an event can make (topside todo Events 5,
/// Claude's list the operator took, 2026-11-24).
#[derive(Clone, Copy, Debug, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub enum Home {
    /// A short circuit: something that burns catches fire.
    Fire,
    /// One of the people falls sick, and it spreads (`sickness`).
    Sickness,
    /// The bottom level floods.
    Flood,
    /// Someone breaks: steals from the store and runs.
    Breaks,
    /// Two of the people fall out.
    FallOut,
    /// Two of the people fall for each other.
    InLove,
}

fn usual_danger() -> u32 {
    3
}

/// How an event is foretold.
#[derive(Clone, Copy, Debug, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub enum Warning {
    /// Nothing: it just happens.
    None,
    /// A sound first (Project Zomboid's helicopter, 7 Days to Die's screamer).
    Sound,
    /// A light in the sky first.
    Sky,
    /// Told on the radio or the television first.
    Broadcast,
}

/// One kind of event: its base. `group` is what the director keeps from
/// repeating (raids, arrivals, drops, the air); `cost` is what one of it
/// at its usual size takes from the director's budget.
#[derive(Clone, Debug, PartialEq, serde::Deserialize)]
#[serde(deny_unknown_fields)]
pub struct EventDef {
    pub name: String,
    pub group: String,
    pub mood: Mood,
    pub does: Vec<Does>,
    #[serde(default = "town")]
    pub places: Vec<Place>,
    #[serde(default = "usual_cost")]
    pub cost: u32,
    /// The twists it can take, by name (`TwistDef`).
    #[serde(default)]
    pub twists: Vec<String>,
    #[serde(default = "usual_warnings")]
    pub warnings: Vec<Warning>,
    #[serde(default)]
    pub from_episode: u32,
    #[serde(default = "usual_weight")]
    pub weight: u32,
}

fn town() -> Vec<Place> {
    vec![Place::Town]
}

fn usual_cost() -> u32 {
    10
}

fn usual_warnings() -> Vec<Warning> {
    vec![Warning::None, Warning::Sound, Warning::Sky, Warning::Broadcast]
}

fn usual_weight() -> u32 {
    100
}

/// A twist on an event (Diablo 2's affixes): what it adds to the cost,
/// how much bigger it makes it, whether it comes only at night or only
/// unforetold, whether it happens at two places, and what more it does.
#[derive(Clone, Debug, PartialEq, serde::Deserialize)]
#[serde(deny_unknown_fields)]
pub struct TwistDef {
    pub name: String,
    #[serde(default)]
    pub cost: u32,
    #[serde(default = "one")]
    pub size: f32,
    #[serde(default)]
    pub night: bool,
    #[serde(default)]
    pub unforetold: bool,
    #[serde(default)]
    pub twice: bool,
    #[serde(default)]
    pub adds: Vec<Does>,
}

fn one() -> f32 {
    1.0
}

/// How often events come: the gap between two, in game days, and how
/// long a foretold one is foretold before it comes, in game hours.
#[derive(Clone, Copy, Debug, PartialEq, serde::Deserialize)]
#[serde(deny_unknown_fields)]
pub struct EventPace {
    pub gap_days: (f32, f32),
    #[serde(default = "usual_lead")]
    pub lead_hours: f32,
}

fn usual_lead() -> f32 {
    1.0
}

/// The director's numbers: its budget at the first episode, what each
/// episode adds, and how many past events it remembers to keep from
/// repeating.
#[derive(Clone, Copy, Debug, PartialEq, serde::Deserialize)]
#[serde(deny_unknown_fields)]
pub struct DirectorDef {
    pub budget: f32,
    pub per_episode: f32,
    #[serde(default = "usual_kept")]
    pub remembers: usize,
}

fn usual_kept() -> usize {
    4
}

/// A game's events, as its content holds them.
#[derive(Clone, Debug, PartialEq, serde::Deserialize)]
#[serde(deny_unknown_fields)]
pub struct EventsDef {
    pub pace: EventPace,
    pub director: DirectorDef,
    pub twists: Vec<TwistDef>,
    pub kinds: Vec<EventDef>,
}

/// The alien director's state: how bored and how tense the show is, each
/// 0 to 1, and the last events it sent (their names and groups). Saved by
/// the game.
#[derive(Clone, Debug, Default, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct Director {
    pub boredom: f32,
    pub tension: f32,
    pub recent: Vec<(String, String)>,
    /// The ratings: the share of the viewers watching, 0 to 1 (topside-show
    /// "The viewers"; operator, 2026-11-24: "they're going to take into
    /// account all the reviewer stats and the ratings"). A dull stretch
    /// drops them; the star in danger lifts them.
    #[serde(default)]
    pub viewers: f32,
}

/// Below these ratings the viewers vote for trouble, whatever else is on
/// offer (topside-show "Ratings bring trouble"; Claude's).
pub const LOW_RATINGS: f32 = 0.4;

/// One event as rolled: every layer settled, for the game to carry out.
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
pub struct Event {
    pub name: String,
    pub mood: Mood,
    /// The base's and the twists' doings, each Arrive with its one kind,
    /// each count and length settled (low and high the same).
    pub does: Vec<Does>,
    /// Where: one place, two with a twice twist.
    pub places: Vec<Place>,
    pub twists: Vec<String>,
    pub warning: Warning,
    /// The seed the game rolls the exact spots from.
    pub seed: u64,
    /// The other event the viewers voted on and turned down (`choose`),
    /// for the television to show (topside-show "The viewers").
    #[serde(default)]
    pub voted_down: Option<String>,
}

impl Event {
    /// What the player is told while it is foretold (Claude's words, for
    /// the operator to change): a sound, a light, or the broadcast naming
    /// it; nothing when it comes unforetold.
    pub fn foretold(&self) -> Option<String> {
        match self.warning {
            Warning::None => None,
            Warning::Sound => Some("Something far off. Listen.".to_string()),
            Warning::Sky => Some("A light crosses the sky.".to_string()),
            Warning::Broadcast => Some(format!("On the air: {} coming.", self.name)),
        }
    }
}

impl Director {
    /// What the game sees, given to the director: game days since the
    /// last trouble and how hurt the star is, 0 to 1. The ratings fall
    /// over a quiet day and rise with the star in danger; the director is
    /// as bored as the viewers are gone.
    pub fn feel(&mut self, days_quiet: f32, hurt: f32) {
        self.tension = hurt.clamp(0.0, 1.0);
        self.viewers = (1.0 - days_quiet.clamp(0.0, 1.0)).max(self.tension);
        self.boredom = 1.0 - self.viewers;
    }

    /// The budget to spend in episode `episode`: more when the show is
    /// dull, less when the star is near dead (a dead star is no show).
    pub fn budget(&self, def: &DirectorDef, episode: u32) -> f32 {
        (def.budget + def.per_episode * episode as f32) * (0.5 + self.boredom) * (1.0 - 0.6 * self.tension)
    }

    /// How likely `event` is now, against its own weight: trouble when
    /// bored, gifts when tense, and less of what was just seen.
    fn weight(&self, event: &EventDef) -> f64 {
        let mood = match event.mood {
            Mood::Trouble => (0.25 + self.boredom) * (1.2 - self.tension),
            Mood::Gift => 0.4 + self.tension,
            Mood::Strange => 0.6,
        };
        let seen = self.recent.iter().filter(|(_, g)| *g == event.group).count()
            + self.recent.iter().filter(|(n, _)| *n == event.name).count() * 2;
        f64::from(event.weight) * f64::from(mood.max(0.05)) / (1.0 + seen as f64)
    }

    /// Remember `event` was sent, keeping the last `remembers`.
    pub fn sent(&mut self, events: &EventsDef, event: &Event) {
        let group = events.kinds.iter().find(|k| k.name == event.name).map(|k| k.group.clone()).unwrap_or_default();
        self.recent.push((event.name.clone(), group));
        while self.recent.len() > events.director.remembers {
            self.recent.remove(0);
        }
    }
}

fn roll(seed: u64, salt: u64, n: u64) -> u64 {
    crate::roll::salted_index(seed, salt, n.max(1))
}

fn share(seed: u64, salt: u64) -> f32 {
    roll(seed, salt, 10_001) as f32 / 10_000.0
}

/// The second the next event comes, `from` the last one: a gap within
/// `pace`, a game day being `day_secs`, rolled from `seed`.
pub fn next_at(pace: &EventPace, from: f32, day_secs: f32, seed: u64) -> f32 {
    let (lo, hi) = (pace.gap_days.0.min(pace.gap_days.1), pace.gap_days.0.max(pace.gap_days.1));
    from + (lo + (hi - lo) * share(seed, 0xE7E7_0100)) * day_secs
}

/// The director's choice of the next event in episode `episode`, every
/// layer rolled from `seed`; `night` says whether night twists can come.
/// None when no event can.
pub fn choose(events: &EventsDef, director: &Director, episode: u32, night: bool, seed: u64) -> Option<Event> {
    let can: Vec<(&EventDef, f64)> = events
        .kinds
        .iter()
        .filter(|e| e.from_episode <= episode && e.weight > 0)
        .map(|e| (e, director.weight(e)))
        .collect();
    let total: f64 = can.iter().map(|(_, w)| w).sum();
    if total <= 0.0 {
        return None;
    }
    let pick = |salt: u64| {
        let mut left = f64::from(share(seed, salt)) * total;
        can.iter()
            .find(|(_, w)| {
                left -= w;
                left <= 0.0
            })
            .or(can.last())
            .map(|(e, _)| *e)
    };
    let first = pick(0xE7E7_0200)?;
    // The viewers vote between two (topside-show "The viewers": "they're
    // voting on what's happening and what is going to happen"): with the
    // ratings low they want trouble; else the vote goes to the first by
    // the share watching, the second by the share gone (Claude's).
    let second = pick(0xE7E7_0210).filter(|e| e.name != first.name);
    let (base, other) = match second {
        None => (first, None),
        Some(second) => {
            let trouble = |e: &EventDef| e.mood == Mood::Trouble;
            let first_wins = if director.viewers < LOW_RATINGS && trouble(first) != trouble(second) {
                trouble(first)
            } else {
                share(seed, 0xE7E7_0220) <= director.viewers.max(0.5)
            };
            if first_wins { (first, Some(second)) } else { (second, Some(first)) }
        }
    };
    let mut event = layer(events, base, director.budget(&events.director, episode), night, seed);
    event.voted_down = other.map(|e| e.name.clone());
    Some(event)
}

/// Every layer of `base` rolled within `budget`: its twists (0 to 2,
/// each only while the budget holds it), its size from what is left, its
/// kinds and counts, its place and its warning.
pub fn layer(events: &EventsDef, base: &EventDef, budget: f32, night: bool, seed: u64) -> Event {
    let mut left = budget - base.cost as f32;
    let mut twists: Vec<&TwistDef> = Vec::new();
    let can: Vec<&TwistDef> = base
        .twists
        .iter()
        .filter_map(|name| events.twists.iter().find(|t| t.name == *name))
        .filter(|t| night || !t.night)
        .collect();
    for k in 0..2u64 {
        let free: Vec<&TwistDef> = can.iter().copied().filter(|t| !twists.iter().any(|h| h.name == t.name)).collect();
        // One in two for the first twist, one in four for the second.
        if free.is_empty() || roll(seed, 0xE7E7_0300 + k, 2 << k) != 0 {
            break;
        }
        let twist = free[roll(seed, 0xE7E7_0310 + k, free.len() as u64) as usize];
        if twist.cost as f32 <= left {
            left -= twist.cost as f32;
            twists.push(twist);
        }
    }
    let spare = (left.max(0.0) / base.cost.max(1) as f32).min(2.0);
    // What the twists add, size and say, in one pass over them.
    let mut does: Vec<Does> = base.does.clone();
    let (mut sized, mut twice, mut unforetold) = (1.0f32, false, false);
    let mut names = Vec::with_capacity(twists.len());
    for t in &twists {
        does.extend(t.adds.iter().cloned());
        sized *= t.size;
        twice |= t.twice;
        unforetold |= t.unforetold;
        names.push(t.name.clone());
    }
    let size = (1.0 + spare) * sized;
    for (n, d) in does.iter_mut().enumerate() {
        let salt = 0xE7E7_0400 + n as u64 * 8;
        let counted = |(lo, hi): (u32, u32)| {
            let (lo, hi) = (lo.min(hi), lo.max(hi));
            let c = lo + roll(seed, salt, u64::from(hi - lo) + 1) as u32;
            ((c as f32 * size).round() as u32).max(1)
        };
        match d {
            Does::Arrive { who, count, .. } => {
                if !who.is_empty() {
                    let one = who[roll(seed, salt + 1, who.len() as u64) as usize].clone();
                    *who = vec![one];
                }
                let c = counted(*count);
                *count = (c, c);
            }
            Does::Drop { count, .. } => {
                let c = counted(*count);
                *count = (c, c);
            }
            Does::Last { hours, .. } => {
                let h = hours.0 + (hours.1 - hours.0) * share(seed, salt + 2);
                *hours = (h, h);
            }
            Does::Spoil | Does::Storm(_) | Does::Home(_) | Does::Aliens(_) => {}
        }
    }
    let at = |k: u64| base.places.get(roll(seed, 0xE7E7_0500 + k, base.places.len() as u64) as usize).copied().unwrap_or(Place::Town);
    let mut places = vec![at(0)];
    if twice {
        places.push(at(1));
    }
    let warning = if unforetold || base.warnings.is_empty() {
        Warning::None
    } else {
        base.warnings[roll(seed, 0xE7E7_0600, base.warnings.len() as u64) as usize]
    };
    Event {
        name: base.name.clone(),
        mood: base.mood,
        does,
        places,
        twists: names,
        warning,
        seed,
        voted_down: None,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn def(name: &str, from_episode: u32) -> EventDef {
        EventDef {
            name: name.to_string(),
            group: name.to_string(),
            mood: Mood::Gift,
            does: vec![Does::Drop {
                item: None,
                count: (1, 3),
                danger: 3,
            }],
            places: town(),
            cost: 10,
            twists: Vec::new(),
            warnings: usual_warnings(),
            from_episode,
            weight: 100,
        }
    }

    fn events(kinds: Vec<EventDef>) -> EventsDef {
        EventsDef {
            pace: EventPace {
                gap_days: (0.5, 1.0),
                lead_hours: 1.0,
            },
            director: DirectorDef {
                budget: 20.0,
                per_episode: 5.0,
                remembers: 4,
            },
            twists: Vec::new(),
            kinds,
        }
    }

    #[test]
    fn an_event_comes_within_its_gap_and_only_once_it_can() {
        let pace = EventPace {
            gap_days: (0.5, 1.0),
            lead_hours: 1.0,
        };
        let at = next_at(&pace, 100.0, 1200.0, 7);
        assert!((700.0..=1300.0).contains(&at), "{at}");
        let all = events(vec![def("early", 0), def("late", 3)]);
        let director = Director::default();
        for n in 0..20 {
            assert_eq!(choose(&all, &director, 0, false, n).map(|e| e.name), Some("early".to_string()));
        }
        assert!((0..50).any(|n| choose(&all, &director, 3, false, n).is_some_and(|e| e.name == "late")));
    }
}
