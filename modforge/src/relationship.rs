//! Relationships at both levels (topside life.md "How a person feels
//! about others", operator 2026-09-27). A person's feeling toward
//! another comes from their own memory; a faction's standing is worked
//! out from its members' feelings, never kept as a second record; a
//! person acts on their own feeling first, else on their faction's
//! standing, else on the faction table they start with. Prior art:
//! RimWorld's pawn opinions and faction goodwill, Mount & Blade's lord
//! and kingdom relations.

use crate::actor::ActorId;
use crate::faction::Relation;
use crate::memory::{Did, Memory};

/// A feeling at or below this is hostile: they fight on sight.
pub const HOSTILE: f32 = -0.5;
/// A feeling at or above this is friendly.
pub const FRIENDLY: f32 = 0.5;
/// Damage that makes the one hit feel fully hostile (-1): a hit of half
/// this is enough to fight.
pub const HIT_HATED: f32 = 50.0;

/// How a person feels toward `toward`, from -1 (hate) to 1 (love), from
/// their own memory: hit by them, killed by them, and what they heard
/// from them (`heard`: how hearing those words feels, from the content
/// that wrote them). None when they have nothing of them in memory.
pub fn feeling(memory: &Memory, toward: ActorId, heard: impl Fn(&str) -> f32) -> Option<f32> {
    let mut felt = None::<f32>;
    for (_, did) in &memory.done {
        let this = match did {
            Did::WasHit(Some(by), amount) if *by == toward => -amount / HIT_HATED,
            Did::Died(Some(by), _) if *by == toward => -1.0,
            Did::Heard(by, words) if *by == toward => heard(words),
            _ => continue,
        };
        felt = Some(felt.unwrap_or(0.0) + this);
    }
    felt.map(|f| f.clamp(-1.0, 1.0))
}

/// Every person they have a feeling toward, with it, in the order they
/// first come up in memory.
pub fn feelings(memory: &Memory, heard: impl Fn(&str) -> f32) -> Vec<(ActorId, f32)> {
    let mut people: Vec<ActorId> = Vec::new();
    for (_, did) in &memory.done {
        let who = match did {
            Did::WasHit(Some(by), _) | Did::Died(Some(by), _) | Did::Heard(by, _) => *by,
            _ => continue,
        };
        if !people.contains(&who) {
            people.push(who);
        }
    }
    people.into_iter().filter_map(|who| feeling(memory, who, &heard).map(|f| (who, f))).collect()
}

/// A faction's standing toward someone: its members' feelings taken
/// together, one per member, a member with none counting as neutral (0),
/// so one member's grudge moves it a little and it grows as more of them
/// feel it. None when no member has a feeling.
pub fn standing(feelings: impl IntoIterator<Item = Option<f32>>) -> Option<f32> {
    let (sum, members, felt) = feelings
        .into_iter()
        .fold((0.0, 0u32, false), |(s, n, felt), f| (s + f.unwrap_or(0.0), n + 1, felt || f.is_some()));
    felt.then(|| sum / members as f32)
}

/// A feeling as a relation.
pub fn relation_of(feeling: f32) -> Relation {
    if feeling <= HOSTILE {
        Relation::Hostile
    } else if feeling >= FRIENDLY {
        Relation::Friendly
    } else {
        Relation::Neutral
    }
}

/// How one person stands to another: their own feeling when they have
/// one, else their faction's standing, else the faction table
/// (`FactionRegistry::relation`, what the factions start as).
pub fn stands(own: Option<f32>, faction: Option<f32>, table: Relation) -> Relation {
    own.or(faction).map_or(table, relation_of)
}

#[cfg(test)]
mod tests {
    use super::*;

    const PLAYER: ActorId = ActorId(1);
    const OTHER: ActorId = ActorId(2);

    fn threat(words: &str) -> f32 {
        if words == "Step away from it." { -0.6 } else { 0.0 }
    }

    #[test]
    fn nothing_in_memory_is_no_feeling() {
        assert_eq!(feeling(&Memory::default(), PLAYER, threat), None);
    }

    #[test]
    fn hit_hard_enough_is_hostile_to_the_one_who_hit() {
        let mut mara = Memory::default();
        mara.did(Did::WasHit(Some(PLAYER), 30.0), 1);
        let felt = feeling(&mara, PLAYER, threat);
        assert_eq!(felt, Some(-0.6));
        assert_eq!(stands(felt, None, Relation::Neutral), Relation::Hostile);
        // Only toward the one who hit.
        assert_eq!(feeling(&mara, OTHER, threat), None);
    }

    #[test]
    fn a_threat_heard_is_hostile() {
        let mut mara = Memory::default();
        mara.did(Did::Heard(PLAYER, "Step away from it.".to_string()), 1);
        assert_eq!(stands(feeling(&mara, PLAYER, threat), None, Relation::Neutral), Relation::Hostile);
    }

    #[test]
    fn killed_by_them_is_full_hate() {
        let mut mara = Memory::default();
        mara.did(Did::Died(Some(PLAYER), "hatchet".to_string()), 1);
        mara.did(Did::Heard(PLAYER, "Step away from it.".to_string()), 2);
        assert_eq!(feeling(&mara, PLAYER, threat), Some(-1.0));
    }

    #[test]
    fn a_member_hit_is_hostile_while_their_faction_mates_are_not() {
        let mut hit = Memory::default();
        hit.did(Did::WasHit(Some(PLAYER), 30.0), 1);
        let mates = [Memory::default(), Memory::default(), Memory::default()];
        let faction = standing(std::iter::once(&hit).chain(&mates).map(|m| feeling(m, PLAYER, threat)));
        assert_eq!(faction, Some(-0.15), "one grudge in four moves the faction a little");
        assert_eq!(stands(feeling(&hit, PLAYER, threat), faction, Relation::Neutral), Relation::Hostile);
        assert_eq!(stands(feeling(&mates[0], PLAYER, threat), faction, Relation::Neutral), Relation::Neutral);
        // Nobody with a feeling: no standing, the table decides.
        assert_eq!(standing(mates.iter().map(|m| feeling(m, PLAYER, threat))), None);
    }

    #[test]
    fn a_member_with_no_feeling_follows_the_faction() {
        let mut a = Memory::default();
        a.did(Did::WasHit(Some(PLAYER), 40.0), 1);
        let mut b = Memory::default();
        b.did(Did::Died(Some(PLAYER), "pipe".to_string()), 1);
        let newcomer_memory = Memory::default();
        let faction = standing([&a, &b, &newcomer_memory].into_iter().map(|m| feeling(m, PLAYER, threat)));
        let newcomer = feeling(&newcomer_memory, PLAYER, threat);
        assert_eq!(newcomer, None);
        assert_eq!(stands(newcomer, faction, Relation::Neutral), Relation::Hostile);
        // With no faction standing either, the table decides.
        assert_eq!(stands(None, None, Relation::Friendly), Relation::Friendly);
    }

    #[test]
    fn feelings_are_toward_everyone_in_memory() {
        let mut mara = Memory::default();
        mara.did(Did::Heard(PLAYER, "Step away from it.".to_string()), 1);
        mara.did(Did::Slept, 2);
        mara.did(Did::WasHit(Some(OTHER), 10.0), 3);
        mara.did(Did::Heard(PLAYER, "hello".to_string()), 4);
        assert_eq!(feelings(&mara, threat), vec![(PLAYER, -0.6), (OTHER, -0.2)]);
    }

    #[test]
    fn own_feeling_comes_before_the_faction() {
        let mut friend = Memory::default();
        friend.did(Did::Heard(PLAYER, "hello".to_string()), 1);
        let warm = |_: &str| 0.6;
        assert_eq!(stands(feeling(&friend, PLAYER, warm), Some(-0.9), Relation::Hostile), Relation::Friendly);
    }
}
