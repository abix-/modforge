//! The one grid path search (A*, Hart, Nilsson and Raphael 1968): roads
//! over the world's cells, people around walls. The caller says what a
//! step costs (None when it is blocked) and how far a cell is from the
//! goal; the search is plain data, eight neighbours, bounded.

use std::collections::{BinaryHeap, HashMap};

/// A cell of a grid, column and row.
pub type Cell = (i32, i32);

/// The eight neighbours, straight first.
const NEIGHBOURS: [(i32, i32); 8] = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (1, -1), (-1, 1), (1, 1)];

#[derive(PartialEq)]
struct Open(f32, Cell);
impl Eq for Open {}
impl PartialOrd for Open {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}
impl Ord for Open {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.0.total_cmp(&self.0)
    }
}

/// The cheapest path of cells from `start` to `goal`, both included.
/// `step(from, to)` is the cost of a step between neighbours, None when
/// it cannot be taken; `estimate(cell)` must not overestimate the cost
/// left to the goal. Gives up after expanding `limit` cells.
pub fn grid_path(
    start: Cell,
    goal: Cell,
    step: impl Fn(Cell, Cell) -> Option<f32>,
    estimate: impl Fn(Cell) -> f32,
    limit: usize,
) -> Option<Vec<Cell>> {
    let mut best: HashMap<Cell, f32> = HashMap::new();
    let mut came: HashMap<Cell, Cell> = HashMap::new();
    let mut open = BinaryHeap::new();
    best.insert(start, 0.0);
    open.push(Open(estimate(start), start));
    let mut expanded = 0;
    while let Some(Open(_, at)) = open.pop() {
        if at == goal {
            let mut cells = vec![at];
            let mut back = at;
            while let Some(&p) = came.get(&back) {
                cells.push(p);
                back = p;
            }
            cells.reverse();
            return Some(cells);
        }
        expanded += 1;
        if expanded > limit {
            return None;
        }
        let g = best[&at];
        for (dc, dr) in NEIGHBOURS {
            let next = (at.0 + dc, at.1 + dr);
            let Some(cost) = step(at, next) else {
                continue;
            };
            let cost = g + cost;
            if best.get(&next).is_none_or(|&b| cost < b) {
                best.insert(next, cost);
                came.insert(next, at);
                open.push(Open(cost + estimate(next), next));
            }
        }
    }
    None
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
