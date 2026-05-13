//! `ProjectionSnapshot` generics. The framework-agnostic shape
//! per the plan's Phase 0b row 20.
//!
//! No concrete projection types live here yet; they're added
//! when a consumer needs them. The shape (typed snapshot trait
//! + dirty-bit tracking + JSON serialization helpers) will
//! land alongside the first consumer.
//!
//! See [`docs/unityforge-plan.md`](../../../docs/unityforge-plan.md)
//! section "What's deferred" for rationale.
