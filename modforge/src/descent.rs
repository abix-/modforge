//! Rivers carved by descent (topside todo 33): a river starts at a high
//! tile and runs downhill, each step to its lowest neighbour, until it
//! reaches water or the world's edge; in a hollow with no lower
//! neighbour it spills over the lowest rim it has not yet run through
//! (the "steepest descent" river of Amit Patel's Red Blob Games map
//! generation, and Dwarf Fortress's river paths). Every few tiles is
//! left a ford, so no river cuts the world in two (topside design.md "A
//! valid world"). Engine-free, on any elevation.

use std::collections::HashSet;

use crate::path::Cell;

/// One river's tiles from `source`, in order, at most `most` long:
/// downhill on `elevation` until `ends` says it reached water or the edge.
pub fn river(source: Cell, elevation: impl Fn(Cell) -> f32, ends: impl Fn(Cell) -> bool, most: usize) -> Vec<Cell> {
    let mut path = vec![source];
    let mut seen: HashSet<Cell> = HashSet::from([source]);
    let mut here = source;
    while path.len() < most && !ends(here) {
        let next = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            .into_iter()
            .map(|(dx, dy)| (here.0 + dx, here.1 + dy))
            .filter(|n| !seen.contains(n))
            .min_by(|a, b| elevation(*a).total_cmp(&elevation(*b)));
        let Some(next) = next else {
            break;
        };
        seen.insert(next);
        path.push(next);
        here = next;
    }
    path
}

/// Whether a river's tile is a ford, walked across: one in `every`, by
/// the tile's place on the river.
pub fn ford(index: usize, every: usize) -> bool {
    every > 0 && index % every == every / 2
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn a_river_runs_downhill_to_the_water() {
        // A slope down to the east; the water is at x 10.
        let elevation = |t: Cell| -(t.0 as f32) + (t.1 as f32).abs() * 0.1;
        let path = river((0, 3), elevation, |t| t.0 >= 10, 100);
        assert_eq!(path.last().unwrap().0, 10);
        assert!(path.windows(2).all(|w| w[1].0 >= w[0].0), "never back uphill: {path:?}");
        // A hollow at the source still spills out.
        let bowl = |t: Cell| if t == (0, 0) { -1.0 } else { (t.0 as f32).abs() - t.0 as f32 * 0.5 };
        assert!(river((0, 0), bowl, |t| t.0 >= 5, 100).len() > 1);
        assert!(ford(4, 8) && !ford(0, 8));
    }
}
