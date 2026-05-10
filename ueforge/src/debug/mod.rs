//! Generic debug-endpoint scaffolding for UE4SS Rust mods.
//!
//! Every mod in this workspace exposes a `POST /debug` HTTP endpoint
//! routing op-dispatch JSON. The framework supplies all the
//! universal pieces -- op routing for the standard catalog, snapshot
//! view types, op-list metadata. Game crates supply the game-
//! specific simulate_* ops + the snapshot data that requires UE
//! class layout knowledge.
//!
//! ```ignore
//! use ueforge::debug::{StandardOps, dispatch_standard};
//!
//! fn handle(body: &str) -> OpResponse {
//!     let (op, args) = parse_request(body)?;
//!     // 1. Try the standard catalog (snapshot/skill_*/reload_slot/
//!     //    set_skill_points/call/read_bytes/write_bytes/walk_class/
//!     //    class_outer_samples/sample_thread_modules).
//!     if let Some(r) = dispatch_standard(&op, &args, &TRACKER,
//!         &DISABLED, &PE_QUEUE, resolve_instance) {
//!         return to_response(&op, r);
//!     }
//!     // 2. Game-specific ops.
//!     match op.as_str() {
//!         "simulate_add_health" => to_response(&op, op_add_health(&args)),
//!         _ => error_response(&op, "unknown op"),
//!     }
//! }
//! ```

use std::time::Duration;

use serde::Serialize;
use serde_json::Value as Json;

use crate::args;
use crate::pe_queue::DrainSite;
use crate::ring::EventRing;
use crate::rpg::{DisabledSkills, RpgApplier, SkillDef, SkillsState, Tracker};

/// Universal player-state view for the debug snapshot. Serde-
/// friendly mapping of `SkillsState` fields. `skill_levels` is a
/// JSON object so per-skill-id lookups in tests don't require a
/// linear scan.
#[derive(Serialize)]
pub struct PlayerStateView {
    pub xp: u64,
    pub level: u32,
    pub skill_points: u32,
    pub skill_levels: serde_json::Map<String, serde_json::Value>,
}

impl PlayerStateView {
    /// Build a view from a `SkillsState`. Allocates one
    /// `serde_json::Map` for the skill-levels field.
    pub fn from_state(s: &SkillsState) -> Self {
        let mut skill_levels = serde_json::Map::new();
        for (id, lv) in &s.skill_levels {
            skill_levels.insert(id.clone(), serde_json::Value::Number((*lv).into()));
        }
        PlayerStateView {
            xp: s.xp,
            level: s.level,
            skill_points: s.skill_points,
            skill_levels,
        }
    }
}

/// One row in a serializable catalog view. `effect_kind` is a
/// game-supplied identifier (typically the SkillEffect variant
/// name) so test assertions key off catalog rows without coupling
/// to the live enum layout.
#[derive(Serialize)]
pub struct CatalogEntry {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_level: u32,
    pub effect_kind: &'static str,
}

/// Map a game's `[SkillDef<E>]` slice into a serializable
/// `Vec<CatalogEntry>`. The `kind_fn` callback produces the
/// effect-kind string per row (game-specific match on the enum).
///
/// ```ignore
/// let view = ueforge::debug::catalog_view(skills::CATALOG.entries(), |e| match e {
///     SkillEffect::Standard(_) => "Standard",
///     SkillEffect::BackpackSlots { .. } => "BackpackSlots",
///     // ...
/// });
/// ```
pub fn catalog_view<E>(
    catalog: &'static [SkillDef<E>],
    kind_fn: impl Fn(&E) -> &'static str,
) -> Vec<CatalogEntry> {
    catalog
        .iter()
        .map(|s| CatalogEntry {
            id: s.id,
            display_name: s.display_name,
            max_level: s.max_level,
            effect_kind: kind_fn(&s.effect),
        })
        .collect()
}

/// The list of op names this framework's standard dispatcher
/// handles. Game crates extend with their own simulate_* ops and
/// concatenate the lists for the "supported ops" error message.
pub const STANDARD_OPS: &[&str] = &[
    "snapshot",
    "skill_toggle",
    "skill_spend",
    "skill_refund",
    "reload_slot",
    "set_skill_points",
    "call",
    "read_bytes",
    "write_bytes",
    "walk_class",
    "class_outer_samples",
    "sample_thread_modules",
];

/// Recent damage / multicast PE event captured by a damage hook.
/// Universal shape: every UE5 RPG mod that observes damage wants
/// the same fields. Game crates push entries from their kill_hook
/// trampoline; the snapshot endpoint reads + serializes the ring.
#[derive(Clone, Serialize)]
pub struct DamageEvent {
    /// Wall-clock seconds since UNIX epoch -- sequences events in
    /// the same clock space as log lines.
    pub at_secs: u64,
    pub function: String,
    pub damage: f32,
    pub damage_flags: i32,
    pub type_flags: u32,
    pub current_damage_before: Option<f32>,
    pub current_damage_after: Option<f32>,
}

/// Bounded drop-oldest ring of `DamageEvent`s. Wraps `EventRing`
/// with the standard observer accessors so game crates declare
/// `static RING: DamageRing = DamageRing::new(64);` and call
/// `RING.record(ev)` / `RING.snapshot()` directly.
pub struct DamageRing {
    inner: EventRing<DamageEvent>,
}

impl DamageRing {
    pub const fn new(capacity: usize) -> Self {
        Self {
            inner: EventRing::new(capacity),
        }
    }
    pub fn record(&self, ev: DamageEvent) {
        self.inner.record(ev);
    }
    pub fn snapshot(&self) -> Vec<DamageEvent> {
        self.inner.snapshot()
    }
    pub fn pushes(&self) -> u64 {
        self.inner.pushes()
    }
    pub fn peak(&self) -> usize {
        self.inner.peak()
    }
}

/// System-metric block that every mod's snapshot includes:
/// counters + per-process memory / CPU / threads + GObjects
/// population + per-region address-space breakdown.
///
/// Build with [`ProcessSnapshot::collect`]; embed in the game's
/// own snapshot struct via `#[serde(flatten)]` or as a named
/// field.
#[derive(Serialize)]
pub struct ProcessSnapshot {
    /// Hot-path counters JSON. Game crate supplies via
    /// `crate::counters::snapshot_json()` (or whatever the mod's
    /// counters module exposes).
    pub counters: Json,
    pub process_memory: Json,
    pub process_cpu: Json,
    pub process_threads: Json,
    pub game_population: Json,
    pub process_regions: Json,
}

impl ProcessSnapshot {
    /// Snapshot every system-metric field. `counters` is supplied
    /// by the caller (the counters module is owned by the game
    /// crate so it can name its own atomics). `top_classes` is the
    /// number of GObjects classes to surface in the population
    /// block (typical: 40).
    pub fn collect(counters: Json, top_classes: usize) -> Self {
        ProcessSnapshot {
            counters,
            process_memory: crate::winproc::process_memory_json(),
            process_cpu: crate::winproc::process_cpu_json(),
            process_threads: crate::winproc::process_threads_json(),
            game_population: crate::ue::probe::gobjects_population(top_classes),
            process_regions: crate::winproc::process_regions_json(),
        }
    }
}

/// Enqueue a closure on a game-thread `DrainSite` with the
/// universal "trampoline must be firing" timeout-hint behavior.
/// `hint` is a short message appended to timeout errors so callers
/// know which trampoline owns the drain (typically the kill-hook
/// fn name).
pub fn enqueue_pe<F>(
    pe_queue: &DrainSite,
    timeout: Duration,
    hint: &str,
    closure: F,
) -> Result<Json, String>
where
    F: FnOnce() -> Result<Json, String> + Send + 'static,
{
    pe_queue
        .queue()
        .enqueue(closure, timeout)
        .map_err(|e| {
            if e.contains("timed out") {
                format!("{e}. {hint}")
            } else {
                e
            }
        })
}

/// Try to handle one of the [`STANDARD_OPS`] generically. Returns
/// `None` if the op isn't standard (caller dispatches their
/// game-specific op). Returns `Some(Ok(json))` / `Some(Err(msg))`
/// for handled ops.
///
/// Ops that need a per-game instance resolver (`call`, `read_bytes`,
/// `write_bytes`) are NOT included here -- they take a closure the
/// game must supply. Use [`dispatch_pe_ops`] for those.
pub fn dispatch_standard_op<A: RpgApplier>(
    op: &str,
    args_json: &Json,
    tracker: &Tracker<A>,
    disabled: &DisabledSkills,
) -> Option<Result<Json, String>> {
    Some(match op {
        "skill_toggle" => crate::rpg::ops::skill_toggle(tracker, disabled, args_json),
        "skill_spend" => crate::rpg::ops::skill_spend(tracker, args_json),
        "skill_refund" => crate::rpg::ops::skill_refund(tracker, args_json),
        "reload_slot" => crate::rpg::ops::reload_slot(tracker),
        "set_skill_points" => crate::rpg::ops::set_skill_points(tracker, args_json),
        "walk_class" => crate::ops::walk_class(args_json),
        "class_outer_samples" => {
            let class_name = match args::arg_str(args_json, "class") {
                Ok(s) => s,
                Err(e) => return Some(Err(e)),
            };
            let k = match args::arg_u64(args_json, "k", Some(20)) {
                Ok(v) => v as usize,
                Err(e) => return Some(Err(e)),
            };
            Ok(crate::ue::probe::class_outer_samples(class_name, k))
        }
        "sample_thread_modules" => {
            let duration_ms = match args::arg_u64(args_json, "duration_ms", Some(30_000)) {
                Ok(v) => v as u32,
                Err(e) => return Some(Err(e)),
            };
            let interval_ms = match args::arg_u64(args_json, "interval_ms", Some(100)) {
                Ok(v) => v as u32,
                Err(e) => return Some(Err(e)),
            };
            Ok(crate::winproc::sample_thread_modules_json(duration_ms, interval_ms))
        }
        _ => return None,
    })
}

/// Handle the three standard ops that need a game-specific
/// instance resolver (`call`, `read_bytes`, `write_bytes`).
/// Returns `None` for non-matching ops.
///
/// `pe_queue` is the game-thread DrainSite the `call` op enqueues
/// onto; `hint` is appended to timeout errors. `resolver` is the
/// game's selector dispatcher (typically wraps
/// [`crate::selector::resolve_generic`] with extra game-specific
/// names like `"live_player"`).
///
/// `read_bytes` and `write_bytes` are off-thread-safe (they only
/// read / write memory, no PE), so they don't go through the
/// queue.
pub fn dispatch_pe_ops<R>(
    op: &str,
    args_json: &Json,
    pe_queue: &'static DrainSite,
    hint: &'static str,
    resolver: R,
) -> Option<Result<Json, String>>
where
    R: Fn(&str) -> Result<&'static crate::ue::UObject, String>
        + Copy
        + Send
        + 'static,
{
    match op {
        "call" => Some(dispatch_call(args_json, pe_queue, hint, resolver)),
        "read_bytes" => Some(crate::ops::read_bytes(args_json, resolver)),
        "write_bytes" => Some(crate::ops::write_bytes(args_json, resolver)),
        _ => None,
    }
}

fn dispatch_call<R>(
    args_json: &Json,
    pe_queue: &'static DrainSite,
    hint: &'static str,
    resolver: R,
) -> Result<Json, String>
where
    R: Fn(&str) -> Result<&'static crate::ue::UObject, String>
        + Copy
        + Send
        + 'static,
{
    let class = args::arg_str(args_json, "class")?.to_string();
    let function = args::arg_str(args_json, "function")?.to_string();
    let selector = args::arg_str(args_json, "instance_selector")?.to_string();
    let parms = crate::hex::decode(args::arg_str(args_json, "parms_hex")?)?;
    enqueue_pe(pe_queue, Duration::from_secs(5), hint, move || {
        let instance = resolver(&selector)?;
        let mut out = crate::ops::exec_call(instance, &class, &function, parms)?;
        if let Some(obj) = out.as_object_mut() {
            obj.insert("selector".into(), Json::String(selector.clone()));
        }
        Ok(out)
    })
}
