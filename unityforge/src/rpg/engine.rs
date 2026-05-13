//! Unity engine plug-in for [`modforge::rpg::Engine`].

use modforge::rpg::Engine;

/// Zero-sized type implementing [`modforge::rpg::Engine`] for
/// Unity. Same `UnityEngine` handles both runtime backends
/// (Mono and IL2CPP); the bridge populated at init dispatches
/// to the right implementation under the hood.
pub struct UnityEngine;

impl Engine for UnityEngine {
    type Event<'a> = UnityEvent<'a>;

    fn event_kind<'a>(event: &Self::Event<'a>) -> &'static str {
        match event {
            UnityEvent::HarmonyPre { .. } => "OnHarmonyPre",
            UnityEvent::HarmonyPost { .. } => "OnHarmonyPost",
            UnityEvent::UnityEvent { .. } => "OnUnityEvent",
        }
    }
}

/// Unity event payload variants. Effects pattern-match on the
/// variant they care about. The `kind` string in
/// [`Engine::event_kind`] is what catalog rows declare in their
/// `TriggerDef`.
pub enum UnityEvent<'a> {
    /// Fired before a Harmony-patched method runs. `class` and
    /// `method` are stable identifiers; `args_json` is the
    /// argument list serialized by the shim.
    HarmonyPre {
        class: &'a str,
        method: &'a str,
        args_json: &'a str,
    },
    /// Fired after a Harmony-patched method runs.
    HarmonyPost {
        class: &'a str,
        method: &'a str,
        args_json: &'a str,
        result_json: &'a str,
    },
    /// Fired when a game's `static event Action` fires (after
    /// the mod subscribed via the shim's event-add helper).
    UnityEvent {
        source: &'a str,
        payload_json: &'a str,
    },
}
