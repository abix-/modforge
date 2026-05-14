// Decompiled from Horsey.exe @ 0x140033a10
// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print
// blocks: 815

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]
pub unsafe fn price_or_score_formula() {

    // ---- bb0 @ 0x140033a10 ----
    /* 140033a10 */ let mut rax: u64 = rsp;
    /* 140033a13 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u64, rbx);
    /* 140033a17 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u64, rsi);
    /* 140033a1b */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u64, rdi);
    /* 140033a1f */ let mut rsp: u64 = (rsp).wrapping_sub(0x8_u64);
    /* 140033a1f */ core::ptr::write(rsp as *mut u64, rbp);
    /* 140033a20 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140033a20 */ core::ptr::write(rsp as *mut u64, r12);
    /* 140033a22 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140033a22 */ core::ptr::write(rsp as *mut u64, r13);
    /* 140033a24 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140033a24 */ core::ptr::write(rsp as *mut u64, r14);
    /* 140033a26 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140033a26 */ core::ptr::write(rsp as *mut u64, r15);
    /* 140033a28 */ let mut rbp: u64 = (rax).wrapping_sub(0x5f_u64);
    /* 140033a2c */ let mut t_140033a2c_0: u64 = (rsp).wrapping_sub(0x90_u64);
    /* 140033a2c */ rsp = t_140033a2c_0;
    /* 140033a33 */ core::ptr::write((rax).wrapping_sub(0x38_u64) as *mut u128, xmm6);
    /* 140033a37 */ core::ptr::write((rax).wrapping_sub(0x48_u64) as *mut u128, xmm7);
    /* 140033a3b */ let mut rbx: u64 = rcx;
    /* 140033a3e */ fn_1400ca670();
    /* 140033a43 */ let mut rcx: u64 = rbx;
    /* 140033a46 */ fn_1400cef70();
    /* 140033a4b */ let mut t_140033a4b: u32 = core::ptr::read((rbx).wrapping_add(0x254_u64) as *const u32);
    /* 140033a4b */ rcx = (t_140033a4b as u64);
    /* 140033a51 */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    /* 140033a53 */ core::ptr::write((rbx).wrapping_add(0x254_u64) as *mut u32, (rcx as u32));
    /* 140033a59 */ rax = ((rcx as u32) as u64);
    /* 140033a5b */ let mut rdi: u64 = (0x1_u32 as u64);
    /* 140033a60 */ let mut t_140033a60_0: u32 = 0x0_u32;
    /* 140033a60 */ let mut r12: u64 = (t_140033a60_0 as u64);
    /* 140033a63 */ let mut t_140033a63: u8 = core::ptr::read((0x140033a6a_u64).wrapping_add(0x3a5b11_u64) as *const u8);
    if (t_140033a63 != (r12 as u8)) {
        /* -> bb27 */
    } else {
        /* -> bb26 */
    }

    // ---- bb26 @ 0x140033a6a ----
    if (t_140033a63 != (r12 as u8)) {
        /* -> bb27 */
    } else {
        /* -> bb44 */
    }

    // ---- bb27 @ 0x140033a6c ----
    /* 140033a6c */ let mut t_140033a6c: u8 = core::ptr::read((0x140033a73_u64).wrapping_add(0x3b9bc9_u64) as *const u8);
    if (t_140033a6c != (r12 as u8)) {
        /* -> bb31 */
    } else {
        /* -> bb30 */
    }

    // ---- bb30 @ 0x140033a73 ----
    if (t_140033a6c != (r12 as u8)) {
        /* -> bb31 */
    } else {
        /* -> bb44 */
    }

    // ---- bb31 @ 0x140033a75 ----
    /* 140033a75 */ let mut t_140033a75: u32 = core::ptr::read((rbx).wrapping_add(0x250_u64) as *const u32);
    if (((SF == OF) & (t_140033a75 != 0x2_u32)) == false) { /* -> bb35 */ }
    if (((SF == OF) & (t_140033a75 != 0x2_u32)) != 0) { /* -> bb34 */ }

    // ---- bb34 @ 0x140033a7c ----
    if (((SF == OF) & (t_140033a75 != 0x2_u32)) == false) { /* -> bb35 */ }
    if (((SF == OF) & (t_140033a75 != 0x2_u32)) != 0) { /* -> bb44 */ }

    // ---- bb35 @ 0x140033a7e ----
    /* 140033a7e */ fn_14003f5e0();
    /* 140033a83 */ rax = (0x3_u32 as u64);
    /* 140033a88 */ let mut t_140033a88: u32 = core::ptr::read((rbx).wrapping_add(0x250_u64) as *const u32);
    if (t_140033a88 != (r12 as u32)) {
        /* -> bb39 */
    } else {
        /* -> bb40 */
    }

    // ---- bb40 @ 0x140033a8f ----
    /* 140033a8f */ rax = ((rdi as u32) as u64);
    /* fallthrough -> bb39 */

    // ---- bb39 @ 0x140033a92 ----
    /* 140033a92 */ core::ptr::write((rbx).wrapping_add(0x250_u64) as *mut u32, (rax as u32));
    /* 140033a98 */ core::ptr::write((rbx).wrapping_add(0x254_u64) as *mut u32, (r12 as u32));
    /* 140033a9f */ rax = ((r12 as u32) as u64);
    /* fallthrough -> bb44 */

    // ---- bb44 @ 0x140033aa2 ----
    /* 140033aa2 */ let mut t_140033aa2: u32 = core::ptr::read((rbx).wrapping_add(0x250_u64) as *const u32);
    /* 140033aa2 */ rcx = (t_140033aa2 as u64);
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2cfca8]
    if (t_140033a75 == 0x2_u32) {
        /* -> bb50 */
    } else {
        /* -> bb49 */
    }

    // ---- bb49 @ 0x140033ab2 ----
    if (t_140033a75 == 0x2_u32) {
        /* -> bb50 */
    } else {
        /* -> bb256 */
    }

    // ---- bb50 @ 0x140033ab8 ----
    if (SF == OF) {
        /* -> bb54 */
    } else {
        /* -> bb53 */
    }

    // ---- bb53 @ 0x140033abb ----
    if (SF == OF) {
        /* -> bb54 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb54 @ 0x140033ac1 ----
    /* 140033ac1 */ rcx = rbx;
    /* 140033ac4 */ fn_1400d1060();
    if ((rax as u32) != 0x3c_u32) {
        /* -> bb60 */
    } else {
        /* -> bb59 */
    }

    // ---- bb59 @ 0x140033acb ----
    if ((rax as u32) != 0x3c_u32) {
        /* -> bb60 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb60 @ 0x140033ad1 ----
    /* 140033ad1 */ let mut t_140033ad1_0: u8 = 0x0_u8;
    /* 140033ad1 */ rcx = ((rcx & 0xffffffffffffff00_u64) | (t_140033ad1_0 as u64));
    /* 140033ad3 */ let mut r8: u64 = ((r12 as u32) as u64);
    /* 140033ad6 */ let mut rdx: u64 = core::ptr::read((rbx).wrapping_add(0xb8_u64) as *const u64);
    /* 140033add */ let mut r9: u64 = core::ptr::read((rbx).wrapping_add(0xc0_u64) as *const u64);
    /* 140033ae4 */ let mut t_140033ae4_0: u64 = (r9).wrapping_sub(rdx);
    /* 140033ae4 */ r9 = t_140033ae4_0;
    /* 140033ae7 */ r9 = (((r9 as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if ((rax as u32) != 0x3c_u32) {
        /* -> bb70 */
    } else {
        /* -> bb69 */
    }

    // ---- bb69 @ 0x140033aee ----
    if ((rax as u32) != 0x3c_u32) {
        /* -> bb70 */
    } else {
        /* -> bb87 */
    }

    // ---- bb70 @ 0x140033af0 ----
    /* 140033af0 */ rax = core::ptr::read(rdx as *const u64);
    /* 140033af3 */ let mut t_140033af3: u32 = core::ptr::read((rax).wrapping_add(0x8_u64) as *const u32);
    if (t_140033af3 == 0x3_u32) {
        /* -> bb75 */
    } else {
        /* -> bb74 */
    }

    // ---- bb74 @ 0x140033af7 ----
    if (t_140033af3 == 0x3_u32) {
        /* -> bb75 */
    } else {
        /* -> bb80 */
    }

    // ---- bb75 @ 0x140033af9 ----
    /* 140033af9 */ rcx = (((rcx as u8) as u32) as u64);
    /* 140033afc */ let mut t_140033afc: u32 = core::ptr::read((rax).wrapping_add(0xc_u64) as *const u32);
    if (t_140033afc != 0xc_u32) {
        /* -> bb80 */
    } else {
        /* -> bb79 */
    }

    // ---- bb79 @ 0x140033b00 ----
    /* 140033b00 */ rcx = ((rdi as u32) as u64);
    /* fallthrough -> bb80 */

    // ---- bb80 @ 0x140033b03 ----
    /* 140033b03 */ r8 = (((r8 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140033b06 */ let mut t_140033b06_0: u64 = (rdx).wrapping_add(0x8_u64);
    /* 140033b06 */ rdx = t_140033b06_0;
    /* 140033b0a */ rax = (((r8 as u32) as i64) as u64);
    if (CF == false) { /* -> bb87 */ }
    if CF { /* -> bb86 */ }

    // ---- bb86 @ 0x140033b10 ----
    if CF { /* -> bb70 */ }
    if (CF == false) { /* -> bb87 */ }

    // ---- bb87 @ 0x140033b12 ----
    /* 140033b12 */ let mut t_140033b12: u32 = core::ptr::read((rbx).wrapping_add(0x254_u64) as *const u32);
    /* 140033b12 */ rax = (t_140033b12 as u64);
    if (rax != r9) {
        /* -> bb92 */
    } else {
        /* -> bb91 */
    }

    // ---- bb91 @ 0x140033b1a ----
    if (rax != r9) {
        /* -> bb92 */
    } else {
        /* -> bb204 */
    }

    // ---- bb92 @ 0x140033b20 ----
    if ((rax as u32) == 0x3c_u32) {
        /* -> bb96 */
    } else {
        /* -> bb95 */
    }

    // ---- bb95 @ 0x140033b23 ----
    if ((rax as u32) == 0x3c_u32) {
        /* -> bb96 */
    } else {
        /* -> bb194 */
    }

    // ---- bb96 @ 0x140033b29 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140033b2c */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 140033b30 */ let mut xmm1: u128 = core::ptr::read((0x140033b38_u64).wrapping_add(0x2cf8c8_u64) as *const u128);
    /* 140033b38 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140033b3d */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb101 */ }
    if DF { /* -> bb102 */ }

    // ---- bb101 @ 0x140033b3d ----
    /* 140033b3d */ let mut rsi: u64 = (rsi).wrapping_add(0x8_u64);
    /* 140033b3d */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb103 */

    // ---- bb102 @ 0x140033b3d ----
    /* 140033b3d */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140033b3d */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb103 */

    // ---- bb103 @ 0x140033b45 ----
    /* 140033b45 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb105 */ }
    if DF { /* -> bb106 */ }

    // ---- bb105 @ 0x140033b45 ----
    /* 140033b45 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140033b45 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb107 */

    // ---- bb106 @ 0x140033b45 ----
    /* 140033b45 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140033b45 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb107 */

    // ---- bb107 @ 0x140033b4a ----
    /* 140033b4a */ let mut t_140033b4a: u32 = core::ptr::read((0x140033b50_u64).wrapping_add(0x2d0100_u64) as *const u32);
    /* 140033b4a */ rax = (t_140033b4a as u64);
    /* 140033b50 */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u32, (rax as u32));
    /* 140033b53 */ let mut t_140033b53: u16 = core::ptr::read((0x140033b5a_u64).wrapping_add(0x2d00fa_u64) as *const u16);
    /* 140033b53 */ rax = ((t_140033b53 as u32) as u64);
    /* 140033b5a */ core::ptr::write((rbp).wrapping_sub(0x5_u64) as *mut u16, (rax as u16));
    /* 140033b5e */ let mut t_140033b5e: u8 = core::ptr::read((0x140033b65_u64).wrapping_add(0x2d00f1_u64) as *const u8);
    /* 140033b5e */ rax = ((t_140033b5e as u32) as u64);
    /* 140033b65 */ core::ptr::write((rbp).wrapping_sub(0x3_u64) as *mut u8, (rax as u8));
    /* 140033b68 */ core::ptr::write((rbp).wrapping_sub(0x2_u64) as *mut u8, (r12 as u8));
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140033b72 */ let mut t_140033b72_0: u32 = 0x0_u32;
    /* 140033b72 */ r9 = (t_140033b72_0 as u64);
    /* 140033b75 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140033b79 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140033b80 */ rcx = rbx;
    /* 140033b83 */ fn_1400d1090();
    /* 140033b89 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb127 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb126 */ }

    // ---- bb126 @ 0x140033b91 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb127 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb143 */ }

    // ---- bb127 @ 0x140033b93 ----
    /* 140033b93 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140033b96 */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140033b9a */ rax = rcx;
    if (CF == false) { /* -> bb134 */ }
    if CF { /* -> bb133 */ }

    // ---- bb133 @ 0x140033ba4 ----
    if (CF == false) { /* -> bb134 */ }
    if CF { /* -> bb142 */ }

    // ---- bb134 @ 0x140033ba6 ----
    /* 140033ba6 */ let mut t_140033ba6_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140033ba6 */ rdx = t_140033ba6_0;
    /* 140033baa */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140033bae */ let mut t_140033bae_0: u64 = (rax).wrapping_sub(rcx);
    /* 140033bae */ rax = t_140033bae_0;
    /* 140033bb1 */ let mut t_140033bb1_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140033bb1 */ rax = t_140033bb1_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb142 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb141 */ }

    // ---- bb141 @ 0x140033bb9 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb142 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1694 */ }

    // ---- bb142 @ 0x140033bbf ----
    /* 140033bbf */ fn_1402c7498();
    /* fallthrough -> bb143 */

    // ---- bb143 @ 0x140033bc4 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140033bc7 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140033bce */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140033bd3 */ rcx = (0x40_u32 as u64);
    /* 140033bd8 */ fn_1400285e0();
    /* 140033bdd */ rcx = rax;
    /* 140033be0 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140033be4 */ let mut xmm0: u128 = core::ptr::read((0x140033bec_u64).wrapping_add(0x2d05e4_u64) as *const u128);
    /* 140033bec */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140033bf1 */ xmm0 = core::ptr::read((0x140033bf8_u64).wrapping_add(0x2d0060_u64) as *const u128);
    /* 140033bf8 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140033bfb */ xmm1 = core::ptr::read((0x140033c02_u64).wrapping_add(0x2d0066_u64) as *const u128);
    /* 140033c02 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 140033c06 */ xmm0 = core::ptr::read((0x140033c0d_u64).wrapping_add(0x2d006b_u64) as *const u128);
    /* 140033c0d */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u128, xmm0);
    /* 140033c11 */ let mut t_140033c11: u32 = core::ptr::read((0x140033c17_u64).wrapping_add(0x2d0071_u64) as *const u32);
    /* 140033c11 */ rax = (t_140033c11 as u64);
    /* 140033c17 */ core::ptr::write((rcx).wrapping_add(0x30_u64) as *mut u32, (rax as u32));
    /* 140033c1a */ let mut t_140033c1a: u16 = core::ptr::read((0x140033c21_u64).wrapping_add(0x2d006b_u64) as *const u16);
    /* 140033c1a */ rax = ((t_140033c1a as u32) as u64);
    /* 140033c21 */ core::ptr::write((rcx).wrapping_add(0x34_u64) as *mut u16, (rax as u16));
    /* 140033c25 */ let mut t_140033c25: u8 = core::ptr::read((0x140033c2c_u64).wrapping_add(0x2d0062_u64) as *const u8);
    /* 140033c25 */ rax = ((t_140033c25 as u32) as u64);
    /* 140033c2c */ core::ptr::write((rcx).wrapping_add(0x36_u64) as *mut u8, (rax as u8));
    /* 140033c2f */ core::ptr::write((rcx).wrapping_add(0x37_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140033c39 */ let mut t_140033c39_0: u32 = 0x0_u32;
    /* 140033c39 */ r9 = (t_140033c39_0 as u64);
    /* 140033c3c */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140033c40 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140033c47 */ rcx = rbx;
    /* 140033c4a */ fn_1400d1090();
    /* 140033c50 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb178 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb177 */ }

    // ---- bb177 @ 0x140033c58 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb178 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1301 */ }

    // ---- bb178 @ 0x140033c5e ----
    /* 140033c5e */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140033c61 */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140033c65 */ rax = rcx;
    if (CF == false) { /* -> bb185 */ }
    if CF { /* -> bb184 */ }

    // ---- bb184 @ 0x140033c6f ----
    if (CF == false) { /* -> bb185 */ }
    if CF { /* -> bb359 */ }

    // ---- bb185 @ 0x140033c75 ----
    /* 140033c75 */ let mut t_140033c75_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140033c75 */ rdx = t_140033c75_0;
    /* 140033c79 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140033c7d */ let mut t_140033c7d_0: u64 = (rax).wrapping_sub(rcx);
    /* 140033c7d */ rax = t_140033c7d_0;
    /* 140033c80 */ let mut t_140033c80_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140033c80 */ rax = t_140033c80_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb193 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb192 */ }

    // ---- bb192 @ 0x140033c88 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb193 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1680 */ }

    // ---- bb193 @ 0x140033c8e ----
    /* fallthrough -> bb359 */

    // ---- bb194 @ 0x140033c93 ----
    if (((SF != OF) | ((rax as u32) == 0x3c_u32)) == false) { /* -> bb197 */ }
    if (((SF != OF) | ((rax as u32) == 0x3c_u32)) != 0) { /* -> bb196 */ }

    // ---- bb196 @ 0x140033c93 ----
    if (((SF != OF) | ((rax as u32) == 0x3c_u32)) == false) { /* -> bb197 */ }
    if (((SF != OF) | ((rax as u32) == 0x3c_u32)) != 0) { /* -> bb1301 */ }

    // ---- bb197 @ 0x140033c99 ----
    /* 140033c99 */ rax = core::ptr::read((rbx).wrapping_add(0x218_u64) as *const u64);
    /* 140033ca0 */ let mut t_140033ca0: u64 = core::ptr::read((rbx).wrapping_add(0x210_u64) as *const u64);
    if (t_140033ca0 == rax) {
        /* -> bb202 */
    } else {
        /* -> bb201 */
    }

    // ---- bb201 @ 0x140033ca7 ----
    if (t_140033ca0 == rax) {
        /* -> bb202 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb202 @ 0x140033cad ----
    /* 140033cad */ core::ptr::write((rbx).wrapping_add(0x250_u64) as *mut u64, rdi);
    /* fallthrough -> bb1301 */

    // ---- bb204 @ 0x140033cb9 ----
    if ((rax as u32) == 0x3c_u32) {
        /* -> bb208 */
    } else {
        /* -> bb207 */
    }

    // ---- bb207 @ 0x140033cbc ----
    if ((rax as u32) == 0x3c_u32) {
        /* -> bb208 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb208 @ 0x140033cc2 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140033cc5 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140033ccc */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140033cd1 */ rcx = (0x20_u32 as u64);
    /* 140033cd6 */ fn_1400285e0();
    /* 140033cdb */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140033cdf */ xmm0 = core::ptr::read((0x140033ce7_u64).wrapping_add(0x2d0439_u64) as *const u128);
    /* 140033ce7 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140033cec */ xmm0 = core::ptr::read((0x140033cf3_u64).wrapping_add(0x2cff9d_u64) as *const u128);
    /* 140033cf3 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140033cf6 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb220 */ }
    if DF { /* -> bb221 */ }

    // ---- bb220 @ 0x140033cf6 ----
    /* 140033cf6 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140033cf6 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb222 */

    // ---- bb221 @ 0x140033cf6 ----
    /* 140033cf6 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140033cf6 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb222 */

    // ---- bb222 @ 0x140033cfe ----
    /* 140033cfe */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb224 */ }
    if DF { /* -> bb225 */ }

    // ---- bb224 @ 0x140033cfe ----
    /* 140033cfe */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140033cfe */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb226 */

    // ---- bb225 @ 0x140033cfe ----
    /* 140033cfe */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140033cfe */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb226 */

    // ---- bb226 @ 0x140033d03 ----
    /* 140033d03 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u8, (r12 as u8));
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140033d0d */ let mut t_140033d0d_0: u32 = 0x0_u32;
    /* 140033d0d */ r9 = (t_140033d0d_0 as u64);
    /* 140033d10 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140033d14 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140033d1b */ rcx = rbx;
    /* 140033d1e */ fn_1400d1090();
    /* 140033d24 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb240 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb239 */ }

    // ---- bb239 @ 0x140033d2c ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb240 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1301 */ }

    // ---- bb240 @ 0x140033d32 ----
    /* 140033d32 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140033d35 */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140033d39 */ rax = rcx;
    if (CF == false) { /* -> bb247 */ }
    if CF { /* -> bb246 */ }

    // ---- bb246 @ 0x140033d43 ----
    if (CF == false) { /* -> bb247 */ }
    if CF { /* -> bb359 */ }

    // ---- bb247 @ 0x140033d49 ----
    /* 140033d49 */ let mut t_140033d49_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140033d49 */ rdx = t_140033d49_0;
    /* 140033d4d */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140033d51 */ let mut t_140033d51_0: u64 = (rax).wrapping_sub(rcx);
    /* 140033d51 */ rax = t_140033d51_0;
    /* 140033d54 */ let mut t_140033d54_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140033d54 */ rax = t_140033d54_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb255 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb254 */ }

    // ---- bb254 @ 0x140033d5c ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb255 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1687 */ }

    // ---- bb255 @ 0x140033d62 ----
    /* fallthrough -> bb359 */

    // ---- bb256 @ 0x140033d67 ----
    if ((rcx as u32) == (rdi as u32)) {
        /* -> bb260 */
    } else {
        /* -> bb259 */
    }

    // ---- bb259 @ 0x140033d69 ----
    if ((rcx as u32) == (rdi as u32)) {
        /* -> bb260 */
    } else {
        /* -> bb308 */
    }

    // ---- bb260 @ 0x140033d6f ----
    if ((rax as u32) == 0x3c_u32) {
        /* -> bb264 */
    } else {
        /* -> bb263 */
    }

    // ---- bb263 @ 0x140033d72 ----
    if ((rax as u32) == 0x3c_u32) {
        /* -> bb264 */
    } else {
        /* -> bb300 */
    }

    // ---- bb264 @ 0x140033d78 ----
    /* 140033d78 */ fn_14003f5e0();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140033d80 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 140033d84 */ xmm1 = core::ptr::read((0x140033d8c_u64).wrapping_add(0x2d0304_u64) as *const u128);
    /* 140033d8c */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140033d91 */ rax = 0x65766f4d68737542_u64;
    /* 140033d9b */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140033d9f */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u8, (r12 as u8));
    /* 140033da3 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x368ef4]
    /* 140033db0 */ rdx = (0x64_u32 as u64);
    /* 140033db5 */ r8 = (0x4b_u32 as u64);
    /* 140033dbb */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140033dbf */ fn_140040b90();
    /* 140033dc5 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb284 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb283 */ }

    // ---- bb283 @ 0x140033dcd ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb284 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb300 */ }

    // ---- bb284 @ 0x140033dcf ----
    /* 140033dcf */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140033dd2 */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140033dd6 */ rax = rcx;
    if (CF == false) { /* -> bb291 */ }
    if CF { /* -> bb290 */ }

    // ---- bb290 @ 0x140033de0 ----
    if (CF == false) { /* -> bb291 */ }
    if CF { /* -> bb299 */ }

    // ---- bb291 @ 0x140033de2 ----
    /* 140033de2 */ let mut t_140033de2_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140033de2 */ rdx = t_140033de2_0;
    /* 140033de6 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140033dea */ let mut t_140033dea_0: u64 = (rax).wrapping_sub(rcx);
    /* 140033dea */ rax = t_140033dea_0;
    /* 140033ded */ let mut t_140033ded_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140033ded */ rax = t_140033ded_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb299 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb298 */ }

    // ---- bb298 @ 0x140033df5 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb299 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1701 */ }

    // ---- bb299 @ 0x140033dfb ----
    /* 140033dfb */ fn_1402c7498();
    /* fallthrough -> bb300 */

    // ---- bb300 @ 0x140033e00 ----
    /* 140033e00 */ rax = (0xf0_u32 as u64);
    /* 140033e05 */ let mut t_140033e05: u32 = core::ptr::read((rbx).wrapping_add(0x254_u64) as *const u32);
    if (t_140033e05 == (rax as u32)) {
        /* -> bb305 */
    } else {
        /* -> bb304 */
    }

    // ---- bb304 @ 0x140033e0b ----
    if (t_140033e05 == (rax as u32)) {
        /* -> bb305 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb305 @ 0x140033e11 ----
    /* 140033e11 */ core::ptr::write((rbx).wrapping_add(0x250_u64) as *mut u32, 0x2_u32);
    /* 140033e1b */ core::ptr::write((rbx).wrapping_add(0x254_u64) as *mut u32, 0x3c_u32);
    /* fallthrough -> bb1301 */

    // ---- bb308 @ 0x140033e2a ----
    if ((rcx as u32) == 0x2_u32) {
        /* -> bb312 */
    } else {
        /* -> bb311 */
    }

    // ---- bb311 @ 0x140033e2d ----
    if ((rcx as u32) == 0x2_u32) {
        /* -> bb312 */
    } else {
        /* -> bb361 */
    }

    // ---- bb312 @ 0x140033e33 ----
    if ((rax as u32) == 0x3c_u32) {
        /* -> bb316 */
    } else {
        /* -> bb315 */
    }

    // ---- bb315 @ 0x140033e36 ----
    if ((rax as u32) == 0x3c_u32) {
        /* -> bb316 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb316 @ 0x140033e3c ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140033e3f */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140033e46 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140033e4b */ rcx = (0x30_u32 as u64);
    /* 140033e50 */ fn_1400285e0();
    /* 140033e55 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140033e59 */ xmm0 = core::ptr::read((0x140033e61_u64).wrapping_add(0x2d02ff_u64) as *const u128);
    /* 140033e61 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140033e66 */ xmm0 = core::ptr::read((0x140033e6d_u64).wrapping_add(0x2cfe43_u64) as *const u128);
    /* 140033e6d */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140033e70 */ xmm1 = core::ptr::read((0x140033e77_u64).wrapping_add(0x2cfe49_u64) as *const u128);
    /* 140033e77 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 140033e7b */ let mut t_140033e7b: u8 = core::ptr::read((0x140033e82_u64).wrapping_add(0x2cfe4e_u64) as *const u8);
    /* 140033e7b */ rcx = ((t_140033e7b as u32) as u64);
    /* 140033e82 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u8, (rcx as u8));
    /* 140033e85 */ core::ptr::write((rax).wrapping_add(0x21_u64) as *mut u8, (r12 as u8));
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140033e8f */ let mut t_140033e8f_0: u32 = 0x0_u32;
    /* 140033e8f */ r9 = (t_140033e8f_0 as u64);
    /* 140033e92 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140033e96 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140033e9d */ rcx = rbx;
    /* 140033ea0 */ fn_1400d1090();
    /* 140033ea6 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb344 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb343 */ }

    // ---- bb343 @ 0x140033eae ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb344 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1301 */ }

    // ---- bb344 @ 0x140033eb4 ----
    /* 140033eb4 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140033eb7 */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140033ebb */ rax = rcx;
    if (CF == false) { /* -> bb351 */ }
    if CF { /* -> bb350 */ }

    // ---- bb350 @ 0x140033ec5 ----
    if (CF == false) { /* -> bb351 */ }
    if CF { /* -> bb359 */ }

    // ---- bb351 @ 0x140033ec7 ----
    /* 140033ec7 */ let mut t_140033ec7_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140033ec7 */ rdx = t_140033ec7_0;
    /* 140033ecb */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140033ecf */ let mut t_140033ecf_0: u64 = (rax).wrapping_sub(rcx);
    /* 140033ecf */ rax = t_140033ecf_0;
    /* 140033ed2 */ let mut t_140033ed2_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140033ed2 */ rax = t_140033ed2_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb359 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb358 */ }

    // ---- bb358 @ 0x140033eda ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb359 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1708 */ }

    // ---- bb359 @ 0x140033ee0 ----
    /* 140033ee0 */ fn_1402c7498();
    /* fallthrough -> bb1301 */

    // ---- bb361 @ 0x140033eea ----
    if ((rcx as u32) == 0x3_u32) {
        /* -> bb365 */
    } else {
        /* -> bb364 */
    }

    // ---- bb364 @ 0x140033eed ----
    if ((rcx as u32) == 0x3_u32) {
        /* -> bb365 */
    } else {
        /* -> bb1100 */
    }

    // ---- bb365 @ 0x140033ef3 ----
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x368da9]
    if ((rax as u32) == 0x5a_u32) {
        /* -> bb370 */
    } else {
        /* -> bb369 */
    }

    // ---- bb369 @ 0x140033efe ----
    if ((rax as u32) == 0x5a_u32) {
        /* -> bb370 */
    } else {
        /* -> bb415 */
    }

    // ---- bb370 @ 0x140033f04 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140033f07 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 140033f0b */ xmm1 = core::ptr::read((0x140033f13_u64).wrapping_add(0x2d01bd_u64) as *const u128);
    /* 140033f13 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140033f18 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb375 */ }
    if DF { /* -> bb376 */ }

    // ---- bb375 @ 0x140033f18 ----
    /* 140033f18 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140033f18 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb377 */

    // ---- bb376 @ 0x140033f18 ----
    /* 140033f18 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140033f18 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb377 */

    // ---- bb377 @ 0x140033f20 ----
    /* 140033f20 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb379 */ }
    if DF { /* -> bb380 */ }

    // ---- bb379 @ 0x140033f20 ----
    /* 140033f20 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140033f20 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb381 */

    // ---- bb380 @ 0x140033f20 ----
    /* 140033f20 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140033f20 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb381 */

    // ---- bb381 @ 0x140033f25 ----
    /* 140033f25 */ let mut t_140033f25: u32 = core::ptr::read((0x140033f2b_u64).wrapping_add(0x2cfdb5_u64) as *const u32);
    /* 140033f25 */ rax = (t_140033f25 as u64);
    /* 140033f2b */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u32, (rax as u32));
    /* 140033f2e */ let mut t_140033f2e: u16 = core::ptr::read((0x140033f35_u64).wrapping_add(0x2cfdaf_u64) as *const u16);
    /* 140033f2e */ rax = ((t_140033f2e as u32) as u64);
    /* 140033f35 */ core::ptr::write((rbp).wrapping_sub(0x5_u64) as *mut u16, (rax as u16));
    /* 140033f39 */ core::ptr::write((rbp).wrapping_sub(0x3_u64) as *mut u8, (r12 as u8));
    /* 140033f3d */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140033f42 */ let mut xmm3: u128 = xmm6;
    /* 140033f45 */ let mut t_140033f45_0: u32 = 0x0_u32;
    /* 140033f45 */ r8 = (t_140033f45_0 as u64);
    /* 140033f48 */ rdx = (0x64_u32 as u64);
    /* 140033f4d */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140033f51 */ fn_140040b90();
    /* 140033f57 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb399 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb398 */ }

    // ---- bb398 @ 0x140033f5f ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb399 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb415 */ }

    // ---- bb399 @ 0x140033f61 ----
    /* 140033f61 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140033f64 */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140033f68 */ rax = rcx;
    if (CF == false) { /* -> bb406 */ }
    if CF { /* -> bb405 */ }

    // ---- bb405 @ 0x140033f72 ----
    if (CF == false) { /* -> bb406 */ }
    if CF { /* -> bb414 */ }

    // ---- bb406 @ 0x140033f74 ----
    /* 140033f74 */ let mut t_140033f74_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140033f74 */ rdx = t_140033f74_0;
    /* 140033f78 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140033f7c */ let mut t_140033f7c_0: u64 = (rax).wrapping_sub(rcx);
    /* 140033f7c */ rax = t_140033f7c_0;
    /* 140033f7f */ let mut t_140033f7f_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140033f7f */ rax = t_140033f7f_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb414 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb413 */ }

    // ---- bb413 @ 0x140033f87 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb414 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1715 */ }

    // ---- bb414 @ 0x140033f8d ----
    /* 140033f8d */ fn_1402c7498();
    /* fallthrough -> bb415 */

    // ---- bb415 @ 0x140033f92 ----
    /* 140033f92 */ let mut t_140033f92: u32 = core::ptr::read((rbx).wrapping_add(0x254_u64) as *const u32);
    if (t_140033f92 == 0x10e_u32) {
        /* -> bb419 */
    } else {
        /* -> bb418 */
    }

    // ---- bb418 @ 0x140033f9c ----
    if (t_140033f92 == 0x10e_u32) {
        /* -> bb419 */
    } else {
        /* -> bb522 */
    }

    // ---- bb419 @ 0x140033fa2 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140033fa5 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 140033fa9 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u64, r12);
    /* 140033fad */ core::ptr::write((rbp).wrapping_add(0x7_u64) as *mut u64, r12);
    /* 140033fb1 */ rcx = (0x20_u32 as u64);
    /* 140033fb6 */ fn_1400285e0();
    /* 140033fbb */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140033fbf */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u64, 0x11_u64);
    /* 140033fc7 */ core::ptr::write((rbp).wrapping_add(0x7_u64) as *mut u64, 0x1f_u64);
    /* 140033fcf */ xmm0 = core::ptr::read((0x140033fd6_u64).wrapping_add(0x2cfd12_u64) as *const u128);
    /* 140033fd6 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140033fd9 */ let mut t_140033fd9: u8 = core::ptr::read((0x140033fe0_u64).wrapping_add(0x2cfd18_u64) as *const u8);
    /* 140033fd9 */ rcx = ((t_140033fd9 as u32) as u64);
    /* 140033fe0 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u8, (rcx as u8));
    /* 140033fe3 */ core::ptr::write((rax).wrapping_add(0x11_u64) as *mut u8, 0x0_u8);
    /* 140033fe7 */ rdx = ((rdx & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 140033fe9 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140033fed */ fn_14003f340();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140033ff5 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 140033ff9 */ xmm1 = core::ptr::read((0x140034001_u64).wrapping_add(0x2d009f_u64) as *const u128);
    /* 140034001 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034006 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb441 */ }
    if DF { /* -> bb442 */ }

    // ---- bb441 @ 0x140034006 ----
    /* 140034006 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140034006 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb443 */

    // ---- bb442 @ 0x140034006 ----
    /* 140034006 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140034006 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb443 */

    // ---- bb443 @ 0x14003400e ----
    /* 14003400e */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb445 */ }
    if DF { /* -> bb446 */ }

    // ---- bb445 @ 0x14003400e ----
    /* 14003400e */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003400e */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb447 */

    // ---- bb446 @ 0x14003400e ----
    /* 14003400e */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003400e */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb447 */

    // ---- bb447 @ 0x140034013 ----
    /* 140034013 */ let mut t_140034013: u8 = core::ptr::read((0x14003401a_u64).wrapping_add(0x2cf896_u64) as *const u8);
    /* 140034013 */ rax = ((t_140034013 as u32) as u64);
    /* 14003401a */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u8, (rax as u8));
    /* 14003401d */ core::ptr::write((rbp).wrapping_sub(0x8_u64) as *mut u8, 0x0_u8);
    /* 140034021 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140034025 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 14003402c */ rcx = rbx;
    /* 14003402f */ fn_1400cfd60();
    /* 140034035 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb461 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb460 */ }

    // ---- bb460 @ 0x14003403d ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb461 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb477 */ }

    // ---- bb461 @ 0x14003403f ----
    /* 14003403f */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140034042 */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140034046 */ rax = rcx;
    if (CF == false) { /* -> bb468 */ }
    if CF { /* -> bb467 */ }

    // ---- bb467 @ 0x140034050 ----
    if (CF == false) { /* -> bb468 */ }
    if CF { /* -> bb476 */ }

    // ---- bb468 @ 0x140034052 ----
    /* 140034052 */ let mut t_140034052_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140034052 */ rdx = t_140034052_0;
    /* 140034056 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 14003405a */ let mut t_14003405a_0: u64 = (rax).wrapping_sub(rcx);
    /* 14003405a */ rax = t_14003405a_0;
    /* 14003405d */ let mut t_14003405d_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 14003405d */ rax = t_14003405d_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb476 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb475 */ }

    // ---- bb475 @ 0x140034065 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb476 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1722 */ }

    // ---- bb476 @ 0x14003406b ----
    /* 14003406b */ fn_1402c7498();
    /* fallthrough -> bb477 */

    // ---- bb477 @ 0x140034070 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034073 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 14003407a */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 14003407f */ rcx = (0x20_u32 as u64);
    /* 140034084 */ fn_1400285e0();
    /* 140034089 */ rdx = rax;
    /* 14003408c */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140034090 */ xmm0 = core::ptr::read((0x140034098_u64).wrapping_add(0x2d00a8_u64) as *const u128);
    /* 140034098 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 14003409d */ xmm0 = core::ptr::read((0x1400340a4_u64).wrapping_add(0x2cfc5c_u64) as *const u128);
    /* 1400340a4 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400340a7 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb490 */ }
    if DF { /* -> bb491 */ }

    // ---- bb490 @ 0x1400340a7 ----
    /* 1400340a7 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400340a7 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb492 */

    // ---- bb491 @ 0x1400340a7 ----
    /* 1400340a7 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400340a7 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb492 */

    // ---- bb492 @ 0x1400340af ----
    /* 1400340af */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb494 */ }
    if DF { /* -> bb495 */ }

    // ---- bb494 @ 0x1400340af ----
    /* 1400340af */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400340af */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb496 */

    // ---- bb495 @ 0x1400340af ----
    /* 1400340af */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400340af */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb496 */

    // ---- bb496 @ 0x1400340b4 ----
    /* 1400340b4 */ let mut t_1400340b4: u32 = core::ptr::read((0x1400340ba_u64).wrapping_add(0x2cfc5e_u64) as *const u32);
    /* 1400340b4 */ rcx = (t_1400340b4 as u64);
    /* 1400340ba */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u32, (rcx as u32));
    /* 1400340bd */ let mut t_1400340bd: u16 = core::ptr::read((0x1400340c4_u64).wrapping_add(0x2cfc58_u64) as *const u16);
    /* 1400340bd */ rax = ((t_1400340bd as u32) as u64);
    /* 1400340c4 */ core::ptr::write((rdx).wrapping_add(0x1c_u64) as *mut u16, (rax as u16));
    /* 1400340c8 */ let mut t_1400340c8: u8 = core::ptr::read((0x1400340cf_u64).wrapping_add(0x2cfc4f_u64) as *const u8);
    /* 1400340c8 */ rax = ((t_1400340c8 as u32) as u64);
    /* 1400340cf */ core::ptr::write((rdx).wrapping_add(0x1e_u64) as *mut u8, (rax as u8));
    /* 1400340d2 */ core::ptr::write((rdx).wrapping_add(0x1f_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 1400340dc */ let mut t_1400340dc_0: u32 = 0x0_u32;
    /* 1400340dc */ r9 = (t_1400340dc_0 as u64);
    /* 1400340df */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 1400340e3 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 1400340ea */ rcx = rbx;
    /* 1400340ed */ fn_1400d1090();
    /* 1400340f3 */ r8 = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb516 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb515 */ }

    // ---- bb515 @ 0x1400340fb ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb516 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb519 */ }

    // ---- bb516 @ 0x1400340fd ----
    /* 1400340fd */ rdx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140034101 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140034105 */ fn_140028310();
    /* fallthrough -> bb519 */

    // ---- bb519 @ 0x14003410a ----
    /* 14003410a */ rcx = (rbx).wrapping_add(0x18_u64);
    /* 14003410e */ rdx = (0x140034115_u64).wrapping_add(0x2cfc0b_u64);
    /* 140034115 */ fn_1400278e0();
    /* fallthrough -> bb522 */

    // ---- bb522 @ 0x14003411a ----
    /* 14003411a */ let mut t_14003411a: u32 = core::ptr::read((rbx).wrapping_add(0x280_u64) as *const u32);
    /* 14003411a */ rax = (t_14003411a as u64);
    /* 140034120 */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* 140034122 */ core::ptr::write((rbx).wrapping_add(0x280_u64) as *mut u32, (rax as u32));
    /* 140034128 */ let mut t_140034128: u32 = core::ptr::read((rbx).wrapping_add(0x27c_u64) as *const u32);
    /* 140034128 */ rcx = (t_140034128 as u64);
    if (t_140033f92 == 0x10e_u32) {
        /* -> bb530 */
    } else {
        /* -> bb529 */
    }

    // ---- bb529 @ 0x140034130 ----
    if (t_140033f92 == 0x10e_u32) {
        /* -> bb530 */
    } else {
        /* -> bb661 */
    }

    // ---- bb530 @ 0x140034136 ----
    /* 140034136 */ let mut t_140034136: u32 = core::ptr::read((rbx).wrapping_add(0xe0_u64) as *const u32);
    /* 140034136 */ rax = (t_140034136 as u64);
    if ((rax as u32) == 0x7_u32) {
        /* -> bb535 */
    } else {
        /* -> bb534 */
    }

    // ---- bb534 @ 0x14003413f ----
    if ((rax as u32) == 0x7_u32) {
        /* -> bb535 */
    } else {
        /* -> bb611 */
    }

    // ---- bb535 @ 0x140034145 ----
    /* 140034145 */ let mut t_140034145: u32 = core::ptr::read((rbx).wrapping_add(0x690_u64) as *const u32);
    if (((SF != OF) | (t_140034145 == (rcx as u32))) == false) { /* -> bb539 */ }
    if (((SF != OF) | (t_140034145 == (rcx as u32))) != 0) { /* -> bb538 */ }

    // ---- bb538 @ 0x14003414b ----
    if (((SF != OF) | (t_140034145 == (rcx as u32))) == false) { /* -> bb539 */ }
    if (((SF != OF) | (t_140034145 == (rcx as u32))) != 0) { /* -> bb541 */ }

    // ---- bb539 @ 0x14003414d ----
    /* 14003414d */ core::ptr::write((rbx).wrapping_add(0x27c_u64) as *mut u64, 0x1_u64);
    /* fallthrough -> bb1301 */

    // ---- bb541 @ 0x14003415d ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034160 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140034167 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 14003416c */ rcx = (0x20_u32 as u64);
    /* 140034171 */ fn_1400285e0();
    /* 140034176 */ rdx = rax;
    /* 140034179 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 14003417d */ xmm0 = core::ptr::read((0x140034185_u64).wrapping_add(0x2cf5eb_u64) as *const u128);
    /* 140034185 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 14003418a */ xmm0 = core::ptr::read((0x140034191_u64).wrapping_add(0x2cfb9f_u64) as *const u128);
    /* 140034191 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140034194 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb554 */ }
    if DF { /* -> bb555 */ }

    // ---- bb554 @ 0x140034194 ----
    /* 140034194 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140034194 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb556 */

    // ---- bb555 @ 0x140034194 ----
    /* 140034194 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140034194 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb556 */

    // ---- bb556 @ 0x14003419c ----
    /* 14003419c */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb558 */ }
    if DF { /* -> bb559 */ }

    // ---- bb558 @ 0x14003419c ----
    /* 14003419c */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003419c */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb560 */

    // ---- bb559 @ 0x14003419c ----
    /* 14003419c */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003419c */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb560 */

    // ---- bb560 @ 0x1400341a1 ----
    /* 1400341a1 */ let mut t_1400341a1: u32 = core::ptr::read((0x1400341a7_u64).wrapping_add(0x2cfba1_u64) as *const u32);
    /* 1400341a1 */ rcx = (t_1400341a1 as u64);
    /* 1400341a7 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u32, (rcx as u32));
    /* 1400341aa */ let mut t_1400341aa: u16 = core::ptr::read((0x1400341b1_u64).wrapping_add(0x2cfb9b_u64) as *const u16);
    /* 1400341aa */ rax = ((t_1400341aa as u32) as u64);
    /* 1400341b1 */ core::ptr::write((rdx).wrapping_add(0x1c_u64) as *mut u16, (rax as u16));
    /* 1400341b5 */ core::ptr::write((rdx).wrapping_add(0x1e_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 1400341bf */ let mut t_1400341bf_0: u32 = 0x0_u32;
    /* 1400341bf */ r9 = (t_1400341bf_0 as u64);
    /* 1400341c2 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 1400341c6 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 1400341cd */ rcx = rbx;
    /* 1400341d0 */ fn_1400d1090();
    /* 1400341d6 */ r8 = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb578 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb577 */ }

    // ---- bb577 @ 0x1400341de ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb578 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb581 */ }

    // ---- bb578 @ 0x1400341e0 ----
    /* 1400341e0 */ rdx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 1400341e4 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 1400341e8 */ fn_140028310();
    /* fallthrough -> bb581 */

    // ---- bb581 @ 0x1400341ed ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400341f0 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 1400341f7 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 1400341fc */ rcx = (0x30_u32 as u64);
    /* 140034201 */ fn_1400285e0();
    /* 140034206 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 14003420a */ xmm0 = core::ptr::read((0x140034212_u64).wrapping_add(0x2cff3e_u64) as *const u128);
    /* 140034212 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140034217 */ xmm0 = core::ptr::read((0x14003421e_u64).wrapping_add(0x2cfb32_u64) as *const u128);
    /* 14003421e */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140034221 */ xmm1 = core::ptr::read((0x140034228_u64).wrapping_add(0x2cfb38_u64) as *const u128);
    /* 140034228 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 14003422c */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140034236 */ let mut t_140034236_0: u32 = 0x0_u32;
    /* 140034236 */ r9 = (t_140034236_0 as u64);
    /* 140034239 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 14003423d */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140034244 */ rcx = rbx;
    /* 140034247 */ fn_1400d1090();
    /* 14003424d */ r8 = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb607 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb606 */ }

    // ---- bb606 @ 0x140034255 ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb607 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb1301 */ }

    // ---- bb607 @ 0x14003425b ----
    /* 14003425b */ rdx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 14003425f */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140034263 */ fn_140028310();
    /* fallthrough -> bb1301 */

    // ---- bb611 @ 0x14003426d ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb615 */
    } else {
        /* -> bb614 */
    }

    // ---- bb614 @ 0x140034270 ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb615 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb615 @ 0x140034276 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034279 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 14003427d */ let mut t_14003427d: u32 = core::ptr::read((rbx).wrapping_add(0x690_u64) as *const u32);
    if (((SF != OF) | (t_14003427d == 0x0_u32)) == false) { /* -> bb621 */ }
    if (((SF != OF) | (t_14003427d == 0x0_u32)) != 0) { /* -> bb620 */ }

    // ---- bb620 @ 0x140034284 ----
    if (((SF != OF) | (t_14003427d == 0x0_u32)) == false) { /* -> bb621 */ }
    if (((SF != OF) | (t_14003427d == 0x0_u32)) != 0) { /* -> bb639 */ }

    // ---- bb621 @ 0x140034286 ----
    /* 140034286 */ xmm1 = core::ptr::read((0x14003428e_u64).wrapping_add(0x2cfdf2_u64) as *const u128);
    /* 14003428e */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034293 */ let mut t_140034293: u32 = core::ptr::read((0x140034299_u64).wrapping_add(0x2cfadb_u64) as *const u32);
    /* 140034293 */ rax = (t_140034293 as u64);
    /* 140034299 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u32, (rax as u32));
    /* 14003429c */ let mut t_14003429c: u8 = core::ptr::read((0x1400342a3_u64).wrapping_add(0x2cfad5_u64) as *const u8);
    /* 14003429c */ rax = ((t_14003429c as u32) as u64);
    /* 1400342a3 */ core::ptr::write((rbp).wrapping_sub(0xd_u64) as *mut u8, (rax as u8));
    /* 1400342a6 */ core::ptr::write((rbp).wrapping_sub(0xc_u64) as *mut u8, 0x0_u8);
    /* 1400342aa */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400342af */ xmm3 = xmm6;
    /* 1400342b2 */ rdx = (0x64_u32 as u64);
    /* 1400342b7 */ r8 = (0x4b_u32 as u64);
    /* 1400342bd */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 1400342c1 */ fn_140040b90();
    /* 1400342c7 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 1400342cb */ fn_140027900();
    /* 1400342d0 */ core::ptr::write((rbx).wrapping_add(0x250_u64) as *mut u64, 0x4_u64);
    /* fallthrough -> bb1301 */

    // ---- bb639 @ 0x1400342e0 ----
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 1400342e3 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 1400342e8 */ rcx = (0x20_u32 as u64);
    /* 1400342ed */ fn_1400285e0();
    /* 1400342f2 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 1400342f6 */ xmm0 = core::ptr::read((0x1400342fe_u64).wrapping_add(0x2cf112_u64) as *const u128);
    /* 1400342fe */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140034303 */ xmm0 = core::ptr::read((0x14003430a_u64).wrapping_add(0x2cfa76_u64) as *const u128);
    /* 14003430a */ core::ptr::write(rax as *mut u128, xmm0);
    /* 14003430d */ let mut t_14003430d: u16 = core::ptr::read((0x140034314_u64).wrapping_add(0x2cfa7c_u64) as *const u16);
    /* 14003430d */ rcx = ((t_14003430d as u32) as u64);
    /* 140034314 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u16, (rcx as u16));
    /* 140034318 */ core::ptr::write((rax).wrapping_add(0x12_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140034322 */ let mut t_140034322_0: u32 = 0x0_u32;
    /* 140034322 */ r9 = (t_140034322_0 as u64);
    /* 140034325 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140034329 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140034330 */ rcx = rbx;
    /* 140034333 */ fn_1400d1090();
    /* 140034339 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 14003433d */ fn_140027900();
    /* fallthrough -> bb1301 */

    // ---- bb661 @ 0x140034347 ----
    if ((rcx as u32) == 0x1_u32) {
        /* -> bb665 */
    } else {
        /* -> bb664 */
    }

    // ---- bb664 @ 0x14003434a ----
    if ((rcx as u32) == 0x1_u32) {
        /* -> bb665 */
    } else {
        /* -> bb714 */
    }

    // ---- bb665 @ 0x140034350 ----
    if ((rax as u32) == (rcx as u32)) {
        /* -> bb669 */
    } else {
        /* -> bb668 */
    }

    // ---- bb668 @ 0x140034352 ----
    if ((rax as u32) == (rcx as u32)) {
        /* -> bb669 */
    } else {
        /* -> bb699 */
    }

    // ---- bb669 @ 0x140034354 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034357 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 14003435b */ xmm1 = core::ptr::read((0x140034363_u64).wrapping_add(0x2cfd3d_u64) as *const u128);
    /* 140034363 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034368 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb674 */ }
    if DF { /* -> bb675 */ }

    // ---- bb674 @ 0x140034368 ----
    /* 140034368 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140034368 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb676 */

    // ---- bb675 @ 0x140034368 ----
    /* 140034368 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140034368 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb676 */

    // ---- bb676 @ 0x140034370 ----
    /* 140034370 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb678 */ }
    if DF { /* -> bb679 */ }

    // ---- bb678 @ 0x140034370 ----
    /* 140034370 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140034370 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb680 */

    // ---- bb679 @ 0x140034370 ----
    /* 140034370 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140034370 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb680 */

    // ---- bb680 @ 0x140034375 ----
    /* 140034375 */ let mut t_140034375: u8 = core::ptr::read((0x14003437c_u64).wrapping_add(0x2cfa24_u64) as *const u8);
    /* 140034375 */ rax = ((t_140034375 as u32) as u64);
    /* 14003437c */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u8, (rax as u8));
    /* 14003437f */ core::ptr::write((rbp).wrapping_sub(0x8_u64) as *mut u8, 0x0_u8);
    /* 140034383 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140034388 */ xmm3 = xmm6;
    /* 14003438b */ let mut t_14003438b_0: u32 = 0x0_u32;
    /* 14003438b */ r8 = (t_14003438b_0 as u64);
    /* 14003438e */ rdx = (0x64_u32 as u64);
    /* 140034393 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140034397 */ fn_140040b90();
    /* 14003439d */ r8 = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb696 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb695 */ }

    // ---- bb695 @ 0x1400343a5 ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb696 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb699 */ }

    // ---- bb696 @ 0x1400343a7 ----
    /* 1400343a7 */ rdx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 1400343ab */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 1400343af */ fn_140028310();
    /* fallthrough -> bb699 */

    // ---- bb699 @ 0x1400343b4 ----
    /* 1400343b4 */ let mut t_1400343b4: u32 = core::ptr::read((rbx).wrapping_add(0x280_u64) as *const u32);
    if (t_1400343b4 == 0xb4_u32) {
        /* -> bb703 */
    } else {
        /* -> bb702 */
    }

    // ---- bb702 @ 0x1400343be ----
    if (t_1400343b4 == 0xb4_u32) {
        /* -> bb703 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb703 @ 0x1400343c4 ----
    /* 1400343c4 */ rax = core::ptr::read((rbx).wrapping_add(0x60_u64) as *const u64);
    /* 1400343c8 */ core::ptr::write((rax).wrapping_add(0x405_u64) as *mut u8, 0x1_u8);
    /* 1400343cf */ rax = core::ptr::read((rbx).wrapping_add(0x60_u64) as *const u64);
    /* 1400343d3 */ core::ptr::write((rax).wrapping_add(0x46d_u64) as *mut u8, 0x1_u8);
    /* 1400343da */ rax = core::ptr::read((rbx).wrapping_add(0x60_u64) as *const u64);
    /* 1400343de */ core::ptr::write((rax).wrapping_add(0x4d5_u64) as *mut u8, 0x1_u8);
    /* 1400343e5 */ rax = core::ptr::read((rbx).wrapping_add(0x60_u64) as *const u64);
    /* 1400343e9 */ core::ptr::write((rax).wrapping_add(0x53d_u64) as *mut u8, 0x1_u8);
    /* 1400343f0 */ rcx = rbx;
    /* 1400343f3 */ fn_1400327b0();
    /* fallthrough -> bb1301 */

    // ---- bb714 @ 0x1400343fd ----
    if ((rcx as u32) == 0x5_u32) {
        /* -> bb718 */
    } else {
        /* -> bb717 */
    }

    // ---- bb717 @ 0x140034400 ----
    if ((rcx as u32) == 0x5_u32) {
        /* -> bb718 */
    } else {
        /* -> bb1097 */
    }

    // ---- bb718 @ 0x140034406 ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb722 */
    } else {
        /* -> bb721 */
    }

    // ---- bb721 @ 0x140034409 ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb722 */
    } else {
        /* -> bb756 */
    }

    // ---- bb722 @ 0x14003440b ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003440e */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 140034412 */ xmm1 = core::ptr::read((0x14003441a_u64).wrapping_add(0x2cefe6_u64) as *const u128);
    /* 14003441a */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 14003441f */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb727 */ }
    if DF { /* -> bb728 */ }

    // ---- bb727 @ 0x14003441f ----
    /* 14003441f */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003441f */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb729 */

    // ---- bb728 @ 0x14003441f ----
    /* 14003441f */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003441f */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb729 */

    // ---- bb729 @ 0x140034427 ----
    /* 140034427 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb731 */ }
    if DF { /* -> bb732 */ }

    // ---- bb731 @ 0x140034427 ----
    /* 140034427 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140034427 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb733 */

    // ---- bb732 @ 0x140034427 ----
    /* 140034427 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140034427 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb733 */

    // ---- bb733 @ 0x14003442c ----
    /* 14003442c */ let mut t_14003442c: u32 = core::ptr::read((0x140034432_u64).wrapping_add(0x2cf97e_u64) as *const u32);
    /* 14003442c */ rax = (t_14003442c as u64);
    /* 140034432 */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u32, (rax as u32));
    /* 140034435 */ let mut t_140034435: u16 = core::ptr::read((0x14003443c_u64).wrapping_add(0x2cf978_u64) as *const u16);
    /* 140034435 */ rax = ((t_140034435 as u32) as u64);
    /* 14003443c */ core::ptr::write((rbp).wrapping_sub(0x5_u64) as *mut u16, (rax as u16));
    /* 140034440 */ let mut t_140034440: u8 = core::ptr::read((0x140034447_u64).wrapping_add(0x2cf96f_u64) as *const u8);
    /* 140034440 */ rax = ((t_140034440 as u32) as u64);
    /* 140034447 */ core::ptr::write((rbp).wrapping_sub(0x3_u64) as *mut u8, (rax as u8));
    /* 14003444a */ core::ptr::write((rbp).wrapping_sub(0x2_u64) as *mut u8, 0x0_u8);
    /* 14003444e */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140034453 */ xmm3 = xmm6;
    /* 140034456 */ let mut t_140034456_0: u32 = 0x0_u32;
    /* 140034456 */ r8 = (t_140034456_0 as u64);
    /* 140034459 */ rdx = (0x64_u32 as u64);
    /* 14003445e */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140034462 */ fn_140040b90();
    /* 140034468 */ r8 = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb753 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb752 */ }

    // ---- bb752 @ 0x140034470 ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb753 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb756 */ }

    // ---- bb753 @ 0x140034472 ----
    /* 140034472 */ rdx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140034476 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 14003447a */ fn_140028310();
    /* fallthrough -> bb756 */

    // ---- bb756 @ 0x14003447f ----
    /* 14003447f */ let mut t_14003447f: u32 = core::ptr::read((rbx).wrapping_add(0x280_u64) as *const u32);
    if (t_14003447f == 0xc3_u32) {
        /* -> bb760 */
    } else {
        /* -> bb759 */
    }

    // ---- bb759 @ 0x140034489 ----
    if (t_14003447f == 0xc3_u32) {
        /* -> bb760 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb760 @ 0x14003448f ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034492 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 140034496 */ xmm1 = core::ptr::read((0x14003449e_u64).wrapping_add(0x2cfc12_u64) as *const u128);
    /* 14003449e */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 1400344a3 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb765 */ }
    if DF { /* -> bb766 */ }

    // ---- bb765 @ 0x1400344a3 ----
    /* 1400344a3 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400344a3 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb767 */

    // ---- bb766 @ 0x1400344a3 ----
    /* 1400344a3 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400344a3 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb767 */

    // ---- bb767 @ 0x1400344ab ----
    /* 1400344ab */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb769 */ }
    if DF { /* -> bb770 */ }

    // ---- bb769 @ 0x1400344ab ----
    /* 1400344ab */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400344ab */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb771 */

    // ---- bb770 @ 0x1400344ab ----
    /* 1400344ab */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400344ab */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb771 */

    // ---- bb771 @ 0x1400344b0 ----
    /* 1400344b0 */ let mut t_1400344b0: u32 = core::ptr::read((0x1400344b6_u64).wrapping_add(0x2cf90a_u64) as *const u32);
    /* 1400344b0 */ rax = (t_1400344b0 as u64);
    /* 1400344b6 */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u32, (rax as u32));
    /* 1400344b9 */ core::ptr::write((rbp).wrapping_sub(0x5_u64) as *mut u8, 0x0_u8);
    /* 1400344bd */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400344c2 */ xmm3 = xmm6;
    /* 1400344c5 */ let mut t_1400344c5_0: u32 = 0x0_u32;
    /* 1400344c5 */ r8 = (t_1400344c5_0 as u64);
    /* 1400344c8 */ rdx = (0x64_u32 as u64);
    /* 1400344cd */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 1400344d1 */ fn_140040b90();
    /* 1400344d7 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 1400344db */ fn_140027900();
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x2cfad0]
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2cfad4]
    /* 1400344f0 */ rdx = (0xd_u32 as u64);
    /* 1400344f5 */ rcx = rbx;
    /* 1400344f8 */ fn_1400ccde0();
    /* 1400344fd */ rcx = core::ptr::read((rbx).wrapping_add(0x260_u64) as *const u64);
    /* 140034504 */ rdx = core::ptr::read(rcx as *const u64);
    /* 140034507 */ let mut t_140034507_0: u64 = (rdx).wrapping_add(0x2b8_u64);
    /* 140034507 */ rdx = t_140034507_0;
    /* 14003450e */ rcx = rax;
    /* 140034511 */ fn_14005d070();
    /* 140034516 */ rdx = (0x14003451d_u64).wrapping_add(0x3a4ff3_u64);
    /* 14003451d */ r8 = core::ptr::read((0x140034524_u64).wrapping_add(0x3a5004_u64) as *const u64);
    /* 140034524 */ rax = rdx;
    /* 140034527 */ r9 = core::ptr::read((0x14003452e_u64).wrapping_add(0x3a4fe2_u64) as *const u64);
    if (((CF == false) & (r8 != 0xf_u64)) == false) { /* -> bb800 */ }
    if (((CF == false) & (r8 != 0xf_u64)) != 0) { /* -> bb801 */ }

    // ---- bb801 @ 0x140034532 ----
    /* 140034532 */ rax = r9;
    /* fallthrough -> bb800 */

    // ---- bb800 @ 0x140034536 ----
    /* 140034536 */ let mut r10: u64 = core::ptr::read((0x14003453d_u64).wrapping_add(0x3a4fe3_u64) as *const u64);
    if (r10 == 0x9_u64) {
        /* -> bb807 */
    } else {
        /* -> bb806 */
    }

    // ---- bb806 @ 0x140034541 ----
    if (r10 == 0x9_u64) {
        /* -> bb807 */
    } else {
        /* -> bb821 */
    }

    // ---- bb807 @ 0x140034543 ----
    /* 140034543 */ rcx = core::ptr::read(rax as *const u64);
    /* 140034546 */ let mut r11: u64 = 0x656b6361686f6942_u64;
    /* 140034550 */ let mut t_140034550_0: u64 = (rcx).wrapping_sub(r11);
    /* 140034550 */ rcx = t_140034550_0;
    if (r10 == 0x9_u64) {
        /* -> bb813 */
    } else {
        /* -> bb812 */
    }

    // ---- bb812 @ 0x140034553 ----
    if (r10 == 0x9_u64) {
        /* -> bb813 */
    } else {
        /* -> bb817 */
    }

    // ---- bb813 @ 0x140034555 ----
    /* 140034555 */ let mut t_140034555: u8 = core::ptr::read((rax).wrapping_add(0x8_u64) as *const u8);
    /* 140034555 */ rcx = ((t_140034555 as u32) as u64);
    /* 140034559 */ rax = (0x72_u32 as u64);
    /* 14003455e */ rax = (((rax as u8) as u32) as u64);
    /* 140034561 */ let mut t_140034561_0: u64 = (rcx).wrapping_sub(rax);
    /* 140034561 */ rcx = t_140034561_0;
    /* fallthrough -> bb817 */

    // ---- bb817 @ 0x140034564 ----
    if (r10 != 0x9_u64) {
        /* -> bb821 */
    } else {
        /* -> bb820 */
    }

    // ---- bb820 @ 0x140034567 ----
    if (r10 != 0x9_u64) {
        /* -> bb821 */
    } else {
        /* -> bb837 */
    }

    // ---- bb821 @ 0x140034569 ----
    if (((CF == false) & (r8 != 0xf_u64)) == false) { /* -> bb823 */ }
    if (((CF == false) & (r8 != 0xf_u64)) != 0) { /* -> bb824 */ }

    // ---- bb824 @ 0x14003456d ----
    /* 14003456d */ rdx = r9;
    /* fallthrough -> bb823 */

    // ---- bb823 @ 0x140034571 ----
    if (r10 == 0x6_u64) {
        /* -> bb829 */
    } else {
        /* -> bb828 */
    }

    // ---- bb828 @ 0x140034575 ----
    if (r10 == 0x6_u64) {
        /* -> bb829 */
    } else {
        /* -> bb965 */
    }

    // ---- bb829 @ 0x14003457b ----
    /* 14003457b */ let mut t_14003457b: u32 = core::ptr::read(rdx as *const u32);
    if (t_14003457b == 0x74696c47_u32) {
        /* -> bb833 */
    } else {
        /* -> bb832 */
    }

    // ---- bb832 @ 0x140034581 ----
    if (t_14003457b == 0x74696c47_u32) {
        /* -> bb833 */
    } else {
        /* -> bb965 */
    }

    // ---- bb833 @ 0x140034587 ----
    /* 140034587 */ let mut t_140034587: u16 = core::ptr::read((rdx).wrapping_add(0x4_u64) as *const u16);
    if (t_140034587 == 0x6863_u16) {
        /* -> bb837 */
    } else {
        /* -> bb836 */
    }

    // ---- bb836 @ 0x14003458d ----
    if (t_140034587 == 0x6863_u16) {
        /* -> bb837 */
    } else {
        /* -> bb965 */
    }

    // ---- bb837 @ 0x140034593 ----
    /* 140034593 */ rax = core::ptr::read((rbx).wrapping_add(0x260_u64) as *const u64);
    /* 14003459a */ let mut r13: u64 = core::ptr::read(rax as *const u64);
    /* 14003459d */ rdi = (rbx).wrapping_add(0x130_u64);
    /* 1400345a4 */ rcx = core::ptr::read((rdi).wrapping_add(0x10_u64) as *const u64);
    /* 1400345a8 */ rsi = core::ptr::read((rdi).wrapping_add(0x8_u64) as *const u64);
    if (rsi != rcx) {
        /* -> bb846 */
    } else {
        /* -> bb845 */
    }

    // ---- bb845 @ 0x1400345af ----
    if (rsi != rcx) {
        /* -> bb846 */
    } else {
        /* -> bb849 */
    }

    // ---- bb846 @ 0x1400345b1 ----
    /* 1400345b1 */ core::ptr::write(rsi as *mut u64, r13);
    /* 1400345b4 */ let mut t_1400345b4: u64 = core::ptr::read((rdi).wrapping_add(0x8_u64) as *const u64);
    /* 1400345b4 */ let mut t_1400345b4_0: u64 = (t_1400345b4).wrapping_add(0x8_u64);
    /* 1400345b4 */ core::ptr::write((rdi).wrapping_add(0x8_u64) as *mut u64, t_1400345b4_0);
    /* fallthrough -> bb919 */

    // ---- bb849 @ 0x1400345be ----
    /* 1400345be */ rax = core::ptr::read(rdi as *const u64);
    /* 1400345c1 */ let mut r15: u64 = rsi;
    /* 1400345c4 */ let mut t_1400345c4_0: u64 = (r15).wrapping_sub(rax);
    /* 1400345c4 */ r15 = t_1400345c4_0;
    /* 1400345c7 */ r15 = (((r15 as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400345cb */ let mut r14: u64 = 0x1fffffffffffffff_u64;
    if (r15 != r14) {
        /* -> bb858 */
    } else {
        /* -> bb857 */
    }

    // ---- bb857 @ 0x1400345d8 ----
    if (r15 != r14) {
        /* -> bb858 */
    } else {
        /* -> bb1729 */
    }

    // ---- bb858 @ 0x1400345de ----
    /* 1400345de */ r8 = (r15).wrapping_add(0x1_u64);
    /* 1400345e2 */ let mut t_1400345e2_0: u64 = (rcx).wrapping_sub(rax);
    /* 1400345e2 */ rcx = t_1400345e2_0;
    /* 1400345e5 */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400345e9 */ rdx = rcx;
    /* 1400345ec */ rdx = (rdx >> 0x1_u64);
    /* 1400345ef */ rax = r14;
    /* 1400345f2 */ let mut t_1400345f2_0: u64 = (rax).wrapping_sub(rdx);
    /* 1400345f2 */ rax = t_1400345f2_0;
    if (((CF == false) & (rcx != rax)) == false) { /* -> bb869 */ }
    if (((CF == false) & (rcx != rax)) != 0) { /* -> bb868 */ }

    // ---- bb868 @ 0x1400345f8 ----
    if (((CF == false) & (rcx != rax)) == false) { /* -> bb869 */ }
    if (((CF == false) & (rcx != rax)) != 0) { /* -> bb880 */ }

    // ---- bb869 @ 0x1400345fa ----
    /* 1400345fa */ rax = (rcx).wrapping_add((rdx).wrapping_mul(0x1_u64));
    /* 1400345fe */ rcx = r8;
    if CF {
        /* -> bb873 */
    } else {
        /* -> bb874 */
    }

    // ---- bb874 @ 0x140034604 ----
    /* 140034604 */ rcx = rax;
    /* fallthrough -> bb873 */

    // ---- bb873 @ 0x140034608 ----
    if (((CF == false) & (rcx != r14)) == false) { /* -> bb879 */ }
    if (((CF == false) & (rcx != r14)) != 0) { /* -> bb878 */ }

    // ---- bb878 @ 0x14003460b ----
    if (((CF == false) & (rcx != r14)) == false) { /* -> bb879 */ }
    if (((CF == false) & (rcx != r14)) != 0) { /* -> bb1731 */ }

    // ---- bb879 @ 0x140034611 ----
    /* 140034611 */ r14 = rcx;
    /* fallthrough -> bb880 */

    // ---- bb880 @ 0x140034614 ----
    /* 140034614 */ rcx = (r14).wrapping_mul(0x8_u64);
    /* 14003461c */ fn_1400285e0();
    /* 140034621 */ r12 = rax;
    /* 140034624 */ rcx = (rax).wrapping_add((r15).wrapping_mul(0x8_u64));
    /* 140034628 */ rax = (rcx).wrapping_add(0x8_u64);
    /* 14003462c */ core::ptr::write((rbp).wrapping_add(0x67_u64) as *mut u64, rax);
    /* 140034630 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rdi);
    /* 140034634 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u64, r14);
    /* 140034638 */ core::ptr::write((rbp).wrapping_add(0xf_u64) as *mut u64, rax);
    /* 14003463c */ core::ptr::write(rcx as *mut u64, r13);
    /* 14003463f */ core::ptr::write((rbp).wrapping_add(0x7_u64) as *mut u64, rcx);
    /* 140034643 */ r8 = core::ptr::read((rdi).wrapping_add(0x8_u64) as *const u64);
    /* 140034647 */ rdx = core::ptr::read(rdi as *const u64);
    /* 14003464a */ rcx = r12;
    if (rsi == r8) {
        /* -> bb898 */
    } else {
        /* -> bb897 */
    }

    // ---- bb897 @ 0x140034650 ----
    if (rsi == r8) {
        /* -> bb898 */
    } else {
        /* -> bb900 */
    }

    // ---- bb898 @ 0x140034652 ----
    /* 140034652 */ let mut t_140034652_0: u64 = (r8).wrapping_sub(rdx);
    /* 140034652 */ r8 = t_140034652_0;
    /* fallthrough -> bb908 */

    // ---- bb900 @ 0x140034657 ----
    /* 140034657 */ r8 = rsi;
    /* 14003465a */ let mut t_14003465a_0: u64 = (r8).wrapping_sub(rdx);
    /* 14003465a */ r8 = t_14003465a_0;
    /* 14003465d */ fn_1402f9230();
    /* 140034662 */ core::ptr::write((rbp).wrapping_add(0x7_u64) as *mut u64, r12);
    /* 140034666 */ r8 = core::ptr::read((rdi).wrapping_add(0x8_u64) as *const u64);
    /* 14003466a */ let mut t_14003466a_0: u64 = (r8).wrapping_sub(rsi);
    /* 14003466a */ r8 = t_14003466a_0;
    /* 14003466d */ rdx = rsi;
    /* 140034670 */ rcx = core::ptr::read((rbp).wrapping_add(0x67_u64) as *const u64);
    /* fallthrough -> bb908 */

    // ---- bb908 @ 0x140034674 ----
    /* 140034674 */ fn_1402f9230();
    /* 140034679 */ let mut t_140034679_0: u32 = 0x0_u32;
    /* 140034679 */ rax = (t_140034679_0 as u64);
    /* 14003467b */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u64, rax);
    /* 14003467f */ r9 = r14;
    /* 140034682 */ r8 = (r15).wrapping_add(0x1_u64);
    /* 140034686 */ rdx = r12;
    /* 140034689 */ rcx = rdi;
    /* 14003468c */ fn_140037380();
    /* 140034691 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140034695 */ fn_1400372c0();
    /* 14003469a */ let mut t_14003469a_0: u32 = 0x0_u32;
    /* 14003469a */ r12 = (t_14003469a_0 as u64);
    /* fallthrough -> bb919 */

    // ---- bb919 @ 0x14003469d ----
    /* 14003469d */ core::ptr::write((rbp).wrapping_add(0x67_u64) as *mut u32, 0x41200000_u32);
    /* 1400346a4 */ core::ptr::write((rbp).wrapping_add(0x6b_u64) as *mut u32, 0x40e00000_u32);
    /* 1400346ab */ rdx = (rbp).wrapping_add(0x67_u64);
    /* 1400346af */ rcx = r13;
    /* 1400346b2 */ fn_1400b6600();
    /* 1400346b7 */ rdx = r13;
    /* 1400346ba */ rcx = rbx;
    /* 1400346bd */ fn_1400ceee0();
    /* 1400346c2 */ core::ptr::write((r13).wrapping_add(0x204_u64) as *mut u8, 0x1_u8);
    /* 1400346ca */ core::ptr::write((r13).wrapping_add(0x224_u64) as *mut u64, 0x0_u64);
    /* 1400346d5 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, 0xffffffff_u32);
    /* 1400346dd */ r9 = (0xffffffff_u32 as u64);
    /* 1400346e3 */ let mut t_1400346e3_0: u32 = 0x0_u32;
    /* 1400346e3 */ r8 = (t_1400346e3_0 as u64);
    /* 1400346e6 */ let mut t_1400346e6_0: u32 = 0x0_u32;
    /* 1400346e6 */ rdx = (t_1400346e6_0 as u64);
    /* 1400346e8 */ let mut t_1400346e8_0: u32 = 0x0_u32;
    /* 1400346e8 */ rcx = (t_1400346e8_0 as u64);
    /* 1400346ea */ fn_1400c7a10();
    /* 1400346ef */ core::ptr::write((r13).wrapping_add(0x1f8_u64) as *mut u32, (rax as u32));
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400346f9 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 1400346fd */ xmm1 = core::ptr::read((0x140034705_u64).wrapping_add(0x2cf99b_u64) as *const u128);
    /* 140034705 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 14003470a */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb941 */ }
    if DF { /* -> bb942 */ }

    // ---- bb941 @ 0x14003470a ----
    /* 14003470a */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003470a */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb943 */

    // ---- bb942 @ 0x14003470a ----
    /* 14003470a */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003470a */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb943 */

    // ---- bb943 @ 0x140034712 ----
    /* 140034712 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb945 */ }
    if DF { /* -> bb946 */ }

    // ---- bb945 @ 0x140034712 ----
    /* 140034712 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140034712 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb947 */

    // ---- bb946 @ 0x140034712 ----
    /* 140034712 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140034712 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb947 */

    // ---- bb947 @ 0x140034717 ----
    /* 140034717 */ let mut t_140034717: u8 = core::ptr::read((0x14003471e_u64).wrapping_add(0x2cf6b2_u64) as *const u8);
    /* 140034717 */ rax = ((t_140034717 as u32) as u64);
    /* 14003471e */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u8, (rax as u8));
    /* 140034721 */ core::ptr::write((rbp).wrapping_sub(0x8_u64) as *mut u8, 0x0_u8);
    /* 140034725 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140034729 */ rdx = r13;
    /* 14003472c */ rcx = rbx;
    /* 14003472f */ fn_1400cfd60();
    /* 140034735 */ r8 = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb961 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb960 */ }

    // ---- bb960 @ 0x14003473d ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb961 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb974 */ }

    // ---- bb961 @ 0x14003473f ----
    /* 14003473f */ rdx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140034743 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140034747 */ fn_140028310();
    /* fallthrough -> bb974 */

    // ---- bb965 @ 0x14003474e ----
    /* 14003474e */ rax = core::ptr::read((rbx).wrapping_add(0x260_u64) as *const u64);
    /* 140034755 */ rcx = core::ptr::read(rax as *const u64);
    if (t_140034587 != 0x6863_u16) {
        /* -> bb971 */
    } else {
        /* -> bb970 */
    }

    // ---- bb970 @ 0x14003475b ----
    if (t_140034587 != 0x6863_u16) {
        /* -> bb971 */
    } else {
        /* -> bb974 */
    }

    // ---- bb971 @ 0x14003475d ----
    /* 14003475d */ rax = core::ptr::read(rcx as *const u64);
    /* 140034760 */ rdx = ((rdi as u32) as u64);
    /* 140034762 */ (/* indirect */ core::ptr::read(rax as *const u64))();
    /* fallthrough -> bb974 */

    // ---- bb974 @ 0x140034764 ----
    /* 140034764 */ rax = core::ptr::read((rbx).wrapping_add(0x260_u64) as *const u64);
    /* 14003476b */ let mut t_14003476b: u64 = core::ptr::read((rbx).wrapping_add(0x268_u64) as *const u64);
    if (rax != t_14003476b) {
        /* -> bb979 */
    } else {
        /* -> bb978 */
    }

    // ---- bb978 @ 0x140034772 ----
    if (rax != t_14003476b) {
        /* -> bb979 */
    } else {
        /* -> bb980 */
    }

    // ---- bb979 @ 0x140034774 ----
    /* 140034774 */ core::ptr::write((rbx).wrapping_add(0x268_u64) as *mut u64, rax);
    /* fallthrough -> bb980 */

    // ---- bb980 @ 0x14003477b ----
    /* 14003477b */ let mut t_14003477b: u64 = core::ptr::read((0x140034783_u64).wrapping_add(0x3a4d9d_u64) as *const u64);
    if (t_14003477b == 0x0_u64) {
        /* -> bb984 */
    } else {
        /* -> bb983 */
    }

    // ---- bb983 @ 0x140034783 ----
    if (t_14003477b == 0x0_u64) {
        /* -> bb984 */
    } else {
        /* -> bb1067 */
    }

    // ---- bb984 @ 0x140034789 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003478c */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140034793 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034798 */ rcx = (0x40_u32 as u64);
    /* 14003479d */ fn_1400285e0();
    /* 1400347a2 */ rcx = rax;
    /* 1400347a5 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 1400347a9 */ xmm0 = core::ptr::read((0x1400347b1_u64).wrapping_add(0x2cfa0f_u64) as *const u128);
    /* 1400347b1 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 1400347b6 */ xmm0 = core::ptr::read((0x1400347bd_u64).wrapping_add(0x2cf61b_u64) as *const u128);
    /* 1400347bd */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400347c0 */ xmm1 = core::ptr::read((0x1400347c7_u64).wrapping_add(0x2cf621_u64) as *const u128);
    /* 1400347c7 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 1400347cb */ xmm0 = core::ptr::read((0x1400347d2_u64).wrapping_add(0x2cf626_u64) as *const u128);
    /* 1400347d2 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u128, xmm0);
    /* 1400347d6 */ let mut t_1400347d6: u32 = core::ptr::read((0x1400347dc_u64).wrapping_add(0x2cf62c_u64) as *const u32);
    /* 1400347d6 */ rax = (t_1400347d6 as u64);
    /* 1400347dc */ core::ptr::write((rcx).wrapping_add(0x30_u64) as *mut u32, (rax as u32));
    /* 1400347df */ let mut t_1400347df: u8 = core::ptr::read((0x1400347e6_u64).wrapping_add(0x2cf626_u64) as *const u8);
    /* 1400347df */ rax = ((t_1400347df as u32) as u64);
    /* 1400347e6 */ core::ptr::write((rcx).wrapping_add(0x34_u64) as *mut u8, (rax as u8));
    /* 1400347e9 */ core::ptr::write((rcx).wrapping_add(0x35_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 1400347f3 */ let mut t_1400347f3_0: u32 = 0x0_u32;
    /* 1400347f3 */ r9 = (t_1400347f3_0 as u64);
    /* 1400347f6 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 1400347fa */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140034801 */ rcx = rbx;
    /* 140034804 */ fn_1400d1090();
    /* 14003480a */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 14003480e */ fn_140027900();
    /* 140034813 */ let mut t_140034813: u8 = core::ptr::read((rbx).wrapping_add(0x6b1_u64) as *const u8);
    if (t_140034813 == 0x0_u8) {
        /* -> bb1018 */
    } else {
        /* -> bb1017 */
    }

    // ---- bb1017 @ 0x14003481a ----
    if (t_140034813 == 0x0_u8) {
        /* -> bb1018 */
    } else {
        /* -> bb1067 */
    }

    // ---- bb1018 @ 0x140034820 ----
    /* 140034820 */ core::ptr::write((rbx).wrapping_add(0x6b1_u64) as *mut u8, 0x1_u8);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003482a */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140034831 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034836 */ rcx = (0x20_u32 as u64);
    /* 14003483b */ fn_1400285e0();
    /* 140034840 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140034844 */ xmm0 = core::ptr::read((0x14003484c_u64).wrapping_add(0x2cebd4_u64) as *const u128);
    /* 14003484c */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140034851 */ xmm0 = core::ptr::read((0x140034858_u64).wrapping_add(0x2cf5b8_u64) as *const u128);
    /* 140034858 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 14003485b */ let mut t_14003485b: u32 = core::ptr::read((0x140034861_u64).wrapping_add(0x2cf5bf_u64) as *const u32);
    /* 14003485b */ rcx = (t_14003485b as u64);
    /* 140034861 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u32, (rcx as u32));
    /* 140034864 */ core::ptr::write((rax).wrapping_add(0x14_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 14003486e */ let mut t_14003486e_0: u32 = 0x0_u32;
    /* 14003486e */ r9 = (t_14003486e_0 as u64);
    /* 140034871 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140034875 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 14003487c */ rcx = rbx;
    /* 14003487f */ fn_1400d1090();
    /* 140034885 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140034889 */ fn_140027900();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034891 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140034898 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 14003489d */ rcx = (0x30_u32 as u64);
    /* 1400348a2 */ fn_1400285e0();
    /* 1400348a7 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 1400348ab */ xmm0 = core::ptr::read((0x1400348b3_u64).wrapping_add(0x2cf8bd_u64) as *const u128);
    /* 1400348b3 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 1400348b8 */ xmm0 = core::ptr::read((0x1400348bf_u64).wrapping_add(0x2cf569_u64) as *const u128);
    /* 1400348bf */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400348c2 */ xmm1 = core::ptr::read((0x1400348c9_u64).wrapping_add(0x2cf56f_u64) as *const u128);
    /* 1400348c9 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 1400348cd */ let mut t_1400348cd: u16 = core::ptr::read((0x1400348d4_u64).wrapping_add(0x2cf574_u64) as *const u16);
    /* 1400348cd */ rcx = ((t_1400348cd as u32) as u64);
    /* 1400348d4 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u16, (rcx as u16));
    /* 1400348d8 */ core::ptr::write((rax).wrapping_add(0x22_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 1400348e2 */ let mut t_1400348e2_0: u32 = 0x0_u32;
    /* 1400348e2 */ r9 = (t_1400348e2_0 as u64);
    /* 1400348e5 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 1400348e9 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 1400348f0 */ rcx = rbx;
    /* 1400348f3 */ fn_1400d1090();
    /* 1400348f9 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 1400348fd */ fn_140027900();
    /* fallthrough -> bb1067 */

    // ---- bb1067 @ 0x140034902 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034905 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    /* 140034909 */ xmm1 = core::ptr::read((0x140034911_u64).wrapping_add(0x2ceabf_u64) as *const u128);
    /* 140034911 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034916 */ let mut t_140034916: u32 = core::ptr::read((0x14003491c_u64).wrapping_add(0x2cf530_u64) as *const u32);
    /* 140034916 */ rax = (t_140034916 as u64);
    /* 14003491c */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u32, (rax as u32));
    /* 14003491f */ let mut t_14003491f: u16 = core::ptr::read((0x140034926_u64).wrapping_add(0x2cf52a_u64) as *const u16);
    /* 14003491f */ rax = ((t_14003491f as u32) as u64);
    /* 140034926 */ core::ptr::write((rbp).wrapping_sub(0xd_u64) as *mut u16, (rax as u16));
    /* 14003492a */ core::ptr::write((rbp).wrapping_sub(0xb_u64) as *mut u8, 0x0_u8);
    /* 14003492e */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 140034932 */ fn_140037710();
    /* 140034938 */ r8 = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb1084 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb1083 */ }

    // ---- bb1083 @ 0x140034940 ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb1084 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb1087 */ }

    // ---- bb1084 @ 0x140034942 ----
    /* 140034942 */ rdx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140034946 */ rcx = (rbp).wrapping_sub(0x11_u64);
    /* 14003494a */ fn_140028310();
    /* fallthrough -> bb1087 */

    // ---- bb1087 @ 0x14003494f ----
    /* 14003494f */ rax = core::ptr::read((rbx).wrapping_add(0x60_u64) as *const u64);
    /* 140034953 */ core::ptr::write((rax).wrapping_add(0x405_u64) as *mut u8, 0x0_u8);
    /* 14003495a */ rax = core::ptr::read((rbx).wrapping_add(0x60_u64) as *const u64);
    /* 14003495e */ core::ptr::write((rax).wrapping_add(0x46d_u64) as *mut u8, 0x0_u8);
    /* 140034965 */ rax = core::ptr::read((rbx).wrapping_add(0x60_u64) as *const u64);
    /* 140034969 */ core::ptr::write((rax).wrapping_add(0x4d5_u64) as *mut u8, 0x0_u8);
    /* 140034970 */ rax = core::ptr::read((rbx).wrapping_add(0x60_u64) as *const u64);
    /* 140034974 */ core::ptr::write((rax).wrapping_add(0x53d_u64) as *mut u8, 0x0_u8);
    /* 14003497b */ core::ptr::write((rbx).wrapping_add(0x27c_u64) as *mut u64, 0x0_u64);
    /* fallthrough -> bb1301 */

    // ---- bb1097 @ 0x14003498b ----
    /* 14003498b */ rcx = rbx;
    /* 14003498e */ fn_140032f90();
    /* fallthrough -> bb1301 */

    // ---- bb1100 @ 0x140034998 ----
    if ((rcx as u32) == 0x4_u32) {
        /* -> bb1104 */
    } else {
        /* -> bb1103 */
    }

    // ---- bb1103 @ 0x14003499b ----
    if ((rcx as u32) == 0x4_u32) {
        /* -> bb1104 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb1104 @ 0x1400349a1 ----
    /* 1400349a1 */ r15 = (rbx).wrapping_add(0x690_u64);
    /* 1400349a8 */ let mut t_1400349a8: u32 = core::ptr::read(r15 as *const u32);
    /* 1400349a8 */ r13 = (t_1400349a8 as u64);
    /* 1400349ab */ let mut t_1400349ab_0: u32 = ((r13 as u32)).wrapping_add(0xfffffff8_u32);
    /* 1400349ab */ r13 = (t_1400349ab_0 as u64);
    if (SF == false) { /* -> bb1108 */ }
    if SF { /* -> bb1109 */ }

    // ---- bb1109 @ 0x1400349af ----
    /* 1400349af */ r13 = ((r12 as u32) as u64);
    /* fallthrough -> bb1108 */

    // ---- bb1108 @ 0x1400349b3 ----
    /* 1400349b3 */ core::ptr::write(r15 as *mut u32, (r13 as u32));
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400349b9 */ core::ptr::write((rbp).wrapping_sub(0x29_u64) as *mut u128, xmm0);
    /* 1400349be */ core::ptr::write((rbp).wrapping_sub(0x19_u64) as *mut u64, r12);
    /* 1400349c2 */ r12 = (rbx).wrapping_add(0x678_u64);
    /* 1400349c9 */ rcx = core::ptr::read((r12).wrapping_add(0x8_u64) as *const u64);
    /* 1400349ce */ let mut t_1400349ce: u64 = core::ptr::read(r12 as *const u64);
    /* 1400349ce */ let mut t_1400349ce_0: u64 = (rcx).wrapping_sub(t_1400349ce);
    /* 1400349ce */ rcx = t_1400349ce_0;
    /* 1400349d2 */ r11 = 0x2aaaaaaaaaaaaaab_u64;
    /* 1400349dc */ rax = r11;
    /* 1400349df */ let mut t_1400349df_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 1400349df */ rdx = ((t_1400349df_0 >> 0x40_u128) as u64);
    /* 1400349df */ rax = (t_1400349df_0 as u64);
    /* 1400349e2 */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 1400349e5 */ rax = rdx;
    /* 1400349e8 */ rax = (rax >> (0x3f_u8 as u64));
    /* 1400349ec */ let mut t_1400349ec_0: u64 = (rdx).wrapping_add(rax);
    /* 1400349ec */ rdx = t_1400349ec_0;
    /* 1400349ef */ r14 = r12;
    if ((rcx as u32) != 0x4_u32) {
        /* -> bb1128 */
    } else {
        /* -> bb1127 */
    }

    // ---- bb1127 @ 0x1400349f2 ----
    if ((rcx as u32) != 0x4_u32) {
        /* -> bb1128 */
    } else {
        /* -> bb1168 */
    }

    // ---- bb1128 @ 0x1400349f8 ----
    /* 1400349f8 */ rax = 0x1555555555555555_u64;
    if (((CF == false) & (rdx != rax)) == false) { /* -> bb1133 */ }
    if (((CF == false) & (rdx != rax)) != 0) { /* -> bb1132 */ }

    // ---- bb1132 @ 0x140034a05 ----
    if (((CF == false) & (rdx != rax)) == false) { /* -> bb1133 */ }
    if (((CF == false) & (rdx != rax)) != 0) { /* -> bb1733 */ }

    // ---- bb1133 @ 0x140034a0b ----
    /* 140034a0b */ rsi = (rdx).wrapping_add((rdx).wrapping_mul(0x2_u64));
    /* 140034a0f */ rsi = (rsi << (0x2_u8 as u64));
    /* 140034a13 */ rcx = rsi;
    /* 140034a16 */ fn_1400285e0();
    /* 140034a1b */ rdi = rax;
    /* 140034a1e */ r8 = core::ptr::read((rbp).wrapping_sub(0x21_u64) as *const u64);
    /* 140034a22 */ rdx = core::ptr::read((rbp).wrapping_sub(0x29_u64) as *const u64);
    /* 140034a26 */ let mut t_140034a26_0: u64 = (r8).wrapping_sub(rdx);
    /* 140034a26 */ r8 = t_140034a26_0;
    /* 140034a29 */ rcx = rax;
    /* 140034a2c */ fn_1402f9230();
    /* 140034a31 */ r9 = core::ptr::read((rbp).wrapping_sub(0x29_u64) as *const u64);
    if (rdx != rax) {
        /* -> bb1148 */
    } else {
        /* -> bb1147 */
    }

    // ---- bb1147 @ 0x140034a38 ----
    if (rdx != rax) {
        /* -> bb1148 */
    } else {
        /* -> bb1161 */
    }

    // ---- bb1148 @ 0x140034a3a ----
    /* 140034a3a */ rcx = core::ptr::read((rbp).wrapping_sub(0x19_u64) as *const u64);
    /* 140034a3e */ let mut t_140034a3e_0: u64 = (rcx).wrapping_sub(r9);
    /* 140034a3e */ rcx = t_140034a3e_0;
    /* 140034a41 */ rax = 0x2aaaaaaaaaaaaaab_u64;
    /* 140034a4b */ let mut t_140034a4b_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 140034a4b */ rdx = ((t_140034a4b_0 >> 0x40_u128) as u64);
    /* 140034a4b */ rax = (t_140034a4b_0 as u64);
    /* 140034a4e */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 140034a51 */ r8 = rdx;
    /* 140034a54 */ r8 = (r8 >> (0x3f_u8 as u64));
    /* 140034a58 */ let mut t_140034a58_0: u64 = (r8).wrapping_add(rdx);
    /* 140034a58 */ r8 = t_140034a58_0;
    /* 140034a5b */ rdx = r9;
    /* 140034a5e */ rcx = (rbp).wrapping_sub(0x29_u64);
    /* 140034a62 */ fn_1400374f0();
    /* 140034a67 */ r14 = (rbx).wrapping_add(0x678_u64);
    /* 140034a6e */ r15 = (rbx).wrapping_add(0x690_u64);
    /* fallthrough -> bb1161 */

    // ---- bb1161 @ 0x140034a75 ----
    /* 140034a75 */ core::ptr::write((rbp).wrapping_sub(0x29_u64) as *mut u64, rdi);
    /* 140034a79 */ r9 = rdi;
    /* 140034a7c */ core::ptr::write((rbp).wrapping_sub(0x21_u64) as *mut u64, rdi);
    /* 140034a80 */ rax = (rsi).wrapping_add((rdi).wrapping_mul(0x1_u64));
    /* 140034a84 */ core::ptr::write((rbp).wrapping_sub(0x19_u64) as *mut u64, rax);
    /* 140034a88 */ r11 = 0x2aaaaaaaaaaaaaab_u64;
    /* fallthrough -> bb1170 */

    // ---- bb1168 @ 0x140034a94 ----
    /* 140034a94 */ r9 = core::ptr::read((rbp).wrapping_sub(0x21_u64) as *const u64);
    /* 140034a98 */ rdi = core::ptr::read((rbp).wrapping_sub(0x29_u64) as *const u64);
    /* fallthrough -> bb1170 */

    // ---- bb1170 @ 0x140034a9c ----
    /* 140034a9c */ let mut t_140034a9c_0: u32 = 0x0_u32;
    /* 140034a9c */ r10 = (t_140034a9c_0 as u64);
    /* 140034a9f */ rsi = ((r10 as u32) as u64);
    /* 140034aa2 */ r8 = core::ptr::read(r12 as *const u64);
    /* 140034aa6 */ rcx = core::ptr::read((r12).wrapping_add(0x8_u64) as *const u64);
    /* 140034aab */ let mut t_140034aab_0: u64 = (rcx).wrapping_sub(r8);
    /* 140034aab */ rcx = t_140034aab_0;
    /* 140034aae */ rax = r11;
    /* 140034ab1 */ let mut t_140034ab1_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 140034ab1 */ rdx = ((t_140034ab1_0 >> 0x40_u128) as u64);
    /* 140034ab1 */ rax = (t_140034ab1_0 as u64);
    /* 140034ab4 */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 140034ab7 */ rcx = rdx;
    /* 140034aba */ rcx = (rcx >> (0x3f_u8 as u64));
    /* 140034abe */ let mut t_140034abe_0: u64 = (rdx).wrapping_add(rcx);
    /* 140034abe */ rdx = t_140034abe_0;
    if ((rcx as u32) != 0x4_u32) {
        /* -> bb1184 */
    } else {
        /* -> bb1183 */
    }

    // ---- bb1183 @ 0x140034ac1 ----
    if ((rcx as u32) != 0x4_u32) {
        /* -> bb1184 */
    } else {
        /* -> bb1239 */
    }

    // ---- bb1184 @ 0x140034ac7 ----
    /* 140034ac7 */ rax = ((r13 as u32) as u64);
    /* 140034aca */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140034acb */ let mut t_140034acb_0: u32 = ((rdx as u32) & 0x1f_u32);
    /* 140034acb */ rdx = (t_140034acb_0 as u64);
    /* 140034ace */ let mut t_140034ace_0: u32 = ((rax as u32)).wrapping_add((rdx as u32));
    /* 140034ace */ rax = (t_140034ace_0 as u64);
    /* 140034ad0 */ rax = (((((rax as u32) as i64) >> ((0x5_u8 as u32) as i64)) as u64) as u64);
    /* 140034ad3 */ r15 = (0x20_u32 as u64);
    /* 140034ad9 */ let mut t_140034ad9_0: u32 = ((r15 as u32)).wrapping_sub((rax as u32));
    /* 140034ad9 */ r15 = (t_140034ad9_0 as u64);
    /* 140034adc */ rdi = ((r10 as u32) as u64);
    /* fallthrough -> bb1193 */

    // ---- bb1193 @ 0x140034ae0 ----
    /* 140034ae0 */ let mut t_140034ae0_0: u64 = (r8).wrapping_add(rdi);
    /* 140034ae0 */ r8 = t_140034ae0_0;
    /* 140034ae3 */ let mut t_140034ae3: u32 = core::ptr::read((r8).wrapping_add(0x4_u64) as *const u32);
    if (SF == OF) {
        /* -> bb1198 */
    } else {
        /* -> bb1197 */
    }

    // ---- bb1197 @ 0x140034ae7 ----
    if (SF == OF) {
        /* -> bb1198 */
    } else {
        /* -> bb1221 */
    }

    // ---- bb1198 @ 0x140034ae9 ----
    /* 140034ae9 */ let mut t_140034ae9: u64 = core::ptr::read((rbp).wrapping_sub(0x19_u64) as *const u64);
    if (r9 != t_140034ae9) {
        /* -> bb1202 */
    } else {
        /* -> bb1201 */
    }

    // ---- bb1201 @ 0x140034aed ----
    if (r9 != t_140034ae9) {
        /* -> bb1202 */
    } else {
        /* -> bb1216 */
    }

    // ---- bb1202 @ 0x140034aef ----
    /* 140034aef */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1203 */ }
    if DF { /* -> bb1204 */ }

    // ---- bb1203 @ 0x140034aef ----
    /* 140034aef */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140034aef */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1205 */

    // ---- bb1204 @ 0x140034aef ----
    /* 140034aef */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140034aef */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1205 */

    // ---- bb1205 @ 0x140034af4 ----
    /* 140034af4 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1207 */ }
    if DF { /* -> bb1208 */ }

    // ---- bb1207 @ 0x140034af4 ----
    /* 140034af4 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140034af4 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1209 */

    // ---- bb1208 @ 0x140034af4 ----
    /* 140034af4 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140034af4 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1209 */

    // ---- bb1209 @ 0x140034af9 ----
    /* 140034af9 */ let mut t_140034af9: u32 = core::ptr::read((r8).wrapping_add(0x8_u64) as *const u32);
    /* 140034af9 */ rax = (t_140034af9 as u64);
    /* 140034afd */ core::ptr::write((r9).wrapping_add(0x8_u64) as *mut u32, (rax as u32));
    /* 140034b01 */ r9 = core::ptr::read((rbp).wrapping_sub(0x21_u64) as *const u64);
    /* 140034b05 */ let mut t_140034b05_0: u64 = (r9).wrapping_add(0xc_u64);
    /* 140034b05 */ r9 = t_140034b05_0;
    /* 140034b09 */ core::ptr::write((rbp).wrapping_sub(0x21_u64) as *mut u64, r9);
    /* fallthrough -> bb1221 */

    // ---- bb1216 @ 0x140034b0f ----
    /* 140034b0f */ rdx = r9;
    /* 140034b12 */ rcx = (rbp).wrapping_sub(0x29_u64);
    /* 140034b16 */ fn_140036850();
    /* 140034b1b */ r9 = core::ptr::read((rbp).wrapping_sub(0x21_u64) as *const u64);
    /* 140034b1f */ r11 = 0x2aaaaaaaaaaaaaab_u64;
    /* fallthrough -> bb1221 */

    // ---- bb1221 @ 0x140034b29 ----
    /* 140034b29 */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    /* 140034b2b */ let mut t_140034b2b_0: u64 = (rdi).wrapping_add(0xc_u64);
    /* 140034b2b */ rdi = t_140034b2b_0;
    /* 140034b2f */ r8 = core::ptr::read(r14 as *const u64);
    /* 140034b32 */ rcx = core::ptr::read((r14).wrapping_add(0x8_u64) as *const u64);
    /* 140034b36 */ let mut t_140034b36_0: u64 = (rcx).wrapping_sub(r8);
    /* 140034b36 */ rcx = t_140034b36_0;
    /* 140034b39 */ rax = r11;
    /* 140034b3c */ let mut t_140034b3c_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 140034b3c */ rdx = ((t_140034b3c_0 >> 0x40_u128) as u64);
    /* 140034b3c */ rax = (t_140034b3c_0 as u64);
    /* 140034b3f */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 140034b42 */ rax = rdx;
    /* 140034b45 */ rax = (rax >> (0x3f_u8 as u64));
    /* 140034b49 */ let mut t_140034b49_0: u64 = (rdx).wrapping_add(rax);
    /* 140034b49 */ rdx = t_140034b49_0;
    /* 140034b4c */ rax = (((rsi as u32) as i64) as u64);
    if (CF == false) { /* -> bb1237 */ }
    if CF { /* -> bb1236 */ }

    // ---- bb1236 @ 0x140034b52 ----
    if CF { /* -> bb1193 */ }
    if (CF == false) { /* -> bb1237 */ }

    // ---- bb1237 @ 0x140034b54 ----
    /* 140034b54 */ r15 = (rbx).wrapping_add(0x690_u64);
    /* 140034b5b */ rdi = core::ptr::read((rbp).wrapping_sub(0x29_u64) as *const u64);
    /* fallthrough -> bb1239 */

    // ---- bb1239 @ 0x140034b5f ----
    /* 140034b5f */ rax = (rbp).wrapping_sub(0x29_u64);
    if (r12 != rax) {
        /* -> bb1244 */
    } else {
        /* -> bb1243 */
    }

    // ---- bb1243 @ 0x140034b66 ----
    if (r12 != rax) {
        /* -> bb1244 */
    } else {
        /* -> bb1256 */
    }

    // ---- bb1244 @ 0x140034b68 ----
    /* 140034b68 */ let mut t_140034b68_0: u64 = (r9).wrapping_sub(rdi);
    /* 140034b68 */ r9 = t_140034b68_0;
    /* 140034b6b */ rax = r11;
    /* 140034b6e */ let mut t_140034b6e_0: u128 = ((rax as u128)).wrapping_mul((r9 as u128));
    /* 140034b6e */ rdx = ((t_140034b6e_0 >> 0x40_u128) as u64);
    /* 140034b6e */ rax = (t_140034b6e_0 as u64);
    /* 140034b71 */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 140034b74 */ r8 = rdx;
    /* 140034b77 */ r8 = (r8 >> (0x3f_u8 as u64));
    /* 140034b7b */ let mut t_140034b7b_0: u64 = (r8).wrapping_add(rdx);
    /* 140034b7b */ r8 = t_140034b7b_0;
    /* 140034b7e */ rdx = rdi;
    /* 140034b81 */ rcx = r12;
    /* 140034b84 */ fn_1400366e0();
    /* 140034b89 */ rdi = core::ptr::read((rbp).wrapping_sub(0x29_u64) as *const u64);
    /* 140034b8d */ r11 = 0x2aaaaaaaaaaaaaab_u64;
    /* fallthrough -> bb1256 */

    // ---- bb1256 @ 0x140034b97 ----
    /* 140034b97 */ let mut t_140034b97: u32 = core::ptr::read(r15 as *const u32);
    if (t_140034b97 == 0x0_u32) {
        /* -> bb1260 */
    } else {
        /* -> bb1259 */
    }

    // ---- bb1259 @ 0x140034b9b ----
    if (t_140034b97 == 0x0_u32) {
        /* -> bb1260 */
    } else {
        /* -> bb1271 */
    }

    // ---- bb1260 @ 0x140034b9d ----
    /* 140034b9d */ rcx = (rbx).wrapping_add(0x2b9_u64);
    /* 140034ba4 */ rax = (0xf0_u32 as u64);
    /* fallthrough -> bb1263 */

    // ---- bb1263 @ 0x140034bb0 ----
    /* 140034bb0 */ core::ptr::write((rcx).wrapping_sub(0x1_u64) as *mut u32, 0x0_u32);
    /* 140034bb7 */ rcx = (rcx).wrapping_add(0x4_u64);
    /* 140034bbb */ let mut t_140034bbb_0: u64 = (rax).wrapping_sub(0x1_u64);
    /* 140034bbb */ rax = t_140034bbb_0;
    if (t_140034b97 == 0x0_u32) {
        /* -> bb1269 */
    } else {
        /* -> bb1268 */
    }

    // ---- bb1268 @ 0x140034bbf ----
    if (t_140034b97 != 0x0_u32) {
        /* -> bb1263 */
    } else {
        /* -> bb1269 */
    }

    // ---- bb1269 @ 0x140034bc1 ----
    /* 140034bc1 */ core::ptr::write((rbx).wrapping_add(0x250_u64) as *mut u32, 0x3_u32);
    /* 140034bcb */ core::ptr::write((rbx).wrapping_add(0x254_u64) as *mut u32, 0x258_u32);
    /* fallthrough -> bb1271 */

    // ---- bb1271 @ 0x140034bd5 ----
    if (t_140034b97 != 0x0_u32) {
        /* -> bb1275 */
    } else {
        /* -> bb1274 */
    }

    // ---- bb1274 @ 0x140034bd8 ----
    if (t_140034b97 != 0x0_u32) {
        /* -> bb1275 */
    } else {
        /* -> bb1300 */
    }

    // ---- bb1275 @ 0x140034bda ----
    /* 140034bda */ rcx = core::ptr::read((rbp).wrapping_sub(0x19_u64) as *const u64);
    /* 140034bde */ let mut t_140034bde_0: u64 = (rcx).wrapping_sub(rdi);
    /* 140034bde */ rcx = t_140034bde_0;
    /* 140034be1 */ rax = r11;
    /* 140034be4 */ let mut t_140034be4_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 140034be4 */ rdx = ((t_140034be4_0 >> 0x40_u128) as u64);
    /* 140034be4 */ rax = (t_140034be4_0 as u64);
    /* 140034be7 */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 140034bea */ rax = rdx;
    /* 140034bed */ rax = (rax >> (0x3f_u8 as u64));
    /* 140034bf1 */ let mut t_140034bf1_0: u64 = (rdx).wrapping_add(rax);
    /* 140034bf1 */ rdx = t_140034bf1_0;
    /* 140034bf4 */ rdx = (rdx).wrapping_add((rdx).wrapping_mul(0x2_u64));
    /* 140034bf8 */ rdx = (rdx << (0x2_u8 as u64));
    /* 140034bfc */ rax = rdi;
    if (CF == false) { /* -> bb1290 */ }
    if CF { /* -> bb1289 */ }

    // ---- bb1289 @ 0x140034c06 ----
    if (CF == false) { /* -> bb1290 */ }
    if CF { /* -> bb1298 */ }

    // ---- bb1290 @ 0x140034c08 ----
    /* 140034c08 */ let mut t_140034c08_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140034c08 */ rdx = t_140034c08_0;
    /* 140034c0c */ rdi = core::ptr::read((rdi).wrapping_sub(0x8_u64) as *const u64);
    /* 140034c10 */ let mut t_140034c10_0: u64 = (rax).wrapping_sub(rdi);
    /* 140034c10 */ rax = t_140034c10_0;
    /* 140034c13 */ let mut t_140034c13_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140034c13 */ rax = t_140034c13_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1298 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1297 */ }

    // ---- bb1297 @ 0x140034c1b ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1298 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1735 */ }

    // ---- bb1298 @ 0x140034c21 ----
    /* 140034c21 */ rcx = rdi;
    /* 140034c24 */ fn_1402c7498();
    /* fallthrough -> bb1300 */

    // ---- bb1300 @ 0x140034c29 ----
    /* 140034c29 */ let mut t_140034c29_0: u32 = 0x0_u32;
    /* 140034c29 */ r12 = (t_140034c29_0 as u64);
    /* fallthrough -> bb1301 */

    // ---- bb1301 @ 0x140034c2c ----
    /* 140034c2c */ let mut t_140034c2c: u32 = core::ptr::read((rbx).wrapping_add(0xd8_u64) as *const u32);
    /* 140034c2c */ rax = (t_140034c2c as u64);
    if ((rax as u32) != 0x7_u32) {
        /* -> bb1306 */
    } else {
        /* -> bb1305 */
    }

    // ---- bb1305 @ 0x140034c35 ----
    if ((rax as u32) != 0x7_u32) {
        /* -> bb1306 */
    } else {
        /* -> bb1310 */
    }

    // ---- bb1306 @ 0x140034c37 ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb1310 */
    } else {
        /* -> bb1309 */
    }

    // ---- bb1309 @ 0x140034c3a ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb1310 */
    } else {
        /* -> bb1320 */
    }

    // ---- bb1310 @ 0x140034c3c ----
    /* 140034c3c */ let mut t_140034c3c: u32 = core::ptr::read((rbx).wrapping_add(0x250_u64) as *const u32);
    if (t_140034c3c == 0x3_u32) {
        /* -> bb1314 */
    } else {
        /* -> bb1313 */
    }

    // ---- bb1313 @ 0x140034c43 ----
    if (t_140034c3c == 0x3_u32) {
        /* -> bb1314 */
    } else {
        /* -> bb1319 */
    }

    // ---- bb1314 @ 0x140034c45 ----
    /* 140034c45 */ let mut t_140034c45: u32 = core::ptr::read((rbx).wrapping_add(0x27c_u64) as *const u32);
    if (t_140034c45 == 0x0_u32) {
        /* -> bb1318 */
    } else {
        /* -> bb1317 */
    }

    // ---- bb1317 @ 0x140034c4c ----
    if (t_140034c45 == 0x0_u32) {
        /* -> bb1318 */
    } else {
        /* -> bb1319 */
    }

    // ---- bb1318 @ 0x140034c4e ----
    /* 140034c4e */ core::ptr::write((rbx).wrapping_add(0x124_u64) as *mut u32, 0x9_u32);
    /* fallthrough -> bb1319 */

    // ---- bb1319 @ 0x140034c58 ----
    /* fallthrough -> bb1320 */

    // ---- bb1320 @ 0x140034c5b ----
    if (((SF != OF) | ((rax as u32) == 0x8_u32)) == false) { /* -> bb1323 */ }
    if (((SF != OF) | ((rax as u32) == 0x8_u32)) != 0) { /* -> bb1322 */ }

    // ---- bb1322 @ 0x140034c5b ----
    if (((SF != OF) | ((rax as u32) == 0x8_u32)) == false) { /* -> bb1323 */ }
    if (((SF != OF) | ((rax as u32) == 0x8_u32)) != 0) { /* -> bb1324 */ }

    // ---- bb1323 @ 0x140034c5d ----
    /* 140034c5d */ core::ptr::write((rbx).wrapping_add(0x124_u64) as *mut u32, 0x4_u32);
    /* fallthrough -> bb1324 */

    // ---- bb1324 @ 0x140034c67 ----
    /* 140034c67 */ rdi = (rbx).wrapping_add(0xe0_u64);
    /* 140034c6e */ let mut t_140034c6e: u32 = core::ptr::read((rbx).wrapping_add(0xe0_u64) as *const u32);
    if (t_140034c6e == 0x9_u32) {
        /* -> bb1329 */
    } else {
        /* -> bb1328 */
    }

    // ---- bb1328 @ 0x140034c75 ----
    if (t_140034c6e == 0x9_u32) {
        /* -> bb1329 */
    } else {
        /* -> bb1376 */
    }

    // ---- bb1329 @ 0x140034c7b ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034c7e */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140034c85 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034c8a */ rcx = (0x20_u32 as u64);
    /* 140034c8f */ fn_1400285e0();
    /* 140034c94 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140034c98 */ xmm0 = core::ptr::read((0x140034ca0_u64).wrapping_add(0x2cf460_u64) as *const u128);
    /* 140034ca0 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140034ca5 */ xmm0 = core::ptr::read((0x140034cac_u64).wrapping_add(0x2cf1ac_u64) as *const u128);
    /* 140034cac */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140034caf */ let mut t_140034caf: u16 = core::ptr::read((0x140034cb6_u64).wrapping_add(0x2cf1b2_u64) as *const u16);
    /* 140034caf */ rcx = ((t_140034caf as u32) as u64);
    /* 140034cb6 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u16, (rcx as u16));
    /* 140034cba */ let mut t_140034cba: u8 = core::ptr::read((0x140034cc1_u64).wrapping_add(0x2cf1a9_u64) as *const u8);
    /* 140034cba */ rcx = ((t_140034cba as u32) as u64);
    /* 140034cc1 */ core::ptr::write((rax).wrapping_add(0x12_u64) as *mut u8, (rcx as u8));
    /* 140034cc4 */ core::ptr::write((rax).wrapping_add(0x13_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140034cce */ let mut t_140034cce_0: u32 = 0x0_u32;
    /* 140034cce */ r9 = (t_140034cce_0 as u64);
    /* 140034cd1 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140034cd5 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140034cdc */ rcx = rbx;
    /* 140034cdf */ fn_1400d1090();
    /* 140034ce5 */ rdi = (rbx).wrapping_add(0xe0_u64);
    /* 140034cec */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1358 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1357 */ }

    // ---- bb1357 @ 0x140034cf4 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1358 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1376 */ }

    // ---- bb1358 @ 0x140034cf6 ----
    /* 140034cf6 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140034cf9 */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140034cfd */ rax = rcx;
    /* 140034d00 */ rdi = (rbx).wrapping_add(0xe0_u64);
    if (CF == false) { /* -> bb1366 */ }
    if CF { /* -> bb1365 */ }

    // ---- bb1365 @ 0x140034d0e ----
    if (CF == false) { /* -> bb1366 */ }
    if CF { /* -> bb1375 */ }

    // ---- bb1366 @ 0x140034d10 ----
    /* 140034d10 */ let mut t_140034d10_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140034d10 */ rdx = t_140034d10_0;
    /* 140034d14 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140034d18 */ let mut t_140034d18_0: u64 = (rax).wrapping_sub(rcx);
    /* 140034d18 */ rax = t_140034d18_0;
    /* 140034d1b */ let mut t_140034d1b_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140034d1b */ rax = t_140034d1b_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1374 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1373 */ }

    // ---- bb1373 @ 0x140034d23 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1374 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1750 */ }

    // ---- bb1374 @ 0x140034d29 ----
    /* 140034d29 */ rdi = (rbx).wrapping_add(0xe0_u64);
    /* fallthrough -> bb1375 */

    // ---- bb1375 @ 0x140034d30 ----
    /* 140034d30 */ fn_1402c7498();
    /* fallthrough -> bb1376 */

    // ---- bb1376 @ 0x140034d35 ----
    /* 140034d35 */ rsi = rdi;
    /* 140034d38 */ let mut t_140034d38: u32 = core::ptr::read((rbx).wrapping_add(0xe0_u64) as *const u32);
    if (t_140034d38 == 0xa_u32) {
        /* -> bb1381 */
    } else {
        /* -> bb1380 */
    }

    // ---- bb1380 @ 0x140034d3f ----
    if (t_140034d38 == 0xa_u32) {
        /* -> bb1381 */
    } else {
        /* -> bb1432 */
    }

    // ---- bb1381 @ 0x140034d45 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034d48 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140034d4f */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034d54 */ rcx = (0x20_u32 as u64);
    /* 140034d59 */ fn_1400285e0();
    /* 140034d5e */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140034d62 */ xmm0 = core::ptr::read((0x140034d6a_u64).wrapping_add(0x2ce9f6_u64) as *const u128);
    /* 140034d6a */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140034d6f */ xmm0 = core::ptr::read((0x140034d76_u64).wrapping_add(0x2cf0fa_u64) as *const u128);
    /* 140034d76 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140034d79 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1393 */ }
    if DF { /* -> bb1394 */ }

    // ---- bb1393 @ 0x140034d79 ----
    /* 140034d79 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140034d79 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1395 */

    // ---- bb1394 @ 0x140034d79 ----
    /* 140034d79 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140034d79 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1395 */

    // ---- bb1395 @ 0x140034d81 ----
    /* 140034d81 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1397 */ }
    if DF { /* -> bb1398 */ }

    // ---- bb1397 @ 0x140034d81 ----
    /* 140034d81 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140034d81 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1399 */

    // ---- bb1398 @ 0x140034d81 ----
    /* 140034d81 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140034d81 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1399 */

    // ---- bb1399 @ 0x140034d86 ----
    /* 140034d86 */ let mut t_140034d86: u8 = core::ptr::read((0x140034d8d_u64).wrapping_add(0x2cf0fb_u64) as *const u8);
    /* 140034d86 */ rcx = ((t_140034d86 as u32) as u64);
    /* 140034d8d */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u8, (rcx as u8));
    /* 140034d90 */ core::ptr::write((rax).wrapping_add(0x19_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140034d9a */ let mut t_140034d9a_0: u32 = 0x0_u32;
    /* 140034d9a */ r9 = (t_140034d9a_0 as u64);
    /* 140034d9d */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140034da1 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140034da8 */ rcx = rbx;
    /* 140034dab */ fn_1400d1090();
    /* 140034db1 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1415 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1414 */ }

    // ---- bb1414 @ 0x140034db9 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1415 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1432 */ }

    // ---- bb1415 @ 0x140034dbb ----
    /* 140034dbb */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140034dbe */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140034dc2 */ rax = rcx;
    if (CF == false) { /* -> bb1422 */ }
    if CF { /* -> bb1421 */ }

    // ---- bb1421 @ 0x140034dcc ----
    if (CF == false) { /* -> bb1422 */ }
    if CF { /* -> bb1431 */ }

    // ---- bb1422 @ 0x140034dce ----
    /* 140034dce */ let mut t_140034dce_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140034dce */ rdx = t_140034dce_0;
    /* 140034dd2 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140034dd6 */ let mut t_140034dd6_0: u64 = (rax).wrapping_sub(rcx);
    /* 140034dd6 */ rax = t_140034dd6_0;
    /* 140034dd9 */ let mut t_140034dd9_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140034dd9 */ rax = t_140034dd9_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1430 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1429 */ }

    // ---- bb1429 @ 0x140034de1 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1430 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1757 */ }

    // ---- bb1430 @ 0x140034de7 ----
    /* 140034de7 */ rsi = (rbx).wrapping_add(0xe0_u64);
    /* fallthrough -> bb1431 */

    // ---- bb1431 @ 0x140034dee ----
    /* 140034dee */ fn_1402c7498();
    /* fallthrough -> bb1432 */

    // ---- bb1432 @ 0x140034df3 ----
    /* 140034df3 */ r14 = rsi;
    /* 140034df6 */ let mut t_140034df6: u32 = core::ptr::read(rdi as *const u32);
    if (t_140034df6 == 0xb_u32) {
        /* -> bb1437 */
    } else {
        /* -> bb1436 */
    }

    // ---- bb1436 @ 0x140034df9 ----
    if (t_140034df6 == 0xb_u32) {
        /* -> bb1437 */
    } else {
        /* -> bb1493 */
    }

    // ---- bb1437 @ 0x140034dff ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034e02 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140034e09 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034e0e */ rcx = (0x20_u32 as u64);
    /* 140034e13 */ fn_1400285e0();
    /* 140034e18 */ rdx = rax;
    /* 140034e1b */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140034e1f */ xmm0 = core::ptr::read((0x140034e27_u64).wrapping_add(0x2cf319_u64) as *const u128);
    /* 140034e27 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140034e2c */ xmm0 = core::ptr::read((0x140034e33_u64).wrapping_add(0x2cf05d_u64) as *const u128);
    /* 140034e33 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140034e36 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1450 */ }
    if DF { /* -> bb1451 */ }

    // ---- bb1450 @ 0x140034e36 ----
    /* 140034e36 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140034e36 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1452 */

    // ---- bb1451 @ 0x140034e36 ----
    /* 140034e36 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140034e36 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1452 */

    // ---- bb1452 @ 0x140034e3e ----
    /* 140034e3e */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1454 */ }
    if DF { /* -> bb1455 */ }

    // ---- bb1454 @ 0x140034e3e ----
    /* 140034e3e */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140034e3e */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1456 */

    // ---- bb1455 @ 0x140034e3e ----
    /* 140034e3e */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140034e3e */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1456 */

    // ---- bb1456 @ 0x140034e43 ----
    /* 140034e43 */ let mut t_140034e43: u32 = core::ptr::read((0x140034e49_u64).wrapping_add(0x2cf05f_u64) as *const u32);
    /* 140034e43 */ rcx = (t_140034e43 as u64);
    /* 140034e49 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u32, (rcx as u32));
    /* 140034e4c */ let mut t_140034e4c: u16 = core::ptr::read((0x140034e53_u64).wrapping_add(0x2cf059_u64) as *const u16);
    /* 140034e4c */ rax = ((t_140034e4c as u32) as u64);
    /* 140034e53 */ core::ptr::write((rdx).wrapping_add(0x1c_u64) as *mut u16, (rax as u16));
    /* 140034e57 */ let mut t_140034e57: u8 = core::ptr::read((0x140034e5e_u64).wrapping_add(0x2cf050_u64) as *const u8);
    /* 140034e57 */ rax = ((t_140034e57 as u32) as u64);
    /* 140034e5e */ core::ptr::write((rdx).wrapping_add(0x1e_u64) as *mut u8, (rax as u8));
    /* 140034e61 */ core::ptr::write((rdx).wrapping_add(0x1f_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140034e6b */ let mut t_140034e6b_0: u32 = 0x0_u32;
    /* 140034e6b */ r9 = (t_140034e6b_0 as u64);
    /* 140034e6e */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140034e72 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140034e79 */ rcx = rbx;
    /* 140034e7c */ fn_1400d1090();
    /* 140034e82 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1476 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1475 */ }

    // ---- bb1475 @ 0x140034e8a ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1476 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1493 */ }

    // ---- bb1476 @ 0x140034e8c ----
    /* 140034e8c */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140034e8f */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140034e93 */ rax = rcx;
    if (CF == false) { /* -> bb1483 */ }
    if CF { /* -> bb1482 */ }

    // ---- bb1482 @ 0x140034e9d ----
    if (CF == false) { /* -> bb1483 */ }
    if CF { /* -> bb1492 */ }

    // ---- bb1483 @ 0x140034e9f ----
    /* 140034e9f */ let mut t_140034e9f_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140034e9f */ rdx = t_140034e9f_0;
    /* 140034ea3 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140034ea7 */ let mut t_140034ea7_0: u64 = (rax).wrapping_sub(rcx);
    /* 140034ea7 */ rax = t_140034ea7_0;
    /* 140034eaa */ let mut t_140034eaa_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140034eaa */ rax = t_140034eaa_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1491 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1490 */ }

    // ---- bb1490 @ 0x140034eb2 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1491 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1764 */ }

    // ---- bb1491 @ 0x140034eb8 ----
    /* 140034eb8 */ r14 = (rbx).wrapping_add(0xe0_u64);
    /* fallthrough -> bb1492 */

    // ---- bb1492 @ 0x140034ebf ----
    /* 140034ebf */ fn_1402c7498();
    /* fallthrough -> bb1493 */

    // ---- bb1493 @ 0x140034ec4 ----
    /* 140034ec4 */ let mut t_140034ec4: u32 = core::ptr::read(rsi as *const u32);
    if (t_140034ec4 == 0xc_u32) {
        /* -> bb1497 */
    } else {
        /* -> bb1496 */
    }

    // ---- bb1496 @ 0x140034ec7 ----
    if (t_140034ec4 == 0xc_u32) {
        /* -> bb1497 */
    } else {
        /* -> bb1541 */
    }

    // ---- bb1497 @ 0x140034ecd ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034ed0 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140034ed7 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034edc */ rcx = (0x40_u32 as u64);
    /* 140034ee1 */ fn_1400285e0();
    /* 140034ee6 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140034eea */ xmm0 = core::ptr::read((0x140034ef2_u64).wrapping_add(0x2cf2be_u64) as *const u128);
    /* 140034ef2 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140034ef7 */ xmm0 = core::ptr::read((0x140034efe_u64).wrapping_add(0x2cefb2_u64) as *const u128);
    /* 140034efe */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140034f01 */ xmm1 = core::ptr::read((0x140034f08_u64).wrapping_add(0x2cefb8_u64) as *const u128);
    /* 140034f08 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 140034f0c */ xmm0 = core::ptr::read((0x140034f13_u64).wrapping_add(0x2cefbd_u64) as *const u128);
    /* 140034f13 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u128, xmm0);
    /* 140034f17 */ core::ptr::write((rax).wrapping_add(0x30_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140034f21 */ let mut t_140034f21_0: u32 = 0x0_u32;
    /* 140034f21 */ r9 = (t_140034f21_0 as u64);
    /* 140034f24 */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140034f28 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140034f2f */ rcx = rbx;
    /* 140034f32 */ fn_1400d1090();
    /* 140034f38 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1525 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1524 */ }

    // ---- bb1524 @ 0x140034f40 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1525 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1541 */ }

    // ---- bb1525 @ 0x140034f42 ----
    /* 140034f42 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140034f45 */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140034f49 */ rax = rcx;
    if (CF == false) { /* -> bb1532 */ }
    if CF { /* -> bb1531 */ }

    // ---- bb1531 @ 0x140034f53 ----
    if (CF == false) { /* -> bb1532 */ }
    if CF { /* -> bb1540 */ }

    // ---- bb1532 @ 0x140034f55 ----
    /* 140034f55 */ let mut t_140034f55_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140034f55 */ rdx = t_140034f55_0;
    /* 140034f59 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140034f5d */ let mut t_140034f5d_0: u64 = (rax).wrapping_sub(rcx);
    /* 140034f5d */ rax = t_140034f5d_0;
    /* 140034f60 */ let mut t_140034f60_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140034f60 */ rax = t_140034f60_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1540 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1539 */ }

    // ---- bb1539 @ 0x140034f68 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1540 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1743 */ }

    // ---- bb1540 @ 0x140034f6e ----
    /* 140034f6e */ fn_1402c7498();
    /* fallthrough -> bb1541 */

    // ---- bb1541 @ 0x140034f73 ----
    /* 140034f73 */ let mut t_140034f73: u32 = core::ptr::read(r14 as *const u32);
    if (t_140034f73 == 0xd_u32) {
        /* -> bb1545 */
    } else {
        /* -> bb1544 */
    }

    // ---- bb1544 @ 0x140034f77 ----
    if (t_140034f73 == 0xd_u32) {
        /* -> bb1545 */
    } else {
        /* -> bb1651 */
    }

    // ---- bb1545 @ 0x140034f7d ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140034f80 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140034f87 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140034f8c */ rcx = (0x30_u32 as u64);
    /* 140034f91 */ fn_1400285e0();
    /* 140034f96 */ rcx = rax;
    /* 140034f99 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 140034f9d */ xmm0 = core::ptr::read((0x140034fa5_u64).wrapping_add(0x2cf1fb_u64) as *const u128);
    /* 140034fa5 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140034faa */ xmm0 = core::ptr::read((0x140034fb1_u64).wrapping_add(0x2cef37_u64) as *const u128);
    /* 140034fb1 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140034fb4 */ xmm1 = core::ptr::read((0x140034fbb_u64).wrapping_add(0x2cef3d_u64) as *const u128);
    /* 140034fbb */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 140034fbf */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1560 */ }
    if DF { /* -> bb1561 */ }

    // ---- bb1560 @ 0x140034fbf ----
    /* 140034fbf */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140034fbf */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1562 */

    // ---- bb1561 @ 0x140034fbf ----
    /* 140034fbf */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140034fbf */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1562 */

    // ---- bb1562 @ 0x140034fc7 ----
    /* 140034fc7 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1564 */ }
    if DF { /* -> bb1565 */ }

    // ---- bb1564 @ 0x140034fc7 ----
    /* 140034fc7 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140034fc7 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1566 */

    // ---- bb1565 @ 0x140034fc7 ----
    /* 140034fc7 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140034fc7 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1566 */

    // ---- bb1566 @ 0x140034fcc ----
    /* 140034fcc */ let mut t_140034fcc: u16 = core::ptr::read((0x140034fd3_u64).wrapping_add(0x2cef3d_u64) as *const u16);
    /* 140034fcc */ rax = ((t_140034fcc as u32) as u64);
    /* 140034fd3 */ core::ptr::write((rcx).wrapping_add(0x28_u64) as *mut u16, (rax as u16));
    /* 140034fd7 */ let mut t_140034fd7: u8 = core::ptr::read((0x140034fde_u64).wrapping_add(0x2cef34_u64) as *const u8);
    /* 140034fd7 */ rax = ((t_140034fd7 as u32) as u64);
    /* 140034fde */ core::ptr::write((rcx).wrapping_add(0x2a_u64) as *mut u8, (rax as u8));
    /* 140034fe1 */ core::ptr::write((rcx).wrapping_add(0x2b_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 140034feb */ let mut t_140034feb_0: u32 = 0x0_u32;
    /* 140034feb */ r9 = (t_140034feb_0 as u64);
    /* 140034fee */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 140034ff2 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 140034ff9 */ rcx = rbx;
    /* 140034ffc */ fn_1400d1090();
    /* 140035002 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1584 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1583 */ }

    // ---- bb1583 @ 0x14003500a ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1584 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1600 */ }

    // ---- bb1584 @ 0x14003500c ----
    /* 14003500c */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 14003500f */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 140035013 */ rax = rcx;
    if (CF == false) { /* -> bb1591 */ }
    if CF { /* -> bb1590 */ }

    // ---- bb1590 @ 0x14003501d ----
    if (CF == false) { /* -> bb1591 */ }
    if CF { /* -> bb1599 */ }

    // ---- bb1591 @ 0x14003501f ----
    /* 14003501f */ let mut t_14003501f_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 14003501f */ rdx = t_14003501f_0;
    /* 140035023 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140035027 */ let mut t_140035027_0: u64 = (rax).wrapping_sub(rcx);
    /* 140035027 */ rax = t_140035027_0;
    /* 14003502a */ let mut t_14003502a_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 14003502a */ rax = t_14003502a_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1599 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1598 */ }

    // ---- bb1598 @ 0x140035032 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1599 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1771 */ }

    // ---- bb1599 @ 0x140035038 ----
    /* 140035038 */ fn_1402c7498();
    /* fallthrough -> bb1600 */

    // ---- bb1600 @ 0x14003503d ----
    /* 14003503d */ let mut t_14003503d: u32 = core::ptr::read((rbx).wrapping_add(0x69c_u64) as *const u32);
    if (t_14003503d == 0x2_u32) {
        /* -> bb1604 */
    } else {
        /* -> bb1603 */
    }

    // ---- bb1603 @ 0x140035044 ----
    if (t_14003503d == 0x2_u32) {
        /* -> bb1604 */
    } else {
        /* -> bb1651 */
    }

    // ---- bb1604 @ 0x14003504a ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003504d */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140035054 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm1);
    /* 140035059 */ rcx = (0x30_u32 as u64);
    /* 14003505e */ fn_1400285e0();
    /* 140035063 */ rdx = rax;
    /* 140035066 */ core::ptr::write((rbp).wrapping_sub(0x11_u64) as *mut u64, rax);
    /* 14003506a */ xmm0 = core::ptr::read((0x140035072_u64).wrapping_add(0x2cf10e_u64) as *const u128);
    /* 140035072 */ core::ptr::write((rbp).wrapping_sub(0x1_u64) as *mut u128, xmm0);
    /* 140035077 */ xmm0 = core::ptr::read((0x14003507e_u64).wrapping_add(0x2cee9a_u64) as *const u128);
    /* 14003507e */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140035081 */ xmm1 = core::ptr::read((0x140035088_u64).wrapping_add(0x2ceea0_u64) as *const u128);
    /* 140035088 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 14003508c */ let mut t_14003508c: u32 = core::ptr::read((0x140035092_u64).wrapping_add(0x2ceea6_u64) as *const u32);
    /* 14003508c */ rcx = (t_14003508c as u64);
    /* 140035092 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u32, (rcx as u32));
    /* 140035095 */ let mut t_140035095: u16 = core::ptr::read((0x14003509c_u64).wrapping_add(0x2ceea0_u64) as *const u16);
    /* 140035095 */ rax = ((t_140035095 as u32) as u64);
    /* 14003509c */ core::ptr::write((rdx).wrapping_add(0x24_u64) as *mut u16, (rax as u16));
    /* 1400350a0 */ core::ptr::write((rdx).wrapping_add(0x26_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f117c movss dword ptr [rsp + 0x20], xmm7
    /* 1400350aa */ let mut t_1400350aa_0: u32 = 0x0_u32;
    /* 1400350aa */ r9 = (t_1400350aa_0 as u64);
    /* 1400350ad */ r8 = (rbp).wrapping_sub(0x11_u64);
    /* 1400350b1 */ rdx = core::ptr::read((rbx).wrapping_add(0x148_u64) as *const u64);
    /* 1400350b8 */ rcx = rbx;
    /* 1400350bb */ fn_1400d1090();
    /* 1400350c1 */ rdx = core::ptr::read((rbp).wrapping_add(0x7_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1635 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1634 */ }

    // ---- bb1634 @ 0x1400350c9 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1635 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1651 */ }

    // ---- bb1635 @ 0x1400350cb ----
    /* 1400350cb */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400350ce */ rcx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    /* 1400350d2 */ rax = rcx;
    if (CF == false) { /* -> bb1642 */ }
    if CF { /* -> bb1641 */ }

    // ---- bb1641 @ 0x1400350dc ----
    if (CF == false) { /* -> bb1642 */ }
    if CF { /* -> bb1650 */ }

    // ---- bb1642 @ 0x1400350de ----
    /* 1400350de */ let mut t_1400350de_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400350de */ rdx = t_1400350de_0;
    /* 1400350e2 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400350e6 */ let mut t_1400350e6_0: u64 = (rax).wrapping_sub(rcx);
    /* 1400350e6 */ rax = t_1400350e6_0;
    /* 1400350e9 */ let mut t_1400350e9_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 1400350e9 */ rax = t_1400350e9_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1650 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1649 */ }

    // ---- bb1649 @ 0x1400350f1 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1650 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1673 */ }

    // ---- bb1650 @ 0x1400350f3 ----
    /* 1400350f3 */ fn_1402c7498();
    /* fallthrough -> bb1651 */

    // ---- bb1651 @ 0x1400350f8 ----
    /* 1400350f8 */ let mut t_1400350f8: u32 = core::ptr::read((rbx).wrapping_add(0xe0_u64) as *const u32);
    if (t_1400350f8 == 0x0_u32) {
        /* -> bb1655 */
    } else {
        /* -> bb1654 */
    }

    // ---- bb1654 @ 0x1400350ff ----
    if (t_1400350f8 == 0x0_u32) {
        /* -> bb1655 */
    } else {
        /* -> bb1660 */
    }

    // ---- bb1655 @ 0x140035101 ----
    /* 140035101 */ rax = core::ptr::read(rbx as *const u64);
    /* 140035104 */ rcx = rbx;
    /* 140035107 */ (/* indirect */ core::ptr::read((rax).wrapping_add(0xa8_u64) as *const u64))();
    /* 14003510d */ rcx = rbx;
    /* 140035110 */ fn_1400cdef0();
    /* fallthrough -> bb1660 */

    // ---- bb1660 @ 0x140035115 ----
    /* 140035115 */ r11 = (rsp).wrapping_add(0x90_u64);
    /* 14003511d */ rbx = core::ptr::read((r11).wrapping_add(0x38_u64) as *const u64);
    /* 140035121 */ rsi = core::ptr::read((r11).wrapping_add(0x40_u64) as *const u64);
    /* 140035125 */ rdi = core::ptr::read((r11).wrapping_add(0x48_u64) as *const u64);
    /* 140035129 */ let mut xmm6: u128 = core::ptr::read((r11).wrapping_sub(0x10_u64) as *const u128);
    /* 14003512e */ let mut xmm7: u128 = core::ptr::read((rsp).wrapping_add(0x70_u64) as *const u128);
    /* 140035133 */ rsp = r11;
    /* 140035136 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140035136 */ r15 = core::ptr::read(rsp as *const u64);
    /* 140035138 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140035138 */ r14 = core::ptr::read(rsp as *const u64);
    /* 14003513a */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003513a */ r13 = core::ptr::read(rsp as *const u64);
    /* 14003513c */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003513c */ r12 = core::ptr::read(rsp as *const u64);
    /* 14003513e */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003513e */ rbp = core::ptr::read(rsp as *const u64);
    /* 14003513f */ return;
    // <no successors>

    // ---- bb1673 @ 0x140035140 ----
    /* 140035140 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 140035145 */ let mut t_140035145_0: u32 = 0x0_u32;
    /* 140035145 */ r9 = (t_140035145_0 as u64);
    /* 140035148 */ let mut t_140035148_0: u32 = 0x0_u32;
    /* 140035148 */ r8 = (t_140035148_0 as u64);
    /* 14003514b */ let mut t_14003514b_0: u32 = 0x0_u32;
    /* 14003514b */ rdx = (t_14003514b_0 as u64);
    /* 14003514d */ let mut t_14003514d_0: u32 = 0x0_u32;
    /* 14003514d */ rcx = (t_14003514d_0 as u64);
    /* 14003514f */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1680 */

    // ---- bb1680 @ 0x140035155 ----
    /* 140035155 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 14003515a */ let mut t_14003515a_0: u32 = 0x0_u32;
    /* 14003515a */ r9 = (t_14003515a_0 as u64);
    /* 14003515d */ let mut t_14003515d_0: u32 = 0x0_u32;
    /* 14003515d */ r8 = (t_14003515d_0 as u64);
    /* 140035160 */ let mut t_140035160_0: u32 = 0x0_u32;
    /* 140035160 */ rdx = (t_140035160_0 as u64);
    /* 140035162 */ let mut t_140035162_0: u32 = 0x0_u32;
    /* 140035162 */ rcx = (t_140035162_0 as u64);
    /* 140035164 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1687 */

    // ---- bb1687 @ 0x14003516a ----
    /* 14003516a */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 14003516f */ let mut t_14003516f_0: u32 = 0x0_u32;
    /* 14003516f */ r9 = (t_14003516f_0 as u64);
    /* 140035172 */ let mut t_140035172_0: u32 = 0x0_u32;
    /* 140035172 */ r8 = (t_140035172_0 as u64);
    /* 140035175 */ let mut t_140035175_0: u32 = 0x0_u32;
    /* 140035175 */ rdx = (t_140035175_0 as u64);
    /* 140035177 */ let mut t_140035177_0: u32 = 0x0_u32;
    /* 140035177 */ rcx = (t_140035177_0 as u64);
    /* 140035179 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1694 */

    // ---- bb1694 @ 0x14003517f ----
    /* 14003517f */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 140035184 */ let mut t_140035184_0: u32 = 0x0_u32;
    /* 140035184 */ r9 = (t_140035184_0 as u64);
    /* 140035187 */ let mut t_140035187_0: u32 = 0x0_u32;
    /* 140035187 */ r8 = (t_140035187_0 as u64);
    /* 14003518a */ let mut t_14003518a_0: u32 = 0x0_u32;
    /* 14003518a */ rdx = (t_14003518a_0 as u64);
    /* 14003518c */ let mut t_14003518c_0: u32 = 0x0_u32;
    /* 14003518c */ rcx = (t_14003518c_0 as u64);
    /* 14003518e */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1701 */

    // ---- bb1701 @ 0x140035194 ----
    /* 140035194 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 140035199 */ let mut t_140035199_0: u32 = 0x0_u32;
    /* 140035199 */ r9 = (t_140035199_0 as u64);
    /* 14003519c */ let mut t_14003519c_0: u32 = 0x0_u32;
    /* 14003519c */ r8 = (t_14003519c_0 as u64);
    /* 14003519f */ let mut t_14003519f_0: u32 = 0x0_u32;
    /* 14003519f */ rdx = (t_14003519f_0 as u64);
    /* 1400351a1 */ let mut t_1400351a1_0: u32 = 0x0_u32;
    /* 1400351a1 */ rcx = (t_1400351a1_0 as u64);
    /* 1400351a3 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1708 */

    // ---- bb1708 @ 0x1400351a9 ----
    /* 1400351a9 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 1400351ae */ let mut t_1400351ae_0: u32 = 0x0_u32;
    /* 1400351ae */ r9 = (t_1400351ae_0 as u64);
    /* 1400351b1 */ let mut t_1400351b1_0: u32 = 0x0_u32;
    /* 1400351b1 */ r8 = (t_1400351b1_0 as u64);
    /* 1400351b4 */ let mut t_1400351b4_0: u32 = 0x0_u32;
    /* 1400351b4 */ rdx = (t_1400351b4_0 as u64);
    /* 1400351b6 */ let mut t_1400351b6_0: u32 = 0x0_u32;
    /* 1400351b6 */ rcx = (t_1400351b6_0 as u64);
    /* 1400351b8 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1715 */

    // ---- bb1715 @ 0x1400351be ----
    /* 1400351be */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 1400351c3 */ let mut t_1400351c3_0: u32 = 0x0_u32;
    /* 1400351c3 */ r9 = (t_1400351c3_0 as u64);
    /* 1400351c6 */ let mut t_1400351c6_0: u32 = 0x0_u32;
    /* 1400351c6 */ r8 = (t_1400351c6_0 as u64);
    /* 1400351c9 */ let mut t_1400351c9_0: u32 = 0x0_u32;
    /* 1400351c9 */ rdx = (t_1400351c9_0 as u64);
    /* 1400351cb */ let mut t_1400351cb_0: u32 = 0x0_u32;
    /* 1400351cb */ rcx = (t_1400351cb_0 as u64);
    /* 1400351cd */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1722 */

    // ---- bb1722 @ 0x1400351d3 ----
    /* 1400351d3 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 1400351d8 */ let mut t_1400351d8_0: u32 = 0x0_u32;
    /* 1400351d8 */ r9 = (t_1400351d8_0 as u64);
    /* 1400351db */ let mut t_1400351db_0: u32 = 0x0_u32;
    /* 1400351db */ r8 = (t_1400351db_0 as u64);
    /* 1400351de */ let mut t_1400351de_0: u32 = 0x0_u32;
    /* 1400351de */ rdx = (t_1400351de_0 as u64);
    /* 1400351e0 */ let mut t_1400351e0_0: u32 = 0x0_u32;
    /* 1400351e0 */ rcx = (t_1400351e0_0 as u64);
    /* 1400351e2 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1729 */

    // ---- bb1729 @ 0x1400351e8 ----
    /* 1400351e8 */ fn_14002f0d0();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1731 */

    // ---- bb1731 @ 0x1400351ee ----
    /* 1400351ee */ fn_140024090();
    /* fallthrough -> bb1733 */

    // ---- bb1733 @ 0x1400351f4 ----
    /* 1400351f4 */ fn_14002f0d0();
    /* fallthrough -> bb1735 */

    // ---- bb1735 @ 0x1400351fa ----
    /* 1400351fa */ let mut t_1400351fa_0: u32 = 0x0_u32;
    /* 1400351fa */ rax = (t_1400351fa_0 as u64);
    /* 1400351fc */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, rax);
    /* 140035201 */ let mut t_140035201_0: u32 = 0x0_u32;
    /* 140035201 */ r9 = (t_140035201_0 as u64);
    /* 140035204 */ let mut t_140035204_0: u32 = 0x0_u32;
    /* 140035204 */ r8 = (t_140035204_0 as u64);
    /* 140035207 */ let mut t_140035207_0: u32 = 0x0_u32;
    /* 140035207 */ rdx = (t_140035207_0 as u64);
    /* 140035209 */ let mut t_140035209_0: u32 = 0x0_u32;
    /* 140035209 */ rcx = (t_140035209_0 as u64);
    /* 14003520b */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1743 */

    // ---- bb1743 @ 0x140035211 ----
    /* 140035211 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 140035216 */ let mut t_140035216_0: u32 = 0x0_u32;
    /* 140035216 */ r9 = (t_140035216_0 as u64);
    /* 140035219 */ let mut t_140035219_0: u32 = 0x0_u32;
    /* 140035219 */ r8 = (t_140035219_0 as u64);
    /* 14003521c */ let mut t_14003521c_0: u32 = 0x0_u32;
    /* 14003521c */ rdx = (t_14003521c_0 as u64);
    /* 14003521e */ let mut t_14003521e_0: u32 = 0x0_u32;
    /* 14003521e */ rcx = (t_14003521e_0 as u64);
    /* 140035220 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1750 */

    // ---- bb1750 @ 0x140035226 ----
    /* 140035226 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 14003522b */ let mut t_14003522b_0: u32 = 0x0_u32;
    /* 14003522b */ r9 = (t_14003522b_0 as u64);
    /* 14003522e */ let mut t_14003522e_0: u32 = 0x0_u32;
    /* 14003522e */ r8 = (t_14003522e_0 as u64);
    /* 140035231 */ let mut t_140035231_0: u32 = 0x0_u32;
    /* 140035231 */ rdx = (t_140035231_0 as u64);
    /* 140035233 */ let mut t_140035233_0: u32 = 0x0_u32;
    /* 140035233 */ rcx = (t_140035233_0 as u64);
    /* 140035235 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1757 */

    // ---- bb1757 @ 0x14003523b ----
    /* 14003523b */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 140035240 */ let mut t_140035240_0: u32 = 0x0_u32;
    /* 140035240 */ r9 = (t_140035240_0 as u64);
    /* 140035243 */ let mut t_140035243_0: u32 = 0x0_u32;
    /* 140035243 */ r8 = (t_140035243_0 as u64);
    /* 140035246 */ let mut t_140035246_0: u32 = 0x0_u32;
    /* 140035246 */ rdx = (t_140035246_0 as u64);
    /* 140035248 */ let mut t_140035248_0: u32 = 0x0_u32;
    /* 140035248 */ rcx = (t_140035248_0 as u64);
    /* 14003524a */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1764 */

    // ---- bb1764 @ 0x140035250 ----
    /* 140035250 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 140035255 */ let mut t_140035255_0: u32 = 0x0_u32;
    /* 140035255 */ r9 = (t_140035255_0 as u64);
    /* 140035258 */ let mut t_140035258_0: u32 = 0x0_u32;
    /* 140035258 */ r8 = (t_140035258_0 as u64);
    /* 14003525b */ let mut t_14003525b_0: u32 = 0x0_u32;
    /* 14003525b */ rdx = (t_14003525b_0 as u64);
    /* 14003525d */ let mut t_14003525d_0: u32 = 0x0_u32;
    /* 14003525d */ rcx = (t_14003525d_0 as u64);
    /* 14003525f */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1771 */

    // ---- bb1771 @ 0x140035265 ----
    /* 140035265 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 14003526a */ let mut t_14003526a_0: u32 = 0x0_u32;
    /* 14003526a */ r9 = (t_14003526a_0 as u64);
    /* 14003526d */ let mut t_14003526d_0: u32 = 0x0_u32;
    /* 14003526d */ r8 = (t_14003526d_0 as u64);
    /* 140035270 */ let mut t_140035270_0: u32 = 0x0_u32;
    /* 140035270 */ rdx = (t_140035270_0 as u64);
    /* 140035272 */ let mut t_140035272_0: u32 = 0x0_u32;
    /* 140035272 */ rcx = (t_140035272_0 as u64);
    /* 140035274 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    /* 140035280 */ rax = rsp;
    /* 140035283 */ core::ptr::write((rax).wrapping_add(0x8_u64) as *mut u64, rbx);
    /* 140035287 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u64, rsi);
    /* 14003528b */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u64, rdi);
    /* 14003528f */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003528f */ core::ptr::write(rsp as *mut u64, rbp);
    /* 140035290 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140035290 */ core::ptr::write(rsp as *mut u64, r12);
    /* 140035292 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140035292 */ core::ptr::write(rsp as *mut u64, r13);
    /* 140035294 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140035294 */ core::ptr::write(rsp as *mut u64, r14);
    /* 140035296 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140035296 */ core::ptr::write(rsp as *mut u64, r15);
    /* 140035298 */ rbp = (rax).wrapping_sub(0x5f_u64);
    /* 14003529c */ let mut t_14003529c_0: u64 = (rsp).wrapping_sub(0xd0_u64);
    /* 14003529c */ rsp = t_14003529c_0;
    /* 1400352a3 */ core::ptr::write((rax).wrapping_sub(0x38_u64) as *mut u128, xmm6);
    /* 1400352a7 */ core::ptr::write((rax).wrapping_sub(0x48_u64) as *mut u128, xmm7);
    /* 1400352ab */ core::ptr::write((rax).wrapping_sub(0x58_u64) as *mut u128, xmm8);
    /* 1400352b0 */ core::ptr::write((rax).wrapping_sub(0x68_u64) as *mut u128, xmm9);
    /* 1400352b5 */ core::ptr::write((rax).wrapping_sub(0x78_u64) as *mut u128, xmm10);
    /* 1400352ba */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u128, xmm12);
    /* 1400352c0 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm13);
    /* 1400352c6 */ rdi = rcx;
    /* 1400352c9 */ let mut t_1400352c9: u32 = core::ptr::read((0x1400352cf_u64).wrapping_add(0x39eef5_u64) as *const u32);
    /* 1400352c9 */ rcx = (t_1400352c9 as u64);
    /* 1400352cf */ fn_140070f40();
    /* 1400352d4 */ let mut t_1400352d4: u32 = core::ptr::read((0x1400352db_u64).wrapping_add(0x3c9455_u64) as *const u32);
    /* 1400352d4 */ r12 = (t_1400352d4 as u64);
    /* 1400352db */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 1400352e4 */ rcx = (0x4_u32 as u64);
    /* 1400352e9 */ rsi = ((rcx as u32) as u64);
    /* 1400352eb */ r14 = core::ptr::read((rax).wrapping_add((r12).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400352ef */ let mut t_1400352ef: u32 = core::ptr::read((r14).wrapping_add((rcx).wrapping_mul(0x1_u64)) as *const u32);
    /* 1400352ef */ rax = (t_1400352ef as u64);
    /* 1400352f3 */ let mut t_1400352f3: u32 = core::ptr::read((0x1400352f9_u64).wrapping_add(0x3b4e03_u64) as *const u32);
    if (((SF == OF) & (t_1400352f3 != (rax as u32))) == false) { /* -> bb1815 */ }
    if (((SF == OF) & (t_1400352f3 != (rax as u32))) != 0) { /* -> bb1814 */ }

    // ---- bb1814 @ 0x1400352f9 ----
    if (((SF == OF) & (t_1400352f3 != (rax as u32))) == false) { /* -> bb1815 */ }
    if (((SF == OF) & (t_1400352f3 != (rax as u32))) != 0) { /* -> bb2926 */ }

    // ---- bb1815 @ 0x1400352ff ----
    /* 1400352ff */ let mut t_1400352ff: u32 = core::ptr::read((r14).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u32);
    /* 1400352ff */ rax = (t_1400352ff as u64);
    /* 140035303 */ let mut t_140035303: u32 = core::ptr::read((0x140035309_u64).wrapping_add(0x3b4dfb_u64) as *const u32);
    if (((SF == OF) & (t_140035303 != (rax as u32))) == false) { /* -> bb1820 */ }
    if (((SF == OF) & (t_140035303 != (rax as u32))) != 0) { /* -> bb1819 */ }

    // ---- bb1819 @ 0x140035309 ----
    if (((SF == OF) & (t_140035303 != (rax as u32))) == false) { /* -> bb1820 */ }
    if (((SF == OF) & (t_140035303 != (rax as u32))) != 0) { /* -> bb2947 */ }

    // ---- bb1820 @ 0x14003530f ----
    // intrinsic: 0f57d200 xorps xmm2, xmm2
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140035315 */ let mut t_140035315: u32 = core::ptr::read((0x14003531b_u64).wrapping_add(0x3b4ddd_u64) as *const u32);
    /* 140035315 */ rcx = (t_140035315 as u64);
    /* 14003531b */ fn_140071cd0();
    // intrinsic: f3440f10 movss xmm9, dword ptr [rip + 0x36797b]
    /* 140035329 */ let mut t_140035329: u32 = core::ptr::read((0x14003532f_u64).wrapping_add(0x3b86d5_u64) as *const u32);
    /* 140035329 */ rax = (t_140035329 as u64);
    if (((SF != OF) | (t_1400363f0 == 0xffffffff_u32)) == false) { /* -> bb1830 */ }
    if (((SF != OF) | (t_1400363f0 == 0xffffffff_u32)) != 0) { /* -> bb1829 */ }

    // ---- bb1829 @ 0x140035331 ----
    if (((SF != OF) | (t_1400363f0 == 0xffffffff_u32)) == false) { /* -> bb1830 */ }
    if (((SF != OF) | (t_1400363f0 == 0xffffffff_u32)) != 0) { /* -> bb1840 */ }

    // ---- bb1830 @ 0x140035333 ----
    /* 140035333 */ let mut t_140035333_0: u32 = (0x0_u32).wrapping_sub((rax as u32));
    /* 140035333 */ rax = (t_140035333_0 as u64);
    /* 140035335 */ xmm0 = ((rax as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    /* 14003533c */ let mut t_14003533c: u32 = core::ptr::read((0x140035342_u64).wrapping_add(0x3b4db6_u64) as *const u32);
    /* 14003533c */ rcx = (t_14003533c as u64);
    /* 140035342 */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 14003534a */ xmm3 = xmm9;
    // intrinsic: 0f57d200 xorps xmm2, xmm2
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140035354 */ fn_140071e80();
    /* fallthrough -> bb1840 */

    // ---- bb1840 @ 0x140035359 ----
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x2cecc6]
    /* 140035362 */ let mut t_140035362: u32 = core::ptr::read((0x140035368_u64).wrapping_add(0x3b8698_u64) as *const u32);
    /* 140035362 */ rax = (t_140035362 as u64);
    if (((SF != OF) | (t_1400363f0 == 0xffffffff_u32)) == false) { /* -> bb1846 */ }
    if (((SF != OF) | (t_1400363f0 == 0xffffffff_u32)) != 0) { /* -> bb1845 */ }

    // ---- bb1845 @ 0x14003536a ----
    if (((SF != OF) | (t_1400363f0 == 0xffffffff_u32)) == false) { /* -> bb1846 */ }
    if (((SF != OF) | (t_1400363f0 == 0xffffffff_u32)) != 0) { /* -> bb1856 */ }

    // ---- bb1846 @ 0x14003536c ----
    /* 14003536c */ let mut xmm2: u128 = ((rax as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 140035373 */ let mut t_140035373_0: u32 = (0x0_u32).wrapping_sub((rax as u32));
    /* 140035373 */ rax = (t_140035373_0 as u64);
    /* 140035375 */ xmm0 = ((rax as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    /* 14003537c */ let mut t_14003537c: u32 = core::ptr::read((0x140035382_u64).wrapping_add(0x39edd2_u64) as *const u32);
    /* 14003537c */ rax = (t_14003537c as u64);
    /* 140035382 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 140035386 */ xmm3 = xmm8;
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 14003538d */ fn_140070fb0();
    /* fallthrough -> bb1856 */

    // ---- bb1856 @ 0x140035392 ----
    /* 140035392 */ let mut t_140035392: u32 = core::ptr::read((0x140035398_u64).wrapping_add(0x39edb0_u64) as *const u32);
    /* 140035392 */ rax = (t_140035392 as u64);
    /* 140035398 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x2cec78]
    // intrinsic: f3440f10 movss xmm12, dword ptr [rip + 0x2cec5f]
    /* 1400353ad */ xmm2 = xmm12;
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2cec87]
    /* 1400353b9 */ xmm1 = xmm0;
    /* 1400353bc */ fn_140070fb0();
    /* 1400353c1 */ let mut t_1400353c1: u32 = core::ptr::read((0x1400353c7_u64).wrapping_add(0x2d6309_u64) as *const u32);
    /* 1400353c1 */ rax = (t_1400353c1 as u64);
    /* 1400353c7 */ let mut t_1400353c7: u32 = core::ptr::read((0x1400353cd_u64).wrapping_add(0x3b8633_u64) as *const u32);
    /* 1400353c7 */ rcx = (t_1400353c7 as u64);
    /* 1400353cd */ rax = (((rax).wrapping_add((rcx).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 1400353d0 */ xmm2 = ((rax as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 1400353d7 */ let mut t_1400353d7_0: u32 = (0x0_u32).wrapping_sub((rcx as u32));
    /* 1400353d7 */ rcx = (t_1400353d7_0 as u64);
    /* 1400353d9 */ xmm0 = ((rcx as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    /* 1400353e0 */ let mut t_1400353e0: u32 = core::ptr::read((0x1400353e6_u64).wrapping_add(0x39ed62_u64) as *const u32);
    /* 1400353e0 */ rax = (t_1400353e0 as u64);
    /* 1400353e6 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x2cdfba]
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2cdfca]
    /* 1400353fa */ fn_140070fb0();
    /* 1400353ff */ let mut t_1400353ff: u32 = core::ptr::read((0x140035407_u64).wrapping_add(0x3b85f9_u64) as *const u32);
    /* 1400353ff */ xmm2 = (t_1400353ff as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 14003540a */ let mut t_14003540a: u32 = core::ptr::read((0x140035410_u64).wrapping_add(0x39ed34_u64) as *const u32);
    /* 14003540a */ rax = (t_14003540a as u64);
    /* 140035410 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    // intrinsic: f3440f10 movss xmm10, dword ptr [rip + 0x2cdf6f]
    /* 14003541d */ xmm3 = xmm10;
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2cec0b]
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2cec3b]
    /* 140035431 */ xmm0 = xmm6;
    /* 140035434 */ fn_140070fb0();
    /* 140035439 */ let mut t_140035439: u32 = core::ptr::read((0x140035441_u64).wrapping_add(0x3b85bf_u64) as *const u32);
    /* 140035439 */ xmm2 = (t_140035439 as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 140035444 */ let mut t_140035444: u32 = core::ptr::read((0x14003544a_u64).wrapping_add(0x39ecfe_u64) as *const u32);
    /* 140035444 */ rax = (t_140035444 as u64);
    /* 14003544a */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 14003544e */ xmm3 = xmm9;
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2cebde]
    /* 14003545a */ xmm1 = xmm7;
    /* 14003545d */ xmm0 = xmm6;
    /* 140035460 */ fn_140070fb0();
    /* 140035465 */ let mut t_140035465_0: u32 = 0x0_u32;
    /* 140035465 */ r15 = (t_140035465_0 as u64);
    /* 140035468 */ let mut t_140035468: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140035468 == 0x4_u32) {
        /* -> bb1901 */
    } else {
        /* -> bb1900 */
    }

    // ---- bb1900 @ 0x14003546f ----
    if (t_140035468 == 0x4_u32) {
        /* -> bb1901 */
    } else {
        /* -> bb1967 */
    }

    // ---- bb1901 @ 0x140035475 ----
    /* 140035475 */ let mut t_140035475: u32 = core::ptr::read((0x14003547b_u64).wrapping_add(0x3b8585_u64) as *const u32);
    /* 140035475 */ rax = (t_140035475 as u64);
    /* 14003547b */ let mut t_14003547b_0: u32 = ((rax as u32)).wrapping_add(0xe_u32);
    /* 14003547b */ rax = (t_14003547b_0 as u64);
    /* 14003547e */ xmm2 = ((rax as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 140035485 */ let mut t_140035485: u32 = core::ptr::read((0x14003548b_u64).wrapping_add(0x39ed1d_u64) as *const u32);
    /* 140035485 */ rax = (t_140035485 as u64);
    /* 14003548b */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 14003548f */ xmm3 = xmm9;
    /* 140035493 */ xmm1 = xmm7;
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2cebca]
    /* 14003549e */ fn_140070fb0();
    /* 1400354a3 */ rbx = ((r15 as u32) as u64);
    /* 1400354a6 */ let mut t_1400354a6: u32 = core::ptr::read((0x1400354ac_u64).wrapping_add(0x3b8554_u64) as *const u32);
    /* 1400354a6 */ rax = (t_1400354a6 as u64);
    /* 1400354ac */ let mut t_1400354ac_0: u32 = ((rax as u32)).wrapping_add(0xe_u32);
    /* 1400354ac */ rax = (t_1400354ac_0 as u64);
    if (((SF != OF) | (t_140035468 == 0x4_u32)) == false) { /* -> bb1918 */ }
    if (((SF != OF) | (t_140035468 == 0x4_u32)) != 0) { /* -> bb1917 */ }

    // ---- bb1917 @ 0x1400354b1 ----
    if (((SF != OF) | (t_140035468 == 0x4_u32)) == false) { /* -> bb1918 */ }
    if (((SF != OF) | (t_140035468 == 0x4_u32)) != 0) { /* -> bb1967 */ }

    // ---- bb1918 @ 0x1400354b7 ----
    /* 1400354b7 */ r15 = (0x1400354be_u64).wrapping_add(0x3b4be6_u64);
    /* 1400354be */ r13 = (0x1400354c5_u64).wrapping_add(0x3b4be3_u64);
    /* 1400354c5 */ r12 = (0x1400354cc_u64).wrapping_add(0x3b4bd4_u64);
    /* fallthrough -> bb1922 */

    // ---- bb1922 @ 0x1400354d0 ----
    /* 1400354d0 */ let mut t_1400354d0: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 1400354d0 */ rcx = (t_1400354d0 as u64);
    /* 1400354d6 */ let mut t_1400354d6_0: u32 = ((rcx as u32)).wrapping_sub((rbx as u32));
    /* 1400354d6 */ rcx = (t_1400354d6_0 as u64);
    /* 1400354d8 */ rdx = (0x20_u32 as u64);
    /* 1400354dd */ fn_1400c7200();
    if ((rbx as u32) == (rax as u32)) {
        /* -> bb1930 */
    } else {
        /* -> bb1929 */
    }

    // ---- bb1929 @ 0x1400354e4 ----
    if ((rbx as u32) == (rax as u32)) {
        /* -> bb1930 */
    } else {
        /* -> bb1932 */
    }

    // ---- bb1930 @ 0x1400354e6 ----
    /* 1400354e6 */ rcx = r12;
    /* fallthrough -> bb1949 */

    // ---- bb1932 @ 0x1400354eb ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb1936 */
    } else {
        /* -> bb1935 */
    }

    // ---- bb1935 @ 0x1400354ee ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb1936 */
    } else {
        /* -> bb1938 */
    }

    // ---- bb1936 @ 0x1400354f0 ----
    /* 1400354f0 */ rcx = r15;
    /* fallthrough -> bb1949 */

    // ---- bb1938 @ 0x1400354f5 ----
    if ((rax as u32) == 0x10_u32) {
        /* -> bb1942 */
    } else {
        /* -> bb1941 */
    }

    // ---- bb1941 @ 0x1400354f8 ----
    if ((rax as u32) == 0x10_u32) {
        /* -> bb1942 */
    } else {
        /* -> bb1944 */
    }

    // ---- bb1942 @ 0x1400354fa ----
    /* 1400354fa */ rcx = r13;
    /* fallthrough -> bb1949 */

    // ---- bb1944 @ 0x1400354ff ----
    if ((rax as u32) == 0x18_u32) {
        /* -> bb1948 */
    } else {
        /* -> bb1947 */
    }

    // ---- bb1947 @ 0x140035502 ----
    if ((rax as u32) == 0x18_u32) {
        /* -> bb1948 */
    } else {
        /* -> bb1958 */
    }

    // ---- bb1948 @ 0x140035504 ----
    /* 140035504 */ rcx = (0x14003550b_u64).wrapping_add(0x3b4ba1_u64);
    /* fallthrough -> bb1949 */

    // ---- bb1949 @ 0x14003550b ----
    /* 14003550b */ rax = (((rbx).wrapping_add(0x132_u64) as u32) as u64);
    /* 140035511 */ xmm0 = ((rax as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    /* 140035518 */ let mut t_140035518: u32 = core::ptr::read(rcx as *const u32);
    /* 140035518 */ rax = (t_140035518 as u64);
    /* 14003551a */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 14003551e */ xmm3 = xmm9;
    /* 140035522 */ xmm2 = xmm9;
    /* 140035526 */ xmm1 = xmm7;
    /* 140035529 */ fn_140070fb0();
    /* fallthrough -> bb1958 */

    // ---- bb1958 @ 0x14003552e ----
    /* 14003552e */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    /* 140035530 */ let mut t_140035530: u32 = core::ptr::read((0x140035536_u64).wrapping_add(0x3b84ca_u64) as *const u32);
    /* 140035530 */ rax = (t_140035530 as u64);
    /* 140035536 */ let mut t_140035536_0: u32 = ((rax as u32)).wrapping_add(0xe_u32);
    /* 140035536 */ rax = (t_140035536_0 as u64);
    if (SF == OF) {
        /* -> bb1965 */
    } else {
        /* -> bb1964 */
    }

    // ---- bb1964 @ 0x14003553b ----
    if (SF != OF) {
        /* -> bb1922 */
    } else {
        /* -> bb1965 */
    }

    // ---- bb1965 @ 0x14003553d ----
    /* 14003553d */ let mut t_14003553d: u32 = core::ptr::read((0x140035544_u64).wrapping_add(0x3c91ec_u64) as *const u32);
    /* 14003553d */ r12 = (t_14003553d as u64);
    /* 140035544 */ let mut t_140035544_0: u32 = 0x0_u32;
    /* 140035544 */ r15 = (t_140035544_0 as u64);
    /* fallthrough -> bb1967 */

    // ---- bb1967 @ 0x140035547 ----
    /* 140035547 */ let mut t_140035547: u8 = core::ptr::read((rdi).wrapping_add(0x6b0_u64) as *const u8);
    if (t_140035547 != 0x0_u8) {
        /* -> bb1971 */
    } else {
        /* -> bb1970 */
    }

    // ---- bb1970 @ 0x14003554e ----
    if (t_140035547 != 0x0_u8) {
        /* -> bb1971 */
    } else {
        /* -> bb1980 */
    }

    // ---- bb1971 @ 0x140035550 ----
    /* 140035550 */ let mut t_140035550: u32 = core::ptr::read((r14).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u32);
    /* 140035550 */ rax = (t_140035550 as u64);
    /* 140035554 */ let mut t_140035554: u32 = core::ptr::read((0x14003555a_u64).wrapping_add(0x3b4bb2_u64) as *const u32);
    if (((SF == OF) & (t_140035554 != (rax as u32))) == false) { /* -> bb1976 */ }
    if (((SF == OF) & (t_140035554 != (rax as u32))) != 0) { /* -> bb1975 */ }

    // ---- bb1975 @ 0x14003555a ----
    if (((SF == OF) & (t_140035554 != (rax as u32))) == false) { /* -> bb1976 */ }
    if (((SF == OF) & (t_140035554 != (rax as u32))) != 0) { /* -> bb2959 */ }

    // ---- bb1976 @ 0x140035560 ----
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ceac4]
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2ceae8]
    /* 140035570 */ let mut t_140035570: u32 = core::ptr::read((0x140035576_u64).wrapping_add(0x3b4b92_u64) as *const u32);
    /* 140035570 */ rcx = (t_140035570 as u64);
    /* 140035576 */ fn_140071cd0();
    /* fallthrough -> bb1980 */

    // ---- bb1980 @ 0x14003557b ----
    /* 14003557b */ rax = core::ptr::read((rdi).wrapping_add(0x60_u64) as *const u64);
    /* 14003557f */ rcx = ((r15 as u32) as u64);
    /* 140035582 */ let mut t_140035582: u32 = core::ptr::read((rdi).wrapping_add(0x27c_u64) as *const u32);
    /* 140035589 */ rcx = ((rcx & 0xffffffffffffff00_u64) | (((SF == OF) as u8) as u64));
    /* 14003558c */ let mut t_14003558c_0: u32 = ((rcx as u32)).wrapping_add(0x3_u32);
    /* 14003558c */ rcx = (t_14003558c_0 as u64);
    /* 14003558f */ let mut t_14003558f: u32 = core::ptr::read((0x140035595_u64).wrapping_add(0x3b4b63_u64) as *const u32);
    /* 14003558f */ let mut t_14003558f_0: u32 = ((rcx as u32)).wrapping_add(t_14003558f);
    /* 14003558f */ rcx = (t_14003558f_0 as u64);
    // intrinsic: f30f1090 movss xmm2, dword ptr [rax + 0x310]
    // intrinsic: f30f1088 movss xmm1, dword ptr [rax + 0x30c]
    /* 1400355a5 */ fn_140071cd0();
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2cea1a]
    /* 1400355b2 */ xmm0 = xmm8;
    // intrinsic: 0f14c100 unpcklps xmm0, xmm1
    /* 1400355b9 */ rcx = (xmm0 as u64);
    /* 1400355be */ fn_140072e00();
    /* 1400355c3 */ let mut t_1400355c3: u32 = core::ptr::read((rdi).wrapping_add(0x27c_u64) as *const u32);
    /* 1400355c3 */ rax = (t_1400355c3 as u64);
    /* 1400355c9 */ r13 = (0x57_u32 as u64);
    // intrinsic: f3440f10 movss xmm13, dword ptr [rip + 0x367708]
    if ((rax as u32) == 0x1_u32) {
        /* -> bb2001 */
    } else {
        /* -> bb2000 */
    }

    // ---- bb2000 @ 0x1400355db ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb2001 */
    } else {
        /* -> bb2093 */
    }

    // ---- bb2001 @ 0x1400355e1 ----
    /* 1400355e1 */ rax = (0x1400355e8_u64).wrapping_add(0x2ce970_u64);
    /* 1400355e8 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 1400355ed */ let mut t_1400355ed: u32 = core::ptr::read((0x1400355f3_u64).wrapping_add(0x39ebc1_u64) as *const u32);
    /* 1400355ed */ rax = (t_1400355ed as u64);
    /* 1400355f3 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm9
    /* 1400355fe */ let mut t_1400355fe_0: u32 = 0x0_u32;
    /* 1400355fe */ r9 = (t_1400355fe_0 as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce9d7]
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2cdd87]
    /* 140035611 */ xmm1 = xmm6;
    /* 140035614 */ rcx = core::ptr::read((0x14003561b_u64).wrapping_add(0x3b881d_u64) as *const u64);
    /* 14003561b */ fn_140086510();
    /* 140035620 */ let mut t_140035620: u32 = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u32);
    /* 140035620 */ rax = (t_140035620 as u64);
    /* 140035626 */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140035627 */ let mut t_140035627_0: u32 = ((rax as u32)).wrapping_sub((rdx as u32));
    /* 140035627 */ rax = (t_140035627_0 as u64);
    /* 140035629 */ rax = (((((rax as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 14003562b */ rcx = ((r13 as u32) as u64);
    if (SF == OF) {
        /* -> bb2019 */
    } else {
        /* -> bb2020 */
    }

    // ---- bb2020 @ 0x140035630 ----
    /* 140035630 */ rcx = ((rax as u32) as u64);
    /* fallthrough -> bb2019 */

    // ---- bb2019 @ 0x140035633 ----
    /* 140035633 */ xmm2 = ((rcx as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 14003563a */ let mut t_14003563a: u32 = core::ptr::read((0x140035640_u64).wrapping_add(0x39eb74_u64) as *const u32);
    /* 14003563a */ rax = (t_14003563a as u64);
    /* 140035640 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 140035644 */ xmm3 = xmm10;
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2ce998]
    /* 140035650 */ xmm0 = xmm6;
    /* 140035653 */ fn_140070fb0();
    /* 140035658 */ let mut t_140035658: u32 = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u32);
    /* 140035658 */ rax = (t_140035658 as u64);
    /* 14003565e */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 14003565f */ let mut t_14003565f_0: u32 = ((rax as u32)).wrapping_sub((rdx as u32));
    /* 14003565f */ rax = (t_14003565f_0 as u64);
    /* 140035661 */ rax = (((((rax as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 140035663 */ r15 = ((rax as u32) as u64);
    /* 140035666 */ r14 = (0x43_u32 as u64);
    /* 14003566c */ r12 = (0x140035673_u64).wrapping_add(0x3b4a2d_u64);
    /* fallthrough -> bb2036 */

    // ---- bb2036 @ 0x140035673 ----
    /* 140035673 */ rbx = (0xa2_u32 as u64);
    /* 140035678 */ xmm6 = ((r14 as u32) as u128);
    // intrinsic: 0f5bf600 cvtdq2ps xmm6, xmm6
    /* 140035680 */ rsi = (((r15).wrapping_add((r14).wrapping_mul(0x1_u64)) as u32) as u64);
    /* fallthrough -> bb2040 */

    // ---- bb2040 @ 0x140035684 ----
    /* 140035684 */ rax = (((rsi).wrapping_add((rbx).wrapping_mul(0x1_u64)) as u32) as u64);
    /* 140035687 */ let mut t_140035687_0: u32 = ((rax as u32) & 0x80000003_u32);
    /* 140035687 */ rax = (t_140035687_0 as u64);
    if (SF != OF) {
        /* -> bb2045 */
    } else {
        /* -> bb2044 */
    }

    // ---- bb2044 @ 0x14003568c ----
    if (SF != OF) {
        /* -> bb2045 */
    } else {
        /* -> bb2048 */
    }

    // ---- bb2045 @ 0x14003568e ----
    /* 14003568e */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    /* 140035690 */ let mut t_140035690_0: u32 = ((rax as u32) | 0xfffffffc_u32);
    /* 140035690 */ rax = (t_140035690_0 as u64);
    /* 140035693 */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb2048 */

    // ---- bb2048 @ 0x140035695 ----
    /* 140035695 */ rax = (((rax as u32) as i64) as u64);
    /* 140035697 */ xmm0 = ((rbx as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    /* 14003569e */ let mut t_14003569e: u32 = core::ptr::read((r12).wrapping_add((rax).wrapping_mul(0x4_u64)) as *const u32);
    /* 14003569e */ rax = (t_14003569e as u64);
    /* 1400356a2 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 1400356a6 */ xmm3 = xmm9;
    /* 1400356aa */ xmm2 = xmm9;
    /* 1400356ae */ xmm1 = xmm6;
    /* 1400356b1 */ fn_140070fb0();
    /* 1400356b6 */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    if (SF == OF) {
        /* -> bb2062 */
    } else {
        /* -> bb2061 */
    }

    // ---- bb2061 @ 0x1400356be ----
    if (SF != OF) {
        /* -> bb2040 */
    } else {
        /* -> bb2062 */
    }

    // ---- bb2062 @ 0x1400356c0 ----
    /* 1400356c0 */ rbx = (0xb7_u32 as u64);
    /* fallthrough -> bb2063 */

    // ---- bb2063 @ 0x1400356c5 ----
    /* 1400356c5 */ rax = (((rsi).wrapping_add((rbx).wrapping_mul(0x1_u64)) as u32) as u64);
    /* 1400356c8 */ let mut t_1400356c8_0: u32 = ((rax as u32) & 0x80000003_u32);
    /* 1400356c8 */ rax = (t_1400356c8_0 as u64);
    if (SF != OF) {
        /* -> bb2068 */
    } else {
        /* -> bb2067 */
    }

    // ---- bb2067 @ 0x1400356cd ----
    if (SF != OF) {
        /* -> bb2068 */
    } else {
        /* -> bb2071 */
    }

    // ---- bb2068 @ 0x1400356cf ----
    /* 1400356cf */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    /* 1400356d1 */ let mut t_1400356d1_0: u32 = ((rax as u32) | 0xfffffffc_u32);
    /* 1400356d1 */ rax = (t_1400356d1_0 as u64);
    /* 1400356d4 */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb2071 */

    // ---- bb2071 @ 0x1400356d6 ----
    /* 1400356d6 */ rax = (((rax as u32) as i64) as u64);
    /* 1400356d8 */ xmm0 = ((rbx as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    /* 1400356df */ let mut t_1400356df: u32 = core::ptr::read((r12).wrapping_add((rax).wrapping_mul(0x4_u64)) as *const u32);
    /* 1400356df */ rax = (t_1400356df as u64);
    /* 1400356e3 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 1400356e7 */ xmm3 = xmm9;
    /* 1400356eb */ xmm2 = xmm9;
    /* 1400356ef */ xmm1 = xmm6;
    /* 1400356f2 */ fn_140070fb0();
    /* 1400356f7 */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    if (SF == OF) {
        /* -> bb2085 */
    } else {
        /* -> bb2084 */
    }

    // ---- bb2084 @ 0x1400356ff ----
    if (SF != OF) {
        /* -> bb2063 */
    } else {
        /* -> bb2085 */
    }

    // ---- bb2085 @ 0x140035701 ----
    /* 140035701 */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    if (SF == OF) {
        /* -> bb2090 */
    } else {
        /* -> bb2089 */
    }

    // ---- bb2089 @ 0x140035708 ----
    if (SF != OF) {
        /* -> bb2036 */
    } else {
        /* -> bb2090 */
    }

    // ---- bb2090 @ 0x14003570e ----
    /* 14003570e */ let mut t_14003570e: u32 = core::ptr::read((0x140035715_u64).wrapping_add(0x3c901b_u64) as *const u32);
    /* 14003570e */ r12 = (t_14003570e as u64);
    /* 140035715 */ let mut t_140035715_0: u32 = 0x0_u32;
    /* 140035715 */ r15 = (t_140035715_0 as u64);
    /* fallthrough -> bb2290 */

    // ---- bb2093 @ 0x14003571d ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb2097 */
    } else {
        /* -> bb2096 */
    }

    // ---- bb2096 @ 0x140035720 ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb2097 */
    } else {
        /* -> bb2160 */
    }

    // ---- bb2097 @ 0x140035726 ----
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2ce01e]
    /* 14003572e */ let mut t_14003572e: u32 = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u32);
    if (((SF == OF) & (t_14003572e != 0xb4_u32)) == false) { /* -> bb2102 */ }
    if (((SF == OF) & (t_14003572e != 0xb4_u32)) != 0) { /* -> bb2101 */ }

    // ---- bb2101 @ 0x140035738 ----
    if (((SF == OF) & (t_14003572e != 0xb4_u32)) == false) { /* -> bb2102 */ }
    if (((SF == OF) & (t_14003572e != 0xb4_u32)) != 0) { /* -> bb2138 */ }

    // ---- bb2102 @ 0x14003573e ----
    /* 14003573e */ rax = (0x140035745_u64).wrapping_add(0x2ce823_u64);
    /* 140035745 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 14003574a */ let mut t_14003574a: u32 = core::ptr::read((0x140035750_u64).wrapping_add(0x39ea64_u64) as *const u32);
    /* 14003574a */ rax = (t_14003574a as u64);
    /* 140035750 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm9
    /* 14003575b */ let mut t_14003575b_0: u32 = 0x0_u32;
    /* 14003575b */ r9 = (t_14003575b_0 as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce87a]
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2cdfe2]
    /* 14003576e */ xmm1 = xmm6;
    /* 140035771 */ rcx = core::ptr::read((0x140035778_u64).wrapping_add(0x3b86c0_u64) as *const u64);
    /* 140035778 */ fn_140086510();
    /* 14003577d */ let mut t_14003577d: u32 = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u32);
    /* 14003577d */ rax = (t_14003577d as u64);
    /* 140035783 */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140035784 */ let mut t_140035784_0: u32 = ((rax as u32)).wrapping_sub((rdx as u32));
    /* 140035784 */ rax = (t_140035784_0 as u64);
    /* 140035786 */ rax = (((((rax as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 140035788 */ rcx = (0x53_u32 as u64);
    if (SF == OF) {
        /* -> bb2120 */
    } else {
        /* -> bb2121 */
    }

    // ---- bb2121 @ 0x14003578f ----
    /* 14003578f */ rcx = ((rax as u32) as u64);
    /* fallthrough -> bb2120 */

    // ---- bb2120 @ 0x140035792 ----
    /* 140035792 */ xmm2 = ((rcx as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 140035799 */ let mut t_140035799: u32 = core::ptr::read((0x14003579f_u64).wrapping_add(0x39ea15_u64) as *const u32);
    /* 140035799 */ rax = (t_140035799 as u64);
    /* 14003579f */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 1400357a3 */ xmm3 = xmm10;
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2ce839]
    /* 1400357af */ xmm0 = xmm6;
    /* 1400357b2 */ fn_140070fb0();
    // intrinsic: 450f57e4 xorps xmm12, xmm12
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 1400357c2 */ xmm3 = xmm7;
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2cdbdf]
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2ce82b]
    /* 1400357d5 */ let mut t_1400357d5: u32 = core::ptr::read((0x1400357db_u64).wrapping_add(0x3b4925_u64) as *const u32);
    /* 1400357d5 */ rcx = (t_1400357d5 as u64);
    /* 1400357db */ fn_140071e80();
    /* fallthrough -> bb2139 */

    // ---- bb2138 @ 0x1400357e2 ----
    // intrinsic: 450f57e4 xorps xmm12, xmm12
    /* fallthrough -> bb2139 */

    // ---- bb2139 @ 0x1400357e6 ----
    /* 1400357e6 */ let mut t_1400357e6: u32 = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u32);
    /* 1400357e6 */ rax = (t_1400357e6 as u64);
    if (((SF != OF) | ((rax as u32) == 0xb4_u32)) == false) { /* -> bb2144 */ }
    if (((SF != OF) | ((rax as u32) == 0xb4_u32)) != 0) { /* -> bb2143 */ }

    // ---- bb2143 @ 0x1400357f1 ----
    if (((SF != OF) | ((rax as u32) == 0xb4_u32)) == false) { /* -> bb2144 */ }
    if (((SF != OF) | ((rax as u32) == 0xb4_u32)) != 0) { /* -> bb2291 */ }

    // ---- bb2144 @ 0x1400357f7 ----
    /* 1400357f7 */ let mut t_1400357f7_0: u32 = ((rax as u32)).wrapping_add(0xffffff4c_u32);
    /* 1400357f7 */ rax = (t_1400357f7_0 as u64);
    /* 1400357fc */ rcx = (0xe_u32 as u64);
    if (SF == OF) {
        /* -> bb2148 */
    } else {
        /* -> bb2149 */
    }

    // ---- bb2149 @ 0x140035803 ----
    /* 140035803 */ rcx = ((rax as u32) as u64);
    /* fallthrough -> bb2148 */

    // ---- bb2148 @ 0x140035806 ----
    /* 140035806 */ let mut t_140035806_0: u32 = (0x0_u32).wrapping_sub((rcx as u32));
    /* 140035806 */ rcx = (t_140035806_0 as u64);
    /* 140035808 */ xmm2 = ((rcx as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 14003580f */ let mut t_14003580f: u32 = core::ptr::read((0x140035815_u64).wrapping_add(0x39e94b_u64) as *const u32);
    /* 14003580f */ rax = (t_14003580f as u64);
    /* 140035815 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 140035819 */ xmm3 = xmm7;
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2ce7fc]
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2ce818]
    /* 14003582c */ fn_140070fb0();
    /* fallthrough -> bb2291 */

    // ---- bb2160 @ 0x140035836 ----
    if (((SF != OF) | ((rax as u32) == 0x5_u32)) == false) { /* -> bb2164 */ }
    if (((SF != OF) | ((rax as u32) == 0x5_u32)) != 0) { /* -> bb2163 */ }

    // ---- bb2163 @ 0x140035838 ----
    if (((SF != OF) | ((rax as u32) == 0x5_u32)) == false) { /* -> bb2164 */ }
    if (((SF != OF) | ((rax as u32) == 0x5_u32)) != 0) { /* -> bb2290 */ }

    // ---- bb2164 @ 0x14003583e ----
    /* 14003583e */ let mut t_14003583e: u32 = core::ptr::read((0x140035844_u64).wrapping_add(0x3b48bc_u64) as *const u32);
    /* 14003583e */ rcx = (t_14003583e as u64);
    /* 140035844 */ rcx = (((rcx as u32)).wrapping_sub(0x1_u32) as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2cdefe]
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2ce796]
    /* 140035856 */ fn_140071cd0();
    /* 14003585b */ rsi = r15;
    /* 14003585e */ rbx = (0xc_u32 as u64);
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2ce779]
    /* fallthrough -> bb2173 */

    // ---- bb2173 @ 0x140035870 ----
    /* 140035870 */ rax = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u64);
    /* 140035877 */ let mut t_140035877: u32 = core::ptr::read((rax).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u32);
    /* 140035877 */ r8 = ((t_140035877 as i64) as u64);
    /* 14003587b */ rax = core::ptr::read((rdi).wrapping_add(0x260_u64) as *const u64);
    /* 140035882 */ r8 = core::ptr::read((rax).wrapping_add((r8).wrapping_mul(0x8_u64)) as *const u64);
    /* 140035886 */ let mut t_140035886: u32 = core::ptr::read((r8).wrapping_add(0x224_u64) as *const u32);
    /* 140035886 */ r8 = (t_140035886 as u64);
    /* 14003588d */ rdx = (0x140035894_u64).wrapping_add(0x3668d0_u64);
    /* 140035894 */ rcx = (rbp).wrapping_sub(0x59_u64);
    /* 140035898 */ fn_14008d720();
    /* 14003589e */ let mut t_14003589e: u64 = core::ptr::read((rax).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_14003589e == 0xf_u64)) == false) { /* -> bb2186 */ }
    if ((CF | (t_14003589e == 0xf_u64)) != 0) { /* -> bb2185 */ }

    // ---- bb2185 @ 0x1400358a3 ----
    if ((CF | (t_14003589e == 0xf_u64)) == false) { /* -> bb2186 */ }
    if ((CF | (t_14003589e == 0xf_u64)) != 0) { /* -> bb2187 */ }

    // ---- bb2186 @ 0x1400358a5 ----
    /* 1400358a5 */ rax = core::ptr::read(rax as *const u64);
    /* fallthrough -> bb2187 */

    // ---- bb2187 @ 0x1400358a8 ----
    /* 1400358a8 */ xmm2 = ((rbx as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 1400358af */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 1400358b4 */ let mut t_1400358b4: u32 = core::ptr::read((0x1400358ba_u64).wrapping_add(0x39e8fa_u64) as *const u32);
    /* 1400358b4 */ rax = (t_1400358b4 as u64);
    /* 1400358ba */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm9
    /* 1400358c5 */ r9 = (0x1_u32 as u64);
    /* 1400358cb */ xmm1 = xmm6;
    /* 1400358ce */ rcx = core::ptr::read((0x1400358d5_u64).wrapping_add(0x3b8563_u64) as *const u64);
    /* 1400358d5 */ fn_140086510();
    /* 1400358db */ rdx = core::ptr::read((rbp).wrapping_sub(0x41_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2203 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2202 */ }

    // ---- bb2202 @ 0x1400358e3 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2203 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2219 */ }

    // ---- bb2203 @ 0x1400358e5 ----
    /* 1400358e5 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400358e8 */ rcx = core::ptr::read((rbp).wrapping_sub(0x59_u64) as *const u64);
    /* 1400358ec */ rax = rcx;
    if (CF == false) { /* -> bb2210 */ }
    if CF { /* -> bb2209 */ }

    // ---- bb2209 @ 0x1400358f6 ----
    if (CF == false) { /* -> bb2210 */ }
    if CF { /* -> bb2218 */ }

    // ---- bb2210 @ 0x1400358f8 ----
    /* 1400358f8 */ let mut t_1400358f8_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400358f8 */ rdx = t_1400358f8_0;
    /* 1400358fc */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140035900 */ let mut t_140035900_0: u64 = (rax).wrapping_sub(rcx);
    /* 140035900 */ rax = t_140035900_0;
    /* 140035903 */ let mut t_140035903_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140035903 */ rax = t_140035903_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2218 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2217 */ }

    // ---- bb2217 @ 0x14003590b ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2218 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2986 */ }

    // ---- bb2218 @ 0x140035911 ----
    /* 140035911 */ fn_1402c7498();
    /* fallthrough -> bb2219 */

    // ---- bb2219 @ 0x140035916 ----
    /* 140035916 */ let mut t_140035916_0: u32 = ((rbx as u32)).wrapping_add(0xc_u32);
    /* 140035916 */ rbx = (t_140035916_0 as u64);
    /* 140035919 */ let mut t_140035919_0: u64 = (rsi).wrapping_add(0x10_u64);
    /* 140035919 */ rsi = t_140035919_0;
    if (SF == OF) {
        /* -> bb2225 */
    } else {
        /* -> bb2224 */
    }

    // ---- bb2224 @ 0x140035920 ----
    if (SF != OF) {
        /* -> bb2173 */
    } else {
        /* -> bb2225 */
    }

    // ---- bb2225 @ 0x140035926 ----
    /* 140035926 */ rax = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u64);
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 8]
    // intrinsic: f30f58c9 addss xmm1, xmm1
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2ce6b6]
    // intrinsic: f30f58ce addss xmm1, xmm6
    /* 140035942 */ let mut t_140035942: u32 = core::ptr::read((0x140035948_u64).wrapping_add(0x3b47b8_u64) as *const u32);
    /* 140035942 */ rcx = (t_140035942 as u64);
    /* 140035948 */ let mut t_140035948: u32 = core::ptr::read((rax).wrapping_add(0x4_u64) as *const u32);
    if (((SF != OF) | (t_140035948 == 0x12c_u32)) == false) { /* -> bb2235 */ }
    if (((SF != OF) | (t_140035948 == 0x12c_u32)) != 0) { /* -> bb2234 */ }

    // ---- bb2234 @ 0x14003594f ----
    if (((SF != OF) | (t_140035948 == 0x12c_u32)) == false) { /* -> bb2235 */ }
    if (((SF != OF) | (t_140035948 == 0x12c_u32)) != 0) { /* -> bb2240 */ }

    // ---- bb2235 @ 0x140035951 ----
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm13
    /* 140035958 */ xmm3 = xmm9;
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2cda40]
    /* 140035964 */ fn_140071e80();
    /* fallthrough -> bb2242 */

    // ---- bb2240 @ 0x14003596b ----
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2cda1d]
    /* 140035973 */ fn_140071cd0();
    /* fallthrough -> bb2242 */

    // ---- bb2242 @ 0x140035978 ----
    /* 140035978 */ rax = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u64);
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0x18]
    // intrinsic: f30f58c9 addss xmm1, xmm1
    // intrinsic: f30f58ce addss xmm1, xmm6
    /* 14003598c */ let mut t_14003598c: u32 = core::ptr::read((0x140035992_u64).wrapping_add(0x3b476e_u64) as *const u32);
    /* 14003598c */ rcx = (t_14003598c as u64);
    /* 140035992 */ let mut t_140035992: u32 = core::ptr::read((rax).wrapping_add(0x14_u64) as *const u32);
    if (((SF != OF) | (t_140035992 == 0x12c_u32)) == false) { /* -> bb2251 */ }
    if (((SF != OF) | (t_140035992 == 0x12c_u32)) != 0) { /* -> bb2250 */ }

    // ---- bb2250 @ 0x140035999 ----
    if (((SF != OF) | (t_140035992 == 0x12c_u32)) == false) { /* -> bb2251 */ }
    if (((SF != OF) | (t_140035992 == 0x12c_u32)) != 0) { /* -> bb2256 */ }

    // ---- bb2251 @ 0x14003599b ----
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm13
    /* 1400359a2 */ xmm3 = xmm9;
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce632]
    /* 1400359ae */ fn_140071e80();
    /* fallthrough -> bb2258 */

    // ---- bb2256 @ 0x1400359b5 ----
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce613]
    /* 1400359bd */ fn_140071cd0();
    /* fallthrough -> bb2258 */

    // ---- bb2258 @ 0x1400359c2 ----
    /* 1400359c2 */ rax = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u64);
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0x28]
    // intrinsic: f30f58c9 addss xmm1, xmm1
    // intrinsic: f30f58ce addss xmm1, xmm6
    /* 1400359d6 */ let mut t_1400359d6: u32 = core::ptr::read((0x1400359dc_u64).wrapping_add(0x3b4724_u64) as *const u32);
    /* 1400359d6 */ rcx = (t_1400359d6 as u64);
    /* 1400359dc */ let mut t_1400359dc: u32 = core::ptr::read((rax).wrapping_add(0x24_u64) as *const u32);
    if (((SF != OF) | (t_1400359dc == 0x12c_u32)) == false) { /* -> bb2267 */ }
    if (((SF != OF) | (t_1400359dc == 0x12c_u32)) != 0) { /* -> bb2266 */ }

    // ---- bb2266 @ 0x1400359e3 ----
    if (((SF != OF) | (t_1400359dc == 0x12c_u32)) == false) { /* -> bb2267 */ }
    if (((SF != OF) | (t_1400359dc == 0x12c_u32)) != 0) { /* -> bb2272 */ }

    // ---- bb2267 @ 0x1400359e5 ----
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm13
    /* 1400359ec */ xmm3 = xmm9;
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce604]
    /* 1400359f8 */ fn_140071e80();
    /* fallthrough -> bb2274 */

    // ---- bb2272 @ 0x1400359ff ----
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce5e9]
    /* 140035a07 */ fn_140071cd0();
    /* fallthrough -> bb2274 */

    // ---- bb2274 @ 0x140035a0c ----
    /* 140035a0c */ rax = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u64);
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0x38]
    // intrinsic: f30f58c9 addss xmm1, xmm1
    // intrinsic: f30f58ce addss xmm1, xmm6
    /* 140035a20 */ let mut t_140035a20: u32 = core::ptr::read((0x140035a26_u64).wrapping_add(0x3b46da_u64) as *const u32);
    /* 140035a20 */ rcx = (t_140035a20 as u64);
    /* 140035a26 */ let mut t_140035a26: u32 = core::ptr::read((rax).wrapping_add(0x34_u64) as *const u32);
    if (((SF != OF) | (t_140035a26 == 0x12c_u32)) == false) { /* -> bb2283 */ }
    if (((SF != OF) | (t_140035a26 == 0x12c_u32)) != 0) { /* -> bb2282 */ }

    // ---- bb2282 @ 0x140035a2d ----
    if (((SF != OF) | (t_140035a26 == 0x12c_u32)) == false) { /* -> bb2283 */ }
    if (((SF != OF) | (t_140035a26 == 0x12c_u32)) != 0) { /* -> bb2288 */ }

    // ---- bb2283 @ 0x140035a2f ----
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm13
    /* 140035a36 */ xmm3 = xmm9;
    /* 140035a3a */ xmm2 = xmm12;
    /* 140035a3e */ fn_140071e80();
    /* fallthrough -> bb2290 */

    // ---- bb2288 @ 0x140035a45 ----
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce5b7]
    /* 140035a4d */ fn_140071cd0();
    /* fallthrough -> bb2290 */

    // ---- bb2290 @ 0x140035a52 ----
    // intrinsic: 450f57e4 xorps xmm12, xmm12
    /* fallthrough -> bb2291 */

    // ---- bb2291 @ 0x140035a56 ----
    /* 140035a56 */ let mut t_140035a56: u32 = core::ptr::read((rdi).wrapping_add(0x27c_u64) as *const u32);
    if (SF == OF) {
        /* -> bb2295 */
    } else {
        /* -> bb2294 */
    }

    // ---- bb2294 @ 0x140035a5d ----
    if (SF == OF) {
        /* -> bb2295 */
    } else {
        /* -> bb2498 */
    }

    // ---- bb2295 @ 0x140035a63 ----
    /* 140035a63 */ let mut t_140035a63: u32 = core::ptr::read((rdi).wrapping_add(0x6ac_u64) as *const u32);
    /* 140035a63 */ rax = (t_140035a63 as u64);
    /* 140035a69 */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140035a6a */ let mut t_140035a6a_0: u32 = ((rdx as u32) & 0x3_u32);
    /* 140035a6a */ rdx = (t_140035a6a_0 as u64);
    /* 140035a6d */ r9 = (((rdx).wrapping_add((rax).wrapping_mul(0x1_u64)) as u32) as u64);
    /* 140035a71 */ r9 = (((((r9 as u32) as i64) >> ((0x2_u8 as u32) as i64)) as u64) as u64);
    /* 140035a75 */ let mut t_140035a75: u32 = core::ptr::read((rdi).wrapping_add(0x278_u64) as *const u32);
    /* 140035a75 */ r8 = (t_140035a75 as u64);
    /* 140035a7c */ r8 = (((r8 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140035a7f */ rdx = (0x140035a86_u64).wrapping_add(0x2ce4f2_u64);
    /* 140035a86 */ rcx = (rbp).wrapping_sub(0x59_u64);
    /* 140035a8a */ fn_14008d720();
    /* 140035a90 */ let mut t_140035a90: u64 = core::ptr::read((rax).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_140035a90 == 0xf_u64)) == false) { /* -> bb2310 */ }
    if ((CF | (t_140035a90 == 0xf_u64)) != 0) { /* -> bb2309 */ }

    // ---- bb2309 @ 0x140035a95 ----
    if ((CF | (t_140035a90 == 0xf_u64)) == false) { /* -> bb2310 */ }
    if ((CF | (t_140035a90 == 0xf_u64)) != 0) { /* -> bb2311 */ }

    // ---- bb2310 @ 0x140035a97 ----
    /* 140035a97 */ rax = core::ptr::read(rax as *const u64);
    /* fallthrough -> bb2311 */

    // ---- bb2311 @ 0x140035a9a ----
    /* 140035a9a */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140035a9f */ let mut t_140035a9f: u32 = core::ptr::read((0x140035aa5_u64).wrapping_add(0x39e6df_u64) as *const u32);
    /* 140035a9f */ rax = (t_140035a9f as u64);
    /* 140035aa5 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm9
    /* 140035ab0 */ let mut t_140035ab0_0: u32 = 0x0_u32;
    /* 140035ab0 */ r9 = (t_140035ab0_0 as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce501]
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2ce585]
    /* 140035ac3 */ xmm1 = xmm6;
    /* 140035ac6 */ rcx = core::ptr::read((0x140035acd_u64).wrapping_add(0x3b836b_u64) as *const u64);
    /* 140035acd */ fn_140086510();
    /* 140035ad3 */ rdx = core::ptr::read((rbp).wrapping_sub(0x41_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2327 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2326 */ }

    // ---- bb2326 @ 0x140035adb ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2327 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2343 */ }

    // ---- bb2327 @ 0x140035add ----
    /* 140035add */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140035ae0 */ rcx = core::ptr::read((rbp).wrapping_sub(0x59_u64) as *const u64);
    /* 140035ae4 */ rax = rcx;
    if (CF == false) { /* -> bb2334 */ }
    if CF { /* -> bb2333 */ }

    // ---- bb2333 @ 0x140035aee ----
    if (CF == false) { /* -> bb2334 */ }
    if CF { /* -> bb2342 */ }

    // ---- bb2334 @ 0x140035af0 ----
    /* 140035af0 */ let mut t_140035af0_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140035af0 */ rdx = t_140035af0_0;
    /* 140035af4 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140035af8 */ let mut t_140035af8_0: u64 = (rax).wrapping_sub(rcx);
    /* 140035af8 */ rax = t_140035af8_0;
    /* 140035afb */ let mut t_140035afb_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140035afb */ rax = t_140035afb_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2342 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2341 */ }

    // ---- bb2341 @ 0x140035b03 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2342 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2993 */ }

    // ---- bb2342 @ 0x140035b09 ----
    /* 140035b09 */ fn_1402c7498();
    /* fallthrough -> bb2343 */

    // ---- bb2343 @ 0x140035b0e ----
    /* 140035b0e */ let mut t_140035b0e: u32 = core::ptr::read((rdi).wrapping_add(0x288_u64) as *const u32);
    /* 140035b0e */ r8 = (t_140035b0e as u64);
    /* 140035b15 */ r8 = (((r8 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140035b18 */ let mut t_140035b18: u32 = core::ptr::read((rdi).wrapping_add(0x6a8_u64) as *const u32);
    /* 140035b18 */ r9 = (t_140035b18 as u64);
    /* 140035b1f */ rdx = (0x140035b26_u64).wrapping_add(0x2ce45a_u64);
    /* 140035b26 */ rcx = (rbp).wrapping_sub(0x59_u64);
    /* 140035b2a */ fn_14008d720();
    /* 140035b30 */ let mut t_140035b30: u64 = core::ptr::read((rax).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_140035b30 == 0xf_u64)) == false) { /* -> bb2354 */ }
    if ((CF | (t_140035b30 == 0xf_u64)) != 0) { /* -> bb2353 */ }

    // ---- bb2353 @ 0x140035b35 ----
    if ((CF | (t_140035b30 == 0xf_u64)) == false) { /* -> bb2354 */ }
    if ((CF | (t_140035b30 == 0xf_u64)) != 0) { /* -> bb2355 */ }

    // ---- bb2354 @ 0x140035b37 ----
    /* 140035b37 */ rax = core::ptr::read(rax as *const u64);
    /* fallthrough -> bb2355 */

    // ---- bb2355 @ 0x140035b3a ----
    /* 140035b3a */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140035b3f */ let mut t_140035b3f: u32 = core::ptr::read((0x140035b45_u64).wrapping_add(0x39e63f_u64) as *const u32);
    /* 140035b3f */ rax = (t_140035b3f as u64);
    /* 140035b45 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm9
    /* 140035b50 */ let mut t_140035b50_0: u32 = 0x0_u32;
    /* 140035b50 */ r9 = (t_140035b50_0 as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce481]
    /* 140035b5b */ xmm1 = xmm6;
    /* 140035b5e */ rcx = core::ptr::read((0x140035b65_u64).wrapping_add(0x3b82d3_u64) as *const u64);
    /* 140035b65 */ fn_140086510();
    /* 140035b6b */ rdx = core::ptr::read((rbp).wrapping_sub(0x41_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2370 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2369 */ }

    // ---- bb2369 @ 0x140035b73 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2370 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2386 */ }

    // ---- bb2370 @ 0x140035b75 ----
    /* 140035b75 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140035b78 */ rcx = core::ptr::read((rbp).wrapping_sub(0x59_u64) as *const u64);
    /* 140035b7c */ rax = rcx;
    if (CF == false) { /* -> bb2377 */ }
    if CF { /* -> bb2376 */ }

    // ---- bb2376 @ 0x140035b86 ----
    if (CF == false) { /* -> bb2377 */ }
    if CF { /* -> bb2385 */ }

    // ---- bb2377 @ 0x140035b88 ----
    /* 140035b88 */ let mut t_140035b88_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140035b88 */ rdx = t_140035b88_0;
    /* 140035b8c */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140035b90 */ let mut t_140035b90_0: u64 = (rax).wrapping_sub(rcx);
    /* 140035b90 */ rax = t_140035b90_0;
    /* 140035b93 */ let mut t_140035b93_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140035b93 */ rax = t_140035b93_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2385 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2384 */ }

    // ---- bb2384 @ 0x140035b9b ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2385 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3000 */ }

    // ---- bb2385 @ 0x140035ba1 ----
    /* 140035ba1 */ fn_1402c7498();
    /* fallthrough -> bb2386 */

    // ---- bb2386 @ 0x140035ba6 ----
    /* 140035ba6 */ let mut t_140035ba6: u32 = core::ptr::read((rdi).wrapping_add(0x290_u64) as *const u32);
    /* 140035ba6 */ rcx = (t_140035ba6 as u64);
    if (rdx == 0xf_u64) {
        /* -> bb2391 */
    } else {
        /* -> bb2390 */
    }

    // ---- bb2390 @ 0x140035bae ----
    if (rdx == 0xf_u64) {
        /* -> bb2391 */
    } else {
        /* -> bb2393 */
    }

    // ---- bb2391 @ 0x140035bb0 ----
    /* 140035bb0 */ rax = ((r15 as u32) as u64);
    /* fallthrough -> bb2396 */

    // ---- bb2393 @ 0x140035bb5 ----
    /* 140035bb5 */ let mut t_140035bb5: u32 = core::ptr::read((rdi).wrapping_add(0x294_u64) as *const u32);
    /* 140035bb5 */ let mut t_140035bb5_0: u64 = ((t_140035bb5 as u64)).wrapping_mul((0x64_u32 as u64));
    /* 140035bb5 */ rax = ((t_140035bb5_0 as u32) as u64);
    /* 140035bbc */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140035bbd */ let mut t_140035bbd_0: u64 = (((((((rdx as u32) as u64) << 0x20_u64) | ((rax as u32) as u64)) as i64) / (((rcx as u32) as u64) as i64)) as u64);
    /* 140035bbd */ let mut t_140035bbd_1: u64 = (((((((rdx as u32) as u64) << 0x20_u64) | ((rax as u32) as u64)) as i64) % (((rcx as u32) as u64) as i64)) as u64);
    /* 140035bbd */ rax = ((t_140035bbd_0 as u32) as u64);
    /* 140035bbd */ rdx = ((t_140035bbd_1 as u32) as u64);
    /* fallthrough -> bb2396 */

    // ---- bb2396 @ 0x140035bbf ----
    /* 140035bbf */ r8 = ((rax as u32) as u64);
    /* 140035bc2 */ rdx = (0x140035bc9_u64).wrapping_add(0x2ce3bf_u64);
    /* 140035bc9 */ rcx = (rbp).wrapping_sub(0x59_u64);
    /* 140035bcd */ fn_14008d720();
    /* 140035bd3 */ let mut t_140035bd3: u64 = core::ptr::read((rax).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_140035bd3 == 0xf_u64)) == false) { /* -> bb2405 */ }
    if ((CF | (t_140035bd3 == 0xf_u64)) != 0) { /* -> bb2404 */ }

    // ---- bb2404 @ 0x140035bd8 ----
    if ((CF | (t_140035bd3 == 0xf_u64)) == false) { /* -> bb2405 */ }
    if ((CF | (t_140035bd3 == 0xf_u64)) != 0) { /* -> bb2406 */ }

    // ---- bb2405 @ 0x140035bda ----
    /* 140035bda */ rax = core::ptr::read(rax as *const u64);
    /* fallthrough -> bb2406 */

    // ---- bb2406 @ 0x140035bdd ----
    /* 140035bdd */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140035be2 */ let mut t_140035be2: u32 = core::ptr::read((0x140035be8_u64).wrapping_add(0x39e59c_u64) as *const u32);
    /* 140035be2 */ rax = (t_140035be2 as u64);
    /* 140035be8 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm9
    /* 140035bf3 */ let mut t_140035bf3_0: u32 = 0x0_u32;
    /* 140035bf3 */ r9 = (t_140035bf3_0 as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce3fa]
    /* 140035bfe */ xmm1 = xmm6;
    /* 140035c01 */ rcx = core::ptr::read((0x140035c08_u64).wrapping_add(0x3b8230_u64) as *const u64);
    /* 140035c08 */ fn_140086510();
    /* 140035c0e */ rdx = core::ptr::read((rbp).wrapping_sub(0x41_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2421 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2420 */ }

    // ---- bb2420 @ 0x140035c16 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2421 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2437 */ }

    // ---- bb2421 @ 0x140035c18 ----
    /* 140035c18 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140035c1b */ rcx = core::ptr::read((rbp).wrapping_sub(0x59_u64) as *const u64);
    /* 140035c1f */ rax = rcx;
    if (CF == false) { /* -> bb2428 */ }
    if CF { /* -> bb2427 */ }

    // ---- bb2427 @ 0x140035c29 ----
    if (CF == false) { /* -> bb2428 */ }
    if CF { /* -> bb2436 */ }

    // ---- bb2428 @ 0x140035c2b ----
    /* 140035c2b */ let mut t_140035c2b_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140035c2b */ rdx = t_140035c2b_0;
    /* 140035c2f */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140035c33 */ let mut t_140035c33_0: u64 = (rax).wrapping_sub(rcx);
    /* 140035c33 */ rax = t_140035c33_0;
    /* 140035c36 */ let mut t_140035c36_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140035c36 */ rax = t_140035c36_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2436 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2435 */ }

    // ---- bb2435 @ 0x140035c3e ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2436 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3007 */ }

    // ---- bb2436 @ 0x140035c44 ----
    /* 140035c44 */ fn_1402c7498();
    /* fallthrough -> bb2437 */

    // ---- bb2437 @ 0x140035c49 ----
    /* 140035c49 */ let mut t_140035c49: u32 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u32);
    /* 140035c49 */ rax = (t_140035c49 as u64);
    if (((SF != OF) | (rdx == 0xf_u64)) == false) { /* -> bb2442 */ }
    if (((SF != OF) | (rdx == 0xf_u64)) != 0) { /* -> bb2441 */ }

    // ---- bb2441 @ 0x140035c51 ----
    if (((SF != OF) | (rdx == 0xf_u64)) == false) { /* -> bb2442 */ }
    if (((SF != OF) | (rdx == 0xf_u64)) != 0) { /* -> bb2488 */ }

    // ---- bb2442 @ 0x140035c57 ----
    /* 140035c57 */ xmm0 = ((rax as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    // intrinsic: f30f5e05 divss xmm0, dword ptr [rip + 0x2ce3ae]
    // intrinsic: 0f5ad000 cvtps2pd xmm2, xmm0
    /* 140035c69 */ r8 = (xmm2 as u64);
    /* 140035c6e */ rdx = (0x140035c75_u64).wrapping_add(0x2ce31b_u64);
    /* 140035c75 */ rcx = (rbp).wrapping_sub(0x59_u64);
    /* 140035c79 */ fn_14008d720();
    /* 140035c7f */ let mut t_140035c7f: u64 = core::ptr::read((rax).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_140035c7f == 0xf_u64)) == false) { /* -> bb2455 */ }
    if ((CF | (t_140035c7f == 0xf_u64)) != 0) { /* -> bb2454 */ }

    // ---- bb2454 @ 0x140035c84 ----
    if ((CF | (t_140035c7f == 0xf_u64)) == false) { /* -> bb2455 */ }
    if ((CF | (t_140035c7f == 0xf_u64)) != 0) { /* -> bb2456 */ }

    // ---- bb2455 @ 0x140035c86 ----
    /* 140035c86 */ rax = core::ptr::read(rax as *const u64);
    /* fallthrough -> bb2456 */

    // ---- bb2456 @ 0x140035c89 ----
    /* 140035c89 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140035c8e */ let mut t_140035c8e: u32 = core::ptr::read((0x140035c94_u64).wrapping_add(0x39e4f0_u64) as *const u32);
    /* 140035c8e */ rax = (t_140035c8e as u64);
    /* 140035c94 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm9
    /* 140035c9f */ let mut t_140035c9f_0: u32 = 0x0_u32;
    /* 140035c9f */ r9 = (t_140035c9f_0 as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce35e]
    /* 140035caa */ xmm1 = xmm6;
    /* 140035cad */ rcx = core::ptr::read((0x140035cb4_u64).wrapping_add(0x3b8184_u64) as *const u64);
    /* 140035cb4 */ fn_140086510();
    /* 140035cba */ rdx = core::ptr::read((rbp).wrapping_sub(0x41_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2471 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2470 */ }

    // ---- bb2470 @ 0x140035cc2 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2471 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2498 */ }

    // ---- bb2471 @ 0x140035cc4 ----
    /* 140035cc4 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140035cc7 */ rcx = core::ptr::read((rbp).wrapping_sub(0x59_u64) as *const u64);
    /* 140035ccb */ rax = rcx;
    if (CF == false) { /* -> bb2478 */ }
    if CF { /* -> bb2477 */ }

    // ---- bb2477 @ 0x140035cd5 ----
    if (CF == false) { /* -> bb2478 */ }
    if CF { /* -> bb2486 */ }

    // ---- bb2478 @ 0x140035cd7 ----
    /* 140035cd7 */ let mut t_140035cd7_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140035cd7 */ rdx = t_140035cd7_0;
    /* 140035cdb */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140035cdf */ let mut t_140035cdf_0: u64 = (rax).wrapping_sub(rcx);
    /* 140035cdf */ rax = t_140035cdf_0;
    /* 140035ce2 */ let mut t_140035ce2_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140035ce2 */ rax = t_140035ce2_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2486 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2485 */ }

    // ---- bb2485 @ 0x140035cea ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2486 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3014 */ }

    // ---- bb2486 @ 0x140035cf0 ----
    /* 140035cf0 */ fn_1402c7498();
    /* fallthrough -> bb2498 */

    // ---- bb2488 @ 0x140035cf7 ----
    /* 140035cf7 */ rax = (0x140035cfe_u64).wrapping_add(0x2ce29a_u64);
    /* 140035cfe */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140035d03 */ let mut t_140035d03: u32 = core::ptr::read((0x140035d09_u64).wrapping_add(0x39e47b_u64) as *const u32);
    /* 140035d03 */ rax = (t_140035d03 as u64);
    /* 140035d09 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm9
    /* 140035d14 */ let mut t_140035d14_0: u32 = 0x0_u32;
    /* 140035d14 */ r9 = (t_140035d14_0 as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce2e9]
    /* 140035d1f */ xmm1 = xmm6;
    /* 140035d22 */ rcx = core::ptr::read((0x140035d29_u64).wrapping_add(0x3b810f_u64) as *const u64);
    /* 140035d29 */ fn_140086510();
    /* fallthrough -> bb2498 */

    // ---- bb2498 @ 0x140035d2e ----
    /* 140035d2e */ fn_1400730b0();
    /* 140035d33 */ let mut t_140035d33: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140035d33 == 0x3_u32) {
        /* -> bb2503 */
    } else {
        /* -> bb2502 */
    }

    // ---- bb2502 @ 0x140035d3a ----
    if (t_140035d33 == 0x3_u32) {
        /* -> bb2503 */
    } else {
        /* -> bb2515 */
    }

    // ---- bb2503 @ 0x140035d3c ----
    /* 140035d3c */ let mut t_140035d3c: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140035d3c */ rax = (t_140035d3c as u64);
    /* 140035d42 */ let mut t_140035d42_0: u32 = ((rax as u32)).wrapping_sub(0x5a_u32);
    /* 140035d42 */ rax = (t_140035d42_0 as u64);
    /* 140035d45 */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140035d46 */ let mut t_140035d46_0: u32 = ((rax as u32)).wrapping_sub((rdx as u32));
    /* 140035d46 */ rax = (t_140035d46_0 as u64);
    /* 140035d48 */ rax = (((((rax as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 140035d4a */ rcx = ((rax as u32) as u64);
    /* 140035d4c */ let mut t_140035d4c_0: u32 = 0x0_u32;
    /* 140035d4c */ rdx = (t_140035d4c_0 as u64);
    /* 140035d4e */ r8 = (0x58_u32 as u64);
    /* 140035d54 */ fn_1400c6360();
    /* 140035d59 */ rsi = (0x8_u32 as u64);
    /* 140035d5e */ let mut t_140035d5e_0: u32 = ((rsi as u32)).wrapping_sub((rax as u32));
    /* 140035d5e */ rsi = (t_140035d5e_0 as u64);
    /* fallthrough -> bb2520 */

    // ---- bb2515 @ 0x140035d62 ----
    /* 140035d62 */ rsi = (0x8_u32 as u64);
    /* 140035d67 */ rcx = (0xffffffb0_u32 as u64);
    if (((SF == OF) & (t_140035d33 != 0x3_u32)) == false) { /* -> bb2520 */ }
    if (((SF == OF) & (t_140035d33 != 0x3_u32)) != 0) { /* -> bb2519 */ }

    // ---- bb2519 @ 0x140035d6c ----
    /* 140035d6c */ rsi = ((rcx as u32) as u64);
    /* fallthrough -> bb2520 */

    // ---- bb2520 @ 0x140035d6f ----
    /* 140035d6f */ rbx = ((rsi as u32) as u64);
    /* 140035d71 */ r14 = (0x8_u32 as u64);
    // intrinsic: f3440f10 movss xmm10, dword ptr [rip + 0x2ce240]
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2ce2c8]
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x2ce293]
    /* fallthrough -> bb2525 */

    // ---- bb2525 @ 0x140035d91 ----
    /* 140035d91 */ xmm6 = ((rbx as u32) as u128);
    // intrinsic: 0f5bf600 cvtdq2ps xmm6, xmm6
    /* 140035d98 */ let mut t_140035d98: u32 = core::ptr::read((0x140035d9e_u64).wrapping_add(0x39e3c2_u64) as *const u32);
    /* 140035d98 */ rax = (t_140035d98 as u64);
    /* 140035d9e */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 140035da2 */ xmm3 = xmm10;
    /* 140035da6 */ xmm2 = xmm7;
    /* 140035da9 */ xmm1 = xmm6;
    /* 140035dac */ xmm0 = xmm8;
    /* 140035db0 */ fn_140070fb0();
    /* 140035db5 */ let mut t_140035db5: u32 = core::ptr::read((0x140035dbb_u64).wrapping_add(0x39e389_u64) as *const u32);
    /* 140035db5 */ rax = (t_140035db5 as u64);
    /* 140035dbb */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 140035dbf */ xmm3 = xmm9;
    /* 140035dc3 */ xmm2 = xmm7;
    /* 140035dc6 */ xmm1 = xmm6;
    /* 140035dc9 */ xmm0 = xmm8;
    /* 140035dcd */ fn_140070fb0();
    /* 140035dd2 */ let mut t_140035dd2_0: u32 = ((rbx as u32)).wrapping_add(0xb_u32);
    /* 140035dd2 */ rbx = (t_140035dd2_0 as u64);
    /* 140035dd5 */ let mut t_140035dd5_0: u64 = (r14).wrapping_sub(0x1_u64);
    /* 140035dd5 */ r14 = t_140035dd5_0;
    if (t_140035d33 == 0x3_u32) {
        /* -> bb2546 */
    } else {
        /* -> bb2545 */
    }

    // ---- bb2545 @ 0x140035dd9 ----
    if (t_140035d33 != 0x3_u32) {
        /* -> bb2525 */
    } else {
        /* -> bb2546 */
    }

    // ---- bb2546 @ 0x140035ddb ----
    /* 140035ddb */ rax = (((rsi).wrapping_add(0x53_u64) as u32) as u64);
    /* 140035dde */ xmm1 = ((rax as u32) as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    /* 140035de5 */ let mut t_140035de5: u32 = core::ptr::read((0x140035deb_u64).wrapping_add(0x39e359_u64) as *const u32);
    /* 140035de5 */ rax = (t_140035de5 as u64);
    /* 140035deb */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x2cd599]
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2cd5a5]
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2ce245]
    /* 140035e07 */ fn_140070fb0();
    /* 140035e0c */ let mut t_140035e0c: u32 = core::ptr::read((0x140035e12_u64).wrapping_add(0x39e342_u64) as *const u32);
    /* 140035e0c */ rax = (t_140035e0c as u64);
    /* 140035e12 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x2ce212]
    /* 140035e1e */ xmm2 = xmm7;
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2ce253]
    /* 140035e29 */ xmm0 = xmm8;
    /* 140035e2d */ fn_140070fb0();
    /* 140035e32 */ let mut t_140035e32: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 140035e32 */ rax = (t_140035e32 as u64);
    if (t_140035d33 != 0x3_u32) {
        /* -> bb2567 */
    } else {
        /* -> bb2566 */
    }

    // ---- bb2566 @ 0x140035e3a ----
    if (t_140035d33 != 0x3_u32) {
        /* -> bb2567 */
    } else {
        /* -> bb2777 */
    }

    // ---- bb2567 @ 0x140035e40 ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb2571 */
    } else {
        /* -> bb2570 */
    }

    // ---- bb2570 @ 0x140035e43 ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb2571 */
    } else {
        /* -> bb2576 */
    }

    // ---- bb2571 @ 0x140035e45 ----
    /* 140035e45 */ let mut t_140035e45: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (((SF != OF) | (t_140035e45 == 0x3c_u32)) == false) { /* -> bb2575 */ }
    if (((SF != OF) | (t_140035e45 == 0x3c_u32)) != 0) { /* -> bb2574 */ }

    // ---- bb2574 @ 0x140035e4c ----
    if (((SF != OF) | (t_140035e45 == 0x3c_u32)) == false) { /* -> bb2575 */ }
    if (((SF != OF) | (t_140035e45 == 0x3c_u32)) != 0) { /* -> bb2576 */ }

    // ---- bb2575 @ 0x140035e4e ----
    /* 140035e4e */ let mut t_140035e4e: u32 = core::ptr::read((rdi).wrapping_add(0x698_u64) as *const u32);
    /* 140035e4e */ core::ptr::write((rdi).wrapping_add(0x698_u64) as *mut u32, (t_140035e4e).wrapping_add(0x1_u32));
    /* fallthrough -> bb2576 */

    // ---- bb2576 @ 0x140035e54 ----
    /* 140035e54 */ rcx = ((r15 as u32) as u64);
    /* 140035e57 */ let mut t_140035e57: u32 = core::ptr::read((rdi).wrapping_add(0x694_u64) as *const u32);
    /* 140035e5e */ rcx = ((rcx & 0xffffffffffffff00_u64) | ((((SF == OF) & (ZF == false)) as u8) as u64));
    /* 140035e61 */ let mut t_140035e61_0: u32 = ((rcx as u32)).wrapping_add(0x2_u32);
    /* 140035e61 */ rcx = (t_140035e61_0 as u64);
    /* 140035e64 */ let mut t_140035e64: u32 = core::ptr::read((rdi).wrapping_add(0x690_u64) as *const u32);
    /* 140035e64 */ rax = (t_140035e64 as u64);
    /* 140035e6a */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140035e6b */ let mut t_140035e6b_0: u32 = ((rdx as u32) & 0x1f_u32);
    /* 140035e6b */ rdx = (t_140035e6b_0 as u64);
    /* 140035e6e */ r12 = (((rdx).wrapping_add((rax).wrapping_mul(0x1_u64)) as u32) as u64);
    /* 140035e72 */ r12 = (((((r12 as u32) as i64) >> ((0x5_u8 as u32) as i64)) as u64) as u64);
    /* 140035e76 */ let mut t_140035e76_0: u32 = ((r12 as u32)).wrapping_sub((rcx as u32));
    /* 140035e76 */ r12 = (t_140035e76_0 as u64);
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2ce1df]
    if (((SF != OF) | (t_140035e57 == 0x0_u32)) == false) { /* -> bb2591 */ }
    if (((SF != OF) | (t_140035e57 == 0x0_u32)) != 0) { /* -> bb2590 */ }

    // ---- bb2590 @ 0x140035e84 ----
    if (((SF != OF) | (t_140035e57 == 0x0_u32)) == false) { /* -> bb2591 */ }
    if (((SF != OF) | (t_140035e57 == 0x0_u32)) != 0) { /* -> bb2602 */ }

    // ---- bb2591 @ 0x140035e86 ----
    /* 140035e86 */ xmm3 = ((r12 as u32) as u128);
    // intrinsic: 0f5bdb00 cvtdq2ps xmm3, xmm3
    /* 140035e8e */ rcx = (0x5b_u32 as u64);
    /* 140035e93 */ let mut t_140035e93_0: u32 = ((rcx as u32)).wrapping_sub((r12 as u32));
    /* 140035e93 */ rcx = (t_140035e93_0 as u64);
    /* 140035e96 */ xmm1 = ((rcx as u32) as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    /* 140035e9d */ let mut t_140035e9d: u32 = core::ptr::read((0x140035ea3_u64).wrapping_add(0x39e305_u64) as *const u32);
    /* 140035e9d */ rcx = (t_140035e9d as u64);
    /* 140035ea3 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rcx as u32));
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ce14d]
    /* 140035eaf */ xmm0 = xmm6;
    /* 140035eb2 */ fn_140070fb0();
    /* fallthrough -> bb2602 */

    // ---- bb2602 @ 0x140035eb7 ----
    /* 140035eb7 */ let mut t_140035eb7: u32 = core::ptr::read((rdi).wrapping_add(0x694_u64) as *const u32);
    /* 140035eb7 */ rcx = (t_140035eb7 as u64);
    if (((SF != OF) | (t_140035e57 == 0x0_u32)) == false) { /* -> bb2607 */ }
    if (((SF != OF) | (t_140035e57 == 0x0_u32)) != 0) { /* -> bb2606 */ }

    // ---- bb2606 @ 0x140035ebf ----
    if (((SF != OF) | (t_140035e57 == 0x0_u32)) == false) { /* -> bb2607 */ }
    if (((SF != OF) | (t_140035e57 == 0x0_u32)) != 0) { /* -> bb2629 */ }

    // ---- bb2607 @ 0x140035ec1 ----
    /* 140035ec1 */ rcx = (((rcx as u32)).wrapping_sub(0x1_u32) as u64);
    /* 140035ec3 */ core::ptr::write((rdi).wrapping_add(0x694_u64) as *mut u32, (rcx as u32));
    /* 140035ec9 */ let mut t_140035ec9_0: u32 = ((r13 as u32)).wrapping_sub((r12 as u32));
    /* 140035ec9 */ r13 = (t_140035ec9_0 as u64);
    /* 140035ecc */ xmm2 = ((r13 as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 140035ed4 */ rax = (0x55555556_u32 as u64);
    /* 140035ed9 */ let mut t_140035ed9_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 140035ed9 */ rdx = (((t_140035ed9_0 >> 0x20_u64) as u32) as u64);
    /* 140035ed9 */ rax = ((t_140035ed9_0 as u32) as u64);
    /* 140035edb */ r8 = ((rdx as u32) as u64);
    /* 140035ede */ r8 = (((r8 as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140035ee2 */ let mut t_140035ee2_0: u32 = ((r8 as u32)).wrapping_add((rdx as u32));
    /* 140035ee2 */ r8 = (t_140035ee2_0 as u64);
    /* 140035ee5 */ rax = (0x55555556_u32 as u64);
    /* 140035eea */ let mut t_140035eea_0: u64 = (((rax as u32) as u64)).wrapping_mul(((r8 as u32) as u64));
    /* 140035eea */ rdx = (((t_140035eea_0 >> 0x20_u64) as u32) as u64);
    /* 140035eea */ rax = ((t_140035eea_0 as u32) as u64);
    /* 140035eed */ rax = ((rdx as u32) as u64);
    /* 140035eef */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140035ef2 */ let mut t_140035ef2_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 140035ef2 */ rdx = (t_140035ef2_0 as u64);
    /* 140035ef4 */ rax = (((rdx).wrapping_add((rdx).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 140035ef7 */ let mut t_140035ef7_0: u32 = ((r8 as u32)).wrapping_sub((rax as u32));
    /* 140035ef7 */ r8 = (t_140035ef7_0 as u64);
    /* 140035efa */ let mut t_140035efa: u32 = core::ptr::read((0x140035f00_u64).wrapping_add(0x3b41f8_u64) as *const u32);
    /* 140035efa */ rcx = (t_140035efa as u64);
    /* 140035f00 */ let mut t_140035f00_0: u32 = ((rcx as u32)).wrapping_add(0x7_u32);
    /* 140035f00 */ rcx = (t_140035f00_0 as u64);
    /* 140035f03 */ let mut t_140035f03_0: u32 = ((rcx as u32)).wrapping_add((r8 as u32));
    /* 140035f03 */ rcx = (t_140035f03_0 as u64);
    /* 140035f06 */ xmm1 = xmm6;
    /* 140035f09 */ fn_140071cd0();
    /* fallthrough -> bb2629 */

    // ---- bb2629 @ 0x140035f0e ----
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2ce102]
    /* 140035f16 */ xmm0 = xmm6;
    /* 140035f19 */ fn_140072e90();
    /* 140035f1e */ rcx = (0x201_u32 as u64);
    /* 140035f23 */ fn_1400c6990();
    /* 140035f28 */ r8 = (((rax as u32) as i64) as u64);
    /* 140035f2b */ r14 = ((r15 as u32) as u64);
    /* 140035f2e */ rsi = core::ptr::read((rdi).wrapping_add(0x678_u64) as *const u64);
    /* 140035f35 */ rcx = core::ptr::read((rdi).wrapping_add(0x680_u64) as *const u64);
    /* 140035f3c */ let mut t_140035f3c_0: u64 = (rcx).wrapping_sub(rsi);
    /* 140035f3c */ rcx = t_140035f3c_0;
    /* 140035f3f */ rax = 0x2aaaaaaaaaaaaaab_u64;
    /* 140035f49 */ let mut t_140035f49_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 140035f49 */ rdx = ((t_140035f49_0 >> 0x40_u128) as u64);
    /* 140035f49 */ rax = (t_140035f49_0 as u64);
    /* 140035f4c */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 140035f4f */ rax = rdx;
    /* 140035f52 */ rax = (rax >> (0x3f_u8 as u64));
    /* 140035f56 */ let mut t_140035f56_0: u64 = (rdx).wrapping_add(rax);
    /* 140035f56 */ rdx = t_140035f56_0;
    if (t_140035e57 != 0x0_u32) {
        /* -> bb2648 */
    } else {
        /* -> bb2647 */
    }

    // ---- bb2647 @ 0x140035f59 ----
    if (t_140035e57 != 0x0_u32) {
        /* -> bb2648 */
    } else {
        /* -> bb2722 */
    }

    // ---- bb2648 @ 0x140035f5f ----
    /* 140035f5f */ r13 = r8;
    /* 140035f62 */ let mut t_140035f62_0: u32 = 0x0_u32;
    /* 140035f62 */ rbx = (t_140035f62_0 as u64);
    /* fallthrough -> bb2650 */

    // ---- bb2650 @ 0x140035f64 ----
    /* 140035f64 */ let mut t_140035f64: u32 = core::ptr::read((rdi).wrapping_add(0x694_u64) as *const u32);
    /* 140035f64 */ rax = (t_140035f64 as u64);
    if (((SF != OF) | (rax == rdx)) == false) { /* -> bb2655 */ }
    if (((SF != OF) | (rax == rdx)) != 0) { /* -> bb2654 */ }

    // ---- bb2654 @ 0x140035f6c ----
    if (((SF != OF) | (rax == rdx)) == false) { /* -> bb2655 */ }
    if (((SF != OF) | (rax == rdx)) != 0) { /* -> bb2668 */ }

    // ---- bb2655 @ 0x140035f6e ----
    /* 140035f6e */ rcx = (((rax).wrapping_add((r14).wrapping_mul(0x1_u64)) as u32) as u64);
    /* 140035f72 */ rax = (0x66666667_u32 as u64);
    /* 140035f77 */ let mut t_140035f77_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 140035f77 */ rdx = (((t_140035f77_0 >> 0x20_u64) as u32) as u64);
    /* 140035f77 */ rax = ((t_140035f77_0 as u32) as u64);
    /* 140035f79 */ rdx = (((((rdx as u32) as i64) >> ((0x2_u8 as u32) as i64)) as u64) as u64);
    /* 140035f7c */ rax = ((rdx as u32) as u64);
    /* 140035f7e */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140035f81 */ let mut t_140035f81_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 140035f81 */ rdx = (t_140035f81_0 as u64);
    /* 140035f83 */ rax = (((rdx).wrapping_add((rdx).wrapping_mul(0x4_u64)) as u32) as u64);
    /* 140035f86 */ let mut t_140035f86_0: u32 = ((rax as u32)).wrapping_add((rax as u32));
    /* 140035f86 */ rax = (t_140035f86_0 as u64);
    if ((rcx as u32) != (rax as u32)) {
        /* -> bb2668 */
    } else {
        /* -> bb2667 */
    }

    // ---- bb2667 @ 0x140035f8a ----
    if ((rcx as u32) != (rax as u32)) {
        /* -> bb2668 */
    } else {
        /* -> bb2672 */
    }

    // ---- bb2668 @ 0x140035f8c ----
    if (r13 == r15) {
        /* -> bb2672 */
    } else {
        /* -> bb2671 */
    }

    // ---- bb2671 @ 0x140035f8f ----
    if (r13 == r15) {
        /* -> bb2672 */
    } else {
        /* -> bb2693 */
    }

    // ---- bb2672 @ 0x140035f91 ----
    /* 140035f91 */ fn_1400c6ad0();
    /* 140035f96 */ rax = (((rax as u8) as u32) as u64);
    /* 140035f99 */ let mut t_140035f99_0: u32 = ((rax as u32)).wrapping_add((rax as u32));
    /* 140035f99 */ rax = (t_140035f99_0 as u64);
    /* 140035f9b */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    /* 140035f9d */ let mut t_140035f9d: u32 = core::ptr::read((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u32);
    /* 140035f9d */ let mut t_140035f9d_0: u32 = (t_140035f9d).wrapping_add((rax as u32));
    /* 140035f9d */ core::ptr::write((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *mut u32, t_140035f9d_0);
    /* 140035fa0 */ fn_1400c6ad0();
    /* 140035fa5 */ rax = (((rax as u8) as u32) as u64);
    /* 140035fa8 */ let mut t_140035fa8_0: u32 = ((rax as u32)).wrapping_add((rax as u32));
    /* 140035fa8 */ rax = (t_140035fa8_0 as u64);
    /* 140035faa */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    /* 140035fac */ let mut t_140035fac: u32 = core::ptr::read(((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x4_u64) as *const u32);
    /* 140035fac */ let mut t_140035fac_0: u32 = (t_140035fac).wrapping_add((rax as u32));
    /* 140035fac */ core::ptr::write(((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x4_u64) as *mut u32, t_140035fac_0);
    /* 140035fb0 */ let mut t_140035fb0_0: u32 = 0x0_u32;
    /* 140035fb0 */ rdx = (t_140035fb0_0 as u64);
    /* 140035fb2 */ r8 = (0x23_u32 as u64);
    /* 140035fb8 */ let mut t_140035fb8: u32 = core::ptr::read((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u32);
    /* 140035fb8 */ rcx = (t_140035fb8 as u64);
    /* 140035fbb */ fn_1400c6360();
    /* 140035fc0 */ core::ptr::write((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *mut u32, (rax as u32));
    /* 140035fc3 */ rdx = (0x1e_u32 as u64);
    /* 140035fc8 */ let mut t_140035fc8_0: u32 = ((rdx as u32)).wrapping_sub((r12 as u32));
    /* 140035fc8 */ rdx = (t_140035fc8_0 as u64);
    /* 140035fcb */ r8 = (0x1e_u32 as u64);
    /* 140035fd1 */ let mut t_140035fd1: u32 = core::ptr::read(((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x4_u64) as *const u32);
    /* 140035fd1 */ rcx = (t_140035fd1 as u64);
    /* 140035fd5 */ fn_1400c6360();
    /* 140035fda */ core::ptr::write(((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x4_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb2693 */

    // ---- bb2693 @ 0x140035fde ----
    /* 140035fde */ let mut t_140035fde: u32 = core::ptr::read(((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *const u32);
    /* 140035fde */ rax = ((t_140035fde as i64) as u64);
    /* 140035fe3 */ let mut t_140035fe3: u32 = core::ptr::read(((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x4_u64) as *const u32);
    /* 140035fe3 */ xmm1 = (t_140035fe3 as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    /* 140035fec */ let mut t_140035fec: u32 = core::ptr::read((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u32);
    /* 140035fec */ xmm0 = (t_140035fec as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    /* 140035ff4 */ rcx = (0x140035ffb_u64).wrapping_add(0x3b40a5_u64);
    /* 140035ffb */ let mut t_140035ffb: u32 = core::ptr::read((rcx).wrapping_add((rax).wrapping_mul(0x4_u64)) as *const u32);
    /* 140035ffb */ rax = (t_140035ffb as u64);
    /* 140035ffe */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 140036002 */ xmm3 = xmm9;
    /* 140036006 */ xmm2 = xmm9;
    /* 14003600a */ fn_140070fb0();
    /* 14003600f */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140036012 */ r15 = (r15).wrapping_add(0x1_u64);
    /* 140036015 */ let mut t_140036015_0: u64 = (rbx).wrapping_add(0xc_u64);
    /* 140036015 */ rbx = t_140036015_0;
    /* 140036019 */ rsi = core::ptr::read((rdi).wrapping_add(0x678_u64) as *const u64);
    /* 140036020 */ rcx = core::ptr::read((rdi).wrapping_add(0x680_u64) as *const u64);
    /* 140036027 */ let mut t_140036027_0: u64 = (rcx).wrapping_sub(rsi);
    /* 140036027 */ rcx = t_140036027_0;
    /* 14003602a */ rax = 0x2aaaaaaaaaaaaaab_u64;
    /* 140036034 */ let mut t_140036034_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 140036034 */ rdx = ((t_140036034_0 >> 0x40_u128) as u64);
    /* 140036034 */ rax = (t_140036034_0 as u64);
    /* 140036037 */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 14003603a */ rax = rdx;
    /* 14003603d */ rax = (rax >> (0x3f_u8 as u64));
    /* 140036041 */ let mut t_140036041_0: u64 = (rdx).wrapping_add(rax);
    /* 140036041 */ rdx = t_140036041_0;
    /* 140036044 */ rax = (((r14 as u32) as i64) as u64);
    if (CF == false) { /* -> bb2721 */ }
    if CF { /* -> bb2720 */ }

    // ---- bb2720 @ 0x14003604a ----
    if CF { /* -> bb2650 */ }
    if (CF == false) { /* -> bb2721 */ }

    // ---- bb2721 @ 0x140036050 ----
    /* 140036050 */ let mut t_140036050_0: u32 = 0x0_u32;
    /* 140036050 */ r15 = (t_140036050_0 as u64);
    /* fallthrough -> bb2722 */

    // ---- bb2722 @ 0x140036053 ----
    /* 140036053 */ fn_1400730b0();
    /* 140036058 */ let mut t_140036058: u32 = core::ptr::read((rdi).wrapping_add(0xd4_u64) as *const u32);
    /* 140036058 */ rax = ((t_140036058 as i64) as u64);
    if ((rax as u32) != 0xffffffff_u32) {
        /* -> bb2728 */
    } else {
        /* -> bb2727 */
    }

    // ---- bb2727 @ 0x140036062 ----
    if ((rax as u32) != 0xffffffff_u32) {
        /* -> bb2728 */
    } else {
        /* -> bb2776 */
    }

    // ---- bb2728 @ 0x140036068 ----
    /* 140036068 */ rcx = rax;
    /* 14003606b */ rax = core::ptr::read((rdi).wrapping_add(0xb8_u64) as *const u64);
    /* 140036072 */ rcx = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 140036076 */ let mut t_140036076: u32 = core::ptr::read((rcx).wrapping_add(0xc_u64) as *const u32);
    if (t_140036076 == 0xc_u32) {
        /* -> bb2735 */
    } else {
        /* -> bb2734 */
    }

    // ---- bb2734 @ 0x14003607a ----
    if (t_140036076 == 0xc_u32) {
        /* -> bb2735 */
    } else {
        /* -> bb2776 */
    }

    // ---- bb2735 @ 0x140036080 ----
    /* 140036080 */ let mut t_140036080: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140036080 == 0x3_u32) {
        /* -> bb2739 */
    } else {
        /* -> bb2738 */
    }

    // ---- bb2738 @ 0x140036087 ----
    if (t_140036080 == 0x3_u32) {
        /* -> bb2739 */
    } else {
        /* -> bb2776 */
    }

    // ---- bb2739 @ 0x14003608d ----
    /* 14003608d */ rbx = (0x4_u32 as u64);
    /* 140036092 */ let mut t_140036092: u32 = core::ptr::read((rdi).wrapping_add(0x27c_u64) as *const u32);
    if (t_140036092 == 0x0_u32) {
        /* -> bb2744 */
    } else {
        /* -> bb2743 */
    }

    // ---- bb2743 @ 0x140036099 ----
    if (t_140036092 == 0x0_u32) {
        /* -> bb2744 */
    } else {
        /* -> bb2774 */
    }

    // ---- bb2744 @ 0x14003609b ----
    /* 14003609b */ let mut t_14003609b: u32 = core::ptr::read((0x1400360a2_u64).wrapping_add(0x3c868e_u64) as *const u32);
    /* 14003609b */ r12 = (t_14003609b as u64);
    /* 1400360a2 */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 1400360ab */ rax = core::ptr::read((rax).wrapping_add((r12).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400360af */ let mut t_1400360af: u32 = core::ptr::read((rbx).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 1400360af */ rax = (t_1400360af as u64);
    /* 1400360b2 */ let mut t_1400360b2: u32 = core::ptr::read((0x1400360b8_u64).wrapping_add(0x3b405c_u64) as *const u32);
    if (((SF == OF) & (t_1400360b2 != (rax as u32))) == false) { /* -> bb2752 */ }
    if (((SF == OF) & (t_1400360b2 != (rax as u32))) != 0) { /* -> bb2751 */ }

    // ---- bb2751 @ 0x1400360b8 ----
    if (((SF == OF) & (t_1400360b2 != (rax as u32))) == false) { /* -> bb2752 */ }
    if (((SF == OF) & (t_1400360b2 != (rax as u32))) != 0) { /* -> bb3021 */ }

    // ---- bb2752 @ 0x1400360be ----
    /* 1400360be */ let mut t_1400360be: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 1400360be */ rcx = (t_1400360be as u64);
    /* 1400360c4 */ rax = (0x88888889_u32 as u64);
    /* 1400360c9 */ let mut t_1400360c9_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 1400360c9 */ rdx = (((t_1400360c9_0 >> 0x20_u64) as u32) as u64);
    /* 1400360c9 */ rax = ((t_1400360c9_0 as u32) as u64);
    /* 1400360cb */ let mut t_1400360cb_0: u32 = ((rdx as u32)).wrapping_add((rcx as u32));
    /* 1400360cb */ rdx = (t_1400360cb_0 as u64);
    /* 1400360cd */ rdx = (((((rdx as u32) as i64) >> ((0x4_u8 as u32) as i64)) as u64) as u64);
    /* 1400360d0 */ rax = ((rdx as u32) as u64);
    /* 1400360d2 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 1400360d5 */ let mut t_1400360d5_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 1400360d5 */ rdx = (t_1400360d5_0 as u64);
    /* 1400360d7 */ let mut t_1400360d7_0: u32 = ((rdx as u32) & 0x80000001_u32);
    /* 1400360d7 */ rdx = (t_1400360d7_0 as u64);
    if (SF != OF) {
        /* -> bb2764 */
    } else {
        /* -> bb2763 */
    }

    // ---- bb2763 @ 0x1400360dd ----
    if (SF != OF) {
        /* -> bb2764 */
    } else {
        /* -> bb2767 */
    }

    // ---- bb2764 @ 0x1400360df ----
    /* 1400360df */ rdx = (((rdx as u32)).wrapping_sub(0x1_u32) as u64);
    /* 1400360e1 */ let mut t_1400360e1_0: u32 = ((rdx as u32) | 0xfffffffe_u32);
    /* 1400360e1 */ rdx = (t_1400360e1_0 as u64);
    /* 1400360e4 */ rdx = (((rdx as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb2767 */

    // ---- bb2767 @ 0x1400360e6 ----
    /* 1400360e6 */ let mut t_1400360e6_0: u32 = ((rdx as u32)).wrapping_add(0x38_u32);
    /* 1400360e6 */ rdx = (t_1400360e6_0 as u64);
    /* 1400360e9 */ xmm2 = ((rdx as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2cdf6c]
    /* 1400360f8 */ let mut t_1400360f8: u32 = core::ptr::read((0x1400360fe_u64).wrapping_add(0x3b4012_u64) as *const u32);
    /* 1400360f8 */ rcx = (t_1400360f8 as u64);
    /* 1400360fe */ fn_140071cd0();
    /* fallthrough -> bb2778 */

    // ---- bb2774 @ 0x140036105 ----
    /* 140036105 */ let mut t_140036105: u32 = core::ptr::read((0x14003610c_u64).wrapping_add(0x3c8624_u64) as *const u32);
    /* 140036105 */ r12 = (t_140036105 as u64);
    /* fallthrough -> bb2778 */

    // ---- bb2776 @ 0x14003610e ----
    /* 14003610e */ let mut t_14003610e: u32 = core::ptr::read((0x140036115_u64).wrapping_add(0x3c861b_u64) as *const u32);
    /* 14003610e */ r12 = (t_14003610e as u64);
    /* fallthrough -> bb2777 */

    // ---- bb2777 @ 0x140036115 ----
    /* 140036115 */ rbx = (0x4_u32 as u64);
    /* fallthrough -> bb2778 */

    // ---- bb2778 @ 0x14003611a ----
    /* 14003611a */ let mut t_14003611a: u32 = core::ptr::read((rdi).wrapping_add(0x698_u64) as *const u32);
    /* 14003611a */ xmm1 = (t_14003611a as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    /* 140036125 */ let mut t_140036125: u32 = core::ptr::read((0x14003612b_u64).wrapping_add(0x3b3fcd_u64) as *const u32);
    /* 140036125 */ rcx = (t_140036125 as u64);
    /* 14003612b */ let mut t_14003612b_0: u32 = ((rcx as u32)).wrapping_add(0x2_u32);
    /* 14003612b */ rcx = (t_14003612b_0 as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2cdeda]
    /* 140036136 */ fn_140071cd0();
    /* 14003613b */ let mut t_14003613b: u8 = core::ptr::read((rdi).wrapping_add(0x6b0_u64) as *const u8);
    if (t_14003613b == 0x0_u8) {
        /* -> bb2788 */
    } else {
        /* -> bb2787 */
    }

    // ---- bb2787 @ 0x140036142 ----
    if (t_14003613b == 0x0_u8) {
        /* -> bb2788 */
    } else {
        /* -> bb2857 */
    }

    // ---- bb2788 @ 0x140036148 ----
    /* 140036148 */ let mut t_140036148: u32 = core::ptr::read((rdi).wrapping_add(0xd4_u64) as *const u32);
    /* 140036148 */ rax = ((t_140036148 as i64) as u64);
    if ((rax as u32) != 0xffffffff_u32) {
        /* -> bb2793 */
    } else {
        /* -> bb2792 */
    }

    // ---- bb2792 @ 0x140036152 ----
    if ((rax as u32) != 0xffffffff_u32) {
        /* -> bb2793 */
    } else {
        /* -> bb2857 */
    }

    // ---- bb2793 @ 0x140036158 ----
    /* 140036158 */ rcx = rax;
    /* 14003615b */ rax = core::ptr::read((rdi).wrapping_add(0xb8_u64) as *const u64);
    /* 140036162 */ rcx = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 140036166 */ let mut t_140036166: u32 = core::ptr::read((rcx).wrapping_add(0xc_u64) as *const u32);
    if (t_140036166 == 0x30_u32) {
        /* -> bb2800 */
    } else {
        /* -> bb2799 */
    }

    // ---- bb2799 @ 0x14003616a ----
    if (t_140036166 == 0x30_u32) {
        /* -> bb2800 */
    } else {
        /* -> bb2857 */
    }

    // ---- bb2800 @ 0x140036170 ----
    /* 140036170 */ let mut t_140036170: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140036170 == 0x3_u32) {
        /* -> bb2804 */
    } else {
        /* -> bb2803 */
    }

    // ---- bb2803 @ 0x140036177 ----
    if (t_140036170 == 0x3_u32) {
        /* -> bb2804 */
    } else {
        /* -> bb2857 */
    }

    // ---- bb2804 @ 0x14003617d ----
    /* 14003617d */ let mut t_14003617d: u32 = core::ptr::read((rdi).wrapping_add(0x27c_u64) as *const u32);
    if (t_14003617d == 0x0_u32) {
        /* -> bb2808 */
    } else {
        /* -> bb2807 */
    }

    // ---- bb2807 @ 0x140036184 ----
    if (t_14003617d == 0x0_u32) {
        /* -> bb2808 */
    } else {
        /* -> bb2857 */
    }

    // ---- bb2808 @ 0x14003618a ----
    /* 14003618a */ rcx = ((r12 as u32) as u64);
    /* 14003618d */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 140036196 */ rdx = ((rbx as u32) as u64);
    /* 140036198 */ rax = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003619c */ let mut t_14003619c: u32 = core::ptr::read((rdx).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003619c */ rax = (t_14003619c as u64);
    /* 14003619f */ let mut t_14003619f: u32 = core::ptr::read((0x1400361a5_u64).wrapping_add(0x3b3f77_u64) as *const u32);
    if (((SF == OF) & (t_14003619f != (rax as u32))) == false) { /* -> bb2817 */ }
    if (((SF == OF) & (t_14003619f != (rax as u32))) != 0) { /* -> bb2816 */ }

    // ---- bb2816 @ 0x1400361a5 ----
    if (((SF == OF) & (t_14003619f != (rax as u32))) == false) { /* -> bb2817 */ }
    if (((SF == OF) & (t_14003619f != (rax as u32))) != 0) { /* -> bb2898 */ }

    // ---- bb2817 @ 0x1400361ab ----
    /* 1400361ab */ let mut t_1400361ab: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 1400361ab */ rcx = (t_1400361ab as u64);
    /* 1400361b1 */ rax = (0x66666667_u32 as u64);
    /* 1400361b6 */ let mut t_1400361b6_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 1400361b6 */ rdx = (((t_1400361b6_0 >> 0x20_u64) as u32) as u64);
    /* 1400361b6 */ rax = ((t_1400361b6_0 as u32) as u64);
    /* 1400361b8 */ rdx = (((((rdx as u32) as i64) >> ((0x3_u8 as u32) as i64)) as u64) as u64);
    /* 1400361bb */ rax = ((rdx as u32) as u64);
    /* 1400361bd */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 1400361c0 */ let mut t_1400361c0_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 1400361c0 */ rdx = (t_1400361c0_0 as u64);
    /* 1400361c2 */ rax = (((rdx).wrapping_add((rdx).wrapping_mul(0x4_u64)) as u32) as u64);
    /* 1400361c5 */ rax = (((rax as u32) << (0x2_u8 as u32)) as u64);
    /* 1400361c8 */ let mut t_1400361c8_0: u32 = ((rcx as u32)).wrapping_sub((rax as u32));
    /* 1400361c8 */ rcx = (t_1400361c8_0 as u64);
    if (SF != OF) {
        /* -> bb2831 */
    } else {
        /* -> bb2830 */
    }

    // ---- bb2830 @ 0x1400361cd ----
    if (SF != OF) {
        /* -> bb2831 */
    } else {
        /* -> bb2857 */
    }

    // ---- bb2831 @ 0x1400361d3 ----
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2cd1d9]
    /* 1400361db */ xmm2 = xmm6;
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x2cde6d]
    /* 1400361e7 */ xmm1 = xmm8;
    /* 1400361eb */ let mut t_1400361eb: u32 = core::ptr::read((0x1400361f1_u64).wrapping_add(0x3b3f27_u64) as *const u32);
    /* 1400361eb */ rcx = (t_1400361eb as u64);
    /* 1400361f1 */ fn_140071cd0();
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm9
    /* 1400361fd */ xmm3 = xmm13;
    /* 140036201 */ xmm2 = xmm6;
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2cde50]
    /* 14003620c */ xmm1 = xmm7;
    /* 14003620f */ let mut t_14003620f: u32 = core::ptr::read((0x140036215_u64).wrapping_add(0x3b3f03_u64) as *const u32);
    /* 14003620f */ rcx = (t_14003620f as u64);
    /* 140036215 */ fn_140071e80();
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm13
    /* 140036221 */ xmm3 = xmm9;
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2cde0f]
    /* 14003622d */ xmm2 = xmm6;
    /* 140036230 */ xmm1 = xmm8;
    /* 140036234 */ let mut t_140036234: u32 = core::ptr::read((0x14003623a_u64).wrapping_add(0x3b3ede_u64) as *const u32);
    /* 140036234 */ rcx = (t_140036234 as u64);
    /* 14003623a */ fn_140071e80();
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm13
    /* 140036246 */ xmm3 = xmm13;
    /* 14003624a */ xmm2 = xmm6;
    /* 14003624d */ xmm1 = xmm7;
    /* 140036250 */ let mut t_140036250: u32 = core::ptr::read((0x140036256_u64).wrapping_add(0x3b3ec2_u64) as *const u32);
    /* 140036250 */ rcx = (t_140036250 as u64);
    /* 140036256 */ fn_140071e80();
    /* fallthrough -> bb2857 */

    // ---- bb2857 @ 0x14003625b ----
    // intrinsic: f30f109f movss xmm3, dword ptr [rdi + 0x114]
    /* 140036263 */ let mut xmm4: u128 = xmm3;
    // intrinsic: 0f5725b3 xorps xmm4, xmmword ptr [rip + 0x366ab3]
    /* 14003626d */ xmm2 = xmm4;
    // intrinsic: f30f5997 mulss xmm2, dword ptr [rdi + 0x10c]
    // intrinsic: f30f59a7 mulss xmm4, dword ptr [rdi + 0x110]
    /* 140036280 */ xmm0 = xmm3;
    // intrinsic: 0f14c300 unpcklps xmm0, xmm3
    /* 140036286 */ r8 = (xmm0 as u64);
    /* 14003628b */ xmm1 = xmm12;
    // intrinsic: 0f14d400 unpcklps xmm2, xmm4
    /* 140036292 */ rcx = (xmm2 as u64);
    /* 140036297 */ fn_140072fa0();
    /* 14003629c */ rdx = ((rdx & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 14003629e */ rcx = rdi;
    /* 1400362a1 */ fn_1400d61a0();
    /* 1400362a6 */ rdx = (0x1_u32 as u64);
    /* 1400362ab */ rcx = rdi;
    /* 1400362ae */ fn_1400d6400();
    /* 1400362b3 */ fn_1400730b0();
    /* 1400362b8 */ r8 = ((r8 & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 1400362bb */ rdx = (((r8 as u8) as u32) as u64);
    /* 1400362bf */ rcx = rdi;
    /* 1400362c2 */ r11 = (rsp).wrapping_add(0xd0_u64);
    /* 1400362ca */ rbx = core::ptr::read((r11).wrapping_add(0x30_u64) as *const u64);
    /* 1400362ce */ rsi = core::ptr::read((r11).wrapping_add(0x40_u64) as *const u64);
    /* 1400362d2 */ rdi = core::ptr::read((r11).wrapping_add(0x48_u64) as *const u64);
    /* 1400362d6 */ xmm6 = core::ptr::read((r11).wrapping_sub(0x10_u64) as *const u128);
    /* 1400362db */ xmm7 = core::ptr::read((r11).wrapping_sub(0x20_u64) as *const u128);
    /* 1400362e0 */ let mut xmm8: u128 = core::ptr::read((r11).wrapping_sub(0x30_u64) as *const u128);
    /* 1400362e5 */ let mut xmm9: u128 = core::ptr::read((r11).wrapping_sub(0x40_u64) as *const u128);
    /* 1400362ea */ let mut xmm10: u128 = core::ptr::read((r11).wrapping_sub(0x50_u64) as *const u128);
    /* 1400362ef */ let mut xmm12: u128 = core::ptr::read((r11).wrapping_sub(0x60_u64) as *const u128);
    /* 1400362f4 */ let mut xmm13: u128 = core::ptr::read((r11).wrapping_sub(0x70_u64) as *const u128);
    /* 1400362f9 */ rsp = r11;
    /* 1400362fc */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400362fc */ r15 = core::ptr::read(rsp as *const u64);
    /* 1400362fe */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400362fe */ r14 = core::ptr::read(rsp as *const u64);
    /* 140036300 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140036300 */ r13 = core::ptr::read(rsp as *const u64);
    /* 140036302 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140036302 */ r12 = core::ptr::read(rsp as *const u64);
    /* 140036304 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140036304 */ rbp = core::ptr::read(rsp as *const u64);
    /* 1400cb0e0 */ rax = rsp;
    /* 1400cb0e3 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u64, rbx);
    /* 1400cb0e7 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u8, (r8 as u8));
    /* 1400cb0eb */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u8, (rdx as u8));
    /* 1400cb0ee */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 1400cb0ee */ core::ptr::write(rsp as *mut u64, rbp);
    /* 1400cb0ef */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 1400cb0ef */ core::ptr::write(rsp as *mut u64, rsi);
    /* 1400cb0f0 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 1400cb0f0 */ core::ptr::write(rsp as *mut u64, rdi);
    /* 1400cb0f1 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 1400cb0f1 */ core::ptr::write(rsp as *mut u64, r12);
    /* 1400cb0f3 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 1400cb0f3 */ core::ptr::write(rsp as *mut u64, r13);
    /* 1400cb0f5 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 1400cb0f5 */ core::ptr::write(rsp as *mut u64, r14);
    /* 1400cb0f7 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 1400cb0f7 */ core::ptr::write(rsp as *mut u64, r15);
    /* 1400cb0f9 */ rbp = (rax).wrapping_sub(0x5f_u64);
    /* 1400cb0fd */ let mut t_1400cb0fd_0: u64 = (rsp).wrapping_sub(0x100_u64);
    /* 1400cb0fd */ rsp = t_1400cb0fd_0;
    /* 1400cb104 */ core::ptr::write((rax).wrapping_sub(0x48_u64) as *mut u128, xmm6);
    /* 1400cb108 */ core::ptr::write((rax).wrapping_sub(0x58_u64) as *mut u128, xmm7);
    /* 1400cb10c */ core::ptr::write((rax).wrapping_sub(0x68_u64) as *mut u128, xmm8);
    /* 1400cb111 */ core::ptr::write((rax).wrapping_sub(0x78_u64) as *mut u128, xmm9);
    /* 1400cb116 */ core::ptr::write((rax).wrapping_sub(0x88_u64) as *mut u128, xmm10);
    /* 1400cb11e */ core::ptr::write((rax).wrapping_sub(0x98_u64) as *mut u128, xmm11);
    /* 1400cb126 */ core::ptr::write((rax).wrapping_sub(0xa8_u64) as *mut u128, xmm12);
    /* 1400cb12e */ core::ptr::write((rax).wrapping_sub(0xb8_u64) as *mut u128, xmm13);
    /* 1400cb136 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u128, xmm14);
    /* 1400cb13c */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm15);
    /* 1400cb142 */ r12 = (((r8 as u8) as u32) as u64);
    /* 1400cb146 */ r14 = rcx;
    /* 1400cb149 */ rdx = (0x4_u32 as u64);
    /* 1400cb14e */ let mut t_1400cb14e: u32 = core::ptr::read((0x1400cb154_u64).wrapping_add(0x3335dc_u64) as *const u32);
    /* 1400cb14e */ rsi = (t_1400cb14e as u64);
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2d1b38]
    /* 1400cb15c */ let mut t_1400cb15c: u32 = core::ptr::read((rcx).wrapping_add(0x1b0_u64) as *const u32);
    if (SF == OF) {
        /* -> bb3072 */
    } else {
        /* -> bb3071 */
    }

    // ---- bb2898 @ 0x14003630a ----
    /* 14003630a */ rcx = (0x140036311_u64).wrapping_add(0x3b3e0b_u64);
    /* 140036311 */ fn_1402c7548();
    /* 140036316 */ let mut t_140036316: u32 = core::ptr::read((0x14003631d_u64).wrapping_add(0x3b3dff_u64) as *const u32);
    if (t_140036316 == 0xffffffff_u32) {
        /* -> bb2904 */
    } else {
        /* -> bb2903 */
    }

    // ---- bb2903 @ 0x14003631d ----
    if (t_140036316 != 0xffffffff_u32) {
        /* -> bb2817 */
    } else {
        /* -> bb2904 */
    }

    // ---- bb2904 @ 0x140036323 ----
    /* 140036323 */ core::ptr::write((rbp).wrapping_sub(0x4b_u64) as *mut u16, (r15 as u16));
    /* 140036328 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u64, 0xd_u64);
    /* 140036330 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u64, 0xf_u64);
    /* 140036338 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb2908 */ }
    if DF { /* -> bb2909 */ }

    // ---- bb2908 @ 0x140036338 ----
    /* 140036338 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140036338 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb2910 */

    // ---- bb2909 @ 0x140036338 ----
    /* 140036338 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140036338 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb2910 */

    // ---- bb2910 @ 0x140036340 ----
    /* 140036340 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb2912 */ }
    if DF { /* -> bb2913 */ }

    // ---- bb2912 @ 0x140036340 ----
    /* 140036340 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140036340 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb2914 */

    // ---- bb2913 @ 0x140036340 ----
    /* 140036340 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140036340 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb2914 */

    // ---- bb2914 @ 0x140036345 ----
    /* 140036345 */ let mut t_140036345: u32 = core::ptr::read((0x14003634b_u64).wrapping_add(0x2cdc5d_u64) as *const u32);
    /* 140036345 */ rax = (t_140036345 as u64);
    /* 14003634b */ core::ptr::write((rbp).wrapping_sub(0x51_u64) as *mut u32, (rax as u32));
    /* 14003634e */ let mut t_14003634e: u8 = core::ptr::read((0x140036355_u64).wrapping_add(0x2cdc57_u64) as *const u8);
    /* 14003634e */ rdx = ((t_14003634e as u32) as u64);
    /* 140036355 */ core::ptr::write((rbp).wrapping_sub(0x4d_u64) as *mut u8, (rdx as u8));
    /* 140036358 */ core::ptr::write((rbp).wrapping_sub(0x4c_u64) as *mut u8, 0x0_u8);
    /* 14003635c */ rcx = (rbp).wrapping_sub(0x59_u64);
    /* 140036360 */ fn_14006fd40();
    /* 140036365 */ core::ptr::write((0x14003636b_u64).wrapping_add(0x3b3dad_u64) as *mut u32, (rax as u32));
    /* 14003636b */ rcx = (0x140036372_u64).wrapping_add(0x3b3daa_u64);
    /* 140036372 */ fn_1402c74dc();
    /* fallthrough -> bb2817 */

    // ---- bb2926 @ 0x14003637c ----
    /* 14003637c */ rcx = (0x140036383_u64).wrapping_add(0x3b3d79_u64);
    /* 140036383 */ fn_1402c7548();
    /* 140036388 */ let mut t_140036388: u32 = core::ptr::read((0x14003638f_u64).wrapping_add(0x3b3d6d_u64) as *const u32);
    if (t_140036388 == 0xffffffff_u32) {
        /* -> bb2932 */
    } else {
        /* -> bb2931 */
    }

    // ---- bb2931 @ 0x14003638f ----
    if (t_140036388 != 0xffffffff_u32) {
        /* -> bb1815 */
    } else {
        /* -> bb2932 */
    }

    // ---- bb2932 @ 0x140036395 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140036398 */ core::ptr::write((rbp).wrapping_sub(0x59_u64) as *mut u128, xmm0);
    /* 14003639c */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u64, 0x6_u64);
    /* 1400363a4 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u64, 0xf_u64);
    /* 1400363ac */ let mut t_1400363ac: u32 = core::ptr::read((0x1400363b2_u64).wrapping_add(0x2cdb8e_u64) as *const u32);
    /* 1400363ac */ rax = (t_1400363ac as u64);
    /* 1400363b2 */ core::ptr::write((rbp).wrapping_sub(0x59_u64) as *mut u32, (rax as u32));
    /* 1400363b5 */ let mut t_1400363b5: u16 = core::ptr::read((0x1400363bc_u64).wrapping_add(0x2cdb88_u64) as *const u16);
    /* 1400363b5 */ rax = ((t_1400363b5 as u32) as u64);
    /* 1400363bc */ core::ptr::write((rbp).wrapping_sub(0x55_u64) as *mut u16, (rax as u16));
    /* 1400363c0 */ core::ptr::write((rbp).wrapping_sub(0x53_u64) as *mut u8, 0x0_u8);
    /* 1400363c4 */ rcx = (rbp).wrapping_sub(0x59_u64);
    /* 1400363c8 */ fn_14006fd40();
    /* 1400363cd */ core::ptr::write((0x1400363d3_u64).wrapping_add(0x3b3d25_u64) as *mut u32, (rax as u32));
    /* 1400363d3 */ rcx = (0x1400363da_u64).wrapping_add(0x3b3d22_u64);
    /* 1400363da */ fn_1402c74dc();
    /* fallthrough -> bb1815 */

    // ---- bb2947 @ 0x1400363e4 ----
    /* 1400363e4 */ rcx = (0x1400363eb_u64).wrapping_add(0x3b3d19_u64);
    /* 1400363eb */ fn_1402c7548();
    /* 1400363f0 */ let mut t_1400363f0: u32 = core::ptr::read((0x1400363f7_u64).wrapping_add(0x3b3d0d_u64) as *const u32);
    if (t_1400363f0 == 0xffffffff_u32) {
        /* -> bb2953 */
    } else {
        /* -> bb2952 */
    }

    // ---- bb2952 @ 0x1400363f7 ----
    if (t_1400363f0 != 0xffffffff_u32) {
        /* -> bb1820 */
    } else {
        /* -> bb2953 */
    }

    // ---- bb2953 @ 0x1400363fd ----
    /* 1400363fd */ let mut t_1400363fd: u32 = core::ptr::read((0x140036403_u64).wrapping_add(0x3b3cf5_u64) as *const u32);
    /* 1400363fd */ rax = (t_1400363fd as u64);
    /* 140036403 */ let mut t_140036403_0: u32 = ((rax as u32)).wrapping_add(0x6_u32);
    /* 140036403 */ rax = (t_140036403_0 as u64);
    /* 140036406 */ core::ptr::write((0x14003640c_u64).wrapping_add(0x3b3cf4_u64) as *mut u32, (rax as u32));
    /* 14003640c */ rcx = (0x140036413_u64).wrapping_add(0x3b3cf1_u64);
    /* 140036413 */ fn_1402c74dc();
    /* fallthrough -> bb1820 */

    // ---- bb2959 @ 0x14003641d ----
    /* 14003641d */ rcx = (0x140036424_u64).wrapping_add(0x3b3ce8_u64);
    /* 140036424 */ fn_1402c7548();
    /* 140036429 */ let mut t_140036429: u32 = core::ptr::read((0x140036430_u64).wrapping_add(0x3b3cdc_u64) as *const u32);
    if (t_140036429 == 0xffffffff_u32) {
        /* -> bb2965 */
    } else {
        /* -> bb2964 */
    }

    // ---- bb2964 @ 0x140036430 ----
    if (t_140036429 != 0xffffffff_u32) {
        /* -> bb1976 */
    } else {
        /* -> bb2965 */
    }

    // ---- bb2965 @ 0x140036436 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140036439 */ core::ptr::write((rbp).wrapping_sub(0x59_u64) as *mut u128, xmm0);
    /* 14003643d */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u64, 0xa_u64);
    /* 140036445 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u64, 0xf_u64);
    /* 14003644d */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb2970 */ }
    if DF { /* -> bb2971 */ }

    // ---- bb2970 @ 0x14003644d ----
    /* 14003644d */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003644d */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb2972 */

    // ---- bb2971 @ 0x14003644d ----
    /* 14003644d */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003644d */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb2972 */

    // ---- bb2972 @ 0x140036455 ----
    /* 140036455 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb2974 */ }
    if DF { /* -> bb2975 */ }

    // ---- bb2974 @ 0x140036455 ----
    /* 140036455 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140036455 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb2976 */

    // ---- bb2975 @ 0x140036455 ----
    /* 140036455 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140036455 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb2976 */

    // ---- bb2976 @ 0x14003645a ----
    /* 14003645a */ let mut t_14003645a: u16 = core::ptr::read((0x140036461_u64).wrapping_add(0x2cdaef_u64) as *const u16);
    /* 14003645a */ rax = ((t_14003645a as u32) as u64);
    /* 140036461 */ core::ptr::write((rbp).wrapping_sub(0x51_u64) as *mut u16, (rax as u16));
    /* 140036465 */ core::ptr::write((rbp).wrapping_sub(0x4f_u64) as *mut u8, 0x0_u8);
    /* 140036469 */ rcx = (rbp).wrapping_sub(0x59_u64);
    /* 14003646d */ fn_14006fd40();
    /* 140036472 */ core::ptr::write((0x140036478_u64).wrapping_add(0x3b3c90_u64) as *mut u32, (rax as u32));
    /* 140036478 */ rcx = (0x14003647f_u64).wrapping_add(0x3b3c8d_u64);
    /* 14003647f */ fn_1402c74dc();
    /* fallthrough -> bb1976 */

    // ---- bb2986 @ 0x140036489 ----
    /* 140036489 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r15);
    /* 14003648e */ let mut t_14003648e_0: u32 = 0x0_u32;
    /* 14003648e */ r9 = (t_14003648e_0 as u64);
    /* 140036491 */ let mut t_140036491_0: u32 = 0x0_u32;
    /* 140036491 */ r8 = (t_140036491_0 as u64);
    /* 140036494 */ let mut t_140036494_0: u32 = 0x0_u32;
    /* 140036494 */ rdx = (t_140036494_0 as u64);
    /* 140036496 */ let mut t_140036496_0: u32 = 0x0_u32;
    /* 140036496 */ rcx = (t_140036496_0 as u64);
    /* 140036498 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb2993 */

    // ---- bb2993 @ 0x14003649e ----
    /* 14003649e */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r15);
    /* 1400364a3 */ let mut t_1400364a3_0: u32 = 0x0_u32;
    /* 1400364a3 */ r9 = (t_1400364a3_0 as u64);
    /* 1400364a6 */ let mut t_1400364a6_0: u32 = 0x0_u32;
    /* 1400364a6 */ r8 = (t_1400364a6_0 as u64);
    /* 1400364a9 */ let mut t_1400364a9_0: u32 = 0x0_u32;
    /* 1400364a9 */ rdx = (t_1400364a9_0 as u64);
    /* 1400364ab */ let mut t_1400364ab_0: u32 = 0x0_u32;
    /* 1400364ab */ rcx = (t_1400364ab_0 as u64);
    /* 1400364ad */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb3000 */

    // ---- bb3000 @ 0x1400364b3 ----
    /* 1400364b3 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r15);
    /* 1400364b8 */ let mut t_1400364b8_0: u32 = 0x0_u32;
    /* 1400364b8 */ r9 = (t_1400364b8_0 as u64);
    /* 1400364bb */ let mut t_1400364bb_0: u32 = 0x0_u32;
    /* 1400364bb */ r8 = (t_1400364bb_0 as u64);
    /* 1400364be */ let mut t_1400364be_0: u32 = 0x0_u32;
    /* 1400364be */ rdx = (t_1400364be_0 as u64);
    /* 1400364c0 */ let mut t_1400364c0_0: u32 = 0x0_u32;
    /* 1400364c0 */ rcx = (t_1400364c0_0 as u64);
    /* 1400364c2 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb3007 */

    // ---- bb3007 @ 0x1400364c8 ----
    /* 1400364c8 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r15);
    /* 1400364cd */ let mut t_1400364cd_0: u32 = 0x0_u32;
    /* 1400364cd */ r9 = (t_1400364cd_0 as u64);
    /* 1400364d0 */ let mut t_1400364d0_0: u32 = 0x0_u32;
    /* 1400364d0 */ r8 = (t_1400364d0_0 as u64);
    /* 1400364d3 */ let mut t_1400364d3_0: u32 = 0x0_u32;
    /* 1400364d3 */ rdx = (t_1400364d3_0 as u64);
    /* 1400364d5 */ let mut t_1400364d5_0: u32 = 0x0_u32;
    /* 1400364d5 */ rcx = (t_1400364d5_0 as u64);
    /* 1400364d7 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb3014 */

    // ---- bb3014 @ 0x1400364dd ----
    /* 1400364dd */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r15);
    /* 1400364e2 */ let mut t_1400364e2_0: u32 = 0x0_u32;
    /* 1400364e2 */ r9 = (t_1400364e2_0 as u64);
    /* 1400364e5 */ let mut t_1400364e5_0: u32 = 0x0_u32;
    /* 1400364e5 */ r8 = (t_1400364e5_0 as u64);
    /* 1400364e8 */ let mut t_1400364e8_0: u32 = 0x0_u32;
    /* 1400364e8 */ rdx = (t_1400364e8_0 as u64);
    /* 1400364ea */ let mut t_1400364ea_0: u32 = 0x0_u32;
    /* 1400364ea */ rcx = (t_1400364ea_0 as u64);
    /* 1400364ec */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb3021 */

    // ---- bb3021 @ 0x1400364f2 ----
    /* 1400364f2 */ rcx = (0x1400364f9_u64).wrapping_add(0x3b3c1b_u64);
    /* 1400364f9 */ fn_1402c7548();
    /* 1400364fe */ let mut t_1400364fe: u32 = core::ptr::read((0x140036505_u64).wrapping_add(0x3b3c0f_u64) as *const u32);
    if (t_1400364fe == 0xffffffff_u32) {
        /* -> bb3027 */
    } else {
        /* -> bb3026 */
    }

    // ---- bb3026 @ 0x140036505 ----
    if (t_1400364fe != 0xffffffff_u32) {
        /* -> bb2752 */
    } else {
        /* -> bb3027 */
    }

    // ---- bb3027 @ 0x14003650b ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003650e */ core::ptr::write((rbp).wrapping_sub(0x59_u64) as *mut u128, xmm0);
    /* 140036512 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u64, 0x8_u64);
    /* 14003651a */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u64, 0xf_u64);
    /* 140036522 */ rax = 0x657265486e776f44_u64;
    /* 14003652c */ core::ptr::write((rbp).wrapping_sub(0x59_u64) as *mut u64, rax);
    /* 140036530 */ core::ptr::write((rbp).wrapping_sub(0x51_u64) as *mut u8, 0x0_u8);
    /* 140036534 */ rcx = (rbp).wrapping_sub(0x59_u64);
    /* 140036538 */ fn_14006fd40();
    /* 14003653d */ core::ptr::write((0x140036543_u64).wrapping_add(0x3b3bcd_u64) as *mut u32, (rax as u32));
    /* 140036543 */ rcx = (0x14003654a_u64).wrapping_add(0x3b3bca_u64);
    /* 14003654a */ fn_1402c74dc();
    /* fallthrough -> bb2752 */

    // ---- bb3071 @ 0x1400cb163 ----
    if (SF == OF) {
        /* -> bb3072 */
    } else {
        /* -> bb3126 */
    }

    // ---- bb3072 @ 0x1400cb169 ----
    /* 1400cb169 */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 1400cb172 */ rbx = ((rdx as u32) as u64);
    /* 1400cb174 */ rdi = core::ptr::read((rax).wrapping_add((rsi).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400cb178 */ let mut t_1400cb178: u32 = core::ptr::read((rdi).wrapping_add((rdx).wrapping_mul(0x1_u64)) as *const u32);
    /* 1400cb178 */ rax = (t_1400cb178 as u64);
    /* 1400cb17b */ let mut t_1400cb17b: u32 = core::ptr::read((0x1400cb181_u64).wrapping_add(0x328543_u64) as *const u32);
    if (((SF == OF) & (t_1400cb17b != (rax as u32))) == false) { /* -> bb3080 */ }
    if (((SF == OF) & (t_1400cb17b != (rax as u32))) != 0) { /* -> bb3079 */ }

    // ---- bb3079 @ 0x1400cb181 ----
    if (((SF == OF) & (t_1400cb17b != (rax as u32))) == false) { /* -> bb3080 */ }
    if (((SF == OF) & (t_1400cb17b != (rax as u32))) != 0) { /* -> bb3601 */ }

    // ---- bb3080 @ 0x1400cb187 ----
    /* 1400cb187 */ let mut t_1400cb187: u32 = core::ptr::read((rdi).wrapping_add((rbx).wrapping_mul(0x1_u64)) as *const u32);
    /* 1400cb187 */ rax = (t_1400cb187 as u64);
    /* 1400cb18a */ let mut t_1400cb18a: u32 = core::ptr::read((0x1400cb190_u64).wrapping_add(0x32853c_u64) as *const u32);
    if (((SF == OF) & (t_1400cb18a != (rax as u32))) == false) { /* -> bb3085 */ }
    if (((SF == OF) & (t_1400cb18a != (rax as u32))) != 0) { /* -> bb3084 */ }

    // ---- bb3084 @ 0x1400cb190 ----
    if (((SF == OF) & (t_1400cb18a != (rax as u32))) == false) { /* -> bb3085 */ }
    if (((SF == OF) & (t_1400cb18a != (rax as u32))) != 0) { /* -> bb3622 */ }

    // ---- bb3085 @ 0x1400cb196 ----
    /* 1400cb196 */ rbx = core::ptr::read((r14).wrapping_add(0x60_u64) as *const u64);
    // intrinsic: f30f1093 movss xmm2, dword ptr [rbx + 0x2b0]
    // intrinsic: f30f5893 addss xmm2, dword ptr [rbx + 0x2a8]
    // intrinsic: f30f108b movss xmm1, dword ptr [rbx + 0x2ac]
    // intrinsic: f30f59cf mulss xmm1, xmm7
    // intrinsic: f30f588b addss xmm1, dword ptr [rbx + 0x2a4]
    /* 1400cb1be */ let mut t_1400cb1be: u32 = core::ptr::read((0x1400cb1c4_u64).wrapping_add(0x3284fc_u64) as *const u32);
    /* 1400cb1be */ rcx = (t_1400cb1be as u64);
    /* 1400cb1c4 */ fn_140071cd0();
    /* 1400cb1c9 */ let mut t_1400cb1c9: u32 = core::ptr::read((r14).wrapping_add(0x1b0_u64) as *const u32);
    if (t_1400cb1c9 == 0x1_u32) {
        /* -> bb3097 */
    } else {
        /* -> bb3096 */
    }

    // ---- bb3096 @ 0x1400cb1d1 ----
    if (t_1400cb1c9 == 0x1_u32) {
        /* -> bb3097 */
    } else {
        /* -> bb3126 */
    }

    // ---- bb3097 @ 0x1400cb1d3 ----
    /* 1400cb1d3 */ let mut t_1400cb1d3: u32 = core::ptr::read((r14).wrapping_add(0xd8_u64) as *const u32);
    if (t_1400cb1d3 != 0x6_u32) {
        /* -> bb3101 */
    } else {
        /* -> bb3100 */
    }

    // ---- bb3100 @ 0x1400cb1db ----
    if (t_1400cb1d3 != 0x6_u32) {
        /* -> bb3101 */
    } else {
        /* -> bb3117 */
    }

    // ---- bb3101 @ 0x1400cb1dd ----
    /* 1400cb1dd */ let mut t_1400cb1dd: u32 = core::ptr::read((r14).wrapping_add(0x1b4_u64) as *const u32);
    /* 1400cb1dd */ rcx = (t_1400cb1dd as u64);
    /* 1400cb1e4 */ rax = (0x88888889_u32 as u64);
    /* 1400cb1e9 */ let mut t_1400cb1e9_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 1400cb1e9 */ rdx = (((t_1400cb1e9_0 >> 0x20_u64) as u32) as u64);
    /* 1400cb1e9 */ rax = ((t_1400cb1e9_0 as u32) as u64);
    /* 1400cb1eb */ let mut t_1400cb1eb_0: u32 = ((rdx as u32)).wrapping_add((rcx as u32));
    /* 1400cb1eb */ rdx = (t_1400cb1eb_0 as u64);
    /* 1400cb1ed */ rdx = (((((rdx as u32) as i64) >> ((0x5_u8 as u32) as i64)) as u64) as u64);
    /* 1400cb1f0 */ rax = ((rdx as u32) as u64);
    /* 1400cb1f2 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 1400cb1f5 */ let mut t_1400cb1f5_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 1400cb1f5 */ rdx = (t_1400cb1f5_0 as u64);
    /* 1400cb1f7 */ let mut t_1400cb1f7_0: u64 = (((rdx as u32) as u64)).wrapping_mul((0x3c_u32 as u64));
    /* 1400cb1f7 */ rax = ((t_1400cb1f7_0 as u32) as u64);
    /* 1400cb1fa */ let mut t_1400cb1fa_0: u32 = ((rcx as u32)).wrapping_sub((rax as u32));
    /* 1400cb1fa */ rcx = (t_1400cb1fa_0 as u64);
    if (SF == OF) {
        /* -> bb3115 */
    } else {
        /* -> bb3114 */
    }

    // ---- bb3114 @ 0x1400cb1ff ----
    if (SF == OF) {
        /* -> bb3115 */
    } else {
        /* -> bb3117 */
    }

    // ---- bb3115 @ 0x1400cb201 ----
    /* 1400cb201 */ let mut t_1400cb201_0: u32 = 0x0_u32;
    /* 1400cb201 */ rcx = (t_1400cb201_0 as u64);
    /* fallthrough -> bb3118 */

    // ---- bb3117 @ 0x1400cb205 ----
    /* 1400cb205 */ rcx = (0x1_u32 as u64);
    /* fallthrough -> bb3118 */

    // ---- bb3118 @ 0x1400cb20a ----
    // intrinsic: f30f1093 movss xmm2, dword ptr [rbx + 0x2b0]
    // intrinsic: f30f59d7 mulss xmm2, xmm7
    // intrinsic: f30f5893 addss xmm2, dword ptr [rbx + 0x2a8]
    // intrinsic: f30f108b movss xmm1, dword ptr [rbx + 0x2ac]
    // intrinsic: f30f59cf mulss xmm1, xmm7
    // intrinsic: f30f588b addss xmm1, dword ptr [rbx + 0x2a4]
    /* 1400cb232 */ let mut t_1400cb232: u32 = core::ptr::read((0x1400cb238_u64).wrapping_add(0x328490_u64) as *const u32);
    /* 1400cb232 */ let mut t_1400cb232_0: u32 = ((rcx as u32)).wrapping_add(t_1400cb232);
    /* 1400cb232 */ rcx = (t_1400cb232_0 as u64);
    /* 1400cb238 */ fn_140071cd0();
    /* fallthrough -> bb3126 */

    // ---- bb3126 @ 0x1400cb23d ----
    /* 1400cb23d */ let mut t_1400cb23d_0: u32 = 0x0_u32;
    /* 1400cb23d */ r15 = (t_1400cb23d_0 as u64);
    /* 1400cb240 */ rdi = core::ptr::read((r14).wrapping_add(0x60_u64) as *const u64);
    /* 1400cb244 */ rcx = core::ptr::read((r14).wrapping_add(0x68_u64) as *const u64);
    /* 1400cb248 */ let mut t_1400cb248_0: u64 = (rcx).wrapping_sub(rdi);
    /* 1400cb248 */ rcx = t_1400cb248_0;
    /* 1400cb24b */ rax = 0x4ec4ec4ec4ec4ec5_u64;
    /* 1400cb255 */ let mut t_1400cb255_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 1400cb255 */ rdx = ((t_1400cb255_0 >> 0x40_u128) as u64);
    /* 1400cb255 */ rax = (t_1400cb255_0 as u64);
    /* 1400cb258 */ rdx = (((rdx as i64) >> ((0x5_u8 as u64) as i64)) as u64);
    /* 1400cb25c */ rax = rdx;
    /* 1400cb25f */ rax = (rax >> (0x3f_u8 as u64));
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x238124]
    // intrinsic: f3440f10 movss xmm10, dword ptr [rip + 0x2d1a2f]
    /* 1400cb275 */ let mut t_1400cb275_0: u64 = (rdx).wrapping_add(rax);
    /* 1400cb275 */ rdx = t_1400cb275_0;
    if (t_1400cb1c9 != 0x1_u32) {
        /* -> bb3141 */
    } else {
        /* -> bb3140 */
    }

    // ---- bb3140 @ 0x1400cb278 ----
    if (t_1400cb1c9 != 0x1_u32) {
        /* -> bb3141 */
    } else {
        /* -> bb3415 */
    }

    // ---- bb3141 @ 0x1400cb27e ----
    /* 1400cb27e */ r13 = rsi;
    /* 1400cb281 */ let mut t_1400cb281_0: u32 = 0x0_u32;
    /* 1400cb281 */ rsi = (t_1400cb281_0 as u64);
    /* 1400cb283 */ r8 = (0x1400cb28a_u64).wrapping_add(0x30f5e6_u64);
    // intrinsic: f3440f10 movss xmm9, dword ptr [rip + 0x2380c9]
    // intrinsic: f3440f10 movss xmm15, dword ptr [rip + 0x2384b4]
    // intrinsic: f3440f10 movss xmm13, dword ptr [rip + 0x2380f3]
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x23849f]
    // intrinsic: 450f57f6 xorps xmm14, xmm14
    // intrinsic: f3440f10 movss xmm11, dword ptr [rip + 0x2380d2]
    // intrinsic: f3440f10 movss xmm12, dword ptr [rip + 0x243b01]
    /* 1400cb2c3 */ r12 = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* fallthrough -> bb3153 */

    // ---- bb3153 @ 0x1400cb2d0 ----
    /* 1400cb2d0 */ let mut t_1400cb2d0: u32 = core::ptr::read((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u32);
    /* 1400cb2d0 */ rdx = (t_1400cb2d0 as u64);
    if ((rdx as u32) != 0xffffffff_u32) {
        /* -> bb3158 */
    } else {
        /* -> bb3157 */
    }

    // ---- bb3157 @ 0x1400cb2d6 ----
    if ((rdx as u32) != 0xffffffff_u32) {
        /* -> bb3158 */
    } else {
        /* -> bb3398 */
    }

    // ---- bb3158 @ 0x1400cb2dc ----
    /* 1400cb2dc */ let mut t_1400cb2dc: u8 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x5d_u64) as *const u8);
    if (t_1400cb2dc != 0x0_u8) {
        /* -> bb3162 */
    } else {
        /* -> bb3161 */
    }

    // ---- bb3161 @ 0x1400cb2e1 ----
    if (t_1400cb2dc != 0x0_u8) {
        /* -> bb3162 */
    } else {
        /* -> bb3398 */
    }

    // ---- bb3162 @ 0x1400cb2e7 ----
    if (t_1400cb2dc == 0x0_u8) {
        /* -> bb3166 */
    } else {
        /* -> bb3165 */
    }

    // ---- bb3165 @ 0x1400cb2e9 ----
    if (t_1400cb2dc == 0x0_u8) {
        /* -> bb3166 */
    } else {
        /* -> bb3170 */
    }

    // ---- bb3166 @ 0x1400cb2eb ----
    /* 1400cb2eb */ let mut t_1400cb2eb: u8 = core::ptr::read((0x1400cb2f1_u64).wrapping_add(0x30e2b3_u64) as *const u8);
    if (t_1400cb2eb == (rdx as u8)) {
        /* -> bb3170 */
    } else {
        /* -> bb3169 */
    }

    // ---- bb3169 @ 0x1400cb2f1 ----
    if (t_1400cb2eb == (rdx as u8)) {
        /* -> bb3170 */
    } else {
        /* -> bb3398 */
    }

    // ---- bb3170 @ 0x1400cb2f7 ----
    /* 1400cb2f7 */ let mut t_1400cb2f7: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x60_u64) as *const u32);
    /* 1400cb2f7 */ core::ptr::write(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x60_u64) as *mut u32, (t_1400cb2f7).wrapping_add(0x1_u32));
    /* 1400cb2fb */ let mut t_1400cb2fb: u8 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x30_u64) as *const u8);
    if (t_1400cb2eb != (rdx as u8)) {
        /* -> bb3175 */
    } else {
        /* -> bb3174 */
    }

    // ---- bb3174 @ 0x1400cb300 ----
    if (t_1400cb2eb != (rdx as u8)) {
        /* -> bb3175 */
    } else {
        /* -> bb3179 */
    }

    // ---- bb3175 @ 0x1400cb302 ----
    /* 1400cb302 */ rax = core::ptr::read(r14 as *const u64);
    /* 1400cb305 */ rcx = r14;
    /* 1400cb308 */ (/* indirect */ core::ptr::read((rax).wrapping_add(0x50_u64) as *const u64))();
    /* fallthrough -> bb3397 */

    // ---- bb3179 @ 0x1400cb310 ----
    /* 1400cb310 */ let mut t_1400cb310: u32 = core::ptr::read((r14).wrapping_add(0xd8_u64) as *const u32);
    if (t_1400cb310 == (r15 as u32)) {
        /* -> bb3183 */
    } else {
        /* -> bb3182 */
    }

    // ---- bb3182 @ 0x1400cb317 ----
    if (t_1400cb310 == (r15 as u32)) {
        /* -> bb3183 */
    } else {
        /* -> bb3194 */
    }

    // ---- bb3183 @ 0x1400cb319 ----
    /* 1400cb319 */ let mut t_1400cb319: u32 = core::ptr::read((r14).wrapping_add(0x168_u64) as *const u32);
    if (t_1400cb319 == 0xffffffff_u32) {
        /* -> bb3187 */
    } else {
        /* -> bb3186 */
    }

    // ---- bb3186 @ 0x1400cb321 ----
    if (t_1400cb319 == 0xffffffff_u32) {
        /* -> bb3187 */
    } else {
        /* -> bb3194 */
    }

    // ---- bb3187 @ 0x1400cb323 ----
    /* 1400cb323 */ let mut t_1400cb323: u32 = core::ptr::read((r14).wrapping_add(0xd4_u64) as *const u32);
    if (t_1400cb323 == 0xffffffff_u32) {
        /* -> bb3191 */
    } else {
        /* -> bb3190 */
    }

    // ---- bb3190 @ 0x1400cb32b ----
    if (t_1400cb323 == 0xffffffff_u32) {
        /* -> bb3191 */
    } else {
        /* -> bb3194 */
    }

    // ---- bb3191 @ 0x1400cb32d ----
    /* 1400cb32d */ let mut t_1400cb32d: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x54_u64) as *const u32);
    /* 1400cb32d */ rax = ((t_1400cb32d as i64) as u64);
    /* 1400cb332 */ rbx = ((rax).wrapping_mul(0x4_u64)).wrapping_add(0x2_u64);
    /* fallthrough -> bb3196 */

    // ---- bb3194 @ 0x1400cb33c ----
    /* 1400cb33c */ let mut t_1400cb33c: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x54_u64) as *const u32);
    /* 1400cb33c */ rax = ((t_1400cb33c as i64) as u64);
    /* 1400cb341 */ rbx = ((rax).wrapping_mul(0x4_u64)).wrapping_add(0x1_u64);
    /* fallthrough -> bb3196 */

    // ---- bb3196 @ 0x1400cb349 ----
    /* 1400cb349 */ let mut t_1400cb349_0: u64 = (rbx).wrapping_add(rax);
    /* 1400cb349 */ rbx = t_1400cb349_0;
    /* 1400cb34c */ rbx = (r8).wrapping_add((rbx).wrapping_mul(0x4_u64));
    /* 1400cb350 */ let mut t_1400cb350: u32 = core::ptr::read(rbx as *const u32);
    /* 1400cb350 */ rbx = (t_1400cb350 as u64);
    /* 1400cb352 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rbx as u32));
    // intrinsic: f30f105c movss xmm3, dword ptr [rdi + rsi + 0x40]
    // intrinsic: f30f1054 movss xmm2, dword ptr [rdi + rsi + 0x3c]
    // intrinsic: f30f104c movss xmm1, dword ptr [rdi + rsi + 0x38]
    // intrinsic: f30f1044 movss xmm0, dword ptr [rdi + rsi + 0x34]
    /* 1400cb36e */ fn_140070fb0();
    /* 1400cb373 */ let mut t_1400cb373: u8 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x30_u64) as *const u8);
    if (t_1400cb323 != 0xffffffff_u32) {
        /* -> bb3209 */
    } else {
        /* -> bb3208 */
    }

    // ---- bb3208 @ 0x1400cb378 ----
    if (t_1400cb323 != 0xffffffff_u32) {
        /* -> bb3209 */
    } else {
        /* -> bb3227 */
    }

    // ---- bb3209 @ 0x1400cb37a ----
    // intrinsic: f30f104c movss xmm1, dword ptr [rdi + rsi + 0x38]
    // intrinsic: f30f106c movss xmm5, dword ptr [rdi + rsi + 0x40]
    // intrinsic: f30f1044 movss xmm0, dword ptr [rdi + rsi + 0x34]
    /* 1400cb38c */ xmm6 = xmm5;
    // intrinsic: f30f59f7 mulss xmm6, xmm7
    // intrinsic: f30f58f1 addss xmm6, xmm1
    /* 1400cb397 */ xmm2 = xmm5;
    // intrinsic: f3410f59 mulss xmm2, xmm9
    /* 1400cb39f */ xmm4 = xmm0;
    // intrinsic: f30f5ce2 subss xmm4, xmm2
    /* 1400cb3a6 */ xmm3 = xmm1;
    // intrinsic: f30f58dd addss xmm3, xmm5
    /* 1400cb3ad */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u32, (rbx as u32));
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x28], xmm6
    // intrinsic: f30f1164 movss dword ptr [rsp + 0x20], xmm4
    /* 1400cb3bd */ xmm2 = xmm0;
    /* 1400cb3c0 */ fn_1400717c0();
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x23837f]
    /* fallthrough -> bb3227 */

    // ---- bb3227 @ 0x1400cb3cd ----
    /* 1400cb3cd */ let mut t_1400cb3cd: u8 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x30_u64) as *const u8);
    if (t_1400cb323 != 0xffffffff_u32) {
        /* -> bb3231 */
    } else {
        /* -> bb3230 */
    }

    // ---- bb3230 @ 0x1400cb3d2 ----
    if (t_1400cb323 != 0xffffffff_u32) {
        /* -> bb3231 */
    } else {
        /* -> bb3246 */
    }

    // ---- bb3231 @ 0x1400cb3d4 ----
    // intrinsic: f30f104c movss xmm1, dword ptr [rdi + rsi + 0x38]
    // intrinsic: f30f1054 movss xmm2, dword ptr [rdi + rsi + 0x40]
    // intrinsic: f30f1044 movss xmm0, dword ptr [rdi + rsi + 0x34]
    // intrinsic: f30f5844 addss xmm0, dword ptr [rdi + rsi + 0x3c]
    /* 1400cb3ec */ xmm4 = xmm1;
    // intrinsic: f30f58e2 addss xmm4, xmm2
    /* 1400cb3f3 */ xmm3 = xmm2;
    // intrinsic: f30f59df mulss xmm3, xmm7
    // intrinsic: f30f58d9 addss xmm3, xmm1
    // intrinsic: f3410f59 mulss xmm2, xmm9
    // intrinsic: f30f58d0 addss xmm2, xmm0
    /* 1400cb407 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u32, (rbx as u32));
    // intrinsic: f30f1164 movss dword ptr [rsp + 0x28], xmm4
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 1400cb417 */ fn_1400717c0();
    /* fallthrough -> bb3246 */

    // ---- bb3246 @ 0x1400cb41c ----
    /* 1400cb41c */ let mut t_1400cb41c: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x54_u64) as *const u32);
    if (t_1400cb41c == 0x5_u32) {
        /* -> bb3250 */
    } else {
        /* -> bb3249 */
    }

    // ---- bb3249 @ 0x1400cb421 ----
    if (t_1400cb41c == 0x5_u32) {
        /* -> bb3250 */
    } else {
        /* -> bb3267 */
    }

    // ---- bb3250 @ 0x1400cb423 ----
    // intrinsic: f30f104c movss xmm1, dword ptr [rdi + rsi + 0x40]
    // intrinsic: f30f584c addss xmm1, dword ptr [rdi + rsi + 0x38]
    // intrinsic: f30f1044 movss xmm0, dword ptr [rdi + rsi + 0x34]
    // intrinsic: f3410f58 addss xmm0, xmm15
    /* 1400cb43a */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rbx as u32));
    /* 1400cb43e */ xmm3 = xmm13;
    /* 1400cb442 */ xmm2 = xmm8;
    /* 1400cb446 */ fn_140070fb0();
    // intrinsic: f30f104c movss xmm1, dword ptr [rdi + rsi + 0x40]
    // intrinsic: f30f584c addss xmm1, dword ptr [rdi + rsi + 0x38]
    // intrinsic: f30f1044 movss xmm0, dword ptr [rdi + rsi + 0x34]
    // intrinsic: f30f5844 addss xmm0, dword ptr [rdi + rsi + 0x3c]
    // intrinsic: f30f5c05 subss xmm0, dword ptr [rip + 0x237f39]
    /* 1400cb46b */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rbx as u32));
    /* 1400cb46f */ xmm3 = xmm13;
    /* 1400cb473 */ xmm2 = xmm8;
    /* 1400cb477 */ fn_140070fb0();
    /* fallthrough -> bb3267 */

    // ---- bb3267 @ 0x1400cb47c ----
    /* 1400cb47c */ rcx = (0x1400cb483_u64).wrapping_add(0x30f3f9_u64);
    /* 1400cb483 */ let mut t_1400cb483: u32 = core::ptr::read((r14).wrapping_add(0xdc_u64) as *const u32);
    /* 1400cb48a */ rbx = (0x1400cb491_u64).wrapping_add(0x30f3ef_u64);
    if (t_1400cb483 == (r15 as u32)) {
        /* -> bb3271 */
    } else {
        /* -> bb3272 */
    }

    // ---- bb3272 @ 0x1400cb491 ----
    /* 1400cb491 */ rcx = rbx;
    /* fallthrough -> bb3271 */

    // ---- bb3271 @ 0x1400cb495 ----
    /* 1400cb495 */ let mut t_1400cb495: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x54_u64) as *const u32);
    /* 1400cb495 */ rax = ((t_1400cb495 as i64) as u64);
    /* 1400cb49a */ rax = (rax).wrapping_add((rax).wrapping_mul(0x4_u64));
    /* 1400cb49e */ let mut t_1400cb49e: u32 = core::ptr::read((rcx).wrapping_add((rax).wrapping_mul(0x4_u64)) as *const u32);
    /* 1400cb49e */ rax = (t_1400cb49e as u64);
    // intrinsic: f30f105c movss xmm3, dword ptr [rdi + rsi + 0x40]
    // intrinsic: f3410f5c subss xmm3, xmm8
    // intrinsic: f30f1054 movss xmm2, dword ptr [rdi + rsi + 0x3c]
    // intrinsic: f3410f5c subss xmm2, xmm8
    // intrinsic: f30f104c movss xmm1, dword ptr [rdi + rsi + 0x38]
    // intrinsic: f30f58ce addss xmm1, xmm6
    // intrinsic: f30f1044 movss xmm0, dword ptr [rdi + rsi + 0x34]
    // intrinsic: f30f58c6 addss xmm0, xmm6
    /* 1400cb4cb */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 1400cb4cf */ fn_140070fb0();
    /* 1400cb4d4 */ let mut t_1400cb4d4: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x30_u64) as *const u32);
    /* 1400cb4d4 */ rax = (t_1400cb4d4 as u64);
    if (t_1400cb483 != (r15 as u32)) {
        /* -> bb3291 */
    } else {
        /* -> bb3290 */
    }

    // ---- bb3290 @ 0x1400cb4da ----
    if (t_1400cb483 != (r15 as u32)) {
        /* -> bb3291 */
    } else {
        /* -> bb3354 */
    }

    // ---- bb3291 @ 0x1400cb4e0 ----
    /* 1400cb4e0 */ let mut t_1400cb4e0_0: u32 = (0x9_u8 as u32);
    /* 1400cb4e0 */ t_1400cb4e0_0 = ((rax as u32) >> t_1400cb4e0_0);
    if CF {
        /* -> bb3295 */
    } else {
        /* -> bb3294 */
    }

    // ---- bb3294 @ 0x1400cb4e4 ----
    if CF {
        /* -> bb3295 */
    } else {
        /* -> bb3327 */
    }

    // ---- bb3295 @ 0x1400cb4ea ----
    // intrinsic: f30f1044 movss xmm0, dword ptr [rdi + rsi + 0x40]
    // intrinsic: f30f59c7 mulss xmm0, xmm7
    // intrinsic: f30f5844 addss xmm0, dword ptr [rdi + rsi + 0x38]
    // intrinsic: f30f105c movss xmm3, dword ptr [rdi + rsi + 0x50]
    /* 1400cb500 */ let mut t_1400cb500: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x58_u64) as *const u32);
    /* 1400cb500 */ let mut t_1400cb500_0: u64 = ((t_1400cb500 as u64)).wrapping_mul((0x19_u32 as u64));
    /* 1400cb500 */ rax = ((t_1400cb500_0 as u32) as u64);
    /* 1400cb505 */ rdx = (0x28_u32 as u64);
    /* 1400cb50a */ let mut t_1400cb50a_0: u32 = ((rdx as u32)).wrapping_sub((rax as u32));
    /* 1400cb50a */ rdx = (t_1400cb50a_0 as u64);
    /* 1400cb50c */ rcx = (rsi).wrapping_add(0x8_u64);
    /* 1400cb510 */ let mut t_1400cb510_0: u64 = (rcx).wrapping_add(rdi);
    /* 1400cb510 */ rcx = t_1400cb510_0;
    /* 1400cb513 */ let mut t_1400cb513: u64 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x20_u64) as *const u64);
    if ((CF | (t_1400cb513 == 0xf_u64)) == false) { /* -> bb3308 */ }
    if ((CF | (t_1400cb513 == 0xf_u64)) != 0) { /* -> bb3307 */ }

    // ---- bb3307 @ 0x1400cb519 ----
    if ((CF | (t_1400cb513 == 0xf_u64)) == false) { /* -> bb3308 */ }
    if ((CF | (t_1400cb513 == 0xf_u64)) != 0) { /* -> bb3309 */ }

    // ---- bb3308 @ 0x1400cb51b ----
    /* 1400cb51b */ rcx = core::ptr::read(rcx as *const u64);
    /* fallthrough -> bb3309 */

    // ---- bb3309 @ 0x1400cb51e ----
    /* 1400cb51e */ let mut t_1400cb51e: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x54_u64) as *const u32);
    /* 1400cb51e */ rax = ((t_1400cb51e as i64) as u64);
    /* 1400cb523 */ rax = (rax).wrapping_add((rax).wrapping_mul(0x4_u64));
    /* 1400cb527 */ xmm2 = ((rdx as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    // intrinsic: f30f59d3 mulss xmm2, xmm3
    // intrinsic: f30f58d0 addss xmm2, xmm0
    // intrinsic: f30f104c movss xmm1, dword ptr [rdi + rsi + 0x3c]
    // intrinsic: f30f59cf mulss xmm1, xmm7
    // intrinsic: f30f584c addss xmm1, dword ptr [rdi + rsi + 0x34]
    /* 1400cb546 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rcx);
    /* 1400cb54b */ rcx = (0x1400cb552_u64).wrapping_add(0x30f31e_u64);
    /* 1400cb552 */ let mut t_1400cb552: u32 = core::ptr::read(((rcx).wrapping_add((rax).wrapping_mul(0x4_u64))).wrapping_add(0xc_u64) as *const u32);
    /* 1400cb552 */ rax = (t_1400cb552 as u64);
    /* 1400cb556 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    // intrinsic: f30f115c movss dword ptr [rsp + 0x20], xmm3
    /* 1400cb560 */ r9 = (0x2_u32 as u64);
    /* 1400cb566 */ rcx = core::ptr::read((0x1400cb56d_u64).wrapping_add(0x3228a3_u64) as *const u64);
    /* 1400cb56d */ fn_14009e2b0();
    /* fallthrough -> bb3380 */

    // ---- bb3327 @ 0x1400cb577 ----
    /* 1400cb577 */ rcx = rbx;
    /* 1400cb57a */ let mut t_1400cb57a: u32 = core::ptr::read((r14).wrapping_add(0xdc_u64) as *const u32);
    /* 1400cb581 */ rax = (0x1400cb588_u64).wrapping_add(0x30f2f4_u64);
    if (t_1400cb57a == (r15 as u32)) {
        /* -> bb3331 */
    } else {
        /* -> bb3332 */
    }

    // ---- bb3332 @ 0x1400cb588 ----
    /* 1400cb588 */ rcx = rax;
    /* fallthrough -> bb3331 */

    // ---- bb3331 @ 0x1400cb58c ----
    /* 1400cb58c */ let mut t_1400cb58c: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x54_u64) as *const u32);
    /* 1400cb58c */ rax = ((t_1400cb58c as i64) as u64);
    /* 1400cb591 */ rax = (rax).wrapping_add((rax).wrapping_mul(0x4_u64));
    /* 1400cb595 */ let mut t_1400cb595: u32 = core::ptr::read((rcx).wrapping_add((rax).wrapping_mul(0x4_u64)) as *const u32);
    /* 1400cb595 */ rax = (t_1400cb595 as u64);
    // intrinsic: f30f1054 movss xmm2, dword ptr [rdi + rsi + 0x48]
    // intrinsic: f30f5854 addss xmm2, dword ptr [rdi + rsi + 0x38]
    // intrinsic: f30f104c movss xmm1, dword ptr [rdi + rsi + 0x44]
    // intrinsic: f30f584c addss xmm1, dword ptr [rdi + rsi + 0x34]
    /* 1400cb5b0 */ rdx = (rsi).wrapping_add(0x8_u64);
    /* 1400cb5b4 */ let mut t_1400cb5b4_0: u64 = (rdx).wrapping_add(rdi);
    /* 1400cb5b4 */ rdx = t_1400cb5b4_0;
    /* 1400cb5b7 */ let mut t_1400cb5b7: u64 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x20_u64) as *const u64);
    if ((CF | (t_1400cb5b7 == 0xf_u64)) == false) { /* -> bb3346 */ }
    if ((CF | (t_1400cb5b7 == 0xf_u64)) != 0) { /* -> bb3345 */ }

    // ---- bb3345 @ 0x1400cb5bd ----
    if ((CF | (t_1400cb5b7 == 0xf_u64)) == false) { /* -> bb3346 */ }
    if ((CF | (t_1400cb5b7 == 0xf_u64)) != 0) { /* -> bb3347 */ }

    // ---- bb3346 @ 0x1400cb5bf ----
    /* 1400cb5bf */ rdx = core::ptr::read(rdx as *const u64);
    /* fallthrough -> bb3347 */

    // ---- bb3347 @ 0x1400cb5c2 ----
    /* 1400cb5c2 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rdx);
    /* 1400cb5c7 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm10
    /* 1400cb5d2 */ let mut t_1400cb5d2_0: u32 = 0x0_u32;
    /* 1400cb5d2 */ r9 = (t_1400cb5d2_0 as u64);
    /* 1400cb5d5 */ rcx = core::ptr::read((0x1400cb5dc_u64).wrapping_add(0x32283c_u64) as *const u64);
    /* 1400cb5dc */ fn_140086510();
    /* fallthrough -> bb3380 */

    // ---- bb3354 @ 0x1400cb5e3 ----
    /* 1400cb5e3 */ let mut t_1400cb5e3: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x2c_u64) as *const u32);
    if (t_1400cb5e3 != 0xffffffff_u32) {
        /* -> bb3358 */
    } else {
        /* -> bb3357 */
    }

    // ---- bb3357 @ 0x1400cb5e8 ----
    if (t_1400cb5e3 != 0xffffffff_u32) {
        /* -> bb3358 */
    } else {
        /* -> bb3380 */
    }

    // ---- bb3358 @ 0x1400cb5ea ----
    /* 1400cb5ea */ fn_140072790();
    /* 1400cb5ef */ let mut t_1400cb5ef: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x30_u64) as *const u32);
    if (t_1400cb5e3 != 0xffffffff_u32) {
        /* -> bb3363 */
    } else {
        /* -> bb3362 */
    }

    // ---- bb3362 @ 0x1400cb5f7 ----
    if (t_1400cb5e3 != 0xffffffff_u32) {
        /* -> bb3363 */
    } else {
        /* -> bb3369 */
    }

    // ---- bb3363 @ 0x1400cb5f9 ----
    /* 1400cb5f9 */ let mut t_1400cb5f9: u32 = core::ptr::read((r14).wrapping_add(0xdc_u64) as *const u32);
    if (t_1400cb5f9 == (r15 as u32)) {
        /* -> bb3367 */
    } else {
        /* -> bb3366 */
    }

    // ---- bb3366 @ 0x1400cb600 ----
    if (t_1400cb5f9 == (r15 as u32)) {
        /* -> bb3367 */
    } else {
        /* -> bb3369 */
    }

    // ---- bb3367 @ 0x1400cb602 ----
    /* 1400cb602 */ rcx = (0x1_u32 as u64);
    /* fallthrough -> bb3370 */

    // ---- bb3369 @ 0x1400cb609 ----
    /* 1400cb609 */ let mut t_1400cb609_0: u32 = 0x0_u32;
    /* 1400cb609 */ rcx = (t_1400cb609_0 as u64);
    /* fallthrough -> bb3370 */

    // ---- bb3370 @ 0x1400cb60b ----
    // intrinsic: f30f1054 movss xmm2, dword ptr [rdi + rsi + 0x40]
    // intrinsic: f30f59d7 mulss xmm2, xmm7
    // intrinsic: f30f5854 addss xmm2, dword ptr [rdi + rsi + 0x38]
    // intrinsic: f30f104c movss xmm1, dword ptr [rdi + rsi + 0x3c]
    // intrinsic: f30f59cf mulss xmm1, xmm7
    // intrinsic: f30f584c addss xmm1, dword ptr [rdi + rsi + 0x34]
    /* 1400cb62b */ let mut t_1400cb62b: u32 = core::ptr::read(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x2c_u64) as *const u32);
    /* 1400cb62b */ let mut t_1400cb62b_0: u32 = ((rcx as u32)).wrapping_add(t_1400cb62b);
    /* 1400cb62b */ rcx = (t_1400cb62b_0 as u64);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm14
    // intrinsic: f30f105c movss xmm3, dword ptr [rdi + rsi + 0x50]
    /* 1400cb63c */ fn_140071e80();
    /* fallthrough -> bb3380 */

    // ---- bb3380 @ 0x1400cb641 ----
    if ((r15 as u32) == 0x2_u32) {
        /* -> bb3384 */
    } else {
        /* -> bb3383 */
    }

    // ---- bb3383 @ 0x1400cb645 ----
    if ((r15 as u32) == 0x2_u32) {
        /* -> bb3384 */
    } else {
        /* -> bb3397 */
    }

    // ---- bb3384 @ 0x1400cb647 ----
    /* 1400cb647 */ rcx = (0x4_u32 as u64);
    /* 1400cb64c */ rax = core::ptr::read((r12).wrapping_add((r13).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400cb650 */ let mut t_1400cb650: u32 = core::ptr::read((rcx).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 1400cb650 */ rax = (t_1400cb650 as u64);
    /* 1400cb653 */ let mut t_1400cb653: u32 = core::ptr::read((0x1400cb659_u64).wrapping_add(0x32807b_u64) as *const u32);
    if (((SF == OF) & (t_1400cb653 != (rax as u32))) == false) { /* -> bb3391 */ }
    if (((SF == OF) & (t_1400cb653 != (rax as u32))) != 0) { /* -> bb3390 */ }

    // ---- bb3390 @ 0x1400cb659 ----
    if (((SF == OF) & (t_1400cb653 != (rax as u32))) == false) { /* -> bb3391 */ }
    if (((SF == OF) & (t_1400cb653 != (rax as u32))) != 0) { /* -> bb3649 */ }

    // ---- bb3391 @ 0x1400cb65f ----
    // intrinsic: f30f1054 movss xmm2, dword ptr [rdi + rsi + 0x38]
    // intrinsic: f3410f58 addss xmm2, xmm11
    // intrinsic: f30f104c movss xmm1, dword ptr [rdi + rsi + 0x34]
    // intrinsic: f3410f58 addss xmm1, xmm12
    /* 1400cb675 */ let mut t_1400cb675: u32 = core::ptr::read((0x1400cb67b_u64).wrapping_add(0x328055_u64) as *const u32);
    /* 1400cb675 */ rcx = (t_1400cb675 as u64);
    /* 1400cb67b */ fn_140071cd0();
    /* fallthrough -> bb3397 */

    // ---- bb3397 @ 0x1400cb680 ----
    /* 1400cb680 */ r8 = (0x1400cb687_u64).wrapping_add(0x30f1e9_u64);
    /* fallthrough -> bb3398 */

    // ---- bb3398 @ 0x1400cb687 ----
    /* 1400cb687 */ r15 = (((r15 as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400cb68a */ let mut t_1400cb68a_0: u64 = (rsi).wrapping_add(0x68_u64);
    /* 1400cb68a */ rsi = t_1400cb68a_0;
    /* 1400cb68e */ rdi = core::ptr::read((r14).wrapping_add(0x60_u64) as *const u64);
    /* 1400cb692 */ rcx = core::ptr::read((r14).wrapping_add(0x68_u64) as *const u64);
    /* 1400cb696 */ let mut t_1400cb696_0: u64 = (rcx).wrapping_sub(rdi);
    /* 1400cb696 */ rcx = t_1400cb696_0;
    /* 1400cb699 */ rax = 0x4ec4ec4ec4ec4ec5_u64;
    /* 1400cb6a3 */ let mut t_1400cb6a3_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 1400cb6a3 */ rdx = ((t_1400cb6a3_0 >> 0x40_u128) as u64);
    /* 1400cb6a3 */ rax = (t_1400cb6a3_0 as u64);
    /* 1400cb6a6 */ rdx = (((rdx as i64) >> ((0x5_u8 as u64) as i64)) as u64);
    /* 1400cb6aa */ rax = rdx;
    /* 1400cb6ad */ rax = (rax >> (0x3f_u8 as u64));
    /* 1400cb6b1 */ let mut t_1400cb6b1_0: u64 = (rdx).wrapping_add(rax);
    /* 1400cb6b1 */ rdx = t_1400cb6b1_0;
    /* 1400cb6b4 */ rax = (((r15 as u32) as i64) as u64);
    if (CF == false) { /* -> bb3414 */ }
    if CF { /* -> bb3413 */ }

    // ---- bb3413 @ 0x1400cb6ba ----
    if CF { /* -> bb3153 */ }
    if (CF == false) { /* -> bb3414 */ }

    // ---- bb3414 @ 0x1400cb6c0 ----
    /* 1400cb6c0 */ let mut t_1400cb6c0: u8 = core::ptr::read((rbp).wrapping_add(0x77_u64) as *const u8);
    /* 1400cb6c0 */ r12 = ((t_1400cb6c0 as u32) as u64);
    /* fallthrough -> bb3415 */

    // ---- bb3415 @ 0x1400cb6c5 ----
    /* 1400cb6c5 */ fn_140072790();
    /* 1400cb6ca */ let mut t_1400cb6ca: u8 = core::ptr::read((rbp).wrapping_add(0x6f_u64) as *const u8);
    if (t_1400cb6ca != 0x0_u8) {
        /* -> bb3420 */
    } else {
        /* -> bb3419 */
    }

    // ---- bb3419 @ 0x1400cb6ce ----
    if (t_1400cb6ca != 0x0_u8) {
        /* -> bb3420 */
    } else {
        /* -> bb3426 */
    }

    // ---- bb3420 @ 0x1400cb6d0 ----
    /* 1400cb6d0 */ let mut t_1400cb6d0: u8 = core::ptr::read((0x1400cb6d7_u64).wrapping_add(0x30decd_u64) as *const u8);
    if (t_1400cb6d0 == 0x0_u8) {
        /* -> bb3424 */
    } else {
        /* -> bb3423 */
    }

    // ---- bb3423 @ 0x1400cb6d7 ----
    if (t_1400cb6d0 == 0x0_u8) {
        /* -> bb3424 */
    } else {
        /* -> bb3426 */
    }

    // ---- bb3424 @ 0x1400cb6d9 ----
    /* 1400cb6d9 */ rcx = core::ptr::read((0x1400cb6e0_u64).wrapping_add(0x32fb08_u64) as *const u64);
    /* 1400cb6e0 */ fn_14010fbf0();
    /* fallthrough -> bb3426 */

    // ---- bb3426 @ 0x1400cb6e5 ----
    if (t_1400cb6d0 != 0x0_u8) {
        /* -> bb3430 */
    } else {
        /* -> bb3429 */
    }

    // ---- bb3429 @ 0x1400cb6e8 ----
    if (t_1400cb6d0 != 0x0_u8) {
        /* -> bb3430 */
    } else {
        /* -> bb3472 */
    }

    // ---- bb3430 @ 0x1400cb6ea ----
    /* 1400cb6ea */ let mut t_1400cb6ea: u8 = core::ptr::read((0x1400cb6f1_u64).wrapping_add(0x322041_u64) as *const u8);
    if (t_1400cb6ea == 0x0_u8) {
        /* -> bb3434 */
    } else {
        /* -> bb3433 */
    }

    // ---- bb3433 @ 0x1400cb6f1 ----
    if (t_1400cb6ea == 0x0_u8) {
        /* -> bb3434 */
    } else {
        /* -> bb3438 */
    }

    // ---- bb3434 @ 0x1400cb6f3 ----
    /* 1400cb6f3 */ let mut t_1400cb6f3: u8 = core::ptr::read((0x1400cb6fa_u64).wrapping_add(0x32203c_u64) as *const u8);
    if (t_1400cb6f3 != 0x0_u8) {
        /* -> bb3438 */
    } else {
        /* -> bb3437 */
    }

    // ---- bb3437 @ 0x1400cb6fa ----
    if (t_1400cb6f3 != 0x0_u8) {
        /* -> bb3438 */
    } else {
        /* -> bb3465 */
    }

    // ---- bb3438 @ 0x1400cb6fc ----
    /* 1400cb6fc */ fn_14008d280();
    if (t_1400cb6f3 == 0x0_u8) {
        /* -> bb3443 */
    } else {
        /* -> bb3442 */
    }

    // ---- bb3442 @ 0x1400cb703 ----
    if (t_1400cb6f3 == 0x0_u8) {
        /* -> bb3443 */
    } else {
        /* -> bb3465 */
    }

    // ---- bb3443 @ 0x1400cb705 ----
    /* 1400cb705 */ let mut t_1400cb705_0: u32 = 0x0_u32;
    /* 1400cb705 */ rbx = (t_1400cb705_0 as u64);
    /* 1400cb707 */ rax = core::ptr::read((r14).wrapping_add(0x138_u64) as *const u64);
    /* 1400cb70e */ let mut t_1400cb70e: u64 = core::ptr::read((r14).wrapping_add(0x130_u64) as *const u64);
    /* 1400cb70e */ let mut t_1400cb70e_0: u64 = (rax).wrapping_sub(t_1400cb70e);
    /* 1400cb70e */ rax = t_1400cb70e_0;
    /* 1400cb715 */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (t_1400cb6f3 != 0x0_u8) {
        /* -> bb3451 */
    } else {
        /* -> bb3450 */
    }

    // ---- bb3450 @ 0x1400cb71c ----
    if (t_1400cb6f3 != 0x0_u8) {
        /* -> bb3451 */
    } else {
        /* -> bb3472 */
    }

    // ---- bb3451 @ 0x1400cb71e ----
    /* fallthrough -> bb3452 */

    // ---- bb3452 @ 0x1400cb720 ----
    /* 1400cb720 */ rdx = ((rbx as u32) as u64);
    /* 1400cb722 */ rcx = r14;
    /* 1400cb725 */ fn_1400d56d0();
    /* 1400cb72a */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400cb72c */ rcx = core::ptr::read((r14).wrapping_add(0x138_u64) as *const u64);
    /* 1400cb733 */ let mut t_1400cb733: u64 = core::ptr::read((r14).wrapping_add(0x130_u64) as *const u64);
    /* 1400cb733 */ let mut t_1400cb733_0: u64 = (rcx).wrapping_sub(t_1400cb733);
    /* 1400cb733 */ rcx = t_1400cb733_0;
    /* 1400cb73a */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400cb73e */ rax = (((rbx as u32) as i64) as u64);
    if (CF == false) { /* -> bb3464 */ }
    if CF { /* -> bb3463 */ }

    // ---- bb3463 @ 0x1400cb744 ----
    if CF { /* -> bb3452 */ }
    if (CF == false) { /* -> bb3464 */ }

    // ---- bb3464 @ 0x1400cb746 ----
    /* fallthrough -> bb3472 */

    // ---- bb3465 @ 0x1400cb748 ----
    /* 1400cb748 */ let mut t_1400cb748: u32 = core::ptr::read((r14).wrapping_add(0x16c_u64) as *const u32);
    /* 1400cb748 */ rdx = (t_1400cb748 as u64);
    if ((rdx as u32) != 0xffffffff_u32) {
        /* -> bb3470 */
    } else {
        /* -> bb3469 */
    }

    // ---- bb3469 @ 0x1400cb752 ----
    if ((rdx as u32) != 0xffffffff_u32) {
        /* -> bb3470 */
    } else {
        /* -> bb3472 */
    }

    // ---- bb3470 @ 0x1400cb754 ----
    /* 1400cb754 */ rcx = r14;
    /* 1400cb757 */ fn_1400d56d0();
    /* fallthrough -> bb3472 */

    // ---- bb3472 @ 0x1400cb75c ----
    /* 1400cb75c */ let mut t_1400cb75c: u32 = core::ptr::read((r14).wrapping_add(0x1a0_u64) as *const u32);
    /* 1400cb75c */ rcx = (t_1400cb75c as u64);
    if ((rcx as u32) != 0xffffffff_u32) {
        /* -> bb3477 */
    } else {
        /* -> bb3476 */
    }

    // ---- bb3476 @ 0x1400cb766 ----
    if ((rcx as u32) != 0xffffffff_u32) {
        /* -> bb3477 */
    } else {
        /* -> bb3541 */
    }

    // ---- bb3477 @ 0x1400cb76c ----
    /* 1400cb76c */ rbx = (r14).wrapping_add(0x1a8_u64);
    // intrinsic: f30f1013 movss xmm2, dword ptr [rbx]
    // intrinsic: f3410f10 movss xmm1, dword ptr [r14 + 0x1a4]
    /* 1400cb780 */ fn_140071cd0();
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x23f617]
    // intrinsic: 0f2f0300 comiss xmm0, dword ptr [rbx]
    if ((CF | ((rcx as u32) == 0xffffffff_u32)) == false) { /* -> bb3486 */ }
    if ((CF | ((rcx as u32) == 0xffffffff_u32)) != 0) { /* -> bb3485 */ }

    // ---- bb3485 @ 0x1400cb790 ----
    if ((CF | ((rcx as u32) == 0xffffffff_u32)) == false) { /* -> bb3486 */ }
    if ((CF | ((rcx as u32) == 0xffffffff_u32)) != 0) { /* -> bb3488 */ }

    // ---- bb3486 @ 0x1400cb792 ----
    /* 1400cb792 */ core::ptr::write((r14).wrapping_add(0x1a0_u64) as *mut u32, 0xffffffff_u32);
    /* fallthrough -> bb3541 */

    // ---- bb3488 @ 0x1400cb7a2 ----
    /* 1400cb7a2 */ let mut t_1400cb7a2: u32 = core::ptr::read((r14).wrapping_add(0x1b0_u64) as *const u32);
    if (t_1400cb7a2 == 0x2_u32) {
        /* -> bb3492 */
    } else {
        /* -> bb3491 */
    }

    // ---- bb3491 @ 0x1400cb7aa ----
    if (t_1400cb7a2 == 0x2_u32) {
        /* -> bb3492 */
    } else {
        /* -> bb3496 */
    }

    // ---- bb3492 @ 0x1400cb7ac ----
    /* 1400cb7ac */ let mut t_1400cb7ac: u32 = core::ptr::read((r14).wrapping_add(0x1b4_u64) as *const u32);
    if (SF == OF) {
        /* -> bb3496 */
    } else {
        /* -> bb3495 */
    }

    // ---- bb3495 @ 0x1400cb7b7 ----
    if (SF == OF) {
        /* -> bb3496 */
    } else {
        /* -> bb3541 */
    }

    // ---- bb3496 @ 0x1400cb7bd ----
    /* 1400cb7bd */ let mut t_1400cb7bd: u32 = core::ptr::read((r14).wrapping_add(0x1b4_u64) as *const u32);
    if (t_1400cb7bd == 0x12d_u32) {
        /* -> bb3500 */
    } else {
        /* -> bb3499 */
    }

    // ---- bb3499 @ 0x1400cb7c8 ----
    if (t_1400cb7bd == 0x12d_u32) {
        /* -> bb3500 */
    } else {
        /* -> bb3538 */
    }

    // ---- bb3500 @ 0x1400cb7ce ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400cb7d1 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm0);
    /* 1400cb7d6 */ xmm1 = core::ptr::read((0x1400cb7de_u64).wrapping_add(0x2388a2_u64) as *const u128);
    /* 1400cb7de */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm1);
    /* 1400cb7e4 */ let mut t_1400cb7e4: u32 = core::ptr::read((0x1400cb7ea_u64).wrapping_add(0x23c0d2_u64) as *const u32);
    /* 1400cb7e4 */ rax = (t_1400cb7e4 as u64);
    /* 1400cb7ea */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u32, (rax as u32));
    /* 1400cb7ee */ let mut t_1400cb7ee: u8 = core::ptr::read((0x1400cb7f5_u64).wrapping_add(0x23c0cb_u64) as *const u8);
    /* 1400cb7ee */ rax = ((t_1400cb7ee as u32) as u64);
    /* 1400cb7f5 */ core::ptr::write((rsp).wrapping_add(0x44_u64) as *mut u8, (rax as u8));
    /* 1400cb7f9 */ core::ptr::write((rsp).wrapping_add(0x45_u64) as *mut u8, 0x0_u8);
    /* 1400cb7fe */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400cb803 */ xmm3 = xmm10;
    /* 1400cb807 */ let mut t_1400cb807_0: u32 = 0x0_u32;
    /* 1400cb807 */ r8 = (t_1400cb807_0 as u64);
    /* 1400cb80a */ rdx = (0x32_u32 as u64);
    /* 1400cb80f */ rcx = (rsp).wrapping_add(0x40_u64);
    /* 1400cb814 */ fn_140040b90();
    /* 1400cb81a */ rdx = core::ptr::read((rsp).wrapping_add(0x58_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb3521 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb3520 */ }

    // ---- bb3520 @ 0x1400cb823 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb3521 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb3538 */ }

    // ---- bb3521 @ 0x1400cb825 ----
    /* 1400cb825 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400cb828 */ rcx = core::ptr::read((rsp).wrapping_add(0x40_u64) as *const u64);
    /* 1400cb82d */ rax = rcx;
    if (CF == false) { /* -> bb3528 */ }
    if CF { /* -> bb3527 */ }

    // ---- bb3527 @ 0x1400cb837 ----
    if (CF == false) { /* -> bb3528 */ }
    if CF { /* -> bb3536 */ }

    // ---- bb3528 @ 0x1400cb839 ----
    /* 1400cb839 */ let mut t_1400cb839_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400cb839 */ rdx = t_1400cb839_0;
    /* 1400cb83d */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400cb841 */ let mut t_1400cb841_0: u64 = (rax).wrapping_sub(rcx);
    /* 1400cb841 */ rax = t_1400cb841_0;
    /* 1400cb844 */ let mut t_1400cb844_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 1400cb844 */ rax = t_1400cb844_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb3536 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3535 */ }

    // ---- bb3535 @ 0x1400cb84c ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb3536 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb3594 */ }

    // ---- bb3536 @ 0x1400cb852 ----
    /* 1400cb852 */ fn_1402c7498();
    /* 1400cb857 */ rbx = (r14).wrapping_add(0x1a8_u64);
    /* fallthrough -> bb3538 */

    // ---- bb3538 @ 0x1400cb85e ----
    // intrinsic: f30f1003 movss xmm0, dword ptr [rbx]
    // intrinsic: f3410f5c subss xmm0, xmm8
    // intrinsic: f30f1103 movss dword ptr [rbx], xmm0
    /* fallthrough -> bb3541 */

    // ---- bb3541 @ 0x1400cb86b ----
    /* 1400cb86b */ rax = core::ptr::read((r14).wrapping_add(0x60_u64) as *const u64);
    /* 1400cb86f */ core::ptr::write((rax).wrapping_add(0x1fd_u64) as *mut u8, (r12 as u8));
    if (t_1400cb7ac != 0x12c_u32) {
        /* -> bb3547 */
    } else {
        /* -> bb3546 */
    }

    // ---- bb3546 @ 0x1400cb879 ----
    if (t_1400cb7ac != 0x12c_u32) {
        /* -> bb3547 */
    } else {
        /* -> bb3570 */
    }

    // ---- bb3547 @ 0x1400cb87b ----
    /* 1400cb87b */ let mut t_1400cb87b: u32 = core::ptr::read((r14).wrapping_add(0x16c_u64) as *const u32);
    /* 1400cb87b */ rax = ((t_1400cb87b as i64) as u64);
    if ((rax as u32) != 0xffffffff_u32) {
        /* -> bb3552 */
    } else {
        /* -> bb3551 */
    }

    // ---- bb3551 @ 0x1400cb885 ----
    if ((rax as u32) != 0xffffffff_u32) {
        /* -> bb3552 */
    } else {
        /* -> bb3570 */
    }

    // ---- bb3552 @ 0x1400cb887 ----
    /* 1400cb887 */ rcx = rax;
    /* 1400cb88a */ rax = core::ptr::read((r14).wrapping_add(0x130_u64) as *const u64);
    /* 1400cb891 */ rdx = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400cb895 */ let mut t_1400cb895: u8 = core::ptr::read((rdx).wrapping_add(0x204_u64) as *const u8);
    if (t_1400cb895 == 0x0_u8) {
        /* -> bb3559 */
    } else {
        /* -> bb3558 */
    }

    // ---- bb3558 @ 0x1400cb89c ----
    if (t_1400cb895 == 0x0_u8) {
        /* -> bb3559 */
    } else {
        /* -> bb3563 */
    }

    // ---- bb3559 @ 0x1400cb89e ----
    /* 1400cb89e */ let mut t_1400cb89e: u32 = core::ptr::read((rdx).wrapping_add(0x1c_u64) as *const u32);
    if (t_1400cb89e == 0x3_u32) {
        /* -> bb3563 */
    } else {
        /* -> bb3562 */
    }

    // ---- bb3562 @ 0x1400cb8a2 ----
    if (t_1400cb89e == 0x3_u32) {
        /* -> bb3563 */
    } else {
        /* -> bb3570 */
    }

    // ---- bb3563 @ 0x1400cb8a4 ----
    /* 1400cb8a4 */ fn_14008d280();
    if (t_1400cb89e == 0x3_u32) {
        /* -> bb3568 */
    } else {
        /* -> bb3567 */
    }

    // ---- bb3567 @ 0x1400cb8ab ----
    if (t_1400cb89e == 0x3_u32) {
        /* -> bb3568 */
    } else {
        /* -> bb3570 */
    }

    // ---- bb3568 @ 0x1400cb8ad ----
    /* 1400cb8ad */ rcx = ((rcx & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* fallthrough -> bb3571 */

    // ---- bb3570 @ 0x1400cb8b1 ----
    /* 1400cb8b1 */ let mut t_1400cb8b1_0: u8 = 0x0_u8;
    /* 1400cb8b1 */ rcx = ((rcx & 0xffffffffffffff00_u64) | (t_1400cb8b1_0 as u64));
    /* fallthrough -> bb3571 */

    // ---- bb3571 @ 0x1400cb8b3 ----
    /* 1400cb8b3 */ rax = core::ptr::read((r14).wrapping_add(0x60_u64) as *const u64);
    /* 1400cb8b7 */ core::ptr::write((rax).wrapping_add(0x265_u64) as *mut u8, (rcx as u8));
    /* 1400cb8bd */ r11 = (rsp).wrapping_add(0x100_u64);
    /* 1400cb8c5 */ rbx = core::ptr::read((r11).wrapping_add(0x58_u64) as *const u64);
    /* 1400cb8c9 */ xmm6 = core::ptr::read((r11).wrapping_sub(0x10_u64) as *const u128);
    /* 1400cb8ce */ xmm7 = core::ptr::read((r11).wrapping_sub(0x20_u64) as *const u128);
    /* 1400cb8d3 */ xmm8 = core::ptr::read((r11).wrapping_sub(0x30_u64) as *const u128);
    /* 1400cb8d8 */ xmm9 = core::ptr::read((r11).wrapping_sub(0x40_u64) as *const u128);
    /* 1400cb8dd */ xmm10 = core::ptr::read((r11).wrapping_sub(0x50_u64) as *const u128);
    /* 1400cb8e2 */ let mut xmm11: u128 = core::ptr::read((r11).wrapping_sub(0x60_u64) as *const u128);
    /* 1400cb8e7 */ xmm12 = core::ptr::read((r11).wrapping_sub(0x70_u64) as *const u128);
    /* 1400cb8ec */ xmm13 = core::ptr::read((r11).wrapping_sub(0x80_u64) as *const u128);
    /* 1400cb8f1 */ let mut xmm14: u128 = core::ptr::read((rsp).wrapping_add(0x70_u64) as *const u128);
    /* 1400cb8f7 */ let mut xmm15: u128 = core::ptr::read((rsp).wrapping_add(0x60_u64) as *const u128);
    /* 1400cb8fd */ rsp = r11;
    /* 1400cb900 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400cb900 */ r15 = core::ptr::read(rsp as *const u64);
    /* 1400cb902 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400cb902 */ r14 = core::ptr::read(rsp as *const u64);
    /* 1400cb904 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400cb904 */ r13 = core::ptr::read(rsp as *const u64);
    /* 1400cb906 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400cb906 */ r12 = core::ptr::read(rsp as *const u64);
    /* 1400cb908 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400cb908 */ rdi = core::ptr::read(rsp as *const u64);
    /* 1400cb909 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400cb909 */ rsi = core::ptr::read(rsp as *const u64);
    /* 1400cb90a */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400cb90a */ rbp = core::ptr::read(rsp as *const u64);
    /* 1400cb90b */ return;
    // <no successors>

    // ---- bb3594 @ 0x1400cb90c ----
    /* 1400cb90c */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 1400cb915 */ let mut t_1400cb915_0: u32 = 0x0_u32;
    /* 1400cb915 */ r9 = (t_1400cb915_0 as u64);
    /* 1400cb918 */ let mut t_1400cb918_0: u32 = 0x0_u32;
    /* 1400cb918 */ r8 = (t_1400cb918_0 as u64);
    /* 1400cb91b */ let mut t_1400cb91b_0: u32 = 0x0_u32;
    /* 1400cb91b */ rdx = (t_1400cb91b_0 as u64);
    /* 1400cb91d */ let mut t_1400cb91d_0: u32 = 0x0_u32;
    /* 1400cb91d */ rcx = (t_1400cb91d_0 as u64);
    /* 1400cb91f */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb3601 */

    // ---- bb3601 @ 0x1400cb925 ----
    /* 1400cb925 */ rcx = (0x1400cb92c_u64).wrapping_add(0x327d98_u64);
    /* 1400cb92c */ fn_1402c7548();
    /* 1400cb931 */ let mut t_1400cb931: u32 = core::ptr::read((0x1400cb938_u64).wrapping_add(0x327d8c_u64) as *const u32);
    if (t_1400cb931 == 0xffffffff_u32) {
        /* -> bb3607 */
    } else {
        /* -> bb3606 */
    }

    // ---- bb3606 @ 0x1400cb938 ----
    if (t_1400cb931 != 0xffffffff_u32) {
        /* -> bb3080 */
    } else {
        /* -> bb3607 */
    }

    // ---- bb3607 @ 0x1400cb93e ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400cb941 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm0);
    /* 1400cb946 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u64, 0x6_u64);
    /* 1400cb94f */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u64, 0xf_u64);
    /* 1400cb958 */ let mut t_1400cb958: u32 = core::ptr::read((0x1400cb95e_u64).wrapping_add(0x23a5a6_u64) as *const u32);
    /* 1400cb958 */ rax = (t_1400cb958 as u64);
    /* 1400cb95e */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u32, (rax as u32));
    /* 1400cb962 */ let mut t_1400cb962: u16 = core::ptr::read((0x1400cb969_u64).wrapping_add(0x23a59f_u64) as *const u16);
    /* 1400cb962 */ rax = ((t_1400cb962 as u32) as u64);
    /* 1400cb969 */ core::ptr::write((rsp).wrapping_add(0x44_u64) as *mut u16, (rax as u16));
    /* 1400cb96e */ core::ptr::write((rsp).wrapping_add(0x46_u64) as *mut u8, 0x0_u8);
    /* 1400cb973 */ rcx = (rsp).wrapping_add(0x40_u64);
    /* 1400cb978 */ fn_14006fd40();
    /* 1400cb97d */ core::ptr::write((0x1400cb983_u64).wrapping_add(0x327d3d_u64) as *mut u32, (rax as u32));
    /* 1400cb983 */ rcx = (0x1400cb98a_u64).wrapping_add(0x327d3a_u64);
    /* 1400cb98a */ fn_1402c74dc();
    /* fallthrough -> bb3080 */

    // ---- bb3622 @ 0x1400cb994 ----
    /* 1400cb994 */ rcx = (0x1400cb99b_u64).wrapping_add(0x327d31_u64);
    /* 1400cb99b */ fn_1402c7548();
    /* 1400cb9a0 */ let mut t_1400cb9a0: u32 = core::ptr::read((0x1400cb9a7_u64).wrapping_add(0x327d25_u64) as *const u32);
    if (t_1400cb9a0 == 0xffffffff_u32) {
        /* -> bb3628 */
    } else {
        /* -> bb3627 */
    }

    // ---- bb3627 @ 0x1400cb9a7 ----
    if (t_1400cb9a0 != 0xffffffff_u32) {
        /* -> bb3085 */
    } else {
        /* -> bb3628 */
    }

    // ---- bb3628 @ 0x1400cb9ad ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400cb9b0 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm0);
    /* 1400cb9b5 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u64, 0xc_u64);
    /* 1400cb9be */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u64, 0xf_u64);
    /* 1400cb9c7 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb3633 */ }
    if DF { /* -> bb3634 */ }

    // ---- bb3633 @ 0x1400cb9c7 ----
    /* 1400cb9c7 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400cb9c7 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb3635 */

    // ---- bb3634 @ 0x1400cb9c7 ----
    /* 1400cb9c7 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400cb9c7 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb3635 */

    // ---- bb3635 @ 0x1400cb9cf ----
    /* 1400cb9cf */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb3637 */ }
    if DF { /* -> bb3638 */ }

    // ---- bb3637 @ 0x1400cb9cf ----
    /* 1400cb9cf */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400cb9cf */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb3639 */

    // ---- bb3638 @ 0x1400cb9cf ----
    /* 1400cb9cf */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400cb9cf */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb3639 */

    // ---- bb3639 @ 0x1400cb9d5 ----
    /* 1400cb9d5 */ let mut t_1400cb9d5: u32 = core::ptr::read((0x1400cb9db_u64).wrapping_add(0x23bffd_u64) as *const u32);
    /* 1400cb9d5 */ rax = (t_1400cb9d5 as u64);
    /* 1400cb9db */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u32, (rax as u32));
    /* 1400cb9df */ core::ptr::write((rsp).wrapping_add(0x4c_u64) as *mut u8, 0x0_u8);
    /* 1400cb9e4 */ rcx = (rsp).wrapping_add(0x40_u64);
    /* 1400cb9e9 */ fn_14006fd40();
    /* 1400cb9ee */ core::ptr::write((0x1400cb9f4_u64).wrapping_add(0x327cd4_u64) as *mut u32, (rax as u32));
    /* 1400cb9f4 */ rcx = (0x1400cb9fb_u64).wrapping_add(0x327cd1_u64);
    /* 1400cb9fb */ fn_1402c74dc();
    /* fallthrough -> bb3085 */

    // ---- bb3649 @ 0x1400cba05 ----
    /* 1400cba05 */ rcx = (0x1400cba0c_u64).wrapping_add(0x327cc8_u64);
    /* 1400cba0c */ fn_1402c7548();
    /* 1400cba11 */ let mut t_1400cba11: u32 = core::ptr::read((0x1400cba18_u64).wrapping_add(0x327cbc_u64) as *const u32);
    if (t_1400cba11 == 0xffffffff_u32) {
        /* -> bb3655 */
    } else {
        /* -> bb3654 */
    }

    // ---- bb3654 @ 0x1400cba18 ----
    if (t_1400cba11 != 0xffffffff_u32) {
        /* -> bb3391 */
    } else {
        /* -> bb3655 */
    }

    // ---- bb3655 @ 0x1400cba1e ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400cba21 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm0);
    /* 1400cba26 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u64, 0x9_u64);
    /* 1400cba2f */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u64, 0xf_u64);
    /* 1400cba38 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb3660 */ }
    if DF { /* -> bb3661 */ }

    // ---- bb3660 @ 0x1400cba38 ----
    /* 1400cba38 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400cba38 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb3662 */

    // ---- bb3661 @ 0x1400cba38 ----
    /* 1400cba38 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400cba38 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb3662 */

    // ---- bb3662 @ 0x1400cba40 ----
    /* 1400cba40 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb3664 */ }
    if DF { /* -> bb3665 */ }

    // ---- bb3664 @ 0x1400cba40 ----
    /* 1400cba40 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400cba40 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb3666 */

    // ---- bb3665 @ 0x1400cba40 ----
    /* 1400cba40 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400cba40 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb3666 */

    // ---- bb3666 @ 0x1400cba46 ----
    /* 1400cba46 */ let mut t_1400cba46: u8 = core::ptr::read((0x1400cba4d_u64).wrapping_add(0x242fbb_u64) as *const u8);
    /* 1400cba46 */ rax = ((t_1400cba46 as u32) as u64);
    /* 1400cba4d */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u8, (rax as u8));
    /* 1400cba51 */ core::ptr::write((rsp).wrapping_add(0x49_u64) as *mut u8, 0x0_u8);
    /* 1400cba56 */ rcx = (rsp).wrapping_add(0x40_u64);
    /* 1400cba5b */ fn_14006fd40();
    /* 1400cba60 */ core::ptr::write((0x1400cba66_u64).wrapping_add(0x327c6a_u64) as *mut u32, (rax as u32));
    /* 1400cba66 */ rcx = (0x1400cba6d_u64).wrapping_add(0x327c67_u64);
    /* 1400cba6d */ fn_1402c74dc();
    /* fallthrough -> bb3391 */
}
