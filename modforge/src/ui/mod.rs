//! Engine-agnostic UI declarative shape.
//!
//! Game mods describe their UI tabs declaratively. Each engine
//! framework renders them with whatever ImGui binding it ships
//! (UE4SS via C++ shim for ueforge, an in-process ImGui or
//! Unity OnGUI for unityforge).
//!
//! ```ignore
//! pub static MOD_INFO: ModDef = ModDef {
//!     name: "MyMod",
//!     // ...
//!     tabs: &[
//!         TabDef { name: "RPG",      render: render_rpg },
//!         TabDef { name: "Debug",    render: render_debug },
//!     ],
//! };
//! ```
//!
//! Rendering implementations stay engine-specific; only the
//! declarative shape is shared.

/// One UI tab declaration. The renderer is a bare `fn()` (no
/// captures, no state) so the struct is `Copy`-able and can
/// live in a `'static` slice.
pub struct TabDef {
    pub name: &'static str,
    pub render: fn(),
}

#[cfg(feature = "overlay-ui")]
pub mod overlay;
