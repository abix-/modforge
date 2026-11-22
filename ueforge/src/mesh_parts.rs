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

fn remember_size(a: &UObject, factor: f64) {
    let key = a as *const UObject as usize;
    let mut s = SIZES.lock();
    s.retain(|(k, _)| *k != key);
    if (factor - 1.0).abs() > 1e-6 {
        s.push((key, factor));
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
/// Install once, after the runtime is up.
pub fn hold_size_through(callers: &[&str]) -> Result<(), String> {
    HOLD_CALLERS
        .lock()
        .extend(callers.iter().map(|c| c.to_string()));
    let h = crate::hook::native_function::NativeFunctionHook::install(
        "SceneComponent",
        "K2_SetWorldTransform",
        |c, frame, result, original| {
            // SAFETY: the engine's own call, unchanged.
            unsafe { original.call(c, frame, result) };
            let Some(owner) = c.outer() else { return };
            let key = owner as *const UObject as usize;
            let Some(f) = SIZES
                .lock()
                .iter()
                .find(|(k, _)| *k == key)
                .map(|(_, f)| *f)
            else {
                return;
            };
            let Some(node) = frame.node() else { return };
            let caller = node.as_object().name();
            if !HOLD_CALLERS.lock().iter().any(|n| *n == caller) {
                return;
            }
            // SAFETY: the game thread (the script VM's call); c is live.
            unsafe {
                let Ok(now) = reflect::get_fields(c, &["RelativeScale3D".to_string()]) else {
                    return;
                };
                let Some((x, y, z)) = vector(&now["RelativeScale3D"]) else {
                    return;
                };
                let _ = call(
                    c,
                    "SceneComponent",
                    "SetRelativeScale3D",
                    json!({"NewScale3D": {"X": x * f, "Y": y * f, "Z": z * f}}),
                );
            }
        },
    )?;
    crate::hook::native_function::register(h);
    Ok(())
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
    ]);
}
