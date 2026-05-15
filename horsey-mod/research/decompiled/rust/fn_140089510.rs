// Decompiled from Horsey.exe @ 0x140089510
// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print
// blocks: 6

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]
pub unsafe fn save_filename_format() {

    // ---- bb0 @ 0x140089510 ----
    /* 140089510 */ let mut t_140089510: u32 = core::ptr::read((0x140089516_u64).wrapping_add(0x371cd2_u64) as *const u32);
    /* 140089510 */ let mut rcx: u64 = (t_140089510 as u64);
    /* 140089516 */ rcx = core::ptr::read((rcx).wrapping_add(0x300_u64) as *const u64);
    /* 14008951d */ fn_1400a8df0();
    /* 140089522 */ let mut t_140089522: u32 = core::ptr::read(rax as *const u32);
    if (t_140089522 == 0x4_u32) {
        /* -> bb7 */
    } else {
        /* -> bb6 */
    }

    // ---- bb6 @ 0x140089525 ----
    if (t_140089522 == 0x4_u32) {
        /* -> bb7 */
    } else {
        /* -> bb11 */
    }

    // ---- bb7 @ 0x140089527 ----
    /* 140089527 */ let mut t_140089527: u8 = core::ptr::read((0x14008952e_u64).wrapping_add(0x36402a_u64) as *const u8);
    if (t_140089527 != 0x0_u8) {
        /* -> bb11 */
    } else {
        /* -> bb10 */
    }

    // ---- bb10 @ 0x14008952e ----
    if (t_140089527 != 0x0_u8) {
        /* -> bb11 */
    } else {
        /* -> bb14 */
    }

    // ---- bb11 @ 0x140089534 ----
    /* 140089534 */ core::ptr::write((0x14008953b_u64).wrapping_add(0x36401d_u64) as *mut u8, 0x0_u8);
    /* 14008953b */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0xd_u64);
    /* fallthrough -> bb14 */

    // ---- bb14 @ 0x14008b55e ----
    /* 14008b55e */ let mut r11: u64 = (rsp).wrapping_add(0x280_u64);
    /* 14008b566 */ let mut rbx: u64 = core::ptr::read((r11).wrapping_add(0x38_u64) as *const u64);
    /* 14008b56a */ let mut rsi: u64 = core::ptr::read((r11).wrapping_add(0x40_u64) as *const u64);
    /* 14008b56e */ let mut xmm6: u128 = core::ptr::read((r11).wrapping_sub(0x10_u64) as *const u128);
    /* 14008b573 */ let mut xmm7: u128 = core::ptr::read((r11).wrapping_sub(0x20_u64) as *const u128);
    /* 14008b578 */ let mut xmm8: u128 = core::ptr::read((r11).wrapping_sub(0x30_u64) as *const u128);
    /* 14008b57d */ let mut xmm9: u128 = core::ptr::read((r11).wrapping_sub(0x40_u64) as *const u128);
    /* 14008b582 */ rsp = r11;
    /* 14008b585 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14008b585 */ let mut r15: u64 = core::ptr::read(rsp as *const u64);
    /* 14008b587 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14008b587 */ let mut r14: u64 = core::ptr::read(rsp as *const u64);
    /* 14008b589 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14008b589 */ let mut r12: u64 = core::ptr::read(rsp as *const u64);
    /* 14008b58b */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14008b58b */ let mut rdi: u64 = core::ptr::read(rsp as *const u64);
    /* 14008b58c */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14008b58c */ let mut rbp: u64 = core::ptr::read(rsp as *const u64);
    /* 14008b58d */ return;
    // <no successors>
}
