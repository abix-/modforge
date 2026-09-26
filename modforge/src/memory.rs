//! What a person knows (topside life.md "What a person knows"):
//! things seen, who hurt them, the last seen threat. The brain only
//! considers what is in here; perception writes it; nothing is
//! broadcast (operator: no advertising, "things describe what they
//! are good for and people remember what they saw"). Engine-free:
//! glam positions and plain ids.

use glam::Vec3;

use crate::actor::ActorId;
use crate::survival::Need;

/// What a kind of thing is good for: the needs it can satisfy and
/// by how much, as a field on its def (an item's `good_for`, a
/// monument type's, the bunker's). A box of food is good for hunger;
/// a camp for rest and safety.
#[derive(Clone, Debug, Default, PartialEq)]
pub struct GoodFor {
    pub needs: Vec<(Need, f32)>,
}

impl GoodFor {
    pub fn new(needs: &[(Need, f32)]) -> Self {
        Self {
            needs: needs.to_vec(),
        }
    }

    /// How much this satisfies `need`, zero if it does not.
    pub fn satisfies(&self, need: Need) -> f32 {
        self.needs
            .iter()
            .find(|(n, _)| *n == need)
            .map_or(0.0, |(_, v)| *v)
    }
}

/// A thing the person knows of: what kind, where, when, and what
/// was seen inside it. `key` is the consumer's handle for it (an
/// entity index, a site index), so the brain can hand it back;
/// `kind` names the def, and the registry says what that kind does.
/// No copy of the def's numbers lives here (life.md "What things are
/// good for": memory stores only what it saw).
#[derive(Clone, Debug, PartialEq)]
pub struct Known {
    pub key: u64,
    pub kind: String,
    pub position: Vec3,
    /// Tick last seen.
    pub seen_at: u64,
    /// Tick last checked up close (looted, opened), if ever.
    pub checked_at: Option<u64>,
    /// What was seen inside it when last checked, each kind with how
    /// many; None until looked (believed to hold something), empty
    /// when it was found bare.
    pub held: Option<Vec<(String, u32)>>,
}

impl Known {
    /// Never looked inside, or found holding something.
    pub fn believed_to_hold(&self) -> bool {
        self.held.as_ref().is_none_or(|h| !h.is_empty())
    }

    /// Seen holding this kind of stack.
    pub fn held_kind(&self, kind: &str) -> bool {
        self.held_count(kind) > 0
    }

    /// How many of this kind were seen inside when last checked.
    pub fn held_count(&self, kind: &str) -> u32 {
        self.held
            .as_ref()
            .map_or(0, |h| h.iter().filter(|(k, _)| k == kind).map(|(_, n)| n).sum())
    }
}

/// What a remembered thing is worth for hunger or thirst, the RimWorld
/// way (topside life.md "What things are good for"): a box does not
/// feed anyone, the food seen inside it does. The best `food` number
/// among the kinds seen inside, from the registry; zero for any other
/// need, and zero until someone has looked inside. A source (a well, a
/// river's water, a berry bush) is worth its own `food`: it is eaten or
/// drunk from where it stands and never runs out.
pub fn food_worth(known: &Known, need: Need, items: &crate::item::ItemRegistry) -> f32 {
    let fills = |food: crate::item::FoodStats| match need {
        Need::Hunger => food.hunger,
        Need::Thirst => food.thirst,
        Need::Rest | Need::Safety => 0.0,
    };
    if let Some(def) = items.def(&known.kind)
        && def.kind == crate::item::ItemKind::Source
    {
        return def.food.map_or(0.0, fills);
    }
    let Some(held) = &known.held else {
        return 0.0;
    };
    held.iter()
        .filter_map(|(kind, _)| items.def(kind).and_then(|d| d.food))
        .map(fills)
        .fold(0.0, f32::max)
}

/// What a bunker is short of (topside design.md "Taking loot"): the food
/// and water in `supplies` (each kind with how many) against what
/// `people` eat and drink in `days`, `per_day` being one person's
/// hunger and thirst points a day. Every need that falls short, the
/// shortest first; empty when the store covers them all.
pub fn short_of<'a>(
    supplies: impl IntoIterator<Item = (&'a str, u32)>,
    people: u32,
    days: f32,
    per_day: (f32, f32),
    items: &crate::item::ItemRegistry,
) -> Vec<Need> {
    let (mut hunger, mut thirst) = (0.0, 0.0);
    for (kind, count) in supplies {
        if let Some(food) = items.def(kind).and_then(|d| d.food) {
            hunger += food.hunger * count as f32;
            thirst += food.thirst * count as f32;
        }
    }
    let wanted = |per: f32| per * people as f32 * days;
    let cover = |have: f32, per: f32| if wanted(per) > 0.0 { have / wanted(per) } else { f32::INFINITY };
    let mut short: Vec<(Need, f32)> = [(Need::Hunger, cover(hunger, per_day.0)), (Need::Thirst, cover(thirst, per_day.1))]
        .into_iter()
        .filter(|(_, c)| *c < 1.0)
        .collect();
    short.sort_by(|a, b| a.1.total_cmp(&b.1));
    short.into_iter().map(|(n, _)| n).collect()
}

/// Something a person did, or had done to them (topside life.md "What a
/// person did").
#[derive(Clone, Debug, PartialEq)]
pub enum Did {
    /// Ate or drank this item (a can, a water bottle).
    Ate(String),
    Slept,
    /// Took this many of an item from a box.
    Took(String, u32),
    /// Put this many of an item into a box (a bunker person's store).
    Stocked(String, u32),
    /// Hit this person for this much.
    Hit(ActorId, f32),
    /// Was hit by this person (None: not a person, as the storm) for this
    /// much.
    WasHit(Option<ActorId>, f32),
    /// Killed this person.
    Killed(ActorId),
    /// Died, killed by this person (None: not a person), of this: the
    /// damage's name, or hunger, thirst, the storm.
    Died(Option<ActorId>, String),
    Respawned,
    /// Went through a doorway.
    Doorway,
}

impl Did {
    /// What kind of thing it was, for counting: "ate", "slept", "took",
    /// "put in", "hit", "was hit", "killed", "died", "respawned",
    /// "doorway".
    pub fn kind(&self) -> &'static str {
        match self {
            Did::Ate(_) => "ate",
            Did::Slept => "slept",
            Did::Took(..) => "took",
            Did::Stocked(..) => "put in",
            Did::Hit(..) => "hit",
            Did::WasHit(..) => "was hit",
            Did::Killed(_) => "killed",
            Did::Died(..) => "died",
            Did::Respawned => "respawned",
            Did::Doorway => "doorway",
        }
    }

    /// In plain words, people by their id: "ate canned food", "was hit by
    /// 12 for 8", "died of hatchet, killed by 12".
    pub fn words(&self) -> String {
        let who = |by: &Option<ActorId>| by.map_or("nobody".to_string(), |a| a.0.to_string());
        match self {
            Did::Ate(item) => format!("ate {item}"),
            Did::Slept => "slept".to_string(),
            Did::Took(item, n) => format!("took {n} {item}"),
            Did::Stocked(item, n) => format!("put in {n} {item}"),
            Did::Hit(whom, amount) => format!("hit {} for {amount:.0}", whom.0),
            Did::WasHit(by, amount) => format!("was hit by {} for {amount:.0}", who(by)),
            Did::Killed(whom) => format!("killed {}", whom.0),
            Did::Died(by, of) => format!("died of {of}, killed by {}", who(by)),
            Did::Respawned => "respawned".to_string(),
            Did::Doorway => "went through a doorway".to_string(),
        }
    }
}

/// A person's memory: things seen, grudges, the last threat, and what
/// they did.
#[derive(Clone, Debug, Default, PartialEq)]
pub struct Memory {
    pub known: Vec<Known>,
    /// Who hurt me, and how much, most recent last.
    pub hurt_by: Vec<(ActorId, f32)>,
    /// The last hostile seen: who, where, when.
    pub last_threat: Option<(ActorId, Vec3, u64)>,
    /// Everything they did, and when (tick), oldest first; the oldest go
    /// past `DONE_KEPT`.
    pub done: Vec<(u64, Did)>,
    /// What they learned about staying alive (topside life.md "Learning
    /// to stay alive").
    pub learned: crate::learn::Learned,
}

/// How many things done a person remembers.
pub const DONE_KEPT: usize = 1024;

/// Memories older than this are forgotten (ticks at 60 a second: a
/// game day of 1200 s is 72000 ticks; a thing is remembered for
/// three days).
pub const FORGET_AFTER: u64 = 3 * 72_000;

impl Memory {
    /// Note a thing seen now. An already known thing is refreshed
    /// (its seen tick and position), never duplicated.
    pub fn see(&mut self, key: u64, kind: &str, position: Vec3, now: u64) {
        match self.known.iter_mut().find(|k| k.key == key) {
            Some(k) => {
                k.seen_at = now;
                k.position = position;
            }
            None => self.known.push(Known {
                key,
                kind: kind.to_string(),
                position,
                seen_at: now,
                checked_at: None,
                held: None,
            }),
        }
    }

    /// Note a thing checked up close now: what was found inside it,
    /// each kind with how many (empty when bare).
    pub fn checked(&mut self, key: u64, held: Vec<(String, u32)>, now: u64) {
        if let Some(k) = self.known.iter_mut().find(|k| k.key == key) {
            k.checked_at = Some(now);
            k.seen_at = now;
            k.held = Some(held);
        }
    }

    /// A place (not a box) visited up close now: it counts as checked,
    /// and what it was believed to offer stays as it was.
    pub fn visited(&mut self, key: u64, now: u64) {
        if let Some(k) = self.known.iter_mut().find(|k| k.key == key) {
            k.checked_at = Some(now);
            k.seen_at = now;
        }
    }

    /// A thing is gone (despawned): forget it.
    pub fn gone(&mut self, key: u64) {
        self.known.retain(|k| k.key != key);
    }

    /// Note something done now.
    pub fn did(&mut self, what: Did, now: u64) {
        self.done.push((now, what));
        if self.done.len() > DONE_KEPT {
            self.done.remove(0);
        }
    }

    /// Who killed them last, and of what: None if they never died.
    pub fn killed_by(&self) -> Option<(Option<ActorId>, &str)> {
        self.done.iter().rev().find_map(|(_, d)| match d {
            Did::Died(by, of) => Some((*by, of.as_str())),
            _ => None,
        })
    }

    pub fn hurt(&mut self, by: ActorId, amount: f32) {
        self.hurt_by.push((by, amount));
        if self.hurt_by.len() > 16 {
            self.hurt_by.remove(0);
        }
    }

    pub fn threat(&mut self, who: ActorId, at: Vec3, now: u64) {
        self.last_threat = Some((who, at, now));
    }

    /// Drop what is too old to trust.
    pub fn forget_old(&mut self, now: u64) {
        self.known
            .retain(|k| now.saturating_sub(k.seen_at) < FORGET_AFTER);
        if let Some((_, _, when)) = self.last_threat
            && now.saturating_sub(when) >= FORGET_AFTER
        {
            self.last_threat = None;
        }
    }

    /// Known things worth something for `need` and believed to still
    /// hold something, with what they give. `worth` is the registry's
    /// answer for a remembered thing (the brain never reads the
    /// world, and memory never copies a def).
    pub fn good_for<'a>(
        &'a self,
        need: Need,
        worth: &'a dyn Fn(&Known, Need) -> f32,
    ) -> impl Iterator<Item = (&'a Known, f32)> + 'a {
        self.known
            .iter()
            .filter(|k| k.believed_to_hold())
            .filter_map(move |k| {
                let v = worth(k, need);
                (v > 0.0).then_some((k, v))
            })
    }

    /// Known things never checked up close, nearest to `from` first:
    /// where to go looking.
    pub fn unchecked_nearest(&self, from: Vec3) -> Option<&Known> {
        self.known
            .iter()
            .filter(|k| k.checked_at.is_none())
            .min_by(|a, b| {
                a.position
                    .distance(from)
                    .total_cmp(&b.position.distance(from))
            })
    }

    pub fn knows(&self, key: u64) -> bool {
        self.known.iter().any(|k| k.key == key)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    /// What a person did is kept in order, the oldest going past the
    /// limit, and the last death says who killed them.
    #[test]
    fn a_person_remembers_what_they_did_and_who_killed_them() {
        let mut m = Memory::default();
        assert_eq!(m.killed_by(), None);
        m.did(Did::Ate("canned food".to_string()), 5);
        m.did(Did::Died(Some(ActorId(7)), "hatchet".to_string()), 9);
        m.did(Did::Respawned, 10);
        m.did(Did::Died(None, "hunger".to_string()), 20);
        assert_eq!(m.killed_by(), Some((None, "hunger")));
        assert_eq!(m.done[0], (5, Did::Ate("canned food".to_string())));
        for t in 0..DONE_KEPT as u64 {
            m.did(Did::Slept, 100 + t);
        }
        assert_eq!(m.done.len(), DONE_KEPT);
        assert_eq!(m.done[0].1, Did::Slept, "the oldest went");
    }

    #[test]
    fn a_box_is_worth_the_food_seen_inside_it() {
        use crate::item::{FoodStats, ItemDef, ItemKind, ItemRegistry};
        let mut items = ItemRegistry::default();
        items
            .register(ItemDef {
                name: "canned food".to_string(),
                unique: false,
                kind: ItemKind::Food,
                max_stack: 10,
                quality_siblings: 1,
                combat: None,
                food: Some(FoodStats {
                    hunger: 50.0,
                    thirst: 0.0,
                    health: 5.0,
                }),
                storage: None,
                armor: None,
                good_for: Default::default(),
                picture: None,
                layer_slots: Vec::new(),
            })
            .unwrap();
        let mut memory = Memory::default();
        memory.see(1, "storage box", Vec3::ZERO, 0);
        assert_eq!(food_worth(&memory.known[0], Need::Hunger, &items), 0.0, "never looked inside");
        memory.checked(1, vec![("scrap".to_string(), 2), ("canned food".to_string(), 1)], 5);
        assert_eq!(food_worth(&memory.known[0], Need::Hunger, &items), 50.0, "the cans inside");
        assert_eq!(food_worth(&memory.known[0], Need::Thirst, &items), 0.0);
    }

    /// A well is worth its own water, seen or not, and never runs out.
    #[test]
    fn a_source_is_worth_what_it_fills() {
        use crate::item::{FoodStats, ItemDef, ItemKind, ItemRegistry};
        let mut items = ItemRegistry::default();
        items
            .register(ItemDef {
                name: "well".to_string(),
                unique: false,
                kind: ItemKind::Source,
                max_stack: 1,
                quality_siblings: 1,
                combat: None,
                food: Some(FoodStats {
                    hunger: 0.0,
                    thirst: 100.0,
                    health: 0.0,
                }),
                storage: None,
                armor: None,
                good_for: Default::default(),
                picture: None,
                layer_slots: Vec::new(),
            })
            .unwrap();
        let mut memory = Memory::default();
        memory.see(1, "well", Vec3::ZERO, 0);
        assert_eq!(food_worth(&memory.known[0], Need::Thirst, &items), 100.0, "the well's water");
        assert_eq!(food_worth(&memory.known[0], Need::Hunger, &items), 0.0);
        assert!(memory.known[0].believed_to_hold(), "a source is never empty");
    }

    /// The registry's answer in these tests: a storage box is worth
    /// 50 for hunger, nothing else is worth anything.
    fn worth(known: &Known, need: Need) -> f32 {
        if known.kind == "storage box" && need == Need::Hunger {
            50.0
        } else {
            0.0
        }
    }

    /// One of each kind named.
    fn kinds(kinds: &[&str]) -> Vec<(String, u32)> {
        kinds.iter().map(|k| (k.to_string(), 1)).collect()
    }

    #[test]
    fn a_bunker_is_short_of_what_does_not_cover_everyone_for_the_days() {
        use crate::item::{FoodStats, ItemDef, ItemKind, ItemRegistry};
        let mut items = ItemRegistry::default();
        for (name, hunger, thirst) in [("canned food", 50.0, 0.0), ("water bottle", 0.0, 50.0)] {
            items
                .register(ItemDef {
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
        // Two people, one day, 100 hunger and 200 thirst each a day: four
        // cans and eight bottles cover it.
        let per_day = (100.0, 200.0);
        let enough = [("canned food", 4), ("water bottle", 8)];
        assert!(short_of(enough, 2, 1.0, per_day, &items).is_empty());
        assert_eq!(short_of([("canned food", 4), ("water bottle", 2)], 2, 1.0, per_day, &items), [Need::Thirst]);
        assert_eq!(short_of([("canned food", 1), ("water bottle", 8)], 2, 1.0, per_day, &items), [Need::Hunger]);
        assert_eq!(
            short_of([("canned food", 2), ("water bottle", 1)], 2, 1.0, per_day, &items),
            [Need::Thirst, Need::Hunger],
            "short of both, the shortest first"
        );
    }

    #[test]
    fn seeing_twice_refreshes_and_never_duplicates() {
        let mut m = Memory::default();
        m.see(7, "storage box", Vec3::new(1.0, 0.0, 0.0), 10);
        m.see(7, "storage box", Vec3::new(2.0, 0.0, 0.0), 20);
        assert_eq!(m.known.len(), 1);
        assert_eq!(m.known[0].seen_at, 20);
        assert_eq!(m.known[0].position.x, 2.0);
        assert!(m.knows(7) && !m.knows(8));
    }

    #[test]
    fn a_checked_box_is_remembered_by_what_it_held() {
        let mut m = Memory::default();
        m.see(7, "storage box", Vec3::ZERO, 10);
        assert!(m.known[0].believed_to_hold(), "never looked: believed full");
        assert!(!m.known[0].held_kind("canned food"), "not seen yet");
        m.checked(7, vec![("canned food".to_string(), 7), ("canned food".to_string(), 3), ("pipe".to_string(), 1)], 30);
        let box_ = &m.known[0];
        assert_eq!(box_.checked_at, Some(30));
        assert!(box_.held_kind("canned food") && box_.held_kind("pipe"));
        assert_eq!(box_.held_count("canned food"), 10, "every stack counted");
        assert!(!box_.held_kind("cloth"));
        assert!(box_.believed_to_hold());
    }

    #[test]
    fn checked_empty_things_are_not_good_for_anything_until_seen_full_again() {
        let mut m = Memory::default();
        m.see(7, "storage box", Vec3::ZERO, 10);
        assert_eq!(m.good_for(Need::Hunger, &worth).count(), 1);
        assert_eq!(
            m.good_for(Need::Rest, &worth).count(),
            0,
            "a box is not a bed"
        );
        m.checked(7, vec![], 30);
        assert_eq!(m.good_for(Need::Hunger, &worth).count(), 0, "known empty");
        assert!(
            m.unchecked_nearest(Vec3::ZERO).is_none(),
            "checked, so not a place to look"
        );
        m.checked(7, kinds(&["canned food"]), 40);
        assert_eq!(m.good_for(Need::Hunger, &worth).count(), 1);
    }

    #[test]
    fn looking_goes_to_the_nearest_unchecked_thing() {
        let mut m = Memory::default();
        m.see(1, "wreck", Vec3::new(50.0, 0.0, 0.0), 1);
        m.see(2, "wreck", Vec3::new(10.0, 0.0, 0.0), 1);
        m.see(3, "wreck", Vec3::new(5.0, 0.0, 0.0), 1);
        m.checked(3, vec![], 2);
        assert_eq!(m.unchecked_nearest(Vec3::ZERO).unwrap().key, 2);
    }

    #[test]
    fn old_things_and_threats_are_forgotten_and_grudges_are_kept_short() {
        let mut m = Memory::default();
        m.see(1, "wreck", Vec3::ZERO, 0);
        m.threat(ActorId(9), Vec3::ZERO, 0);
        m.forget_old(FORGET_AFTER - 1);
        assert_eq!(m.known.len(), 1);
        assert!(m.last_threat.is_some());
        m.forget_old(FORGET_AFTER);
        assert!(m.known.is_empty());
        assert!(m.last_threat.is_none());
        for i in 0..20 {
            m.hurt(ActorId(i), 1.0);
        }
        assert_eq!(m.hurt_by.len(), 16);
        assert_eq!(m.hurt_by.last().unwrap().0, ActorId(19));
        m.gone(1);
    }
}
