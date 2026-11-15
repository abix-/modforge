//! The game's events, read where they wait for delivery. A hook on
//! DeliverEvents, which SimStep calls once per step with a world's
//! storage before any program runs, logs every LootInteractionEvent it
//! is about to hand out: who loots (guest), what (host), and whether it
//! is a loot-all. Kiln found the place: docs/re/gameplay.md section 1.

use modforge::hook::Hook;
use modforge::keen::{LookupKey, PendingEvents, find_in_exe, registry};
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::json;
use std::sync::OnceLock;
use std::sync::atomic::{AtomicU64, Ordering};

/// Kiln's signatures (sigdb/symbols/server.d/gameplay.json), the same
/// in this build (tests/research_events.rs).
const DELIVER_EVENTS: &str = "40 56 41 55 41 56 48 83 EC 40 48 8B 31 45 33 ED 4C 8B F1 4C 39 A9 {gameplay/storage.pending_count:d32} 0F 86";
const DELIVER_PENDING: &str = "4D 8B BE {gameplay/storage.pending:d32} 33 ED 4C 03 F9 41 39 6F {gameplay/buffer.used:d8} 0F 86";
const DELIVER_RECORD: &str = "4C 8B 9E {gameplay/events.map.cap:d32} 8B FD 49 03 3F 83 BE {gameplay/events.map.count:d32} 00 44 0F B6 67 {gameplay/record.size:d8} 44 8B 0F 74 ?? 48 8B 9E {gameplay/events.map.bits:d32}";
/// Kiln's WorldDestroy (sigdb client.json): the world's storage and
/// the storage's kind byte (0 server, 1 prediction, 2 client).
const WORLD_DESTROY: &str = "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 40 80 39 03 48 8B F9 74 03 C6 01 03 4C 8D B1 {world.storage:d32} 45 33 FF 45 38 7E {storage.kind:d8} 0F 85";
/// Pending buffers are 0x18 bytes apart (Kiln's gameplay/buffer.stride).
const BUFFER_STRIDE: usize = 0x18;

const LOOT_EVENT: &str = "keen::ecs::LootInteractionEvent";

type DeliverFn = unsafe extern "system" fn(usize) -> usize;

/// The loot event's hash and field offsets, from the type tables.
struct LootLayout {
    hash: u32,
    guest: usize,
    host: usize,
    offer: usize,
    loot_all: usize,
    bypass: usize,
}

struct Armed {
    hook: Hook<DeliverFn>,
    pending: PendingEvents,
    kind: usize,
    loot: LootLayout,
}

static ARMED: OnceLock<Armed> = OnceLock::new();
static STEPS: AtomicU64 = AtomicU64::new(0);
static LOOT_SEEN: AtomicU64 = AtomicU64::new(0);
static FAULTS: AtomicU64 = AtomicU64::new(0);

fn value(values: &[(String, u64)], name: &str) -> Result<usize, String> {
    values
        .iter()
        .find(|(n, _)| n == name)
        .map(|(_, v)| *v as usize)
        .ok_or_else(|| format!("no {name}"))
}

fn loot_layout() -> Result<LootLayout, String> {
    let reg = registry()?;
    let ty = reg
        .get_by_name(LookupKey::Qualified(LOOT_EVENT))
        .ok_or_else(|| format!("no type {LOOT_EVENT}"))?;
    let field = |name: &str| {
        ty.struct_fields
            .get(name)
            .map(|f| f.data_offset as usize)
            .ok_or_else(|| format!("{LOOT_EVENT} has no {name}"))
    };
    Ok(LootLayout {
        hash: ty.qualified_hash,
        guest: field("guestId")?,
        host: field("hostId")?,
        offer: field("offerId")?,
        loot_all: field("lootAll")?,
        bypass: field("bypassInteraction")?,
    })
}

unsafe extern "system" fn on_deliver(storage: usize) -> usize {
    let Some(a) = ARMED.get() else {
        return 0;
    };
    STEPS.fetch_add(1, Ordering::Relaxed);
    let read = modforge::seh::guard(|| {
        // SAFETY: SimStep hands DeliverEvents a live storage on the sim
        // thread, before delivery; reads are guarded against faults.
        unsafe {
            let kind = *((storage + a.kind) as *const u8);
            a.pending.each(storage, |hash, data, size| {
                if hash != a.loot.hash || size <= a.loot.bypass {
                    return;
                }
                LOOT_SEEN.fetch_add(1, Ordering::Relaxed);
                let u32_at = |o: usize| *(data.add(o) as *const u32);
                modforge::log!(
                    "loot event (world kind {kind}): guest {} host {} offer {} lootAll {} bypass {}",
                    u32_at(a.loot.guest),
                    u32_at(a.loot.host),
                    u32_at(a.loot.offer),
                    *data.add(a.loot.loot_all),
                    *data.add(a.loot.bypass)
                );
            });
        }
    });
    if read.is_err() {
        FAULTS.fetch_add(1, Ordering::Relaxed);
    }
    modforge::call_original!(a.hook, storage).unwrap_or(0)
}

fn arm() -> Result<(), String> {
    let (deliver, v) = find_in_exe(DELIVER_EVENTS)?;
    let pending_count = value(&v, "gameplay/storage.pending_count")?;
    let (_, v) = find_in_exe(DELIVER_PENDING)?;
    let pending = value(&v, "gameplay/storage.pending")?;
    let used = value(&v, "gameplay/buffer.used")?;
    let (_, v) = find_in_exe(DELIVER_RECORD)?;
    let record_size = value(&v, "gameplay/record.size")?;
    let (_, v) = find_in_exe(WORLD_DESTROY)?;
    let kind = value(&v, "storage.kind")?;
    let loot = loot_layout()?;
    // SAFETY: DELIVER_EVENTS matches the entry of the game's
    // DeliverEvents(storage), a normal x64 function.
    let hook = unsafe { Hook::<DeliverFn>::install("DeliverEvents", deliver, on_deliver) }
        .map_err(|e| format!("{e:#}"))?;
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
        loot,
    };
    modforge::log!(
        "events: DeliverEvents hooked at {deliver:#x}, {:?}, kind byte +{kind:#x}, loot hash {:#x}",
        armed.pending,
        armed.loot.hash
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

/// Hooks DeliverEvents when every signature matches; logs why not
/// otherwise. Adds `events.status`.
pub fn register() {
    if let Err(e) = arm() {
        modforge::log!("events: not hooked: {e}");
    }
    OP_REGISTRY.register(OpDef::new(
        "events.status",
        "read-only: whether DeliverEvents is hooked, steps seen, loot events seen",
        "",
        |_| {
            Ok(json!({
                "hooked": ARMED.get().is_some(),
                "steps": STEPS.load(Ordering::Relaxed),
                "loot_events": LOOT_SEEN.load(Ordering::Relaxed),
                "faults": FAULTS.load(Ordering::Relaxed),
            }))
        },
    ));
}
