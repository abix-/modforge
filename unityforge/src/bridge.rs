//! Function-pointer bridge between the C# shim and Rust.
//!
//! The shim's `Awake` calls `unityforge_init(*const BridgeTable)`
//! once at startup, passing a packed struct of `extern "C" fn`
//! pointers. Rust stashes it in a `OnceLock<BridgeTable>` and
//! every subsequent Mono / Harmony call routes through it.
//!
//! The struct layout MUST exactly match the C# `[StructLayout
//! (LayoutKind.Sequential)]` `BridgeTable` in
//! `cs-shim/Bridge.cs`. Add fields at the END only; never
//! reorder.
//!
//! ABI versioning: the first two fields are a magic number and
//! a version. The shim and Rust check both at init. A mismatch
//! returns an error to the shim and refuses to start, which
//! beats a silent corruption.

use std::ffi::c_void;
use std::os::raw::c_char;
use std::sync::OnceLock;

/// Magic number identifying a unityforge bridge. ASCII "UFBR" in
/// little-endian. The shim writes this; Rust verifies it.
pub const BRIDGE_MAGIC: u32 = 0x52424655;

/// Current ABI version. Bump when the BridgeTable layout
/// changes incompatibly. The shim writes its compile-time
/// version; Rust refuses to init if they don't match.
pub const BRIDGE_VERSION: u32 = 1;

/// One opaque managed-object handle. Identifies a Mono Type /
/// Object / Field / Method. The shim keeps the actual managed
/// reference in a `Dictionary<int, object>`; Rust only sees the
/// integer cookie. 0 means "null / invalid".
#[repr(transparent)]
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub struct MonoHandle(pub i32);

impl MonoHandle {
    pub const NULL: Self = Self(0);
    pub fn is_null(self) -> bool {
        self.0 == 0
    }
}

/// One Harmony patch handle. Returned by `harmony_patch`; passed
/// back to `harmony_unpatch`.
#[repr(transparent)]
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub struct PatchHandle(pub i32);

/// The packed function-pointer table. Layout matches the C#
/// `[StructLayout(LayoutKind.Sequential)] BridgeTable`.
#[repr(C)]
#[derive(Clone, Copy)]
pub struct BridgeTable {
    /// Sanity / magic. Must equal BRIDGE_MAGIC.
    pub magic: u32,
    /// ABI version. Must equal BRIDGE_VERSION.
    pub version: u32,

    // ---- logging ---------------------------------------------------------
    /// Log a line. `level` is one of: 0=trace, 1=debug, 2=info,
    /// 3=warn, 4=error. `msg_utf8` is a null-terminated UTF-8
    /// string; the shim copies it into BepInEx's log sink.
    pub log_emit: extern "C" fn(level: i32, msg_utf8: *const c_char),

    // ---- mono reflection -------------------------------------------------
    /// Find a Mono Type by fully-qualified name
    /// (`"PlayerManager"`, `"UnityEngine.GameObject"`).
    /// Returns NULL on miss.
    pub mono_find_type: extern "C" fn(name_utf8: *const c_char) -> MonoHandle,

    /// Find the live instance returned by `Singleton<T>.Instance`
    /// for the given Type. Returns NULL if T does not derive from
    /// the Singleton<T> template or the instance is null.
    pub mono_singleton_instance: extern "C" fn(type_handle: MonoHandle) -> MonoHandle,

    /// Find the live instance returned by
    /// `StaticInstance<T>.Instance`. Same semantics as
    /// `mono_singleton_instance` for the StaticInstance pattern.
    pub mono_static_instance: extern "C" fn(type_handle: MonoHandle) -> MonoHandle,

    /// Walk a class and return every live instance as a JSON
    /// array of `{ "handle": i32, "name": str }`. `out_json_utf8`
    /// is a buffer the shim writes a NUL-terminated UTF-8 JSON
    /// string into; `cap` is its size. Returns bytes written
    /// (not counting NUL), or -1 if cap was too small.
    pub mono_walk_class: extern "C" fn(
        type_handle: MonoHandle,
        include_inactive: i32,
        out_json_utf8: *mut c_char,
        cap: i32,
    ) -> i32,

    /// Dump an object's fields + property values as JSON.
    /// Same `out_json_utf8` / `cap` shape as `mono_walk_class`.
    pub mono_inspect_object:
        extern "C" fn(obj: MonoHandle, out_json_utf8: *mut c_char, cap: i32) -> i32,

    /// Read a typed field by name. The result kind is encoded in
    /// the JSON: `{"i32": 42}`, `{"f32": 3.14}`, `{"bool": true}`,
    /// `{"string": "..."}`, `{"object": {"handle": <int>,
    /// "type": "<name>"}}`. Returns -1 on field-not-found.
    pub mono_read_field: extern "C" fn(
        obj: MonoHandle,
        field_name_utf8: *const c_char,
        out_json_utf8: *mut c_char,
        cap: i32,
    ) -> i32,

    /// Write a field. `value_json_utf8` is a null-terminated UTF-8
    /// JSON document matching the read-field encoding above.
    /// Returns 0 on success, -1 on type mismatch, -2 on
    /// field-not-found.
    pub mono_write_field: extern "C" fn(
        obj: MonoHandle,
        field_name_utf8: *const c_char,
        value_json_utf8: *const c_char,
    ) -> i32,

    /// Invoke a method by name. `args_json_utf8` is a JSON array
    /// of argument values (each in the same encoding as
    /// read/write field). `out_json_utf8` receives the boxed
    /// return value. Returns 0 on success, -1 on method-not-
    /// found, -2 on arg-mismatch, -3 on exception (with the
    /// exception message written to out_json_utf8 as
    /// `{"error": "..."}`).
    pub mono_invoke_method: extern "C" fn(
        obj: MonoHandle,
        method_name_utf8: *const c_char,
        args_json_utf8: *const c_char,
        out_json_utf8: *mut c_char,
        cap: i32,
    ) -> i32,

    /// Release a handle (`Dictionary.Remove`). Idempotent; safe
    /// to call on a null handle. Rust calls this from Drop of
    /// its idiomatic wrappers.
    pub mono_release_handle: extern "C" fn(handle: MonoHandle),

    // ---- harmony ---------------------------------------------------------
    /// Patch a prefix on `type::method`. `prefix_fn` is an
    /// `extern "C" fn(*const c_void) -> i32`; the shim wraps it
    /// in a managed delegate via
    /// `Marshal.GetDelegateForFunctionPointer` and passes that to
    /// `harmony.Patch(prefix: HarmonyMethod(...))`. Returns a
    /// PatchHandle (0 on failure).
    pub harmony_patch_prefix: extern "C" fn(
        type_name_utf8: *const c_char,
        method_name_utf8: *const c_char,
        prefix_fn: extern "C" fn(*const c_void) -> i32,
    ) -> PatchHandle,

    /// Patch a postfix. Same shape as prefix.
    pub harmony_patch_postfix: extern "C" fn(
        type_name_utf8: *const c_char,
        method_name_utf8: *const c_char,
        postfix_fn: extern "C" fn(*const c_void),
    ) -> PatchHandle,

    /// Remove a Harmony patch. Idempotent.
    pub harmony_unpatch: extern "C" fn(patch: PatchHandle),
}

static BRIDGE: OnceLock<BridgeTable> = OnceLock::new();

/// Install the bridge table (called from the C# shim via
/// `unityforge_init`). Verifies magic + version; refuses on
/// mismatch (returns false). Idempotent: only the first call
/// installs.
pub fn install(bridge: &BridgeTable) -> bool {
    if bridge.magic != BRIDGE_MAGIC {
        return false;
    }
    if bridge.version != BRIDGE_VERSION {
        return false;
    }
    BRIDGE.set(*bridge).is_ok() || BRIDGE.get().is_some()
}

/// Get the installed bridge table. Returns None before
/// `install` succeeds (i.e. before the shim has called
/// `unityforge_init`).
pub fn get() -> Option<&'static BridgeTable> {
    BRIDGE.get()
}

/// Convenience: get the bridge or return an error message
/// suitable for op handlers.
pub fn try_get() -> Result<&'static BridgeTable, String> {
    BRIDGE
        .get()
        .ok_or_else(|| "unityforge: bridge not installed (shim init failed)".to_string())
}
