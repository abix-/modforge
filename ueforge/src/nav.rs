//! Unreal navigation: ask the game's own A* for a walkable path.
//!
//! One UFunction call, `NavigationSystemV1::FindPathToLocationSynchronously`,
//! returns a `UNavigationPath` whose `PathPoints` array is the detailed
//! path. This is the Unreal half of the shared bot navigation
//! (`modforge::route`): it does not steer or move the player, only
//! answers a path request. Game thread only (it calls ProcessEvent).
//!
//! Performance (see misery-mod/docs/performance.md): the navigation
//! system instance is found once and cached; the per-waypoint A* call
//! is not an object-list search. The travel loop asks for a path once
//! at the start of a leg and again only if the path is blocked, never
//! per tick.

use modforge::route::{GameNavigation, Path, PathPoint, Position};
use parking_lot::Mutex;

use crate::ue::UObject;
use crate::ue::actor::LiveActor;

static NAVSYS: Mutex<Option<u64>> = Mutex::new(None);

fn readable(addr: u64) -> bool {
    addr > 0x1_0000 && modforge::winproc::is_addr_readable(addr as usize)
}

/// The live `NavigationSystemV1`, cached and re-resolved only if the
/// cached pointer goes stale (world change).
fn navsys() -> Result<&'static UObject, String> {
    let mut cache = NAVSYS.lock();
    if let Some(addr) = *cache {
        if readable(addr) {
            // SAFETY: found before and just confirmed readable.
            return Ok(unsafe { &*(addr as *const UObject) });
        }
    }
    let addr = crate::ue::actor::find_objects_by_chain("NavigationSystemV1")
        .first()
        .map(|p| *p as u64)
        .ok_or("NavigationSystemV1 not found")?;
    *cache = Some(addr);
    // SAFETY: address came from the GObjects walk.
    Ok(unsafe { &*(addr as *const UObject) })
}

fn write_fvector(buf: &mut [u8], off: usize, p: Position) {
    buf[off..off + 8].copy_from_slice(&p.x.to_le_bytes());
    buf[off + 8..off + 16].copy_from_slice(&p.y.to_le_bytes());
    buf[off + 16..off + 24].copy_from_slice(&p.z.to_le_bytes());
}

/// Ask Unreal A* for a complete path from `start` to `end`. `world_ctx`
/// is any live UObject in the world (the player pawn works); it lets
/// the engine find the `UWorld`. Game thread only.
pub fn find_path(world_ctx: u64, start: Position, end: Position) -> Result<Path, String> {
    let ns = navsys()?;

    // FindPathToLocationSynchronously(WorldContextObject, PathStart,
    // PathEnd, PathfindingContext, FilterClass) -> UNavigationPath*.
    // 80-byte parm block: WorldContext +0x00; PathStart FVector +0x08;
    // PathEnd FVector +0x20; PathfindingContext +0x38 (null); FilterClass
    // +0x40 (null); ReturnValue +0x48.
    let mut parms = vec![0u8; 80];
    parms[0..8].copy_from_slice(&world_ctx.to_le_bytes());
    write_fvector(&mut parms, 8, start);
    write_fvector(&mut parms, 32, end);

    let out = crate::ops::exec_call(
        ns,
        "NavigationSystemV1",
        "FindPathToLocationSynchronously",
        parms,
    )?;
    let hex = out["parms_hex_after"]
        .as_str()
        .ok_or("navigation call returned no parm buffer")?;
    let bytes = hex::decode(hex).map_err(|e| format!("bad nav parm hex: {e}"))?;
    if bytes.len() < 80 {
        return Err("nav parm buffer too short".into());
    }
    let ret = u64::from_le_bytes(bytes[72..80].try_into().unwrap());
    if !readable(ret) {
        return Err("navigation returned no path (null or unreachable)".into());
    }
    // SAFETY: the engine wrote a live UNavigationPath pointer here.
    let path_obj = unsafe { &*(ret as *const UObject) };

    // UNavigationPath.PathPoints: TArray<FVector> at +0x38.
    // SAFETY: field_ptr only computes an address; the header read is
    // guarded below.
    let hdr_ptr = unsafe { path_obj.field_ptr(0x38) };
    if !readable(hdr_ptr as u64) {
        return Err("nav PathPoints header unreadable".into());
    }
    // SAFETY: the 16-byte TArray header is within the object.
    let hdr = unsafe { std::slice::from_raw_parts(hdr_ptr, 16) };
    let data = u64::from_le_bytes(hdr[0..8].try_into().unwrap());
    let num = u32::from_le_bytes(hdr[8..12].try_into().unwrap()) as usize;
    if num == 0 || num > 10_000 || !readable(data) {
        return Err(format!("nav path has {num} points (unusable)"));
    }

    let mut points = Vec::with_capacity(num);
    for i in 0..num {
        let base = data + (i * 24) as u64;
        if !readable(base) {
            break;
        }
        // SAFETY: each 24-byte FVector element is within the array.
        let fv = unsafe { std::slice::from_raw_parts(base as *const u8, 24) };
        let x = f64::from_le_bytes(fv[0..8].try_into().unwrap());
        let y = f64::from_le_bytes(fv[8..16].try_into().unwrap());
        let z = f64::from_le_bytes(fv[16..24].try_into().unwrap());
        points.push(PathPoint::new(Position::new(x, y, z)));
    }
    Path::new(points)
}

/// The Unreal implementation of the shared `GameNavigation` trait. The
/// retained player pawn is the world context for every path request.
pub struct UnrealNavigation {
    player: &'static LiveActor,
}

impl UnrealNavigation {
    pub fn new(player: &'static LiveActor) -> Self {
        Self { player }
    }
}

impl GameNavigation for UnrealNavigation {
    fn find_path(&self, start: Position, goal: Position) -> Result<Path, String> {
        let world_ctx = self
            .player
            .retained()
            .ok_or("navigation has no retained player for world context")?
            as *const UObject as u64;
        find_path(world_ctx, start, goal)
    }
}
