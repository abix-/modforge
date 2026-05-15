// Decompiled from Horsey.exe @ 0x1400e0aa0
// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print
// blocks: 104

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]
pub unsafe fn none_of_horses_are_tired() {

    // ---- bb11 @ 0x1400e0a32 ----
    if (rax != rcx) {
        /* -> bb12 */
    } else {
        /* -> bb252 */
    }

    // ---- bb12 @ 0x1400e0a38 ----
    /* 1400e0a38 */ let mut t_1400e0a38: u64 = core::ptr::read((r15).wrapping_add(0x148_u64) as *const u64);
    if (rbx != t_1400e0a38) {
        /* -> bb16 */
    } else {
        /* -> bb15 */
    }

    // ---- bb15 @ 0x1400e0a3f ----
    if (rbx != t_1400e0a38) {
        /* -> bb16 */
    } else {
        /* -> bb252 */
    }

    // ---- bb16 @ 0x1400e0a45 ----
    /* 1400e0a45 */ let mut t_1400e0a45: u32 = core::ptr::read((rbx).wrapping_add(0x224_u64) as *const u32);
    if (t_1400e0a45 == 0x0_u32) {
        /* -> bb20 */
    } else {
        /* -> bb19 */
    }

    // ---- bb19 @ 0x1400e0a4c ----
    if (t_1400e0a45 == 0x0_u32) {
        /* -> bb20 */
    } else {
        /* -> bb252 */
    }

    // ---- bb20 @ 0x1400e0a52 ----
    /* 1400e0a52 */ let mut t_1400e0a52: u8 = core::ptr::read((rdi).wrapping_add(0x58_u64) as *const u8);
    if (t_1400e0a52 == 0x0_u8) {
        /* -> bb24 */
    } else {
        /* -> bb23 */
    }

    // ---- bb23 @ 0x1400e0a56 ----
    if (t_1400e0a52 == 0x0_u8) {
        /* -> bb24 */
    } else {
        /* -> bb252 */
    }

    // ---- bb24 @ 0x1400e0a5c ----
    /* 1400e0a5c */ let mut r8: u64 = ((r14 as u32) as u64);
    /* 1400e0a5f */ let mut rdx: u64 = rbx;
    /* 1400e0a62 */ let mut rcx: u64 = r15;
    /* 1400e0a65 */ fn_1400cfe10();
    if (t_1400e0a52 != 0x0_u8) {
        /* -> bb32 */
    } else {
        /* -> bb31 */
    }

    // ---- bb31 @ 0x1400e0a6c ----
    if (t_1400e0a52 != 0x0_u8) {
        /* -> bb32 */
    } else {
        /* -> bb252 */
    }

    // ---- bb32 @ 0x1400e0a72 ----
    /* 1400e0a72 */ let mut t_1400e0a72: u32 = core::ptr::read((rbx).wrapping_add(0x214_u64) as *const u32);
    if ((r14 as u32) == 0x1_u32) {
        /* -> bb38 */
    } else {
        /* -> bb37 */
    }

    // ---- bb37 @ 0x1400e0a80 ----
    if ((r14 as u32) == 0x1_u32) {
        /* -> bb38 */
    } else {
        /* -> bb44 */
    }

    // ---- bb38 @ 0x1400e0a82 ----
    /* 1400e0a82 */ let mut t_1400e0a82: u32 = core::ptr::read((rdi).wrapping_add(0x54_u64) as *const u32);
    if (((SF != OF) | (t_1400e0a82 == 0x0_u32)) == false) { /* -> bb42 */ }
    if (((SF != OF) | (t_1400e0a82 == 0x0_u32)) != 0) { /* -> bb41 */ }

    // ---- bb41 @ 0x1400e0a86 ----
    if (((SF != OF) | (t_1400e0a82 == 0x0_u32)) == false) { /* -> bb42 */ }
    if (((SF != OF) | (t_1400e0a82 == 0x0_u32)) != 0) { /* -> bb48 */ }

    // ---- bb42 @ 0x1400e0a88 ----
    /* 1400e0a88 */ let mut t_1400e0a88_0: u8 = 0x0_u8;
    /* fallthrough -> bb48 */

    // ---- bb44 @ 0x1400e0a8c ----
    if ((r14 as u32) != 0x8_u32) {
        /* -> bb48 */
    } else {
        /* -> bb47 */
    }

    // ---- bb47 @ 0x1400e0a90 ----
    if ((r14 as u32) != 0x8_u32) {
        /* -> bb48 */
    } else {
        /* -> bb60 */
    }

    // ---- bb48 @ 0x1400e0a92 ----
    /* 1400e0a92 */ rcx = ((rsi as u32) as u64);
    /* 1400e0a94 */ let mut rax: u64 = (((rax as u8) as u32) as u64);
    /* 1400e0a97 */ let mut t_1400e0a97: u32 = core::ptr::read((rbx).wrapping_add(0x21c_u64) as *const u32);
    if (SF == OF) {
        /* -> bb52 */
    } else {
        /* -> bb53 */
    }

    // ---- bb53 @ 0x1400e0a9e ----
    /* 1400e0a9e */ rcx = ((rax as u32) as u64);
    /* fallthrough -> bb52 */

    // ---- bb59 @ 0x1400e0aa0 ----
    /* fallthrough -> bb55 */

    // ---- bb52 @ 0x1400e0aa1 ----
    /* fallthrough -> bb55 */

    // ---- bb55 @ 0x1400e0aa4 ----
    if ((r14 as u32) != 0x5_u32) {
        /* -> bb60 */
    } else {
        /* -> bb58 */
    }

    // ---- bb58 @ 0x1400e0aa8 ----
    if ((r14 as u32) != 0x5_u32) {
        /* -> bb60 */
    } else {
        /* -> bb64 */
    }

    // ---- bb60 @ 0x1400e0aaa ----
    /* 1400e0aaa */ let mut t_1400e0aaa: u32 = core::ptr::read((rdi).wrapping_add(0x54_u64) as *const u32);
    if (SF != OF) {
        /* -> bb64 */
    } else {
        /* -> bb63 */
    }

    // ---- bb63 @ 0x1400e0aae ----
    if (SF != OF) {
        /* -> bb64 */
    } else {
        /* -> bb160 */
    }

    // ---- bb64 @ 0x1400e0ab4 ----
    if ((r14 as u32) != 0x5_u32) {
        /* -> bb68 */
    } else {
        /* -> bb67 */
    }

    // ---- bb67 @ 0x1400e0ab6 ----
    if ((r14 as u32) != 0x5_u32) {
        /* -> bb68 */
    } else {
        /* -> bb160 */
    }

    // ---- bb68 @ 0x1400e0abc ----
    /* 1400e0abc */ let mut rdi: u64 = core::ptr::read((rbp).wrapping_sub(0x30_u64) as *const u64);
    /* 1400e0ac0 */ rcx = core::ptr::read((rbp).wrapping_sub(0x28_u64) as *const u64);
    if (rdi != rcx) {
        /* -> bb74 */
    } else {
        /* -> bb73 */
    }

    // ---- bb73 @ 0x1400e0ac7 ----
    if (rdi != rcx) {
        /* -> bb74 */
    } else {
        /* -> bb77 */
    }

    // ---- bb74 @ 0x1400e0ac9 ----
    /* 1400e0ac9 */ core::ptr::write(rdi as *mut u64, rbx);
    /* 1400e0acc */ let mut t_1400e0acc: u64 = core::ptr::read((rbp).wrapping_sub(0x30_u64) as *const u64);
    /* 1400e0acc */ core::ptr::write((rbp).wrapping_sub(0x30_u64) as *mut u64, (t_1400e0acc).wrapping_add(0x8_u64));
    /* fallthrough -> bb160 */

    // ---- bb77 @ 0x1400e0ad6 ----
    /* 1400e0ad9 */ rax = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    /* 1400e0add */ let mut rsi: u64 = (rsi).wrapping_sub(rax);
    /* 1400e0ae0 */ rsi = (((rsi as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400e0ae4 */ r8 = 0x1fffffffffffffff_u64;
    if (rsi != r8) {
        /* -> bb86 */
    } else {
        /* -> bb85 */
    }

    // ---- bb85 @ 0x1400e0af1 ----
    if (rsi != r8) {
        /* -> bb86 */
    } else {
        /* -> bb372 */
    }

    // ---- bb86 @ 0x1400e0af7 ----
    /* 1400e0af7 */ let mut r13: u64 = (rsi).wrapping_add(0x1_u64);
    /* 1400e0afb */ rcx = (rcx).wrapping_sub(rax);
    /* 1400e0afe */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400e0b02 */ rdx = rcx;
    /* 1400e0b05 */ rdx = (rdx >> 0x1_u64);
    /* 1400e0b0b */ rax = (rax).wrapping_sub(rdx);
    if ((CF | (rcx == rax)) == false) { /* -> bb97 */ }
    if ((CF | (rcx == rax)) != 0) { /* -> bb96 */ }

    // ---- bb96 @ 0x1400e0b11 ----
    if ((CF | (rcx == rax)) == false) { /* -> bb97 */ }
    if ((CF | (rcx == rax)) != 0) { /* -> bb99 */ }

    // ---- bb97 @ 0x1400e0b13 ----
    /* 1400e0b13 */ rcx = r8;
    /* fallthrough -> bb109 */

    // ---- bb99 @ 0x1400e0b18 ----
    /* 1400e0b18 */ rax = (rcx).wrapping_add((rdx).wrapping_mul(0x1_u64));
    /* 1400e0b1c */ rcx = r13;
    if CF {
        /* -> bb103 */
    } else {
        /* -> bb104 */
    }

    // ---- bb104 @ 0x1400e0b22 ----
    /* 1400e0b22 */ rcx = rax;
    /* fallthrough -> bb103 */

    // ---- bb103 @ 0x1400e0b26 ----
    if (((CF == false) & (rcx != r8)) == false) { /* -> bb109 */ }
    if (((CF == false) & (rcx != r8)) != 0) { /* -> bb108 */ }

    // ---- bb108 @ 0x1400e0b29 ----
    if (((CF == false) & (rcx != r8)) == false) { /* -> bb109 */ }
    if (((CF == false) & (rcx != r8)) != 0) { /* -> bb370 */ }

    // ---- bb109 @ 0x1400e0b2f ----
    /* 1400e0b2f */ let mut r12: u64 = (rcx).wrapping_mul(0x8_u64);
    /* 1400e0b37 */ rcx = r12;
    /* 1400e0b3a */ fn_1400285e0();
    /* 1400e0b3f */ let mut r14: u64 = rax;
    /* 1400e0b42 */ core::ptr::write((rax).wrapping_add((rsi).wrapping_mul(0x8_u64)) as *mut u64, rbx);
    /* 1400e0b46 */ let mut t_1400e0b46: u64 = core::ptr::read((rbp).wrapping_sub(0x30_u64) as *const u64);
    /* 1400e0b4a */ rdx = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    /* 1400e0b4e */ rcx = rax;
    if (rdi == r8) {
        /* -> bb121 */
    } else {
        /* -> bb120 */
    }

    // ---- bb120 @ 0x1400e0b54 ----
    if (rdi == r8) {
        /* -> bb121 */
    } else {
        /* -> bb123 */
    }

    // ---- bb121 @ 0x1400e0b56 ----
    /* 1400e0b56 */ let mut t_1400e0b56_0: u64 = (r8).wrapping_sub(rdx);
    /* 1400e0b56 */ r8 = t_1400e0b56_0;
    /* fallthrough -> bb131 */

    // ---- bb123 @ 0x1400e0b5b ----
    /* 1400e0b5e */ let mut t_1400e0b5e_0: u64 = (r8).wrapping_sub(rdx);
    /* 1400e0b5e */ r8 = t_1400e0b5e_0;
    /* 1400e0b61 */ fn_1402f9230();
    /* 1400e0b66 */ let mut t_1400e0b66: u64 = core::ptr::read((rbp).wrapping_sub(0x30_u64) as *const u64);
    /* 1400e0b6a */ let mut t_1400e0b6a_0: u64 = (r8).wrapping_sub(rdi);
    /* 1400e0b6a */ r8 = t_1400e0b6a_0;
    /* 1400e0b71 */ rcx = (r14).wrapping_add((rcx).wrapping_mul(0x8_u64));
    /* 1400e0b75 */ rdx = rdi;
    /* fallthrough -> bb131 */

    // ---- bb131 @ 0x1400e0b78 ----
    /* 1400e0b78 */ fn_1402f9230();
    /* 1400e0b7d */ rcx = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    if (rdi != r8) {
        /* -> bb137 */
    } else {
        /* -> bb136 */
    }

    // ---- bb136 @ 0x1400e0b84 ----
    if (rdi != r8) {
        /* -> bb137 */
    } else {
        /* -> bb154 */
    }

    // ---- bb137 @ 0x1400e0b86 ----
    /* 1400e0b86 */ let mut t_1400e0b86: u64 = core::ptr::read((rbp).wrapping_sub(0x28_u64) as *const u64);
    /* 1400e0b8a */ rdx = (rdx).wrapping_sub(rcx);
    /* 1400e0b8d */ rdx = (rdx & 0xfffffffffffffff8_u64);
    /* 1400e0b91 */ rax = rcx;
    if (CF == false) { /* -> bb145 */ }
    if CF { /* -> bb144 */ }

    // ---- bb144 @ 0x1400e0b9b ----
    if (CF == false) { /* -> bb145 */ }
    if CF { /* -> bb153 */ }

    // ---- bb145 @ 0x1400e0b9d ----
    /* 1400e0b9d */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 1400e0ba1 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400e0ba5 */ rax = (rax).wrapping_sub(rcx);
    /* 1400e0ba8 */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb153 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb152 */ }

    // ---- bb152 @ 0x1400e0bb0 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb153 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb362 */ }

    // ---- bb153 @ 0x1400e0bb6 ----
    /* 1400e0bb6 */ fn_1402c7498();
    /* fallthrough -> bb154 */

    // ---- bb154 @ 0x1400e0bbb ----
    /* 1400e0bbb */ core::ptr::write((rbp).wrapping_sub(0x38_u64) as *mut u64, r14);
    /* 1400e0bc3 */ core::ptr::write((rbp).wrapping_sub(0x30_u64) as *mut u64, rax);
    /* 1400e0bcb */ core::ptr::write((rbp).wrapping_sub(0x28_u64) as *mut u64, rax);
    /* 1400e0bcf */ let mut t_1400e0bcf: u32 = core::ptr::read((rbp).wrapping_add(0x58_u64) as *const u32);
    /* 1400e0bcf */ r12 = (t_1400e0bcf as u64);
    /* fallthrough -> bb160 */

    // ---- bb160 @ 0x1400e0bd3 ----
    /* 1400e0bd3 */ rdi = core::ptr::read((rbp).wrapping_sub(0x18_u64) as *const u64);
    /* 1400e0bd7 */ rcx = core::ptr::read((rbp).wrapping_sub(0x10_u64) as *const u64);
    if (rdi != rcx) {
        /* -> bb166 */
    } else {
        /* -> bb165 */
    }

    // ---- bb165 @ 0x1400e0bde ----
    if (rdi != rcx) {
        /* -> bb166 */
    } else {
        /* -> bb169 */
    }

    // ---- bb166 @ 0x1400e0be0 ----
    /* 1400e0be0 */ core::ptr::write(rdi as *mut u64, rbx);
    /* 1400e0be3 */ let mut t_1400e0be3: u64 = core::ptr::read((rbp).wrapping_sub(0x18_u64) as *const u64);
    /* 1400e0be3 */ core::ptr::write((rbp).wrapping_sub(0x18_u64) as *mut u64, (t_1400e0be3).wrapping_add(0x8_u64));
    /* fallthrough -> bb252 */

    // ---- bb169 @ 0x1400e0bed ----
    /* 1400e0bf0 */ rax = core::ptr::read((rbp).wrapping_sub(0x20_u64) as *const u64);
    /* 1400e0bf4 */ r14 = (r14).wrapping_sub(rax);
    /* 1400e0bf7 */ r14 = (((r14 as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400e0bfb */ r8 = 0x1fffffffffffffff_u64;
    if (r14 != r8) {
        /* -> bb178 */
    } else {
        /* -> bb177 */
    }

    // ---- bb177 @ 0x1400e0c08 ----
    if (r14 != r8) {
        /* -> bb178 */
    } else {
        /* -> bb372 */
    }

    // ---- bb178 @ 0x1400e0c0e ----
    /* 1400e0c0e */ r13 = (r14).wrapping_add(0x1_u64);
    /* 1400e0c12 */ rcx = (rcx).wrapping_sub(rax);
    /* 1400e0c15 */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400e0c19 */ rdx = rcx;
    /* 1400e0c1c */ rdx = (rdx >> 0x1_u64);
    /* 1400e0c22 */ rax = (rax).wrapping_sub(rdx);
    if ((CF | (rcx == rax)) == false) { /* -> bb189 */ }
    if ((CF | (rcx == rax)) != 0) { /* -> bb188 */ }

    // ---- bb188 @ 0x1400e0c28 ----
    if ((CF | (rcx == rax)) == false) { /* -> bb189 */ }
    if ((CF | (rcx == rax)) != 0) { /* -> bb191 */ }

    // ---- bb189 @ 0x1400e0c2a ----
    /* 1400e0c2a */ rcx = r8;
    /* fallthrough -> bb201 */

    // ---- bb191 @ 0x1400e0c2f ----
    /* 1400e0c2f */ rax = (rdx).wrapping_add((rcx).wrapping_mul(0x1_u64));
    /* 1400e0c33 */ rcx = r13;
    if CF {
        /* -> bb195 */
    } else {
        /* -> bb196 */
    }

    // ---- bb196 @ 0x1400e0c39 ----
    /* 1400e0c39 */ rcx = rax;
    /* fallthrough -> bb195 */

    // ---- bb195 @ 0x1400e0c3d ----
    if (((CF == false) & (rcx != r8)) == false) { /* -> bb201 */ }
    if (((CF == false) & (rcx != r8)) != 0) { /* -> bb200 */ }

    // ---- bb200 @ 0x1400e0c40 ----
    if (((CF == false) & (rcx != r8)) == false) { /* -> bb201 */ }
    if (((CF == false) & (rcx != r8)) != 0) { /* -> bb370 */ }

    // ---- bb201 @ 0x1400e0c46 ----
    /* 1400e0c46 */ r12 = (rcx).wrapping_mul(0x8_u64);
    /* 1400e0c4e */ rcx = r12;
    /* 1400e0c51 */ fn_1400285e0();
    /* 1400e0c56 */ rsi = rax;
    /* 1400e0c59 */ core::ptr::write((rax).wrapping_add((r14).wrapping_mul(0x8_u64)) as *mut u64, rbx);
    /* 1400e0c5d */ let mut t_1400e0c5d: u64 = core::ptr::read((rbp).wrapping_sub(0x18_u64) as *const u64);
    /* 1400e0c61 */ rdx = core::ptr::read((rbp).wrapping_sub(0x20_u64) as *const u64);
    /* 1400e0c65 */ rcx = rax;
    if (rdi == r8) {
        /* -> bb213 */
    } else {
        /* -> bb212 */
    }

    // ---- bb212 @ 0x1400e0c6b ----
    if (rdi == r8) {
        /* -> bb213 */
    } else {
        /* -> bb215 */
    }

    // ---- bb213 @ 0x1400e0c6d ----
    /* 1400e0c6d */ let mut t_1400e0c6d_0: u64 = (r8).wrapping_sub(rdx);
    /* 1400e0c6d */ r8 = t_1400e0c6d_0;
    /* fallthrough -> bb223 */

    // ---- bb215 @ 0x1400e0c72 ----
    /* 1400e0c75 */ let mut t_1400e0c75_0: u64 = (r8).wrapping_sub(rdx);
    /* 1400e0c75 */ r8 = t_1400e0c75_0;
    /* 1400e0c78 */ fn_1402f9230();
    /* 1400e0c7d */ let mut t_1400e0c7d: u64 = core::ptr::read((rbp).wrapping_sub(0x18_u64) as *const u64);
    /* 1400e0c81 */ let mut t_1400e0c81_0: u64 = (r8).wrapping_sub(rdi);
    /* 1400e0c81 */ r8 = t_1400e0c81_0;
    /* 1400e0c88 */ rcx = (rsi).wrapping_add((rcx).wrapping_mul(0x8_u64));
    /* 1400e0c8c */ rdx = rdi;
    /* fallthrough -> bb223 */

    // ---- bb223 @ 0x1400e0c8f ----
    /* 1400e0c8f */ fn_1402f9230();
    /* 1400e0c94 */ rcx = core::ptr::read((rbp).wrapping_sub(0x20_u64) as *const u64);
    if (rdi != r8) {
        /* -> bb229 */
    } else {
        /* -> bb228 */
    }

    // ---- bb228 @ 0x1400e0c9b ----
    if (rdi != r8) {
        /* -> bb229 */
    } else {
        /* -> bb246 */
    }

    // ---- bb229 @ 0x1400e0c9d ----
    /* 1400e0c9d */ let mut t_1400e0c9d: u64 = core::ptr::read((rbp).wrapping_sub(0x10_u64) as *const u64);
    /* 1400e0ca1 */ rdx = (rdx).wrapping_sub(rcx);
    /* 1400e0ca4 */ rdx = (rdx & 0xfffffffffffffff8_u64);
    /* 1400e0ca8 */ rax = rcx;
    if (CF == false) { /* -> bb237 */ }
    if CF { /* -> bb236 */ }

    // ---- bb236 @ 0x1400e0cb2 ----
    if (CF == false) { /* -> bb237 */ }
    if CF { /* -> bb245 */ }

    // ---- bb237 @ 0x1400e0cb4 ----
    /* 1400e0cb4 */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 1400e0cb8 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400e0cbc */ rax = (rax).wrapping_sub(rcx);
    /* 1400e0cbf */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb245 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb244 */ }

    // ---- bb244 @ 0x1400e0cc7 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb245 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb362 */ }

    // ---- bb245 @ 0x1400e0ccd ----
    /* 1400e0ccd */ fn_1402c7498();
    /* fallthrough -> bb246 */

    // ---- bb246 @ 0x1400e0cd2 ----
    /* 1400e0cd2 */ core::ptr::write((rbp).wrapping_sub(0x20_u64) as *mut u64, rsi);
    /* 1400e0cda */ core::ptr::write((rbp).wrapping_sub(0x18_u64) as *mut u64, rax);
    /* 1400e0ce2 */ core::ptr::write((rbp).wrapping_sub(0x10_u64) as *mut u64, rax);
    /* 1400e0ce6 */ let mut t_1400e0ce6: u32 = core::ptr::read((rbp).wrapping_add(0x58_u64) as *const u32);
    /* 1400e0ce6 */ r12 = (t_1400e0ce6 as u64);
    /* fallthrough -> bb252 */

    // ---- bb252 @ 0x1400e0cea ----
    /* 1400e0cea */ r12 = (((r12 as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400e0ced */ core::ptr::write((rbp).wrapping_add(0x58_u64) as *mut u32, (r12 as u32));
    /* 1400e0cf1 */ rdx = core::ptr::read((rbp).wrapping_add(0x60_u64) as *const u64);
    /* 1400e0cf5 */ rdx = (rdx).wrapping_add(0x8_u64);
    /* 1400e0cf9 */ core::ptr::write((rbp).wrapping_add(0x60_u64) as *mut u64, rdx);
    /* 1400e0cfd */ r8 = core::ptr::read((r15).wrapping_add(0x130_u64) as *const u64);
    /* 1400e0d04 */ let mut t_1400e0d04: u64 = core::ptr::read((r15).wrapping_add(0x138_u64) as *const u64);
    /* 1400e0d0b */ rcx = (rcx).wrapping_sub(r8);
    /* 1400e0d0e */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400e0d12 */ rax = (((r12 as u32) as i64) as u64);
    /* 1400e0d15 */ let mut t_1400e0d15_0: u32 = 0x0_u32;
    /* 1400e0d15 */ rsi = (t_1400e0d15_0 as u64);
    if CF {
        /* -> bb267 */
    } else {
        /* -> bb266 */
    }

    // ---- bb266 @ 0x1400e0d1a ----
    if CF {
        /* -> bb267 */
    } else {
        /* -> bb269 */
    }

    // ---- bb267 @ 0x1400e0d1c ----
    /* 1400e0d1c */ let mut t_1400e0d1c: u32 = core::ptr::read((rbp).wrapping_add(0x50_u64) as *const u32);
    /* 1400e0d1c */ r14 = (t_1400e0d1c as u64);
    /* 1400e0a11 */ let mut rbx: u64 = core::ptr::read((rdx).wrapping_add((r8).wrapping_mul(0x1_u64)) as *const u64);
    /* 1400e0a15 */ let mut t_1400e0a15: u32 = core::ptr::read((rbx).wrapping_add(0x1f8_u64) as *const u32);
    /* 1400e0a15 */ rcx = (t_1400e0a15 as u64);
    /* 1400e0a1b */ fn_1400c7930();
    /* 1400e0a20 */ rdi = rax;
    /* 1400e0a23 */ let mut t_1400e0a23_0: u32 = 0x0_u32;
    /* 1400e0a23 */ r8 = (t_1400e0a23_0 as u64);
    /* 1400e0a26 */ let mut t_1400e0a26_0: u32 = 0x0_u32;
    /* 1400e0a26 */ rdx = (t_1400e0a26_0 as u64);
    /* 1400e0a28 */ rcx = rbx;
    /* 1400e0a2b */ fn_1400b7650();
    if (rax != rcx) {
        /* -> bb12 */
    } else {
        /* -> bb11 */
    }

    // ---- bb269 @ 0x1400e0d25 ----
    /* 1400e0d25 */ let mut t_1400e0d25: u64 = core::ptr::read((rbp).wrapping_sub(0x18_u64) as *const u64);
    /* 1400e0d29 */ let mut t_1400e0d29: u64 = core::ptr::read((rbp).wrapping_sub(0x20_u64) as *const u64);
    /* 1400e0d2d */ rax = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    if (t_1400e0d29 == rax) {
        /* -> bb275 */
    } else {
        /* -> bb274 */
    }

    // ---- bb274 @ 0x1400e0d31 ----
    if (t_1400e0d29 == rax) {
        /* -> bb275 */
    } else {
        /* -> bb277 */
    }

    // ---- bb275 @ 0x1400e0d33 ----
    /* 1400e0d33 */ rbx = rsi;
    /* fallthrough -> bb297 */

    // ---- bb277 @ 0x1400e0d38 ----
    /* 1400e0d38 */ let mut t_1400e0d38: u64 = core::ptr::read((rbp).wrapping_sub(0x30_u64) as *const u64);
    if (rax == rcx) {
        /* -> bb282 */
    } else {
        /* -> bb281 */
    }

    // ---- bb281 @ 0x1400e0d3f ----
    if (rax == rcx) {
        /* -> bb282 */
    } else {
        /* -> bb291 */
    }

    // ---- bb282 @ 0x1400e0d41 ----
    /* 1400e0d41 */ let mut t_1400e0d41: u64 = core::ptr::read((rbp).wrapping_sub(0x18_u64) as *const u64);
    /* 1400e0d45 */ let mut t_1400e0d45: u64 = core::ptr::read((rbp).wrapping_sub(0x20_u64) as *const u64);
    /* 1400e0d45 */ rcx = (rcx).wrapping_sub(t_1400e0d45);
    /* 1400e0d49 */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400e0d4d */ fn_1400c6990();
    /* 1400e0d55 */ let mut t_1400e0d55: u64 = core::ptr::read((rbp).wrapping_sub(0x20_u64) as *const u64);
    /* 1400e0d59 */ rbx = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400e0d5d */ rax = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    /* fallthrough -> bb297 */

    // ---- bb291 @ 0x1400e0d63 ----
    /* 1400e0d63 */ rcx = (rcx).wrapping_sub(rax);
    /* 1400e0d66 */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 1400e0d6a */ fn_1400c6990();
    /* 1400e0d72 */ rax = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    /* 1400e0d76 */ rbx = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* fallthrough -> bb297 */

    // ---- bb297 @ 0x1400e0d7a ----
    if (rax != rcx) {
        /* -> bb301 */
    } else {
        /* -> bb300 */
    }

    // ---- bb300 @ 0x1400e0d7d ----
    if (rax != rcx) {
        /* -> bb301 */
    } else {
        /* -> bb322 */
    }

    // ---- bb301 @ 0x1400e0d7f ----
    /* 1400e0d7f */ let mut t_1400e0d7f: u64 = core::ptr::read((rbp).wrapping_sub(0x28_u64) as *const u64);
    /* 1400e0d83 */ rdx = (rdx).wrapping_sub(rax);
    /* 1400e0d86 */ rdx = (rdx & 0xfffffffffffffff8_u64);
    if (CF == false) { /* -> bb309 */ }
    if CF { /* -> bb308 */ }

    // ---- bb308 @ 0x1400e0d94 ----
    if (CF == false) { /* -> bb309 */ }
    if CF { /* -> bb317 */ }

    // ---- bb309 @ 0x1400e0d96 ----
    /* 1400e0d96 */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 1400e0d9a */ rax = core::ptr::read((rax).wrapping_sub(0x8_u64) as *const u64);
    /* 1400e0d9e */ rcx = (rcx).wrapping_sub(rax);
    /* 1400e0da1 */ rcx = (rcx).wrapping_sub(0x8_u64);
    if (((CF == false) & (rcx != 0x1f_u64)) == false) { /* -> bb317 */ }
    if (((CF == false) & (rcx != 0x1f_u64)) != 0) { /* -> bb316 */ }

    // ---- bb316 @ 0x1400e0da9 ----
    if (((CF == false) & (rcx != 0x1f_u64)) == false) { /* -> bb317 */ }
    if (((CF == false) & (rcx != 0x1f_u64)) != 0) { /* -> bb374 */ }

    // ---- bb317 @ 0x1400e0daf ----
    /* 1400e0daf */ rcx = rax;
    /* 1400e0db2 */ fn_1402c7498();
    /* 1400e0dba */ core::ptr::write((rbp).wrapping_sub(0x38_u64) as *mut u128, xmm0);
    /* 1400e0dbf */ core::ptr::write((rbp).wrapping_sub(0x28_u64) as *mut u64, rsi);
    /* fallthrough -> bb322 */

    // ---- bb322 @ 0x1400e0dc3 ----
    /* 1400e0dc3 */ rcx = core::ptr::read((rbp).wrapping_sub(0x20_u64) as *const u64);
    if (rax != rcx) {
        /* -> bb327 */
    } else {
        /* -> bb326 */
    }

    // ---- bb326 @ 0x1400e0dca ----
    if (rax != rcx) {
        /* -> bb327 */
    } else {
        /* -> bb344 */
    }

    // ---- bb327 @ 0x1400e0dcc ----
    /* 1400e0dcc */ let mut t_1400e0dcc: u64 = core::ptr::read((rbp).wrapping_sub(0x10_u64) as *const u64);
    /* 1400e0dd0 */ rdx = (rdx).wrapping_sub(rcx);
    /* 1400e0dd3 */ rdx = (rdx & 0xfffffffffffffff8_u64);
    /* 1400e0dd7 */ rax = rcx;
    if (CF == false) { /* -> bb335 */ }
    if CF { /* -> bb334 */ }

    // ---- bb334 @ 0x1400e0de1 ----
    if (CF == false) { /* -> bb335 */ }
    if CF { /* -> bb343 */ }

    // ---- bb335 @ 0x1400e0de3 ----
    /* 1400e0de3 */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 1400e0de7 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400e0deb */ rax = (rax).wrapping_sub(rcx);
    /* 1400e0dee */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb343 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb342 */ }

    // ---- bb342 @ 0x1400e0df6 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb343 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb355 */ }

    // ---- bb343 @ 0x1400e0df8 ----
    /* 1400e0df8 */ fn_1402c7498();
    /* fallthrough -> bb344 */

    // ---- bb344 @ 0x1400e0dfd ----
    /* 1400e0dfd */ rax = rbx;
    /* 1400e0e00 */ let mut t_1400e0e00_0: u64 = (rsp).wrapping_add(0x68_u64);
    /* 1400e0e00 */ rsp = t_1400e0e00_0;
    /* 1400e0e04 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400e0e04 */ let mut r15: u64 = core::ptr::read(rsp as *const u64);
    /* 1400e0e06 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400e0e06 */ r14 = core::ptr::read(rsp as *const u64);
    /* 1400e0e08 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400e0e08 */ r13 = core::ptr::read(rsp as *const u64);
    /* 1400e0e0a */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400e0e0a */ r12 = core::ptr::read(rsp as *const u64);
    /* 1400e0e0c */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400e0e0c */ rdi = core::ptr::read(rsp as *const u64);
    /* 1400e0e0d */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400e0e0d */ rsi = core::ptr::read(rsp as *const u64);
    /* 1400e0e0e */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400e0e0e */ rbx = core::ptr::read(rsp as *const u64);
    /* 1400e0e0f */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400e0e0f */ let mut rbp: u64 = core::ptr::read(rsp as *const u64);
    /* 1400e0e10 */ return;
    // <no successors>

    // ---- bb355 @ 0x1400e0e11 ----
    /* 1400e0e11 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, rsi);
    /* 1400e0e16 */ let mut t_1400e0e16_0: u32 = 0x0_u32;
    /* 1400e0e16 */ let mut r9: u64 = (t_1400e0e16_0 as u64);
    /* 1400e0e19 */ let mut t_1400e0e19_0: u32 = 0x0_u32;
    /* 1400e0e19 */ r8 = (t_1400e0e19_0 as u64);
    /* 1400e0e1c */ let mut t_1400e0e1c_0: u32 = 0x0_u32;
    /* 1400e0e1c */ rdx = (t_1400e0e1c_0 as u64);
    /* 1400e0e1e */ let mut t_1400e0e1e_0: u32 = 0x0_u32;
    /* 1400e0e1e */ rcx = (t_1400e0e1e_0 as u64);
    /* 1400e0e20 */ fn_1402cd884();
    /* fallthrough -> bb362 */

    // ---- bb362 @ 0x1400e0e26 ----
    /* 1400e0e26 */ let mut t_1400e0e26_0: u32 = 0x0_u32;
    /* 1400e0e26 */ r13 = (t_1400e0e26_0 as u64);
    /* 1400e0e29 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 1400e0e2e */ let mut t_1400e0e2e_0: u32 = 0x0_u32;
    /* 1400e0e2e */ r9 = (t_1400e0e2e_0 as u64);
    /* 1400e0e31 */ let mut t_1400e0e31_0: u32 = 0x0_u32;
    /* 1400e0e31 */ r8 = (t_1400e0e31_0 as u64);
    /* 1400e0e34 */ let mut t_1400e0e34_0: u32 = 0x0_u32;
    /* 1400e0e34 */ rdx = (t_1400e0e34_0 as u64);
    /* 1400e0e36 */ let mut t_1400e0e36_0: u32 = 0x0_u32;
    /* 1400e0e36 */ rcx = (t_1400e0e36_0 as u64);
    /* 1400e0e38 */ fn_1402cd884();
    /* fallthrough -> bb370 */

    // ---- bb370 @ 0x1400e0e3e ----
    /* 1400e0e3e */ fn_140024090();
    /* fallthrough -> bb372 */

    // ---- bb372 @ 0x1400e0e44 ----
    /* 1400e0e44 */ fn_14002f0d0();
    /* fallthrough -> bb374 */

    // ---- bb374 @ 0x1400e0e4a ----
    /* 1400e0e4a */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, rsi);
    /* 1400e0e4f */ let mut t_1400e0e4f_0: u32 = 0x0_u32;
    /* 1400e0e4f */ r9 = (t_1400e0e4f_0 as u64);
    /* 1400e0e52 */ let mut t_1400e0e52_0: u32 = 0x0_u32;
    /* 1400e0e52 */ r8 = (t_1400e0e52_0 as u64);
    /* 1400e0e55 */ let mut t_1400e0e55_0: u32 = 0x0_u32;
    /* 1400e0e55 */ rdx = (t_1400e0e55_0 as u64);
    /* 1400e0e57 */ let mut t_1400e0e57_0: u32 = 0x0_u32;
    /* 1400e0e57 */ rcx = (t_1400e0e57_0 as u64);
    /* 1400e0e59 */ fn_1402cd884();
    /* 1400e0e70 */ let mut t_1400e0e70: u32 = core::ptr::read((rcx).wrapping_add(0x250_u64) as *const u32);
    /* 1400e0e77 */ rax = ((rax & 0xffffffffffffff00_u64) | (((ZF == true) as u8) as u64));
    /* 1400e0e7a */ return;
    // <no successors>
}
