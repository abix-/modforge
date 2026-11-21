//! Sophia's PersonaBinder in Abiotic Factor: her senses (her own
//! perception, damage, hostility, where she is asked to be) fill her
//! modforge Perception; her modforge Persona decides through the brain's
//! shared states; what it decides is carried out by her NPC controller
//! (native movement and melee). Her orders (follow, hold, attack, recall,
//! stance) are what she is asked and whom she counts as a threat.
//! K8s slot: Def=OrdersDef, Registry=PLAYERS, Instance=PlayerOrders,
//! Controller=tick.
use crate::ai_player::{addr, object_ptr, session_controller};
use glam::Vec3;
use modforge::actor::ActorId;
use modforge::brain::{Brain, Do, Perception};
use modforge::memory::Known;
use modforge::persona::{Persona, PersonaBinder};
use modforge::statetree::StateTree;
use modforge::survival::Need;
use parking_lot::Mutex;
use serde::{Deserialize, Serialize};
use serde_json::{Value, json};
use std::{
    collections::BTreeMap,
    time::{Duration, Instant},
};
use ueforge::behavior_tree::Action;
use ueforge::{
    reflect,
    ue::{UObject, uobject::ObjectIdentity},
};

pub type Position = [f64; 3];

pub fn distance(a: Position, b: Position) -> f64 {
    a.into_iter().zip(b).map(|(a, b)| (a - b).powi(2)).sum::<f64>().sqrt()
}

/// Where she is asked to be: by a human she follows, or at a spot.
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
#[serde(tag = "kind", rename_all = "snake_case")]
pub enum Assignment {
    Follow { player: String },
    Hold { position: Position, protected_player: Option<String> },
}

/// Whom she counts as a threat: nobody, whoever attacked her or the one
/// she protects, or every hostile she sees.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize, Deserialize)]
#[serde(rename_all = "snake_case")]
pub enum Stance {
    Passive,
    Defensive,
    Aggressive,
}

/// In Unreal units (cm): how near counts as following and holding, and how
/// far from where she is asked to be a hostile still counts.
/// `pursuit_timeout` is kept so saved orders load; the brain's leash and
/// flee line decide how long she fights.
#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct Limits {
    pub follow_distance: f64,
    pub hold_radius: f64,
    pub chase_distance: f64,
    pub pursuit_timeout: f64,
}

impl Limits {
    pub fn validate(&self) -> Result<(), String> {
        for (name, value) in [
            ("follow distance", self.follow_distance),
            ("hold radius", self.hold_radius),
            ("chase distance", self.chase_distance),
            ("pursuit timeout", self.pursuit_timeout),
        ] {
            if !value.is_finite() || value <= 0.0 {
                return Err(format!("{name} must be finite and positive"));
            }
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
    /// Settings from the UI and the command op.
    pub fn configure(&mut self, command: &str, args: &Value) -> Result<bool, String> {
        let mut next = self.clone();
        match command {
            "stance" => next.stance = serde_json::from_value(args["stance"].clone()).map_err(|e| e.to_string())?,
            "groups" => {
                next.groups = serde_json::from_value(args["groups"].clone()).map_err(|e| e.to_string())?;
                if next.groups.iter().any(|g| g.trim().is_empty()) {
                    return Err("group names cannot be empty".into());
                }
                next.groups.sort();
                next.groups.dedup();
            }
            "limits" => {
                let mut values = serde_json::to_value(&next.limits).map_err(|e| e.to_string())?;
                for (key, value) in args["limits"].as_object().ok_or("limits object required")? {
                    if values.get(key).is_none() {
                        return Err(format!("unknown limit {key}"));
                    }
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

/// The AI players a command names: one, several, a group, or all.
fn recipients<'a>(args: &Value, players: impl Iterator<Item = (&'a str, &'a OrdersDef)>) -> Result<Vec<String>, String> {
    let players: BTreeMap<_, _> = players.collect();
    let mut names: Vec<String> = if args["all"] == true {
        players.keys().map(|n| (*n).into()).collect()
    } else if let Some(group) = args["group"].as_str() {
        players.iter().filter(|(_, def)| def.groups.iter().any(|g| g == group)).map(|(n, _)| (*n).into()).collect()
    } else if let Some(names) = args["players"].as_array() {
        names
            .iter()
            .map(|n| n.as_str().map(str::to_owned).ok_or("players must contain names".into()))
            .collect::<Result<_, String>>()?
    } else if let Some(name) = args["player"].as_str() {
        vec![name.into()]
    } else if players.len() == 1 {
        players.keys().map(|n| (*n).into()).collect()
    } else {
        return Err("select one AI player, a group, or all AI players".into());
    };
    names.sort();
    names.dedup();
    if names.is_empty() {
        return Err("no AI players selected".into());
    }
    for name in &names {
        if !players.contains_key(name.as_str()) {
            return Err(format!("{name} has no active orders"));
        }
    }
    Ok(names)
}

/// A hostile character she knows of this tick, in Unreal units.
#[derive(Clone, Copy, Debug)]
struct Target {
    id: u64,
    position: Position,
    perceived: bool,
    threatens_self: bool,
    threatens_protected: bool,
}

/// Unreal's cm (x and y on the ground, z up) as the brain's metres (y up,
/// the ground x and z).
fn to_brain(p: Position) -> Vec3 {
    Vec3::new(p[0] as f32, p[2] as f32, p[1] as f32) / 100.0
}

fn to_unreal(p: Vec3) -> Position {
    [f64::from(p.x) * 100.0, f64::from(p.z) * 100.0, f64::from(p.y) * 100.0]
}

/// Her tree: the states every game shares (modforge brain), nothing of
/// Abiotic Factor's own yet.
fn brain_tree() -> StateTree<Brain> {
    let mut s = vec![modforge::brain::root()];
    modforge::brain::fighting_states(&mut s);
    modforge::brain::eat_carried_state(&mut s);
    modforge::brain::need_states(&mut s);
    modforge::brain::trade_states(&mut s);
    modforge::brain::asked_states(&mut s);
    modforge::brain::look_states(&mut s);
    modforge::brain::wander_state(&mut s);
    StateTree { states: s }
}

/// Sophia's senses this tick, read on the game thread, and what her brain
/// decided.
struct AbioticBinder {
    now: u64,
    position: Vec3,
    health_fraction: f32,
    hostile: Option<(ActorId, Vec3)>,
    asked: Option<Vec3>,
    decided: Vec<modforge::actions::Action>,
}

impl PersonaBinder for AbioticBinder {
    fn perceive<'a>(&'a self, persona: &'a Persona, worth: &'a dyn Fn(&Known, Need) -> f32) -> Perception<'a> {
        Perception {
            now: self.now,
            position: self.position,
            yaw: 0.0,
            health_fraction: self.health_fraction,
            needs: persona.needs,
            home: None,
            behaviour: modforge::actor::Behaviour::Hunter,
            at_home: false,
            asleep: false,
            hostile: self.hostile,
            game: &(),
            night: false,
            carries_food: false,
            carries_drink: false,
            bags_full: false,
            memory: &persona.memory,
            personality: &persona.personality,
            worth,
            standable: &|_| true,
            reachable: &Vec::new,
            unknown: &|_| false,
            asked: self.asked,
            trader: None,
        }
    }

    /// Nothing in Abiotic Factor answers her needs yet.
    fn worth(&self, _: &Known, _: Need) -> f32 {
        0.0
    }

    fn act(&mut self, actions: Vec<modforge::actions::Action>, _: Option<Do>) {
        self.decided = actions;
    }
}

impl AbioticBinder {
    /// What her NPC controller carries out: the fight when the brain fights
    /// the hostile (attacking, or going to where it stands), else the walk
    /// the brain asked for, else staying where she is asked to be.
    fn order(&self, anchor: Position, radius: f64, returning: bool, following: bool) -> Action {
        use modforge::actions::Action as Did;
        let go = self.decided.iter().rev().find_map(|a| match *a {
            Did::Go { x, y, z } => Some(Vec3::new(x, y, z)),
            _ => None,
        });
        if let Some((who, at)) = self.hostile {
            if self.decided.contains(&Did::Attack) || go.is_some_and(|g| g.distance(at) < 0.5) {
                return Action::Attacking { target: who.0 };
            }
        }
        let position = go.map_or(anchor, to_unreal);
        if returning {
            Action::Returning { position, radius }
        } else if following {
            Action::Following { position, radius }
        } else {
            Action::Holding { position, radius }
        }
    }
}

struct KnownTarget {
    identity: ObjectIdentity,
    self_attack: bool,
    protected_attack: bool,
}
struct PlayerOrders {
    def: OrdersDef,
    /// Her whole person, from her folder while she has orders.
    persona: Persona,
    brain: StateTree<Brain>,
    roll: modforge::monument::Roll,
    /// The hostile she was told to attack.
    explicit: Option<u64>,
    /// Recalled: no fighting until she is back where she is asked to be.
    returning: bool,
    /// The most health seen on her; her health is a fraction of it.
    most_health: f64,
    ticks: u64,
    execution: ueforge::behavior_tree::AiOrderExecution,
    tree: Option<ObjectIdentity>,
    targets: BTreeMap<u64, KnownTarget>,
    damage_cursor: u64,
    action: Action,
    sources_at: Option<Instant>,
    available: Vec<Value>,
}
static PLAYERS: Mutex<BTreeMap<String, PlayerOrders>> = Mutex::new(BTreeMap::new());
static DAMAGE: Mutex<Option<ueforge::damage::actor::ActorDamageTracker>> = Mutex::new(None);

pub(crate) fn shutdown() {
    // Drop hooks while the engine and this DLL are still present.
    DAMAGE.lock().take();
}

pub(crate) fn active(name: &str) -> bool {
    PLAYERS.lock().contains_key(name)
}
pub(crate) fn snapshot() -> Value {
    json!(PLAYERS.lock().iter().map(|(name, orders)| json!({"name": name, "definition": orders.def, "action": orders.action, "targets": orders.available})).collect::<Vec<_>>())
}
pub(crate) fn stop(name: &str) {
    ueforge::loops::stop(&crate::ai_player::loop_name(name, "orders"));
    if let Some(orders) = PLAYERS.lock().remove(name) {
        save_persona(name, &orders.persona);
    }
}

/// Her person back to her folder.
fn save_persona(name: &str, persona: &Persona) {
    let saved = crate::ai_player::session_directory(name).and_then(|d| persona.save(&d).map_err(|e| e.to_string()));
    if let Err(error) = saved {
        ueforge::log!("AI player {name} persona: {error}");
    }
}

/// Save her person every this many order ticks (10 s at 250 ms). Claude's number.
const SAVE_EVERY: u64 = 40;

pub(crate) fn start(name: &str, defaults: OrdersDef) -> Result<(), String> {
    if active(name) {
        return Ok(());
    }
    let path = crate::ai_player::session_directory(name)?.join("abiotic-orders.json");
    let def: OrdersDef = match std::fs::read(&path) {
        Ok(bytes) => {
            serde_json::from_slice(&bytes).map_err(|e| format!("AI player orders: {e}"))?
        }
        Err(e) if e.kind() == std::io::ErrorKind::NotFound => defaults,
        Err(e) => return Err(format!("read AI player orders: {e}")),
    };
    def.limits.validate()?;
    let directory = crate::ai_player::session_directory(name)?;
    let persona = Persona::load(&directory).map_err(|e| format!("AI player persona: {e}"))?;
    PLAYERS.lock().insert(
        name.into(),
        PlayerOrders {
            def,
            persona,
            brain: brain_tree(),
            roll: modforge::monument::Roll::new(modforge::persona::key_of(name)),
            explicit: None,
            returning: false,
            most_health: 0.0,
            ticks: 0,
            execution: Default::default(),
            tree: None,
            targets: BTreeMap::new(),
            damage_cursor: DAMAGE.lock().as_ref().map_or(0, |d| d.sequence()),
            action: Action::Blocked {
                reason: "initializing".into(),
            },
            sources_at: None,
            available: Vec::new(),
        },
    );
    crate::ai_player::take_walking(name, "orders");
    tick(&json!({"player": name}))?;
    ueforge::loops::start(
        &crate::ai_player::loop_name(name, "orders"),
        "ai_player.order_tick",
        json!({"player": name}),
        Duration::from_millis(250),
    )?;
    Ok(())
}

unsafe fn location(object: &UObject) -> Result<[f64; 3], String> {
    unsafe { ueforge::ue::transform::world_location(object.as_ptr()) }
        .map(|(x, y, z)| [x, y, z])
        .ok_or("actor location unavailable".into())
}

unsafe fn remember(
    orders: &mut PlayerOrders,
    object: &UObject,
    self_attack: bool,
    protected_attack: bool,
) {
    let id = object as *const UObject as u64;
    let target = orders.targets.entry(id).or_insert_with(|| KnownTarget {
        identity: ObjectIdentity::capture(object),
        self_attack: false,
        protected_attack: false,
    });
    target.self_attack |= self_attack;
    target.protected_attack |= protected_attack;
}

/// One think of Sophia's brain from what she senses this tick, turned into
/// what her NPC controller carries out. Her orders say where she is asked
/// to be and whom she counts as a threat; the brain decides.
fn decide(
    name: &str,
    orders: &mut PlayerOrders,
    here: Position,
    health: f64,
    anchor: Option<Position>,
    targets: &[Target],
) -> Action {
    if health <= 0.0 {
        orders.explicit = None;
        return Action::Dead;
    }
    let Some(anchor) = anchor else {
        orders.explicit = None;
        return Action::Blocked { reason: "assignment destination unavailable".into() };
    };
    let (radius, following) = match orders.def.assignment {
        Assignment::Follow { .. } => (orders.def.limits.follow_distance, true),
        Assignment::Hold { .. } => (orders.def.limits.hold_radius, false),
    };
    if orders.returning && distance(here, anchor) <= radius {
        orders.returning = false;
    }
    let limits = &orders.def.limits;
    let in_bounds = |t: &&Target| {
        distance(t.position, anchor) <= limits.chase_distance && distance(here, anchor) <= limits.chase_distance
    };
    if orders.explicit.is_some_and(|id| !targets.iter().any(|t| t.id == id)) {
        orders.explicit = None;
    }
    let stance = orders.def.stance;
    let threat = |t: &&Target| match stance {
        Stance::Passive => false,
        Stance::Defensive => t.threatens_self || t.threatens_protected,
        Stance::Aggressive => t.perceived,
    };
    let hostile = if orders.returning {
        None
    } else if let Some(id) = orders.explicit {
        targets.iter().find(|t| t.id == id).filter(in_bounds)
    } else {
        targets
            .iter()
            .filter(in_bounds)
            .filter(threat)
            .min_by(|a, b| distance(a.position, here).total_cmp(&distance(b.position, here)))
    };
    let mut binder = AbioticBinder {
        now: crate::explore::now(),
        position: to_brain(here),
        health_fraction: (health / orders.most_health.max(1.0)) as f32,
        hostile: hostile.map(|t| (ActorId(t.id), to_brain(t.position))),
        asked: Some(to_brain(anchor)),
        decided: Vec::new(),
    };
    modforge::persona::think(&mut binder, &mut orders.persona, &orders.brain, &mut orders.roll);
    orders.ticks += 1;
    if orders.ticks % SAVE_EVERY == 0 {
        save_persona(name, &orders.persona);
    }
    binder.order(anchor, radius, orders.returning, following)
}

unsafe fn hostile_character(
    controller: &UObject,
    body: &UObject,
    target: &UObject,
) -> Result<bool, String> {
    let class = ueforge::ue::find_class_fast("Character").ok_or("Character class unavailable")?;
    if !target.is_a(class) {
        return Ok(false);
    }
    let address = format!("0x{:X}", target as *const UObject as u64);
    // SAFETY: all three actors are live in the current game-thread job.
    unsafe {
        let friend = reflect::call(
            body,
            "Abiotic_Character_ParentBP_C",
            "CheckFriendlyAllyOrHostile",
            json!({"PawnToTest": address}).as_object().unwrap(),
        )?;
        if friend["Friend"] == true {
            return Ok(false);
        }
        let hostile = reflect::call(
            controller,
            "Abiotic_AI_Controller_ParentBP_C",
            "GetHostilityTowardsTarget",
            json!({"Target": address}).as_object().unwrap(),
        )?;
        if hostile["Hostile"] != true {
            return Ok(false);
        }
        let validity = reflect::call(
            controller,
            "Abiotic_AI_Controller_ParentBP_C",
            "CheckCombatTargetValidity",
            json!({"TargetToCheck": address, "Maintain": true})
                .as_object()
                .unwrap(),
        )?;
        Ok(validity["Valid"] == true)
    }
}

unsafe fn update(name: &str, orders: &mut PlayerOrders) -> Result<(), String> {
    // SAFETY: this entire adapter executes in one game-thread job; engine-owned
    // references are resolved before use and cached targets carry identities.
    unsafe {
        let (controller, pawn) = session_controller(name)?;
        if pawn == 0 {
            orders.action = Action::Dead;
            return Ok(());
        }
        let body = &*(pawn as *const UObject);
        if orders.tree.is_none() {
            // Reuse native melee animation/hit execution without any NPC target
            // chooser, wandering, investigation or corpse-eating services.
            reflect::object_ref(&json!(
                "asset:/Game/Blueprints/AI/Zombie/BT_Attack_Zombie.BT_Attack_Zombie"
            ))?;
            let original = object_ptr(controller, "BehaviorTree")?;
            let board = object_ptr(&*(original as *const UObject), "BlackboardAsset")?;
            let keys =
                ueforge::behavior_tree::blackboard_get(controller, &["RangeToMeleeAttack".into()])?;
            let range = keys["RangeToMeleeAttack"]
                .as_f64()
                .ok_or("native melee range unavailable")?;
            let root = json!({"class": "BTComposite_Sequence", "children": [
                {"class": "BTTask_MoveTo", "fields": {"BlackboardKey": {"SelectedKeyName": "TargetActor"}, "AcceptableRadius": range, "bAllowPartialPath": false, "bReachTestIncludesAgentRadius": false, "bReachTestIncludesGoalRadius": false}},
                {"class": "BTT_DoMeleeAttack_C", "fields": {"OnlyIncrementOnMiss": false, "OnlyIncrementOnHit": true, "Delay": false}},
                {"class": "BTTask_Wait", "fields": {"WaitTime": 0.5, "RandomDeviation": 0.0}}
            ]});
            let tree =
                ueforge::behavior_tree::build(controller as *const UObject as u64, board, &root)?;
            reflect::set_fields(
                controller,
                json!({"BehaviorTree": format!("0x{tree:X}")})
                    .as_object()
                    .unwrap(),
            )?;
            orders.tree = Some(ObjectIdentity::capture(&*(tree as *const UObject)));
        }
        let tree = orders
            .tree
            .as_ref()
            .and_then(|t| t.resolve())
            .ok_or("AI player tree disappeared")? as *const UObject as u64;
        let health =
            reflect::get_fields(body, &["TotalCombinedHealth".into()])?["TotalCombinedHealth"]
                .as_f64()
                .ok_or("health unavailable")?;
        // Her greatest health is not read from the game yet: the most seen
        // on her stands for it (Claude's).
        orders.most_health = orders.most_health.max(health);
        let protected = match &orders.def.assignment {
            Assignment::Follow { player } => Some(player.clone()),
            Assignment::Hold {
                protected_player, ..
            } => protected_player.clone(),
        };
        let human = protected
            .as_deref()
            .and_then(|p| crate::nav::player_character(p).ok())
            .map(|(_, p)| p);
        {
            let mut observer = DAMAGE.lock();
            let observer = observer.get_or_insert_with(Default::default);
            observer.watch(body)?;
            if let Some(human) = human {
                observer.watch(human)?;
            }
            for event in observer.since(&mut orders.damage_cursor)? {
                let Some(victim) = event.victim.resolve() else {
                    continue;
                };
                let is_self = std::ptr::eq(victim, body);
                let is_player = human.is_some_and(|human| std::ptr::eq(victim, human));
                if !is_self && !is_player {
                    continue;
                }
                let causer = event.causer.as_ref().and_then(|c| c.resolve());
                let character = ueforge::ue::find_class_fast("Character")
                    .ok_or("Character class unavailable")?;
                let attacker = match causer.filter(|c| c.is_a(character)) {
                    Some(actor) => Some(actor),
                    None => match event.instigator.as_ref().and_then(|c| c.resolve()) {
                        Some(controller) => {
                            let pawn = object_ptr(controller, "Pawn")?;
                            if pawn == 0 {
                                None
                            } else {
                                Some(&*(pawn as *const UObject))
                            }
                        }
                        None => None,
                    },
                };
                if let Some(attacker) = attacker {
                    remember(orders, attacker, is_self, is_player);
                }
            }
        }
        let anchor = match orders.def.assignment {
            Assignment::Follow { .. } => human.map(|p| location(p)).transpose()?,
            Assignment::Hold { position, .. } => Some(position),
        };
        if orders
            .sources_at
            .is_none_or(|t| t.elapsed() >= Duration::from_secs(2))
        {
            crate::perception::register_npc_sources()?;
            orders.sources_at = Some(Instant::now());
        }
        let perception = object_ptr(body, "AIPerception")?;
        if perception == 0 {
            return Err("AI player native perception missing".into());
        }
        let seen = reflect::call(
            &*(perception as *const UObject),
            "AIPerceptionComponent",
            "GetCurrentlyPerceivedActors",
            json!({"SenseToUse": "class:AISense_Sight"})
                .as_object()
                .unwrap(),
        )?;
        let seen: Vec<u64> = seen["OutActors"]
            .as_array()
            .ok_or_else(|| format!("perception output unavailable: {seen}"))?
            .iter()
            .map(addr)
            .filter(|a| *a != 0)
            .collect();
        for address in &seen {
            remember(orders, &*(*address as *const UObject), false, false);
        }
        let mut targets = Vec::new();
        orders.available.clear();
        orders.targets.retain(|_, t| t.identity.resolve().is_some());
        for (id, known) in &orders.targets {
            let Some(target) = known.identity.resolve() else {
                continue;
            };
            // Native NPC hostility also includes player deployables (a water
            // cooler was returned live). AI player combat targets characters.
            if !hostile_character(controller, body, target)? {
                continue;
            }
            if seen.contains(id) {
                let class = target
                    .class()
                    .ok_or("target class unavailable")?
                    .as_object()
                    .name();
                let display = class
                    .trim_start_matches("NPC_Monster_")
                    .trim_start_matches("NPC_Soldier_")
                    .trim_start_matches("NPC_")
                    .trim_end_matches("_C")
                    .replace('_', " ");
                orders
                    .available
                    .push(json!({"selector": format!("addr:0x{id:X}"), "name": display}));
            }
            targets.push(Target {
                id: *id,
                position: location(target)?,
                perceived: seen.contains(id),
                threatens_self: known.self_attack,
                threatens_protected: known.protected_attack,
            });
        }
        let here = location(body)?;
        let action = decide(name, orders, here, health, anchor, &targets);
        let target = match action {
            Action::Attacking { target } => Some(target),
            _ => None,
        };
        ueforge::behavior_tree::blackboard_set(controller, json!({"TargetActor": target.map(|t| format!("0x{t:X}")),
            "CombatMode": target.is_some(), "CanSeeTarget": target.is_some_and(|t| seen.contains(&t)), "TargetLocked": target.is_some()}).as_object().unwrap())?;
        let combat = reflect::get_fields(controller, &["IsInCombat".into()])?["IsInCombat"]
            .as_bool()
            .ok_or("native combat state unavailable")?;
        if combat != target.is_some() {
            reflect::call(
                controller,
                "Abiotic_AI_Controller_ParentBP_C",
                "BT_SetCombatState",
                json!({"State": target.is_some(), "SkipAggroAnimation": true})
                    .as_object()
                    .unwrap(),
            )?;
        }
        orders.execution.apply(controller, tree, &action)?;
        orders.action = action;
        Ok(())
    }
}

fn tick(args: &Value) -> Result<Value, String> {
    let name = crate::ai_player::player_name(args)?;
    ueforge::debug::enqueue_pe(
        &crate::DRAIN,
        Duration::from_secs(10),
        crate::DRAIN_HINT,
        move || {
            let mut all = PLAYERS.lock();
            let orders = all.get_mut(&name).ok_or("AI player orders not active")?;
            // SAFETY: queued game-thread adapter.
            if let Err(error) = unsafe { update(&name, orders) } {
                orders.action = Action::Blocked {
                    reason: error.clone(),
                };
                if let Ok((controller, _)) = unsafe { session_controller(&name) } {
                    unsafe { orders.execution.apply(controller, 0, &orders.action) }
                        .map_err(|stop| format!("{error}; stop: {stop}"))?;
                }
                // A missing tree is failed initialization. Once initialized, an
                // unreachable destination is a visible blocked assignment, not a
                // reason to destroy a successfully spawned AI player.
                if orders.tree.is_none() {
                    return Err(error);
                }
            }
            Ok(json!({"name": name, "definition": orders.def, "action": orders.action}))
        },
    )
}

pub(crate) fn command(args: &Value) -> Result<Value, String> {
    let args = args.clone();
    ueforge::debug::enqueue_pe(
        &crate::DRAIN,
        Duration::from_secs(10),
        crate::DRAIN_HINT,
        move || {
            let mut all = PLAYERS.lock();
            let names = recipients(
                &args,
                all.iter()
                    .map(|(name, orders)| (name.as_str(), &orders.def)),
            )?;
            let command = args["command"].as_str().ok_or("command required")?;
            let mut changed = Vec::new();
            for name in names {
                let orders = all.get_mut(&name).unwrap();
                let mut def = orders.def.clone();
                match command {
                    "follow" => {
                        let human = args["target"]
                            .as_str()
                            .filter(|t| !t.is_empty())
                            .map(str::to_owned)
                            .or_else(|| {
                                unsafe { crate::nav::players() }
                                    .ok()?
                                    .into_iter()
                                    .map(|(n, _)| n)
                                    .next()
                            })
                            .ok_or("no human available")?;
                        unsafe { crate::nav::player_character(&human)? };
                        def.assignment = Assignment::Follow { player: human };
                        if let Some(distance) = args["distance"].as_f64() {
                            def.limits.follow_distance = distance;
                        }
                    }
                    "hold" => {
                        let (_, pawn) = unsafe { session_controller(&name)? };
                        if pawn == 0 {
                            return Err("AI player has no body".into());
                        }
                        let protected_player = match &def.assignment {
                            Assignment::Follow { player } => Some(player.clone()),
                            Assignment::Hold {
                                protected_player, ..
                            } => protected_player.clone(),
                        };
                        def.assignment = Assignment::Hold {
                            position: unsafe { location(&*(pawn as *const UObject))? },
                            protected_player,
                        };
                    }
                    "attack" => {
                        let target = ueforge::selector::resolve(
                            args["target"].as_str().ok_or("target selector required")?,
                        )?;
                        let (controller, pawn) = unsafe { session_controller(&name)? };
                        if pawn == 0 {
                            return Err("AI player has no body".into());
                        }
                        if !unsafe {
                            hostile_character(controller, &*(pawn as *const UObject), target)?
                        } {
                            return Err("attack target must be a living hostile character".into());
                        }
                        unsafe { remember(orders, target, false, false) };
                        orders.explicit = Some(target as *const UObject as u64);
                        orders.returning = false;
                    }
                    "recall" => {
                        orders.explicit = None;
                        orders.returning = true;
                    }
                    "cancel_attack" => orders.explicit = None,
                    _ => {
                        if !def.configure(command, &args)? {
                            return Err(format!("unknown AI player command {command}"));
                        }
                    }
                }
                def.limits.validate()?;
                let path = crate::ai_player::session_directory(&name)?.join("abiotic-orders.json");
                modforge::settings::save_atomic(&path, &def)
                    .map_err(|e| format!("save {name} orders: {e}"))?;
                orders.def = def;
                changed.push(name);
            }
            Ok(json!({"affected": changed}))
        },
    )
}

pub(crate) fn register() {
    use ueforge::ops::{OP_REGISTRY, OpDef};
    OP_REGISTRY.register_many([
        OpDef::new("ai_player.command", "Set assignment, stance, limits, groups, attack, recall or cancel attack for selected AI players", "{player?: str, players?: [str], group?: str, all?: bool, command: str, target?: str, stance?: str, limits?: object, groups?: [str]}", command),
        OpDef::new("ai_player.orders", "Read AI player assignments, stance and current action", "{}", |_| Ok(snapshot())),
        OpDef::new("ai_player.order_tick", "Apply one shared AI player decision using native perception and melee", "{player?: str}", tick),
    ]);
}
