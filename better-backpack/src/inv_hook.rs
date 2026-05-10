// WBP_InventoryInterface_C ProcessEvent hook + viewport rebind.
//
// Keeps the visible 4x10 grid; scrolls by rebinding visible slots against a
// shifting `ItemStartIndex`. Applies the audit fixes:
//   - Function dispatch by cached `&UFunction` pointer identity, not by
//     name string compare.
//   - Trace logging gated under `cfg!(debug_assertions)` -- no chatter in
//     release builds.
//   - Single hook surface (WBP_InventoryInterface_C). No more hooking
//     generic Widget/UserWidget/PanelWidget for trace coverage.

#![allow(dead_code)]

use std::ffi::c_void;
use std::sync::atomic::{AtomicBool, AtomicI32, Ordering};
use std::sync::{Mutex, OnceLock};

use ueforge::hook::{OriginalProcessEvent, ProcessEventHook};
use crate::parms::{
    F_POINTER_EVENT_SIZE, GetChildAtParms, GetInventoryItemsParms, GetItemInItemListSlotParms,
    InitializeItemSlotParms, IntReturnParms, OnMouseWheelInputView, PointerEventGetWheelDeltaParms,
    SelectedIndexParms, SetSelectedInventorySlotParms,
};
use ueforge::ue::{self, UClass, UFunction, UObject, find_class_fast};

const VIEWPORT_ROWS: i32 = 4;
const VIEWPORT_COLUMNS: i32 = 10;
const VIEWPORT_PAGE_SIZE: i32 = VIEWPORT_ROWS * VIEWPORT_COLUMNS;
const SCROLL_STEP_SLOTS: i32 = VIEWPORT_COLUMNS;
const INV_IFACE_ITEM_GRID_OFFSET: usize = 0x0430;

// Cached UFunction pointers for identity dispatch. Captured once at hook
// install. Wrapped in raw `usize` because UFunction references aren't
// `Send` / `Sync`-clean and we only need pointer identity.
struct InvIfaceFns {
    populate_item_grid: usize,
    construct: usize,
    on_mouse_wheel: usize,
    on_inventory_changed: usize,
    on_inventory_count_changed: usize,
    refresh_ui: usize,
    refresh_menu_page: usize,
    get_inventory_items: usize,
    get_selected_inventory_slot_index: usize,
    set_selected_inventory_slot: usize,
    initialize_item_slot: usize,
}

struct PanelFns {
    get_children_count: usize,
    get_child_at: usize,
}

struct BpfFns {
    cdo: *const UObject,
    get_item_in_item_list_slot: usize,
}

struct KismetInputFns {
    cdo: *const UObject,
    pointer_event_get_wheel_delta: usize,
}

struct State {
    inv_iface: InvIfaceFns,
    panel: PanelFns,
    bpf: BpfFns,
    kismet: KismetInputFns,
    slot_count: AtomicI32,
    viewport_starts: Mutex<Vec<(usize, i32)>>, // (widget_ptr_as_usize, start_index)
    in_synthetic_refresh: AtomicBool,
}

unsafe impl Send for State {}
unsafe impl Sync for State {}

static STATE: OnceLock<State> = OnceLock::new();

pub fn install(slot_count: i32) -> Result<ProcessEventHook, &'static str> {
    let inv_iface_class = find_class_fast("WBP_InventoryInterface_C")
        .ok_or("WBP_InventoryInterface_C not loaded yet")?;
    let panel_widget = find_class_fast("PanelWidget").ok_or("PanelWidget not loaded")?;
    let bpf_class =
        find_class_fast("BPF_InventoryFunctions_C").ok_or("BPF_InventoryFunctions_C not loaded")?;
    let kismet_class =
        find_class_fast("KismetInputLibrary").ok_or("KismetInputLibrary not loaded")?;

    let inv_fns = InvIfaceFns {
        populate_item_grid: lookup(
            inv_iface_class,
            "WBP_InventoryInterface_C",
            "PopulateItemGrid",
        )?,
        construct: lookup(inv_iface_class, "WBP_InventoryInterface_C", "Construct")?,
        on_mouse_wheel: lookup(inv_iface_class, "WBP_InventoryInterface_C", "OnMouseWheel")?,
        on_inventory_changed: lookup_optional(
            inv_iface_class,
            "WBP_InventoryInterface_C",
            "OnInventoryChanged",
        ),
        on_inventory_count_changed: lookup_optional(
            inv_iface_class,
            "WBP_InventoryInterface_C",
            "OnInventoryCountChanged",
        ),
        refresh_ui: lookup_optional(inv_iface_class, "WBP_InventoryInterface_C", "RefreshUI"),
        refresh_menu_page: lookup_optional(
            inv_iface_class,
            "WBP_InventoryInterface_C",
            "RefreshMenuPage",
        ),
        get_inventory_items: lookup(
            inv_iface_class,
            "WBP_InventoryInterface_C",
            "GetInventoryItems",
        )?,
        get_selected_inventory_slot_index: lookup_optional(
            inv_iface_class,
            "WBP_InventoryInterface_C",
            "GetSelectedInventorySlotIndex",
        ),
        set_selected_inventory_slot: lookup_optional(
            inv_iface_class,
            "WBP_InventoryInterface_C",
            "SetSelectedInventorySlot",
        ),
        initialize_item_slot: lookup(
            inv_iface_class,
            "WBP_InventoryInterface_C",
            "InitializeItemSlot",
        )?,
    };
    let panel = PanelFns {
        get_children_count: lookup(panel_widget, "PanelWidget", "GetChildrenCount")?,
        get_child_at: lookup(panel_widget, "PanelWidget", "GetChildAt")?,
    };
    let bpf = BpfFns {
        cdo: bpf_class.class_default_object().ok_or("BPF CDO missing")? as *const UObject,
        get_item_in_item_list_slot: lookup(
            bpf_class,
            "BPF_InventoryFunctions_C",
            "GetItemInItemListSlot",
        )?,
    };
    let kismet = KismetInputFns {
        cdo: kismet_class
            .class_default_object()
            .ok_or("KismetInputLibrary CDO missing")? as *const UObject,
        pointer_event_get_wheel_delta: lookup(
            kismet_class,
            "KismetInputLibrary",
            "PointerEvent_GetWheelDelta",
        )?,
    };

    let _ = STATE.set(State {
        inv_iface: inv_fns,
        panel,
        bpf,
        kismet,
        slot_count: AtomicI32::new(slot_count),
        viewport_starts: Mutex::new(Vec::new()),
        in_synthetic_refresh: AtomicBool::new(false),
    });

    ueforge::log!("inv hook: installing on WBP_InventoryInterface_C");
    ProcessEventHook::install("WBP_InventoryInterface_C", on_event)
}

pub fn update_slot_count(slot_count: i32) {
    if let Some(state) = STATE.get() {
        state.slot_count.store(slot_count, Ordering::Release);
        ueforge::log!("inv hook: slot_count updated to {}", slot_count);
    }
}

/// Currently-applied slot count (after backpack apply). 0 if the
/// hook hasn't installed yet. Used by the debug snapshot.
pub fn current_slot_count() -> i32 {
    STATE
        .get()
        .map(|s| s.slot_count.load(Ordering::Acquire))
        .unwrap_or(0)
}

fn lookup(cls: &UClass, owner: &str, name: &str) -> Result<usize, &'static str> {
    cls.get_function(owner, name)
        .map(|f| f as *const UFunction as usize)
        .ok_or("function not found on inventory interface")
}

fn lookup_optional(cls: &UClass, owner: &str, name: &str) -> usize {
    cls.get_function(owner, name)
        .map(|f| f as *const UFunction as usize)
        .unwrap_or(0)
}

fn on_event(
    this: &UObject,
    function: &UFunction,
    parms: *mut c_void,
    original: OriginalProcessEvent,
) {
    let Some(state) = STATE.get() else {
        unsafe { original.call(this, function, parms) };
        return;
    };

    if state.in_synthetic_refresh.load(Ordering::Acquire) {
        unsafe { original.call(this, function, parms) };
        return;
    }

    let fn_id = function as *const UFunction as usize;

    if fn_id == state.inv_iface.construct {
        set_viewport_start(state, this, 0);
    }

    unsafe { original.call(this, function, parms) };

    if fn_id == state.inv_iface.on_mouse_wheel {
        handle_mouse_wheel(state, this, parms);
    } else if matches_any(
        fn_id,
        &[
            state.inv_iface.on_inventory_changed,
            state.inv_iface.on_inventory_count_changed,
            state.inv_iface.refresh_ui,
            state.inv_iface.refresh_menu_page,
            state.inv_iface.populate_item_grid,
        ],
    ) && get_viewport_start(state, this) != 0
    {
        let cur = get_viewport_start(state, this);
        let _ = rebind(state, this, cur, "post-refresh");
    }
}

fn matches_any(fn_id: usize, set: &[usize]) -> bool {
    fn_id != 0 && set.iter().any(|&s| s != 0 && s == fn_id)
}

fn handle_mouse_wheel(state: &State, widget: &UObject, parms: *mut c_void) {
    let slot_count = state.slot_count.load(Ordering::Acquire);
    if slot_count <= VIEWPORT_PAGE_SIZE || parms.is_null() {
        return;
    }
    let view = unsafe { &*(parms as *const OnMouseWheelInputView) };
    let Some(delta) = pointer_wheel_delta(state, &view.mouse_event) else {
        return;
    };

    let cur = get_viewport_start(state, widget);
    let next = if delta > 0.001 {
        clamp_start_with(cur - SCROLL_STEP_SLOTS, slot_count)
    } else if delta < -0.001 {
        clamp_start_with(cur + SCROLL_STEP_SLOTS, slot_count)
    } else {
        cur
    };
    if next != cur {
        let _ = rebind(state, widget, next, "mouse-wheel");
    }
}

fn pointer_wheel_delta(state: &State, event: &[u8; F_POINTER_EVENT_SIZE]) -> Option<f32> {
    if state.kismet.cdo.is_null() || state.kismet.pointer_event_get_wheel_delta == 0 {
        return None;
    }
    let func = unsafe { &*(state.kismet.pointer_event_get_wheel_delta as *const UFunction) };
    let saved_flags = func.function_flags();
    func.set_function_flags(saved_flags | ue::offsets::FUNC_NATIVE);
    let mut parms = PointerEventGetWheelDeltaParms {
        input: *event,
        return_value: 0.0,
        _pad: 0,
    };
    unsafe {
        (&*state.kismet.cdo).process_event(func, &mut parms as *mut _ as *mut c_void);
    }
    func.set_function_flags(saved_flags);
    Some(parms.return_value)
}

fn rebind(
    state: &State,
    widget: &UObject,
    new_start: i32,
    reason: &str,
) -> Result<(), &'static str> {
    let item_grid_ptr = unsafe {
        widget
            .field_ptr(INV_IFACE_ITEM_GRID_OFFSET)
            .cast::<*mut UObject>()
            .read_unaligned()
    };
    if item_grid_ptr.is_null() {
        return Err("ItemGrid is null");
    }
    let item_grid = unsafe { &*item_grid_ptr };

    let child_count = panel_children_count(state, item_grid);
    if child_count != VIEWPORT_PAGE_SIZE {
        if cfg!(debug_assertions) {
            ueforge::log!(
                "scroll skipped: expected {} visible children, found {}",
                VIEWPORT_PAGE_SIZE,
                child_count
            );
        }
        return Err("unexpected child count");
    }

    let slot_count = state.slot_count.load(Ordering::Acquire);
    let clamped = clamp_start_with(new_start, slot_count);
    let old_start = get_viewport_start(state, widget);

    state.in_synthetic_refresh.store(true, Ordering::Release);
    let result = rebind_visible_slots(state, widget, item_grid, clamped);
    state.in_synthetic_refresh.store(false, Ordering::Release);
    result?;

    set_viewport_start(state, widget, clamped);

    if cfg!(debug_assertions) {
        ueforge::log!("scroll {}: start={} -> {}", reason, old_start, clamped);
    }
    Ok(())
}

fn rebind_visible_slots(
    state: &State,
    widget: &UObject,
    item_grid: &UObject,
    item_start_index: i32,
) -> Result<(), &'static str> {
    let mut items_parms = GetInventoryItemsParms {
        items: ue::TArray::default(),
    };
    let func = unsafe { &*(state.inv_iface.get_inventory_items as *const UFunction) };
    unsafe {
        widget.process_event(func, &mut items_parms as *mut _ as *mut c_void);
    }

    for visible in 0..VIEWPORT_PAGE_SIZE {
        let child = panel_child_at(state, item_grid, visible);
        let Some(child) = child else { continue };
        let absolute = item_start_index + visible;
        let item = bpf_get_item(state, widget, &items_parms.items, absolute);
        let _ = init_item_slot(state, widget, child, item);
    }
    Ok(())
}

fn panel_children_count(state: &State, panel: &UObject) -> i32 {
    let func = unsafe { &*(state.panel.get_children_count as *const UFunction) };
    let mut parms = IntReturnParms { return_value: -1 };
    unsafe { panel.process_event(func, &mut parms as *mut _ as *mut c_void) };
    parms.return_value
}

fn panel_child_at(state: &State, panel: &UObject, index: i32) -> Option<&'static UObject> {
    let func = unsafe { &*(state.panel.get_child_at as *const UFunction) };
    let mut parms = GetChildAtParms {
        index,
        _pad: 0,
        return_value: std::ptr::null_mut(),
    };
    unsafe { panel.process_event(func, &mut parms as *mut _ as *mut c_void) };
    if parms.return_value.is_null() {
        None
    } else {
        Some(unsafe { &*parms.return_value })
    }
}

fn bpf_get_item(
    state: &State,
    widget: &UObject,
    item_list: &ue::TArray<*mut UObject>,
    absolute_slot: i32,
) -> *mut UObject {
    let func = unsafe { &*(state.bpf.get_item_in_item_list_slot as *const UFunction) };
    let mut parms = GetItemInItemListSlotParms {
        item_list: ue::TArray {
            data: item_list.data,
            num: item_list.num,
            max: item_list.max,
        },
        index: absolute_slot,
        _pad: 0,
        world_context: widget as *const UObject as *mut UObject,
        item: std::ptr::null_mut(),
    };
    unsafe {
        (&*state.bpf.cdo).process_event(func, &mut parms as *mut _ as *mut c_void);
    }
    parms.item
}

fn init_item_slot(
    state: &State,
    widget: &UObject,
    slot: &UObject,
    item: *mut UObject,
) -> Result<(), &'static str> {
    if state.inv_iface.initialize_item_slot == 0 {
        return Err("InitializeItemSlot missing");
    }
    let func = unsafe { &*(state.inv_iface.initialize_item_slot as *const UFunction) };
    let mut parms = InitializeItemSlotParms {
        item_slot: slot as *const UObject as *mut UObject,
        item,
    };
    unsafe { widget.process_event(func, &mut parms as *mut _ as *mut c_void) };
    Ok(())
}

fn clamp_start_with(value: i32, slot_count: i32) -> i32 {
    let max_start = (slot_count - VIEWPORT_PAGE_SIZE).max(0);
    value.clamp(0, max_start)
}

fn get_viewport_start(state: &State, widget: &UObject) -> i32 {
    let key = widget as *const UObject as usize;
    state
        .viewport_starts
        .lock()
        .unwrap()
        .iter()
        .find_map(|(k, v)| if *k == key { Some(*v) } else { None })
        .unwrap_or(0)
}

fn set_viewport_start(state: &State, widget: &UObject, value: i32) {
    let key = widget as *const UObject as usize;
    let mut guard = state.viewport_starts.lock().unwrap();
    for entry in guard.iter_mut() {
        if entry.0 == key {
            entry.1 = value;
            return;
        }
    }
    guard.push((key, value));
}

#[allow(dead_code)]
fn _silence(_: SelectedIndexParms, _: SetSelectedInventorySlotParms) {}
