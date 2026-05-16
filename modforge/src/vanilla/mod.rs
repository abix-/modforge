//! Invoke any vanilla function at any address with any signature.
//!
//! See `../docs/vanilla-invoke.md` for the design.
//!
//! Three layers:
//! - `sig`: `Signature`, `ArgKind`, `RetKind`, `ArgValue`, `RetValue`.
//!   Pure data; no asm; const-evaluable.
//! - `dispatch`: Win64 ABI asm dispatcher. Materializes args into
//!   registers + stack and calls the target.
//! - `invoker`: `Invoker` controller bound to a `sleuth::Resolver`.
//!   Looks targets up by name, applies SEH wrapping by default.

pub mod dispatch;
pub mod invoker;
pub mod ops;
pub mod sig;

pub use invoker::{Invoker, VanillaError, VanillaFn};
pub use sig::{ArgKind, ArgValue, RetKind, RetValue, Signature};
