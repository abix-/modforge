//! Engine facts this game does not log.
//!
//! - `process_event_slot`: UE4SS runs with HookUObjectProcessEvent=0
//!   here, so its log has no "ProcessEvent address" line. The slot is
//!   found instead as the place where the player's (an actor's)
//!   function calls the GameInstance's (a plain object's) function in
//!   the same slot: AActor::ProcessEvent calls UObject::ProcessEvent.
//!   Prints every slot of that shape; read only.
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_engine -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, instances, ping_or_skip};

#[test]
fn process_event_slot() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let gi = modforge::client::walk_class_chain_instances(&api, "GameInstance", 4);
    let Some(g) = gi.iter().find(|i| !i.name.contains("Default__")) else {
        println!("no live GameInstance");
        return;
    };
    let Some((player, pname)) = instances(&api, "FS_Full_PlayerChar_C", 4).into_iter().next() else {
        println!("no live player");
        return;
    };
    println!("plain object {} @ {:#x}, actor {pname} @ {player:#x}", g.name, g.addr);
    match modforge::client::super_call_slots(&api, g.addr, player, 0x100, 0x200) {
        Ok(slots) => {
            let vt = modforge::client::read_u64(&api, g.addr, 0);
            for s in &slots {
                // Length up to the first int3 padding run: the base
                // call function is hundreds of bytes, small virtuals
                // are a few dozen.
                let f = modforge::client::read_u64(&api, vt, *s as u64 * 8);
                let code = modforge::client::read_bytes(&api, f, 0, 0x1000);
                let len = code.windows(3).position(|w| w == [0xCC; 3]).unwrap_or(code.len());
                println!("  slot {s:#x}: actor's function calls the object's {f:#x}, about {len} bytes");
            }
            println!("{} slots", slots.len());
        }
        Err(e) => println!("{e}"),
    }
}
