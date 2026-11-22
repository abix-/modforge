//! The mesh parts of the actors near the player: list them, hide or
//! show a whole mesh or one material slot of it, and scale a mesh.
//! Every step is an engine function called through reflection
//! (reflect::call, which refuses a function of a class the object is
//! not), on the game thread, so nothing here reads engine memory by
//! offset. Prior art: UEVR's pawn library (github jbusfield/uevrlib
//! libs/pawn.lua) hides body meshes with SetHiddenInGame and arms with
//! HideBoneByName.
//!
//! Nothing is saved: hiding, showing and scale live on the component
//! until the actor unloads.
//!
//! Ops (register_ops):
//! - parts.list {class, max_distance?}: actors of `class` within
//!   max_distance (cm) of the player, nearest first, each with its mesh
//!   components and their material slots.
//! - parts.hide {component, hidden}: SceneComponent::SetHiddenInGame.
//! - parts.slot {component, slot, show}: one material slot of a skinned
//!   mesh, by SkinnedMeshComponent::ShowMaterialSection on every LOD.
//! - parts.scale {component, scale}: SceneComponent::SetRelativeScale3D,
//!   the same factor on all three axes.
//! - parts.morph {component, name, value}: one morph target of a
//!   skeletal mesh, SkeletalMeshComponent::SetMorphTarget.
//! - parts.size {actor, scale}: the whole actor, Actor::SetActorScale3D.
//!   With hold_size_through, a script that puts a component back at a
//!   stored world transform keeps the size.
//! - parts.bones {component}: a skinned mesh's bones with parent and
//!   hidden.
//! - parts.bone {component, bone, hidden}: HideBoneByName or
//!   UnHideBoneByName, the bone and every bone below it.

use crate::reflect;
use crate::ue::{UObject, actor, find_class_fast};
use serde_json::{Value, json};

fn hex(o: &UObject) -> String {
    format!("0x{:X}", o as *const UObject as usize)
}

/// SAFETY of callers: game thread, `o` live.
unsafe fn call(o: &UObject, class: &str, function: &str, params: Value) -> Result<Value, String> {
    let params = params.as_object().cloned().unwrap_or_default();
    // SAFETY: the caller's.
    unsafe { reflect::call(o, class, function, &params) }
}

fn vector(v: &Value) -> Option<(f64, f64, f64)> {
    Some((v["X"].as_f64()?, v["Y"].as_f64()?, v["Z"].as_f64()?))
}

fn is(o: &UObject, class: &str) -> bool {
    find_class_fast(class).is_some_and(|c| o.is_a(c))
}

/// The player's pawn, through GameplayStatics::GetPlayerPawn.
///
/// # Safety
/// Game thread.
pub unsafe fn player_pawn() -> Result<&'static UObject, String> {
    let ctx = actor::any_world_actor().ok_or("no level loaded")?;
    let statics = crate::selector::resolve("singleton:GameplayStatics")?;
    // SAFETY: game thread; the context is a live level actor.
    let r = unsafe {
        call(
            statics,
            "GameplayStatics",
            "GetPlayerPawn",
            json!({"WorldContextObject": format!("0x{:X}", ctx as usize), "PlayerIndex": 0}),
        )?
    };
    let addr = r["ReturnValue"]["addr"]
        .as_str()
        .and_then(|s| usize::from_str_radix(s.trim_start_matches("0x"), 16).ok())
        .ok_or("no player pawn")?;
    crate::selector::resolve(&format!("addr:0x{addr:X}"))
}

/// One mesh component: what it is, whether it shows, its scale, its
/// mesh asset and its material slots.
///
/// # Safety
/// Game thread, `c` live.
pub unsafe fn describe(c: &UObject) -> Value {
    // SAFETY: the caller's, for every call below.
    unsafe {
        let class = c.class().map(|k| k.as_object().name()).unwrap_or_default();
        let visible = call(c, "SceneComponent", "IsVisible", json!({}))
            .map(|v| v["ReturnValue"].clone())
            .unwrap_or(Value::Null);
        let fields = reflect::get_fields(c, &["bHiddenInGame".into(), "RelativeScale3D".into()])
            .unwrap_or(Value::Null);
        let asset_field = if is(c, "SkinnedMeshComponent") {
            Some("SkinnedAsset")
        } else if is(c, "StaticMeshComponent") {
            Some("StaticMesh")
        } else {
            None
        };
        let asset = asset_field
            .and_then(|f| {
                reflect::get_fields(c, &[f.into()])
                    .ok()
                    .map(|v| v[f]["name"].clone())
            })
            .unwrap_or(Value::Null);
        let n = call(c, "PrimitiveComponent", "GetNumMaterials", json!({}))
            .ok()
            .and_then(|v| v["ReturnValue"].as_i64())
            .unwrap_or(0);
        let slots: Vec<Value> = (0..n)
            .map(|i| {
                call(
                    c,
                    "PrimitiveComponent",
                    "GetMaterial",
                    json!({"ElementIndex": i}),
                )
                .map(|v| v["ReturnValue"]["name"].clone())
                .unwrap_or(Value::Null)
            })
            .collect();
        json!({
            "component": hex(c),
            "name": c.name(),
            "class": class,
            "skinned": is(c, "SkinnedMeshComponent"),
            "asset": asset,
            "visible": visible,
            "hidden_in_game": fields["bHiddenInGame"],
            "scale": fields["RelativeScale3D"],
            "slots": slots,
            "morphs": morphs(c),
        })
    }
}

/// A skeletal mesh's morph targets with their current values, as
/// [name, value] pairs: the mesh asset's names
/// (SkeletalMesh::K2_GetAllMorphTargetNames), each read back through
/// SkeletalMeshComponent::GetMorphTarget. Empty for any other mesh.
///
/// # Safety
/// Game thread, `c` live.
unsafe fn morphs(c: &UObject) -> Value {
    if !is(c, "SkeletalMeshComponent") {
        return json!([]);
    }
    // SAFETY: the caller's, for every call below.
    unsafe {
        let Some(mesh) = reflect::get_fields(c, &["SkinnedAsset".into()])
            .ok()
            .and_then(|v| v["SkinnedAsset"]["addr"].as_str().map(str::to_owned))
            .and_then(|a| crate::selector::resolve(&format!("addr:{a}")).ok())
        else {
            return json!([]);
        };
        let names = call(mesh, "SkeletalMesh", "K2_GetAllMorphTargetNames", json!({}))
            .map(|v| v["ReturnValue"].as_array().cloned().unwrap_or_default())
            .unwrap_or_default();
        let pairs: Vec<Value> = names
            .into_iter()
            .map(|n| {
                let value = call(
                    c,
                    "SkeletalMeshComponent",
                    "GetMorphTarget",
                    json!({"MorphTargetName": n}),
                )
                .map(|v| v["ReturnValue"].clone())
                .unwrap_or(Value::Null);
                json!([n, value])
            })
            .collect();
        Value::Array(pairs)
    }
}

/// Set one morph target on a skeletal mesh
/// (SkeletalMeshComponent::SetMorphTarget). Values below 0 push the
/// shape the other way.
///
/// # Safety
/// Game thread.
pub unsafe fn morph(component: &UObject, name: &str, value: f64) -> Result<Value, String> {
    // SAFETY: the caller's.
    unsafe {
        call(
            component,
            "SkeletalMeshComponent",
            "SetMorphTarget",
            json!({"MorphTargetName": name, "Value": value, "bRemoveZeroWeight": false}),
        )?;
        let now = call(
            component,
            "SkeletalMeshComponent",
            "GetMorphTarget",
            json!({"MorphTargetName": name}),
        )?;
        Ok(
            json!({"component": hex(component), "morph": name, "set": value, "reads": now["ReturnValue"]}),
        )
    }
}

/// Actors of `class` within `max_distance` of the player, nearest
/// first, each with its mesh components.
///
/// # Safety
/// Game thread.
pub unsafe fn list(class: &str, max_distance: f64) -> Result<Value, String> {
    let uclass = find_class_fast(class).ok_or_else(|| format!("class {class} not loaded"))?;
    let mesh = find_class_fast("MeshComponent").ok_or("MeshComponent not loaded")?;
    // SAFETY: game thread, for every call below.
    unsafe {
        let pawn = player_pawn()?;
        let here = vector(&call(pawn, "Actor", "K2_GetActorLocation", json!({}))?["ReturnValue"])
            .ok_or("player location unreadable")?;
        let mut out = Vec::new();
        for a in actor::actors_of_class(pawn, uclass)? {
            let a = &*a;
            let Some(at) =
                vector(&call(a, "Actor", "K2_GetActorLocation", json!({}))?["ReturnValue"])
            else {
                continue;
            };
            let d = ((at.0 - here.0).powi(2) + (at.1 - here.1).powi(2) + (at.2 - here.2).powi(2))
                .sqrt();
            if d > max_distance {
                continue;
            }
            let parts: Vec<Value> = actor::components_by_class(a, mesh)?
                .into_iter()
                .map(|c| describe(&*c))
                .collect();
            let size = call(a, "Actor", "GetActorScale3D", json!({}))
                .map(|v| v["ReturnValue"]["X"].clone())
                .unwrap_or(Value::Null);
            out.push(json!({
                "actor": hex(a),
                "name": a.name(),
                "class": a.class().map(|k| k.as_object().name()).unwrap_or_default(),
                "distance": d,
                "size": size,
                "parts": parts,
            }));
        }
        out.sort_by(|x, y| {
            x["distance"]
                .as_f64()
                .partial_cmp(&y["distance"].as_f64())
                .unwrap_or(std::cmp::Ordering::Equal)
        });
        Ok(json!({"actors": out}))
    }
}

/// # Safety
/// Game thread.
pub unsafe fn hide(component: &UObject, hidden: bool) -> Result<Value, String> {
    // SAFETY: the caller's.
    unsafe {
        call(
            component,
            "SceneComponent",
            "SetHiddenInGame",
            json!({"NewHidden": hidden, "bPropagateToChildren": false}),
        )?;
        Ok(describe(component))
    }
}

/// One material slot on or off, on every LOD of a skinned mesh.
///
/// # Safety
/// Game thread.
pub unsafe fn slot(component: &UObject, slot: i64, show: bool) -> Result<Value, String> {
    // SAFETY: the caller's.
    unsafe {
        let lods = call(component, "SkinnedMeshComponent", "GetNumLODs", json!({}))?["ReturnValue"]
            .as_i64()
            .unwrap_or(1)
            .max(1);
        for lod in 0..lods {
            call(
                component,
                "SkinnedMeshComponent",
                "ShowMaterialSection",
                json!({"MaterialID": slot, "SectionIndex": slot, "bShow": show, "LODIndex": lod}),
            )?;
        }
        Ok(json!({"component": hex(component), "slot": slot, "show": show, "lods": lods}))
    }
}

/// # Safety
/// Game thread.
pub unsafe fn scale(component: &UObject, factor: f64) -> Result<Value, String> {
    // SAFETY: the caller's.
    unsafe {
        call(
            component,
            "SceneComponent",
            "SetRelativeScale3D",
            json!({"NewScale3D": {"X": factor, "Y": factor, "Z": factor}}),
        )?;
        Ok(describe(component))
    }
}

/// The whole actor's size, the same factor on all three axes
/// (Actor::SetActorScale3D), as the Onset client scales a character
/// (github OALM-Team/YRPF-Client character_api.lua:124). In Wicked
/// Island this holds where a body mesh's own scale is put back within
/// about 100 ms (wickedisland-mod tests/research_parts.rs actor_scale
/// and scale_reset_timing, 2026-11-21).
///
/// # Safety
/// Game thread.
pub unsafe fn actor_scale(a: &UObject, factor: f64) -> Result<Value, String> {
    // SAFETY: the caller's.
    unsafe {
        call(
            a,
            "Actor",
            "SetActorScale3D",
            json!({"NewScale3D": {"X": factor, "Y": factor, "Z": factor}}),
        )?;
        remember_size(a, factor);
        let now = call(a, "Actor", "GetActorScale3D", json!({}))?;
        Ok(json!({"actor": hex(a), "set": factor, "reads": now["ReturnValue"]["X"]}))
    }
}

/// Sizes set through [`actor_scale`], by actor address; 1.0 removes one.
static SIZES: parking_lot::Mutex<Vec<(usize, f64)>> = parking_lot::Mutex::new(Vec::new());
/// Script functions whose world-transform calls [`hold_size_through`]
/// scales by the actor's size.
static HOLD_CALLERS: parking_lot::Mutex<Vec<String>> = parking_lot::Mutex::new(Vec::new());

/// The bone [`hold_size_through`] keeps in place, by its chain's root.
static HOLD_ANCHOR: parking_lot::Mutex<Option<String>> = parking_lot::Mutex::new(None);
/// Bones on the other body a sized body is scaled around.
static HOLD_ENTRANCES: parking_lot::Mutex<Vec<String>> = parking_lot::Mutex::new(Vec::new());
/// The last component a held caller placed on an actor with no size: the
/// other body in the scene.
static PARTNER: std::sync::atomic::AtomicUsize = std::sync::atomic::AtomicUsize::new(0);
/// Per partner component, which of [`HOLD_ENTRANCES`] it has.
static PARTNER_ENTRANCES: parking_lot::Mutex<Vec<(usize, Vec<String>)>> =
    parking_lot::Mutex::new(Vec::new());

/// The entrance bones `c` has (SceneComponent::DoesSocketExist; a
/// skinned mesh's bones are sockets), looked up once per component.
///
/// # Safety
/// Game thread, `c` live.
unsafe fn entrances_on(c: &UObject) -> Vec<String> {
    let key = c as *const UObject as usize;
    if let Some((_, e)) = PARTNER_ENTRANCES.lock().iter().find(|(k, _)| *k == key) {
        return e.clone();
    }
    let wanted = HOLD_ENTRANCES.lock().clone();
    let found: Vec<String> = wanted
        .into_iter()
        .filter(|b| {
            // SAFETY: the caller's.
            unsafe {
                call(
                    c,
                    "SceneComponent",
                    "DoesSocketExist",
                    json!({"InSocketName": b}),
                )
            }
            .is_ok_and(|v| v["ReturnValue"] == json!(true))
        })
        .collect();
    crate::log!("parts: entrances on {}: {found:?}", c.name());
    PARTNER_ENTRANCES.lock().push((key, found.clone()));
    found
}

/// Of the partner's entrance bones, the one nearest `to`, in world
/// space.
///
/// # Safety
/// Game thread.
unsafe fn nearest_entrance(to: (f64, f64, f64)) -> Option<(f64, f64, f64)> {
    let p = PARTNER.load(std::sync::atomic::Ordering::Acquire);
    if !crate::ue::uobject::is_live(p) {
        return None;
    }
    // SAFETY: p is the live object GObjects holds at its index.
    let partner = unsafe { &*(p as *const UObject) };
    let d2 =
        |a: (f64, f64, f64)| (a.0 - to.0).powi(2) + (a.1 - to.1).powi(2) + (a.2 - to.2).powi(2);
    // SAFETY: the caller's; partner is live.
    unsafe { entrances_on(partner) }
        .iter()
        .filter_map(|b| unsafe { bone_location(partner, b) })
        .min_by(|a, b| {
            d2(*a)
                .partial_cmp(&d2(*b))
                .unwrap_or(std::cmp::Ordering::Equal)
        })
}
/// Every placement by a held caller so far, on any body: with the frame
/// in each record it shows how often the scene places the bodies.
static HELD_CALLS: std::sync::atomic::AtomicU64 = std::sync::atomic::AtomicU64::new(0);
/// Frames [`record_stroke`] still records, set by parts.stroke_record.
static STROKE_LEFT: std::sync::atomic::AtomicUsize = std::sync::atomic::AtomicUsize::new(0);
/// What [`record_stroke`] recorded, one entry per placement.
static STROKE: parking_lot::Mutex<Vec<Value>> = parking_lot::Mutex::new(Vec::new());
/// More partner bones [`record_stroke`] records besides the entrances
/// (a mouth, hands), set by parts.stroke_record; the placement does not
/// use them.
static STROKE_BONES: parking_lot::Mutex<Vec<String>> = parking_lot::Mutex::new(Vec::new());

/// Record one placement of a sized body by a held caller, as the game
/// put it, before this mod scales or moves it: the frame, the size, the
/// component's world location, the anchor bone (the chain's root) and
/// its tip in world space, and the partner's component location and each
/// of its entrance bones' world transform (GetSocketTransform, world).
/// For measuring how the two bodies meet through a stroke.
///
/// # Safety
/// Game thread, `c` live.
unsafe fn record_stroke(c: &UObject, size: f64, tip: Option<&str>) {
    let v3 = |p: Option<(f64, f64, f64)>| p.map(|(x, y, z)| json!([x, y, z]));
    // SAFETY: the caller's, for every call below.
    unsafe {
        let root = HOLD_ANCHOR.lock().clone();
        let at = |o: &UObject| {
            call(o, "SceneComponent", "K2_GetComponentLocation", json!({}))
                .ok()
                .and_then(|v| vector(&v["ReturnValue"]))
        };
        let mut rec = json!({
            "frame": crate::frame::frames(),
            "calls": HELD_CALLS.load(std::sync::atomic::Ordering::Relaxed),
            "component": c.name(),
            "actor": c.outer().map(|o| o.name()),
            "size": size,
            "body": v3(at(c)),
            "base": v3(root.as_deref().and_then(|b| bone_location(c, b))),
            "tip": v3(tip.and_then(|t| bone_location(c, t))),
            "tip_bone": tip,
        });
        let p = PARTNER.load(std::sync::atomic::Ordering::Acquire);
        if crate::ue::uobject::is_live(p) {
            // SAFETY: p is the live object GObjects holds at its index.
            let partner = &*(p as *const UObject);
            rec["partner"] = json!(v3(at(partner)));
            let mut ents = serde_json::Map::new();
            let mut wanted = entrances_on(partner);
            wanted.extend(STROKE_BONES.lock().iter().cloned());
            for e in wanted {
                let t = call(
                    partner,
                    "SceneComponent",
                    "GetSocketTransform",
                    json!({"InSocketName": e, "TransformSpace": 0}),
                )
                .map(|v| v["ReturnValue"].clone())
                .unwrap_or(Value::Null);
                ents.insert(e, t);
            }
            rec["entrances"] = Value::Object(ents);
        }
        STROKE.lock().push(rec);
    }
    STROKE_LEFT.fetch_sub(1, std::sync::atomic::Ordering::AcqRel);
}

/// Per skinned mesh, the tip of the anchor chain (None: no such bone).
static ANCHOR_TIPS: parking_lot::Mutex<Vec<(usize, Option<String>)>> =
    parking_lot::Mutex::new(Vec::new());

/// The deepest bone under the anchor bone on `c`, looked up once per
/// component.
///
/// # Safety
/// Game thread, `c` live.
unsafe fn anchor_tip(c: &UObject) -> Option<String> {
    let root = HOLD_ANCHOR.lock().clone()?;
    let key = c as *const UObject as usize;
    if let Some((_, t)) = ANCHOR_TIPS.lock().iter().find(|(k, _)| *k == key) {
        return t.clone();
    }
    // SAFETY: the caller's.
    let tip = unsafe { chain_tip(c, &root) };
    crate::log!("parts: anchor tip on {}: {tip:?}", c.name());
    ANCHOR_TIPS.lock().push((key, tip.clone()));
    tip
}

/// A bone's world location (SceneComponent::GetSocketLocation; a
/// skinned mesh's bones are sockets).
///
/// # Safety
/// Game thread, `c` live.
unsafe fn bone_location(c: &UObject, bone: &str) -> Option<(f64, f64, f64)> {
    // SAFETY: the caller's.
    let r = unsafe {
        call(
            c,
            "SceneComponent",
            "GetSocketLocation",
            json!({"InSocketName": bone}),
        )
    }
    .ok()?;
    vector(&r["ReturnValue"])
}

fn remember_size(a: &UObject, factor: f64) {
    let key = a as *const UObject as usize;
    let mut s = SIZES.lock();
    s.retain(|(k, _)| *k != key);
    if (factor - 1.0).abs() > 1e-6 {
        s.push((key, factor));
    }
}

/// Called on the game thread with the actor each time a caller named in
/// [`hold_size_through`] places one of its components, before its size
/// is applied: a mod can apply a [`Look`] there the first time.
static ON_HELD: parking_lot::Mutex<Option<fn(&UObject)>> = parking_lot::Mutex::new(None);

/// Set the [`ON_HELD`] callback.
pub fn on_held_placement(f: fn(&UObject)) {
    *ON_HELD.lock() = Some(f);
}

/// How an actor looks: its size and what is hidden or changed on its
/// meshes, by component name (the same on every actor of a class).
/// Applied with [`apply_look`], put back with [`undo_look`].
#[derive(Clone, Debug, PartialEq, serde::Serialize, serde::Deserialize)]
#[serde(default)]
pub struct Look {
    pub size: f64,
    /// Meshes hidden (SetHiddenInGame).
    pub hidden: Vec<String>,
    /// Material slots off: (component, slot).
    pub slots_off: Vec<(String, i64)>,
    /// Bones hidden with every bone below them: (component, bone).
    pub bones_off: Vec<(String, String)>,
    /// Bones hidden alone, the bones below them still shown
    /// (pose_hide.rs): (component, bone).
    pub bones_alone: Vec<(String, String)>,
    /// Morph values: (component, morph, value).
    pub morphs: Vec<(String, String, f64)>,
}

impl Default for Look {
    fn default() -> Self {
        Self {
            size: 1.0,
            hidden: Vec::new(),
            slots_off: Vec::new(),
            bones_off: Vec::new(),
            bones_alone: Vec::new(),
            morphs: Vec::new(),
        }
    }
}

/// What [`apply_look`] changed, to put back.
#[derive(Debug)]
pub struct Undo {
    actor: usize,
    size: f64,
    hidden: Vec<(usize, bool)>,
    slots: Vec<(usize, i64)>,
    bones: Vec<(usize, String)>,
    /// Components with bones hidden alone.
    alone: Vec<usize>,
    morphs: Vec<(usize, String, f64)>,
}

impl Undo {
    pub fn actor(&self) -> usize {
        self.actor
    }
}

/// The actor's mesh components by name.
///
/// # Safety
/// Game thread, `a` live.
unsafe fn meshes(a: &UObject) -> Vec<(String, &'static UObject)> {
    let Some(mesh) = find_class_fast("MeshComponent") else {
        return Vec::new();
    };
    actor::components_by_class(a, mesh)
        .unwrap_or_default()
        .into_iter()
        // SAFETY: the actor's live components.
        .map(|c| unsafe { &*c })
        .map(|c| (c.name(), c))
        .collect()
}

/// Apply `look` to the actor, recording what it was.
///
/// # Safety
/// Game thread, `a` live.
pub unsafe fn apply_look(a: &UObject, look: &Look) -> Undo {
    // SAFETY: the caller's, for every call below.
    unsafe {
        let parts = meshes(a);
        let find = |n: &str| parts.iter().find(|(name, _)| name == n).map(|(_, c)| *c);
        let addr = |c: &UObject| c as *const UObject as usize;
        let size = call(a, "Actor", "GetActorScale3D", json!({}))
            .ok()
            .and_then(|v| v["ReturnValue"]["X"].as_f64())
            .unwrap_or(1.0);
        let mut undo = Undo {
            actor: addr(a),
            size,
            hidden: Vec::new(),
            slots: Vec::new(),
            bones: Vec::new(),
            alone: Vec::new(),
            morphs: Vec::new(),
        };
        if (look.size - size).abs() > 1e-6 {
            let _ = actor_scale(a, look.size);
        }
        for n in &look.hidden {
            let Some(c) = find(n) else { continue };
            let was = reflect::get_fields(c, &["bHiddenInGame".into()])
                .ok()
                .and_then(|v| v["bHiddenInGame"].as_bool())
                .unwrap_or(false);
            if hide(c, true).is_ok() {
                undo.hidden.push((addr(c), was));
            }
        }
        for (n, s) in &look.slots_off {
            let Some(c) = find(n) else { continue };
            if slot(c, *s, false).is_ok() {
                undo.slots.push((addr(c), *s));
            }
        }
        for (n, b) in &look.bones_off {
            let Some(c) = find(n) else { continue };
            if bone(c, b, true).is_ok() {
                undo.bones.push((addr(c), b.clone()));
            }
        }
        // One list per component: pose_hide replaces a component's list.
        let mut alone: Vec<(&str, Vec<String>)> = Vec::new();
        for (n, b) in &look.bones_alone {
            match alone.iter_mut().find(|(c, _)| c == n) {
                Some((_, list)) => list.push(b.clone()),
                None => alone.push((n.as_str(), vec![b.clone()])),
            }
        }
        for (n, list) in &alone {
            let Some(c) = find(n) else { continue };
            match crate::pose_hide::set(c, list) {
                Ok(_) => undo.alone.push(addr(c)),
                Err(e) => crate::log!("parts: {n}: bones alone: {e}"),
            }
        }
        for (n, m, v) in &look.morphs {
            let Some(c) = find(n) else { continue };
            let was = call(
                c,
                "SkeletalMeshComponent",
                "GetMorphTarget",
                json!({"MorphTargetName": m}),
            )
            .ok()
            .and_then(|r| r["ReturnValue"].as_f64())
            .unwrap_or(0.0);
            if morph(c, m, *v).is_ok() {
                undo.morphs.push((addr(c), m.clone(), was));
            }
        }
        crate::log!("parts: look on {}: {look:?}", a.name());
        undo
    }
}

/// The actor's look as it is now: its size, the meshes hidden in game,
/// the topmost hidden bones (hiding one hides the bones below it), and
/// the morphs not at 0. The engine has no getter for a material slot
/// shown by ShowMaterialSection, so `slots_off` comes from the caller,
/// who turned them off.
///
/// # Safety
/// Game thread, `a` live.
pub unsafe fn capture_look(a: &UObject, slots_off: &[(String, i64)]) -> Look {
    // SAFETY: the caller's, for every call below.
    unsafe {
        let mut look = Look {
            size: call(a, "Actor", "GetActorScale3D", json!({}))
                .ok()
                .and_then(|v| v["ReturnValue"]["X"].as_f64())
                .unwrap_or(1.0),
            slots_off: slots_off.to_vec(),
            ..Look::default()
        };
        for (n, c) in meshes(a) {
            for b in crate::pose_hide::bones_of(c as *const UObject as usize) {
                look.bones_alone.push((n.clone(), b));
            }
            let d = describe(c);
            if d["hidden_in_game"] == json!(true) {
                look.hidden.push(n.clone());
            }
            for m in d["morphs"].as_array().into_iter().flatten() {
                let v = m[1].as_f64().unwrap_or(0.0);
                if v.abs() > 1e-6
                    && let Some(name) = m[0].as_str()
                {
                    look.morphs.push((n.clone(), name.to_owned(), v));
                }
            }
            let Ok(b) = bones(c) else { continue };
            let list = b["bones"].as_array().cloned().unwrap_or_default();
            let hidden: Vec<&str> = list
                .iter()
                .filter(|x| x[2] == json!(true))
                .filter_map(|x| x[0].as_str())
                .collect();
            for x in &list {
                let (Some(name), parent) = (x[0].as_str(), x[1].as_str()) else {
                    continue;
                };
                if x[2] == json!(true) && !parent.is_some_and(|p| hidden.contains(&p)) {
                    look.bones_off.push((n.clone(), name.to_owned()));
                }
            }
        }
        look
    }
}

/// Put back what [`apply_look`] changed, skipping objects that are gone.
///
/// # Safety
/// Game thread.
pub unsafe fn undo_look(u: &Undo) {
    let live = |p: usize| crate::selector::resolve(&format!("addr:0x{p:X}")).ok();
    // SAFETY: the caller's; every object is checked live first.
    unsafe {
        for (c, m, v) in &u.morphs {
            if let Some(c) = live(*c) {
                let _ = morph(c, m, *v);
            }
        }
        for (c, b) in &u.bones {
            if let Some(c) = live(*c) {
                let _ = bone(c, b, false);
            }
        }
        for c in &u.alone {
            match live(*c) {
                Some(c) => {
                    let _ = crate::pose_hide::set(c, &[]);
                }
                // Gone: drop its entry so the hook stops looking for it.
                None => crate::pose_hide::forget(*c),
            }
        }
        for (c, s) in &u.slots {
            if let Some(c) = live(*c) {
                let _ = slot(c, *s, true);
            }
        }
        for (c, was) in &u.hidden {
            if let Some(c) = live(*c) {
                let _ = hide(c, *was);
            }
        }
        if let Some(a) = live(u.actor) {
            let _ = actor_scale(a, u.size);
            crate::log!("parts: look undone on {}", a.name());
        }
    }
}

/// Keep an actor's size from [`actor_scale`] when a script function
/// named in `callers` puts one of its components at a stored world
/// transform (SceneComponent.K2_SetWorldTransform), which carries the
/// unscaled size. Right after the engine's call, that component's
/// relative size is multiplied by the actor's size, so its world size
/// is the stored one times the actor's. Wicked Island's sex scene
/// (AC_Sex_C "Update Actor Lock") does this to both bodies every frame
/// (wickedisland-mod tests/research_parts.rs native_callers,
/// 2026-11-21). Other world-transform calls are left alone: one built
/// from the actor's current transform already has its size.
///
/// With `anchor` (a bone name), the body is then moved so the tip of
/// that bone's chain (its deepest bone) stays where the game put it at
/// full size, so a shrunk body still meets the other one at that point.
/// Bodies without that bone are only scaled.
///
/// With `entrances` (bone names on the other body), the body is instead
/// scaled around the entrance bone nearest the full-size tip, on the
/// other body the same caller places (one with no size). Every point of
/// the body moves toward that bone by the size, so the stroke shrinks
/// with the body: where the game had the full-size tip at the entrance,
/// the shrunk tip is there too, and where it had the full-size base
/// there, the shrunk base is. Asked 2026-11-21: "it should be full
/// withdrawl. full insertion. with it working correctly after resize".
/// Without an entrance found, the tip is kept as above.
///
/// Install once, after the runtime is up.
pub fn hold_size_through(
    callers: &[&str],
    anchor: Option<&str>,
    entrances: &[&str],
) -> Result<(), String> {
    HOLD_CALLERS
        .lock()
        .extend(callers.iter().map(|c| c.to_string()));
    *HOLD_ANCHOR.lock() = anchor.map(str::to_owned);
    *HOLD_ENTRANCES.lock() = entrances.iter().map(|e| e.to_string()).collect();
    let h = crate::hook::native_function::NativeFunctionHook::install(
        "SceneComponent",
        "K2_SetWorldTransform",
        |c, frame, result, original| {
            // SAFETY: the engine's own call, unchanged.
            unsafe { original.call(c, frame, result) };
            let Some(owner) = c.outer() else { return };
            let key = owner as *const UObject as usize;
            let Some(node) = frame.node() else { return };
            let caller = node.as_object().name();
            if !HOLD_CALLERS.lock().iter().any(|n| *n == caller) {
                return;
            }
            HELD_CALLS.fetch_add(1, std::sync::atomic::Ordering::Relaxed);
            let placed = *ON_HELD.lock();
            if let Some(cb) = placed {
                let _ = std::panic::catch_unwind(|| cb(owner));
            }
            let placed = *ON_HELD_COMPONENT.lock();
            if let Some(cb) = placed {
                let _ = std::panic::catch_unwind(|| cb(c));
            }
            let Some(f) = SIZES
                .lock()
                .iter()
                .find(|(k, _)| *k == key)
                .map(|(_, f)| *f)
            else {
                PARTNER.store(
                    c as *const UObject as usize,
                    std::sync::atomic::Ordering::Release,
                );
                return;
            };
            // SAFETY: the game thread (the script VM's call); c is live.
            unsafe {
                let Ok(now) = reflect::get_fields(c, &["RelativeScale3D".to_string()]) else {
                    return;
                };
                let Some((x, y, z)) = vector(&now["RelativeScale3D"]) else {
                    return;
                };
                let tip = anchor_tip(c);
                let full = tip.as_deref().and_then(|t| bone_location(c, t));
                if STROKE_LEFT.load(std::sync::atomic::Ordering::Acquire) > 0 {
                    record_stroke(c, f, tip.as_deref());
                }
                let _ = call(
                    c,
                    "SceneComponent",
                    "SetRelativeScale3D",
                    json!({"NewScale3D": {"X": x * f, "Y": y * f, "Z": z * f}}),
                );
                let (Some(t), Some(full)) = (tip, full) else {
                    return;
                };
                // Scaling by f moved every point toward the component's
                // origin O; moving the body by (1 - f)(E - O) makes it
                // toward the entrance E instead.
                let anchor = *SCALE_ANCHOR.lock();
                let fixed = anchor.and_then(|a| a(c)).map(|p| (p.x, p.y, p.z));
                if let Some(e) = fixed.or_else(|| nearest_entrance(full)) {
                    let Some(o) = call(c, "SceneComponent", "K2_GetComponentLocation", json!({}))
                        .ok()
                        .and_then(|v| vector(&v["ReturnValue"]))
                    else {
                        return;
                    };
                    let k = 1.0 - f;
                    let _ = call(
                        c,
                        "SceneComponent",
                        "K2_AddWorldOffset",
                        json!({
                            "DeltaLocation": {"X": k * (e.0 - o.0), "Y": k * (e.1 - o.1), "Z": k * (e.2 - o.2)},
                            "bSweep": false,
                            "bTeleport": true,
                        }),
                    );
                    return;
                }
                let Some(small) = bone_location(c, &t) else {
                    return;
                };
                let _ = call(
                    c,
                    "SceneComponent",
                    "K2_AddWorldOffset",
                    json!({
                        "DeltaLocation": {"X": full.0 - small.0, "Y": full.1 - small.1, "Z": full.2 - small.2},
                        "bSweep": false,
                        "bTeleport": true,
                    }),
                );
            }
        },
    )?;
    crate::hook::native_function::register(h);
    Ok(())
}

/// Called on the game thread with the component each time a caller
/// named in [`hold_size_through`] places it, right after the game set
/// its world transform and before any resize, at any size.
static ON_HELD_COMPONENT: parking_lot::Mutex<Option<fn(&UObject)>> = parking_lot::Mutex::new(None);

/// Set the [`ON_HELD_COMPONENT`] callback.
pub fn on_held_component(f: fn(&UObject)) {
    *ON_HELD_COMPONENT.lock() = Some(f);
}

/// Asked for the world point a sized component is scaled around each
/// time a held caller places it; None falls back to the partner's
/// entrance nearest the full-size tip at that moment.
static SCALE_ANCHOR: parking_lot::Mutex<Option<fn(&UObject) -> Option<glam::DVec3>>> =
    parking_lot::Mutex::new(None);

/// Set the [`SCALE_ANCHOR`] callback: a fixed point keeps the sized
/// body's transform the same at every placement, so where a point of the
/// other body lands in its space follows from the animations alone.
pub fn scale_anchor(f: fn(&UObject) -> Option<glam::DVec3>) {
    *SCALE_ANCHOR.lock() = Some(f);
}

/// The size set on actor `actor` (its address) through the parts ops,
/// None when it has none.
pub fn size_of(actor: usize) -> Option<f64> {
    SIZES
        .lock()
        .iter()
        .find(|(k, _)| *k == actor)
        .map(|(_, f)| *f)
}

/// The deepest bone below `root` on skinned mesh `c` (`root` itself when
/// nothing is below it), None when `c` has no such bone.
///
/// # Safety
/// Game thread, `c` live.
pub unsafe fn chain_tip(c: &UObject, root: &str) -> Option<String> {
    // SAFETY: the caller's.
    let list = unsafe { bones(c) }.ok()?;
    // Bones come parents first: depth below the root, by name.
    let mut depth: Vec<(String, usize)> = Vec::new();
    let mut tip: Option<(String, usize)> = None;
    for b in list["bones"].as_array().into_iter().flatten() {
        let name = b[0].as_str().unwrap_or("").to_owned();
        let parent = b[1].as_str().unwrap_or("");
        let d = if name == root {
            Some(0)
        } else {
            depth.iter().find(|(n, _)| n == parent).map(|(_, d)| d + 1)
        };
        if let Some(d) = d {
            if tip.as_ref().is_none_or(|(_, td)| d > *td) {
                tip = Some((name.clone(), d));
            }
            depth.push((name, d));
        }
    }
    tip.map(|(n, _)| n)
}

/// How far the mesh's collision capsules (its physics asset's sphyl
/// shapes, FKSphylElem: axis local Z, half length plus radius from the
/// center) reach past bone `tip` along `from` to `tip`, in component
/// space cm at the pose now: where the shape the game gives the body
/// ends, when the mesh's own points cannot be read. Only capsules on
/// bones whose name has `word`. None without a physics asset or capsule.
/// Asked 2026-11-22: "what are you measuring as the tip then?".
///
/// # Safety
/// Game thread, `c` a live skinned mesh.
pub unsafe fn capsule_reach(c: &UObject, from: &str, tip: &str, word: &str) -> Option<f64> {
    use crate::anim_data::Xform;
    use glam::DVec3;
    let obj = |v: &Value| crate::selector::resolve(&format!("addr:{}", v["addr"].as_str()?)).ok();
    let field = |o: &UObject, f: &str| -> Option<Value> {
        // SAFETY: the caller's; o live.
        unsafe { crate::reflect::get_fields(o, &[f.to_owned()]) }
            .ok()
            .map(|v| v[f].clone())
    };
    let bone = |n: &str| -> Option<Xform> {
        let p = json!({"InSocketName": n, "TransformSpace": 2});
        // SAFETY: the caller's.
        let v = unsafe {
            crate::reflect::call(c, "SceneComponent", "GetSocketTransform", p.as_object()?)
        }
        .ok()?;
        Xform::from_json(&v["ReturnValue"])
    };
    let mesh = obj(&field(c, "SkinnedAsset")?)?;
    let physics = obj(&field(mesh, "PhysicsAsset")?)?;
    // SAFETY: the caller's; physics live.
    let bodies = unsafe { crate::reflect::array_get(physics, "SkeletalBodySetups", None) }.ok()?;
    let (a, t) = (bone(from)?, bone(tip)?);
    let dir = (t.pos - a.pos).normalize_or_zero();
    let n = |v: &Value, k: &str| v[k].as_f64().unwrap_or(0.0);
    let mut most: Option<f64> = None;
    for b in bodies["elements"].as_array().into_iter().flatten() {
        let Some(body) = obj(b) else { continue };
        let Some(name) = field(body, "BoneName").and_then(|v| v.as_str().map(str::to_owned)) else {
            continue;
        };
        if !name.contains(word) {
            continue;
        }
        let (Some(x), Some(geom)) = (bone(&name), field(body, "AggGeom")) else {
            continue;
        };
        for s in geom["SphylElems"].as_array().into_iter().flatten() {
            let c = DVec3::new(
                n(&s["Center"], "X"),
                n(&s["Center"], "Y"),
                n(&s["Center"], "Z"),
            );
            let r = &s["Rotation"];
            let q = rotator_quat(n(r, "Pitch"), n(r, "Yaw"), n(r, "Roll"));
            let half = n(s, "Length") / 2.0 + n(s, "Radius");
            for sign in [-1.0, 1.0] {
                let p = x.point(c + q * DVec3::new(0.0, 0.0, sign * half));
                let past = (p - t.pos).dot(dir);
                most = Some(most.map_or(past, |m: f64| m.max(past)));
            }
        }
    }
    most
}

/// UE's FRotator::Quaternion, degrees.
fn rotator_quat(pitch: f64, yaw: f64, roll: f64) -> glam::DQuat {
    let h = |d: f64| (d.to_radians() / 2.0).sin_cos();
    let ((sp, cp), (sy, cy), (sr, cr)) = (h(pitch), h(yaw), h(roll));
    glam::DQuat::from_xyzw(
        cr * sp * sy - sr * cp * cy,
        -cr * sp * cy - sr * cp * sy,
        cr * cp * sy - sr * sp * cy,
        cr * cp * cy + sr * sp * sy,
    )
}

/// A skinned mesh's bones, in index order, each as [name, parent,
/// hidden] (GetNumBones, GetBoneName, GetParentBone,
/// IsBoneHiddenByName). Only for skinned meshes: GetNumBones on another
/// class crashed the game (reflect::call now refuses that).
///
/// # Safety
/// Game thread, `c` live.
pub unsafe fn bones(c: &UObject) -> Result<Value, String> {
    if !is(c, "SkinnedMeshComponent") {
        return Err(format!("{} is not a skinned mesh", c.name()));
    }
    // SAFETY: the caller's, for every call below.
    unsafe {
        let n = call(c, "SkinnedMeshComponent", "GetNumBones", json!({}))?["ReturnValue"]
            .as_i64()
            .unwrap_or(0);
        let mut out = Vec::new();
        for i in 0..n {
            let name = call(
                c,
                "SkinnedMeshComponent",
                "GetBoneName",
                json!({"BoneIndex": i}),
            )?["ReturnValue"]
                .clone();
            let parent = call(
                c,
                "SkinnedMeshComponent",
                "GetParentBone",
                json!({"BoneName": name}),
            )?["ReturnValue"]
                .clone();
            let hidden = call(
                c,
                "SkinnedMeshComponent",
                "IsBoneHiddenByName",
                json!({"BoneName": name}),
            )?["ReturnValue"]
                .clone();
            out.push(json!([name, parent, hidden]));
        }
        Ok(json!({"component": hex(c), "bones": out}))
    }
}

/// Hide or show one bone and every bone below it
/// (SkinnedMeshComponent::HideBoneByName with PhysBodyOption 0, and
/// UnHideBoneByName), as UEVR's pawn library hides arms (github
/// jbusfield/uevrlib libs/pawn.lua:146,153).
///
/// # Safety
/// Game thread.
pub unsafe fn bone(c: &UObject, name: &str, hidden: bool) -> Result<Value, String> {
    if !is(c, "SkinnedMeshComponent") {
        return Err(format!("{} is not a skinned mesh", c.name()));
    }
    // SAFETY: the caller's.
    unsafe {
        if hidden {
            call(
                c,
                "SkinnedMeshComponent",
                "HideBoneByName",
                json!({"BoneName": name, "PhysBodyOption": 0}),
            )?;
        } else {
            call(
                c,
                "SkinnedMeshComponent",
                "UnHideBoneByName",
                json!({"BoneName": name}),
            )?;
        }
        let now = call(
            c,
            "SkinnedMeshComponent",
            "IsBoneHiddenByName",
            json!({"BoneName": name}),
        )?;
        Ok(json!({"component": hex(c), "bone": name, "hidden": now["ReturnValue"]}))
    }
}

/// The topmost bones whose names hold one of `words` and none of `not`
/// (any case): the bones to hide for that body area, as hiding a bone
/// hides every bone below it.
pub fn topmost_matching(
    tree: &[(String, String)],
    words: &[String],
    not: &[String],
) -> Vec<String> {
    let hit = |n: &str| {
        let n = n.to_lowercase();
        words.iter().any(|w| n.contains(&w.to_lowercase()))
            && !not.iter().any(|w| n.contains(&w.to_lowercase()))
    };
    let parent_of = |n: &str| tree.iter().find(|(b, _)| b == n).map(|(_, p)| p.as_str());
    tree.iter()
        .filter(|(n, _)| hit(n))
        .filter(|(n, _)| {
            // No bone above it is a hit.
            let mut p = parent_of(n);
            let mut steps = 0;
            while let Some(b) = p
                && !b.is_empty()
                && b != "None"
                && steps < tree.len()
            {
                if hit(b) {
                    return false;
                }
                p = parent_of(b);
                steps += 1;
            }
            true
        })
        .map(|(n, _)| n.clone())
        .collect()
}

/// Each skeletal mesh asset's morph names, read once per asset.
static MORPH_NAMES: parking_lot::Mutex<Vec<(usize, Vec<String>)>> =
    parking_lot::Mutex::new(Vec::new());

/// A skeletal mesh asset's morph names (K2_GetAllMorphTargetNames),
/// cached by the asset.
///
/// # Safety
/// Game thread, `mesh` a live SkeletalMesh.
unsafe fn asset_morph_names(mesh: &UObject) -> Vec<String> {
    let key = mesh as *const UObject as usize;
    if let Some((_, n)) = MORPH_NAMES.lock().iter().find(|(k, _)| *k == key) {
        return n.clone();
    }
    // SAFETY: the caller's.
    let names: Vec<String> =
        unsafe { call(mesh, "SkeletalMesh", "K2_GetAllMorphTargetNames", json!({})) }
            .ok()
            .and_then(|v| v["ReturnValue"].as_array().cloned())
            .unwrap_or_default()
            .iter()
            .filter_map(|v| v.as_str().map(str::to_owned))
            .collect();
    MORPH_NAMES.lock().push((key, names.clone()));
    names
}

/// A skeletal mesh component's asset, or None.
///
/// # Safety
/// Game thread, `c` live.
unsafe fn skeletal_asset(c: &UObject) -> Option<&'static UObject> {
    if !is(c, "SkeletalMeshComponent") {
        return None;
    }
    // SAFETY: the caller's.
    let addr = unsafe { reflect::get_fields(c, &["SkinnedAsset".into()]) }
        .ok()?
        .get("SkinnedAsset")?
        .get("addr")?
        .as_str()?
        .to_owned();
    crate::selector::resolve(&format!("addr:{addr}")).ok()
}

/// Every morph name on the main mesh (the Character "Mesh" field) of the
/// loaded classes made from `base_class`, each with the classes that
/// have it, read from the class defaults, so no live actor is needed.
///
/// # Safety
/// Game thread.
pub unsafe fn morphs_by_class(base_class: &str) -> std::collections::BTreeMap<String, Vec<String>> {
    let mut out: std::collections::BTreeMap<String, Vec<String>> = Default::default();
    crate::ue::ClassRef::new_dynamic(base_class).for_each_cdo_subclass(|cdo| {
        let class = cdo
            .class()
            .map(|c| c.as_object().name())
            .unwrap_or_default();
        // SAFETY: the caller's; class defaults live as long as their class.
        let names = unsafe {
            let Some(mesh) = reflect::get_fields(cdo, &["Mesh".into()])
                .ok()
                .and_then(|v| v["Mesh"]["addr"].as_str().map(str::to_owned))
                .and_then(|a| crate::selector::resolve(&format!("addr:{a}")).ok())
            else {
                return;
            };
            let Some(asset) = skeletal_asset(mesh) else {
                return;
            };
            asset_morph_names(asset)
        };
        for n in names {
            let e = out.entry(n).or_default();
            if !e.contains(&class) {
                e.push(class.clone());
            }
        }
    });
    out
}

/// A look of `size` that turns off, on every skinned mesh of the actor,
/// each material slot `hide_slot` answers true for (the slots the
/// parts.slot op turns off), hides alone each bone `hide_bone` answers
/// true for (pose_hide.rs: the bones below stay shown), and sets each of
/// `morphs` (name, value) on every skeletal mesh that has a morph of that
/// name.
///
/// `hide_slot` gets the slot's material name and whether bones carry
/// that mesh: true when the mesh is posed by its own anim instance (its
/// bones are hidden here) or follows another mesh's pose (it draws with
/// that mesh's bones). A caller can then leave a slot that holds several
/// areas, such as one skin for a whole body, to the bones.
///
/// # Safety
/// Game thread, `a` live.
pub unsafe fn area_look(
    a: &UObject,
    size: f64,
    hide_slot: &dyn Fn(&str, bool) -> bool,
    hide_bone: &dyn Fn(&str) -> bool,
    morphs: &[(String, f64)],
) -> Look {
    let mut look = Look {
        size,
        ..Look::default()
    };
    // SAFETY: the caller's.
    for (name, c) in unsafe { meshes(a) } {
        // Body meshes only: a widget's or a carried stone's slots are
        // not body parts (Satyr log 2026-11-22: StateWidget, Projectile,
        // Stone slots were turned off with Torso).
        if !is(c, "SkinnedMeshComponent") {
            continue;
        }
        let posed = crate::pose_hide::posable(c);
        // SAFETY: the actor's live component, on the game thread.
        let follows = unsafe { reflect::get_fields(c, &["LeaderPoseComponent".into()]) }
            .is_ok_and(|v| v["LeaderPoseComponent"]["addr"].is_string());
        if posed {
            // SAFETY: as above.
            let tree = unsafe { bones(c) }.unwrap_or_default();
            for b in tree["bones"].as_array().into_iter().flatten() {
                if let Some(b) = b[0].as_str()
                    && hide_bone(b)
                {
                    look.bones_alone.push((name.clone(), b.to_owned()));
                }
            }
        }
        // SAFETY: the actor's live component, on the game thread.
        let n = unsafe { call(c, "PrimitiveComponent", "GetNumMaterials", json!({})) }
            .ok()
            .and_then(|v| v["ReturnValue"].as_i64())
            .unwrap_or(0);
        for i in 0..n {
            // SAFETY: as above.
            let material = unsafe {
                call(
                    c,
                    "PrimitiveComponent",
                    "GetMaterial",
                    json!({"ElementIndex": i}),
                )
            }
            .ok()
            .and_then(|v| v["ReturnValue"]["name"].as_str().map(str::to_owned))
            .unwrap_or_default();
            if hide_slot(&material, posed || follows) {
                look.slots_off.push((name.clone(), i));
            }
        }
        if morphs.is_empty() {
            continue;
        }
        // SAFETY: as above.
        let Some(asset) = (unsafe { skeletal_asset(c) }) else {
            continue;
        };
        // SAFETY: the component's live asset.
        let has = unsafe { asset_morph_names(asset) };
        for (m, v) in morphs {
            if has.contains(m) {
                look.morphs.push((name.clone(), m.clone(), *v));
            }
        }
    }
    look
}

/// parts.list, parts.hide, parts.slot, parts.morph, parts.scale,
/// parts.size, parts.bones, parts.bone on the game thread through
/// `drain`. Each logs what it was asked and what it returned.
pub fn register_ops(drain: &'static crate::pe_queue::GameThread, hint: &'static str) {
    use crate::ops::{OP_REGISTRY, OpDef};
    fn job(
        drain: &'static crate::pe_queue::GameThread,
        hint: &'static str,
        what: String,
        f: Box<dyn FnOnce() -> Result<Value, String> + Send>,
    ) -> Result<Value, String> {
        crate::log!("parts: {what}");
        let r = crate::debug::enqueue_pe(drain, std::time::Duration::from_secs(10), hint, f);
        match &r {
            Ok(v) if what.starts_with("list") => crate::log!(
                "parts: {what}: {} actors",
                v["actors"].as_array().map_or(0, Vec::len)
            ),
            Ok(v) => crate::log!("parts: {what}: {v}"),
            Err(e) => crate::log!("parts: {what}: failed: {e}"),
        }
        r
    }
    fn component(args: &Value) -> Result<String, String> {
        let c = args["component"]
            .as_str()
            .ok_or("component: 0x address is required")?;
        Ok(format!("addr:{c}"))
    }
    fn target(c: &str) -> Result<&'static UObject, String> {
        crate::selector::resolve(c)
    }
    OP_REGISTRY.register_many([
        OpDef::new("parts.list", "Actors of a class near the player, nearest first, with their mesh components (asset, shown, scale, material slots)", "{class: str, max_distance?: f64 (cm, default 5000)}", move |args| {
            let class = args["class"].as_str().ok_or("class is required")?.to_owned();
            let max = args["max_distance"].as_f64().unwrap_or(5000.0);
            job(drain, hint, format!("list {class} within {max}"), Box::new(move || unsafe { list(&class, max) }))
        }),
        OpDef::new("parts.hide", "Hide or show a whole mesh component (SetHiddenInGame)", "{component: 0x addr, hidden: bool}", move |args| {
            let c = component(args)?;
            let hidden = args["hidden"].as_bool().ok_or("hidden: bool is required")?;
            job(drain, hint, format!("hide {c} {hidden}"), Box::new(move || unsafe { hide(target(&c)?, hidden) }))
        }),
        OpDef::new("parts.slot", "Show or hide one material slot of a skinned mesh on every LOD (ShowMaterialSection)", "{component: 0x addr, slot: i64, show: bool}", move |args| {
            let c = component(args)?;
            let s = args["slot"].as_i64().ok_or("slot is required")?;
            let show = args["show"].as_bool().ok_or("show: bool is required")?;
            job(drain, hint, format!("slot {c} {s} show {show}"), Box::new(move || unsafe { slot(target(&c)?, s, show) }))
        }),
        OpDef::new("parts.morph", "Set one morph target of a skeletal mesh (SetMorphTarget); below 0 pushes the shape the other way", "{component: 0x addr, name: str, value: f64}", move |args| {
            let c = component(args)?;
            let name = args["name"].as_str().ok_or("name is required")?.to_owned();
            let v = args["value"].as_f64().ok_or("value is required")?;
            job(drain, hint, format!("morph {c} {name} {v}"), Box::new(move || unsafe { morph(target(&c)?, &name, v) }))
        }),
        OpDef::new("parts.scale", "Scale a whole mesh component by one factor on all axes (SetRelativeScale3D); a game may put a body mesh's scale back, see parts.size", "{component: 0x addr, scale: f64}", move |args| {
            let c = component(args)?;
            let f = args["scale"].as_f64().ok_or("scale is required")?;
            job(drain, hint, format!("scale {c} {f}"), Box::new(move || unsafe { scale(target(&c)?, f) }))
        }),
        OpDef::new("parts.size", "The whole actor's size, one factor on all axes (SetActorScale3D)", "{actor: 0x addr, scale: f64}", move |args| {
            let a = format!("addr:{}", args["actor"].as_str().ok_or("actor: 0x address is required")?);
            let f = args["scale"].as_f64().ok_or("scale is required")?;
            job(drain, hint, format!("size {a} {f}"), Box::new(move || unsafe { actor_scale(target(&a)?, f) }))
        }),
        OpDef::new("parts.bones", "A skinned mesh's bones as [name, parent, hidden]", "{component: 0x addr}", move |args| {
            let c = component(args)?;
            job(drain, hint, format!("bones {c}"), Box::new(move || unsafe { bones(target(&c)?) }))
        }),
        OpDef::new("parts.bone", "Hide or show one bone of a skinned mesh and every bone below it (HideBoneByName, UnHideBoneByName)", "{component: 0x addr, bone: str, hidden: bool}", move |args| {
            let c = component(args)?;
            let b = args["bone"].as_str().ok_or("bone is required")?.to_owned();
            let hidden = args["hidden"].as_bool().ok_or("hidden: bool is required")?;
            job(drain, hint, format!("bone {c} {b} {hidden}"), Box::new(move || unsafe { bone(target(&c)?, &b, hidden) }))
        }),
        // No game-thread work: the size hook records on its own call.
        OpDef::new("parts.stroke_record", "Record the next N placements of a sized body by a held caller (see hold_size_through), before the mod moves it: body, anchor base and tip, partner entrance transforms and any partner_bones; clears the last recording", "{frames: u64, partner_bones?: [str]}", |args| {
            let n = args["frames"].as_u64().ok_or("frames is required")? as usize;
            *STROKE_BONES.lock() = args["partner_bones"]
                .as_array()
                .into_iter()
                .flatten()
                .filter_map(|b| b.as_str().map(str::to_owned))
                .collect();
            STROKE.lock().clear();
            STROKE_LEFT.store(n, std::sync::atomic::Ordering::Release);
            Ok(json!({"recording": n}))
        }),
        OpDef::new("parts.stroke_read", "What parts.stroke_record recorded so far, and how many placements it still waits for", "{}", |_| {
            Ok(json!({
                "left": STROKE_LEFT.load(std::sync::atomic::Ordering::Acquire),
                "records": STROKE.lock().clone(),
            }))
        }),
    ]);
}

#[cfg(test)]
mod tests {
    use super::topmost_matching;

    fn tree(pairs: &[(&str, &str)]) -> Vec<(String, String)> {
        pairs
            .iter()
            .map(|(a, b)| (a.to_string(), b.to_string()))
            .collect()
    }

    fn words(w: &[&str]) -> Vec<String> {
        w.iter().map(|s| s.to_string()).collect()
    }

    #[test]
    fn only_the_topmost_bone_of_an_area_is_returned_and_not_words_are_skipped() {
        // The deer's "Ponytail1" sits on its head; the dragon's fins sit
        // on its tail (tests/research_parts.rs skeleton_per_enemy).
        let t = tree(&[
            ("Root", "None"),
            ("Head", "Root"),
            ("Ponytail1", "Head"),
            ("Tail", "Root"),
            ("Tail1", "Tail"),
            ("fintailA1", "Tail1"),
            ("peener_shaft_BASE", "Root"),
            ("peener_shaft_001", "peener_shaft_BASE"),
        ]);
        let tail = topmost_matching(&t, &words(&["tail"]), &words(&["ponytail", "fintail"]));
        assert_eq!(tail, vec!["Tail".to_string()]);
        let penis = topmost_matching(&t, &words(&["penis", "peener"]), &[]);
        assert_eq!(penis, vec!["peener_shaft_BASE".to_string()]);
        assert!(topmost_matching(&t, &words(&["wing"]), &[]).is_empty());
    }
}
