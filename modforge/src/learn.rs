//! Learning to stay alive (topside life.md "Learning to stay alive"): one
//! goal, staying alive, and one measure that scores every stage of it,
//! from the next seconds to the days ahead: how long this person can stay
//! alive from here. A choice is learned as good or bad by how much it
//! changed this measure. Engine-free.
//!
//! How, from those who did it: each choice is kept with the situation it
//! was made in (Black & White's learning episodes); every change in the
//! measure is shared among the recent choices, the latest most (Sutton
//! and Barto's eligibility traces), so a death blames what led to it; a
//! new situation uses the most similar one remembered (Blundell et al.'s
//! episodic control, learning from a handful of lives, not millions); the
//! brain's rules are what a person is born with and only offer the
//! choices, what was learned picks among them (Creatures' instincts).

use std::collections::HashMap;

use crate::item::ItemRegistry;
use crate::memory::Memory;
use crate::survival::{FULL, SurvivalRates, SurvivalStats};

/// How much food in a box that is not their own store counts: someone
/// else may take it, and it is out there. Taking it and carrying it home
/// makes it count in full. Tuning.
pub const KNOWN_ELSEWHERE: f32 = 0.5;

/// How long this person can stay alive from here, in seconds: until
/// hunger or thirst runs out, counting what they carry and their store in
/// full and every other box they know holds food or water at
/// `KNOWN_ELSEWHERE`, times their health. Finding food adds to it, taking
/// it adds more, a hit takes from it, death is zero. Eating moves food
/// from the bag into the stomach and changes nothing, except that what
/// goes past a full stomach is lost: eat what you need.
pub fn alive_for(
    needs: &SurvivalStats,
    rates: SurvivalRates,
    health_fraction: f32,
    carried: &[(String, u32)],
    store: Option<u64>,
    memory: &Memory,
    items: &ItemRegistry,
) -> f32 {
    if health_fraction <= 0.0 {
        return 0.0;
    }
    let (mut hunger, mut thirst) = (needs.hunger.min(FULL), needs.thirst.min(FULL));
    let known = memory.known.iter().flat_map(|k| {
        let share = if Some(k.key) == store { 1.0 } else { KNOWN_ELSEWHERE };
        k.held.iter().flatten().map(move |held| (held, share))
    });
    for ((item, count), share) in carried.iter().map(|c| (c, 1.0)).chain(known) {
        if let Some(food) = items.def(item).and_then(|d| d.food) {
            hunger += food.hunger * *count as f32 * share;
            thirst += food.thirst * *count as f32 * share;
        }
    }
    let last = |points: f32, per_sec: f32| if per_sec > 0.0 { points / per_sec } else { f32::INFINITY };
    last(hunger, rates.hunger_per_sec).min(last(thirst, rates.thirst_per_sec)) * health_fraction.min(1.0)
}

/// How a need or health stands, in three bands, so like moments match.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub enum Band {
    Low,
    Middle,
    Fine,
}

impl Band {
    /// Below `low` is low, below `middle` middle, else fine.
    pub fn of(value: f32, low: f32, middle: f32) -> Self {
        if value < low {
            Band::Low
        } else if value < middle {
            Band::Middle
        } else {
            Band::Fine
        }
    }
}

/// The moment a choice is made in, kept small so that like moments match.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub struct Situation {
    pub hunger: Band,
    pub thirst: Band,
    pub rest: Band,
    pub health: Band,
    pub has_home: bool,
    pub at_home: bool,
    pub hostile_in_sight: bool,
    pub carries_food: bool,
    pub knows_food: bool,
    pub storm_coming: bool,
    pub bunker_short: bool,
}

impl Situation {
    /// How many things differ between two moments.
    pub fn differs(&self, other: &Situation) -> u32 {
        [
            self.hunger != other.hunger,
            self.thirst != other.thirst,
            self.rest != other.rest,
            self.health != other.health,
            self.has_home != other.has_home,
            self.at_home != other.at_home,
            self.hostile_in_sight != other.hostile_in_sight,
            self.carries_food != other.carries_food,
            self.knows_food != other.knows_food,
            self.storm_coming != other.storm_coming,
            self.bunker_short != other.bunker_short,
        ]
        .into_iter()
        .filter(|d| *d)
        .count() as u32
    }
}

/// Which of the brain's rules was acted on (topside life.md "The
/// brain"): what a person is born able to do.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub enum Choice {
    /// Home before the storm.
    Hide,
    Flee,
    /// Break off a chase gone too far.
    BreakOff,
    Fight,
    EatCarried,
    /// Carry on with what they were doing.
    CarryOn,
    /// Go to what answers a need (food, water, sleep).
    GoToNeed,
    /// Fetch what their bunker is short of, or bring it home.
    Supply,
    /// Go and look at something not yet checked, or head out to find food.
    Look,
    Wander,
}

/// How much of a change in the measure reaches a choice made one choice
/// earlier than the last (eligibility trace decay). Tuning.
pub const TRACE_DECAY: f32 = 0.8;
/// How far a choice's value moves toward each new outcome. Tuning.
pub const LEARN_RATE: f32 = 0.3;
/// What dying loses beyond the measure: all that was still to come,
/// counted as a game day of staying alive (seconds). Tuning.
pub const DEATH_COST: f32 = 1200.0;
/// Instinct's lead for each place higher in its order, in seconds of
/// staying alive: what was learned must beat it to overturn instinct.
/// Tuning.
pub const INSTINCT_STEP: f32 = 60.0;
/// Below this share a choice no longer takes blame or credit.
const TRACE_GONE: f32 = 0.01;
/// The most different a remembered moment may be and still stand in for
/// a new one.
pub const MOST_DIFFERENT: u32 = 2;

/// What a person has learned: each choice's value in each situation (the
/// seconds of staying alive it tended to add), and the recent choices
/// still taking credit or blame. Part of their memory; never shared.
#[derive(Clone, Debug, Default, PartialEq)]
pub struct Learned {
    pub values: HashMap<(Situation, Choice), f32>,
    /// Recent choices and their share of the next change, latest last.
    pub recent: Vec<(Situation, Choice, f32)>,
    /// The measure and the tick it was taken at, last time.
    pub last: Option<(u64, f32)>,
}

impl Learned {
    /// A new reading of the measure at `now` (ticks at 60 a second): the
    /// change since the last, less the time that passed (standing still
    /// scores nothing), goes to the recent choices by their share.
    pub fn score(&mut self, now: u64, alive_for: f32) {
        if let Some(change) = self.change(now, alive_for) {
            self.credit(change);
        }
        self.last = Some((now, alive_for));
    }

    /// The change in the measure since the last reading, less the time
    /// that passed.
    fn change(&self, now: u64, alive_for: f32) -> Option<f32> {
        let (then, before) = self.last?;
        let passed = now.saturating_sub(then) as f32 / 60.0;
        Some(alive_for + passed - before)
    }

    /// Each recent choice's value moves toward `change` by its share (the
    /// Q-learning step: a value is what the choice tends to bring, never a
    /// sum that grows without end).
    fn credit(&mut self, change: f32) {
        for (situation, choice, share) in &self.recent {
            let value = self.values.entry((*situation, *choice)).or_insert(0.0);
            *value += LEARN_RATE * share * (change - *value);
        }
    }

    /// Died: the measure fell to nothing, and dying loses all that was
    /// still to come as well (`DEATH_COST`), the biggest blame for what
    /// led here; the next life starts fresh, keeping what was learned.
    pub fn died(&mut self, now: u64) {
        let change = self.change(now, 0.0).unwrap_or(0.0) - DEATH_COST;
        self.credit(change);
        self.recent.clear();
        self.last = None;
    }

    /// A choice made now in `situation`: it takes the next change in
    /// full, the earlier ones less.
    pub fn chose(&mut self, situation: Situation, choice: Choice) {
        for (_, _, share) in &mut self.recent {
            *share *= TRACE_DECAY;
        }
        self.recent.retain(|(_, _, share)| *share >= TRACE_GONE);
        self.recent.push((situation, choice, 1.0));
    }

    /// What `choice` is worth in `situation`: learned there, or in the
    /// most similar moment remembered (no more than `MOST_DIFFERENT`
    /// apart, and never across what changes what is at stake: a hostile in
    /// sight, the storm, having a home); None if never learned near it.
    pub fn value(&self, situation: &Situation, choice: Choice) -> Option<f32> {
        if let Some(v) = self.values.get(&(*situation, choice)) {
            return Some(*v);
        }
        let at_stake = |s: &Situation| (s.hostile_in_sight, s.storm_coming, s.has_home);
        self.values
            .iter()
            .filter(|((s, c), _)| {
                *c == choice && at_stake(s) == at_stake(situation) && s.differs(situation) <= MOST_DIFFERENT
            })
            .min_by_key(|((s, _), _)| s.differs(situation))
            .map(|(_, v)| *v)
    }

    /// Of the choices offered in order of instinct, the one to take: the
    /// highest learned value with instinct's lead added (`INSTINCT_STEP`
    /// less for each place down the order), a choice never learned
    /// counting as nothing but its lead. With nothing learned, instinct's
    /// first choice; what was learned overturns instinct only by more than
    /// the lead, and a choice that went badly loses to one not yet tried.
    pub fn pick(&self, situation: &Situation, offered: &[Choice]) -> usize {
        let mut best = 0;
        let mut best_value = f32::NEG_INFINITY;
        for (i, choice) in offered.iter().enumerate() {
            let lead = -(i as f32) * INSTINCT_STEP;
            let v = self.value(situation, *choice).unwrap_or(0.0) + lead;
            if v > best_value {
                best = i;
                best_value = v;
            }
        }
        best
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::item::{FoodStats, ItemDef, ItemKind};

    fn items() -> ItemRegistry {
        let mut reg = ItemRegistry::default();
        for (name, hunger, thirst) in [("can", 30.0, 0.0), ("bottle", 0.0, 30.0)] {
            reg.register(ItemDef {
                name: name.to_string(),
                unique: false,
                kind: ItemKind::Food,
                max_stack: 10,
                quality_siblings: 1,
                combat: None,
                food: Some(FoodStats { hunger, thirst, health: 0.0 }),
                storage: None,
                armor: None,
                good_for: Default::default(),
                picture: None,
                layer_slots: Vec::new(),
            })
            .unwrap();
        }
        reg
    }

    fn rates() -> SurvivalRates {
        // A full stomach and canteen last 100 s each.
        SurvivalRates::lasting(100.0, 100.0, 1200.0)
    }

    fn needs(hunger: f32, thirst: f32) -> SurvivalStats {
        SurvivalStats { hunger, thirst, ..SurvivalStats::default() }
    }

    fn held(list: &[(&str, u32)]) -> Vec<(String, u32)> {
        list.iter().map(|(i, n)| (i.to_string(), *n)).collect()
    }

    /// Every stage moves the one measure: a known box of food adds to it,
    /// a hit takes from it, death is zero, and it is the need that runs
    /// out first that counts.
    #[test]
    fn staying_alive_is_one_measure() {
        let (items, memory) = (items(), Memory::default());
        let alive = |needs: SurvivalStats, health: f32, carried: &[(String, u32)], store: Option<u64>, memory: &Memory| {
            alive_for(&needs, rates(), health, carried, store, memory, &items)
        };
        assert_eq!(alive(needs(50.0, 80.0), 1.0, &[], None, &memory), 50.0, "hunger runs out first");
        assert_eq!(alive(needs(50.0, 80.0), 1.0, &held(&[("can", 2)]), None, &memory), 80.0, "two cans: thirst first now");
        let mut knows = Memory::default();
        knows.see(1, "storage box", glam::Vec3::ZERO, 0);
        knows.checked(1, held(&[("can", 10), ("bottle", 10)]), 0);
        assert_eq!(alive(needs(50.0, 80.0), 1.0, &[], Some(1), &knows), 350.0, "their own store adds days");
        assert_eq!(alive(needs(50.0, 80.0), 1.0, &[], None, &knows), 200.0, "a box out there counts half");
        assert_eq!(alive(needs(50.0, 80.0), 0.5, &[], None, &memory), 25.0, "a hit takes from it");
        assert_eq!(alive(needs(50.0, 80.0), 0.0, &[], None, &memory), 0.0, "death is zero");
    }

    /// Eating what you need changes nothing (the food moves from the bag
    /// to the stomach); eating past full loses what goes past.
    #[test]
    fn eating_past_full_loses_food() {
        let (items, memory) = (items(), Memory::default());
        let alive = |needs: SurvivalStats, carried: &[(String, u32)]| alive_for(&needs, rates(), 1.0, carried, None, &memory, &items);
        assert_eq!(alive(needs(40.0, 100.0), &held(&[("can", 1)])), alive(needs(70.0, 100.0), &[]));
        // Plenty to drink, so hunger is what counts.
        let bottles = ("bottle", 5);
        let full_before = alive(needs(90.0, 100.0), &held(&[("can", 1), bottles]));
        let full_ate = alive(needs(120.0, 100.0), &held(&[bottles]));
        assert!(full_ate < full_before, "{full_ate} after, {full_before} before");
    }

    fn moment(hunger: Band, at_home: bool) -> Situation {
        Situation {
            hunger,
            thirst: Band::Fine,
            rest: Band::Fine,
            health: Band::Fine,
            has_home: true,
            at_home,
            hostile_in_sight: false,
            carries_food: false,
            knows_food: false,
            storm_coming: false,
            bunker_short: false,
        }
    }

    /// The story from the design: hungry at home, the first life waits
    /// (instinct's first offer) and dies of hunger; the death blames
    /// waiting, so the next life, hungry at home again, goes out and
    /// looks instead, and finding food there makes looking worth it.
    #[test]
    fn dying_of_hunger_at_home_teaches_going_out() {
        let hungry_home = moment(Band::Low, true);
        let offered = [Choice::CarryOn, Choice::Look];
        let mut learned = Learned::default();
        assert_eq!(learned.pick(&hungry_home, &offered), 0, "nothing learned: instinct's order");
        learned.score(0, 60.0);
        learned.chose(hungry_home, Choice::CarryOn);
        learned.died(60 * 60);
        assert!(learned.values[&(hungry_home, Choice::CarryOn)] < 0.0);
        assert_eq!(learned.pick(&hungry_home, &offered), 1, "what went badly loses to what is untried");
        // The next life looks, and finds a box of food.
        learned.score(0, 60.0);
        learned.chose(hungry_home, Choice::Look);
        learned.score(60 * 10, 300.0);
        assert!(learned.values[&(hungry_home, Choice::Look)] > 0.0);
        // A moment a little different (not at home) is judged by this one.
        let hungry_out = moment(Band::Low, false);
        assert_eq!(learned.pick(&hungry_out, &offered), 1);
        assert_eq!(learned.value(&hungry_out, Choice::Look), learned.value(&hungry_home, Choice::Look));
    }

    /// Found in the real game: wandering found a box of food while calm,
    /// and that stood in for the moment a hostile came into sight, so
    /// nobody fought. What changes the stakes must match: calm luck says
    /// nothing about a fight, and instinct fights.
    #[test]
    fn a_calm_find_says_nothing_about_a_fight() {
        let mut learned = Learned::default();
        let calm = moment(Band::Fine, false);
        learned.score(0, 100.0);
        learned.chose(calm, Choice::Wander);
        learned.score(60, 1900.0);
        assert!(learned.values[&(calm, Choice::Wander)] > INSTINCT_STEP);
        let threatened = Situation { hostile_in_sight: true, ..calm };
        assert_eq!(learned.value(&threatened, Choice::Wander), None);
        assert_eq!(learned.pick(&threatened, &[Choice::Fight, Choice::Wander]), 0, "fights");
        // A value is what a choice tends to bring, not a sum: the same
        // find again does not make it grow without end.
        let once = learned.values[&(calm, Choice::Wander)];
        for t in 2..50 {
            learned.chose(calm, Choice::Wander);
            learned.score(60 * t, 1900.0 + 1800.0 * (t - 1) as f32);
        }
        // Each find adds 1801 s (1800 found, 1 passed): the value nears
        // that, never more.
        assert!(learned.values[&(calm, Choice::Wander)] <= 1801.0 && once > 0.0);
    }

    /// Standing still scores nothing: time passing is not a loss.
    #[test]
    fn time_passing_is_not_blamed() {
        let mut learned = Learned::default();
        let s = moment(Band::Fine, true);
        learned.score(0, 100.0);
        learned.chose(s, Choice::Wander);
        learned.score(60 * 30, 70.0);
        assert_eq!(learned.values[&(s, Choice::Wander)], 0.0);
    }

    /// The choice just made takes most of what follows; earlier ones less.
    #[test]
    fn the_latest_choice_takes_most_blame() {
        let mut learned = Learned::default();
        let (a, b) = (moment(Band::Fine, true), moment(Band::Middle, false));
        learned.score(0, 100.0);
        learned.chose(a, Choice::Wander);
        learned.chose(b, Choice::Fight);
        learned.died(0);
        let (wander, fight) = (learned.values[&(a, Choice::Wander)], learned.values[&(b, Choice::Fight)]);
        assert!(fight < wander && wander < 0.0, "fight {fight}, wander {wander}");
    }
}
