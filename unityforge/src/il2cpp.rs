//! IL2CPP-only escape hatches.
//!
//! Most code should reach for [`crate::unity`] instead. This
//! module is for IL2CPP-specific quirks (e.g.
//! `Il2CppObjectBase` lifetime handling) that the
//! backend-agnostic SDK can't paper over.
//!
//! Stub for now; populate as IL2CPP consumers surface specific
//! needs.

use crate::bridge::{RuntimeKind, runtime_kind};

/// `true` when the loaded shim is the IL2CPP variant.
pub fn is_active() -> bool {
    runtime_kind() == Some(RuntimeKind::Il2Cpp)
}
