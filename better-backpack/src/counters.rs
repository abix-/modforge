// Bbp-specific perf counters. Generic primitives (`bump`,
// `time_scope`, `observe_peak`, `Ring`) live in `ueforge::counters`
// and `ueforge::winproc`; consumers reach for those directly.
//
// Snapshot endpoint diffs these statics across two `snapshot` calls
// to find cycle thieves.

use std::sync::atomic::AtomicUsize;

use ueforge::{counter, counter_json};

// kill_hook (UHealthComponent vtable)
counter!(
    KILL_HOOK_FIRES,
    KILL_HOOK_PLAYER_FIRES,
    KILL_HOOK_OWNER_FULLNAME_ALLOCS,
    KILL_HOOK_LOG_LINES,
    KILL_HOOK_DAMAGETYPE_NAME_ALLOCS,
);

// fall_hook (player BP class vtable)
counter!(FALL_HOOK_FIRES, FALL_HOOK_FNNAME_ALLOCS);

// PE-queue drain
counter!(DRAIN_PENDING_CALLS, DRAIN_PENDING_DRAINED_CMDS);

// debug damage_ring
counter!(DAMAGE_RING_PUSHES);

// world_loader poller
counter!(WORLD_LOADER_POLLS, WORLD_LOADER_GOBJECTS_WALKS);

// ImGui RPG tab render path
counter!(IMGUI_TAB_RENDERS);

// HTTP endpoint
counter!(HTTP_REQUESTS);

// Peak high-water marks (size_t).
pub static DAMAGE_RING_PEAK: AtomicUsize = AtomicUsize::new(0);
pub static PE_QUEUE_PEAK: AtomicUsize = AtomicUsize::new(0);

// CPU time accumulators (nanoseconds spent inside hot paths). Diff
// over a window = total wall time bbp stole from the game thread.
counter!(
    TIME_NS_KILL_HOOK,
    TIME_NS_FALL_HOOK,
    TIME_NS_DRAIN_PENDING,
    TIME_NS_IMGUI_GET_XP,
    TIME_NS_HTTP_HANDLE,
);

/// Snapshot all counters as a JSON object. Called by debug::snapshot.
pub fn snapshot_json() -> serde_json::Value {
    counter_json! {
        KILL_HOOK_FIRES                  => "kill_hook_fires",
        KILL_HOOK_PLAYER_FIRES           => "kill_hook_player_fires",
        KILL_HOOK_OWNER_FULLNAME_ALLOCS  => "kill_hook_owner_fullname_allocs",
        KILL_HOOK_LOG_LINES              => "kill_hook_log_lines",
        KILL_HOOK_DAMAGETYPE_NAME_ALLOCS => "kill_hook_damagetype_name_allocs",
        FALL_HOOK_FIRES                  => "fall_hook_fires",
        FALL_HOOK_FNNAME_ALLOCS          => "fall_hook_fnname_allocs",
        DRAIN_PENDING_CALLS              => "drain_pending_calls",
        DRAIN_PENDING_DRAINED_CMDS       => "drain_pending_drained_cmds",
        DAMAGE_RING_PUSHES               => "damage_ring_pushes",
        WORLD_LOADER_POLLS               => "world_loader_polls",
        WORLD_LOADER_GOBJECTS_WALKS      => "world_loader_gobjects_walks",
        IMGUI_TAB_RENDERS                => "imgui_tab_renders",
        HTTP_REQUESTS                    => "http_requests",
        DAMAGE_RING_PEAK                 => "damage_ring_peak",
        PE_QUEUE_PEAK                    => "pe_queue_peak",
        TIME_NS_KILL_HOOK                => "time_ns_kill_hook",
        TIME_NS_FALL_HOOK                => "time_ns_fall_hook",
        TIME_NS_DRAIN_PENDING            => "time_ns_drain_pending",
        TIME_NS_IMGUI_GET_XP             => "time_ns_imgui_get_xp",
        TIME_NS_HTTP_HANDLE              => "time_ns_http_handle",
    }
}
