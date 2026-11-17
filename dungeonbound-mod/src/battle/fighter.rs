//! One fighter as the game holds it in a fight: combatant_runtime.gd
//! (fields, statuses, heal, attack rate, soft caps, gated rolls) and
//! ability_timer.gd (the swing clock). Combat log lines are left out.

use std::collections::HashMap;

use serde_json::{Map, Value};

use super::status::{Active, Db, Kind, Status};

const BUFF_STACK_CAP: i64 = 99;
const STATUS_STACK_CAP: i64 = 9999;
const STAGGER_THRESHOLD: i64 = 3;
const STUN_IMMUNITY: f64 = 2.0;
const POISON_WARD: f64 = 0.5;
const BURN_WARD: f64 = 0.5;
const POISON_CUT_CAP: f64 = 0.75;
const POISON_HP_TICK_CAP: f64 = 0.05;
const BURN_TICK_INTERVAL: f64 = 1.5;
const BURN_FIRST_DECAY: f64 = 2.0 * BURN_TICK_INTERVAL;
const MAX_TICKS_PER_CALL: i64 = 8;
const LOW_HP_RESIST_BELOW: f64 = 0.3;
pub const BLOCK_RESIDUAL: f64 = 0.15;
const AMOUNT_CAP: f64 = 1e15;
const MIN_ATTACK_RATE: f64 = 0.1;
const CHARGE_RATE: f64 = 0.3;
const CHARGE_STEP: i64 = 10;
const CHARGE_STEP_RATE: f64 = 0.05;
const CHARGE_MAX_STEPS: i64 = 6;
const ROOT_RATE: f64 = 0.4;
const DODGE_KNEE: f64 = 0.35;
const DODGE_LIMIT: f64 = 0.6;
const CRIT_KNEE: f64 = 0.5;
const CRIT_LIMIT: f64 = 0.85;
const MULTISTRIKE_KNEE: f64 = 0.35;
const MULTISTRIKE_LIMIT: f64 = 0.75;
const MAGIC_RESIST_KNEE: f64 = 0.5;
const MAGIC_RESIST_LIMIT: f64 = 0.75;
const CAMPAIGN_MAGIC_RESIST_LIMIT: f64 = 0.9;
const FREEZE_DODGE_PER_STACK: f64 = 0.05;

pub const GATE_DODGE: &str = "dodge";
pub const GATE_CRIT: &str = "crit";
pub const GATE_MULTI: &str = "multi";

/// ability_timer.gd.
#[derive(Clone, Debug)]
pub struct Timer {
    pub duration: f64,
    pub time_remaining: f64,
    pub is_paused: bool,
    pub is_frozen: bool,
}

impl Timer {
    pub fn new(duration: f64) -> Timer {
        Timer {
            duration,
            time_remaining: duration,
            is_paused: false,
            is_frozen: false,
        }
    }

    pub fn tick(&mut self, delta: f64, rate: f64) -> bool {
        if self.is_paused || self.is_frozen || rate <= 0.0 {
            return false;
        }
        self.time_remaining -= delta * rate;
        if self.time_remaining <= 0.0 {
            self.time_remaining += self.duration;
            return true;
        }
        false
    }

    pub fn progress(&self) -> f64 {
        if self.duration <= 0.0 {
            return 1.0;
        }
        (1.0 - self.time_remaining / self.duration).clamp(0.0, 1.0)
    }
}

/// combatant_runtime.gd soft_cap.
pub fn soft_cap(raw: f64, knee: f64, limit: f64) -> f64 {
    if raw <= knee {
        return raw;
    }
    let room = limit - knee;
    knee + room * (1.0 - (-(raw - knee) / room).exp())
}

pub fn capped_amount(value: f64) -> i64 {
    value.ceil().clamp(0.0, AMOUNT_CAP) as i64
}

pub fn charge_rate(stacks: i64) -> f64 {
    if stacks <= 0 {
        return 0.0;
    }
    CHARGE_RATE + CHARGE_STEP_RATE * (stacks / CHARGE_STEP).min(CHARGE_MAX_STEPS) as f64
}

pub fn root_rate(stacks: i64) -> f64 {
    if stacks <= 0 {
        return 0.0;
    }
    ROOT_RATE + CHARGE_STEP_RATE * (stacks / CHARGE_STEP).min(CHARGE_MAX_STEPS) as f64
}

/// Godot's round: half away from zero.
pub fn round(v: f64) -> i64 {
    v.round() as i64
}

/// What a status tick did (tick_statuses events).
#[derive(Clone, Debug)]
pub enum Tick {
    Heal(Status, i64),
    Hurt(Status, i64, i64),
    Expire(Status),
}

/// combatant_runtime.gd: the fields the fight math reads. Names are the
/// game's.
#[derive(Clone, Debug, Default)]
pub struct Fighter {
    pub display_name: String,
    pub is_player: bool,
    pub king: bool,
    pub current_hp: i64,
    pub max_hp: i64,
    pub atk: i64,
    pub armor: i64,
    pub armor_pool_mult: f64,
    pub campaign_caps: bool,
    pub block_chance: f64,
    pub block_pool: i64,
    pub block_pierce: f64,
    pub dmg_type: String,
    pub magic_resist: f64,
    pub speed: f64,
    pub speed_cut: f64,
    pub dodge_chance: f64,
    pub crit_chance: f64,
    pub crit_multiplier: f64,
    pub multistrike_chance: f64,
    pub double_dmg_chance: f64,
    pub damage_taken_mult: f64,
    pub damage_dealt_mult: f64,
    pub below_half_dr: i64,
    pub below_half_status_immune: bool,
    pub low_hp_status_resist: f64,
    pub stun_immune: bool,
    pub freeze_immune: bool,
    pub freeze_ward: f64,
    pub item_stun: bool,
    pub status_resistance: HashMap<String, f64>,
    pub cleanse_all_chance: f64,
    pub cleanse_poison_chance: f64,
    pub cleanse_burn_chance: f64,
    pub cleanse_bleed_chance: f64,
    pub debuff_wards: i64,
    pub nullify_buff_chance: f64,
    pub enrage_bonus_atk: i64,
    pub poison_tick_mult: f64,
    pub dot_tick_slow: f64,
    pub poison_damage_cut: f64,
    pub burn_damage_cut: f64,
    pub poison_warded: bool,
    pub burn_warded: bool,
    pub poison_resist: i64,
    pub poison_hp_share: f64,
    pub regen_hp_share: f64,
    pub dmg_per_self_burn: f64,
    pub dmg_per_self_poison: f64,
    pub crit_vs_status_types: Vec<Kind>,
    pub lifesteal: f64,
    pub lifesteal_flat: i64,
    pub enemy_lifesteal_cut: f64,
    pub berserker_atk_per_hit: i64,
    pub hits_taken: i64,
    pub thawing: bool,
    pub stun_immunity: f64,
    pub battle_opening: bool,
    pub last_hit: i64,
    pub attack_timer: Option<Timer>,
    pub active_statuses: Vec<Active>,
    pub gate_fails: HashMap<&'static str, Option<u32>>,
}

/// Reads a fighter's script variables.
struct Vars<'a>(&'a Map<String, Value>);

impl Vars<'_> {
    fn f(&self, k: &str) -> f64 {
        self.0.get(k).and_then(Value::as_f64).unwrap_or(0.0)
    }
    fn i(&self, k: &str) -> i64 {
        self.0
            .get(k)
            .and_then(|v| v.as_i64().or_else(|| v.as_f64().map(|f| f as i64)))
            .unwrap_or(0)
    }
    fn b(&self, k: &str) -> bool {
        self.0.get(k).and_then(Value::as_bool).unwrap_or(false)
    }
    fn s(&self, k: &str) -> String {
        self.0
            .get(k)
            .and_then(Value::as_str)
            .unwrap_or("")
            .to_string()
    }
}

impl Fighter {
    /// From a CombatantRuntime's script variables (a battle snapshot).
    pub fn from_vars(vars: &Map<String, Value>, is_player: bool) -> Fighter {
        let v = Vars(vars);
        let mut status_resistance = HashMap::new();
        if let Some(Value::Object(m)) = vars.get("status_resistance") {
            for (k, x) in m {
                status_resistance.insert(k.clone(), x.as_f64().unwrap_or(0.0));
            }
        }
        let crit_vs_status_types = vars
            .get("crit_vs_status_types")
            .and_then(Value::as_array)
            .map(|a| {
                a.iter()
                    .filter_map(|x| x.as_i64().and_then(Kind::from_index))
                    .collect()
            })
            .unwrap_or_default();
        let mut f = Fighter {
            display_name: v.s("display_name"),
            is_player,
            king: false,
            current_hp: v.i("current_hp"),
            max_hp: v.i("max_hp"),
            atk: v.i("atk"),
            armor: v.i("armor"),
            armor_pool_mult: v.f("armor_pool_mult"),
            campaign_caps: v.b("campaign_caps"),
            block_chance: v.f("block_chance"),
            block_pool: v.i("block_pool"),
            block_pierce: v.f("block_pierce"),
            dmg_type: v.s("dmg_type"),
            magic_resist: v.f("magic_resist"),
            speed: v.f("speed"),
            speed_cut: v.f("speed_cut"),
            dodge_chance: v.f("dodge_chance"),
            crit_chance: v.f("crit_chance"),
            crit_multiplier: v.f("crit_multiplier"),
            multistrike_chance: v.f("multistrike_chance"),
            double_dmg_chance: v.f("double_dmg_chance"),
            damage_taken_mult: v.f("damage_taken_mult"),
            damage_dealt_mult: v.f("damage_dealt_mult"),
            below_half_dr: v.i("below_half_dr"),
            below_half_status_immune: v.b("below_half_status_immune"),
            low_hp_status_resist: v.f("low_hp_status_resist"),
            stun_immune: v.b("stun_immune"),
            freeze_immune: v.b("freeze_immune"),
            freeze_ward: v.f("freeze_ward"),
            item_stun: v.b("item_stun"),
            status_resistance,
            cleanse_all_chance: v.f("cleanse_all_chance"),
            cleanse_poison_chance: v.f("cleanse_poison_chance"),
            cleanse_burn_chance: v.f("cleanse_burn_chance"),
            cleanse_bleed_chance: v.f("cleanse_bleed_chance"),
            debuff_wards: v.i("debuff_wards"),
            nullify_buff_chance: v.f("nullify_buff_chance"),
            enrage_bonus_atk: v.i("enrage_bonus_atk"),
            poison_tick_mult: v.f("poison_tick_mult"),
            dot_tick_slow: v.f("dot_tick_slow"),
            poison_damage_cut: v.f("poison_damage_cut"),
            burn_damage_cut: v.f("burn_damage_cut"),
            poison_warded: v.b("poison_warded"),
            burn_warded: v.b("burn_warded"),
            poison_resist: v.i("poison_resist"),
            poison_hp_share: v.f("poison_hp_share"),
            regen_hp_share: v.f("regen_hp_share"),
            dmg_per_self_burn: v.f("dmg_per_self_burn"),
            dmg_per_self_poison: v.f("dmg_per_self_poison"),
            crit_vs_status_types,
            lifesteal: v.f("lifesteal"),
            lifesteal_flat: v.i("lifesteal_flat"),
            enemy_lifesteal_cut: v.f("enemy_lifesteal_cut"),
            berserker_atk_per_hit: v.i("berserker_atk_per_hit"),
            hits_taken: v.i("hits_taken"),
            thawing: false,
            stun_immunity: 0.0,
            battle_opening: true,
            last_hit: 0,
            attack_timer: None,
            active_statuses: Vec::new(),
            gate_fails: HashMap::new(),
        };
        if f.damage_dealt_mult == 0.0 && !vars.contains_key("damage_dealt_mult") {
            f.damage_dealt_mult = 1.0;
        }
        if f.poison_tick_mult == 0.0 && !vars.contains_key("poison_tick_mult") {
            f.poison_tick_mult = 1.0;
        }
        f
    }

    pub fn is_dead(&self) -> bool {
        self.current_hp <= 0
    }

    pub fn is_below_half_hp(&self) -> bool {
        self.current_hp * 2 < self.max_hp
    }

    pub fn block_max(&self) -> i64 {
        (self.armor as f64 * (1.0 + self.armor_pool_mult)) as i64
    }

    pub fn has_status(&self, kind: Kind) -> bool {
        self.active_statuses.iter().any(|a| a.kind() == kind)
    }

    pub fn get_status_stacks(&self, kind: Kind) -> i64 {
        self.active_statuses
            .iter()
            .find(|a| a.kind() == kind)
            .map_or(0, |a| a.stacks)
    }

    pub fn hindered_miss_chance(&self) -> f64 {
        self.active_statuses
            .iter()
            .find(|a| a.kind() == Kind::Hindered)
            .map_or(0.0, |a| a.data.stacked_pct(a.stacks))
    }

    pub fn curse_penalty(&self, stat: &str) -> f64 {
        self.active_statuses
            .iter()
            .filter(|a| a.kind() == Kind::Curse && a.curse_stat == stat)
            .map(|a| a.curse_amount)
            .sum()
    }

    pub fn frailty_block_penalty(&self) -> i64 {
        self.curse_penalty("armor") as i64
    }

    pub fn heal(&mut self, mut amount: i64) -> i64 {
        if amount <= 0 || self.is_dead() {
            return 0;
        }
        for a in &self.active_statuses {
            if a.kind() == Kind::Unhealing {
                amount = round(amount as f64 * (1.0 - a.data.stacked_pct(a.stacks)));
            }
        }
        let restored = amount.clamp(0, (self.max_hp - self.current_hp).max(0));
        self.current_hp += restored;
        restored
    }

    pub fn dot_tick_rate(&self, kind: Kind) -> f64 {
        let rate = if kind == Kind::Poison {
            self.poison_tick_mult
        } else {
            1.0
        };
        rate / (1.0 + self.dot_tick_slow.max(0.0))
    }

    pub fn poison_cut(&self) -> f64 {
        (self.poison_damage_cut + if self.poison_warded { POISON_WARD } else { 0.0 })
            .clamp(0.0, POISON_CUT_CAP)
    }

    pub fn burn_cut(&self) -> f64 {
        (self.burn_damage_cut + if self.burn_warded { BURN_WARD } else { 0.0 })
            .clamp(0.0, POISON_CUT_CAP)
    }

    pub fn status_resist_chance(&self, status: &Status) -> f64 {
        let mut chance = self
            .status_resistance
            .get(&status.id)
            .copied()
            .unwrap_or(0.0);
        if status.kind.is_buff() || status.kind == Kind::Stagger {
            return chance;
        }
        chance += self.cleanse_all_chance;
        chance += match status.kind {
            Kind::Poison => self.cleanse_poison_chance,
            Kind::Burn => self.cleanse_burn_chance,
            Kind::Bleed => self.cleanse_bleed_chance,
            _ => 0.0,
        };
        chance
    }

    /// apply_status / _land_status. `foe` is the other side's fighter
    /// (nullify and reflect); `db` finds stagger.
    pub fn apply_status(
        &mut self,
        status: &Status,
        stack_amount: i64,
        dmg_per_stack: f64,
        freeze_bonus_turns: i64,
        reflected: bool,
        foe: Option<&mut Fighter>,
        db: &Db,
        rng: &mut fastrand::Rng,
    ) -> bool {
        let mut stack_amount = stack_amount;
        if self.below_half_status_immune && self.is_below_half_hp() {
            return false;
        }
        if self.low_hp_status_resist > 0.0
            && (self.current_hp as f64) < self.max_hp as f64 * LOW_HP_RESIST_BELOW
            && rng.f64() < self.low_hp_status_resist
        {
            return false;
        }
        if (status.kind == Kind::Stun && self.stun_immune)
            || (status.kind == Kind::Freeze && self.freeze_immune)
        {
            return false;
        }
        if status.kind == Kind::Freeze && self.freeze_ward > 0.0 && !reflected {
            let kept = (0..stack_amount.max(0))
                .filter(|_| rng.f64() >= self.freeze_ward)
                .count() as i64;
            if kept <= 0 {
                return false;
            }
            stack_amount = kept;
        }
        if rng.f64() < self.status_resist_chance(status) {
            return false;
        }
        if !status.kind.is_buff() && status.kind != Kind::Stagger && self.debuff_wards > 0 {
            self.debuff_wards -= 1;
            return false;
        }
        if let Some(foe) = foe {
            if status.kind.is_buff()
                && foe.nullify_buff_chance > 0.0
                && rng.f64() < foe.nullify_buff_chance
            {
                return false;
            }
            if !reflected
                && !status.kind.is_buff()
                && status.kind != Kind::Stagger
                && self.has_status(Kind::Reflect)
            {
                self.spend_status_stack(Kind::Reflect);
                foe.apply_status(status, stack_amount, dmg_per_stack, 0, true, None, db, rng);
                return false;
            }
        }
        if status.kind == Kind::Stun {
            if self.item_stun {
                return self.add_item_stun(status, stack_amount, dmg_per_stack);
            }
            return self.add_stagger(status, db);
        }
        if status.kind == Kind::Curse {
            for _ in 0..stack_amount.clamp(1, BUFF_STACK_CAP) {
                let c = self.roll_curse(status, rng);
                self.active_statuses.push(c);
            }
            return true;
        }
        if status.kind == Kind::Freeze {
            stack_amount = stack_amount.max(1) + freeze_bonus_turns;
        }
        if status.kind.is_stacking() {
            let cap = if status.kind.is_buff() {
                BUFF_STACK_CAP
            } else {
                STATUS_STACK_CAP
            };
            stack_amount = stack_amount.min(cap - self.get_status_stacks(status.kind));
            if stack_amount <= 0 {
                return false;
            }
        }
        if status.kind == Kind::Enrage {
            self.atk += stack_amount.max(1) * (1 + self.enrage_bonus_atk);
        }
        let applications = 1;
        let opening = self.battle_opening;
        for existing in self.active_statuses.iter_mut() {
            if std::sync::Arc::ptr_eq(&existing.data, status) || existing.data.id == status.id {
                if !opening {
                    existing.dormant = false;
                }
                if status.kind.is_stacking() {
                    existing.stacks += stack_amount;
                    existing.dmg_per_stack = dmg_per_stack;
                } else {
                    existing.stacks += applications;
                    existing.remaining_duration += status.duration * applications as f64;
                }
                return true;
            }
        }
        let mut fresh = Active::new(status.clone(), stack_amount, dmg_per_stack);
        fresh.dormant = opening && status.kind == Kind::Regen;
        if status.kind.decays_by_stack() {
            fresh.remaining_duration = status.duration;
        }
        if !status.kind.is_stacking() {
            fresh.stacks = applications;
            fresh.remaining_duration = status.duration * applications as f64;
        }
        self.active_statuses.push(fresh);
        true
    }

    fn add_item_stun(&mut self, stun: &Status, stacks: i64, dmg_per_stack: f64) -> bool {
        let stacks = stacks
            .max(1)
            .min(STATUS_STACK_CAP - self.get_status_stacks(Kind::Stun));
        if stacks <= 0 {
            return false;
        }
        let per = if dmg_per_stack > 0.0 {
            dmg_per_stack
        } else {
            stun.base_dmg_per_stack
        };
        if let Some(a) = self
            .active_statuses
            .iter_mut()
            .find(|a| a.kind() == Kind::Stun)
        {
            a.stacks += stacks;
            a.dmg_per_stack = per;
        } else {
            self.active_statuses
                .push(Active::new(stun.clone(), stacks, per));
        }
        true
    }

    fn add_stagger(&mut self, stun: &Status, db: &Db) -> bool {
        if self.stun_immunity > 0.0 || self.has_status(Kind::Stun) {
            return false;
        }
        let stacks = self.get_status_stacks(Kind::Stagger) + 1;
        if stacks < STAGGER_THRESHOLD {
            if let Some(a) = self
                .active_statuses
                .iter_mut()
                .find(|a| a.kind() == Kind::Stagger)
            {
                a.stacks = stacks;
                return true;
            }
            if let Some(stagger) = db.get("stagger") {
                self.active_statuses.push(Active::new(stagger, 1, 0.0));
            }
            return true;
        }
        self.take_status_stacks(Kind::Stagger);
        let mut stunned = Active::new(stun.clone(), 1, 0.0);
        stunned.remaining_duration = stun.duration;
        self.active_statuses.push(stunned);
        self.stun_immunity = stun.duration + STUN_IMMUNITY;
        true
    }

    fn roll_curse(&self, status: &Status, rng: &mut fastrand::Rng) -> Active {
        let mut a = Active::new(status.clone(), 1, 0.0);
        let range = |rng: &mut fastrand::Rng, lo: f64, hi: f64| lo + (hi - lo) * rng.f64();
        match rng.u32(..) % 5 {
            0 => {
                a.curse_stat = "atk";
                a.curse_amount =
                    ((self.atk as f64 * range(rng, 0.1, 0.25)).ceil() as i64).max(1) as f64;
            }
            1 => {
                a.curse_stat = "armor";
                a.curse_amount =
                    ((self.armor as f64 * range(rng, 0.1, 0.25)).ceil() as i64).max(1) as f64;
            }
            2 => {
                a.curse_stat = "speed";
                a.curse_amount = f64::from(rng.u32(1..=3));
            }
            3 => {
                a.curse_stat = "dodge";
                a.curse_amount = (range(rng, 0.05, 0.15) * 100.0).round() / 100.0;
            }
            _ => {
                a.curse_stat = "crit";
                a.curse_amount = (range(rng, 0.05, 0.15) * 100.0).round() / 100.0;
            }
        }
        a
    }

    pub fn end_battle_statuses(&mut self) {
        let gone: i64 = self
            .active_statuses
            .iter()
            .filter(|a| a.kind() == Kind::Enrage)
            .map(|a| a.stacks * (1 + self.enrage_bonus_atk))
            .sum();
        self.atk = (self.atk - gone).max(0);
        self.active_statuses.clear();
        self.stun_immunity = 0.0;
        self.thawing = false;
    }

    /// Removes the status and returns its stacks times damage per stack.
    pub fn consume_status_stacks(&mut self, kind: Kind) -> i64 {
        match self.active_statuses.iter().position(|a| a.kind() == kind) {
            Some(i) => {
                let a = self.active_statuses.remove(i);
                capped_amount(a.stacks as f64 * a.dmg_per_stack)
            }
            None => 0,
        }
    }

    pub fn take_status_stacks(&mut self, kind: Kind) -> i64 {
        match self.active_statuses.iter().position(|a| a.kind() == kind) {
            Some(i) => self.active_statuses.remove(i).stacks.max(1),
            None => 0,
        }
    }

    pub fn spend_status_stack(&mut self, kind: Kind) -> Option<Status> {
        let i = self.active_statuses.iter().position(|a| a.kind() == kind)?;
        let data = self.active_statuses[i].data.clone();
        self.active_statuses[i].stacks -= 1;
        if self.active_statuses[i].stacks <= 0 {
            self.active_statuses.remove(i);
        }
        Some(data)
    }

    pub fn shed_status_stacks(&mut self, kind: Kind, count: i64) -> i64 {
        let Some(i) = self.active_statuses.iter().position(|a| a.kind() == kind) else {
            return 0;
        };
        let taken = count.max(0).min(self.active_statuses[i].stacks);
        self.active_statuses[i].stacks -= taken;
        if self.active_statuses[i].stacks <= 0 {
            self.active_statuses.remove(i);
        }
        taken
    }

    pub fn attack_speed(&self) -> f64 {
        ((self.speed - self.curse_penalty("speed")).max(1.0) * (1.0 - self.speed_cut)).max(1.0)
    }

    pub fn attack_interval(&self) -> f64 {
        crate::fight::interval_at(self.attack_speed())
    }

    pub fn attack_rate(&self) -> f64 {
        let mut rate = 1.0;
        let rooted = self.get_status_stacks(Kind::Root);
        for a in &self.active_statuses {
            match a.kind() {
                Kind::Stun => {
                    if !self.item_stun {
                        return 0.0;
                    }
                }
                Kind::Charge => {
                    if rooted <= 0 {
                        rate += charge_rate(a.stacks);
                    }
                }
                Kind::Slow => rate -= charge_rate(a.stacks),
                _ => {}
            }
        }
        rate -= root_rate(rooted);
        rate.max(MIN_ATTACK_RATE)
    }

    /// tick_statuses: one step of every status on this fighter.
    pub fn tick_statuses(&mut self, delta: f64) -> Vec<Tick> {
        let mut events = Vec::new();
        let mut still = Vec::with_capacity(self.active_statuses.len());
        self.stun_immunity = (self.stun_immunity - delta).max(0.0);
        self.battle_opening = false;
        // The game walks its list and puts the kept ones back at the
        // end, so a heal mid-walk still sees every status.
        let statuses = self.active_statuses.clone();
        for mut a in statuses {
            let status = a.data.clone();
            let kind = status.kind;
            if matches!(
                kind,
                Kind::Bleed
                    | Kind::Terror
                    | Kind::Freeze
                    | Kind::Stagger
                    | Kind::Reflect
                    | Kind::Haste
            ) {
                still.push(a);
                continue;
            }
            if kind == Kind::Regen {
                if a.dormant && self.current_hp >= self.max_hp {
                    still.push(a);
                    continue;
                }
                a.dormant = false;
                a.tick_timer += delta;
                if a.tick_timer >= status.tick_interval {
                    a.tick_timer -= status.tick_interval;
                    let amount = a.stacks as f64 * a.dmg_per_stack
                        + a.stacks as f64 * self.regen_hp_share * self.max_hp as f64;
                    let restored = self.heal(capped_amount(amount));
                    events.push(Tick::Heal(status.clone(), restored));
                    a.stacks -= 1;
                }
                if a.stacks > 0 {
                    still.push(a);
                } else {
                    events.push(Tick::Expire(status));
                }
                continue;
            }
            if kind == Kind::Poison || kind == Kind::Burn {
                a.tick_timer += delta * self.dot_tick_rate(kind);
                let mut due = i64::from(a.tick_timer >= status.tick_interval);
                if kind == Kind::Poison {
                    due = ((a.tick_timer / status.tick_interval) as i64).min(MAX_TICKS_PER_CALL);
                }
                for _ in 0..due {
                    if a.stacks <= 0 {
                        break;
                    }
                    a.tick_timer -= status.tick_interval;
                    let mut amount = capped_amount(a.stacks as f64 * a.dmg_per_stack);
                    if kind == Kind::Poison && self.poison_hp_share > 0.0 {
                        amount = capped_amount(
                            amount as f64
                                + ((a.stacks as f64 * self.poison_hp_share)
                                    .min(POISON_HP_TICK_CAP)
                                    * self.max_hp as f64)
                                    .trunc(),
                        );
                    }
                    let mut blocked = 0;
                    if kind == Kind::Burn && self.burn_cut() > 0.0 {
                        amount = round(amount as f64 * (1.0 - self.burn_cut()));
                    }
                    if kind == Kind::Burn {
                        blocked = self.block_split(amount);
                        amount -= blocked;
                    } else {
                        amount = (round(amount as f64 * (1.0 - self.poison_cut()))
                            - self.poison_resist)
                            .max(0);
                    }
                    self.current_hp = (self.current_hp - amount).max(0);
                    events.push(Tick::Hurt(status.clone(), amount, blocked));
                    if kind == Kind::Burn {
                        a.ticks_since_decay += 1;
                        if a.ticks_since_decay as f64 * status.tick_interval
                            >= BURN_FIRST_DECAY - 0.0001
                        {
                            a.stacks -= 1;
                        }
                    } else {
                        if a.ticks_since_decay > 0 {
                            a.stacks -= 1;
                        }
                        a.ticks_since_decay += 1;
                    }
                }
                if a.stacks > 0 {
                    still.push(a);
                } else {
                    events.push(Tick::Expire(status));
                }
                continue;
            }
            a.remaining_duration -= delta;
            let sheds = kind.decays_by_stack() || (kind == Kind::Stun && self.item_stun);
            if sheds && a.remaining_duration <= 0.0 && a.stacks > 1 {
                a.stacks -= 1;
                a.remaining_duration += status.duration;
                self.enrage_lost(kind, 1);
            }
            if a.remaining_duration <= 0.0 {
                self.enrage_lost(kind, a.stacks);
                events.push(Tick::Expire(status));
            } else {
                still.push(a);
            }
        }
        self.active_statuses = still;
        events
    }

    fn enrage_lost(&mut self, kind: Kind, stacks: i64) {
        if kind == Kind::Enrage && stacks > 0 {
            self.atk = (self.atk - stacks * (1 + self.enrage_bonus_atk)).max(0);
        }
    }

    pub fn block_split(&mut self, amount: i64) -> i64 {
        let blocked = self.block_pool.min(amount - amount / 2);
        self.block_pool -= blocked;
        blocked
    }

    pub fn effective_dodge(&self) -> f64 {
        if self.king {
            return 0.0;
        }
        let capped = soft_cap(
            (self.dodge_chance - self.curse_penalty("dodge")).max(0.0),
            DODGE_KNEE,
            DODGE_LIMIT,
        );
        (capped
            - FREEZE_DODGE_PER_STACK * self.get_status_stacks(Kind::Freeze) as f64
            - self.blind_penalty())
        .max(0.0)
    }

    pub fn blind_penalty(&self) -> f64 {
        self.active_statuses
            .iter()
            .find(|a| a.kind() == Kind::Blind)
            .map_or(0.0, |a| {
                a.data.pct_cap.min(a.data.pct_per_stack * a.stacks as f64)
            })
    }

    pub fn effective_crit(&self) -> f64 {
        soft_cap(
            (self.crit_chance - self.curse_penalty("crit")).max(0.0),
            CRIT_KNEE,
            CRIT_LIMIT,
        )
    }

    pub fn effective_multistrike(&self) -> f64 {
        soft_cap(
            self.multistrike_chance.max(0.0),
            MULTISTRIKE_KNEE,
            MULTISTRIKE_LIMIT,
        )
    }

    pub fn magic_resist_limit(&self) -> f64 {
        if self.campaign_caps {
            CAMPAIGN_MAGIC_RESIST_LIMIT
        } else {
            MAGIC_RESIST_LIMIT
        }
    }

    pub fn effective_magic_resist(&self) -> f64 {
        soft_cap(
            self.magic_resist.max(0.0),
            MAGIC_RESIST_KNEE,
            self.magic_resist_limit(),
        )
    }

    /// gated_roll: the game's pseudo-random gate, one miss count per key.
    pub fn gated_roll(&mut self, key: &'static str, chance: f64, rng: &mut fastrand::Rng) -> bool {
        let fails = self.gate_fails.entry(key).or_insert(None);
        modforge::chance::gated_roll(fails, chance, rng)
    }
}
