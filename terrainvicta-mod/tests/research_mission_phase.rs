//! Research: what "Awaiting Next Mission Phase" on a councilor means.
//!
//! The game picks that text (UI.CouncilorView.NoMissionPhase) in
//! TICouncilorState.GetCurrentMissionString when the councilor has no
//! active mission, is not detained, and TIMissionPhaseState.InMissionPhase()
//! is false. This reads the mission phase state from the live game.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test research_mission_phase -- --nocapture
//! ```

mod common;
use common::api_or_skip;
use serde_json::json;

const PHASE: &str = "PavonisInteractive.TerraInvicta.TIMissionPhaseState";

#[test]
fn mission_phase_state() {
    let Some(api) = api_or_skip() else { return };
    for method in [
        "InMissionPhase",
        "get_nextMissionPhase",
        "get_timeToNextMissionPhase_d",
        "get_phasesPerMonth",
    ] {
        let r = api.op("invoke_static", json!({"class": PHASE, "method": method}));
        assert!(r.ok, "{method} failed: {:?}", r.error);
        println!("{method}: {}", r.result);
    }
}
