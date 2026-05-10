// Debug HTTP endpoint and state snapshot.
//
// Single POST /debug endpoint, opt-in via `settings.debug.http_port`.
// Body: `{"op": "<name>", "args": {...}}`. Response always includes a
// full `state` snapshot so callers see post-op state in one round-trip.
//
// First op: `snapshot` (read-only). Future ops (skill_spend,
// skill_toggle, simulate_damage / simulate_heal, reload_slot) get
// queued onto a known-game-thread surface and drained from
// `kill_hook`'s PE trampoline. Read-only first because reads are safe
// off-thread and immediately useful for diagnosis.
//
// See `docs/todo.md` "Integration testing" for the full design and
// the bandage-regression test that gates the next milestone.

use std::time::Duration;

use serde::Serialize;
use serde_json::Value as Json;
use ueforge::args::{arg_bool, arg_f64, arg_str, arg_u64};
use ueforge::envelope::{OpResponse as UespyResponse, parse_request};
use ueforge::pe_queue::Queue as PeQueue;

use crate::bbp_log;
use crate::inv_hook;
use crate::rpg::{apply, fall_hook, skills, tracker, world_loader};
use crate::sdk::{self, UObject};

// Ops are added one at a time, each driven by a failing test in
// `better-backpack/tests/`. Discipline: write the red test FIRST,
// then add the match arm + handler. See
// `~/.claude/skills/runtime-control-http/SKILL.md` for the
// cross-project pattern.
const SUPPORTED_OPS: &[&str] = &[
    "snapshot",
    "skill_toggle",
    "skill_spend",
    "skill_refund",
    "reload_slot",
    "simulate_add_health",
    "simulate_apply_damage",
    "simulate_set_current_health",
    "set_skill_points",
    "call",
    "read_bytes",
    "write_bytes",
    "walk_class",
    "class_outer_samples",
    "sample_thread_modules",
];

// PE-thread queue. The HTTP handler enqueues a command + a reply
// channel; `drain_pending()` is called from `kill_hook`'s
// trampoline (which UE calls on the game thread for every
// MulticastHandleEffectsWithDamageFlags event = many per second
// during gameplay). The trampoline drains the queue, executes
// each command on the game thread, and sends the result back via
// the channel. The HTTP handler blocks on `recv_timeout(5s)` so
// the response sees post-op state.
//
// This is the load-bearing piece for `simulate_*` ops: native
// UFunctions like `AddHealth` and `ApplyDamageFromInfo` are only
// safe to call via process_event on the game thread.

#[derive(Debug)]
#[allow(dead_code)]
enum DebugCmd {
    AddHealth(f32),
    SetCurrentHealth(f32),
}

/// Game-thread job queue. The HTTP handler enqueues a closure that
/// captures a `DebugCmd`; the closure runs from `drain_pending` on
/// the game thread. See `ueforge::pe_queue` for mechanics.
static PE_QUEUE: PeQueue = PeQueue::new();

/// Ring buffer of recent damage / multicast events captured by
/// the `kill_hook` trampoline. Populated by
/// `record_damage_event()` from the trampoline; drained by the
/// snapshot endpoint. Bounded (64) so a long session can't
/// exhaust memory; mechanics in `ueforge::ring::Ring`.
static DAMAGE_RING: ueforge::ring::Ring<DamageEvent> = ueforge::ring::Ring::new(64);

#[derive(Clone, Serialize)]
pub struct DamageEvent {
    /// Wall-clock seconds since logger init's UNIX epoch wrap, to
    /// sequence events. Matches the same clock as bbp_log lines.
    pub at_secs: u64,
    pub function: String,
    /// Damage value as read from the parm struct (offset depends
    /// on which UFunction; the trampoline picks the right one).
    pub damage: f32,
    pub damage_flags: i32,
    pub type_flags: u32,
    pub current_damage_before: Option<f32>,
    pub current_damage_after: Option<f32>,
}

pub fn record_damage_event(ev: DamageEvent) {
    crate::counters::bump(&crate::counters::DAMAGE_RING_PUSHES);
    if let Some(n) = DAMAGE_RING.push(ev) {
        crate::counters::observe_peak(&crate::counters::DAMAGE_RING_PEAK, n);
    }
}

fn snapshot_damage_ring() -> Vec<DamageEvent> {
    DAMAGE_RING.snapshot()
}

fn enqueue_pe(cmd: DebugCmd) -> Result<Json, String> {
    PE_QUEUE
        .enqueue(
            move || execute_on_game_thread(cmd),
            Duration::from_secs(5),
        )
        .map_err(|e| {
            // Wrap the generic timeout/poison message with the
            // game-specific hint so callers know which trampoline
            // is supposed to be draining.
            if e.contains("timed out") {
                format!(
                    "{e}. Is kill_hook firing? \
                     (Move around / take damage to drive multicast events.)"
                )
            } else {
                e
            }
        })
}

/// Called from `kill_hook`'s trampoline (game thread). Wraps
/// `ueforge::Queue::drain` with our perf counters. The queue itself
/// owns the re-entrance guard, the lock-free empty-check, and the
/// reply-channel plumbing.
pub fn drain_pending() {
    crate::counters::bump(&crate::counters::DRAIN_PENDING_CALLS);
    if PE_QUEUE.is_empty() {
        return;
    }
    let _t = crate::counters::time_scope(&crate::counters::TIME_NS_DRAIN_PENDING);
    let stats = PE_QUEUE.drain();
    if stats.reentered {
        return;
    }
    crate::counters::observe_peak(&crate::counters::PE_QUEUE_PEAK, stats.peak);
    for _ in 0..stats.drained {
        crate::counters::bump(&crate::counters::DRAIN_PENDING_DRAINED_CMDS);
    }
}

fn execute_on_game_thread(cmd: DebugCmd) -> Result<Json, String> {
    match cmd {
        DebugCmd::AddHealth(amount) => exec_add_health(amount),
        DebugCmd::SetCurrentHealth(value) => exec_set_current_health(value),
    }
}

pub fn spawn(port: u16) {
    ueforge::spawn(
        ueforge::Config {
            port,
            endpoint: "/debug",
            thread_name: "bbp-debug-http",
        },
        |body| {
            let _t = crate::counters::time_scope(&crate::counters::TIME_NS_HTTP_HANDLE);
            crate::counters::bump(&crate::counters::HTTP_REQUESTS);
            let resp = handle(body);
            serde_json::to_vec(&resp).unwrap_or_else(|_| b"{}".to_vec())
        },
        |msg| bbp_log!("{}", msg),
    );
}

type OpResponse = UespyResponse<Snapshot>;

fn handle(body: &str) -> OpResponse {
    let (op, args) = match parse_request(body) {
        Ok(v) => v,
        Err(e) => return error_response("<parse-error>", e),
    };

    match op.as_str() {
        "snapshot" => ok_response(&op, Json::Null),
        "skill_toggle" => to_response(&op, op_skill_toggle(&args)),
        "skill_spend" => to_response(&op, op_skill_spend(&args)),
        "skill_refund" => to_response(&op, op_skill_refund(&args)),
        "reload_slot" => to_response(&op, op_reload_slot()),
        "simulate_add_health" => to_response(&op, op_simulate_add_health(&args)),
        "simulate_apply_damage" => to_response(&op, op_simulate_apply_damage(&args)),
        "simulate_set_current_health" => {
            to_response(&op, op_simulate_set_current_health(&args))
        }
        "set_skill_points" => to_response(&op, op_set_skill_points(&args)),
        "call" => to_response(&op, op_call(&args)),
        "read_bytes" => to_response(&op, op_read_bytes(&args)),
        "write_bytes" => to_response(&op, op_write_bytes(&args)),
        "walk_class" => to_response(&op, op_walk_class(&args)),
        "class_outer_samples" => to_response(&op, op_class_outer_samples(&args)),
        "sample_thread_modules" => to_response(&op, op_sample_thread_modules(&args)),
        "" => error_response(
            "<missing>",
            format!("missing 'op' field; supported ops: {SUPPORTED_OPS:?}"),
        ),
        other => error_response(
            other,
            format!("unknown op '{other}'; supported ops: {SUPPORTED_OPS:?}"),
        ),
    }
}

fn ok_response(op: &str, result: Json) -> OpResponse {
    OpResponse::ok(op, result, build_snapshot())
}

fn to_response(op: &str, r: Result<Json, String>) -> OpResponse {
    OpResponse::from_result(op, r, build_snapshot())
}

fn lookup_skill(id: &str) -> Result<&'static skills::Skill, String> {
    skills::lookup(id).ok_or_else(|| format!("unknown skill '{id}'"))
}

fn op_skill_toggle(args: &Json) -> Result<Json, String> {
    let id = arg_str(args, "id")?;
    let enabled = arg_bool(args, "enabled")?;
    let skill = lookup_skill(id)?;
    let new_state = apply::set_skill_enabled(skill.id, enabled);
    tracker::reapply_one(skill.id);
    Ok(serde_json::json!({"id": id, "enabled": new_state}))
}

fn op_skill_spend(args: &Json) -> Result<Json, String> {
    let id = arg_str(args, "id")?;
    let count = arg_u64(args, "count", Some(1))?;
    let count = u32::try_from(count).map_err(|_| format!("count {count} > u32::MAX"))?;
    let skill = lookup_skill(id)?;
    let spent = tracker::spend_skill_points(skill, count);
    Ok(serde_json::json!({"id": id, "requested": count, "spent": spent}))
}

fn op_skill_refund(args: &Json) -> Result<Json, String> {
    let id = arg_str(args, "id")?;
    let count = arg_u64(args, "count", Some(1))?;
    let count = u32::try_from(count).map_err(|_| format!("count {count} > u32::MAX"))?;
    let skill = lookup_skill(id)?;
    let refunded = tracker::refund_skill_points(skill, count);
    Ok(serde_json::json!({"id": id, "requested": count, "refunded": refunded}))
}

fn op_reload_slot() -> Result<Json, String> {
    if tracker::reapply_all() {
        Ok(serde_json::json!({"reapplied": true}))
    } else {
        Err("no slot active; cannot reload".into())
    }
}

fn op_simulate_add_health(args: &Json) -> Result<Json, String> {
    let amount = arg_f64(args, "amount")? as f32;
    enqueue_pe(DebugCmd::AddHealth(amount))
}

fn op_simulate_apply_damage(_args: &Json) -> Result<Json, String> {
    // Disabled: calling ApplyDamageFromInfo via process_event from
    // any of our current PE trampolines (kill_hook, fall_hook,
    // inv_hook) hangs the game because the engine's damage
    // replication path re-enters ProcessEvent. The op stays in
    // the API surface (so tests can detect-and-skip cleanly) but
    // refuses with an explanation until the safe drain site
    // lands. See `docs/todo.md` "Endpoint parity gap".
    Err(
        "simulate_apply_damage temporarily disabled: \
         calling ApplyDamageFromInfo from inside a PE trampoline \
         crashes the game (replication re-entry). \
         Use simulate_add_health / simulate_set_current_health for \
         healing tests, or watch state.damage_ring while a real \
         bandage is used in-game."
            .to_string(),
    )
}

fn op_simulate_set_current_health(args: &Json) -> Result<Json, String> {
    let value = arg_f64(args, "value")? as f32;
    enqueue_pe(DebugCmd::SetCurrentHealth(value))
}

// ---- generic call primitive ----
//
// op: "call"
// args: { class, function, instance_selector, parms_hex }
// returns: { parms_hex_after, instance_kind }
//
// Tests build the parm bytes test-side (using #[repr(C)] structs
// matching the SDK), hex-encode, send. The mod calls
// process_event with the buffer and returns the (possibly
// engine-mutated) buffer back as hex. This is the test-side
// "do anything" surface.

fn op_call(args: &Json) -> Result<Json, String> {
    let class = arg_str(args, "class")?.to_string();
    let function = arg_str(args, "function")?.to_string();
    let selector = arg_str(args, "instance_selector")?.to_string();
    let parms = ueforge::hex::decode(arg_str(args, "parms_hex")?)?;
    PE_QUEUE
        .enqueue(
            move || {
                let instance = resolve_instance(&selector)?;
                let mut out = ueforge::ops::exec_call(instance, &class, &function, parms)?;
                // Preserve historical "selector" echo in the result.
                if let Some(obj) = out.as_object_mut() {
                    obj.insert("selector".into(), Json::String(selector.clone()));
                }
                Ok(out)
            },
            Duration::from_secs(5),
        )
        .map_err(|e| {
            if e.contains("timed out") {
                format!(
                    "{e}. Is kill_hook firing? \
                     (Move around / take damage to drive multicast events.)"
                )
            } else {
                e
            }
        })
}

fn resolve_instance(selector: &str) -> Result<&'static UObject, String> {
    if let Some(r) = ueforge::selector::resolve_generic(selector) {
        return r;
    }
    match selector {
        "live_player_hc" => live_player_hc(),
        "live_player" => {
            let mut found: Option<&'static UObject> = None;
            apply::apply_to_live_player_characters(|p| {
                if found.is_none() {
                    let extended: &'static UObject =
                        unsafe { std::mem::transmute::<&UObject, &'static UObject>(p) };
                    found = Some(extended);
                }
            });
            found.ok_or_else(|| "no live player".to_string())
        }
        _ => Err(format!(
            "unknown selector '{selector}'. supported: live_player_hc, live_player, first_class:<name>, addr:0x<hex>"
        )),
    }
}

// ---- read_bytes / write_bytes / walk_class primitives ----
//
// With these + `call`, the test side can do literally anything on
// the host: read any field, write any field, find any instance,
// invoke any UFunction. The endpoint stops growing.

fn op_read_bytes(args: &Json) -> Result<Json, String> {
    ueforge::ops::read_bytes(args, resolve_instance)
}

fn op_write_bytes(args: &Json) -> Result<Json, String> {
    ueforge::ops::write_bytes(args, resolve_instance)
}

fn op_walk_class(args: &Json) -> Result<Json, String> {
    ueforge::ops::walk_class(args)
}

fn op_class_outer_samples(args: &Json) -> Result<Json, String> {
    let class_name = arg_str(args, "class")?;
    let k = arg_u64(args, "k", Some(20))? as usize;
    Ok(ueforge::ue::probe::class_outer_samples(class_name, k))
}

fn op_sample_thread_modules(args: &Json) -> Result<Json, String> {
    let duration_ms = arg_u64(args, "duration_ms", Some(30_000))? as u32;
    let interval_ms = arg_u64(args, "interval_ms", Some(100))? as u32;
    Ok(crate::counters::sample_thread_modules_json(duration_ms, interval_ms))
}

fn op_set_skill_points(args: &Json) -> Result<Json, String> {
    let count = arg_u64(args, "count", None)?;
    let count = u32::try_from(count).map_err(|_| format!("count {count} > u32::MAX"))?;
    if !tracker::debug_grant_skill_points(count) {
        return Err("no slot active".into());
    }
    Ok(serde_json::json!({"granted": count}))
}

// ---- Game-thread executors. Called from kill_hook trampoline. ----

fn live_player_hc() -> Result<&'static UObject, String> {
    let mut hc: Option<&'static UObject> = None;
    apply::apply_to_live_player_characters(|player| {
        if hc.is_none()
            && let Some(found) = apply::read_component_ptr(player, apply::ASC_HEALTH_COMPONENT)
        {
            // SAFETY: while we're on the game thread inside the
            // trampoline, GObjects is stable. The reference's
            // lifetime is artificially extended; we use it only
            // within this drain cycle.
            let extended: &'static UObject =
                unsafe { std::mem::transmute::<&UObject, &'static UObject>(found) };
            hc = Some(extended);
        }
    });
    hc.ok_or_else(|| "no live player HealthComponent".into())
}

fn exec_add_health(amount: f32) -> Result<Json, String> {
    use std::ffi::c_void;
    let hc = live_player_hc()?;
    let class = sdk::find_class_fast("HealthComponent")
        .ok_or_else(|| "HealthComponent class not found".to_string())?;
    let func = class
        .get_function("HealthComponent", "AddHealth")
        .ok_or_else(|| "AddHealth UFunction not found".to_string())?;
    let before = apply::read_f32(hc, 0x032C); // CurrentDamage
    #[repr(C)]
    struct AddHealthParms {
        amount: f32,
        causer: *mut c_void,
    }
    let mut parms = AddHealthParms {
        amount,
        causer: std::ptr::null_mut(),
    };
    unsafe {
        hc.process_event(func, &mut parms as *mut _ as *mut c_void);
    }
    let after = apply::read_f32(hc, 0x032C);
    Ok(serde_json::json!({
        "amount_requested": amount,
        "current_damage_before": before,
        "current_damage_after": after,
        "delta": before - after,
    }))
}

#[allow(dead_code)] // kept as reference; tests should use `call` instead
fn exec_apply_damage(amount: f32, type_flags: u32) -> Result<Json, String> {
    use std::ffi::c_void;
    let hc = live_player_hc()?;
    let class = sdk::find_class_fast("HealthComponent")
        .ok_or_else(|| "HealthComponent class not found".to_string())?;
    let func = class
        .get_function("HealthComponent", "ApplyDamageFromInfo")
        .ok_or_else(|| "ApplyDamageFromInfo UFunction not found".to_string())?;

    // Parm struct layout (Maine_parameters.hpp HealthComponent_ApplyDamageFromInfo):
    //   +0x000 Damage          f32  (OUT, the engine writes back the
    //                                applied damage after gates / mitigation)
    //   +0x004 Pad
    //   +0x008 FDamageEvent    16 bytes (Pad8 + DamageTypeClass)
    //   +0x018 FDamageInfo     0xE8 bytes
    // Total: 0x100. We allocate zeroed and only set the fields we care about.
    //
    // FDamageInfo layout (Maine_structs.hpp FDamageInfo, relative to parm+0x018):
    //   +0x70 DamageFlags    int32   (the gate consults this for the type-flag check)
    //   +0x78 OriginDamageData FDamageData (its first field is `float Damage`)
    const PARM_SIZE: usize = 0x100;
    const DAMAGE_OUT_OFFSET: usize = 0x000;
    const DAMAGE_INFO_OFFSET: usize = 0x018;
    const DAMAGE_FLAGS_REL: usize = 0x070;
    const ORIGIN_DAMAGE_DATA_REL: usize = 0x078;

    let mut parms = [0u8; PARM_SIZE];
    unsafe {
        // Damage value (input lives inside FDamageInfo.OriginDamageData.Damage).
        let damage_in_ptr = parms
            .as_mut_ptr()
            .add(DAMAGE_INFO_OFFSET + ORIGIN_DAMAGE_DATA_REL) as *mut f32;
        damage_in_ptr.write_unaligned(amount);

        // DamageFlags (the int32 the gate reads).
        let flags_ptr = parms
            .as_mut_ptr()
            .add(DAMAGE_INFO_OFFSET + DAMAGE_FLAGS_REL) as *mut u32;
        flags_ptr.write_unaligned(type_flags);
    }

    let cd_before = apply::read_f32(hc, 0x032C);
    let max_before = apply::read_f32(hc, 0x0328);

    unsafe {
        hc.process_event(func, parms.as_mut_ptr() as *mut c_void);
    }

    let damage_out: f32 = unsafe {
        (parms.as_ptr().add(DAMAGE_OUT_OFFSET) as *const f32).read_unaligned()
    };
    let cd_after = apply::read_f32(hc, 0x032C);

    Ok(serde_json::json!({
        "amount_requested": amount,
        "type_flags_requested": format!("0x{type_flags:08X}"),
        "damage_out": damage_out,
        "current_damage_before": cd_before,
        "current_damage_after": cd_after,
        "current_damage_delta": cd_after - cd_before,
        "max_health": max_before,
    }))
}

fn exec_set_current_health(value: f32) -> Result<Json, String> {
    let hc = live_player_hc()?;
    let class = sdk::find_class_fast("HealthComponent")
        .ok_or_else(|| "HealthComponent class not found".to_string())?;
    let func = class
        .get_function("HealthComponent", "SetCurrentHealth")
        .ok_or_else(|| "SetCurrentHealth UFunction not found".to_string())?;
    #[repr(C)]
    struct SetHealthParms {
        desired_health: f32,
    }
    let mut parms = SetHealthParms {
        desired_health: value,
    };
    unsafe {
        use std::ffi::c_void;
        hc.process_event(func, &mut parms as *mut _ as *mut c_void);
    }
    let after = apply::read_f32(hc, 0x032C);
    Ok(serde_json::json!({
        "value_requested": value,
        "current_damage_after": after,
    }))
}

fn error_response(op: &str, err: impl Into<String>) -> OpResponse {
    OpResponse::err(op, err, build_snapshot())
}

#[derive(Serialize)]
pub struct Snapshot {
    pub slot: Option<String>,
    pub player_state: Option<PlayerStateView>,
    pub disabled_skills: Vec<&'static str>,
    pub vanilla: VanillaView,
    pub live_player: Option<LivePlayerView>,
    pub cdo: CdoView,
    pub inventory: InventoryView,
    /// Status effects currently active on the player, by data
    /// table row. Drives status-effect-migration research and
    /// regression tests for skills that interact with the engine's
    /// canonical `UStatusEffectComponent` surface.
    pub status_effects: Option<Vec<StatusEffectView>>,
    /// Catalog dump (server-authoritative). Tests iterate this
    /// instead of hardcoding skill ids; new skills get coverage
    /// automatically.
    pub catalog: Vec<CatalogEntry>,
    /// Settings echo: what the mod loaded from settings.json.
    /// Tests verify settings.json was honored without re-parsing
    /// the file from the test side.
    pub settings: SettingsView,
    /// Recent damage / multicast events captured by the kill_hook
    /// trampoline. Read-only (no process_event re-entry). Used to
    /// observe what bandages / consumables / fall events look
    /// like as they happen.
    pub damage_ring: Vec<DamageEvent>,
    /// Hot-path counters. Snapshot at T0, play, snapshot at T1,
    /// diff to find runaway. See `src/counters.rs`.
    pub counters: Json,
    /// Process memory readings via GetProcessMemoryInfo. Used by
    /// the perf test to detect actual RAM growth (working set,
    /// commit/private bytes, page faults) over a window.
    pub process_memory: Json,
    /// Process CPU times (user + kernel ns) via GetProcessTimes.
    /// Diff over a window vs our `TIME_NS_*` counters tells us
    /// what fraction of total process CPU is in our code.
    pub process_cpu: Json,
    /// Per-thread CPU times via Toolhelp + GetThreadTimes.
    /// Diff over a window shows which named thread (GameThread,
    /// RenderThread, etc.) is the cycle thief.
    pub process_threads: Json,
    /// UE5 GObjects population: total count + top classes by
    /// instance count. Diff over a window finds the leak source
    /// when an object class is growing unboundedly.
    pub game_population: Json,
    /// Process address-space breakdown via VirtualQuery. Diff
    /// over a window narrows non-UObject memory leaks to a
    /// specific category (image / mapped / private) and
    /// protection class. Top committed regions list sorts by
    /// size and includes mapped file names when applicable.
    pub process_regions: Json,
}

#[derive(Serialize)]
pub struct SettingsView {
    pub inventory_slot_count: i32,
    pub thirst_multiplier: f32,
    pub hunger_multiplier: f32,
    pub buggy_kill_xp_multiplier: f32,
    pub debug_http_port: Option<u16>,
}

#[derive(Serialize)]
pub struct CatalogEntry {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_level: u32,
    pub effect_kind: &'static str,
}

#[derive(Serialize)]
pub struct StatusEffectView {
    pub row: String,
    pub table: String,
    pub stat_type: Option<u8>,
    pub value: Option<f32>,
}

#[derive(Serialize)]
pub struct InventoryView {
    /// Slot count currently applied via the backpack patch. The
    /// inv_hook also stores this as the in-memory authoritative
    /// view that the inventory UI reads.
    pub current_slot_count: i32,
}

#[derive(Serialize)]
pub struct PlayerStateView {
    pub xp: u64,
    pub level: u32,
    pub skill_points: u32,
    pub skill_levels: serde_json::Map<String, Json>,
    pub kill_count: u64,
    pub last_killed: String,
}

#[derive(Serialize)]
pub struct VanillaView {
    pub hunger: Option<f32>,
    pub thirst: Option<f32>,
    pub fall_damage_ratio: Option<f32>,
    pub max_health: Option<f32>,
    pub hc_u32_masks: Vec<HcMaskView>,
}

#[derive(Serialize)]
pub struct HcMaskView {
    pub offset: String,
    pub value: String,
}

#[derive(Serialize)]
pub struct LivePlayerView {
    pub instance_count: usize,
    /// Reads of well-known UHealthComponent fields on the first
    /// live player encountered. Multiple players (multi-character
    /// switch) are typically all the same character at runtime, so
    /// the first one is representative.
    pub hc: Option<HcFields>,
    /// CharMovementComponent fields. Drives the per-skill
    /// expectations for move_speed, jump_height, leap_distance,
    /// glide_speed (and the per-character fall_resistance writes).
    pub cmc: Option<CmcFields>,
    /// ASurvivalCharacter-level fields (combat multipliers, fall
    /// damage trio).
    pub asc: Option<AscFields>,
}

#[derive(Serialize)]
pub struct HcFields {
    pub required_damage_type_flags: String,
    pub immunity_flags: String,
    pub base_damage_reduction: f32,
    pub max_health: f32,
    pub current_damage: f32,
}

#[derive(Serialize)]
pub struct CmcFields {
    pub max_walk_speed: f32,
    pub max_sprint_speed: f32,
    pub max_swim_speed: f32,
    pub max_swim_sprint_speed: f32,
    pub max_fly_speed: f32,
    pub jump_z_velocity: f32,
    pub air_control: f32,
    pub air_control_boost_multiplier: f32,
    pub air_control_boost_velocity_threshold: f32,
    pub custom_ground_speed_multiplier: f32,
    pub custom_fly_speed_multiplier: f32,
    pub custom_swim_speed_multiplier: f32,
}

#[derive(Serialize)]
pub struct AscFields {
    pub custom_damage_multiplier: f32,
    pub take_fall_damage: bool,
    pub minimum_fall_damage_velocity: f32,
    pub fall_damage_ratio: f32,
}

/// Per-class-default-object snapshot: drain rates, combat scalars,
/// regen knobs. Each sub-struct is None when the class isn't loaded
/// or vanilla hasn't been observed yet.
#[derive(Serialize)]
pub struct CdoView {
    pub survival: Option<SurvivalCdoFields>,
    pub global_combat_data: Option<GlobalCombatDataFields>,
    pub game_mode_settings: Option<GmsFields>,
    pub survival_mode_manager: Option<SmmcFields>,
}

#[derive(Serialize)]
pub struct SurvivalCdoFields {
    pub hunger_adjustment_per_second: f32,
    pub thirst_adjustment_per_second: f32,
}

#[derive(Serialize)]
pub struct GlobalCombatDataFields {
    pub combat_regen_delay: f32,
    pub combat_regen_tick_percentage: f32,
    pub combat_regen_tick_rate: f32,
}

#[derive(Serialize)]
pub struct GmsFields {
    pub fall_damage_multiplier: f32,
}

#[derive(Serialize)]
pub struct SmmcFields {
    pub custom_fall_damage_multiplier: f32,
}

fn build_snapshot() -> Snapshot {
    let slot = tracker::current_slot();
    let player_state = tracker::with_state(player_state_view);

    let mut skill_levels_map = serde_json::Map::new();
    if let Some(ref ps) = player_state {
        for (id, lv) in &ps.skill_levels {
            skill_levels_map.insert(id.clone(), Json::Number((*lv).into()));
        }
    }

    let player_state_view = player_state.map(|ps| PlayerStateView {
        xp: ps.xp,
        level: ps.level,
        skill_points: ps.skill_points,
        skill_levels: skill_levels_map,
        kill_count: ps.kill_count,
        last_killed: ps.last_killed,
    });

    let vanilla_masks = apply::vanilla_hc_masks_snapshot()
        .into_iter()
        .map(|(o, v)| HcMaskView {
            offset: format!("0x{:X}", o),
            value: format!("0x{:08X}", v),
        })
        .collect();

    let vanilla = VanillaView {
        hunger: apply::vanilla_hunger(),
        thirst: apply::vanilla_thirst(),
        fall_damage_ratio: apply::vanilla_fall_damage_ratio(),
        max_health: apply::vanilla_max_health(),
        hc_u32_masks: vanilla_masks,
    };

    let live_player = collect_live_player();
    let cdo = collect_cdo();
    let inventory = InventoryView {
        current_slot_count: inv_hook::current_slot_count(),
    };
    let status_effects = fall_hook::snapshot_player_status_effects().map(|v| {
        v.into_iter()
            .map(|e| StatusEffectView {
                row: e.row,
                table: e.table,
                stat_type: e.stat_type,
                value: e.value,
            })
            .collect()
    });

    let catalog = skills::CATALOG
        .iter()
        .map(|s| CatalogEntry {
            id: s.id,
            display_name: s.display_name,
            max_level: s.max_level,
            effect_kind: skill_effect_kind(&s.effect),
        })
        .collect();

    let settings = world_loader::loaded_settings()
        .map(|s| SettingsView {
            inventory_slot_count: s.inventory.slot_count,
            thirst_multiplier: s.survival.thirst_multiplier,
            hunger_multiplier: s.survival.hunger_multiplier,
            buggy_kill_xp_multiplier: s.rpg.buggy_kill_xp_multiplier,
            debug_http_port: s.debug.http_port,
        })
        .unwrap_or(SettingsView {
            inventory_slot_count: 0,
            thirst_multiplier: 0.0,
            hunger_multiplier: 0.0,
            buggy_kill_xp_multiplier: 0.0,
            debug_http_port: None,
        });

    Snapshot {
        slot,
        player_state: player_state_view,
        disabled_skills: apply::disabled_skills_snapshot(),
        vanilla,
        live_player,
        cdo,
        inventory,
        status_effects,
        catalog,
        settings,
        damage_ring: snapshot_damage_ring(),
        counters: crate::counters::snapshot_json(),
        process_memory: crate::counters::process_memory_json(),
        process_cpu: crate::counters::process_cpu_json(),
        process_threads: crate::counters::process_threads_json(),
        game_population: ueforge::ue::probe::gobjects_population(40),
        process_regions: crate::counters::process_regions_json(),
    }
}

fn skill_effect_kind(e: &skills::SkillEffect) -> &'static str {
    use skills::SkillEffect::*;
    match e {
        BackpackSlots { .. } => "BackpackSlots",
        SurvivalDrain { .. } => "SurvivalDrain",
        PlayerCharFloat { .. } => "PlayerCharFloat",
        PlayerHealthCompFloat { .. } => "PlayerHealthCompFloat",
        PlayerHealthCompAdditive { .. } => "PlayerHealthCompAdditive",
        PlayerHealthCompU32Mask { .. } => "PlayerHealthCompU32Mask",
        PlayerMovementMult { .. } => "PlayerMovementMult",
        PlayerFallDamageReduction { .. } => "PlayerFallDamageReduction",
        GlobalDataMult { .. } => "GlobalDataMult",
        Runtime { .. } => "Runtime",
        PlayerStatusEffect { .. } => "PlayerStatusEffect",
    }
}

fn player_state_view(ps: &crate::rpg::state::PlayerState) -> PlayerStateSnap {
    PlayerStateSnap {
        xp: ps.xp,
        level: ps.level,
        skill_points: ps.skill_points,
        skill_levels: ps.skill_levels.clone(),
        kill_count: ps.kill_count,
        last_killed: ps.last_killed.clone(),
    }
}

struct PlayerStateSnap {
    xp: u64,
    level: u32,
    skill_points: u32,
    skill_levels: std::collections::BTreeMap<String, u32>,
    kill_count: u64,
    last_killed: String,
}

fn collect_live_player() -> Option<LivePlayerView> {
    let mut count = 0usize;
    let mut hc: Option<HcFields> = None;
    let mut cmc: Option<CmcFields> = None;
    let mut asc: Option<AscFields> = None;
    apply::apply_to_live_player_characters(|player| {
        count += 1;
        if hc.is_none()
            && let Some(hc_obj) = apply::read_component_ptr(player, apply::ASC_HEALTH_COMPONENT)
        {
            hc = Some(read_hc_fields(hc_obj));
        }
        if cmc.is_none()
            && let Some(cmc_obj) =
                apply::read_component_ptr(player, apply::ASC_CHAR_MOVEMENT_COMPONENT)
        {
            cmc = Some(read_cmc_fields(cmc_obj));
        }
        if asc.is_none() {
            asc = Some(read_asc_fields(player));
        }
    });
    if count == 0 {
        None
    } else {
        Some(LivePlayerView {
            instance_count: count,
            hc,
            cmc,
            asc,
        })
    }
}

fn read_cmc_fields(cmc: &UObject) -> CmcFields {
    use crate::rpg::skills::*;
    CmcFields {
        max_walk_speed: apply::read_f32(cmc, CMC_MAX_WALK_SPEED),
        max_sprint_speed: apply::read_f32(cmc, CMC_MAX_SPRINT_SPEED),
        max_swim_speed: apply::read_f32(cmc, CMC_MAX_SWIM_SPEED),
        max_swim_sprint_speed: apply::read_f32(cmc, CMC_MAX_SWIM_SPRINT_SPEED),
        max_fly_speed: apply::read_f32(cmc, CMC_MAX_FLY_SPEED),
        jump_z_velocity: apply::read_f32(cmc, CMC_JUMP_Z_VELOCITY),
        air_control: apply::read_f32(cmc, CMC_AIR_CONTROL),
        air_control_boost_multiplier: apply::read_f32(cmc, CMC_AIR_CONTROL_BOOST_MULT),
        air_control_boost_velocity_threshold: apply::read_f32(cmc, CMC_AIR_CONTROL_BOOST_THRESHOLD),
        custom_ground_speed_multiplier: apply::read_f32(cmc, CMC_CUSTOM_GROUND_SPEED_MULTIPLIER),
        custom_fly_speed_multiplier: apply::read_f32(cmc, CMC_CUSTOM_FLY_SPEED_MULTIPLIER),
        custom_swim_speed_multiplier: apply::read_f32(cmc, CMC_CUSTOM_SWIM_SPEED_MULTIPLIER),
    }
}

fn read_asc_fields(asc: &UObject) -> AscFields {
    use crate::rpg::skills::*;
    AscFields {
        custom_damage_multiplier: apply::read_f32(asc, ASC_CUSTOM_DAMAGE_MULTIPLIER),
        take_fall_damage: unsafe {
            (asc.field_ptr(ASC_TAKE_FALL_DAMAGE) as *const u8).read() != 0
        },
        minimum_fall_damage_velocity: apply::read_f32(asc, ASC_MINIMUM_FALL_DAMAGE_VELOCITY),
        fall_damage_ratio: apply::read_f32(asc, ASC_FALL_DAMAGE_RATIO),
    }
}

fn collect_cdo() -> CdoView {
    use crate::rpg::skills::*;

    let mut survival = None;
    apply::class_default_object("SurvivalComponent", |obj| {
        survival = Some(SurvivalCdoFields {
            hunger_adjustment_per_second: apply::read_f32(obj, SURVIVAL_HUNGER_OFFSET),
            thirst_adjustment_per_second: apply::read_f32(obj, SURVIVAL_THIRST_OFFSET),
        });
    });

    let mut gcd = None;
    apply::first_instance_of("GlobalCombatData", |obj| {
        gcd = Some(GlobalCombatDataFields {
            combat_regen_delay: apply::read_f32(obj, GCD_COMBAT_REGEN_DELAY),
            combat_regen_tick_percentage: apply::read_f32(obj, GCD_COMBAT_REGEN_TICK_PERCENTAGE),
            combat_regen_tick_rate: apply::read_f32(obj, GCD_COMBAT_REGEN_TICK_RATE),
        });
    });

    let mut gms = None;
    apply::first_instance_of("SurvivalGameModeSettings", |obj| {
        gms = Some(GmsFields {
            fall_damage_multiplier: apply::read_f32(obj, GMS_FALL_DAMAGE_MULTIPLIER),
        });
    });

    let mut smmc = None;
    apply::first_instance_of("SurvivalModeManagerComponent", |obj| {
        smmc = Some(SmmcFields {
            custom_fall_damage_multiplier: apply::read_f32(obj, SMMC_CUSTOM_FALL_DAMAGE_MULTIPLIER),
        });
    });

    CdoView {
        survival,
        global_combat_data: gcd,
        game_mode_settings: gms,
        survival_mode_manager: smmc,
    }
}

fn read_hc_fields(hc: &UObject) -> HcFields {
    // Offsets verified against Maine_classes.hpp + skills.rs.
    const HC_IMMUNITY_FLAGS: usize = 0x00F8;
    const HC_BASE_DAMAGE_REDUCTION: usize = 0x00EC;
    const HC_REQUIRED_DAMAGE_TYPE_FLAGS: usize = 0x00FC;
    const HC_MAX_HEALTH: usize = 0x0328;
    const HC_CURRENT_DAMAGE: usize = 0x032C;
    HcFields {
        required_damage_type_flags: format!(
            "0x{:08X}",
            apply::read_u32(hc, HC_REQUIRED_DAMAGE_TYPE_FLAGS)
        ),
        immunity_flags: format!("0x{:08X}", apply::read_u32(hc, HC_IMMUNITY_FLAGS)),
        base_damage_reduction: apply::read_f32(hc, HC_BASE_DAMAGE_REDUCTION),
        max_health: apply::read_f32(hc, HC_MAX_HEALTH),
        current_damage: apply::read_f32(hc, HC_CURRENT_DAMAGE),
    }
}

/// All registered skill ids in the catalog. Exposed so docs and
/// tests can iterate the canonical list without re-deriving it.
#[allow(dead_code)]
pub fn catalog_skill_ids() -> Vec<&'static str> {
    skills::CATALOG.iter().map(|s| s.id).collect()
}
