//! Behavior trees built in memory from a JSON description, the way Epic's
//! own test suite builds them (Engine/Source/Developer/AITestSuite/Public/
//! BTBuilder.h): a UBehaviorTree object, a root composite, children appended
//! to the composite's Children array, decorators to a child's Decorators,
//! services to a composite's Services, then RunBehaviorTree on the
//! controller, whose loader initializes every node from the asset. No file
//! on disk, so a tree can change while the game runs.
//!
//! A node description:
//!
//! ```json
//! {"class": "BTComposite_Selector",
//!  "fields": {},                       // any reflected field, see reflect.rs
//!  "services": [node, ...],            // composites only
//!  "children": [node, ...],            // composites only
//!  "decorators": [node, ...]}          // on a child: gates for that child
//! ```
//!
//! Struct layouts (the child entry, the key selector, the blackboard entry)
//! come from the live reflection, never from headers.
use crate::ue::UObject;
use crate::reflect;
use serde_json::{Value, json};

/// Transfer movement ownership between native combat and assignment movement.
/// The caller prepares game-specific combat keys before entering combat.
#[derive(Default)]
pub struct AiOrderExecution {
    combat: bool,
    initialized: bool,
    destination: Option<([f64; 3], f64)>,
    focus: Option<u64>,
}

impl AiOrderExecution {
    /// # Safety
    /// Controller and combat_tree must be live, on the game thread.
    pub unsafe fn apply(&mut self, controller: &UObject, combat_tree: u64,
        action: &modforge::ai_orders::Action) -> Result<(), String> {
        use modforge::ai_orders::Action;
        let attacking = matches!(action, Action::Attacking { .. });
        let fields = unsafe { reflect::get_fields(controller, &["BrainComponent".into()])? };
        let brain = fields["BrainComponent"]["addr"].as_str().map(|address| reflect::object_ref(&json!(address))).transpose()?.unwrap_or(0);
        let unexpected_running = !attacking && brain != 0 && unsafe { reflect::call(&*(brain as *const UObject), "BrainComponent", "IsRunning", &serde_json::Map::new())? }["ReturnValue"] == true;
        if !self.initialized || self.combat != attacking || unexpected_running {
            // StopLogic aborts the old tree's movement before a new owner starts.
            if brain != 0 {
                    unsafe { reflect::call(&*(brain as *const UObject), "BrainComponent", "StopLogic",
                        json!({"Reason": "AI player assignment"}).as_object().unwrap())? };
            }
            unsafe { reflect::call(controller, "Controller", "StopMovement", &serde_json::Map::new())? };
            if attacking {
                let started = unsafe { reflect::call(controller, "AIController", "RunBehaviorTree",
                    json!({"BTAsset": format!("0x{combat_tree:X}")}).as_object().unwrap())? };
                if started["ReturnValue"] != true { return Err("AI player combat tree refused to start".into()); }
            }
            self.combat = attacking;
            self.initialized = true;
            self.destination = None;
        }
        let focus = match action { Action::Attacking { target } => Some(*target), _ => None };
        if focus != self.focus {
            match focus {
                Some(target) => { unsafe { reflect::call(controller, "AIController", "K2_SetFocus", json!({"NewFocus": format!("0x{target:X}")}).as_object().unwrap())? }; }
                None => { unsafe { reflect::call(controller, "AIController", "K2_ClearFocus", &serde_json::Map::new())? }; }
            }
            self.focus = focus;
        }
        let (position, radius) = match action {
            Action::Following { position, radius } | Action::Holding { position, radius }
                | Action::Returning { position, radius } => (*position, *radius),
            Action::Attacking { .. } => return Ok(()),
            Action::Dead | Action::Blocked { .. } => {
                unsafe { reflect::call(controller, "Controller", "StopMovement", &serde_json::Map::new())? };
                self.destination = None;
                return Ok(());
            }
        };
        let moving = unsafe { reflect::call(controller, "AIController", "GetMoveStatus", &serde_json::Map::new())? }["ReturnValue"].as_u64() == Some(3);
        if moving && self.destination.is_some_and(|(previous, old_radius)|
            old_radius == radius && modforge::ai_orders::distance(previous, position) < radius * 0.5) { return Ok(()); }
        let reply = unsafe { reflect::call(controller, "AIController", "MoveToLocation", json!({
            "Dest": {"X": position[0], "Y": position[1], "Z": position[2]}, "AcceptanceRadius": radius,
            "bStopOnOverlap": false, "bUsePathfinding": true, "bProjectDestinationToNavigation": true,
            "bCanStrafe": true, "FilterClass": null, "bAllowPartialPath": false
        }).as_object().unwrap())? };
        if !matches!(reply["ReturnValue"].as_u64(), Some(1 | 2)) {
            self.destination = None;
            return Err("no complete path to assignment".into());
        }
        self.destination = Some((position, radius));
        Ok(())
    }
}

/// A script struct's element stride and one field's offset from its live
/// reflection. The stride is the end of the last reflected field rounded up
/// to pointer alignment; the UStruct size read is not trusted for structs
/// (it gave 4101 for the 24-byte FBlackboardEntry on Abiotic Factor).
pub fn struct_layout(name: &str, field: &str) -> Result<(usize, usize), String> {
    let layout = crate::ue::find_struct_fast(name).ok_or_else(|| format!("struct {name} not found"))?;
    let properties = layout.cached_native_properties();
    let offset = properties.iter().find(|p| p.name == field).map(|p| p.offset as usize).ok_or_else(|| format!("struct {name} has no field {field}"))?;
    let end = properties.iter().map(|p| (p.offset + p.element_size) as usize).max().ok_or_else(|| format!("struct {name} has no reflected fields"))?;
    Ok((end.div_ceil(8) * 8, offset))
}

/// Append one pointer to a reflected TArray. Game thread.
unsafe fn push_pointer(header: *mut u8, value: u64) -> Result<(), String> {
    // SAFETY: a TArray header is data pointer, count, capacity.
    unsafe {
        let count = ((header as usize + 8) as *const i32).read_unaligned();
        crate::ue::tarray::grow_raw(header, 8, count + 1)?;
        let data = (header as *const *mut u64).read_unaligned();
        data.add(count as usize).write_unaligned(value);
        ((header as usize + 8) as *mut i32).write_unaligned(count + 1);
    }
    Ok(())
}

/// Append a child (task or composite) to a composite's Children, the
/// engine's FBTCompositeChild, zeroed then filled. Returns the entry address.
unsafe fn push_child(composite: &UObject, child: u64, is_task: bool) -> Result<usize, String> {
    let (stride, composite_offset) = struct_layout("BTCompositeChild", "ChildComposite")?;
    let (_, task_offset) = struct_layout("BTCompositeChild", "ChildTask")?;
    let header = unsafe { composite.field_ptr(crate::input::class_property_offset(composite, "Children", 16)?) };
    // SAFETY: the Children TArray header on the live composite; the new element is zeroed before use.
    unsafe {
        let count = ((header as usize + 8) as *const i32).read_unaligned();
        crate::ue::tarray::grow_raw(header, stride, count + 1)?;
        let data = (header as *const *mut u8).read_unaligned();
        let entry = data.add(count as usize * stride);
        std::ptr::write_bytes(entry, 0, stride);
        (entry.add(if is_task { task_offset } else { composite_offset }) as *mut u64).write_unaligned(child);
        ((header as usize + 8) as *mut i32).write_unaligned(count + 1);
        Ok(entry as usize)
    }
}

/// Is this node class a composite (has Children) rather than a task?
fn is_composite(node: &UObject) -> bool {
    crate::input::class_property_offset(node, "Children", 16).is_ok()
}

/// Build one node and everything under it, owned by `tree`. Game thread.
unsafe fn build_node(tree: u64, spec: &Value) -> Result<u64, String> {
    let class = spec["class"].as_str().ok_or_else(|| format!("node needs a class: {spec}"))?;
    let node = unsafe { reflect::spawn_object(class, tree)? };
    // SAFETY: the node the engine just created.
    let node_object = unsafe { &*(node as *const UObject) };
    if let Some(fields) = spec["fields"].as_object() { unsafe { reflect::set_fields(node_object, fields)? }; }
    for service in spec["services"].as_array().into_iter().flatten() {
        let built = unsafe { build_node(tree, service)? };
        let header = unsafe { node_object.field_ptr(crate::input::class_property_offset(node_object, "Services", 16)?) };
        unsafe { push_pointer(header, built)? };
    }
    for child in spec["children"].as_array().into_iter().flatten() {
        let built = unsafe { build_node(tree, child)? };
        // SAFETY: the child the recursion just built.
        let task = !is_composite(unsafe { &*(built as *const UObject) });
        let entry = unsafe { push_child(node_object, built, task)? };
        let (_, decorators) = struct_layout("BTCompositeChild", "Decorators")?;
        for decorator in child["decorators"].as_array().into_iter().flatten() {
            let built = unsafe { build_node(tree, decorator)? };
            unsafe { push_pointer((entry + decorators) as *mut u8, built)? };
        }
    }
    Ok(node)
}

/// Build a whole tree: a UBehaviorTree owned by `outer` on `blackboard`,
/// with `root` as its root node description. Every node is created and
/// filled before the root is linked, so a failed step leaves nothing
/// half-built in a running tree. Game thread.
///
/// # Safety
/// `outer` must be live.
pub unsafe fn build(outer: u64, blackboard: u64, root: &Value) -> Result<u64, String> {
    let tree = unsafe { reflect::spawn_object("BehaviorTree", outer)? };
    let root_node = unsafe { build_node(tree, root)? };
    // SAFETY: the tree object the engine just created.
    let tree_object = unsafe { &*(tree as *const UObject) };
    unsafe { reflect::set_fields(tree_object, json!({"BlackboardAsset": format!("0x{blackboard:X}"), "RootNode": format!("0x{root_node:X}")}).as_object().unwrap())? };
    Ok(tree)
}

/// The keys a blackboard asset declares, parents first: (name, key type class). Game thread.
///
/// # Safety
/// `asset` must be a live UBlackboardData.
pub unsafe fn blackboard_keys(asset: u64) -> Result<Vec<(String, String)>, String> {
    let (stride, name_offset) = struct_layout("BlackboardEntry", "EntryName")?;
    let (_, type_offset) = struct_layout("BlackboardEntry", "KeyType")?;
    let mut chain = Vec::new();
    let mut current = asset;
    while current != 0 && chain.len() < 8 {
        chain.push(current);
        // SAFETY: a live blackboard asset.
        current = unsafe { reflect::get_fields(&*(current as *const UObject), &["Parent".into()])? }["Parent"]["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0);
    }
    let mut keys = Vec::new();
    for asset in chain.into_iter().rev() {
        // SAFETY: a live blackboard asset and its Keys TArray of FBlackboardEntry.
        let object = unsafe { &*(asset as *const UObject) };
        let header = unsafe { object.field_ptr(crate::input::class_property_offset(object, "Keys", 16)?) };
        let (data, count) = unsafe { ((header as *const *const u8).read_unaligned(), ((header as usize + 8) as *const i32).read_unaligned()) };
        for index in 0..count.max(0) as usize {
            let name = unsafe { crate::ue::fname::read_at(data.add(index * stride), name_offset) }.unwrap_or_default();
            let key_type = unsafe { (data.add(index * stride + type_offset) as *const u64).read_unaligned() };
            let type_name = if key_type == 0 { String::new() } else { unsafe { &*(key_type as *const UObject) }.class().map(|c| c.as_object().name()).unwrap_or_default() };
            keys.push((name, type_name));
        }
    }
    Ok(keys)
}

/// The suffix of the BlackboardComponent getter and setter for a key type class.
fn accessor(key_type: &str) -> Option<&'static str> {
    Some(match key_type {
        "BlackboardKeyType_Object" => "Object",
        "BlackboardKeyType_Class" => "Class",
        "BlackboardKeyType_Bool" => "Bool",
        "BlackboardKeyType_Int" => "Int",
        "BlackboardKeyType_Float" => "Float",
        "BlackboardKeyType_Vector" => "Vector",
        "BlackboardKeyType_Rotator" => "Rotator",
        "BlackboardKeyType_Name" => "Name",
        "BlackboardKeyType_String" => "String",
        "BlackboardKeyType_Enum" => "Enum",
        _ => return None,
    })
}

/// A controller's live blackboard component and its asset's keys. Game thread.
unsafe fn blackboard_of(controller: &UObject) -> Result<(&'static UObject, Vec<(String, String)>), String> {
    let fields = unsafe { reflect::get_fields(controller, &["Blackboard".into()])? };
    let board = fields["Blackboard"]["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0);
    if board == 0 { return Err("the controller has no blackboard component; run a tree first".into()); }
    // SAFETY: the live blackboard component.
    let board = unsafe { &*(board as *const UObject) };
    let asset = unsafe { reflect::get_fields(board, &["BlackboardAsset".into()])? }["BlackboardAsset"]["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0);
    if asset == 0 { return Err("the blackboard component has no asset".into()); }
    Ok((board, unsafe { blackboard_keys(asset)? }))
}

/// Read blackboard keys by name (all when none given), each through the
/// engine's GetValueAs* for its declared type. Game thread.
pub unsafe fn blackboard_get(controller: &UObject, names: &[String]) -> Result<Value, String> {
    let (board, keys) = unsafe { blackboard_of(controller)? };
    let mut out = serde_json::Map::new();
    for (name, key_type) in &keys {
        if !names.is_empty() && !names.contains(name) { continue; }
        let Some(suffix) = accessor(key_type) else { out.insert(name.clone(), json!(format!("<{key_type}>"))); continue };
        let reply = unsafe { reflect::call(board, "BlackboardComponent", &format!("GetValueAs{suffix}"), json!({"KeyName": name}).as_object().unwrap())? };
        out.insert(name.clone(), reply["ReturnValue"].clone());
    }
    Ok(Value::Object(out))
}

/// Write blackboard keys from a JSON map through SetValueAs* for each key's type. Game thread.
pub unsafe fn blackboard_set(controller: &UObject, values: &serde_json::Map<String, Value>) -> Result<(), String> {
    let (board, keys) = unsafe { blackboard_of(controller)? };
    for (name, value) in values {
        let (_, key_type) = keys.iter().find(|(k, _)| k == name).ok_or_else(|| format!("no blackboard key {name}; keys: {keys:?}"))?;
        let suffix = accessor(key_type).ok_or_else(|| format!("{name} is a {key_type} key, which has no setter here"))?;
        let parameter = match suffix { "Object" => "ObjectValue", "Class" => "ClassValue", "Bool" => "BoolValue", "Int" => "IntValue", "Float" => "FloatValue", "Vector" => "VectorValue", "Rotator" => "RotatorValue", "Name" => "NameValue", "String" => "StringValue", _ => "EnumValue" };
        unsafe { reflect::call(board, "BlackboardComponent", &format!("SetValueAs{suffix}"), json!({"KeyName": name, parameter: value}).as_object().unwrap())? };
    }
    Ok(())
}

/// The ops: bt.build, bt.run, bt.stop, bt.keys, bb.get, bb.set.
pub fn register_ops(drain: &'static crate::pe_queue::GameThread, hint: &'static str) {
    use crate::ops::{OP_REGISTRY, OpDef};
    let job = move |timeout: u64, f: Box<dyn FnOnce() -> Result<Value, String> + Send>| -> Result<Value, String> {
        crate::debug::enqueue_pe(drain, std::time::Duration::from_secs(timeout), hint, f)
    };
    OP_REGISTRY.register_many([
        OpDef::new("bt.build", "Build a behavior tree in memory from a node description, owned by outer, on a blackboard asset (0x address or asset:Path.Name); returns the tree's address", "{outer: selector, blackboard: ref, root: node}", move |args| {
            let outer = args["outer"].as_str().ok_or("outer must be a selector")?.to_owned();
            let blackboard = args["blackboard"].clone();
            let root = args["root"].clone();
            job(30, Box::new(move || {
                let outer = crate::selector::resolve(&outer)? as *const UObject as u64;
                let blackboard = reflect::object_ref(&blackboard)?;
                if blackboard == 0 { return Err("blackboard resolved to null".into()); }
                let tree = unsafe { build(outer, blackboard, &root)? };
                Ok(json!({"tree": format!("0x{tree:X}")}))
            }))
        }),
        OpDef::new("bt.run", "RunBehaviorTree on a controller with a tree (0x address or asset:Path.Name)", "{controller: selector, tree: ref}", move |args| {
            let controller = args["controller"].as_str().ok_or("controller must be a selector")?.to_owned();
            let tree = args["tree"].clone();
            job(30, Box::new(move || {
                let controller = crate::selector::resolve(&controller)?;
                let tree = reflect::object_ref(&tree)?;
                let reply = unsafe { reflect::call(controller, "AIController", "RunBehaviorTree", json!({"BTAsset": format!("0x{tree:X}")}).as_object().unwrap())? };
                Ok(json!({"started": reply["ReturnValue"]}))
            }))
        }),
        OpDef::new("bt.stop", "Stop a controller's brain (BrainComponent::StopLogic)", "{controller: selector}", move |args| {
            let controller = args["controller"].as_str().ok_or("controller must be a selector")?.to_owned();
            job(10, Box::new(move || {
                let controller = crate::selector::resolve(&controller)?;
                let brain = unsafe { reflect::get_fields(controller, &["BrainComponent".into()])? }["BrainComponent"]["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0);
                if brain == 0 { return Ok(json!({"stopped": false, "reason": "no brain component"})); }
                // SAFETY: the live brain component.
                unsafe { reflect::call(&*(brain as *const UObject), "BrainComponent", "StopLogic", json!({"Reason": ""}).as_object().unwrap())? };
                Ok(json!({"stopped": true}))
            }))
        }),
        OpDef::new("bt.keys", "The keys a blackboard asset declares (0x address or asset:Path.Name), parents first, with their key types", "{blackboard: ref}", move |args| {
            let blackboard = args["blackboard"].clone();
            job(10, Box::new(move || { let asset = reflect::object_ref(&blackboard)?; Ok(json!({"keys": unsafe { blackboard_keys(asset)? }})) }))
        }),
        OpDef::new("bb.get", "Read a controller's blackboard keys by name (all when none given) through GetValueAs* for each key's declared type", "{controller: selector, keys?: [str]}", move |args| {
            let controller = args["controller"].as_str().ok_or("controller must be a selector")?.to_owned();
            let names: Vec<String> = args["keys"].as_array().into_iter().flatten().filter_map(|v| v.as_str().map(str::to_owned)).collect();
            job(10, Box::new(move || { let controller = crate::selector::resolve(&controller)?; unsafe { blackboard_get(controller, &names) } }))
        }),
        OpDef::new("bb.set", "Write a controller's blackboard keys from a JSON map through SetValueAs* for each key's declared type", "{controller: selector, values: {key: value}}", move |args| {
            let controller = args["controller"].as_str().ok_or("controller must be a selector")?.to_owned();
            let values = args["values"].as_object().cloned().ok_or("values must be an object")?;
            job(10, Box::new(move || { let controller = crate::selector::resolve(&controller)?; unsafe { blackboard_set(controller, &values)? }; Ok(json!({"written": values.len()})) }))
        }),
    ]);
}
