//! Deposit: F6 moves every item in the inventory and the worn backpack
//! into a box within range that already holds that same item. Items with
//! no matching box stay where they are. Hands and worn gear are never
//! touched.
//!
//! The move is the game's own SlotController.MoveToOtherInventory, aimed
//! at the box slot that holds the item; what does not fit that stack goes
//! to the same box's other slots, and nothing is dropped on the floor.
//! Boxes skipped: someone else's (taking from it would be theft), locked
//! ones, the backpack boxes, crafting stations and traders.

use std::collections::{HashMap, HashSet};

use serde_json::{Value as Json, json};
use unityforge::input::{KeyCode, register_key_press};
use unityforge::mono::{
    LogLevel, MonoObject, MonoType, invoke_static, json_handle, log, owned_object,
};

use crate::settings;
use crate::tweaks::read_owner_id;

pub const DEFAULT_RANGE: f64 = 10.0;
const KEY: KeyCode = KeyCode::F6;
const BACKPACK_BOXES: [&str; 3] = ["backpackStorage", "rucksackStorage", "coolerBagStorage"];

pub fn install() {
    if register_key_press(KEY, on_deposit).is_none() {
        log(LogLevel::Error, "obenseuer-mod: deposit key binding failed");
    }
}

extern "C" fn on_deposit() {
    match deposit() {
        Ok((items, boxes)) => {
            let text = format!("{items} items into {boxes} boxes");
            log(LogLevel::Info, &format!("obenseuer-mod: deposit: {text}"));
            notify("Deposit", &text);
        }
        Err(e) => log(LogLevel::Warn, &format!("obenseuer-mod: deposit failed: {e}")),
    }
}

/// Returns how many items moved and into how many boxes.
fn deposit() -> Result<(i64, usize), String> {
    let range = settings::get().get().deposit.range;
    let camera = obj(&invoke_static("UnityEngine.Camera", "get_main", &json!([]))?)
        .ok_or("no main camera")?;
    let centre = position(&camera)?;

    let backpack = first_instance("BackpackStorage")?;
    let mut backpack_boxes = HashSet::new();
    for field in BACKPACK_BOXES {
        if let Some(b) = field_obj(&backpack, field)? {
            backpack_boxes.insert(instance_id(&b)?);
        }
    }

    // Every slot in reach that already holds an item, by item id, with
    // the number of the box it is in.
    let mut by_item: HashMap<i64, Vec<(usize, MonoObject)>> = HashMap::new();
    for (n, storage) in instances("Storage")?.into_iter().enumerate() {
        match takes_deposits(&storage, &backpack_boxes, centre, range) {
            Ok(true) => {}
            Ok(false) => continue,
            Err(e) => {
                log(LogLevel::Warn, &format!("obenseuer-mod: deposit: box skipped: {e}"));
                continue;
            }
        }
        for slot in slots(&storage)? {
            if let Some((id, _)) = contents(&slot)? {
                by_item.entry(id).or_default().push((n, slot));
            }
        }
    }

    let inventory = first_instance("Inventory")?;
    let mut sources = array(&inventory, "Slots")?;
    if let Some(worn) = obj(&backpack.invoke("GetStorage", &json!([]))?) {
        sources.extend(slots(&worn)?);
    }

    let mut moved = 0;
    let mut boxes_used = HashSet::new();
    for source in &sources {
        let Some((id, mut left)) = contents(source)? else {
            continue;
        };
        let Some(targets) = by_item.get(&id) else {
            continue;
        };
        for (n, target) in targets {
            source.invoke(
                "MoveToOtherInventory",
                &json!([{"handle": target.handle().0}, left, null]),
            )?;
            let now = contents(source)?.map_or(0, |(_, amount)| amount);
            if now < left {
                moved += left - now;
                boxes_used.insert(*n);
            }
            left = now;
            if left == 0 {
                break;
            }
        }
    }
    Ok((moved, boxes_used.len()))
}

fn takes_deposits(
    storage: &MonoObject,
    backpack_boxes: &HashSet<i64>,
    centre: [f64; 3],
    range: f64,
) -> Result<bool, String> {
    if backpack_boxes.contains(&instance_id(storage)?) {
        return Ok(false);
    }
    let p = position(storage)?;
    let d2: f64 = (0..3).map(|i| (p[i] - centre[i]).powi(2)).sum();
    if d2 > range * range {
        return Ok(false);
    }
    let permission = storage.read_field("PermissionToTake")?.as_bool().unwrap_or(false);
    if read_owner_id(storage, "StorageOwner") > 1 && !permission {
        return Ok(false);
    }
    if let Some(lock) = field_obj(storage, "_Lock")? {
        if lock.read_field("Locked")?.as_bool().unwrap_or(false) {
            return Ok(false);
        }
    }
    for component in ["Trade", "CraftingBase"] {
        if obj(&storage.invoke("GetComponent", &json!([component]))?).is_some() {
            return Ok(false);
        }
    }
    Ok(true)
}

/// A message in the game's own notification box.
pub(crate) fn notify(title: &str, text: &str) {
    match first_instance("Notifications") {
        Ok(n) => {
            if let Err(e) = n.invoke("CreateNotification", &json!([title, text, false])) {
                log(LogLevel::Warn, &format!("obenseuer-mod: notification failed: {e}"));
            }
        }
        Err(e) => log(LogLevel::Warn, &format!("obenseuer-mod: notification failed: {e}")),
    }
}

/// A storage's slots.
fn slots(storage: &MonoObject) -> Result<Vec<MonoObject>, String> {
    array(storage, "Slots")
}

/// The item id and amount in a slot; None for an empty slot.
fn contents(slot: &MonoObject) -> Result<Option<(i64, i64)>, String> {
    let Some(stack) = field_obj(slot, "itemStack")? else {
        return Ok(None);
    };
    let id = int_field(&stack, "itemId")?;
    let amount = int_field(&stack, "itemAmount")?;
    Ok((id >= 0 && amount > 0).then_some((id, amount)))
}

fn array(owner: &MonoObject, field: &str) -> Result<Vec<MonoObject>, String> {
    let Some(arr) = field_obj(owner, field)? else {
        return Ok(Vec::new());
    };
    let len = int_field(&arr, "Length")?;
    let mut out = Vec::new();
    for i in 0..len {
        if let Some(o) = obj(&arr.invoke("Get", &json!([i]))?) {
            out.push(o);
        }
    }
    Ok(out)
}

fn position(o: &MonoObject) -> Result<[f64; 3], String> {
    let t = obj(&o.invoke("get_transform", &json!([]))?).ok_or("no transform")?;
    let p = t.invoke("get_position", &json!([]))?;
    let c = |k: &str| {
        p.get(k)
            .and_then(Json::as_f64)
            .ok_or_else(|| format!("position has no {k}: {p}"))
    };
    Ok([c("x")?, c("y")?, c("z")?])
}

fn instance_id(o: &MonoObject) -> Result<i64, String> {
    o.invoke("GetInstanceID", &json!([]))?
        .as_i64()
        .ok_or_else(|| "GetInstanceID is not a number".to_string())
}

pub(crate) fn instances(class: &str) -> Result<Vec<MonoObject>, String> {
    instances_with(class, false)
}

/// Live instances of a class; `include_inactive` also takes those on
/// switched-off objects.
pub(crate) fn instances_with(class: &str, include_inactive: bool) -> Result<Vec<MonoObject>, String> {
    let walk = MonoType::find(class)
        .ok_or_else(|| format!("{class} type not found"))?
        .walk(include_inactive)?;
    Ok(walk
        .get("instances")
        .and_then(Json::as_array)
        .map(|a| a.iter().filter_map(obj).collect())
        .unwrap_or_default())
}

pub(crate) fn first_instance(class: &str) -> Result<MonoObject, String> {
    instances(class)?
        .into_iter()
        .next()
        .ok_or_else(|| format!("no live {class}"))
}

fn field_obj(o: &MonoObject, field: &str) -> Result<Option<MonoObject>, String> {
    Ok(obj(&o.read_field(field)?))
}

fn int_field(o: &MonoObject, field: &str) -> Result<i64, String> {
    o.read_field(field)?
        .as_i64()
        .ok_or_else(|| format!("{field} is not a number"))
}

fn obj(v: &Json) -> Option<MonoObject> {
    json_handle(v).map(owned_object)
}
