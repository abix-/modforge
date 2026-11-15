//! The game's events, read and sent where they wait for delivery. A
//! hook on DeliverEvents, which SimStep calls once per step with a
//! world's storage before any program runs:
//!
//! - logs every LootInteractionEvent about to be handed out: who loots
//!   (guest), what (host), and whether it is a loot-all;
//! - answers `loot.near`: the entities near the player and which
//!   loot-related components each has;
//! - sends `loot.all`: a LootInteractionEvent with lootAll and
//!   bypassInteraction set, as the game sends when you hold E;
//! - auto loot, on by default (`loot.auto`): 6 times a second, every
//!   ground item and dead enemy within 6 m gets that loot-all.
//!
//! Requests come in on the control-plane thread and run in the hook, on
//! the sim thread, so the game's maps are not read while it changes
//! them. Kiln found every place used here: docs/re/gameplay.md section
//! 1, docs/re/world.md, docs/re/time.md.

use modforge::hook::Hook;
use modforge::keen::{
    LookupKey, PendingEvents, find_in, find_in_exe, fixed_to_m, map_keys, registry,
};
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use std::collections::HashMap;
use std::sync::atomic::{AtomicBool, AtomicU32, AtomicU64, Ordering};
use std::sync::mpsc;
use std::sync::{Mutex, OnceLock};
use std::time::Duration;

/// Kiln's signatures (sigdb/symbols/server.d/gameplay.json and
/// server.json), the same in this build (tests/research_events.rs).
const SIM_STEP: &str = "40 55 53 56 41 55 48 8D AC 24 F8 FF FD FF B8 08 01 02 00 E8 ?? ?? ?? ??";
const SIM_STEP_CLOCK: &str = "48 8D 9E {storage.clock:d32} 4C 8B BC 24";
const SIM_STEP_PERIOD: &str = "48 8B 86 {storage.clock_period:d32} 48 85 D2 75 05";
const DELIVER_EVENTS: &str = "40 56 41 55 41 56 48 83 EC 40 48 8B 31 45 33 ED 4C 8B F1 4C 39 A9 {gameplay/storage.pending_count:d32} 0F 86";
const DELIVER_PENDING: &str = "4D 8B BE {gameplay/storage.pending:d32} 33 ED 4C 03 F9 41 39 6F {gameplay/buffer.used:d8} 0F 86";
const DELIVER_RECORD: &str = "4C 8B 9E {gameplay/events.map.cap:d32} 8B FD 49 03 3F 83 BE {gameplay/events.map.count:d32} 00 44 0F B6 67 {gameplay/record.size:d8} 44 8B 0F 74 ?? 48 8B 9E {gameplay/events.map.bits:d32}";
const EMIT_EVENT: &str =
    "48 83 EC 28 4C 8B D9 41 81 F8 00 01 00 00 73 ?? 45 8B D0 41 8B C0 41 83 E2 07";
const GET_COMPONENT: &str =
    "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 48 8D BA {world.storage:d32} 44 89";
const GET_ENTITY_TRANSFORM: &str =
    "48 89 5C 24 08 57 48 83 EC 20 48 8D B9 {world.storage:d32} 89 54 24 38 48 8D 8F";
/// Kiln's WorldDestroy (sigdb client.json): the storage's kind byte
/// (0 server, 1 prediction, 2 client).
const WORLD_DESTROY: &str = "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 40 80 39 03 48 8B F9 74 03 C6 01 03 4C 8D B1 {world.storage:d32} 45 33 FF 45 38 7E {storage.kind:d8} 0F 85";
/// Pending buffers are 0x18 bytes apart (Kiln's gameplay/buffer.stride).
const BUFFER_STRIDE: usize = 0x18;
/// The entity map in a storage (Kiln, docs/re/world.md "Entities").
const ENTITY_MAP: usize = 0x148;
/// How far into SimStep its scoped signatures look.
const SIM_STEP_SCOPE: usize = 8192;
/// The player in single player (guest of the game's own loot events).
const PLAYER: u32 = 1;

const LOOT_EVENT: &str = "keen::ecs::LootInteractionEvent";
const ACCEPT_EVENT: &str = "keen::ecs::AcceptOfferedInteractionEvent";
const OFFER_COMPONENT: &str = "keen::ecs::InteractionOfferRuntime";

type DeliverFn = unsafe extern "system" fn(usize) -> usize;
type EmitFn = unsafe extern "system" fn(usize, u32, u32, u16) -> *mut u8;
type GetComponentFn =
    unsafe extern "system" fn(*mut [usize; 2], usize, u32, u32) -> *mut [usize; 2];
type GetTransformFn = unsafe extern "system" fn(usize, u32) -> *const i64;

/// An interaction event's hash, size and field offsets, from the type
/// tables.
struct EventLayout {
    hash: u32,
    size: u32,
    guest: usize,
    host: usize,
    offer: usize,
}

/// The loot event: an interaction event with lootAll and
/// bypassInteraction.
struct LootLayout {
    ev: EventLayout,
    loot_all: usize,
    bypass: usize,
}

/// The corpse's offer (InteractionOfferRuntime): its id and whether it
/// is switched off.
struct OfferLayout {
    hash: u32,
    offer: usize,
    disabled: usize,
}

/// One corpse on its way to the bag, as kiln-auto-loot's VisitTable:
/// first seen, then opened (the accept, as pressing E), then looted.
struct Visit {
    first: u64,
    opened: bool,
}

struct Armed {
    hook: Hook<DeliverFn>,
    pending: PendingEvents,
    kind: usize,
    world_storage: usize,
    clock: usize,
    clock_period: usize,
    emit: EmitFn,
    get_component: GetComponentFn,
    get_transform: GetTransformFn,
    loot: LootLayout,
    accept: EventLayout,
    offer: OfferLayout,
    /// (name, hash) of the components `loot.near` looks for.
    components: Vec<(String, u32)>,
    /// What auto loot takes, as kiln-auto-loot finds it
    /// (src/Server/LootLoop.cs): a ground item has PickupItem and no
    /// Inventory; a dead enemy has DisableColliderModeChanges and an
    /// Inventory. Chests are left alone, so the player's own storage
    /// is never emptied.
    pickup_item: u32,
    inventory: u32,
    dead_marker: u32,
}

enum Request {
    Near {
        radius: f64,
        reply: mpsc::Sender<Json>,
    },
    LootAll {
        host: u32,
        reply: mpsc::Sender<Json>,
    },
}

static ARMED: OnceLock<Armed> = OnceLock::new();
static REQUESTS: Mutex<Vec<Request>> = Mutex::new(Vec::new());
static STEPS: AtomicU64 = AtomicU64::new(0);
static LOOT_SEEN: AtomicU64 = AtomicU64::new(0);
static LOOT_SENT: AtomicU64 = AtomicU64::new(0);
static FAULTS: AtomicU64 = AtomicU64::new(0);
static SERVER_STEPS: AtomicU64 = AtomicU64::new(0);
/// Auto loot on, and its radius in meters (f64 bits).
static AUTO: AtomicBool = AtomicBool::new(true);
static AUTO_RADIUS: AtomicU64 = AtomicU64::new(0x4018_0000_0000_0000); // 6.0
/// The program id the game's own loot events carry, once one is seen.
static LOOT_PROGRAM: AtomicU32 = AtomicU32::new(u32::MAX);
/// The slowest auto-loot scan so far, in microseconds.
static SCAN_WORST_US: AtomicU64 = AtomicU64::new(0);
/// Host -> server step it was last sent, so a pile is sent once per
/// [`RESEND_STEPS`].
static SENT_AT: Mutex<Option<HashMap<u32, u64>>> = Mutex::new(None);
/// Corpses seen and not looted yet.
static VISITS: Mutex<Option<HashMap<u32, Visit>>> = Mutex::new(None);
/// The pending buffer index (<< 16) and program of the last send.
static LAST_BUFFER: AtomicU64 = AtomicU64::new(u64::MAX);
/// The entities near the player, from the last full scan.
static NEAR: Mutex<Vec<u32>> = Mutex::new(Vec::new());
/// The slowest quick check so far, in microseconds.
static CHECK_WORST_US: AtomicU64 = AtomicU64::new(0);
/// The near list reaches this far past the loot radius.
const NEAR_EXTRA_M: f64 = 15.0;
/// The near list is checked 6 times a second (every 10 steps).
const CHECK_STEPS: u64 = 10;
/// The full scan for the near list runs once a second (60 steps).
const SCAN_STEPS: u64 = 60;
/// A host is sent again after 10 s if it is still there.
const RESEND_STEPS: u64 = 600;
/// At most this many loot-alls per scan, as kiln-auto-loot's budget.
const SENDS_PER_SCAN: usize = 4;

fn value(values: &[(String, u64)], name: &str) -> Result<usize, String> {
    values
        .iter()
        .find(|(n, _)| n == name)
        .map(|(_, v)| *v as usize)
        .ok_or_else(|| format!("no {name}"))
}

/// A type by full name: (hash, size, field offset by name).
#[allow(clippy::type_complexity)]
fn type_fields(
    name: &str,
) -> Result<(u32, u32, impl Fn(&str) -> Result<usize, String> + '_), String> {
    let reg = registry()?;
    let ty = reg
        .get_by_name(LookupKey::Qualified(name))
        .ok_or_else(|| format!("no type {name}"))?;
    let field = move |f: &str| {
        ty.struct_fields
            .get(f)
            .map(|x| x.data_offset as usize)
            .ok_or_else(|| format!("{name} has no {f}"))
    };
    Ok((ty.qualified_hash, ty.size, field))
}

fn loot_layout() -> Result<LootLayout, String> {
    let (hash, size, field) = type_fields(LOOT_EVENT)?;
    Ok(LootLayout {
        ev: EventLayout {
            hash,
            size,
            guest: field("guestId")?,
            host: field("hostId")?,
            offer: field("offerId")?,
        },
        loot_all: field("lootAll")?,
        bypass: field("bypassInteraction")?,
    })
}

fn accept_layout() -> Result<EventLayout, String> {
    let (hash, size, field) = type_fields(ACCEPT_EVENT)?;
    Ok(EventLayout {
        hash,
        size,
        guest: field("guestEntityId")?,
        host: field("hostEntityId")?,
        offer: field("offerId")?,
    })
}

fn offer_layout() -> Result<OfferLayout, String> {
    let (hash, _, field) = type_fields(OFFER_COMPONENT)?;
    Ok(OfferLayout {
        hash,
        offer: field("offerId")?,
        disabled: field("isDisabled")?,
    })
}

/// The server-side components whose names say loot, pickup,
/// interaction or inventory.
fn loot_components() -> Result<Vec<(String, u32)>, String> {
    let reg = registry()?;
    Ok(reg
        .iter()
        .filter(|t| {
            let n = t.qualified_name.as_str();
            n.starts_with("keen::ecs::")
                && ["Loot", "Pickup", "Interaction", "Inventory"]
                    .iter()
                    .any(|w| n.contains(w))
                && t.inner_type
                    .and_then(|i| reg.get(i))
                    .is_some_and(|p| p.qualified_name == "keen::ecs::Component")
        })
        .map(|t| (t.name.clone(), t.qualified_hash))
        .collect())
}

/// A component's hash by its short name (`PickupItem`).
fn component_hash(name: &str) -> Result<u32, String> {
    let reg = registry()?;
    reg.iter()
        .find(|t| {
            t.name == name
                && t.inner_type
                    .and_then(|i| reg.get(i))
                    .is_some_and(|p| p.qualified_name == "keen::ecs::Component")
        })
        .map(|t| t.qualified_hash)
        .ok_or_else(|| format!("no component {name}"))
}

impl Armed {
    /// Auto loot: every ground item and dead enemy within the radius
    /// gets a loot-all, as holding E does.
    /// The entities within [`NEAR_EXTRA_M`] past the radius: the whole
    /// entity map walked once a second, so the quick checks between
    /// look at a short list. A dying enemy is already on it.
    unsafe fn refresh_near(&self, storage: usize) {
        let started = std::time::Instant::now();
        let radius = f64::from_bits(AUTO_RADIUS.load(Ordering::Relaxed)) + NEAR_EXTRA_M;
        let world = storage - self.world_storage;
        // SAFETY: on the sim thread before delivery.
        let near: Vec<u32> = unsafe {
            let Some(me) = self.position(world, PLAYER) else {
                return;
            };
            map_keys(storage + ENTITY_MAP)
                .into_iter()
                .filter(|id| {
                    *id != PLAYER
                        && self.position(world, *id).is_some_and(|p| {
                            (p[0] - me[0]).powi(2) + (p[1] - me[1]).powi(2) + (p[2] - me[2]).powi(2)
                                <= radius * radius
                        })
                })
                .collect()
        };
        *NEAR.lock().unwrap() = near;
        let us = started.elapsed().as_micros() as u64;
        if us > SCAN_WORST_US.fetch_max(us, Ordering::Relaxed) {
            modforge::log!("auto loot: slowest full scan so far {us} us");
        }
    }

    unsafe fn auto_loot(&self, storage: usize, step: u64) {
        let started = std::time::Instant::now();
        let radius = f64::from_bits(AUTO_RADIUS.load(Ordering::Relaxed));
        let world = storage - self.world_storage;
        let near = NEAR.lock().unwrap().clone();
        let mut sent_at = SENT_AT.lock().unwrap();
        let sent_at = sent_at.get_or_insert_with(HashMap::new);
        sent_at.retain(|_, at| step - *at < RESEND_STEPS);
        let mut visits = VISITS.lock().unwrap();
        let visits = visits.get_or_insert_with(HashMap::new);
        visits.retain(|_, v| step - v.first < RESEND_STEPS);
        // SAFETY: on the sim thread before delivery.
        unsafe {
            let Some(me) = self.position(world, PLAYER) else {
                return;
            };
            let mut sent = 0;
            for id in near {
                if sent_at.contains_key(&id) {
                    continue;
                }
                let Some(p) = self.position(world, id) else {
                    continue;
                };
                let d2 = (p[0] - me[0]).powi(2) + (p[1] - me[1]).powi(2) + (p[2] - me[2]).powi(2);
                if d2 > radius * radius {
                    continue;
                }
                let inventory = self.has(world, self.inventory, id);
                let ground = !inventory && self.has(world, self.pickup_item, id);
                let corpse = inventory && self.has(world, self.dead_marker, id);
                if !ground && !corpse {
                    continue;
                }
                if corpse {
                    // kiln-auto-loot's container steps: open it as E
                    // does, then loot-all in the next check.
                    let v = visits.entry(id).or_insert(Visit {
                        first: step,
                        opened: false,
                    });
                    if !v.opened {
                        if let Some((offer, true)) = self.offer_of(world, id) {
                            let r = self.accept(storage, id, offer);
                            modforge::log!("auto loot open corpse {id}: {r}");
                            // a failed open is tried again next check
                            v.opened = r.get("error").is_none();
                            sent += 1;
                            if sent >= SENDS_PER_SCAN {
                                break;
                            }
                            continue;
                        }
                    }
                    visits.remove(&id);
                }
                let r = self.loot_all(storage, id);
                modforge::log!(
                    "auto loot {} {id} at {:.1} m: {r}",
                    if ground { "item" } else { "corpse" },
                    d2.sqrt()
                );
                if r.get("error").is_some() {
                    continue; // tried again at the next check
                }
                sent_at.insert(id, step);
                sent += 1;
                if sent >= SENDS_PER_SCAN {
                    break;
                }
            }
        }
        let us = started.elapsed().as_micros() as u64;
        if us > CHECK_WORST_US.fetch_max(us, Ordering::Relaxed) {
            modforge::log!("auto loot: slowest check so far {us} us");
        }
    }

    /// The ECS time now: clock period times clock (Kiln,
    /// docs/re/time.md).
    unsafe fn now(&self, storage: usize) -> i64 {
        // SAFETY: a live storage; offsets from SimStep's own code.
        unsafe {
            let period = *((storage + self.clock_period) as *const i64);
            let clock = i64::from(*((storage + self.clock) as *const u32));
            period * clock
        }
    }

    unsafe fn position(&self, world: usize, entity: u32) -> Option<[f64; 3]> {
        // SAFETY: the game's GetEntityTransform on a live world.
        let t = unsafe { (self.get_transform)(world, entity) };
        if t.is_null() {
            return None;
        }
        // SAFETY: a WorldTransform starts with three 32.32 i64s.
        Some(unsafe { [fixed_to_m(*t), fixed_to_m(*t.add(1)), fixed_to_m(*t.add(2))] })
    }

    unsafe fn has(&self, world: usize, hash: u32, entity: u32) -> bool {
        let mut out = [0usize; 2];
        // SAFETY: the game's GetComponent(out, world, hash, entity).
        unsafe { (self.get_component)(&mut out, world, hash, entity) };
        out[0] != 0
    }

    unsafe fn near(&self, storage: usize, radius: f64) -> Json {
        let world = storage - self.world_storage;
        // SAFETY: on the sim thread before delivery.
        unsafe {
            let Some(me) = self.position(world, PLAYER) else {
                return json!({"error": "no player transform"});
            };
            let mut rows = Vec::new();
            let ids = map_keys(storage + ENTITY_MAP);
            for id in &ids {
                let Some(p) = self.position(world, *id) else {
                    continue;
                };
                let d = ((p[0] - me[0]).powi(2) + (p[1] - me[1]).powi(2) + (p[2] - me[2]).powi(2))
                    .sqrt();
                if d > radius || *id == PLAYER {
                    continue;
                }
                let has: Vec<&str> = self
                    .components
                    .iter()
                    .filter(|(_, h)| self.has(world, *h, *id))
                    .map(|(n, _)| n.as_str())
                    .collect();
                if !has.is_empty() {
                    rows.push(
                        json!({"id": id, "distance": (d * 10.0).round() / 10.0, "components": has}),
                    );
                }
            }
            json!({"player": me, "entities": ids.len(), "near": rows})
        }
    }

    unsafe fn loot_all(&self, storage: usize, host: u32) -> Json {
        let flags = [self.loot.loot_all, self.loot.bypass];
        // SAFETY: on the sim thread before delivery.
        match unsafe { self.send(storage, &self.loot.ev, host, 0, &flags) } {
            Ok((program, time)) => {
                LOOT_SENT.fetch_add(1, Ordering::Relaxed);
                json!({"sent": true, "host": host, "program": program, "time": time})
            }
            Err(e) => json!({"error": e}),
        }
    }

    /// Opens host's offer, as pressing E does.
    unsafe fn accept(&self, storage: usize, host: u32, offer: u32) -> Json {
        // SAFETY: on the sim thread before delivery.
        match unsafe { self.send(storage, &self.accept, host, offer, &[]) } {
            Ok((program, time)) => {
                json!({"opened": true, "host": host, "offer": offer, "program": program, "time": time})
            }
            Err(e) => json!({"error": e}),
        }
    }

    /// host's InteractionOfferRuntime: (offer id, usable), None when it
    /// has none.
    unsafe fn offer_of(&self, world: usize, host: u32) -> Option<(u32, bool)> {
        let mut out = [0usize; 2];
        // SAFETY: the game's GetComponent; the data is offer.hash's type.
        unsafe {
            (self.get_component)(&mut out, world, self.offer.hash, host);
            let data = out[0] as *const u8;
            if data.is_null() {
                return None;
            }
            let id = *(data.add(self.offer.offer) as *const u32);
            Some((id, *data.add(self.offer.disabled) == 0))
        }
    }

    /// Sends one interaction event from the player to host: time,
    /// guest, host, offer, and each byte in `flags` set to 1. Returns
    /// (program, time).
    unsafe fn send(
        &self,
        storage: usize,
        ev: &EventLayout,
        host: u32,
        offer: u32,
        flags: &[usize],
    ) -> Result<(u16, i64), &'static str> {
        // SAFETY: on the sim thread before delivery.
        unsafe {
            // Send from a buffer that already holds a program's events,
            // with that program's id, as that program would: the
            // program that sends the game's own loot events when it is
            // known, else the first buffer with events.
            let wanted = LOOT_PROGRAM.load(Ordering::Relaxed);
            let mut target = None;
            let buffers = *((storage + self.pending.pending) as *const usize);
            let count = *((storage + self.pending.pending_count) as *const u64) as usize;
            for i in 0..count {
                let buf = buffers + i * BUFFER_STRIDE;
                if *((buf + self.pending.used) as *const u32) >= 8 {
                    let first = *(buf as *const usize);
                    let program = *((first + 4) as *const u16);
                    if u32::from(program) == wanted {
                        target = Some((buf, program));
                        break;
                    }
                    target.get_or_insert((buf, program));
                }
            }
            // No program sent anything this step: the buffer and
            // program used last time, as that program would send.
            let last = LAST_BUFFER.load(Ordering::Relaxed);
            if target.is_none() && last != u64::MAX && ((last >> 16) as usize) < count {
                target = Some((buffers + (last >> 16) as usize * BUFFER_STRIDE, last as u16));
            }
            let Some((buf, program)) = target else {
                return Err("no event buffer with events this step");
            };
            LAST_BUFFER.store(
                (((buf - buffers) / BUFFER_STRIDE) as u64) << 16 | u64::from(program),
                Ordering::Relaxed,
            );
            let e = (self.emit)(buf, ev.hash, ev.size, program);
            if e.is_null() {
                return Err("event buffer full");
            }
            let now = self.now(storage);
            *(e as *mut i64) = now;
            *(e.add(ev.guest) as *mut u32) = PLAYER;
            *(e.add(ev.host) as *mut u32) = host;
            *(e.add(ev.offer) as *mut u32) = offer;
            for f in flags {
                *e.add(*f) = 1;
            }
            Ok((program, now))
        }
    }
}

unsafe extern "system" fn on_deliver(storage: usize) -> usize {
    let Some(a) = ARMED.get() else {
        return 0;
    };
    STEPS.fetch_add(1, Ordering::Relaxed);
    let read = modforge::seh::guard(|| {
        // SAFETY: SimStep hands DeliverEvents a live storage on the sim
        // thread, before delivery; everything here is fault-guarded.
        unsafe {
            let kind = *((storage + a.kind) as *const u8);
            if kind == 0 {
                let requests = std::mem::take(&mut *REQUESTS.lock().unwrap());
                for r in requests {
                    match r {
                        Request::Near { radius, reply } => {
                            let _ = reply.send(a.near(storage, radius));
                        }
                        Request::LootAll { host, reply } => {
                            let _ = reply.send(a.loot_all(storage, host));
                        }
                    }
                }
                let step = SERVER_STEPS.fetch_add(1, Ordering::Relaxed);
                if AUTO.load(Ordering::Relaxed) {
                    if step.is_multiple_of(SCAN_STEPS) {
                        a.refresh_near(storage);
                    }
                    if step.is_multiple_of(CHECK_STEPS) {
                        a.auto_loot(storage, step);
                    }
                }
            }
            a.pending.each(storage, |hash, data, size| {
                let ev = &a.loot.ev;
                if hash != ev.hash || size <= a.loot.bypass {
                    return;
                }
                LOOT_SEEN.fetch_add(1, Ordering::Relaxed);
                let u32_at = |o: usize| *(data.add(o) as *const u32);
                let header = data.sub(8);
                let program = *(header.add(4) as *const u16);
                if u32_at(ev.guest) == PLAYER && *data.add(a.loot.bypass) == 1 {
                    LOOT_PROGRAM.store(u32::from(program), Ordering::Relaxed);
                }
                modforge::log!(
                    "loot event (world kind {kind}): guest {} host {} offer {} lootAll {} bypass {} program {} time {} now {}",
                    u32_at(ev.guest),
                    u32_at(ev.host),
                    u32_at(ev.offer),
                    *data.add(a.loot.loot_all),
                    *data.add(a.loot.bypass),
                    program,
                    *(data as *const i64),
                    a.now(storage)
                );
                // What the host is, so the game's own hold-E picks can
                // be set against what auto loot takes.
                if kind == 0 {
                    let world = storage - a.world_storage;
                    let host = u32_at(ev.host);
                    let has: Vec<&str> = a
                        .components
                        .iter()
                        .filter(|(_, h)| a.has(world, *h, host))
                        .map(|(n, _)| n.as_str())
                        .collect();
                    let inventory = a.has(world, a.inventory, host);
                    let taken = if !inventory && a.has(world, a.pickup_item, host) {
                        "item"
                    } else if inventory && a.has(world, a.dead_marker, host) {
                        "corpse"
                    } else {
                        "NOT TAKEN"
                    };
                    modforge::log!("loot host {host}: auto loot {taken}; components {has:?}");
                }
            });
        }
    });
    if read.is_err() {
        FAULTS.fetch_add(1, Ordering::Relaxed);
    }
    modforge::call_original!(a.hook, storage).unwrap_or(0)
}

fn arm() -> Result<(), String> {
    let (sim_step, _) = find_in_exe(SIM_STEP)?;
    let scope = Some((sim_step, SIM_STEP_SCOPE));
    let (_, v) = find_in(SIM_STEP_CLOCK, scope)?;
    let clock = value(&v, "storage.clock")?;
    let (_, v) = find_in(SIM_STEP_PERIOD, scope)?;
    let clock_period = value(&v, "storage.clock_period")?;
    let (deliver, v) = find_in_exe(DELIVER_EVENTS)?;
    let pending_count = value(&v, "gameplay/storage.pending_count")?;
    let (_, v) = find_in_exe(DELIVER_PENDING)?;
    let pending = value(&v, "gameplay/storage.pending")?;
    let used = value(&v, "gameplay/buffer.used")?;
    let (_, v) = find_in_exe(DELIVER_RECORD)?;
    let record_size = value(&v, "gameplay/record.size")?;
    let (_, v) = find_in_exe(WORLD_DESTROY)?;
    let kind = value(&v, "storage.kind")?;
    let world_storage = value(&v, "world.storage")?;
    let (emit, _) = find_in_exe(EMIT_EVENT)?;
    let (get_component, _) = find_in_exe(GET_COMPONENT)?;
    let (get_transform, _) = find_in_exe(GET_ENTITY_TRANSFORM)?;
    let loot = loot_layout()?;
    let accept = accept_layout()?;
    let offer = offer_layout()?;
    let components = loot_components()?;
    let pickup_item = component_hash("PickupItem")?;
    let inventory = component_hash("Inventory")?;
    let dead_marker = component_hash("DisableColliderModeChanges")?;
    // SAFETY: DELIVER_EVENTS matches the entry of the game's
    // DeliverEvents(storage), a normal x64 function.
    let hook = unsafe { Hook::<DeliverFn>::install("DeliverEvents", deliver, on_deliver) }
        .map_err(|e| format!("{e:#}"))?;
    // SAFETY: each address is the entry of the game function its
    // signature names, with the ABI Kiln documents.
    let (emit, get_component, get_transform) = unsafe {
        (
            std::mem::transmute::<usize, EmitFn>(emit),
            std::mem::transmute::<usize, GetComponentFn>(get_component),
            std::mem::transmute::<usize, GetTransformFn>(get_transform),
        )
    };
    let armed = Armed {
        hook,
        pending: PendingEvents {
            pending,
            pending_count,
            stride: BUFFER_STRIDE,
            used,
            record_size,
        },
        kind,
        world_storage,
        clock,
        clock_period,
        emit,
        get_component,
        get_transform,
        loot,
        accept,
        offer,
        components,
        pickup_item,
        inventory,
        dead_marker,
    };
    modforge::log!(
        "events: DeliverEvents hooked at {deliver:#x}, {:?}, kind +{kind:#x}, world.storage {world_storage:#x}, clock +{clock:#x}, period +{clock_period:#x}, loot hash {:#x}, {} components watched",
        armed.pending,
        armed.loot.ev.hash,
        armed.components.len()
    );
    ARMED.set(armed).map_err(|_| "already armed".to_string())?;
    modforge::shutdown::SHUTDOWN_REGISTRY
        .record("events", "unhook DeliverEvents".into(), 0, || {
            if let Some(a) = ARMED.get() {
                // SAFETY: disabling the detour this module enabled.
                let _ = unsafe { a.hook.detour().disable() };
            }
        })
        .keep();
    Ok(())
}

/// Queue a request for the next server step and wait for its answer.
fn ask(make: impl FnOnce(mpsc::Sender<Json>) -> Request) -> Result<Json, String> {
    if ARMED.get().is_none() {
        return Err("DeliverEvents is not hooked".into());
    }
    let (tx, rx) = mpsc::channel();
    REQUESTS.lock().unwrap().push(make(tx));
    rx.recv_timeout(Duration::from_secs(5))
        .map_err(|_| "no server step answered in 5 s (world not running?)".to_string())
}

/// Hooks DeliverEvents when every signature matches; logs why not
/// otherwise. Adds `events.status`, `loot.near` and `loot.all`.
pub fn register() {
    if let Err(e) = arm() {
        modforge::log!("events: not hooked: {e}");
    }
    OP_REGISTRY.register_many([
        OpDef::new(
            "events.status",
            "read-only: whether DeliverEvents is hooked, steps seen, loot events seen and sent",
            "",
            |_| {
                Ok(json!({
                    "hooked": ARMED.get().is_some(),
                    "steps": STEPS.load(Ordering::Relaxed),
                    "loot_events": LOOT_SEEN.load(Ordering::Relaxed),
                    "loot_sent": LOOT_SENT.load(Ordering::Relaxed),
                    "faults": FAULTS.load(Ordering::Relaxed),
                }))
            },
        ),
        OpDef::new(
            "loot.near",
            "read-only: entities within radius (default 15 m) of the player with their loot-related components",
            "radius?",
            |args| {
                let radius = args["radius"].as_f64().unwrap_or(15.0);
                ask(|reply| Request::Near { radius, reply })
            },
        ),
        OpDef::new(
            "loot.all",
            "send a loot-all LootInteractionEvent from the player to host, as holding E does",
            "host",
            |args| {
                let host = args["host"].as_u64().ok_or("host missing")? as u32;
                ask(|reply| Request::LootAll { host, reply })
            },
        ),
        OpDef::new(
            "loot.auto",
            "auto loot: on (true/false) and radius in meters; with no args, the current setting",
            "on?, radius?",
            |args| {
                if let Some(on) = args["on"].as_bool() {
                    AUTO.store(on, Ordering::Relaxed);
                }
                if let Some(r) = args["radius"].as_f64() {
                    AUTO_RADIUS.store(r.clamp(1.0, 30.0).to_bits(), Ordering::Relaxed);
                }
                Ok(json!({
                    "on": AUTO.load(Ordering::Relaxed),
                    "radius": f64::from_bits(AUTO_RADIUS.load(Ordering::Relaxed)),
                    "server_steps": SERVER_STEPS.load(Ordering::Relaxed),
                    "loot_sent": LOOT_SENT.load(Ordering::Relaxed),
                    "loot_program": LOOT_PROGRAM.load(Ordering::Relaxed),
                    "slowest_scan_us": SCAN_WORST_US.load(Ordering::Relaxed),
                    "slowest_check_us": CHECK_WORST_US.load(Ordering::Relaxed),
                }))
            },
        ),
    ]);
}
