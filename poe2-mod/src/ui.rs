//! The game's UI elements, read the way GameHelper2 does
//! (GameOffsets/Objects/UiElement/UiElementBaseOffset.cs,
//! States/InGameStateOffset.cs, InGameState/ImportantUiElementsOffsets.cs;
//! RemoteObjects/UiElement/UiElementBase.cs, States/InGameState.cs,
//! InGameStateObjects/ImportantUiElements.cs).
//!
//! Every element has flags, a parent, children and a string id. An
//! element shows when its visible flag is set and so is every
//! parent's. The UI manager is itself an element; GameHelper2 finds
//! most panels by child index paths from it, and chat and the side
//! panels by fixed offsets into it.

use anyhow::{Context, Result, ensure};
use modforge::msvc_std::{read_vector, read_vector_header, read_wstring};
use modforge::process_memory::ProcessMemory;
use serde::Serialize;
use std::collections::HashSet;

/// InGameStateOffset.UiRootStructPtr, and GamepadUiRootStructPtr for
/// controller mode (used when the first is null).
pub const IN_GAME_UI: u64 = 0x2F0;
pub const IN_GAME_GAMEPAD_UI: u64 = 0x318;
/// UiRootStruct.UiRootPtr.
pub const UI_ROOT: u64 = 0x340;
/// ImportantUiElementsOffsets still read by offset, mouse and keyboard
/// mode only.
pub const OFFSET_PANELS: &[(&str, u64)] = &[
    ("chat", 0x640),
    ("left_panel", 0x6D0),
    ("right_panel", 0x6D8),
];
/// ImportantUiElements child paths from the UI manager.
pub const PATH_PANELS: &[(&str, &[usize])] = &[
    ("world_map", &[22, 0]),
    ("large_map", &[6, 0]),
    ("mini_map", &[6, 1]),
    ("passive_tree", &[24, 2]),
    ("act1", &[22, 0, 0]),
    ("act2", &[22, 0, 1]),
    ("act3", &[22, 0, 2]),
    ("act4", &[22, 0, 3]),
    ("interlude", &[22, 0, 5]),
    ("atlas", &[22, 0, 6]),
    ("atlas_skills", &[25, 0]),
    ("currency_exchange", &[114, 20, 6, 1]),
    ("gemcutting", &[53, 3]),
    ("support_gemcutting", &[54, 3]),
    ("temple_console", &[64, 0]),
];
/// UiElementBaseOffset.
pub mod element {
    pub const SELF: u64 = 0x08;
    pub const CHILDREN: u64 = 0x10;
    pub const PARENT: u64 = 0xB8;
    pub const STRING_ID: u64 = 0x128;
    pub const FLAGS: u64 = 0x168;
    /// UiElementBaseFuncs IS_VISIBLE_BINARY_POS.
    pub const VISIBLE_BIT: u32 = 0x0B;
}
/// Stop climbing parents after this many (a torn tree can loop).
const MAX_DEPTH: usize = 64;

/// The UI manager: the mouse and keyboard one, or the controller one
/// when that is null. The bool is true in controller mode.
pub fn manager(mem: &ProcessMemory, in_game_state: u64) -> Result<(u64, bool)> {
    let ui: u64 = mem
        .read_value(in_game_state + IN_GAME_UI)
        .context("read UI pointer")?;
    if ui != 0 {
        return Ok((ui, false));
    }
    let pad: u64 = mem
        .read_value(in_game_state + IN_GAME_GAMEPAD_UI)
        .context("read controller UI pointer")?;
    ensure!(pad != 0, "no UI");
    Ok((pad, true))
}

pub fn visible_flag(flags: u32) -> bool {
    flags & (1 << element::VISIBLE_BIT) != 0
}

/// GameHelper2 ValidUiElementOrZero: a real element points at itself.
pub fn is_element(mem: &ProcessMemory, at: u64) -> bool {
    at != 0 && mem.read_value::<u64>(at + element::SELF).ok() == Some(at)
}

/// The element's children.
pub fn children(mem: &ProcessMemory, at: u64) -> Vec<u64> {
    read_vector(mem, at + element::CHILDREN).unwrap_or_default()
}

/// The `i`th child, without reading the others.
pub fn child(mem: &ProcessMemory, at: u64, i: usize) -> Option<u64> {
    let v = read_vector_header(mem, at + element::CHILDREN).ok()?;
    if v.first == 0 || i >= v.len(8) {
        return None;
    }
    mem.read_value::<u64>(v.at(i, 8)).ok().filter(|p| *p != 0)
}

/// GameHelper2 ResolveChildAddress: follow child indexes from `root`;
/// the end must be a real element.
pub fn child_path(mem: &ProcessMemory, root: u64, path: &[usize]) -> Option<u64> {
    let mut at = root;
    for i in path {
        at = child(mem, at, *i)?;
    }
    is_element(mem, at).then_some(at)
}

/// GameHelper2 UiElementBase.IsVisible: this element's flag and every
/// parent's up to the root.
pub fn is_visible(mem: &ProcessMemory, at: u64) -> Result<bool> {
    let mut seen = HashSet::new();
    let mut at = at;
    while at != 0 {
        ensure!(
            seen.insert(at) && seen.len() <= MAX_DEPTH,
            "UI parents loop at {at:#x}"
        );
        let flags: u32 = mem
            .read_value(at + element::FLAGS)
            .with_context(|| format!("read UI flags at {at:#x}"))?;
        if !visible_flag(flags) {
            return Ok(false);
        }
        at = mem
            .read_value(at + element::PARENT)
            .with_context(|| format!("read UI parent at {at:#x}"))?;
    }
    Ok(true)
}

/// One important panel by name, None when absent.
pub fn panel(mem: &ProcessMemory, manager: u64, controller: bool, name: &str) -> Option<u64> {
    if let Some((_, offset)) = OFFSET_PANELS.iter().find(|(n, _)| *n == name) {
        if controller {
            return None;
        }
        let at: u64 = mem.read_value(manager + offset).ok()?;
        // GameHelper2 takes chat as is and checks the side panels.
        return (at != 0 && (name == "chat" || is_element(mem, at))).then_some(at);
    }
    let (_, path) = PATH_PANELS.iter().find(|(n, _)| *n == name)?;
    child_path(mem, manager, path)
}

/// Each important panel's address and whether it shows. Chat and the
/// side panels are only read by offset in mouse and keyboard mode, as
/// GameHelper2 does outside co-op.
pub fn panels(
    mem: &ProcessMemory,
    manager: u64,
    controller: bool,
) -> Vec<(&'static str, Option<(u64, bool)>)> {
    let names = OFFSET_PANELS
        .iter()
        .map(|(n, _)| *n)
        .chain(PATH_PANELS.iter().map(|(n, _)| *n));
    names
        .map(|name| {
            let at = panel(mem, manager, controller, name);
            (name, at.map(|p| (p, is_visible(mem, p).unwrap_or(false))))
        })
        .collect()
}

/// One element in a tree walk.
#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Node {
    pub address: u64,
    pub depth: usize,
    pub id: String,
    pub visible_flag: bool,
    pub children: usize,
}

/// The tree under `root`, depth first, at most `max_depth` deep and
/// `max_nodes` long; children are listed in the game's order.
pub fn walk(mem: &ProcessMemory, root: u64, max_depth: usize, max_nodes: usize) -> Vec<Node> {
    let mut out = Vec::new();
    let mut seen = HashSet::new();
    let mut todo = vec![(root, 0usize)];
    while let Some((at, depth)) = todo.pop() {
        if at == 0 || !seen.insert(at) || out.len() >= max_nodes {
            continue;
        }
        let Ok(flags) = mem.read_value::<u32>(at + element::FLAGS) else {
            continue;
        };
        let kids = children(mem, at);
        out.push(Node {
            address: at,
            depth,
            id: read_wstring(mem, at + element::STRING_ID).unwrap_or_default(),
            visible_flag: visible_flag(flags),
            children: kids.len(),
        });
        if depth < max_depth {
            todo.extend(kids.into_iter().rev().map(|c| (c, depth + 1)));
        }
    }
    out
}

pub fn root(mem: &ProcessMemory, manager: u64) -> Result<u64> {
    let root: u64 = mem.read_value(manager + UI_ROOT).context("read UI root")?;
    ensure!(root != 0, "no UI root");
    Ok(root)
}

#[cfg(test)]
pub(crate) mod tests {
    use super::*;
    use crate::entities::tests::put;
    use modforge::msvc_std::Vector;

    pub const SIZE: usize = 0x990;
    pub const VISIBLE: u32 = 1 << 11;

    /// Fake elements: each points at itself and has the visible flag.
    /// The vector is never resized, so the addresses stay put.
    pub fn fake_elements(n: usize) -> (Vec<[u8; SIZE]>, Vec<u64>) {
        let mut nodes = vec![[0u8; SIZE]; n];
        let at: Vec<u64> = nodes.iter().map(|b| b.as_ptr() as u64).collect();
        for (node, a) in nodes.iter_mut().zip(&at) {
            put(&mut node[..], 0x08, *a);
            put(&mut node[..], 0x168, VISIBLE);
        }
        (nodes, at)
    }

    pub fn set_children(node: &mut [u8], kids: &[u64]) {
        let first = kids.as_ptr() as u64;
        let last = first + 8 * kids.len() as u64;
        put(
            node,
            0x10,
            Vector {
                first,
                last,
                end: last,
            },
        );
    }

    #[test]
    fn visible_bit_like_gamehelper2() {
        assert!(visible_flag(0x800));
        assert!(!visible_flag(0x400));
    }

    #[test]
    fn visible_needs_every_parent_and_walk_follows_children() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let (mut nodes, at) = fake_elements(3);
        // 0 is the root with children 1 and 2; 2 hides itself.
        let kids = [at[1], at[2]];
        set_children(&mut nodes[0][..], &kids);
        put(&mut nodes[1][..], 0xB8, at[0]);
        put(&mut nodes[2][..], 0xB8, at[0]);
        put(&mut nodes[2][..], 0x168, 0u32);
        assert!(is_visible(&mem, at[1]).unwrap());
        assert!(!is_visible(&mem, at[2]).unwrap());
        put(&mut nodes[0][..], 0x168, 0u32);
        assert!(
            !is_visible(&mem, at[1]).unwrap(),
            "a hidden parent hides the child"
        );

        let tree = walk(&mem, at[0], 4, 100);
        let order: Vec<(u64, usize)> = tree.iter().map(|n| (n.address, n.depth)).collect();
        assert_eq!(order, [(at[0], 0), (at[1], 1), (at[2], 1)]);
        assert_eq!(tree[0].children, 2);
        assert_eq!(walk(&mem, at[0], 0, 100).len(), 1);
        assert_eq!(child_path(&mem, at[0], &[1]), Some(at[2]));
        assert_eq!(child_path(&mem, at[0], &[2]), None);
    }

    #[test]
    fn panels_by_offset_and_path_with_controller_fallback() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        // Manager 0; its child 22 is element 1, whose child 0 is the
        // world map (2), whose child 0 is act 1 (4) and child 6 the
        // atlas (5). Element 3 is the right panel.
        let (mut nodes, at) = fake_elements(6);
        let mut top = vec![0u64; 23];
        top[22] = at[1];
        set_children(&mut nodes[0][..], &top);
        let one = [at[2]];
        set_children(&mut nodes[1][..], &one);
        let mut acts = vec![0u64; 7];
        acts[0] = at[4];
        acts[6] = at[5];
        set_children(&mut nodes[2][..], &acts);
        put(&mut nodes[1][..], 0xB8, at[0]);
        put(&mut nodes[2][..], 0xB8, at[1]);
        put(&mut nodes[5][..], 0xB8, at[2]);
        put(&mut nodes[5][..], 0x168, 0u32);
        put(&mut nodes[0][..], 0x6D8, at[3]);
        // The left panel points at something that is not an element.
        let junk = [0u8; 0x10];
        put(&mut nodes[0][..], 0x6D0, junk.as_ptr() as u64);
        let mut state = [0u8; 0x320];
        put(&mut state[..], 0x318, at[0]);

        assert_eq!(manager(&mem, state.as_ptr() as u64).unwrap(), (at[0], true));
        let find = |p: &[(&str, Option<(u64, bool)>)], n: &str| {
            p.iter().find(|(name, _)| *name == n).unwrap().1
        };
        let mouse = panels(&mem, at[0], false);
        assert_eq!(find(&mouse, "right_panel"), Some((at[3], true)));
        assert_eq!(find(&mouse, "left_panel"), None);
        assert_eq!(find(&mouse, "world_map"), Some((at[2], true)));
        assert_eq!(find(&mouse, "act1"), Some((at[4], true)));
        assert_eq!(find(&mouse, "atlas"), Some((at[5], false)));
        assert_eq!(find(&mouse, "act2"), None);
        let pad = panels(&mem, at[0], true);
        assert_eq!(find(&pad, "right_panel"), None);
        assert_eq!(find(&pad, "world_map"), Some((at[2], true)));
    }
}
