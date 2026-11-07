//! Units against units, in numbers that name no game.
//!
//! A game crate reads its units into [`UnitStats`] (Mechabellum:
//! mechabellum-mod `src/units.rs`) and every comparison it shows the
//! player (the starting lineup, matchups, deployment) goes through
//! here, so they all count the same way.
//!
//! Two levels:
//! - [`totals`]: a group's summed life and damage per second, no map.
//! - [`fight`]: two groups of placed units fought out in time steps.
//!   Each unit picks the nearest enemy it can hit (air or ground),
//!   walks until it is in range, attacks every `attack_interval`
//!   seconds, and its splash hits every enemy of that kind within
//!   `splash` of the target. Range, speed and formation (where each
//!   unit starts, [`formation`]) all change the result.
//!
//! Operator 2026-11-07: "simulated fights between two units ... as we
//! play we can use the data to refine our math"; "it should be units vs
//! units ... eventually we'll have to do math worrying about range and
//! formation". Weapon count, armor, crowd control and unit size are
//! not yet counted (not yet proven how the game uses them); the fight
//! is to be checked against real fights (mechabellum-mod
//! research_fight) and against the game's own simulation.

use serde::Serialize;

/// One kind of unit, as many of it as the player has.
#[derive(Clone, Debug, Default, Serialize)]
pub struct UnitStats {
    pub id: i64,
    pub name: String,
    /// How many of this unit.
    pub count: u32,
    pub life: f64,
    /// Damage per hit.
    pub damage: f64,
    /// Seconds between attacks.
    pub attack_interval: f64,
    pub range: f64,
    pub splash: f64,
    /// Map units per second.
    pub speed: f64,
    pub weapons: u32,
    pub hits_air: bool,
    pub hits_ground: bool,
    pub flies: bool,
}

impl UnitStats {
    /// Damage per second of one unit.
    pub fn dps(&self) -> f64 {
        if self.attack_interval > 0.0 { self.damage / self.attack_interval } else { 0.0 }
    }

    /// Whether this unit can attack `other`.
    pub fn can_hit(&self, other: &UnitStats) -> bool {
        if other.flies { self.hits_air } else { self.hits_ground }
    }
}

/// A group's totals: all its units together.
#[derive(Clone, Debug, Default, PartialEq, Serialize)]
pub struct Totals {
    pub units: u32,
    pub life: f64,
    pub dps: f64,
    pub hits_air: bool,
}

pub fn totals(group: &[UnitStats]) -> Totals {
    let mut t = Totals::default();
    for u in group {
        let n = f64::from(u.count);
        t.units += u.count;
        t.life += u.life * n;
        t.dps += u.dps() * n;
        t.hits_air |= u.hits_air;
    }
    t
}

/// One unit on the map. `kind` indexes the side's list of
/// [`UnitStats`], so a hundred of one unit share one row.
#[derive(Clone, Debug, Serialize)]
pub struct Placed {
    pub kind: usize,
    pub x: f64,
    pub y: f64,
}

/// `count` units of one kind in rows of `per_row`, `spacing` apart,
/// centred on (x, y).
pub fn formation(kind: usize, count: u32, x: f64, y: f64, per_row: u32, spacing: f64) -> Vec<Placed> {
    let per_row = per_row.max(1);
    let rows = count.div_ceil(per_row);
    (0..count)
        .map(|i| {
            let (col, row) = (i % per_row, i / per_row);
            let in_row = per_row.min(count - row * per_row);
            Placed {
                kind,
                x: x + (f64::from(col) - f64::from(in_row - 1) / 2.0) * spacing,
                y: y + (f64::from(row) - f64::from(rows - 1) / 2.0) * spacing,
            }
        })
        .collect()
}

/// One side of a fight: its kinds of unit and where each unit stands.
pub struct Side<'a> {
    pub kinds: &'a [UnitStats],
    pub units: &'a [Placed],
}

/// What is left of one kind of unit after a fight.
#[derive(Clone, Debug, Default, PartialEq, Serialize)]
pub struct Left {
    pub kind: usize,
    pub alive: u32,
    pub life: f64,
    pub damage_dealt: f64,
}

#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct FightResult {
    /// 0 or 1, None when both sides still stand at the time limit or
    /// both die in the same step.
    pub winner: Option<usize>,
    pub seconds: f64,
    pub left: [Vec<Left>; 2],
}

struct Unit {
    side: usize,
    kind: usize,
    x: f64,
    y: f64,
    life: f64,
    cooldown: f64,
}

/// Time step of [`fight`], seconds.
pub const STEP: f64 = 0.1;

/// Fight two sides out, at most `limit` seconds.
pub fn fight(a: &Side, b: &Side, limit: f64) -> FightResult {
    let sides = [a, b];
    let mut units: Vec<Unit> = sides
        .iter()
        .enumerate()
        .flat_map(|(s, side)| {
            side.units.iter().map(move |p| Unit { side: s, kind: p.kind, x: p.x, y: p.y, life: side.kinds[p.kind].life, cooldown: 0.0 })
        })
        .collect();
    let mut dealt = [vec![0.0; a.kinds.len()], vec![0.0; b.kinds.len()]];
    let stats = |u: &Unit| &sides[u.side].kinds[u.kind];
    let mut t = 0.0;
    let alive = |units: &[Unit], s: usize| units.iter().any(|u| u.side == s && u.life > 0.0);
    while t < limit && alive(&units, 0) && alive(&units, 1) {
        // Damage lands at the end of the step, so neither side shoots first.
        let mut hits = vec![0.0; units.len()];
        let mut moves = Vec::new();
        let mut fired = Vec::new();
        for (i, u) in units.iter().enumerate() {
            if u.life <= 0.0 {
                continue;
            }
            let me = stats(u);
            let target = units
                .iter()
                .enumerate()
                .filter(|(_, e)| e.side != u.side && e.life > 0.0 && me.can_hit(stats(e)))
                .map(|(j, e)| (j, (e.x - u.x).hypot(e.y - u.y)))
                .min_by(|p, q| p.1.total_cmp(&q.1));
            let Some((j, dist)) = target else { continue };
            if dist > me.range {
                let step = (me.speed * STEP).min(dist - me.range);
                let (ex, ey) = (units[j].x, units[j].y);
                moves.push((i, u.x + (ex - u.x) / dist * step, u.y + (ey - u.y) / dist * step));
                continue;
            }
            if u.cooldown > 0.0 {
                continue;
            }
            let tgt = &units[j];
            for (k, e) in units.iter().enumerate() {
                let splashed = me.splash > 0.0 && (e.x - tgt.x).hypot(e.y - tgt.y) <= me.splash;
                if e.side != u.side && e.life > 0.0 && me.can_hit(stats(e)) && (k == j || splashed) {
                    hits[k] += me.damage;
                    dealt[u.side][u.kind] += me.damage.min(e.life);
                }
            }
            fired.push(i);
        }
        for i in fired {
            units[i].cooldown = stats(&units[i]).attack_interval;
        }
        for (i, x, y) in moves {
            units[i].x = x;
            units[i].y = y;
        }
        for (u, h) in units.iter_mut().zip(hits) {
            u.life -= h;
            u.cooldown -= STEP;
        }
        t += STEP;
    }
    let left = [0, 1].map(|s| {
        (0..sides[s].kinds.len())
            .map(|k| {
                let mine = units.iter().filter(|u| u.side == s && u.kind == k && u.life > 0.0);
                Left {
                    kind: k,
                    alive: mine.clone().count() as u32,
                    life: mine.map(|u| u.life).sum(),
                    damage_dealt: dealt[s][k],
                }
            })
            .collect()
    });
    let winner = match (alive(&units, 0), alive(&units, 1)) {
        (true, false) => Some(0),
        (false, true) => Some(1),
        _ => None,
    };
    FightResult { winner, seconds: t, left }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn unit(count: u32, life: f64, damage: f64, interval: f64, range: f64) -> UnitStats {
        UnitStats { count, life, damage, attack_interval: interval, range, speed: 10.0, hits_ground: true, ..Default::default() }
    }

    #[test]
    fn dps_is_damage_over_interval() {
        assert_eq!(unit(1, 1.0, 7858.0, 3.4, 1.0).dps(), 7858.0 / 3.4);
        assert_eq!(unit(1, 1.0, 10.0, 0.0, 1.0).dps(), 0.0);
    }

    #[test]
    fn totals_count_every_unit() {
        // Sabertooth x1 and two purchases of 12 Fangs (Mechabellum
        // Star Expedition rows, 2026-11-07).
        let mut fang = unit(24, 158.0, 104.0, 1.5, 80.0);
        fang.hits_air = true;
        let t = totals(&[unit(1, 15541.0, 7858.0, 3.4, 95.0), fang]);
        assert_eq!(t.units, 25);
        assert_eq!(t.life, 15541.0 + 24.0 * 158.0);
        assert!((t.dps - (7858.0 / 3.4 + 24.0 * 104.0 / 1.5)).abs() < 1e-9);
        assert!(t.hits_air);
    }

    #[test]
    fn formation_centres_rows() {
        let f = formation(0, 5, 0.0, 0.0, 3, 2.0);
        assert_eq!(f.len(), 5);
        assert_eq!((f[0].x, f[0].y), (-2.0, -1.0));
        assert_eq!((f[3].x, f[3].y), (-1.0, 1.0));
    }

    fn one(kinds: &[UnitStats], x: f64) -> Vec<Placed> {
        vec![Placed { kind: 0, x, y: 0.0 }; kinds[0].count as usize]
    }

    #[test]
    fn the_stronger_unit_wins_and_takes_damage() {
        let big = [unit(1, 100.0, 10.0, 1.0, 5.0)];
        let small = [unit(1, 30.0, 10.0, 1.0, 5.0)];
        let (pa, pb) = (one(&big, 0.0), one(&small, 4.0));
        let r = fight(&Side { kinds: &big, units: &pa }, &Side { kinds: &small, units: &pb }, 60.0);
        assert_eq!(r.winner, Some(0));
        assert_eq!(r.left[1][0].alive, 0);
        // Three hits kill the small one; it lands three too.
        assert_eq!(r.left[0][0].life, 70.0);
    }

    #[test]
    fn range_lets_a_unit_shoot_while_the_other_walks() {
        // Same life and damage; one outranges the other by 50 at speed 10,
        // so it gets five free seconds of shots.
        let long = [unit(1, 100.0, 10.0, 1.0, 60.0)];
        let short = [unit(1, 100.0, 10.0, 1.0, 10.0)];
        let (pa, pb) = (one(&long, 0.0), one(&short, 60.0));
        let r = fight(&Side { kinds: &long, units: &pa }, &Side { kinds: &short, units: &pb }, 60.0);
        assert_eq!(r.winner, Some(0));
    }

    #[test]
    fn splash_hits_a_packed_group_harder_than_a_spread_one() {
        let splasher = [UnitStats { splash: 3.0, ..unit(1, 10_000.0, 10.0, 1.0, 50.0) }];
        let swarm = [unit(9, 25.0, 0.0, 1.0, 1.0)];
        let me = one(&splasher, 0.0);
        let packed = formation(0, 9, 30.0, 0.0, 3, 1.0);
        let spread = formation(0, 9, 30.0, 0.0, 3, 10.0);
        let time = |p: &[Placed]| {
            fight(&Side { kinds: &splasher, units: &me }, &Side { kinds: &swarm, units: p }, 120.0).seconds
        };
        assert!(time(&packed) < time(&spread));
    }

    #[test]
    fn ground_only_units_cannot_hit_air() {
        let ground = [unit(1, 100.0, 10.0, 1.0, 50.0)];
        let air = [UnitStats { flies: true, ..unit(1, 100.0, 0.0, 1.0, 1.0) }];
        let (pa, pb) = (one(&ground, 0.0), one(&air, 10.0));
        let r = fight(&Side { kinds: &ground, units: &pa }, &Side { kinds: &air, units: &pb }, 10.0);
        assert_eq!(r.winner, None);
        assert_eq!(r.left[1][0].life, 100.0);
    }
}
