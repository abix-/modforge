//! Statuses as the game holds them: status_effect_data.gd (the kind and
//! its numbers, read from the game's EquipmentDB) and
//! active_status_effect.gd (one status on a fighter).

use std::sync::Arc;

/// status_effect_data.gd `Type`, in the game's order.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub enum Kind {
    Poison,
    Burn,
    Bleed,
    Freeze,
    Stun,
    Vulnerable,
    Enrage,
    Curse,
    Terror,
    Slow,
    Charge,
    Regen,
    Stagger,
    Weak,
    Hindered,
    Unhealing,
    Reflect,
    Resilient,
    Haste,
    Blind,
    Silence,
    Root,
}

impl Kind {
    pub const ALL: [Kind; 22] = [
        Kind::Poison,
        Kind::Burn,
        Kind::Bleed,
        Kind::Freeze,
        Kind::Stun,
        Kind::Vulnerable,
        Kind::Enrage,
        Kind::Curse,
        Kind::Terror,
        Kind::Slow,
        Kind::Charge,
        Kind::Regen,
        Kind::Stagger,
        Kind::Weak,
        Kind::Hindered,
        Kind::Unhealing,
        Kind::Reflect,
        Kind::Resilient,
        Kind::Haste,
        Kind::Blind,
        Kind::Silence,
        Kind::Root,
    ];

    /// From the game's enum number.
    pub fn from_index(i: i64) -> Option<Kind> {
        usize::try_from(i)
            .ok()
            .and_then(|i| Kind::ALL.get(i).copied())
    }

    pub fn is_speed_shift(self) -> bool {
        matches!(self, Kind::Slow | Kind::Charge)
    }

    pub fn decays_by_stack(self) -> bool {
        self.is_speed_shift()
            || matches!(
                self,
                Kind::Enrage
                    | Kind::Weak
                    | Kind::Hindered
                    | Kind::Unhealing
                    | Kind::Resilient
                    | Kind::Blind
                    | Kind::Silence
                    | Kind::Root
            )
    }

    pub fn is_dot(self) -> bool {
        matches!(self, Kind::Poison | Kind::Burn | Kind::Bleed)
    }

    pub fn is_stacking(self) -> bool {
        self.is_dot()
            || matches!(
                self,
                Kind::Enrage
                    | Kind::Terror
                    | Kind::Freeze
                    | Kind::Regen
                    | Kind::Stagger
                    | Kind::Reflect
            )
            || self.decays_by_stack()
    }

    pub fn is_buff(self) -> bool {
        matches!(
            self,
            Kind::Enrage
                | Kind::Charge
                | Kind::Regen
                | Kind::Reflect
                | Kind::Resilient
                | Kind::Haste
        )
    }

    pub fn is_stealable(self) -> bool {
        matches!(
            self,
            Kind::Charge | Kind::Regen | Kind::Reflect | Kind::Resilient
        )
    }

    pub fn is_cc(self) -> bool {
        matches!(self, Kind::Freeze | Kind::Stun | Kind::Slow)
    }
}

/// status_effect_data.gd: one status's numbers.
#[derive(Clone, Debug)]
pub struct Data {
    pub id: String,
    pub name: String,
    pub kind: Kind,
    pub base_dmg_per_stack: f64,
    pub tick_interval: f64,
    pub duration: f64,
    pub freeze_skip_turns: i64,
    pub stun_skip_chance: f64,
    pub pct_per_stack: f64,
    pub pct_cap: f64,
}

pub type Status = Arc<Data>;

impl Data {
    pub fn stacked_pct(&self, stacks: i64) -> f64 {
        self.pct_cap.min(self.pct_per_stack * stacks as f64)
    }

    /// From a status resource's script variables.
    pub fn from_vars(vars: &serde_json::Map<String, serde_json::Value>) -> Option<Data> {
        let f = |k: &str, or: f64| {
            vars.get(k)
                .and_then(serde_json::Value::as_f64)
                .unwrap_or(or)
        };
        let s = |k: &str| {
            vars.get(k)
                .and_then(serde_json::Value::as_str)
                .unwrap_or("")
                .to_string()
        };
        Some(Data {
            id: s("id"),
            name: s("display_name"),
            kind: Kind::from_index(vars.get("type")?.as_i64()?)?,
            base_dmg_per_stack: f("base_dmg_per_stack", 1.0),
            tick_interval: f("tick_interval", 1.0),
            duration: f("duration", 4.0),
            freeze_skip_turns: f("freeze_skip_turns", 1.0) as i64,
            stun_skip_chance: f("stun_skip_chance", 0.25),
            pct_per_stack: f("pct_per_stack", 0.0),
            pct_cap: f("pct_cap", 0.0),
        })
    }
}

/// Every status the game knows, by id (EquipmentDB.get_status).
#[derive(Clone, Debug, Default)]
pub struct Db {
    pub all: Vec<Status>,
}

impl Db {
    pub fn get(&self, id: &str) -> Option<Status> {
        self.all.iter().find(|s| s.id == id).cloned()
    }

    pub fn of_kind(&self, kind: Kind) -> Option<Status> {
        self.all.iter().find(|s| s.kind == kind).cloned()
    }
}

/// active_status_effect.gd: one status on a fighter.
#[derive(Clone, Debug)]
pub struct Active {
    pub data: Status,
    pub remaining_duration: f64,
    pub tick_timer: f64,
    pub ticks_since_decay: i64,
    pub remaining_skip_turns: i64,
    pub stacks: i64,
    pub dmg_per_stack: f64,
    pub dormant: bool,
    pub curse_stat: &'static str,
    pub curse_amount: f64,
}

impl Active {
    pub fn new(data: Status, stacks: i64, per_stack: f64) -> Active {
        Active {
            remaining_duration: data.duration,
            remaining_skip_turns: data.freeze_skip_turns,
            data,
            tick_timer: 0.0,
            ticks_since_decay: 0,
            stacks,
            dmg_per_stack: per_stack,
            dormant: false,
            curse_stat: "",
            curse_amount: 0.0,
        }
    }

    pub fn refresh(&mut self) {
        self.remaining_duration = self.data.duration;
        self.remaining_skip_turns = self.data.freeze_skip_turns;
    }

    pub fn kind(&self) -> Kind {
        self.data.kind
    }
}
