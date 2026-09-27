//! Talking (topside, operator 2026-09-27): one person says something to
//! another in reach, and both remember it. What a listener answers comes
//! only from their memory (topside life.md "What a person knows": told):
//! asked about a thing, they tell it back if they know it. The player and
//! every NPC talk the same way (`Action::Talk`). Prior art: Dwarf
//! Fortress adventure mode's asking about surroundings and rumours,
//! Morrowind's topics.

use crate::actions::Said;
use crate::actor::ActorId;
use crate::memory::{Did, Memory};

/// What came of one `Talk`.
#[derive(Clone, Debug, PartialEq)]
pub enum Answer {
    /// The listener was told of the thing with this key.
    Learned(u64),
    /// Asked, the listener told the speaker of the thing with this key.
    ToldBack(u64),
    /// Asked, the listener does not know the thing.
    DontKnow,
    /// The speaker offered this item.
    Offered(String),
    /// The speaker threatened the listener.
    Threatened,
    /// Nothing was said: the speaker does not know what they would tell,
    /// or offered an empty slot.
    Nothing,
}

/// One person says something to another: `offered` is the item in the
/// offered slot, if any. Both memories remember what was said; a told
/// thing is known by the listener, told by the speaker.
pub fn talk(
    said: Said,
    (speaker, speaker_memory): (ActorId, &mut Memory),
    (listener, listener_memory): (ActorId, &mut Memory),
    offered: Option<&str>,
    now: u64,
) -> Answer {
    let say = |words: String, speaker_memory: &mut Memory, listener_memory: &mut Memory| {
        speaker_memory.did(Did::Talked(listener, words.clone()), now);
        listener_memory.did(Did::Heard(speaker, words), now);
    };
    match said {
        Said::Tell { key } => {
            let Some(thing) = speaker_memory.known.iter().find(|k| k.key == key).cloned() else {
                return Answer::Nothing;
            };
            listener_memory.told(&thing, speaker, now);
            say(format!("told of the {}", thing.kind), speaker_memory, listener_memory);
            Answer::Learned(key)
        }
        Said::Ask { key } => {
            let about = speaker_memory.known.iter().find(|k| k.key == key).map_or("something".to_string(), |k| k.kind.clone());
            say(format!("asked about the {about}"), speaker_memory, listener_memory);
            let Some(thing) = listener_memory.known.iter().find(|k| k.key == key).cloned() else {
                return Answer::DontKnow;
            };
            speaker_memory.told(&thing, listener, now);
            listener_memory.did(Did::Talked(speaker, format!("told of the {}", thing.kind)), now);
            speaker_memory.did(Did::Heard(listener, format!("told of the {}", thing.kind)), now);
            Answer::ToldBack(key)
        }
        Said::Offer { .. } => {
            let Some(item) = offered else {
                return Answer::Nothing;
            };
            say(format!("offered {item}"), speaker_memory, listener_memory);
            Answer::Offered(item.to_string())
        }
        Said::Threaten => {
            say("threatened them".to_string(), speaker_memory, listener_memory);
            Answer::Threatened
        }
    }
}

#[cfg(test)]
mod tests {
    use glam::Vec3;

    use super::*;

    const DELL: ActorId = ActorId(3);
    const PLAYER: ActorId = ActorId(1);
    const TAP: u64 = 77;

    fn dell_knows_the_tap() -> Memory {
        let mut memory = Memory::default();
        memory.see(TAP, "tap", Vec3::new(150.0, 0.0, 1.0), 10);
        memory
    }

    #[test]
    fn a_told_thing_is_known_with_who_told_it() {
        let (mut dell, mut player) = (dell_knows_the_tap(), Memory::default());
        let answer = talk(Said::Tell { key: TAP }, (DELL, &mut dell), (PLAYER, &mut player), None, 20);
        assert_eq!(answer, Answer::Learned(TAP));
        let known = player.known.iter().find(|k| k.key == TAP).expect("the player knows the tap");
        assert_eq!((known.kind.as_str(), known.told_by), ("tap", Some(DELL)));
        assert_eq!(dell.done.last(), Some(&(20, Did::Talked(PLAYER, "told of the tap".to_string()))));
        assert_eq!(player.done.last(), Some(&(20, Did::Heard(DELL, "told of the tap".to_string()))));
    }

    #[test]
    fn nobody_tells_what_they_do_not_know() {
        let (mut dell, mut player) = (Memory::default(), Memory::default());
        assert_eq!(talk(Said::Tell { key: TAP }, (DELL, &mut dell), (PLAYER, &mut player), None, 20), Answer::Nothing);
        assert!(player.known.is_empty() && player.done.is_empty());
    }

    #[test]
    fn an_ask_is_answered_only_with_what_the_listener_knows() {
        let (mut player, mut dell) = (Memory::default(), dell_knows_the_tap());
        assert_eq!(talk(Said::Ask { key: TAP }, (PLAYER, &mut player), (DELL, &mut dell), None, 20), Answer::ToldBack(TAP));
        assert_eq!(player.known.iter().find(|k| k.key == TAP).and_then(|k| k.told_by), Some(DELL));
        let (mut player, mut stranger) = (Memory::default(), Memory::default());
        assert_eq!(talk(Said::Ask { key: TAP }, (PLAYER, &mut player), (ActorId(9), &mut stranger), None, 20), Answer::DontKnow);
        assert!(player.known.is_empty());
    }

    #[test]
    fn seeing_a_thing_beats_being_told_of_it() {
        let (mut dell, mut player) = (dell_knows_the_tap(), Memory::default());
        talk(Said::Tell { key: TAP }, (DELL, &mut dell), (PLAYER, &mut player), None, 20);
        player.see(TAP, "tap", Vec3::new(150.0, 0.0, 1.0), 30);
        assert_eq!(player.known.iter().find(|k| k.key == TAP).and_then(|k| k.told_by), None);
    }

    #[test]
    fn a_threat_and_an_offer_are_remembered_by_both() {
        let (mut player, mut mara) = (Memory::default(), Memory::default());
        assert_eq!(talk(Said::Threaten, (PLAYER, &mut player), (ActorId(8), &mut mara), None, 20), Answer::Threatened);
        assert_eq!(mara.done.last(), Some(&(20, Did::Heard(PLAYER, "threatened them".to_string()))));
        let answer = talk(Said::Offer { slot: 0 }, (PLAYER, &mut player), (ActorId(8), &mut mara), Some("water bottle"), 21);
        assert_eq!(answer, Answer::Offered("water bottle".to_string()));
        assert_eq!(player.done.last(), Some(&(21, Did::Talked(ActorId(8), "offered water bottle".to_string()))));
    }
}
