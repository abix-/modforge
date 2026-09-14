//! Abiotic perception, damage and native melee adapter for shared AI player orders.
//! K8s slot: Def=modforge::ai_orders::OrdersDef, Registry=PLAYERS,
//! Instance=PlayerOrders, Controller=tick.
use modforge::ai_orders::{Action, Assignment, OrdersDef, OrdersTracker, Observation, Target};
use parking_lot::Mutex;
use serde_json::{Value, json};
use std::{collections::BTreeMap, time::{Duration, Instant}};
use ueforge::{reflect, ue::{UObject, uobject::ObjectIdentity}};
use crate::ai_player::{addr, object_ptr, session_controller};

struct KnownTarget { identity: ObjectIdentity, self_attack: bool, protected_attack: bool }
struct PlayerOrders {
    def: OrdersDef,
    tracker: OrdersTracker,
    execution: ueforge::behavior_tree::AiOrderExecution,
    tree: Option<ObjectIdentity>,
    targets: BTreeMap<u64, KnownTarget>,
    damage_cursor: u64,
    action: Action,
    started: Instant,
    sources_at: Option<Instant>,
    available: Vec<Value>,
}
static PLAYERS: Mutex<BTreeMap<String, PlayerOrders>> = Mutex::new(BTreeMap::new());
static DAMAGE: Mutex<Option<ueforge::damage::actor::ActorDamageTracker>> = Mutex::new(None);

pub(crate) fn shutdown() {
    // Drop hooks while the engine and this DLL are still present.
    DAMAGE.lock().take();
}

pub(crate) fn active(name: &str) -> bool { PLAYERS.lock().contains_key(name) }
pub(crate) fn snapshot() -> Value {
    json!(PLAYERS.lock().iter().map(|(name, orders)| json!({"name": name, "definition": orders.def, "action": orders.action, "targets": orders.available})).collect::<Vec<_>>())
}
pub(crate) fn stop(name: &str) {
    ueforge::loops::stop(&crate::ai_player::loop_name(name, "orders"));
    PLAYERS.lock().remove(name);
}

pub(crate) fn start(name: &str, defaults: OrdersDef) -> Result<(), String> {
    if active(name) { return Ok(()); }
    let path = crate::ai_player::session_directory(name)?.join("abiotic-orders.json");
    let def: OrdersDef = match std::fs::read(&path) {
        Ok(bytes) => serde_json::from_slice(&bytes).map_err(|e| format!("AI player orders: {e}"))?,
        Err(e) if e.kind() == std::io::ErrorKind::NotFound => defaults,
        Err(e) => return Err(format!("read AI player orders: {e}")),
    };
    def.limits.validate()?;
    PLAYERS.lock().insert(name.into(), PlayerOrders { def, tracker: OrdersTracker::default(), execution: Default::default(),
        tree: None, targets: BTreeMap::new(), damage_cursor: DAMAGE.lock().as_ref().map_or(0, |d| d.sequence()), action: Action::Blocked { reason: "initializing".into() },
        started: Instant::now(), sources_at: None, available: Vec::new() });
    crate::ai_player::take_walking(name, "orders");
    tick(&json!({"player": name}))?;
    ueforge::loops::start(&crate::ai_player::loop_name(name, "orders"), "ai_player.order_tick", json!({"player": name}), Duration::from_millis(250))?;
    Ok(())
}

unsafe fn location(object: &UObject) -> Result<[f64; 3], String> {
    unsafe { ueforge::ue::transform::world_location(object.as_ptr()) }.map(|(x,y,z)| [x,y,z]).ok_or("actor location unavailable".into())
}

unsafe fn remember(orders: &mut PlayerOrders, object: &UObject, self_attack: bool, protected_attack: bool) {
    let id = object as *const UObject as u64;
    if self_attack || protected_attack { orders.tracker.attacked_by(id); }
    let target = orders.targets.entry(id).or_insert_with(|| KnownTarget { identity: ObjectIdentity::capture(object), self_attack: false, protected_attack: false });
    target.self_attack |= self_attack;
    target.protected_attack |= protected_attack;
}

unsafe fn hostile_character(controller: &UObject, body: &UObject, target: &UObject) -> Result<bool, String> {
    let class = ueforge::ue::find_class_fast("Character").ok_or("Character class unavailable")?;
    if !target.is_a(class) { return Ok(false); }
    let address = format!("0x{:X}", target as *const UObject as u64);
    // SAFETY: all three actors are live in the current game-thread job.
    unsafe {
        let friend = reflect::call(body, "Abiotic_Character_ParentBP_C", "CheckFriendlyAllyOrHostile",
            json!({"PawnToTest": address}).as_object().unwrap())?;
        if friend["Friend"] == true { return Ok(false); }
        let hostile = reflect::call(controller, "Abiotic_AI_Controller_ParentBP_C", "GetHostilityTowardsTarget",
            json!({"Target": address}).as_object().unwrap())?;
        if hostile["Hostile"] != true { return Ok(false); }
        let validity = reflect::call(controller, "Abiotic_AI_Controller_ParentBP_C", "CheckCombatTargetValidity",
            json!({"TargetToCheck": address, "Maintain": true}).as_object().unwrap())?;
        Ok(validity["Valid"] == true)
    }
}

unsafe fn update(name: &str, orders: &mut PlayerOrders) -> Result<(), String> {
    // SAFETY: this entire adapter executes in one game-thread job; engine-owned
    // references are resolved before use and cached targets carry identities.
    unsafe {
        let (controller, pawn) = session_controller(name)?;
        if pawn == 0 { orders.action = Action::Dead; return Ok(()); }
        let body = &*(pawn as *const UObject);
        if orders.tree.is_none() {
            // Reuse native melee animation/hit execution without any NPC target
            // chooser, wandering, investigation or corpse-eating services.
            reflect::object_ref(&json!("asset:/Game/Blueprints/AI/Zombie/BT_Attack_Zombie.BT_Attack_Zombie"))?;
            let original = object_ptr(controller, "BehaviorTree")?;
            let board = object_ptr(&*(original as *const UObject), "BlackboardAsset")?;
            let keys = ueforge::behavior_tree::blackboard_get(controller, &["RangeToMeleeAttack".into()])?;
            let range = keys["RangeToMeleeAttack"].as_f64().ok_or("native melee range unavailable")?;
            let root = json!({"class": "BTComposite_Sequence", "children": [
                {"class": "BTTask_MoveTo", "fields": {"BlackboardKey": {"SelectedKeyName": "TargetActor"}, "AcceptableRadius": range, "bAllowPartialPath": false, "bReachTestIncludesAgentRadius": false, "bReachTestIncludesGoalRadius": false}},
                {"class": "BTT_DoMeleeAttack_C", "fields": {"OnlyIncrementOnMiss": false, "OnlyIncrementOnHit": true, "Delay": false}},
                {"class": "BTTask_Wait", "fields": {"WaitTime": 0.5, "RandomDeviation": 0.0}}
            ]});
            let tree = ueforge::behavior_tree::build(controller as *const UObject as u64, board, &root)?;
            reflect::set_fields(controller, json!({"BehaviorTree": format!("0x{tree:X}")}).as_object().unwrap())?;
            orders.tree = Some(ObjectIdentity::capture(&*(tree as *const UObject)));
        }
        let tree = orders.tree.as_ref().and_then(|t| t.resolve()).ok_or("AI player tree disappeared")? as *const UObject as u64;
        let alive = reflect::get_fields(body, &["TotalCombinedHealth".into()])?["TotalCombinedHealth"].as_f64().ok_or("health unavailable")? > 0.0;
        let protected = match &orders.def.assignment {
            Assignment::Follow { player } => Some(player.clone()),
            Assignment::Hold { protected_player, .. } => protected_player.clone(),
        };
        let human = protected.as_deref().and_then(|p| crate::nav::player_character(p).ok()).map(|(_,p)| p);
        {
            let mut observer = DAMAGE.lock();
            let observer = observer.get_or_insert_with(Default::default);
            observer.watch(body)?;
            if let Some(human) = human { observer.watch(human)?; }
            for event in observer.since(&mut orders.damage_cursor)? {
                let Some(victim) = event.victim.resolve() else { continue; };
                let is_self = std::ptr::eq(victim, body);
                let is_player = human.is_some_and(|human| std::ptr::eq(victim, human));
                if !is_self && !is_player { continue; }
                let causer = event.causer.as_ref().and_then(|c| c.resolve());
                let character = ueforge::ue::find_class_fast("Character").ok_or("Character class unavailable")?;
                let attacker = match causer.filter(|c| c.is_a(character)) {
                    Some(actor) => Some(actor),
                    None => match event.instigator.as_ref().and_then(|c| c.resolve()) {
                        Some(controller) => { let pawn = object_ptr(controller, "Pawn")?; if pawn == 0 { None } else { Some(&*(pawn as *const UObject)) } }
                        None => None,
                    },
                };
                if let Some(attacker) = attacker { remember(orders, attacker, is_self, is_player); }
            }
        }
        let anchor = match orders.def.assignment {
            Assignment::Follow { .. } => human.map(|p| location(p)).transpose()?,
            Assignment::Hold { position, .. } => Some(position),
        };
        if orders.sources_at.is_none_or(|t| t.elapsed() >= Duration::from_secs(2)) {
            crate::perception::register_npc_sources()?;
            orders.sources_at = Some(Instant::now());
        }
        let perception = object_ptr(body, "AIPerception")?;
        if perception == 0 { return Err("AI player native perception missing".into()); }
        let seen = reflect::call(&*(perception as *const UObject), "AIPerceptionComponent", "GetCurrentlyPerceivedActors",
            json!({"SenseToUse": "class:AISense_Sight"}).as_object().unwrap())?;
        let seen: Vec<u64> = seen["OutActors"].as_array().ok_or_else(|| format!("perception output unavailable: {seen}"))?.iter().map(addr).filter(|a| *a != 0).collect();
        for address in &seen { remember(orders, &*(*address as *const UObject), false, false); }
        let mut targets = Vec::new();
        orders.available.clear();
        orders.targets.retain(|_, t| t.identity.resolve().is_some());
        for (id, known) in &orders.targets {
            let Some(target) = known.identity.resolve() else { continue; };
            // Native NPC hostility also includes player deployables (a water
            // cooler was returned live). AI player combat targets characters.
            if !hostile_character(controller, body, target)? { continue; }
            if seen.contains(id) {
                let class = target.class().ok_or("target class unavailable")?.as_object().name();
                let display = class.trim_start_matches("NPC_Monster_").trim_start_matches("NPC_Soldier_").trim_start_matches("NPC_").trim_end_matches("_C").replace('_', " ");
                orders.available.push(json!({"selector": format!("addr:0x{id:X}"), "name": display}));
            }
            targets.push(Target { id: *id, position: location(target)?, perceived: seen.contains(id),
                threatens_self: known.self_attack, threatens_protected: known.protected_attack });
        }
        let action = orders.tracker.decide(&orders.def, &Observation { now: orders.started.elapsed().as_secs_f64(),
            position: location(body)?, anchor, alive, targets: &targets });
        let target = match action { Action::Attacking { target } => Some(target), _ => None };
        ueforge::behavior_tree::blackboard_set(controller, json!({"TargetActor": target.map(|t| format!("0x{t:X}")),
            "CombatMode": target.is_some(), "CanSeeTarget": target.is_some_and(|t| seen.contains(&t)), "TargetLocked": target.is_some()}).as_object().unwrap())?;
        let combat = reflect::get_fields(controller, &["IsInCombat".into()])?["IsInCombat"].as_bool().ok_or("native combat state unavailable")?;
        if combat != target.is_some() {
            reflect::call(controller, "Abiotic_AI_Controller_ParentBP_C", "BT_SetCombatState",
                json!({"State": target.is_some(), "SkipAggroAnimation": true}).as_object().unwrap())?;
        }
        orders.execution.apply(controller, tree, &action)?;
        orders.action = action;
        Ok(())
    }
}

fn tick(args: &Value) -> Result<Value, String> {
    let name = crate::ai_player::player_name(args)?;
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        let mut all = PLAYERS.lock();
        let orders = all.get_mut(&name).ok_or("AI player orders not active")?;
        // SAFETY: queued game-thread adapter.
        if let Err(error) = unsafe { update(&name, orders) } {
            orders.action = Action::Blocked { reason: error.clone() };
            if let Ok((controller, _)) = unsafe { session_controller(&name) } {
                unsafe { orders.execution.apply(controller, 0, &orders.action) }.map_err(|stop| format!("{error}; stop: {stop}"))?;
            }
            // A missing tree is failed initialization. Once initialized, an
            // unreachable destination is a visible blocked assignment, not a
            // reason to destroy a successfully spawned AI player.
            if orders.tree.is_none() { return Err(error); }
        }
        Ok(json!({"name": name, "definition": orders.def, "action": orders.action}))
    })
}

pub(crate) fn command(args: &Value) -> Result<Value, String> {
    let args = args.clone();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        let mut all = PLAYERS.lock();
        let names = modforge::ai_orders::recipients(&args, all.iter().map(|(name, orders)| (name.as_str(), &orders.def)))?;
        let command = args["command"].as_str().ok_or("command required")?;
        let mut changed = Vec::new();
        for name in names {
            let orders = all.get_mut(&name).unwrap();
            let mut def = orders.def.clone();
            match command {
                "follow" => {
                    let human = args["target"].as_str().filter(|t| !t.is_empty()).map(str::to_owned)
                        .or_else(|| unsafe { crate::nav::players() }.ok()?.into_iter().map(|(n,_)| n).next()).ok_or("no human available")?;
                    unsafe { crate::nav::player_character(&human)? };
                    def.assignment = Assignment::Follow { player: human };
                    if let Some(distance) = args["distance"].as_f64() { def.limits.follow_distance = distance; }
                }
                "hold" => {
                    let (_, pawn) = unsafe { session_controller(&name)? };
                    if pawn == 0 { return Err("AI player has no body".into()); }
                    let protected_player = match &def.assignment { Assignment::Follow { player } => Some(player.clone()), Assignment::Hold { protected_player, .. } => protected_player.clone() };
                    def.assignment = Assignment::Hold { position: unsafe { location(&*(pawn as *const UObject))? }, protected_player };
                }
                "attack" => {
                    let target = ueforge::selector::resolve(args["target"].as_str().ok_or("target selector required")?)?;
                    let (controller, pawn) = unsafe { session_controller(&name)? };
                    if pawn == 0 { return Err("AI player has no body".into()); }
                    if !unsafe { hostile_character(controller, &*(pawn as *const UObject), target)? } { return Err("attack target must be a living hostile character".into()); }
                    unsafe { remember(orders, target, false, false) };
                    orders.tracker.attack(target as *const UObject as u64);
                }
                "recall" => orders.tracker.recall(),
                "cancel_attack" => orders.tracker.cancel_attack(),
                _ => if !def.configure(command, &args)? { return Err(format!("unknown AI player command {command}")); },
            }
            def.limits.validate()?;
            let path = crate::ai_player::session_directory(&name)?.join("abiotic-orders.json");
            modforge::settings::save_atomic(&path, &def).map_err(|e| format!("save {name} orders: {e}"))?;
            orders.def = def;
            changed.push(name);
        }
        Ok(json!({"affected": changed}))
    })
}

pub(crate) fn register() {
    use ueforge::ops::{OpDef, OP_REGISTRY};
    OP_REGISTRY.register_many([
        OpDef::new("ai_player.command", "Set assignment, stance, limits, groups, attack, recall or cancel attack for selected AI players", "{player?: str, players?: [str], group?: str, all?: bool, command: str, target?: str, stance?: str, limits?: object, groups?: [str]}", command),
        OpDef::new("ai_player.orders", "Read AI player assignments, stance and current action", "{}", |_| Ok(snapshot())),
        OpDef::new("ai_player.order_tick", "Apply one shared AI player decision using native perception and melee", "{player?: str}", tick),
    ]);
}
