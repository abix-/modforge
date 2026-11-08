//! Walking on a grid of open and blocked cells, after GameHelper2's
//! Radar (Pathfinder.cs, LineWalker.cs): the path search with no corner
//! cutting, the nearest open cell, a straight line check and path
//! smoothing. The caller says which cells are open.

use crate::path::{Cell, grid_path};

const DIAGONAL: f32 = std::f32::consts::SQRT_2;

/// The straight line distance between two cells.
pub fn distance(a: Cell, b: Cell) -> f32 {
    let (dx, dy) = ((b.0 - a.0) as f32, (b.1 - a.1) as f32);
    (dx * dx + dy * dy).sqrt()
}

/// Every cell on the Bresenham line from `a` to `b`, both included, is
/// open (LineWalker.CheckLine).
pub fn line_clear(a: Cell, b: Cell, open: impl Fn(Cell) -> bool) -> bool {
    let (dx, dy) = ((b.0 - a.0).abs(), (b.1 - a.1).abs());
    let sx = if a.0 < b.0 { 1 } else { -1 };
    let sy = if a.1 < b.1 { 1 } else { -1 };
    let (mut x, mut y, mut err) = (a.0, a.1, dx - dy);
    loop {
        if !open((x, y)) {
            return false;
        }
        if (x, y) == b {
            return true;
        }
        let e2 = err * 2;
        if e2 > -dy {
            err -= dy;
            x += sx;
        }
        if e2 < dx {
            err += dx;
            y += sy;
        }
    }
}

/// The open cell nearest `at`, scanning square rings outward up to
/// `radius` (Pathfinder.TryFindNearestWalkable).
pub fn nearest_open(at: Cell, radius: i32, open: impl Fn(Cell) -> bool) -> Option<Cell> {
    if open(at) {
        return Some(at);
    }
    let (x, y) = at;
    for r in 1..=radius {
        for dx in -r..=r {
            for c in [(x + dx, y - r), (x + dx, y + r)] {
                if open(c) {
                    return Some(c);
                }
            }
        }
        for dy in (-r + 1)..r {
            for c in [(x - r, y + dy), (x + r, y + dy)] {
                if open(c) {
                    return Some(c);
                }
            }
        }
    }
    None
}

/// The cheapest path over open cells from `start` to `goal`, both
/// included: eight directions, a diagonal step only when both straight
/// cells beside it are open. Gives up after expanding `limit` cells.
pub fn walk_path(
    start: Cell,
    goal: Cell,
    open: impl Fn(Cell) -> bool,
    limit: usize,
) -> Option<Vec<Cell>> {
    let step = |from: Cell, to: Cell| {
        if !open(to) {
            return None;
        }
        if from.0 == to.0 || from.1 == to.1 {
            return Some(1.0);
        }
        (open((to.0, from.1)) && open((from.0, to.1))).then_some(DIAGONAL)
    };
    grid_path(start, goal, step, |c| distance(c, goal), limit)
}

/// The path with the points in between dropped wherever a straight
/// clear line reaches further along it (Pathfinder.SmoothPath).
pub fn smooth(path: &[Cell], open: impl Fn(Cell) -> bool) -> Vec<Cell> {
    if path.len() <= 2 {
        return path.to_vec();
    }
    let mut out = vec![path[0]];
    let mut at = 0;
    while at < path.len() - 1 {
        let far = (at + 2..path.len())
            .rev()
            .find(|&i| line_clear(path[at], path[i], &open))
            .unwrap_or(at + 1);
        at = far;
        out.push(path[at]);
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    /// A 10 by 10 room with a wall at x = 5 from y = 0 to 7.
    fn room(c: Cell) -> bool {
        (0..10).contains(&c.0) && (0..10).contains(&c.1) && !(c.0 == 5 && c.1 <= 7)
    }

    #[test]
    fn the_line_is_blocked_by_the_wall() {
        assert!(line_clear((0, 0), (4, 7), room));
        assert!(!line_clear((0, 0), (9, 0), room));
        assert!(line_clear((0, 9), (9, 9), room));
    }

    #[test]
    fn the_nearest_open_cell_is_beside_the_wall() {
        assert_eq!(nearest_open((1, 1), 3, room), Some((1, 1)));
        assert_eq!(nearest_open((5, 3), 3, room), Some((4, 2)));
        assert_eq!(nearest_open((50, 50), 3, room), None);
    }

    #[test]
    fn the_path_goes_round_the_wall_without_cutting_corners() {
        let path = walk_path((0, 0), (9, 0), room, 10_000).unwrap();
        assert_eq!(path.first(), Some(&(0, 0)));
        assert_eq!(path.last(), Some(&(9, 0)));
        assert!(path.iter().all(|&c| room(c)));
        assert!(path.iter().any(|c| c.1 >= 8));
        for w in path.windows(2) {
            let (a, b) = (w[0], w[1]);
            if a.0 != b.0 && a.1 != b.1 {
                assert!(room((b.0, a.1)) && room((a.0, b.1)), "{a:?} to {b:?}");
            }
        }
        let short = smooth(&path, room);
        assert!(short.len() < path.len());
        assert_eq!(short.first(), path.first());
        assert_eq!(short.last(), path.last());
        assert!(short.windows(2).all(|w| line_clear(w[0], w[1], room)));
    }

    #[test]
    fn no_path_out_of_a_closed_room() {
        let closed = |c: Cell| room(c) && c.1 <= 7;
        assert_eq!(walk_path((0, 0), (9, 0), closed, 10_000), None);
    }
}
