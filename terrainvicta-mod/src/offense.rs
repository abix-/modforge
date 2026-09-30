//! Offense mode: a siege from HOME. The game's councilor automation
//! button puts all the player's automated councilors on one enemy
//! nation at a time, working it down in the order the game's rules
//! reward, until it falls.
//!
//! At each mission phase start the game calls
//! TICouncilorState.SelectPermanentDefenseModeMission for every
//! councilor with automation on. For the player's councilors this
//! replaces it with one plan for all of them, made on the phase's first
//! call and kept for the rest (`plan`).
//!
//! The target nation (`siege_target`): the one besieged last phase
//! while it still has enemy control points in reach; else the nearest
//! (borders from HOME, TINationState.AdjacentNations, up to MAX_RING)
//! nation with control points of ENEMY_FACTIONS, the weakest of that
//! ring: where the councilors' best Crackdown or Purge chance is
//! highest. With no ENEMY_FACTIONS nation in range, any other faction's.
//!
//! The work, in STEPS order; within a step the councilor with the
//! highest value of the mission's attack stat first
//! (TIMissionTemplate.primaryAttackerStat: Espionage for Purge,
//! Investigation for Crackdown, Persuasion for Public Campaign), then
//! best chance; one Purge or Crackdown per control point:
//! - Purge a control point Crackdown has disabled: a disabled point
//!   counts TIMissionModifier_DisabledControlPoint (-10) against its own
//!   Purge defense, and each other disabled point of the same faction
//!   in the nation -5 more (TIMissionModifier_DisabledControlPoint).
//! - Purge a point not disabled yet when the chance is PURGE_NOW or
//!   better: capture now rather than crack down first.
//! - Crackdown a point not disabled yet (it also ends Defend Interests
//!   on it, TIControlPoint.ResolveCrackdownEffect).
//! - Purge a point not disabled yet.
//! - Public Campaign in the nation, for everyone left (it stacks,
//!   AIDoubleUpAllowed): public opinion is an attack modifier of Purge,
//!   Crackdown, Coup and Control Nation
//!   (TIMissionModifier_AttackerPopulationIdeology).
//!
//! Chances come from each mission's resolution method with no optional
//! bonus spent; a flat cost is charged as the mission screen does. The
//! assignment is the one the mission screen makes: an
//! AssignCouncilorToMission action through the faction's player. AI
//! councilors keep the game's own pick.

use std::collections::{HashMap, VecDeque};
use std::ffi::c_void;
use std::sync::Mutex;
use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{LogLevel, MonoObject, invoke_static, json_handle, log, owned_object};

const NS: &str = "PavonisInteractive.TerraInvicta";

/// The home nation the war is fought from.
const HOME: &str = "Ukraine";
/// Borders from HOME beyond which nothing counts.
const MAX_RING: u32 = 5;

/// The enemy: the Servants, and the Aliens (whose control points are
/// the Alien Administration's).
const ENEMY_FACTIONS: [&str; 2] = ["SubmitCouncil", "AlienCouncil"];

const PURGE: &str = "Purge";
const CRACKDOWN: &str = "Crackdown";
const CAMPAIGN: &str = "Propaganda";

/// The siege's steps in priority order: (step, mission, least chance
/// worth taking).
const STEPS: [(Step, &str, f64); 5] = [
    (Step::PurgeDisabled, PURGE, 0.33),
    (Step::PurgeNow, PURGE, PURGE_NOW),
    (Step::Crackdown, CRACKDOWN, 0.15),
    (Step::Purge, PURGE, 0.33),
    (Step::Campaign, CAMPAIGN, 0.0),
];

/// A Purge at this chance or better goes ahead of Crackdown: capture
/// now instead of cracking down first and purging a turn later.
const PURGE_NOW: f64 = 0.50;

#[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
enum Step {
    PurgeDisabled,
    PurgeNow,
    Crackdown,
    Purge,
    Campaign,
}

impl Step {
    fn name(self) -> &'static str {
        match self {
            Step::PurgeDisabled => "purge a disabled point",
            Step::PurgeNow => "purge now",
            Step::Crackdown => "crackdown",
            Step::Purge => "purge",
            Step::Campaign => "public campaign",
        }
    }
}

pub fn install() {
    match patch_prefix_ctx(
        &format!("{NS}.TICouncilorState"),
        "SelectPermanentDefenseModeMission",
        HookCtx::Instance,
        on_select,
    ) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            log(LogLevel::Info, "terrainvicta-mod: offense mode (siege) armed");
        }
        Err(e) => log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: offense mode patch failed: {e}"),
        ),
    }
    OP_REGISTRY.register(OpDef::new(
        "offense_preview",
        "The siege plan offense mode would make right now for the player's idle automated councilors, without assigning; as_phase_start: as the next phase start will see it (all automated councilors idle)",
        "{as_phase_start?: bool}",
        |args| {
            let as_phase_start = args.get("as_phase_start").and_then(Json::as_bool).unwrap_or(false);
            MAIN_QUEUE.run("offense_preview", Duration::from_secs(60), move || preview(as_phase_start))?
        },
    ));
}

// ---- game object helpers ----------------------------------------------

/// A field, or failing that a property getter.
fn member(obj: &MonoObject, name: &str) -> Result<Json, String> {
    obj.read_field(name)
        .or_else(|_| obj.invoke(&format!("get_{name}"), &json!([])))
}

fn member_object(obj: &MonoObject, name: &str) -> Result<Option<MonoObject>, String> {
    Ok(json_handle(&member(obj, name)?).map(owned_object))
}

fn call_object(obj: &MonoObject, method: &str, args: Json) -> Result<Option<MonoObject>, String> {
    Ok(json_handle(&obj.invoke(method, &args)?).map(owned_object))
}

/// The items of a managed list or array.
fn list(obj: &MonoObject) -> Result<Vec<MonoObject>, String> {
    let mut out = Vec::new();
    if let Ok(Json::Number(n)) = obj.invoke("get_Length", &json!([])) {
        for i in 0..n.as_i64().unwrap_or(0) {
            if let Some(item) = call_object(obj, "GetValue", json!([i]))? {
                out.push(item);
            }
        }
        return Ok(out);
    }
    for i in 0..obj.list_len_or_zero()? {
        if let Some(item) = obj.list_handle(i)?.map(owned_object) {
            out.push(item);
        }
    }
    Ok(out)
}

fn text(obj: &MonoObject, name: &str) -> String {
    member(obj, name)
        .ok()
        .and_then(|v| v.as_str().map(str::to_string))
        .unwrap_or_default()
}

fn flag(obj: &MonoObject, name: &str) -> bool {
    member(obj, name).ok().and_then(|v| v.as_bool()) == Some(true)
}

fn hash(obj: &MonoObject) -> Result<i64, String> {
    obj.invoke("GetHashCode", &json!([]))?
        .as_i64()
        .ok_or_else(|| "GetHashCode: not a number".to_string())
}

fn is_enemy(faction: &MonoObject) -> bool {
    ENEMY_FACTIONS.contains(&text(faction, "templateName").as_str())
}

fn players_faction(councilor: &MonoObject) -> Result<Option<MonoObject>, String> {
    let Some(faction) = member_object(councilor, "faction")? else {
        return Ok(None);
    };
    Ok(flag(&faction, "isActivePlayer").then_some(faction))
}

/// What the mission costs on `target`: its flat cost, or 0 for a
/// mission whose only cost is an optional bonus.
fn resources(template: &MonoObject, councilor: &MonoObject, target: &MonoObject) -> Result<f64, String> {
    let Some(cost) = member_object(template, "cost")? else {
        return Ok(0.0);
    };
    let ty = call_object(&cost, "GetType", json!([]))?.ok_or("cost has no type")?;
    if ty.invoke("get_Name", &json!([]))?.as_str() != Some("TIMissionCost_Flat") {
        return Ok(0.0);
    }
    cost.invoke(
        "GetCost",
        &json!([0.0, {"$handle": councilor.handle().0}, {"$handle": target.handle().0}]),
    )?
    .as_f64()
    .ok_or_else(|| "GetCost: not a number".to_string())
}

fn chance(template: &MonoObject, councilor: &MonoObject, target: &MonoObject, spend: f64) -> Result<f64, String> {
    let resolution = member_object(template, "resolutionMethod")?.ok_or("no resolution method")?;
    resolution
        .invoke(
            "GetSuccessChance",
            &json!([
                {"$handle": template.handle().0},
                {"$handle": councilor.handle().0},
                {"$handle": target.handle().0},
                spend,
                false
            ]),
        )?
        .as_f64()
        .ok_or_else(|| "GetSuccessChance: not a number".to_string())
}

/// The councilor's missions it can run now and afford, by dataName.
fn missions(councilor: &MonoObject, faction: &MonoObject) -> Result<HashMap<String, MonoObject>, String> {
    let possible = call_object(councilor, "GetPossibleMissionList", json!([true, false, true, null, false]))?
        .ok_or("no mission list")?;
    let mut out = HashMap::new();
    for m in list(&possible)? {
        let affordable = m.invoke(
            "CanAfford",
            &json!([{"$handle": faction.handle().0}, {"$handle": councilor.handle().0}]),
        )?;
        if affordable.as_bool() == Some(true) {
            out.insert(text(&m, "dataName"), m);
        }
    }
    Ok(out)
}

// ---- rings --------------------------------------------------------------

/// Borders from HOME for every nation within MAX_RING, by nation hash,
/// measured on the map: a walk from HOME's regions over neighbouring
/// regions (TIRegionState.AdjacentRegions) where only a step into a
/// different nation counts as a border. Nation to nation adjacency
/// (TINationState.AdjacentNations) is not used: a nation scattered
/// across the world, like the Alien Administration, would make every
/// nation any piece of it touches look like a neighbour of HOME.
fn rings() -> Result<HashMap<i64, u32>, String> {
    // AllNations is an array; AllExtantNations a lazy query the bridge
    // cannot index.
    let nations = json_handle(&invoke_static(&format!("{NS}.GameStateManager"), "AllNations", &json!([]))?)
        .map(owned_object)
        .ok_or("AllNations returned null")?;
    let home = list(&nations)?
        .into_iter()
        .find(|n| text(n, "displayName") == HOME && flag(n, "extant"))
        .ok_or_else(|| format!("no nation {HOME}"))?;
    let home_regions = member_object(&home, "regions")?.ok_or("home has no regions")?;
    // Borders crossed to reach each region (by hash); a 0-1 walk:
    // same-nation steps go to the front of the queue, border crossings
    // to the back.
    let mut region_cost: HashMap<i64, u32> = HashMap::new();
    let mut ring: HashMap<i64, u32> = HashMap::new();
    let mut queue: VecDeque<(MonoObject, u32)> = VecDeque::new();
    for r in list(&home_regions)? {
        region_cost.insert(hash(&r)?, 0);
        queue.push_back((r, 0));
    }
    while let Some((region, d)) = queue.pop_front() {
        if region_cost.get(&hash(&region)?).is_some_and(|&c| c < d) {
            continue;
        }
        let Some(nation) = member_object(&region, "nation")? else {
            continue;
        };
        let nation_hash = hash(&nation)?;
        let e = ring.entry(nation_hash).or_insert(d);
        *e = (*e).min(d);
        let Some(adjacent) = call_object(&region, "AdjacentRegions", json!([false]))? else {
            continue;
        };
        for next in list(&adjacent)? {
            let Some(next_nation) = member_object(&next, "nation")? else {
                continue;
            };
            let step = if hash(&next_nation)? == nation_hash { 0 } else { 1 };
            let cost = d + step;
            if cost > MAX_RING {
                continue;
            }
            let h = hash(&next)?;
            if region_cost.get(&h).is_none_or(|&c| cost < c) {
                region_cost.insert(h, cost);
                if step == 0 {
                    queue.push_front((next, cost));
                } else {
                    queue.push_back((next, cost));
                }
            }
        }
    }
    Ok(ring)
}

// ---- the plan -----------------------------------------------------------

/// One councilor's planned mission. Game objects are named by hash so
/// the plan outlives the handles it was made with.
#[derive(Clone)]
struct Planned {
    step: Step,
    mission: String,
    target: i64,
    target_name: String,
    nation: String,
    ring: u32,
    /// The councilor's value of the mission's attack stat
    /// (TIMissionTemplate.primaryAttackerStat).
    stat: i64,
    chance: f64,
    resources: f64,
}

/// The councilor's value of the stat `template` attacks with.
fn attack_stat(template: &MonoObject, councilor: &MonoObject) -> Result<i64, String> {
    let stat = template.invoke("get_primaryAttackerStat", &json!([]))?;
    let stat = match &stat {
        Json::String(s) => s.clone(),
        other => other.to_string(),
    };
    councilor
        .invoke("GetAttribute", &json!([stat, true, true, true, false, false, false]))?
        .as_i64()
        .ok_or_else(|| "GetAttribute: not a number".to_string())
}

/// This phase's plan: the game date it was made on, the besieged
/// nation, and the planned mission of each councilor it covered (None:
/// nothing worthwhile).
struct Plan {
    date: String,
    by_councilor: HashMap<i64, Option<Planned>>,
}

static PLAN: Mutex<Option<Plan>> = Mutex::new(None);

/// The nation being besieged, by hash; kept across phases while it
/// still has enemy control points in reach.
static SIEGE: Mutex<Option<i64>> = Mutex::new(None);

fn now() -> Result<String, String> {
    let date = json_handle(&invoke_static(&format!("{NS}.TITimeState"), "Now", &json!([]))?)
        .map(owned_object)
        .ok_or("TITimeState.Now returned null")?;
    Ok(date.invoke("ToString", &json!([]))?.as_str().unwrap_or_default().to_string())
}

/// How many of the faction's councilors are on each (mission dataName,
/// target hash) already.
fn taken(faction: &MonoObject) -> Result<HashMap<(String, i64), u32>, String> {
    let mut out = HashMap::new();
    let councilors = member_object(faction, "councilors")?.ok_or("no councilors")?;
    for c in list(&councilors)? {
        let Some(mission) = member_object(&c, "activeMission")? else {
            continue;
        };
        let Some(template) = call_object(&mission, "get_missionTemplate", json!([]))? else {
            continue;
        };
        if let Some(target) = member_object(&mission, "target")? {
            *out.entry((text(&template, "dataName"), hash(&target)?)).or_insert(0) += 1;
        }
    }
    Ok(out)
}

/// A (councilor, mission, target) the siege could use.
struct Option_ {
    councilor: i64,
    nation: i64,
    planned: Planned,
}

/// Every Purge and Crackdown option of `idle` councilors against
/// control points of other factions within MAX_RING, with
/// whether the owner is one of ENEMY_FACTIONS; and the Public Campaign
/// target and spend of each councilor by nation hash.
#[allow(clippy::type_complexity)]
fn options(
    idle: &[MonoObject],
    faction: &MonoObject,
    rings: &HashMap<i64, u32>,
) -> Result<(Vec<(Option_, bool)>, HashMap<(i64, i64), (MonoObject, f64)>), String> {
    let mut attacks = Vec::new();
    let mut campaigns = HashMap::new();
    for c in idle {
        let me = hash(c)?;
        let runnable = missions(c, faction)?;
        for (name, template) in &runnable {
            let is_attack = [PURGE, CRACKDOWN].contains(&name.as_str());
            if !is_attack && name != CAMPAIGN {
                continue;
            }
            let targets = call_object(template, "GetValidTargets", json!([{"$handle": c.handle().0}]))?
                .ok_or("no target list")?;
            for target in list(&targets)? {
                let Some(nation) = member_object(&target, "ref_nation")? else {
                    continue;
                };
                let nation_hash = hash(&nation)?;
                let Some(&ring) = rings.get(&nation_hash) else {
                    continue;
                };
                let spend = resources(template, c, &target)?;
                if name == CAMPAIGN {
                    campaigns.insert((me, nation_hash), (target, spend));
                    continue;
                }
                // The faction the attack hits: the point's owner.
                let Some(owner) = member_object(&target, "ref_faction")? else {
                    continue;
                };
                if flag(&owner, "isActivePlayer") {
                    continue;
                }
                let p = chance(template, c, &target, spend)?;
                let step = match name.as_str() {
                    PURGE if flag(&target, "benefitsDisabled") => Step::PurgeDisabled,
                    PURGE if p >= PURGE_NOW => Step::PurgeNow,
                    PURGE => Step::Purge,
                    _ => Step::Crackdown,
                };
                attacks.push((
                    Option_ {
                        councilor: me,
                        nation: nation_hash,
                        planned: Planned {
                            step,
                            mission: name.clone(),
                            target: hash(&target)?,
                            target_name: text(&target, "displayName"),
                            nation: text(&nation, "displayName"),
                            ring,
                            stat: attack_stat(template, c)?,
                            chance: p,
                            resources: spend,
                        },
                    },
                    is_enemy(&owner),
                ));
            }
        }
    }
    Ok((attacks, campaigns))
}

fn min_chance(step: Step) -> f64 {
    STEPS.iter().find(|(s, _, _)| *s == step).map(|(_, _, m)| *m).unwrap_or(0.0)
}

/// The nation to besiege: last phase's while it still has attack
/// options, else the nearest ring's weakest nation of ENEMY_FACTIONS
/// (best Crackdown or Purge chance), else of any other faction.
fn siege_target(attacks: &[(Option_, bool)]) -> Result<Option<i64>, String> {
    let current = *SIEGE.lock().map_err(|e| format!("siege: {e}"))?;
    if let Some(n) = current {
        if attacks.iter().any(|(o, _)| o.nation == n) {
            return Ok(Some(n));
        }
    }
    for enemies_only in [true, false] {
        // (ring, weakness) per nation.
        let mut nations: HashMap<i64, (u32, f64)> = HashMap::new();
        for (o, enemy) in attacks {
            if enemies_only && !enemy {
                continue;
            }
            if !matches!(o.planned.step, Step::Crackdown | Step::Purge | Step::PurgeNow | Step::PurgeDisabled) {
                continue;
            }
            let e = nations.entry(o.nation).or_insert((o.planned.ring, 0.0));
            e.1 = e.1.max(o.planned.chance);
        }
        let best = nations
            .into_iter()
            .min_by(|a, b| a.1.0.cmp(&b.1.0).then(b.1.1.total_cmp(&a.1.1)));
        if let Some((n, _)) = best {
            return Ok(Some(n));
        }
    }
    Ok(None)
}

/// Plan for every idle automated councilor of the faction: the siege
/// target's steps in order, best chance first, one Purge or Crackdown
/// per control point, Public Campaign for everyone left. With
/// `as_phase_start`, as a phase start sees it: every automated
/// councilor idle and no missions running (the preview's view).
fn make_plan(faction: &MonoObject, as_phase_start: bool) -> Result<HashMap<i64, Option<Planned>>, String> {
    let rings = rings()?;
    let mut used = if as_phase_start { HashMap::new() } else { taken(faction)? };
    let councilors = member_object(faction, "councilors")?.ok_or("no councilors")?;
    let mut idle = Vec::new();
    for c in list(&councilors)? {
        if flag(&c, "permanentDefenseMode") && (as_phase_start || member_object(&c, "activeMission")?.is_none()) {
            idle.push(c);
        }
    }
    let (attacks, campaigns) = options(&idle, faction, &rings)?;
    let target = siege_target(&attacks)?;
    *SIEGE.lock().map_err(|e| format!("siege: {e}"))? = target;
    let mut plan: HashMap<i64, Option<Planned>> = HashMap::new();
    let Some(target) = target else {
        return Ok(plan);
    };
    let mut here: Vec<Planned> = Vec::new();
    let mut who: Vec<i64> = Vec::new();
    for (o, _) in attacks.into_iter().filter(|(o, _)| o.nation == target) {
        if o.planned.chance >= min_chance(o.planned.step) {
            who.push(o.councilor);
            here.push(o.planned);
        }
    }
    // By step, then the councilor best at the mission's attack stat,
    // then chance.
    let mut order: Vec<usize> = (0..here.len()).collect();
    order.sort_by(|&a, &b| {
        here[a]
            .step
            .cmp(&here[b].step)
            .then(here[b].stat.cmp(&here[a].stat))
            .then(here[b].chance.total_cmp(&here[a].chance))
    });
    for i in order {
        let (c, p) = (who[i], &here[i]);
        if plan.contains_key(&c) {
            continue;
        }
        // One Purge or Crackdown per control point, whichever mission.
        let key = ("attack".to_string(), p.target);
        if used.contains_key(&key) {
            continue;
        }
        let exact = (p.mission.clone(), p.target);
        if used.contains_key(&exact) {
            continue;
        }
        used.insert(key, 1);
        used.insert(exact, 1);
        plan.insert(c, Some(p.clone()));
    }
    // Everyone left: Public Campaign in the besieged nation.
    for c in &idle {
        let me = hash(c)?;
        if plan.contains_key(&me) {
            continue;
        }
        let runnable = missions(c, faction)?;
        let planned = match (campaigns.get(&(me, target)), runnable.get(CAMPAIGN)) {
            (Some((t, spend)), Some(template)) => {
                let nation = member_object(t, "ref_nation")?.ok_or("no nation")?;
                Some(Planned {
                    step: Step::Campaign,
                    mission: CAMPAIGN.into(),
                    target: hash(t)?,
                    target_name: text(t, "displayName"),
                    nation: text(&nation, "displayName"),
                    ring: rings.get(&target).copied().unwrap_or(0),
                    stat: attack_stat(template, c)?,
                    chance: chance(template, c, t, *spend)?,
                    resources: *spend,
                })
            }
            _ => None,
        };
        plan.insert(me, planned);
    }
    Ok(plan)
}

/// This councilor's planned mission, making the phase's plan if needed
/// (a new game date, or a councilor the plan did not cover).
fn planned_for(councilor: &MonoObject, faction: &MonoObject) -> Result<Option<Planned>, String> {
    let me = hash(councilor)?;
    let date = now()?;
    let mut plan = PLAN.lock().map_err(|e| format!("plan: {e}"))?;
    let fresh = plan.as_ref().is_some_and(|p| p.date == date && p.by_councilor.contains_key(&me));
    if !fresh {
        *plan = Some(Plan { date, by_councilor: make_plan(faction, false)? });
    }
    Ok(plan.as_ref().and_then(|p| p.by_councilor.get(&me).cloned()).flatten())
}

fn assign(councilor: &MonoObject, faction: &MonoObject, planned: &Planned) -> Result<(), String> {
    let runnable = missions(councilor, faction)?;
    let template = runnable
        .get(&planned.mission)
        .ok_or_else(|| format!("{} no longer available", planned.mission))?;
    let targets = call_object(template, "GetValidTargets", json!([{"$handle": councilor.handle().0}]))?
        .ok_or("no target list")?;
    let target = list(&targets)?
        .into_iter()
        .find(|t| hash(t).is_ok_and(|h| h == planned.target))
        .ok_or_else(|| format!("{} is no longer a valid target", planned.target_name))?;
    let action = json_handle(&invoke_static(
        &format!("{NS}.Actions.AssignCouncilorToMission"),
        ".ctor",
        &json!([
            {"$handle": councilor.handle().0},
            {"$handle": template.handle().0},
            {"$handle": target.handle().0},
            planned.resources,
            false
        ]),
    )?)
    .map(owned_object)
    .ok_or("AssignCouncilorToMission constructor returned null")?;
    let player = call_object(faction, "get_playerControl", json!([]))?.ok_or("no player control")?;
    player.invoke("StartAction", &json!([{"$handle": action.handle().0}]))?;
    Ok(())
}

fn describe(p: &Planned) -> String {
    format!(
        "{}: {} on {} in {} (ring {}), stat {}, at {:.0}%",
        p.step.name(),
        p.mission,
        p.target_name,
        p.nation,
        p.ring,
        p.stat,
        p.chance * 100.0
    )
}

extern "C" fn on_select(ctx: *const c_void) -> i32 {
    let h = ctx as isize as i32;
    if h == 0 {
        return 0;
    }
    let councilor = owned_object(h);
    let faction = match players_faction(&councilor) {
        Ok(Some(f)) => f,
        Ok(None) => return 0,
        Err(e) => {
            log(LogLevel::Warn, &format!("terrainvicta-mod: offense mode: {e}"));
            return 0;
        }
    };
    let name = text(&councilor, "displayName");
    let run = || -> Result<String, String> {
        match planned_for(&councilor, &faction)? {
            Some(p) => {
                assign(&councilor, &faction, &p)?;
                Ok(describe(&p))
            }
            None => Ok("nothing to do in the besieged nation".into()),
        }
    };
    match run() {
        Ok(what) => {
            log(LogLevel::Info, &format!("terrainvicta-mod: offense mode {name}: {what}"));
            1
        }
        Err(e) => {
            // Fall back to the game's own pick rather than leave the
            // councilor idle on an error.
            log(LogLevel::Warn, &format!("terrainvicta-mod: offense mode {name}: {e}"));
            0
        }
    }
}

fn preview(as_phase_start: bool) -> Result<Json, String> {
    let control = json_handle(&invoke_static("GameControl", "get_control", &json!([]))?)
        .map(owned_object)
        .ok_or("GameControl.control is null")?;
    let faction = call_object(&control, "get_activePlayer", json!([]))?.ok_or("no active player")?;
    let plan = make_plan(&faction, as_phase_start)?;
    let councilors = member_object(&faction, "councilors")?.ok_or("no councilors")?;
    let mut out = Vec::new();
    for c in list(&councilors)? {
        let planned = plan.get(&hash(&c)?);
        out.push(json!({
            "councilor": text(&c, "displayName"),
            "automation_on": flag(&c, "permanentDefenseMode"),
            "planned": match planned {
                None => json!("not planned (automation off or already on a mission)"),
                Some(None) => json!("nothing to do in the besieged nation"),
                Some(Some(p)) => json!({
                    "step": p.step.name(),
                    "mission": p.mission,
                    "target": p.target_name,
                    "nation": p.nation,
                    "ring": p.ring,
                    "stat": p.stat,
                    "chance": p.chance,
                }),
            },
        }));
    }
    Ok(Json::Array(out))
}
