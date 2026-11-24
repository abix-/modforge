//! What is on the air (topside-town "Everything works": "phones, radios,
//! TVs, mailboxes and the post office"; Project Zomboid's radio and TV
//! channels, each playing its programme at its hours): a channel is a
//! list of programmes, each from one hour of the day to another; what a
//! radio, a TV or a phone says when turned on is the programme on at
//! that hour, or nothing. Engine-free; the game holds the channels.

use serde::{Deserialize, Serialize};

/// One programme: from `from` to `to`, hours of the day (0 to 24; `to`
/// below `from` runs past midnight), and its words.
#[derive(Clone, Copy, Debug, PartialEq, Serialize, Deserialize)]
pub struct Programme {
    pub from: f32,
    pub to: f32,
    pub words: &'static str,
}

/// The programme on `channel` at `hour`, if any.
pub fn on_air(channel: &[Programme], hour: f32) -> Option<&'static str> {
    let hour = hour.rem_euclid(24.0);
    channel
        .iter()
        .find(|p| if p.from <= p.to { (p.from..p.to).contains(&hour) } else { hour >= p.from || hour < p.to })
        .map(|p| p.words)
}

#[cfg(test)]
mod tests {
    use super::*;

    const CHANNEL: [Programme; 2] = [Programme { from: 6.0, to: 12.0, words: "the news" }, Programme { from: 22.0, to: 2.0, words: "static" }];

    #[test]
    fn the_programme_on_at_the_hour_plays() {
        assert_eq!(on_air(&CHANNEL, 7.0), Some("the news"));
        assert_eq!(on_air(&CHANNEL, 23.0), Some("static"));
        assert_eq!(on_air(&CHANNEL, 1.0), Some("static"));
        assert_eq!(on_air(&CHANNEL, 15.0), None);
    }
}
