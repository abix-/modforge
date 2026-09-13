//! Auto-hit the punching bag: see prompt, wait, hit bag.
//!
//! The one open question is how long to wait after the prompt.
//! Rather than deriving the wait from code reading, the bot
//! SWEEPS it: each prompt uses a different wait from a fixed
//! ladder, presses once, and logs the game's own grade
//! (`lastHitResult`) next to the wait that produced it. The
//! ladder covers 0 to 0.55 seconds in 0.05 steps. Whatever wait
//! the game grades Perfect is the right one, by measurement.
//!
//! Mechanics: a prefix on `PunchingBagStation.ActivateNextPrompt`
//! (the prompt appearing) starts a per-frame job on the
//! main-thread queue; once the prompt's age reaches the chosen
//! wait it calls the game's own `ResolvePunch` with
//! `expectsLeftHand`. The prompt's age comes from
//! `reactionWindowTimer` (it starts at the tier's reaction
//! window and counts down). On any failure the job logs and
//! stops, which is a vanilla missed prompt.

use std::ffi::c_void;
use std::os::raw::c_char;
use std::sync::atomic::{AtomicUsize, Ordering};

use unityforge::hook::{HOOK_REGISTRY, patch_prefix_instance_args};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{self, LogLevel, MonoObject, owned_object};

/// Seconds to wait after the prompt before pressing, tried in
/// order, one per prompt, wrapping around. Fine sweep of the
/// boundary where Good turns into OffTimingHit on tier 2.
const WAIT_LADDER: [f64; 11] = [
    0.35, 0.36, 0.37, 0.38, 0.39, 0.40, 0.41, 0.42, 0.43, 0.44, 0.45,
];

static WAIT_INDEX: AtomicUsize = AtomicUsize::new(0);

/// Frames to keep watching one prompt before giving up. Pure
/// safety net; the prompt clearing ends the job first.
const MAX_FRAMES: u32 = 300;

pub fn install() {
    match patch_prefix_instance_args(
        "PunchingBagStation",
        "ActivateNextPrompt",
        activate_next_prompt_prefix,
    ) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            mono::log(
                LogLevel::Info,
                "bossgangsters-mod: punching bag auto-hit armed (wait-ladder sweep)",
            );
        }
        Err(e) => mono::log(
            LogLevel::Error,
            &format!("bossgangsters-mod: punching bag patch failed: {e}"),
        ),
    }
}

extern "C" fn activate_next_prompt_prefix(instance: *const c_void, _args: *const c_char) -> i32 {
    if !instance.is_null() {
        let wait = WAIT_LADDER[WAIT_INDEX.fetch_add(1, Ordering::Relaxed) % WAIT_LADDER.len()];
        // Owns the handle; carried by the per-frame job, released
        // on drop when the job ends.
        let station = owned_object(instance as i32);
        watch_prompt(Watch {
            station,
            frames_left: MAX_FRAMES,
            wait,
            started: std::time::Instant::now(),
        });
    }
    0 // always run the original: the game picks the hand first
}

struct Watch {
    station: MonoObject,
    frames_left: u32,
    /// Seconds after the prompt to press.
    wait: f64,
    /// When the prompt appeared (the prefix fired).
    started: std::time::Instant,
}

enum Step {
    /// Pressed; watch for the registered result under this
    /// header, starting from this feedbackVersion.
    Punched { header: String, version_before: i64 },
    Wait,
    SessionOver,
}

fn watch_prompt(mut w: Watch) {
    MAIN_QUEUE.push(move || match check_and_punch(&mut w) {
        Ok(Step::Punched { header, version_before }) => {
            // Rhythm double-tap: the same press again a beat
            // later, while the first punch is still mid-swing.
            second_press(
                w.station,
                header,
                version_before,
                std::time::Instant::now(),
                180,
            );
        }
        Ok(Step::SessionOver) => {}
        Ok(Step::Wait) if w.frames_left > 0 => {
            w.frames_left -= 1;
            watch_prompt(w);
        }
        Ok(Step::Wait) => mono::log(
            LogLevel::Warn,
            "bossgangsters-mod: punching bag prompt watched 300 frames without pressing; gave up",
        ),
        Err(e) => mono::log(
            LogLevel::Warn,
            &format!("bossgangsters-mod: auto punch stopped: {e}"),
        ),
    });
}

/// Seconds between the two presses of the rhythm double-tap.
/// The mid-swing branch accepts a second press between 12% and
/// 32% of the punch animation; 0.18 s sits in the middle.
const SECOND_PRESS_GAP: f64 = 0.18;

/// The rhythm's second press: same hand, one beat after the
/// first, while the punch is still mid-swing. Then watch for the
/// registered result.
fn second_press(
    station: MonoObject,
    header: String,
    version_before: i64,
    first_press: std::time::Instant,
    frames_left: u32,
) {
    MAIN_QUEUE.push(move || {
        if first_press.elapsed().as_secs_f64() < SECOND_PRESS_GAP {
            if frames_left > 0 {
                second_press(station, header, version_before, first_press, frames_left - 1);
            }
            return;
        }
        let left = station
            .read_field("expectsLeftHand")
            .ok()
            .and_then(|v| v.as_bool())
            .unwrap_or(true);
        if let Err(e) = station.invoke("ResolvePunch", &serde_json::json!([left, 0.05])) {
            mono::log(
                LogLevel::Warn,
                &format!("bossgangsters-mod: second press failed: {e}"),
            );
        }
        watch_result(station, format!("{header} x2"), version_before, 180);
    });
}

/// After a press, wait for the game to REGISTER the result
/// (feedbackVersion increments at the punch's impact), then log
/// lastHitResult: the same result the screen shows.
fn watch_result(station: MonoObject, header: String, version_before: i64, frames_left: u32) {
    MAIN_QUEUE.push(move || {
        let version = station
            .read_field("feedbackVersion")
            .ok()
            .and_then(|v| v.as_i64())
            .unwrap_or(-1);
        if version == version_before {
            if frames_left > 0 {
                watch_result(station, header, version_before, frames_left - 1);
            } else {
                mono::log(
                    LogLevel::Info,
                    &format!("{header} -> (no result registered within 3s)"),
                );
            }
            return;
        }
        let grade_json = station.read_field("lastHitResult").unwrap_or_default();
        let grade = grade_json
            .as_str()
            .map(str::to_string)
            .unwrap_or_else(|| grade_json.to_string());
        mono::log(LogLevel::Info, &format!("{header} -> {grade}"));
    });
}

fn read_f64(station: &MonoObject, field: &str) -> Result<f64, String> {
    station
        .read_field(field)?
        .as_f64()
        .ok_or_else(|| format!("{field} not a number"))
}

fn check_and_punch(w: &mut Watch) -> Result<Step, String> {
    let station = &w.station;
    // Stop only when the gym session itself ended; the press
    // happens at the scheduled time even after the prompt is
    // over, so late and between-prompt timings get graded too.
    if station.read_field("activeFighter")?.is_null() {
        return Ok(Step::SessionOver);
    }
    if w.started.elapsed().as_secs_f64() < w.wait {
        return Ok(Step::Wait); // still waiting our chosen delay
    }

    let prompt_active = station
        .read_field("promptActive")?
        .as_bool()
        .ok_or("promptActive not a bool")?;
    let timer = read_f64(station, "reactionWindowTimer")?;
    let ratio = read_f64(station, "signedBagAngle")? / read_f64(station, "maximumAwayAngle")?;
    let tier = station
        .read_field("difficultyTier")?
        .as_i64()
        .unwrap_or(1);
    let left = station
        .read_field("expectsLeftHand")?
        .as_bool()
        .ok_or("expectsLeftHand not a bool")?;
    let version_before = station
        .read_field("feedbackVersion")?
        .as_i64()
        .unwrap_or(-1);
    station.invoke("ResolvePunch", &serde_json::json!([left, 0.05]))?;

    // The REGISTERED result (lastHitResult, what the screen
    // shows) lands at the punch's impact, ~1/3 s after the
    // press; feedbackVersion increments then. Watch for it.
    let header = format!(
        "bossgangsters-mod: wait {:.2}s pressed {} tier {tier} prompt={} ratio {ratio:.3} timer {timer:.3}",
        w.wait,
        if left { "left (A)" } else { "right (D)" },
        if prompt_active { "on" } else { "off" },
    );
    Ok(Step::Punched { header, version_before })
}
