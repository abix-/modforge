//! `FDamageInfo` reader -- the canonical UE5 damage-event payload
//! that lives at a known offset on most game-side HealthComponents.
//!
//! Every game extends UE's damage system with its own
//! `FDamageInfo`-shaped struct. The fields and offsets vary, but
//! the **shape** is universal: a fixed-offset struct on the
//! HealthComponent (or equivalent) that the engine populates with
//! the current damage event's metadata before firing the
//! multicast / apply UFunctions.
//!
//! Game crates configure the offsets once via [`DamageInfoLayout`]
//! and call its read methods from their kill / damage hook. The
//! universal helpers below cover the four fields virtually every
//! UE5 RPG mod needs:
//!
//! - **Instigator controller** (`AController` -- the killer's
//!   controller, used to classify the killer).
//! - **Damage source** (`UObject` -- the damage-causing object,
//!   often the same as the instigator's pawn).
//! - **Damage-type class** (`UClass` of the
//!   `UDamageType` subtype, used to discriminate environmental /
//!   fall / fire / etc).
//! - **Damage flags** (`i32` -- bitfield, includes the killing-blow
//!   bit on most games).
//!
//! ```ignore
//! use ueforge::ue::damage_info::DamageInfoLayout;
//!
//! const G2_DAMAGE_INFO: DamageInfoLayout = DamageInfoLayout {
//!     last_damage_info_offset: 0x03B0,  // HC.LastDamageInfo
//!     instigator_offset: 0x0020,        // FDamageInfo.InstigatorController
//!     damage_source_offset: 0x0028,     // FDamageInfo.DamageSource
//!     damage_type_class_offset: 0x0040, // FDamageInfo.DamageTypeClass
//!     damage_flags_offset: 0x0070,      // FDamageInfo.DamageFlags
//! };
//!
//! let killer = G2_DAMAGE_INFO.instigator(hc);
//! let dt = G2_DAMAGE_INFO.damage_type_class(hc);
//! ```

use crate::ue::{FWeakObjectPtr, UClass, UObject};

/// Per-game offsets for the `FDamageInfo` struct on a damage
/// component (typically `UHealthComponent`). All offsets are
/// **byte offsets within the component**, not relative to the
/// damage-info struct -- so each is `last_damage_info_offset +
/// <field_offset_in_struct>`.
#[derive(Debug, Clone, Copy)]
pub struct DamageInfoLayout {
    /// Byte offset of the `FDamageInfo` struct on the component.
    /// (E.g. Maine `UHealthComponent.LastDamageInfo` at `0x03B0`.)
    /// Kept for documentation; the four field offsets below are
    /// already absolute (component-relative).
    pub last_damage_info_offset: usize,
    /// Absolute offset of `InstigatorController` (TWeakObjectPtr).
    pub instigator_offset: usize,
    /// Absolute offset of `DamageSource` (TWeakObjectPtr).
    pub damage_source_offset: usize,
    /// Absolute offset of the damage-type `UClass` pointer.
    pub damage_type_class_offset: usize,
    /// Absolute offset of the damage-flags `i32`.
    pub damage_flags_offset: usize,
}

impl DamageInfoLayout {
    /// Resolve the `InstigatorController` from this damage event.
    pub fn instigator(&self, component: &UObject) -> Option<&'static UObject> {
        FWeakObjectPtr::read(component, self.instigator_offset).resolve()
    }

    /// Resolve the `DamageSource` from this damage event.
    pub fn damage_source(&self, component: &UObject) -> Option<&'static UObject> {
        FWeakObjectPtr::read(component, self.damage_source_offset).resolve()
    }

    /// Read the `DamageTypeClass` raw `*mut UClass` and return a
    /// `&'static UClass` if non-null. Class names are stable, so
    /// callers typically just do `.as_object().name().contains("...")`.
    pub fn damage_type_class(&self, component: &UObject) -> Option<&'static UClass> {
        unsafe {
            let cls: *mut UClass = component
                .field_ptr(self.damage_type_class_offset)
                .cast::<*mut UClass>()
                .read_unaligned();
            cls.as_ref()
        }
    }

    /// Damage-type class **name** (or empty string if null).
    /// Cheaper than fetching the class when you only need a name
    /// substring match.
    pub fn damage_type_name(&self, component: &UObject) -> String {
        self.damage_type_class(component)
            .map(|c| c.as_object().name())
            .unwrap_or_default()
    }

    /// Read the damage-flags `i32`.
    pub fn damage_flags(&self, component: &UObject) -> i32 {
        unsafe {
            component
                .field_ptr(self.damage_flags_offset)
                .cast::<i32>()
                .read_unaligned()
        }
    }
}
