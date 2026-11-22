//! Hide chosen bones of a skinned mesh while bones below them stay
//! shown. Asked 2026-11-22: "i want to hide some bones and show other
//! bones. and some chidlren should stay visible", "we need all the
//! framework changes necessary. DRY".
//!
//! The engine's own HideBoneByName (mesh_parts::bone) cannot do this:
//! it hides the bone and every bone below it, and a child shown again is
//! marked hidden by its parent on the next update (engine
//! SkinnedMeshComponent.cpp UnHideBone's comment). But the renderer
//! builds each bone's skin matrix from that bone's own component space
//! transform, one bone at a time (engine SkeletalRender.cpp
//! UpdateRefToLocalMatrices; a hidden bone there is its parent's
//! transform scaled to 0). So a bone whose component space transform has
//! scale 0 draws nothing, and its children, whose component space
//! transforms are already worked out, draw where the animation put them.
//!
//! When: every frame the animation is evaluated, the engine calls the
//! anim instance's PostEvaluateAnimation, which calls the Blueprint event
//! BlueprintPostEvaluateAnimation through ProcessEvent (engine
//! AnimInstance.cpp), on the game thread, before the component flips its
//! two component space buffers and sends the new one to the renderer
//! (SkeletalMeshComponent.cpp PostAnimEvaluation, then
//! SkinnedMeshComponent.cpp FinalizeBoneTransform). A ProcessEvent hook
//! on the anim instance's function table zeroes the bones' scale there.
//!
//! Where: USkinnedMeshComponent's ComponentSpaceTransformsArray[2], two
//! TArray<FTransform> side by side, each with one transform per bone
//! (measured on Wicked Island 5.6 at +0x5F0 and +0x600 of the Minotaur's
//! body, tests/research_parts.rs pose_buffers, 2026-11-22), found by
//! shape in the component and kept. Both buffers get the zero: the one
//! being filled is what this frame draws; the other is filled anew
//! before it is drawn.
//!
//! Frames the engine only blends between two evaluated poses (update
//! rate optimisation) call no PostEvaluateAnimation, so while bones are
//! hidden the component's bEnableUpdateRateOptimizations is off (every
//! frame evaluated), put back when they are shown. Skin weighted partly
//! to a hidden bone is pulled toward the shown one.
//!
//! Ops: parts.hide_alone {component, bones: [str]} (an empty list shows
//! them all again), parts.hidden_alone {}.

use std::sync::atomic::{AtomicUsize, Ordering};

use parking_lot::Mutex;
use serde_json::{Value, json};

use crate::hook::ProcessEventHook;
use crate::ue::{UObject, find_class_fast};

/// One FTransform of doubles: rotation 0..32, translation 32..64 (with
/// padding), scale 64..88.
const TRANSFORM: usize = 96;
const SCALE: usize = 64;

struct Hide {
    component: usize,
    anim: usize,
    bones: Vec<(String, usize)>,
    /// bEnableUpdateRateOptimizations before, put back when cleared.
    uro_was: Option<bool>,
}

static HIDES: Mutex<Vec<Hide>> = Mutex::new(Vec::new());
/// Function tables already hooked.
static HOOKED: Mutex<Vec<usize>> = Mutex::new(Vec::new());
/// Offset of ComponentSpaceTransformsArray[0] in a skinned mesh
/// component; 0 until found.
static BUFFERS: AtomicUsize = AtomicUsize::new(0);
/// The UFunction BlueprintPostEvaluateAnimation; 0 until found.
static POST_EVALUATE: AtomicUsize = AtomicUsize::new(0);

use crate::anim_data::{read, readable};

/// A TArray<FTransform> at `addr` with `bones` entries whose first
/// rotation is a unit quaternion: its data pointer.
fn transform_array(addr: usize, bones: usize) -> Option<usize> {
    let data: usize = read(addr)?;
    let n: i32 = read(addr + 8)?;
    let max: i32 = read(addr + 12)?;
    if n as usize != bones || max < n || data < 0x1_0000 {
        return None;
    }
    if !readable(data, bones * TRANSFORM) {
        return None;
    }
    let q: Option<Vec<f64>> = (0..4).map(|i| read::<f64>(data + i * 8)).collect();
    let len = q?.iter().map(|v| v * v).sum::<f64>().sqrt();
    ((len - 1.0).abs() < 1e-3).then_some(data)
}

/// The offset of the two component space buffers in `c`, found once by
/// their shape: two transform arrays of `bones` entries side by side.
fn buffers(c: &UObject, bones: usize) -> Result<usize, String> {
    let base = c.as_ptr() as usize;
    let known = BUFFERS.load(Ordering::Acquire);
    if known != 0 {
        if transform_array(base + known, bones).is_some()
            && transform_array(base + known + 16, bones).is_some()
        {
            return Ok(known);
        }
        return Err(format!(
            "{}: no bone buffers at the known offset 0x{known:X}",
            c.name()
        ));
    }
    for o in (0x100..0x1000).step_by(8) {
        if transform_array(base + o, bones).is_some()
            && transform_array(base + o + 16, bones).is_some()
        {
            BUFFERS.store(o, Ordering::Release);
            crate::log!("pose_hide: bone buffers at +0x{o:X}");
            return Ok(o);
        }
    }
    Err(format!("{}: no bone buffers found", c.name()))
}

/// Scale 0 on each hidden bone in both buffers. Game thread, in the
/// anim instance's post evaluate.
fn zero(h: &Hide) {
    let off = BUFFERS.load(Ordering::Acquire);
    if off == 0 {
        return;
    }
    for b in 0..2 {
        let arr = h.component + off + b * 16;
        let (Some(data), Some(n)) = (read::<usize>(arr), read::<i32>(arr + 8)) else {
            continue;
        };
        for &(_, i) in &h.bones {
            if i >= n.max(0) as usize {
                continue;
            }
            let s = data + i * TRANSFORM + SCALE;
            if !readable(s, 24) {
                continue;
            }
            // SAFETY: inside the component's live transform array,
            // checked readable; the engine writes it on this thread.
            unsafe { std::ptr::write_bytes(s as *mut u8, 0, 24) };
        }
    }
}

/// Hook the function table of `anim` (once per table).
fn hook(anim: &UObject) -> Result<(), String> {
    if POST_EVALUATE.load(Ordering::Acquire) == 0 {
        let f = crate::hook::function_ptr("AnimInstance", "BlueprintPostEvaluateAnimation")
            .ok_or("AnimInstance::BlueprintPostEvaluateAnimation not found")?;
        POST_EVALUATE.store(f, Ordering::Release);
    }
    // SAFETY: a live object's first word is its function table.
    let table = unsafe { *(anim.as_ptr() as *const usize) };
    let mut hooked = HOOKED.lock();
    if hooked.contains(&table) {
        return Ok(());
    }
    let h =
        ProcessEventHook::install_for_object("AnimInstance", anim, |this, f, parms, original| {
            // SAFETY: the engine's own call passed on unchanged.
            unsafe { original.call(this, f, parms) };
            if f as *const _ as usize != POST_EVALUATE.load(Ordering::Relaxed) {
                return;
            }
            let key = this as *const UObject as usize;
            let hides = HIDES.lock();
            for h in hides.iter().filter(|h| h.anim == key) {
                // The anim instance's outer is its component; a freed
                // address reused by another anim instance is skipped.
                if this.outer().map(|o| o as *const UObject as usize) == Some(h.component) {
                    zero(h);
                }
            }
        })
        .map_err(|e| format!("hook {}: {e}", anim.name()))?;
    crate::hook::register(h);
    hooked.push(table);
    crate::log!("pose_hide: hooked {} (table 0x{table:X})", anim.name());
    Ok(())
}

fn call(o: &UObject, class: &str, function: &str, params: Value) -> Result<Value, String> {
    let params = params.as_object().cloned().unwrap_or_default();
    // SAFETY: callers are on the game thread with `o` live.
    unsafe { crate::reflect::call(o, class, function, &params) }
}

/// Hide `bones` of skeletal mesh `c` while every other bone, children
/// included, stays as animated; an empty list shows them all again.
/// Game thread.
pub fn set(c: &UObject, bones: &[String]) -> Result<Value, String> {
    let key = c as *const UObject as usize;
    let old = {
        let mut hides = HIDES.lock();
        let i = hides.iter().position(|h| h.component == key);
        i.map(|i| hides.remove(i))
    };
    // The update rate setting as it was before any hiding.
    let uro_was = match &old {
        Some(h) => h.uro_was,
        None => uro(c),
    };
    if bones.is_empty() {
        if let Some(was) = old.and_then(|h| h.uro_was) {
            set_uro(c, was);
        }
        return Ok(json!({"component": format!("0x{key:X}"), "hidden": []}));
    }
    if !find_class_fast("SkeletalMeshComponent").is_some_and(|k| c.is_a(k)) {
        return Err(format!("{} is not a skeletal mesh", c.name()));
    }
    let count = call(c, "SkinnedMeshComponent", "GetNumBones", json!({}))?["ReturnValue"]
        .as_i64()
        .unwrap_or(0) as usize;
    let mut found = Vec::new();
    for b in bones {
        let i = call(
            c,
            "SkinnedMeshComponent",
            "GetBoneIndex",
            json!({"BoneName": b}),
        )?["ReturnValue"]
            .as_i64()
            .unwrap_or(-1);
        if i < 0 || i as usize >= count {
            return Err(format!("{}: no bone {b}", c.name()));
        }
        found.push((b.clone(), i as usize));
    }
    buffers(c, count)?;
    let anim = call(c, "SkeletalMeshComponent", "GetAnimInstance", json!({}))?;
    let anim = anim["ReturnValue"]["addr"]
        .as_str()
        .ok_or_else(|| format!("{}: no anim instance", c.name()))?;
    let anim = crate::selector::resolve(&format!("addr:{anim}"))?;
    hook(anim)?;
    // Every frame evaluated, so every frame runs PostEvaluateAnimation.
    set_uro(c, false);
    let out = json!({
        "component": format!("0x{key:X}"),
        "anim": anim.name(),
        "hidden": found.iter().map(|(n, i)| json!([n, i])).collect::<Vec<_>>(),
    });
    HIDES.lock().push(Hide {
        component: key,
        anim: anim as *const UObject as usize,
        bones: found,
        uro_was,
    });
    Ok(out)
}

const URO: &str = "bEnableUpdateRateOptimizations";

/// SkinnedMeshComponent.bEnableUpdateRateOptimizations now.
fn uro(c: &UObject) -> Option<bool> {
    // SAFETY: game thread, `c` live (callers').
    unsafe { crate::reflect::get_fields(c, &[URO.to_owned()]) }
        .ok()?
        .get(URO)?
        .as_bool()
}

fn set_uro(c: &UObject, on: bool) {
    let mut m = serde_json::Map::new();
    m.insert(URO.to_owned(), json!(on));
    // SAFETY: as in uro().
    if let Err(e) = unsafe { crate::reflect::set_fields(c, &m) } {
        crate::log!("pose_hide: {}: {URO}: {e}", c.name());
    }
}

/// Whether `c` can hide bones alone: a skeletal mesh posed by its own
/// anim instance. A mesh following another's pose (LeaderPoseComponent)
/// draws with its leader's bones, so hiding them on the leader hides
/// them on it too. Game thread.
pub fn posable(c: &UObject) -> bool {
    find_class_fast("SkeletalMeshComponent").is_some_and(|k| c.is_a(k))
        && call(c, "SkeletalMeshComponent", "GetAnimInstance", json!({}))
            .is_ok_and(|v| v["ReturnValue"]["addr"].is_string())
}

/// Drop the entry of a component that is gone.
pub fn forget(component: usize) {
    HIDES.lock().retain(|h| h.component != component);
}

/// The bones hidden alone on the component at `component` now.
pub fn bones_of(component: usize) -> Vec<String> {
    HIDES
        .lock()
        .iter()
        .find(|h| h.component == component)
        .map(|h| h.bones.iter().map(|(n, _)| n.clone()).collect())
        .unwrap_or_default()
}

/// Every component with bones hidden this way.
pub fn list() -> Value {
    let hides = HIDES.lock();
    json!(
        hides
            .iter()
            .map(|h| json!({
                "component": format!("0x{:X}", h.component),
                "bones": h.bones.iter().map(|(n, _)| n.as_str()).collect::<Vec<_>>(),
            }))
            .collect::<Vec<_>>()
    )
}

pub fn register_ops(drain: &'static crate::pe_queue::GameThread, hint: &'static str) {
    use crate::ops::OP_REGISTRY;
    use modforge::ops::OpDef;
    OP_REGISTRY.register_many([
        OpDef::new(
            "parts.hide_alone",
            "Hide bones of a skeletal mesh while the bones below them stay shown, every frame after the animation; an empty list shows them again",
            "{component: 0x addr, bones: [str]}",
            move |args| {
                let c = args["component"]
                    .as_str()
                    .ok_or("component: 0x address is required")?;
                let c = format!("addr:{c}");
                let bones: Vec<String> = args["bones"]
                    .as_array()
                    .ok_or("bones: [str] is required")?
                    .iter()
                    .filter_map(|b| b.as_str().map(str::to_owned))
                    .collect();
                crate::debug::enqueue_pe(drain, std::time::Duration::from_secs(10), hint, move || {
                    set(crate::selector::resolve(&c)?, &bones)
                })
            },
        ),
        OpDef::new(
            "parts.hidden_alone",
            "The components and bones parts.hide_alone hides now",
            "{}",
            |_| Ok(list()),
        ),
    ]);
}
