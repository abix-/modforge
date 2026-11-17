//! The mod's own packing of the equipment grid: which pieces to wear
//! and where, for the most value, under the game's rules
//! (inventory.gd):
//!
//! - a piece's cells (shape_cells for its turn) sit on open cells only
//!   (cell_open) and inside the grid;
//! - a piece's hole cells (hole_cells: empty cells its shape walls in)
//!   take no other piece, and no piece sits in another's holes
//!   (fits, first_fit mark holes as taken); a hole may be on a shut
//!   cell;
//! - one piece per family (equip_block_reason "Already equipped");
//! - at most `hands` weapons ("Only one weapon").
//!
//! The search fills the first free cell in reading order each step:
//! some piece covers it with its first cell, or it stays empty. A
//! bound (the best value the free cells could still hold, by value per
//! cell) cuts branches that cannot win. Prior art: exact cover by the
//! first empty cell (Knuth, Algorithm X), with branch and bound for
//! the value.

/// One piece that may be worn.
#[derive(Debug, Clone)]
pub struct Piece {
    /// What wearing it is worth (the fight judge's gain).
    pub value: f64,
    /// Shape cells for turns 0 to 3, relative to the origin.
    pub shapes: [Vec<(i32, i32)>; 4],
    /// Hole cells for turns 0 to 3.
    pub holes: [Vec<(i32, i32)>; 4],
    /// The game's equip family (one worn per family).
    pub family: String,
    pub weapon: bool,
}

/// Where a piece goes.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Spot {
    pub piece: usize,
    pub x: i32,
    pub y: i32,
    pub rot: i32,
}

pub struct Grid {
    pub w: i32,
    pub h: i32,
    /// Row-major, w * h.
    pub open: Vec<bool>,
}

/// The best layout found, and whether the search ran to the end
/// (false: it stopped at `budget` steps with the best so far).
pub fn pack(grid: &Grid, pieces: &[Piece], hands: usize, budget: u64) -> (Vec<Spot>, f64, bool) {
    let n = (grid.w * grid.h) as usize;
    let mut s = Search {
        grid,
        pieces,
        hands,
        taken: vec![false; n],
        skipped: vec![false; n],
        used: vec![false; pieces.len()],
        families: Vec::new(),
        weapons: 0,
        layout: Vec::new(),
        value: 0.0,
        best: Vec::new(),
        best_value: 0.0,
        steps: 0,
        budget,
        order: Vec::new(),
    };
    // Turns that give the same cells are tried once.
    let mut order: Vec<usize> = (0..pieces.len())
        .filter(|&i| pieces[i].value > 0.0)
        .collect();
    order.sort_by(|&a, &b| {
        let pa = pieces[a].value / pieces[a].shapes[0].len().max(1) as f64;
        let pb = pieces[b].value / pieces[b].shapes[0].len().max(1) as f64;
        pb.total_cmp(&pa)
    });
    s.order = order;
    s.go(0);
    let done = s.steps < s.budget;
    (s.best, s.best_value, done)
}

struct Search<'a> {
    grid: &'a Grid,
    pieces: &'a [Piece],
    hands: usize,
    taken: Vec<bool>,
    skipped: Vec<bool>,
    used: Vec<bool>,
    families: Vec<String>,
    weapons: usize,
    layout: Vec<Spot>,
    value: f64,
    best: Vec<Spot>,
    best_value: f64,
    steps: u64,
    budget: u64,
    /// Pieces with value, best value per cell first.
    order: Vec<usize>,
}

impl Search<'_> {
    fn at(&self, x: i32, y: i32) -> Option<usize> {
        (x >= 0 && y >= 0 && x < self.grid.w && y < self.grid.h)
            .then(|| (y * self.grid.w + x) as usize)
    }

    /// The most the free cells could still add: unused pieces by value
    /// per cell, filling the free cells (the last one in part).
    fn bound(&self, from: usize) -> f64 {
        let mut free = (from..self.taken.len())
            .filter(|&c| self.grid.open[c] && !self.taken[c] && !self.skipped[c])
            .count() as f64;
        let mut add = 0.0;
        for &i in &self.order {
            if self.used[i] || free <= 0.0 {
                continue;
            }
            let cells = self.pieces[i].shapes[0].len().max(1) as f64;
            if cells <= free {
                add += self.pieces[i].value;
                free -= cells;
            } else {
                add += self.pieces[i].value * free / cells;
                free = 0.0;
            }
        }
        self.value + add
    }

    fn fits(&self, p: &Piece, rot: usize, ox: i32, oy: i32) -> bool {
        for &(dx, dy) in &p.shapes[rot] {
            match self.at(ox + dx, oy + dy) {
                Some(c) if self.grid.open[c] && !self.taken[c] => {}
                _ => return false,
            }
        }
        for &(dx, dy) in &p.holes[rot] {
            match self.at(ox + dx, oy + dy) {
                Some(c) if !self.taken[c] => {}
                _ => return false,
            }
        }
        true
    }

    fn mark(&mut self, p: &Piece, rot: usize, ox: i32, oy: i32, on: bool) {
        for &(dx, dy) in p.shapes[rot].iter().chain(&p.holes[rot]) {
            if let Some(c) = self.at(ox + dx, oy + dy) {
                self.taken[c] = on;
            }
        }
    }

    fn go(&mut self, from: usize) {
        self.steps += 1;
        if self.value > self.best_value {
            self.best_value = self.value;
            self.best = self.layout.clone();
        }
        if self.steps >= self.budget || self.bound(from) <= self.best_value + 1e-12 {
            return;
        }
        let Some(cell) = (from..self.taken.len())
            .find(|&c| self.grid.open[c] && !self.taken[c] && !self.skipped[c])
        else {
            return;
        };
        let (cx, cy) = ((cell as i32) % self.grid.w, (cell as i32) / self.grid.w);
        for k in 0..self.order.len() {
            let i = self.order[k];
            let p = &self.pieces[i];
            if self.used[i]
                || self.families.contains(&p.family)
                || (p.weapon && self.weapons >= self.hands)
            {
                continue;
            }
            let mut seen: Vec<&Vec<(i32, i32)>> = Vec::new();
            for rot in 0..4 {
                if seen.contains(&&p.shapes[rot]) {
                    continue;
                }
                seen.push(&p.shapes[rot]);
                // The first cell in reading order goes on `cell`.
                let Some(&(fx, fy)) = p.shapes[rot].iter().min_by_key(|&&(x, y)| (y, x)) else {
                    continue;
                };
                let (ox, oy) = (cx - fx, cy - fy);
                if !self.fits(p, rot, ox, oy) {
                    continue;
                }
                let p = p.clone();
                self.mark(&p, rot, ox, oy, true);
                self.used[i] = true;
                self.families.push(p.family.clone());
                self.weapons += usize::from(p.weapon);
                self.layout.push(Spot {
                    piece: i,
                    x: ox,
                    y: oy,
                    rot: rot as i32,
                });
                self.value += p.value;
                self.go(cell + 1);
                self.value -= p.value;
                self.layout.pop();
                self.weapons -= usize::from(p.weapon);
                self.families.pop();
                self.used[i] = false;
                self.mark(&p, rot, ox, oy, false);
                if self.steps >= self.budget {
                    return;
                }
            }
        }
        // Or the cell stays empty.
        self.skipped[cell] = true;
        self.go(cell + 1);
        self.skipped[cell] = false;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn piece(value: f64, cells: &[(i32, i32)], family: &str, weapon: bool) -> Piece {
        let turn = |c: &[(i32, i32)]| -> Vec<(i32, i32)> {
            // Clockwise, then moved back to start at 0.
            let r: Vec<(i32, i32)> = c.iter().map(|&(x, y)| (-y, x)).collect();
            let mx = r.iter().map(|c| c.0).min().unwrap_or(0);
            let my = r.iter().map(|c| c.1).min().unwrap_or(0);
            r.iter().map(|&(x, y)| (x - mx, y - my)).collect()
        };
        let a = cells.to_vec();
        let b = turn(&a);
        let c = turn(&b);
        let d = turn(&c);
        Piece {
            value,
            shapes: [a, b, c, d],
            holes: [vec![], vec![], vec![], vec![]],
            family: family.into(),
            weapon,
        }
    }

    fn grid(w: i32, h: i32) -> Grid {
        Grid {
            w,
            h,
            open: vec![true; (w * h) as usize],
        }
    }

    /// First fit would put the long piece flat on row 0 and leave no
    /// room for the square; turned upright both fit.
    #[test]
    fn turns_a_piece_to_fit_more() {
        let g = grid(3, 3);
        let pieces = [
            piece(1.0, &[(0, 0), (1, 0), (2, 0)], "bar", false),
            piece(1.0, &[(0, 0), (1, 0), (0, 1), (1, 1)], "box", false),
        ];
        let (layout, value, done) = pack(&g, &pieces, 1, 1_000_000);
        assert!(done);
        assert_eq!(layout.len(), 2, "{layout:?}");
        assert!((value - 2.0).abs() < 1e-9);
    }

    #[test]
    fn one_per_family_and_weapon_limit() {
        let g = grid(4, 1);
        let pieces = [
            piece(3.0, &[(0, 0)], "sword", true),
            piece(2.0, &[(0, 0)], "axe", true),
            piece(1.0, &[(0, 0)], "ring", false),
            piece(1.0, &[(0, 0)], "ring", false),
        ];
        let (layout, value, _) = pack(&g, &pieces, 1, 1_000_000);
        let ids: Vec<usize> = layout.iter().map(|s| s.piece).collect();
        assert!(ids.contains(&0) && !ids.contains(&1), "{ids:?}");
        assert!((value - 4.0).abs() < 1e-9);
    }

    #[test]
    fn shut_cells_take_nothing() {
        let mut g = grid(2, 2);
        g.open = vec![true, true, false, false];
        let pieces = [piece(1.0, &[(0, 0), (0, 1)], "tall", false)];
        let (layout, _, _) = pack(&g, &pieces, 1, 1_000_000);
        let s = layout[0];
        assert_eq!(s.y, 0);
        assert!(s.rot == 1 || s.rot == 3, "lies flat: {s:?}");
    }

    /// A piece's hole takes no other piece.
    #[test]
    fn holes_stay_empty() {
        let g = grid(3, 3);
        let mut ring = piece(
            5.0,
            &[
                (0, 0),
                (1, 0),
                (2, 0),
                (0, 1),
                (2, 1),
                (0, 2),
                (1, 2),
                (2, 2),
            ],
            "ring",
            false,
        );
        ring.holes = [vec![(1, 1)], vec![(1, 1)], vec![(1, 1)], vec![(1, 1)]];
        let pieces = [ring, piece(1.0, &[(0, 0)], "dot", false)];
        let (layout, value, _) = pack(&g, &pieces, 1, 1_000_000);
        assert_eq!(layout.len(), 1, "{layout:?}");
        assert!((value - 5.0).abs() < 1e-9);
    }
}
