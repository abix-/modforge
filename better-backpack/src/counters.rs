// Hot-path performance counters.
//
// Every counter is an `AtomicU64` bumped at a specific call site
// in the mod. Snapshot endpoint exposes them. To find the
// runaway: snapshot at T0, play for N seconds, snapshot at T1,
// diff. Whichever counter has the largest delta is the cycle
// thief.
//
// Counters are write-mostly; no contention with reads. Each
// bump is a single relaxed atomic add.

use std::sync::atomic::{AtomicU64, AtomicUsize, Ordering};

// Generic primitives now live in `uespy::counters`. Re-exported
// here so existing call sites (`crate::counters::bump`,
// `crate::counters::time_scope`, `crate::counters::observe_peak`)
// keep working without churn.
pub use uespy::counters::{TimeScope, bump, observe_peak, time_scope};

// Generic Windows process-introspection helpers (used by debug ops
// `process_threads_json`, `process_cpu_json`, `process_regions_json`,
// `sample_thread_modules_json`, `process_memory_json`).
pub use uespy::winproc::{
    process_cpu_json, process_memory_json, process_regions_json, process_threads_json,
    sample_thread_modules_json,
};

macro_rules! counter {
    ($name:ident) => {
        pub static $name: AtomicU64 = AtomicU64::new(0);
    };
}

// kill_hook (UHealthComponent vtable)
counter!(KILL_HOOK_FIRES);
counter!(KILL_HOOK_PLAYER_FIRES);
counter!(KILL_HOOK_OWNER_FULLNAME_ALLOCS);
counter!(KILL_HOOK_LOG_LINES);
counter!(KILL_HOOK_DAMAGETYPE_NAME_ALLOCS);

// fall_hook (player BP class vtable)
counter!(FALL_HOOK_FIRES);
counter!(FALL_HOOK_FNNAME_ALLOCS);

// PE-queue drain
counter!(DRAIN_PENDING_CALLS);
counter!(DRAIN_PENDING_DRAINED_CMDS);

// debug damage_ring
counter!(DAMAGE_RING_PUSHES);

// world_loader poller
counter!(WORLD_LOADER_POLLS);
counter!(WORLD_LOADER_GOBJECTS_WALKS);

// ImGui RPG tab render path (FFI hits)
counter!(IMGUI_TAB_RENDERS);
counter!(IMGUI_FORMAT_CALLS);

// File logging
counter!(BBP_LOG_LINES);
counter!(BBP_LOG_FSYNCS);

// HTTP endpoint
counter!(HTTP_REQUESTS);

// Peak high-water marks (size_t).
pub static DAMAGE_RING_PEAK: AtomicUsize = AtomicUsize::new(0);
pub static PE_QUEUE_PEAK: AtomicUsize = AtomicUsize::new(0);

// CPU time accumulators (nanoseconds spent inside our hot-path
// functions). Diff over a window = total wall time our code
// stole from the game thread. Compare to the process's total
// CPU time delta (process_cpu_user_ns + process_cpu_kernel_ns)
// to compute our fraction of total CPU load.
counter!(TIME_NS_KILL_HOOK);
counter!(TIME_NS_FALL_HOOK);
counter!(TIME_NS_DRAIN_PENDING);
counter!(TIME_NS_BBP_LOG);
counter!(TIME_NS_IMGUI_GET_XP);
counter!(TIME_NS_FORMAT_SKILL_EFFECT);
counter!(TIME_NS_HTTP_HANDLE);

/// Snapshot all counters as a JSON object. Called by debug::snapshot.
pub fn snapshot_json() -> serde_json::Value {
    serde_json::json!({
        "kill_hook_fires":                  KILL_HOOK_FIRES.load(Ordering::Relaxed),
        "kill_hook_player_fires":           KILL_HOOK_PLAYER_FIRES.load(Ordering::Relaxed),
        "kill_hook_owner_fullname_allocs":  KILL_HOOK_OWNER_FULLNAME_ALLOCS.load(Ordering::Relaxed),
        "kill_hook_log_lines":              KILL_HOOK_LOG_LINES.load(Ordering::Relaxed),
        "kill_hook_damagetype_name_allocs": KILL_HOOK_DAMAGETYPE_NAME_ALLOCS.load(Ordering::Relaxed),
        "fall_hook_fires":                  FALL_HOOK_FIRES.load(Ordering::Relaxed),
        "fall_hook_fnname_allocs":          FALL_HOOK_FNNAME_ALLOCS.load(Ordering::Relaxed),
        "drain_pending_calls":              DRAIN_PENDING_CALLS.load(Ordering::Relaxed),
        "drain_pending_drained_cmds":       DRAIN_PENDING_DRAINED_CMDS.load(Ordering::Relaxed),
        "damage_ring_pushes":               DAMAGE_RING_PUSHES.load(Ordering::Relaxed),
        "world_loader_polls":               WORLD_LOADER_POLLS.load(Ordering::Relaxed),
        "world_loader_gobjects_walks":      WORLD_LOADER_GOBJECTS_WALKS.load(Ordering::Relaxed),
        "imgui_tab_renders":                IMGUI_TAB_RENDERS.load(Ordering::Relaxed),
        "imgui_format_calls":               IMGUI_FORMAT_CALLS.load(Ordering::Relaxed),
        "bbp_log_lines":                    BBP_LOG_LINES.load(Ordering::Relaxed),
        "bbp_log_fsyncs":                   BBP_LOG_FSYNCS.load(Ordering::Relaxed),
        "http_requests":                    HTTP_REQUESTS.load(Ordering::Relaxed),
        "damage_ring_peak":                 DAMAGE_RING_PEAK.load(Ordering::Relaxed),
        "pe_queue_peak":                    PE_QUEUE_PEAK.load(Ordering::Relaxed),
        // CPU time spent in our hot paths (cumulative ns).
        "time_ns_kill_hook":                TIME_NS_KILL_HOOK.load(Ordering::Relaxed),
        "time_ns_fall_hook":                TIME_NS_FALL_HOOK.load(Ordering::Relaxed),
        "time_ns_drain_pending":            TIME_NS_DRAIN_PENDING.load(Ordering::Relaxed),
        "time_ns_bbp_log":                  TIME_NS_BBP_LOG.load(Ordering::Relaxed),
        "time_ns_imgui_get_xp":             TIME_NS_IMGUI_GET_XP.load(Ordering::Relaxed),
        "time_ns_format_skill_effect":      TIME_NS_FORMAT_SKILL_EFFECT.load(Ordering::Relaxed),
        "time_ns_http_handle":              TIME_NS_HTTP_HANDLE.load(Ordering::Relaxed),
    })
}
