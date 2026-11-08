//! The game states object, read the way GameHelper2's GameStates does
//! (layout in [`crate::game::game_states`]).

use crate::game::game_states as gs;
use anyhow::{Context, Result};
use modforge::process_memory::ProcessMemory;

#[derive(Clone, Debug)]
pub struct States {
    /// The object the "Game States" global points at.
    pub object: u64,
    /// The current state's address.
    pub current: u64,
    /// Each state's address, in [`gs::NAMES`] order.
    pub all: [u64; 13],
}

impl States {
    pub fn current_name(&self) -> Option<&'static str> {
        if self.current == 0 {
            return None;
        }
        self.all
            .iter()
            .position(|a| *a == self.current)
            .map(|i| gs::NAMES[i])
    }

    /// The address of the state named `name`.
    pub fn get(&self, name: &str) -> Option<u64> {
        gs::NAMES
            .iter()
            .position(|n| *n == name)
            .map(|i| self.all[i])
    }
}

pub fn read(mem: &ProcessMemory, global: u64) -> Result<States> {
    let ptr = |addr: u64| -> Result<u64> {
        mem.read_value(addr)
            .with_context(|| format!("read pointer at {addr:#x}"))
    };
    let object = ptr(global)?;
    let last = ptr(object + gs::CURRENT_STATE_VECTOR + 8)?;
    let current = ptr(last
        .checked_sub(gs::CURRENT_STATE_FROM_END)
        .context("current state vector is empty")?)?;
    let mut all = [0u64; 13];
    for (i, at) in all.iter_mut().enumerate() {
        *at = ptr(object + gs::STATES + i as u64 * gs::STATE_STRIDE)?;
    }
    Ok(States {
        object,
        current,
        all,
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn reads_current_and_every_state() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        // The object: a vector at 0x10 and 13 pairs at 0x50.
        let mut object = [0u64; (0x50 + 13 * 0x10) / 8];
        let states: Vec<u64> = (0..13).map(|i| 0x1000 + i * 0x100).collect();
        for (i, s) in states.iter().enumerate() {
            object[(0x50 + i * 0x10) / 8] = *s;
        }
        // The vector holds (state, other) pairs; the current is 0x10 before Last.
        let stack = [states[0], 0, states[4], 0];
        object[0x10 / 8] = stack.as_ptr() as u64;
        object[0x18 / 8] = stack.as_ptr() as u64 + 0x20;
        let global = object.as_ptr() as u64;
        let global_cell = [global];
        let s = read(&mem, global_cell.as_ptr() as u64).unwrap();
        assert_eq!(s.current_name(), Some("InGameState"));
        assert_eq!(s.get("AreaLoadingState"), Some(0x1000));
        assert_eq!(s.all.to_vec(), states);
    }
}
