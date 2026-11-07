//! Placing pieces on a flat area for the best result a judge gives.
//!
//! The search under deployment planning (Mechabellum's plan_placement):
//! each piece is a rectangle by its centre; a move shifts one piece, or
//! all of them together, by a step in x or y. A move is tried only when
//! every moved piece is allowed where it lands (the game's own check)
//! and no two pieces overlap. The judge scores a whole placement
//! (higher is better); a better score is kept at once and the search
//! goes on from it. When no move at a step helps, the step gets
//! smaller. Plain hill climbing with shrinking steps (pattern search,
//! Hooke and Jeeves 1961).

/// A rectangle by its centre.
#[derive(Clone, Copy, Debug, PartialEq, Eq, serde::Serialize)]
pub struct Piece {
    pub x: i32,
    pub y: i32,
    pub w: i32,
    pub h: i32,
}

impl Piece {
    /// True when the two rectangles share any area (touching edges do not).
    pub fn overlaps(&self, o: &Piece) -> bool {
        (self.x - o.x).abs() * 2 < self.w + o.w && (self.y - o.y).abs() * 2 < self.h + o.h
    }

    fn shifted(&self, dx: i32, dy: i32) -> Piece {
        Piece { x: self.x + dx, y: self.y + dy, ..*self }
    }
}

/// The best placement found.
#[derive(Clone, Debug, serde::Serialize)]
pub struct Found {
    pub pieces: Vec<Piece>,
    pub score: f64,
    /// The start's score, for comparison.
    pub start_score: f64,
    /// Placements judged, the start included.
    pub tries: usize,
}

/// Best placement reachable from `start` in at most `budget` judgements.
/// `steps` largest first (for example `[100, 50, 20, 10]`). `allowed(i,
/// piece)` says whether piece `i` may stand there.
pub fn improve(
    start: Vec<Piece>,
    steps: &[i32],
    budget: usize,
    mut allowed: impl FnMut(usize, &Piece) -> bool,
    mut judge: impl FnMut(&[Piece]) -> f64,
) -> Found {
    let start_score = judge(&start);
    let mut found = Found { pieces: start, score: start_score, start_score, tries: 1 };
    let n = found.pieces.len();
    for &step in steps {
        let mut better = true;
        while better {
            better = false;
            // Piece i alone for i < n; i == n moves all of them together.
            for i in 0..=n {
                for (dx, dy) in [(step, 0), (-step, 0), (0, step), (0, -step)] {
                    if found.tries >= budget {
                        return found;
                    }
                    let mut cand = found.pieces.clone();
                    let moved: Vec<usize> = if i == n { (0..n).collect() } else { vec![i] };
                    for &j in &moved {
                        cand[j] = cand[j].shifted(dx, dy);
                    }
                    let fits = moved.iter().all(|&j| allowed(j, &cand[j]))
                        && moved.iter().all(|&j| (0..n).all(|k| k == j || !cand[j].overlaps(&cand[k])));
                    if !fits {
                        continue;
                    }
                    let score = judge(&cand);
                    found.tries += 1;
                    if score > found.score {
                        found.pieces = cand;
                        found.score = score;
                        better = true;
                    }
                }
            }
        }
    }
    found
}

#[cfg(test)]
mod tests {
    use super::*;

    fn p(x: i32, y: i32) -> Piece {
        Piece { x, y, w: 20, h: 10 }
    }

    #[test]
    fn overlap_is_area_not_edges() {
        assert!(p(0, 0).overlaps(&p(10, 0)));
        assert!(!p(0, 0).overlaps(&p(20, 0)));
        assert!(!p(0, 0).overlaps(&p(0, 10)));
    }

    #[test]
    fn climbs_to_the_judges_best_spot() {
        // Best at x = 130: reachable by steps of 100, 20, 10.
        let f = improve(vec![p(0, 0)], &[100, 20, 10], 500, |_, _| true, |ps| -((ps[0].x - 130).abs() as f64));
        assert_eq!(f.pieces[0].x, 130);
        assert_eq!(f.start_score, -130.0);
        assert_eq!(f.score, 0.0);
    }

    #[test]
    fn never_tries_a_refused_or_overlapping_placement() {
        let mut seen = Vec::new();
        let f = improve(
            vec![p(0, 0), p(40, 0)],
            &[20],
            200,
            |_, pc| pc.x >= 0 && pc.x <= 60,
            |ps| {
                seen.push(ps.to_vec());
                // Wants the two pieces as close as they go.
                -((ps[1].x - ps[0].x).abs() as f64)
            },
        );
        for ps in &seen[1..] {
            assert!(ps.iter().all(|pc| pc.x >= 0 && pc.x <= 60));
            assert!(!ps[0].overlaps(&ps[1]));
        }
        assert_eq!((f.pieces[1].x - f.pieces[0].x).abs(), 20);
    }

    #[test]
    fn stops_at_the_budget() {
        let f = improve(vec![p(0, 0)], &[1], 7, |_, _| true, |ps| ps[0].x as f64);
        assert_eq!(f.tries, 7);
    }
}
