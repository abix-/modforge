//! Items shown in an open panel (stash, inventory, vendor, ritual
//! rewards), found the way GameHelper2's LootValue does
//! (Plugins/LootValue/LootValueCore.cs ScanItemSlots,
//! TryGetScrollContainer, TryGetSlotRect; GameHelper/Plugin
//! PluginUiElementReflection.cs TryValidateItemAddress, TryGetAbsoluteRect;
//! RemoteObjects/GameWindowScale.cs; GameOffsets/Objects/UiElement
//! UiElementBaseOffset.cs).
//!
//! A slot is a UI element holding an item pointer. The panel's tree is
//! walked breadth first through shown elements; each item is kept once,
//! at the first of its elements whose centre lies inside the panel.

use crate::items;
use crate::model::Item;
use crate::ui::{children, element, visible_flag};
use modforge::process_memory::ProcessMemory;
use serde::Serialize;
use std::collections::{HashMap, HashSet, VecDeque};
use std::ops::Range;

/// LootValueCore.UiElementItemAddressOffset.
pub const ITEM_POINTER: u64 = 0x4E0;
/// LootValueCore.ItemPathPrefix.
pub const ITEM_PATH_PREFIX: &str = "Metadata/Items";
/// ScanItemSlots stops after this many elements.
pub const MAX_ELEMENTS: usize = 5000;
/// LootValueCore.RitualRewardGridPath from the UI manager.
pub const RITUAL_REWARD_GRID: [usize; 2] = [76, 13];
/// UiElementBaseFuncs.BaseResolution.
pub const BASE_RESOLUTION: (f32, f32) = (2560.0, 1600.0);
/// UiElementBaseOffset fields for positions.
pub mod rect {
    pub const RELATIVE_POSITION: u64 = 0x100;
    pub const POSITION_MODIFIER: u64 = 0x108;
    pub const LOCAL_SCALE: u64 = 0x118;
    pub const SCALE_INDEX: u64 = 0x172;
    pub const UNSCALED_SIZE: u64 = 0x270;
    /// UiElementBaseFuncs SHOULD_MODIFY_BINARY_POS.
    pub const SHOULD_MODIFY_BIT: u32 = 0x0A;
}
/// Stop climbing parents after this many.
const MAX_DEPTH: usize = 64;

/// GameWindowScale: width and height scale for each of the three scale
/// indexes, from the window size and the cull on each side.
#[derive(Clone, Copy, Debug, PartialEq, Serialize)]
pub struct Scale {
    pub values: [f32; 6],
    pub cull: f32,
}

impl Scale {
    pub fn new(width: f32, height: f32, cull: i32) -> Self {
        let cull = cull as f32;
        if width <= 0.0 || height <= 0.0 {
            return Self {
                values: [1.0; 6],
                cull,
            };
        }
        let w = (width - cull - cull) / BASE_RESOLUTION.0;
        let h = height / BASE_RESOLUTION.1;
        Self {
            values: [w, w, h, h, w, h],
            cull,
        }
    }

    /// GetScaleValue.
    pub fn get(&self, index: u8, multiplier: f32) -> (f32, f32) {
        let v = &self.values;
        match index {
            1 => (multiplier * v[0], multiplier * v[1]),
            2 => (multiplier * v[2], multiplier * v[3]),
            3 => (multiplier * v[4], multiplier * v[5]),
            _ => (multiplier, multiplier),
        }
    }
}

/// A rectangle on the screen: top left and size.
#[derive(Clone, Copy, Debug, Default, PartialEq, Serialize)]
pub struct Rect {
    pub x: f32,
    pub y: f32,
    pub w: f32,
    pub h: f32,
}

impl Rect {
    fn centre(&self) -> (f32, f32) {
        (self.x + self.w * 0.5, self.y + self.h * 0.5)
    }
}

/// The UiElementBaseOffset fields a position needs.
struct Element {
    self_ptr: u64,
    parent: u64,
    flags: u32,
    relative: [f32; 2],
    modifier: [f32; 2],
    local_scale: f32,
    scale_index: u8,
    unscaled_size: [f32; 2],
}

fn element_at(mem: &ProcessMemory, at: u64) -> Option<Element> {
    Some(Element {
        self_ptr: mem.read_value(at + element::SELF).ok()?,
        parent: mem.read_value(at + element::PARENT).ok()?,
        flags: mem.read_value(at + element::FLAGS).ok()?,
        relative: mem.read_value(at + rect::RELATIVE_POSITION).ok()?,
        modifier: mem.read_value(at + rect::POSITION_MODIFIER).ok()?,
        local_scale: mem.read_value(at + rect::LOCAL_SCALE).ok()?,
        scale_index: mem.read_value(at + rect::SCALE_INDEX).ok()?,
        unscaled_size: mem.read_value(at + rect::UNSCALED_SIZE).ok()?,
    })
}

/// TryGetUnscaledPosition: the element's position from its parents,
/// in its own scale. None when it or a parent is hidden or torn.
fn unscaled_position(
    mem: &ProcessMemory,
    at: u64,
    depth: usize,
    scale: &Scale,
) -> Option<([f32; 2], Element)> {
    if at == 0 || depth >= MAX_DEPTH {
        return None;
    }
    let e = element_at(mem, at)?;
    if (e.self_ptr != 0 && e.self_ptr != at) || !visible_flag(e.flags) {
        return None;
    }
    if e.parent == 0 {
        return Some((e.relative, e));
    }
    let (mut parent_pos, p) = unscaled_position(mem, e.parent, depth + 1, scale)?;
    if e.flags & (1 << rect::SHOULD_MODIFY_BIT) != 0 {
        parent_pos[0] += p.modifier[0];
        parent_pos[1] += p.modifier[1];
    }
    if p.scale_index == e.scale_index && p.local_scale == e.local_scale {
        let pos = [parent_pos[0] + e.relative[0], parent_pos[1] + e.relative[1]];
        return Some((pos, e));
    }
    let (pw, ph) = scale.get(p.scale_index, p.local_scale);
    let (w, h) = scale.get(e.scale_index, e.local_scale);
    if w == 0.0 || h == 0.0 {
        return None;
    }
    let pos = [
        parent_pos[0] * pw / w + e.relative[0],
        parent_pos[1] * ph / h + e.relative[1],
    ];
    Some((pos, e))
}

/// UiElementBase.Position: the element's top left on the screen, with
/// no need for a size.
pub fn position(mem: &ProcessMemory, at: u64, scale: &Scale) -> Option<[f32; 2]> {
    let (pos, e) = unscaled_position(mem, at, 0, scale)?;
    let (w, h) = scale.get(e.scale_index, e.local_scale);
    let p = [pos[0] * w + scale.cull, pos[1] * h];
    p.iter().all(|v| v.is_finite()).then_some(p)
}

/// TryGetAbsoluteRect: the element's rectangle on the screen.
pub fn absolute_rect(mem: &ProcessMemory, at: u64, scale: &Scale) -> Option<Rect> {
    let (pos, e) = unscaled_position(mem, at, 0, scale)?;
    let (w, h) = scale.get(e.scale_index, e.local_scale);
    let r = Rect {
        x: pos[0] * w + scale.cull,
        y: pos[1] * h,
        w: e.unscaled_size[0] * w,
        h: e.unscaled_size[1] * h,
    };
    let finite = [r.x, r.y, r.w, r.h].iter().all(|v| v.is_finite());
    (finite && r.w > 0.0 && r.h > 0.0).then_some(r)
}

/// ScrollBinding: a scroll view's bar and how far it is scrolled.
#[derive(Clone, Copy, Debug, Default, PartialEq, Serialize)]
pub struct Scroll {
    pub holder: u64,
    pub thumb: u64,
    pub content_height: f32,
    /// How far the content is scrolled up.
    pub offset_y: f32,
    pub clip_top: f32,
    pub clip_bottom: f32,
}

impl Scroll {
    pub fn active(&self) -> bool {
        self.holder != 0 && self.thumb != 0
    }
}

/// TryGetScrollContainer: children 1 (the content) and 2 (the bar
/// holder, whose child 0 is the thumb) shaped like a scroll view.
/// Gives the content element and the scroll.
fn scroll_container(mem: &ProcessMemory, kids: &[u64], scale: &Scale) -> Option<(u64, Scroll)> {
    if kids.len() <= 2 || kids[1] == 0 || kids[2] == 0 {
        return None;
    }
    let (content, holder) = (kids[1], kids[2]);
    let flags: u32 = mem.read_value(holder + element::FLAGS).ok()?;
    if !visible_flag(flags) {
        return None;
    }
    let thumb = *children(mem, holder).first().filter(|t| **t != 0)?;
    let c = absolute_rect(mem, content, scale)?;
    let h = absolute_rect(mem, holder, scale)?;
    let t = absolute_rect(mem, thumb, scale)?;
    // Shape checks keep ordinary layouts from passing as scroll views.
    if h.w < 4.0
        || h.w > 64.0
        || h.h < 40.0
        || t.w < 2.0
        || t.w > h.w * 1.5
        || t.h < 8.0
        || t.h >= h.h
        || c.h <= h.h + 1.0
        || h.x < c.x
        || t.y < h.y - 2.0
        || t.y + t.h > h.y + h.h + 2.0
    {
        return None;
    }
    let travel = h.h - t.h;
    let overflow = c.h - h.h;
    if travel <= 0.0 || overflow <= 0.0 {
        return None;
    }
    let progress = ((t.y - h.y) / travel).clamp(0.0, 1.0);
    let scroll = Scroll {
        holder,
        thumb,
        content_height: c.h,
        offset_y: progress * overflow,
        clip_top: h.y,
        clip_bottom: h.y + h.h,
    };
    (scroll.offset_y.is_finite() && scroll.clip_bottom > scroll.clip_top)
        .then_some((content, scroll))
}

/// TryGetSlotRect: the element's rectangle, or its parent's when the
/// parent is cell sized (premium tabs keep the pointer on a small
/// child), moved up by the scroll.
fn slot_rect(
    mem: &ProcessMemory,
    at: u64,
    parent: u64,
    scroll: &Scroll,
    scale: &Scale,
) -> Option<Rect> {
    let mut r = absolute_rect(mem, at, scale)?;
    if parent != 0
        && let Some(p) = absolute_rect(mem, parent, scale)
        && p.w >= 20.0
        && p.h >= 20.0
        && ((p.w <= 160.0 && p.h <= 256.0) || (p.w <= 256.0 && p.h <= 160.0))
    {
        r = p;
    }
    r.y -= scroll.offset_y;
    Some(r)
}

/// TryValidateItemAddress: the vtable lies in the game's exe and the
/// path starts with Metadata/Items. Gives the path, or why not.
pub fn validate_item(mem: &ProcessMemory, at: u64, exe: &Range<u64>) -> Result<String, String> {
    let vtable: u64 = mem.read_value(at).map_err(|_| "item unreadable")?;
    if !exe.contains(&vtable) {
        return Err(format!("vtable {vtable:#x} outside game module"));
    }
    let details: u64 = mem
        .read_value(at + crate::entities::entity::DETAILS)
        .map_err(|_| "entity details unreadable")?;
    let path = modforge::msvc_std::read_wstring(mem, details + crate::entities::details::PATH)
        .unwrap_or_default();
    if !path
        .to_lowercase()
        .starts_with(&ITEM_PATH_PREFIX.to_lowercase())
    {
        return Err(if path.is_empty() {
            "item path unreadable".into()
        } else {
            format!("non-item path: {path}")
        });
    }
    Ok(path)
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Slot {
    pub address: u64,
    pub rect: Rect,
    pub scroll: Option<Scroll>,
    pub item: Item,
}

/// SlotScanReport.
#[derive(Clone, Debug, Default, PartialEq, Serialize)]
pub struct Report {
    pub visited: usize,
    pub scroll_containers: usize,
    pub pointers: usize,
    pub unique_items: usize,
    pub valid_items: usize,
    pub rejected: Vec<(u64, String)>,
}

/// ScanItemSlots: every item shown in the panel at `panel`, whose
/// rectangle on the screen is `area`. `exe` is the game exe's range.
pub fn scan(
    mem: &ProcessMemory,
    panel: u64,
    area: Rect,
    scale: &Scale,
    exe: &Range<u64>,
) -> (Vec<Slot>, Report) {
    let mut report = Report::default();
    // Items in the order first found, each with its elements.
    let mut order: Vec<u64> = Vec::new();
    let mut by_item: HashMap<u64, Vec<(u64, u64, Scroll)>> = HashMap::new();
    let mut queue = VecDeque::from([(panel, 0u64, Scroll::default())]);
    let mut visited = HashSet::new();
    while visited.len() < MAX_ELEMENTS
        && let Some((at, parent, scroll)) = queue.pop_front()
    {
        if at == 0 || !visited.insert(at) {
            continue;
        }
        report.visited += 1;
        let Ok(flags) = mem.read_value::<u32>(at + element::FLAGS) else {
            continue;
        };
        if !visible_flag(flags) {
            continue;
        }
        let kids = children(mem, at);
        let inner = scroll_container(mem, &kids, scale);
        if inner.is_some() {
            report.scroll_containers += 1;
        }
        for kid in kids {
            match inner {
                Some((content, s)) if kid == content => queue.push_back((kid, at, s)),
                _ => queue.push_back((kid, at, scroll)),
            }
        }
        let item: u64 = mem.read_value(at + ITEM_POINTER).unwrap_or(0);
        if item == 0 {
            continue;
        }
        report.pointers += 1;
        by_item
            .entry(item)
            .or_insert_with(|| {
                order.push(item);
                Vec::new()
            })
            .push((at, parent, scroll));
    }
    report.unique_items = order.len();
    let right = area.x + area.w;
    let bottom = area.y + area.h;
    let mut slots = Vec::new();
    for item_at in order {
        let found = by_item[&item_at].iter().find_map(|(at, parent, scroll)| {
            let r = slot_rect(mem, *at, *parent, scroll, scale)?;
            let (cx, cy) = r.centre();
            let inside_x = cx >= area.x && cx <= right;
            let inside_y = scroll.active() || (cy >= area.y && cy <= bottom);
            (inside_x && inside_y).then_some((*at, r, *scroll))
        });
        let Some((at, r, scroll)) = found else {
            continue;
        };
        if let Err(why) = validate_item(mem, item_at, exe) {
            report.rejected.push((at, why));
            continue;
        }
        let Ok(item) = items::read(mem, item_at) else {
            report
                .rejected
                .push((at, "item changed after validation".into()));
            continue;
        };
        if !item
            .path
            .to_lowercase()
            .starts_with(&ITEM_PATH_PREFIX.to_lowercase())
        {
            report
                .rejected
                .push((at, "item changed after validation".into()));
            continue;
        }
        report.valid_items += 1;
        slots.push(Slot {
            address: item_at,
            rect: r,
            scroll: scroll.active().then_some(scroll),
            item,
        });
    }
    (slots, report)
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::tests::{fake_entity, put};
    use crate::ui::tests::{fake_elements, set_children};

    #[test]
    fn scale_like_gamehelper2() {
        let s = Scale::new(2560.0 + 40.0, 800.0, 20);
        assert_eq!(s.values, [1.0, 1.0, 0.5, 0.5, 1.0, 0.5]);
        assert_eq!(s.get(2, 2.0), (1.0, 1.0));
        assert_eq!(s.get(0, 3.0), (3.0, 3.0));
        assert_eq!(Scale::new(0.0, 0.0, 0).values, [1.0; 6]);
    }

    /// Element `i` sits at `pos` inside its parent with `size`, scale 1.
    fn place(node: &mut [u8], parent: u64, pos: [f32; 2], size: [f32; 2]) {
        put(node, 0xB8, parent);
        put(node, 0x100, pos);
        put(node, 0x118, 1.0f32);
        put(node, 0x172, 1u8);
        put(node, 0x270, size);
    }

    #[test]
    fn positions_add_up_through_parents_and_scale() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let (mut nodes, at) = fake_elements(2);
        place(&mut nodes[0][..], 0, [100.0, 50.0], [500.0, 500.0]);
        place(&mut nodes[1][..], at[0], [10.0, 20.0], [60.0, 60.0]);
        let s = Scale::new(1280.0 + 10.0, 800.0, 5);
        // Index 1 scales by 0.5 both ways (width uses the first pair).
        assert_eq!(
            absolute_rect(&mem, at[1], &s),
            Some(Rect {
                x: 110.0 * 0.5 + 5.0,
                y: 70.0 * 0.5,
                w: 30.0,
                h: 30.0
            })
        );
        put(&mut nodes[0][..], 0x168, 0u32);
        assert_eq!(absolute_rect(&mem, at[1], &s), None, "hidden parent");
    }

    #[test]
    fn finds_each_item_once_inside_the_panel() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let vtable = 0x1000u64;
        let exe = 0x1000..0x2000;
        let mut ring = fake_entity("Metadata/Items/Rings/Ring1", &[]);
        ring.set_vtable(vtable);
        let mut not_item = fake_entity("Metadata/Monsters/Thing", &[]);
        not_item.set_vtable(vtable);
        // Panel 0 at (0,0) 400x400. Children: 1 holds the ring, 2 a
        // ghost copy of the ring, 3 the monster, 4 the ring again but
        // outside the panel (its copy in 1 wins first), 5 hidden.
        let (mut nodes, at) = fake_elements(6);
        place(&mut nodes[0][..], 0, [0.0, 0.0], [400.0, 400.0]);
        for (i, x) in [(1, 10.0), (2, 70.0), (3, 130.0), (4, 900.0), (5, 190.0)] {
            place(&mut nodes[i][..], at[0], [x, 10.0], [50.0, 50.0]);
        }
        put(&mut nodes[1][..], 0x4E0, ring.address());
        put(&mut nodes[2][..], 0x4E0, ring.address());
        put(&mut nodes[3][..], 0x4E0, not_item.address());
        put(&mut nodes[4][..], 0x4E0, ring.address());
        put(&mut nodes[5][..], 0x4E0, ring.address());
        put(&mut nodes[5][..], 0x168, 0u32);
        let kids = [at[1], at[2], at[3], at[4], at[5]];
        set_children(&mut nodes[0][..], &kids);

        let s = Scale::new(2560.0, 1600.0, 0);
        let area = absolute_rect(&mem, at[0], &s).unwrap();
        let (slots, report) = scan(&mem, at[0], area, &s, &exe);
        assert_eq!(slots.len(), 1);
        assert_eq!(slots[0].address, ring.address());
        assert_eq!(slots[0].item.path, "Metadata/Items/Rings/Ring1");
        assert_eq!(slots[0].rect.x, 10.0);
        assert_eq!((report.pointers, report.unique_items), (4, 2));
        assert_eq!(report.rejected.len(), 1);
        assert!(report.rejected[0].1.starts_with("non-item path"));
        assert!(validate_item(&mem, ring.address(), &(0..1)).is_err());
    }
}
