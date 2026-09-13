//! What crashed: read the newest Unreal minidump under the game's Saved
//! folder, name the faulting address and every return address on the
//! crashed thread's stack with the shipped PDB. No debugger needed.
//!
//! ```text
//! cargo test -p abioticfactor-mod --test crash_dump -- --nocapture
//! ```
//! Minidump layout from the Windows SDK minidumpapiset.h: header, stream
//! directory, ExceptionStream (6), ModuleListStream (4), Memory64ListStream (9).

use std::path::PathBuf;
use ueforge::symbols;

const DEFAULT_PDB: &str = r"C:\Games\Steam\steamapps\common\AbioticFactor\AbioticFactor\Binaries\Win64\AbioticFactor-Win64-Shipping.pdb";

fn u32_at(b: &[u8], at: usize) -> u32 { u32::from_le_bytes(b[at..at + 4].try_into().unwrap()) }
fn u64_at(b: &[u8], at: usize) -> u64 { u64::from_le_bytes(b[at..at + 8].try_into().unwrap()) }

fn newest_dump() -> Option<PathBuf> {
    let crashes = PathBuf::from(std::env::var("LOCALAPPDATA").ok()?).join(r"AbioticFactor\Saved\Crashes");
    let mut dumps: Vec<(std::time::SystemTime, PathBuf)> = std::fs::read_dir(&crashes).ok()?
        .flatten().map(|e| e.path().join("UEMinidump.dmp")).filter(|p| p.is_file())
        .filter_map(|p| Some((p.metadata().ok()?.modified().ok()?, p))).collect();
    dumps.sort();
    dumps.pop().map(|(_, p)| p)
}

/// Nearest procedure at or below `rva`, as "name+offset".
fn name_near(procedures: &[(u32, String)], rva: u32) -> String {
    match procedures.iter().rev().find(|(start, _)| *start <= rva) {
        Some((start, name)) => format!("{name}+0x{:X}", rva - start),
        None => "?".into(),
    }
}

#[test]
fn newest_crash_named_from_pdb() {
    let Some(dump) = newest_dump() else { eprintln!("SKIP: no minidump under Saved/Crashes"); return; };
    let pdb = std::env::var("ABIOTICFACTOR_PDB").map(PathBuf::from).unwrap_or_else(|_| PathBuf::from(DEFAULT_PDB));
    if !pdb.is_file() { eprintln!("SKIP: no PDB at {}", pdb.display()); return; }
    println!("dump: {}", dump.display());
    let b = std::fs::read(&dump).expect("read dump");
    assert_eq!(&b[..4], b"MDMP", "not a minidump");
    let (streams, directory) = (u32_at(&b, 8) as usize, u32_at(&b, 12) as usize);
    let mut exception = None;
    let mut modules = Vec::new();
    let mut memory = Vec::new();
    for i in 0..streams {
        let entry = directory + i * 12;
        let (kind, size, rva) = (u32_at(&b, entry), u32_at(&b, entry + 4) as usize, u32_at(&b, entry + 8) as usize);
        match kind {
            6 => {
                let thread = u32_at(&b, rva);
                let code = u32_at(&b, rva + 8);
                let address = u64_at(&b, rva + 24);
                let parameters: Vec<u64> = (0..u32_at(&b, rva + 32).min(15) as usize).map(|p| u64_at(&b, rva + 40 + p * 8)).collect();
                let (context_size, context_rva) = (u32_at(&b, rva + 160) as usize, u32_at(&b, rva + 164) as usize);
                // x64 CONTEXT: Rsp at 0x98, Rip at 0xF8.
                let (rsp, rip) = if context_size >= 0x100 { (u64_at(&b, context_rva + 0x98), u64_at(&b, context_rva + 0xF8)) } else { (0, 0) };
                exception = Some((thread, code, address, parameters, rsp, rip));
            }
            4 => {
                let count = u32_at(&b, rva) as usize;
                for m in 0..count {
                    let module = rva + 4 + m * 108;
                    let (base, size, name_rva) = (u64_at(&b, module), u32_at(&b, module + 8) as u64, u32_at(&b, module + 20) as usize);
                    let length = u32_at(&b, name_rva) as usize;
                    let name: String = String::from_utf16_lossy(&b[name_rva + 4..name_rva + 4 + length].chunks_exact(2).map(|c| u16::from_le_bytes([c[0], c[1]])).collect::<Vec<_>>());
                    modules.push((base, size, name));
                }
            }
            9 => {
                let count = u64_at(&b, rva) as usize;
                let mut data = u64_at(&b, rva + 8) as usize;
                for r in 0..count {
                    let descriptor = rva + 16 + r * 16;
                    let (start, len) = (u64_at(&b, descriptor), u64_at(&b, descriptor + 8) as usize);
                    memory.push((start, len, data));
                    data += len;
                }
            }
            _ => { let _ = size; }
        }
    }
    let (thread, code, address, parameters, rsp, rip) = exception.expect("exception stream");
    println!("thread {thread} exception 0x{code:08X} at 0x{address:X} parameters {parameters:X?} rip 0x{rip:X} rsp 0x{rsp:X}");
    let game = modules.iter().find(|(_, _, n)| n.ends_with("AbioticFactor-Win64-Shipping.exe")).expect("game module in dump").clone();
    for (base, size, name) in modules.iter().filter(|(_, _, n)| n.ends_with(".exe") || n.contains("main") || n.contains("ue4ss") || n.contains("dwmapi")) {
        println!("module 0x{base:X}+0x{size:X} {name}");
    }
    let in_game = |a: u64| a >= game.0 && a < game.0 + game.1;
    let mut procedures: Vec<(u32, String)> = symbols::procedures(&pdb, "").expect("pdb procedures").into_iter().map(|s| (s.rva, s.decorated)).collect();
    procedures.sort();
    procedures.dedup_by_key(|(rva, _)| *rva);
    if in_game(address) {
        println!("faulting: {} (rva 0x{:X})", name_near(&procedures, (address - game.0) as u32), address - game.0);
    } else {
        let owner = modules.iter().find(|(b, s, _)| address >= *b && address < b + *s as u64).map(|(b, _, n)| format!("{n}+0x{:X}", address - b)).unwrap_or("no module".into());
        println!("faulting address is outside the game exe: {owner}");
    }
    // Poor man's stack: every value on the crashed thread's stack that points into the game exe.
    let Some(&(start, len, data)) = memory.iter().find(|(s, l, _)| rsp >= *s && rsp < s + *l as u64) else { println!("no stack memory for rsp"); return; };
    let end = (start + len as u64).min(rsp + 0x4000);
    let mut printed = 0;
    let mut at = rsp;
    while at + 8 <= end {
        let value = u64_at(&b, data + (at - start) as usize);
        if in_game(value) {
            println!("  stack+0x{:X}: {}", at - rsp, name_near(&procedures, (value - game.0) as u32));
            printed += 1;
            if printed >= 40 { break; }
        }
        at += 8;
    }
}
