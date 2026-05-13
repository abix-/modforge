//! Unity save-slot key resolver.
//!
//! Most Unity RPG games store a stable per-playthrough id on a
//! singleton class (typically a save-system MonoBehaviour). The
//! pattern:
//!
//! 1. Find the singleton instance of class `X`.
//! 2. Read field `Y` (string or int) on it.
//! 3. Format as a filename-safe slot key.
//!
//! Game crates configure once and plug a closure into the
//! engine-agnostic [`modforge::rpg::poller::SlotPoller`].
//!
//! ```ignore
//! static SLOT_KEY: UnitySlotKey =
//!     UnitySlotKey::new("GameSerializationSystem",
//!                       "_currentLoadedSaveNumber");
//!
//! modforge::rpg::poller::SlotPoller::spawn(
//!     Duration::from_secs(1),
//!     || SLOT_KEY.resolve(),
//!     |slot| TRACKER.activate_slot(slot),
//!     || TRACKER.deactivate_slot(),
//! );
//! ```

use crate::mono::MonoType;

pub struct UnitySlotKey {
    class_name: &'static str,
    field_name: &'static str,
}

impl UnitySlotKey {
    pub const fn new(class_name: &'static str, field_name: &'static str) -> Self {
        Self {
            class_name,
            field_name,
        }
    }

    /// Resolve the current slot key. Returns None when the type
    /// isn't loaded yet, no singleton instance exists (main
    /// menu / between saves), or the field value is missing or
    /// empty.
    pub fn resolve(&self) -> Option<String> {
        let ty = MonoType::find(self.class_name)?;
        let obj = ty.singleton_instance()?;
        let value = obj.read_field(self.field_name).ok()?;
        format_slot(&value)
    }
}

fn format_slot(value: &serde_json::Value) -> Option<String> {
    if let Some(s) = value.as_str() {
        if s.is_empty() {
            None
        } else {
            Some(sanitize(s))
        }
    } else if let Some(n) = value.as_i64() {
        Some(format!("{n}"))
    } else if let Some(n) = value.as_u64() {
        Some(format!("{n}"))
    } else {
        None
    }
}

fn sanitize(s: &str) -> String {
    s.chars()
        .map(|c| match c {
            '/' | '\\' | ':' | '\0' | '?' | '*' | '"' | '<' | '>' | '|' => '_',
            c => c,
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;
    use serde_json::json;

    #[test]
    fn const_constructible() {
        const _R: UnitySlotKey = UnitySlotKey::new("Foo", "Bar");
    }

    #[test]
    fn format_string_slot() {
        assert_eq!(format_slot(&json!("abc")), Some("abc".to_string()));
    }

    #[test]
    fn format_empty_string_is_none() {
        assert_eq!(format_slot(&json!("")), None);
    }

    #[test]
    fn format_int_slot() {
        assert_eq!(format_slot(&json!(42)), Some("42".to_string()));
    }

    #[test]
    fn format_null_is_none() {
        assert_eq!(format_slot(&json!(null)), None);
    }

    #[test]
    fn sanitize_strips_separators() {
        assert_eq!(sanitize("a/b\\c:d"), "a_b_c_d");
    }
}
