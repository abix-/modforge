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
    /// A line was said that told of nothing.
    Said,
}

/// Which way to go out of a door facing `outward` to head for `to` (both
/// on the ground, from the door): "straight out" within 35 degrees, else
/// "left" or "right" (right is the facing turned a quarter towards +y,
/// as topside reads WASD).
pub fn way_out(outward: glam::Vec2, to: glam::Vec2) -> &'static str {
    if outward.angle_to(to).abs() <= 35f32.to_radians() {
        "straight out"
    } else {
        side_of(outward, to)
    }
}

/// Which side of someone walking along `along` a point `at` (from where
/// they are) stands: "right" or "left", the same hand as `way_out`.
pub fn side_of(along: glam::Vec2, at: glam::Vec2) -> &'static str {
    if along.perp_dot(at) > 0.0 { "right" } else { "left" }
}

/// One person says something to another: `offered` is the item in the
/// offered slot, if any; `words` a line's words (`Said::Line`). Both
/// memories remember what was said; a told thing is known by the
/// listener, told by the speaker.
pub fn talk(
    said: Said,
    (speaker, speaker_memory): (ActorId, &mut Memory),
    (listener, listener_memory): (ActorId, &mut Memory),
    (offered, words): (Option<&str>, Option<&str>),
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
        Said::Line { key, .. } => {
            let Some(words) = words else {
                return Answer::Nothing;
            };
            let thing = (key != 0).then(|| speaker_memory.known.iter().find(|k| k.key == key).cloned()).flatten();
            if let Some(thing) = &thing {
                listener_memory.told(thing, speaker, now);
            }
            say(words.to_string(), speaker_memory, listener_memory);
            thing.map_or(Answer::Said, |t| Answer::Learned(t.key))
        }
    }
}

/// Word spreads (topside life.md "How a person feels about others"): the
/// teller tells the listener what was done to them by someone else, each
/// thing once: hit, killed, or said something that is felt (`heard`, as
/// `relationship::feeling` reads it). Only what happened to the teller
/// themselves, never what they were told. The number of things told.
pub fn share(
    (teller, teller_memory): (ActorId, &Memory),
    (listener, listener_memory): (ActorId, &mut Memory),
    heard: impl Fn(&str) -> f32,
    now: u64,
) -> usize {
    let mut told = 0;
    for (when, did) in &teller_memory.done {
        let by = match did {
            Did::WasHit(Some(by), _) | Did::Died(Some(by), _) => *by,
            Did::Heard(by, words) if heard(words) != 0.0 => *by,
            _ => continue,
        };
        if by == listener || by == teller {
            continue;
        }
        let already = listener_memory
            .done
            .iter()
            .any(|(_, d)| matches!(d, Did::WasTold(from, at, what) if *from == teller && at == when && **what == *did));
        if !already {
            listener_memory.did(Did::WasTold(teller, *when, Box::new(did.clone())), now);
            told += 1;
        }
    }
    told
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
        let answer = talk(Said::Tell { key: TAP }, (DELL, &mut dell), (PLAYER, &mut player), (None, None), 20);
        assert_eq!(answer, Answer::Learned(TAP));
        let known = player.known.iter().find(|k| k.key == TAP).expect("the player knows the tap");
        assert_eq!((known.kind.as_str(), known.told_by), ("tap", Some(DELL)));
        assert_eq!(dell.done.last(), Some(&(20, Did::Talked(PLAYER, "told of the tap".to_string()))));
        assert_eq!(player.done.last(), Some(&(20, Did::Heard(DELL, "told of the tap".to_string()))));
    }

    #[test]
    fn nobody_tells_what_they_do_not_know() {
        let (mut dell, mut player) = (Memory::default(), Memory::default());
        assert_eq!(talk(Said::Tell { key: TAP }, (DELL, &mut dell), (PLAYER, &mut player), (None, None), 20), Answer::Nothing);
        assert!(player.known.is_empty() && player.done.is_empty());
    }

    #[test]
    fn an_ask_is_answered_only_with_what_the_listener_knows() {
        let (mut player, mut dell) = (Memory::default(), dell_knows_the_tap());
        assert_eq!(talk(Said::Ask { key: TAP }, (PLAYER, &mut player), (DELL, &mut dell), (None, None), 20), Answer::ToldBack(TAP));
        assert_eq!(player.known.iter().find(|k| k.key == TAP).and_then(|k| k.told_by), Some(DELL));
        let (mut player, mut stranger) = (Memory::default(), Memory::default());
        assert_eq!(talk(Said::Ask { key: TAP }, (PLAYER, &mut player), (ActorId(9), &mut stranger), (None, None), 20), Answer::DontKnow);
        assert!(player.known.is_empty());
    }

    #[test]
    fn seeing_a_thing_beats_being_told_of_it() {
        let (mut dell, mut player) = (dell_knows_the_tap(), Memory::default());
        talk(Said::Tell { key: TAP }, (DELL, &mut dell), (PLAYER, &mut player), (None, None), 20);
        player.see(TAP, "tap", Vec3::new(150.0, 0.0, 1.0), 30);
        assert_eq!(player.known.iter().find(|k| k.key == TAP).and_then(|k| k.told_by), None);
    }

    #[test]
    fn a_line_is_remembered_by_both_and_tells_what_it_names() {
        let (mut dell, mut player) = (dell_knows_the_tap(), Memory::default());
        let words = "Out the door, then left. The gas station has a tap.";
        let answer = talk(Said::Line { line: 0, key: TAP }, (DELL, &mut dell), (PLAYER, &mut player), (None, Some(words)), 20);
        assert_eq!(answer, Answer::Learned(TAP));
        assert_eq!(player.known.iter().find(|k| k.key == TAP).and_then(|k| k.told_by), Some(DELL));
        assert_eq!(player.done.last(), Some(&(20, Did::Heard(DELL, words.to_string()))));
        let answer = talk(Said::Line { line: 1, key: 0 }, (PLAYER, &mut player), (DELL, &mut dell), (None, Some("Show me.")), 21);
        assert_eq!(answer, Answer::Said);
        assert_eq!(dell.done.last(), Some(&(21, Did::Heard(PLAYER, "Show me.".to_string()))));
    }

    #[test]
    fn the_way_out_of_a_door_and_the_side_of_a_landmark() {
        use glam::Vec2;
        let out = Vec2::new(0.0, 1.0);
        assert_eq!(way_out(out, Vec2::new(0.1, 5.0)), "straight out");
        assert_eq!(way_out(out, Vec2::new(-5.0, 1.0)), "right");
        assert_eq!(way_out(out, Vec2::new(5.0, 1.0)), "left");
        assert_eq!(side_of(out, Vec2::new(-3.0, 4.0)), "right");
        assert_eq!(side_of(out, Vec2::new(3.0, 4.0)), "left");
    }

    #[test]
    fn a_threat_and_an_offer_are_remembered_by_both() {
        let (mut player, mut mara) = (Memory::default(), Memory::default());
        assert_eq!(talk(Said::Threaten, (PLAYER, &mut player), (ActorId(8), &mut mara), (None, None), 20), Answer::Threatened);
        assert_eq!(mara.done.last(), Some(&(20, Did::Heard(PLAYER, "threatened them".to_string()))));
        let answer = talk(Said::Offer { slot: 0 }, (PLAYER, &mut player), (ActorId(8), &mut mara), (Some("water bottle"), None), 21);
        assert_eq!(answer, Answer::Offered("water bottle".to_string()));
        assert_eq!(player.done.last(), Some(&(21, Did::Talked(ActorId(8), "offered water bottle".to_string()))));
    }

    fn threat(words: &str) -> f32 {
        if words == "Step away from it." { -0.6 } else { 0.0 }
    }

    #[test]
    fn a_mate_is_told_what_was_done_and_feels_it_less() {
        const MARA: ActorId = ActorId(8);
        const MATE: ActorId = ActorId(9);
        let mut mara = Memory::default();
        mara.did(Did::Heard(PLAYER, "Step away from it.".to_string()), 5);
        mara.did(Did::Heard(PLAYER, "Busy.".to_string()), 6);
        mara.did(Did::WasHit(Some(PLAYER), 30.0), 7);
        mara.did(Did::Slept, 8);
        let mut mate = Memory::default();
        // The threat and the hit; words nobody feels are not worth telling.
        assert_eq!(share((MARA, &mara), (MATE, &mut mate), threat, 20), 2);
        assert_eq!(mate.done.first(), Some(&(20, Did::WasTold(MARA, 5, Box::new(Did::Heard(PLAYER, "Step away from it.".to_string()))))));
        // Each thing once.
        assert_eq!(share((MARA, &mara), (MATE, &mut mate), threat, 21), 0);
        // Felt at half: (-0.6 - 0.6) / 2.
        let felt = crate::relationship::feeling(&mate, PLAYER, threat).unwrap();
        assert!((felt + 0.6).abs() < 1e-5, "{felt}");
        assert_eq!(crate::relationship::feelings(&mate, threat).len(), 1);
    }

    #[test]
    fn only_what_was_done_to_the_teller_is_told() {
        const MARA: ActorId = ActorId(8);
        const MATE: ActorId = ActorId(9);
        let mut mate = Memory::default();
        mate.did(Did::WasHit(Some(PLAYER), 30.0), 5);
        let mut mara = Memory::default();
        assert_eq!(share((MATE, &mate), (MARA, &mut mara), threat, 10), 1);
        // What Mara was told she does not tell on, and nobody is told what
        // they did themselves.
        let mut other = Memory::default();
        assert_eq!(share((MARA, &mara), (ActorId(10), &mut other), threat, 11), 0);
        assert_eq!(share((MATE, &mate), (PLAYER, &mut other), threat, 11), 0);
    }
}
