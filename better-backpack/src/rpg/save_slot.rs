// Spike B: locate the active save slot via AInGameGameState.
//
// AInGameGameState is the in-game UWorld's GameState. It's populated for
// the duration of the active session and carries `PlaythroughGuid`
// (FGuid, 16 bytes) at offset 0x032C
// (`Maine_classes.hpp:28544`). This is the same stable GUID used to
// disambiguate saves on disk -- exactly what we need as a persistence
// filename key.
//
// Earlier attempt used `USaveLoadManager.SaveInProgressSaveGameHeaderData`
// at +0x90, but that field is null except during an active save
// operation. AInGameGameState is the right surface for "we're in a
// world, give me the playthrough id."
//
// Returns None when not in-world (main menu, between saves). Caller
// should re-check on demand.

use ueforge::ue::{ClassRef, UObject};

const IN_GAME_GAME_STATE_PLAYTHROUGH_GUID: usize = 0x032C;

#[repr(C)]
#[derive(Clone, Copy, Default, PartialEq, Eq)]
struct FGuid {
    a: u32,
    b: u32,
    c: u32,
    d: u32,
}

impl FGuid {
    fn is_zero(&self) -> bool {
        self.a == 0 && self.b == 0 && self.c == 0 && self.d == 0
    }

    fn to_filename(self) -> String {
        format!("{:08x}{:08x}{:08x}{:08x}", self.a, self.b, self.c, self.d)
    }
}

/// Returns the current playthrough's stable identifier as a 32-char hex
/// string suitable as a filename. None when not in-world.
pub fn current_slot_key() -> Option<String> {
    let game_state = find_in_game_game_state()?;
    let guid: FGuid = unsafe {
        game_state
            .field_ptr(IN_GAME_GAME_STATE_PLAYTHROUGH_GUID)
            .cast::<FGuid>()
            .read_unaligned()
    };
    if guid.is_zero() {
        return None;
    }
    Some(guid.to_filename())
}

static IN_GAME_GAME_STATE: ClassRef = ClassRef::new("InGameGameState");

fn find_in_game_game_state() -> Option<&'static UObject> {
    ueforge::counters::bump(&crate::counters::WORLD_LOADER_GOBJECTS_WALKS);
    IN_GAME_GAME_STATE.with_first_instance(|o| unsafe { &*(o as *const UObject) })
}
