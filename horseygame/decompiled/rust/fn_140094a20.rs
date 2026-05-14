// Decompiled from Horsey.exe @ 0x140094a20
// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print
// blocks: 1106

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]
pub unsafe fn click_race_when_ready_dialog() {

    // ---- bb0 @ 0x140094a20 ----
    /* 140094a20 */ core::ptr::write((rax).wrapping_sub(0xa8_u64) as *mut u128, xmm4);
    /* 140094a27 */ core::ptr::write((rax).wrapping_sub(0xb8_u64) as *mut u128, xmm13);
    /* 140094a2f */ core::ptr::write((rax).wrapping_sub(0xc8_u64) as *mut u128, xmm14);
    /* 140094a37 */ core::ptr::write((rax).wrapping_sub(0xd8_u64) as *mut u128, xmm15);
    /* 140094a3f */ let mut rdi: u64 = rcx;
    /* 140094a42 */ let mut t_140094a42: u8 = core::ptr::read((0x140094a49_u64).wrapping_add(0x344b32_u64) as *const u8);
    if (t_140094a42 != 0x0_u8) {
        /* -> bb9 */
    } else {
        /* -> bb8 */
    }

    // ---- bb8 @ 0x140094a49 ----
    if (t_140094a42 != 0x0_u8) {
        /* -> bb9 */
    } else {
        /* -> bb18 */
    }

    // ---- bb9 @ 0x140094a4b ----
    /* 140094a4b */ let mut t_140094a4b: u8 = core::ptr::read((0x140094a52_u64).wrapping_add(0x358bec_u64) as *const u8);
    if (t_140094a4b != 0x0_u8) {
        /* -> bb13 */
    } else {
        /* -> bb12 */
    }

    // ---- bb12 @ 0x140094a52 ----
    if (t_140094a4b != 0x0_u8) {
        /* -> bb13 */
    } else {
        /* -> bb18 */
    }

    // ---- bb13 @ 0x140094a54 ----
    /* 140094a54 */ fn_140092110();
    /* 140094a59 */ let mut rcx: u64 = rdi;
    /* 140094a5c */ fn_140092340();
    /* 140094a61 */ rcx = rdi;
    /* 140094a64 */ fn_14008ff80();
    /* fallthrough -> bb18 */

    // ---- bb18 @ 0x140094a69 ----
    /* 140094a69 */ let mut t_140094a69_0: u32 = 0x0_u32;
    /* 140094a69 */ let mut rsi: u64 = (t_140094a69_0 as u64);
    /* 140094a6b */ core::ptr::write((rdi).wrapping_add(0x124_u64) as *mut u32, (rsi as u32));
    /* 140094a71 */ let mut t_140094a71: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140094a71 */ core::ptr::write((rdi).wrapping_add(0x254_u64) as *mut u32, (t_140094a71).wrapping_add(0x1_u32));
    /* 140094a77 */ let mut t_140094a77: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_140094a77 == (rsi as u8)) {
        /* -> bb25 */
    } else {
        /* -> bb24 */
    }

    // ---- bb24 @ 0x140094a7e ----
    if (t_140094a77 == (rsi as u8)) {
        /* -> bb25 */
    } else {
        /* -> bb31 */
    }

    // ---- bb25 @ 0x140094a80 ----
    // intrinsic: f30f1087 movss xmm0, dword ptr [rdi + 0x10c]
    /* 140094a88 */ let mut t_140094a88: u32 = core::ptr::read((0x140094a90_u64).wrapping_add(0x276c40_u64) as *const u32);
    /* 140094a88 */ let mut xmm1: u128 = (t_140094a88 as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    // intrinsic: f30f5e8f divss xmm1, dword ptr [rdi + 0x114]
    // intrinsic: f30f58c8 addss xmm1, xmm0
    /* 140094a9f */ fn_140040eb0();
    /* fallthrough -> bb31 */

    // ---- bb31 @ 0x140094aa4 ----
    /* 140094aa4 */ rcx = core::ptr::read((rdi).wrapping_add(0x328_u64) as *const u64);
    /* 140094aab */ fn_1400c9280();
    /* 140094ab0 */ let mut t_140094ab0: u32 = core::ptr::read((rdi).wrapping_add(0x320_u64) as *const u32);
    /* 140094ab0 */ let mut rax: u64 = (t_140094ab0 as u64);
    if (((SF != OF) | (t_140094a77 == (rsi as u8))) == false) { /* -> bb38 */ }
    if (((SF != OF) | (t_140094a77 == (rsi as u8))) != 0) { /* -> bb37 */ }

    // ---- bb37 @ 0x140094ab8 ----
    if (((SF != OF) | (t_140094a77 == (rsi as u8))) == false) { /* -> bb38 */ }
    if (((SF != OF) | (t_140094a77 == (rsi as u8))) != 0) { /* -> bb40 */ }

    // ---- bb38 @ 0x140094aba ----
    /* 140094aba */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    /* 140094abc */ core::ptr::write((rdi).wrapping_add(0x320_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb40 */

    // ---- bb40 @ 0x140094ac2 ----
    /* 140094ac2 */ rcx = rdi;
    /* 140094ac5 */ fn_1400ca670();
    /* 140094aca */ let mut t_140094aca: u32 = core::ptr::read((rdi).wrapping_add(0xd8_u64) as *const u32);
    /* 140094aca */ let mut rdx: u64 = (t_140094aca as u64);
    /* 140094ad0 */ core::ptr::write((0x140094ad6_u64).wrapping_add(0x3455c6_u64) as *mut u32, (rdx as u32));
    /* 140094ad6 */ let mut t_140094ad6: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    /* 140094ad6 */ rax = (t_140094ad6 as u64);
    if (SF != OF) {
        /* -> bb49 */
    } else {
        /* -> bb48 */
    }

    // ---- bb48 @ 0x140094adf ----
    if (SF != OF) {
        /* -> bb49 */
    } else {
        /* -> bb84 */
    }

    // ---- bb49 @ 0x140094ae1 ----
    /* 140094ae1 */ let mut t_140094ae1_0: u32 = ((rax as u32)).wrapping_add(0xfffffffd_u32);
    /* 140094ae1 */ rax = (t_140094ae1_0 as u64);
    if ((rax as u32) != 0x9_u32) {
        /* -> bb54 */
    } else {
        /* -> bb53 */
    }

    // ---- bb53 @ 0x140094ae9 ----
    if ((rax as u32) != 0x9_u32) {
        /* -> bb54 */
    } else {
        /* -> bb84 */
    }

    // ---- bb54 @ 0x140094aeb ----
    /* 140094aeb */ let mut t_140094aeb: u32 = core::ptr::read((rdi).wrapping_add(0x3d0_u64) as *const u32);
    if (((SF == OF) & (t_140094aeb != (rsi as u32))) == false) { /* -> bb58 */ }
    if (((SF == OF) & (t_140094aeb != (rsi as u32))) != 0) { /* -> bb57 */ }

    // ---- bb57 @ 0x140094af1 ----
    if (((SF == OF) & (t_140094aeb != (rsi as u32))) == false) { /* -> bb58 */ }
    if (((SF == OF) & (t_140094aeb != (rsi as u32))) != 0) { /* -> bb62 */ }

    // ---- bb58 @ 0x140094af3 ----
    /* 140094af3 */ let mut t_140094af3: u64 = core::ptr::read((rdi).wrapping_add(0x3c0_u64) as *const u64);
    if (t_140094af3 != rsi) {
        /* -> bb62 */
    } else {
        /* -> bb61 */
    }

    // ---- bb61 @ 0x140094afa ----
    if (t_140094af3 != rsi) {
        /* -> bb62 */
    } else {
        /* -> bb84 */
    }

    // ---- bb62 @ 0x140094afc ----
    /* 140094afc */ let mut t_140094afc: u32 = core::ptr::read((rdi).wrapping_add(0xe0_u64) as *const u32);
    /* 140094afc */ rcx = (t_140094afc as u64);
    if ((rcx as u32) != 0x18_u32) {
        /* -> bb67 */
    } else {
        /* -> bb66 */
    }

    // ---- bb66 @ 0x140094b05 ----
    if ((rcx as u32) != 0x18_u32) {
        /* -> bb67 */
    } else {
        /* -> bb80 */
    }

    // ---- bb67 @ 0x140094b07 ----
    if ((rcx as u32) != 0x19_u32) {
        /* -> bb71 */
    } else {
        /* -> bb70 */
    }

    // ---- bb70 @ 0x140094b0a ----
    if ((rcx as u32) != 0x19_u32) {
        /* -> bb71 */
    } else {
        /* -> bb80 */
    }

    // ---- bb71 @ 0x140094b0c ----
    /* 140094b0c */ rax = (((rdx).wrapping_sub(0x18_u64) as u32) as u64);
    if (((CF == false) & ((rax as u32) != 0x1_u32)) == false) { /* -> bb76 */ }
    if (((CF == false) & ((rax as u32) != 0x1_u32)) != 0) { /* -> bb75 */ }

    // ---- bb75 @ 0x140094b12 ----
    if (((CF == false) & ((rax as u32) != 0x1_u32)) == false) { /* -> bb76 */ }
    if (((CF == false) & ((rax as u32) != 0x1_u32)) != 0) { /* -> bb92 */ }

    // ---- bb76 @ 0x140094b14 ----
    if ((rcx as u32) != 0xffffffff_u32) {
        /* -> bb80 */
    } else {
        /* -> bb79 */
    }

    // ---- bb79 @ 0x140094b17 ----
    if ((rcx as u32) != 0xffffffff_u32) {
        /* -> bb80 */
    } else {
        /* -> bb81 */
    }

    // ---- bb80 @ 0x140094b19 ----
    /* 140094b19 */ core::ptr::write((rdi).wrapping_add(0x1fc_u64) as *mut u32, 0x3_u32);
    /* fallthrough -> bb81 */

    // ---- bb81 @ 0x140094b23 ----
    /* 140094b23 */ core::ptr::write((rdi).wrapping_add(0xd8_u64) as *mut u64, 0xffffffffffffffff_u64);
    /* 140094b2e */ core::ptr::write((rdi).wrapping_add(0xe0_u64) as *mut u32, 0xffffffff_u32);
    /* fallthrough -> bb92 */

    // ---- bb84 @ 0x140094b3a ----
    /* 140094b3a */ let mut t_140094b3a_0: u32 = 0x0_u32;
    /* 140094b3a */ rdx = (t_140094b3a_0 as u64);
    /* 140094b3c */ let mut r8: u64 = (0x18_u32 as u64);
    /* 140094b42 */ rcx = rdi;
    /* 140094b45 */ fn_1400ca560();
    /* 140094b4a */ rdx = (0x1_u32 as u64);
    /* 140094b4f */ r8 = (0x19_u32 as u64);
    /* 140094b55 */ rcx = rdi;
    /* 140094b58 */ fn_1400ca560();
    /* fallthrough -> bb92 */

    // ---- bb92 @ 0x140094b5d ----
    /* 140094b5d */ rdx = (0x3_u32 as u64);
    /* 140094b62 */ r8 = (0x1a_u32 as u64);
    /* 140094b68 */ rcx = rdi;
    /* 140094b6b */ fn_1400ca560();
    /* 140094b70 */ rdx = (0x2_u32 as u64);
    /* 140094b75 */ r8 = (0x1b_u32 as u64);
    /* 140094b7b */ rcx = rdi;
    /* 140094b7e */ fn_1400ca560();
    /* 140094b83 */ let mut t_140094b83: u8 = core::ptr::read((rdi).wrapping_add(0x259_u64) as *const u8);
    if (t_140094b83 != (rsi as u8)) {
        /* -> bb104 */
    } else {
        /* -> bb103 */
    }

    // ---- bb103 @ 0x140094b8a ----
    if (t_140094b83 != (rsi as u8)) {
        /* -> bb104 */
    } else {
        /* -> bb121 */
    }

    // ---- bb104 @ 0x140094b8c ----
    /* 140094b8c */ let mut t_140094b8c: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140094b8c == 0x8_u32) {
        /* -> bb108 */
    } else {
        /* -> bb107 */
    }

    // ---- bb107 @ 0x140094b93 ----
    if (t_140094b8c == 0x8_u32) {
        /* -> bb108 */
    } else {
        /* -> bb121 */
    }

    // ---- bb108 @ 0x140094b95 ----
    /* 140094b95 */ let mut t_140094b95: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (((SF != OF) | (t_140094b95 == 0xb4_u32)) == false) { /* -> bb112 */ }
    if (((SF != OF) | (t_140094b95 == 0xb4_u32)) != 0) { /* -> bb111 */ }

    // ---- bb111 @ 0x140094b9f ----
    if (((SF != OF) | (t_140094b95 == 0xb4_u32)) == false) { /* -> bb112 */ }
    if (((SF != OF) | (t_140094b95 == 0xb4_u32)) != 0) { /* -> bb121 */ }

    // ---- bb112 @ 0x140094ba1 ----
    /* 140094ba1 */ let mut t_140094ba1: u8 = core::ptr::read((0x140094ba8_u64).wrapping_add(0x3589c8_u64) as *const u8);
    if (t_140094ba1 == (rsi as u8)) {
        /* -> bb116 */
    } else {
        /* -> bb115 */
    }

    // ---- bb115 @ 0x140094ba8 ----
    if (t_140094ba1 == (rsi as u8)) {
        /* -> bb116 */
    } else {
        /* -> bb120 */
    }

    // ---- bb116 @ 0x140094baa ----
    /* 140094baa */ let mut t_140094baa: u32 = core::ptr::read((0x140094bb0_u64).wrapping_add(0x358db8_u64) as *const u32);
    if (t_140094baa != (rsi as u32)) {
        /* -> bb120 */
    } else {
        /* -> bb119 */
    }

    // ---- bb119 @ 0x140094bb0 ----
    if (t_140094baa != (rsi as u32)) {
        /* -> bb120 */
    } else {
        /* -> bb121 */
    }

    // ---- bb120 @ 0x140094bb2 ----
    /* 140094bb2 */ core::ptr::write((rdi).wrapping_add(0xe0_u64) as *mut u32, 0x1b_u32);
    /* fallthrough -> bb121 */

    // ---- bb121 @ 0x140094bbc ----
    /* 140094bbc */ let mut t_140094bbc: u32 = core::ptr::read((rdi).wrapping_add(0xe0_u64) as *const u32);
    if (t_140094bbc == 0x1a_u32) {
        /* -> bb125 */
    } else {
        /* -> bb124 */
    }

    // ---- bb124 @ 0x140094bc3 ----
    if (t_140094bbc == 0x1a_u32) {
        /* -> bb125 */
    } else {
        /* -> bb126 */
    }

    // ---- bb125 @ 0x140094bc5 ----
    /* 140094bc5 */ core::ptr::write((rdi).wrapping_add(0xe0_u64) as *mut u32, 0xffffffff_u32);
    /* fallthrough -> bb126 */

    // ---- bb126 @ 0x140094bcf ----
    /* 140094bcf */ let mut r12: u64 = (0x5_u32 as u64);
    /* 140094bd5 */ let mut t_140094bd5: u32 = core::ptr::read((rdi).wrapping_add(0xdc_u64) as *const u32);
    if (t_140094bd5 == 0x1a_u32) {
        /* -> bb131 */
    } else {
        /* -> bb130 */
    }

    // ---- bb130 @ 0x140094bdc ----
    if (t_140094bd5 == 0x1a_u32) {
        /* -> bb131 */
    } else {
        /* -> bb155 */
    }

    // ---- bb131 @ 0x140094bde ----
    /* 140094bde */ let mut t_140094bde: u32 = core::ptr::read((rdi).wrapping_add(0x2cc_u64) as *const u32);
    /* 140094bde */ r8 = (t_140094bde as u64);
    if (t_140094bd5 != 0x1a_u32) {
        /* -> bb136 */
    } else {
        /* -> bb135 */
    }

    // ---- bb135 @ 0x140094be8 ----
    if (t_140094bd5 != 0x1a_u32) {
        /* -> bb136 */
    } else {
        /* -> bb152 */
    }

    // ---- bb136 @ 0x140094bea ----
    if (SF == OF) {
        /* -> bb140 */
    } else {
        /* -> bb139 */
    }

    // ---- bb139 @ 0x140094bee ----
    if (SF == OF) {
        /* -> bb140 */
    } else {
        /* -> bb153 */
    }

    // ---- bb140 @ 0x140094bf0 ----
    /* 140094bf0 */ rcx = (0xa_u32 as u64);
    if (SF != OF) {
        /* -> bb143 */
    } else {
        /* -> bb144 */
    }

    // ---- bb144 @ 0x140094bfc ----
    /* 140094bfc */ rcx = ((r12 as u32) as u64);
    /* fallthrough -> bb143 */

    // ---- bb143 @ 0x140094c00 ----
    /* 140094c00 */ rax = ((r8 as u32) as u64);
    /* 140094c03 */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140094c04 */ let mut t_140094c04_0: u64 = (((((((rdx as u32) as u64) << 0x20_u64) | ((rax as u32) as u64)) as i64) / (((rcx as u32) as u64) as i64)) as u64);
    /* 140094c04 */ let mut t_140094c04_1: u64 = (((((((rdx as u32) as u64) << 0x20_u64) | ((rax as u32) as u64)) as i64) % (((rcx as u32) as u64) as i64)) as u64);
    /* 140094c04 */ rax = ((t_140094c04_0 as u32) as u64);
    /* 140094c04 */ rdx = ((t_140094c04_1 as u32) as u64);
    if ((r8 as u32) == 0x12c_u32) {
        /* -> bb152 */
    } else {
        /* -> bb151 */
    }

    // ---- bb151 @ 0x140094c08 ----
    if ((r8 as u32) == 0x12c_u32) {
        /* -> bb152 */
    } else {
        /* -> bb153 */
    }

    // ---- bb152 @ 0x140094c0a ----
    /* 140094c0a */ core::ptr::write((rdi).wrapping_add(0xe0_u64) as *mut u32, 0x1a_u32);
    /* fallthrough -> bb153 */

    // ---- bb153 @ 0x140094c14 ----
    /* 140094c14 */ r8 = (((r8 as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb156 */

    // ---- bb155 @ 0x140094c19 ----
    /* 140094c19 */ r8 = ((rsi as u32) as u64);
    /* fallthrough -> bb156 */

    // ---- bb156 @ 0x140094c1c ----
    /* 140094c1c */ core::ptr::write((rdi).wrapping_add(0x2cc_u64) as *mut u32, (r8 as u32));
    /* 140094c23 */ let mut t_140094c23: u32 = core::ptr::read((rdi).wrapping_add(0x1f8_u64) as *const u32);
    if (t_140094c23 == (rsi as u32)) {
        /* -> bb161 */
    } else {
        /* -> bb160 */
    }

    // ---- bb160 @ 0x140094c29 ----
    if (t_140094c23 == (rsi as u32)) {
        /* -> bb161 */
    } else {
        /* -> bb181 */
    }

    // ---- bb161 @ 0x140094c2b ----
    /* 140094c2b */ rdx = (rdi).wrapping_add(0x3b0_u64);
    /* 140094c32 */ let mut t_140094c32: u64 = core::ptr::read((rdx).wrapping_add(0x10_u64) as *const u64);
    if (t_140094c32 != rsi) {
        /* -> bb166 */
    } else {
        /* -> bb165 */
    }

    // ---- bb165 @ 0x140094c36 ----
    if (t_140094c32 != rsi) {
        /* -> bb166 */
    } else {
        /* -> bb181 */
    }

    // ---- bb166 @ 0x140094c38 ----
    /* 140094c38 */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, 0x1_u32);
    /* 140094c42 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140094c47 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140094c4e */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140094c53 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 140094c58 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 140094c61 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, (rsi as u8));
    /* 140094c66 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140094c6b */ fn_1400279c0();
    /* 140094c71 */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 140094c76 */ rdx = rax;
    /* 140094c79 */ rcx = rdi;
    /* 140094c7c */ fn_1400947d0();
    /* fallthrough -> bb181 */

    // ---- bb181 @ 0x140094c81 ----
    /* 140094c81 */ rax = core::ptr::read((rdi).wrapping_add(0x60_u64) as *const u64);
    /* 140094c85 */ core::ptr::write((rax).wrapping_add(0xa60_u64) as *mut u32, 0x431d0000_u32);
    /* 140094c8f */ let mut t_140094c8f: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    if (t_140094c8f == 0x8_u32) {
        /* -> bb187 */
    } else {
        /* -> bb186 */
    }

    // ---- bb186 @ 0x140094c96 ----
    if (t_140094c8f == 0x8_u32) {
        /* -> bb187 */
    } else {
        /* -> bb212 */
    }

    // ---- bb187 @ 0x140094c98 ----
    /* 140094c98 */ let mut t_140094c98: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140094c98 == 0x3_u32) {
        /* -> bb191 */
    } else {
        /* -> bb190 */
    }

    // ---- bb190 @ 0x140094c9f ----
    if (t_140094c98 == 0x3_u32) {
        /* -> bb191 */
    } else {
        /* -> bb212 */
    }

    // ---- bb191 @ 0x140094ca1 ----
    /* 140094ca1 */ r8 = core::ptr::read((rdi).wrapping_add(0x60_u64) as *const u64);
    /* 140094ca5 */ let mut t_140094ca5: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140094ca5 */ rcx = (t_140094ca5 as u64);
    /* 140094cab */ rax = (0x88888889_u32 as u64);
    /* 140094cb0 */ let mut t_140094cb0_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 140094cb0 */ rdx = (((t_140094cb0_0 >> 0x20_u64) as u32) as u64);
    /* 140094cb0 */ rax = ((t_140094cb0_0 as u32) as u64);
    /* 140094cb2 */ let mut t_140094cb2_0: u32 = ((rdx as u32)).wrapping_add((rcx as u32));
    /* 140094cb2 */ rdx = (t_140094cb2_0 as u64);
    /* 140094cb4 */ rdx = (((((rdx as u32) as i64) >> ((0x3_u8 as u32) as i64)) as u64) as u64);
    /* 140094cb7 */ rax = ((rdx as u32) as u64);
    /* 140094cb9 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140094cbc */ let mut t_140094cbc_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 140094cbc */ rdx = (t_140094cbc_0 as u64);
    /* 140094cbe */ let mut t_140094cbe_0: u32 = ((rdx as u32) & 0x80000001_u32);
    /* 140094cbe */ rdx = (t_140094cbe_0 as u64);
    if (SF != OF) {
        /* -> bb204 */
    } else {
        /* -> bb203 */
    }

    // ---- bb203 @ 0x140094cc4 ----
    if (SF != OF) {
        /* -> bb204 */
    } else {
        /* -> bb207 */
    }

    // ---- bb204 @ 0x140094cc6 ----
    /* 140094cc6 */ rdx = (((rdx as u32)).wrapping_sub(0x1_u32) as u64);
    /* 140094cc8 */ let mut t_140094cc8_0: u32 = ((rdx as u32) | 0xfffffffe_u32);
    /* 140094cc8 */ rdx = (t_140094cc8_0 as u64);
    /* 140094ccb */ rdx = (((rdx as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb207 */

    // ---- bb207 @ 0x140094ccd ----
    /* 140094ccd */ let mut xmm0: u128 = ((rdx as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    // intrinsic: f3410f10 movss xmm1, dword ptr [r8 + 0xa60]
    // intrinsic: f30f5cc8 subss xmm1, xmm0
    // intrinsic: f3410f11 movss dword ptr [r8 + 0xa60], xmm1
    /* fallthrough -> bb212 */

    // ---- bb212 @ 0x140094cea ----
    // intrinsic: f3440f10 movss xmm15, dword ptr [rip + 0x277649]
    /* 140094cf3 */ let mut t_140094cf3: u8 = core::ptr::read((rdi).wrapping_add(0x2b0_u64) as *const u8);
    /* 140094cf3 */ rax = ((t_140094cf3 as u32) as u64);
    if (t_140094c98 != 0x3_u32) {
        /* -> bb218 */
    } else {
        /* -> bb217 */
    }

    // ---- bb217 @ 0x140094cfc ----
    if (t_140094c98 != 0x3_u32) {
        /* -> bb218 */
    } else {
        /* -> bb222 */
    }

    // ---- bb218 @ 0x140094cfe ----
    /* 140094cfe */ let mut t_140094cfe: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_140094cfe == 0x0_u8) {
        /* -> bb222 */
    } else {
        /* -> bb221 */
    }

    // ---- bb221 @ 0x140094d05 ----
    if (t_140094cfe == 0x0_u8) {
        /* -> bb222 */
    } else {
        /* -> bb3455 */
    }

    // ---- bb222 @ 0x140094d0b ----
    /* 140094d0b */ let mut t_140094d0b: u32 = core::ptr::read((rdi).wrapping_add(0xe0_u64) as *const u32);
    if (t_140094d0b != 0x19_u32) {
        /* -> bb226 */
    } else {
        /* -> bb225 */
    }

    // ---- bb225 @ 0x140094d12 ----
    if (t_140094d0b != 0x19_u32) {
        /* -> bb226 */
    } else {
        /* -> bb3433 */
    }

    // ---- bb226 @ 0x140094d18 ----
    if (t_140094d0b == 0x19_u32) {
        /* -> bb230 */
    } else {
        /* -> bb229 */
    }

    // ---- bb229 @ 0x140094d1a ----
    if (t_140094d0b == 0x19_u32) {
        /* -> bb230 */
    } else {
        /* -> bb3433 */
    }

    // ---- bb230 @ 0x140094d20 ----
    /* 140094d20 */ core::ptr::write((rdi).wrapping_add(0x15c_u64) as *mut u32, 0xffffffff_u32);
    /* 140094d2a */ let mut r15: u64 = (0x87_u32 as u64);
    /* 140094d30 */ let mut t_140094d30: u32 = core::ptr::read((rdi).wrapping_add(0xd8_u64) as *const u32);
    if (t_140094d30 == 0xffffffff_u32) {
        /* -> bb236 */
    } else {
        /* -> bb235 */
    }

    // ---- bb235 @ 0x140094d37 ----
    if (t_140094d30 == 0xffffffff_u32) {
        /* -> bb236 */
    } else {
        /* -> bb330 */
    }

    // ---- bb236 @ 0x140094d3d ----
    /* 140094d3d */ let mut t_140094d3d: u32 = core::ptr::read((0x140094d44_u64).wrapping_add(0x359194_u64) as *const u32);
    if (((SF != OF) | (t_140094d3d == 0x1_u32)) == false) { /* -> bb240 */ }
    if (((SF != OF) | (t_140094d3d == 0x1_u32)) != 0) { /* -> bb239 */ }

    // ---- bb239 @ 0x140094d44 ----
    if (((SF != OF) | (t_140094d3d == 0x1_u32)) == false) { /* -> bb240 */ }
    if (((SF != OF) | (t_140094d3d == 0x1_u32)) != 0) { /* -> bb330 */ }

    // ---- bb240 @ 0x140094d4a ----
    /* 140094d4a */ let mut t_140094d4a: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 140094d4a */ rax = (t_140094d4a as u64);
    /* 140094d50 */ let mut t_140094d50_0: u32 = ((rax as u32)).wrapping_sub(0x3_u32);
    /* 140094d50 */ rax = (t_140094d50_0 as u64);
    if (((CF == false) & ((rax as u32) != 0x1_u32)) == false) { /* -> bb246 */ }
    if (((CF == false) & ((rax as u32) != 0x1_u32)) != 0) { /* -> bb245 */ }

    // ---- bb245 @ 0x140094d56 ----
    if (((CF == false) & ((rax as u32) != 0x1_u32)) == false) { /* -> bb246 */ }
    if (((CF == false) & ((rax as u32) != 0x1_u32)) != 0) { /* -> bb330 */ }

    // ---- bb246 @ 0x140094d5c ----
    // intrinsic: f30f1087 movss xmm0, dword ptr [rdi + 0x114]
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x358c04]
    // intrinsic: f30f5ef8 divss xmm7, xmm0
    // intrinsic: f30f58bf addss xmm7, dword ptr [rdi + 0x10c]
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x358bf8]
    // intrinsic: f30f5ef0 divss xmm6, xmm0
    // intrinsic: f30f58b7 addss xmm6, dword ptr [rdi + 0x110]
    /* 140094d8c */ let mut r14: u64 = ((rsi as u32) as u64);
    /* 140094d8f */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140094d96 */ rax = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 140094d9d */ let mut t_140094d9d_0: u64 = (rax).wrapping_sub(rdx);
    /* 140094d9d */ rax = t_140094d9d_0;
    /* 140094da0 */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if ((rax as u32) != 0x1_u32) {
        /* -> bb262 */
    } else {
        /* -> bb261 */
    }

    // ---- bb261 @ 0x140094da7 ----
    if ((rax as u32) != 0x1_u32) {
        /* -> bb262 */
    } else {
        /* -> bb292 */
    }

    // ---- bb262 @ 0x140094da9 ----
    /* 140094da9 */ let mut rbx: u64 = rsi;
    /* fallthrough -> bb264 */

    // ---- bb264 @ 0x140094db0 ----
    /* 140094db0 */ let mut t_140094db0_0: u32 = 0x0_u32;
    /* 140094db0 */ let mut r9: u64 = (t_140094db0_0 as u64);
    /* 140094db3 */ let mut xmm2: u128 = xmm6;
    /* 140094db6 */ xmm1 = xmm7;
    /* 140094db9 */ rcx = core::ptr::read((rdx).wrapping_add((rbx).wrapping_mul(0x1_u64)) as *const u64);
    /* 140094dbd */ fn_1400b6fc0();
    if (rax != rcx) {
        /* -> bb273 */
    } else {
        /* -> bb272 */
    }

    // ---- bb272 @ 0x140094dc4 ----
    if (rax != rcx) {
        /* -> bb273 */
    } else {
        /* -> bb281 */
    }

    // ---- bb273 @ 0x140094dc6 ----
    /* 140094dc6 */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140094dcd */ rcx = core::ptr::read((rax).wrapping_add((rbx).wrapping_mul(0x1_u64)) as *const u64);
    /* 140094dd1 */ let mut t_140094dd1: u32 = core::ptr::read((rcx).wrapping_add(0x1f8_u64) as *const u32);
    if (t_140094dd1 != 0xffffffff_u32) {
        /* -> bb279 */
    } else {
        /* -> bb278 */
    }

    // ---- bb278 @ 0x140094dd8 ----
    if (t_140094dd1 != 0xffffffff_u32) {
        /* -> bb279 */
    } else {
        /* -> bb281 */
    }

    // ---- bb279 @ 0x140094dda ----
    /* 140094dda */ core::ptr::write((rdi).wrapping_add(0x15c_u64) as *mut u32, (r14 as u32));
    /* 140094de1 */ core::ptr::write((rdi).wrapping_add(0x124_u64) as *mut u32, 0x4_u32);
    /* fallthrough -> bb281 */

    // ---- bb281 @ 0x140094deb ----
    /* 140094deb */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140094dee */ let mut t_140094dee_0: u64 = (rbx).wrapping_add(0x8_u64);
    /* 140094dee */ rbx = t_140094dee_0;
    /* 140094df2 */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140094df9 */ rcx = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 140094e00 */ let mut t_140094e00_0: u64 = (rcx).wrapping_sub(rdx);
    /* 140094e00 */ rcx = t_140094e00_0;
    /* 140094e03 */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 140094e07 */ rax = (((r14 as u32) as i64) as u64);
    if (CF == false) { /* -> bb292 */ }
    if CF { /* -> bb291 */ }

    // ---- bb291 @ 0x140094e0d ----
    if CF { /* -> bb264 */ }
    if (CF == false) { /* -> bb292 */ }

    // ---- bb292 @ 0x140094e0f ----
    /* 140094e0f */ let mut t_140094e0f: u32 = core::ptr::read((rdi).wrapping_add(0x18c_u64) as *const u32);
    if (t_140094e0f != 0xffffffff_u32) {
        /* -> bb296 */
    } else {
        /* -> bb295 */
    }

    // ---- bb295 @ 0x140094e16 ----
    if (t_140094e0f != 0xffffffff_u32) {
        /* -> bb296 */
    } else {
        /* -> bb303 */
    }

    // ---- bb296 @ 0x140094e18 ----
    /* 140094e18 */ let mut t_140094e18: u32 = core::ptr::read((rdi).wrapping_add(0x190_u64) as *const u32);
    /* 140094e18 */ rax = (t_140094e18 as u64);
    /* 140094e1e */ let mut t_140094e1e_0: u32 = ((rax as u32)).wrapping_sub(0x10_u32);
    /* 140094e1e */ rax = (t_140094e1e_0 as u64);
    if (((CF == false) & ((rax as u32) != 0x2c_u32)) == false) { /* -> bb302 */ }
    if (((CF == false) & ((rax as u32) != 0x2c_u32)) != 0) { /* -> bb301 */ }

    // ---- bb301 @ 0x140094e24 ----
    if (((CF == false) & ((rax as u32) != 0x2c_u32)) == false) { /* -> bb302 */ }
    if (((CF == false) & ((rax as u32) != 0x2c_u32)) != 0) { /* -> bb303 */ }

    // ---- bb302 @ 0x140094e26 ----
    /* 140094e26 */ core::ptr::write((rdi).wrapping_add(0x124_u64) as *mut u32, 0xb_u32);
    /* fallthrough -> bb303 */

    // ---- bb303 @ 0x140094e30 ----
    /* 140094e30 */ rcx = core::ptr::read((rdi).wrapping_add(0x3a8_u64) as *const u64);
    if ((rax as u32) != 0x2c_u32) {
        /* -> bb308 */
    } else {
        /* -> bb307 */
    }

    // ---- bb307 @ 0x140094e3a ----
    if ((rax as u32) != 0x2c_u32) {
        /* -> bb308 */
    } else {
        /* -> bb330 */
    }

    // ---- bb308 @ 0x140094e3c ----
    /* 140094e3c */ let mut t_140094e3c: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140094e3c == 0x3_u32) {
        /* -> bb312 */
    } else {
        /* -> bb311 */
    }

    // ---- bb311 @ 0x140094e43 ----
    if (t_140094e3c == 0x3_u32) {
        /* -> bb312 */
    } else {
        /* -> bb330 */
    }

    // ---- bb312 @ 0x140094e45 ----
    /* 140094e45 */ let mut t_140094e45: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (((SF != OF) | (t_140094e45 == (r15 as u32))) == false) { /* -> bb316 */ }
    if (((SF != OF) | (t_140094e45 == (r15 as u32))) != 0) { /* -> bb315 */ }

    // ---- bb315 @ 0x140094e4c ----
    if (((SF != OF) | (t_140094e45 == (r15 as u32))) == false) { /* -> bb316 */ }
    if (((SF != OF) | (t_140094e45 == (r15 as u32))) != 0) { /* -> bb330 */ }

    // ---- bb316 @ 0x140094e4e ----
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x26e52e]
    // intrinsic: 0f2fc600 comiss xmm0, xmm6
    if (CF == false) { /* -> bb321 */ }
    if CF { /* -> bb320 */ }

    // ---- bb320 @ 0x140094e59 ----
    if (CF == false) { /* -> bb321 */ }
    if CF { /* -> bb330 */ }

    // ---- bb321 @ 0x140094e5b ----
    /* 140094e5b */ let mut t_140094e5b_0: u32 = 0x0_u32;
    /* 140094e5b */ r9 = (t_140094e5b_0 as u64);
    /* 140094e5e */ xmm2 = xmm6;
    /* 140094e61 */ xmm1 = xmm7;
    /* 140094e64 */ fn_1400b6fc0();
    if (t_140094e45 != (r15 as u32)) {
        /* -> bb329 */
    } else {
        /* -> bb328 */
    }

    // ---- bb328 @ 0x140094e6b ----
    if (t_140094e45 != (r15 as u32)) {
        /* -> bb329 */
    } else {
        /* -> bb330 */
    }

    // ---- bb329 @ 0x140094e6d ----
    /* 140094e6d */ core::ptr::write((rdi).wrapping_add(0x124_u64) as *mut u32, 0xa_u32);
    /* fallthrough -> bb330 */

    // ---- bb330 @ 0x140094e77 ----
    /* 140094e77 */ let mut t_140094e77: u32 = core::ptr::read((rdi).wrapping_add(0x324_u64) as *const u32);
    /* 140094e77 */ rax = (t_140094e77 as u64);
    if (((SF != OF) | (t_140094e45 == (r15 as u32))) == false) { /* -> bb335 */ }
    if (((SF != OF) | (t_140094e45 == (r15 as u32))) != 0) { /* -> bb334 */ }

    // ---- bb334 @ 0x140094e7f ----
    if (((SF != OF) | (t_140094e45 == (r15 as u32))) == false) { /* -> bb335 */ }
    if (((SF != OF) | (t_140094e45 == (r15 as u32))) != 0) { /* -> bb338 */ }

    // ---- bb335 @ 0x140094e81 ----
    /* 140094e81 */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    /* 140094e83 */ core::ptr::write((rdi).wrapping_add(0x324_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb422 */

    // ---- bb338 @ 0x140094e8e ----
    /* 140094e8e */ let mut t_140094e8e: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (((SF == OF) & (t_140094e8e != 0x8_u32)) == false) { /* -> bb342 */ }
    if (((SF == OF) & (t_140094e8e != 0x8_u32)) != 0) { /* -> bb341 */ }

    // ---- bb341 @ 0x140094e95 ----
    if (((SF == OF) & (t_140094e8e != 0x8_u32)) == false) { /* -> bb342 */ }
    if (((SF == OF) & (t_140094e8e != 0x8_u32)) != 0) { /* -> bb422 */ }

    // ---- bb342 @ 0x140094e9b ----
    /* 140094e9b */ let mut t_140094e9b: u8 = core::ptr::read((rdi).wrapping_add(0xb0_u64) as *const u8);
    if (t_140094e9b == 0x0_u8) {
        /* -> bb346 */
    } else {
        /* -> bb345 */
    }

    // ---- bb345 @ 0x140094ea2 ----
    if (t_140094e9b == 0x0_u8) {
        /* -> bb346 */
    } else {
        /* -> bb422 */
    }

    // ---- bb346 @ 0x140094ea8 ----
    /* 140094ea8 */ let mut t_140094ea8: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    /* 140094ea8 */ r15 = ((t_140094ea8 as u32) as u64);
    /* 140094eb0 */ r14 = ((rsi as u32) as u64);
    /* 140094eb3 */ r8 = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140094eba */ rax = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 140094ec1 */ let mut t_140094ec1_0: u64 = (rax).wrapping_sub(r8);
    /* 140094ec1 */ rax = t_140094ec1_0;
    /* 140094ec4 */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (t_140094e9b != 0x0_u8) {
        /* -> bb356 */
    } else {
        /* -> bb355 */
    }

    // ---- bb355 @ 0x140094ecb ----
    if (t_140094e9b != 0x0_u8) {
        /* -> bb356 */
    } else {
        /* -> bb386 */
    }

    // ---- bb356 @ 0x140094ecd ----
    /* 140094ecd */ rbx = rsi;
    /* fallthrough -> bb357 */

    // ---- bb357 @ 0x140094ed0 ----
    /* 140094ed0 */ rdx = (((r15 as u8) as u32) as u64);
    /* 140094ed4 */ rcx = core::ptr::read((r8).wrapping_add((rbx).wrapping_mul(0x1_u64)) as *const u64);
    /* 140094ed8 */ fn_1400b9530();
    /* 140094edd */ rcx = core::ptr::read((rdi).wrapping_add(0x378_u64) as *const u64);
    /* 140094ee4 */ let mut t_140094ee4: u64 = core::ptr::read((rdi).wrapping_add(0x380_u64) as *const u64);
    if (rcx != t_140094ee4) {
        /* -> bb365 */
    } else {
        /* -> bb364 */
    }

    // ---- bb364 @ 0x140094eeb ----
    if (rcx != t_140094ee4) {
        /* -> bb365 */
    } else {
        /* -> bb368 */
    }

    // ---- bb365 @ 0x140094eed ----
    /* 140094eed */ rdx = (((r15 as u8) as u32) as u64);
    /* 140094ef1 */ rcx = core::ptr::read((rbx).wrapping_add((rcx).wrapping_mul(0x1_u64)) as *const u64);
    /* 140094ef5 */ fn_1400b9530();
    /* fallthrough -> bb368 */

    // ---- bb368 @ 0x140094efa ----
    /* 140094efa */ rcx = core::ptr::read((rdi).wrapping_add(0x3a8_u64) as *const u64);
    if (rcx != t_140094ee4) {
        /* -> bb373 */
    } else {
        /* -> bb372 */
    }

    // ---- bb372 @ 0x140094f04 ----
    if (rcx != t_140094ee4) {
        /* -> bb373 */
    } else {
        /* -> bb375 */
    }

    // ---- bb373 @ 0x140094f06 ----
    /* 140094f06 */ let mut t_140094f06_0: u32 = 0x0_u32;
    /* 140094f06 */ rdx = (t_140094f06_0 as u64);
    /* 140094f08 */ fn_1400b9530();
    /* fallthrough -> bb375 */

    // ---- bb375 @ 0x140094f0d ----
    /* 140094f0d */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140094f10 */ let mut t_140094f10_0: u64 = (rbx).wrapping_add(0x8_u64);
    /* 140094f10 */ rbx = t_140094f10_0;
    /* 140094f14 */ r8 = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140094f1b */ rcx = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 140094f22 */ let mut t_140094f22_0: u64 = (rcx).wrapping_sub(r8);
    /* 140094f22 */ rcx = t_140094f22_0;
    /* 140094f25 */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 140094f29 */ rax = (((r14 as u32) as i64) as u64);
    if (CF == false) { /* -> bb386 */ }
    if CF { /* -> bb385 */ }

    // ---- bb385 @ 0x140094f2f ----
    if CF { /* -> bb357 */ }
    if (CF == false) { /* -> bb386 */ }

    // ---- bb386 @ 0x140094f31 ----
    /* 140094f31 */ rcx = core::ptr::read((rdi).wrapping_add(0x98_u64) as *const u64);
    if (rax != rcx) {
        /* -> bb391 */
    } else {
        /* -> bb390 */
    }

    // ---- bb390 @ 0x140094f3b ----
    if (rax != rcx) {
        /* -> bb391 */
    } else {
        /* -> bb395 */
    }

    // ---- bb391 @ 0x140094f3d ----
    /* 140094f3d */ r9 = (0x4_u32 as u64);
    /* 140094f43 */ r8 = ((r9 as u32) as u64);
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x26f062]
    /* 140094f4e */ fn_140007610();
    /* fallthrough -> bb395 */

    // ---- bb395 @ 0x140094f53 ----
    /* 140094f53 */ rbx = core::ptr::read((rdi).wrapping_add(0xa0_u64) as *const u64);
    if (rax != rcx) {
        /* -> bb400 */
    } else {
        /* -> bb399 */
    }

    // ---- bb399 @ 0x140094f5d ----
    if (rax != rcx) {
        /* -> bb400 */
    } else {
        /* -> bb421 */
    }

    // ---- bb400 @ 0x140094f5f ----
    /* 140094f5f */ rcx = (rbx).wrapping_add(0xc_u64);
    /* 140094f63 */ fn_14000f890();
    if (rax != rcx) {
        /* -> bb406 */
    } else {
        /* -> bb405 */
    }

    // ---- bb405 @ 0x140094f6a ----
    if (rax != rcx) {
        /* -> bb406 */
    } else {
        /* -> bb420 */
    }

    // ---- bb406 @ 0x140094f6c ----
    /* 140094f6c */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb407 */ }
    if DF { /* -> bb408 */ }

    // ---- bb407 @ 0x140094f6c ----
    /* 140094f6c */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140094f6c */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb409 */

    // ---- bb408 @ 0x140094f6c ----
    /* 140094f6c */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140094f6c */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb409 */

    // ---- bb409 @ 0x140094f71 ----
    /* 140094f71 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb411 */ }
    if DF { /* -> bb412 */ }

    // ---- bb411 @ 0x140094f71 ----
    /* 140094f71 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140094f71 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb413 */

    // ---- bb412 @ 0x140094f71 ----
    /* 140094f71 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140094f71 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb413 */

    // ---- bb413 @ 0x140094f76 ----
    /* 140094f76 */ rcx = (rbp).wrapping_add(0x60_u64);
    /* 140094f7a */ fn_14000f890();
    if (rax == rcx) {
        /* -> bb420 */
    } else {
        /* -> bb419 */
    }

    // ---- bb419 @ 0x140094f81 ----
    if (rax == rcx) {
        /* -> bb420 */
    } else {
        /* -> bb421 */
    }

    // ---- bb420 @ 0x140094f83 ----
    /* 140094f83 */ core::ptr::write((rdi).wrapping_add(0xb0_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb421 */

    // ---- bb421 @ 0x140094f8a ----
    /* 140094f8a */ r15 = (0x87_u32 as u64);
    /* fallthrough -> bb422 */

    // ---- bb422 @ 0x140094f90 ----
    /* 140094f90 */ let mut t_140094f90: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 140094f90 */ rax = (t_140094f90 as u64);
    /* 140094f96 */ let mut t_140094f96_0: u32 = ((rax as u32)).wrapping_sub(0x3_u32);
    /* 140094f96 */ rax = (t_140094f96_0 as u64);
    if (((CF == false) & ((rax as u32) != 0x1_u32)) == false) { /* -> bb428 */ }
    if (((CF == false) & ((rax as u32) != 0x1_u32)) != 0) { /* -> bb427 */ }

    // ---- bb427 @ 0x140094f9c ----
    if (((CF == false) & ((rax as u32) != 0x1_u32)) == false) { /* -> bb428 */ }
    if (((CF == false) & ((rax as u32) != 0x1_u32)) != 0) { /* -> bb486 */ }

    // ---- bb428 @ 0x140094fa2 ----
    /* 140094fa2 */ let mut t_140094fa2: u32 = core::ptr::read((0x140094fa9_u64).wrapping_add(0x3589bf_u64) as *const u32);
    if (t_140094fa2 != 0x0_u32) {
        /* -> bb432 */
    } else {
        /* -> bb431 */
    }

    // ---- bb431 @ 0x140094fa9 ----
    if (t_140094fa2 != 0x0_u32) {
        /* -> bb432 */
    } else {
        /* -> bb446 */
    }

    // ---- bb432 @ 0x140094fab ----
    /* 140094fab */ let mut t_140094fab: u32 = core::ptr::read((rdi).wrapping_add(0x15c_u64) as *const u32);
    /* 140094fab */ rax = ((t_140094fab as i64) as u64);
    if ((rax as u32) != 0xffffffff_u32) {
        /* -> bb437 */
    } else {
        /* -> bb436 */
    }

    // ---- bb436 @ 0x140094fb5 ----
    if ((rax as u32) != 0xffffffff_u32) {
        /* -> bb437 */
    } else {
        /* -> bb446 */
    }

    // ---- bb437 @ 0x140094fb7 ----
    /* 140094fb7 */ rcx = rax;
    /* 140094fba */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140094fc1 */ rdx = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 140094fc5 */ let mut t_140094fc5: u32 = core::ptr::read((rdx).wrapping_add(0x1f8_u64) as *const u32);
    if (t_140094fc5 != 0xffffffff_u32) {
        /* -> bb444 */
    } else {
        /* -> bb443 */
    }

    // ---- bb443 @ 0x140094fcc ----
    if (t_140094fc5 != 0xffffffff_u32) {
        /* -> bb444 */
    } else {
        /* -> bb446 */
    }

    // ---- bb444 @ 0x140094fce ----
    /* 140094fce */ rcx = core::ptr::read((0x140094fd5_u64).wrapping_add(0x35904b_u64) as *const u64);
    /* 140094fd5 */ fn_14009c790();
    /* fallthrough -> bb446 */

    // ---- bb446 @ 0x140094fda ----
    /* 140094fda */ let mut t_140094fda: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140094fda == 0xf_u32) {
        /* -> bb450 */
    } else {
        /* -> bb449 */
    }

    // ---- bb449 @ 0x140094fe1 ----
    if (t_140094fda == 0xf_u32) {
        /* -> bb450 */
    } else {
        /* -> bb486 */
    }

    // ---- bb450 @ 0x140094fe3 ----
    /* 140094fe3 */ r14 = ((rsi as u32) as u64);
    /* 140094fe6 */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140094fed */ rax = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 140094ff4 */ let mut t_140094ff4_0: u64 = (rax).wrapping_sub(rdx);
    /* 140094ff4 */ rax = t_140094ff4_0;
    /* 140094ff7 */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (t_140094fda != 0xf_u32) {
        /* -> bb459 */
    } else {
        /* -> bb458 */
    }

    // ---- bb458 @ 0x140094ffe ----
    if (t_140094fda != 0xf_u32) {
        /* -> bb459 */
    } else {
        /* -> bb486 */
    }

    // ---- bb459 @ 0x140095000 ----
    /* 140095000 */ rbx = rsi;
    /* fallthrough -> bb460 */

    // ---- bb460 @ 0x140095003 ----
    /* 140095003 */ rax = core::ptr::read((rbx).wrapping_add((rdx).wrapping_mul(0x1_u64)) as *const u64);
    /* 140095007 */ let mut t_140095007: u32 = core::ptr::read((rax).wrapping_add(0x1c_u64) as *const u32);
    if (t_140095007 == 0x2_u32) {
        /* -> bb465 */
    } else {
        /* -> bb464 */
    }

    // ---- bb464 @ 0x14009500b ----
    if (t_140095007 == 0x2_u32) {
        /* -> bb465 */
    } else {
        /* -> bb475 */
    }

    // ---- bb465 @ 0x14009500d ----
    /* 14009500d */ rcx = (0xa_u32 as u64);
    /* 140095012 */ fn_1400c6990();
    if (t_140095007 == 0x2_u32) {
        /* -> bb471 */
    } else {
        /* -> bb470 */
    }

    // ---- bb470 @ 0x140095019 ----
    if (t_140095007 == 0x2_u32) {
        /* -> bb471 */
    } else {
        /* -> bb475 */
    }

    // ---- bb471 @ 0x14009501b ----
    /* 14009501b */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140095022 */ let mut t_140095022_0: u32 = 0x0_u32;
    /* 140095022 */ rdx = (t_140095022_0 as u64);
    /* 140095024 */ rcx = core::ptr::read((rbx).wrapping_add((rcx).wrapping_mul(0x1_u64)) as *const u64);
    /* 140095028 */ fn_1400b7fd0();
    /* fallthrough -> bb475 */

    // ---- bb475 @ 0x14009502d ----
    /* 14009502d */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140095030 */ let mut t_140095030_0: u64 = (rbx).wrapping_add(0x8_u64);
    /* 140095030 */ rbx = t_140095030_0;
    /* 140095034 */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 14009503b */ rcx = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 140095042 */ let mut t_140095042_0: u64 = (rcx).wrapping_sub(rdx);
    /* 140095042 */ rcx = t_140095042_0;
    /* 140095045 */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 140095049 */ rax = (((r14 as u32) as i64) as u64);
    if (CF == false) { /* -> bb486 */ }
    if CF { /* -> bb485 */ }

    // ---- bb485 @ 0x14009504f ----
    if CF { /* -> bb460 */ }
    if (CF == false) { /* -> bb486 */ }

    // ---- bb486 @ 0x140095051 ----
    /* 140095051 */ let mut t_140095051: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 140095051 */ rax = (t_140095051 as u64);
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x26e2f5]
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x26e365]
    // intrinsic: f3440f10 movss xmm14, dword ptr [rip + 0x307c34]
    if (rax == rcx) {
        /* -> bb494 */
    } else {
        /* -> bb493 */
    }

    // ---- bb493 @ 0x140095072 ----
    if (rax == rcx) {
        /* -> bb494 */
    } else {
        /* -> bb547 */
    }

    // ---- bb494 @ 0x140095078 ----
    /* 140095078 */ let mut t_140095078: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (((SF != OF) | (t_140095078 == 0x78_u32)) == false) { /* -> bb498 */ }
    if (((SF != OF) | (t_140095078 == 0x78_u32)) != 0) { /* -> bb497 */ }

    // ---- bb497 @ 0x14009507f ----
    if (((SF != OF) | (t_140095078 == 0x78_u32)) == false) { /* -> bb498 */ }
    if (((SF != OF) | (t_140095078 == 0x78_u32)) != 0) { /* -> bb2988 */ }

    // ---- bb498 @ 0x140095085 ----
    /* 140095085 */ let mut t_140095085: u32 = core::ptr::read((0x14009508b_u64).wrapping_add(0x3588dd_u64) as *const u32);
    if (t_140095085 != (rax as u32)) {
        /* -> bb502 */
    } else {
        /* -> bb501 */
    }

    // ---- bb501 @ 0x14009508b ----
    if (t_140095085 != (rax as u32)) {
        /* -> bb502 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb502 @ 0x140095091 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095094 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095099 */ xmm1 = core::ptr::read((0x1400950a1_u64).wrapping_add(0x26e34f_u64) as *const u128);
    /* 1400950a1 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm1);
    /* 1400950a7 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb507 */ }
    if DF { /* -> bb508 */ }

    // ---- bb507 @ 0x1400950a7 ----
    /* 1400950a7 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400950a7 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb509 */

    // ---- bb508 @ 0x1400950a7 ----
    /* 1400950a7 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400950a7 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb509 */

    // ---- bb509 @ 0x1400950af ----
    /* 1400950af */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb511 */ }
    if DF { /* -> bb512 */ }

    // ---- bb511 @ 0x1400950af ----
    /* 1400950af */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400950af */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb513 */

    // ---- bb512 @ 0x1400950af ----
    /* 1400950af */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400950af */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb513 */

    // ---- bb513 @ 0x1400950b5 ----
    /* 1400950b5 */ let mut t_1400950b5: u16 = core::ptr::read((0x1400950bc_u64).wrapping_add(0x276bec_u64) as *const u16);
    /* 1400950b5 */ rax = ((t_1400950b5 as u32) as u64);
    /* 1400950bc */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u16, (rax as u16));
    /* 1400950c1 */ core::ptr::write((rsp).wrapping_add(0x3a_u64) as *mut u8, 0x0_u8);
    /* 1400950c6 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400950cb */ let mut xmm3: u128 = xmm14;
    /* 1400950cf */ let mut t_1400950cf_0: u32 = 0x0_u32;
    /* 1400950cf */ r8 = (t_1400950cf_0 as u64);
    /* 1400950d2 */ rdx = (0x64_u32 as u64);
    /* 1400950d7 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 1400950dc */ fn_140040b90();
    /* 1400950e1 */ core::ptr::write((rdi).wrapping_add(0x2f4_u64) as *mut u32, (rax as u32));
    /* 1400950e7 */ rdx = core::ptr::read((rsp).wrapping_add(0x48_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb529 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb528 */ }

    // ---- bb528 @ 0x1400950f0 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb529 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb545 */ }

    // ---- bb529 @ 0x1400950f2 ----
    /* 1400950f2 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400950f5 */ rcx = core::ptr::read((rsp).wrapping_add(0x30_u64) as *const u64);
    /* 1400950fa */ rax = rcx;
    if (CF == false) { /* -> bb536 */ }
    if CF { /* -> bb535 */ }

    // ---- bb535 @ 0x140095104 ----
    if (CF == false) { /* -> bb536 */ }
    if CF { /* -> bb544 */ }

    // ---- bb536 @ 0x140095106 ----
    /* 140095106 */ let mut t_140095106_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140095106 */ rdx = t_140095106_0;
    /* 14009510a */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 14009510e */ let mut t_14009510e_0: u64 = (rax).wrapping_sub(rcx);
    /* 14009510e */ rax = t_14009510e_0;
    /* 140095111 */ let mut t_140095111_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140095111 */ rax = t_140095111_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb544 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb543 */ }

    // ---- bb543 @ 0x140095119 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb544 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3483 */ }

    // ---- bb544 @ 0x14009511f ----
    /* 14009511f */ fn_1402c7498();
    /* fallthrough -> bb545 */

    // ---- bb545 @ 0x140095124 ----
    /* 140095124 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0x1_u64);
    /* fallthrough -> bb2988 */

    // ---- bb547 @ 0x140095134 ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb551 */
    } else {
        /* -> bb550 */
    }

    // ---- bb550 @ 0x140095137 ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb551 */
    } else {
        /* -> bb564 */
    }

    // ---- bb551 @ 0x140095139 ----
    // intrinsic: f30f1087 movss xmm0, dword ptr [rdi + 0x10c]
    // intrinsic: f30f5cc7 subss xmm0, xmm7
    // intrinsic: f30f5fc6 maxss xmm0, xmm6
    // intrinsic: f30f1187 movss dword ptr [rdi + 0x10c], xmm0
    // intrinsic: 0f2ec600 ucomiss xmm0, xmm6
    if (PF == false) { /* -> bb559 */ }
    if PF { /* -> bb558 */ }

    // ---- bb558 @ 0x140095154 ----
    if (PF == false) { /* -> bb559 */ }
    if PF { /* -> bb2988 */ }

    // ---- bb559 @ 0x14009515a ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb562 */
    } else {
        /* -> bb561 */
    }

    // ---- bb561 @ 0x14009515a ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb562 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb562 @ 0x140095160 ----
    /* 140095160 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0x2_u64);
    /* fallthrough -> bb2988 */

    // ---- bb564 @ 0x140095170 ----
    if ((rax as u32) == 0x2_u32) {
        /* -> bb568 */
    } else {
        /* -> bb567 */
    }

    // ---- bb567 @ 0x140095173 ----
    if ((rax as u32) == 0x2_u32) {
        /* -> bb568 */
    } else {
        /* -> bb649 */
    }

    // ---- bb568 @ 0x140095179 ----
    /* 140095179 */ let mut t_140095179: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140095179 == 0x1_u32) {
        /* -> bb572 */
    } else {
        /* -> bb571 */
    }

    // ---- bb571 @ 0x140095180 ----
    if (t_140095179 == 0x1_u32) {
        /* -> bb572 */
    } else {
        /* -> bb615 */
    }

    // ---- bb572 @ 0x140095186 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095189 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 14009518e */ xmm1 = core::ptr::read((0x140095196_u64).wrapping_add(0x26ef1a_u64) as *const u128);
    /* 140095196 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm1);
    /* 14009519c */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb577 */ }
    if DF { /* -> bb578 */ }

    // ---- bb577 @ 0x14009519c ----
    /* 14009519c */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14009519c */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb579 */

    // ---- bb578 @ 0x14009519c ----
    /* 14009519c */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14009519c */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb579 */

    // ---- bb579 @ 0x1400951a4 ----
    /* 1400951a4 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb581 */ }
    if DF { /* -> bb582 */ }

    // ---- bb581 @ 0x1400951a4 ----
    /* 1400951a4 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400951a4 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb583 */

    // ---- bb582 @ 0x1400951a4 ----
    /* 1400951a4 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400951a4 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb583 */

    // ---- bb583 @ 0x1400951aa ----
    /* 1400951aa */ let mut t_1400951aa: u32 = core::ptr::read((0x1400951b0_u64).wrapping_add(0x276bd8_u64) as *const u32);
    /* 1400951aa */ rax = (t_1400951aa as u64);
    /* 1400951b0 */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u32, (rax as u32));
    /* 1400951b4 */ core::ptr::write((rsp).wrapping_add(0x3c_u64) as *mut u8, 0x0_u8);
    /* 1400951b9 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400951be */ xmm3 = xmm14;
    /* 1400951c2 */ let mut t_1400951c2_0: u32 = 0x0_u32;
    /* 1400951c2 */ r8 = (t_1400951c2_0 as u64);
    /* 1400951c5 */ rdx = (0x64_u32 as u64);
    /* 1400951ca */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 1400951cf */ fn_140040b90();
    /* 1400951d5 */ rdx = core::ptr::read((rsp).wrapping_add(0x48_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb599 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb598 */ }

    // ---- bb598 @ 0x1400951de ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb599 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb615 */ }

    // ---- bb599 @ 0x1400951e0 ----
    /* 1400951e0 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400951e3 */ rcx = core::ptr::read((rsp).wrapping_add(0x30_u64) as *const u64);
    /* 1400951e8 */ rax = rcx;
    if (CF == false) { /* -> bb606 */ }
    if CF { /* -> bb605 */ }

    // ---- bb605 @ 0x1400951f2 ----
    if (CF == false) { /* -> bb606 */ }
    if CF { /* -> bb614 */ }

    // ---- bb606 @ 0x1400951f4 ----
    /* 1400951f4 */ let mut t_1400951f4_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400951f4 */ rdx = t_1400951f4_0;
    /* 1400951f8 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400951fc */ let mut t_1400951fc_0: u64 = (rax).wrapping_sub(rcx);
    /* 1400951fc */ rax = t_1400951fc_0;
    /* 1400951ff */ let mut t_1400951ff_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 1400951ff */ rax = t_1400951ff_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb614 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb613 */ }

    // ---- bb613 @ 0x140095207 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb614 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3490 */ }

    // ---- bb614 @ 0x14009520d ----
    /* 14009520d */ fn_1402c7498();
    /* fallthrough -> bb615 */

    // ---- bb615 @ 0x140095212 ----
    /* 140095212 */ let mut t_140095212: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140095212 == 0x3c_u32) {
        /* -> bb619 */
    } else {
        /* -> bb618 */
    }

    // ---- bb618 @ 0x140095219 ----
    if (t_140095212 == 0x3c_u32) {
        /* -> bb619 */
    } else {
        /* -> bb643 */
    }

    // ---- bb619 @ 0x14009521f ----
    /* 14009521f */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095224 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14009522b */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140095230 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 140095235 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 14009523e */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, 0x0_u8);
    /* 140095243 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095248 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 14009524d */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095252 */ rcx = (0x20_u32 as u64);
    /* 140095257 */ fn_1400285e0();
    /* 14009525c */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140095261 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x14_u64);
    /* 14009526a */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x1f_u64);
    /* 140095273 */ xmm0 = core::ptr::read((0x14009527a_u64).wrapping_add(0x276b16_u64) as *const u128);
    /* 14009527a */ core::ptr::write(rax as *mut u128, xmm0);
    /* 14009527d */ let mut t_14009527d: u32 = core::ptr::read((0x140095283_u64).wrapping_add(0x276b1d_u64) as *const u32);
    /* 14009527d */ rcx = (t_14009527d as u64);
    /* 140095283 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u32, (rcx as u32));
    /* 140095286 */ core::ptr::write((rax).wrapping_add(0x14_u64) as *mut u8, 0x0_u8);
    /* 14009528a */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 14009528f */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 140095294 */ rcx = rdi;
    /* 140095297 */ fn_1400947d0();
    /* fallthrough -> bb643 */

    // ---- bb643 @ 0x14009529c ----
    /* 14009529c */ let mut t_14009529c: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_14009529c == 0xb4_u32) {
        /* -> bb647 */
    } else {
        /* -> bb646 */
    }

    // ---- bb646 @ 0x1400952a6 ----
    if (t_14009529c == 0xb4_u32) {
        /* -> bb647 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb647 @ 0x1400952ac ----
    /* 1400952ac */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0x3_u64);
    /* fallthrough -> bb2988 */

    // ---- bb649 @ 0x1400952bc ----
    if ((rax as u32) == 0x3_u32) {
        /* -> bb653 */
    } else {
        /* -> bb652 */
    }

    // ---- bb652 @ 0x1400952bf ----
    if ((rax as u32) == 0x3_u32) {
        /* -> bb653 */
    } else {
        /* -> bb1779 */
    }

    // ---- bb653 @ 0x1400952c5 ----
    /* 1400952c5 */ rcx = rdi;
    /* 1400952c8 */ fn_1400d2b50();
    /* 1400952cd */ let mut t_1400952cd: u32 = core::ptr::read((rdi).wrapping_add(0x124_u64) as *const u32);
    if (t_1400952cd == 0xa_u32) {
        /* -> bb659 */
    } else {
        /* -> bb658 */
    }

    // ---- bb658 @ 0x1400952d4 ----
    if (t_1400952cd == 0xa_u32) {
        /* -> bb659 */
    } else {
        /* -> bb686 */
    }

    // ---- bb659 @ 0x1400952da ----
    /* 1400952da */ let mut t_1400952da: u32 = core::ptr::read((0x1400952e1_u64).wrapping_add(0x358687_u64) as *const u32);
    if (t_1400952da != 0x0_u32) {
        /* -> bb663 */
    } else {
        /* -> bb662 */
    }

    // ---- bb662 @ 0x1400952e1 ----
    if (t_1400952da != 0x0_u32) {
        /* -> bb663 */
    } else {
        /* -> bb686 */
    }

    // ---- bb663 @ 0x1400952e7 ----
    /* 1400952e7 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 1400952ec */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400952f3 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 1400952f8 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 1400952fd */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 140095306 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, 0x0_u8);
    /* 14009530b */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095310 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 140095315 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 14009531a */ rcx = (0x20_u32 as u64);
    /* 14009531f */ fn_1400285e0();
    /* 140095324 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140095329 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x10_u64);
    /* 140095332 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x1f_u64);
    /* 14009533b */ xmm0 = core::ptr::read((0x140095342_u64).wrapping_add(0x276a66_u64) as *const u128);
    /* 140095342 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140095345 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u8, 0x0_u8);
    /* 140095349 */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 14009534e */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 140095353 */ rcx = rdi;
    /* 140095356 */ fn_1400947d0();
    /* 14009535b */ core::ptr::write((0x140095361_u64).wrapping_add(0x358607_u64) as *mut u32, (rsi as u32));
    /* fallthrough -> bb686 */

    // ---- bb686 @ 0x140095361 ----
    /* 140095361 */ let mut t_140095361: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140095361 == 0x1_u32) {
        /* -> bb690 */
    } else {
        /* -> bb689 */
    }

    // ---- bb689 @ 0x140095368 ----
    if (t_140095361 == 0x1_u32) {
        /* -> bb690 */
    } else {
        /* -> bb737 */
    }

    // ---- bb690 @ 0x14009536e ----
    /* 14009536e */ let mut t_14009536e: u32 = core::ptr::read((0x140095375_u64).wrapping_add(0x358b63_u64) as *const u32);
    if (((SF != OF) | (t_14009536e == 0x1_u32)) == false) { /* -> bb694 */ }
    if (((SF != OF) | (t_14009536e == 0x1_u32)) != 0) { /* -> bb693 */ }

    // ---- bb693 @ 0x140095375 ----
    if (((SF != OF) | (t_14009536e == 0x1_u32)) == false) { /* -> bb694 */ }
    if (((SF != OF) | (t_14009536e == 0x1_u32)) != 0) { /* -> bb737 */ }

    // ---- bb694 @ 0x14009537b ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14009537e */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095383 */ xmm1 = core::ptr::read((0x14009538b_u64).wrapping_add(0x26ed25_u64) as *const u128);
    /* 14009538b */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm1);
    /* 140095391 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb699 */ }
    if DF { /* -> bb700 */ }

    // ---- bb699 @ 0x140095391 ----
    /* 140095391 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140095391 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb701 */

    // ---- bb700 @ 0x140095391 ----
    /* 140095391 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140095391 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb701 */

    // ---- bb701 @ 0x140095399 ----
    /* 140095399 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb703 */ }
    if DF { /* -> bb704 */ }

    // ---- bb703 @ 0x140095399 ----
    /* 140095399 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140095399 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb705 */

    // ---- bb704 @ 0x140095399 ----
    /* 140095399 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140095399 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb705 */

    // ---- bb705 @ 0x14009539f ----
    /* 14009539f */ let mut t_14009539f: u32 = core::ptr::read((0x1400953a5_u64).wrapping_add(0x2769e3_u64) as *const u32);
    /* 14009539f */ rax = (t_14009539f as u64);
    /* 1400953a5 */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u32, (rax as u32));
    /* 1400953a9 */ core::ptr::write((rsp).wrapping_add(0x3c_u64) as *mut u8, 0x0_u8);
    /* 1400953ae */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400953b3 */ xmm3 = xmm14;
    /* 1400953b7 */ let mut t_1400953b7_0: u32 = 0x0_u32;
    /* 1400953b7 */ r8 = (t_1400953b7_0 as u64);
    /* 1400953ba */ rdx = (0x64_u32 as u64);
    /* 1400953bf */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 1400953c4 */ fn_140040b90();
    /* 1400953ca */ rdx = core::ptr::read((rsp).wrapping_add(0x48_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb721 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb720 */ }

    // ---- bb720 @ 0x1400953d3 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb721 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb737 */ }

    // ---- bb721 @ 0x1400953d5 ----
    /* 1400953d5 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400953d8 */ rcx = core::ptr::read((rsp).wrapping_add(0x30_u64) as *const u64);
    /* 1400953dd */ rax = rcx;
    if (CF == false) { /* -> bb728 */ }
    if CF { /* -> bb727 */ }

    // ---- bb727 @ 0x1400953e7 ----
    if (CF == false) { /* -> bb728 */ }
    if CF { /* -> bb736 */ }

    // ---- bb728 @ 0x1400953e9 ----
    /* 1400953e9 */ let mut t_1400953e9_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400953e9 */ rdx = t_1400953e9_0;
    /* 1400953ed */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400953f1 */ let mut t_1400953f1_0: u64 = (rax).wrapping_sub(rcx);
    /* 1400953f1 */ rax = t_1400953f1_0;
    /* 1400953f4 */ let mut t_1400953f4_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 1400953f4 */ rax = t_1400953f4_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb736 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb735 */ }

    // ---- bb735 @ 0x1400953fc ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb736 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3497 */ }

    // ---- bb736 @ 0x140095402 ----
    /* 140095402 */ fn_1402c7498();
    /* fallthrough -> bb737 */

    // ---- bb737 @ 0x140095407 ----
    /* 140095407 */ let mut t_140095407: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140095407 */ rax = (t_140095407 as u64);
    if ((rax as u32) == 0xf_u32) {
        /* -> bb742 */
    } else {
        /* -> bb741 */
    }

    // ---- bb741 @ 0x140095410 ----
    if ((rax as u32) == 0xf_u32) {
        /* -> bb742 */
    } else {
        /* -> bb752 */
    }

    // ---- bb742 @ 0x140095412 ----
    /* 140095412 */ let mut t_140095412: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    if (t_140095412 == 0x3_u32) {
        /* -> bb746 */
    } else {
        /* -> bb745 */
    }

    // ---- bb745 @ 0x140095419 ----
    if (t_140095412 == 0x3_u32) {
        /* -> bb746 */
    } else {
        /* -> bb1290 */
    }

    // ---- bb746 @ 0x14009541f ----
    /* 14009541f */ let mut t_14009541f: u32 = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u32);
    if (SF == OF) {
        /* -> bb750 */
    } else {
        /* -> bb749 */
    }

    // ---- bb749 @ 0x140095426 ----
    if (SF == OF) {
        /* -> bb750 */
    } else {
        /* -> bb1290 */
    }

    // ---- bb750 @ 0x14009542c ----
    /* 14009542c */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, (r12 as u32));
    /* fallthrough -> bb1290 */

    // ---- bb752 @ 0x140095438 ----
    if ((rax as u32) == (r15 as u32)) {
        /* -> bb756 */
    } else {
        /* -> bb755 */
    }

    // ---- bb755 @ 0x14009543b ----
    if ((rax as u32) == (r15 as u32)) {
        /* -> bb756 */
    } else {
        /* -> bb1290 */
    }

    // ---- bb756 @ 0x140095441 ----
    /* 140095441 */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u64, rsi);
    /* 140095446 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x7_u64);
    /* 14009544f */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0xf_u64);
    /* 140095458 */ rax = core::ptr::read((0x14009545f_u64).wrapping_add(0x26de11_u64) as *const u64);
    /* 14009545f */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u32, (rax as u32));
    /* 140095463 */ let mut t_140095463: u16 = core::ptr::read((0x14009546a_u64).wrapping_add(0x26de0a_u64) as *const u16);
    /* 140095463 */ rax = ((t_140095463 as u32) as u64);
    /* 14009546a */ core::ptr::write((rsp).wrapping_add(0x34_u64) as *mut u16, (rax as u16));
    /* 14009546f */ let mut t_14009546f: u8 = core::ptr::read((0x140095476_u64).wrapping_add(0x26de00_u64) as *const u8);
    /* 14009546f */ rax = ((t_14009546f as u32) as u64);
    /* 140095476 */ core::ptr::write((rsp).wrapping_add(0x36_u64) as *mut u8, (rax as u8));
    /* 14009547a */ core::ptr::write((rsp).wrapping_add(0x37_u64) as *mut u8, 0x0_u8);
    /* 14009547f */ rdx = ((rdx & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 140095481 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140095486 */ fn_14003f340();
    /* 14009548b */ let mut t_14009548b: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    if (t_14009548b == 0x0_u32) {
        /* -> bb773 */
    } else {
        /* -> bb772 */
    }

    // ---- bb772 @ 0x140095492 ----
    if (t_14009548b == 0x0_u32) {
        /* -> bb773 */
    } else {
        /* -> bb796 */
    }

    // ---- bb773 @ 0x140095498 ----
    /* 140095498 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 14009549d */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400954a4 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 1400954a9 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 1400954ae */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 1400954b7 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, 0x0_u8);
    /* 1400954bc */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 1400954c1 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 1400954c6 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 1400954cb */ rcx = (0x30_u32 as u64);
    /* 1400954d0 */ fn_1400285e0();
    /* 1400954d5 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 1400954da */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x20_u64);
    /* 1400954e3 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x2f_u64);
    /* 1400954ec */ xmm0 = core::ptr::read((0x1400954f3_u64).wrapping_add(0x2768cd_u64) as *const u128);
    /* 1400954f3 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400954f6 */ xmm1 = core::ptr::read((0x1400954fd_u64).wrapping_add(0x2768d3_u64) as *const u128);
    /* 1400954fd */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 140095501 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140095505 */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 14009550a */ rdx = (rsp).wrapping_add(0x30_u64);
    /* fallthrough -> bb1288 */

    // ---- bb796 @ 0x140095514 ----
    /* 140095514 */ let mut t_140095514: u8 = core::ptr::read((rdi).wrapping_add(0x270_u64) as *const u8);
    if (t_140095514 != 0x0_u8) {
        /* -> bb800 */
    } else {
        /* -> bb799 */
    }

    // ---- bb799 @ 0x14009551b ----
    if (t_140095514 != 0x0_u8) {
        /* -> bb800 */
    } else {
        /* -> bb994 */
    }

    // ---- bb800 @ 0x140095521 ----
    /* 140095521 */ let mut t_140095521: u32 = core::ptr::read((rdi).wrapping_add(0x26c_u64) as *const u32);
    /* 140095521 */ rax = (t_140095521 as u64);
    /* 140095527 */ let mut t_140095527: u32 = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u32);
    /* 140095527 */ rcx = (t_140095527 as u64);
    if ((rcx as u32) == 0x3_u32) {
        /* -> bb806 */
    } else {
        /* -> bb805 */
    }

    // ---- bb805 @ 0x140095530 ----
    if ((rcx as u32) == 0x3_u32) {
        /* -> bb806 */
    } else {
        /* -> bb879 */
    }

    // ---- bb806 @ 0x140095536 ----
    /* 140095538 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 14009553d */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    if (SF != OF) {
        /* -> bb812 */
    } else {
        /* -> bb811 */
    }

    // ---- bb811 @ 0x140095541 ----
    if (SF != OF) {
        /* -> bb812 */
    } else {
        /* -> bb847 */
    }

    // ---- bb812 @ 0x140095547 ----
    /* 140095547 */ let mut t_140095547: u32 = core::ptr::read((rdi).wrapping_add(0x2c8_u64) as *const u32);
    /* 140095547 */ r8 = (t_140095547 as u64);
    /* 14009554e */ rdx = (0x140095555_u64).wrapping_add(0x276893_u64);
    /* 140095555 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14009555a */ fn_14008d720();
    /* 14009555f */ rbx = rax;
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095565 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 14009556a */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 14009556f */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095574 */ rcx = (0x50_u32 as u64);
    /* 140095579 */ fn_1400285e0();
    /* 14009557e */ rcx = rax;
    /* 140095581 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140095586 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x43_u64);
    /* 14009558f */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x4f_u64);
    /* 140095598 */ xmm0 = core::ptr::read((0x14009559f_u64).wrapping_add(0x276871_u64) as *const u128);
    /* 14009559f */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400955a2 */ xmm1 = core::ptr::read((0x1400955a9_u64).wrapping_add(0x276877_u64) as *const u128);
    /* 1400955a9 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 1400955ad */ xmm0 = core::ptr::read((0x1400955b4_u64).wrapping_add(0x27687c_u64) as *const u128);
    /* 1400955b4 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u128, xmm0);
    /* 1400955b8 */ xmm1 = core::ptr::read((0x1400955bf_u64).wrapping_add(0x276881_u64) as *const u128);
    /* 1400955bf */ core::ptr::write((rax).wrapping_add(0x30_u64) as *mut u128, xmm1);
    /* 1400955c3 */ let mut t_1400955c3: u16 = core::ptr::read((0x1400955ca_u64).wrapping_add(0x276886_u64) as *const u16);
    /* 1400955c3 */ rax = ((t_1400955c3 as u32) as u64);
    /* 1400955ca */ core::ptr::write((rcx).wrapping_add(0x40_u64) as *mut u16, (rax as u16));
    /* 1400955ce */ let mut t_1400955ce: u8 = core::ptr::read((0x1400955d5_u64).wrapping_add(0x27687d_u64) as *const u8);
    /* 1400955ce */ rax = ((t_1400955ce as u32) as u64);
    /* 1400955d5 */ core::ptr::write((rcx).wrapping_add(0x42_u64) as *mut u8, (rax as u8));
    /* 1400955d8 */ core::ptr::write((rcx).wrapping_add(0x43_u64) as *mut u8, 0x0_u8);
    /* 1400955dc */ r8 = rbx;
    /* 1400955df */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 1400955e4 */ rcx = rdi;
    /* 1400955e7 */ fn_1400947d0();
    /* 1400955ec */ let mut t_1400955ec: u32 = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u32);
    /* 1400955ec */ rax = (t_1400955ec as u64);
    /* 1400955f2 */ core::ptr::write((rdi).wrapping_add(0x26c_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb1290 */

    // ---- bb847 @ 0x1400955fd ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095600 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140095605 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 14009560a */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 140095613 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, 0x0_u8);
    /* 140095618 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 14009561d */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 140095622 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095627 */ rcx = (0x40_u32 as u64);
    /* 14009562c */ fn_1400285e0();
    /* 140095631 */ rcx = rax;
    /* 140095634 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140095639 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x3c_u64);
    /* 140095642 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x3f_u64);
    /* 14009564b */ xmm0 = core::ptr::read((0x140095652_u64).wrapping_add(0x276806_u64) as *const u128);
    /* 140095652 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140095655 */ xmm1 = core::ptr::read((0x14009565c_u64).wrapping_add(0x27680c_u64) as *const u128);
    /* 14009565c */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 140095660 */ xmm0 = core::ptr::read((0x140095667_u64).wrapping_add(0x276811_u64) as *const u128);
    /* 140095667 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u128, xmm0);
    /* 14009566b */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb868 */ }
    if DF { /* -> bb869 */ }

    // ---- bb868 @ 0x14009566b ----
    /* 14009566b */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14009566b */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb870 */

    // ---- bb869 @ 0x14009566b ----
    /* 14009566b */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14009566b */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb870 */

    // ---- bb870 @ 0x140095673 ----
    /* 140095673 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb872 */ }
    if DF { /* -> bb873 */ }

    // ---- bb872 @ 0x140095673 ----
    /* 140095673 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140095673 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb874 */

    // ---- bb873 @ 0x140095673 ----
    /* 140095673 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140095673 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb874 */

    // ---- bb874 @ 0x140095678 ----
    /* 140095678 */ let mut t_140095678: u32 = core::ptr::read((0x14009567e_u64).wrapping_add(0x276812_u64) as *const u32);
    /* 140095678 */ rax = (t_140095678 as u64);
    /* 14009567e */ core::ptr::write((rcx).wrapping_add(0x38_u64) as *mut u32, (rax as u32));
    /* 140095681 */ core::ptr::write((rcx).wrapping_add(0x3c_u64) as *mut u8, 0x0_u8);
    /* fallthrough -> bb930 */

    // ---- bb879 @ 0x14009568a ----
    if ((rcx as u32) == 0x2_u32) {
        /* -> bb883 */
    } else {
        /* -> bb882 */
    }

    // ---- bb882 @ 0x14009568d ----
    if ((rcx as u32) == 0x2_u32) {
        /* -> bb883 */
    } else {
        /* -> bb937 */
    }

    // ---- bb883 @ 0x140095693 ----
    if (SF != OF) {
        /* -> bb887 */
    } else {
        /* -> bb886 */
    }

    // ---- bb886 @ 0x140095695 ----
    if (SF != OF) {
        /* -> bb887 */
    } else {
        /* -> bb910 */
    }

    // ---- bb887 @ 0x140095697 ----
    /* 140095697 */ rax = (rsp).wrapping_add(0x30_u64);
    /* 14009569c */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 1400956a0 */ let mut t_1400956a0: u32 = core::ptr::read((rdi).wrapping_add(0x2c8_u64) as *const u32);
    /* 1400956a0 */ r8 = (t_1400956a0 as u64);
    /* 1400956a7 */ rdx = (0x1400956ae_u64).wrapping_add(0x2767ea_u64);
    /* 1400956ae */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 1400956b3 */ fn_14008d720();
    /* 1400956b8 */ rbx = rax;
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400956be */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 1400956c3 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 1400956c8 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rsi);
    /* 1400956cd */ r8 = (0x2a_u32 as u64);
    /* 1400956d3 */ rdx = (0x1400956da_u64).wrapping_add(0x2767d6_u64);
    /* 1400956da */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400956df */ fn_140027e30();
    /* 1400956e5 */ r8 = rbx;
    /* 1400956e8 */ rdx = (rsp).wrapping_add(0x58_u64);
    /* 1400956ed */ rcx = rdi;
    /* 1400956f0 */ fn_1400947d0();
    /* 1400956f5 */ let mut t_1400956f5: u32 = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u32);
    /* 1400956f5 */ rax = (t_1400956f5 as u64);
    /* 1400956fb */ core::ptr::write((rdi).wrapping_add(0x26c_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb1290 */

    // ---- bb910 @ 0x140095706 ----
    /* 140095706 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 14009570b */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095712 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140095717 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 14009571c */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rsi);
    /* 140095721 */ r8 = (0x21_u32 as u64);
    /* 140095727 */ rdx = (0x14009572e_u64).wrapping_add(0x2767b2_u64);
    /* 14009572e */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095733 */ fn_140027e30();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14009573c */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095741 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 140095746 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 14009574b */ r8 = (0x1e_u32 as u64);
    /* 140095751 */ rdx = (0x140095758_u64).wrapping_add(0x2767b0_u64);
    /* 140095758 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 14009575d */ fn_140027e30();
    /* fallthrough -> bb930 */

    // ---- bb930 @ 0x140095763 ----
    /* 140095763 */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 140095768 */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 14009576d */ rcx = rdi;
    /* 140095770 */ fn_1400947d0();
    /* 140095775 */ let mut t_140095775: u32 = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u32);
    /* 140095775 */ rax = (t_140095775 as u64);
    /* 14009577b */ core::ptr::write((rdi).wrapping_add(0x26c_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb1290 */

    // ---- bb937 @ 0x140095786 ----
    /* 140095788 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 14009578d */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    if (SF != OF) {
        /* -> bb943 */
    } else {
        /* -> bb942 */
    }

    // ---- bb942 @ 0x140095791 ----
    if (SF != OF) {
        /* -> bb943 */
    } else {
        /* -> bb969 */
    }

    // ---- bb943 @ 0x140095797 ----
    /* 140095797 */ let mut t_140095797: u32 = core::ptr::read((rdi).wrapping_add(0x2c8_u64) as *const u32);
    /* 140095797 */ r8 = (t_140095797 as u64);
    /* 14009579e */ rdx = (0x1400957a5_u64).wrapping_add(0x2766f3_u64);
    /* 1400957a5 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400957aa */ fn_14008d720();
    /* 1400957af */ rbx = rax;
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400957b5 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 1400957ba */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 1400957bf */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 1400957c4 */ rcx = (0x20_u32 as u64);
    /* 1400957c9 */ fn_1400285e0();
    /* 1400957ce */ rdx = rax;
    /* 1400957d1 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 1400957d6 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x17_u64);
    /* 1400957df */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x1f_u64);
    /* 1400957e8 */ xmm0 = core::ptr::read((0x1400957ef_u64).wrapping_add(0x276739_u64) as *const u128);
    /* 1400957ef */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400957f2 */ let mut t_1400957f2: u32 = core::ptr::read((0x1400957f8_u64).wrapping_add(0x276740_u64) as *const u32);
    /* 1400957f2 */ rcx = (t_1400957f2 as u64);
    /* 1400957f8 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u32, (rcx as u32));
    /* 1400957fb */ let mut t_1400957fb: u16 = core::ptr::read((0x140095802_u64).wrapping_add(0x27673a_u64) as *const u16);
    /* 1400957fb */ rcx = ((t_1400957fb as u32) as u64);
    /* 140095802 */ core::ptr::write((rax).wrapping_add(0x14_u64) as *mut u16, (rcx as u16));
    /* 140095806 */ let mut t_140095806: u8 = core::ptr::read((0x14009580d_u64).wrapping_add(0x276731_u64) as *const u8);
    /* 140095806 */ rax = ((t_140095806 as u32) as u64);
    /* 14009580d */ core::ptr::write((rdx).wrapping_add(0x16_u64) as *mut u8, (rax as u8));
    /* 140095810 */ core::ptr::write((rdx).wrapping_add(0x17_u64) as *mut u8, 0x0_u8);
    /* 140095814 */ r8 = rbx;
    /* fallthrough -> bb983 */

    // ---- bb969 @ 0x140095819 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14009581c */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140095821 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 140095826 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 14009582f */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, 0x0_u8);
    /* 140095834 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095839 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 14009583e */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095843 */ r8 = (0x17_u32 as u64);
    /* 140095849 */ rdx = (0x140095850_u64).wrapping_add(0x2766d8_u64);
    /* 140095850 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140095855 */ fn_140027e30();
    /* 14009585b */ r8 = (rsp).wrapping_add(0x58_u64);
    /* fallthrough -> bb983 */

    // ---- bb983 @ 0x140095860 ----
    /* 140095860 */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 140095865 */ rcx = rdi;
    /* 140095868 */ fn_1400947d0();
    /* 14009586d */ let mut t_14009586d: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    if (t_14009586d == 0x3_u32) {
        /* -> bb990 */
    } else {
        /* -> bb989 */
    }

    // ---- bb989 @ 0x140095874 ----
    if (t_14009586d == 0x3_u32) {
        /* -> bb990 */
    } else {
        /* -> bb991 */
    }

    // ---- bb990 @ 0x140095876 ----
    /* 140095876 */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, 0x4_u32);
    /* fallthrough -> bb991 */

    // ---- bb991 @ 0x140095880 ----
    /* 140095880 */ let mut t_140095880: u32 = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u32);
    /* 140095880 */ rax = (t_140095880 as u64);
    /* 140095886 */ core::ptr::write((rdi).wrapping_add(0x26c_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb1290 */

    // ---- bb994 @ 0x140095891 ----
    /* 140095891 */ let mut t_140095891: u32 = core::ptr::read((0x140095898_u64).wrapping_add(0x358640_u64) as *const u32);
    if (SF == OF) {
        /* -> bb998 */
    } else {
        /* -> bb997 */
    }

    // ---- bb997 @ 0x140095898 ----
    if (SF == OF) {
        /* -> bb998 */
    } else {
        /* -> bb1036 */
    }

    // ---- bb998 @ 0x14009589e ----
    /* 14009589e */ let mut t_14009589e: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    if (t_14009589e == 0x7_u32) {
        /* -> bb1002 */
    } else {
        /* -> bb1001 */
    }

    // ---- bb1001 @ 0x1400958a5 ----
    if (t_14009589e == 0x7_u32) {
        /* -> bb1002 */
    } else {
        /* -> bb1036 */
    }

    // ---- bb1002 @ 0x1400958ab ----
    /* 1400958ab */ rax = core::ptr::read((0x1400958b2_u64).wrapping_add(0x365936_u64) as *const u64);
    /* 1400958b2 */ let mut t_1400958b2: u32 = core::ptr::read((rax).wrapping_add(0x308_u64) as *const u32);
    if (SF == OF) {
        /* -> bb1007 */
    } else {
        /* -> bb1006 */
    }

    // ---- bb1006 @ 0x1400958b9 ----
    if (SF == OF) {
        /* -> bb1007 */
    } else {
        /* -> bb1036 */
    }

    // ---- bb1007 @ 0x1400958bb ----
    /* 1400958bb */ rax = core::ptr::read((rdi).wrapping_add(0x278_u64) as *const u64);
    if (t_1400958b2 != 0x64_u32) {
        /* -> bb1012 */
    } else {
        /* -> bb1011 */
    }

    // ---- bb1011 @ 0x1400958c5 ----
    if (t_1400958b2 != 0x64_u32) {
        /* -> bb1012 */
    } else {
        /* -> bb1033 */
    }

    // ---- bb1012 @ 0x1400958c7 ----
    /* 1400958c7 */ let mut t_1400958c7: u8 = core::ptr::read((rax).wrapping_add(0x26e_u64) as *const u8);
    if (t_1400958c7 == 0x0_u8) {
        /* -> bb1016 */
    } else {
        /* -> bb1015 */
    }

    // ---- bb1015 @ 0x1400958ce ----
    if (t_1400958c7 == 0x0_u8) {
        /* -> bb1016 */
    } else {
        /* -> bb1033 */
    }

    // ---- bb1016 @ 0x1400958d0 ----
    /* 1400958d0 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 1400958d5 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 1400958d9 */ rdx = (0x1400958e0_u64).wrapping_add(0x276660_u64);
    /* 1400958e0 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400958e5 */ fn_140027980();
    /* 1400958ea */ rbx = rax;
    /* 1400958ed */ rdx = (0x1400958f4_u64).wrapping_add(0x27666c_u64);
    /* 1400958f4 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 1400958f9 */ fn_140027980();
    /* 1400958ff */ r8 = rbx;
    /* 140095902 */ rdx = rax;
    /* 140095905 */ rcx = rdi;
    /* 140095908 */ fn_1400947d0();
    /* 14009590d */ rax = (0x8_u32 as u64);
    /* 140095912 */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb1290 */

    // ---- bb1033 @ 0x14009591d ----
    /* 14009591d */ rax = (0x9_u32 as u64);
    /* 140095922 */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb1290 */

    // ---- bb1036 @ 0x14009592d ----
    /* 14009592d */ let mut t_14009592d: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    /* 14009592d */ rdx = (t_14009592d as u64);
    if (t_1400958b2 == 0x64_u32) {
        /* -> bb1041 */
    } else {
        /* -> bb1040 */
    }

    // ---- bb1040 @ 0x140095935 ----
    if (t_1400958b2 == 0x64_u32) {
        /* -> bb1041 */
    } else {
        /* -> bb1068 */
    }

    // ---- bb1041 @ 0x14009593b ----
    /* 14009593b */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, 0x1_u32);
    /* 140095945 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 14009594a */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095951 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140095956 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 14009595b */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 140095964 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, (rdx as u8));
    /* 140095968 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 14009596d */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 140095972 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095977 */ rcx = (0x20_u32 as u64);
    /* 14009597c */ fn_1400285e0();
    /* 140095981 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140095986 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x14_u64);
    /* 14009598f */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x1f_u64);
    /* 140095998 */ xmm0 = core::ptr::read((0x14009599f_u64).wrapping_add(0x2765e9_u64) as *const u128);
    /* 14009599f */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400959a2 */ let mut t_1400959a2: u32 = core::ptr::read((0x1400959a8_u64).wrapping_add(0x2765f0_u64) as *const u32);
    /* 1400959a2 */ rcx = (t_1400959a2 as u64);
    /* 1400959a8 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u32, (rcx as u32));
    /* 1400959ab */ core::ptr::write((rax).wrapping_add(0x14_u64) as *mut u8, 0x0_u8);
    /* 1400959af */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 1400959b4 */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 1400959b9 */ rcx = rdi;
    /* 1400959bc */ fn_1400947d0();
    /* 1400959c1 */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, 0x8ca0_u32);
    /* fallthrough -> bb1290 */

    // ---- bb1068 @ 0x1400959d0 ----
    if ((rdx as u32) == 0x2_u32) {
        /* -> bb1072 */
    } else {
        /* -> bb1071 */
    }

    // ---- bb1071 @ 0x1400959d3 ----
    if ((rdx as u32) == 0x2_u32) {
        /* -> bb1072 */
    } else {
        /* -> bb1133 */
    }

    // ---- bb1072 @ 0x1400959d9 ----
    /* 1400959d9 */ rax = (rsp).wrapping_add(0x58_u64);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400959e1 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 1400959e6 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 1400959ea */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 1400959ef */ let mut t_1400959ef: u8 = core::ptr::read((rdi).wrapping_add(0x264_u64) as *const u8);
    if (t_1400959ef != 0x0_u8) {
        /* -> bb1081 */
    } else {
        /* -> bb1080 */
    }

    // ---- bb1080 @ 0x1400959f6 ----
    if (t_1400959ef != 0x0_u8) {
        /* -> bb1081 */
    } else {
        /* -> bb1112 */
    }

    // ---- bb1081 @ 0x1400959fc ----
    /* 1400959fc */ let mut t_1400959fc: u8 = core::ptr::read((rdi).wrapping_add(0x3d8_u64) as *const u8);
    if (t_1400959fc != 0x0_u8) {
        /* -> bb1085 */
    } else {
        /* -> bb1084 */
    }

    // ---- bb1084 @ 0x140095a03 ----
    if (t_1400959fc != 0x0_u8) {
        /* -> bb1085 */
    } else {
        /* -> bb1090 */
    }

    // ---- bb1085 @ 0x140095a05 ----
    /* 140095a05 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 140095a0e */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, 0x0_u8);
    /* 140095a13 */ r8 = (0x10_u32 as u64);
    /* 140095a19 */ rdx = (0x140095a20_u64).wrapping_add(0x276388_u64);
    /* fallthrough -> bb1121 */

    // ---- bb1090 @ 0x140095a25 ----
    /* 140095a25 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rsi);
    /* 140095a2a */ r8 = (0x10_u32 as u64);
    /* 140095a30 */ rdx = (0x140095a37_u64).wrapping_add(0x276371_u64);
    /* 140095a37 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095a3c */ fn_140027e30();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095a45 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095a4a */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 140095a4f */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095a54 */ r8 = (0x19_u32 as u64);
    /* 140095a5a */ rdx = (0x140095a61_u64).wrapping_add(0x27653f_u64);
    /* 140095a61 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140095a66 */ fn_140027e30();
    /* 140095a6c */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 140095a71 */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 140095a76 */ rcx = rdi;
    /* 140095a79 */ fn_1400947d0();
    /* 140095a7e */ core::ptr::write((rdi).wrapping_add(0x3d8_u64) as *mut u8, 0x1_u8);
    /* 140095a85 */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, 0x3_u32);
    /* fallthrough -> bb1290 */

    // ---- bb1112 @ 0x140095a94 ----
    /* 140095a94 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rsi);
    /* 140095a99 */ r8 = (0x10_u32 as u64);
    /* 140095a9f */ rdx = (0x140095aa6_u64).wrapping_add(0x276302_u64);
    /* 140095aa6 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095aab */ fn_140027e30();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095ab4 */ r8 = (0x1e_u32 as u64);
    /* 140095aba */ rdx = (0x140095ac1_u64).wrapping_add(0x2764ff_u64);
    /* fallthrough -> bb1121 */

    // ---- bb1121 @ 0x140095ac1 ----
    /* 140095ac1 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095ac6 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 140095acb */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095ad0 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140095ad5 */ fn_140027e30();
    /* 140095adb */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 140095ae0 */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 140095ae5 */ rcx = rdi;
    /* 140095ae8 */ fn_1400947d0();
    /* 140095aed */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, 0x3_u32);
    /* fallthrough -> bb1290 */

    // ---- bb1133 @ 0x140095afc ----
    /* 140095afc */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140095b03 */ rcx = core::ptr::read(rax as *const u64);
    /* 140095b06 */ let mut t_140095b06: u64 = core::ptr::read((rdi).wrapping_add(0x3a8_u64) as *const u64);
    if (t_140095b06 == rcx) {
        /* -> bb1139 */
    } else {
        /* -> bb1138 */
    }

    // ---- bb1138 @ 0x140095b0d ----
    if (t_140095b06 == rcx) {
        /* -> bb1139 */
    } else {
        /* -> bb1162 */
    }

    // ---- bb1139 @ 0x140095b0f ----
    /* 140095b0f */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095b14 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095b1b */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140095b20 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 140095b25 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rsi);
    /* 140095b2a */ r8 = (0xd_u32 as u64);
    /* 140095b30 */ rdx = (0x140095b37_u64).wrapping_add(0x2764a9_u64);
    /* 140095b37 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095b3c */ fn_140027e30();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095b45 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095b4a */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 140095b4f */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095b54 */ r8 = (0x10_u32 as u64);
    /* 140095b5a */ rdx = (0x140095b61_u64).wrapping_add(0x276247_u64);
    /* 140095b61 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140095b66 */ fn_140027e30();
    /* 140095b6c */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 140095b71 */ rdx = (rsp).wrapping_add(0x30_u64);
    /* fallthrough -> bb1288 */

    // ---- bb1162 @ 0x140095b7b ----
    /* 140095b7b */ let mut t_140095b7b: u32 = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u32);
    /* 140095b7b */ rax = (t_140095b7b as u64);
    if ((rax as u32) == 0x7_u32) {
        /* -> bb1167 */
    } else {
        /* -> bb1166 */
    }

    // ---- bb1166 @ 0x140095b84 ----
    if ((rax as u32) == 0x7_u32) {
        /* -> bb1167 */
    } else {
        /* -> bb1178 */
    }

    // ---- bb1167 @ 0x140095b86 ----
    if (SF == OF) {
        /* -> bb1171 */
    } else {
        /* -> bb1170 */
    }

    // ---- bb1170 @ 0x140095b89 ----
    if (SF == OF) {
        /* -> bb1171 */
    } else {
        /* -> bb1253 */
    }

    // ---- bb1171 @ 0x140095b8f ----
    /* 140095b8f */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095b94 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 140095b98 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095b9d */ fn_140027b00();
    /* 140095ba2 */ rbx = rax;
    /* 140095ba5 */ rdx = (0x140095bac_u64).wrapping_add(0x276444_u64);
    /* fallthrough -> bb1283 */

    // ---- bb1178 @ 0x140095bb1 ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb1182 */
    } else {
        /* -> bb1181 */
    }

    // ---- bb1181 @ 0x140095bb4 ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb1182 */
    } else {
        /* -> bb1193 */
    }

    // ---- bb1182 @ 0x140095bb6 ----
    if (SF == OF) {
        /* -> bb1186 */
    } else {
        /* -> bb1185 */
    }

    // ---- bb1185 @ 0x140095bb9 ----
    if (SF == OF) {
        /* -> bb1186 */
    } else {
        /* -> bb1253 */
    }

    // ---- bb1186 @ 0x140095bbf ----
    /* 140095bbf */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095bc4 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 140095bc8 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095bcd */ fn_140027b00();
    /* 140095bd2 */ rbx = rax;
    /* 140095bd5 */ rdx = (0x140095bdc_u64).wrapping_add(0x276444_u64);
    /* fallthrough -> bb1283 */

    // ---- bb1193 @ 0x140095be1 ----
    if ((rax as u32) == 0x4_u32) {
        /* -> bb1197 */
    } else {
        /* -> bb1196 */
    }

    // ---- bb1196 @ 0x140095be4 ----
    if ((rax as u32) == 0x4_u32) {
        /* -> bb1197 */
    } else {
        /* -> bb1208 */
    }

    // ---- bb1197 @ 0x140095be6 ----
    if (SF == OF) {
        /* -> bb1201 */
    } else {
        /* -> bb1200 */
    }

    // ---- bb1200 @ 0x140095be9 ----
    if (SF == OF) {
        /* -> bb1201 */
    } else {
        /* -> bb1253 */
    }

    // ---- bb1201 @ 0x140095bef ----
    /* 140095bef */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095bf4 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 140095bf8 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095bfd */ fn_140027b00();
    /* 140095c02 */ rbx = rax;
    /* 140095c05 */ rdx = (0x140095c0c_u64).wrapping_add(0x276434_u64);
    /* fallthrough -> bb1283 */

    // ---- bb1208 @ 0x140095c11 ----
    if ((rax as u32) == 0x3_u32) {
        /* -> bb1212 */
    } else {
        /* -> bb1211 */
    }

    // ---- bb1211 @ 0x140095c14 ----
    if ((rax as u32) == 0x3_u32) {
        /* -> bb1212 */
    } else {
        /* -> bb1223 */
    }

    // ---- bb1212 @ 0x140095c16 ----
    if (SF == OF) {
        /* -> bb1216 */
    } else {
        /* -> bb1215 */
    }

    // ---- bb1215 @ 0x140095c19 ----
    if (SF == OF) {
        /* -> bb1216 */
    } else {
        /* -> bb1253 */
    }

    // ---- bb1216 @ 0x140095c1b ----
    /* 140095c1b */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095c20 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 140095c24 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095c29 */ fn_140027b00();
    /* 140095c2e */ rbx = rax;
    /* 140095c31 */ rdx = (0x140095c38_u64).wrapping_add(0x276428_u64);
    /* fallthrough -> bb1283 */

    // ---- bb1223 @ 0x140095c3d ----
    if ((rax as u32) == 0x2_u32) {
        /* -> bb1227 */
    } else {
        /* -> bb1226 */
    }

    // ---- bb1226 @ 0x140095c40 ----
    if ((rax as u32) == 0x2_u32) {
        /* -> bb1227 */
    } else {
        /* -> bb1238 */
    }

    // ---- bb1227 @ 0x140095c42 ----
    if (SF == OF) {
        /* -> bb1231 */
    } else {
        /* -> bb1230 */
    }

    // ---- bb1230 @ 0x140095c45 ----
    if (SF == OF) {
        /* -> bb1231 */
    } else {
        /* -> bb1253 */
    }

    // ---- bb1231 @ 0x140095c47 ----
    /* 140095c47 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095c4c */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 140095c50 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095c55 */ fn_140027b00();
    /* 140095c5a */ rbx = rax;
    /* 140095c5d */ rdx = (0x140095c64_u64).wrapping_add(0x27641c_u64);
    /* fallthrough -> bb1283 */

    // ---- bb1238 @ 0x140095c69 ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb1242 */
    } else {
        /* -> bb1241 */
    }

    // ---- bb1241 @ 0x140095c6c ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb1242 */
    } else {
        /* -> bb1253 */
    }

    // ---- bb1242 @ 0x140095c6e ----
    if (SF == OF) {
        /* -> bb1246 */
    } else {
        /* -> bb1245 */
    }

    // ---- bb1245 @ 0x140095c71 ----
    if (SF == OF) {
        /* -> bb1246 */
    } else {
        /* -> bb1253 */
    }

    // ---- bb1246 @ 0x140095c73 ----
    /* 140095c73 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095c78 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 140095c7c */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095c81 */ fn_140027b00();
    /* 140095c86 */ rbx = rax;
    /* 140095c89 */ rdx = (0x140095c90_u64).wrapping_add(0x276410_u64);
    /* fallthrough -> bb1283 */

    // ---- bb1253 @ 0x140095c95 ----
    /* 140095c95 */ let mut t_140095c95: u8 = core::ptr::read((rdi).wrapping_add(0x3d8_u64) as *const u8);
    if (t_140095c95 == 0x0_u8) {
        /* -> bb1257 */
    } else {
        /* -> bb1256 */
    }

    // ---- bb1256 @ 0x140095c9c ----
    if (t_140095c95 == 0x0_u8) {
        /* -> bb1257 */
    } else {
        /* -> bb1277 */
    }

    // ---- bb1257 @ 0x140095c9e ----
    /* 140095c9e */ let mut t_140095c9e: u8 = core::ptr::read((rdi).wrapping_add(0x264_u64) as *const u8);
    if (t_140095c9e != 0x0_u8) {
        /* -> bb1261 */
    } else {
        /* -> bb1260 */
    }

    // ---- bb1260 @ 0x140095ca5 ----
    if (t_140095c9e != 0x0_u8) {
        /* -> bb1261 */
    } else {
        /* -> bb1277 */
    }

    // ---- bb1261 @ 0x140095ca7 ----
    /* 140095ca7 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095cac */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 140095cb0 */ rdx = (0x140095cb7_u64).wrapping_add(0x2760f1_u64);
    /* 140095cb7 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095cbc */ fn_140027980();
    /* 140095cc1 */ rbx = rax;
    /* 140095cc4 */ rdx = (0x140095ccb_u64).wrapping_add(0x2762d5_u64);
    /* 140095ccb */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140095cd0 */ fn_140027980();
    /* 140095cd6 */ r8 = rbx;
    /* 140095cd9 */ rdx = rax;
    /* 140095cdc */ rcx = rdi;
    /* 140095cdf */ fn_1400947d0();
    /* 140095ce4 */ core::ptr::write((rdi).wrapping_add(0x3d8_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb1290 */

    // ---- bb1277 @ 0x140095ced ----
    /* 140095ced */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095cf2 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    /* 140095cf6 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140095cfb */ fn_140027b00();
    /* 140095d00 */ rbx = rax;
    /* 140095d03 */ rdx = (0x140095d0a_u64).wrapping_add(0x27609e_u64);
    /* fallthrough -> bb1283 */

    // ---- bb1283 @ 0x140095d0a ----
    /* 140095d0a */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140095d0f */ fn_140027980();
    /* 140095d15 */ r8 = rbx;
    /* 140095d18 */ rdx = rax;
    /* fallthrough -> bb1288 */

    // ---- bb1288 @ 0x140095d1b ----
    /* 140095d1b */ rcx = rdi;
    /* 140095d1e */ fn_1400947d0();
    /* fallthrough -> bb1290 */

    // ---- bb1290 @ 0x140095d23 ----
    /* 140095d23 */ let mut t_140095d23: u32 = core::ptr::read((rdi).wrapping_add(0x3d0_u64) as *const u32);
    /* 140095d23 */ rax = (t_140095d23 as u64);
    if (((SF != OF) | ((rax as u32) == (r15 as u32))) == false) { /* -> bb1295 */ }
    if (((SF != OF) | ((rax as u32) == (r15 as u32))) != 0) { /* -> bb1294 */ }

    // ---- bb1294 @ 0x140095d2b ----
    if (((SF != OF) | ((rax as u32) == (r15 as u32))) == false) { /* -> bb1295 */ }
    if (((SF != OF) | ((rax as u32) == (r15 as u32))) != 0) { /* -> bb1471 */ }

    // ---- bb1295 @ 0x140095d31 ----
    /* 140095d31 */ let mut t_140095d31_0: u32 = ((rax as u32)).wrapping_sub(0x1_u32);
    /* 140095d31 */ rax = (t_140095d31_0 as u64);
    /* 140095d34 */ core::ptr::write((rdi).wrapping_add(0x3d0_u64) as *mut u32, (rax as u32));
    if ((rax as u32) == (r15 as u32)) {
        /* -> bb1300 */
    } else {
        /* -> bb1299 */
    }

    // ---- bb1299 @ 0x140095d3a ----
    if ((rax as u32) == (r15 as u32)) {
        /* -> bb1300 */
    } else {
        /* -> bb1471 */
    }

    // ---- bb1300 @ 0x140095d40 ----
    /* 140095d40 */ let mut t_140095d40: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    /* 140095d40 */ rax = (t_140095d40 as u64);
    if ((rax as u32) == (r15 as u32)) {
        /* -> bb1305 */
    } else {
        /* -> bb1304 */
    }

    // ---- bb1304 @ 0x140095d48 ----
    if ((rax as u32) == (r15 as u32)) {
        /* -> bb1305 */
    } else {
        /* -> bb1334 */
    }

    // ---- bb1305 @ 0x140095d4e ----
    /* 140095d4e */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, 0x1_u32);
    /* 140095d58 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095d5d */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095d64 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140095d69 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 140095d6e */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 140095d77 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, 0x0_u8);
    /* 140095d7c */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095d81 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 140095d86 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095d8b */ rcx = (0x20_u32 as u64);
    /* 140095d90 */ fn_1400285e0();
    /* 140095d95 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140095d9a */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x16_u64);
    /* 140095da3 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x1f_u64);
    /* 140095dac */ xmm0 = core::ptr::read((0x140095db3_u64).wrapping_add(0x276305_u64) as *const u128);
    /* 140095db3 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140095db6 */ let mut t_140095db6: u32 = core::ptr::read((0x140095dbc_u64).wrapping_add(0x27630c_u64) as *const u32);
    /* 140095db6 */ rcx = (t_140095db6 as u64);
    /* 140095dbc */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u32, (rcx as u32));
    /* 140095dbf */ let mut t_140095dbf: u16 = core::ptr::read((0x140095dc6_u64).wrapping_add(0x276306_u64) as *const u16);
    /* 140095dbf */ rcx = ((t_140095dbf as u32) as u64);
    /* 140095dc6 */ core::ptr::write((rax).wrapping_add(0x14_u64) as *mut u16, (rcx as u16));
    /* 140095dca */ core::ptr::write((rax).wrapping_add(0x16_u64) as *mut u8, 0x0_u8);
    /* 140095dce */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 140095dd3 */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 140095dd8 */ rcx = rdi;
    /* 140095ddb */ fn_1400947d0();
    /* 140095de0 */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, 0x1_u32);
    /* fallthrough -> bb1470 */

    // ---- bb1334 @ 0x140095def ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb1338 */
    } else {
        /* -> bb1337 */
    }

    // ---- bb1337 @ 0x140095df2 ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb1338 */
    } else {
        /* -> bb1369 */
    }

    // ---- bb1338 @ 0x140095df8 ----
    /* 140095df8 */ rax = core::ptr::read((rdi).wrapping_add(0x60_u64) as *const u64);
    /* 140095dfc */ core::ptr::write((rax).wrapping_add(0xa1d_u64) as *mut u8, 0x1_u8);
    /* 140095e03 */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, 0x1_u32);
    /* 140095e0d */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095e12 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095e19 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140095e1e */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 140095e23 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 140095e2c */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, 0x0_u8);
    /* 140095e31 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095e36 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 140095e3b */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095e40 */ rcx = (0x20_u32 as u64);
    /* 140095e45 */ fn_1400285e0();
    /* 140095e4a */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140095e4f */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x16_u64);
    /* 140095e58 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x1f_u64);
    /* 140095e61 */ xmm0 = core::ptr::read((0x140095e68_u64).wrapping_add(0x276268_u64) as *const u128);
    /* 140095e68 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140095e6b */ let mut t_140095e6b: u32 = core::ptr::read((0x140095e71_u64).wrapping_add(0x27626f_u64) as *const u32);
    /* 140095e6b */ rcx = (t_140095e6b as u64);
    /* 140095e71 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u32, (rcx as u32));
    /* 140095e74 */ let mut t_140095e74: u16 = core::ptr::read((0x140095e7b_u64).wrapping_add(0x276269_u64) as *const u16);
    /* 140095e74 */ rcx = ((t_140095e74 as u32) as u64);
    /* 140095e7b */ core::ptr::write((rax).wrapping_add(0x14_u64) as *mut u16, (rcx as u16));
    /* 140095e7f */ core::ptr::write((rax).wrapping_add(0x16_u64) as *mut u8, 0x0_u8);
    /* 140095e83 */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 140095e88 */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 140095e8d */ rcx = rdi;
    /* 140095e90 */ fn_1400947d0();
    /* 140095e95 */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, 0x2_u32);
    /* fallthrough -> bb1470 */

    // ---- bb1369 @ 0x140095ea4 ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb1373 */
    } else {
        /* -> bb1372 */
    }

    // ---- bb1372 @ 0x140095ea7 ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb1373 */
    } else {
        /* -> bb1416 */
    }

    // ---- bb1373 @ 0x140095ead ----
    /* 140095ead */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, 0x1_u32);
    /* 140095eb7 */ rax = (rsp).wrapping_add(0x30_u64);
    /* 140095ebc */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095ec3 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140095ec8 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 140095ecd */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140095ed2 */ rcx = (0x20_u32 as u64);
    /* 140095ed7 */ fn_1400285e0();
    /* 140095edc */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140095ee1 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x15_u64);
    /* 140095eea */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x1f_u64);
    /* 140095ef3 */ xmm0 = core::ptr::read((0x140095efa_u64).wrapping_add(0x2761ee_u64) as *const u128);
    /* 140095efa */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140095efd */ let mut t_140095efd: u32 = core::ptr::read((0x140095f03_u64).wrapping_add(0x2761f5_u64) as *const u32);
    /* 140095efd */ rdx = (t_140095efd as u64);
    /* 140095f03 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u32, (rdx as u32));
    /* 140095f06 */ let mut t_140095f06: u8 = core::ptr::read((0x140095f0d_u64).wrapping_add(0x2761ef_u64) as *const u8);
    /* 140095f06 */ rdx = ((t_140095f06 as u32) as u64);
    /* 140095f0d */ core::ptr::write((rax).wrapping_add(0x14_u64) as *mut u8, (rdx as u8));
    /* 140095f10 */ core::ptr::write((rax).wrapping_add(0x15_u64) as *mut u8, 0x0_u8);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095f17 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140095f1c */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 140095f21 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rsi);
    /* 140095f26 */ rcx = (0x30_u32 as u64);
    /* 140095f2b */ fn_1400285e0();
    /* 140095f30 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u64, rax);
    /* 140095f35 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0x25_u64);
    /* 140095f3e */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0x2f_u64);
    /* 140095f47 */ xmm0 = core::ptr::read((0x140095f4e_u64).wrapping_add(0x2761b2_u64) as *const u128);
    /* 140095f4e */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140095f51 */ xmm1 = core::ptr::read((0x140095f58_u64).wrapping_add(0x2761b8_u64) as *const u128);
    /* 140095f58 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 140095f5c */ let mut t_140095f5c: u32 = core::ptr::read((0x140095f62_u64).wrapping_add(0x2761be_u64) as *const u32);
    /* 140095f5c */ rcx = (t_140095f5c as u64);
    /* 140095f62 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u32, (rcx as u32));
    /* 140095f65 */ let mut t_140095f65: u8 = core::ptr::read((0x140095f6c_u64).wrapping_add(0x2761b8_u64) as *const u8);
    /* 140095f65 */ rcx = ((t_140095f65 as u32) as u64);
    /* 140095f6c */ core::ptr::write((rax).wrapping_add(0x24_u64) as *mut u8, (rcx as u8));
    /* 140095f6f */ core::ptr::write((rax).wrapping_add(0x25_u64) as *mut u8, 0x0_u8);
    /* 140095f73 */ r8 = (rsp).wrapping_add(0x30_u64);
    /* 140095f78 */ rdx = (rsp).wrapping_add(0x58_u64);
    /* 140095f7d */ rcx = rdi;
    /* 140095f80 */ fn_1400947d0();
    /* 140095f85 */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, 0x6_u32);
    /* fallthrough -> bb1470 */

    // ---- bb1416 @ 0x140095f94 ----
    if ((rax as u32) == 0x6_u32) {
        /* -> bb1420 */
    } else {
        /* -> bb1419 */
    }

    // ---- bb1419 @ 0x140095f97 ----
    if ((rax as u32) == 0x6_u32) {
        /* -> bb1420 */
    } else {
        /* -> bb1471 */
    }

    // ---- bb1420 @ 0x140095f9d ----
    /* 140095f9d */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, 0x1_u32);
    /* 140095fa7 */ rax = (rsp).wrapping_add(0x58_u64);
    /* 140095fac */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rax);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140095fb3 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140095fb8 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, rsi);
    /* 140095fbd */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rsi);
    /* 140095fc2 */ rcx = (0x20_u32 as u64);
    /* 140095fc7 */ fn_1400285e0();
    /* 140095fcc */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u64, rax);
    /* 140095fd1 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0x18_u64);
    /* 140095fda */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0x1f_u64);
    /* 140095fe3 */ xmm0 = core::ptr::read((0x140095fea_u64).wrapping_add(0x27613e_u64) as *const u128);
    /* 140095fea */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140095fed */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1435 */ }
    if DF { /* -> bb1436 */ }

    // ---- bb1435 @ 0x140095fed ----
    /* 140095fed */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140095fed */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1437 */

    // ---- bb1436 @ 0x140095fed ----
    /* 140095fed */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140095fed */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1437 */

    // ---- bb1437 @ 0x140095ff5 ----
    /* 140095ff5 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1439 */ }
    if DF { /* -> bb1440 */ }

    // ---- bb1439 @ 0x140095ff5 ----
    /* 140095ff5 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140095ff5 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1441 */

    // ---- bb1440 @ 0x140095ff5 ----
    /* 140095ff5 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140095ff5 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1441 */

    // ---- bb1441 @ 0x140095ffa ----
    /* 140095ffa */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u8, 0x0_u8);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140096001 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140096006 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 14009600b */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rsi);
    /* 140096010 */ rcx = (0x20_u32 as u64);
    /* 140096015 */ fn_1400285e0();
    /* 14009601a */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 14009601f */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x1c_u64);
    /* 140096028 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0x1f_u64);
    /* 140096031 */ xmm0 = core::ptr::read((0x140096038_u64).wrapping_add(0x276110_u64) as *const u128);
    /* 140096038 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 14009603b */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1455 */ }
    if DF { /* -> bb1456 */ }

    // ---- bb1455 @ 0x14009603b ----
    /* 14009603b */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14009603b */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1457 */

    // ---- bb1456 @ 0x14009603b ----
    /* 14009603b */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14009603b */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1457 */

    // ---- bb1457 @ 0x140096043 ----
    /* 140096043 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1459 */ }
    if DF { /* -> bb1460 */ }

    // ---- bb1459 @ 0x140096043 ----
    /* 140096043 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140096043 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1461 */

    // ---- bb1460 @ 0x140096043 ----
    /* 140096043 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140096043 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1461 */

    // ---- bb1461 @ 0x140096048 ----
    /* 140096048 */ let mut t_140096048: u32 = core::ptr::read((0x14009604e_u64).wrapping_add(0x276112_u64) as *const u32);
    /* 140096048 */ rcx = (t_140096048 as u64);
    /* 14009604e */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u32, (rcx as u32));
    /* 140096051 */ core::ptr::write((rax).wrapping_add(0x1c_u64) as *mut u8, 0x0_u8);
    /* 140096055 */ r8 = (rsp).wrapping_add(0x58_u64);
    /* 14009605a */ rdx = (rsp).wrapping_add(0x30_u64);
    /* 14009605f */ rcx = rdi;
    /* 140096062 */ fn_1400947d0();
    /* 140096067 */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, 0x7_u32);
    /* fallthrough -> bb1470 */

    // ---- bb1470 @ 0x140096071 ----
    /* 140096071 */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, 0x8ca0_u32);
    /* fallthrough -> bb1471 */

    // ---- bb1471 @ 0x14009607b ----
    /* 14009607b */ let mut t_14009607b: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    if (t_14009607b == 0x0_u32) {
        /* -> bb1475 */
    } else {
        /* -> bb1474 */
    }

    // ---- bb1474 @ 0x140096082 ----
    if (t_14009607b == 0x0_u32) {
        /* -> bb1475 */
    } else {
        /* -> bb1486 */
    }

    // ---- bb1475 @ 0x140096084 ----
    /* 140096084 */ let mut t_140096084: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (((SF != OF) | (t_140096084 == (r15 as u32))) == false) { /* -> bb1479 */ }
    if (((SF != OF) | (t_140096084 == (r15 as u32))) != 0) { /* -> bb1478 */ }

    // ---- bb1478 @ 0x14009608b ----
    if (((SF != OF) | (t_140096084 == (r15 as u32))) == false) { /* -> bb1479 */ }
    if (((SF != OF) | (t_140096084 == (r15 as u32))) != 0) { /* -> bb1486 */ }

    // ---- bb1479 @ 0x14009608d ----
    /* 14009608d */ let mut t_14009608d: u32 = core::ptr::read((rdi).wrapping_add(0x1f8_u64) as *const u32);
    if (t_14009608d == 0x0_u32) {
        /* -> bb1483 */
    } else {
        /* -> bb1482 */
    }

    // ---- bb1482 @ 0x140096094 ----
    if (t_14009608d == 0x0_u32) {
        /* -> bb1483 */
    } else {
        /* -> bb1486 */
    }

    // ---- bb1483 @ 0x140096096 ----
    /* 140096096 */ rdx = (0x4_u32 as u64);
    /* 14009609b */ rcx = rdi;
    /* 14009609e */ fn_14008ff20();
    /* fallthrough -> bb1486 */

    // ---- bb1486 @ 0x1400960a3 ----
    /* 1400960a3 */ let mut t_1400960a3: u32 = core::ptr::read((rdi).wrapping_add(0xe0_u64) as *const u32);
    /* 1400960a3 */ rcx = ((t_1400960a3 as i64) as u64);
    if (SF == OF) {
        /* -> bb1491 */
    } else {
        /* -> bb1490 */
    }

    // ---- bb1490 @ 0x1400960ad ----
    if (SF == OF) {
        /* -> bb1491 */
    } else {
        /* -> bb1576 */
    }

    // ---- bb1491 @ 0x1400960b3 ----
    /* 1400960b3 */ let mut t_1400960b3: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    /* 1400960b3 */ rax = (t_1400960b3 as u64);
    /* 1400960b9 */ let mut t_1400960b9_0: u32 = ((rax as u32)).wrapping_add(0x8_u32);
    /* 1400960b9 */ rax = (t_1400960b9_0 as u64);
    if (SF != OF) {
        /* -> bb1497 */
    } else {
        /* -> bb1496 */
    }

    // ---- bb1496 @ 0x1400960be ----
    if (SF != OF) {
        /* -> bb1497 */
    } else {
        /* -> bb1576 */
    }

    // ---- bb1497 @ 0x1400960c4 ----
    /* 1400960c4 */ r14 = (rcx).wrapping_sub(0x8_u64);
    /* 1400960c8 */ let mut t_1400960c8_0: u128 = ((r14 as u128)).wrapping_mul((0x70_u64 as u128));
    /* 1400960c8 */ rdx = (t_1400960c8_0 as u64);
    /* 1400960cc */ r8 = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 1400960d3 */ let mut t_1400960d3: u32 = core::ptr::read(((r8).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *const u32);
    if (t_1400960d3 == 0xffffffff_u32) {
        /* -> bb1504 */
    } else {
        /* -> bb1503 */
    }

    // ---- bb1503 @ 0x1400960d9 ----
    if (t_1400960d3 == 0xffffffff_u32) {
        /* -> bb1504 */
    } else {
        /* -> bb1566 */
    }

    // ---- bb1504 @ 0x1400960df ----
    /* 1400960df */ rbx = (rdi).wrapping_add(0x2bc_u64);
    /* 1400960e6 */ let mut t_1400960e6: u32 = core::ptr::read(rbx as *const u32);
    /* 1400960e6 */ rcx = (t_1400960e6 as u64);
    /* 1400960e8 */ rax = (((rcx).wrapping_add(0x1_u64) as u32) as u64);
    /* 1400960eb */ core::ptr::write(rbx as *mut u32, (rax as u32));
    /* 1400960ed */ core::ptr::write(((r8).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *mut u32, (rcx as u32));
    /* 1400960f2 */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400960f9 */ rcx = core::ptr::read((rcx).wrapping_add((r14).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400960fd */ fn_1400b87d0();
    /* 140096102 */ let mut t_140096102: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    if (SF != OF) {
        /* -> bb1516 */
    } else {
        /* -> bb1515 */
    }

    // ---- bb1515 @ 0x140096109 ----
    if (SF != OF) {
        /* -> bb1516 */
    } else {
        /* -> bb1545 */
    }

    // ---- bb1516 @ 0x14009610b ----
    /* 14009610b */ r9 = ((rsi as u32) as u64);
    /* 14009610e */ rax = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 140096115 */ let mut t_140096115: u64 = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140096115 */ let mut t_140096115_0: u64 = (rax).wrapping_sub(t_140096115);
    /* 140096115 */ rax = t_140096115_0;
    /* 14009611c */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (t_140096102 != 0x5_u32) {
        /* -> bb1524 */
    } else {
        /* -> bb1523 */
    }

    // ---- bb1523 @ 0x140096123 ----
    if (t_140096102 != 0x5_u32) {
        /* -> bb1524 */
    } else {
        /* -> bb1545 */
    }

    // ---- bb1524 @ 0x140096125 ----
    /* 140096125 */ rdx = rsi;
    /* 140096128 */ r8 = rsi;
    /* fallthrough -> bb1527 */

    // ---- bb1527 @ 0x140096130 ----
    if (rdx != r14) {
        /* -> bb1531 */
    } else {
        /* -> bb1530 */
    }

    // ---- bb1530 @ 0x140096133 ----
    if (rdx != r14) {
        /* -> bb1531 */
    } else {
        /* -> bb1533 */
    }

    // ---- bb1531 @ 0x140096135 ----
    /* 140096135 */ rax = core::ptr::read((rdi).wrapping_add(0x60_u64) as *const u64);
    /* 140096139 */ core::ptr::write(((r8).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0x39d_u64) as *mut u8, 0x0_u8);
    /* fallthrough -> bb1533 */

    // ---- bb1533 @ 0x140096142 ----
    /* 140096142 */ r9 = (((r9 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140096145 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140096148 */ let mut t_140096148_0: u64 = (r8).wrapping_add(0x68_u64);
    /* 140096148 */ r8 = t_140096148_0;
    /* 14009614c */ rcx = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 140096153 */ let mut t_140096153: u64 = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140096153 */ let mut t_140096153_0: u64 = (rcx).wrapping_sub(t_140096153);
    /* 140096153 */ rcx = t_140096153_0;
    /* 14009615a */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 14009615e */ rax = (((r9 as u32) as i64) as u64);
    if (CF == false) { /* -> bb1544 */ }
    if CF { /* -> bb1543 */ }

    // ---- bb1543 @ 0x140096164 ----
    if CF { /* -> bb1527 */ }
    if (CF == false) { /* -> bb1544 */ }

    // ---- bb1544 @ 0x140096166 ----
    /* 140096166 */ rbx = (rdi).wrapping_add(0x2bc_u64);
    /* fallthrough -> bb1545 */

    // ---- bb1545 @ 0x14009616d ----
    /* 14009616d */ let mut t_14009616d: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    /* 14009616d */ rax = (t_14009616d as u64);
    if (t_140096102 == 0x5_u32) {
        /* -> bb1550 */
    } else {
        /* -> bb1549 */
    }

    // ---- bb1549 @ 0x140096175 ----
    if (t_140096102 == 0x5_u32) {
        /* -> bb1550 */
    } else {
        /* -> bb1552 */
    }

    // ---- bb1550 @ 0x140096177 ----
    /* 140096177 */ core::ptr::write((rdi).wrapping_add(0x3d0_u64) as *mut u32, 0x5a_u32);
    /* fallthrough -> bb1566 */

    // ---- bb1552 @ 0x140096183 ----
    if ((rax as u32) != 0x5_u32) {
        /* -> bb1556 */
    } else {
        /* -> bb1555 */
    }

    // ---- bb1555 @ 0x140096186 ----
    if ((rax as u32) != 0x5_u32) {
        /* -> bb1556 */
    } else {
        /* -> bb1564 */
    }

    // ---- bb1556 @ 0x140096188 ----
    if ((rax as u32) == 0x6_u32) {
        /* -> bb1560 */
    } else {
        /* -> bb1559 */
    }

    // ---- bb1559 @ 0x14009618b ----
    if ((rax as u32) == 0x6_u32) {
        /* -> bb1560 */
    } else {
        /* -> bb1566 */
    }

    // ---- bb1560 @ 0x14009618d ----
    /* 14009618d */ let mut t_14009618d: u32 = core::ptr::read(rbx as *const u32);
    if (t_14009618d == 0x2_u32) {
        /* -> bb1564 */
    } else {
        /* -> bb1563 */
    }

    // ---- bb1563 @ 0x140096190 ----
    if (t_14009618d == 0x2_u32) {
        /* -> bb1564 */
    } else {
        /* -> bb1566 */
    }

    // ---- bb1564 @ 0x140096192 ----
    /* 140096192 */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, (rsi as u32));
    /* 140096198 */ core::ptr::write((rdi).wrapping_add(0x3d0_u64) as *mut u32, 0x3c_u32);
    /* fallthrough -> bb1566 */

    // ---- bb1566 @ 0x1400961a2 ----
    /* 1400961a2 */ let mut t_1400961a2: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    if (SF == OF) {
        /* -> bb1570 */
    } else {
        /* -> bb1569 */
    }

    // ---- bb1569 @ 0x1400961a9 ----
    if (SF == OF) {
        /* -> bb1570 */
    } else {
        /* -> bb1776 */
    }

    // ---- bb1570 @ 0x1400961af ----
    /* 1400961af */ let mut t_1400961af: u32 = core::ptr::read((rdi).wrapping_add(0x2c0_u64) as *const u32);
    if (((SF != OF) | (t_1400961af == 0x0_u32)) == false) { /* -> bb1574 */ }
    if (((SF != OF) | (t_1400961af == 0x0_u32)) != 0) { /* -> bb1573 */ }

    // ---- bb1573 @ 0x1400961b6 ----
    if (((SF != OF) | (t_1400961af == 0x0_u32)) == false) { /* -> bb1574 */ }
    if (((SF != OF) | (t_1400961af == 0x0_u32)) != 0) { /* -> bb1776 */ }

    // ---- bb1574 @ 0x1400961bc ----
    /* 1400961bc */ r8 = ((r8 & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* fallthrough -> bb1773 */

    // ---- bb1576 @ 0x1400961c4 ----
    if ((rcx as u32) == 0x1a_u32) {
        /* -> bb1580 */
    } else {
        /* -> bb1579 */
    }

    // ---- bb1579 @ 0x1400961c7 ----
    if ((rcx as u32) == 0x1a_u32) {
        /* -> bb1580 */
    } else {
        /* -> bb1666 */
    }

    // ---- bb1580 @ 0x1400961cd ----
    /* 1400961cd */ let mut t_1400961cd: u32 = core::ptr::read((rdi).wrapping_add(0x2c0_u64) as *const u32);
    /* 1400961cd */ rcx = (t_1400961cd as u64);
    /* 1400961d3 */ let mut t_1400961d3: u32 = core::ptr::read((rdi).wrapping_add(0x2c4_u64) as *const u32);
    if ((rcx as u32) != t_1400961d3) {
        /* -> bb1585 */
    } else {
        /* -> bb1584 */
    }

    // ---- bb1584 @ 0x1400961d9 ----
    if ((rcx as u32) != t_1400961d3) {
        /* -> bb1585 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb1585 @ 0x1400961df ----
    /* 1400961df */ rax = core::ptr::read((0x1400961e6_u64).wrapping_add(0x365002_u64) as *const u64);
    /* 1400961e6 */ let mut t_1400961e6: u32 = core::ptr::read((rax).wrapping_add(0x308_u64) as *const u32);
    if ((rcx as u32) != t_1400961e6) {
        /* -> bb1590 */
    } else {
        /* -> bb1589 */
    }

    // ---- bb1589 @ 0x1400961ec ----
    if ((rcx as u32) != t_1400961e6) {
        /* -> bb1590 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb1590 @ 0x1400961f2 ----
    /* 1400961f2 */ let mut t_1400961f2: u32 = core::ptr::read((rdi).wrapping_add(0x2c8_u64) as *const u32);
    /* 1400961f2 */ let mut t_1400961f2_0: u32 = ((rcx as u32)).wrapping_add(t_1400961f2);
    /* 1400961f2 */ rcx = (t_1400961f2_0 as u64);
    /* 1400961f8 */ core::ptr::write((rdi).wrapping_add(0x2c0_u64) as *mut u32, (rcx as u32));
    /* 1400961fe */ rdx = core::ptr::read((0x140096205_u64).wrapping_add(0x364fe3_u64) as *const u64);
    /* 140096205 */ let mut t_140096205: u32 = core::ptr::read((rdx).wrapping_add(0x308_u64) as *const u32);
    /* 140096205 */ rdx = (t_140096205 as u64);
    /* 14009620b */ fn_1400c6030();
    /* 140096210 */ core::ptr::write((rdi).wrapping_add(0x2c0_u64) as *mut u32, (rax as u32));
    /* 140096216 */ let mut t_140096216: u32 = core::ptr::read((rdi).wrapping_add(0x2c4_u64) as *const u32);
    /* 140096216 */ rdx = (t_140096216 as u64);
    /* 14009621c */ rcx = ((rax as u32) as u64);
    /* 14009621e */ fn_1400c6030();
    /* 140096223 */ rdx = ((rax as u32) as u64);
    /* 140096225 */ core::ptr::write((rdi).wrapping_add(0x2c0_u64) as *mut u32, (rax as u32));
    /* 14009622b */ let mut t_14009622b: u32 = core::ptr::read((rdi).wrapping_add(0x2c4_u64) as *const u32);
    /* 14009622b */ r8 = (t_14009622b as u64);
    if ((rax as u32) != (r8 as u32)) {
        /* -> bb1606 */
    } else {
        /* -> bb1605 */
    }

    // ---- bb1605 @ 0x140096235 ----
    if ((rax as u32) != (r8 as u32)) {
        /* -> bb1606 */
    } else {
        /* -> bb1636 */
    }

    // ---- bb1606 @ 0x14009623b ----
    /* 14009623b */ rcx = core::ptr::read((0x140096242_u64).wrapping_add(0x364fa6_u64) as *const u64);
    /* 140096242 */ let mut t_140096242: u32 = core::ptr::read((rcx).wrapping_add(0x308_u64) as *const u32);
    if ((rax as u32) != t_140096242) {
        /* -> bb1611 */
    } else {
        /* -> bb1610 */
    }

    // ---- bb1610 @ 0x140096248 ----
    if ((rax as u32) != t_140096242) {
        /* -> bb1611 */
    } else {
        /* -> bb1636 */
    }

    // ---- bb1611 @ 0x14009624a ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14009624d */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140096252 */ xmm1 = core::ptr::read((0x14009625a_u64).wrapping_add(0x26d186_u64) as *const u128);
    /* 14009625a */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm1);
    /* 140096260 */ rax = core::ptr::read((0x140096267_u64).wrapping_add(0x275f09_u64) as *const u64);
    /* 140096267 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u32, (rax as u32));
    /* 14009626b */ let mut t_14009626b: u16 = core::ptr::read((0x140096272_u64).wrapping_add(0x275f02_u64) as *const u16);
    /* 14009626b */ rax = ((t_14009626b as u32) as u64);
    /* 140096272 */ core::ptr::write((rsp).wrapping_add(0x34_u64) as *mut u16, (rax as u16));
    /* 140096277 */ let mut t_140096277: u8 = core::ptr::read((0x14009627e_u64).wrapping_add(0x275ef8_u64) as *const u8);
    /* 140096277 */ rax = ((t_140096277 as u32) as u64);
    /* 14009627e */ core::ptr::write((rsp).wrapping_add(0x36_u64) as *mut u8, (rax as u8));
    /* 140096282 */ core::ptr::write((rsp).wrapping_add(0x37_u64) as *mut u8, 0x0_u8);
    /* 140096287 */ xmm3 = ((rdx as u32) as u128);
    // intrinsic: 0f5bdb00 cvtdq2ps xmm3, xmm3
    // intrinsic: f30f591d mulss xmm3, dword ptr [rip + 0x26d0c6]
    /* 140096296 */ xmm0 = ((r8 as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    // intrinsic: f30f5ed8 divss xmm3, xmm0
    // intrinsic: f30f581d addss xmm3, dword ptr [rip + 0x3069ee]
    /* 1400962aa */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400962af */ let mut t_1400962af_0: u32 = 0x0_u32;
    /* 1400962af */ r8 = (t_1400962af_0 as u64);
    /* 1400962b2 */ rdx = (0x64_u32 as u64);
    /* 1400962b7 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 1400962bc */ fn_140040b90();
    /* fallthrough -> bb1652 */

    // ---- bb1636 @ 0x1400962c4 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400962c7 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 1400962cc */ xmm1 = core::ptr::read((0x1400962d4_u64).wrapping_add(0x26d0fc_u64) as *const u128);
    /* 1400962d4 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm1);
    /* 1400962da */ let mut t_1400962da: u32 = core::ptr::read((0x1400962e0_u64).wrapping_add(0x275e88_u64) as *const u32);
    /* 1400962da */ rax = (t_1400962da as u64);
    /* 1400962e0 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u32, (rax as u32));
    /* 1400962e4 */ let mut t_1400962e4: u16 = core::ptr::read((0x1400962eb_u64).wrapping_add(0x275e81_u64) as *const u16);
    /* 1400962e4 */ rax = ((t_1400962e4 as u32) as u64);
    /* 1400962eb */ core::ptr::write((rsp).wrapping_add(0x34_u64) as *mut u16, (rax as u16));
    /* 1400962f0 */ core::ptr::write((rsp).wrapping_add(0x36_u64) as *mut u8, 0x0_u8);
    /* 1400962f5 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400962fa */ xmm3 = xmm14;
    /* 1400962fe */ let mut t_1400962fe_0: u32 = 0x0_u32;
    /* 1400962fe */ r8 = (t_1400962fe_0 as u64);
    /* 140096301 */ rdx = (0x64_u32 as u64);
    /* 140096306 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 14009630b */ fn_140040b90();
    /* fallthrough -> bb1652 */

    // ---- bb1652 @ 0x140096311 ----
    /* 140096311 */ r8 = core::ptr::read((rsp).wrapping_add(0x48_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb1657 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb1656 */ }

    // ---- bb1656 @ 0x14009631a ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb1657 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb1660 */ }

    // ---- bb1657 @ 0x14009631c ----
    /* 14009631c */ rdx = core::ptr::read((rsp).wrapping_add(0x30_u64) as *const u64);
    /* 140096321 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140096326 */ fn_140028310();
    /* fallthrough -> bb1660 */

    // ---- bb1660 @ 0x14009632b ----
    /* 14009632b */ let mut t_14009632b: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    if (t_14009632b == 0x1_u32) {
        /* -> bb1664 */
    } else {
        /* -> bb1663 */
    }

    // ---- bb1663 @ 0x140096332 ----
    if (t_14009632b == 0x1_u32) {
        /* -> bb1664 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb1664 @ 0x140096338 ----
    /* 140096338 */ core::ptr::write((rdi).wrapping_add(0x3d0_u64) as *mut u32, 0x3c_u32);
    /* fallthrough -> bb2988 */

    // ---- bb1666 @ 0x140096347 ----
    if ((rcx as u32) == 0x18_u32) {
        /* -> bb1670 */
    } else {
        /* -> bb1669 */
    }

    // ---- bb1669 @ 0x14009634a ----
    if ((rcx as u32) == 0x18_u32) {
        /* -> bb1670 */
    } else {
        /* -> bb1707 */
    }

    // ---- bb1670 @ 0x140096350 ----
    /* 140096350 */ let mut t_140096350: u32 = core::ptr::read((rdi).wrapping_add(0x2bc_u64) as *const u32);
    if (((SF != OF) | (t_140096350 == 0x0_u32)) == false) { /* -> bb1674 */ }
    if (((SF != OF) | (t_140096350 == 0x0_u32)) != 0) { /* -> bb1673 */ }

    // ---- bb1673 @ 0x140096357 ----
    if (((SF != OF) | (t_140096350 == 0x0_u32)) == false) { /* -> bb1674 */ }
    if (((SF != OF) | (t_140096350 == 0x0_u32)) != 0) { /* -> bb2988 */ }

    // ---- bb1674 @ 0x14009635d ----
    /* 14009635d */ let mut t_14009635d: u32 = core::ptr::read((rdi).wrapping_add(0x3d4_u64) as *const u32);
    if (t_14009635d == 0x4_u32) {
        /* -> bb1678 */
    } else {
        /* -> bb1677 */
    }

    // ---- bb1677 @ 0x140096364 ----
    if (t_14009635d == 0x4_u32) {
        /* -> bb1678 */
    } else {
        /* -> bb1679 */
    }

    // ---- bb1678 @ 0x140096366 ----
    /* 140096366 */ core::ptr::write((rdi).wrapping_add(0x3d4_u64) as *mut u32, (r12 as u32));
    /* fallthrough -> bb1679 */

    // ---- bb1679 @ 0x14009636d ----
    /* 14009636d */ let mut t_14009636d_0: u32 = 0x0_u32;
    /* 14009636d */ r8 = (t_14009636d_0 as u64);
    /* 140096370 */ rdx = (0x1a_u32 as u64);
    /* 140096375 */ rcx = rdi;
    /* 140096378 */ fn_1400ca650();
    /* 14009637d */ let mut t_14009637d_0: u32 = 0x0_u32;
    /* 14009637d */ r8 = (t_14009637d_0 as u64);
    /* 140096380 */ rdx = (0x18_u32 as u64);
    /* 140096385 */ rcx = rdi;
    /* 140096388 */ fn_1400ca650();
    /* 14009638d */ let mut t_14009638d_0: u32 = 0x0_u32;
    /* 14009638d */ r8 = (t_14009638d_0 as u64);
    /* 140096390 */ rdx = (0x19_u32 as u64);
    /* 140096395 */ rcx = rdi;
    /* 140096398 */ fn_1400ca650();
    /* 14009639d */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, (rsi as u32));
    /* 1400963a3 */ let mut t_1400963a3_0: u32 = 0x0_u32;
    /* 1400963a3 */ r9 = (t_1400963a3_0 as u64);
    /* 1400963a6 */ r8 = ((r8 & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 1400963a9 */ let mut t_1400963a9: u32 = core::ptr::read((rdi).wrapping_add(0x2c0_u64) as *const u32);
    /* 1400963a9 */ rdx = (t_1400963a9 as u64);
    /* 1400963af */ rcx = core::ptr::read((0x1400963b6_u64).wrapping_add(0x364e32_u64) as *const u64);
    /* 1400963b6 */ fn_140105000();
    /* 1400963bb */ let mut t_1400963bb: u32 = core::ptr::read((rdi).wrapping_add(0x2d8_u64) as *const u32);
    /* 1400963bb */ rcx = (t_1400963bb as u64);
    /* 1400963c1 */ let mut t_1400963c1: u32 = core::ptr::read((rdi).wrapping_add(0x2d4_u64) as *const u32);
    /* 1400963c1 */ rax = (t_1400963c1 as u64);
    /* 1400963c7 */ let mut t_1400963c7_0: u32 = ((rax as u32)).wrapping_add((rcx as u32));
    /* 1400963c7 */ rax = (t_1400963c7_0 as u64);
    /* 1400963c9 */ let mut t_1400963c9: u32 = core::ptr::read((rdi).wrapping_add(0x2c0_u64) as *const u32);
    /* 1400963c9 */ let mut t_1400963c9_0: u64 = (((rax as u32) as u64)).wrapping_mul((t_1400963c9 as u64));
    /* 1400963c9 */ rax = ((t_1400963c9_0 as u32) as u64);
    /* 1400963d0 */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 1400963d1 */ let mut t_1400963d1_0: u64 = (((((((rdx as u32) as u64) << 0x20_u64) | ((rax as u32) as u64)) as i64) / (((rcx as u32) as u64) as i64)) as u64);
    /* 1400963d1 */ let mut t_1400963d1_1: u64 = (((((((rdx as u32) as u64) << 0x20_u64) | ((rax as u32) as u64)) as i64) % (((rcx as u32) as u64) as i64)) as u64);
    /* 1400963d1 */ rax = ((t_1400963d1_0 as u32) as u64);
    /* 1400963d1 */ rdx = ((t_1400963d1_1 as u32) as u64);
    /* 1400963d3 */ core::ptr::write((rdi).wrapping_add(0x2e0_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb1704 */

    // ---- bb1704 @ 0x1400963d9 ----
    /* 1400963d9 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0x7_u64);
    /* 1400963e4 */ core::ptr::write((rdi).wrapping_add(0x2ec_u64) as *mut u32, (rsi as u32));
    /* fallthrough -> bb2988 */

    // ---- bb1707 @ 0x1400963ef ----
    if ((rcx as u32) == 0x1b_u32) {
        /* -> bb1711 */
    } else {
        /* -> bb1710 */
    }

    // ---- bb1710 @ 0x1400963f2 ----
    if ((rcx as u32) == 0x1b_u32) {
        /* -> bb1711 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb1711 @ 0x1400963f8 ----
    /* 1400963f8 */ let mut t_1400963f8: u32 = core::ptr::read((rdi).wrapping_add(0x2bc_u64) as *const u32);
    if (((SF != OF) | (t_1400963f8 == 0x0_u32)) == false) { /* -> bb1715 */ }
    if (((SF != OF) | (t_1400963f8 == 0x0_u32)) != 0) { /* -> bb1714 */ }

    // ---- bb1714 @ 0x1400963ff ----
    if (((SF != OF) | (t_1400963f8 == 0x0_u32)) == false) { /* -> bb1715 */ }
    if (((SF != OF) | (t_1400963f8 == 0x0_u32)) != 0) { /* -> bb2988 */ }

    // ---- bb1715 @ 0x140096405 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140096408 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 14009640d */ xmm1 = core::ptr::read((0x140096415_u64).wrapping_add(0x26f26b_u64) as *const u128);
    /* 140096415 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u128, xmm1);
    /* 14009641b */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, 0x72616554_u32);
    /* 140096423 */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u8, 0x0_u8);
    /* 140096428 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 14009642d */ xmm3 = xmm14;
    /* 140096431 */ let mut t_140096431_0: u32 = 0x0_u32;
    /* 140096431 */ r8 = (t_140096431_0 as u64);
    /* 140096434 */ rdx = (0x64_u32 as u64);
    /* 140096439 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14009643e */ fn_140040b90();
    /* 140096444 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140096449 */ fn_140027900();
    /* 14009644e */ rcx = rdi;
    /* 140096451 */ fn_140094500();
    /* 140096456 */ let mut r11: u64 = ((rsi as u32) as u64);
    /* 140096459 */ let mut r10: u64 = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140096460 */ rcx = core::ptr::read((rdi).wrapping_add(0x288_u64) as *const u64);
    /* 140096467 */ let mut t_140096467_0: u64 = (rcx).wrapping_sub(r10);
    /* 140096467 */ rcx = t_140096467_0;
    /* 14009646a */ rbx = 0x4924924924924925_u64;
    /* 140096474 */ rax = rbx;
    /* 140096477 */ let mut t_140096477_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 140096477 */ rdx = ((t_140096477_0 >> 0x40_u128) as u64);
    /* 140096477 */ rax = (t_140096477_0 as u64);
    /* 14009647a */ rdx = (((rdx as i64) >> ((0x5_u8 as u64) as i64)) as u64);
    /* 14009647e */ rax = rdx;
    /* 140096481 */ rax = (rax >> (0x3f_u8 as u64));
    /* 140096485 */ let mut t_140096485_0: u64 = (rdx).wrapping_add(rax);
    /* 140096485 */ rdx = t_140096485_0;
    if (t_1400963f8 != 0x0_u32) {
        /* -> bb1746 */
    } else {
        /* -> bb1745 */
    }

    // ---- bb1745 @ 0x140096488 ----
    if (t_1400963f8 != 0x0_u32) {
        /* -> bb1746 */
    } else {
        /* -> bb1768 */
    }

    // ---- bb1746 @ 0x14009648a ----
    /* 14009648a */ r8 = rsi;
    /* 14009648d */ r9 = rsi;
    /* fallthrough -> bb1748 */

    // ---- bb1748 @ 0x140096490 ----
    /* 140096490 */ core::ptr::write(((r9).wrapping_add((r10).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *mut u32, 0xffffffff_u32);
    /* 140096499 */ rax = core::ptr::read((rdi).wrapping_add(0x60_u64) as *const u64);
    /* 14009649d */ core::ptr::write(((r8).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0x39d_u64) as *mut u8, 0x1_u8);
    /* 1400964a6 */ r11 = (((r11 as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400964a9 */ r9 = (r9).wrapping_add(0x70_u64);
    /* 1400964ad */ r8 = (r8).wrapping_add(0x68_u64);
    /* 1400964b1 */ r10 = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 1400964b8 */ rcx = core::ptr::read((rdi).wrapping_add(0x288_u64) as *const u64);
    /* 1400964bf */ let mut t_1400964bf_0: u64 = (rcx).wrapping_sub(r10);
    /* 1400964bf */ rcx = t_1400964bf_0;
    /* 1400964c2 */ rax = rbx;
    /* 1400964c5 */ let mut t_1400964c5_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 1400964c5 */ rdx = ((t_1400964c5_0 >> 0x40_u128) as u64);
    /* 1400964c5 */ rax = (t_1400964c5_0 as u64);
    /* 1400964c8 */ rdx = (((rdx as i64) >> ((0x5_u8 as u64) as i64)) as u64);
    /* 1400964cc */ rax = rdx;
    /* 1400964cf */ rax = (rax >> (0x3f_u8 as u64));
    /* 1400964d3 */ let mut t_1400964d3_0: u64 = (rdx).wrapping_add(rax);
    /* 1400964d3 */ rdx = t_1400964d3_0;
    /* 1400964d6 */ rax = (((r11 as u32) as i64) as u64);
    if (CF == false) { /* -> bb1768 */ }
    if CF { /* -> bb1767 */ }

    // ---- bb1767 @ 0x1400964dc ----
    if CF { /* -> bb1748 */ }
    if (CF == false) { /* -> bb1768 */ }

    // ---- bb1768 @ 0x1400964de ----
    /* 1400964de */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, (rsi as u32));
    /* 1400964e4 */ core::ptr::write((rdi).wrapping_add(0x2bc_u64) as *mut u32, (rsi as u32));
    /* 1400964ea */ let mut t_1400964ea: u32 = core::ptr::read((rdi).wrapping_add(0x2c8_u64) as *const u32);
    /* 1400964ea */ rax = (t_1400964ea as u64);
    /* 1400964f0 */ core::ptr::write((rdi).wrapping_add(0x2c0_u64) as *mut u32, (rax as u32));
    /* 1400964f6 */ let mut t_1400964f6_0: u32 = 0x0_u32;
    /* 1400964f6 */ r8 = (t_1400964f6_0 as u64);
    /* fallthrough -> bb1773 */

    // ---- bb1773 @ 0x1400964f9 ----
    /* 1400964f9 */ rdx = (0x18_u32 as u64);
    /* 1400964fe */ rcx = rdi;
    /* 140096501 */ fn_1400ca650();
    /* fallthrough -> bb1776 */

    // ---- bb1776 @ 0x140096506 ----
    /* 140096506 */ rcx = rdi;
    /* 140096509 */ fn_140093d50();
    /* fallthrough -> bb2988 */

    // ---- bb1779 @ 0x140096513 ----
    if ((rax as u32) == 0x4_u32) {
        /* -> bb1783 */
    } else {
        /* -> bb1782 */
    }

    // ---- bb1782 @ 0x140096516 ----
    if ((rax as u32) == 0x4_u32) {
        /* -> bb1783 */
    } else {
        /* -> bb1801 */
    }

    // ---- bb1783 @ 0x140096518 ----
    /* 140096518 */ rcx = rdi;
    /* 14009651b */ fn_1400d2b50();
    /* 140096520 */ let mut t_140096520: u32 = core::ptr::read((rdi).wrapping_add(0xe0_u64) as *const u32);
    if (t_140096520 == 0x18_u32) {
        /* -> bb1789 */
    } else {
        /* -> bb1788 */
    }

    // ---- bb1788 @ 0x140096527 ----
    if (t_140096520 == 0x18_u32) {
        /* -> bb1789 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb1789 @ 0x14009652d ----
    /* 14009652d */ let mut t_14009652d_0: u32 = 0x0_u32;
    /* 14009652d */ r8 = (t_14009652d_0 as u64);
    /* 140096530 */ rdx = (0x18_u32 as u64);
    /* 140096535 */ rcx = rdi;
    /* 140096538 */ fn_1400ca650();
    /* 14009653d */ let mut t_14009653d_0: u32 = 0x0_u32;
    /* 14009653d */ r8 = (t_14009653d_0 as u64);
    /* 140096540 */ rdx = (0x19_u32 as u64);
    /* 140096545 */ rcx = rdi;
    /* 140096548 */ fn_1400ca650();
    /* 14009654d */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0x7_u64);
    /* 140096558 */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, (rsi as u32));
    /* 14009655e */ core::ptr::write((rdi).wrapping_add(0x2ec_u64) as *mut u32, (rsi as u32));
    /* fallthrough -> bb2988 */

    // ---- bb1801 @ 0x140096569 ----
    if ((rax as u32) == 0x6_u32) {
        /* -> bb1805 */
    } else {
        /* -> bb1804 */
    }

    // ---- bb1804 @ 0x14009656c ----
    if ((rax as u32) == 0x6_u32) {
        /* -> bb1805 */
    } else {
        /* -> bb1839 */
    }

    // ---- bb1805 @ 0x140096572 ----
    /* 140096572 */ let mut t_140096572: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140096572 == 0x78_u32) {
        /* -> bb1809 */
    } else {
        /* -> bb1808 */
    }

    // ---- bb1808 @ 0x140096579 ----
    if (t_140096572 == 0x78_u32) {
        /* -> bb1809 */
    } else {
        /* -> bb1822 */
    }

    // ---- bb1809 @ 0x14009657b ----
    /* 14009657b */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u64, rsi);
    /* 140096580 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, 0x7_u64);
    /* 140096589 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, 0xf_u64);
    /* 140096592 */ rax = core::ptr::read((0x140096599_u64).wrapping_add(0x26ccd7_u64) as *const u64);
    /* 140096599 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u32, (rax as u32));
    /* 14009659d */ let mut t_14009659d: u16 = core::ptr::read((0x1400965a4_u64).wrapping_add(0x26ccd0_u64) as *const u16);
    /* 14009659d */ rax = ((t_14009659d as u32) as u64);
    /* 1400965a4 */ core::ptr::write((rsp).wrapping_add(0x34_u64) as *mut u16, (rax as u16));
    /* 1400965a9 */ let mut t_1400965a9: u8 = core::ptr::read((0x1400965b0_u64).wrapping_add(0x26ccc6_u64) as *const u8);
    /* 1400965a9 */ rax = ((t_1400965a9 as u32) as u64);
    /* 1400965b0 */ core::ptr::write((rsp).wrapping_add(0x36_u64) as *mut u8, (rax as u8));
    /* 1400965b4 */ core::ptr::write((rsp).wrapping_add(0x37_u64) as *mut u8, 0x0_u8);
    /* 1400965b9 */ rdx = ((rdx & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 1400965bb */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 1400965c0 */ fn_14003f340();
    /* fallthrough -> bb1822 */

    // ---- bb1822 @ 0x1400965c5 ----
    /* 1400965c5 */ let mut t_1400965c5: u8 = core::ptr::read((0x1400965cc_u64).wrapping_add(0x356fa4_u64) as *const u8);
    if (t_1400965c5 == 0x0_u8) {
        /* -> bb1826 */
    } else {
        /* -> bb1825 */
    }

    // ---- bb1825 @ 0x1400965cc ----
    if (t_1400965c5 == 0x0_u8) {
        /* -> bb1826 */
    } else {
        /* -> bb1830 */
    }

    // ---- bb1826 @ 0x1400965ce ----
    /* 1400965ce */ let mut t_1400965ce: u32 = core::ptr::read((0x1400965d5_u64).wrapping_add(0x357393_u64) as *const u32);
    if (t_1400965ce != 0x0_u32) {
        /* -> bb1830 */
    } else {
        /* -> bb1829 */
    }

    // ---- bb1829 @ 0x1400965d5 ----
    if (t_1400965ce != 0x0_u32) {
        /* -> bb1830 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb1830 @ 0x1400965db ----
    /* 1400965db */ let mut t_1400965db_0: u32 = 0x0_u32;
    /* 1400965db */ r8 = (t_1400965db_0 as u64);
    /* 1400965de */ rdx = (0x18_u32 as u64);
    /* 1400965e3 */ rcx = rdi;
    /* 1400965e6 */ fn_1400ca650();
    /* 1400965eb */ let mut t_1400965eb: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    if (((SF != OF) | (t_1400965eb == 0x0_u32)) == false) { /* -> bb1838 */ }
    if (((SF != OF) | (t_1400965eb == 0x0_u32)) != 0) { /* -> bb1837 */ }

    // ---- bb1837 @ 0x1400965f2 ----
    if (((SF != OF) | (t_1400965eb == 0x0_u32)) == false) { /* -> bb1838 */ }
    if (((SF != OF) | (t_1400965eb == 0x0_u32)) != 0) { /* -> bb1851 */ }

    // ---- bb1838 @ 0x1400965f4 ----
    /* fallthrough -> bb1704 */

    // ---- bb1839 @ 0x1400965f9 ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb1843 */
    } else {
        /* -> bb1842 */
    }

    // ---- bb1842 @ 0x1400965fc ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb1843 */
    } else {
        /* -> bb1858 */
    }

    // ---- bb1843 @ 0x1400965fe ----
    /* 1400965fe */ let mut t_1400965fe: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_1400965fe == 0xf0_u32) {
        /* -> bb1847 */
    } else {
        /* -> bb1846 */
    }

    // ---- bb1846 @ 0x140096608 ----
    if (t_1400965fe == 0xf0_u32) {
        /* -> bb1847 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb1847 @ 0x14009660e ----
    /* 14009660e */ let mut t_14009660e: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    if (((SF == OF) & (t_14009660e != 0x0_u32)) == false) { /* -> bb1851 */ }
    if (((SF == OF) & (t_14009660e != 0x0_u32)) != 0) { /* -> bb1850 */ }

    // ---- bb1850 @ 0x140096615 ----
    if (((SF == OF) & (t_14009660e != 0x0_u32)) != 0) { /* -> bb1704 */ }
    if (((SF == OF) & (t_14009660e != 0x0_u32)) == false) { /* -> bb1851 */ }

    // ---- bb1851 @ 0x14009661b ----
    /* 14009661b */ rcx = rdi;
    /* 14009661e */ fn_140092110();
    /* 140096623 */ rcx = rdi;
    /* 140096626 */ fn_140092340();
    /* 14009662b */ rcx = rdi;
    /* 14009662e */ fn_14008ff80();
    /* fallthrough -> bb2988 */

    // ---- bb1858 @ 0x140096638 ----
    if ((rax as u32) == 0x7_u32) {
        /* -> bb1862 */
    } else {
        /* -> bb1861 */
    }

    // ---- bb1861 @ 0x14009663b ----
    if ((rax as u32) == 0x7_u32) {
        /* -> bb1862 */
    } else {
        /* -> bb2187 */
    }

    // ---- bb1862 @ 0x140096641 ----
    /* 140096641 */ let mut t_140096641: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140096641 == 0x1_u32) {
        /* -> bb1866 */
    } else {
        /* -> bb1865 */
    }

    // ---- bb1865 @ 0x140096648 ----
    if (t_140096641 == 0x1_u32) {
        /* -> bb1866 */
    } else {
        /* -> bb1904 */
    }

    // ---- bb1866 @ 0x14009664e ----
    /* 14009664e */ let mut t_14009664e: u8 = core::ptr::read((rdi).wrapping_add(0x2a5_u64) as *const u8);
    if (t_14009664e == 0x0_u8) {
        /* -> bb1870 */
    } else {
        /* -> bb1869 */
    }

    // ---- bb1869 @ 0x140096655 ----
    if (t_14009664e == 0x0_u8) {
        /* -> bb1870 */
    } else {
        /* -> bb1904 */
    }

    // ---- bb1870 @ 0x140096657 ----
    /* 140096657 */ let mut t_140096657: u8 = core::ptr::read((rdi).wrapping_add(0x259_u64) as *const u8);
    if (t_140096657 == 0x0_u8) {
        /* -> bb1874 */
    } else {
        /* -> bb1873 */
    }

    // ---- bb1873 @ 0x14009665e ----
    if (t_140096657 == 0x0_u8) {
        /* -> bb1874 */
    } else {
        /* -> bb1904 */
    }

    // ---- bb1874 @ 0x140096660 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140096663 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140096668 */ xmm1 = core::ptr::read((0x140096670_u64).wrapping_add(0x26da40_u64) as *const u128);
    /* 140096670 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm1);
    /* 140096676 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1879 */ }
    if DF { /* -> bb1880 */ }

    // ---- bb1879 @ 0x140096676 ----
    /* 140096676 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140096676 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1881 */

    // ---- bb1880 @ 0x140096676 ----
    /* 140096676 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140096676 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1881 */

    // ---- bb1881 @ 0x14009667e ----
    /* 14009667e */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1883 */ }
    if DF { /* -> bb1884 */ }

    // ---- bb1883 @ 0x14009667e ----
    /* 14009667e */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14009667e */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1885 */

    // ---- bb1884 @ 0x14009667e ----
    /* 14009667e */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14009667e */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1885 */

    // ---- bb1885 @ 0x140096684 ----
    /* 140096684 */ let mut t_140096684: u32 = core::ptr::read((0x14009668a_u64).wrapping_add(0x2756fe_u64) as *const u32);
    /* 140096684 */ rax = (t_140096684 as u64);
    /* 14009668a */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u32, (rax as u32));
    /* 14009668e */ core::ptr::write((rsp).wrapping_add(0x3c_u64) as *mut u8, 0x0_u8);
    /* 140096693 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140096698 */ xmm3 = xmm14;
    /* 14009669c */ let mut t_14009669c_0: u32 = 0x0_u32;
    /* 14009669c */ r8 = (t_14009669c_0 as u64);
    /* 14009669f */ rdx = (0x64_u32 as u64);
    /* 1400966a4 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 1400966a9 */ fn_140040b90();
    /* 1400966af */ r8 = core::ptr::read((rsp).wrapping_add(0x48_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb1901 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb1900 */ }

    // ---- bb1900 @ 0x1400966b8 ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb1901 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb1904 */ }

    // ---- bb1901 @ 0x1400966ba ----
    /* 1400966ba */ rdx = core::ptr::read((rsp).wrapping_add(0x30_u64) as *const u64);
    /* 1400966bf */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 1400966c4 */ fn_140028310();
    /* fallthrough -> bb1904 */

    // ---- bb1904 @ 0x1400966c9 ----
    /* 1400966c9 */ rbx = (rdi).wrapping_add(0x2ec_u64);
    /* 1400966d0 */ let mut t_1400966d0: u32 = core::ptr::read(rbx as *const u32);
    /* 1400966d0 */ rax = (t_1400966d0 as u64);
    /* 1400966d2 */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400966d4 */ let mut t_1400966d4: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_1400966d4 == (rax as u32)) {
        /* -> bb1911 */
    } else {
        /* -> bb1910 */
    }

    // ---- bb1910 @ 0x1400966da ----
    if (t_1400966d4 == (rax as u32)) {
        /* -> bb1911 */
    } else {
        /* -> bb1949 */
    }

    // ---- bb1911 @ 0x1400966e0 ----
    /* 1400966e0 */ fn_14003f5e0();
    /* 1400966e5 */ let mut t_1400966e5: u32 = core::ptr::read((rdi).wrapping_add(0x2f4_u64) as *const u32);
    /* 1400966e5 */ rcx = (t_1400966e5 as u64);
    if ((rcx as u32) != 0xffffffff_u32) {
        /* -> bb1917 */
    } else {
        /* -> bb1916 */
    }

    // ---- bb1916 @ 0x1400966ee ----
    if ((rcx as u32) != 0xffffffff_u32) {
        /* -> bb1917 */
    } else {
        /* -> bb1919 */
    }

    // ---- bb1917 @ 0x1400966f0 ----
    /* 1400966f0 */ fn_140040d90();
    /* 1400966f5 */ rbx = (rdi).wrapping_add(0x2ec_u64);
    /* fallthrough -> bb1919 */

    // ---- bb1919 @ 0x1400966fc ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400966ff */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140096704 */ xmm1 = core::ptr::read((0x14009670c_u64).wrapping_add(0x26cce4_u64) as *const u128);
    /* 14009670c */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm1);
    /* 140096712 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1924 */ }
    if DF { /* -> bb1925 */ }

    // ---- bb1924 @ 0x140096712 ----
    /* 140096712 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140096712 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1926 */

    // ---- bb1925 @ 0x140096712 ----
    /* 140096712 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140096712 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1926 */

    // ---- bb1926 @ 0x14009671a ----
    /* 14009671a */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1928 */ }
    if DF { /* -> bb1929 */ }

    // ---- bb1928 @ 0x14009671a ----
    /* 14009671a */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14009671a */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1930 */

    // ---- bb1929 @ 0x14009671a ----
    /* 14009671a */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14009671a */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1930 */

    // ---- bb1930 @ 0x140096720 ----
    /* 140096720 */ let mut t_140096720: u16 = core::ptr::read((0x140096727_u64).wrapping_add(0x26cb71_u64) as *const u16);
    /* 140096720 */ rax = ((t_140096720 as u32) as u64);
    /* 140096727 */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u16, (rax as u16));
    /* 14009672c */ core::ptr::write((rsp).wrapping_add(0x3a_u64) as *mut u8, 0x0_u8);
    /* 140096731 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140096736 */ xmm3 = xmm14;
    /* 14009673a */ let mut t_14009673a_0: u32 = 0x0_u32;
    /* 14009673a */ r8 = (t_14009673a_0 as u64);
    /* 14009673d */ rdx = (0x64_u32 as u64);
    /* 140096742 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140096747 */ fn_140040b90();
    /* 14009674d */ r8 = core::ptr::read((rsp).wrapping_add(0x48_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb1946 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb1945 */ }

    // ---- bb1945 @ 0x140096756 ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb1946 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb1949 */ }

    // ---- bb1946 @ 0x140096758 ----
    /* 140096758 */ rdx = core::ptr::read((rsp).wrapping_add(0x30_u64) as *const u64);
    /* 14009675d */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140096762 */ fn_140028310();
    /* fallthrough -> bb1949 */

    // ---- bb1949 @ 0x140096767 ----
    /* 140096767 */ let mut t_140096767: u8 = core::ptr::read((0x14009676e_u64).wrapping_add(0x342d72_u64) as *const u8);
    if (t_140096767 != 0x0_u8) {
        /* -> bb1953 */
    } else {
        /* -> bb1952 */
    }

    // ---- bb1952 @ 0x14009676e ----
    if (t_140096767 != 0x0_u8) {
        /* -> bb1953 */
    } else {
        /* -> bb1961 */
    }

    // ---- bb1953 @ 0x140096770 ----
    /* 140096770 */ let mut t_140096770: u32 = core::ptr::read((0x140096777_u64).wrapping_add(0x342d6d_u64) as *const u32);
    if (((SF != OF) | (t_140096770 == 0x0_u32)) == false) { /* -> bb1957 */ }
    if (((SF != OF) | (t_140096770 == 0x0_u32)) != 0) { /* -> bb1956 */ }

    // ---- bb1956 @ 0x140096777 ----
    if (((SF != OF) | (t_140096770 == 0x0_u32)) == false) { /* -> bb1957 */ }
    if (((SF != OF) | (t_140096770 == 0x0_u32)) != 0) { /* -> bb1961 */ }

    // ---- bb1957 @ 0x140096779 ----
    /* 140096779 */ rax = (0x87_u32 as u64);
    /* 14009677e */ let mut r13: u64 = (0xb4_u32 as u64);
    /* 140096784 */ r15 = (0xa5_u32 as u64);
    /* fallthrough -> bb1964 */

    // ---- bb1961 @ 0x14009678c ----
    /* 14009678c */ rax = (0x3c_u32 as u64);
    /* 140096791 */ r13 = (0x69_u32 as u64);
    /* 140096797 */ r15 = (0x5a_u32 as u64);
    /* fallthrough -> bb1964 */

    // ---- bb1964 @ 0x14009679d ----
    /* 14009679d */ let mut t_14009679d: u32 = core::ptr::read(rbx as *const u32);
    /* 14009679d */ r12 = (t_14009679d as u64);
    /* 1400967a0 */ let mut t_1400967a0_0: u32 = ((rax as u32)).wrapping_add((r12 as u32));
    /* 1400967a0 */ rax = (t_1400967a0_0 as u64);
    /* 1400967a3 */ let mut t_1400967a3: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_1400967a3 == (rax as u32)) {
        /* -> bb1970 */
    } else {
        /* -> bb1969 */
    }

    // ---- bb1969 @ 0x1400967a9 ----
    if (t_1400967a3 == (rax as u32)) {
        /* -> bb1970 */
    } else {
        /* -> bb2018 */
    }

    // ---- bb1970 @ 0x1400967af ----
    /* 1400967af */ let mut t_1400967af: u32 = core::ptr::read((0x1400967b6_u64).wrapping_add(0x357722_u64) as *const u32);
    if (((SF != OF) | (t_1400967af == 0x3_u32)) == false) { /* -> bb1974 */ }
    if (((SF != OF) | (t_1400967af == 0x3_u32)) != 0) { /* -> bb1973 */ }

    // ---- bb1973 @ 0x1400967b6 ----
    if (((SF != OF) | (t_1400967af == 0x3_u32)) == false) { /* -> bb1974 */ }
    if (((SF != OF) | (t_1400967af == 0x3_u32)) != 0) { /* -> bb2018 */ }

    // ---- bb1974 @ 0x1400967bc ----
    /* 1400967bc */ r14 = ((rsi as u32) as u64);
    /* 1400967bf */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400967c6 */ rax = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 1400967cd */ let mut t_1400967cd_0: u64 = (rax).wrapping_sub(rdx);
    /* 1400967cd */ rax = t_1400967cd_0;
    /* 1400967d0 */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (t_1400967af != 0x3_u32) {
        /* -> bb1983 */
    } else {
        /* -> bb1982 */
    }

    // ---- bb1982 @ 0x1400967d7 ----
    if (t_1400967af != 0x3_u32) {
        /* -> bb1983 */
    } else {
        /* -> bb2018 */
    }

    // ---- bb1983 @ 0x1400967d9 ----
    /* 1400967d9 */ rbx = rsi;
    /* fallthrough -> bb1985 */

    // ---- bb1985 @ 0x1400967e0 ----
    /* 1400967e0 */ rax = core::ptr::read((rbx).wrapping_add((rdx).wrapping_mul(0x1_u64)) as *const u64);
    /* 1400967e4 */ let mut t_1400967e4: u32 = core::ptr::read((rax).wrapping_add(0x258_u64) as *const u32);
    if (rax != rcx) {
        /* -> bb1990 */
    } else {
        /* -> bb1989 */
    }

    // ---- bb1989 @ 0x1400967ee ----
    if (rax != rcx) {
        /* -> bb1990 */
    } else {
        /* -> bb1999 */
    }

    // ---- bb1990 @ 0x1400967f0 ----
    /* 1400967f0 */ rcx = (0x6_u32 as u64);
    /* 1400967f5 */ fn_1400c6990();
    if (rax == rcx) {
        /* -> bb1996 */
    } else {
        /* -> bb1995 */
    }

    // ---- bb1995 @ 0x1400967fc ----
    if (rax == rcx) {
        /* -> bb1996 */
    } else {
        /* -> bb1999 */
    }

    // ---- bb1996 @ 0x1400967fe ----
    /* 1400967fe */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140096805 */ rcx = core::ptr::read((rbx).wrapping_add((rcx).wrapping_mul(0x1_u64)) as *const u64);
    /* fallthrough -> bb2005 */

    // ---- bb1999 @ 0x14009680b ----
    /* 14009680b */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140096812 */ rcx = core::ptr::read((rbx).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u64);
    /* 140096816 */ let mut t_140096816: u32 = core::ptr::read((rcx).wrapping_add(0x258_u64) as *const u32);
    if (rax != rcx) {
        /* -> bb2005 */
    } else {
        /* -> bb2004 */
    }

    // ---- bb2004 @ 0x140096820 ----
    if (rax != rcx) {
        /* -> bb2005 */
    } else {
        /* -> bb2007 */
    }

    // ---- bb2005 @ 0x140096822 ----
    /* 140096822 */ let mut t_140096822_0: u32 = 0x0_u32;
    /* 140096822 */ rdx = (t_140096822_0 as u64);
    /* 140096824 */ fn_1400b7fd0();
    /* fallthrough -> bb2007 */

    // ---- bb2007 @ 0x140096829 ----
    /* 140096829 */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    /* 14009682c */ let mut t_14009682c_0: u64 = (rbx).wrapping_add(0x8_u64);
    /* 14009682c */ rbx = t_14009682c_0;
    /* 140096830 */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140096837 */ rcx = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 14009683e */ let mut t_14009683e_0: u64 = (rcx).wrapping_sub(rdx);
    /* 14009683e */ rcx = t_14009683e_0;
    /* 140096841 */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 140096845 */ rax = (((r14 as u32) as i64) as u64);
    if (CF == false) { /* -> bb2018 */ }
    if CF { /* -> bb2017 */ }

    // ---- bb2017 @ 0x14009684b ----
    if CF { /* -> bb1985 */ }
    if (CF == false) { /* -> bb2018 */ }

    // ---- bb2018 @ 0x14009684d ----
    /* 14009684d */ rax = (((r12).wrapping_add((r15).wrapping_mul(0x1_u64)) as u32) as u64);
    /* 140096851 */ let mut t_140096851: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140096851 == (rax as u32)) {
        /* -> bb2023 */
    } else {
        /* -> bb2022 */
    }

    // ---- bb2022 @ 0x140096857 ----
    if (t_140096851 == (rax as u32)) {
        /* -> bb2023 */
    } else {
        /* -> bb2059 */
    }

    // ---- bb2023 @ 0x140096859 ----
    /* 140096859 */ r14 = ((rsi as u32) as u64);
    /* 14009685c */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140096863 */ rax = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 14009686a */ let mut t_14009686a_0: u64 = (rax).wrapping_sub(rdx);
    /* 14009686a */ rax = t_14009686a_0;
    /* 14009686d */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (t_140096851 != (rax as u32)) {
        /* -> bb2032 */
    } else {
        /* -> bb2031 */
    }

    // ---- bb2031 @ 0x140096874 ----
    if (t_140096851 != (rax as u32)) {
        /* -> bb2032 */
    } else {
        /* -> bb2059 */
    }

    // ---- bb2032 @ 0x140096876 ----
    /* 140096876 */ rbx = rsi;
    /* fallthrough -> bb2034 */

    // ---- bb2034 @ 0x140096880 ----
    /* 140096880 */ rax = core::ptr::read((rbx).wrapping_add((rdx).wrapping_mul(0x1_u64)) as *const u64);
    /* 140096884 */ let mut t_140096884: u32 = core::ptr::read((rax).wrapping_add(0x1c_u64) as *const u32);
    if (t_140096884 == 0x1_u32) {
        /* -> bb2039 */
    } else {
        /* -> bb2038 */
    }

    // ---- bb2038 @ 0x140096888 ----
    if (t_140096884 == 0x1_u32) {
        /* -> bb2039 */
    } else {
        /* -> bb2048 */
    }

    // ---- bb2039 @ 0x14009688a ----
    /* 14009688a */ fn_1400c6ad0();
    if (t_140096884 != 0x1_u32) {
        /* -> bb2044 */
    } else {
        /* -> bb2043 */
    }

    // ---- bb2043 @ 0x140096891 ----
    if (t_140096884 != 0x1_u32) {
        /* -> bb2044 */
    } else {
        /* -> bb2048 */
    }

    // ---- bb2044 @ 0x140096893 ----
    /* 140096893 */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 14009689a */ let mut t_14009689a_0: u32 = 0x0_u32;
    /* 14009689a */ rdx = (t_14009689a_0 as u64);
    /* 14009689c */ rcx = core::ptr::read((rbx).wrapping_add((rcx).wrapping_mul(0x1_u64)) as *const u64);
    /* 1400968a0 */ fn_1400b7fd0();
    /* fallthrough -> bb2048 */

    // ---- bb2048 @ 0x1400968a5 ----
    /* 1400968a5 */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400968a8 */ let mut t_1400968a8_0: u64 = (rbx).wrapping_add(0x8_u64);
    /* 1400968a8 */ rbx = t_1400968a8_0;
    /* 1400968ac */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400968b3 */ rcx = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 1400968ba */ let mut t_1400968ba_0: u64 = (rcx).wrapping_sub(rdx);
    /* 1400968ba */ rcx = t_1400968ba_0;
    /* 1400968bd */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400968c1 */ rax = (((r14 as u32) as i64) as u64);
    if (CF == false) { /* -> bb2059 */ }
    if CF { /* -> bb2058 */ }

    // ---- bb2058 @ 0x1400968c7 ----
    if CF { /* -> bb2034 */ }
    if (CF == false) { /* -> bb2059 */ }

    // ---- bb2059 @ 0x1400968c9 ----
    /* 1400968c9 */ rax = (((r12).wrapping_add((r13).wrapping_mul(0x1_u64)) as u32) as u64);
    /* 1400968cd */ let mut t_1400968cd: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_1400968cd == (rax as u32)) {
        /* -> bb2064 */
    } else {
        /* -> bb2063 */
    }

    // ---- bb2063 @ 0x1400968d3 ----
    if (t_1400968cd == (rax as u32)) {
        /* -> bb2064 */
    } else {
        /* -> bb2988 */
    }

    // ---- bb2064 @ 0x1400968d9 ----
    /* 1400968d9 */ r14 = ((rsi as u32) as u64);
    /* 1400968dc */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400968e3 */ rax = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 1400968ea */ let mut t_1400968ea_0: u64 = (rax).wrapping_sub(rdx);
    /* 1400968ea */ rax = t_1400968ea_0;
    /* 1400968ed */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (t_1400968cd != (rax as u32)) {
        /* -> bb2073 */
    } else {
        /* -> bb2072 */
    }

    // ---- bb2072 @ 0x1400968f4 ----
    if (t_1400968cd != (rax as u32)) {
        /* -> bb2073 */
    } else {
        /* -> bb2142 */
    }

    // ---- bb2073 @ 0x1400968fa ----
    /* 1400968fa */ r12 = rsi;
    /* fallthrough -> bb2075 */

    // ---- bb2075 @ 0x140096900 ----
    /* 140096900 */ rbx = core::ptr::read((r12).wrapping_add((rdx).wrapping_mul(0x1_u64)) as *const u64);
    /* 140096904 */ let mut t_140096904: u32 = core::ptr::read((rbx).wrapping_add(0x1f8_u64) as *const u32);
    /* 140096904 */ rcx = (t_140096904 as u64);
    if ((rcx as u32) != 0xffffffff_u32) {
        /* -> bb2081 */
    } else {
        /* -> bb2080 */
    }

    // ---- bb2080 @ 0x14009690d ----
    if ((rcx as u32) != 0xffffffff_u32) {
        /* -> bb2081 */
    } else {
        /* -> bb2083 */
    }

    // ---- bb2081 @ 0x14009690f ----
    /* 14009690f */ fn_1400c7930();
    /* 140096914 */ let mut t_140096914: u32 = core::ptr::read((rax).wrapping_add(0x50_u64) as *const u32);
    /* 140096914 */ core::ptr::write((rax).wrapping_add(0x50_u64) as *mut u32, (t_140096914).wrapping_add(0x1_u32));
    /* fallthrough -> bb2083 */

    // ---- bb2083 @ 0x140096917 ----
    /* 140096917 */ rcx = rbx;
    /* 14009691a */ fn_1400b7720();
    if ((rcx as u32) == 0xffffffff_u32) {
        /* -> bb2089 */
    } else {
        /* -> bb2088 */
    }

    // ---- bb2088 @ 0x140096921 ----
    if ((rcx as u32) == 0xffffffff_u32) {
        /* -> bb2089 */
    } else {
        /* -> bb2091 */
    }

    // ---- bb2089 @ 0x140096923 ----
    /* 140096923 */ r8 = (0x1e_u32 as u64);
    /* fallthrough -> bb2128 */

    // ---- bb2091 @ 0x14009692b ----
    /* 14009692b */ let mut t_14009692b: u32 = core::ptr::read((rbx).wrapping_add(0xc_u64) as *const u32);
    if (t_14009692b != 0x4_u32) {
        /* -> bb2095 */
    } else {
        /* -> bb2094 */
    }

    // ---- bb2094 @ 0x14009692f ----
    if (t_14009692b != 0x4_u32) {
        /* -> bb2095 */
    } else {
        /* -> bb2131 */
    }

    // ---- bb2095 @ 0x140096931 ----
    /* 140096931 */ r15 = ((rsi as u32) as u64);
    /* 140096934 */ let mut t_140096934: u32 = core::ptr::read((0x14009693b_u64).wrapping_add(0x35759d_u64) as *const u32);
    if (((SF != OF) | (t_140096934 == 0x3_u32)) == false) { /* -> bb2100 */ }
    if (((SF != OF) | (t_140096934 == 0x3_u32)) != 0) { /* -> bb2099 */ }

    // ---- bb2099 @ 0x14009693b ----
    if (((SF != OF) | (t_140096934 == 0x3_u32)) == false) { /* -> bb2100 */ }
    if (((SF != OF) | (t_140096934 == 0x3_u32)) != 0) { /* -> bb2124 */ }

    // ---- bb2100 @ 0x14009693d ----
    /* 14009693d */ let mut t_14009693d: u32 = core::ptr::read((rbx).wrapping_add(0x258_u64) as *const u32);
    if (t_140096934 == 0x3_u32) {
        /* -> bb2104 */
    } else {
        /* -> bb2103 */
    }

    // ---- bb2103 @ 0x140096947 ----
    if (t_140096934 == 0x3_u32) {
        /* -> bb2104 */
    } else {
        /* -> bb2108 */
    }

    // ---- bb2104 @ 0x140096949 ----
    /* 140096949 */ let mut t_140096949: u32 = core::ptr::read((rbx).wrapping_add(0x1c_u64) as *const u32);
    if (t_140096949 == 0x2_u32) {
        /* -> bb2108 */
    } else {
        /* -> bb2107 */
    }

    // ---- bb2107 @ 0x14009694d ----
    if (t_140096949 == 0x2_u32) {
        /* -> bb2108 */
    } else {
        /* -> bb2124 */
    }

    // ---- bb2108 @ 0x14009694f ----
    /* 14009694f */ rcx = (0x14_u32 as u64);
    /* 140096954 */ fn_1400c6990();
    if (t_140096949 == 0x2_u32) {
        /* -> bb2114 */
    } else {
        /* -> bb2113 */
    }

    // ---- bb2113 @ 0x14009695b ----
    if (t_140096949 == 0x2_u32) {
        /* -> bb2114 */
    } else {
        /* -> bb2116 */
    }

    // ---- bb2114 @ 0x14009695d ----
    /* 14009695d */ r15 = (0x12c_u32 as u64);
    /* fallthrough -> bb2124 */

    // ---- bb2116 @ 0x140096965 ----
    if (SF != OF) {
        /* -> bb2120 */
    } else {
        /* -> bb2119 */
    }

    // ---- bb2119 @ 0x140096968 ----
    if (SF != OF) {
        /* -> bb2120 */
    } else {
        /* -> bb2124 */
    }

    // ---- bb2120 @ 0x14009696a ----
    /* 14009696a */ rcx = (0x4_u32 as u64);
    /* 14009696f */ fn_1400c6990();
    /* 140096974 */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* 140096976 */ let mut t_140096976_0: u64 = (((rax as u32) as u64)).wrapping_mul((0x1e_u32 as u64));
    /* 140096976 */ r15 = ((t_140096976_0 as u32) as u64);
    /* fallthrough -> bb2124 */

    // ---- bb2124 @ 0x14009697a ----
    /* 14009697a */ rdx = ((r15 as u32) as u64);
    /* 14009697d */ rcx = rbx;
    /* 140096980 */ fn_1400b7fd0();
    /* 140096985 */ r8 = (0x1a_u32 as u64);
    /* fallthrough -> bb2128 */

    // ---- bb2128 @ 0x14009698b ----
    /* 14009698b */ rdx = ((r14 as u32) as u64);
    /* 14009698e */ rcx = rdi;
    /* 140096991 */ fn_1400d2220();
    /* fallthrough -> bb2131 */

    // ---- bb2131 @ 0x140096996 ----
    /* 140096996 */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140096999 */ let mut t_140096999_0: u64 = (r12).wrapping_add(0x8_u64);
    /* 140096999 */ r12 = t_140096999_0;
    /* 14009699d */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400969a4 */ rcx = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 1400969ab */ let mut t_1400969ab_0: u64 = (rcx).wrapping_sub(rdx);
    /* 1400969ab */ rcx = t_1400969ab_0;
    /* 1400969ae */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400969b2 */ rax = (((r14 as u32) as i64) as u64);
    if (CF == false) { /* -> bb2142 */ }
    if CF { /* -> bb2141 */ }

    // ---- bb2141 @ 0x1400969b8 ----
    if CF { /* -> bb2075 */ }
    if (CF == false) { /* -> bb2142 */ }

    // ---- bb2142 @ 0x1400969be ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400969c1 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 1400969c6 */ xmm1 = core::ptr::read((0x1400969ce_u64).wrapping_add(0x26ca02_u64) as *const u128);
    /* 1400969ce */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u128, xmm1);
    /* 1400969d4 */ let mut t_1400969d4: u32 = core::ptr::read((0x1400969da_u64).wrapping_add(0x26c8c2_u64) as *const u32);
    /* 1400969d4 */ rax = (t_1400969d4 as u64);
    /* 1400969da */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, (rax as u32));
    /* 1400969de */ let mut t_1400969de: u16 = core::ptr::read((0x1400969e5_u64).wrapping_add(0x26c8bb_u64) as *const u16);
    /* 1400969de */ rax = ((t_1400969de as u32) as u64);
    /* 1400969e5 */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u16, (rax as u16));
    /* 1400969ea */ core::ptr::write((rsp).wrapping_add(0x5e_u64) as *mut u8, 0x0_u8);
    /* 1400969ef */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400969f4 */ xmm3 = xmm14;
    /* 1400969f8 */ let mut t_1400969f8_0: u32 = 0x0_u32;
    /* 1400969f8 */ r8 = (t_1400969f8_0 as u64);
    /* 1400969fb */ rdx = (0x64_u32 as u64);
    /* 140096a00 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140096a05 */ fn_140040b90();
    /* 140096a0b */ rdx = core::ptr::read((rsp).wrapping_add(0x70_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2163 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2162 */ }

    // ---- bb2162 @ 0x140096a14 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2163 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2179 */ }

    // ---- bb2163 @ 0x140096a16 ----
    /* 140096a16 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140096a19 */ rcx = core::ptr::read((rsp).wrapping_add(0x58_u64) as *const u64);
    /* 140096a1e */ rax = rcx;
    if (CF == false) { /* -> bb2170 */ }
    if CF { /* -> bb2169 */ }

    // ---- bb2169 @ 0x140096a28 ----
    if (CF == false) { /* -> bb2170 */ }
    if CF { /* -> bb2178 */ }

    // ---- bb2170 @ 0x140096a2a ----
    /* 140096a2a */ let mut t_140096a2a_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140096a2a */ rdx = t_140096a2a_0;
    /* 140096a2e */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140096a32 */ let mut t_140096a32_0: u64 = (rax).wrapping_sub(rcx);
    /* 140096a32 */ rax = t_140096a32_0;
    /* 140096a35 */ let mut t_140096a35_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140096a35 */ rax = t_140096a35_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2178 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2177 */ }

    // ---- bb2177 @ 0x140096a3d ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2178 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3504 */ }

    // ---- bb2178 @ 0x140096a43 ----
    /* 140096a43 */ fn_1402c7498();
    /* fallthrough -> bb2179 */

    // ---- bb2179 @ 0x140096a48 ----
    /* 140096a48 */ rcx = (rdi).wrapping_add(0x300_u64);
    /* 140096a4f */ r8 = (0x13_u32 as u64);
    /* 140096a55 */ rdx = (0x140096a5c_u64).wrapping_add(0x27571c_u64);
    /* 140096a5c */ fn_140027f50();
    /* 140096a61 */ core::ptr::write((rdi).wrapping_add(0x320_u64) as *mut u32, 0xb4_u32);
    /* 140096a6b */ core::ptr::write((rdi).wrapping_add(0x264_u64) as *mut u8, 0x0_u8);
    /* 140096a72 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0x8_u64);
    /* fallthrough -> bb2988 */

    // ---- bb2187 @ 0x140096a82 ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb2191 */
    } else {
        /* -> bb2190 */
    }

    // ---- bb2190 @ 0x140096a85 ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb2191 */
    } else {
        /* -> bb3030 */
    }

    // ---- bb2191 @ 0x140096a8b ----
    /* 140096a8b */ let mut t_140096a8b: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140096a8b == 0x3c_u32) {
        /* -> bb2195 */
    } else {
        /* -> bb2194 */
    }

    // ---- bb2194 @ 0x140096a92 ----
    if (t_140096a8b == 0x3c_u32) {
        /* -> bb2195 */
    } else {
        /* -> bb2207 */
    }

    // ---- bb2195 @ 0x140096a94 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140096a97 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140096a9c */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0x6_u64);
    /* 140096aa5 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 140096aae */ let mut t_140096aae: u32 = core::ptr::read((0x140096ab4_u64).wrapping_add(0x26c7f0_u64) as *const u32);
    /* 140096aae */ rax = (t_140096aae as u64);
    /* 140096ab4 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, (rax as u32));
    /* 140096ab8 */ let mut t_140096ab8: u16 = core::ptr::read((0x140096abf_u64).wrapping_add(0x26c7e9_u64) as *const u16);
    /* 140096ab8 */ rax = ((t_140096ab8 as u32) as u64);
    /* 140096abf */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u16, (rax as u16));
    /* 140096ac4 */ core::ptr::write((rsp).wrapping_add(0x5e_u64) as *mut u8, 0x0_u8);
    /* 140096ac9 */ let mut t_140096ac9_0: u32 = 0x0_u32;
    /* 140096ac9 */ rdx = (t_140096ac9_0 as u64);
    /* 140096acb */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140096ad0 */ fn_14003f340();
    /* fallthrough -> bb2207 */

    // ---- bb2207 @ 0x140096ad5 ----
    /* 140096ad5 */ let mut t_140096ad5: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_140096ad5 == 0x0_u8) {
        /* -> bb2211 */
    } else {
        /* -> bb2210 */
    }

    // ---- bb2210 @ 0x140096adc ----
    if (t_140096ad5 == 0x0_u8) {
        /* -> bb2211 */
    } else {
        /* -> bb2243 */
    }

    // ---- bb2211 @ 0x140096ade ----
    /* 140096ade */ let mut t_140096ade: u32 = core::ptr::read((rdi).wrapping_add(0x230_u64) as *const u32);
    /* 140096ade */ rax = ((t_140096ade as i64) as u64);
    if ((rax as u32) != 0xffffffff_u32) {
        /* -> bb2216 */
    } else {
        /* -> bb2215 */
    }

    // ---- bb2215 @ 0x140096ae8 ----
    if ((rax as u32) != 0xffffffff_u32) {
        /* -> bb2216 */
    } else {
        /* -> bb2243 */
    }

    // ---- bb2216 @ 0x140096aea ----
    /* 140096aea */ let mut t_140096aea: u32 = core::ptr::read((rdi).wrapping_add(0x22c_u64) as *const u32);
    /* 140096aea */ r8 = (t_140096aea as u64);
    if ((r8 as u32) != 0xffffffff_u32) {
        /* -> bb2221 */
    } else {
        /* -> bb2220 */
    }

    // ---- bb2220 @ 0x140096af5 ----
    if ((r8 as u32) != 0xffffffff_u32) {
        /* -> bb2221 */
    } else {
        /* -> bb2243 */
    }

    // ---- bb2221 @ 0x140096af7 ----
    /* 140096af7 */ let mut t_140096af7: u32 = core::ptr::read((rdi).wrapping_add(0x1f8_u64) as *const u32);
    if (t_140096af7 == 0x0_u32) {
        /* -> bb2225 */
    } else {
        /* -> bb2224 */
    }

    // ---- bb2224 @ 0x140096afe ----
    if (t_140096af7 == 0x0_u32) {
        /* -> bb2225 */
    } else {
        /* -> bb2243 */
    }

    // ---- bb2225 @ 0x140096b00 ----
    /* 140096b00 */ rcx = rax;
    /* 140096b03 */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140096b0a */ rbx = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 140096b0e */ let mut t_140096b0e: u32 = core::ptr::read((rbx).wrapping_add(0x284_u64) as *const u32);
    /* 140096b0e */ rdx = (t_140096b0e as u64);
    /* 140096b14 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140096b19 */ fn_140067990();
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x26cc31]
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 140096b2d */ let mut t_140096b2d_0: u32 = 0x0_u32;
    /* 140096b2d */ r9 = (t_140096b2d_0 as u64);
    /* 140096b30 */ r8 = rax;
    /* 140096b33 */ rdx = rbx;
    /* 140096b36 */ rcx = rdi;
    /* 140096b39 */ fn_1400d1090();
    /* 140096b3f */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140096b44 */ fn_140027900();
    /* 140096b49 */ core::ptr::write((rdi).wrapping_add(0x22c_u64) as *mut u32, 0xffffffff_u32);
    /* fallthrough -> bb2243 */

    // ---- bb2243 @ 0x140096b53 ----
    /* 140096b53 */ let mut t_140096b53: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140096b53 */ rcx = (t_140096b53 as u64);
    if (SF == OF) {
        /* -> bb2248 */
    } else {
        /* -> bb2247 */
    }

    // ---- bb2247 @ 0x140096b5f ----
    if (SF == OF) {
        /* -> bb2248 */
    } else {
        /* -> bb2289 */
    }

    // ---- bb2248 @ 0x140096b65 ----
    /* 140096b65 */ rax = (0x88888889_u32 as u64);
    /* 140096b6a */ let mut t_140096b6a_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 140096b6a */ rdx = (((t_140096b6a_0 >> 0x20_u64) as u32) as u64);
    /* 140096b6a */ rax = ((t_140096b6a_0 as u32) as u64);
    /* 140096b6c */ let mut t_140096b6c_0: u32 = ((rdx as u32)).wrapping_add((rcx as u32));
    /* 140096b6c */ rdx = (t_140096b6c_0 as u64);
    /* 140096b6e */ rdx = (((((rdx as u32) as i64) >> ((0x5_u8 as u32) as i64)) as u64) as u64);
    /* 140096b71 */ rax = ((rdx as u32) as u64);
    /* 140096b73 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140096b76 */ let mut t_140096b76_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 140096b76 */ rdx = (t_140096b76_0 as u64);
    /* 140096b78 */ let mut t_140096b78_0: u64 = (((rdx as u32) as u64)).wrapping_mul((0x3c_u32 as u64));
    /* 140096b78 */ rax = ((t_140096b78_0 as u32) as u64);
    if ((rcx as u32) == (rax as u32)) {
        /* -> bb2260 */
    } else {
        /* -> bb2259 */
    }

    // ---- bb2259 @ 0x140096b7d ----
    if ((rcx as u32) == (rax as u32)) {
        /* -> bb2260 */
    } else {
        /* -> bb2289 */
    }

    // ---- bb2260 @ 0x140096b7f ----
    /* 140096b7f */ rcx = (0xa_u32 as u64);
    /* 140096b84 */ fn_1400c6990();
    if ((rcx as u32) == (rax as u32)) {
        /* -> bb2266 */
    } else {
        /* -> bb2265 */
    }

    // ---- bb2265 @ 0x140096b8b ----
    if ((rcx as u32) == (rax as u32)) {
        /* -> bb2266 */
    } else {
        /* -> bb2289 */
    }

    // ---- bb2266 @ 0x140096b8d ----
    /* 140096b8d */ let mut t_140096b8d: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    /* 140096b8d */ rcx = (t_140096b8d as u64);
    /* 140096b93 */ fn_1400c6990();
    /* 140096b98 */ rbx = (((rax as u32) as i64) as u64);
    /* 140096b9b */ let mut t_140096b9b_0: u128 = ((rbx as u128)).wrapping_mul((0x70_u64 as u128));
    /* 140096b9b */ rcx = (t_140096b9b_0 as u64);
    /* 140096b9f */ rdx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140096ba6 */ let mut t_140096ba6: u32 = core::ptr::read(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x14_u64) as *const u32);
    if (SF != OF) {
        /* -> bb2275 */
    } else {
        /* -> bb2274 */
    }

    // ---- bb2274 @ 0x140096bae ----
    if (SF != OF) {
        /* -> bb2275 */
    } else {
        /* -> bb2289 */
    }

    // ---- bb2275 @ 0x140096bb0 ----
    /* 140096bb0 */ let mut t_140096bb0: u32 = core::ptr::read(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0xc_u64) as *const u32);
    if (t_140096bb0 == 0xffffffff_u32) {
        /* -> bb2279 */
    } else {
        /* -> bb2278 */
    }

    // ---- bb2278 @ 0x140096bb5 ----
    if (t_140096bb0 == 0xffffffff_u32) {
        /* -> bb2279 */
    } else {
        /* -> bb2289 */
    }

    // ---- bb2279 @ 0x140096bb7 ----
    /* 140096bb7 */ let mut t_140096bb7_0: u32 = 0x0_u32;
    /* 140096bb7 */ r8 = (t_140096bb7_0 as u64);
    /* 140096bba */ rdx = ((rax as u32) as u64);
    /* 140096bbc */ rcx = rdi;
    /* 140096bbf */ fn_1400985a0();
    /* 140096bc4 */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140096bcb */ rbx = core::ptr::read((rax).wrapping_add((rbx).wrapping_mul(0x8_u64)) as *const u64);
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x275731]
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x275719]
    /* 140096bdf */ fn_1400c6d50();
    // intrinsic: f30f1183 movss dword ptr [rbx + 0x264], xmm0
    /* fallthrough -> bb2289 */

    // ---- bb2289 @ 0x140096bec ----
    /* 140096bec */ rbx = ((rsi as u32) as u64);
    /* 140096bee */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u32, (rbx as u32));
    /* 140096bf1 */ r14 = (0x2710_u32 as u64);
    /* 140096bf7 */ core::ptr::write((rbp).wrapping_add(0x68_u64) as *mut u32, (r14 as u32));
    /* 140096bfb */ r13 = ((rsi as u32) as u64);
    /* 140096bfe */ let mut t_140096bfe: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    /* 140096bfe */ rax = (t_140096bfe as u64);
    /* 140096c04 */ let mut xmm13: u128 = core::ptr::read((0x140096c0d_u64).wrapping_add(0x26d483_u64) as *const u128);
    if (((SF != OF) | (t_140096bb0 == 0xffffffff_u32)) == false) { /* -> bb2300 */ }
    if (((SF != OF) | (t_140096bb0 == 0xffffffff_u32)) != 0) { /* -> bb2299 */ }

    // ---- bb2299 @ 0x140096c0f ----
    if (((SF != OF) | (t_140096bb0 == 0xffffffff_u32)) == false) { /* -> bb2300 */ }
    if (((SF != OF) | (t_140096bb0 == 0xffffffff_u32)) != 0) { /* -> bb2734 */ }

    // ---- bb2300 @ 0x140096c15 ----
    /* 140096c15 */ r15 = rsi;
    /* 140096c18 */ r12 = rsi;
    /* 140096c1b */ rbx = (rdi).wrapping_add(0x130_u64);
    /* 140096c22 */ let mut xmm10: u128 = core::ptr::read((0x140096c2b_u64).wrapping_add(0x26c7b5_u64) as *const u128);
    /* 140096c2b */ let mut xmm11: u128 = core::ptr::read((0x140096c34_u64).wrapping_add(0x26c7cc_u64) as *const u128);
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x3060b4]
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x306084]
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x30600f]
    // intrinsic: f3440f10 movss xmm12, dword ptr [rip + 0x30602e]
    // intrinsic: f3440f10 movss xmm9, dword ptr [rip + 0x26c6f9]
    /* fallthrough -> bb2311 */

    // ---- bb2311 @ 0x140096c60 ----
    /* 140096c60 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140096c67 */ let mut t_140096c67: u32 = core::ptr::read(((r15).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0xc_u64) as *const u32);
    if (t_140096c67 != 0xffffffff_u32) {
        /* -> bb2316 */
    } else {
        /* -> bb2315 */
    }

    // ---- bb2315 @ 0x140096c6d ----
    if (t_140096c67 != 0xffffffff_u32) {
        /* -> bb2316 */
    } else {
        /* -> bb2324 */
    }

    // ---- bb2316 @ 0x140096c6f ----
    /* 140096c6f */ rbx = (rdi).wrapping_add(0x130_u64);
    /* 140096c76 */ rcx = core::ptr::read(rbx as *const u64);
    /* 140096c79 */ rcx = core::ptr::read((r12).wrapping_add((rcx).wrapping_mul(0x1_u64)) as *const u64);
    /* 140096c7d */ fn_1400b4980();
    if (t_140096c67 != 0xffffffff_u32) {
        /* -> bb2324 */
    } else {
        /* -> bb2323 */
    }

    // ---- bb2323 @ 0x140096c84 ----
    if (t_140096c67 != 0xffffffff_u32) {
        /* -> bb2324 */
    } else {
        /* -> bb2724 */
    }

    // ---- bb2324 @ 0x140096c8a ----
    /* 140096c8a */ r14 = (((r13 as u32) as i64) as u64);
    /* 140096c8d */ rdx = ((r13 as u32) as u64);
    /* 140096c90 */ rcx = rdi;
    /* 140096c93 */ fn_140097d90();
    /* 140096c98 */ rdx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140096c9f */ let mut t_140096c9f: u32 = core::ptr::read(((r15).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x14_u64) as *const u32);
    if (SF != OF) {
        /* -> bb2333 */
    } else {
        /* -> bb2332 */
    }

    // ---- bb2332 @ 0x140096ca8 ----
    if (SF != OF) {
        /* -> bb2333 */
    } else {
        /* -> bb2335 */
    }

    // ---- bb2333 @ 0x140096caa ----
    /* 140096caa */ let mut t_140096caa_0: u128 = ((r14 as u128)).wrapping_mul((0x70_u64 as u128));
    /* 140096caa */ rax = (t_140096caa_0 as u64);
    /* 140096cae */ let mut t_140096cae: u32 = core::ptr::read(((rax).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x10_u64) as *const u32);
    /* 140096cae */ core::ptr::write(((rax).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x10_u64) as *mut u32, (t_140096cae).wrapping_add(0x1_u32));
    /* fallthrough -> bb2335 */

    // ---- bb2335 @ 0x140096cb2 ----
    /* 140096cb2 */ rcx = core::ptr::read(rbx as *const u64);
    /* 140096cb5 */ rcx = core::ptr::read((rcx).wrapping_add((r14).wrapping_mul(0x8_u64)) as *const u64);
    /* 140096cb9 */ fn_1400b5fd0();
    // intrinsic: 0f2ec000 ucomiss xmm0, xmm0
    if (PF == false) { /* -> bb2342 */ }
    if PF { /* -> bb2341 */ }

    // ---- bb2341 @ 0x140096cc1 ----
    if (PF == false) { /* -> bb2342 */ }
    if PF { /* -> bb2359 */ }

    // ---- bb2342 @ 0x140096cc3 ----
    // intrinsic: 0f2fc600 comiss xmm0, xmm6
    if ((CF | (t_140096c9f == 0xb4_u32)) == false) { /* -> bb2346 */ }
    if ((CF | (t_140096c9f == 0xb4_u32)) != 0) { /* -> bb2345 */ }

    // ---- bb2345 @ 0x140096cc6 ----
    if ((CF | (t_140096c9f == 0xb4_u32)) == false) { /* -> bb2346 */ }
    if ((CF | (t_140096c9f == 0xb4_u32)) != 0) { /* -> bb2359 */ }

    // ---- bb2346 @ 0x140096cc8 ----
    // intrinsic: 0f2ff800 comiss xmm7, xmm0
    if ((CF | (t_140096c9f == 0xb4_u32)) == false) { /* -> bb2350 */ }
    if ((CF | (t_140096c9f == 0xb4_u32)) != 0) { /* -> bb2349 */ }

    // ---- bb2349 @ 0x140096ccb ----
    if ((CF | (t_140096c9f == 0xb4_u32)) == false) { /* -> bb2350 */ }
    if ((CF | (t_140096c9f == 0xb4_u32)) != 0) { /* -> bb2359 */ }

    // ---- bb2350 @ 0x140096ccd ----
    // intrinsic: f30f108f movss xmm1, dword ptr [rdi + 0x2f8]
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if (CF == false) { /* -> bb2355 */ }
    if CF { /* -> bb2354 */ }

    // ---- bb2354 @ 0x140096cd8 ----
    if (CF == false) { /* -> bb2355 */ }
    if CF { /* -> bb2357 */ }

    // ---- bb2355 @ 0x140096cda ----
    /* 140096cda */ xmm0 = xmm1;
    // intrinsic: f3410f58 addss xmm0, xmm8
    /* fallthrough -> bb2357 */

    // ---- bb2357 @ 0x140096ce2 ----
    /* 140096ce2 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    // intrinsic: f3410f11 movss dword ptr [r15 + rax + 0x24], xmm0
    /* fallthrough -> bb2359 */

    // ---- bb2359 @ 0x140096cf0 ----
    /* 140096cf0 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    // intrinsic: f3410f10 movss xmm0, dword ptr [r15 + rax + 0x24]
    // intrinsic: 410f2fc7 comiss xmm0, xmm15
    if ((CF | (t_140096c9f == 0xb4_u32)) == false) { /* -> bb2365 */ }
    if ((CF | (t_140096c9f == 0xb4_u32)) != 0) { /* -> bb2364 */ }

    // ---- bb2364 @ 0x140096d02 ----
    if ((CF | (t_140096c9f == 0xb4_u32)) == false) { /* -> bb2365 */ }
    if ((CF | (t_140096c9f == 0xb4_u32)) != 0) { /* -> bb2370 */ }

    // ---- bb2365 @ 0x140096d04 ----
    /* 140096d04 */ let mut t_140096d04: u32 = core::ptr::read(((r15).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0x14_u64) as *const u32);
    if (SF != OF) {
        /* -> bb2369 */
    } else {
        /* -> bb2368 */
    }

    // ---- bb2368 @ 0x140096d0d ----
    if (SF != OF) {
        /* -> bb2369 */
    } else {
        /* -> bb2370 */
    }

    // ---- bb2369 @ 0x140096d0f ----
    /* 140096d0f */ let mut xmm15: u128 = xmm0;
    /* fallthrough -> bb2370 */

    // ---- bb2370 @ 0x140096d13 ----
    // intrinsic: 0f2f87f8 comiss xmm0, dword ptr [rdi + 0x2f8]
    if (CF == false) { /* -> bb2374 */ }
    if CF { /* -> bb2373 */ }

    // ---- bb2373 @ 0x140096d1a ----
    if (CF == false) { /* -> bb2374 */ }
    if CF { /* -> bb2666 */ }

    // ---- bb2374 @ 0x140096d20 ----
    /* 140096d20 */ let mut t_140096d20: u32 = core::ptr::read((rdi).wrapping_add(0x2fc_u64) as *const u32);
    /* 140096d20 */ rbx = (t_140096d20 as u64);
    /* 140096d26 */ rax = (((rbx).wrapping_add(0x1_u64) as u32) as u64);
    /* 140096d29 */ core::ptr::write((rdi).wrapping_add(0x2fc_u64) as *mut u32, (rax as u32));
    /* 140096d2f */ r8 = (0x1d_u32 as u64);
    /* 140096d35 */ rdx = ((r13 as u32) as u64);
    /* 140096d38 */ rcx = rdi;
    /* 140096d3b */ fn_1400d2220();
    /* 140096d40 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140096d47 */ core::ptr::write(((r15).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0xc_u64) as *mut u32, (rbx as u32));
    if (SF != OF) {
        /* -> bb2387 */
    } else {
        /* -> bb2386 */
    }

    // ---- bb2386 @ 0x140096d4f ----
    if (SF != OF) {
        /* -> bb2387 */
    } else {
        /* -> bb2418 */
    }

    // ---- bb2387 @ 0x140096d51 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140096d54 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140096d59 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm11);
    /* 140096d60 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb2391 */ }
    if DF { /* -> bb2392 */ }

    // ---- bb2391 @ 0x140096d60 ----
    /* 140096d60 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140096d60 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb2393 */

    // ---- bb2392 @ 0x140096d60 ----
    /* 140096d60 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140096d60 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb2393 */

    // ---- bb2393 @ 0x140096d68 ----
    /* 140096d68 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb2395 */ }
    if DF { /* -> bb2396 */ }

    // ---- bb2395 @ 0x140096d68 ----
    /* 140096d68 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140096d68 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb2397 */

    // ---- bb2396 @ 0x140096d68 ----
    /* 140096d68 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140096d68 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb2397 */

    // ---- bb2397 @ 0x140096d6e ----
    /* 140096d6e */ let mut t_140096d6e: u32 = core::ptr::read((0x140096d74_u64).wrapping_add(0x26c544_u64) as *const u32);
    /* 140096d6e */ rax = (t_140096d6e as u64);
    /* 140096d74 */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u32, (rax as u32));
    /* 140096d78 */ let mut t_140096d78: u16 = core::ptr::read((0x140096d7f_u64).wrapping_add(0x26c53d_u64) as *const u16);
    /* 140096d78 */ rax = ((t_140096d78 as u32) as u64);
    /* 140096d7f */ core::ptr::write((rsp).wrapping_add(0x3c_u64) as *mut u16, (rax as u16));
    /* 140096d84 */ let mut t_140096d84: u8 = core::ptr::read((0x140096d8b_u64).wrapping_add(0x26c533_u64) as *const u8);
    /* 140096d84 */ rax = ((t_140096d84 as u32) as u64);
    /* 140096d8b */ core::ptr::write((rsp).wrapping_add(0x3e_u64) as *mut u8, (rax as u8));
    /* 140096d8f */ core::ptr::write((rsp).wrapping_add(0x3f_u64) as *mut u8, 0x0_u8);
    /* 140096d94 */ xmm0 = ((rbx as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    // intrinsic: f3410f59 mulss xmm0, xmm12
    /* 140096da0 */ xmm3 = xmm14;
    // intrinsic: f30f5cd8 subss xmm3, xmm0
    /* 140096da8 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140096dad */ rdx = (0x64_u32 as u64);
    /* 140096db2 */ r8 = (0x32_u32 as u64);
    /* 140096db8 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140096dbd */ fn_140040b90();
    /* 140096dc3 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140096dc8 */ fn_140027900();
    /* fallthrough -> bb2418 */

    // ---- bb2418 @ 0x140096dcd ----
    /* 140096dcd */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140096dd4 */ rcx = core::ptr::read((rcx).wrapping_add((r12).wrapping_mul(0x1_u64)) as *const u64);
    /* 140096dd8 */ fn_1400b47d0();
    /* 140096ddd */ rax = core::ptr::read((rdi).wrapping_add(0x378_u64) as *const u64);
    /* 140096de4 */ let mut t_140096de4: u64 = core::ptr::read((rdi).wrapping_add(0x380_u64) as *const u64);
    if (rax != t_140096de4) {
        /* -> bb2426 */
    } else {
        /* -> bb2425 */
    }

    // ---- bb2425 @ 0x140096deb ----
    if (rax != t_140096de4) {
        /* -> bb2426 */
    } else {
        /* -> bb2439 */
    }

    // ---- bb2426 @ 0x140096ded ----
    /* 140096ded */ let mut t_140096ded: u64 = core::ptr::read((r12).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u64);
    if (t_140096ded != 0x0_u64) {
        /* -> bb2430 */
    } else {
        /* -> bb2429 */
    }

    // ---- bb2429 @ 0x140096df2 ----
    if (t_140096ded != 0x0_u64) {
        /* -> bb2430 */
    } else {
        /* -> bb2439 */
    }

    // ---- bb2430 @ 0x140096df4 ----
    /* 140096df4 */ rcx = (0x14_u32 as u64);
    /* 140096df9 */ fn_1400c6990();
    if (((SF != OF) | (t_140096ded == 0x0_u64)) == false) { /* -> bb2436 */ }
    if (((SF != OF) | (t_140096ded == 0x0_u64)) != 0) { /* -> bb2435 */ }

    // ---- bb2435 @ 0x140096e00 ----
    if (((SF != OF) | (t_140096ded == 0x0_u64)) == false) { /* -> bb2436 */ }
    if (((SF != OF) | (t_140096ded == 0x0_u64)) != 0) { /* -> bb2439 */ }

    // ---- bb2436 @ 0x140096e02 ----
    /* 140096e02 */ rcx = core::ptr::read((rdi).wrapping_add(0x378_u64) as *const u64);
    /* 140096e09 */ rcx = core::ptr::read((r12).wrapping_add((rcx).wrapping_mul(0x1_u64)) as *const u64);
    /* 140096e0d */ fn_1400b47d0();
    /* fallthrough -> bb2439 */

    // ---- bb2439 @ 0x140096e12 ----
    if (t_140096ded == 0x0_u64) {
        /* -> bb2443 */
    } else {
        /* -> bb2442 */
    }

    // ---- bb2442 @ 0x140096e14 ----
    if (t_140096ded == 0x0_u64) {
        /* -> bb2443 */
    } else {
        /* -> bb2459 */
    }

    // ---- bb2443 @ 0x140096e16 ----
    /* 140096e16 */ let mut t_140096e16: u32 = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u32);
    /* 140096e16 */ rax = (t_140096e16 as u64);
    if ((rax as u32) != 0x5_u32) {
        /* -> bb2448 */
    } else {
        /* -> bb2447 */
    }

    // ---- bb2447 @ 0x140096e1f ----
    if ((rax as u32) != 0x5_u32) {
        /* -> bb2448 */
    } else {
        /* -> bb2454 */
    }

    // ---- bb2448 @ 0x140096e21 ----
    if ((rax as u32) != 0x6_u32) {
        /* -> bb2452 */
    } else {
        /* -> bb2451 */
    }

    // ---- bb2451 @ 0x140096e24 ----
    if ((rax as u32) != 0x6_u32) {
        /* -> bb2452 */
    } else {
        /* -> bb2454 */
    }

    // ---- bb2452 @ 0x140096e26 ----
    /* 140096e26 */ let mut t_140096e26_0: u32 = 0x0_u32;
    /* 140096e26 */ r8 = (t_140096e26_0 as u64);
    /* fallthrough -> bb2455 */

    // ---- bb2454 @ 0x140096e2b ----
    /* 140096e2b */ r8 = ((r8 & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* fallthrough -> bb2455 */

    // ---- bb2455 @ 0x140096e2e ----
    /* 140096e2e */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140096e35 */ rdx = core::ptr::read((rdx).wrapping_add((r12).wrapping_mul(0x1_u64)) as *const u64);
    /* 140096e39 */ rcx = core::ptr::read((0x140096e40_u64).wrapping_add(0x3643a8_u64) as *const u64);
    /* 140096e40 */ fn_140105d80();
    /* fallthrough -> bb2459 */

    // ---- bb2459 @ 0x140096e45 ----
    /* 140096e45 */ let mut t_140096e45: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_140096e45 == 0x0_u8) {
        /* -> bb2463 */
    } else {
        /* -> bb2462 */
    }

    // ---- bb2462 @ 0x140096e4c ----
    if (t_140096e45 == 0x0_u8) {
        /* -> bb2463 */
    } else {
        /* -> bb2467 */
    }

    // ---- bb2463 @ 0x140096e4e ----
    /* 140096e4e */ let mut t_140096e4e: u8 = core::ptr::read((rdi).wrapping_add(0x259_u64) as *const u8);
    if (t_140096e4e != 0x0_u8) {
        /* -> bb2467 */
    } else {
        /* -> bb2466 */
    }

    // ---- bb2466 @ 0x140096e55 ----
    if (t_140096e4e != 0x0_u8) {
        /* -> bb2467 */
    } else {
        /* -> bb2587 */
    }

    // ---- bb2467 @ 0x140096e5b ----
    /* 140096e5b */ let mut t_140096e5b: u32 = core::ptr::read((rdi).wrapping_add(0x2fc_u64) as *const u32);
    if (t_140096e5b == 0x1_u32) {
        /* -> bb2471 */
    } else {
        /* -> bb2470 */
    }

    // ---- bb2470 @ 0x140096e62 ----
    if (t_140096e5b == 0x1_u32) {
        /* -> bb2471 */
    } else {
        /* -> bb2587 */
    }

    // ---- bb2471 @ 0x140096e68 ----
    /* 140096e68 */ r10 = core::ptr::read((0x140096e6f_u64).wrapping_add(0x3570c1_u64) as *const u64);
    /* 140096e6f */ rdx = core::ptr::read((0x140096e76_u64).wrapping_add(0x3570b2_u64) as *const u64);
    /* 140096e76 */ let mut t_140096e76_0: u64 = (r10).wrapping_sub(rdx);
    /* 140096e76 */ r10 = t_140096e76_0;
    /* 140096e79 */ r10 = (((r10 as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 140096e7d */ let mut t_140096e7d: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140096e7d */ rcx = ((t_140096e7d as i64) as u64);
    /* 140096e84 */ let mut t_140096e84: u32 = core::ptr::read((0x140096e8b_u64).wrapping_add(0x35705d_u64) as *const u32);
    /* 140096e84 */ rax = ((t_140096e84 as i64) as u64);
    /* 140096e8b */ core::ptr::write((rdx).wrapping_add((rax).wrapping_mul(0x8_u64)) as *mut u64, rcx);
    /* 140096e8f */ let mut t_140096e8f: u32 = core::ptr::read((0x140096e95_u64).wrapping_add(0x357053_u64) as *const u32);
    /* 140096e8f */ rax = (t_140096e8f as u64);
    /* 140096e95 */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* 140096e97 */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140096e98 */ let mut t_140096e98_0: u64 = (((((((rdx as u32) as u64) << 0x20_u64) | ((rax as u32) as u64)) as i64) / (((r10 as u32) as u64) as i64)) as u64);
    /* 140096e98 */ let mut t_140096e98_1: u64 = (((((((rdx as u32) as u64) << 0x20_u64) | ((rax as u32) as u64)) as i64) % (((r10 as u32) as u64) as i64)) as u64);
    /* 140096e98 */ rax = ((t_140096e98_0 as u32) as u64);
    /* 140096e98 */ rdx = ((t_140096e98_1 as u32) as u64);
    /* 140096e9b */ core::ptr::write((0x140096ea1_u64).wrapping_add(0x357047_u64) as *mut u32, (rdx as u32));
    /* 140096ea1 */ core::ptr::write((0x140096ea8_u64).wrapping_add(0x357038_u64) as *mut u64, rsi);
    /* 140096ea8 */ rdx = rsi;
    /* 140096eab */ r9 = (((r10 as u32) as i64) as u64);
    /* 140096eae */ rax = rsi;
    if (((SF != OF) | (t_140096e5b == 0x1_u32)) == false) { /* -> bb2491 */ }
    if (((SF != OF) | (t_140096e5b == 0x1_u32)) != 0) { /* -> bb2490 */ }

    // ---- bb2490 @ 0x140096eb4 ----
    if (((SF != OF) | (t_140096e5b == 0x1_u32)) == false) { /* -> bb2491 */ }
    if (((SF != OF) | (t_140096e5b == 0x1_u32)) != 0) { /* -> bb2500 */ }

    // ---- bb2491 @ 0x140096eb6 ----
    /* 140096eb6 */ r8 = core::ptr::read((0x140096ebd_u64).wrapping_add(0x35706b_u64) as *const u64);
    /* fallthrough -> bb2493 */

    // ---- bb2493 @ 0x140096ec0 ----
    /* 140096ec0 */ let mut t_140096ec0: u64 = core::ptr::read((r8).wrapping_add((rdx).wrapping_mul(0x8_u64)) as *const u64);
    /* 140096ec0 */ let mut t_140096ec0_0: u64 = (rax).wrapping_add(t_140096ec0);
    /* 140096ec0 */ rax = t_140096ec0_0;
    /* 140096ec4 */ core::ptr::write((0x140096ecb_u64).wrapping_add(0x357015_u64) as *mut u64, rax);
    /* 140096ecb */ rdx = (rdx).wrapping_add(0x1_u64);
    if (SF == OF) {
        /* -> bb2500 */
    } else {
        /* -> bb2499 */
    }

    // ---- bb2499 @ 0x140096ed1 ----
    if (SF != OF) {
        /* -> bb2493 */
    } else {
        /* -> bb2500 */
    }

    // ---- bb2500 @ 0x140096ed3 ----
    /* 140096ed3 */ rcx = (((r10 as u32) as i64) as u64);
    /* 140096ed6 */ let mut t_140096ed6_0: u32 = 0x0_u32;
    /* 140096ed6 */ rdx = (t_140096ed6_0 as u64);
    /* 140096ed8 */ let mut t_140096ed8_0: u128 = ((((rdx as u128) << 0x40_u128) | ((rax as u32) as u128)) / (rcx as u128));
    /* 140096ed8 */ let mut t_140096ed8_1: u128 = ((((rdx as u128) << 0x40_u128) | ((rax as u32) as u128)) % (rcx as u128));
    /* 140096ed8 */ rax = (t_140096ed8_0 as u64);
    /* 140096ed8 */ rdx = (t_140096ed8_1 as u64);
    /* 140096edb */ core::ptr::write((0x140096ee2_u64).wrapping_add(0x356ffe_u64) as *mut u64, rax);
    /* 140096ee2 */ let mut t_140096ee2: u32 = core::ptr::read((0x140096ee9_u64).wrapping_add(0x357007_u64) as *const u32);
    /* 140096ee2 */ rdx = ((t_140096ee2 as i64) as u64);
    /* 140096ee9 */ r8 = rdx;
    /* 140096eec */ r8 = (r8 >> (0x5_u8 as u64));
    /* 140096ef0 */ rcx = core::ptr::read((0x140096ef7_u64).wrapping_add(0x357011_u64) as *const u64);
    /* 140096ef7 */ let mut t_140096ef7_0: u32 = ((rdx as u32) & 0x1f_u32);
    /* 140096ef7 */ rdx = (t_140096ef7_0 as u64);
    /* 140096efa */ let mut t_140096efa: u32 = core::ptr::read((rcx).wrapping_add((r8).wrapping_mul(0x4_u64)) as *const u32);
    /* 140096efa */ rax = (t_140096efa as u64);
    /* 140096efe */ let mut t_140096efe_1: u32 = ((rax as u32) >> (rdx as u32));
    /* 140096efe */ rax = (((rax as u32) | (0x1_u32 << (rdx as u32))) as u64);
    /* 140096f01 */ core::ptr::write((rcx).wrapping_add((r8).wrapping_mul(0x4_u64)) as *mut u32, (rax as u32));
    /* 140096f05 */ let mut t_140096f05: u32 = core::ptr::read((0x140096f0b_u64).wrapping_add(0x356fe5_u64) as *const u32);
    /* 140096f05 */ rax = (t_140096f05 as u64);
    /* 140096f0b */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* 140096f0d */ rax = (((rax as u32) as i64) as u64);
    /* 140096f0f */ let mut t_140096f0f_0: u32 = 0x0_u32;
    /* 140096f0f */ rdx = (t_140096f0f_0 as u64);
    /* 140096f11 */ r10 = core::ptr::read((0x140096f18_u64).wrapping_add(0x357008_u64) as *const u64);
    /* 140096f18 */ let mut t_140096f18_0: u128 = ((((rdx as u128) << 0x40_u128) | ((rax as u32) as u128)) / (r10 as u128));
    /* 140096f18 */ let mut t_140096f18_1: u128 = ((((rdx as u128) << 0x40_u128) | ((rax as u32) as u128)) % (r10 as u128));
    /* 140096f18 */ rax = (t_140096f18_0 as u64);
    /* 140096f18 */ rdx = (t_140096f18_1 as u64);
    /* 140096f1b */ core::ptr::write((0x140096f21_u64).wrapping_add(0x356fcf_u64) as *mut u32, (rdx as u32));
    /* 140096f21 */ r8 = ((rsi as u32) as u64);
    /* 140096f24 */ core::ptr::write((0x140096f2a_u64).wrapping_add(0x356fc2_u64) as *mut u32, (rsi as u32));
    /* 140096f2a */ r9 = ((rsi as u32) as u64);
    if (rdx != r9) {
        /* -> bb2526 */
    } else {
        /* -> bb2525 */
    }

    // ---- bb2525 @ 0x140096f30 ----
    if (rdx != r9) {
        /* -> bb2526 */
    } else {
        /* -> bb2546 */
    }

    // ---- bb2526 @ 0x140096f32 ----
    /* 140096f32 */ rdx = rsi;
    /* 140096f35 */ r11 = core::ptr::read((0x140096f3c_u64).wrapping_add(0x356fcc_u64) as *const u64);
    /* fallthrough -> bb2529 */

    // ---- bb2529 @ 0x140096f40 ----
    /* 140096f40 */ rax = (((rdx as u8) as u32) as u64);
    /* 140096f43 */ let mut t_140096f43_0: u8 = ((rax as u8) & 0x1f_u8);
    /* 140096f43 */ rax = ((rax & 0xffffffffffffff00_u64) | (t_140096f43_0 as u64));
    /* 140096f45 */ rcx = (((rax as u8) as u32) as u64);
    /* 140096f48 */ rdx = (rdx >> (0x5_u8 as u64));
    /* 140096f4c */ let mut t_140096f4c: u32 = core::ptr::read((r11).wrapping_add((rdx).wrapping_mul(0x4_u64)) as *const u32);
    /* 140096f4c */ rax = (t_140096f4c as u64);
    /* 140096f50 */ let mut t_140096f50_0: u32 = ((rax as u32) >> (rcx as u32));
    if CF {
        /* -> bb2538 */
    } else {
        /* -> bb2537 */
    }

    // ---- bb2537 @ 0x140096f53 ----
    if CF {
        /* -> bb2538 */
    } else {
        /* -> bb2540 */
    }

    // ---- bb2538 @ 0x140096f55 ----
    /* 140096f55 */ r8 = (((r8 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140096f58 */ core::ptr::write((0x140096f5f_u64).wrapping_add(0x356f8d_u64) as *mut u32, (r8 as u32));
    /* fallthrough -> bb2540 */

    // ---- bb2540 @ 0x140096f5f ----
    /* 140096f5f */ r9 = (((r9 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140096f62 */ rdx = (((r9 as u32) as i64) as u64);
    if (CF == false) { /* -> bb2546 */ }
    if CF { /* -> bb2545 */ }

    // ---- bb2545 @ 0x140096f68 ----
    if CF { /* -> bb2529 */ }
    if (CF == false) { /* -> bb2546 */ }

    // ---- bb2546 @ 0x140096f6a ----
    /* 140096f6a */ fn_14003f5e0();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140096f72 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140096f77 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm10);
    /* 140096f7e */ rax = core::ptr::read((0x140096f85_u64).wrapping_add(0x26c33b_u64) as *const u64);
    /* 140096f85 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u32, (rax as u32));
    /* 140096f89 */ let mut t_140096f89: u16 = core::ptr::read((0x140096f90_u64).wrapping_add(0x26c334_u64) as *const u16);
    /* 140096f89 */ rax = ((t_140096f89 as u32) as u64);
    /* 140096f90 */ core::ptr::write((rsp).wrapping_add(0x34_u64) as *mut u16, (rax as u16));
    /* 140096f95 */ let mut t_140096f95: u8 = core::ptr::read((0x140096f9c_u64).wrapping_add(0x26c32a_u64) as *const u8);
    /* 140096f95 */ rax = ((t_140096f95 as u32) as u64);
    /* 140096f9c */ core::ptr::write((rsp).wrapping_add(0x36_u64) as *mut u8, (rax as u8));
    /* 140096fa0 */ core::ptr::write((rsp).wrapping_add(0x37_u64) as *mut u8, 0x0_u8);
    /* 140096fa5 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140096faa */ xmm3 = xmm14;
    /* 140096fae */ let mut t_140096fae_0: u32 = 0x0_u32;
    /* 140096fae */ r8 = (t_140096fae_0 as u64);
    /* 140096fb1 */ rdx = (0x64_u32 as u64);
    /* 140096fb6 */ rcx = (rsp).wrapping_add(0x30_u64);
    /* 140096fbb */ fn_140040b90();
    /* 140096fc1 */ rdx = core::ptr::read((rsp).wrapping_add(0x48_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2569 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2568 */ }

    // ---- bb2568 @ 0x140096fca ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2569 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2585 */ }

    // ---- bb2569 @ 0x140096fcc ----
    /* 140096fcc */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140096fcf */ rcx = core::ptr::read((rsp).wrapping_add(0x30_u64) as *const u64);
    /* 140096fd4 */ rax = rcx;
    if (CF == false) { /* -> bb2576 */ }
    if CF { /* -> bb2575 */ }

    // ---- bb2575 @ 0x140096fde ----
    if (CF == false) { /* -> bb2576 */ }
    if CF { /* -> bb2584 */ }

    // ---- bb2576 @ 0x140096fe0 ----
    /* 140096fe0 */ let mut t_140096fe0_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140096fe0 */ rdx = t_140096fe0_0;
    /* 140096fe4 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140096fe8 */ let mut t_140096fe8_0: u64 = (rax).wrapping_sub(rcx);
    /* 140096fe8 */ rax = t_140096fe8_0;
    /* 140096feb */ let mut t_140096feb_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140096feb */ rax = t_140096feb_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2584 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2583 */ }

    // ---- bb2583 @ 0x140096ff3 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2584 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3511 */ }

    // ---- bb2584 @ 0x140096ff9 ----
    /* 140096ff9 */ fn_1402c7498();
    /* fallthrough -> bb2585 */

    // ---- bb2585 @ 0x140096ffe ----
    /* 140096ffe */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0xa_u64);
    /* fallthrough -> bb2666 */

    // ---- bb2587 @ 0x14009700e ----
    /* 14009700e */ let mut t_14009700e: u32 = core::ptr::read((rdi).wrapping_add(0x2bc_u64) as *const u32);
    /* 14009700e */ r8 = (t_14009700e as u64);
    /* 140097015 */ let mut t_140097015: u32 = core::ptr::read((rdi).wrapping_add(0x2fc_u64) as *const u32);
    /* 140097015 */ rdx = (t_140097015 as u64);
    if (((SF == OF) & ((rdx as u32) != (r8 as u32))) == false) { /* -> bb2593 */ }
    if (((SF == OF) & ((rdx as u32) != (r8 as u32))) != 0) { /* -> bb2592 */ }

    // ---- bb2592 @ 0x14009701e ----
    if (((SF == OF) & ((rdx as u32) != (r8 as u32))) == false) { /* -> bb2593 */ }
    if (((SF == OF) & ((rdx as u32) != (r8 as u32))) != 0) { /* -> bb2641 */ }

    // ---- bb2593 @ 0x140097024 ----
    /* 140097024 */ rcx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 14009702b */ let mut t_14009702b: u32 = core::ptr::read(((r15).wrapping_add((rcx).wrapping_mul(0x1_u64))).wrapping_add(0xc_u64) as *const u32);
    /* 14009702b */ rax = (t_14009702b as u64);
    /* 140097030 */ let mut t_140097030: u32 = core::ptr::read(((r15).wrapping_add((rcx).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *const u32);
    if (t_140097030 != (rax as u32)) {
        /* -> bb2599 */
    } else {
        /* -> bb2598 */
    }

    // ---- bb2598 @ 0x140097035 ----
    if (t_140097030 != (rax as u32)) {
        /* -> bb2599 */
    } else {
        /* -> bb2626 */
    }

    // ---- bb2599 @ 0x140097037 ----
    /* 140097037 */ let mut t_140097037: u8 = core::ptr::read((rdi).wrapping_add(0x2e4_u64) as *const u8);
    if (t_140097037 == 0x0_u8) {
        /* -> bb2603 */
    } else {
        /* -> bb2602 */
    }

    // ---- bb2602 @ 0x14009703e ----
    if (t_140097037 == 0x0_u8) {
        /* -> bb2603 */
    } else {
        /* -> bb2666 */
    }

    // ---- bb2603 @ 0x140097044 ----
    /* 140097044 */ fn_14003f5e0();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14009704c */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140097051 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u128, xmm13);
    /* 140097058 */ rax = 0x6563615265736f4c_u64;
    /* 140097062 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u64, rax);
    /* 140097067 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u8, 0x0_u8);
    /* 14009706c */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140097071 */ xmm3 = xmm14;
    /* 140097075 */ let mut t_140097075_0: u32 = 0x0_u32;
    /* 140097075 */ r8 = (t_140097075_0 as u64);
    /* 140097078 */ rdx = (0x64_u32 as u64);
    /* 14009707d */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097082 */ fn_140040b90();
    /* 140097088 */ r8 = core::ptr::read((rsp).wrapping_add(0x70_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb2622 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb2621 */ }

    // ---- bb2621 @ 0x140097091 ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb2622 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb2665 */ }

    // ---- bb2622 @ 0x140097097 ----
    /* 140097097 */ rdx = core::ptr::read((rsp).wrapping_add(0x58_u64) as *const u64);
    /* 14009709c */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400970a1 */ fn_140028310();
    /* fallthrough -> bb2665 */

    // ---- bb2626 @ 0x1400970ab ----
    if ((rdx as u32) == (r8 as u32)) {
        /* -> bb2630 */
    } else {
        /* -> bb2629 */
    }

    // ---- bb2629 @ 0x1400970ae ----
    if ((rdx as u32) == (r8 as u32)) {
        /* -> bb2630 */
    } else {
        /* -> bb2641 */
    }

    // ---- bb2630 @ 0x1400970b0 ----
    /* 1400970b0 */ let mut t_1400970b0: u8 = core::ptr::read((rdi).wrapping_add(0x2e4_u64) as *const u8);
    if (t_1400970b0 == 0x0_u8) {
        /* -> bb2634 */
    } else {
        /* -> bb2633 */
    }

    // ---- bb2633 @ 0x1400970b7 ----
    if (t_1400970b0 == 0x0_u8) {
        /* -> bb2634 */
    } else {
        /* -> bb2641 */
    }

    // ---- bb2634 @ 0x1400970b9 ----
    /* 1400970b9 */ let mut t_1400970b9_0: u32 = 0x0_u32;
    /* 1400970b9 */ r8 = (t_1400970b9_0 as u64);
    /* 1400970bc */ rdx = (0x1b_u32 as u64);
    /* 1400970c1 */ rcx = rdi;
    /* 1400970c4 */ fn_1400ca650();
    /* 1400970c9 */ fn_14003f5e0();
    /* 1400970ce */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0x9_u64);
    /* fallthrough -> bb2666 */

    // ---- bb2641 @ 0x1400970db ----
    /* 1400970db */ let mut t_1400970db: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    if ((rdx as u32) == t_1400970db) {
        /* -> bb2645 */
    } else {
        /* -> bb2644 */
    }

    // ---- bb2644 @ 0x1400970e1 ----
    if ((rdx as u32) == t_1400970db) {
        /* -> bb2645 */
    } else {
        /* -> bb2666 */
    }

    // ---- bb2645 @ 0x1400970e3 ----
    /* 1400970e3 */ let mut t_1400970e3: u8 = core::ptr::read((rdi).wrapping_add(0x2e4_u64) as *const u8);
    if (t_1400970e3 == 0x0_u8) {
        /* -> bb2649 */
    } else {
        /* -> bb2648 */
    }

    // ---- bb2648 @ 0x1400970ea ----
    if (t_1400970e3 == 0x0_u8) {
        /* -> bb2649 */
    } else {
        /* -> bb2666 */
    }

    // ---- bb2649 @ 0x1400970ec ----
    /* 1400970ec */ fn_14003f5e0();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400970f4 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 1400970f9 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u128, xmm13);
    /* 140097100 */ rax = 0x6563615265736f4c_u64;
    /* 14009710a */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u64, rax);
    /* 14009710f */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u8, 0x0_u8);
    /* 140097114 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140097119 */ xmm3 = xmm14;
    /* 14009711d */ let mut t_14009711d_0: u32 = 0x0_u32;
    /* 14009711d */ r8 = (t_14009711d_0 as u64);
    /* 140097120 */ rdx = (0x64_u32 as u64);
    /* 140097125 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14009712a */ fn_140040b90();
    /* 140097130 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097135 */ fn_140027900();
    /* fallthrough -> bb2665 */

    // ---- bb2665 @ 0x14009713a ----
    /* 14009713a */ core::ptr::write((rdi).wrapping_add(0x2e4_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb2666 */

    // ---- bb2666 @ 0x140097141 ----
    /* 140097141 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    // intrinsic: f3410f10 movss xmm0, dword ptr [r15 + rax + 0x24]
    // intrinsic: 410f2f44 comiss xmm0, dword ptr [r15 + rax + 0x20]
    if ((CF | (t_1400970e3 == 0x0_u8)) == false) { /* -> bb2672 */ }
    if ((CF | (t_1400970e3 == 0x0_u8)) != 0) { /* -> bb2671 */ }

    // ---- bb2671 @ 0x140097155 ----
    if ((CF | (t_1400970e3 == 0x0_u8)) == false) { /* -> bb2672 */ }
    if ((CF | (t_1400970e3 == 0x0_u8)) != 0) { /* -> bb2677 */ }

    // ---- bb2672 @ 0x140097157 ----
    // intrinsic: f3410f58 addss xmm0, xmm9
    // intrinsic: f3410f11 movss dword ptr [r15 + rax + 0x20], xmm0
    /* 140097163 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 14009716a */ core::ptr::write(((r15).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0x14_u64) as *mut u32, (rsi as u32));
    /* fallthrough -> bb2687 */

    // ---- bb2677 @ 0x140097171 ----
    /* 140097171 */ let mut t_140097171: u32 = core::ptr::read(((r15).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0x14_u64) as *const u32);
    /* 140097171 */ core::ptr::write(((r15).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0x14_u64) as *mut u32, (t_140097171).wrapping_add(0x1_u32));
    /* 140097176 */ let mut t_140097176: u32 = core::ptr::read(((r15).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0x14_u64) as *const u32);
    if (((SF != OF) | (t_140097176 == 0x12c_u32)) == false) { /* -> bb2682 */ }
    if (((SF != OF) | (t_140097176 == 0x12c_u32)) != 0) { /* -> bb2681 */ }

    // ---- bb2681 @ 0x14009717f ----
    if (((SF != OF) | (t_140097176 == 0x12c_u32)) == false) { /* -> bb2682 */ }
    if (((SF != OF) | (t_140097176 == 0x12c_u32)) != 0) { /* -> bb2687 */ }

    // ---- bb2682 @ 0x140097181 ----
    /* 140097181 */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140097188 */ rcx = core::ptr::read((r12).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u64);
    /* 14009718c */ let mut t_14009718c: u32 = core::ptr::read((rcx).wrapping_add(0x25c_u64) as *const u32);
    /* 14009718c */ rax = (t_14009718c as u64);
    /* 140097192 */ core::ptr::write((rcx).wrapping_add(0x260_u64) as *mut u32, (rax as u32));
    /* 140097198 */ let mut t_140097198: u32 = core::ptr::read((rbp).wrapping_add(0x60_u64) as *const u32);
    /* 140097198 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u32, (t_140097198).wrapping_add(0x1_u32));
    /* fallthrough -> bb2687 */

    // ---- bb2687 @ 0x14009719b ----
    /* 14009719b */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400971a2 */ rcx = core::ptr::read((r12).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u64);
    /* 1400971a6 */ let mut t_1400971a6: u32 = core::ptr::read((rcx).wrapping_add(0x270_u64) as *const u32);
    if (t_1400971a6 == 0x1_u32) {
        /* -> bb2693 */
    } else {
        /* -> bb2692 */
    }

    // ---- bb2692 @ 0x1400971ad ----
    if (t_1400971a6 == 0x1_u32) {
        /* -> bb2693 */
    } else {
        /* -> bb2716 */
    }

    // ---- bb2693 @ 0x1400971af ----
    /* 1400971af */ let mut t_1400971af: u32 = core::ptr::read((rcx).wrapping_add(0x258_u64) as *const u32);
    if (t_1400971a6 != 0x1_u32) {
        /* -> bb2697 */
    } else {
        /* -> bb2696 */
    }

    // ---- bb2696 @ 0x1400971b9 ----
    if (t_1400971a6 != 0x1_u32) {
        /* -> bb2697 */
    } else {
        /* -> bb2716 */
    }

    // ---- bb2697 @ 0x1400971bb ----
    /* 1400971bb */ let mut t_1400971bb: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_1400971bb == 0x0_u8) {
        /* -> bb2701 */
    } else {
        /* -> bb2700 */
    }

    // ---- bb2700 @ 0x1400971c2 ----
    if (t_1400971bb == 0x0_u8) {
        /* -> bb2701 */
    } else {
        /* -> bb2716 */
    }

    // ---- bb2701 @ 0x1400971c4 ----
    /* 1400971c4 */ rcx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 1400971cb */ let mut t_1400971cb: u32 = core::ptr::read(((r15).wrapping_add((rcx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *const u32);
    /* 1400971cb */ rax = (t_1400971cb as u64);
    /* 1400971d0 */ let mut t_1400971d0_0: u32 = (0x11_u8 as u32);
    /* 1400971d0 */ t_1400971d0_0 = ((rax as u32) >> t_1400971d0_0);
    if (CF == false) { /* -> bb2707 */ }
    if CF { /* -> bb2706 */ }

    // ---- bb2706 @ 0x1400971d4 ----
    if (CF == false) { /* -> bb2707 */ }
    if CF { /* -> bb2716 */ }

    // ---- bb2707 @ 0x1400971d6 ----
    /* 1400971d6 */ let mut t_1400971d6_0: u32 = (0x11_u8 as u32);
    /* 1400971d6 */ let mut t_1400971d6_1: u32 = ((rax as u32) >> t_1400971d6_0);
    /* 1400971d6 */ rax = (((rax as u32) & ((0x1_u32 << t_1400971d6_0) ^ 0xffffffff_u32)) as u64);
    /* 1400971da */ core::ptr::write(((r15).wrapping_add((rcx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *mut u32, (rax as u32));
    /* 1400971df */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400971e6 */ rcx = core::ptr::read((rcx).wrapping_add((r12).wrapping_mul(0x1_u64)) as *const u64);
    /* 1400971ea */ fn_1400b87d0();
    /* 1400971ef */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400971f6 */ rdx = core::ptr::read((rdx).wrapping_add((r12).wrapping_mul(0x1_u64)) as *const u64);
    /* 1400971fa */ rcx = rdi;
    /* 1400971fd */ fn_1400d5360();
    /* fallthrough -> bb2716 */

    // ---- bb2716 @ 0x140097202 ----
    /* 140097202 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140097209 */ let mut t_140097209: u32 = core::ptr::read((rbp).wrapping_add(0x68_u64) as *const u32);
    /* 140097209 */ r14 = (t_140097209 as u64);
    /* 14009720d */ let mut t_14009720d: u32 = core::ptr::read(((r15).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0x14_u64) as *const u32);
    if (SF == OF) {
        /* -> bb2720 */
    } else {
        /* -> bb2721 */
    }

    // ---- bb2721 @ 0x140097212 ----
    /* 140097212 */ let mut t_140097212: u32 = core::ptr::read(((r15).wrapping_add((rax).wrapping_mul(0x1_u64))).wrapping_add(0x14_u64) as *const u32);
    /* 140097212 */ r14 = (t_140097212 as u64);
    /* fallthrough -> bb2720 */

    // ---- bb2720 @ 0x140097218 ----
    /* 140097218 */ core::ptr::write((rbp).wrapping_add(0x68_u64) as *mut u32, (r14 as u32));
    /* 14009721c */ rbx = (rdi).wrapping_add(0x130_u64);
    /* fallthrough -> bb2724 */

    // ---- bb2724 @ 0x140097223 ----
    /* 140097223 */ r13 = (((r13 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140097226 */ let mut t_140097226_0: u64 = (r12).wrapping_add(0x8_u64);
    /* 140097226 */ r12 = t_140097226_0;
    /* 14009722a */ let mut t_14009722a_0: u64 = (r15).wrapping_add(0x70_u64);
    /* 14009722a */ r15 = t_14009722a_0;
    /* 14009722e */ let mut t_14009722e: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    /* 14009722e */ rax = (t_14009722e as u64);
    if (SF == OF) {
        /* -> bb2732 */
    } else {
        /* -> bb2731 */
    }

    // ---- bb2731 @ 0x140097237 ----
    if (SF != OF) {
        /* -> bb2311 */
    } else {
        /* -> bb2732 */
    }

    // ---- bb2732 @ 0x14009723d ----
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x26c10f]
    /* 140097245 */ let mut t_140097245: u32 = core::ptr::read((rbp).wrapping_add(0x60_u64) as *const u32);
    /* 140097245 */ rbx = (t_140097245 as u64);
    /* fallthrough -> bb2734 */

    // ---- bb2734 @ 0x140097248 ----
    /* 140097248 */ let mut t_140097248: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140097248 */ xmm2 = (t_140097248 as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 140097253 */ xmm1 = xmm15;
    // intrinsic: f30f590d mulss xmm1, dword ptr [rip + 0x26c12d]
    // intrinsic: f30f580d addss xmm1, dword ptr [rip + 0x26cdad]
    // intrinsic: f30f590d mulss xmm1, dword ptr [rip + 0x26cda5]
    // intrinsic: 0f2fd100 comiss xmm2, xmm1
    /* 140097272 */ rcx = ((rcx & 0xffffffffffffff00_u64) | ((((CF == false) & (ZF == false)) as u8) as u64));
    /* 140097275 */ let mut t_140097275: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_140097275 != 0x0_u8) {
        /* -> bb2746 */
    } else {
        /* -> bb2745 */
    }

    // ---- bb2745 @ 0x14009727c ----
    if (t_140097275 != 0x0_u8) {
        /* -> bb2746 */
    } else {
        /* -> bb2813 */
    }

    // ---- bb2746 @ 0x140097282 ----
    if ((rbx as u32) != (rax as u32)) {
        /* -> bb2750 */
    } else {
        /* -> bb2749 */
    }

    // ---- bb2749 @ 0x140097284 ----
    if ((rbx as u32) != (rax as u32)) {
        /* -> bb2750 */
    } else {
        /* -> bb2755 */
    }

    // ---- bb2750 @ 0x140097286 ----
    if ((rbx as u32) != (rax as u32)) {
        /* -> bb2754 */
    } else {
        /* -> bb2753 */
    }

    // ---- bb2753 @ 0x140097288 ----
    if ((rbx as u32) != (rax as u32)) {
        /* -> bb2754 */
    } else {
        /* -> bb2813 */
    }

    // ---- bb2754 @ 0x14009728e ----
    /* fallthrough -> bb2759 */

    // ---- bb2755 @ 0x140097290 ----
    if ((rbx as u32) != (rax as u32)) {
        /* -> bb2759 */
    } else {
        /* -> bb2758 */
    }

    // ---- bb2758 @ 0x140097292 ----
    if ((rbx as u32) != (rax as u32)) {
        /* -> bb2759 */
    } else {
        /* -> bb2770 */
    }

    // ---- bb2759 @ 0x140097294 ----
    /* 140097294 */ let mut t_140097294: u8 = core::ptr::read((0x14009729b_u64).wrapping_add(0x34226d_u64) as *const u8);
    if (t_140097294 != 0x0_u8) {
        /* -> bb2763 */
    } else {
        /* -> bb2762 */
    }

    // ---- bb2762 @ 0x14009729b ----
    if (t_140097294 != 0x0_u8) {
        /* -> bb2763 */
    } else {
        /* -> bb2768 */
    }

    // ---- bb2763 @ 0x14009729d ----
    /* 14009729d */ let mut t_14009729d: u32 = core::ptr::read((0x1400972a3_u64).wrapping_add(0x356ce5_u64) as *const u32);
    /* 14009729d */ rdx = (t_14009729d as u64);
    /* 1400972a3 */ rdx = (((rdx as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400972a5 */ core::ptr::write((0x1400972ab_u64).wrapping_add(0x356cdd_u64) as *mut u32, (rdx as u32));
    /* 1400972ab */ rcx = (0x1400972b2_u64).wrapping_add(0x274ede_u64);
    /* 1400972b2 */ fn_1400c4650();
    /* fallthrough -> bb2768 */

    // ---- bb2768 @ 0x1400972b7 ----
    /* 1400972b7 */ rcx = rdi;
    /* 1400972ba */ fn_140092470();
    /* fallthrough -> bb2770 */

    // ---- bb2770 @ 0x1400972bf ----
    /* 1400972bf */ let mut t_1400972bf: u32 = core::ptr::read((0x1400972c6_u64).wrapping_add(0x356c2a_u64) as *const u32);
    /* 1400972bf */ rdx = ((t_1400972bf as i64) as u64);
    /* 1400972c6 */ r8 = rdx;
    /* 1400972c9 */ r8 = (r8 >> (0x5_u8 as u64));
    /* 1400972cd */ rcx = core::ptr::read((0x1400972d4_u64).wrapping_add(0x356c34_u64) as *const u64);
    /* 1400972d4 */ let mut t_1400972d4_0: u32 = ((rdx as u32) & 0x1f_u32);
    /* 1400972d4 */ rdx = (t_1400972d4_0 as u64);
    /* 1400972d7 */ let mut t_1400972d7: u32 = core::ptr::read((rcx).wrapping_add((r8).wrapping_mul(0x4_u64)) as *const u32);
    /* 1400972d7 */ rax = (t_1400972d7 as u64);
    /* 1400972db */ let mut t_1400972db_1: u32 = ((rax as u32) >> (rdx as u32));
    /* 1400972db */ rax = (((rax as u32) & ((0x1_u32 << (rdx as u32)) ^ 0xffffffff_u32)) as u64);
    /* 1400972de */ core::ptr::write((rcx).wrapping_add((r8).wrapping_mul(0x4_u64)) as *mut u32, (rax as u32));
    /* 1400972e2 */ let mut t_1400972e2: u32 = core::ptr::read((0x1400972e8_u64).wrapping_add(0x356c08_u64) as *const u32);
    /* 1400972e2 */ rax = (t_1400972e2 as u64);
    /* 1400972e8 */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400972ea */ rax = (((rax as u32) as i64) as u64);
    /* 1400972ec */ let mut t_1400972ec_0: u32 = 0x0_u32;
    /* 1400972ec */ rdx = (t_1400972ec_0 as u64);
    /* 1400972ee */ r10 = core::ptr::read((0x1400972f5_u64).wrapping_add(0x356c2b_u64) as *const u64);
    /* 1400972f5 */ let mut t_1400972f5_0: u128 = ((((rdx as u128) << 0x40_u128) | ((rax as u32) as u128)) / (r10 as u128));
    /* 1400972f5 */ let mut t_1400972f5_1: u128 = ((((rdx as u128) << 0x40_u128) | ((rax as u32) as u128)) % (r10 as u128));
    /* 1400972f5 */ rax = (t_1400972f5_0 as u64);
    /* 1400972f5 */ rdx = (t_1400972f5_1 as u64);
    /* 1400972f8 */ core::ptr::write((0x1400972fe_u64).wrapping_add(0x356bf2_u64) as *mut u32, (rdx as u32));
    /* 1400972fe */ r8 = ((rsi as u32) as u64);
    /* 140097301 */ core::ptr::write((0x140097307_u64).wrapping_add(0x356be5_u64) as *mut u32, (rsi as u32));
    /* 140097307 */ r9 = ((rsi as u32) as u64);
    if ((rbx as u32) != (rax as u32)) {
        /* -> bb2792 */
    } else {
        /* -> bb2791 */
    }

    // ---- bb2791 @ 0x14009730d ----
    if ((rbx as u32) != (rax as u32)) {
        /* -> bb2792 */
    } else {
        /* -> bb2812 */
    }

    // ---- bb2792 @ 0x14009730f ----
    /* 14009730f */ rdx = rsi;
    /* 140097312 */ r11 = core::ptr::read((0x140097319_u64).wrapping_add(0x356bef_u64) as *const u64);
    /* fallthrough -> bb2795 */

    // ---- bb2795 @ 0x140097320 ----
    /* 140097320 */ rax = (((rdx as u8) as u32) as u64);
    /* 140097323 */ let mut t_140097323_0: u8 = ((rax as u8) & 0x1f_u8);
    /* 140097323 */ rax = ((rax & 0xffffffffffffff00_u64) | (t_140097323_0 as u64));
    /* 140097325 */ rcx = (((rax as u8) as u32) as u64);
    /* 140097328 */ rdx = (rdx >> (0x5_u8 as u64));
    /* 14009732c */ let mut t_14009732c: u32 = core::ptr::read((r11).wrapping_add((rdx).wrapping_mul(0x4_u64)) as *const u32);
    /* 14009732c */ rax = (t_14009732c as u64);
    /* 140097330 */ let mut t_140097330_0: u32 = ((rax as u32) >> (rcx as u32));
    if CF {
        /* -> bb2804 */
    } else {
        /* -> bb2803 */
    }

    // ---- bb2803 @ 0x140097333 ----
    if CF {
        /* -> bb2804 */
    } else {
        /* -> bb2806 */
    }

    // ---- bb2804 @ 0x140097335 ----
    /* 140097335 */ r8 = (((r8 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140097338 */ core::ptr::write((0x14009733f_u64).wrapping_add(0x356bad_u64) as *mut u32, (r8 as u32));
    /* fallthrough -> bb2806 */

    // ---- bb2806 @ 0x14009733f ----
    /* 14009733f */ r9 = (((r9 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140097342 */ rdx = (((r9 as u32) as i64) as u64);
    if (CF == false) { /* -> bb2812 */ }
    if CF { /* -> bb2811 */ }

    // ---- bb2811 @ 0x140097348 ----
    if CF { /* -> bb2795 */ }
    if (CF == false) { /* -> bb2812 */ }

    // ---- bb2812 @ 0x14009734a ----
    /* 14009734a */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0xa_u64);
    /* fallthrough -> bb2813 */

    // ---- bb2813 @ 0x140097355 ----
    /* 140097355 */ let mut t_140097355: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    if ((rbx as u32) == t_140097355) {
        /* -> bb2817 */
    } else {
        /* -> bb2816 */
    }

    // ---- bb2816 @ 0x14009735b ----
    if ((rbx as u32) == t_140097355) {
        /* -> bb2817 */
    } else {
        /* -> bb2903 */
    }

    // ---- bb2817 @ 0x140097361 ----
    if (SF == OF) {
        /* -> bb2821 */
    } else {
        /* -> bb2820 */
    }

    // ---- bb2820 @ 0x140097368 ----
    if (SF == OF) {
        /* -> bb2821 */
    } else {
        /* -> bb2903 */
    }

    // ---- bb2821 @ 0x14009736e ----
    /* 14009736e */ let mut t_14009736e: u32 = core::ptr::read((rdi).wrapping_add(0x2fc_u64) as *const u32);
    if (t_14009736e == 0x0_u32) {
        /* -> bb2825 */
    } else {
        /* -> bb2824 */
    }

    // ---- bb2824 @ 0x140097375 ----
    if (t_14009736e == 0x0_u32) {
        /* -> bb2825 */
    } else {
        /* -> bb2903 */
    }

    // ---- bb2825 @ 0x14009737b ----
    /* 14009737b */ let mut t_14009737b: u8 = core::ptr::read((rdi).wrapping_add(0x2e4_u64) as *const u8);
    if (t_14009737b == 0x0_u8) {
        /* -> bb2829 */
    } else {
        /* -> bb2828 */
    }

    // ---- bb2828 @ 0x140097382 ----
    if (t_14009737b == 0x0_u8) {
        /* -> bb2829 */
    } else {
        /* -> bb2903 */
    }

    // ---- bb2829 @ 0x140097388 ----
    /* 140097388 */ r15 = ((r15 & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 14009738b */ r14 = ((rsi as u32) as u64);
    /* 14009738e */ let mut t_14009738e: u32 = core::ptr::read((rdi).wrapping_add(0x2bc_u64) as *const u32);
    if (((SF != OF) | (t_14009738e == (rsi as u32))) == false) { /* -> bb2835 */ }
    if (((SF != OF) | (t_14009738e == (rsi as u32))) != 0) { /* -> bb2834 */ }

    // ---- bb2834 @ 0x140097394 ----
    if (((SF != OF) | (t_14009738e == (rsi as u32))) == false) { /* -> bb2835 */ }
    if (((SF != OF) | (t_14009738e == (rsi as u32))) != 0) { /* -> bb2897 */ }

    // ---- bb2835 @ 0x14009739a ----
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x274f9e]
    /* fallthrough -> bb2836 */

    // ---- bb2836 @ 0x1400973a2 ----
    if ((r14 as u32) != t_140097433) {
        /* -> bb2840 */
    } else {
        /* -> bb2839 */
    }

    // ---- bb2839 @ 0x1400973a5 ----
    if ((r14 as u32) != t_140097433) {
        /* -> bb2840 */
    } else {
        /* -> bb2895 */
    }

    // ---- bb2840 @ 0x1400973ab ----
    /* 1400973ab */ xmm1 = xmm6;
    /* 1400973ae */ rdx = (0xffffffff_u32 as u64);
    /* 1400973b3 */ r10 = 0xffffffffffffffff_u64;
    /* 1400973ba */ rcx = ((rsi as u32) as u64);
    /* 1400973bc */ r8 = rsi;
    /* 1400973bf */ let mut t_1400973bf: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    /* 1400973bf */ r9 = (t_1400973bf as u64);
    if (((SF != OF) | ((r14 as u32) == t_140097433)) == false) { /* -> bb2850 */ }
    if (((SF != OF) | ((r14 as u32) == t_140097433)) != 0) { /* -> bb2849 */ }

    // ---- bb2849 @ 0x1400973c9 ----
    if (((SF != OF) | ((r14 as u32) == t_140097433)) == false) { /* -> bb2850 */ }
    if (((SF != OF) | ((r14 as u32) == t_140097433)) != 0) { /* -> bb2886 */ }

    // ---- bb2850 @ 0x1400973cb ----
    /* 1400973cb */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 1400973d2 */ let mut t_1400973d2_0: u64 = (rax).wrapping_add(0x24_u64);
    /* 1400973d2 */ rax = t_1400973d2_0;
    /* fallthrough -> bb2852 */

    // ---- bb2852 @ 0x1400973d6 ----
    /* 1400973d6 */ let mut t_1400973d6: u32 = core::ptr::read((rax).wrapping_sub(0x18_u64) as *const u32);
    if (t_1400973d6 == 0xffffffff_u32) {
        /* -> bb2856 */
    } else {
        /* -> bb2855 */
    }

    // ---- bb2855 @ 0x1400973da ----
    if (t_1400973d6 == 0xffffffff_u32) {
        /* -> bb2856 */
    } else {
        /* -> bb2864 */
    }

    // ---- bb2856 @ 0x1400973dc ----
    // intrinsic: f30f1000 movss xmm0, dword ptr [rax]
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if ((CF | (t_1400973d6 == 0xffffffff_u32)) == false) { /* -> bb2861 */ }
    if ((CF | (t_1400973d6 == 0xffffffff_u32)) != 0) { /* -> bb2860 */ }

    // ---- bb2860 @ 0x1400973e3 ----
    if ((CF | (t_1400973d6 == 0xffffffff_u32)) == false) { /* -> bb2861 */ }
    if ((CF | (t_1400973d6 == 0xffffffff_u32)) != 0) { /* -> bb2864 */ }

    // ---- bb2861 @ 0x1400973e5 ----
    /* 1400973e5 */ xmm1 = xmm0;
    /* 1400973e8 */ rdx = ((rcx as u32) as u64);
    /* 1400973ea */ r10 = r8;
    /* fallthrough -> bb2864 */

    // ---- bb2864 @ 0x1400973ed ----
    /* 1400973ed */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400973ef */ r8 = (r8).wrapping_add(0x1_u64);
    /* 1400973f2 */ let mut t_1400973f2_0: u64 = (rax).wrapping_add(0x70_u64);
    /* 1400973f2 */ rax = t_1400973f2_0;
    if (SF == OF) {
        /* -> bb2871 */
    } else {
        /* -> bb2870 */
    }

    // ---- bb2870 @ 0x1400973f9 ----
    if (SF != OF) {
        /* -> bb2852 */
    } else {
        /* -> bb2871 */
    }

    // ---- bb2871 @ 0x1400973fb ----
    if ((rdx as u32) != 0xffffffff_u32) {
        /* -> bb2875 */
    } else {
        /* -> bb2874 */
    }

    // ---- bb2874 @ 0x1400973fe ----
    if ((rdx as u32) != 0xffffffff_u32) {
        /* -> bb2875 */
    } else {
        /* -> bb2886 */
    }

    // ---- bb2875 @ 0x140097400 ----
    /* 140097400 */ let mut t_140097400_0: u128 = ((r10 as u128)).wrapping_mul((0x70_u64 as u128));
    /* 140097400 */ rbx = (t_140097400_0 as u64);
    /* 140097404 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 14009740b */ core::ptr::write(((rax).wrapping_add((rbx).wrapping_mul(0x1_u64))).wrapping_add(0xc_u64) as *mut u32, (r14 as u32));
    /* 140097410 */ rcx = (0x140097417_u64).wrapping_add(0x274d89_u64);
    /* 140097417 */ fn_1400c4650();
    /* 14009741c */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140097423 */ r15 = (((r15 as u8) as u32) as u64);
    /* 140097427 */ let mut t_140097427: u32 = core::ptr::read(((rax).wrapping_add((rbx).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *const u32);
    if (t_140097427 == (r14 as u32)) {
        /* -> bb2886 */
    } else {
        /* -> bb2885 */
    }

    // ---- bb2885 @ 0x14009742c ----
    /* 14009742c */ r15 = ((rsi as u32) as u64);
    /* fallthrough -> bb2886 */

    // ---- bb2886 @ 0x140097430 ----
    /* 140097430 */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140097433 */ let mut t_140097433: u32 = core::ptr::read((rdi).wrapping_add(0x2bc_u64) as *const u32);
    if (SF == OF) {
        /* -> bb2891 */
    } else {
        /* -> bb2890 */
    }

    // ---- bb2890 @ 0x14009743a ----
    if (SF != OF) {
        /* -> bb2836 */
    } else {
        /* -> bb2891 */
    }

    // ---- bb2891 @ 0x140097440 ----
    if ((r14 as u32) == t_140097433) {
        /* -> bb2895 */
    } else {
        /* -> bb2894 */
    }

    // ---- bb2894 @ 0x140097443 ----
    if ((r14 as u32) == t_140097433) {
        /* -> bb2895 */
    } else {
        /* -> bb2897 */
    }

    // ---- bb2895 @ 0x140097445 ----
    /* 140097445 */ core::ptr::write((rdi).wrapping_add(0x2e4_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb2903 */

    // ---- bb2897 @ 0x14009744e ----
    /* 14009744e */ let mut t_14009744e_0: u32 = 0x0_u32;
    /* 14009744e */ r8 = (t_14009744e_0 as u64);
    /* 140097451 */ rdx = (0x1b_u32 as u64);
    /* 140097456 */ rcx = rdi;
    /* 140097459 */ fn_1400ca650();
    /* 14009745e */ fn_14003f5e0();
    /* 140097463 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0x9_u64);
    /* fallthrough -> bb2903 */

    // ---- bb2903 @ 0x14009746e ----
    /* 14009746e */ let mut t_14009746e: u32 = core::ptr::read((rdi).wrapping_add(0xe0_u64) as *const u32);
    if (t_14009746e != 0x1b_u32) {
        /* -> bb2907 */
    } else {
        /* -> bb2906 */
    }

    // ---- bb2906 @ 0x140097475 ----
    if (t_14009746e != 0x1b_u32) {
        /* -> bb2907 */
    } else {
        /* -> bb2911 */
    }

    // ---- bb2907 @ 0x140097477 ----
    /* 140097477 */ let mut t_140097477: u8 = core::ptr::read((rdi).wrapping_add(0x2e5_u64) as *const u8);
    if (t_140097477 != 0x0_u8) {
        /* -> bb2911 */
    } else {
        /* -> bb2910 */
    }

    // ---- bb2910 @ 0x14009747e ----
    if (t_140097477 != 0x0_u8) {
        /* -> bb2911 */
    } else {
        /* -> bb2987 */
    }

    // ---- bb2911 @ 0x140097484 ----
    /* 140097484 */ let mut t_140097484_0: u32 = 0x0_u32;
    /* 140097484 */ r8 = (t_140097484_0 as u64);
    /* 140097487 */ rdx = (0x1b_u32 as u64);
    /* 14009748c */ rcx = rdi;
    /* 14009748f */ fn_1400ca650();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140097497 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 14009749c */ xmm1 = core::ptr::read((0x1400974a4_u64).wrapping_add(0x26e1dc_u64) as *const u128);
    /* 1400974a4 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u128, xmm1);
    /* 1400974aa */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, 0x72616554_u32);
    /* 1400974b2 */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u8, 0x0_u8);
    /* 1400974b7 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400974bc */ xmm3 = xmm14;
    /* 1400974c0 */ let mut t_1400974c0_0: u32 = 0x0_u32;
    /* 1400974c0 */ r8 = (t_1400974c0_0 as u64);
    /* 1400974c3 */ rdx = (0x64_u32 as u64);
    /* 1400974c8 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400974cd */ fn_140040b90();
    /* 1400974d3 */ rdx = core::ptr::read((rsp).wrapping_add(0x70_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2933 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2932 */ }

    // ---- bb2932 @ 0x1400974dc ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2933 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2949 */ }

    // ---- bb2933 @ 0x1400974de ----
    /* 1400974de */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400974e1 */ rcx = core::ptr::read((rsp).wrapping_add(0x58_u64) as *const u64);
    /* 1400974e6 */ rax = rcx;
    if (CF == false) { /* -> bb2940 */ }
    if CF { /* -> bb2939 */ }

    // ---- bb2939 @ 0x1400974f0 ----
    if (CF == false) { /* -> bb2940 */ }
    if CF { /* -> bb2948 */ }

    // ---- bb2940 @ 0x1400974f2 ----
    /* 1400974f2 */ let mut t_1400974f2_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400974f2 */ rdx = t_1400974f2_0;
    /* 1400974f6 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400974fa */ let mut t_1400974fa_0: u64 = (rax).wrapping_sub(rcx);
    /* 1400974fa */ rax = t_1400974fa_0;
    /* 1400974fd */ let mut t_1400974fd_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 1400974fd */ rax = t_1400974fd_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2948 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2947 */ }

    // ---- bb2947 @ 0x140097505 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2948 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3476 */ }

    // ---- bb2948 @ 0x14009750b ----
    /* 14009750b */ fn_1402c7498();
    /* fallthrough -> bb2949 */

    // ---- bb2949 @ 0x140097510 ----
    /* 140097510 */ let mut t_140097510: u8 = core::ptr::read((rdi).wrapping_add(0x2e4_u64) as *const u8);
    if (t_140097510 == 0x0_u8) {
        /* -> bb2953 */
    } else {
        /* -> bb2952 */
    }

    // ---- bb2952 @ 0x140097517 ----
    if (t_140097510 == 0x0_u8) {
        /* -> bb2953 */
    } else {
        /* -> bb2970 */
    }

    // ---- bb2953 @ 0x140097519 ----
    /* 140097519 */ core::ptr::write((rdi).wrapping_add(0x2e4_u64) as *mut u8, 0x1_u8);
    /* 140097520 */ fn_14003f5e0();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140097528 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 14009752d */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u128, xmm13);
    /* 140097534 */ rax = 0x6563615265736f4c_u64;
    /* 14009753e */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u64, rax);
    /* 140097543 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u8, 0x0_u8);
    /* 140097548 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 14009754d */ xmm3 = xmm14;
    /* 140097551 */ let mut t_140097551_0: u32 = 0x0_u32;
    /* 140097551 */ r8 = (t_140097551_0 as u64);
    /* 140097554 */ rdx = (0x64_u32 as u64);
    /* 140097559 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14009755e */ fn_140040b90();
    /* 140097564 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097569 */ fn_140027900();
    /* fallthrough -> bb2970 */

    // ---- bb2970 @ 0x14009756e ----
    /* 14009756e */ core::ptr::write((rdi).wrapping_add(0x2e5_u64) as *mut u8, 0x1_u8);
    /* 140097575 */ rcx = rdi;
    /* 140097578 */ fn_140094500();
    /* 14009757d */ let mut t_14009757d: u32 = core::ptr::read((rdi).wrapping_add(0x2fc_u64) as *const u32);
    if (t_14009757d == 0x0_u32) {
        /* -> bb2977 */
    } else {
        /* -> bb2976 */
    }

    // ---- bb2976 @ 0x140097584 ----
    if (t_14009757d == 0x0_u32) {
        /* -> bb2977 */
    } else {
        /* -> bb2985 */
    }

    // ---- bb2977 @ 0x140097586 ----
    /* 140097586 */ let mut t_140097586: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (SF != OF) {
        /* -> bb2981 */
    } else {
        /* -> bb2980 */
    }

    // ---- bb2980 @ 0x140097590 ----
    if (SF != OF) {
        /* -> bb2981 */
    } else {
        /* -> bb2983 */
    }

    // ---- bb2981 @ 0x140097592 ----
    /* 140097592 */ core::ptr::write((rdi).wrapping_add(0x2f0_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb2985 */

    // ---- bb2983 @ 0x14009759b ----
    /* 14009759b */ rcx = rdi;
    /* 14009759e */ fn_140092470();
    /* fallthrough -> bb2985 */

    // ---- bb2985 @ 0x1400975a3 ----
    /* 1400975a3 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u32, 0xb_u32);
    /* 1400975ad */ core::ptr::write((rdi).wrapping_add(0x254_u64) as *mut u32, 0xffffffc4_u32);
    /* fallthrough -> bb2987 */

    // ---- bb2987 @ 0x1400975b7 ----
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x26be0d]
    /* fallthrough -> bb2988 */

    // ---- bb2988 @ 0x1400975bf ----
    /* 1400975bf */ let mut t_1400975bf: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 1400975bf */ rax = (t_1400975bf as u64);
    if ((rax as u32) != 0x8_u32) {
        /* -> bb2993 */
    } else {
        /* -> bb2992 */
    }

    // ---- bb2992 @ 0x1400975c8 ----
    if ((rax as u32) != 0x8_u32) {
        /* -> bb2993 */
    } else {
        /* -> bb2997 */
    }

    // ---- bb2993 @ 0x1400975ca ----
    if ((rax as u32) == 0x9_u32) {
        /* -> bb2997 */
    } else {
        /* -> bb2996 */
    }

    // ---- bb2996 @ 0x1400975cd ----
    if ((rax as u32) == 0x9_u32) {
        /* -> bb2997 */
    } else {
        /* -> bb3455 */
    }

    // ---- bb2997 @ 0x1400975d3 ----
    // intrinsic: f30f1087 movss xmm0, dword ptr [rdi + 0x118]
    // intrinsic: f3440f5c subss xmm15, xmm0
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x26bdb0]
    // intrinsic: f3440f58 addss xmm15, xmm2
    /* 1400975ed */ let mut t_1400975ed: u8 = core::ptr::read((0x1400975f4_u64).wrapping_add(0x3560ac_u64) as *const u8);
    if (t_1400975ed == 0x0_u8) {
        /* -> bb3005 */
    } else {
        /* -> bb3004 */
    }

    // ---- bb3004 @ 0x1400975f4 ----
    if (t_1400975ed == 0x0_u8) {
        /* -> bb3005 */
    } else {
        /* -> bb3400 */
    }

    // ---- bb3005 @ 0x1400975fa ----
    /* 1400975fa */ let mut t_1400975fa: u8 = core::ptr::read((0x140097601_u64).wrapping_add(0x356053_u64) as *const u8);
    if (t_1400975fa == 0x0_u8) {
        /* -> bb3009 */
    } else {
        /* -> bb3008 */
    }

    // ---- bb3008 @ 0x140097601 ----
    if (t_1400975fa == 0x0_u8) {
        /* -> bb3009 */
    } else {
        /* -> bb3400 */
    }

    // ---- bb3009 @ 0x140097607 ----
    /* 140097607 */ let mut t_140097607: u8 = core::ptr::read((0x14009760e_u64).wrapping_add(0x356091_u64) as *const u8);
    if (t_140097607 == 0x0_u8) {
        /* -> bb3013 */
    } else {
        /* -> bb3012 */
    }

    // ---- bb3012 @ 0x14009760e ----
    if (t_140097607 == 0x0_u8) {
        /* -> bb3013 */
    } else {
        /* -> bb3017 */
    }

    // ---- bb3013 @ 0x140097610 ----
    /* 140097610 */ let mut t_140097610: u8 = core::ptr::read((0x140097617_u64).wrapping_add(0x356040_u64) as *const u8);
    if (t_140097610 != 0x0_u8) {
        /* -> bb3017 */
    } else {
        /* -> bb3016 */
    }

    // ---- bb3016 @ 0x140097617 ----
    if (t_140097610 != 0x0_u8) {
        /* -> bb3017 */
    } else {
        /* -> bb3405 */
    }

    // ---- bb3017 @ 0x14009761d ----
    // intrinsic: f30f108f movss xmm1, dword ptr [rdi + 0x2f8]
    // intrinsic: f30f5cc8 subss xmm1, xmm0
    // intrinsic: f30f58ca addss xmm1, xmm2
    // intrinsic: f30f1087 movss xmm0, dword ptr [rdi + 0x10c]
    // intrinsic: f30f58c7 addss xmm0, xmm7
    // intrinsic: f30f5dc8 minss xmm1, xmm0
    // intrinsic: f30f118f movss dword ptr [rdi + 0x10c], xmm1
    /* 140097645 */ xmm0 = xmm15;
    // intrinsic: f3410f5c subss xmm0, xmm14
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    /* 140097651 */ rax = ((rax & 0xffffffffffffff00_u64) | ((((CF == false) & (ZF == false)) as u8) as u64));
    /* 140097654 */ core::ptr::write((rdi).wrapping_add(0x2b1_u64) as *mut u8, (rax as u8));
    /* fallthrough -> bb3405 */

    // ---- bb3030 @ 0x14009765f ----
    if ((rax as u32) == 0x9_u32) {
        /* -> bb3034 */
    } else {
        /* -> bb3033 */
    }

    // ---- bb3033 @ 0x140097662 ----
    if ((rax as u32) == 0x9_u32) {
        /* -> bb3034 */
    } else {
        /* -> bb3182 */
    }

    // ---- bb3034 @ 0x140097668 ----
    // intrinsic: f3440f10 movss xmm15, dword ptr [rdi + 0x2f8]
    /* 140097671 */ let mut t_140097671: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140097671 */ rax = (t_140097671 as u64);
    if ((rax as u32) == 0x1_u32) {
        /* -> bb3040 */
    } else {
        /* -> bb3039 */
    }

    // ---- bb3039 @ 0x14009767a ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb3040 */
    } else {
        /* -> bb3042 */
    }

    // ---- bb3040 @ 0x14009767c ----
    /* 14009767c */ core::ptr::write((rdi).wrapping_add(0x2b1_u64) as *mut u8, 0x0_u8);
    /* fallthrough -> bb3066 */

    // ---- bb3042 @ 0x140097685 ----
    if ((rax as u32) == 0x1e_u32) {
        /* -> bb3046 */
    } else {
        /* -> bb3045 */
    }

    // ---- bb3045 @ 0x140097688 ----
    if ((rax as u32) == 0x1e_u32) {
        /* -> bb3046 */
    } else {
        /* -> bb3066 */
    }

    // ---- bb3046 @ 0x14009768a ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14009768d */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140097692 */ xmm1 = core::ptr::read((0x14009769a_u64).wrapping_add(0x26bd46_u64) as *const u128);
    /* 14009769a */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u128, xmm1);
    /* 1400976a0 */ rax = core::ptr::read((0x1400976a7_u64).wrapping_add(0x26bc19_u64) as *const u64);
    /* 1400976a7 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, (rax as u32));
    /* 1400976ab */ let mut t_1400976ab: u16 = core::ptr::read((0x1400976b2_u64).wrapping_add(0x26bc12_u64) as *const u16);
    /* 1400976ab */ rax = ((t_1400976ab as u32) as u64);
    /* 1400976b2 */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u16, (rax as u16));
    /* 1400976b7 */ let mut t_1400976b7: u8 = core::ptr::read((0x1400976be_u64).wrapping_add(0x26bc08_u64) as *const u8);
    /* 1400976b7 */ rax = ((t_1400976b7 as u32) as u64);
    /* 1400976be */ core::ptr::write((rsp).wrapping_add(0x5e_u64) as *mut u8, (rax as u8));
    /* 1400976c2 */ core::ptr::write((rsp).wrapping_add(0x5f_u64) as *mut u8, 0x0_u8);
    /* 1400976c7 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400976cc */ xmm3 = xmm14;
    /* 1400976d0 */ let mut t_1400976d0_0: u32 = 0x0_u32;
    /* 1400976d0 */ r8 = (t_1400976d0_0 as u64);
    /* 1400976d3 */ rdx = (0x64_u32 as u64);
    /* 1400976d8 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400976dd */ fn_140040b90();
    /* 1400976e3 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400976e8 */ fn_140027900();
    /* fallthrough -> bb3066 */

    // ---- bb3066 @ 0x1400976ed ----
    /* 1400976ed */ let mut t_1400976ed: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 1400976ed */ rax = (t_1400976ed as u64);
    if ((rax as u32) == 0x78_u32) {
        /* -> bb3071 */
    } else {
        /* -> bb3070 */
    }

    // ---- bb3070 @ 0x1400976f6 ----
    if ((rax as u32) == 0x78_u32) {
        /* -> bb3071 */
    } else {
        /* -> bb3088 */
    }

    // ---- bb3071 @ 0x1400976f8 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400976fb */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 140097700 */ xmm1 = core::ptr::read((0x140097708_u64).wrapping_add(0x26c988_u64) as *const u128);
    /* 140097708 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u128, xmm1);
    /* 14009770e */ rax = 0x676e697070616c43_u64;
    /* 140097718 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u64, rax);
    /* 14009771d */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u8, 0x0_u8);
    /* 140097722 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140097727 */ xmm3 = xmm14;
    /* 14009772b */ let mut t_14009772b_0: u32 = 0x0_u32;
    /* 14009772b */ r8 = (t_14009772b_0 as u64);
    /* 14009772e */ rdx = (0x64_u32 as u64);
    /* 140097733 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097738 */ fn_140040b90();
    /* 14009773e */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097743 */ fn_140027900();
    /* 140097748 */ let mut t_140097748: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140097748 */ rax = (t_140097748 as u64);
    /* fallthrough -> bb3088 */

    // ---- bb3088 @ 0x14009774e ----
    /* 14009774e */ rcx = ((rax as u32) as u64);
    /* 140097750 */ let mut t_140097750: u32 = core::ptr::read((0x140097757_u64).wrapping_add(0x356211_u64) as *const u32);
    if (t_140097750 != 0x0_u32) {
        /* -> bb3093 */
    } else {
        /* -> bb3092 */
    }

    // ---- bb3092 @ 0x140097757 ----
    if (t_140097750 != 0x0_u32) {
        /* -> bb3093 */
    } else {
        /* -> bb3103 */
    }

    // ---- bb3093 @ 0x140097759 ----
    if (SF == OF) {
        /* -> bb3097 */
    } else {
        /* -> bb3096 */
    }

    // ---- bb3096 @ 0x14009775c ----
    if (SF == OF) {
        /* -> bb3097 */
    } else {
        /* -> bb3103 */
    }

    // ---- bb3097 @ 0x14009775e ----
    if (SF != OF) {
        /* -> bb3101 */
    } else {
        /* -> bb3100 */
    }

    // ---- bb3100 @ 0x140097763 ----
    if (SF != OF) {
        /* -> bb3101 */
    } else {
        /* -> bb3103 */
    }

    // ---- bb3101 @ 0x140097765 ----
    /* 140097765 */ core::ptr::write((rdi).wrapping_add(0x254_u64) as *mut u32, 0x258_u32);
    /* fallthrough -> bb3176 */

    // ---- bb3103 @ 0x140097774 ----
    if ((rcx as u32) == 0x267_u32) {
        /* -> bb3107 */
    } else {
        /* -> bb3106 */
    }

    // ---- bb3106 @ 0x14009777a ----
    if ((rcx as u32) == 0x267_u32) {
        /* -> bb3107 */
    } else {
        /* -> bb3176 */
    }

    // ---- bb3107 @ 0x140097780 ----
    /* 140097780 */ let mut t_140097780_0: u32 = 0x0_u32;
    /* 140097780 */ r8 = (t_140097780_0 as u64);
    /* 140097783 */ let mut t_140097783: u32 = core::ptr::read((rdi).wrapping_add(0x2e0_u64) as *const u32);
    /* 140097783 */ rdx = (t_140097783 as u64);
    /* 140097789 */ rcx = core::ptr::read((0x140097790_u64).wrapping_add(0x363a58_u64) as *const u64);
    /* 140097790 */ fn_140104f20();
    /* 140097795 */ let mut t_140097795: u8 = core::ptr::read((rdi).wrapping_add(0x2a5_u64) as *const u8);
    if (t_140097795 != 0x0_u8) {
        /* -> bb3115 */
    } else {
        /* -> bb3114 */
    }

    // ---- bb3114 @ 0x14009779c ----
    if (t_140097795 != 0x0_u8) {
        /* -> bb3115 */
    } else {
        /* -> bb3133 */
    }

    // ---- bb3115 @ 0x14009779e ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400977a1 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 1400977a6 */ xmm1 = core::ptr::read((0x1400977ae_u64).wrapping_add(0x26ded2_u64) as *const u128);
    /* 1400977ae */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u128, xmm1);
    /* 1400977b4 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, 0x65636172_u32);
    /* 1400977bc */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u8, 0x0_u8);
    /* 1400977c1 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400977c6 */ fn_140037710();
    /* 1400977cc */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400977d1 */ fn_140027900();
    /* 1400977d6 */ let mut t_1400977d6: u32 = core::ptr::read((rdi).wrapping_add(0x2a8_u64) as *const u32);
    /* 1400977d6 */ rdx = ((t_1400977d6 as i64) as u64);
    /* 1400977dd */ let mut t_1400977dd_0: u64 = (rdx).wrapping_add(rdx);
    /* 1400977dd */ rdx = t_1400977dd_0;
    /* 1400977e0 */ rax = core::ptr::read((rdi).wrapping_add(0x278_u64) as *const u64);
    /* 1400977e7 */ rcx = core::ptr::read((rax).wrapping_add(0x298_u64) as *const u64);
    /* 1400977ee */ core::ptr::write(((rcx).wrapping_add((rdx).wrapping_mul(0x8_u64))).wrapping_add(0xa_u64) as *mut u8, 0x1_u8);
    /* 1400977f3 */ let mut t_1400977f3: u32 = core::ptr::read((rdi).wrapping_add(0x3e0_u64) as *const u32);
    /* 1400977f3 */ core::ptr::write((rdi).wrapping_add(0x3e0_u64) as *mut u32, (t_1400977f3).wrapping_add(0x1_u32));
    /* fallthrough -> bb3169 */

    // ---- bb3133 @ 0x1400977fe ----
    /* 1400977fe */ rdx = (0x140097805_u64).wrapping_add(0x26ca6f_u64);
    /* 140097805 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14009780a */ fn_140027980();
    /* 140097810 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097815 */ fn_140037710();
    /* 14009781b */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097820 */ fn_140027900();
    /* 140097825 */ let mut t_140097825: u32 = core::ptr::read((rdi).wrapping_add(0x2bc_u64) as *const u32);
    if (t_140097825 == 0x3_u32) {
        /* -> bb3146 */
    } else {
        /* -> bb3145 */
    }

    // ---- bb3145 @ 0x14009782c ----
    if (t_140097825 == 0x3_u32) {
        /* -> bb3146 */
    } else {
        /* -> bb3155 */
    }

    // ---- bb3146 @ 0x14009782e ----
    /* 14009782e */ rdx = (0x140097835_u64).wrapping_add(0x26cccf_u64);
    /* 140097835 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14009783a */ fn_140027980();
    /* 140097840 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097845 */ fn_140037710();
    /* 14009784b */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097850 */ fn_140027900();
    /* fallthrough -> bb3155 */

    // ---- bb3155 @ 0x140097855 ----
    /* 140097855 */ let mut t_140097855: u32 = core::ptr::read((rdi).wrapping_add(0x2e0_u64) as *const u32);
    if (SF == OF) {
        /* -> bb3159 */
    } else {
        /* -> bb3158 */
    }

    // ---- bb3158 @ 0x14009785f ----
    if (SF == OF) {
        /* -> bb3159 */
    } else {
        /* -> bb3168 */
    }

    // ---- bb3159 @ 0x140097861 ----
    /* 140097861 */ rdx = (0x140097868_u64).wrapping_add(0x26cc38_u64);
    /* 140097868 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14009786d */ fn_140027980();
    /* 140097873 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097878 */ fn_140037710();
    /* 14009787e */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097883 */ fn_140027900();
    /* fallthrough -> bb3168 */

    // ---- bb3168 @ 0x140097888 ----
    /* 140097888 */ core::ptr::write((rdi).wrapping_add(0x264_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb3169 */

    // ---- bb3169 @ 0x14009788f ----
    /* 14009788f */ let mut t_14009788f: u32 = core::ptr::read((rdi).wrapping_add(0x2e0_u64) as *const u32);
    /* 14009788f */ rax = (t_14009788f as u64);
    /* 140097895 */ let mut t_140097895: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    /* 140097895 */ let mut t_140097895_0: u32 = (t_140097895).wrapping_add((rax as u32));
    /* 140097895 */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, t_140097895_0);
    /* 14009789b */ rdx = core::ptr::read((0x1400978a2_u64).wrapping_add(0x363946_u64) as *const u64);
    /* 1400978a2 */ let mut t_1400978a2: u32 = core::ptr::read((rdx).wrapping_add(0x308_u64) as *const u32);
    /* 1400978a2 */ rdx = (t_1400978a2 as u64);
    /* 1400978a8 */ let mut t_1400978a8: u32 = core::ptr::read((rdi).wrapping_add(0x260_u64) as *const u32);
    /* 1400978a8 */ rcx = (t_1400978a8 as u64);
    /* 1400978ae */ fn_1400c6040();
    /* 1400978b3 */ core::ptr::write((rdi).wrapping_add(0x260_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb3176 */

    // ---- bb3176 @ 0x1400978b9 ----
    /* 1400978b9 */ let mut t_1400978b9: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_1400978b9 == 0x294_u32) {
        /* -> bb3180 */
    } else {
        /* -> bb3179 */
    }

    // ---- bb3179 @ 0x1400978c3 ----
    if (t_1400978b9 != 0x294_u32) {
        /* -> bb2988 */
    } else {
        /* -> bb3180 */
    }

    // ---- bb3180 @ 0x1400978c9 ----
    /* 1400978c9 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0xb_u64);
    /* fallthrough -> bb2988 */

    // ---- bb3182 @ 0x1400978d9 ----
    if ((rax as u32) == 0xa_u32) {
        /* -> bb3186 */
    } else {
        /* -> bb3185 */
    }

    // ---- bb3185 @ 0x1400978dc ----
    if ((rax as u32) == 0xa_u32) {
        /* -> bb3186 */
    } else {
        /* -> bb3229 */
    }

    // ---- bb3186 @ 0x1400978e2 ----
    /* 1400978e2 */ let mut t_1400978e2: u8 = core::ptr::read((rdi).wrapping_add(0x259_u64) as *const u8);
    if (t_1400978e2 != 0x0_u8) {
        /* -> bb3190 */
    } else {
        /* -> bb3189 */
    }

    // ---- bb3189 @ 0x1400978e9 ----
    if (t_1400978e2 != 0x0_u8) {
        /* -> bb3190 */
    } else {
        /* -> bb3207 */
    }

    // ---- bb3190 @ 0x1400978eb ----
    /* 1400978eb */ let mut t_1400978eb: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_1400978eb == 0x78_u32) {
        /* -> bb3194 */
    } else {
        /* -> bb3193 */
    }

    // ---- bb3193 @ 0x1400978f2 ----
    if (t_1400978eb == 0x78_u32) {
        /* -> bb3194 */
    } else {
        /* -> bb3207 */
    }

    // ---- bb3194 @ 0x1400978f4 ----
    /* 1400978f4 */ rdx = (0x1400978fb_u64).wrapping_add(0x2748b5_u64);
    /* 1400978fb */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097900 */ fn_140027980();
    /* 140097906 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 14009790b */ xmm3 = xmm14;
    /* 14009790f */ let mut t_14009790f_0: u32 = 0x0_u32;
    /* 14009790f */ r8 = (t_14009790f_0 as u64);
    /* 140097912 */ rdx = (0x64_u32 as u64);
    /* 140097917 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14009791c */ fn_140040b90();
    /* 140097922 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097927 */ fn_140027900();
    /* fallthrough -> bb3207 */

    // ---- bb3207 @ 0x14009792c ----
    /* 14009792c */ let mut t_14009792c: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_14009792c != 0x0_u8) {
        /* -> bb3211 */
    } else {
        /* -> bb3210 */
    }

    // ---- bb3210 @ 0x140097933 ----
    if (t_14009792c != 0x0_u8) {
        /* -> bb3211 */
    } else {
        /* -> bb3215 */
    }

    // ---- bb3211 @ 0x140097935 ----
    /* 140097935 */ let mut t_140097935: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140097935 != 0xf0_u32) {
        /* -> bb3215 */
    } else {
        /* -> bb3214 */
    }

    // ---- bb3214 @ 0x14009793f ----
    if (t_140097935 != 0xf0_u32) {
        /* -> bb3215 */
    } else {
        /* -> bb3227 */
    }

    // ---- bb3215 @ 0x140097941 ----
    /* 140097941 */ let mut t_140097941: u8 = core::ptr::read((rdi).wrapping_add(0x259_u64) as *const u8);
    if (t_140097941 != 0x0_u8) {
        /* -> bb3219 */
    } else {
        /* -> bb3218 */
    }

    // ---- bb3218 @ 0x140097948 ----
    if (t_140097941 == 0x0_u8) {
        /* -> bb2988 */
    } else {
        /* -> bb3219 */
    }

    // ---- bb3219 @ 0x14009794e ----
    /* 14009794e */ let mut t_14009794e: u8 = core::ptr::read((0x140097955_u64).wrapping_add(0x355c1b_u64) as *const u8);
    if (t_14009794e == 0x0_u8) {
        /* -> bb3223 */
    } else {
        /* -> bb3222 */
    }

    // ---- bb3222 @ 0x140097955 ----
    if (t_14009794e == 0x0_u8) {
        /* -> bb3223 */
    } else {
        /* -> bb3227 */
    }

    // ---- bb3223 @ 0x140097957 ----
    /* 140097957 */ let mut t_140097957: u32 = core::ptr::read((0x14009795e_u64).wrapping_add(0x35600a_u64) as *const u32);
    if (t_140097957 != 0x0_u32) {
        /* -> bb3227 */
    } else {
        /* -> bb3226 */
    }

    // ---- bb3226 @ 0x14009795e ----
    if (t_140097957 == 0x0_u32) {
        /* -> bb2988 */
    } else {
        /* -> bb3227 */
    }

    // ---- bb3227 @ 0x140097964 ----
    /* 140097964 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0xb_u64);
    /* fallthrough -> bb2988 */

    // ---- bb3229 @ 0x140097974 ----
    /* 140097974 */ let mut t_140097974: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 140097974 */ rax = (t_140097974 as u64);
    if ((rax as u32) == 0xb_u32) {
        /* -> bb3234 */
    } else {
        /* -> bb3233 */
    }

    // ---- bb3233 @ 0x14009797d ----
    if ((rax as u32) == 0xb_u32) {
        /* -> bb3234 */
    } else {
        /* -> bb3369 */
    }

    // ---- bb3234 @ 0x140097983 ----
    /* 140097983 */ let mut t_140097983: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140097983 == 0x1_u32) {
        /* -> bb3238 */
    } else {
        /* -> bb3237 */
    }

    // ---- bb3237 @ 0x14009798a ----
    if (t_140097983 == 0x1_u32) {
        /* -> bb3238 */
    } else {
        /* -> bb3251 */
    }

    // ---- bb3238 @ 0x14009798c ----
    /* 14009798c */ rdx = (0x140097993_u64).wrapping_add(0x26ff29_u64);
    /* 140097993 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097998 */ fn_140027980();
    /* 14009799e */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400979a3 */ xmm3 = xmm14;
    /* 1400979a7 */ let mut t_1400979a7_0: u32 = 0x0_u32;
    /* 1400979a7 */ r8 = (t_1400979a7_0 as u64);
    /* 1400979aa */ rdx = (0x32_u32 as u64);
    /* 1400979af */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400979b4 */ fn_140040b90();
    /* 1400979ba */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 1400979bf */ fn_140027900();
    /* fallthrough -> bb3251 */

    // ---- bb3251 @ 0x1400979c4 ----
    /* 1400979c4 */ let mut t_1400979c4: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_1400979c4 == 0x10_u32) {
        /* -> bb3255 */
    } else {
        /* -> bb3254 */
    }

    // ---- bb3254 @ 0x1400979cb ----
    if (t_1400979c4 != 0x10_u32) {
        /* -> bb2988 */
    } else {
        /* -> bb3255 */
    }

    // ---- bb3255 @ 0x1400979d1 ----
    /* 1400979d1 */ let mut t_1400979d1: u8 = core::ptr::read((rdi).wrapping_add(0x2f0_u64) as *const u8);
    if (t_1400979d1 == 0x0_u8) {
        /* -> bb3259 */
    } else {
        /* -> bb3258 */
    }

    // ---- bb3258 @ 0x1400979d8 ----
    if (t_1400979d1 == 0x0_u8) {
        /* -> bb3259 */
    } else {
        /* -> bb3263 */
    }

    // ---- bb3259 @ 0x1400979da ----
    /* 1400979da */ rcx = rdi;
    /* 1400979dd */ fn_140092110();
    /* 1400979e2 */ r14 = (rdi).wrapping_add(0x2a5_u64);
    /* fallthrough -> bb3272 */

    // ---- bb3263 @ 0x1400979eb ----
    /* 1400979eb */ r14 = (rdi).wrapping_add(0x2a5_u64);
    /* 1400979f2 */ let mut t_1400979f2: u8 = core::ptr::read(r14 as *const u8);
    if (t_1400979f2 != 0x0_u8) {
        /* -> bb3268 */
    } else {
        /* -> bb3267 */
    }

    // ---- bb3267 @ 0x1400979f6 ----
    if (t_1400979f2 != 0x0_u8) {
        /* -> bb3268 */
    } else {
        /* -> bb3272 */
    }

    // ---- bb3268 @ 0x1400979f8 ----
    /* 1400979f8 */ let mut t_1400979f8: u32 = core::ptr::read((rdi).wrapping_add(0x2ac_u64) as *const u32);
    /* 1400979f8 */ rax = ((t_1400979f8 as i64) as u64);
    /* 1400979ff */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140097a06 */ rcx = core::ptr::read((rcx).wrapping_add((rax).wrapping_mul(0x8_u64)) as *const u64);
    /* 140097a0a */ fn_1400b9210();
    /* fallthrough -> bb3272 */

    // ---- bb3272 @ 0x140097a0f ----
    /* 140097a0f */ let mut t_140097a0f: u32 = core::ptr::read((rdi).wrapping_add(0x2a8_u64) as *const u32);
    /* 140097a0f */ rax = (t_140097a0f as u64);
    /* 140097a15 */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* 140097a17 */ r15 = (((rax as u32) as i64) as u64);
    /* 140097a1a */ rax = core::ptr::read((rdi).wrapping_add(0x278_u64) as *const u64);
    /* 140097a21 */ rbx = core::ptr::read((rax).wrapping_add(0x2a0_u64) as *const u64);
    /* 140097a28 */ let mut t_140097a28: u64 = core::ptr::read((rax).wrapping_add(0x298_u64) as *const u64);
    /* 140097a28 */ let mut t_140097a28_0: u64 = (rbx).wrapping_sub(t_140097a28);
    /* 140097a28 */ rbx = t_140097a28_0;
    /* 140097a2f */ rbx = (((rbx as i64) >> ((0x4_u8 as u64) as i64)) as u64);
    /* 140097a33 */ rcx = rdi;
    /* 140097a36 */ fn_140092340();
    /* 140097a3b */ rax = core::ptr::read((0x140097a42_u64).wrapping_add(0x3637a6_u64) as *const u64);
    /* 140097a42 */ let mut t_140097a42: u32 = core::ptr::read((rax).wrapping_add(0x308_u64) as *const u32);
    if (t_140097a42 == 0x0_u32) {
        /* -> bb3286 */
    } else {
        /* -> bb3285 */
    }

    // ---- bb3285 @ 0x140097a49 ----
    if (t_140097a42 == 0x0_u32) {
        /* -> bb3286 */
    } else {
        /* -> bb3321 */
    }

    // ---- bb3286 @ 0x140097a4b ----
    /* 140097a4b */ let mut t_140097a4b: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_140097a4b == 0x0_u8) {
        /* -> bb3290 */
    } else {
        /* -> bb3289 */
    }

    // ---- bb3289 @ 0x140097a52 ----
    if (t_140097a4b == 0x0_u8) {
        /* -> bb3290 */
    } else {
        /* -> bb3321 */
    }

    // ---- bb3290 @ 0x140097a54 ----
    /* 140097a54 */ let mut t_140097a54: u8 = core::ptr::read((rdi).wrapping_add(0x259_u64) as *const u8);
    if (t_140097a54 == 0x0_u8) {
        /* -> bb3294 */
    } else {
        /* -> bb3293 */
    }

    // ---- bb3293 @ 0x140097a5b ----
    if (t_140097a54 == 0x0_u8) {
        /* -> bb3294 */
    } else {
        /* -> bb3321 */
    }

    // ---- bb3294 @ 0x140097a5d ----
    /* 140097a5d */ let mut t_140097a5d: u64 = core::ptr::read((rdi).wrapping_add(0x278_u64) as *const u64);
    if (t_140097a5d != 0x0_u64) {
        /* -> bb3298 */
    } else {
        /* -> bb3297 */
    }

    // ---- bb3297 @ 0x140097a65 ----
    if (t_140097a5d != 0x0_u64) {
        /* -> bb3298 */
    } else {
        /* -> bb3321 */
    }

    // ---- bb3298 @ 0x140097a67 ----
    if (CF == false) { /* -> bb3302 */ }
    if CF { /* -> bb3301 */ }

    // ---- bb3301 @ 0x140097a6a ----
    if (CF == false) { /* -> bb3302 */ }
    if CF { /* -> bb3321 */ }

    // ---- bb3302 @ 0x140097a6c ----
    /* 140097a6c */ let mut t_140097a6c: u32 = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u32);
    /* 140097a6c */ rax = (t_140097a6c as u64);
    if (((SF != OF) | (r15 == rbx)) == false) { /* -> bb3307 */ }
    if (((SF != OF) | (r15 == rbx)) != 0) { /* -> bb3306 */ }

    // ---- bb3306 @ 0x140097a74 ----
    if (((SF != OF) | (r15 == rbx)) == false) { /* -> bb3307 */ }
    if (((SF != OF) | (r15 == rbx)) != 0) { /* -> bb3317 */ }

    // ---- bb3307 @ 0x140097a76 ----
    /* 140097a79 */ rsi = ((rsi & 0xffffffffffffff00_u64) | (((ZF == false) as u8) as u64));
    /* 140097a7d */ rax = ((rsi as u32) as u64);
    /* 140097a7f */ core::ptr::write((rdi).wrapping_add(0x268_u64) as *mut u32, (rax as u32));
    /* 140097a85 */ rcx = (rax).wrapping_add((rax).wrapping_mul(0x2_u64));
    /* 140097a89 */ r8 = (0x140097a90_u64).wrapping_add(0x2740b8_u64);
    /* 140097a90 */ let mut t_140097a90: u32 = core::ptr::read(((r8).wrapping_add((rcx).wrapping_mul(0x4_u64))).wrapping_add(0x8_u64) as *const u32);
    /* 140097a90 */ rax = (t_140097a90 as u64);
    /* 140097a95 */ core::ptr::write((rdi).wrapping_add(0x2c4_u64) as *mut u32, (rax as u32));
    /* 140097a9b */ let mut t_140097a9b: u32 = core::ptr::read(((r8).wrapping_add((rcx).wrapping_mul(0x4_u64))).wrapping_add(0x4_u64) as *const u32);
    /* 140097a9b */ rax = (t_140097a9b as u64);
    /* 140097aa0 */ core::ptr::write((rdi).wrapping_add(0x2c8_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb3317 */

    // ---- bb3317 @ 0x140097aa6 ----
    /* 140097aa6 */ rdx = ((r12 as u32) as u64);
    /* 140097aa9 */ rcx = rdi;
    /* 140097aac */ fn_14008ff20();
    /* fallthrough -> bb2988 */

    // ---- bb3321 @ 0x140097ab6 ----
    /* 140097ab6 */ let mut t_140097ab6: u8 = core::ptr::read(r14 as *const u8);
    if (t_140097ab6 != 0x0_u8) {
        /* -> bb3325 */
    } else {
        /* -> bb3324 */
    }

    // ---- bb3324 @ 0x140097aba ----
    if (t_140097ab6 != 0x0_u8) {
        /* -> bb3325 */
    } else {
        /* -> bb3353 */
    }

    // ---- bb3325 @ 0x140097abc ----
    /* 140097abc */ rcx = core::ptr::read((rdi).wrapping_add(0x278_u64) as *const u64);
    if (t_140097ab6 != 0x0_u8) {
        /* -> bb3330 */
    } else {
        /* -> bb3329 */
    }

    // ---- bb3329 @ 0x140097ac6 ----
    if (t_140097ab6 != 0x0_u8) {
        /* -> bb3330 */
    } else {
        /* -> bb3353 */
    }

    // ---- bb3330 @ 0x140097ac8 ----
    if (CF == false) { /* -> bb3334 */ }
    if CF { /* -> bb3333 */ }

    // ---- bb3333 @ 0x140097acb ----
    if (CF == false) { /* -> bb3334 */ }
    if CF { /* -> bb3353 */ }

    // ---- bb3334 @ 0x140097acd ----
    /* 140097acd */ let mut t_140097acd: u32 = core::ptr::read((rdi).wrapping_add(0x2a8_u64) as *const u32);
    /* 140097acd */ rax = ((t_140097acd as i64) as u64);
    /* 140097ad4 */ let mut t_140097ad4_0: u64 = (rax).wrapping_add(rax);
    /* 140097ad4 */ rax = t_140097ad4_0;
    /* 140097ad7 */ rcx = core::ptr::read((rcx).wrapping_add(0x298_u64) as *const u64);
    /* 140097ade */ let mut t_140097ade: u8 = core::ptr::read(((rcx).wrapping_add((rax).wrapping_mul(0x8_u64))).wrapping_add(0xa_u64) as *const u8);
    if (t_140097ade != 0x0_u8) {
        /* -> bb3341 */
    } else {
        /* -> bb3340 */
    }

    // ---- bb3340 @ 0x140097ae3 ----
    if (t_140097ade != 0x0_u8) {
        /* -> bb3341 */
    } else {
        /* -> bb3353 */
    }

    // ---- bb3341 @ 0x140097ae5 ----
    /* 140097ae5 */ let mut t_140097ae5: u8 = core::ptr::read(((rcx).wrapping_add((rax).wrapping_mul(0x8_u64))).wrapping_add(0x9_u64) as *const u8);
    if (t_140097ae5 == 0x0_u8) {
        /* -> bb3345 */
    } else {
        /* -> bb3344 */
    }

    // ---- bb3344 @ 0x140097aea ----
    if (t_140097ae5 == 0x0_u8) {
        /* -> bb3345 */
    } else {
        /* -> bb3349 */
    }

    // ---- bb3345 @ 0x140097aec ----
    /* 140097aec */ let mut t_140097aec: u32 = core::ptr::read((rdi).wrapping_add(0x3e0_u64) as *const u32);
    if (t_140097aec == 0x1_u32) {
        /* -> bb3349 */
    } else {
        /* -> bb3348 */
    }

    // ---- bb3348 @ 0x140097af3 ----
    if (t_140097aec == 0x1_u32) {
        /* -> bb3349 */
    } else {
        /* -> bb3353 */
    }

    // ---- bb3349 @ 0x140097af5 ----
    /* 140097af5 */ rdx = (0x1_u32 as u64);
    /* 140097afa */ rcx = rdi;
    /* 140097afd */ fn_14008ff20();
    /* fallthrough -> bb2988 */

    // ---- bb3353 @ 0x140097b07 ----
    /* 140097b07 */ rdx = (0x140097b0e_u64).wrapping_add(0x2746b2_u64);
    /* 140097b0e */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097b13 */ fn_140027980();
    /* 140097b19 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140097b1e */ xmm3 = xmm14;
    /* 140097b22 */ let mut t_140097b22_0: u32 = 0x0_u32;
    /* 140097b22 */ r8 = (t_140097b22_0 as u64);
    /* 140097b25 */ rdx = (0x64_u32 as u64);
    /* 140097b2a */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097b2f */ fn_140040b90();
    /* 140097b35 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097b3a */ fn_140027900();
    /* 140097b3f */ rcx = rdi;
    /* 140097b42 */ fn_14008ff80();
    /* fallthrough -> bb2988 */

    // ---- bb3369 @ 0x140097b4c ----
    if ((rax as u32) == 0xc_u32) {
        /* -> bb3373 */
    } else {
        /* -> bb3372 */
    }

    // ---- bb3372 @ 0x140097b4f ----
    if ((rax as u32) != 0xc_u32) {
        /* -> bb2988 */
    } else {
        /* -> bb3373 */
    }

    // ---- bb3373 @ 0x140097b55 ----
    /* 140097b55 */ let mut t_140097b55: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140097b55 == 0x1_u32) {
        /* -> bb3377 */
    } else {
        /* -> bb3376 */
    }

    // ---- bb3376 @ 0x140097b5c ----
    if (t_140097b55 == 0x1_u32) {
        /* -> bb3377 */
    } else {
        /* -> bb3390 */
    }

    // ---- bb3377 @ 0x140097b5e ----
    /* 140097b5e */ rdx = (0x140097b65_u64).wrapping_add(0x26fd57_u64);
    /* 140097b65 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097b6a */ fn_140027980();
    /* 140097b70 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140097b75 */ xmm3 = xmm14;
    /* 140097b79 */ let mut t_140097b79_0: u32 = 0x0_u32;
    /* 140097b79 */ r8 = (t_140097b79_0 as u64);
    /* 140097b7c */ rdx = (0x32_u32 as u64);
    /* 140097b81 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097b86 */ fn_140040b90();
    /* 140097b8c */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 140097b91 */ fn_140027900();
    /* fallthrough -> bb3390 */

    // ---- bb3390 @ 0x140097b96 ----
    /* 140097b96 */ let mut t_140097b96: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_140097b96 == 0x10_u32) {
        /* -> bb3394 */
    } else {
        /* -> bb3393 */
    }

    // ---- bb3393 @ 0x140097b9d ----
    if (t_140097b96 != 0x10_u32) {
        /* -> bb2988 */
    } else {
        /* -> bb3394 */
    }

    // ---- bb3394 @ 0x140097ba3 ----
    /* 140097ba3 */ rcx = rdi;
    /* 140097ba6 */ fn_140092340();
    /* 140097bab */ rdx = (0x1_u32 as u64);
    /* 140097bb0 */ rcx = rdi;
    /* 140097bb3 */ fn_14008ff20();
    /* fallthrough -> bb2988 */

    // ---- bb3400 @ 0x140097bbd ----
    // intrinsic: f30f1087 movss xmm0, dword ptr [rdi + 0x10c]
    // intrinsic: f30f5cc7 subss xmm0, xmm7
    // intrinsic: f30f5ff0 maxss xmm6, xmm0
    // intrinsic: f30f11b7 movss dword ptr [rdi + 0x10c], xmm6
    /* 140097bd5 */ core::ptr::write((rdi).wrapping_add(0x2b1_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb3405 */

    // ---- bb3405 @ 0x140097bdc ----
    /* 140097bdc */ let mut t_140097bdc: u8 = core::ptr::read((rdi).wrapping_add(0x2b1_u64) as *const u8);
    if (t_140097bdc == 0x0_u8) {
        /* -> bb3409 */
    } else {
        /* -> bb3408 */
    }

    // ---- bb3408 @ 0x140097be3 ----
    if (t_140097bdc == 0x0_u8) {
        /* -> bb3409 */
    } else {
        /* -> bb3455 */
    }

    // ---- bb3409 @ 0x140097be9 ----
    /* 140097be9 */ let mut t_140097be9: u32 = core::ptr::read((rdi).wrapping_add(0x2fc_u64) as *const u32);
    if (((SF != OF) | (t_140097be9 == 0x0_u32)) == false) { /* -> bb3413 */ }
    if (((SF != OF) | (t_140097be9 == 0x0_u32)) != 0) { /* -> bb3412 */ }

    // ---- bb3412 @ 0x140097bf0 ----
    if (((SF != OF) | (t_140097be9 == 0x0_u32)) == false) { /* -> bb3413 */ }
    if (((SF != OF) | (t_140097be9 == 0x0_u32)) != 0) { /* -> bb3415 */ }

    // ---- bb3413 @ 0x140097bf2 ----
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x30509a]
    /* fallthrough -> bb3416 */

    // ---- bb3415 @ 0x140097bfc ----
    // intrinsic: 0f57d200 xorps xmm2, xmm2
    /* fallthrough -> bb3416 */

    // ---- bb3416 @ 0x140097bff ----
    // intrinsic: f30f108f movss xmm1, dword ptr [rdi + 0x10c]
    /* 140097c07 */ xmm0 = xmm15;
    // intrinsic: f30f5cc2 subss xmm0, xmm2
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if ((CF | (t_140097be9 == 0x0_u32)) == false) { /* -> bb3423 */ }
    if ((CF | (t_140097be9 == 0x0_u32)) != 0) { /* -> bb3422 */ }

    // ---- bb3422 @ 0x140097c12 ----
    if ((CF | (t_140097be9 == 0x0_u32)) == false) { /* -> bb3423 */ }
    if ((CF | (t_140097be9 == 0x0_u32)) != 0) { /* -> bb3455 */ }

    // ---- bb3423 @ 0x140097c18 ----
    /* 140097c18 */ xmm0 = xmm1;
    // intrinsic: f30f5905 mulss xmm0, dword ptr [rip + 0x305079]
    /* 140097c23 */ xmm3 = xmm15;
    // intrinsic: f30f591d mulss xmm3, dword ptr [rip + 0x26b71d]
    // intrinsic: f30f58c3 addss xmm0, xmm3
    // intrinsic: f30f5805 addss xmm0, dword ptr [rip + 0x26b70d]
    /* 140097c3b */ xmm2 = xmm15;
    /* 140097c3f */ fn_1400c6380();
    // intrinsic: f30f1187 movss dword ptr [rdi + 0x10c], xmm0
    /* fallthrough -> bb3455 */

    // ---- bb3433 @ 0x140097c4e ----
    /* 140097c4e */ let mut t_140097c4e: u32 = core::ptr::read((0x140097c54_u64).wrapping_add(0x356284_u64) as *const u32);
    /* 140097c4e */ core::ptr::write((0x140097c54_u64).wrapping_add(0x356284_u64) as *mut u32, (t_140097c4e).wrapping_sub(0x1_u32));
    /* 140097c54 */ fn_14003f5e0();
    /* 140097c59 */ let mut t_140097c59: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    if (t_140097c59 == 0x0_u32) {
        /* -> bb3439 */
    } else {
        /* -> bb3438 */
    }

    // ---- bb3438 @ 0x140097c60 ----
    if (t_140097c59 == 0x0_u32) {
        /* -> bb3439 */
    } else {
        /* -> bb3454 */
    }

    // ---- bb3439 @ 0x140097c62 ----
    /* 140097c62 */ rcx = core::ptr::read((0x140097c69_u64).wrapping_add(0x35d2a7_u64) as *const u64);
    /* 140097c69 */ fn_1400fb6a0();
    /* 140097c6e */ rax = core::ptr::read((rdi).wrapping_add(0x278_u64) as *const u64);
    /* 140097c75 */ rcx = rdi;
    if (t_140097c59 != 0x0_u32) {
        /* -> bb3447 */
    } else {
        /* -> bb3446 */
    }

    // ---- bb3446 @ 0x140097c7b ----
    if (t_140097c59 != 0x0_u32) {
        /* -> bb3447 */
    } else {
        /* -> bb3452 */
    }

    // ---- bb3447 @ 0x140097c7d ----
    /* 140097c7d */ core::ptr::write((rax).wrapping_add(0x254_u64) as *mut u32, 0x4_u32);
    /* 140097c87 */ rdx = core::ptr::read((rdi).wrapping_add(0x278_u64) as *const u64);
    /* 140097c8e */ let mut t_140097c8e: u32 = core::ptr::read((rdx).wrapping_add(0x8_u64) as *const u32);
    /* 140097c8e */ rdx = (t_140097c8e as u64);
    /* 140097c91 */ fn_1400cd970();
    /* fallthrough -> bb3455 */

    // ---- bb3452 @ 0x140097c98 ----
    /* 140097c98 */ fn_1400cdef0();
    /* fallthrough -> bb3455 */

    // ---- bb3454 @ 0x140097c9f ----
    /* 140097c9f */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u64, 0xc_u64);
    /* fallthrough -> bb3455 */

    // ---- bb3455 @ 0x140097caa ----
    /* 140097caa */ r11 = (rsp).wrapping_add(0x120_u64);
    /* 140097cb2 */ rbx = core::ptr::read((r11).wrapping_add(0x50_u64) as *const u64);
    /* 140097cb6 */ let mut xmm6: u128 = core::ptr::read((r11).wrapping_sub(0x10_u64) as *const u128);
    /* 140097cbb */ let mut xmm7: u128 = core::ptr::read((r11).wrapping_sub(0x20_u64) as *const u128);
    /* 140097cc0 */ let mut xmm8: u128 = core::ptr::read((r11).wrapping_sub(0x30_u64) as *const u128);
    /* 140097cc5 */ let mut xmm9: u128 = core::ptr::read((r11).wrapping_sub(0x40_u64) as *const u128);
    /* 140097cca */ xmm10 = core::ptr::read((r11).wrapping_sub(0x50_u64) as *const u128);
    /* 140097ccf */ xmm11 = core::ptr::read((r11).wrapping_sub(0x60_u64) as *const u128);
    /* 140097cd4 */ let mut xmm12: u128 = core::ptr::read((r11).wrapping_sub(0x70_u64) as *const u128);
    /* 140097cd9 */ xmm13 = core::ptr::read((r11).wrapping_sub(0x80_u64) as *const u128);
    /* 140097cde */ let mut xmm14: u128 = core::ptr::read((r11).wrapping_sub(0x90_u64) as *const u128);
    /* 140097ce6 */ xmm15 = core::ptr::read((r11).wrapping_sub(0xa0_u64) as *const u128);
    /* 140097cee */ rsp = r11;
    /* 140097cf1 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140097cf1 */ r15 = core::ptr::read(rsp as *const u64);
    /* 140097cf3 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140097cf3 */ r14 = core::ptr::read(rsp as *const u64);
    /* 140097cf5 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140097cf5 */ r13 = core::ptr::read(rsp as *const u64);
    /* 140097cf7 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140097cf7 */ r12 = core::ptr::read(rsp as *const u64);
    /* 140097cf9 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140097cf9 */ rdi = core::ptr::read(rsp as *const u64);
    /* 140097cfa */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140097cfa */ rsi = core::ptr::read(rsp as *const u64);
    /* 140097cfb */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140097cfb */ let mut rbp: u64 = core::ptr::read(rsp as *const u64);
    /* 140097cfc */ return;
    // <no successors>

    // ---- bb3476 @ 0x140097cfd ----
    /* 140097cfd */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, rsi);
    /* 140097d02 */ let mut t_140097d02_0: u32 = 0x0_u32;
    /* 140097d02 */ r9 = (t_140097d02_0 as u64);
    /* 140097d05 */ let mut t_140097d05_0: u32 = 0x0_u32;
    /* 140097d05 */ r8 = (t_140097d05_0 as u64);
    /* 140097d08 */ let mut t_140097d08_0: u32 = 0x0_u32;
    /* 140097d08 */ rdx = (t_140097d08_0 as u64);
    /* 140097d0a */ let mut t_140097d0a_0: u32 = 0x0_u32;
    /* 140097d0a */ rcx = (t_140097d0a_0 as u64);
    /* 140097d0c */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb3483 */

    // ---- bb3483 @ 0x140097d12 ----
    /* 140097d12 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, rsi);
    /* 140097d17 */ let mut t_140097d17_0: u32 = 0x0_u32;
    /* 140097d17 */ r9 = (t_140097d17_0 as u64);
    /* 140097d1a */ let mut t_140097d1a_0: u32 = 0x0_u32;
    /* 140097d1a */ r8 = (t_140097d1a_0 as u64);
    /* 140097d1d */ let mut t_140097d1d_0: u32 = 0x0_u32;
    /* 140097d1d */ rdx = (t_140097d1d_0 as u64);
    /* 140097d1f */ let mut t_140097d1f_0: u32 = 0x0_u32;
    /* 140097d1f */ rcx = (t_140097d1f_0 as u64);
    /* 140097d21 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb3490 */

    // ---- bb3490 @ 0x140097d27 ----
    /* 140097d27 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, rsi);
    /* 140097d2c */ let mut t_140097d2c_0: u32 = 0x0_u32;
    /* 140097d2c */ r9 = (t_140097d2c_0 as u64);
    /* 140097d2f */ let mut t_140097d2f_0: u32 = 0x0_u32;
    /* 140097d2f */ r8 = (t_140097d2f_0 as u64);
    /* 140097d32 */ let mut t_140097d32_0: u32 = 0x0_u32;
    /* 140097d32 */ rdx = (t_140097d32_0 as u64);
    /* 140097d34 */ let mut t_140097d34_0: u32 = 0x0_u32;
    /* 140097d34 */ rcx = (t_140097d34_0 as u64);
    /* 140097d36 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb3497 */

    // ---- bb3497 @ 0x140097d3c ----
    /* 140097d3c */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, rsi);
    /* 140097d41 */ let mut t_140097d41_0: u32 = 0x0_u32;
    /* 140097d41 */ r9 = (t_140097d41_0 as u64);
    /* 140097d44 */ let mut t_140097d44_0: u32 = 0x0_u32;
    /* 140097d44 */ r8 = (t_140097d44_0 as u64);
    /* 140097d47 */ let mut t_140097d47_0: u32 = 0x0_u32;
    /* 140097d47 */ rdx = (t_140097d47_0 as u64);
    /* 140097d49 */ let mut t_140097d49_0: u32 = 0x0_u32;
    /* 140097d49 */ rcx = (t_140097d49_0 as u64);
    /* 140097d4b */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb3504 */

    // ---- bb3504 @ 0x140097d51 ----
    /* 140097d51 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, rsi);
    /* 140097d56 */ let mut t_140097d56_0: u32 = 0x0_u32;
    /* 140097d56 */ r9 = (t_140097d56_0 as u64);
    /* 140097d59 */ let mut t_140097d59_0: u32 = 0x0_u32;
    /* 140097d59 */ r8 = (t_140097d59_0 as u64);
    /* 140097d5c */ let mut t_140097d5c_0: u32 = 0x0_u32;
    /* 140097d5c */ rdx = (t_140097d5c_0 as u64);
    /* 140097d5e */ let mut t_140097d5e_0: u32 = 0x0_u32;
    /* 140097d5e */ rcx = (t_140097d5e_0 as u64);
    /* 140097d60 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb3511 */

    // ---- bb3511 @ 0x140097d66 ----
    /* 140097d66 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, rsi);
    /* 140097d6b */ let mut t_140097d6b_0: u32 = 0x0_u32;
    /* 140097d6b */ r9 = (t_140097d6b_0 as u64);
    /* 140097d6e */ let mut t_140097d6e_0: u32 = 0x0_u32;
    /* 140097d6e */ r8 = (t_140097d6e_0 as u64);
    /* 140097d71 */ let mut t_140097d71_0: u32 = 0x0_u32;
    /* 140097d71 */ rdx = (t_140097d71_0 as u64);
    /* 140097d73 */ let mut t_140097d73_0: u32 = 0x0_u32;
    /* 140097d73 */ rcx = (t_140097d73_0 as u64);
    /* 140097d75 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    /* 140097d90 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140097d90 */ core::ptr::write(rsp as *mut u64, rbx);
    /* 140097d92 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140097d92 */ core::ptr::write(rsp as *mut u64, rbp);
    /* 140097d93 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140097d93 */ core::ptr::write(rsp as *mut u64, rsi);
    /* 140097d94 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140097d94 */ core::ptr::write(rsp as *mut u64, rdi);
    /* 140097d95 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140097d95 */ core::ptr::write(rsp as *mut u64, r12);
    /* 140097d97 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140097d97 */ core::ptr::write(rsp as *mut u64, r13);
    /* 140097d99 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140097d99 */ core::ptr::write(rsp as *mut u64, r14);
    /* 140097d9b */ let mut t_140097d9b_0: u64 = (rsp).wrapping_sub(0x50_u64);
    /* 140097d9b */ rsp = t_140097d9b_0;
    /* 140097d9f */ rax = core::ptr::read((rcx).wrapping_add(0x130_u64) as *const u64);
    /* 140097da6 */ rdi = rcx;
    /* 140097da9 */ r13 = (((rdx as u32) as i64) as u64);
    /* 140097dac */ let mut t_140097dac_0: u32 = 0x0_u32;
    /* 140097dac */ r9 = (t_140097dac_0 as u64);
    /* 140097daf */ let mut t_140097daf_0: u128 = ((r13 as u128)).wrapping_mul((0x70_u64 as u128));
    /* 140097daf */ rcx = (t_140097daf_0 as u64);
    /* 140097db3 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm6);
    // intrinsic: 0f57f600 xorps xmm6, xmm6
    /* 140097dbb */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm7);
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x304edc]
    /* 140097dc8 */ rsi = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140097dcf */ rdx = ((r9 as u32) as u64);
    /* 140097dd2 */ rbp = core::ptr::read((rax).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 140097dd6 */ let mut t_140097dd6_0: u64 = (rsi).wrapping_add(rcx);
    /* 140097dd6 */ rsi = t_140097dd6_0;
    /* 140097dd9 */ core::ptr::write((rsp).wrapping_add(0xa0_u64) as *mut u64, rcx);
    /* 140097de1 */ r12 = r13;
    /* 140097de4 */ rcx = ((r9 as u32) as u64);
    /* 140097de7 */ core::ptr::write((rsp).wrapping_add(0xa8_u64) as *mut u64, r15);
    /* 140097def */ r15 = ((r9 as u32) as u64);
    /* 140097df2 */ core::ptr::write((rsp).wrapping_add(0x90_u64) as *mut u32, (rdx as u32));
    /* 140097df9 */ core::ptr::write((rsp).wrapping_add(0x98_u64) as *mut u32, (rcx as u32));
    /* 140097e00 */ let mut t_140097e00: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    if (((SF != OF) | (t_140097e00 == (rcx as u32))) == false) { /* -> bb3571 */ }
    if (((SF != OF) | (t_140097e00 == (rcx as u32))) != 0) { /* -> bb3570 */ }

    // ---- bb3570 @ 0x140097e06 ----
    if (((SF != OF) | (t_140097e00 == (rcx as u32))) == false) { /* -> bb3571 */ }
    if (((SF != OF) | (t_140097e00 == (rcx as u32))) != 0) { /* -> bb3615 */ }

    // ---- bb3571 @ 0x140097e0c ----
    /* 140097e0c */ rbx = ((r9 as u32) as u64);
    /* 140097e0f */ r14 = ((r9 as u32) as u64);
    /* fallthrough -> bb3573 */

    // ---- bb3573 @ 0x140097e12 ----
    if (r12 != rbx) {
        /* -> bb3577 */
    } else {
        /* -> bb3576 */
    }

    // ---- bb3576 @ 0x140097e15 ----
    if (r12 != rbx) {
        /* -> bb3577 */
    } else {
        /* -> bb3607 */
    }

    // ---- bb3577 @ 0x140097e17 ----
    // intrinsic: f30f105e movss xmm3, dword ptr [rsi + 0x24]
    /* 140097e1c */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140097e23 */ xmm0 = xmm3;
    // intrinsic: f30f58c7 addss xmm0, xmm7
    // intrinsic: f3410f10 movss xmm1, dword ptr [r14 + rax + 0x24]
    // intrinsic: 0f2fc800 comiss xmm1, xmm0
    if ((CF | (r12 == rbx)) == false) { /* -> bb3586 */ }
    if ((CF | (r12 == rbx)) != 0) { /* -> bb3585 */ }

    // ---- bb3585 @ 0x140097e34 ----
    if ((CF | (r12 == rbx)) == false) { /* -> bb3586 */ }
    if ((CF | (r12 == rbx)) != 0) { /* -> bb3589 */ }

    // ---- bb3586 @ 0x140097e36 ----
    /* 140097e36 */ rdx = (((rdx as u32)).wrapping_add(0x1_u32) as u64);
    /* 140097e38 */ core::ptr::write((rsp).wrapping_add(0x90_u64) as *mut u32, (rdx as u32));
    /* fallthrough -> bb3597 */

    // ---- bb3589 @ 0x140097e41 ----
    /* 140097e41 */ xmm2 = xmm3;
    // intrinsic: f30f5cd7 subss xmm2, xmm7
    // intrinsic: 0f2fd100 comiss xmm2, xmm1
    if ((CF | (r12 == rbx)) == false) { /* -> bb3595 */ }
    if ((CF | (r12 == rbx)) != 0) { /* -> bb3594 */ }

    // ---- bb3594 @ 0x140097e4b ----
    if ((CF | (r12 == rbx)) == false) { /* -> bb3595 */ }
    if ((CF | (r12 == rbx)) != 0) { /* -> bb3597 */ }

    // ---- bb3595 @ 0x140097e4d ----
    /* 140097e4d */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    /* 140097e4f */ core::ptr::write((rsp).wrapping_add(0x98_u64) as *mut u32, (rcx as u32));
    /* fallthrough -> bb3597 */

    // ---- bb3597 @ 0x140097e56 ----
    // intrinsic: 0f2fcb00 comiss xmm1, xmm3
    if ((CF | (r12 == rbx)) == false) { /* -> bb3601 */ }
    if ((CF | (r12 == rbx)) != 0) { /* -> bb3600 */ }

    // ---- bb3600 @ 0x140097e59 ----
    if ((CF | (r12 == rbx)) == false) { /* -> bb3601 */ }
    if ((CF | (r12 == rbx)) != 0) { /* -> bb3607 */ }

    // ---- bb3601 @ 0x140097e5b ----
    // intrinsic: f30f5ccb subss xmm1, xmm3
    /* 140097e5f */ xmm0 = xmm6;
    /* 140097e62 */ fn_1400c6020();
    /* 140097e67 */ let mut t_140097e67: u32 = core::ptr::read((rsp).wrapping_add(0x98_u64) as *const u32);
    /* 140097e67 */ rcx = (t_140097e67 as u64);
    /* 140097e6e */ xmm6 = xmm0;
    /* 140097e71 */ let mut t_140097e71: u32 = core::ptr::read((rsp).wrapping_add(0x90_u64) as *const u32);
    /* 140097e71 */ rdx = (t_140097e71 as u64);
    /* fallthrough -> bb3607 */

    // ---- bb3607 @ 0x140097e78 ----
    /* 140097e78 */ r15 = (((r15 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140097e7b */ rbx = (rbx).wrapping_add(0x1_u64);
    /* 140097e7e */ let mut t_140097e7e_0: u64 = (r14).wrapping_add(0x70_u64);
    /* 140097e7e */ r14 = t_140097e7e_0;
    /* 140097e82 */ let mut t_140097e82: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    if (SF == OF) {
        /* -> bb3614 */
    } else {
        /* -> bb3613 */
    }

    // ---- bb3613 @ 0x140097e89 ----
    if (SF != OF) {
        /* -> bb3573 */
    } else {
        /* -> bb3614 */
    }

    // ---- bb3614 @ 0x140097e8b ----
    /* 140097e8b */ let mut t_140097e8b_0: u32 = 0x0_u32;
    /* 140097e8b */ r9 = (t_140097e8b_0 as u64);
    /* fallthrough -> bb3615 */

    // ---- bb3615 @ 0x140097e8e ----
    /* 140097e8e */ let mut t_140097e8e: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140097e8e */ r8 = (t_140097e8e as u64);
    /* 140097e95 */ rax = (0x88888889_u32 as u64);
    /* 140097e9a */ let mut t_140097e9a: u32 = core::ptr::read((rbp).wrapping_add(0x258_u64) as *const u32);
    /* 140097e9a */ rbx = (t_140097e9a as u64);
    /* 140097ea0 */ r15 = core::ptr::read((rsp).wrapping_add(0xa8_u64) as *const u64);
    /* 140097ea8 */ rcx = (((r8).wrapping_sub(0x1_u64) as u32) as u64);
    /* 140097eac */ let mut t_140097eac_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 140097eac */ rdx = (((t_140097eac_0 >> 0x20_u64) as u32) as u64);
    /* 140097eac */ rax = ((t_140097eac_0 as u32) as u64);
    /* 140097eae */ rax = (0x88888889_u32 as u64);
    /* 140097eb3 */ r14 = (((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64)) as u32) as u64);
    /* 140097eb7 */ let mut t_140097eb7_0: u64 = (((rax as u32) as u64)).wrapping_mul(((r8 as u32) as u64));
    /* 140097eb7 */ rdx = (((t_140097eb7_0 >> 0x20_u64) as u32) as u64);
    /* 140097eb7 */ rax = ((t_140097eb7_0 as u32) as u64);
    /* 140097eba */ r14 = (((((r14 as u32) as i64) >> ((0x5_u8 as u32) as i64)) as u64) as u64);
    /* 140097ebe */ let mut t_140097ebe_0: u32 = ((rdx as u32)).wrapping_add((r8 as u32));
    /* 140097ebe */ rdx = (t_140097ebe_0 as u64);
    /* 140097ec1 */ rcx = ((r14 as u32) as u64);
    /* 140097ec4 */ rdx = (((((rdx as u32) as i64) >> ((0x5_u8 as u32) as i64)) as u64) as u64);
    /* 140097ec7 */ rax = ((rdx as u32) as u64);
    /* 140097ec9 */ rcx = (((rcx as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140097ecc */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140097ecf */ let mut t_140097ecf_0: u32 = ((r14 as u32)).wrapping_add((rcx as u32));
    /* 140097ecf */ r14 = (t_140097ecf_0 as u64);
    /* 140097ed2 */ let mut t_140097ed2_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 140097ed2 */ rdx = (t_140097ed2_0 as u64);
    /* 140097ed4 */ let mut t_140097ed4_0: u64 = (((rdx as u32) as u64)).wrapping_mul((0x3c_u32 as u64));
    /* 140097ed4 */ rax = ((t_140097ed4_0 as u32) as u64);
    /* 140097ed7 */ let mut t_140097ed7_0: u32 = ((r8 as u32)).wrapping_sub((rax as u32));
    /* 140097ed7 */ r8 = (t_140097ed7_0 as u64);
    if ((r8 as u32) == 0x1_u32) {
        /* -> bb3639 */
    } else {
        /* -> bb3638 */
    }

    // ---- bb3638 @ 0x140097ede ----
    if ((r8 as u32) == 0x1_u32) {
        /* -> bb3639 */
    } else {
        /* -> bb4117 */
    }

    // ---- bb3639 @ 0x140097ee4 ----
    /* 140097ee4 */ rax = (0x66666667_u32 as u64);
    /* 140097ee9 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u128, xmm9);
    // intrinsic: f3440f10 movss xmm9, dword ptr [rip + 0x26b494]
    /* 140097ef8 */ rcx = ((r14 as u32) as u64);
    /* 140097efb */ let mut t_140097efb_0: u64 = (((rax as u32) as u64)).wrapping_mul(((r14 as u32) as u64));
    /* 140097efb */ rdx = (((t_140097efb_0 >> 0x20_u64) as u32) as u64);
    /* 140097efb */ rax = ((t_140097efb_0 as u32) as u64);
    /* 140097efe */ core::ptr::write((rsi).wrapping_add(0x18_u64) as *mut u32, (r9 as u32));
    /* 140097f02 */ rdx = (((((rdx as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 140097f04 */ rax = ((rdx as u32) as u64);
    /* 140097f06 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140097f09 */ let mut t_140097f09_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 140097f09 */ rdx = (t_140097f09_0 as u64);
    /* 140097f0b */ rax = (((rdx).wrapping_add((rdx).wrapping_mul(0x4_u64)) as u32) as u64);
    /* 140097f0e */ let mut t_140097f0e_0: u32 = ((rcx as u32)).wrapping_sub((rax as u32));
    /* 140097f0e */ rcx = (t_140097f0e_0 as u64);
    if ((rcx as u32) == 0x4_u32) {
        /* -> bb3655 */
    } else {
        /* -> bb3654 */
    }

    // ---- bb3654 @ 0x140097f13 ----
    if ((rcx as u32) == 0x4_u32) {
        /* -> bb3655 */
    } else {
        /* -> bb3690 */
    }

    // ---- bb3655 @ 0x140097f15 ----
    /* 140097f15 */ let mut t_140097f15: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    /* 140097f15 */ rax = (t_140097f15 as u64);
    /* 140097f1b */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    if (SF != OF) {
        /* -> bb3661 */
    } else {
        /* -> bb3660 */
    }

    // ---- bb3660 @ 0x140097f20 ----
    if (SF != OF) {
        /* -> bb3661 */
    } else {
        /* -> bb3690 */
    }

    // ---- bb3661 @ 0x140097f22 ----
    /* 140097f22 */ let mut t_140097f22: u32 = core::ptr::read((rsi).wrapping_add(0x14_u64) as *const u32);
    if (SF != OF) {
        /* -> bb3665 */
    } else {
        /* -> bb3664 */
    }

    // ---- bb3664 @ 0x140097f26 ----
    if (SF != OF) {
        /* -> bb3665 */
    } else {
        /* -> bb3690 */
    }

    // ---- bb3665 @ 0x140097f28 ----
    /* 140097f28 */ rcx = (0x3e8_u32 as u64);
    /* 140097f2d */ fn_1400c6990();
    if (t_140097f22 == 0x1e_u32) {
        /* -> bb3671 */
    } else {
        /* -> bb3670 */
    }

    // ---- bb3670 @ 0x140097f34 ----
    if (t_140097f22 == 0x1e_u32) {
        /* -> bb3671 */
    } else {
        /* -> bb3690 */
    }

    // ---- bb3671 @ 0x140097f36 ----
    // intrinsic: f30f1087 movss xmm0, dword ptr [rdi + 0x2f8]
    // intrinsic: f30f5c05 subss xmm0, dword ptr [rip + 0x26b44a]
    // intrinsic: f30f104e movss xmm1, dword ptr [rsi + 0x24]
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if ((CF | (t_140097f22 == 0x1e_u32)) == false) { /* -> bb3678 */ }
    if ((CF | (t_140097f22 == 0x1e_u32)) != 0) { /* -> bb3677 */ }

    // ---- bb3677 @ 0x140097f4e ----
    if ((CF | (t_140097f22 == 0x1e_u32)) == false) { /* -> bb3678 */ }
    if ((CF | (t_140097f22 == 0x1e_u32)) != 0) { /* -> bb3690 */ }

    // ---- bb3678 @ 0x140097f50 ----
    /* 140097f50 */ let mut t_140097f50_0: u128 = ((r12 as u128)).wrapping_mul((0x70_u64 as u128));
    /* 140097f50 */ rax = (t_140097f50_0 as u64);
    // intrinsic: f30f5c8c subss xmm1, dword ptr [rax + rsi + 0x94]
    // intrinsic: 0f540dac andps xmm1, xmmword ptr [rip + 0x304dac]
    // intrinsic: 440f2fc9 comiss xmm9, xmm1
    if ((CF | (t_140097f22 == 0x1e_u32)) == false) { /* -> bb3685 */ }
    if ((CF | (t_140097f22 == 0x1e_u32)) != 0) { /* -> bb3684 */ }

    // ---- bb3684 @ 0x140097f68 ----
    if ((CF | (t_140097f22 == 0x1e_u32)) == false) { /* -> bb3685 */ }
    if ((CF | (t_140097f22 == 0x1e_u32)) != 0) { /* -> bb3690 */ }

    // ---- bb3685 @ 0x140097f6a ----
    /* 140097f6a */ rdx = (((r13).wrapping_add(0x2_u64) as u32) as u64);
    /* 140097f6e */ r8 = ((r8 & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 140097f71 */ rcx = rbp;
    /* 140097f74 */ fn_1400b6980();
    /* 140097f79 */ core::ptr::write((rbp).wrapping_add(0x1e0_u64) as *mut u8, 0x0_u8);
    /* fallthrough -> bb3690 */

    // ---- bb3690 @ 0x140097f80 ----
    /* 140097f80 */ let mut t_140097f80_0: u32 = (0x16_u8 as u32);
    /* 140097f80 */ t_140097f80_0 = ((rbx as u32) >> t_140097f80_0);
    if CF {
        /* -> bb3694 */
    } else {
        /* -> bb3693 */
    }

    // ---- bb3693 @ 0x140097f84 ----
    if CF {
        /* -> bb3694 */
    } else {
        /* -> bb3762 */
    }

    // ---- bb3694 @ 0x140097f8a ----
    /* 140097f8a */ let mut t_140097f8a: u32 = core::ptr::read((0x140097f91_u64).wrapping_add(0x355f47_u64) as *const u32);
    if (((SF != OF) | (t_140097f8a == 0x5_u32)) == false) { /* -> bb3698 */ }
    if (((SF != OF) | (t_140097f8a == 0x5_u32)) != 0) { /* -> bb3697 */ }

    // ---- bb3697 @ 0x140097f91 ----
    if (((SF != OF) | (t_140097f8a == 0x5_u32)) == false) { /* -> bb3698 */ }
    if (((SF != OF) | (t_140097f8a == 0x5_u32)) != 0) { /* -> bb3762 */ }

    // ---- bb3698 @ 0x140097f97 ----
    if (SF == OF) {
        /* -> bb3702 */
    } else {
        /* -> bb3701 */
    }

    // ---- bb3701 @ 0x140097f9b ----
    if (SF == OF) {
        /* -> bb3702 */
    } else {
        /* -> bb3762 */
    }

    // ---- bb3702 @ 0x140097fa1 ----
    /* 140097fa1 */ let mut t_140097fa1: u8 = core::ptr::read((rbp).wrapping_add(0x1a_u64) as *const u8);
    /* 140097fa1 */ rax = ((t_140097fa1 as u32) as u64);
    if ((r14 as u32) == 0x3_u32) {
        /* -> bb3707 */
    } else {
        /* -> bb3706 */
    }

    // ---- bb3706 @ 0x140097fa7 ----
    if ((r14 as u32) == 0x3_u32) {
        /* -> bb3707 */
    } else {
        /* -> bb3711 */
    }

    // ---- bb3707 @ 0x140097fa9 ----
    /* 140097fa9 */ let mut t_140097fa9: u32 = core::ptr::read((rsi).wrapping_add(0x14_u64) as *const u32);
    if (SF != OF) {
        /* -> bb3711 */
    } else {
        /* -> bb3710 */
    }

    // ---- bb3710 @ 0x140097fad ----
    if (SF != OF) {
        /* -> bb3711 */
    } else {
        /* -> bb3762 */
    }

    // ---- bb3711 @ 0x140097fb3 ----
    /* 140097fb5 */ rcx = (0x1f4_u32 as u64);
    /* 140097fba */ rdx = (0xa_u32 as u64);
    if (t_140097fa9 == 0x1e_u32) {
        /* -> bb3715 */
    } else {
        /* -> bb3716 */
    }

    // ---- bb3716 @ 0x140097fbf ----
    /* 140097fbf */ rcx = ((rdx as u32) as u64);
    /* fallthrough -> bb3715 */

    // ---- bb3715 @ 0x140097fc2 ----
    /* 140097fc2 */ fn_1400c6990();
    if (t_140097fa9 == 0x1e_u32) {
        /* -> bb3722 */
    } else {
        /* -> bb3721 */
    }

    // ---- bb3721 @ 0x140097fc9 ----
    if (t_140097fa9 == 0x1e_u32) {
        /* -> bb3722 */
    } else {
        /* -> bb3762 */
    }

    // ---- bb3722 @ 0x140097fcf ----
    /* 140097fcf */ rax = core::ptr::read((rbp).wrapping_add(0x40_u64) as *const u64);
    /* 140097fd3 */ rcx = core::ptr::read((rax).wrapping_add(0x30_u64) as *const u64);
    // intrinsic: f30f1071 movss xmm6, dword ptr [rcx + 0xc]
    /* 140097fdc */ rcx = rbp;
    /* 140097fdf */ fn_1400b47d0();
    /* 140097fe4 */ let mut t_140097fe4: u8 = core::ptr::read((rbp).wrapping_add(0x1a_u64) as *const u8);
    /* 140097fe8 */ rbx = (((r13).wrapping_add(0x1_u64) as u32) as u64);
    /* 140097fec */ xmm2 = ((rbx as u32) as u128);
    /* 140097ff0 */ xmm1 = xmm6;
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 140097ff6 */ rax = ((rax & 0xffffffffffffff00_u64) | (((ZF == true) as u8) as u64));
    /* 140097ff9 */ rcx = rbp;
    /* 140097ffc */ core::ptr::write((rbp).wrapping_add(0x1a_u64) as *mut u8, (rax as u8));
    /* 140097fff */ let mut t_140097fff: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    /* 140097fff */ xmm0 = (t_140097fff as u128);
    // intrinsic: f30f5915 mulss xmm2, dword ptr [rip + 0x26b749]
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    // intrinsic: f30f5ed0 divss xmm2, xmm0
    // intrinsic: f30f5e97 divss xmm2, dword ptr [rdi + 0x114]
    /* 14009801e */ fn_1400b6810();
    /* 140098023 */ rdx = core::ptr::read((rdi).wrapping_add(0x98_u64) as *const u64);
    /* 14009802a */ rcx = rbp;
    /* 14009802d */ fn_1400b3db0();
    /* 140098032 */ let mut t_140098032_0: u32 = 0x0_u32;
    /* 140098032 */ r8 = (t_140098032_0 as u64);
    /* 140098035 */ rdx = ((rbx as u32) as u64);
    /* 140098037 */ rcx = rbp;
    /* 14009803a */ fn_1400b6980();
    /* 14009803f */ let mut t_14009803f_0: u32 = 0x0_u32;
    /* 14009803f */ rdx = (t_14009803f_0 as u64);
    /* 140098041 */ rcx = rbp;
    /* 140098044 */ fn_1400b7fd0();
    /* 140098049 */ let mut t_140098049_0: u32 = 0x0_u32;
    /* 140098049 */ rdx = (t_140098049_0 as u64);
    /* 14009804b */ rcx = rbp;
    /* 14009804e */ fn_1400b9530();
    /* 140098053 */ let mut t_140098053: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_140098053 == 0x0_u8) {
        /* -> bb3758 */
    } else {
        /* -> bb3757 */
    }

    // ---- bb3757 @ 0x14009805a ----
    if (t_140098053 == 0x0_u8) {
        /* -> bb3758 */
    } else {
        /* -> bb4055 */
    }

    // ---- bb3758 @ 0x140098060 ----
    /* 140098060 */ rdx = rbp;
    /* 140098063 */ rcx = rdi;
    /* 140098066 */ fn_1400d5360();
    /* fallthrough -> bb4055 */

    // ---- bb3762 @ 0x140098070 ----
    /* 140098070 */ let mut t_140098070_0: u32 = (0x12_u8 as u32);
    /* 140098070 */ t_140098070_0 = ((rbx as u32) >> t_140098070_0);
    if CF {
        /* -> bb3766 */
    } else {
        /* -> bb3765 */
    }

    // ---- bb3765 @ 0x140098074 ----
    if CF {
        /* -> bb3766 */
    } else {
        /* -> bb3782 */
    }

    // ---- bb3766 @ 0x140098076 ----
    if (SF != OF) {
        /* -> bb3770 */
    } else {
        /* -> bb3769 */
    }

    // ---- bb3769 @ 0x14009807a ----
    if (SF != OF) {
        /* -> bb3770 */
    } else {
        /* -> bb3782 */
    }

    // ---- bb3770 @ 0x14009807c ----
    /* 14009807c */ rcx = (0x2_u32 as u64);
    /* 140098081 */ fn_1400c6990();
    if ((r14 as u32) == 0x1_u32) {
        /* -> bb3776 */
    } else {
        /* -> bb3775 */
    }

    // ---- bb3775 @ 0x140098088 ----
    if ((r14 as u32) == 0x1_u32) {
        /* -> bb3776 */
    } else {
        /* -> bb3782 */
    }

    // ---- bb3776 @ 0x14009808a ----
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x26b2f2]
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x26b2da]
    /* 14009809a */ fn_1400c6d50();
    // intrinsic: f30f1185 movss dword ptr [rbp + 0x268], xmm0
    /* 1400980a7 */ let mut t_1400980a7: u32 = core::ptr::read((rsi).wrapping_add(0x18_u64) as *const u32);
    /* 1400980a7 */ let mut t_1400980a7_0: u32 = (t_1400980a7 | 0x40000_u32);
    /* 1400980a7 */ core::ptr::write((rsi).wrapping_add(0x18_u64) as *mut u32, t_1400980a7_0);
    /* fallthrough -> bb4055 */

    // ---- bb3782 @ 0x1400980b3 ----
    /* 1400980b3 */ let mut t_1400980b3_0: u32 = (0xc_u8 as u32);
    /* 1400980b3 */ t_1400980b3_0 = ((rbx as u32) >> t_1400980b3_0);
    if CF {
        /* -> bb3786 */
    } else {
        /* -> bb3785 */
    }

    // ---- bb3785 @ 0x1400980b7 ----
    if CF {
        /* -> bb3786 */
    } else {
        /* -> bb3797 */
    }

    // ---- bb3786 @ 0x1400980b9 ----
    if (SF != OF) {
        /* -> bb3790 */
    } else {
        /* -> bb3789 */
    }

    // ---- bb3789 @ 0x1400980bd ----
    if (SF != OF) {
        /* -> bb3790 */
    } else {
        /* -> bb3797 */
    }

    // ---- bb3790 @ 0x1400980bf ----
    /* 1400980bf */ rax = (((r14).wrapping_add(0x5_u64) as u32) as u64);
    /* 1400980c3 */ xmm0 = ((rax as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    // intrinsic: f30f5905 mulss xmm0, dword ptr [rip + 0x304bb2]
    // intrinsic: f30f1185 movss dword ptr [rbp + 0x268], xmm0
    /* 1400980da */ let mut t_1400980da: u32 = core::ptr::read((rsi).wrapping_add(0x18_u64) as *const u32);
    /* 1400980da */ let mut t_1400980da_0: u32 = (t_1400980da | 0x1000_u32);
    /* 1400980da */ core::ptr::write((rsi).wrapping_add(0x18_u64) as *mut u32, t_1400980da_0);
    /* fallthrough -> bb4055 */

    // ---- bb3797 @ 0x1400980e6 ----
    /* 1400980e6 */ let mut t_1400980e6_0: u32 = (0x13_u8 as u32);
    /* 1400980e6 */ t_1400980e6_0 = ((rbx as u32) >> t_1400980e6_0);
    if CF {
        /* -> bb3801 */
    } else {
        /* -> bb3800 */
    }

    // ---- bb3800 @ 0x1400980ea ----
    if CF {
        /* -> bb3801 */
    } else {
        /* -> bb3827 */
    }

    // ---- bb3801 @ 0x1400980ec ----
    // intrinsic: f30f108f movss xmm1, dword ptr [rdi + 0x2f8]
    // intrinsic: f30f5c0d subss xmm1, dword ptr [rip + 0x26b298]
    // intrinsic: f30f1046 movss xmm0, dword ptr [rsi + 0x24]
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if ((CF | ((r14 as u32) == 0x5_u32)) == false) { /* -> bb3808 */ }
    if ((CF | ((r14 as u32) == 0x5_u32)) != 0) { /* -> bb3807 */ }

    // ---- bb3807 @ 0x140098104 ----
    if ((CF | ((r14 as u32) == 0x5_u32)) == false) { /* -> bb3808 */ }
    if ((CF | ((r14 as u32) == 0x5_u32)) != 0) { /* -> bb3827 */ }

    // ---- bb3808 @ 0x140098106 ----
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x26b26e]
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x26b25a]
    /* 140098116 */ fn_1400c6d50();
    // intrinsic: f30f1185 movss dword ptr [rbp + 0x268], xmm0
    /* 140098123 */ let mut t_140098123: u32 = core::ptr::read((rsi).wrapping_add(0x18_u64) as *const u32);
    /* 140098123 */ let mut t_140098123_0: u32 = (t_140098123 | 0x80000_u32);
    /* 140098123 */ core::ptr::write((rsi).wrapping_add(0x18_u64) as *mut u32, t_140098123_0);
    /* 14009812a */ let mut t_14009812a: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_14009812a == 0x0_u8) {
        /* -> bb3817 */
    } else {
        /* -> bb3816 */
    }

    // ---- bb3816 @ 0x140098131 ----
    if (t_14009812a == 0x0_u8) {
        /* -> bb3817 */
    } else {
        /* -> bb4055 */
    }

    // ---- bb3817 @ 0x140098137 ----
    /* 140098137 */ rcx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 14009813e */ rdx = core::ptr::read((rsp).wrapping_add(0xa0_u64) as *const u64);
    /* 140098146 */ let mut t_140098146: u32 = core::ptr::read(((rdx).wrapping_add((rcx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *const u32);
    /* 140098146 */ rax = (t_140098146 as u64);
    /* 14009814a */ let mut t_14009814a_0: u32 = (0x13_u8 as u32);
    /* 14009814a */ t_14009814a_0 = ((rax as u32) >> t_14009814a_0);
    if (CF == false) { /* -> bb3824 */ }
    if CF { /* -> bb3823 */ }

    // ---- bb3823 @ 0x14009814e ----
    if (CF == false) { /* -> bb3824 */ }
    if CF { /* -> bb4055 */ }

    // ---- bb3824 @ 0x140098154 ----
    /* 140098154 */ let mut t_140098154_0: u32 = (0x13_u8 as u32);
    /* 140098154 */ let mut t_140098154_1: u32 = ((rax as u32) >> t_140098154_0);
    /* 140098154 */ rax = (((rax as u32) & ((0x1_u32 << t_140098154_0) ^ 0xffffffff_u32)) as u64);
    /* 140098158 */ core::ptr::write(((rdx).wrapping_add((rcx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb3985 */

    // ---- bb3827 @ 0x140098161 ----
    // intrinsic: f30f108f movss xmm1, dword ptr [rdi + 0x2f8]
    // intrinsic: f30f1046 movss xmm0, dword ptr [rsi + 0x24]
    // intrinsic: f30f5ccf subss xmm1, xmm7
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if ((CF | ((r14 as u32) == 0x5_u32)) == false) { /* -> bb3834 */ }
    if ((CF | ((r14 as u32) == 0x5_u32)) != 0) { /* -> bb3833 */ }

    // ---- bb3833 @ 0x140098175 ----
    if ((CF | ((r14 as u32) == 0x5_u32)) == false) { /* -> bb3834 */ }
    if ((CF | ((r14 as u32) == 0x5_u32)) != 0) { /* -> bb3865 */ }

    // ---- bb3834 @ 0x14009817b ----
    /* 14009817b */ rcx = (0x8_u32 as u64);
    /* 140098180 */ fn_1400c6990();
    if ((r14 as u32) == 0x5_u32) {
        /* -> bb3840 */
    } else {
        /* -> bb3839 */
    }

    // ---- bb3839 @ 0x140098187 ----
    if ((r14 as u32) == 0x5_u32) {
        /* -> bb3840 */
    } else {
        /* -> bb3865 */
    }

    // ---- bb3840 @ 0x140098189 ----
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x26b1f7]
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x26b1e7]
    /* 140098199 */ fn_1400c6d50();
    // intrinsic: f30f1185 movss dword ptr [rbp + 0x268], xmm0
    /* 1400981a6 */ let mut t_1400981a6: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_1400981a6 == 0x0_u8) {
        /* -> bb3848 */
    } else {
        /* -> bb3847 */
    }

    // ---- bb3847 @ 0x1400981ad ----
    if (t_1400981a6 == 0x0_u8) {
        /* -> bb3848 */
    } else {
        /* -> bb4055 */
    }

    // ---- bb3848 @ 0x1400981b3 ----
    /* 1400981b3 */ rdx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 1400981ba */ let mut t_1400981ba_0: u128 = ((r13 as u128)).wrapping_mul((0x70_u64 as u128));
    /* 1400981ba */ rcx = (t_1400981ba_0 as u64);
    /* 1400981be */ let mut t_1400981be: u32 = core::ptr::read(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *const u32);
    /* 1400981be */ rax = (t_1400981be as u64);
    /* 1400981c2 */ let mut t_1400981c2_0: u32 = (0x13_u8 as u32);
    /* 1400981c2 */ t_1400981c2_0 = ((rax as u32) >> t_1400981c2_0);
    if (CF == false) { /* -> bb3855 */ }
    if CF { /* -> bb3854 */ }

    // ---- bb3854 @ 0x1400981c6 ----
    if (CF == false) { /* -> bb3855 */ }
    if CF { /* -> bb4055 */ }

    // ---- bb3855 @ 0x1400981cc ----
    /* 1400981cc */ let mut t_1400981cc_0: u32 = (0x13_u8 as u32);
    /* 1400981cc */ let mut t_1400981cc_1: u32 = ((rax as u32) >> t_1400981cc_0);
    /* 1400981cc */ rax = (((rax as u32) & ((0x1_u32 << t_1400981cc_0) ^ 0xffffffff_u32)) as u64);
    /* 1400981d0 */ core::ptr::write(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *mut u32, (rax as u32));
    /* 1400981d4 */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400981db */ rcx = core::ptr::read((rcx).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400981df */ fn_1400b87d0();
    /* 1400981e4 */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400981eb */ rcx = rdi;
    /* 1400981ee */ rdx = core::ptr::read((rdx).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400981f2 */ fn_1400d5360();
    /* fallthrough -> bb4055 */

    // ---- bb3865 @ 0x1400981fc ----
    /* 1400981fc */ let mut t_1400981fc_0: u32 = (0xf_u8 as u32);
    /* 1400981fc */ t_1400981fc_0 = ((rbx as u32) >> t_1400981fc_0);
    if CF {
        /* -> bb3869 */
    } else {
        /* -> bb3868 */
    }

    // ---- bb3868 @ 0x140098200 ----
    if CF {
        /* -> bb3869 */
    } else {
        /* -> bb3905 */
    }

    // ---- bb3869 @ 0x140098206 ----
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x304a86]
    // intrinsic: 0f2ff000 comiss xmm6, xmm0
    if ((CF | ((r14 as u32) == 0x5_u32)) == false) { /* -> bb3874 */ }
    if ((CF | ((r14 as u32) == 0x5_u32)) != 0) { /* -> bb3873 */ }

    // ---- bb3873 @ 0x140098211 ----
    if ((CF | ((r14 as u32) == 0x5_u32)) == false) { /* -> bb3874 */ }
    if ((CF | ((r14 as u32) == 0x5_u32)) != 0) { /* -> bb3905 */ }

    // ---- bb3874 @ 0x140098217 ----
    if (((SF != OF) | ((r14 as u32) == 0x4_u32)) == false) { /* -> bb3878 */ }
    if (((SF != OF) | ((r14 as u32) == 0x4_u32)) != 0) { /* -> bb3877 */ }

    // ---- bb3877 @ 0x14009821b ----
    if (((SF != OF) | ((r14 as u32) == 0x4_u32)) == false) { /* -> bb3878 */ }
    if (((SF != OF) | ((r14 as u32) == 0x4_u32)) != 0) { /* -> bb3905 */ }

    // ---- bb3878 @ 0x14009821d ----
    // intrinsic: f30f5cf0 subss xmm6, xmm0
    // intrinsic: f30f5935 mulss xmm6, dword ptr [rip + 0x26b127]
    // intrinsic: f30f58f7 addss xmm6, xmm7
    // intrinsic: f30f5d35 minss xmm6, dword ptr [rip + 0x26b143]
    // intrinsic: f30f11b5 movss dword ptr [rbp + 0x268], xmm6
    /* 14009823d */ let mut t_14009823d: u32 = core::ptr::read((rsi).wrapping_add(0x18_u64) as *const u32);
    /* 14009823d */ let mut t_14009823d_0: u32 = (t_14009823d | 0x8000_u32);
    /* 14009823d */ core::ptr::write((rsi).wrapping_add(0x18_u64) as *mut u32, t_14009823d_0);
    /* 140098244 */ let mut t_140098244: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_140098244 == 0x0_u8) {
        /* -> bb3888 */
    } else {
        /* -> bb3887 */
    }

    // ---- bb3887 @ 0x14009824b ----
    if (t_140098244 == 0x0_u8) {
        /* -> bb3888 */
    } else {
        /* -> bb4055 */
    }

    // ---- bb3888 @ 0x140098251 ----
    /* 140098251 */ rdx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140098258 */ let mut t_140098258_0: u128 = ((r13 as u128)).wrapping_mul((0x70_u64 as u128));
    /* 140098258 */ rcx = (t_140098258_0 as u64);
    /* 14009825c */ let mut t_14009825c: u32 = core::ptr::read(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *const u32);
    /* 14009825c */ rax = (t_14009825c as u64);
    /* 140098260 */ let mut t_140098260_0: u32 = (0xf_u8 as u32);
    /* 140098260 */ t_140098260_0 = ((rax as u32) >> t_140098260_0);
    if (CF == false) { /* -> bb3895 */ }
    if CF { /* -> bb3894 */ }

    // ---- bb3894 @ 0x140098264 ----
    if (CF == false) { /* -> bb3895 */ }
    if CF { /* -> bb4055 */ }

    // ---- bb3895 @ 0x14009826a ----
    /* 14009826a */ let mut t_14009826a_0: u32 = (0xf_u8 as u32);
    /* 14009826a */ let mut t_14009826a_1: u32 = ((rax as u32) >> t_14009826a_0);
    /* 14009826a */ rax = (((rax as u32) & ((0x1_u32 << t_14009826a_0) ^ 0xffffffff_u32)) as u64);
    /* 14009826e */ core::ptr::write(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *mut u32, (rax as u32));
    /* 140098272 */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140098279 */ rcx = core::ptr::read((rcx).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 14009827d */ fn_1400b87d0();
    /* 140098282 */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140098289 */ rcx = rdi;
    /* 14009828c */ rdx = core::ptr::read((rdx).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 140098290 */ fn_1400d5360();
    /* fallthrough -> bb4055 */

    // ---- bb3905 @ 0x14009829a ----
    /* 14009829a */ let mut t_14009829a_0: u32 = (0x10_u8 as u32);
    /* 14009829a */ t_14009829a_0 = ((rbx as u32) >> t_14009829a_0);
    if CF {
        /* -> bb3909 */
    } else {
        /* -> bb3908 */
    }

    // ---- bb3908 @ 0x14009829e ----
    if CF {
        /* -> bb3909 */
    } else {
        /* -> bb3945 */
    }

    // ---- bb3909 @ 0x1400982a4 ----
    if (SF == OF) {
        /* -> bb3913 */
    } else {
        /* -> bb3912 */
    }

    // ---- bb3912 @ 0x1400982a8 ----
    if (SF == OF) {
        /* -> bb3913 */
    } else {
        /* -> bb3945 */
    }

    // ---- bb3913 @ 0x1400982ae ----
    /* 1400982ae */ let mut t_1400982ae: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    /* 1400982ae */ rax = (t_1400982ae as u64);
    /* 1400982b4 */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    /* 1400982b6 */ let mut t_1400982b6: u32 = core::ptr::read((rsp).wrapping_add(0x98_u64) as *const u32);
    if (t_1400982b6 == (rax as u32)) {
        /* -> bb3919 */
    } else {
        /* -> bb3918 */
    }

    // ---- bb3918 @ 0x1400982bd ----
    if (t_1400982b6 == (rax as u32)) {
        /* -> bb3919 */
    } else {
        /* -> bb3945 */
    }

    // ---- bb3919 @ 0x1400982bf ----
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x26b0a1]
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x26b091]
    /* 1400982cf */ fn_1400c6d50();
    // intrinsic: f30f1185 movss dword ptr [rbp + 0x268], xmm0
    /* 1400982dc */ let mut t_1400982dc: u32 = core::ptr::read((rsi).wrapping_add(0x18_u64) as *const u32);
    /* 1400982dc */ let mut t_1400982dc_0: u32 = (t_1400982dc | 0x10000_u32);
    /* 1400982dc */ core::ptr::write((rsi).wrapping_add(0x18_u64) as *mut u32, t_1400982dc_0);
    /* 1400982e3 */ let mut t_1400982e3: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_1400982e3 == 0x0_u8) {
        /* -> bb3928 */
    } else {
        /* -> bb3927 */
    }

    // ---- bb3927 @ 0x1400982ea ----
    if (t_1400982e3 == 0x0_u8) {
        /* -> bb3928 */
    } else {
        /* -> bb4055 */
    }

    // ---- bb3928 @ 0x1400982f0 ----
    /* 1400982f0 */ rdx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 1400982f7 */ let mut t_1400982f7_0: u128 = ((r13 as u128)).wrapping_mul((0x70_u64 as u128));
    /* 1400982f7 */ rcx = (t_1400982f7_0 as u64);
    /* 1400982fb */ let mut t_1400982fb: u32 = core::ptr::read(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *const u32);
    /* 1400982fb */ rax = (t_1400982fb as u64);
    /* 1400982ff */ let mut t_1400982ff_0: u32 = (0x10_u8 as u32);
    /* 1400982ff */ t_1400982ff_0 = ((rax as u32) >> t_1400982ff_0);
    if (CF == false) { /* -> bb3935 */ }
    if CF { /* -> bb3934 */ }

    // ---- bb3934 @ 0x140098303 ----
    if (CF == false) { /* -> bb3935 */ }
    if CF { /* -> bb4055 */ }

    // ---- bb3935 @ 0x140098309 ----
    /* 140098309 */ let mut t_140098309_0: u32 = (0x10_u8 as u32);
    /* 140098309 */ let mut t_140098309_1: u32 = ((rax as u32) >> t_140098309_0);
    /* 140098309 */ rax = (((rax as u32) & ((0x1_u32 << t_140098309_0) ^ 0xffffffff_u32)) as u64);
    /* 14009830d */ core::ptr::write(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *mut u32, (rax as u32));
    /* 140098311 */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140098318 */ rcx = core::ptr::read((rcx).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 14009831c */ fn_1400b87d0();
    /* 140098321 */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140098328 */ rcx = rdi;
    /* 14009832b */ rdx = core::ptr::read((rdx).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 14009832f */ fn_1400d5360();
    /* fallthrough -> bb4055 */

    // ---- bb3945 @ 0x140098339 ----
    /* 140098339 */ let mut t_140098339_0: u32 = (0xd_u8 as u32);
    /* 140098339 */ t_140098339_0 = ((rbx as u32) >> t_140098339_0);
    if CF {
        /* -> bb3949 */
    } else {
        /* -> bb3948 */
    }

    // ---- bb3948 @ 0x14009833d ----
    if CF {
        /* -> bb3949 */
    } else {
        /* -> bb3993 */
    }

    // ---- bb3949 @ 0x140098343 ----
    /* 140098343 */ let mut t_140098343: u32 = core::ptr::read((rbp).wrapping_add(0xc_u64) as *const u32);
    if (t_140098343 == 0x4_u32) {
        /* -> bb3953 */
    } else {
        /* -> bb3952 */
    }

    // ---- bb3952 @ 0x140098347 ----
    if (t_140098343 == 0x4_u32) {
        /* -> bb3953 */
    } else {
        /* -> bb3993 */
    }

    // ---- bb3953 @ 0x14009834d ----
    if (SF == OF) {
        /* -> bb3957 */
    } else {
        /* -> bb3956 */
    }

    // ---- bb3956 @ 0x140098351 ----
    if (SF == OF) {
        /* -> bb3957 */
    } else {
        /* -> bb3963 */
    }

    // ---- bb3957 @ 0x140098353 ----
    /* 140098353 */ let mut t_140098353: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    /* 140098353 */ rax = (t_140098353 as u64);
    /* 140098359 */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    /* 14009835b */ let mut t_14009835b: u32 = core::ptr::read((rsp).wrapping_add(0x90_u64) as *const u32);
    if (t_14009835b != (rax as u32)) {
        /* -> bb3963 */
    } else {
        /* -> bb3962 */
    }

    // ---- bb3962 @ 0x140098362 ----
    if (t_14009835b != (rax as u32)) {
        /* -> bb3963 */
    } else {
        /* -> bb3969 */
    }

    // ---- bb3963 @ 0x140098364 ----
    /* 140098364 */ rcx = (0x3e8_u32 as u64);
    /* 140098369 */ fn_1400c6990();
    if (t_14009835b == (rax as u32)) {
        /* -> bb3969 */
    } else {
        /* -> bb3968 */
    }

    // ---- bb3968 @ 0x140098370 ----
    if (t_14009835b == (rax as u32)) {
        /* -> bb3969 */
    } else {
        /* -> bb3993 */
    }

    // ---- bb3969 @ 0x140098372 ----
    /* 140098372 */ rcx = rbp;
    /* 140098375 */ fn_1400b8410();
    /* 14009837a */ let mut t_14009837a: u32 = core::ptr::read((rsi).wrapping_add(0x18_u64) as *const u32);
    /* 14009837a */ let mut t_14009837a_0: u32 = (t_14009837a | 0x2000_u32);
    /* 14009837a */ core::ptr::write((rsi).wrapping_add(0x18_u64) as *mut u32, t_14009837a_0);
    /* 140098381 */ let mut t_140098381: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_140098381 == 0x0_u8) {
        /* -> bb3976 */
    } else {
        /* -> bb3975 */
    }

    // ---- bb3975 @ 0x140098388 ----
    if (t_140098381 == 0x0_u8) {
        /* -> bb3976 */
    } else {
        /* -> bb4055 */
    }

    // ---- bb3976 @ 0x14009838e ----
    /* 14009838e */ rdx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140098395 */ let mut t_140098395_0: u128 = ((r13 as u128)).wrapping_mul((0x70_u64 as u128));
    /* 140098395 */ rcx = (t_140098395_0 as u64);
    /* 140098399 */ let mut t_140098399: u32 = core::ptr::read(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *const u32);
    /* 140098399 */ rax = (t_140098399 as u64);
    /* 14009839d */ let mut t_14009839d_0: u32 = (0xd_u8 as u32);
    /* 14009839d */ t_14009839d_0 = ((rax as u32) >> t_14009839d_0);
    if (CF == false) { /* -> bb3983 */ }
    if CF { /* -> bb3982 */ }

    // ---- bb3982 @ 0x1400983a1 ----
    if (CF == false) { /* -> bb3983 */ }
    if CF { /* -> bb4055 */ }

    // ---- bb3983 @ 0x1400983a7 ----
    /* 1400983a7 */ let mut t_1400983a7_0: u32 = (0xd_u8 as u32);
    /* 1400983a7 */ let mut t_1400983a7_1: u32 = ((rax as u32) >> t_1400983a7_0);
    /* 1400983a7 */ rax = (((rax as u32) & ((0x1_u32 << t_1400983a7_0) ^ 0xffffffff_u32)) as u64);
    /* 1400983ab */ core::ptr::write(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb3985 */

    // ---- bb3985 @ 0x1400983af ----
    /* 1400983af */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400983b6 */ rcx = core::ptr::read((rcx).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400983ba */ fn_1400b87d0();
    /* 1400983bf */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400983c6 */ rcx = rdi;
    /* 1400983c9 */ rdx = core::ptr::read((rdx).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400983cd */ fn_1400d5360();
    /* fallthrough -> bb4055 */

    // ---- bb3993 @ 0x1400983d7 ----
    /* 1400983d7 */ let mut t_1400983d7_0: u32 = (0xe_u8 as u32);
    /* 1400983d7 */ t_1400983d7_0 = ((rbx as u32) >> t_1400983d7_0);
    if CF {
        /* -> bb3997 */
    } else {
        /* -> bb3996 */
    }

    // ---- bb3996 @ 0x1400983db ----
    if CF {
        /* -> bb3997 */
    } else {
        /* -> bb4033 */
    }

    // ---- bb3997 @ 0x1400983e1 ----
    /* 1400983e1 */ let mut t_1400983e1: u8 = core::ptr::read((rsi).wrapping_add(0x29_u64) as *const u8);
    if (t_1400983e1 == 0x0_u8) {
        /* -> bb4001 */
    } else {
        /* -> bb4000 */
    }

    // ---- bb4000 @ 0x1400983e5 ----
    if (t_1400983e1 == 0x0_u8) {
        /* -> bb4001 */
    } else {
        /* -> bb4011 */
    }

    // ---- bb4001 @ 0x1400983e7 ----
    /* 1400983e7 */ core::ptr::write((rbp).wrapping_add(0x268_u64) as *mut u32, 0x3f400000_u32);
    /* 1400983f1 */ rcx = (0x8_u32 as u64);
    /* 1400983f6 */ let mut t_1400983f6: u32 = core::ptr::read((rsi).wrapping_add(0x18_u64) as *const u32);
    /* 1400983f6 */ let mut t_1400983f6_0: u32 = (t_1400983f6 | 0x4000_u32);
    /* 1400983f6 */ core::ptr::write((rsi).wrapping_add(0x18_u64) as *mut u32, t_1400983f6_0);
    /* 1400983fd */ fn_1400c6990();
    if (t_1400983e1 == 0x0_u8) {
        /* -> bb4009 */
    } else {
        /* -> bb4008 */
    }

    // ---- bb4008 @ 0x140098404 ----
    if (t_1400983e1 == 0x0_u8) {
        /* -> bb4009 */
    } else {
        /* -> bb4055 */
    }

    // ---- bb4009 @ 0x14009840a ----
    /* 14009840a */ core::ptr::write((rsi).wrapping_add(0x29_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb4055 */

    // ---- bb4011 @ 0x140098413 ----
    /* 140098413 */ let mut t_140098413: u8 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u8);
    if (t_140098413 == 0x0_u8) {
        /* -> bb4015 */
    } else {
        /* -> bb4014 */
    }

    // ---- bb4014 @ 0x14009841a ----
    if (t_140098413 == 0x0_u8) {
        /* -> bb4015 */
    } else {
        /* -> bb4031 */
    }

    // ---- bb4015 @ 0x14009841c ----
    /* 14009841c */ rdx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 140098423 */ let mut t_140098423_0: u128 = ((r13 as u128)).wrapping_mul((0x70_u64 as u128));
    /* 140098423 */ rcx = (t_140098423_0 as u64);
    /* 140098427 */ let mut t_140098427: u32 = core::ptr::read(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *const u32);
    /* 140098427 */ rax = (t_140098427 as u64);
    /* 14009842b */ let mut t_14009842b_0: u32 = (0xe_u8 as u32);
    /* 14009842b */ t_14009842b_0 = ((rax as u32) >> t_14009842b_0);
    if (CF == false) { /* -> bb4022 */ }
    if CF { /* -> bb4021 */ }

    // ---- bb4021 @ 0x14009842f ----
    if (CF == false) { /* -> bb4022 */ }
    if CF { /* -> bb4031 */ }

    // ---- bb4022 @ 0x140098431 ----
    /* 140098431 */ let mut t_140098431_0: u32 = (0xe_u8 as u32);
    /* 140098431 */ let mut t_140098431_1: u32 = ((rax as u32) >> t_140098431_0);
    /* 140098431 */ rax = (((rax as u32) & ((0x1_u32 << t_140098431_0) ^ 0xffffffff_u32)) as u64);
    /* 140098435 */ core::ptr::write(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x1c_u64) as *mut u32, (rax as u32));
    /* 140098439 */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140098440 */ rcx = core::ptr::read((rcx).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 140098444 */ fn_1400b87d0();
    /* 140098449 */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140098450 */ rcx = rdi;
    /* 140098453 */ rdx = core::ptr::read((rdx).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 140098457 */ fn_1400d5360();
    /* fallthrough -> bb4031 */

    // ---- bb4031 @ 0x14009845c ----
    /* 14009845c */ core::ptr::write((rbp).wrapping_add(0x268_u64) as *mut u32, 0x3f8ccccd_u32);
    /* fallthrough -> bb4055 */

    // ---- bb4033 @ 0x140098468 ----
    /* 140098468 */ let mut t_140098468_0: u32 = (0x15_u8 as u32);
    /* 140098468 */ t_140098468_0 = ((rbx as u32) >> t_140098468_0);
    if CF {
        /* -> bb4037 */
    } else {
        /* -> bb4036 */
    }

    // ---- bb4036 @ 0x14009846c ----
    if CF {
        /* -> bb4037 */
    } else {
        /* -> bb4054 */
    }

    // ---- bb4037 @ 0x14009846e ----
    /* 14009846e */ rcx = (0x2_u32 as u64);
    /* 140098473 */ fn_1400c6990();
    if (t_14009835b == (rax as u32)) {
        /* -> bb4043 */
    } else {
        /* -> bb4042 */
    }

    // ---- bb4042 @ 0x14009847a ----
    if (t_14009835b == (rax as u32)) {
        /* -> bb4043 */
    } else {
        /* -> bb4055 */
    }

    // ---- bb4043 @ 0x14009847c ----
    /* 14009847c */ fn_1400c6ad0();
    if (t_14009835b != (rax as u32)) {
        /* -> bb4048 */
    } else {
        /* -> bb4047 */
    }

    // ---- bb4047 @ 0x140098483 ----
    if (t_14009835b != (rax as u32)) {
        /* -> bb4048 */
    } else {
        /* -> bb4051 */
    }

    // ---- bb4048 @ 0x140098485 ----
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x26aed7]
    // intrinsic: f30f1185 movss dword ptr [rbp + 0x268], xmm0
    /* fallthrough -> bb4055 */

    // ---- bb4051 @ 0x140098497 ----
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x26aecd]
    // intrinsic: f30f1185 movss dword ptr [rbp + 0x268], xmm0
    /* fallthrough -> bb4055 */

    // ---- bb4054 @ 0x1400984a9 ----
    /* 1400984a9 */ core::ptr::write((rbp).wrapping_add(0x268_u64) as *mut u32, 0x3f800000_u32);
    /* fallthrough -> bb4055 */

    // ---- bb4055 @ 0x1400984b3 ----
    /* 1400984b3 */ let mut t_1400984b3: u8 = core::ptr::read((rdi).wrapping_add(0x2a5_u64) as *const u8);
    if (t_1400984b3 != 0x0_u8) {
        /* -> bb4059 */
    } else {
        /* -> bb4058 */
    }

    // ---- bb4058 @ 0x1400984ba ----
    if (t_1400984b3 != 0x0_u8) {
        /* -> bb4059 */
    } else {
        /* -> bb4078 */
    }

    // ---- bb4059 @ 0x1400984bc ----
    /* 1400984bc */ let mut t_1400984bc: u8 = core::ptr::read((rsi).wrapping_add(0x28_u64) as *const u8);
    if (t_1400984bc == 0x0_u8) {
        /* -> bb4063 */
    } else {
        /* -> bb4062 */
    }

    // ---- bb4062 @ 0x1400984c0 ----
    if (t_1400984bc == 0x0_u8) {
        /* -> bb4063 */
    } else {
        /* -> bb4086 */
    }

    // ---- bb4063 @ 0x1400984c2 ----
    /* 1400984c2 */ let mut t_1400984c2: u32 = core::ptr::read((rdi).wrapping_add(0x3e0_u64) as *const u32);
    /* 1400984c2 */ rax = (t_1400984c2 as u64);
    if (((SF == OF) & ((rax as u32) != 0x1_u32)) == false) { /* -> bb4068 */ }
    if (((SF == OF) & ((rax as u32) != 0x1_u32)) != 0) { /* -> bb4067 */ }

    // ---- bb4067 @ 0x1400984cb ----
    if (((SF == OF) & ((rax as u32) != 0x1_u32)) == false) { /* -> bb4068 */ }
    if (((SF == OF) & ((rax as u32) != 0x1_u32)) != 0) { /* -> bb4086 */ }

    // ---- bb4068 @ 0x1400984cd ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb4072 */
    } else {
        /* -> bb4071 */
    }

    // ---- bb4071 @ 0x1400984cf ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb4072 */
    } else {
        /* -> bb4075 */
    }

    // ---- bb4072 @ 0x1400984d1 ----
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x273e1f]
    // intrinsic: f30f5985 mulss xmm0, dword ptr [rbp + 0x268]
    /* fallthrough -> bb4092 */

    // ---- bb4075 @ 0x1400984e3 ----
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x3047b1]
    // intrinsic: f30f5985 mulss xmm0, dword ptr [rbp + 0x268]
    /* fallthrough -> bb4092 */

    // ---- bb4078 @ 0x1400984f5 ----
    /* 1400984f5 */ let mut t_1400984f5: u32 = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u32);
    if (t_1400984f5 == 0x0_u32) {
        /* -> bb4082 */
    } else {
        /* -> bb4081 */
    }

    // ---- bb4081 @ 0x1400984fc ----
    if (t_1400984f5 == 0x0_u32) {
        /* -> bb4082 */
    } else {
        /* -> bb4086 */
    }

    // ---- bb4082 @ 0x1400984fe ----
    /* 1400984fe */ let mut t_1400984fe: u32 = core::ptr::read((rsi).wrapping_add(0x8_u64) as *const u32);
    if (t_1400984fe != 0xffffffff_u32) {
        /* -> bb4086 */
    } else {
        /* -> bb4085 */
    }

    // ---- bb4085 @ 0x140098502 ----
    if (t_1400984fe != 0xffffffff_u32) {
        /* -> bb4086 */
    } else {
        /* -> bb4090 */
    }

    // ---- bb4086 @ 0x140098504 ----
    /* 140098504 */ let mut t_140098504: u32 = core::ptr::read((rbp).wrapping_add(0x214_u64) as *const u32);
    if (((SF != OF) | (t_140098504 == 0x0_u32)) == false) { /* -> bb4090 */ }
    if (((SF != OF) | (t_140098504 == 0x0_u32)) != 0) { /* -> bb4089 */ }

    // ---- bb4089 @ 0x14009850b ----
    if (((SF != OF) | (t_140098504 == 0x0_u32)) == false) { /* -> bb4090 */ }
    if (((SF != OF) | (t_140098504 == 0x0_u32)) != 0) { /* -> bb4094 */ }

    // ---- bb4090 @ 0x14009850d ----
    // intrinsic: f30f1085 movss xmm0, dword ptr [rbp + 0x268]
    // intrinsic: f30f5905 mulss xmm0, dword ptr [rip + 0x273ddb]
    /* fallthrough -> bb4092 */

    // ---- bb4092 @ 0x14009851d ----
    // intrinsic: f30f1185 movss dword ptr [rbp + 0x268], xmm0
    /* 140098525 */ let mut t_140098525: u32 = core::ptr::read((rsi).wrapping_add(0x18_u64) as *const u32);
    /* 140098525 */ let mut t_140098525_0: u32 = (t_140098525 | 0x2_u32);
    /* 140098525 */ core::ptr::write((rsi).wrapping_add(0x18_u64) as *mut u32, t_140098525_0);
    /* fallthrough -> bb4094 */

    // ---- bb4094 @ 0x140098529 ----
    if ((r14 as u32) == 0xa_u32) {
        /* -> bb4098 */
    } else {
        /* -> bb4097 */
    }

    // ---- bb4097 @ 0x14009852d ----
    if ((r14 as u32) == 0xa_u32) {
        /* -> bb4098 */
    } else {
        /* -> bb4116 */
    }

    // ---- bb4098 @ 0x14009852f ----
    // intrinsic: f30f104e movss xmm1, dword ptr [rsi + 0x24]
    // intrinsic: 410f2fc9 comiss xmm1, xmm9
    if ((CF | ((r14 as u32) == 0xa_u32)) == false) { /* -> bb4103 */ }
    if ((CF | ((r14 as u32) == 0xa_u32)) != 0) { /* -> bb4102 */ }

    // ---- bb4102 @ 0x140098538 ----
    if ((CF | ((r14 as u32) == 0xa_u32)) == false) { /* -> bb4103 */ }
    if ((CF | ((r14 as u32) == 0xa_u32)) != 0) { /* -> bb4116 */ }

    // ---- bb4103 @ 0x14009853a ----
    // intrinsic: f30f1087 movss xmm0, dword ptr [rdi + 0x2f8]
    // intrinsic: f30f5c05 subss xmm0, dword ptr [rip + 0x26ae4a]
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if ((CF | ((r14 as u32) == 0xa_u32)) == false) { /* -> bb4109 */ }
    if ((CF | ((r14 as u32) == 0xa_u32)) != 0) { /* -> bb4108 */ }

    // ---- bb4108 @ 0x14009854d ----
    if ((CF | ((r14 as u32) == 0xa_u32)) == false) { /* -> bb4109 */ }
    if ((CF | ((r14 as u32) == 0xa_u32)) != 0) { /* -> bb4116 */ }

    // ---- bb4109 @ 0x14009854f ----
    /* 14009854f */ let mut t_14009854f: u32 = core::ptr::read((rsi).wrapping_add(0x14_u64) as *const u32);
    /* 140098556 */ r8 = (0x0_u32 as u64);
    /* 14009855c */ rdx = ((r13 as u32) as u64);
    /* 14009855f */ rcx = rdi;
    /* 140098562 */ r8 = ((r8 & 0xffffffffffffff00_u64) | ((((SF == OF) & (ZF == false)) as u8) as u64));
    /* 140098566 */ let mut t_140098566_0: u32 = ((r8 as u32)).wrapping_add(0x1b_u32);
    /* 140098566 */ r8 = (t_140098566_0 as u64);
    /* 14009856a */ fn_1400d2220();
    /* fallthrough -> bb4116 */

    // ---- bb4116 @ 0x14009856f ----
    /* 14009856f */ xmm9 = core::ptr::read((rsp).wrapping_add(0x20_u64) as *const u128);
    /* fallthrough -> bb4117 */

    // ---- bb4117 @ 0x140098575 ----
    /* 140098575 */ xmm6 = core::ptr::read((rsp).wrapping_add(0x40_u64) as *const u128);
    /* 14009857a */ xmm7 = core::ptr::read((rsp).wrapping_add(0x30_u64) as *const u128);
    /* 14009857f */ let mut t_14009857f_0: u64 = (rsp).wrapping_add(0x50_u64);
    /* 14009857f */ rsp = t_14009857f_0;
    /* 140098583 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140098583 */ r14 = core::ptr::read(rsp as *const u64);
    /* 140098585 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140098585 */ r13 = core::ptr::read(rsp as *const u64);
    /* 140098587 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140098587 */ r12 = core::ptr::read(rsp as *const u64);
    /* 140098589 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140098589 */ rdi = core::ptr::read(rsp as *const u64);
    /* 14009858a */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14009858a */ rsi = core::ptr::read(rsp as *const u64);
    /* 14009858b */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14009858b */ rbp = core::ptr::read(rsp as *const u64);
    /* 14009858c */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14009858c */ rbx = core::ptr::read(rsp as *const u64);
    /* 14009858d */ return;
    // <no successors>
}
