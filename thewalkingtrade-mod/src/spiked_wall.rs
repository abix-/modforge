//! Spiked walls last 10 times longer.
//!
//! Vanilla (Cpp2IL dump 1.2.5, `SpikedWallDamageTrigger.OnTriggerEnter`):
//! a mob touching the wall takes (wall health x 3 when secured) and the
//! wall takes (the mob's health), each through `Damageable.ApplyDamage`
//! whose multiplier argument is loaded from the constant 1.0 at
//! 0x183648C1C (`movss xmm3, [rip+disp]`). There is no stored setting
//! for the wall's own damage, so the byte patch points the wall's own
//! `movss` at a 0.1f constant the game already has in `.rdata`: the
//! wall takes a tenth, the damage it deals is unchanged.

use unityforge::mono::{LogLevel, log};

const MODULE: &str = "GameAssembly.dll";

/// The wall's own `movss xmm3, [rip+disp]` with 24 bytes before it and
/// the instructions after it (read from the 1.2.5 DLL: instruction at
/// VA 0x182651148). The load plus the bytes after it alone matched 4
/// places live; with this prefix (the `je` distance wildcarded) it
/// matches once in every code section (`spiked_wall_bytes`).
const WALL_HIT_SIG: &str = "0F 84 ?? ?? ?? ?? 48 8B 16 4C 8D 44 24 30 F2 0F 10 00 48 8B CE 8B 40 08 F3 0F 10 1D ?? ?? ?? ?? 4C 8B 8A 28 02 00 00 89 44 24 38 48 8B 82 30 02";
/// Where the `movss` starts in a match.
const INSTR_AT: usize = 24;
const DISP_AT: usize = 4;
const INSTR_LEN: usize = 8;
/// 0.1f, little endian.
const TENTH_SIG: &str = "CD CC CC 3D";

pub fn install() {
    match patch() {
        Ok(msg) => log(LogLevel::Info, &format!("thewalkingtrade-mod: spiked wall: {msg}")),
        Err(e) => log(LogLevel::Error, &format!("thewalkingtrade-mod: spiked wall FAILED: {e}")),
    }
}

fn patch() -> Result<String, String> {
    use modforge::patterns::sleuth::{scan_module_matches, scan_module_section};
    let hits = scan_module_matches(MODULE, WALL_HIT_SIG).map_err(|e| format!("scan: {e}"))?;
    let [start] = hits[..] else {
        return Err(format!("expected 1 match, found {}: {hits:x?}", hits.len()));
    };
    let instr = start + INSTR_AT;
    let disp_addr = instr + DISP_AT;
    let next_ip = instr + INSTR_LEN;
    // SAFETY: instr is a matched instruction inside the loaded module.
    let old_disp = unsafe { std::ptr::read_unaligned(disp_addr as *const i32) };
    let old_target = (next_ip as i64 + old_disp as i64) as usize;
    // SAFETY: old_target is the module constant the instruction loads.
    let old_value = unsafe { std::ptr::read_unaligned(old_target as *const f32) };
    if old_value != 1.0 {
        return Err(format!("wall multiplier at 0x{old_target:x} is {old_value}, expected 1.0"));
    }
    let tenths = scan_module_section(MODULE, TENTH_SIG, Some(object::SectionKind::ReadOnlyData))
        .map_err(|e| format!("scan 0.1f: {e}"))?;
    let tenth = *tenths.first().ok_or("no 0.1f in .rdata")?;
    let new_disp = i32::try_from(tenth as i64 - next_ip as i64).map_err(|e| e.to_string())?;
    modforge::code_patch::patch_bytes("spiked_wall_own_damage", disp_addr, &new_disp.to_le_bytes())
        .map_err(|e| e.to_string())?;
    Ok(format!("own damage x1.0 -> x0.1 at 0x{instr:x} (0.1f at 0x{tenth:x})"))
}
