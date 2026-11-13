//! The main-thread queue lives in modforge (it names no engine);
//! godotforge drains the same type. Kept at this path so the
//! existing `unityforge::main_thread_queue::MAIN_QUEUE` callers
//! across the game crates keep working.

pub use modforge::main_thread_queue::{MAIN_QUEUE, MainThreadQueue};
