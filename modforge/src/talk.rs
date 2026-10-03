//! Talking (topside, operator 2026-09-27): one person says something to
//! another in reach, and both remember it. What a listener answers comes
//! only from their memory (topside life.md "What a person knows": told):
//! asked about a thing, they tell it back if they know it. The player and
//! every NPC talk the same way (`Action::Talk`). Prior art: Dwarf
//! Fortress adventure mode's asking about surroundings and rumours,
//! Morrowind's topics.
//!
//! What anyone says is one way for every conversation, an episode's or
//! plain talk (topside episodes.md "One way for every conversation"):
//! lines are rules (`storyteller::LineDef`), and the line said is the one
//! whose conditions on the speaker match best (`pick`), the player's
//! choices the ones that match for them (`choices`). Prior art: Valve's
//! response rules (Left 4 Dead, Elan Ruskin, GDC 2012).

use crate::actions::Said;
use crate::actor::ActorId;
use crate::memory::{Did, Line, Memory};
use crate::storyteller::{LineDef, When};

/// How fast a line is read, in characters a second (subtitle practice:
/// about 15), and the least time any line stays to be read, in seconds.
pub const READ_CHARS_PER_SEC: f64 = 15.0;
pub const READ_LEAST_SECS: f64 = 1.5;

/// How long these words take to read, in real seconds: the one rule for
/// how long a conversation waits on a line before the next line, the
/// player's choices, or its end.
pub fn reading_secs(words: &str) -> f64 {
    (words.chars().count() as f64 / READ_CHARS_PER_SEC).max(READ_LEAST_SECS)
}

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
    /// The speaker asked the listener to trade.
    AskedToTrade,
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
/// offered slot, if any; `line` a line's name and words as said
/// (`Said::Line`). Both memories remember what was said, by its name and
/// words; a told thing is known by the listener, told by the speaker.
pub fn talk(
    said: Said,
    (speaker, speaker_memory): (ActorId, &mut Memory),
    (listener, listener_memory): (ActorId, &mut Memory),
    (offered, line): (Option<&str>, Option<(&str, &str)>),
    now: u64,
) -> Answer {
    let say = |name: &str, words: String, speaker_memory: &mut Memory, listener_memory: &mut Memory| {
        let line = Line { name: name.to_string(), words };
        speaker_memory.did(Did::Talked(listener, line.clone()), now);
        listener_memory.did(Did::Heard(speaker, line), now);
    };
    match said {
        Said::Tell { key } => {
            let Some(thing) = speaker_memory.known.iter().find(|k| k.key == key).cloned() else {
                return Answer::Nothing;
            };
            listener_memory.told(&thing, speaker, now);
            say("told", format!("told of the {}", thing.kind), speaker_memory, listener_memory);
            Answer::Learned(key)
        }
        Said::Ask { key } => {
            let about = speaker_memory.known.iter().find(|k| k.key == key).map_or("something".to_string(), |k| k.kind.clone());
            say("asked", format!("asked about the {about}"), speaker_memory, listener_memory);
            let Some(thing) = listener_memory.known.iter().find(|k| k.key == key).cloned() else {
                return Answer::DontKnow;
            };
            speaker_memory.told(&thing, listener, now);
            let told = Line { name: "told".to_string(), words: format!("told of the {}", thing.kind) };
            listener_memory.did(Did::Talked(speaker, told.clone()), now);
            speaker_memory.did(Did::Heard(listener, told), now);
            Answer::ToldBack(key)
        }
        Said::Offer { .. } => {
            let Some(item) = offered else {
                return Answer::Nothing;
            };
            say("offered", format!("offered {item}"), speaker_memory, listener_memory);
            Answer::Offered(item.to_string())
        }
        Said::Threaten => {
            say("threatened", "threatened them".to_string(), speaker_memory, listener_memory);
            Answer::Threatened
        }
        // Whether they will, and at what prices, is how they stand toward
        // the speaker (crate::trade::terms), the consumer's to read.
        Said::Trade => {
            say("asked to trade", "asked to trade".to_string(), speaker_memory, listener_memory);
            Answer::AskedToTrade
        }
        Said::Line { key, .. } => {
            let Some((name, words)) = line else {
                return Answer::Nothing;
            };
            let thing = (key != 0).then(|| speaker_memory.known.iter().find(|k| k.key == key).cloned()).flatten();
            if let Some(thing) = &thing {
                listener_memory.told(thing, speaker, now);
            }
            say(name, words.to_string(), speaker_memory, listener_memory);
            thing.map_or(Answer::Said, |t| Answer::Learned(t.key))
        }
    }
}

/// What is true of someone who may speak, for matching lines against
/// (`pick`, `choices`): all read by the consumer from its world and the
/// speaker's memory.
pub struct Speaking<'a> {
    /// The speaker's part: "player", the episode part they are cast as,
    /// or "".
    pub part: &'a str,
    /// The one spoken to's part, the same way.
    pub to_part: &'a str,
    /// The one spoken to.
    pub to: ActorId,
    /// The speaker's memory.
    pub memory: &'a Memory,
    /// The tick this conversation started: what was said before it
    /// belongs to another conversation.
    pub since: u64,
    /// The one spoken to started this conversation (the player's E).
    pub opened: bool,
    /// The episode's pivot points reached so far.
    pub reached: &'a [String],
    /// How far the speaker stands from each thing the episode brought in,
    /// by its name.
    pub near: &'a [(String, f32)],
    /// The speaker's needs by name ("hunger", "thirst"), as the survival
    /// numbers have them.
    pub needs: &'a [(String, f32)],
    /// The speaker is knocking on a shut door now: a line said is called
    /// through it, heard like the knock (topside authority.md "Talking").
    pub knocking: bool,
    /// The speaker holds a place and warns off one who comes for it: a
    /// line said is called to them (topside todo 11z).
    pub warning: bool,
    /// How the speaker feels toward the one spoken to (relationship::
    /// feeling, 0 with none), for `When::Feels`.
    pub feels: f32,
}

impl Speaking<'_> {
    /// The lines of this conversation between the speaker and the one
    /// they talk to, as (place in memory, heard, line): heard true for
    /// what the speaker heard, false for what they said.
    fn this_conversation(&self) -> impl DoubleEndedIterator<Item = (usize, bool, &Line)> {
        self.memory.done.iter().enumerate().filter_map(move |(at, (t, did))| {
            if *t < self.since {
                return None;
            }
            match did {
                Did::Heard(by, line) if *by == self.to => Some((at, true, line)),
                Did::Talked(to, line) if *to == self.to => Some((at, false, line)),
                _ => None,
            }
        })
    }

    /// The last line of this conversation and whether the speaker heard
    /// it (true) or said it (false).
    fn last(&self) -> Option<(bool, &Line)> {
        self.this_conversation().next_back().map(|(_, heard, line)| (heard, line))
    }

    fn holds(&self, when: &When) -> bool {
        match when {
            When::To(part) => self.to_part == part,
            When::Opened => self.opened,
            When::Knocking => self.knocking,
            When::Warning => self.warning,
            When::Feels(at_least) => self.feels >= *at_least,
            When::First => self.last().is_none(),
            When::Heard(name) => matches!(self.last(), Some((true, line)) if line.name == *name),
            When::HasHeard(name) => {
                self.memory.done.iter().any(|(_, d)| matches!(d, Did::Heard(by, line) if *by == self.to && line.name == *name))
            }
            When::JustSaid(name) => matches!(self.last(), Some((false, line)) if line.name == *name),
            When::Said(name) => self.memory.done.iter().any(|(_, d)| matches!(d, Did::Talked(_, line) if line.name == *name)),
            When::Reached(pivot) => self.reached.iter().any(|r| r == pivot),
            When::Knows(kind) => self.memory.known.iter().any(|k| k.kind == *kind && !self.memory.quiet.contains(&k.key)),
            When::Near(thing, metres) => self.near.iter().any(|(n, d)| n == thing && d <= metres),
            When::Needs(need, level) => self.needs.iter().any(|(n, v)| n == need && v <= level),
            When::Not(when) => !self.holds(when),
            When::Any(any) => any.iter().any(|w| self.holds(w)),
        }
    }

    /// Whether the speaker may say this line at all: their part, and
    /// every condition.
    fn matches(&self, line: &LineDef) -> bool {
        let part = match line.part.as_str() {
            "" => self.part != "player",
            part => self.part == part,
        };
        part && line.when.iter().all(|w| self.holds(w))
    }
}

/// How specific a line is: a part counts as one condition. The most
/// specific matching line is said (Valve's rule: the line that knows most
/// about the moment).
fn specific(line: &LineDef) -> usize {
    line.when.len() + usize::from(!line.part.is_empty())
}

/// Whether the line goes on from what the speaker just said
/// (`When::JustSaid` among its conditions).
fn goes_on(line: &LineDef) -> bool {
    line.when.iter().any(|w| matches!(w, When::JustSaid(_)))
}

/// What, if anything, an NPC says now, as the place of its line in
/// `lines`; the player's lines are `choices`. Whose turn it is comes from
/// the conversation in memory:
///
/// - heard something not yet answered: any matching line (a reply);
/// - said the last word: only a line that goes on from it
///   (`When::JustSaid`), else they have finished;
/// - nothing said yet, the other having started it: any matching line;
/// - nothing said yet, starting it themselves: only a line with a
///   condition, so nobody speaks up unprompted with nothing to say.
///
/// The most specific matching line wins; among equally specific ones the
/// seed picks.
pub fn pick(lines: &[LineDef], speaking: &Speaking, seed: u64) -> Option<usize> {
    if speaking.part == "player" {
        return None;
    }
    let allowed = |line: &LineDef| match speaking.last() {
        Some((true, _)) => true,
        Some((false, _)) => goes_on(line),
        None => speaking.opened || !line.when.is_empty(),
    };
    let matching: Vec<usize> = (0..lines.len()).filter(|&i| allowed(&lines[i]) && speaking.matches(&lines[i])).collect();
    let best = matching.iter().map(|&i| specific(&lines[i])).max()?;
    let tied: Vec<usize> = matching.into_iter().filter(|&i| specific(&lines[i]) == best).collect();
    Some(tied[crate::roll::salted_index(seed, speaking.memory.done.len() as u64, tied.len() as u64) as usize])
}

/// The player's choices now, as places of their lines in `lines`: every
/// line for the player that matches, one per name (the first), when it is
/// the player's turn: the other has spoken and is not answered, or the
/// player started the conversation and nothing is said yet (they speak
/// first; the other answers only when the player has nothing to say).
/// Empty when it is not their turn or nothing matches.
pub fn choices(lines: &[LineDef], speaking: &Speaking) -> Vec<usize> {
    let turn = match speaking.last() {
        Some((heard, _)) => heard,
        None => !speaking.opened,
    };
    if speaking.part != "player" || !turn {
        return Vec::new();
    }
    let mut names: Vec<&str> = Vec::new();
    (0..lines.len())
        .filter(|&i| {
            let line = &lines[i];
            let new = !names.contains(&line.name.as_str());
            let ok = new && speaking.matches(line);
            if ok {
                names.push(&line.name);
            }
            ok
        })
        .collect()
}

/// Among the player's `choices`, the ones shown (they have ways of being
/// said) and the silence, if any: a line with no ways and a `wait`, said
/// by itself when the player chooses nothing in time.
pub fn shown_and_silence(lines: &[LineDef], choices: &[usize]) -> (Vec<usize>, Option<usize>) {
    let shown = choices.iter().copied().filter(|&i| !lines[i].ways.is_empty()).collect();
    let silence = choices.iter().copied().find(|&i| lines[i].ways.is_empty() && lines[i].wait > 0.0);
    (shown, silence)
}

/// Word spreads (topside life.md "How a person feels about others"): the
/// teller tells the listener what was done to them by someone else, each
/// thing once: hit, killed, or said something that is felt (`heard`, by
/// the line's name, as `relationship::feeling` reads it), only what
/// happened to the teller themselves, never what they were told; and every
/// place they know that the listener does not, seen or told of, except
/// what they keep quiet. The number of things told.
pub fn share(
    (teller, teller_memory): (ActorId, &Memory),
    (listener, listener_memory): (ActorId, &mut Memory),
    heard: impl Fn(&str) -> f32,
    now: u64,
) -> usize {
    let mut told = 0;
    for thing in &teller_memory.known {
        if teller_memory.quiet.contains(&thing.key) || listener_memory.knows(thing.key) {
            continue;
        }
        listener_memory.told(thing, teller, now);
        told += 1;
    }
    for (when, did) in &teller_memory.done {
        let by = match did {
            Did::WasHit(Some(by), _) | Did::Died(Some(by), _) => *by,
            Did::Heard(by, line) if heard(&line.name) != 0.0 => *by,
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

    #[test]
    fn a_line_stays_as_long_as_it_takes_to_read_and_never_less_than_the_least() {
        assert_eq!(reading_secs("Busy."), READ_LEAST_SECS, "a word: the least");
        let long = "Out the door, then left. There's a sewer out there, and a tap inside it that runs.";
        assert!((reading_secs(long) - long.len() as f64 / 15.0).abs() < 1e-9, "a long line: by its length");
        assert!(reading_secs(long) > 5.0);
    }

    const DELL: ActorId = ActorId(3);
    const PLAYER: ActorId = ActorId(1);
    const TAP: u64 = 77;

    fn dell_knows_the_tap() -> Memory {
        let mut memory = Memory::default();
        memory.see(TAP, "tap", Vec3::new(150.0, 0.0, 1.0), 10);
        memory
    }

    fn line(name: &str, words: &str) -> Line {
        Line { name: name.to_string(), words: words.to_string() }
    }

    #[test]
    fn a_told_thing_is_known_with_who_told_it() {
        let (mut dell, mut player) = (dell_knows_the_tap(), Memory::default());
        let answer = talk(Said::Tell { key: TAP }, (DELL, &mut dell), (PLAYER, &mut player), (None, None), 20);
        assert_eq!(answer, Answer::Learned(TAP));
        let known = player.known.iter().find(|k| k.key == TAP).expect("the player knows the tap");
        assert_eq!((known.kind.as_str(), known.told_by), ("tap", Some(DELL)));
        assert_eq!(dell.done.last(), Some(&(20, Did::Talked(PLAYER, line("told", "told of the tap")))));
        assert_eq!(player.done.last(), Some(&(20, Did::Heard(DELL, line("told", "told of the tap")))));
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
    fn a_line_is_remembered_by_both_by_its_name_and_tells_what_it_names() {
        let (mut dell, mut player) = (dell_knows_the_tap(), Memory::default());
        let words = "Out the door, then left. The gas station has a tap.";
        let answer = talk(Said::Line { line: 0, key: TAP }, (DELL, &mut dell), (PLAYER, &mut player), (None, Some(("the way", words))), 20);
        assert_eq!(answer, Answer::Learned(TAP));
        assert_eq!(player.known.iter().find(|k| k.key == TAP).and_then(|k| k.told_by), Some(DELL));
        assert_eq!(player.done.last(), Some(&(20, Did::Heard(DELL, line("the way", words)))));
        let answer = talk(Said::Line { line: 1, key: 0 }, (PLAYER, &mut player), (DELL, &mut dell), (None, Some(("believes Dell", "Show me."))), 21);
        assert_eq!(answer, Answer::Said);
        assert_eq!(dell.done.last(), Some(&(21, Did::Heard(PLAYER, line("believes Dell", "Show me.")))));
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
        assert_eq!(mara.done.last(), Some(&(20, Did::Heard(PLAYER, line("threatened", "threatened them")))));
        let answer = talk(Said::Offer { slot: 0 }, (PLAYER, &mut player), (ActorId(8), &mut mara), (Some("water bottle"), None), 21);
        assert_eq!(answer, Answer::Offered("water bottle".to_string()));
        assert_eq!(player.done.last(), Some(&(21, Did::Talked(ActorId(8), line("offered", "offered water bottle")))));
    }

    fn threat(name: &str) -> f32 {
        if name == "threatens Mara" { -0.6 } else { 0.0 }
    }

    #[test]
    fn a_mate_is_told_what_was_done_and_feels_it_less() {
        const MARA: ActorId = ActorId(8);
        const MATE: ActorId = ActorId(9);
        let mut mara = Memory::default();
        mara.did(Did::Heard(PLAYER, line("threatens Mara", "Step away from it.")), 5);
        mara.did(Did::Heard(PLAYER, line("nothing to say", "Busy.")), 6);
        mara.did(Did::WasHit(Some(PLAYER), 30.0), 7);
        mara.did(Did::Slept, 8);
        let mut mate = Memory::default();
        // The threat and the hit; lines nobody feels are not worth telling.
        assert_eq!(share((MARA, &mara), (MATE, &mut mate), threat, 20), 2);
        assert_eq!(
            mate.done.first(),
            Some(&(20, Did::WasTold(MARA, 5, Box::new(Did::Heard(PLAYER, line("threatens Mara", "Step away from it."))))))
        );
        // Each thing once.
        assert_eq!(share((MARA, &mara), (MATE, &mut mate), threat, 21), 0);
        // Felt at half: (-0.6 - 0.6) / 2.
        let felt = crate::relationship::feeling(&mate, PLAYER, threat).unwrap();
        assert!((felt + 0.6).abs() < 1e-5, "{felt}");
        assert_eq!(crate::relationship::feelings(&mate, threat).len(), 1);
    }

    #[test]
    fn places_are_told_on_except_what_is_kept_quiet() {
        const ROXANNE: ActorId = ActorId(9);
        let mut dell = Memory::default();
        dell.see(TAP, "tap", Vec3::new(10.0, 0.0, 5.0), 1);
        dell.see(88, "well", Vec3::new(2.0, 0.0, 2.0), 1);
        dell.keep_quiet(TAP);
        let mut roxanne = Memory::default();
        assert_eq!(share((DELL, &dell), (ROXANNE, &mut roxanne), |_| 0.0, 5), 1);
        assert!(roxanne.knows(88) && !roxanne.knows(TAP), "the well told, the tap kept quiet");
        assert_eq!(roxanne.known[0].told_by, Some(DELL));
        // A place told of is told on, and nobody is told twice.
        let mut mate = Memory::default();
        assert_eq!(share((ROXANNE, &roxanne), (ActorId(10), &mut mate), |_| 0.0, 6), 1);
        assert_eq!(share((ROXANNE, &roxanne), (ActorId(10), &mut mate), |_| 0.0, 7), 0);
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

    // ---- lines as rules ----------------------------------------------

    fn rule(name: &str, part: &str, when: Vec<When>) -> LineDef {
        LineDef { name: name.to_string(), part: part.to_string(), when, ways: vec![name.to_string()], tells: String::new(), felt: 0.0, wait: 0.0, gives: String::new() }
    }

    /// The Tap's opening and plain talk, as rules.
    fn lines() -> Vec<LineDef> {
        let heard = |n: &str| When::Heard(n.to_string());
        vec![
            rule("nothing to say", "", vec![When::Opened]),
            rule("the opening", "Dell", vec![When::To("player".to_string()), When::Not(Box::new(When::Said("the opening".to_string())))]),
            rule("the way", "Dell", vec![When::JustSaid("the opening".to_string())]),
            rule("the way", "Dell", vec![heard("asks the way")]),
            rule("believes Dell", "player", vec![When::To("Dell".to_string()), heard("the way")]),
            rule("asks the way", "player", vec![When::To("Dell".to_string()), heard("the way")]),
            rule("Dell leads", "Dell", vec![heard("believes Dell")]),
            rule("asks for water", "player", vec![When::Needs("thirst".to_string(), 50.0), When::First]),
            rule("gives the well", "", vec![heard("asks for water"), When::Knows("well".to_string())]),
            rule("no water", "", vec![heard("asks for water")]),
        ]
    }

    struct Moment {
        part: &'static str,
        to_part: &'static str,
        to: ActorId,
        since: u64,
        opened: bool,
        needs: Vec<(String, f32)>,
    }

    impl Moment {
        fn of<'a>(&'a self, memory: &'a Memory) -> Speaking<'a> {
            Speaking {
                part: self.part,
                to_part: self.to_part,
                to: self.to,
                memory,
                since: self.since,
                opened: self.opened,
                reached: &[],
                near: &[],
                needs: &self.needs,
                knocking: false,
                warning: false,
                feels: 0.0,
            }
        }
    }

    fn said(lines: &[LineDef], at: Option<usize>) -> Option<&str> {
        at.map(|i| lines[i].name.as_str())
    }

    /// Who said what, written into both memories the one talk path writes.
    fn say(lines: &[LineDef], i: usize, from: (ActorId, &mut Memory), to: (ActorId, &mut Memory), now: u64) {
        let name = lines[i].name.clone();
        talk(Said::Line { line: lines[i].id(), key: 0 }, from, to, (None, Some((&name, &name))), now);
    }

    #[test]
    fn an_episode_conversation_runs_on_the_rules_alone() {
        let lines = lines();
        let (mut dell, mut player) = (Memory::default(), Memory::default());
        let dell_speaks = Moment { part: "Dell", to_part: "player", to: PLAYER, since: 5, opened: false, needs: Vec::new() };
        let player_speaks = Moment { part: "player", to_part: "Dell", to: DELL, since: 5, opened: false, needs: Vec::new() };
        // Unprompted, Dell opens; the plain "nothing to say" needs the
        // player to have started it, so it does not.
        let first = pick(&lines, &dell_speaks.of(&dell), 1).unwrap();
        assert_eq!(said(&lines, Some(first)), Some("the opening"));
        say(&lines, first, (DELL, &mut dell), (PLAYER, &mut player), 10);
        // Nothing for the player to answer yet: she goes on with the way.
        assert!(choices(&lines, &player_speaks.of(&player)).is_empty());
        let next = pick(&lines, &dell_speaks.of(&dell), 1).unwrap();
        assert_eq!(said(&lines, Some(next)), Some("the way"));
        say(&lines, next, (DELL, &mut dell), (PLAYER, &mut player), 11);
        // Finished, she waits; the player's choices are the two answers.
        assert_eq!(pick(&lines, &dell_speaks.of(&dell), 1), None);
        let open: Vec<&str> = choices(&lines, &player_speaks.of(&player)).into_iter().map(|i| lines[i].name.as_str()).collect();
        assert_eq!(open, ["believes Dell", "asks the way"]);
        // Asked the way, she says it again, and the choices come back.
        let ask = lines.iter().position(|l| l.name == "asks the way").unwrap();
        say(&lines, ask, (PLAYER, &mut player), (DELL, &mut dell), 12);
        let again = pick(&lines, &dell_speaks.of(&dell), 1).unwrap();
        assert_eq!(said(&lines, Some(again)), Some("the way"));
        say(&lines, again, (DELL, &mut dell), (PLAYER, &mut player), 13);
        assert_eq!(choices(&lines, &player_speaks.of(&player)).len(), 2);
        // Believed, she answers, and nothing is left to say: it ends.
        let go = lines.iter().position(|l| l.name == "believes Dell").unwrap();
        say(&lines, go, (PLAYER, &mut player), (DELL, &mut dell), 14);
        let reply = pick(&lines, &dell_speaks.of(&dell), 1).unwrap();
        assert_eq!(said(&lines, Some(reply)), Some("Dell leads"));
        say(&lines, reply, (DELL, &mut dell), (PLAYER, &mut player), 15);
        assert!(choices(&lines, &player_speaks.of(&player)).is_empty());
        assert_eq!(pick(&lines, &dell_speaks.of(&dell), 1), None);
        // Later, the player's E: she has opened already, so plain talk.
        let later = Moment { part: "Dell", to_part: "player", to: PLAYER, since: 50, opened: true, needs: Vec::new() };
        assert_eq!(said(&lines, pick(&lines, &later.of(&dell), 1)), Some("nothing to say"));
    }

    #[test]
    fn plain_talk_is_the_same_rules() {
        let lines = lines();
        let stranger_id = ActorId(9);
        let (mut stranger, mut player) = (Memory::default(), Memory::default());
        // The player's E on a stranger: nothing to say; nobody speaks up
        // unprompted with it.
        let unprompted = Moment { part: "", to_part: "player", to: PLAYER, since: 5, opened: false, needs: Vec::new() };
        assert_eq!(pick(&lines, &unprompted.of(&stranger), 1), None);
        // Not thirsty, the player who started it has nothing to say first;
        // the stranger answers with nothing to say, and that is the end.
        let content = Moment { part: "player", to_part: "", to: stranger_id, since: 5, opened: false, needs: vec![("thirst".to_string(), 90.0)] };
        assert!(choices(&lines, &content.of(&player)).is_empty());
        let stranger_speaks = Moment { part: "", to_part: "player", to: PLAYER, since: 5, opened: true, needs: Vec::new() };
        let first = pick(&lines, &stranger_speaks.of(&stranger), 1).unwrap();
        assert_eq!(said(&lines, Some(first)), Some("nothing to say"));
        say(&lines, first, (stranger_id, &mut stranger), (PLAYER, &mut player), 10);
        assert!(choices(&lines, &content.of(&player)).is_empty());
        // Thirsty, in a new conversation, the player's first word can be to
        // ask for water.
        let thirsty = Moment { part: "player", to_part: "", to: stranger_id, since: 11, opened: false, needs: vec![("thirst".to_string(), 20.0)] };
        let ask = choices(&lines, &thirsty.of(&player));
        assert_eq!(ask.iter().map(|&i| lines[i].name.as_str()).collect::<Vec<_>>(), ["asks for water"]);
        say(&lines, ask[0], (PLAYER, &mut player), (stranger_id, &mut stranger), 11);
        let stranger_speaks = Moment { part: "", to_part: "player", to: PLAYER, since: 11, opened: true, needs: Vec::new() };
        // Knowing no well: no water. Knowing one, they give it; a well kept
        // quiet is not given.
        assert_eq!(said(&lines, pick(&lines, &stranger_speaks.of(&stranger), 1)), Some("no water"));
        stranger.see(88, "well", Vec3::new(3.0, 0.0, 3.0), 1);
        assert_eq!(said(&lines, pick(&lines, &stranger_speaks.of(&stranger), 1)), Some("gives the well"));
        stranger.keep_quiet(88);
        assert_eq!(said(&lines, pick(&lines, &stranger_speaks.of(&stranger), 1)), Some("no water"));
    }

    #[test]
    fn a_moment_left_open_is_open_the_next_time_and_the_player_speaks_first() {
        let not_said = |n: &str| When::Not(Box::new(When::Said(n.to_string())));
        let mut lines = lines();
        lines.push(rule("believes Dell", "player", vec![When::To("Dell".to_string()), When::HasHeard("the way".to_string()), not_said("believes Dell")]));
        let (mut dell, mut player) = (Memory::default(), Memory::default());
        // Dell's opening and the way, then the player walks off unanswered.
        for name in ["the opening", "the way"] {
            let i = lines.iter().position(|l| l.name == name).unwrap();
            say(&lines, i, (DELL, &mut dell), (PLAYER, &mut player), 10);
        }
        // Later the player presses E on her: they speak first, the moment
        // still open; she does not say "nothing to say" over it.
        let player_opens = Moment { part: "player", to_part: "Dell", to: DELL, since: 50, opened: false, needs: Vec::new() };
        let open: Vec<&str> = choices(&lines, &player_opens.of(&player)).into_iter().map(|i| lines[i].name.as_str()).collect();
        assert_eq!(open, ["believes Dell"]);
        // Answered, the moment is closed for good.
        let go = lines.iter().rposition(|l| l.name == "believes Dell").unwrap();
        say(&lines, go, (PLAYER, &mut player), (DELL, &mut dell), 51);
        let later = Moment { part: "player", to_part: "Dell", to: DELL, since: 90, opened: false, needs: Vec::new() };
        assert!(choices(&lines, &later.of(&player)).is_empty());
    }

    #[test]
    fn silence_is_a_choice_never_shown_and_said_when_time_runs_out() {
        let mut lines = lines();
        let mut quiet = rule("says nothing", "player", vec![When::To("Dell".to_string()), When::Heard("the way".to_string())]);
        quiet.ways.clear();
        quiet.wait = 10.0;
        lines.push(quiet);
        let (mut dell, mut player) = (Memory::default(), Memory::default());
        for name in ["the opening", "the way"] {
            let i = lines.iter().position(|l| l.name == name).unwrap();
            say(&lines, i, (DELL, &mut dell), (PLAYER, &mut player), 10);
        }
        let player_speaks = Moment { part: "player", to_part: "Dell", to: DELL, since: 5, opened: false, needs: Vec::new() };
        let open = choices(&lines, &player_speaks.of(&player));
        let (shown, silence) = shown_and_silence(&lines, &open);
        let names = |ids: &[usize]| ids.iter().map(|&i| lines[i].name.clone()).collect::<Vec<_>>();
        assert_eq!(names(&shown), ["believes Dell", "asks the way"]);
        assert_eq!(silence.map(|i| lines[i].name.as_str()), Some("says nothing"));
    }

    #[test]
    fn what_was_said_before_this_conversation_is_another_conversation() {
        let lines = lines();
        let stranger_id = ActorId(9);
        let (mut stranger, mut player) = (Memory::default(), Memory::default());
        let ask = lines.iter().position(|l| l.name == "asks for water").unwrap();
        say(&lines, ask, (PLAYER, &mut player), (stranger_id, &mut stranger), 3);
        // An unanswered ask from an earlier conversation is not answered
        // in this one.
        let now = Moment { part: "", to_part: "player", to: PLAYER, since: 10, opened: true, needs: Vec::new() };
        assert_eq!(said(&lines, pick(&lines, &now.of(&stranger), 1)), Some("nothing to say"));
    }
}
