//! `HorseyState` snapshot returned in every HTTP `OpResponse`.
//!
//! Following ueforge / unityforge's pattern: every op response
//! carries a small per-game state snapshot so the client can see
//! the current world without an extra round-trip. Keep this
//! cheap to capture. It runs once per HTTP request.

use serde::Serialize;

use crate::gamestate;

#[derive(Serialize)]
pub struct HorseyState {
    /// True when the GameState global is initialized (world is loaded).
    pub world_loaded: bool,
    pub money: Option<u32>,
    pub year: Option<u32>,
    pub sleeps: Option<u32>,
    pub races: u32,
    pub horse_count: usize,
    pub no_tire: bool,
    pub debug_mode: bool,
}

impl HorseyState {
    /// Read the live state from the game. Cheap; ~10 atomic reads.
    pub fn capture() -> Self {
        modforge::log!("capture: enter; reading gamestate ptr");
        let gs = gamestate::ptr();
        modforge::log!("capture: gamestate ptr = 0x{gs:x}");
        modforge::log!("capture: reading money");
        let money = gamestate::money();
        modforge::log!("capture: money read OK");
        modforge::log!("capture: reading year");
        let year = gamestate::year();
        modforge::log!("capture: year read OK");
        modforge::log!("capture: reading sleeps");
        let sleeps = gamestate::sleeps();
        modforge::log!("capture: sleeps read OK");
        modforge::log!("capture: reading races");
        let races = gamestate::races();
        modforge::log!("capture: races read OK");
        modforge::log!("capture: reading horse_count");
        let horse_count = gamestate::horse_count();
        modforge::log!("capture: horse_count read OK ({horse_count})");
        modforge::log!("capture: reading no_tire");
        let no_tire = gamestate::no_tire();
        modforge::log!("capture: no_tire read OK ({no_tire})");
        modforge::log!("capture: reading debug_mode");
        let debug_mode = gamestate::debug_mode();
        modforge::log!("capture: debug_mode read OK ({debug_mode}); done");
        Self {
            world_loaded: gs != 0,
            money,
            year,
            sleeps,
            races,
            horse_count,
            no_tire,
            debug_mode,
        }
    }

    /// Used in parse-error paths where we couldn't even start
    /// dispatching the op. Returns a state with `world_loaded=false`
    /// and everything zero/none.
    pub fn placeholder() -> Self {
        Self {
            world_loaded: false,
            money: None,
            year: None,
            sleeps: None,
            races: 0,
            horse_count: 0,
            no_tire: false,
            debug_mode: false,
        }
    }
}
