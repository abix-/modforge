//! The game's UI elements, read the way GameHelper2 does
//! (GameOffsets/Objects/UiElement/UiElementBaseOffset.cs,
//! States/InGameStateOffset.cs, InGameState/ImportantUiElementsOffsets.cs;
//! RemoteObjects/UiElement/UiElementBase.cs, States/InGameState.cs).
//!
//! Every element has flags, a parent, children and a string id. An
//! element shows when its visible flag is set and so is every
//! parent's.

use anyhow::{Context, Result, ensure};
use modforge::msvc_std::{read_vector, read_wstring};
use modforge::process_memory::ProcessMemory;
use serde::Serialize;
use std::collections::HashSet;

/// InGameStateOffset.UiRootStructPtr, and GamepadUiRootStructPtr for
/// controller mode (used when the first is null).
pub const IN_GAME_UI: u64 = 0x2F0;
pub const IN_GAME_GAMEPAD_UI: u64 = 0x318;
/// UiRootStruct.UiRootPtr.
pub const UI_ROOT: u64 = 0x340;
/// ImportantUiElementsOffsets, from the same struct as the root.
pub const PANELS: &[(&str, u64)] = &[
    ("chat", 0x640),
    ("left_panel", 0x6D0),
    ("right_panel", 0x6D8),
    ("passive_tree", 0x730),
    ("map", 0x7C0),
    ("world_map", 0x988),
];
/// UiElementBaseOffset.
pub mod element {
    pub const CHILDREN: u64 = 0x10;
    pub const PARENT: u64 = 0xB8;
    pub const STRING_ID: u64 = 0x128;
    pub const FLAGS: u64 = 0x168;
    /// UiElementBaseFuncs IS_VISIBLE_BINARY_POS.
    pub const VISIBLE_BIT: u32 = 0x0B;
}
/// Stop climbing parents after this many (a torn tree can loop).
const MAX_DEPTH: usize = 64;

/// The UI struct holding the root and the panels: the mouse and
/// keyboard one, or the controller one when that is null.
pub fn ui_struct(mem: &ProcessMemory, in_game_state: u64) -> Result<u64> {
    let ui: u64 = mem
        .read_value(in_game_state + IN_GAME_UI)
        .context("read UI pointer")?;
    if ui != 0 {
        return Ok(ui);
    }
    let pad: u64 = mem
        .read_value(in_game_state + IN_GAME_GAMEPAD_UI)
        .context("read controller UI pointer")?;
    ensure!(pad != 0, "no UI");
    Ok(pad)
}

pub fn visible_flag(flags: u32) -> bool {
    flags & (1 << element::VISIBLE_BIT) != 0
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

/// Each panel's address and whether it shows; a null panel is absent.
pub fn panels(mem: &ProcessMemory, ui: u64) -> Vec<(&'static str, Option<(u64, bool)>)> {
    PANELS
        .iter()
        .map(|(name, offset)| {
            let at = mem.read_value::<u64>(ui + offset).ok().filter(|p| *p != 0);
            let shown = at.map(|p| (p, is_visible(mem, p).unwrap_or(false)));
            (*name, shown)
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
        let children: Vec<u64> = read_vector(mem, at + element::CHILDREN).unwrap_or_default();
        out.push(Node {
            address: at,
            depth,
            id: read_wstring(mem, at + element::STRING_ID).unwrap_or_default(),
            visible_flag: visible_flag(flags),
            children: children.len(),
        });
        if depth < max_depth {
            todo.extend(children.into_iter().rev().map(|c| (c, depth + 1)));
        }
    }
    out
}

pub fn root(mem: &ProcessMemory, ui: u64) -> Result<u64> {
    let root: u64 = mem.read_value(ui + UI_ROOT).context("read UI root")?;
    ensure!(root != 0, "no UI root");
    Ok(root)
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::tests::put;
    use modforge::msvc_std::Vector;

    const SIZE: usize = 0x170;
    const VISIBLE: u32 = 1 << 11;

    #[test]
    fn visible_bit_like_gamehelper2() {
        assert!(visible_flag(0x800));
        assert!(!visible_flag(0x400));
    }

    #[test]
    fn visible_needs_every_parent_and_walk_follows_children() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let mut nodes: Vec<Box<[u8; SIZE]>> = (0..3).map(|_| Box::new([0u8; SIZE])).collect();
        let at: Vec<u64> = nodes.iter().map(|n| n.as_ptr() as u64).collect();
        // 0 is the root with children 1 and 2; 2 hides itself.
        let kids = [at[1], at[2]];
        let first = kids.as_ptr() as u64;
        put(
            &mut nodes[0][..],
            0x10,
            Vector {
                first,
                last: first + 16,
                end: first + 16,
            },
        );
        put(&mut nodes[0][..], 0x168, VISIBLE);
        put(&mut nodes[1][..], 0xB8, at[0]);
        put(&mut nodes[1][..], 0x168, VISIBLE);
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
    }

    #[test]
    fn panels_and_controller_fallback() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let mut panel = [0u8; SIZE];
        put(&mut panel[..], 0x168, VISIBLE);
        let mut ui = [0u8; 0x990];
        put(&mut ui[..], 0x6D8, panel.as_ptr() as u64);
        let mut state = [0u8; 0x320];
        put(&mut state[..], 0x318, ui.as_ptr() as u64);
        let found = ui_struct(&mem, state.as_ptr() as u64).unwrap();
        assert_eq!(found, ui.as_ptr() as u64);
        let p = panels(&mem, found);
        assert_eq!(p[2], ("right_panel", Some((panel.as_ptr() as u64, true))));
        assert_eq!(p[1], ("left_panel", None));
    }
}
