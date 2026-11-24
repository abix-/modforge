//! The show the aliens watch (topside-show; topside todo Show 1 to 8):
//! a channel running day and night, its viewers, their chat and vote,
//! each person's popularity, the recaps edited to tell a better story,
//! and the sponsors. Engine-free: the game feeds it what its people do
//! (each `Did` from their memory) and the alien director's ratings, and
//! draws what it says. The content (`ShowDef`) is the game's.
//!
//! Prior art: Twitch's viewer count, chat and polls; reality TV's edit
//! (UnREAL); The Hunger Games' sponsors; Big Brother's audience votes;
//! The Running Man.

use serde::{Deserialize, Serialize};

use crate::actor::ActorId;
use crate::memory::Did;
use crate::roll::salted_index;

/// What is on the channel now (topside-show "The television": "clips and
/// little commercials and little, next time on topside and last time").
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
pub enum Segment {
    /// The star live, over their shoulder.
    Live,
    /// A clip of something done.
    Clip,
    /// An ad for a sponsor's thing.
    Commercial,
    /// "Last time on" the show: the recap.
    LastTime,
    /// "Next time on" the show: what is coming.
    NextTime,
}

/// How the viewers take one kind of deed (`Did::kind`).
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Reaction {
    /// The deed's kind ("killed", "hit", "ate"...).
    pub kind: String,
    /// What it does to the doer's popularity, -1 to 1.
    pub popularity: f32,
    /// How much it stirs the viewers, added to the ratings and fading.
    pub stir: f32,
    /// What the chat says, one picked.
    pub chat: Vec<String>,
}

/// A game's show, as its content holds it.
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct ShowDef {
    /// Its name ("topside").
    pub name: String,
    /// How many watch at full ratings.
    pub audience: u32,
    /// The channel's running order, each segment and its seconds, round
    /// and round.
    pub cycle: Vec<(Segment, f32)>,
    /// How each kind of deed is taken.
    pub reactions: Vec<Reaction>,
    /// The edit: plain words and what the recap says instead.
    pub edits: Vec<(String, String)>,
    /// The episode titles, one picked for each recap.
    pub titles: Vec<String>,
    /// The things sponsors sell (the game's item names).
    pub sponsors: Vec<String>,
    /// What the chat says when it sees the star watching.
    pub watched: Vec<String>,
    /// How much of the stir is left after a second.
    pub stir_fades: f32,
    /// How many clips and chat lines are kept.
    pub keeps: usize,
}

/// One clip: what someone did, and when.
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
pub struct Clip {
    pub tick: u64,
    pub who: ActorId,
    pub words: String,
}

/// The show's state. Saved by the game.
#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Show {
    pub clips: Vec<Clip>,
    pub chat: Vec<String>,
    /// Each person's popularity, -1 (hated) to 1 (a favourite).
    pub popularity: Vec<(ActorId, f32)>,
    /// How stirred the viewers are now, over the ratings.
    pub stir: f32,
    /// The last thing a commercial sold, until it turns up in loot.
    pub sponsored: Option<String>,
    /// The other channels paid for, by their show's name.
    pub tuned: Vec<String>,
}

/// The segment on at `secs` into the channel's day.
pub fn segment(def: &ShowDef, secs: f32) -> Segment {
    let round: f32 = def.cycle.iter().map(|(_, s)| *s).sum();
    if round <= 0.0 {
        return Segment::Live;
    }
    let mut at = secs.rem_euclid(round);
    for (segment, len) in &def.cycle {
        if at < *len {
            return *segment;
        }
        at -= len;
    }
    Segment::Live
}

impl Show {
    /// `who` did `did` at `tick`: the viewers react, the chat says so,
    /// and it is kept as a clip.
    pub fn saw(&mut self, def: &ShowDef, who: ActorId, did: &Did, tick: u64) {
        let Some(reaction) = def.reactions.iter().find(|r| r.kind == did.kind()) else {
            return;
        };
        let liked = self.popularity_of(who) + reaction.popularity;
        self.set_popularity(who, liked);
        self.stir += reaction.stir;
        if !reaction.chat.is_empty() {
            let line = &reaction.chat[salted_index(tick, who.0, reaction.chat.len() as u64) as usize];
            self.say(def, line.clone());
        }
        self.clips.push(Clip { tick, who, words: did.words() });
        while self.clips.len() > def.keeps {
            self.clips.remove(0);
        }
    }

    /// The chat says `line`.
    pub fn say(&mut self, def: &ShowDef, line: String) {
        self.chat.push(line);
        while self.chat.len() > def.keeps {
            self.chat.remove(0);
        }
    }

    /// The chat sees the star watching them (topside-show "The viewers":
    /// "they would see that you're watching them").
    pub fn seen_watching(&mut self, def: &ShowDef, seed: u64) {
        if !def.watched.is_empty() {
            let line = def.watched[salted_index(seed, 0x5EE, def.watched.len() as u64) as usize].clone();
            self.say(def, line);
        }
    }

    /// A second passes: the stir fades.
    pub fn fade(&mut self, def: &ShowDef) {
        self.stir *= def.stir_fades;
    }

    /// How many watch now, from the alien director's ratings (0 to 1)
    /// and the stir.
    pub fn viewers(&self, def: &ShowDef, ratings: f32) -> u32 {
        (def.audience as f32 * (ratings + self.stir).clamp(0.0, 1.0)) as u32
    }

    /// The stir, as the director takes it into its ratings.
    pub fn ratings(&self, ratings: f32) -> f32 {
        (ratings + self.stir).clamp(0.0, 1.0)
    }

    pub fn popularity_of(&self, who: ActorId) -> f32 {
        self.popularity.iter().find(|(w, _)| *w == who).map_or(0.0, |(_, p)| *p)
    }

    pub fn set_popularity(&mut self, who: ActorId, to: f32) {
        let to = to.clamp(-1.0, 1.0);
        match self.popularity.iter_mut().find(|(w, _)| *w == who) {
            Some((_, p)) => *p = to,
            None => self.popularity.push((who, to)),
        }
    }

    /// A vote cast on another bunker's show against its people (topside-
    /// show "Other channels": "spy on them and even vote"): each of them
    /// less liked by `by`, so their storms come harder (Claude's).
    pub fn vote_against(&mut self, people: &[ActorId], by: f32) {
        for who in people {
            self.set_popularity(*who, self.popularity_of(*who) - by);
        }
    }

    /// "Last time on" the show: a title and the clips, edited to tell a
    /// better story than what happened (topside-show "What the show
    /// does" 1).
    pub fn recap(&self, def: &ShowDef, seed: u64) -> (String, Vec<String>) {
        let title = if def.titles.is_empty() { def.name.clone() } else { def.titles[salted_index(seed, 0x7171E, def.titles.len() as u64) as usize].clone() };
        let lines = self.clips.iter().map(|c| edit(def, &c.words)).collect();
        (title, lines)
    }

    /// A commercial airs: a sponsor's thing is sold, and is owed to the
    /// loot (topside-show "What the show does" 2).
    pub fn commercial(&mut self, def: &ShowDef, seed: u64) -> Option<String> {
        if def.sponsors.is_empty() {
            return None;
        }
        let item = def.sponsors[salted_index(seed, 0xAD, def.sponsors.len() as u64) as usize].clone();
        self.sponsored = Some(item.clone());
        Some(item)
    }
}

/// The edit: every plain phrase the recap knows a stronger word for.
pub fn edit(def: &ShowDef, words: &str) -> String {
    def.edits.iter().fold(words.to_string(), |w, (plain, cut)| w.replace(plain.as_str(), cut))
}

/// "Next time on" the show: what is coming, if anything is foretold.
pub fn next_time(def: &ShowDef, coming: Option<&str>) -> String {
    match coming {
        Some(what) => format!("Next time on {}: {what}", def.name),
        None => format!("Next time on {}...", def.name),
    }
}

/// How hard a storm is on someone of `popularity`: the favourites get a
/// kinder one, the hated a harder (topside-show "Popularity and playing
/// to the camera"). A factor on the storm's harm, 0.5 to 1.5.
pub fn storm_factor(popularity: f32) -> f32 {
    1.0 - 0.5 * popularity.clamp(-1.0, 1.0)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn def() -> ShowDef {
        ShowDef {
            name: "topside".into(),
            audience: 1000,
            cycle: vec![(Segment::Live, 10.0), (Segment::Commercial, 2.0)],
            reactions: vec![Reaction { kind: "killed".into(), popularity: -0.3, stir: 0.4, chat: vec!["no way".into()] }],
            edits: vec![("killed".into(), "murdered".into())],
            titles: vec!["Blood in the Water".into()],
            sponsors: vec!["canned food".into()],
            watched: vec!["they see us".into()],
            stir_fades: 0.5,
            keeps: 3,
        }
    }

    #[test]
    fn the_cycle_goes_round() {
        let d = def();
        assert_eq!(segment(&d, 5.0), Segment::Live);
        assert_eq!(segment(&d, 11.0), Segment::Commercial);
        assert_eq!(segment(&d, 13.0), Segment::Live);
    }

    #[test]
    fn a_killing_stirs_them_and_the_recap_lies() {
        let d = def();
        let mut show = Show::default();
        show.saw(&d, ActorId(1), &Did::Killed(ActorId(2)), 7);
        assert!(show.viewers(&d, 0.2) > d.audience / 5);
        assert!(show.popularity_of(ActorId(1)) < 0.0);
        assert_eq!(show.chat, vec!["no way".to_string()]);
        let (_, lines) = show.recap(&d, 1);
        assert!(lines[0].contains("murdered"));
        show.fade(&d);
        assert!(show.stir < 0.4);
    }

    #[test]
    fn the_hated_get_harder_storms() {
        assert!(storm_factor(1.0) < 1.0);
        assert!(storm_factor(-1.0) > 1.0);
    }
}
