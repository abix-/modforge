//! The one path search (A*, Hart, Nilsson and Raphael 1968): roads over
//! the world's cells, people around walls, and people across chunks by
//! their doorways (topside docs/pathing.md). The caller says where a
//! place leads and at what cost, and how far a place is from the goal;
//! the search is plain data and bounded.

use std::collections::{BinaryHeap, HashMap};
use std::hash::Hash;

/// A cell of a grid, column and row.
pub type Cell = (i32, i32);

/// The eight neighbours, straight first.
const NEIGHBOURS: [(i32, i32); 8] = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (1, -1), (-1, 1), (1, 1)];

struct Open<N>(f32, N);
impl<N> PartialEq for Open<N> {
    fn eq(&self, other: &Self) -> bool {
        self.0 == other.0
    }
}
impl<N> Eq for Open<N> {}
impl<N> PartialOrd for Open<N> {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}
impl<N> Ord for Open<N> {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.0.total_cmp(&self.0)
    }
}

/// The cheapest path of places from `start` to the first place where
/// `is_goal` holds, both included, and its cost. `next(place)` lists
/// where a place leads and what each step costs; `estimate(place)` must
/// not overestimate the cost left. Gives up after expanding `limit`
/// places.
pub fn search<N: Copy + Eq + Hash>(
    start: N,
    mut next: impl FnMut(N) -> Vec<(N, f32)>,
    estimate: impl Fn(N) -> f32,
    is_goal: impl Fn(N) -> bool,
    limit: usize,
) -> Option<(Vec<N>, f32)> {
    let mut best: HashMap<N, f32> = HashMap::new();
    let mut came: HashMap<N, N> = HashMap::new();
    let mut open = BinaryHeap::new();
    best.insert(start, 0.0);
    open.push(Open(estimate(start), start));
    let mut expanded = 0;
    while let Some(Open(_, at)) = open.pop() {
        if is_goal(at) {
            let mut path = vec![at];
            let mut back = at;
            while let Some(&p) = came.get(&back) {
                path.push(p);
                back = p;
            }
            path.reverse();
            return Some((path, best[&at]));
        }
        expanded += 1;
        if expanded > limit {
            return None;
        }
        let g = best[&at];
        for (to, cost) in next(at) {
            let cost = g + cost;
            if best.get(&to).is_none_or(|&b| cost < b) {
                best.insert(to, cost);
                came.insert(to, at);
                open.push(Open(cost + estimate(to), to));
            }
        }
    }
    None
}

/// The cheapest path of cells from `start` to `goal`, both included,
/// over a grid's eight neighbours. `step(from, to)` is the cost of a
/// step between neighbours, None when it cannot be taken;
/// `estimate(cell)` must not overestimate the cost left to the goal.
/// Gives up after expanding `limit` cells.
pub fn grid_path(
    start: Cell,
    goal: Cell,
    step: impl Fn(Cell, Cell) -> Option<f32>,
    estimate: impl Fn(Cell) -> f32,
    limit: usize,
) -> Option<Vec<Cell>> {
    let next = |at: Cell| {
        NEIGHBOURS
            .iter()
            .filter_map(|(dc, dr)| {
                let to = (at.0 + dc, at.1 + dr);
                step(at, to).map(|cost| (to, cost))
            })
            .collect()
    };
    search(start, next, estimate, |c| c == goal, limit).map(|(cells, _)| cells)
}

#[cfg(test)]
mod tests {
    use super::*;

    /// A wall along x = 5 from y = -3 to 3: the way round it.
    #[test]
    fn the_path_goes_round_a_wall() {
        let wall = |c: Cell| c.0 == 5 && (-3..=3).contains(&c.1);
        let step = |from: Cell, to: Cell| {
            (!wall(to)).then(|| if from.0 != to.0 && from.1 != to.1 { 1.414 } else { 1.0 })
        };
        let goal = (10, 0);
        let estimate = |c: Cell| (((goal.0 - c.0).pow(2) + (goal.1 - c.1).pow(2)) as f32).sqrt();
        let path = grid_path((0, 0), goal, step, estimate, 10_000).expect("a way round");
        assert_eq!(path.first(), Some(&(0, 0)));
        assert_eq!(path.last(), Some(&goal));
        assert!(path.iter().all(|&c| !wall(c)), "never through the wall");
        assert!(path.iter().any(|c| c.1.abs() > 3), "round an end of it");
    }

    #[test]
    fn a_goal_walled_in_is_given_up_on() {
        let step = |_: Cell, to: Cell| (to.0.abs() <= 3 && to.1.abs() <= 3).then_some(1.0);
        assert!(grid_path((0, 0), (9, 9), step, |_| 0.0, 500).is_none());
    }
}
