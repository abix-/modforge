//! Dungeonbound's fight, worked out by the mod.
//!
//! Operator 2026-11-16: "copying the game fight is what got us into
//! trouble in mechabellum. we need to do the math ourselves in our
//! mod"; "i want more than 80% for auto-success". So the game's fight
//! code is never run: its rules, read from the decompiled scripts
//! (combat_resolver.gd, combatant_runtime.gd, ability_timer.gd), are
//! written again here, and [`success_rate`] plays the fight many
//! times.
//!
//! Counted, as the game does it:
//! - time in steps of 1/60 game second; the player swings first in a
//!   step, then each engaged foe, then hits still on their way
//! - seconds between swings from speed, with the soft caps
//! - dodge and crit through the game's growing-chance roll
//!   ([`modforge::chance::Gate`]), with their soft caps
//! - double damage, the block pool, block chance, the small part a
//!   failed block still soaks, block pierce, magic resist
//! - a foe's second strike (multistrike) a quarter second later
//! - up to three foes at once; the next steps in, block full, when
//!   one falls
//! - in a roguelite run: fatigue from 60 s, and every block holding
//!
//! Not counted yet: statuses (burn, poison, stun, freeze, slow and
//! the rest), item triggers and procs, healing, thorns, curses,
//! bonuses against full, half or fast foes, area attacks, bows and
//! mana. A fight that leans on those is not yet predicted right.

use modforge::chance::Gate;

/// One game step (combat_resolver.gd COMBAT_STEP).
const STEP: f64 = 1.0 / 60.0;
const BASE_ATTACK_INTERVAL: f64 = 5.0;
const BASE_SPEED: f64 = 10.0;
const SPEED_SOFTNESS: f64 = 0.6;
const SPEED_SOFT_CAP: f64 = 20.0;
const SPEED_OVERCAP_SOFTNESS: f64 = 0.2;
const FASTEST_ATTACK: f64 = 0.5;
const SPEED_LOG_GAIN: f64 = 0.15;
const BLOCK_RESIDUAL: f64 = 0.15;
const DODGE_KNEE: f64 = 0.35;
const DODGE_LIMIT: f64 = 0.6;
const CRIT_KNEE: f64 = 0.5;
const CRIT_LIMIT: f64 = 0.85;
const MULTISTRIKE_KNEE: f64 = 0.35;
const MULTISTRIKE_LIMIT: f64 = 0.75;
const MAGIC_RESIST_KNEE: f64 = 0.5;
const MAGIC_RESIST_LIMIT: f64 = 0.75;
const CAMPAIGN_MAGIC_RESIST_LIMIT: f64 = 0.9;
const MULTISTRIKE_GAP: f64 = 0.25;
const MAX_ENGAGED: usize = 3;
const FATIGUE_START: f64 = 60.0;
const FATIGUE_STEP: f64 = 5.0;
const FATIGUE_MAX_DOUBLINGS: i32 = 30;
const FATIGUE_SHARE_FROM: i32 = 10;
const FATIGUE_SHARE_START: f64 = 0.01;
/// Game seconds after which a fight counts as lost.
const TIME_LIMIT: f64 = 600.0;

/// A fighter's numbers, as the game holds them on the fighter
/// (combatant_runtime.gd field names in brackets).
#[derive(Clone, Debug, Default)]
pub struct Fighter {
    pub name: String,
    /// `current_hp`
    pub hp: i64,
    /// `max_hp`
    pub max_hp: i64,
    /// `atk`
    pub atk: i64,
    /// `block_pool` now.
    pub block: i64,
    /// `block_max()`: armor times (1 + `armor_pool_mult`). A foe
    /// steps in with this much.
    pub block_max: i64,
    /// `block_chance`
    pub block_chance: f64,
    /// `speed`
    pub speed: f64,
    /// `speed_cut`
    pub speed_cut: f64,
    /// `dodge_chance`, before its soft cap.
    pub dodge: f64,
    /// `crit_chance`, before its soft cap.
    pub crit: f64,
    /// `crit_multiplier`
    pub crit_mult: f64,
    /// `multistrike_chance`, before its soft cap. Foes only.
    pub multistrike: f64,
    /// `double_dmg_chance`
    pub double_dmg: f64,
    /// `block_pierce`
    pub block_pierce: f64,
    /// `dmg_type == "magic"`
    pub magic: bool,
    /// `magic_resist`, before its soft cap.
    pub magic_resist: f64,
    /// `campaign_caps`
    pub campaign_caps: bool,
}

/// What kind of run: the rules differ (game_state.gd
/// `in_campaign_framing`, combat_resolver.gd `fatigue_amount`).
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Run {
    /// Blocks roll against block chance; magic resist counts; no
    /// fatigue.
    Campaign,
    /// Every block holds; magic resist is not rolled; fatigue.
    Roguelite,
}

/// How one fight ended.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Outcome {
    Won,
    Lost,
    /// Both sides fell together.
    Draw,
    /// Still going at the time limit.
    TimedOut,
}

#[derive(Clone, Debug)]
pub struct Result {
    pub outcome: Outcome,
    /// Game seconds.
    pub seconds: f64,
    pub hp_left: i64,
    /// Share of the squad's max hp still standing at the end.
    pub foes_left: f64,
}

fn foes_left(foes: &[Live]) -> f64 {
    let max: i64 = foes.iter().map(|f| f.f.max_hp.max(1)).sum();
    let left: i64 = foes.iter().map(|f| f.f.hp.max(0)).sum();
    left as f64 / max.max(1) as f64
}

/// The game's soft cap (`soft_cap`): straight up to the knee, then
/// bending toward the limit.
pub fn soft_cap(raw: f64, knee: f64, limit: f64) -> f64 {
    if raw <= knee {
        return raw;
    }
    let room = limit - knee;
    knee + room * (1.0 - (-(raw - knee) / room).exp())
}

/// Speed past which only the log gain is left (`speed_cap`).
fn speed_cap() -> f64 {
    let over_soft = (BASE_ATTACK_INTERVAL * BASE_SPEED / FASTEST_ATTACK
        - BASE_SPEED
        - (SPEED_SOFT_CAP - BASE_SPEED) * SPEED_SOFTNESS)
        / SPEED_OVERCAP_SOFTNESS;
    (SPEED_SOFT_CAP + over_soft).round()
}

/// Game seconds between swings at a speed (`interval_at`).
pub fn interval_at(speed: f64) -> f64 {
    let knee = speed_cap();
    let under = speed.min(SPEED_SOFT_CAP);
    let mut effective = BASE_SPEED + (under - BASE_SPEED) * SPEED_SOFTNESS;
    if speed > SPEED_SOFT_CAP {
        effective += (speed.min(knee) - SPEED_SOFT_CAP) * SPEED_OVERCAP_SOFTNESS;
    }
    if speed > knee {
        effective *= 1.0 + SPEED_LOG_GAIN * (speed / knee).ln();
    }
    BASE_ATTACK_INTERVAL * BASE_SPEED / effective.max(1.0)
}

impl Fighter {
    /// `attack_speed`, without curses.
    pub fn attack_speed(&self) -> f64 {
        (self.speed.max(1.0) * (1.0 - self.speed_cut)).max(1.0)
    }

    pub fn attack_interval(&self) -> f64 {
        interval_at(self.attack_speed())
    }

    fn magic_resist_now(&self) -> f64 {
        let limit = if self.campaign_caps {
            CAMPAIGN_MAGIC_RESIST_LIMIT
        } else {
            MAGIC_RESIST_LIMIT
        };
        soft_cap(self.magic_resist.max(0.0), MAGIC_RESIST_KNEE, limit)
    }
}

/// A fighter during one fight.
struct Live {
    f: Fighter,
    /// `AbilityTimer.time_remaining`; None until it steps in.
    timer: Option<f64>,
    dodge: Gate,
    crit: Gate,
    multi: Gate,
}

impl Live {
    fn new(f: &Fighter) -> Self {
        Self {
            dodge: Gate::new(soft_cap(f.dodge.max(0.0), DODGE_KNEE, DODGE_LIMIT)),
            crit: Gate::new(soft_cap(f.crit.max(0.0), CRIT_KNEE, CRIT_LIMIT)),
            multi: Gate::new(soft_cap(
                f.multistrike.max(0.0),
                MULTISTRIKE_KNEE,
                MULTISTRIKE_LIMIT,
            )),
            timer: None,
            f: f.clone(),
        }
    }

    fn dead(&self) -> bool {
        self.f.hp <= 0
    }

    /// `AbilityTimer.tick` at rate 1: true when the swing comes.
    fn tick(&mut self) -> bool {
        let duration = self.f.attack_interval();
        let left = self.timer.get_or_insert(duration);
        *left -= STEP;
        if *left <= 0.0 {
            *left += duration;
            true
        } else {
            false
        }
    }
}

/// Damage after statuses-free mitigation (`_mitigated_damage`).
fn mitigate(
    attacker: &Fighter,
    defender: &mut Fighter,
    dmg: i64,
    run: Run,
    rng: &mut fastrand::Rng,
) -> i64 {
    let rolls = run == Run::Campaign;
    if attacker.magic && rolls {
        let resist = defender.magic_resist_now();
        return ((dmg as f64 * (1.0 - resist)).round() as i64).max(1);
    }
    let pool = defender.block.max(0);
    if pool <= 0 {
        return dmg;
    }
    let blocked = !rolls || rng.f64() < defender.block_chance;
    let soak = if blocked {
        pool
    } else {
        (pool as f64 * BLOCK_RESIDUAL) as i64
    };
    let soakable = (dmg as f64 * (1.0 - attacker.block_pierce)).round() as i64;
    let absorbed = soak.min(soakable);
    defender.block -= absorbed;
    dmg - absorbed
}

/// Raw damage of one strike: crit, then double (`hit_damage`).
fn strike_damage(attacker: &mut Live, rng: &mut fastrand::Rng) -> i64 {
    let mut dmg = attacker.f.atk.max(1);
    if attacker.crit.roll(rng) {
        dmg = (dmg as f64 * attacker.f.crit_mult) as i64;
    }
    if rng.f64() < attacker.f.double_dmg {
        dmg *= 2;
    }
    dmg
}

fn fatigue_at(seconds: f64) -> i64 {
    if seconds < FATIGUE_START {
        return 0;
    }
    let steps = ((seconds - FATIGUE_START) / FATIGUE_STEP) as i32;
    1i64 << steps.min(FATIGUE_MAX_DOUBLINGS)
}

fn fatigue_share_at(seconds: f64) -> f64 {
    if seconds < FATIGUE_START {
        return 0.0;
    }
    let steps = ((seconds - FATIGUE_START) / FATIGUE_STEP) as i32;
    (FATIGUE_SHARE_START * 2f64.powi(steps - FATIGUE_SHARE_FROM)).min(1.0)
}

/// One fatigue tick on a fighter (`_tick_fatigue`).
fn fatigue(c: &mut Fighter, seconds: f64) {
    if c.hp <= 0 {
        return;
    }
    let share = fatigue_share_at(seconds);
    let dose = fatigue_at(seconds).max((c.max_hp as f64 * share).round() as i64);
    let held = c.block.max(0).min(dose);
    c.block -= held;
    let hurt = if share >= 1.0 {
        c.block = 0;
        c.hp
    } else {
        dose - held
    };
    c.hp = (c.hp - hurt).max(0);
}

/// Foes fighting now: the first three standing, in squad order
/// (`_front_window`). A foe stepping in fills its block.
fn engaged(foes: &mut [Live]) -> Vec<usize> {
    let mut out = Vec::new();
    for (i, f) in foes.iter_mut().enumerate() {
        if out.len() >= MAX_ENGAGED {
            break;
        }
        if f.dead() {
            continue;
        }
        if f.timer.is_none() {
            f.f.block = f.f.block_max;
            f.timer = Some(f.f.attack_interval());
        }
        out.push(i);
    }
    out
}

/// Play one fight to its end.
pub fn fight(player: &Fighter, squad: &[Fighter], run: Run, rng: &mut fastrand::Rng) -> Result {
    let mut me = Live::new(player);
    me.timer = Some(player.attack_interval());
    let mut foes: Vec<Live> = squad.iter().map(Live::new).collect();
    // Second strikes waiting: (foe, seconds left).
    let mut pending: Vec<(usize, f64)> = Vec::new();
    let mut clock = 0.0;
    let mut fatigue_tick = 0.0;
    let end = |me: &Live, foes: &[Live], clock: f64| -> Option<Result> {
        let standing = foes.iter().any(|f| !f.dead());
        let outcome = match (me.dead(), standing) {
            (true, true) => Outcome::Lost,
            (true, false) => Outcome::Draw,
            (false, false) => Outcome::Won,
            (false, true) => return None,
        };
        Some(Result {
            outcome,
            seconds: clock,
            hp_left: me.f.hp,
            foes_left: foes_left(foes),
        })
    };
    loop {
        clock += STEP;
        if clock > TIME_LIMIT {
            return Result {
                outcome: Outcome::TimedOut,
                seconds: clock,
                hp_left: me.f.hp,
                foes_left: foes_left(&foes),
            };
        }
        if run == Run::Roguelite {
            if clock >= FATIGUE_START {
                fatigue_tick += STEP;
                if fatigue_tick >= 1.0 {
                    fatigue_tick -= 1.0;
                    fatigue(&mut me.f, clock);
                    for i in engaged(&mut foes) {
                        fatigue(&mut foes[i].f, clock);
                    }
                }
            }
            if let Some(r) = end(&me, &foes, clock) {
                return r;
            }
        }

        // The player.
        if me.tick()
            && let Some(&t) = engaged(&mut foes).first()
        {
            let target = &mut foes[t];
            if !target.dodge.roll(rng) {
                let dmg = strike_damage(&mut me, rng);
                let dmg = mitigate(&me.f, &mut target.f, dmg, run, rng);
                target.f.hp = (target.f.hp - dmg.max(0)).max(0);
            }
            if let Some(r) = end(&me, &foes, clock) {
                return r;
            }
        }

        // Each foe fighting.
        for i in engaged(&mut foes) {
            if !foes[i].tick() {
                continue;
            }
            let foe = &mut foes[i];
            if !me.dodge.roll(rng) {
                let dmg = strike_damage(foe, rng);
                let dmg = mitigate(&foe.f, &mut me.f, dmg, run, rng);
                me.f.hp = (me.f.hp - dmg.max(0)).max(0);
                if foe.multi.roll(rng) {
                    pending.push((i, MULTISTRIKE_GAP));
                }
            }
            if let Some(r) = end(&me, &foes, clock) {
                return r;
            }
        }

        // Second strikes landing: no dodge roll (`_advance_pending_strikes`).
        let mut waiting = Vec::new();
        for (i, left) in std::mem::take(&mut pending) {
            let left = left - STEP;
            if left > 0.0 {
                waiting.push((i, left));
                continue;
            }
            if foes[i].dead() || me.dead() {
                continue;
            }
            let dmg = strike_damage(&mut foes[i], rng);
            let dmg = mitigate(&foes[i].f, &mut me.f, dmg, run, rng);
            me.f.hp = (me.f.hp - dmg.max(0)).max(0);
        }
        pending = waiting;
        if let Some(r) = end(&me, &foes, clock) {
            return r;
        }
    }
}

/// Share of `trials` fights won.
pub fn success_rate(player: &Fighter, squad: &[Fighter], run: Run, trials: u32, seed: u64) -> f64 {
    modforge::chance::win_rate(trials, seed, |rng| {
        fight(player, squad, run, rng).outcome == Outcome::Won
    })
}

/// The fighter as the game holds it: a fighter's script variables
/// (`inspect` rows, combatant_runtime.gd names) by name.
pub fn from_vars(name: &str, vars: &serde_json::Map<String, serde_json::Value>) -> Fighter {
    let f = |k: &str| {
        vars.get(k)
            .and_then(serde_json::Value::as_f64)
            .unwrap_or(0.0)
    };
    let i = |k: &str| f(k) as i64;
    let armor = f("armor");
    Fighter {
        name: name.to_string(),
        hp: i("current_hp"),
        max_hp: i("max_hp"),
        atk: i("atk"),
        block: i("block_pool"),
        block_max: (armor * (1.0 + f("armor_pool_mult"))).round() as i64,
        block_chance: f("block_chance"),
        speed: f("speed"),
        speed_cut: f("speed_cut"),
        dodge: f("dodge_chance"),
        crit: f("crit_chance"),
        crit_mult: f("crit_multiplier"),
        multistrike: f("multistrike_chance"),
        double_dmg: f("double_dmg_chance"),
        block_pierce: f("block_pierce"),
        magic: vars.get("dmg_type").and_then(serde_json::Value::as_str) == Some("magic"),
        magic_resist: f("magic_resist"),
        campaign_caps: vars.get("campaign_caps") == Some(&serde_json::Value::Bool(true)),
    }
}

/// Which choice leaves the player most likely to win: each choice
/// changes a copy of the player, and every copy fights the same
/// squad with the same random rolls. Returns (best index, each
/// choice's success rate).
pub fn best_choice<T>(
    player: &Fighter,
    squad: &[Fighter],
    run: Run,
    choices: &[T],
    apply: impl Fn(&mut Fighter, &T),
) -> (Option<usize>, Vec<f64>) {
    let ranked = rank(player, squad, run, choices, apply);
    let mut rates = vec![0.0; choices.len()];
    for (i, s) in &ranked {
        rates[*i] = s.win;
    }
    (ranked.first().map(|r| r.0), rates)
}

/// Every choice scored, best first. The one judge for every choice
/// a stop offers (genie wish, dismantle, and the rest): each stop
/// only says what its choices do to the player.
pub fn rank<T>(
    player: &Fighter,
    squad: &[Fighter],
    run: Run,
    choices: &[T],
    apply: impl Fn(&mut Fighter, &T),
) -> Vec<(usize, Score)> {
    let mut scores: Vec<(usize, Score)> = choices
        .iter()
        .enumerate()
        .map(|(i, c)| {
            let mut p = player.clone();
            apply(&mut p, c);
            (i, score(&p, squad, run))
        })
        .collect();
    scores.sort_by(|a, b| b.1.cmp(&a.1));
    scores
}

/// How well a player does against a squad: win rate, then the mean
/// share of max hp left, so of two loadouts that both always win the
/// one that wins with more hp left is better; then the mean share of
/// the squad's hp left, so of two that both always lose the one that
/// gets closer is better. Same seed every time, so two loadouts meet
/// the same rolls.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Score {
    pub win: f64,
    pub hp_left: f64,
    pub foes_left: f64,
    /// One number for the fight, -1 to 1: a won fight counts its
    /// share of hp left, a lost one minus the squad's share left.
    pub margin: f64,
}

impl Score {
    pub fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.win
            .total_cmp(&other.win)
            .then(self.hp_left.total_cmp(&other.hp_left))
            .then(other.foes_left.total_cmp(&self.foes_left))
    }
}

pub fn score(player: &Fighter, squad: &[Fighter], run: Run) -> Score {
    const TRIALS: u32 = 1000;
    const SEED: u64 = 0x5eed;
    let mut rng = fastrand::Rng::with_seed(SEED);
    let (mut wins, mut left, mut foes, mut margin) = (0u32, 0.0, 0.0, 0.0);
    for _ in 0..TRIALS {
        let r = fight(player, squad, run, &mut rng);
        foes += r.foes_left;
        if r.outcome == Outcome::Won {
            wins += 1;
            let share = r.hp_left as f64 / player.max_hp.max(1) as f64;
            left += share;
            margin += share;
        } else {
            margin -= r.foes_left;
        }
    }
    let n = f64::from(TRIALS);
    Score {
        win: f64::from(wins) / n,
        hp_left: left / n,
        foes_left: foes / n,
        margin: margin / n,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    /// The player and Kaizoku as read live on 2026-11-16
    /// (research_character, research_enemy).
    fn player() -> Fighter {
        Fighter {
            name: "Player".into(),
            hp: 60,
            max_hp: 60,
            atk: 14,
            block: 15,
            block_max: 15,
            block_chance: 0.35,
            speed: 8.0,
            crit_mult: 1.1,
            ..Default::default()
        }
    }

    fn kaizoku(speed: f64) -> Fighter {
        Fighter {
            name: "Kaizoku".into(),
            hp: 58,
            max_hp: 58,
            atk: 8,
            speed,
            dodge: 0.1,
            crit: 0.08,
            crit_mult: 1.5,
            ..Default::default()
        }
    }

    #[test]
    fn swing_time_matches_the_watched_fight() {
        // Watched 2026-11-16 at the game's 2x fight speed: the
        // player swung every 2.83 to 2.85 s real.
        let real = interval_at(8.0) / 2.0;
        assert!((real - 2.84).abs() < 0.01, "{real}");
    }

    #[test]
    fn soft_caps() {
        assert_eq!(soft_cap(0.2, DODGE_KNEE, DODGE_LIMIT), 0.2);
        assert!(soft_cap(5.0, DODGE_KNEE, DODGE_LIMIT) < DODGE_LIMIT);
        assert_eq!(interval_at(10.0), 5.0);
    }

    #[test]
    fn block_matches_the_watched_fight() {
        // Watched: pool 15. Hits of 8: full block (pool 7), then
        // 7 through (a failed block soaks int(7 * 0.15) = 1, pool 6),
        // then 8 through (int(6 * 0.15) = 0), then "2 (blocked 6)".
        let foe = kaizoku(16.0);
        let mut me = player();
        let mut rng = fastrand::Rng::with_seed(0);
        me.block_chance = 1.0;
        assert_eq!(mitigate(&foe, &mut me, 8, Run::Campaign, &mut rng), 0);
        assert_eq!(me.block, 7);
        me.block_chance = 0.0;
        assert_eq!(mitigate(&foe, &mut me, 8, Run::Campaign, &mut rng), 7);
        assert_eq!(mitigate(&foe, &mut me, 8, Run::Campaign, &mut rng), 8);
        me.block = 6;
        me.block_chance = 1.0;
        assert_eq!(mitigate(&foe, &mut me, 8, Run::Campaign, &mut rng), 2);
        assert_eq!(me.block, 0);
    }

    #[test]
    fn kaizoku_fight() {
        // The player won this one with 19 hp left in 17 s real.
        let rate = success_rate(&player(), &[kaizoku(16.0)], Run::Campaign, 5000, 1);
        let mut rng = fastrand::Rng::with_seed(2);
        let one = fight(&player(), &[kaizoku(16.0)], Run::Campaign, &mut rng);
        println!("success {rate:.3}; one fight {one:?}");
        // Watched, Kaizoku swung every 2.25 s real (4.5 game s), not
        // the 1.84 s speed 16 gives: speed 11.85 gives 4.5. Which
        // number the game really uses is not yet known.
        let watched = success_rate(&player(), &[kaizoku(11.85)], Run::Campaign, 5000, 1);
        println!("at the watched swing time: {watched:.3}");
        assert!(rate > 0.5, "{rate}");
    }
}
