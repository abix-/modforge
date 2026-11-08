//! The endgame atlas: map nodes with their state, map id, grid
//! position, links and content, read the way GameHelper2 does
//! (RemoteObjects/States/InGameStateObjects ImportantUiElements.cs
//! UpdateAtlasMapData, ReadAtlasMapNode, ReadAtlasContentTokens,
//! MergePersistentAtlasBadgeContent, ReadAtlasConnections,
//! ReadAtlasContentContainer; AtlasMapNodeContent.cs for badge names).
//!
//! The atlas is a UI panel (child path 22, 0, 6 from the UI manager);
//! GameHelper2 reads it only while it shows. Each child is told apart
//! by its flags with the visible bit masked out.

use crate::ui;
use anyhow::{Result, ensure};
use modforge::msvc_std::read_vector;
use modforge::process_memory::ProcessMemory;
use serde::Serialize;
use std::collections::{BTreeMap, BTreeSet};

const VISIBLE: u32 = 0x800;
/// UI element fingerprints (flags without the visible bit).
const MARKER_FP: u32 = 0x502EF3;
const MAP_NODE_FP: u32 = 0x542EF3;
/// A King in the Mists node: the map node fingerprint with bit 20 clear.
const MIST_NODE_FP: u32 = 0x442EF3;
const MAX_CHILDREN: usize = 10_000;

/// ImportantUiElements atlas offsets.
pub mod node {
    /// The children vector's start; the node data pointer is 0x20 past
    /// it (the fifth child entry), as GameHelper2 reads it.
    pub const DATA_STORAGE: u64 = 0x10;
    pub const DATA: u64 = 0x20;
    pub const GRID: u64 = 0x310;
    pub const TOKENS: u64 = 0x350;
    pub const BADGES_BEGIN: u64 = 0x368;
    pub const BADGES_END: u64 = 0x370;
    /// On the node data.
    pub const MAP_DATA: u64 = 0x290;
    pub const BIOME: u64 = 0x2BE;
    pub const STATUS: u64 = 0x2BF;
    /// On a badge child of the content container.
    pub const BADGE_ID: u64 = 0x170;
    pub const BADGE_NAME: u64 = 0x278;
}
pub const ATLAS_CONNECTIONS: u64 = 0x590;
/// EndgameRegionActionButton, the sea ship.
pub mod region_button {
    pub const ROW_PTR: u64 = 0x308;
    pub const GRID: u64 = 0x318;
    pub const ROW_INDEX: u64 = 0x320;
    pub const OCEAN_ROW: i32 = 2;
    pub const GRID_LIMIT: i32 = 0x80000;
}
const MAX_CONTENT: usize = 64;
const BADGE_ROW_TO_ID: u32 = 100;
const COMPLETED_BIT: u8 = 0x02;
const ACCESSIBLE_BIT: u8 = 0x01;
/// GameHelper2 ReadUnicodeString reads 256 bytes.
const TEXT_UNITS: usize = 128;

/// GameHelper2 AtlasMapNodeBadge.Known: badge content id to name.
pub const BADGE_NAMES: &[(u32, &str)] = &[
    (0x0064, "Powerful Map Boss"),
    (0x0065, "Breach"),
    (0x0066, "Expedition"),
    (0x0067, "Delirium"),
    (0x0068, "Ritual"),
    (0x0069, "Irradiated"),
    (0x006A, "Overrun by the Abyssal"),
    (0x006B, "Vaal Beacons"),
    (0x006C, "Abyss"),
    (0x006D, "Notable Location"),
    (0x006E, "[DNT] Breach City - Not Shown to Players"),
    (0x006F, "Great Beast"),
    (0x0070, "Essence Trove"),
    (0x0071, "Monstrous Treasure"),
    (0x0072, "Spirit Guide"),
    (0x0073, "Arcane Hordes"),
    (0x0074, "Hunting Grounds"),
    (0x0075, "Nature Shrines"),
    (0x0076, "Crystalised Twinning"),
    (0x0077, "Indomitable Essence"),
    (0x0078, "Azmeri Energisation"),
    (0x0079, "Spirit Migration"),
    (0x007A, "Sacred Spirit"),
    (0x007B, "Ancient Trove"),
    (0x007C, "Twice-Locked Boxes"),
    (0x007D, "Power of Faith"),
    (0x007E, "Large Congregation"),
    (0x007F, "Zealous Reverence"),
    (0x0080, "Persistent Devotion"),
    (0x0081, "Rites of the Rogues"),
    (0x0082, "Surprising Alliances"),
    (0x0083, "Azmeri Bloodline"),
    (0x0084, "Twinned Terrors"),
    (0x0085, "Scattered Stones"),
    (0x0086, "Map Area Modified"),
    (0x0087, "Fleeing Exile"),
    (0x0088, "Breach Hive"),
    (0x0089, "Simulacrum"),
    (0x008A, "Chaotic Cacophony"),
    (0x008B, "Affluent Armies"),
    (0x008C, "Monstrous Treasure"),
    (0x008D, "Trialmaster's Trainee"),
    (0x008E, "Sekhema's Student"),
    (0x008F, "Azmeri Champion"),
    (0x0090, "Gigantic Uprising"),
    (0x0091, "Glimmering Mutation"),
    (0x0092, "Stolen Power"),
    (0x0093, "Headhunters"),
    (0x0094, "Swarming Spirits"),
    (0x0095, "Power Struggle"),
    (0x0096, "Corrupted Mirage"),
    (0x0097, "Energized Ley Lines"),
    (0x0098, "Exceptional Find"),
    (0x0099, "Water Influence"),
    (0x009A, "Mountain Influence"),
    (0x009B, "Grass Influence"),
    (0x009C, "Forest Influence"),
    (0x009D, "Swamp Influence"),
    (0x009E, "Desert Influence"),
    (0x009F, "Immured Fury"),
    (0x00A0, "Mirage of Riches"),
    (0x00A1, "Wisdom's Teachings"),
    (0x00A2, "Tight Pockets"),
    (0x00A3, "Fragment of Immortality"),
    (0x00A4, "Prosperous Populous"),
    (0x00A5, "Echoes of Power"),
    (0x00A6, "Grand Expedition"),
    (0x00A7, "Abyssal Depths"),
    (0x00A8, "Abyssal Fissure"),
    (0x00A9, "Viridian Wildwood"),
    (0x03E8, "Corruption"),
    (0x6157, "Grand Mirror"),
];

/// GameHelper2 GetBadgeContentName: by the low 16 bits.
pub fn badge_name(id: u32) -> Option<&'static str> {
    let id = id & 0xFFFF;
    BADGE_NAMES.iter().find(|(i, _)| *i == id).map(|(_, n)| *n)
}

#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize)]
#[serde(rename_all = "snake_case")]
pub enum NodeState {
    Locked,
    Open,
    Done,
}

pub fn state(status: u8) -> NodeState {
    if status & COMPLETED_BIT != 0 {
        NodeState::Done
    } else if status & ACCESSIBLE_BIT != 0 {
        NodeState::Open
    } else {
        NodeState::Locked
    }
}

/// One effect line on a node: a stat row id and its value.
#[derive(Clone, Copy, Debug, PartialEq, Serialize)]
pub struct Token {
    pub stat: u32,
    pub value: u32,
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct MapNode {
    /// Index among the atlas panel's children.
    pub index: usize,
    pub address: u64,
    pub map_id: String,
    pub grid: [i32; 2],
    pub biome: u8,
    pub status: u8,
    pub state: NodeState,
    pub visible: bool,
    /// Badge content ids, from the badge children and the node's own
    /// list (which survives fog and culling).
    pub badges: Vec<u32>,
    /// Content titles: the badge children's text, then known badge names.
    pub content: Vec<String>,
    pub tokens: Vec<Token>,
    /// Grid positions of the nodes linked to this one.
    pub links: Vec<[i32; 2]>,
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Atlas {
    pub address: u64,
    pub nodes: Vec<MapNode>,
    /// Sea ship buttons by the grid of the chunk a logbook reveals.
    pub ocean_buttons: Vec<[i32; 2]>,
    /// "You are here" markers showing.
    pub markers: usize,
}

/// AtlasNodeConnectionEdgeOffsets, 20 bytes.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct Edge {
    _unknown: i32,
    source: [i32; 2],
    target: [i32; 2],
}

/// GameHelper2 ReadAtlasConnections and AddAtlasConnection: links both
/// ways, without empty targets or self links.
fn links(mem: &ProcessMemory, atlas: u64) -> BTreeMap<[i32; 2], BTreeSet<[i32; 2]>> {
    let mut out: BTreeMap<[i32; 2], BTreeSet<[i32; 2]>> = BTreeMap::new();
    for e in read_vector::<Edge>(mem, atlas + ATLAS_CONNECTIONS).unwrap_or_default() {
        if e.target == [0, 0] || e.target == e.source {
            continue;
        }
        out.entry(e.source).or_default().insert(e.target);
        out.entry(e.target).or_default().insert(e.source);
    }
    out
}

fn wide_at(mem: &ProcessMemory, ptr: u64) -> Option<String> {
    (ptr != 0)
        .then(|| mem.read_wide_cstr(ptr, TEXT_UNITS).ok())
        .flatten()
}

/// The map id: node data +0x290 points at a pointer to a pointer to
/// the wide text.
fn map_id(mem: &ProcessMemory, data: u64) -> String {
    let deref = |p: u64| mem.read_value::<u64>(p).ok().filter(|v| *v != 0);
    deref(data + node::MAP_DATA)
        .and_then(deref)
        .and_then(deref)
        .and_then(|p| wide_at(mem, p))
        .unwrap_or_default()
}

/// GameHelper2 ReadAtlasContentTokens: {stat, value} pairs, at most 64
/// numbers.
fn tokens(mem: &ProcessMemory, at: u64) -> Vec<Token> {
    let raw: Vec<u32> = read_vector(mem, at + node::TOKENS).unwrap_or_default();
    if raw.len() < 2 || raw.len() > MAX_CONTENT || !raw.len().is_multiple_of(2) {
        return Vec::new();
    }
    raw.as_chunks::<2>()
        .0
        .iter()
        .map(|[stat, value]| Token {
            stat: stat & 0xFFFF,
            value: *value,
        })
        .collect()
}

fn add_badge(id: u32, badges: &mut Vec<u32>, content: &mut Vec<String>) {
    if !badges.iter().any(|b| b & 0xFFFF == id) {
        badges.push(id);
    }
    if let Some(name) = badge_name(id)
        && !content.iter().any(|c| c.eq_ignore_ascii_case(name))
    {
        content.push(name.to_string());
    }
}

/// One map node, or None when its pointer chain does not read.
fn read_node(
    mem: &ProcessMemory,
    index: usize,
    at: u64,
    visible: bool,
    all_links: &BTreeMap<[i32; 2], BTreeSet<[i32; 2]>>,
) -> Option<MapNode> {
    let storage: u64 = mem
        .read_value(at + node::DATA_STORAGE)
        .ok()
        .filter(|p| *p != 0)?;
    let data: u64 = mem
        .read_value(storage + node::DATA)
        .ok()
        .filter(|p| *p != 0)?;
    let grid: [i32; 2] = mem.read_value(at + node::GRID).ok()?;
    let biome: u8 = mem.read_value(data + node::BIOME).ok()?;
    let status: u8 = mem.read_value(data + node::STATUS).ok()?;
    let map_id = map_id(mem, data);

    // The content container is the node's first child's first child.
    let mut badges = Vec::new();
    let mut content = Vec::new();
    if let Some(container) = ui::child(mem, at, 0).and_then(|c| ui::child(mem, c, 0)) {
        let kids = ui::children(mem, container);
        if kids.len() <= MAX_CONTENT {
            for kid in kids.into_iter().filter(|k| *k != 0) {
                badges.push(mem.read_value(kid + node::BADGE_ID).unwrap_or(0));
                let name = mem
                    .read_value::<u64>(kid + node::BADGE_NAME)
                    .ok()
                    .and_then(|p| wide_at(mem, p))
                    .filter(|n| !n.trim().is_empty());
                content.extend(name);
            }
        }
    }
    // GameHelper2 skips hideouts by their world area tags; the id rule
    // the zone reader uses stands in for those tags here.
    if !crate::zone::is_hideout(&map_id) {
        let begin: u64 = mem.read_value(at + node::BADGES_BEGIN).unwrap_or(0);
        let end: u64 = mem.read_value(at + node::BADGES_END).unwrap_or(0);
        let count = end.wrapping_sub(begin) as usize;
        if begin != 0
            && end > begin
            && count <= MAX_CONTENT
            && let Ok(rows) = mem.read_array::<u8>(begin, count)
        {
            for row in rows {
                add_badge(u32::from(row) + BADGE_ROW_TO_ID, &mut badges, &mut content);
            }
        }
        let lower = map_id.to_lowercase();
        if lower.starts_with("expeditionsubarea") {
            add_badge(0x64, &mut badges, &mut content);
        } else if lower.starts_with("expeditionlogbook") {
            add_badge(0xA6, &mut badges, &mut content);
        }
    }
    Some(MapNode {
        index,
        address: at,
        map_id,
        grid,
        biome,
        status,
        state: state(status),
        visible,
        badges,
        content,
        tokens: tokens(mem, at),
        links: all_links
            .get(&grid)
            .map(|s| s.iter().copied().collect())
            .unwrap_or_default(),
    })
}

/// The atlas panel at `atlas` and its nodes.
pub fn read(mem: &ProcessMemory, atlas: u64) -> Result<Atlas> {
    let kids = ui::children(mem, atlas);
    ensure!(
        !kids.is_empty() && kids.len() <= MAX_CHILDREN,
        "atlas has {} children",
        kids.len()
    );
    let all_links = links(mem, atlas);
    let mut nodes = Vec::new();
    let mut ocean_buttons = Vec::new();
    let mut markers = 0;
    for (i, at) in kids.into_iter().enumerate() {
        if at == 0 {
            continue;
        }
        let Ok(flags) = mem.read_value::<u32>(at + ui::element::FLAGS) else {
            continue;
        };
        let fp = flags & !VISIBLE;
        let visible = flags & VISIBLE != 0;
        if fp == MARKER_FP & !VISIBLE {
            markers += usize::from(visible);
            continue;
        }
        if fp != MAP_NODE_FP & !VISIBLE && fp != MIST_NODE_FP & !VISIBLE {
            let row: Option<i32> = mem.read_value(at + region_button::ROW_INDEX).ok();
            let row_ptr: u64 = mem.read_value(at + region_button::ROW_PTR).unwrap_or(0);
            let grid: Option<[i32; 2]> = mem.read_value(at + region_button::GRID).ok();
            if row == Some(region_button::OCEAN_ROW)
                && row_ptr != 0
                && let Some(g) = grid
                && g.iter().all(|v| v.abs() <= region_button::GRID_LIMIT)
            {
                ocean_buttons.push(g);
            }
            continue;
        }
        nodes.extend(read_node(mem, i, at, visible, &all_links));
    }
    Ok(Atlas {
        address: atlas,
        nodes,
        ocean_buttons,
        markers,
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::tests::put;
    use crate::ui::tests::{fake_elements, set_children};
    use modforge::msvc_std::Vector;

    fn vector_of<T>(items: &[T]) -> Vector {
        let first = items.as_ptr() as u64;
        let last = first + size_of_val(items) as u64;
        Vector {
            first,
            last,
            end: last,
        }
    }

    #[test]
    fn states_and_badge_names() {
        assert_eq!(state(0), NodeState::Locked);
        assert_eq!(state(1), NodeState::Open);
        assert_eq!(state(3), NodeState::Done);
        assert_eq!(badge_name(0x0002_0064), Some("Powerful Map Boss"));
        assert_eq!(badge_name(0x03E9), None);
    }

    #[test]
    fn reads_nodes_links_content_and_markers() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        // 0 atlas; 1 map node; 2 marker; 3 content holder; 4 content
        // container; 5 badge child; 6 sea ship button.
        let (mut el, at) = fake_elements(7);
        let atlas_kids = [at[1], at[2], at[6]];
        set_children(&mut el[0][..], &atlas_kids);
        let edges = [
            Edge {
                _unknown: 0,
                source: [3, 4],
                target: [5, 6],
            },
            Edge {
                _unknown: 0,
                source: [3, 4],
                target: [0, 0],
            },
        ];
        put(&mut el[0][..], 0x590, vector_of(&edges));

        // Map node: flags, data chain, grid, content, tokens, badges.
        put(&mut el[1][..], 0x168, MAP_NODE_FP | VISIBLE);
        let id: Vec<u16> = "MapBluff\0".encode_utf16().collect();
        let buffer = [id.as_ptr() as u64];
        let header = [buffer.as_ptr() as u64];
        let mut data = vec![0u8; 0x2C0];
        put(&mut data[..], 0x290, header.as_ptr() as u64);
        data[0x2BE] = 4;
        data[0x2BF] = 0x01;
        // GameHelper2 reads the node's children vector start (+0x10)
        // and 0x20 past it: the data is the fifth child entry. Child 0
        // holds the content container, whose child is one badge.
        let node_kids = [at[3], 0, 0, 0, data.as_ptr() as u64];
        set_children(&mut el[1][..], &node_kids);
        let holder_kids = [at[4]];
        set_children(&mut el[3][..], &holder_kids);
        let badge_kids = [at[5]];
        set_children(&mut el[4][..], &badge_kids);
        put(&mut el[5][..], 0x170, 0x0002_0068u32);
        let ritual: Vec<u16> = "Ritual\0".encode_utf16().collect();
        put(&mut el[5][..], 0x278, ritual.as_ptr() as u64);
        put(&mut el[1][..], 0x310, [3i32, 4]);
        let raw_tokens = [0x0001_686Eu32, 2];
        put(&mut el[1][..], 0x350, vector_of(&raw_tokens));
        let rows = [3u8, 0];
        put(&mut el[1][..], 0x368, rows.as_ptr() as u64);
        put(&mut el[1][..], 0x370, rows.as_ptr() as u64 + 2);

        // Marker, showing.
        put(&mut el[2][..], 0x168, MARKER_FP | VISIBLE);
        // Sea ship.
        put(&mut el[6][..], 0x168, 0x1234u32);
        put(&mut el[6][..], 0x320, 2i32);
        put(&mut el[6][..], 0x308, 1u64);
        put(&mut el[6][..], 0x318, [16i32, -32]);

        let a = read(&mem, at[0]).unwrap();
        assert_eq!(a.markers, 1);
        assert_eq!(a.ocean_buttons, [[16, -32]]);
        assert_eq!(a.nodes.len(), 1);
        let n = &a.nodes[0];
        assert_eq!(n.map_id, "MapBluff");
        assert_eq!((n.grid, n.biome, n.state), ([3, 4], 4, NodeState::Open));
        assert_eq!(n.links, [[5, 6]]);
        assert_eq!(
            n.tokens,
            [Token {
                stat: 0x686E,
                value: 2
            }]
        );
        // The badge child first, then rows 3 and 0 of the node's own
        // list: ids 103 (Delirium) and 100 (Powerful Map Boss).
        assert_eq!(n.badges, [0x0002_0068, 0x67, 0x64]);
        assert_eq!(n.content, ["Ritual", "Delirium", "Powerful Map Boss"]);
    }
}
