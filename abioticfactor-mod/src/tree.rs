//! Sophia's behavior tree, built in memory the way Epic's own test suite
//! builds trees (Engine/Source/Developer/AITestSuite/Public/BTBuilder.h):
//! a UBehaviorTree object, a root composite, children appended to the
//! composite's Children array, decorators appended to a child's Decorators
//! array, a RunBehavior task pointing at another tree, then RunBehaviorTree
//! on the controller, whose loader initializes every node from the asset.
//! No file on disk, so the tree can change at run time.
//!
//! The tree:
//!
//! ```text
//! Selector  [service: the game's BTS_ChooseBestTarget_C, the Exor's target choice]
//!   RunBehavior BT_Main_Exor    [decorator: blackboard TargetActor is set, abort both ways]
//!   MoveTo <follow key>         (the human, 300 units)
//! ```
//!
//! With an enemy on the blackboard the Exor's whole combat tree runs on her;
//! when the target clears, the decorator aborts it and the selector falls
//! back to following. Every node class is the engine's or the game's.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

use crate::ai_player::{describe, fname_bytes, object_ptr, session_controller};

const FOLLOW_RADIUS: f32 = 300.0;

/// A new object of a named class, owned by `outer`, through the engine's
/// GameplayStatics::SpawnObject. Game thread.
unsafe fn spawn_object(class: &str, outer: u64) -> Result<u64, String> {
    let class = ueforge::ue::find_class_fast(class).ok_or_else(|| format!("class {class} not found"))?;
    let (parms, ret) = unsafe { crate::host::call_static("GameplayStatics", "SpawnObject", &[("ObjectClass", &(class as *const _ as u64).to_le_bytes()), ("Outer", &outer.to_le_bytes())])? };
    let object = u64::from_le_bytes(parms[ret..ret + 8].try_into().unwrap());
    if object == 0 { return Err(format!("SpawnObject returned null for {}", class.as_object().name())); }
    Ok(object)
}

/// Write a reflected pointer field. Game thread.
unsafe fn write_ptr(object: &UObject, name: &str, value: u64) -> Result<(), String> {
    let offset = ueforge::input::class_property_offset(object, name, 8)?;
    // SAFETY: an eight-byte reflected field on a live object.
    unsafe { std::ptr::write_volatile(object.field_ptr(offset) as *mut u64, value) };
    Ok(())
}

/// Write a reflected byte field. Game thread.
unsafe fn write_u8(object: &UObject, name: &str, value: u8) -> Result<(), String> {
    let offset = ueforge::input::class_property_offset(object, name, 1)?;
    // SAFETY: a one-byte reflected field on a live object.
    unsafe { std::ptr::write_volatile(object.field_ptr(offset), value) };
    Ok(())
}

/// Write a reflected float field. Game thread.
unsafe fn write_f32(object: &UObject, name: &str, value: f32) -> Result<(), String> {
    let offset = ueforge::input::class_property_offset(object, name, 4)?;
    // SAFETY: a four-byte reflected field on a live object.
    unsafe { std::ptr::write_volatile(object.field_ptr(offset) as *mut f32, value) };
    Ok(())
}

/// A script struct's size and one field's offset, from its reflection. The
/// size is the end of its last reflected field rounded up to pointer
/// alignment: the UStruct size read gave 4101 for the 24-byte
/// FBlackboardEntry (2026-09-13), so it is not trusted for structs.
fn struct_layout(name: &str, field: &str) -> Result<(usize, usize), String> {
    let layout = ueforge::ue::find_struct_fast(name).ok_or_else(|| format!("struct {name} not found"))?;
    let properties = layout.cached_native_properties();
    let offset = properties.iter().find(|p| p.name == field).map(|p| p.offset as usize).ok_or_else(|| format!("struct {name} has no field {field}"))?;
    let end = properties.iter().map(|p| (p.offset + p.element_size) as usize).max().ok_or_else(|| format!("struct {name} has no reflected fields"))?;
    Ok((end.div_ceil(8) * 8, offset))
}

/// Append one element to a reflected TArray of pointers and return its slot. Game thread.
unsafe fn push_pointer(header: *mut u8, value: u64) -> Result<(), String> {
    // SAFETY: a TArray header is data pointer, count, capacity.
    unsafe {
        let count = ((header as usize + 8) as *const i32).read_unaligned();
        ueforge::ue::tarray::grow_raw(header, 8, count + 1)?;
        let data = (header as *const *mut u64).read_unaligned();
        data.add(count as usize).write_unaligned(value);
        ((header as usize + 8) as *mut i32).write_unaligned(count + 1);
    }
    Ok(())
}

/// Append a child (task or composite) to a composite's Children array, the
/// engine's FBTCompositeChild, zeroed then filled. Returns the entry's address.
unsafe fn push_child(composite: &UObject, child: u64, is_task: bool) -> Result<usize, String> {
    let (stride, composite_offset) = struct_layout("BTCompositeChild", "ChildComposite")?;
    let (_, task_offset) = struct_layout("BTCompositeChild", "ChildTask")?;
    let header = unsafe { composite.field_ptr(ueforge::input::class_property_offset(composite, "Children", 16)?) };
    // SAFETY: the Children TArray header on the live composite; the new element is zeroed before use.
    unsafe {
        let count = ((header as usize + 8) as *const i32).read_unaligned();
        ueforge::ue::tarray::grow_raw(header, stride, count + 1)?;
        let data = (header as *const *mut u8).read_unaligned();
        let entry = data.add(count as usize * stride);
        std::ptr::write_bytes(entry, 0, stride);
        (entry.add(if is_task { task_offset } else { composite_offset }) as *mut u64).write_unaligned(child);
        ((header as usize + 8) as *mut i32).write_unaligned(count + 1);
        Ok(entry as usize)
    }
}

/// Append a decorator to a child entry's Decorators array. Game thread.
unsafe fn add_decorator(entry: usize, decorator: u64) -> Result<(), String> {
    let (_, offset) = struct_layout("BTCompositeChild", "Decorators")?;
    unsafe { push_pointer((entry + offset) as *mut u8, decorator) }
}

/// Point a node's BlackboardKey selector at a key by name; the loader resolves the id and type.
unsafe fn select_key(node: &UObject, key: &str) -> Result<(), String> {
    let (_, name_offset) = struct_layout("BlackboardKeySelector", "SelectedKeyName")?;
    let selector = ueforge::input::class_property_offset(node, "BlackboardKey", 8)?;
    // SAFETY: the FName inside the selector struct on the live node.
    unsafe { (node.field_ptr(selector + name_offset) as *mut [u8; 8]).write_unaligned(fname_bytes(key)?) };
    Ok(())
}

/// The key names a blackboard asset declares, parents first. Game thread.
pub(crate) unsafe fn blackboard_keys(asset: u64) -> Result<Vec<String>, String> {
    let mut names = Vec::new();
    let mut current = asset;
    let (stride, name_offset) = struct_layout("BlackboardEntry", "EntryName")?;
    let mut chain = Vec::new();
    while current != 0 && chain.len() < 8 {
        chain.push(current);
        // SAFETY: a live blackboard asset.
        current = unsafe { object_ptr(&*(current as *const UObject), "Parent")? };
    }
    for asset in chain.into_iter().rev() {
        // SAFETY: a live blackboard asset and its Keys TArray of FBlackboardEntry.
        let object = unsafe { &*(asset as *const UObject) };
        let header = unsafe { object.field_ptr(ueforge::input::class_property_offset(object, "Keys", 16)?) };
        let (data, count) = unsafe { ((header as *const *const u8).read_unaligned(), ((header as usize + 8) as *const i32).read_unaligned()) };
        for index in 0..count.max(0) as usize {
            names.push(unsafe { ueforge::ue::fname::read_at(data.add(index * stride), name_offset) }.unwrap_or_default());
        }
    }
    Ok(names)
}

/// Build her tree on the Exor's blackboard and run it. Game thread.
unsafe fn build_and_run(controller: &UObject, follow_key: &str, follow_actor: u64) -> Result<Value, String> {
    let controller_addr = controller as *const UObject as u64;
    let exor_tree = unsafe { object_ptr(controller, "BehaviorTree")? };
    if exor_tree == 0 { return Err("the controller class names no behavior tree; join with AI_Controller_NPC_Exor_C".into()); }
    // SAFETY: the live Exor tree asset.
    let blackboard = unsafe { object_ptr(&*(exor_tree as *const UObject), "BlackboardAsset")? };
    if blackboard == 0 { return Err("the Exor tree has no blackboard asset".into()); }
    let keys = unsafe { blackboard_keys(blackboard)? };
    if !keys.iter().any(|k| k == follow_key) { return Err(format!("the Exor blackboard has no key {follow_key}; its keys are {keys:?}")); }

    let tree = unsafe { spawn_object("BehaviorTree", controller_addr)? };
    // SAFETY: objects the engine just created for us, filled by reflected offsets.
    let tree_object = unsafe { &*(tree as *const UObject) };
    unsafe { write_ptr(tree_object, "BlackboardAsset", blackboard)? };
    let root = unsafe { spawn_object("BTComposite_Selector", tree)? };
    unsafe { write_ptr(tree_object, "RootNode", root)? };
    let root_object = unsafe { &*(root as *const UObject) };
    // The Exor's own target choice, as a service on the root so it runs in both branches.
    let chooser = unsafe { spawn_object("BTS_ChooseBestTarget_C", tree)? };
    unsafe { push_pointer(root_object.field_ptr(ueforge::input::class_property_offset(root_object, "Services", 16)?), chooser)? };
    // Fight: the Exor's whole tree, while TargetActor is set.
    let fight = unsafe { spawn_object("BTTask_RunBehavior", tree)? };
    unsafe { write_ptr(&*(fight as *const UObject), "BehaviorAsset", exor_tree)? };
    let fight_entry = unsafe { push_child(root_object, fight, true)? };
    let has_target = unsafe { spawn_object("BTDecorator_Blackboard", tree)? };
    let has_target_object = unsafe { &*(has_target as *const UObject) };
    unsafe {
        select_key(has_target_object, "TargetActor")?;
        write_u8(has_target_object, "OperationType", 0)?; // EBasicKeyOperation::Set
        write_u8(has_target_object, "FlowAbortMode", 3)?; // EBTFlowAbortMode::Both
        add_decorator(fight_entry, has_target)?;
    }
    // Follow: the engine's MoveTo toward the actor in the follow key.
    let follow = unsafe { spawn_object("BTTask_MoveTo", tree)? };
    let follow_object = unsafe { &*(follow as *const UObject) };
    unsafe {
        select_key(follow_object, follow_key)?;
        write_f32(follow_object, "AcceptableRadius", FOLLOW_RADIUS)?;
        ueforge::input::write_class_bool(follow_object, "bTrackMovingGoal", true)?;
        push_child(root_object, follow, true)?;
    }
    // Run it, then put the human in the follow key on the live blackboard.
    let (parms, ret) = unsafe { crate::perception::call_named(controller, "AIController", "RunBehaviorTree", &[("BTAsset", &tree.to_le_bytes())])? };
    let started = parms.get(ret).copied().unwrap_or(0) != 0;
    let board = unsafe { object_ptr(controller, "Blackboard")? };
    if board != 0 && follow_actor != 0 {
        unsafe { crate::perception::call_named(&*(board as *const UObject), "BlackboardComponent", "SetValueAsObject", &[("KeyName", &fname_bytes(follow_key)?), ("ObjectValue", &follow_actor.to_le_bytes())])? };
    }
    Ok(json!({"tree": format!("0x{tree:X}"), "started": started, "blackboard_keys": keys, "follow_key": follow_key, "follow_actor": unsafe { describe(follow_actor) }}))
}

/// Op: build and run her tree; `follow_key` must be an object key of the
/// Exor blackboard (read with ai_player.status), `follow_player` the human.
fn run(args: &Value) -> Result<Value, String> {
    let follow_key = args["follow_key"].as_str().filter(|s| !s.is_empty()).ok_or("follow_key must name an object key of the Exor blackboard")?.to_owned();
    let follow_player = args["follow_player"].as_str().filter(|s| !s.is_empty()).map(str::to_owned);
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(30), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller()? };
        let follow_actor = match follow_player.as_deref() {
            Some(player) => unsafe { crate::nav::player_character(player)? }.1 as *const UObject as u64,
            None => 0,
        };
        unsafe { build_and_run(controller, &follow_key, follow_actor) }
    })
}

/// Op: the keys of the blackboard her controller's tree uses.
fn keys(_: &Value) -> Result<Value, String> {
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller()? };
        let tree = unsafe { object_ptr(controller, "BehaviorTree")? };
        if tree == 0 { return Err("the controller class names no behavior tree".into()); }
        let blackboard = unsafe { object_ptr(&*(tree as *const UObject), "BlackboardAsset")? };
        // The structs' reflected layouts, so a wrong stride is visible rather than guessed.
        let layouts: serde_json::Map<String, Value> = ["BlackboardEntry", "BTCompositeChild", "BlackboardKeySelector"].iter().map(|name| (name.to_string(),
            ueforge::ue::find_struct_fast(name).map(|s| json!({"reported_size": s.properties_size(),
                "fields": s.cached_native_properties().iter().map(|p| format!("{}@{}+{}", p.name, p.offset, p.element_size)).collect::<Vec<_>>()})).unwrap_or(Value::Null))).collect();
        Ok(json!({"keys": unsafe { blackboard_keys(blackboard)? }, "layouts": layouts}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.tree", "Build Sophia's behavior tree in memory (fight with the Exor's tree while TargetActor is set, otherwise follow the actor in follow_key) and run it", "{follow_key: str, follow_player?: str}", run),
        ueforge::ops::OpDef::new("ai_player.blackboard_keys", "The keys of the blackboard her controller's tree declares", "{}", keys),
    ]);
}
