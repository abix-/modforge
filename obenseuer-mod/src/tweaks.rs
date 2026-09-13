use std::ffi::c_void;
use std::sync::atomic::{AtomicBool, AtomicI32, Ordering};

use serde_json::json;
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_postfix, patch_prefix_ctx};
use unityforge::mono::{MonoObject, MonoType, json_handle, owned_object};

use crate::settings;

pub const DEFAULT_SLOT_COUNT: i32 = 70;
pub const DEFAULT_STACK_MULTIPLIER: i32 = 10;

static INVENTORY_PATCHED: AtomicBool = AtomicBool::new(false);
static ITEMS_PATCHED: AtomicBool = AtomicBool::new(false);
static TRADES_DUMPED: AtomicBool = AtomicBool::new(false);
static ITEM_DB_HANDLE: AtomicI32 = AtomicI32::new(0);
static INV_HANDLE: AtomicI32 = AtomicI32::new(0);

const BASE_SLOT_COUNT: i32 = 35;
const GRID_COLUMNS: i32 = 5;

pub fn install() {
    let cfg = settings::get().get();

    match patch_prefix_ctx(
        "Inventory",
        "Awake",
        HookCtx::Instance,
        on_inventory_awake,
    ) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            unityforge::mono::log(
                unityforge::mono::LogLevel::Info,
                &format!(
                    "obenseuer-mod: inventory patch armed (slots={})",
                    cfg.inventory.slot_count
                ),
            );
        }
        Err(e) => unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            &format!("obenseuer-mod: inventory patch failed: {e}"),
        ),
    }

    match patch_prefix_ctx("Inventory", "Start", HookCtx::Instance, on_inventory_start_prefix) {
        Ok(hook) => HOOK_REGISTRY.register(hook),
        Err(e) => unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            &format!("obenseuer-mod: Inventory.Start prefix failed: {e}"),
        ),
    }

    match patch_postfix("Inventory", "Start", on_inventory_start_postfix) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            unityforge::mono::log(
                unityforge::mono::LogLevel::Info,
                "obenseuer-mod: inventory UI resize patch armed",
            );
        }
        Err(e) => unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            &format!("obenseuer-mod: Inventory.Start postfix failed: {e}"),
        ),
    }

    match patch_prefix_ctx(
        "ItemDatabase",
        "Awake",
        HookCtx::Instance,
        on_item_db_prefix,
    ) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
        }
        Err(e) => unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            &format!("obenseuer-mod: ItemDatabase prefix patch failed: {e}"),
        ),
    }

    match patch_postfix("ItemDatabase", "Awake", on_item_db_postfix) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            unityforge::mono::log(
                unityforge::mono::LogLevel::Info,
                &format!(
                    "obenseuer-mod: stack patch armed (multiplier={}x)",
                    cfg.stacks.multiplier
                ),
            );
        }
        Err(e) => unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            &format!("obenseuer-mod: stack patch failed: {e}"),
        ),
    }
}

extern "C" fn on_inventory_awake(ctx: *const c_void) -> i32 {
    let h = ctx as isize as i32;
    if h == 0 {
        return 0;
    }
    let slot_count = settings::get().get().inventory.slot_count;
    let obj = owned_object(h);
    if let Err(e) = obj.write_field("slotAmount", &json!(slot_count)) {
        unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            &format!("obenseuer-mod: set slotAmount failed: {e}"),
        );
        return 0;
    }
    if !INVENTORY_PATCHED.swap(true, Ordering::Relaxed) {
        unityforge::mono::log(
            unityforge::mono::LogLevel::Info,
            &format!("obenseuer-mod: inventory slots set to {slot_count}"),
        );
    }
    0
}

extern "C" fn on_inventory_start_prefix(ctx: *const c_void) -> i32 {
    let h = ctx as isize as i32;
    INV_HANDLE.store(h, Ordering::Release);
    0
}

extern "C" fn on_inventory_start_postfix(_ctx: *const c_void) {
    let slot_count = settings::get().get().inventory.slot_count;
    if slot_count <= BASE_SLOT_COUNT {
        return;
    }

    let h = INV_HANDLE.swap(0, Ordering::Acquire);
    if h == 0 {
        return;
    }

    if let Err(e) = resize_inventory_panel(h, slot_count) {
        unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            &format!("obenseuer-mod: inventory UI resize failed: {e}"),
        );
    }

    dump_trade_info();
}

fn resize_inventory_panel(inv_handle: i32, slot_count: i32) -> Result<(), String> {
    let inv = owned_object(inv_handle);
    let panel_ui_val = inv.read_field("inventoryPanelUI")?;
    let panel_ui_h = json_handle(&panel_ui_val).ok_or("inventoryPanelUI has no handle")?;
    let panel_ui = owned_object(panel_ui_h);

    let slot_panel_val = panel_ui.read_field("inventorySlotPanel")?;
    let slot_panel_h = json_handle(&slot_panel_val).ok_or("inventorySlotPanel has no handle")?;
    let slot_panel = owned_object(slot_panel_h);

    let grid_val = slot_panel.invoke("GetComponent", &json!(["GridLayoutGroup"]))?;
    let grid_h = json_handle(&grid_val).ok_or("GridLayoutGroup not found")?;
    let grid = owned_object(grid_h);

    let old_cols = grid
        .read_field("m_ConstraintCount")
        .ok()
        .and_then(|v| v.as_i64())
        .unwrap_or(GRID_COLUMNS as i64) as i32;

    let base_rows = (BASE_SLOT_COUNT + old_cols - 1) / old_cols;
    let new_cols = (slot_count + base_rows - 1) / base_rows;

    grid.write_field("m_ConstraintCount", &json!(new_cols))?;

    let rt_val = slot_panel.invoke("GetComponent", &json!(["RectTransform"]))?;
    let rt_h = json_handle(&rt_val).ok_or("RectTransform not found")?;
    let rt = owned_object(rt_h);

    let size_val = rt.invoke("get_sizeDelta", &json!([]))?;
    let cur_x = size_val.get("x").and_then(|v| v.as_f64()).unwrap_or(0.0);
    let cur_y = size_val.get("y").and_then(|v| v.as_f64()).unwrap_or(0.0);

    let col_width = cur_x / old_cols as f64;
    let new_x = col_width * new_cols as f64;
    let extra_x = new_x - cur_x;

    rt.invoke("set_sizeDelta", &json!([{"x": new_x, "y": cur_y}]))?;

    let pos_val = rt.invoke("get_anchoredPosition", &json!([]))?;
    let cur_px = pos_val.get("x").and_then(|v| v.as_f64()).unwrap_or(0.0);
    let cur_py = pos_val.get("y").and_then(|v| v.as_f64()).unwrap_or(0.0);
    let new_px = cur_px - extra_x;

    rt.invoke("set_anchoredPosition", &json!([{"x": new_px, "y": cur_py}]))?;

    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        &format!(
            "obenseuer-mod: inventory grid {old_cols}x{base_rows} -> {new_cols}x{base_rows} (width {cur_x:.0} -> {new_x:.0}, shifted left by {:.0})",
            extra_x
        ),
    );
    Ok(())
}

extern "C" fn on_item_db_prefix(ctx: *const c_void) -> i32 {
    let h = ctx as isize as i32;
    ITEM_DB_HANDLE.store(h, Ordering::Release);
    0
}

extern "C" fn on_item_db_postfix(_ctx: *const c_void) {
    let multiplier = settings::get().get().stacks.multiplier;
    if multiplier <= 1 {
        return;
    }

    let h = ITEM_DB_HANDLE.swap(0, Ordering::Acquire);
    if h == 0 {
        unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            "obenseuer-mod: no ItemDatabase handle from prefix",
        );
        return;
    }

    let instance = owned_object(h);
    let items_result = instance.invoke("GetDatabase", &json!([]));
    match items_result {
        Ok(arr_val) => {
            if let Some(arr_handle) = json_handle(&arr_val) {
                let arr = owned_object(arr_handle);
                match apply_stack_multiplier_array(&arr, multiplier) {
                    Ok(n) => {
                        if !ITEMS_PATCHED.swap(true, Ordering::Relaxed) {
                            unityforge::mono::log(
                                unityforge::mono::LogLevel::Info,
                                &format!(
                                    "obenseuer-mod: stacks multiplied by {multiplier}x on {n} items"
                                ),
                            );
                        }
                    }
                    Err(e) => unityforge::mono::log(
                        unityforge::mono::LogLevel::Warn,
                        &format!("obenseuer-mod: stack multiply failed: {e}"),
                    ),
                }
            }
        }
        Err(e) => unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            &format!("obenseuer-mod: GetDatabase() failed: {e}"),
        ),
    }
}

fn apply_stack_multiplier_array(arr: &MonoObject, multiplier: i32) -> Result<usize, String> {
    let len = arr
        .read_field("Length")?
        .as_i64()
        .ok_or("Length is not an integer")? as usize;
    let mut patched = 0;
    for i in 0..len {
        let item_val = arr.invoke("Get", &json!([i as i64]))?;
        let Some(item_handle) = json_handle(&item_val) else {
            continue;
        };
        let item = owned_object(item_handle);
        let stackable = item
            .read_field("Stackable")?
            .as_i64()
            .ok_or("Stackable is not an integer")?;
        if stackable > 1 {
            let new_val = (stackable as i32).saturating_mul(multiplier);
            item.write_field("Stackable", &json!(new_val))?;
            patched += 1;
        }
    }
    Ok(patched)
}

fn dump_trade_info() {
    if TRADES_DUMPED.swap(true, Ordering::Relaxed) {
        return;
    }

    let Some(trade_type) = MonoType::find("Trade") else {
        unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            "obenseuer-mod: trade dump: Trade type not found",
        );
        return;
    };

    let trades_json = match trade_type.walk(true) {
        Ok(j) => j,
        Err(e) => {
            unityforge::mono::log(
                unityforge::mono::LogLevel::Warn,
                &format!("obenseuer-mod: trade dump: walk failed: {e}"),
            );
            return;
        }
    };

    let Some(trades) = trades_json
        .get("instances")
        .and_then(|v| v.as_array())
    else {
        unityforge::mono::log(
            unityforge::mono::LogLevel::Warn,
            "obenseuer-mod: trade dump: walk returned no instances array",
        );
        return;
    };

    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        &format!("=== TRADE DUMP: {} traders found ===", trades.len()),
    );

    for (i, trade_val) in trades.iter().enumerate() {
        let Some(h) = json_handle(trade_val) else { continue };
        let obj = owned_object(h);

        let name = obj
            .invoke("get_name", &json!([]))
            .ok()
            .and_then(|v| v.as_str().map(String::from))
            .unwrap_or_else(|| "?".into());

        let sell = obj
            .read_field("baseSellPrice")
            .ok()
            .and_then(|v| v.as_f64())
            .unwrap_or(0.0);
        let buy = obj
            .read_field("basePurchasePrice")
            .ok()
            .and_then(|v| v.as_f64())
            .unwrap_or(0.0);
        let money_min = obj
            .read_field("traderMoneyAmountMin")
            .ok()
            .and_then(|v| v.as_i64())
            .unwrap_or(0);
        let money_max = obj
            .read_field("traderMoneyAmountMax")
            .ok()
            .and_then(|v| v.as_i64())
            .unwrap_or(0);
        let current = obj
            .read_field("currentMoney")
            .ok()
            .and_then(|v| v.as_f64())
            .unwrap_or(-1.0);
        let stolen = obj
            .read_field("buysStolen")
            .ok()
            .and_then(|v| v.as_bool())
            .unwrap_or(false);
        let is_open = obj
            .read_field("open")
            .ok()
            .and_then(|v| v.as_bool())
            .unwrap_or(false);
        let destroy = obj
            .read_field("destroyPurchasedItems")
            .ok()
            .and_then(|v| v.as_bool())
            .unwrap_or(false);
        let sell_mode = obj
            .read_field("sellPriceMode")
            .ok()
            .and_then(|v| v.as_i64())
            .unwrap_or(1);
        let buy_mode = obj
            .read_field("purchasePriceMode")
            .ok()
            .and_then(|v| v.as_i64())
            .unwrap_or(1);

        let currency_name = |mode: i64| if mode == 0 { "RM" } else { "OC" };

        let owner_id = read_owner_id(&obj);

        unityforge::mono::log(
            unityforge::mono::LogLevel::Info,
            &format!(
                "Trade[{i}] \"{name}\" owner={owner_id} open={is_open} sell={sell}/{} buy={buy}/{} money={current:.0}({money_min}-{money_max}) stolen={stolen} destroy={destroy}",
                currency_name(sell_mode),
                currency_name(buy_mode),
            ),
        );

        if let Ok(arr_val) = obj.read_field("allowedCategories") {
            let cats = read_mono_string_array(&arr_val);
            if !cats.is_empty() {
                unityforge::mono::log(
                    unityforge::mono::LogLevel::Info,
                    &format!("  allowed: {}", cats.join(", ")),
                );
            }
        }
        if let Ok(arr_val) = obj.read_field("forbiddenCategories") {
            let cats = read_mono_string_array(&arr_val);
            if !cats.is_empty() {
                unityforge::mono::log(
                    unityforge::mono::LogLevel::Info,
                    &format!("  forbidden: {}", cats.join(", ")),
                );
            }
        }
    }

    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        "=== END TRADE DUMP ===",
    );
}

fn read_owner_id(obj: &MonoObject) -> i64 {
    let Ok(owner_val) = obj.read_field("owner") else {
        return -1;
    };
    if let Some(id) = owner_val.get("ID").and_then(|x| x.as_i64()) {
        return id;
    }
    if let Some(oh) = json_handle(&owner_val) {
        let owner_obj = owned_object(oh);
        if let Ok(id_val) = owner_obj.read_field("ID") {
            if let Some(id) = id_val.as_i64() {
                return id;
            }
        }
    }
    -1
}

fn read_mono_string_array(arr_val: &serde_json::Value) -> Vec<String> {
    let Some(arr_h) = json_handle(arr_val) else {
        return vec![];
    };
    let arr = owned_object(arr_h);
    let len = arr
        .read_field("Length")
        .ok()
        .and_then(|v| v.as_i64())
        .unwrap_or(0) as usize;
    let mut result = Vec::new();
    for i in 0..len {
        if let Ok(s) = arr.invoke("Get", &json!([i as i64])) {
            if let Some(text) = s.as_str() {
                result.push(text.to_string());
            }
        }
    }
    result
}
