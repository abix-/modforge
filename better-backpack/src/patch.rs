// DefaultMaxSize patcher for the player's main backpack
// (UInventoryComponent at offset 0x01E0). Same logic as the C++ baseline:
// only player-owned components, never the mount/saddlebag (vanilla 30),
// never already-patched ones.

use crate::bbp_log;
use crate::sdk::{self, GObjectsView, UClass};

pub const SLOT_COUNT: i32 = 100;
pub const VANILLA_MAIN: i32 = 40;
pub const VANILLA_MOUNT: i32 = 30;
pub const DEFAULT_MAX_SIZE_OFFSET: usize = 0x01E0;

pub struct PatchStats {
    pub scanned: usize,
    pub patched: usize,
    pub skipped_non_player: usize,
}

pub fn run() -> PatchStats {
    let mut stats = PatchStats {
        scanned: 0,
        patched: 0,
        skipped_non_player: 0,
    };

    let Some(rt) = sdk::try_runtime() else {
        return stats;
    };
    let Some(inv_class) = sdk::find_class_fast("InventoryComponent") else {
        bbp_log!("ERROR: InventoryComponent class not found");
        return stats;
    };

    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        bbp_log!("ERROR: GObjects unavailable");
        return stats;
    }

    for obj in view.iter() {
        if !obj.is_a(inv_class) {
            continue;
        }
        stats.scanned += 1;

        let current = unsafe {
            (obj.field_ptr(DEFAULT_MAX_SIZE_OFFSET) as *const i32).read_unaligned()
        };
        if current == VANILLA_MOUNT || current >= SLOT_COUNT {
            continue;
        }

        let full = obj.full_name();
        let is_player = full.contains("BP_SurvivalPlayerCharacter");
        if !is_player {
            if current == VANILLA_MAIN {
                stats.skipped_non_player += 1;
            }
            continue;
        }

        unsafe {
            (obj.field_ptr(DEFAULT_MAX_SIZE_OFFSET) as *mut i32).write_unaligned(SLOT_COUNT);
        }
        let verify = unsafe {
            (obj.field_ptr(DEFAULT_MAX_SIZE_OFFSET) as *const i32).read_unaligned()
        };
        bbp_log!(
            "PATCH {}: {} -> {} (verify={})",
            full,
            current,
            SLOT_COUNT,
            verify
        );
        stats.patched += 1;
    }

    if stats.skipped_non_player > 0 {
        bbp_log!(
            "skipped {} non-player components with DefaultMaxSize=40",
            stats.skipped_non_player
        );
    }
    stats
}

#[allow(dead_code)]
fn _force_class_use(_c: &UClass) {}
