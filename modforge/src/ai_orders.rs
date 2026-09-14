//! AI player orders independent of an engine. Positions and distances use the
//! consumer's world units; time is monotonic seconds supplied by the consumer.
//! K8s slot: Def=OrdersDef, Registry=consumer, Instance=OrdersTracker,
//! Controller=OrdersTracker::decide.
//!
//! This is assignment execution, not the persistent AI player's identity or
//! autonomous goal selection. The adapter supplies hostiles relative to this
//! AI player, whether allied or hostile to the human. Persona owns persistence.
use serde::{Deserialize, Serialize};

pub type Position = [f64; 3];

pub fn distance(a: Position, b: Position) -> f64 {
    a.into_iter().zip(b).map(|(a, b)| (a - b).powi(2)).sum::<f64>().sqrt()
}

#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
#[serde(tag = "kind", rename_all = "snake_case")]
pub enum Assignment {
    Follow { player: String },
    Hold { position: Position, protected_player: Option<String> },
}

#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
#[serde(rename_all = "snake_case")]
pub enum Stance { Passive, Defensive, Aggressive }

#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct Limits {
    pub follow_distance: f64,
    pub hold_radius: f64,
    pub chase_distance: f64,
    pub pursuit_timeout: f64,
}

impl Limits {
    pub fn validate(&self) -> Result<(), String> {
        for (name, value) in [("follow distance", self.follow_distance), ("hold radius", self.hold_radius),
            ("chase distance", self.chase_distance), ("pursuit timeout", self.pursuit_timeout)] {
            if !value.is_finite() || value <= 0.0 { return Err(format!("{name} must be finite and positive")); }
        }
        if self.chase_distance < self.follow_distance.max(self.hold_radius) {
            return Err("chase distance must cover the follow distance and hold radius".into());
        }
        Ok(())
    }
}

#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct OrdersDef {
    pub assignment: Assignment,
    pub stance: Stance,
    pub limits: Limits,
    pub groups: Vec<String>,
}

impl OrdersDef {
    /// Shared settings handling for UI and API adapters. Assignment destinations
    /// and actor selectors are resolved by the consumer before applying orders.
    pub fn configure(&mut self, command: &str, args: &serde_json::Value) -> Result<bool, String> {
        let mut next = self.clone();
        match command {
            "stance" => next.stance = serde_json::from_value(args["stance"].clone()).map_err(|e| e.to_string())?,
            "groups" => {
                next.groups = serde_json::from_value(args["groups"].clone()).map_err(|e| e.to_string())?;
                if next.groups.iter().any(|g| g.trim().is_empty()) { return Err("group names cannot be empty".into()); }
                next.groups.sort(); next.groups.dedup();
            }
            "limits" => {
                let mut values = serde_json::to_value(&next.limits).map_err(|e| e.to_string())?;
                for (key, value) in args["limits"].as_object().ok_or("limits object required")? {
                    if values.get(key).is_none() { return Err(format!("unknown limit {key}")); }
                    values[key] = value.clone();
                }
                next.limits = serde_json::from_value(values).map_err(|e| e.to_string())?;
            }
            _ => return Ok(false),
        }
        next.limits.validate()?;
        *self = next;
        Ok(true)
    }
}

/// Select from AI players the caller is allowed to command. Group membership
/// alone does not establish allegiance or permission to command an AI player.
pub fn recipients<'a>(args: &serde_json::Value, players: impl Iterator<Item = (&'a str, &'a OrdersDef)>) -> Result<Vec<String>, String> {
    let players: std::collections::BTreeMap<_,_> = players.collect();
    let mut names: Vec<String> = if args["all"] == true { players.keys().map(|n| (*n).into()).collect() }
    else if let Some(group) = args["group"].as_str() {
        players.iter().filter(|(_,def)| def.groups.iter().any(|g| g == group)).map(|(n,_)| (*n).into()).collect()
    } else if let Some(names) = args["players"].as_array() {
        names.iter().map(|n| n.as_str().map(str::to_owned).ok_or("players must contain names".into())).collect::<Result<_,String>>()?
    } else if let Some(name) = args["player"].as_str() { vec![name.into()] }
    else if players.len() == 1 { players.keys().map(|n| (*n).into()).collect() }
    else { return Err("select one AI player, a group, or all AI players".into()); };
    names.sort(); names.dedup();
    if names.is_empty() { return Err("no AI players selected".into()); }
    for name in &names { if !players.contains_key(name.as_str()) { return Err(format!("{name} has no active orders")); } }
    Ok(names)
}

#[derive(Clone, Copy, Debug)]
pub struct Target {
    /// Opaque identity supplied by the adapter, never an unchecked pointer.
    pub id: u64,
    pub position: Position,
    pub perceived: bool,
    pub threatens_self: bool,
    pub threatens_protected: bool,
}

pub struct Observation<'a> {
    pub now: f64,
    pub position: Position,
    pub anchor: Option<Position>,
    pub alive: bool,
    /// Only living hostiles, including a still-valid explicit target.
    pub targets: &'a [Target],
}

#[derive(Clone, Debug, PartialEq, Serialize)]
#[serde(tag = "kind", rename_all = "snake_case")]
pub enum Action {
    Following { position: Position, radius: f64 },
    Holding { position: Position, radius: f64 },
    Attacking { target: u64 },
    Returning { position: Position, radius: f64 },
    Blocked { reason: String },
    Dead,
}

#[derive(Default, Debug)]
pub struct OrdersTracker {
    explicit: Option<u64>,
    pursuit: Option<(u64, f64)>,
    returning: bool,
    /// A failed pursuit cannot restart merely because the next tick sees it.
    rejected: Option<u64>,
}

impl OrdersTracker {
    pub fn attack(&mut self, target: u64) {
        self.explicit = Some(target);
        self.pursuit = None;
        self.returning = false;
        self.rejected = None;
    }

    pub fn cancel_attack(&mut self) {
        self.explicit = None;
        self.pursuit = None;
    }

    pub fn recall(&mut self) {
        self.cancel_attack();
        self.returning = true;
    }

    pub fn attacked_by(&mut self, target: u64) {
        if self.rejected == Some(target) { self.rejected = None; }
    }

    pub fn decide(&mut self, def: &OrdersDef, view: &Observation<'_>) -> Action {
        if !view.alive {
            self.cancel_attack();
            return Action::Dead;
        }
        let Some(anchor) = view.anchor else {
            self.cancel_attack();
            return Action::Blocked { reason: "assignment destination unavailable".into() };
        };
        let radius = match def.assignment { Assignment::Follow { .. } => def.limits.follow_distance, Assignment::Hold { .. } => def.limits.hold_radius };
        if self.rejected.is_some_and(|id| !view.targets.iter().any(|t| t.id == id)) {
            self.rejected = None;
        }
        if self.returning {
            if distance(view.position, anchor) <= radius { self.returning = false; }
            // Even on arrival, finish return before permitting another attack.
            return Action::Returning { position: anchor, radius };
        }
        let permitted = |t: &&Target| distance(t.position, anchor) <= def.limits.chase_distance
            && distance(view.position, anchor) <= def.limits.chase_distance;
        let automatic = |t: &&Target| self.rejected != Some(t.id) && match def.stance {
            Stance::Passive => false,
            Stance::Defensive => t.threatens_self || t.threatens_protected,
            Stance::Aggressive => t.perceived,
        };
        let target = if let Some(explicit) = self.explicit {
            view.targets.iter().find(|t| t.id == explicit).filter(permitted)
        } else {
            self.pursuit.and_then(|(id, _)| view.targets.iter().find(|t| t.id == id).filter(permitted).filter(automatic))
                .or_else(|| view.targets.iter().filter(permitted).filter(automatic)
                    .min_by(|a, b| distance(a.position, view.position).total_cmp(&distance(b.position, view.position))))
        };
        if let Some(target) = target {
            let began = match self.pursuit { Some((id, began)) if id == target.id => began, _ => view.now };
            if view.now - began < def.limits.pursuit_timeout {
                self.pursuit = Some((target.id, began));
                return Action::Attacking { target: target.id };
            }
            self.rejected = Some(target.id);
        }
        if self.pursuit.is_some() || self.explicit.is_some() {
            self.cancel_attack();
            self.returning = true;
            return Action::Returning { position: anchor, radius };
        }
        match def.assignment {
            Assignment::Follow { .. } => Action::Following { position: anchor, radius },
            Assignment::Hold { .. } => Action::Holding { position: anchor, radius },
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn definition(stance: Stance) -> OrdersDef {
        OrdersDef { assignment: Assignment::Follow { player: "human".into() }, stance,
            limits: Limits { follow_distance: 2.0, hold_radius: 1.0, chase_distance: 10.0, pursuit_timeout: 5.0 }, groups: vec![] }
    }
    fn view(targets: &[Target], now: f64) -> Observation<'_> {
        Observation { now, position: [0.0; 3], anchor: Some([0.0; 3]), alive: true, targets }
    }
    fn enemy() -> Target { Target { id: 1, position: [5.0, 0.0, 0.0], perceived: true, threatens_self: false, threatens_protected: false } }

    #[test]
    fn stances_and_explicit_attack_preserve_assignment() {
        let mut enemies = [enemy()];
        let mut tracker = OrdersTracker::default();
        for stance in [Stance::Passive, Stance::Defensive] {
            assert!(matches!(tracker.decide(&definition(stance), &view(&enemies, 0.0)), Action::Following { .. }));
        }
        enemies[0].threatens_protected = true;
        assert_eq!(tracker.decide(&definition(Stance::Defensive), &view(&enemies, 0.0)), Action::Attacking { target: 1 });
        tracker.attack(1);
        let mut def = definition(Stance::Passive);
        assert_eq!(tracker.decide(&def, &view(&enemies, 1.0)), Action::Attacking { target: 1 });
        def.assignment = Assignment::Hold { position: [7.0, 0.0, 0.0], protected_player: None };
        let mut observation = view(&[], 2.0);
        observation.anchor = Some([7.0, 0.0, 0.0]);
        assert_eq!(tracker.decide(&def, &observation), Action::Returning { position: [7.0, 0.0, 0.0], radius: 1.0 });
        assert_eq!(def.stance, Stance::Passive);
    }

    #[test]
    fn recall_and_timeout_prevent_immediate_reacquisition() {
        let enemies = [enemy()];
        let def = definition(Stance::Aggressive);
        let mut tracker = OrdersTracker::default();
        assert!(matches!(tracker.decide(&def, &view(&enemies, 0.0)), Action::Attacking { .. }));
        tracker.recall();
        let mut away = view(&enemies, 1.0);
        away.position = [4.0, 0.0, 0.0];
        for _ in 0..3 { assert!(matches!(tracker.decide(&def, &away), Action::Returning { .. })); }
        assert!(matches!(tracker.decide(&def, &view(&enemies, 2.0)), Action::Returning { .. }));
        assert!(matches!(tracker.decide(&def, &view(&enemies, 3.0)), Action::Attacking { .. }));
        assert!(matches!(tracker.decide(&def, &view(&enemies, 9.0)), Action::Returning { .. }));
        tracker.decide(&def, &view(&enemies, 10.0));
        assert!(matches!(tracker.decide(&def, &view(&enemies, 11.0)), Action::Following { .. }));
    }

    #[test]
    fn explicit_attacks_obey_limits_and_dead_body_cannot_execute() {
        let mut enemies = [enemy()];
        enemies[0].position = [11.0, 0.0, 0.0];
        let mut tracker = OrdersTracker::default();
        tracker.attack(1);
        let def = definition(Stance::Passive);
        assert!(matches!(tracker.decide(&def, &view(&enemies, 0.0)), Action::Returning { .. }));
        let mut observation = view(&enemies, 1.0);
        observation.alive = false;
        assert_eq!(tracker.decide(&def, &observation), Action::Dead);
    }

    #[test]
    fn group_selection_and_rejected_settings_preserve_intent() {
        let mut sophia = definition(Stance::Defensive);
        sophia.configure("groups", &serde_json::json!({"groups": ["players", "players"]})).unwrap();
        let charles = definition(Stance::Passive);
        let players = [("Sophia", &sophia), ("Charles", &charles)];
        assert_eq!(recipients(&serde_json::json!({"group": "players"}), players.into_iter()).unwrap(), ["Sophia"]);
        assert!(recipients(&serde_json::json!({"players": ["Sophia", "missing"]}), players.into_iter()).is_err());
        let before = serde_json::to_value(&sophia).unwrap();
        assert!(sophia.configure("limits", &serde_json::json!({"limits": {"chase_distance": -1.0}})).is_err());
        assert_eq!(serde_json::to_value(&sophia).unwrap(), before);
        sophia.configure("stance", &serde_json::json!({"stance": "passive"})).unwrap();
        assert_eq!(sophia.assignment, definition(Stance::Defensive).assignment);
    }

    #[test]
    fn unseen_attacker_does_not_restart_a_timed_out_pursuit_without_a_new_attack() {
        let mut target = enemy();
        target.perceived = false;
        target.threatens_self = true;
        let targets = [target];
        let def = definition(Stance::Defensive);
        let mut tracker = OrdersTracker::default();
        assert!(matches!(tracker.decide(&def, &view(&targets, 0.0)), Action::Attacking { .. }));
        assert!(matches!(tracker.decide(&def, &view(&targets, 6.0)), Action::Returning { .. }));
        tracker.decide(&def, &view(&targets, 7.0));
        assert!(matches!(tracker.decide(&def, &view(&targets, 8.0)), Action::Following { .. }));
        tracker.attacked_by(target.id);
        assert!(matches!(tracker.decide(&def, &view(&targets, 9.0)), Action::Attacking { .. }));
    }

    #[test]
    fn holding_ai_player_fights_and_returns_without_a_human_to_protect() {
        let def = OrdersDef {
            assignment: Assignment::Hold { position: [0.0; 3], protected_player: None },
            ..definition(Stance::Defensive)
        };
        let mut target = enemy();
        target.threatens_self = true;
        let mut tracker = OrdersTracker::default();
        assert_eq!(tracker.decide(&def, &view(&[target], 0.0)), Action::Attacking { target: target.id });
        assert!(matches!(tracker.decide(&def, &view(&[], 1.0)), Action::Returning { .. }));
        tracker.decide(&def, &view(&[], 2.0));
        assert_eq!(tracker.decide(&def, &view(&[], 3.0)), Action::Holding { position: [0.0; 3], radius: 1.0 });
        assert_eq!(def.assignment, Assignment::Hold { position: [0.0; 3], protected_player: None });
    }
}
