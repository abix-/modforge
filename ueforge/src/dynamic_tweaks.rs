//! Settings-driven data-table tweaks. Generic framework consumed
//! by every game mod via a `Vec<DynamicTweak>` field on its own
//! settings struct. Resolution is name-based -- the discovery
//! cache supplies offsets at apply time, so new entries land with
//! no recompile + no SDK header dive.
//!
//! ```text
//! K8s slot: Def=DynamicTweak (settings-supplied; no compile-time
//!                             registry -- carve-out like Settings),
//!           Registry=n/a (consumers pass their own slice),
//!           Instance=per-(table,field) FieldTweak<T> in the
//!                    ueforge::data_table dynamic registry,
//!           Controller=apply_all / apply_one / revert_all
//! ```
//!
//! Each `DynamicTweak` carries `{ id, table, field, kind, value,
//! skip_below?, enabled }`. `kind` selects the primitive
//! decoder; today's set: `i32_mul`, `u32_mul`, `f32_mul`. Adding a
//! new kind = one match arm + (if a new T) a new registry in
//! `data_table::dynamic_apply_*`.
//!
//! ```jsonc
//! // <game>/settings.json (game crate decides the outer shape):
//! {
//!   "dynamic_tweaks": [
//!     { "id": "stacks_x4", "table": "DT_Materials",
//!       "field": "MaxCanStack", "kind": "i32_mul",
//!       "value": 4.0, "skip_below": 2.0 }
//!   ]
//! }
//! ```
//!
//! Game crate calls `ueforge::dynamic_tweaks::apply_all(&s.dynamic_tweaks)`
//! from its `on_unreal_init` worker (after `discovery::run_at_load`).
//! The shared ImGui widget `ueforge::ui_dynamic_tweaks::render`
//! consumes the same slice + drives re-apply / revert / refresh.

use std::sync::Mutex;
use std::sync::atomic::{AtomicUsize, Ordering};

use serde::{Deserialize, Serialize};

/// One settings-driven data-table tweak. Resolved against the
/// `ueforge::discovery` cache on apply; rows whose vanilla value
/// is strictly less than `skip_below` are left untouched.
#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct DynamicTweak {
    pub id: String,
    pub table: String,
    pub field: String,
    pub kind: String,
    pub value: f64,
    #[serde(default)]
    pub skip_below: Option<f64>,
    #[serde(default = "default_enabled")]
    pub enabled: bool,
}

fn default_enabled() -> bool {
    true
}

/// Per-entry outcome of the last `apply_all` call.
#[derive(Debug, Clone)]
pub struct TweakStatus {
    pub id: String,
    pub table: String,
    pub field: String,
    pub kind: String,
    pub value: f64,
    pub last_result: Result<usize, String>,
}

static LAST_STATUS: Mutex<Vec<TweakStatus>> = Mutex::new(Vec::new());
static APPLY_COUNT: AtomicUsize = AtomicUsize::new(0);

/// Apply every enabled tweak from `tweaks`. Caller (game crate)
/// supplies the slice -- typically from its own
/// `Settings<T>.dynamic_tweaks` field.
///
/// Requires `ueforge::discovery::run_at_load()` (or any
/// `discovery::refresh`) to have populated the cache.
///
/// Returns one [`TweakStatus`] per attempted entry. Skipped
/// (disabled) entries are omitted.
pub fn apply_all(tweaks: &[DynamicTweak]) -> Vec<TweakStatus> {
    let mut out: Vec<TweakStatus> = Vec::with_capacity(tweaks.len());
    for entry in tweaks {
        if !entry.enabled {
            continue;
        }
        let result = apply_one(entry);
        match &result {
            Ok(n) => crate::log::log(format_args!(
                "dynamic_tweaks: '{}' applied to {n} rows ({}.{}, {}={})",
                entry.id, entry.table, entry.field, entry.kind, entry.value
            )),
            Err(e) => crate::log::log(format_args!(
                "dynamic_tweaks: '{}' failed ({}.{}): {e}",
                entry.id, entry.table, entry.field
            )),
        }
        out.push(TweakStatus {
            id: entry.id.clone(),
            table: entry.table.clone(),
            field: entry.field.clone(),
            kind: entry.kind.clone(),
            value: entry.value,
            last_result: result,
        });
    }
    APPLY_COUNT.fetch_add(1, Ordering::Relaxed);
    *LAST_STATUS.lock().expect("LAST_STATUS poisoned") = out.clone();
    out
}

/// Apply one tweak. Returns the row-count touched on success.
pub fn apply_one(entry: &DynamicTweak) -> Result<usize, String> {
    let table = entry.table.as_str();
    let field = entry.field.as_str();
    let skip_below = entry.skip_below;
    match entry.kind.as_str() {
        "i32_mul" => {
            let m = entry.value as i32;
            let threshold = skip_below.map(|v| v as i32);
            crate::data_table::dynamic_apply_i32(
                table,
                field,
                move |v| v.saturating_mul(m),
                move |v| threshold.is_some_and(|t| v < t),
            )
        }
        "u32_mul" => {
            let m = entry.value as u32;
            let threshold = skip_below.map(|v| v as u32);
            crate::data_table::dynamic_apply_u32(
                table,
                field,
                move |v| v.saturating_mul(m),
                move |v| threshold.is_some_and(|t| v < t),
            )
        }
        "f32_mul" => {
            let m = entry.value as f32;
            let threshold = skip_below.map(|v| v as f32);
            crate::data_table::dynamic_apply_f32(
                table,
                field,
                move |v| v * m,
                move |v| threshold.is_some_and(|t| v < t),
            )
        }
        other => Err(format!(
            "unknown kind '{other}' (i32_mul / u32_mul / f32_mul)"
        )),
    }
}

/// Most recent per-entry status from [`apply_all`]. Used by the
/// shared ImGui widget; the game crate can read it too.
pub fn last_status() -> Vec<TweakStatus> {
    LAST_STATUS
        .lock()
        .expect("LAST_STATUS poisoned")
        .clone()
}

pub fn apply_count() -> usize {
    APPLY_COUNT.load(Ordering::Relaxed)
}

/// Revert every dynamic tweak captured so far. Delegates to
/// `data_table::dynamic_revert_all` and logs the row count.
pub fn revert_all() -> usize {
    let n = crate::data_table::dynamic_revert_all();
    crate::log::log(format_args!(
        "dynamic_tweaks: reverted {n} rows across all entries"
    ));
    n
}
