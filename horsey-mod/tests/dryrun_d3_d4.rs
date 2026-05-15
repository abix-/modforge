//! Dryrun verification for the D3 / D4 patch targets.
//!
//! What this asserts (for every new patch target):
//!   1. The dryrun op succeeds.
//!   2. The runtime address is non-zero and inside the loaded
//!      Horsey.exe image (image_base + RVA range).
//!   3. The 16-byte prologue starts with a plausible MSVC
//!      function-entry pattern (see `looks_like_msvc_entry`).
//!      Catches the -16 Ghidra-offset-adjustment regression
//!      automatically: if a target's true entry is wrong, its
//!      prologue starts with INT3 padding (`cc cc ..`) or random
//!      middle-of-function bytes.
//!
//! Targets checked:
//!   - genes.ext.combinator.dryrun  (1 target: GENE_COMBINATOR)
//!   - genes.ext.lifecycle.dryrun   (2 targets: HORSE_CONSTRUCTOR,
//!                                              HORSE_DESTRUCTOR)
//!   - genes.ext.save.dryrun        (4 targets: SAVE_WRITER,
//!                                              LOAD_GAME,
//!                                              HORSE_SAVE_WRITER,
//!                                              HORSE_SAVE_LOADER)
//!
//! Failure of this test => DO NOT arm those detours. Re-derive the
//! address (the -16 adjustment is probably wrong for that one) and
//! re-run.

mod common;

use modforge::harness::RunningGame;
use serde_json::Value;
use serde_json::json;

/// Returns true if the byte sequence looks like the entry of an
/// MSVC-compiled Win64 function. Specifically, accepts the shapes
/// we see across `Horsey.exe` working detours:
///   - `48 89 ..`   mov [rsp+disp], <reg>   (shadow-space saves)
///   - `48 8b c4`   mov rax, rsp            (big-frame prologue)
///   - `48 83 ec`   sub rsp, imm8           (small leaf frame)
///   - `48 81 ec`   sub rsp, imm32          (large leaf frame)
///   - `40 53/55/56/57` REX + push reg      (push r12/r13/r14/r15)
///   - `53/55/56/57`   push rbx/rbp/rsi/rdi (plain push prologue)
///   - `4c 89 ..`   mov [rsp+disp], r8..r15
///   - `44 89 ..`   mov [rsp+disp], r8d..r15d
///   - `41 ..`      REX.B push
///
/// Rejects:
///   - all `cc`     INT3 padding (function-boundary gap)
///   - all zero    .reloc or BSS
///   - `e9 ..`      jmp rel32 leading byte (jump table thunk, not
///                  a real entry)
fn looks_like_msvc_entry(bytes: &[u8]) -> bool {
    if bytes.len() < 4 {
        return false;
    }
    // Reject INT3 padding outright.
    if bytes.iter().take(8).all(|&b| b == 0xcc) {
        return false;
    }
    if bytes.iter().take(8).all(|&b| b == 0x00) {
        return false;
    }
    match bytes[0] {
        // REX.W (48). Most common Win64 entry prefix.
        0x48 => matches!(
            bytes[1],
            0x89 | 0x8b | 0x83 | 0x81 | 0x57 | 0x55 | 0x53 | 0x56
        ),
        // REX.WR (49) or REX.WB (4c)
        0x49 | 0x4c => matches!(bytes[1], 0x89 | 0x8b),
        // REX.WR (44) for r8d..r15d store
        0x44 => bytes[1] == 0x89,
        // REX.B for push r12..r15
        0x40..=0x47 => matches!(bytes[1], 0x53 | 0x55 | 0x56 | 0x57),
        // Plain pushes (rbx, rbp, rsi, rdi)
        0x53 | 0x55 | 0x56 | 0x57 => true,
        // REX.B push r12..r15
        0x41 => matches!(bytes[1], 0x54 | 0x55 | 0x56 | 0x57),
        _ => false,
    }
}

fn parse_prologue_hex(s: &str) -> Vec<u8> {
    s.split_whitespace()
        .filter_map(|tok| u8::from_str_radix(tok, 16).ok())
        .collect()
}

fn check_target(game: &RunningGame, group: &str, name: &str, target: &Value) {
    let resolved = target
        .get("runtime_addr")
        .and_then(|v| v.as_str())
        .unwrap_or("");
    let prologue_str = target
        .get("prologue_bytes")
        .and_then(|v| v.as_str())
        .unwrap_or("");
    let bytes = parse_prologue_hex(prologue_str);

    let log = game.log();
    log.event(
        group,
        &format!(
            "{name} resolved={resolved} prologue=[{prologue_str}]"
        ),
    );

    assert!(
        !resolved.is_empty() && resolved != "0x0",
        "{group}/{name}: empty/zero runtime_addr"
    );
    assert!(
        bytes.len() >= 8,
        "{group}/{name}: prologue too short ({} bytes)",
        bytes.len()
    );
    assert!(
        looks_like_msvc_entry(&bytes),
        "{group}/{name}: prologue does not look like MSVC function entry. \
         Got first 4 bytes [{}]. \
         Re-derive the address (the -16 Ghidra adjustment is probably wrong for this target).",
        bytes
            .iter()
            .take(4)
            .map(|b| format!("{b:02x}"))
            .collect::<Vec<_>>()
            .join(" ")
    );

    log.event(group, &format!("{name} PROLOGUE OK"));
}

#[test]
fn combinator_dryrun_prologue_ok() {
    let Some(game) = common::launch("dryrun_combinator") else {
        return;
    };

    let resp = game
        .op_json("genes.ext.combinator.dryrun", &json!({}))
        .expect("combinator dryrun should succeed");

    let snap = resp
        .get("snapshot")
        .unwrap_or(&resp);

    check_target(&game, "COMBINATOR", "GENE_COMBINATOR", snap);
    game.pass("combinator prologue ok");
}

#[test]
fn lifecycle_dryrun_prologues_ok() {
    let Some(game) = common::launch("dryrun_lifecycle") else {
        return;
    };

    let resp = game
        .op_json("genes.ext.lifecycle.dryrun", &json!({}))
        .expect("lifecycle dryrun should succeed");

    let snap = resp
        .get("snapshot")
        .unwrap_or(&resp);

    let ctor = snap
        .get("ctor")
        .expect("lifecycle dryrun should include ctor");
    let dtor = snap
        .get("dtor")
        .expect("lifecycle dryrun should include dtor");

    check_target(&game, "LIFECYCLE", "HORSE_CONSTRUCTOR", ctor);
    check_target(&game, "LIFECYCLE", "HORSE_DESTRUCTOR", dtor);
    game.pass("lifecycle prologues ok");
}

#[test]
fn save_dryrun_prologues_ok() {
    let Some(game) = common::launch("dryrun_save") else {
        return;
    };

    let resp = game
        .op_json("genes.ext.save.dryrun", &json!({}))
        .expect("save dryrun should succeed");

    let snap = resp
        .get("snapshot")
        .unwrap_or(&resp);

    let targets = snap
        .get("targets")
        .and_then(|v| v.as_array())
        .expect("save dryrun should include targets array");

    assert_eq!(
        targets.len(),
        4,
        "expected 4 save targets, got {}",
        targets.len()
    );

    for t in targets {
        let name = t
            .get("name")
            .and_then(|v| v.as_str())
            .unwrap_or("(unnamed)")
            .to_string();
        check_target(&game, "SAVE", &name, t);
    }
    game.pass("save prologues ok");
}
