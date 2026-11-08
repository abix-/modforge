//! Map names and routes on the atlas after GameHelper2 (Utils
//! WorldAreaNames.cs with Data/WorldAreaNames.tsv, copied to
//! data/world_area_names.tsv; Plugins/Atlas2 Atlas2.cs RefreshNodeCache,
//! MultiSourceBfs, PathFromAccessible; Atlas2Settings.cs): the shortest
//! hop path from any open map to each target map.

use crate::atlas::{Atlas, MapNode, NodeState};
use serde::Serialize;
use std::collections::{BTreeMap, HashMap, HashSet, VecDeque};

/// Atlas2Settings "Towers" group.
pub const TOWERS: [&str; 5] = [
    "Bluff",
    "Lost Towers",
    "Mesa",
    "Sinking Spire",
    "Alpine Ridge",
];
/// Atlas2.RoutingExcludedMaps: never a start or a way through.
pub const ROUTING_EXCLUDED: [&str; 1] = ["MapUniqueReactor_04"];
/// Atlas2Settings MaxHops default.
pub const MAX_HOPS: usize = 15;

type Grid = [i32; 2];

/// WorldAreaNames: internal world area id to the name shown in game.
pub fn names() -> HashMap<&'static str, &'static str> {
    include_str!("../data/world_area_names.tsv")
        .lines()
        .filter(|l| !l.is_empty() && !l.starts_with('#'))
        .filter_map(|l| l.split_once('\t'))
        .filter(|(id, _)| !id.is_empty())
        .collect()
}

/// The name shown for a map id, the id itself when unknown.
pub fn display_name<'a>(names: &HashMap<&str, &'a str>, id: &'a str) -> &'a str {
    names.get(id).copied().unwrap_or(id)
}

/// MultiSourceBfs: from every source over the links, a no-pass node is
/// reached but never left. Gives each reached node the one it came from.
pub fn multi_source_bfs(
    graph: &BTreeMap<Grid, Vec<Grid>>,
    sources: &HashSet<Grid>,
    no_pass: &HashSet<Grid>,
) -> HashMap<Grid, Grid> {
    let mut came_from = HashMap::new();
    let mut visited = HashSet::new();
    let mut queue = VecDeque::new();
    let mut seeds: Vec<_> = sources.iter().copied().collect();
    seeds.sort();
    for s in seeds {
        if graph.contains_key(&s) && !no_pass.contains(&s) && visited.insert(s) {
            queue.push_back(s);
        }
    }
    while let Some(cur) = queue.pop_front() {
        if no_pass.contains(&cur) {
            continue;
        }
        for &nb in graph.get(&cur).into_iter().flatten() {
            if visited.insert(nb) {
                came_from.insert(nb, cur);
                queue.push_back(nb);
            }
        }
    }
    came_from
}

/// PathFromAccessible: the path from an open map to `target`, None when
/// it cannot be reached.
pub fn path_from(
    target: Grid,
    came_from: &HashMap<Grid, Grid>,
    sources: &HashSet<Grid>,
) -> Option<Vec<Grid>> {
    if sources.contains(&target) {
        return Some(vec![target]);
    }
    came_from.get(&target)?;
    let mut path = vec![target];
    let mut cur = target;
    while let Some(&prev) = came_from.get(&cur) {
        cur = prev;
        path.push(cur);
    }
    path.reverse();
    Some(path)
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Route {
    pub map_id: String,
    pub name: String,
    pub target: Grid,
    /// From the open map to start in, to the target.
    pub path: Vec<Grid>,
    pub hops: usize,
}

/// Routes to every map not done yet whose shown name is in `targets`
/// (ignoring case), at most `max_hops` long.
pub fn routes(atlas: &Atlas, targets: &[&str], max_hops: usize) -> Vec<Route> {
    let names = names();
    let graph: BTreeMap<Grid, Vec<Grid>> = atlas
        .nodes
        .iter()
        .map(|n| (n.grid, n.links.clone()))
        .collect();
    let excluded = |n: &MapNode| ROUTING_EXCLUDED.contains(&n.map_id.as_str());
    let no_pass: HashSet<Grid> = atlas
        .nodes
        .iter()
        .filter(|n| excluded(n))
        .map(|n| n.grid)
        .collect();
    let sources: HashSet<Grid> = atlas
        .nodes
        .iter()
        .filter(|n| !excluded(n) && n.state == NodeState::Open)
        .map(|n| n.grid)
        .collect();
    let came_from = multi_source_bfs(&graph, &sources, &no_pass);
    atlas
        .nodes
        .iter()
        .filter(|n| n.state != NodeState::Done)
        .filter_map(|n| {
            let name = display_name(&names, &n.map_id);
            if !targets.iter().any(|t| t.eq_ignore_ascii_case(name)) {
                return None;
            }
            let path = path_from(n.grid, &came_from, &sources)?;
            let hops = path.len() - 1;
            (hops <= max_hops).then(|| Route {
                map_id: n.map_id.clone(),
                name: name.to_string(),
                target: n.grid,
                path,
                hops,
            })
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn node(map_id: &str, grid: Grid, state: NodeState, links: &[Grid]) -> MapNode {
        MapNode {
            index: 0,
            address: 0,
            map_id: map_id.into(),
            grid,
            biome: 0,
            status: 0,
            state,
            visible: true,
            badges: Vec::new(),
            content: Vec::new(),
            tokens: Vec::new(),
            links: links.to_vec(),
        }
    }

    #[test]
    fn names_load() {
        let n = names();
        assert_eq!(display_name(&n, "Abyss_Boss1"), "Lightless Void");
        assert_eq!(display_name(&n, "NoSuchMap"), "NoSuchMap");
        assert!(n.values().any(|v| *v == "Bluff"));
    }

    #[test]
    fn the_route_starts_at_the_nearest_open_map() {
        let bluff = names()
            .into_iter()
            .find(|(_, v)| *v == "Bluff")
            .map(|(k, _)| k)
            .unwrap();
        // Open A at (0,0) - B (1,0) - excluded X (2,0) - bluff (3,0),
        // and the long way round: A - C (0,1) - D (1,1) - E (2,1) - bluff.
        let atlas = Atlas {
            address: 0,
            nodes: vec![
                node("A", [0, 0], NodeState::Open, &[[1, 0], [0, 1]]),
                node("B", [1, 0], NodeState::Locked, &[[0, 0], [2, 0]]),
                node(
                    "MapUniqueReactor_04",
                    [2, 0],
                    NodeState::Open,
                    &[[1, 0], [3, 0]],
                ),
                node(bluff, [3, 0], NodeState::Locked, &[[2, 0], [2, 1]]),
                node("C", [0, 1], NodeState::Locked, &[[0, 0], [1, 1]]),
                node("D", [1, 1], NodeState::Locked, &[[0, 1], [2, 1]]),
                node("E", [2, 1], NodeState::Locked, &[[1, 1], [3, 0]]),
            ],
            ocean_buttons: Vec::new(),
            markers: 0,
        };
        let r = routes(&atlas, &TOWERS, MAX_HOPS);
        assert_eq!(r.len(), 1);
        assert_eq!(r[0].name, "Bluff");
        assert_eq!(r[0].path, [[0, 0], [0, 1], [1, 1], [2, 1], [3, 0]]);
        assert_eq!(r[0].hops, 4);
        assert!(routes(&atlas, &TOWERS, 3).is_empty());
        // The excluded map itself can still be routed to.
        let came = multi_source_bfs(
            &atlas
                .nodes
                .iter()
                .map(|n| (n.grid, n.links.clone()))
                .collect(),
            &HashSet::from([[0, 0]]),
            &HashSet::from([[2, 0]]),
        );
        assert_eq!(
            path_from([2, 0], &came, &HashSet::from([[0, 0]])),
            Some(vec![[0, 0], [1, 0], [2, 0]])
        );
    }
}
