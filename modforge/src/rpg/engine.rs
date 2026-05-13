//! Engine plug-in trait.
//!
//! `modforge::rpg` is engine-agnostic. Every type that needs to
//! observe engine-specific events (`Effect<E>`, `TriggerCtx<E>`,
//! `Tracker<E>`) is parametric over an implementor of this
//! trait. Each framework crate ships a zero-sized type
//! implementing `Engine` plus a per-engine `Event<'a>` enum
//! holding the borrowed event payloads.
//!
//! ```ignore
//! // ueforge
//! pub struct UeEngine;
//! impl modforge::rpg::Engine for UeEngine {
//!     type Event<'a> = UeEvent<'a>;
//!     fn event_kind<'a>(e: &Self::Event<'a>) -> &'static str {
//!         match e {
//!             UeEvent::Kill(_) => "OnKill",
//!             UeEvent::Fall(_) => "OnFall",
//!             ...
//!         }
//!     }
//! }
//!
//! pub enum UeEvent<'a> {
//!     Kill(&'a KillEvent<'a>),
//!     Fall(&'a FallEvent<'a>),
//!     ...
//! }
//! ```

pub trait Engine: Send + Sync + 'static {
    /// Engine-specific event payload. The borrow lifetime ties
    /// the event to the [`crate::rpg::TriggerCtx`] that wraps
    /// it, so events can carry references to live engine state
    /// without static lifetimes.
    type Event<'a>;

    /// Stable kind tag for an event. Catalog rows declare which
    /// trigger kind they subscribe to via
    /// [`crate::rpg::TriggerDef::kind`]; the tracker matches by
    /// string so the dispatch path is generic over the engine's
    /// concrete enum.
    fn event_kind<'a>(event: &Self::Event<'a>) -> &'static str;
}
