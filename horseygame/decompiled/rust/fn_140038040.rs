// Decompiled from Horsey.exe @ 0x140038040
// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print
// blocks: 1091

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]
pub unsafe fn tired_looking_horse_dialog() {

    // ---- bb0 @ 0x140038040 ----
    /* 140038040 */ core::ptr::write((rsp).wrapping_add(0x10_u64) as *mut u64, rbx);
    /* 140038045 */ core::ptr::write((rsp).wrapping_add(0x18_u64) as *mut u64, rsi);
    /* 14003804a */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, rdi);
    /* 14003804f */ let mut rsp: u64 = (rsp).wrapping_sub(0x8_u64);
    /* 14003804f */ core::ptr::write(rsp as *mut u64, rbp);
    /* 140038050 */ let mut rbp: u64 = rsp;
    /* 140038053 */ let mut t_140038053_0: u64 = (rsp).wrapping_sub(0x80_u64);
    /* 140038053 */ rsp = t_140038053_0;
    /* 14003805a */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u128, xmm6);
    /* 14003805f */ let mut rdi: u64 = rcx;
    /* 140038062 */ let mut t_140038062: u32 = core::ptr::read((rcx).wrapping_add(0x254_u64) as *const u32);
    if (t_140038062 == 0x3_u32) {
        /* -> bb12 */
    } else {
        /* -> bb11 */
    }

    // ---- bb11 @ 0x140038069 ----
    if (t_140038062 == 0x3_u32) {
        /* -> bb12 */
    } else {
        /* -> bb67 */
    }

    // ---- bb12 @ 0x14003806f ----
    /* 14003806f */ let mut rcx: u64 = core::ptr::read((rcx).wrapping_add(0x130_u64) as *const u64);
    /* 140038076 */ let mut rdx: u64 = (((rdx as u32) as i64) as u64);
    /* 140038079 */ let mut rax: u64 = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 140038080 */ let mut t_140038080_0: u64 = (rax).wrapping_sub(rcx);
    /* 140038080 */ rax = t_140038080_0;
    /* 140038083 */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 140038087 */ rax = (rax).wrapping_sub(0x1_u64);
    if (rdx == rax) {
        /* -> bb22 */
    } else {
        /* -> bb21 */
    }

    // ---- bb21 @ 0x14003808d ----
    if (rdx == rax) {
        /* -> bb22 */
    } else {
        /* -> bb499 */
    }

    // ---- bb22 @ 0x140038093 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140038096 */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u128, xmm0);
    /* 14003809a */ let mut xmm1: u128 = core::ptr::read((0x1400380a2_u64).wrapping_add(0x2cb34e_u64) as *const u128);
    /* 1400380a2 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm1);
    /* 1400380a7 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb27 */ }
    if DF { /* -> bb28 */ }

    // ---- bb27 @ 0x1400380a7 ----
    /* 1400380a7 */ let mut rsi: u64 = (rsi).wrapping_add(0x8_u64);
    /* 1400380a7 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb29 */

    // ---- bb28 @ 0x1400380a7 ----
    /* 1400380a7 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400380a7 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb29 */

    // ---- bb29 @ 0x1400380af ----
    /* 1400380af */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb31 */ }
    if DF { /* -> bb32 */ }

    // ---- bb31 @ 0x1400380af ----
    /* 1400380af */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400380af */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb33 */

    // ---- bb32 @ 0x1400380af ----
    /* 1400380af */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400380af */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb33 */

    // ---- bb33 @ 0x1400380b4 ----
    /* 1400380b4 */ let mut t_1400380b4: u16 = core::ptr::read((0x1400380bb_u64).wrapping_add(0x2cc5c5_u64) as *const u16);
    /* 1400380b4 */ rax = ((t_1400380b4 as u32) as u64);
    /* 1400380bb */ core::ptr::write((rbp).wrapping_sub(0x48_u64) as *mut u16, (rax as u16));
    /* 1400380bf */ core::ptr::write((rbp).wrapping_sub(0x46_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2cb68d]
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 1400380d1 */ let mut t_1400380d1_0: u32 = 0x0_u32;
    /* 1400380d1 */ let mut r9: u64 = (t_1400380d1_0 as u64);
    /* 1400380d4 */ let mut r8: u64 = (rbp).wrapping_sub(0x50_u64);
    /* 1400380d8 */ rdx = core::ptr::read((rcx).wrapping_add((rdx).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400380dc */ rcx = rdi;
    /* 1400380df */ fn_1400d1090();
    /* 1400380e5 */ rdx = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb50 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb49 */ }

    // ---- bb49 @ 0x1400380ed ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb50 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb499 */ }

    // ---- bb50 @ 0x1400380f3 ----
    /* 1400380f3 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400380f6 */ rcx = core::ptr::read((rbp).wrapping_sub(0x50_u64) as *const u64);
    /* 1400380fa */ rax = rcx;
    if (CF == false) { /* -> bb57 */ }
    if CF { /* -> bb56 */ }

    // ---- bb56 @ 0x140038104 ----
    if (CF == false) { /* -> bb57 */ }
    if CF { /* -> bb65 */ }

    // ---- bb57 @ 0x140038106 ----
    /* 140038106 */ let mut t_140038106_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140038106 */ rdx = t_140038106_0;
    /* 14003810a */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 14003810e */ let mut t_14003810e_0: u64 = (rax).wrapping_sub(rcx);
    /* 14003810e */ rax = t_14003810e_0;
    /* 140038111 */ let mut t_140038111_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140038111 */ rax = t_140038111_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb65 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb64 */ }

    // ---- bb64 @ 0x140038119 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb65 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb549 */ }

    // ---- bb65 @ 0x14003811f ----
    /* 14003811f */ fn_1402c7498();
    /* fallthrough -> bb499 */

    // ---- bb67 @ 0x140038129 ----
    /* 140038129 */ let mut t_140038129: u32 = core::ptr::read((rcx).wrapping_add(0x25c_u64) as *const u32);
    if (t_140038129 == 0x0_u32) {
        /* -> bb71 */
    } else {
        /* -> bb70 */
    }

    // ---- bb70 @ 0x140038130 ----
    if (t_140038129 == 0x0_u32) {
        /* -> bb71 */
    } else {
        /* -> bb499 */
    }

    // ---- bb71 @ 0x140038136 ----
    /* 140038136 */ rsi = (((rdx as u32) as i64) as u64);
    /* 140038139 */ rax = core::ptr::read((rcx).wrapping_add(0x130_u64) as *const u64);
    /* 140038140 */ rcx = core::ptr::read((rax).wrapping_add((rsi).wrapping_mul(0x8_u64)) as *const u64);
    /* 140038144 */ let mut t_140038144: u64 = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    if (t_140038144 == rcx) {
        /* -> bb78 */
    } else {
        /* -> bb77 */
    }

    // ---- bb77 @ 0x14003814b ----
    if (t_140038144 == rcx) {
        /* -> bb78 */
    } else {
        /* -> bb442 */
    }

    // ---- bb78 @ 0x140038151 ----
    /* 140038151 */ let mut t_140038151: u32 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u32);
    /* 140038151 */ rax = (t_140038151 as u64);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 14003815d */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u128, xmm0);
    /* 140038161 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm1);
    if (t_140038144 == rcx) {
        /* -> bb87 */
    } else {
        /* -> bb86 */
    }

    // ---- bb86 @ 0x140038168 ----
    if (t_140038144 == rcx) {
        /* -> bb87 */
    } else {
        /* -> bb128 */
    }

    // ---- bb87 @ 0x14003816e ----
    /* 14003816e */ rcx = (0x20_u32 as u64);
    /* 140038173 */ fn_1400285e0();
    /* 140038178 */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u64, rax);
    /* 14003817c */ let mut xmm0: u128 = core::ptr::read((0x140038184_u64).wrapping_add(0x2cbf8c_u64) as *const u128);
    /* 140038184 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm0);
    /* 140038189 */ xmm0 = core::ptr::read((0x140038190_u64).wrapping_add(0x2cc4f8_u64) as *const u128);
    /* 140038190 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140038193 */ let mut t_140038193: u32 = core::ptr::read((0x140038199_u64).wrapping_add(0x2cc4ff_u64) as *const u32);
    /* 140038193 */ rcx = (t_140038193 as u64);
    /* 140038199 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u32, (rcx as u32));
    /* 14003819c */ let mut t_14003819c: u8 = core::ptr::read((0x1400381a3_u64).wrapping_add(0x2cc4f9_u64) as *const u8);
    /* 14003819c */ rcx = ((t_14003819c as u32) as u64);
    /* 1400381a3 */ core::ptr::write((rax).wrapping_add(0x14_u64) as *mut u8, (rcx as u8));
    /* 1400381a6 */ core::ptr::write((rax).wrapping_add(0x15_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2cb5a6]
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 1400381b8 */ let mut t_1400381b8_0: u32 = 0x0_u32;
    /* 1400381b8 */ r9 = (t_1400381b8_0 as u64);
    /* 1400381bb */ r8 = (rbp).wrapping_sub(0x50_u64);
    /* 1400381bf */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 1400381c6 */ rcx = rdi;
    /* 1400381c9 */ fn_1400d1090();
    /* 1400381cf */ rdx = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb112 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb111 */ }

    // ---- bb111 @ 0x1400381d7 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb112 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb440 */ }

    // ---- bb112 @ 0x1400381dd ----
    /* 1400381dd */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400381e0 */ rcx = core::ptr::read((rbp).wrapping_sub(0x50_u64) as *const u64);
    /* 1400381e4 */ rax = rcx;
    if (CF == false) { /* -> bb119 */ }
    if CF { /* -> bb118 */ }

    // ---- bb118 @ 0x1400381ee ----
    if (CF == false) { /* -> bb119 */ }
    if CF { /* -> bb439 */ }

    // ---- bb119 @ 0x1400381f4 ----
    /* 1400381f4 */ let mut t_1400381f4_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400381f4 */ rdx = t_1400381f4_0;
    /* 1400381f8 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400381fc */ let mut t_1400381fc_0: u64 = (rax).wrapping_sub(rcx);
    /* 1400381fc */ rax = t_1400381fc_0;
    /* 1400381ff */ let mut t_1400381ff_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 1400381ff */ rax = t_1400381ff_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb127 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb126 */ }

    // ---- bb126 @ 0x140038207 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb127 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb514 */ }

    // ---- bb127 @ 0x14003820d ----
    /* fallthrough -> bb439 */

    // ---- bb128 @ 0x140038212 ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb132 */
    } else {
        /* -> bb131 */
    }

    // ---- bb131 @ 0x140038215 ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb132 */
    } else {
        /* -> bb182 */
    }

    // ---- bb132 @ 0x14003821b ----
    /* 14003821b */ rcx = (0x30_u32 as u64);
    /* 140038220 */ fn_1400285e0();
    /* 140038225 */ rcx = rax;
    /* 140038228 */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u64, rax);
    /* 14003822c */ xmm0 = core::ptr::read((0x140038234_u64).wrapping_add(0x2cb54c_u64) as *const u128);
    /* 140038234 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm0);
    /* 140038239 */ xmm0 = core::ptr::read((0x140038240_u64).wrapping_add(0x2cc460_u64) as *const u128);
    /* 140038240 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140038243 */ xmm1 = core::ptr::read((0x14003824a_u64).wrapping_add(0x2cc466_u64) as *const u128);
    /* 14003824a */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 14003824e */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb143 */ }
    if DF { /* -> bb144 */ }

    // ---- bb143 @ 0x14003824e ----
    /* 14003824e */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003824e */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb145 */

    // ---- bb144 @ 0x14003824e ----
    /* 14003824e */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003824e */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb145 */

    // ---- bb145 @ 0x140038256 ----
    /* 140038256 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb147 */ }
    if DF { /* -> bb148 */ }

    // ---- bb147 @ 0x140038256 ----
    /* 140038256 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140038256 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb149 */

    // ---- bb148 @ 0x140038256 ----
    /* 140038256 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140038256 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb149 */

    // ---- bb149 @ 0x14003825b ----
    /* 14003825b */ let mut t_14003825b: u16 = core::ptr::read((0x140038262_u64).wrapping_add(0x2cc466_u64) as *const u16);
    /* 14003825b */ rax = ((t_14003825b as u32) as u64);
    /* 140038262 */ core::ptr::write((rcx).wrapping_add(0x28_u64) as *mut u16, (rax as u16));
    /* 140038266 */ core::ptr::write((rcx).wrapping_add(0x2a_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2cb4e6]
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 140038278 */ let mut t_140038278_0: u32 = 0x0_u32;
    /* 140038278 */ r9 = (t_140038278_0 as u64);
    /* 14003827b */ r8 = (rbp).wrapping_sub(0x50_u64);
    /* 14003827f */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140038286 */ rcx = rdi;
    /* 140038289 */ fn_1400d1090();
    /* 14003828f */ rdx = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb166 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb165 */ }

    // ---- bb165 @ 0x140038297 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb166 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb440 */ }

    // ---- bb166 @ 0x14003829d ----
    /* 14003829d */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400382a0 */ rcx = core::ptr::read((rbp).wrapping_sub(0x50_u64) as *const u64);
    /* 1400382a4 */ rax = rcx;
    if (CF == false) { /* -> bb173 */ }
    if CF { /* -> bb172 */ }

    // ---- bb172 @ 0x1400382ae ----
    if (CF == false) { /* -> bb173 */ }
    if CF { /* -> bb439 */ }

    // ---- bb173 @ 0x1400382b4 ----
    /* 1400382b4 */ let mut t_1400382b4_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400382b4 */ rdx = t_1400382b4_0;
    /* 1400382b8 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400382bc */ let mut t_1400382bc_0: u64 = (rax).wrapping_sub(rcx);
    /* 1400382bc */ rax = t_1400382bc_0;
    /* 1400382bf */ let mut t_1400382bf_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 1400382bf */ rax = t_1400382bf_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb181 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb180 */ }

    // ---- bb180 @ 0x1400382c7 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb181 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb521 */ }

    // ---- bb181 @ 0x1400382cd ----
    /* fallthrough -> bb439 */

    // ---- bb182 @ 0x1400382d2 ----
    if ((rax as u32) == 0x2_u32) {
        /* -> bb186 */
    } else {
        /* -> bb185 */
    }

    // ---- bb185 @ 0x1400382d5 ----
    if ((rax as u32) == 0x2_u32) {
        /* -> bb186 */
    } else {
        /* -> bb238 */
    }

    // ---- bb186 @ 0x1400382db ----
    /* 1400382db */ rcx = (0x20_u32 as u64);
    /* 1400382e0 */ fn_1400285e0();
    /* 1400382e5 */ rdx = rax;
    /* 1400382e8 */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u64, rax);
    /* 1400382ec */ xmm0 = core::ptr::read((0x1400382f4_u64).wrapping_add(0x2cbe4c_u64) as *const u128);
    /* 1400382f4 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm0);
    /* 1400382f9 */ xmm0 = core::ptr::read((0x140038300_u64).wrapping_add(0x2cc3d0_u64) as *const u128);
    /* 140038300 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140038303 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb195 */ }
    if DF { /* -> bb196 */ }

    // ---- bb195 @ 0x140038303 ----
    /* 140038303 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140038303 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb197 */

    // ---- bb196 @ 0x140038303 ----
    /* 140038303 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140038303 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb197 */

    // ---- bb197 @ 0x14003830b ----
    /* 14003830b */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb199 */ }
    if DF { /* -> bb200 */ }

    // ---- bb199 @ 0x14003830b ----
    /* 14003830b */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003830b */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb201 */

    // ---- bb200 @ 0x14003830b ----
    /* 14003830b */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003830b */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb201 */

    // ---- bb201 @ 0x140038310 ----
    /* 140038310 */ let mut t_140038310: u32 = core::ptr::read((0x140038316_u64).wrapping_add(0x2cc3d2_u64) as *const u32);
    /* 140038310 */ rcx = (t_140038310 as u64);
    /* 140038316 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u32, (rcx as u32));
    /* 140038319 */ let mut t_140038319: u16 = core::ptr::read((0x140038320_u64).wrapping_add(0x2cc3cc_u64) as *const u16);
    /* 140038319 */ rax = ((t_140038319 as u32) as u64);
    /* 140038320 */ core::ptr::write((rdx).wrapping_add(0x1c_u64) as *mut u16, (rax as u16));
    /* 140038324 */ let mut t_140038324: u8 = core::ptr::read((0x14003832b_u64).wrapping_add(0x2cc3c3_u64) as *const u8);
    /* 140038324 */ rax = ((t_140038324 as u32) as u64);
    /* 14003832b */ core::ptr::write((rdx).wrapping_add(0x1e_u64) as *mut u8, (rax as u8));
    /* 14003832e */ core::ptr::write((rdx).wrapping_add(0x1f_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2cb41e]
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 140038340 */ let mut t_140038340_0: u32 = 0x0_u32;
    /* 140038340 */ r9 = (t_140038340_0 as u64);
    /* 140038343 */ r8 = (rbp).wrapping_sub(0x50_u64);
    /* 140038347 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 14003834e */ rcx = rdi;
    /* 140038351 */ fn_1400d1090();
    /* 140038357 */ rdx = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb222 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb221 */ }

    // ---- bb221 @ 0x14003835f ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb222 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb440 */ }

    // ---- bb222 @ 0x140038365 ----
    /* 140038365 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140038368 */ rcx = core::ptr::read((rbp).wrapping_sub(0x50_u64) as *const u64);
    /* 14003836c */ rax = rcx;
    if (CF == false) { /* -> bb229 */ }
    if CF { /* -> bb228 */ }

    // ---- bb228 @ 0x140038376 ----
    if (CF == false) { /* -> bb229 */ }
    if CF { /* -> bb439 */ }

    // ---- bb229 @ 0x14003837c ----
    /* 14003837c */ let mut t_14003837c_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 14003837c */ rdx = t_14003837c_0;
    /* 140038380 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140038384 */ let mut t_140038384_0: u64 = (rax).wrapping_sub(rcx);
    /* 140038384 */ rax = t_140038384_0;
    /* 140038387 */ let mut t_140038387_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140038387 */ rax = t_140038387_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb237 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb236 */ }

    // ---- bb236 @ 0x14003838f ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb237 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb528 */ }

    // ---- bb237 @ 0x140038395 ----
    /* fallthrough -> bb439 */

    // ---- bb238 @ 0x14003839a ----
    if ((rax as u32) == 0x3_u32) {
        /* -> bb242 */
    } else {
        /* -> bb241 */
    }

    // ---- bb241 @ 0x14003839d ----
    if ((rax as u32) == 0x3_u32) {
        /* -> bb242 */
    } else {
        /* -> bb292 */
    }

    // ---- bb242 @ 0x1400383a3 ----
    /* 1400383a3 */ rcx = (0x20_u32 as u64);
    /* 1400383a8 */ fn_1400285e0();
    /* 1400383ad */ rdx = rax;
    /* 1400383b0 */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u64, rax);
    /* 1400383b4 */ xmm0 = core::ptr::read((0x1400383bc_u64).wrapping_add(0x2cc944_u64) as *const u128);
    /* 1400383bc */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm0);
    /* 1400383c1 */ xmm0 = core::ptr::read((0x1400383c8_u64).wrapping_add(0x2cc328_u64) as *const u128);
    /* 1400383c8 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400383cb */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb251 */ }
    if DF { /* -> bb252 */ }

    // ---- bb251 @ 0x1400383cb ----
    /* 1400383cb */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400383cb */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb253 */

    // ---- bb252 @ 0x1400383cb ----
    /* 1400383cb */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400383cb */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb253 */

    // ---- bb253 @ 0x1400383d3 ----
    /* 1400383d3 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb255 */ }
    if DF { /* -> bb256 */ }

    // ---- bb255 @ 0x1400383d3 ----
    /* 1400383d3 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400383d3 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb257 */

    // ---- bb256 @ 0x1400383d3 ----
    /* 1400383d3 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400383d3 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb257 */

    // ---- bb257 @ 0x1400383d8 ----
    /* 1400383d8 */ let mut t_1400383d8: u32 = core::ptr::read((0x1400383de_u64).wrapping_add(0x2cc32a_u64) as *const u32);
    /* 1400383d8 */ rcx = (t_1400383d8 as u64);
    /* 1400383de */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u32, (rcx as u32));
    /* 1400383e1 */ let mut t_1400383e1: u8 = core::ptr::read((0x1400383e8_u64).wrapping_add(0x2cc324_u64) as *const u8);
    /* 1400383e1 */ rax = ((t_1400383e1 as u32) as u64);
    /* 1400383e8 */ core::ptr::write((rdx).wrapping_add(0x1c_u64) as *mut u8, (rax as u8));
    /* 1400383eb */ core::ptr::write((rdx).wrapping_add(0x1d_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2cb361]
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 1400383fd */ let mut t_1400383fd_0: u32 = 0x0_u32;
    /* 1400383fd */ r9 = (t_1400383fd_0 as u64);
    /* 140038400 */ r8 = (rbp).wrapping_sub(0x50_u64);
    /* 140038404 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 14003840b */ rcx = rdi;
    /* 14003840e */ fn_1400d1090();
    /* 140038414 */ rdx = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb276 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb275 */ }

    // ---- bb275 @ 0x14003841c ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb276 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb440 */ }

    // ---- bb276 @ 0x140038422 ----
    /* 140038422 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140038425 */ rcx = core::ptr::read((rbp).wrapping_sub(0x50_u64) as *const u64);
    /* 140038429 */ rax = rcx;
    if (CF == false) { /* -> bb283 */ }
    if CF { /* -> bb282 */ }

    // ---- bb282 @ 0x140038433 ----
    if (CF == false) { /* -> bb283 */ }
    if CF { /* -> bb439 */ }

    // ---- bb283 @ 0x140038439 ----
    /* 140038439 */ let mut t_140038439_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140038439 */ rdx = t_140038439_0;
    /* 14003843d */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140038441 */ let mut t_140038441_0: u64 = (rax).wrapping_sub(rcx);
    /* 140038441 */ rax = t_140038441_0;
    /* 140038444 */ let mut t_140038444_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140038444 */ rax = t_140038444_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb291 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb290 */ }

    // ---- bb290 @ 0x14003844c ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb291 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb535 */ }

    // ---- bb291 @ 0x140038452 ----
    /* fallthrough -> bb439 */

    // ---- bb292 @ 0x140038457 ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb296 */
    } else {
        /* -> bb295 */
    }

    // ---- bb295 @ 0x14003845a ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb296 */
    } else {
        /* -> bb393 */
    }

    // ---- bb296 @ 0x140038460 ----
    /* 140038460 */ rcx = (0x30_u32 as u64);
    /* 140038465 */ fn_1400285e0();
    /* 14003846a */ rcx = rax;
    /* 14003846d */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u64, rax);
    /* 140038471 */ xmm0 = core::ptr::read((0x140038479_u64).wrapping_add(0x2cb307_u64) as *const u128);
    /* 140038479 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm0);
    /* 14003847e */ xmm0 = core::ptr::read((0x140038485_u64).wrapping_add(0x2cc28b_u64) as *const u128);
    /* 140038485 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140038488 */ xmm1 = core::ptr::read((0x14003848f_u64).wrapping_add(0x2cc291_u64) as *const u128);
    /* 14003848f */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 140038493 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb307 */ }
    if DF { /* -> bb308 */ }

    // ---- bb307 @ 0x140038493 ----
    /* 140038493 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140038493 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb309 */

    // ---- bb308 @ 0x140038493 ----
    /* 140038493 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140038493 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb309 */

    // ---- bb309 @ 0x14003849b ----
    /* 14003849b */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb311 */ }
    if DF { /* -> bb312 */ }

    // ---- bb311 @ 0x14003849b ----
    /* 14003849b */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003849b */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb313 */

    // ---- bb312 @ 0x14003849b ----
    /* 14003849b */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003849b */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb313 */

    // ---- bb313 @ 0x1400384a0 ----
    /* 1400384a0 */ let mut t_1400384a0: u16 = core::ptr::read((0x1400384a7_u64).wrapping_add(0x2cc291_u64) as *const u16);
    /* 1400384a0 */ rax = ((t_1400384a0 as u32) as u64);
    /* 1400384a7 */ core::ptr::write((rcx).wrapping_add(0x28_u64) as *mut u16, (rax as u16));
    /* 1400384ab */ core::ptr::write((rcx).wrapping_add(0x2a_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2cb2a1]
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 1400384bd */ let mut t_1400384bd_0: u32 = 0x0_u32;
    /* 1400384bd */ r9 = (t_1400384bd_0 as u64);
    /* 1400384c0 */ r8 = (rbp).wrapping_sub(0x50_u64);
    /* 1400384c4 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 1400384cb */ rcx = rdi;
    /* 1400384ce */ fn_1400d1090();
    /* 1400384d4 */ rdx = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb330 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb329 */ }

    // ---- bb329 @ 0x1400384dc ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb330 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb346 */ }

    // ---- bb330 @ 0x1400384de ----
    /* 1400384de */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400384e1 */ rcx = core::ptr::read((rbp).wrapping_sub(0x50_u64) as *const u64);
    /* 1400384e5 */ rax = rcx;
    if (CF == false) { /* -> bb337 */ }
    if CF { /* -> bb336 */ }

    // ---- bb336 @ 0x1400384ef ----
    if (CF == false) { /* -> bb337 */ }
    if CF { /* -> bb345 */ }

    // ---- bb337 @ 0x1400384f1 ----
    /* 1400384f1 */ let mut t_1400384f1_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400384f1 */ rdx = t_1400384f1_0;
    /* 1400384f5 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400384f9 */ let mut t_1400384f9_0: u64 = (rax).wrapping_sub(rcx);
    /* 1400384f9 */ rax = t_1400384f9_0;
    /* 1400384fc */ let mut t_1400384fc_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 1400384fc */ rax = t_1400384fc_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb345 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb344 */ }

    // ---- bb344 @ 0x140038504 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb345 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb556 */ }

    // ---- bb345 @ 0x14003850a ----
    /* 14003850a */ fn_1402c7498();
    /* fallthrough -> bb346 */

    // ---- bb346 @ 0x14003850f ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140038512 */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140038519 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm1);
    /* 14003851e */ rcx = (0x20_u32 as u64);
    /* 140038523 */ fn_1400285e0();
    /* 140038528 */ rdx = rax;
    /* 14003852b */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u64, rax);
    /* 14003852f */ xmm0 = core::ptr::read((0x140038537_u64).wrapping_add(0x2cc799_u64) as *const u128);
    /* 140038537 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm0);
    /* 14003853c */ xmm0 = core::ptr::read((0x140038543_u64).wrapping_add(0x2cc1fd_u64) as *const u128);
    /* 140038543 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140038546 */ let mut t_140038546: u32 = core::ptr::read((0x14003854c_u64).wrapping_add(0x2cc204_u64) as *const u32);
    /* 140038546 */ rcx = (t_140038546 as u64);
    /* 14003854c */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u32, (rcx as u32));
    /* 14003854f */ let mut t_14003854f: u16 = core::ptr::read((0x140038556_u64).wrapping_add(0x2cc1fe_u64) as *const u16);
    /* 14003854f */ rcx = ((t_14003854f as u32) as u64);
    /* 140038556 */ core::ptr::write((rax).wrapping_add(0x14_u64) as *mut u16, (rcx as u16));
    /* 14003855a */ let mut t_14003855a: u8 = core::ptr::read((0x140038561_u64).wrapping_add(0x2cc1f5_u64) as *const u8);
    /* 14003855a */ rax = ((t_14003855a as u32) as u64);
    /* 140038561 */ core::ptr::write((rdx).wrapping_add(0x16_u64) as *mut u8, (rax as u8));
    /* 140038564 */ core::ptr::write((rdx).wrapping_add(0x17_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 14003856e */ let mut t_14003856e_0: u32 = 0x0_u32;
    /* 14003856e */ r9 = (t_14003856e_0 as u64);
    /* 140038571 */ r8 = (rbp).wrapping_sub(0x50_u64);
    /* 140038575 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 14003857c */ rcx = rdi;
    /* 14003857f */ fn_1400d1090();
    /* 140038585 */ rdx = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb377 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb376 */ }

    // ---- bb376 @ 0x14003858d ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb377 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb440 */ }

    // ---- bb377 @ 0x140038593 ----
    /* 140038593 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140038596 */ rcx = core::ptr::read((rbp).wrapping_sub(0x50_u64) as *const u64);
    /* 14003859a */ rax = rcx;
    if (CF == false) { /* -> bb384 */ }
    if CF { /* -> bb383 */ }

    // ---- bb383 @ 0x1400385a4 ----
    if (CF == false) { /* -> bb384 */ }
    if CF { /* -> bb439 */ }

    // ---- bb384 @ 0x1400385aa ----
    /* 1400385aa */ let mut t_1400385aa_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400385aa */ rdx = t_1400385aa_0;
    /* 1400385ae */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400385b2 */ let mut t_1400385b2_0: u64 = (rax).wrapping_sub(rcx);
    /* 1400385b2 */ rax = t_1400385b2_0;
    /* 1400385b5 */ let mut t_1400385b5_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 1400385b5 */ rax = t_1400385b5_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb392 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb391 */ }

    // ---- bb391 @ 0x1400385bd ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb392 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb542 */ }

    // ---- bb392 @ 0x1400385c3 ----
    /* fallthrough -> bb439 */

    // ---- bb393 @ 0x1400385c8 ----
    /* 1400385c8 */ rcx = (0x20_u32 as u64);
    /* 1400385cd */ fn_1400285e0();
    /* 1400385d2 */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u64, rax);
    /* 1400385d6 */ xmm0 = core::ptr::read((0x1400385de_u64).wrapping_add(0x2cc702_u64) as *const u128);
    /* 1400385de */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm0);
    /* 1400385e3 */ xmm0 = core::ptr::read((0x1400385ea_u64).wrapping_add(0x2cc16e_u64) as *const u128);
    /* 1400385ea */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400385ed */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb401 */ }
    if DF { /* -> bb402 */ }

    // ---- bb401 @ 0x1400385ed ----
    /* 1400385ed */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400385ed */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb403 */

    // ---- bb402 @ 0x1400385ed ----
    /* 1400385ed */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400385ed */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb403 */

    // ---- bb403 @ 0x1400385f5 ----
    /* 1400385f5 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb405 */ }
    if DF { /* -> bb406 */ }

    // ---- bb405 @ 0x1400385f5 ----
    /* 1400385f5 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400385f5 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb407 */

    // ---- bb406 @ 0x1400385f5 ----
    /* 1400385f5 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400385f5 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb407 */

    // ---- bb407 @ 0x1400385fa ----
    /* 1400385fa */ let mut t_1400385fa: u16 = core::ptr::read((0x140038601_u64).wrapping_add(0x2cc16f_u64) as *const u16);
    /* 1400385fa */ rcx = ((t_1400385fa as u32) as u64);
    /* 140038601 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u16, (rcx as u16));
    /* 140038605 */ core::ptr::write((rax).wrapping_add(0x1a_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2cb147]
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 140038617 */ let mut t_140038617_0: u32 = 0x0_u32;
    /* 140038617 */ r9 = (t_140038617_0 as u64);
    /* 14003861a */ r8 = (rbp).wrapping_sub(0x50_u64);
    /* 14003861e */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140038625 */ rcx = rdi;
    /* 140038628 */ fn_1400d1090();
    /* 14003862e */ rdx = core::ptr::read((rbp).wrapping_sub(0x38_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb424 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb423 */ }

    // ---- bb423 @ 0x140038636 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb424 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb440 */ }

    // ---- bb424 @ 0x140038638 ----
    /* 140038638 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 14003863b */ rcx = core::ptr::read((rbp).wrapping_sub(0x50_u64) as *const u64);
    /* 14003863f */ rax = rcx;
    if (CF == false) { /* -> bb431 */ }
    if CF { /* -> bb430 */ }

    // ---- bb430 @ 0x140038649 ----
    if (CF == false) { /* -> bb431 */ }
    if CF { /* -> bb439 */ }

    // ---- bb431 @ 0x14003864b ----
    /* 14003864b */ let mut t_14003864b_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 14003864b */ rdx = t_14003864b_0;
    /* 14003864f */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140038653 */ let mut t_140038653_0: u64 = (rax).wrapping_sub(rcx);
    /* 140038653 */ rax = t_140038653_0;
    /* 140038656 */ let mut t_140038656_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140038656 */ rax = t_140038656_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb439 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb438 */ }

    // ---- bb438 @ 0x14003865e ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb439 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb507 */ }

    // ---- bb439 @ 0x140038664 ----
    /* 140038664 */ fn_1402c7498();
    /* fallthrough -> bb440 */

    // ---- bb440 @ 0x140038669 ----
    /* 140038669 */ core::ptr::write((rdi).wrapping_add(0x258_u64) as *mut u32, 0xffffffff_u32);
    /* fallthrough -> bb499 */

    // ---- bb442 @ 0x140038678 ----
    /* 140038678 */ let mut t_140038678: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (((SF != OF) | (t_140038678 == 0x78_u32)) == false) { /* -> bb446 */ }
    if (((SF != OF) | (t_140038678 == 0x78_u32)) != 0) { /* -> bb445 */ }

    // ---- bb445 @ 0x14003867f ----
    if (((SF != OF) | (t_140038678 == 0x78_u32)) == false) { /* -> bb446 */ }
    if (((SF != OF) | (t_140038678 == 0x78_u32)) != 0) { /* -> bb499 */ }

    // ---- bb446 @ 0x140038685 ----
    /* 140038685 */ let mut rbx: u64 = core::ptr::read((rdi).wrapping_add(0x78_u64) as *const u64);
    /* 140038689 */ rdx = (rbp).wrapping_add(0x10_u64);
    /* 14003868d */ fn_1400b4a00();
    /* 140038692 */ rcx = rax;
    // intrinsic: 0f57d200 xorps xmm2, xmm2
    /* 140038698 */ rdx = rbx;
    /* 14003869b */ fn_1400c5b50();
    if (t_140038678 != 0x78_u32) {
        /* -> bb457 */
    } else {
        /* -> bb456 */
    }

    // ---- bb456 @ 0x1400386a2 ----
    if (t_140038678 != 0x78_u32) {
        /* -> bb457 */
    } else {
        /* -> bb499 */
    }

    // ---- bb457 @ 0x1400386a8 ----
    /* 1400386a8 */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400386af */ rcx = core::ptr::read((rax).wrapping_add((rsi).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400386b3 */ let mut t_1400386b3: u8 = core::ptr::read((rcx).wrapping_add(0x206_u64) as *const u8);
    if (t_1400386b3 != 0x0_u8) {
        /* -> bb463 */
    } else {
        /* -> bb462 */
    }

    // ---- bb462 @ 0x1400386ba ----
    if (t_1400386b3 != 0x0_u8) {
        /* -> bb463 */
    } else {
        /* -> bb468 */
    }

    // ---- bb463 @ 0x1400386bc ----
    /* 1400386bc */ r8 = (0x1400386c3_u64).wrapping_add(0x2cc0b5_u64);
    /* 1400386c3 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 1400386ca */ rcx = rdi;
    /* 1400386cd */ fn_1400d2050();
    /* fallthrough -> bb499 */

    // ---- bb468 @ 0x1400386d7 ----
    /* 1400386d7 */ let mut t_1400386d7: u8 = core::ptr::read((rcx).wrapping_add(0x205_u64) as *const u8);
    if (t_1400386d7 != 0x0_u8) {
        /* -> bb472 */
    } else {
        /* -> bb471 */
    }

    // ---- bb471 @ 0x1400386de ----
    if (t_1400386d7 != 0x0_u8) {
        /* -> bb472 */
    } else {
        /* -> bb477 */
    }

    // ---- bb472 @ 0x1400386e0 ----
    /* 1400386e0 */ r8 = (0x1400386e7_u64).wrapping_add(0x2cc0b1_u64);
    /* 1400386e7 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 1400386ee */ rcx = rdi;
    /* 1400386f1 */ fn_1400d2050();
    /* fallthrough -> bb499 */

    // ---- bb477 @ 0x1400386f8 ----
    /* 1400386f8 */ rax = (0x1400386ff_u64).wrapping_add(0x2cbd6d_u64);
    /* 1400386ff */ core::ptr::write((rbp).wrapping_sub(0x50_u64) as *mut u64, rax);
    /* 140038703 */ rax = (0x14003870a_u64).wrapping_add(0x2cc0ae_u64);
    /* 14003870a */ core::ptr::write((rbp).wrapping_sub(0x48_u64) as *mut u64, rax);
    /* 14003870e */ rax = (0x140038715_u64).wrapping_add(0x2cc0ab_u64);
    /* 140038715 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u64, rax);
    /* 140038719 */ rax = (0x140038720_u64).wrapping_add(0x2cc0a8_u64);
    /* 140038720 */ core::ptr::write((rbp).wrapping_sub(0x38_u64) as *mut u64, rax);
    /* 140038724 */ rax = (0x14003872b_u64).wrapping_add(0x2cc0a5_u64);
    /* 14003872b */ core::ptr::write((rbp).wrapping_sub(0x30_u64) as *mut u64, rax);
    /* 14003872f */ rax = (0x140038736_u64).wrapping_add(0x2cc0a2_u64);
    /* 140038736 */ core::ptr::write((rbp).wrapping_sub(0x28_u64) as *mut u64, rax);
    /* 14003873a */ rax = (0x140038741_u64).wrapping_add(0x2cc0a7_u64);
    /* 140038741 */ core::ptr::write((rbp).wrapping_sub(0x20_u64) as *mut u64, rax);
    /* 140038745 */ rcx = (0x7_u32 as u64);
    /* 14003874a */ fn_1400c6990();
    /* 14003874f */ rcx = (((rax as u32) as i64) as u64);
    /* 140038752 */ r9 = core::ptr::read(((rbp).wrapping_add((rcx).wrapping_mul(0x8_u64))).wrapping_sub(0x50_u64) as *const u64);
    /* 140038757 */ r8 = (0x14003875e_u64).wrapping_add(0x2cc09a_u64);
    /* 14003875e */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140038765 */ rcx = rdi;
    /* 140038768 */ fn_1400d2050();
    /* fallthrough -> bb499 */

    // ---- bb499 @ 0x14003876d ----
    /* 14003876d */ let mut r11: u64 = (rsp).wrapping_add(0x80_u64);
    /* 140038775 */ rbx = core::ptr::read((r11).wrapping_add(0x18_u64) as *const u64);
    /* 140038779 */ rsi = core::ptr::read((r11).wrapping_add(0x20_u64) as *const u64);
    /* 14003877d */ rdi = core::ptr::read((r11).wrapping_add(0x28_u64) as *const u64);
    /* 140038781 */ let mut xmm6: u128 = core::ptr::read((rsp).wrapping_add(0x70_u64) as *const u128);
    /* 140038786 */ rsp = r11;
    /* 140038789 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140038789 */ rbp = core::ptr::read(rsp as *const u64);
    /* 14003878a */ return;
    // <no successors>

    // ---- bb507 @ 0x14003878b ----
    /* 14003878b */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 140038794 */ let mut t_140038794_0: u32 = 0x0_u32;
    /* 140038794 */ r9 = (t_140038794_0 as u64);
    /* 140038797 */ let mut t_140038797_0: u32 = 0x0_u32;
    /* 140038797 */ r8 = (t_140038797_0 as u64);
    /* 14003879a */ let mut t_14003879a_0: u32 = 0x0_u32;
    /* 14003879a */ rdx = (t_14003879a_0 as u64);
    /* 14003879c */ let mut t_14003879c_0: u32 = 0x0_u32;
    /* 14003879c */ rcx = (t_14003879c_0 as u64);
    /* 14003879e */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb514 */

    // ---- bb514 @ 0x1400387a4 ----
    /* 1400387a4 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 1400387ad */ let mut t_1400387ad_0: u32 = 0x0_u32;
    /* 1400387ad */ r9 = (t_1400387ad_0 as u64);
    /* 1400387b0 */ let mut t_1400387b0_0: u32 = 0x0_u32;
    /* 1400387b0 */ r8 = (t_1400387b0_0 as u64);
    /* 1400387b3 */ let mut t_1400387b3_0: u32 = 0x0_u32;
    /* 1400387b3 */ rdx = (t_1400387b3_0 as u64);
    /* 1400387b5 */ let mut t_1400387b5_0: u32 = 0x0_u32;
    /* 1400387b5 */ rcx = (t_1400387b5_0 as u64);
    /* 1400387b7 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb521 */

    // ---- bb521 @ 0x1400387bd ----
    /* 1400387bd */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 1400387c6 */ let mut t_1400387c6_0: u32 = 0x0_u32;
    /* 1400387c6 */ r9 = (t_1400387c6_0 as u64);
    /* 1400387c9 */ let mut t_1400387c9_0: u32 = 0x0_u32;
    /* 1400387c9 */ r8 = (t_1400387c9_0 as u64);
    /* 1400387cc */ let mut t_1400387cc_0: u32 = 0x0_u32;
    /* 1400387cc */ rdx = (t_1400387cc_0 as u64);
    /* 1400387ce */ let mut t_1400387ce_0: u32 = 0x0_u32;
    /* 1400387ce */ rcx = (t_1400387ce_0 as u64);
    /* 1400387d0 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb528 */

    // ---- bb528 @ 0x1400387d6 ----
    /* 1400387d6 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 1400387df */ let mut t_1400387df_0: u32 = 0x0_u32;
    /* 1400387df */ r9 = (t_1400387df_0 as u64);
    /* 1400387e2 */ let mut t_1400387e2_0: u32 = 0x0_u32;
    /* 1400387e2 */ r8 = (t_1400387e2_0 as u64);
    /* 1400387e5 */ let mut t_1400387e5_0: u32 = 0x0_u32;
    /* 1400387e5 */ rdx = (t_1400387e5_0 as u64);
    /* 1400387e7 */ let mut t_1400387e7_0: u32 = 0x0_u32;
    /* 1400387e7 */ rcx = (t_1400387e7_0 as u64);
    /* 1400387e9 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb535 */

    // ---- bb535 @ 0x1400387ef ----
    /* 1400387ef */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 1400387f8 */ let mut t_1400387f8_0: u32 = 0x0_u32;
    /* 1400387f8 */ r9 = (t_1400387f8_0 as u64);
    /* 1400387fb */ let mut t_1400387fb_0: u32 = 0x0_u32;
    /* 1400387fb */ r8 = (t_1400387fb_0 as u64);
    /* 1400387fe */ let mut t_1400387fe_0: u32 = 0x0_u32;
    /* 1400387fe */ rdx = (t_1400387fe_0 as u64);
    /* 140038800 */ let mut t_140038800_0: u32 = 0x0_u32;
    /* 140038800 */ rcx = (t_140038800_0 as u64);
    /* 140038802 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb542 */

    // ---- bb542 @ 0x140038808 ----
    /* 140038808 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 140038811 */ let mut t_140038811_0: u32 = 0x0_u32;
    /* 140038811 */ r9 = (t_140038811_0 as u64);
    /* 140038814 */ let mut t_140038814_0: u32 = 0x0_u32;
    /* 140038814 */ r8 = (t_140038814_0 as u64);
    /* 140038817 */ let mut t_140038817_0: u32 = 0x0_u32;
    /* 140038817 */ rdx = (t_140038817_0 as u64);
    /* 140038819 */ let mut t_140038819_0: u32 = 0x0_u32;
    /* 140038819 */ rcx = (t_140038819_0 as u64);
    /* 14003881b */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb549 */

    // ---- bb549 @ 0x140038821 ----
    /* 140038821 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 14003882a */ let mut t_14003882a_0: u32 = 0x0_u32;
    /* 14003882a */ r9 = (t_14003882a_0 as u64);
    /* 14003882d */ let mut t_14003882d_0: u32 = 0x0_u32;
    /* 14003882d */ r8 = (t_14003882d_0 as u64);
    /* 140038830 */ let mut t_140038830_0: u32 = 0x0_u32;
    /* 140038830 */ rdx = (t_140038830_0 as u64);
    /* 140038832 */ let mut t_140038832_0: u32 = 0x0_u32;
    /* 140038832 */ rcx = (t_140038832_0 as u64);
    /* 140038834 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb556 */

    // ---- bb556 @ 0x14003883a ----
    /* 14003883a */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 140038843 */ let mut t_140038843_0: u32 = 0x0_u32;
    /* 140038843 */ r9 = (t_140038843_0 as u64);
    /* 140038846 */ let mut t_140038846_0: u32 = 0x0_u32;
    /* 140038846 */ r8 = (t_140038846_0 as u64);
    /* 140038849 */ let mut t_140038849_0: u32 = 0x0_u32;
    /* 140038849 */ rdx = (t_140038849_0 as u64);
    /* 14003884b */ let mut t_14003884b_0: u32 = 0x0_u32;
    /* 14003884b */ rcx = (t_14003884b_0 as u64);
    /* 14003884d */ fn_1402cd884();
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
    /* 140038860 */ rax = rsp;
    /* 140038863 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u64, rbx);
    /* 140038867 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u64, rsi);
    /* 14003886b */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u64, rdi);
    /* 14003886f */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003886f */ core::ptr::write(rsp as *mut u64, rbp);
    /* 140038870 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140038870 */ core::ptr::write(rsp as *mut u64, r12);
    /* 140038872 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140038872 */ core::ptr::write(rsp as *mut u64, r13);
    /* 140038874 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140038874 */ core::ptr::write(rsp as *mut u64, r14);
    /* 140038876 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140038876 */ core::ptr::write(rsp as *mut u64, r15);
    /* 140038878 */ rbp = (rax).wrapping_sub(0x5f_u64);
    /* 14003887c */ let mut t_14003887c_0: u64 = (rsp).wrapping_sub(0xb0_u64);
    /* 14003887c */ rsp = t_14003887c_0;
    /* 140038883 */ core::ptr::write((rax).wrapping_sub(0x38_u64) as *mut u128, xmm6);
    /* 140038887 */ core::ptr::write((rax).wrapping_sub(0x48_u64) as *mut u128, xmm7);
    /* 14003888b */ core::ptr::write((rax).wrapping_sub(0x58_u64) as *mut u128, xmm8);
    /* 140038890 */ core::ptr::write((rax).wrapping_sub(0x68_u64) as *mut u128, xmm9);
    /* 140038895 */ core::ptr::write((rax).wrapping_sub(0x78_u64) as *mut u128, xmm10);
    /* 14003889a */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm11);
    /* 1400388a0 */ rbx = ((r8 as u32) as u64);
    /* 1400388a3 */ rdi = rcx;
    /* 1400388a6 */ let mut r12: u64 = (((rdx as u32) as i64) as u64);
    /* 1400388a9 */ rcx = core::ptr::read((rcx).wrapping_add(0x130_u64) as *const u64);
    /* 1400388b0 */ let mut t_1400388b0_0: u32 = 0x0_u32;
    /* 1400388b0 */ r8 = (t_1400388b0_0 as u64);
    /* 1400388b3 */ rdx = ((rdx & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 1400388b5 */ rcx = core::ptr::read((rcx).wrapping_add((r12).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400388b9 */ fn_1400b7650();
    if (rax == 0x1f_u64) {
        /* -> bb605 */
    } else {
        /* -> bb604 */
    }

    // ---- bb604 @ 0x1400388c0 ----
    if (rax == 0x1f_u64) {
        /* -> bb605 */
    } else {
        /* -> bb608 */
    }

    // ---- bb605 @ 0x1400388c2 ----
    /* 1400388c4 */ rax = ((rax & 0xffffffffffffff00_u64) | (((ZF == true) as u8) as u64));
    /* fallthrough -> bb926 */

    // ---- bb608 @ 0x1400388cc ----
    /* 1400388cc */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 1400388d3 */ rdx = (rbp).wrapping_add(0x67_u64);
    /* 1400388d7 */ rcx = core::ptr::read((rcx).wrapping_add((r12).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400388db */ fn_1400b4a00();
    /* 1400388e0 */ let mut t_1400388e0_0: u32 = 0x0_u32;
    /* 1400388e0 */ let mut r13: u64 = (t_1400388e0_0 as u64);
    /* 1400388e3 */ rsi = ((r13 as u32) as u64);
    /* 1400388e6 */ let mut r15: u64 = ((r13 as u32) as u64);
    /* 1400388e9 */ let mut r14: u64 = ((r13 as u32) as u64);
    /* 1400388ec */ let mut xmm7: u128 = core::ptr::read((0x1400388f4_u64).wrapping_add(0x2cb7ac_u64) as *const u128);
    /* 1400388f4 */ let mut xmm10: u128 = core::ptr::read((0x1400388fd_u64).wrapping_add(0x2cb8b3_u64) as *const u128);
    /* 1400388fd */ let mut xmm9: u128 = core::ptr::read((0x140038906_u64).wrapping_add(0x2cc3ea_u64) as *const u128);
    /* 140038906 */ let mut xmm11: u128 = core::ptr::read((0x14003890f_u64).wrapping_add(0x2cc411_u64) as *const u128);
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2cae41]
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x364384]
    /* fallthrough -> bb622 */

    // ---- bb622 @ 0x140038920 ----
    /* 140038920 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    // intrinsic: f3410f10 movss xmm0, dword ptr [r14 + rax]
    // intrinsic: f30f104d movss xmm1, dword ptr [rbp + 0x67]
    // intrinsic: 0f2fc800 comiss xmm1, xmm0
    if (CF == false) { /* -> bb629 */ }
    if CF { /* -> bb628 */ }

    // ---- bb628 @ 0x140038935 ----
    if (CF == false) { /* -> bb629 */ }
    if CF { /* -> bb918 */ }

    // ---- bb629 @ 0x14003893b ----
    // intrinsic: f3410f58 addss xmm0, dword ptr [r14 + rax + 8]
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if ((CF | ((rsi as u32) == 0x6_u32)) == false) { /* -> bb634 */ }
    if ((CF | ((rsi as u32) == 0x6_u32)) != 0) { /* -> bb633 */ }

    // ---- bb633 @ 0x140038945 ----
    if ((CF | ((rsi as u32) == 0x6_u32)) == false) { /* -> bb634 */ }
    if ((CF | ((rsi as u32) == 0x6_u32)) != 0) { /* -> bb918 */ }

    // ---- bb634 @ 0x14003894b ----
    // intrinsic: f3410f10 movss xmm0, dword ptr [r14 + rax + 4]
    // intrinsic: f30f104d movss xmm1, dword ptr [rbp + 0x6b]
    // intrinsic: 0f2fc800 comiss xmm1, xmm0
    if (CF == false) { /* -> bb640 */ }
    if CF { /* -> bb639 */ }

    // ---- bb639 @ 0x14003895a ----
    if (CF == false) { /* -> bb640 */ }
    if CF { /* -> bb918 */ }

    // ---- bb640 @ 0x140038960 ----
    // intrinsic: f3410f58 addss xmm0, dword ptr [r14 + rax + 0xc]
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if ((CF | ((rsi as u32) == 0x6_u32)) == false) { /* -> bb645 */ }
    if ((CF | ((rsi as u32) == 0x6_u32)) != 0) { /* -> bb644 */ }

    // ---- bb644 @ 0x14003896a ----
    if ((CF | ((rsi as u32) == 0x6_u32)) == false) { /* -> bb645 */ }
    if ((CF | ((rsi as u32) == 0x6_u32)) != 0) { /* -> bb918 */ }

    // ---- bb645 @ 0x140038970 ----
    if ((rsi as u32) == 0x4_u32) {
        /* -> bb649 */
    } else {
        /* -> bb648 */
    }

    // ---- bb648 @ 0x140038973 ----
    if ((rsi as u32) == 0x4_u32) {
        /* -> bb649 */
    } else {
        /* -> bb701 */
    }

    // ---- bb649 @ 0x140038979 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003897c */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140038983 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm1);
    /* 140038988 */ rcx = (0x40_u32 as u64);
    /* 14003898d */ fn_1400285e0();
    /* 140038992 */ rcx = rax;
    /* 140038995 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u64, rax);
    /* 140038999 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm11);
    /* 14003899f */ xmm0 = core::ptr::read((0x1400389a6_u64).wrapping_add(0x2cbe72_u64) as *const u128);
    /* 1400389a6 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400389a9 */ xmm1 = core::ptr::read((0x1400389b0_u64).wrapping_add(0x2cbe78_u64) as *const u128);
    /* 1400389b0 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 1400389b4 */ xmm0 = core::ptr::read((0x1400389bb_u64).wrapping_add(0x2cbe7d_u64) as *const u128);
    /* 1400389bb */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u128, xmm0);
    /* 1400389bf */ let mut t_1400389bf: u16 = core::ptr::read((0x1400389c6_u64).wrapping_add(0x2cbe82_u64) as *const u16);
    /* 1400389bf */ rax = ((t_1400389bf as u32) as u64);
    /* 1400389c6 */ core::ptr::write((rcx).wrapping_add(0x30_u64) as *mut u16, (rax as u16));
    /* 1400389ca */ let mut t_1400389ca: u8 = core::ptr::read((0x1400389d1_u64).wrapping_add(0x2cbe79_u64) as *const u8);
    /* 1400389ca */ rax = ((t_1400389ca as u32) as u64);
    /* 1400389d1 */ core::ptr::write((rcx).wrapping_add(0x32_u64) as *mut u8, (rax as u8));
    /* 1400389d4 */ core::ptr::write((rcx).wrapping_add(0x33_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 1400389de */ let mut t_1400389de_0: u32 = 0x0_u32;
    /* 1400389de */ r9 = (t_1400389de_0 as u64);
    /* 1400389e1 */ r8 = (rbp).wrapping_sub(0x49_u64);
    /* 1400389e5 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 1400389ec */ rcx = rdi;
    /* 1400389ef */ fn_1400d1090();
    /* 1400389f5 */ rdx = core::ptr::read((rbp).wrapping_sub(0x31_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb681 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb680 */ }

    // ---- bb680 @ 0x1400389fd ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb681 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb835 */ }

    // ---- bb681 @ 0x140038a03 ----
    /* 140038a03 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140038a06 */ rcx = core::ptr::read((rbp).wrapping_sub(0x49_u64) as *const u64);
    /* 140038a0a */ rax = rcx;
    if (CF == false) { /* -> bb688 */ }
    if CF { /* -> bb687 */ }

    // ---- bb687 @ 0x140038a14 ----
    if (CF == false) { /* -> bb688 */ }
    if CF { /* -> bb696 */ }

    // ---- bb688 @ 0x140038a16 ----
    /* 140038a16 */ let mut t_140038a16_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140038a16 */ rdx = t_140038a16_0;
    /* 140038a1a */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140038a1e */ let mut t_140038a1e_0: u64 = (rax).wrapping_sub(rcx);
    /* 140038a1e */ rax = t_140038a1e_0;
    /* 140038a21 */ let mut t_140038a21_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140038a21 */ rax = t_140038a21_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb696 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb695 */ }

    // ---- bb695 @ 0x140038a29 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb696 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1028 */ }

    // ---- bb696 @ 0x140038a2f ----
    /* 140038a2f */ fn_1402c7498();
    /* 140038a34 */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    /* 140038a36 */ r15 = (r15).wrapping_add(0x1_u64);
    /* 140038a39 */ let mut t_140038a39_0: u64 = (r14).wrapping_add(0x10_u64);
    /* 140038a39 */ r14 = t_140038a39_0;
    /* fallthrough -> bb622 */

    // ---- bb701 @ 0x140038a42 ----
    if ((rsi as u32) == 0x3_u32) {
        /* -> bb705 */
    } else {
        /* -> bb704 */
    }

    // ---- bb704 @ 0x140038a45 ----
    if ((rsi as u32) == 0x3_u32) {
        /* -> bb705 */
    } else {
        /* -> bb766 */
    }

    // ---- bb705 @ 0x140038a4b ----
    /* 140038a4b */ let mut t_140038a4b: u64 = core::ptr::read((rdi).wrapping_add(0x278_u64) as *const u64);
    if (t_140038a4b == 0x0_u64) {
        /* -> bb709 */
    } else {
        /* -> bb708 */
    }

    // ---- bb708 @ 0x140038a53 ----
    if (t_140038a4b == 0x0_u64) {
        /* -> bb709 */
    } else {
        /* -> bb947 */
    }

    // ---- bb709 @ 0x140038a59 ----
    /* 140038a59 */ let mut t_140038a59: u64 = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u64);
    if (t_140038a59 == 0x0_u64) {
        /* -> bb713 */
    } else {
        /* -> bb712 */
    }

    // ---- bb712 @ 0x140038a61 ----
    if (t_140038a59 == 0x0_u64) {
        /* -> bb713 */
    } else {
        /* -> bb947 */
    }

    // ---- bb713 @ 0x140038a67 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140038a6a */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140038a71 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm1);
    /* 140038a76 */ rcx = (0x20_u32 as u64);
    /* 140038a7b */ fn_1400285e0();
    /* 140038a80 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u64, rax);
    /* 140038a84 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm9);
    /* 140038a8a */ xmm0 = core::ptr::read((0x140038a91_u64).wrapping_add(0x2cbdbf_u64) as *const u128);
    /* 140038a91 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140038a94 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb724 */ }
    if DF { /* -> bb725 */ }

    // ---- bb724 @ 0x140038a94 ----
    /* 140038a94 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140038a94 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb726 */

    // ---- bb725 @ 0x140038a94 ----
    /* 140038a94 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140038a94 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb726 */

    // ---- bb726 @ 0x140038a9c ----
    /* 140038a9c */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb728 */ }
    if DF { /* -> bb729 */ }

    // ---- bb728 @ 0x140038a9c ----
    /* 140038a9c */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140038a9c */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb730 */

    // ---- bb729 @ 0x140038a9c ----
    /* 140038a9c */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140038a9c */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb730 */

    // ---- bb730 @ 0x140038aa1 ----
    /* 140038aa1 */ let mut t_140038aa1: u32 = core::ptr::read((0x140038aa7_u64).wrapping_add(0x2cbdc1_u64) as *const u32);
    /* 140038aa1 */ rcx = (t_140038aa1 as u64);
    /* 140038aa7 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u32, (rcx as u32));
    /* 140038aaa */ core::ptr::write((rax).wrapping_add(0x1c_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 140038ab4 */ let mut t_140038ab4_0: u32 = 0x0_u32;
    /* 140038ab4 */ r9 = (t_140038ab4_0 as u64);
    /* 140038ab7 */ r8 = (rbp).wrapping_sub(0x49_u64);
    /* 140038abb */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140038ac2 */ rcx = rdi;
    /* 140038ac5 */ fn_1400d1090();
    /* 140038acb */ rdx = core::ptr::read((rbp).wrapping_sub(0x31_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb746 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb745 */ }

    // ---- bb745 @ 0x140038ad3 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb746 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb835 */ }

    // ---- bb746 @ 0x140038ad9 ----
    /* 140038ad9 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140038adc */ rcx = core::ptr::read((rbp).wrapping_sub(0x49_u64) as *const u64);
    /* 140038ae0 */ rax = rcx;
    if (CF == false) { /* -> bb753 */ }
    if CF { /* -> bb752 */ }

    // ---- bb752 @ 0x140038aea ----
    if (CF == false) { /* -> bb753 */ }
    if CF { /* -> bb761 */ }

    // ---- bb753 @ 0x140038aec ----
    /* 140038aec */ let mut t_140038aec_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140038aec */ rdx = t_140038aec_0;
    /* 140038af0 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140038af4 */ let mut t_140038af4_0: u64 = (rax).wrapping_sub(rcx);
    /* 140038af4 */ rax = t_140038af4_0;
    /* 140038af7 */ let mut t_140038af7_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140038af7 */ rax = t_140038af7_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb761 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb760 */ }

    // ---- bb760 @ 0x140038aff ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb761 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1035 */ }

    // ---- bb761 @ 0x140038b05 ----
    /* 140038b05 */ fn_1402c7498();
    /* 140038b0a */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    /* 140038b0c */ r15 = (r15).wrapping_add(0x1_u64);
    /* 140038b0f */ let mut t_140038b0f_0: u64 = (r14).wrapping_add(0x10_u64);
    /* 140038b0f */ r14 = t_140038b0f_0;
    /* fallthrough -> bb622 */

    // ---- bb766 @ 0x140038b18 ----
    if ((rsi as u32) == 0x1_u32) {
        /* -> bb770 */
    } else {
        /* -> bb769 */
    }

    // ---- bb769 @ 0x140038b1b ----
    if ((rsi as u32) == 0x1_u32) {
        /* -> bb770 */
    } else {
        /* -> bb839 */
    }

    // ---- bb770 @ 0x140038b21 ----
    /* 140038b21 */ let mut t_140038b21: u64 = core::ptr::read((rdi).wrapping_add(0x270_u64) as *const u64);
    if (t_140038b21 == 0x0_u64) {
        /* -> bb774 */
    } else {
        /* -> bb773 */
    }

    // ---- bb773 @ 0x140038b29 ----
    if (t_140038b21 == 0x0_u64) {
        /* -> bb774 */
    } else {
        /* -> bb947 */
    }

    // ---- bb774 @ 0x140038b2f ----
    /* 140038b2f */ let mut t_140038b2f: u64 = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u64);
    if (t_140038b2f == 0x0_u64) {
        /* -> bb778 */
    } else {
        /* -> bb777 */
    }

    // ---- bb777 @ 0x140038b37 ----
    if (t_140038b2f == 0x0_u64) {
        /* -> bb778 */
    } else {
        /* -> bb947 */
    }

    // ---- bb778 @ 0x140038b3d ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140038b40 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140038b47 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm1);
    /* 140038b4c */ rcx = (0x40_u32 as u64);
    /* 140038b51 */ fn_1400285e0();
    /* 140038b56 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u64, rax);
    /* 140038b5a */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm10);
    /* 140038b60 */ xmm0 = core::ptr::read((0x140038b67_u64).wrapping_add(0x2cbd09_u64) as *const u128);
    /* 140038b67 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140038b6a */ xmm1 = core::ptr::read((0x140038b71_u64).wrapping_add(0x2cbd0f_u64) as *const u128);
    /* 140038b71 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 140038b75 */ xmm0 = core::ptr::read((0x140038b7c_u64).wrapping_add(0x2cbd14_u64) as *const u128);
    /* 140038b7c */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u128, xmm0);
    /* 140038b80 */ core::ptr::write((rax).wrapping_add(0x30_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 140038b8a */ let mut t_140038b8a_0: u32 = 0x0_u32;
    /* 140038b8a */ r9 = (t_140038b8a_0 as u64);
    /* 140038b8d */ r8 = (rbp).wrapping_sub(0x49_u64);
    /* 140038b91 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140038b98 */ rcx = rdi;
    /* 140038b9b */ fn_1400d1090();
    /* 140038ba1 */ rdx = core::ptr::read((rbp).wrapping_sub(0x31_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb805 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb804 */ }

    // ---- bb804 @ 0x140038ba9 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb805 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb821 */ }

    // ---- bb805 @ 0x140038bab ----
    /* 140038bab */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140038bae */ rcx = core::ptr::read((rbp).wrapping_sub(0x49_u64) as *const u64);
    /* 140038bb2 */ rax = rcx;
    if (CF == false) { /* -> bb812 */ }
    if CF { /* -> bb811 */ }

    // ---- bb811 @ 0x140038bbc ----
    if (CF == false) { /* -> bb812 */ }
    if CF { /* -> bb820 */ }

    // ---- bb812 @ 0x140038bbe ----
    /* 140038bbe */ let mut t_140038bbe_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140038bbe */ rdx = t_140038bbe_0;
    /* 140038bc2 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140038bc6 */ let mut t_140038bc6_0: u64 = (rax).wrapping_sub(rcx);
    /* 140038bc6 */ rax = t_140038bc6_0;
    /* 140038bc9 */ let mut t_140038bc9_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140038bc9 */ rax = t_140038bc9_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb820 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb819 */ }

    // ---- bb819 @ 0x140038bd1 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb820 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1042 */ }

    // ---- bb820 @ 0x140038bd7 ----
    /* 140038bd7 */ fn_1402c7498();
    /* fallthrough -> bb821 */

    // ---- bb821 @ 0x140038bdc ----
    /* 140038bdc */ rcx = core::ptr::read((0x140038be3_u64).wrapping_add(0x3c2605_u64) as *const u64);
    /* 140038be3 */ fn_14010e240();
    if (rdx != 0xf_u64) {
        /* -> bb827 */
    } else {
        /* -> bb826 */
    }

    // ---- bb826 @ 0x140038beb ----
    if (rdx != 0xf_u64) {
        /* -> bb827 */
    } else {
        /* -> bb835 */
    }

    // ---- bb827 @ 0x140038bed ----
    /* 140038bed */ rbx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140038bf4 */ rcx = core::ptr::read((0x140038bfb_u64).wrapping_add(0x3c25ed_u64) as *const u64);
    /* 140038bfb */ fn_14010e240();
    /* 140038c00 */ r9 = rax;
    /* 140038c03 */ r8 = (0x140038c0a_u64).wrapping_add(0x2cbc9e_u64);
    /* 140038c0a */ rdx = rbx;
    /* 140038c0d */ rcx = rdi;
    /* 140038c10 */ fn_1400d2050();
    /* fallthrough -> bb835 */

    // ---- bb835 @ 0x140038c15 ----
    /* 140038c15 */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    /* 140038c17 */ r15 = (r15).wrapping_add(0x1_u64);
    /* 140038c1a */ let mut t_140038c1a_0: u64 = (r14).wrapping_add(0x10_u64);
    /* 140038c1a */ r14 = t_140038c1a_0;
    /* fallthrough -> bb622 */

    // ---- bb839 @ 0x140038c23 ----
    if ((rsi as u32) == 0x5_u32) {
        /* -> bb843 */
    } else {
        /* -> bb842 */
    }

    // ---- bb842 @ 0x140038c26 ----
    if ((rsi as u32) == 0x5_u32) {
        /* -> bb843 */
    } else {
        /* -> bb943 */
    }

    // ---- bb843 @ 0x140038c2c ----
    /* 140038c2c */ rcx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    if ((rsi as u32) != 0x5_u32) {
        /* -> bb848 */
    } else {
        /* -> bb847 */
    }

    // ---- bb847 @ 0x140038c36 ----
    if ((rsi as u32) != 0x5_u32) {
        /* -> bb848 */
    } else {
        /* -> bb966 */
    }

    // ---- bb848 @ 0x140038c3c ----
    /* 140038c3c */ fn_1400b7640();
    if ((rsi as u32) != 0x5_u32) {
        /* -> bb853 */
    } else {
        /* -> bb852 */
    }

    // ---- bb852 @ 0x140038c43 ----
    if ((rsi as u32) != 0x5_u32) {
        /* -> bb853 */
    } else {
        /* -> bb966 */
    }

    // ---- bb853 @ 0x140038c49 ----
    /* 140038c49 */ let mut t_140038c49_0: u32 = 0x0_u32;
    /* 140038c49 */ r9 = (t_140038c49_0 as u64);
    /* 140038c4c */ let mut t_140038c4c_0: u32 = 0x0_u32;
    /* 140038c4c */ r8 = (t_140038c4c_0 as u64);
    /* 140038c4f */ rdx = (0xa_u32 as u64);
    /* 140038c54 */ rcx = core::ptr::read((0x140038c5b_u64).wrapping_add(0x3c258d_u64) as *const u64);
    /* 140038c5b */ fn_140105000();
    if ((rsi as u32) != 0x5_u32) {
        /* -> bb862 */
    } else {
        /* -> bb861 */
    }

    // ---- bb861 @ 0x140038c62 ----
    if ((rsi as u32) != 0x5_u32) {
        /* -> bb862 */
    } else {
        /* -> bb966 */
    }

    // ---- bb862 @ 0x140038c68 ----
    /* 140038c68 */ core::ptr::write((rdi).wrapping_add(0x254_u64) as *mut u32, (rsi as u32));
    /* 140038c6e */ core::ptr::write((rdi).wrapping_add(0x223c_u64) as *mut u8, 0x0_u8);
    /* 140038c75 */ core::ptr::write((rdi).wrapping_add(0x2250_u64) as *mut u8, 0x0_u8);
    /* 140038c7c */ let mut t_140038c7c: u32 = core::ptr::read((rdi).wrapping_add(0x2240_u64) as *const u32);
    /* 140038c7c */ core::ptr::write((rdi).wrapping_add(0x2240_u64) as *mut u32, (t_140038c7c).wrapping_add(0x1_u32));
    /* 140038c82 */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140038c89 */ rcx = core::ptr::read((rax).wrapping_add((r12).wrapping_mul(0x8_u64)) as *const u64);
    /* 140038c8d */ core::ptr::write((rdi).wrapping_add(0x260_u64) as *mut u64, rcx);
    /* 140038c94 */ rax = core::ptr::read((rdi).wrapping_add(0x60_u64) as *const u64);
    /* 140038c98 */ core::ptr::write((rax).wrapping_add(0x5d_u64) as *mut u8, 0x0_u8);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140038c9f */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 140038ca3 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm7);
    /* 140038ca8 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb875 */ }
    if DF { /* -> bb876 */ }

    // ---- bb875 @ 0x140038ca8 ----
    /* 140038ca8 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140038ca8 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb877 */

    // ---- bb876 @ 0x140038ca8 ----
    /* 140038ca8 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140038ca8 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb877 */

    // ---- bb877 @ 0x140038cb0 ----
    /* 140038cb0 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb879 */ }
    if DF { /* -> bb880 */ }

    // ---- bb879 @ 0x140038cb0 ----
    /* 140038cb0 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140038cb0 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb881 */

    // ---- bb880 @ 0x140038cb0 ----
    /* 140038cb0 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140038cb0 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb881 */

    // ---- bb881 @ 0x140038cb5 ----
    /* 140038cb5 */ let mut t_140038cb5: u8 = core::ptr::read((0x140038cbc_u64).wrapping_add(0x2cbc54_u64) as *const u8);
    /* 140038cb5 */ rax = ((t_140038cb5 as u32) as u64);
    /* 140038cbc */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u8, (rax as u8));
    /* 140038cbf */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u8, 0x0_u8);
    /* 140038cc3 */ r8 = (((rsi).wrapping_add((rsi).wrapping_mul(0x4_u64)) as u32) as u64);
    /* 140038cc7 */ r8 = ((((r8).wrapping_mul(0x4_u64)).wrapping_sub(0x32_u64) as u32) as u64);
    /* 140038ccf */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140038cd4 */ let mut xmm3: u128 = xmm8;
    /* 140038cd8 */ rdx = (0x64_u32 as u64);
    /* 140038cdd */ rcx = (rbp).wrapping_sub(0x49_u64);
    /* 140038ce1 */ fn_140040b90();
    /* 140038ce7 */ rdx = core::ptr::read((rbp).wrapping_sub(0x31_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb898 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb897 */ }

    // ---- bb897 @ 0x140038cef ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb898 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb914 */ }

    // ---- bb898 @ 0x140038cf1 ----
    /* 140038cf1 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140038cf4 */ rcx = core::ptr::read((rbp).wrapping_sub(0x49_u64) as *const u64);
    /* 140038cf8 */ rax = rcx;
    if (CF == false) { /* -> bb905 */ }
    if CF { /* -> bb904 */ }

    // ---- bb904 @ 0x140038d02 ----
    if (CF == false) { /* -> bb905 */ }
    if CF { /* -> bb913 */ }

    // ---- bb905 @ 0x140038d04 ----
    /* 140038d04 */ let mut t_140038d04_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140038d04 */ rdx = t_140038d04_0;
    /* 140038d08 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140038d0c */ let mut t_140038d0c_0: u64 = (rax).wrapping_sub(rcx);
    /* 140038d0c */ rax = t_140038d0c_0;
    /* 140038d0f */ let mut t_140038d0f_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140038d0f */ rax = t_140038d0f_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb913 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb912 */ }

    // ---- bb912 @ 0x140038d17 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb913 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1021 */ }

    // ---- bb913 @ 0x140038d1d ----
    /* 140038d1d */ fn_1402c7498();
    /* fallthrough -> bb914 */

    // ---- bb914 @ 0x140038d22 ----
    /* 140038d22 */ fn_14003f5e0();
    /* 140038d27 */ core::ptr::write((rdi).wrapping_add(0x1b0_u64) as *mut u32, (r13 as u32));
    /* 140038d2e */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, 0x1_u32);
    /* 140038d38 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u32, (r13 as u32));
    /* fallthrough -> bb918 */

    // ---- bb918 @ 0x140038d3f ----
    /* 140038d3f */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    /* 140038d41 */ r15 = (r15).wrapping_add(0x1_u64);
    /* 140038d44 */ let mut t_140038d44_0: u64 = (r14).wrapping_add(0x10_u64);
    /* 140038d44 */ r14 = t_140038d44_0;
    if (SF == OF) {
        /* -> bb925 */
    } else {
        /* -> bb924 */
    }

    // ---- bb924 @ 0x140038d4b ----
    if (SF != OF) {
        /* -> bb622 */
    } else {
        /* -> bb925 */
    }

    // ---- bb925 @ 0x140038d51 ----
    /* 140038d51 */ rax = ((rax & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* fallthrough -> bb926 */

    // ---- bb926 @ 0x140038d53 ----
    /* 140038d53 */ r11 = (rsp).wrapping_add(0xb0_u64);
    /* 140038d5b */ rbx = core::ptr::read((r11).wrapping_add(0x38_u64) as *const u64);
    /* 140038d5f */ rsi = core::ptr::read((r11).wrapping_add(0x40_u64) as *const u64);
    /* 140038d63 */ rdi = core::ptr::read((r11).wrapping_add(0x48_u64) as *const u64);
    /* 140038d67 */ xmm6 = core::ptr::read((r11).wrapping_sub(0x10_u64) as *const u128);
    /* 140038d6c */ xmm7 = core::ptr::read((r11).wrapping_sub(0x20_u64) as *const u128);
    /* 140038d71 */ let mut xmm8: u128 = core::ptr::read((r11).wrapping_sub(0x30_u64) as *const u128);
    /* 140038d76 */ xmm9 = core::ptr::read((r11).wrapping_sub(0x40_u64) as *const u128);
    /* 140038d7b */ xmm10 = core::ptr::read((r11).wrapping_sub(0x50_u64) as *const u128);
    /* 140038d80 */ xmm11 = core::ptr::read((r11).wrapping_sub(0x60_u64) as *const u128);
    /* 140038d85 */ rsp = r11;
    /* 140038d88 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140038d88 */ r15 = core::ptr::read(rsp as *const u64);
    /* 140038d8a */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140038d8a */ r14 = core::ptr::read(rsp as *const u64);
    /* 140038d8c */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140038d8c */ r13 = core::ptr::read(rsp as *const u64);
    /* 140038d8e */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140038d8e */ r12 = core::ptr::read(rsp as *const u64);
    /* 140038d90 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140038d90 */ rbp = core::ptr::read(rsp as *const u64);
    /* 140038d91 */ return;
    // <no successors>

    // ---- bb943 @ 0x140038d92 ----
    if (SF != OF) {
        /* -> bb947 */
    } else {
        /* -> bb946 */
    }

    // ---- bb946 @ 0x140038d95 ----
    if (SF == OF) {
        /* -> bb862 */
    } else {
        /* -> bb947 */
    }

    // ---- bb947 @ 0x140038d9b ----
    /* 140038d9b */ rax = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140038da2 */ rcx = core::ptr::read((rax).wrapping_add((r12).wrapping_mul(0x8_u64)) as *const u64);
    /* 140038da6 */ let mut t_140038da6: u32 = core::ptr::read((rcx).wrapping_add(0x1f8_u64) as *const u32);
    /* 140038da6 */ rcx = (t_140038da6 as u64);
    /* 140038dac */ fn_1400c7930();
    /* 140038db1 */ let mut t_140038db1: u8 = core::ptr::read(((rax).wrapping_add((r15).wrapping_mul(0x1_u64))).wrapping_add(0x60_u64) as *const u8);
    if (t_140038db1 != 0x0_u8) {
        /* -> bb955 */
    } else {
        /* -> bb954 */
    }

    // ---- bb954 @ 0x140038db7 ----
    if (t_140038db1 == 0x0_u8) {
        /* -> bb862 */
    } else {
        /* -> bb955 */
    }

    // ---- bb955 @ 0x140038dbd ----
    /* 140038dbd */ rbx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140038dc4 */ rdx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140038dcb */ rdx = core::ptr::read((rdx).wrapping_add((r12).wrapping_mul(0x8_u64)) as *const u64);
    /* 140038dcf */ rcx = rdi;
    /* 140038dd2 */ fn_1400cfdb0();
    /* 140038dd7 */ r9 = rax;
    /* 140038dda */ r8 = (0x140038de1_u64).wrapping_add(0x2cbb07_u64);
    /* 140038de1 */ rdx = rbx;
    /* 140038de4 */ rcx = rdi;
    /* 140038de7 */ fn_1400d2050();
    /* fallthrough -> bb918 */

    // ---- bb966 @ 0x140038df1 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140038df4 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140038dfb */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm1);
    /* 140038e00 */ rcx = (0x20_u32 as u64);
    /* 140038e05 */ fn_1400285e0();
    /* 140038e0a */ rdx = rax;
    /* 140038e0d */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u64, rax);
    /* 140038e11 */ xmm0 = core::ptr::read((0x140038e19_u64).wrapping_add(0x2cbeb7_u64) as *const u128);
    /* 140038e19 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm0);
    /* 140038e1e */ xmm0 = core::ptr::read((0x140038e25_u64).wrapping_add(0x2cbaab_u64) as *const u128);
    /* 140038e25 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 140038e28 */ let mut t_140038e28: u32 = core::ptr::read((0x140038e2e_u64).wrapping_add(0x2cbab2_u64) as *const u32);
    /* 140038e28 */ rcx = (t_140038e28 as u64);
    /* 140038e2e */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u32, (rcx as u32));
    /* 140038e31 */ let mut t_140038e31: u16 = core::ptr::read((0x140038e38_u64).wrapping_add(0x2cbaac_u64) as *const u16);
    /* 140038e31 */ rcx = ((t_140038e31 as u32) as u64);
    /* 140038e38 */ core::ptr::write((rax).wrapping_add(0x14_u64) as *mut u16, (rcx as u16));
    /* 140038e3c */ let mut t_140038e3c: u8 = core::ptr::read((0x140038e43_u64).wrapping_add(0x2cbaa3_u64) as *const u8);
    /* 140038e3c */ rax = ((t_140038e3c as u32) as u64);
    /* 140038e43 */ core::ptr::write((rdx).wrapping_add(0x16_u64) as *mut u8, (rax as u8));
    /* 140038e46 */ core::ptr::write((rdx).wrapping_add(0x17_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 140038e50 */ let mut t_140038e50_0: u32 = 0x0_u32;
    /* 140038e50 */ r9 = (t_140038e50_0 as u64);
    /* 140038e53 */ r8 = (rbp).wrapping_sub(0x49_u64);
    /* 140038e57 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140038e5e */ rcx = rdi;
    /* 140038e61 */ fn_1400d1090();
    /* 140038e67 */ rdx = core::ptr::read((rbp).wrapping_sub(0x31_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb997 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb996 */ }

    // ---- bb996 @ 0x140038e6f ----
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb925 */ }
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb997 */ }

    // ---- bb997 @ 0x140038e75 ----
    /* 140038e75 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140038e78 */ rcx = core::ptr::read((rbp).wrapping_sub(0x49_u64) as *const u64);
    /* 140038e7c */ rax = rcx;
    if (CF == false) { /* -> bb1004 */ }
    if CF { /* -> bb1003 */ }

    // ---- bb1003 @ 0x140038e86 ----
    if (CF == false) { /* -> bb1004 */ }
    if CF { /* -> bb1012 */ }

    // ---- bb1004 @ 0x140038e88 ----
    /* 140038e88 */ let mut t_140038e88_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140038e88 */ rdx = t_140038e88_0;
    /* 140038e8c */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140038e90 */ let mut t_140038e90_0: u64 = (rax).wrapping_sub(rcx);
    /* 140038e90 */ rax = t_140038e90_0;
    /* 140038e93 */ let mut t_140038e93_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140038e93 */ rax = t_140038e93_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1012 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1011 */ }

    // ---- bb1011 @ 0x140038e9b ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1012 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1014 */ }

    // ---- bb1012 @ 0x140038e9d ----
    /* 140038e9d */ fn_1402c7498();
    /* fallthrough -> bb925 */

    // ---- bb1014 @ 0x140038ea7 ----
    /* 140038ea7 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 140038eac */ let mut t_140038eac_0: u32 = 0x0_u32;
    /* 140038eac */ r9 = (t_140038eac_0 as u64);
    /* 140038eaf */ let mut t_140038eaf_0: u32 = 0x0_u32;
    /* 140038eaf */ r8 = (t_140038eaf_0 as u64);
    /* 140038eb2 */ let mut t_140038eb2_0: u32 = 0x0_u32;
    /* 140038eb2 */ rdx = (t_140038eb2_0 as u64);
    /* 140038eb4 */ let mut t_140038eb4_0: u32 = 0x0_u32;
    /* 140038eb4 */ rcx = (t_140038eb4_0 as u64);
    /* 140038eb6 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1021 */

    // ---- bb1021 @ 0x140038ebc ----
    /* 140038ebc */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 140038ec1 */ let mut t_140038ec1_0: u32 = 0x0_u32;
    /* 140038ec1 */ r9 = (t_140038ec1_0 as u64);
    /* 140038ec4 */ let mut t_140038ec4_0: u32 = 0x0_u32;
    /* 140038ec4 */ r8 = (t_140038ec4_0 as u64);
    /* 140038ec7 */ let mut t_140038ec7_0: u32 = 0x0_u32;
    /* 140038ec7 */ rdx = (t_140038ec7_0 as u64);
    /* 140038ec9 */ let mut t_140038ec9_0: u32 = 0x0_u32;
    /* 140038ec9 */ rcx = (t_140038ec9_0 as u64);
    /* 140038ecb */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1028 */

    // ---- bb1028 @ 0x140038ed1 ----
    /* 140038ed1 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 140038ed6 */ let mut t_140038ed6_0: u32 = 0x0_u32;
    /* 140038ed6 */ r9 = (t_140038ed6_0 as u64);
    /* 140038ed9 */ let mut t_140038ed9_0: u32 = 0x0_u32;
    /* 140038ed9 */ r8 = (t_140038ed9_0 as u64);
    /* 140038edc */ let mut t_140038edc_0: u32 = 0x0_u32;
    /* 140038edc */ rdx = (t_140038edc_0 as u64);
    /* 140038ede */ let mut t_140038ede_0: u32 = 0x0_u32;
    /* 140038ede */ rcx = (t_140038ede_0 as u64);
    /* 140038ee0 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1035 */

    // ---- bb1035 @ 0x140038ee6 ----
    /* 140038ee6 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 140038eeb */ let mut t_140038eeb_0: u32 = 0x0_u32;
    /* 140038eeb */ r9 = (t_140038eeb_0 as u64);
    /* 140038eee */ let mut t_140038eee_0: u32 = 0x0_u32;
    /* 140038eee */ r8 = (t_140038eee_0 as u64);
    /* 140038ef1 */ let mut t_140038ef1_0: u32 = 0x0_u32;
    /* 140038ef1 */ rdx = (t_140038ef1_0 as u64);
    /* 140038ef3 */ let mut t_140038ef3_0: u32 = 0x0_u32;
    /* 140038ef3 */ rcx = (t_140038ef3_0 as u64);
    /* 140038ef5 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1042 */

    // ---- bb1042 @ 0x140038efb ----
    /* 140038efb */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 140038f00 */ let mut t_140038f00_0: u32 = 0x0_u32;
    /* 140038f00 */ r9 = (t_140038f00_0 as u64);
    /* 140038f03 */ let mut t_140038f03_0: u32 = 0x0_u32;
    /* 140038f03 */ r8 = (t_140038f03_0 as u64);
    /* 140038f06 */ let mut t_140038f06_0: u32 = 0x0_u32;
    /* 140038f06 */ rdx = (t_140038f06_0 as u64);
    /* 140038f08 */ let mut t_140038f08_0: u32 = 0x0_u32;
    /* 140038f08 */ rcx = (t_140038f08_0 as u64);
    /* 140038f0a */ fn_1402cd884();
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
    /* 140038f20 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140038f20 */ core::ptr::write(rsp as *mut u64, rbx);
    /* 140038f22 */ let mut t_140038f22_0: u64 = (rsp).wrapping_sub(0x50_u64);
    /* 140038f22 */ rsp = t_140038f22_0;
    /* 140038f26 */ rbx = rcx;
    /* 140038f29 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, 0xffffffff_u32);
    /* 140038f31 */ rdx = (0x4_u32 as u64);
    /* 140038f36 */ let mut t_140038f36_0: u32 = 0x0_u32;
    /* 140038f36 */ rcx = (t_140038f36_0 as u64);
    /* 140038f38 */ r9 = (0xffffffff_u32 as u64);
    /* 140038f3e */ r8 = ((r9 as u32) as u64);
    /* 140038f41 */ fn_1400c7a10();
    /* 140038f46 */ rdx = core::ptr::read((rbx).wrapping_add(0x268_u64) as *const u64);
    /* 140038f4d */ core::ptr::write((rdx).wrapping_add(0x1f8_u64) as *mut u32, (rax as u32));
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140038f56 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u128, xmm0);
    /* 140038f5b */ xmm1 = core::ptr::read((0x140038f63_u64).wrapping_add(0x2cb11d_u64) as *const u128);
    /* 140038f63 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u128, xmm1);
    /* 140038f69 */ let mut t_140038f69: u32 = core::ptr::read((0x140038f6f_u64).wrapping_add(0x2cb9a5_u64) as *const u32);
    /* 140038f69 */ rax = (t_140038f69 as u64);
    /* 140038f6f */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u32, (rax as u32));
    /* 140038f73 */ let mut t_140038f73: u8 = core::ptr::read((0x140038f7a_u64).wrapping_add(0x2cb99e_u64) as *const u8);
    /* 140038f73 */ rax = ((t_140038f73 as u32) as u64);
    /* 140038f7a */ core::ptr::write((rsp).wrapping_add(0x34_u64) as *mut u8, (rax as u8));
    /* 140038f7e */ core::ptr::write((rsp).wrapping_add(0x35_u64) as *mut u8, 0x0_u8);
    /* 140038f83 */ r8 = (rsp).wrapping_add(0x30_u64);
    /* 140038f88 */ rdx = core::ptr::read((rbx).wrapping_add(0x268_u64) as *const u64);
    /* 140038f8f */ rcx = rbx;
    /* 140038f92 */ fn_1400cfd60();
    /* 140038f98 */ rdx = core::ptr::read((rsp).wrapping_add(0x48_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1095 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1094 */ }

    // ---- bb1094 @ 0x140038fa1 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1095 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1111 */ }

    // ---- bb1095 @ 0x140038fa3 ----
    /* 140038fa3 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140038fa6 */ rcx = core::ptr::read((rsp).wrapping_add(0x30_u64) as *const u64);
    /* 140038fab */ rax = rcx;
    if (CF == false) { /* -> bb1102 */ }
    if CF { /* -> bb1101 */ }

    // ---- bb1101 @ 0x140038fb5 ----
    if (CF == false) { /* -> bb1102 */ }
    if CF { /* -> bb1110 */ }

    // ---- bb1102 @ 0x140038fb7 ----
    /* 140038fb7 */ let mut t_140038fb7_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140038fb7 */ rdx = t_140038fb7_0;
    /* 140038fbb */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140038fbf */ let mut t_140038fbf_0: u64 = (rax).wrapping_sub(rcx);
    /* 140038fbf */ rax = t_140038fbf_0;
    /* 140038fc2 */ let mut t_140038fc2_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140038fc2 */ rax = t_140038fc2_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1110 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1109 */ }

    // ---- bb1109 @ 0x140038fca ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1110 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1115 */ }

    // ---- bb1110 @ 0x140038fcc ----
    /* 140038fcc */ fn_1402c7498();
    /* fallthrough -> bb1111 */

    // ---- bb1111 @ 0x140038fd1 ----
    /* 140038fd1 */ core::ptr::write((rbx).wrapping_add(0x268_u64) as *mut u64, 0x0_u64);
    /* 140038fdc */ let mut t_140038fdc_0: u64 = (rsp).wrapping_add(0x50_u64);
    /* 140038fdc */ rsp = t_140038fdc_0;
    /* 140038fe0 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140038fe0 */ rbx = core::ptr::read(rsp as *const u64);
    /* 140038fe1 */ return;
    // <no successors>

    // ---- bb1115 @ 0x140038fe2 ----
    /* 140038fe2 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 140038feb */ let mut t_140038feb_0: u32 = 0x0_u32;
    /* 140038feb */ r9 = (t_140038feb_0 as u64);
    /* 140038fee */ let mut t_140038fee_0: u32 = 0x0_u32;
    /* 140038fee */ r8 = (t_140038fee_0 as u64);
    /* 140038ff1 */ let mut t_140038ff1_0: u32 = 0x0_u32;
    /* 140038ff1 */ rdx = (t_140038ff1_0 as u64);
    /* 140038ff3 */ let mut t_140038ff3_0: u32 = 0x0_u32;
    /* 140038ff3 */ rcx = (t_140038ff3_0 as u64);
    /* 140038ff5 */ fn_1402cd884();
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
    /* 140039010 */ let mut t_140039010_0: u64 = (rsp).wrapping_sub(0x28_u64);
    /* 140039010 */ rsp = t_140039010_0;
    /* 140039014 */ let mut t_140039014: u32 = core::ptr::read((rcx).wrapping_add(0x254_u64) as *const u32);
    /* 140039014 */ rax = (t_140039014 as u64);
    /* 14003901a */ rdx = rcx;
    if ((rax as u32) != 0x1_u32) {
        /* -> bb1150 */
    } else {
        /* -> bb1149 */
    }

    // ---- bb1149 @ 0x140039020 ----
    if ((rax as u32) != 0x1_u32) {
        /* -> bb1150 */
    } else {
        /* -> bb1155 */
    }

    // ---- bb1150 @ 0x140039022 ----
    /* 140039022 */ let mut t_140039022_0: u32 = ((rax as u32)).wrapping_add(0xfffffffd_u32);
    /* 140039022 */ rax = (t_140039022_0 as u64);
    if ((rax as u32) == 0x1_u32) {
        /* -> bb1155 */
    } else {
        /* -> bb1154 */
    }

    // ---- bb1154 @ 0x14003902a ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb1155 */
    } else {
        /* -> bb1231 */
    }

    // ---- bb1155 @ 0x140039030 ----
    /* 140039030 */ core::ptr::write((rsp).wrapping_add(0x48_u64) as *mut u64, rdi);
    /* 140039035 */ rdi = (rcx).wrapping_add(0x130_u64);
    /* 14003903c */ rax = core::ptr::read((rdi).wrapping_add(0x8_u64) as *const u64);
    /* 140039040 */ let mut t_140039040: u64 = core::ptr::read(rdi as *const u64);
    if (t_140039040 != rax) {
        /* -> bb1162 */
    } else {
        /* -> bb1161 */
    }

    // ---- bb1161 @ 0x140039043 ----
    if (t_140039040 != rax) {
        /* -> bb1162 */
    } else {
        /* -> bb1230 */
    }

    // ---- bb1162 @ 0x140039049 ----
    /* 140039049 */ rax = core::ptr::read((rcx).wrapping_add(0x138_u64) as *const u64);
    /* 140039050 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rbx);
    /* 140039055 */ core::ptr::write((rsp).wrapping_add(0x40_u64) as *mut u64, rsi);
    /* 14003905a */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r14);
    /* 14003905f */ rcx = core::ptr::read((rax).wrapping_sub(0x8_u64) as *const u64);
    /* 140039063 */ core::ptr::write((rcx).wrapping_add(0x1e0_u64) as *mut u8, 0x0_u8);
    /* 14003906a */ rcx = core::ptr::read((rdx).wrapping_add(0x138_u64) as *const u64);
    /* 140039071 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140039075 */ fn_1400b47d0();
    /* 14003907a */ rbx = core::ptr::read((rdi).wrapping_add(0x8_u64) as *const u64);
    /* 14003907e */ rax = core::ptr::read(rdi as *const u64);
    /* 140039081 */ r14 = rbx;
    /* 140039084 */ let mut t_140039084_0: u64 = (r14).wrapping_sub(rax);
    /* 140039084 */ r14 = t_140039084_0;
    /* 140039087 */ r14 = (((r14 as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    /* 14003908b */ rsi = (r14).wrapping_sub(0x1_u64);
    if CF {
        /* -> bb1181 */
    } else {
        /* -> bb1180 */
    }

    // ---- bb1180 @ 0x140039092 ----
    if CF {
        /* -> bb1181 */
    } else {
        /* -> bb1184 */
    }

    // ---- bb1181 @ 0x140039094 ----
    /* 140039094 */ rax = (rax).wrapping_add((rsi).wrapping_mul(0x8_u64));
    /* 140039098 */ core::ptr::write((rdi).wrapping_add(0x8_u64) as *mut u64, rax);
    /* fallthrough -> bb1227 */

    // ---- bb1184 @ 0x1400390a1 ----
    if ((CF | (rsi == r14)) == false) { /* -> bb1187 */ }
    if ((CF | (rsi == r14)) != 0) { /* -> bb1186 */ }

    // ---- bb1186 @ 0x1400390a1 ----
    if ((CF | (rsi == r14)) == false) { /* -> bb1187 */ }
    if ((CF | (rsi == r14)) != 0) { /* -> bb1227 */ }

    // ---- bb1187 @ 0x1400390a7 ----
    /* 1400390a7 */ rcx = core::ptr::read((rdi).wrapping_add(0x10_u64) as *const u64);
    /* 1400390ab */ let mut t_1400390ab_0: u64 = (rcx).wrapping_sub(rax);
    /* 1400390ab */ rcx = t_1400390ab_0;
    /* 1400390ae */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if ((CF | (rsi == rcx)) == false) { /* -> bb1194 */ }
    if ((CF | (rsi == rcx)) != 0) { /* -> bb1193 */ }

    // ---- bb1193 @ 0x1400390b5 ----
    if ((CF | (rsi == rcx)) == false) { /* -> bb1194 */ }
    if ((CF | (rsi == rcx)) != 0) { /* -> bb1245 */ }

    // ---- bb1194 @ 0x1400390bb ----
    /* 1400390bb */ r8 = 0x1fffffffffffffff_u64;
    if (((CF == false) & (rsi != r8)) == false) { /* -> bb1199 */ }
    if (((CF == false) & (rsi != r8)) != 0) { /* -> bb1198 */ }

    // ---- bb1198 @ 0x1400390c8 ----
    if (((CF == false) & (rsi != r8)) == false) { /* -> bb1199 */ }
    if (((CF == false) & (rsi != r8)) != 0) { /* -> bb1252 */ }

    // ---- bb1199 @ 0x1400390ce ----
    /* 1400390ce */ rdx = rcx;
    /* 1400390d1 */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u64, rbp);
    /* 1400390d6 */ rdx = (rdx >> 0x1_u64);
    /* 1400390d9 */ rax = r8;
    /* 1400390dc */ let mut t_1400390dc_0: u64 = (rax).wrapping_sub(rdx);
    /* 1400390dc */ rax = t_1400390dc_0;
    if ((CF | (rcx == rax)) == false) { /* -> bb1208 */ }
    if ((CF | (rcx == rax)) != 0) { /* -> bb1207 */ }

    // ---- bb1207 @ 0x1400390e2 ----
    if ((CF | (rcx == rax)) == false) { /* -> bb1208 */ }
    if ((CF | (rcx == rax)) != 0) { /* -> bb1233 */ }

    // ---- bb1208 @ 0x1400390e4 ----
    /* 1400390e4 */ rbp = r8;
    /* fallthrough -> bb1209 */

    // ---- bb1209 @ 0x1400390e7 ----
    /* 1400390e7 */ rcx = (rbp).wrapping_mul(0x8_u64);
    /* 1400390ef */ fn_1400285e0();
    /* 1400390f4 */ let mut t_1400390f4_0: u32 = 0x0_u32;
    /* 1400390f4 */ rdx = (t_1400390f4_0 as u64);
    /* 1400390f6 */ r8 = 0xfffffffffffffff8_u64;
    /* 1400390fd */ rbx = rax;
    /* 140039100 */ rcx = (rax).wrapping_add((r14).wrapping_mul(0x8_u64));
    /* 140039104 */ fn_1402f98d0();
    /* 140039109 */ rdx = core::ptr::read(rdi as *const u64);
    /* 14003910c */ rcx = rbx;
    /* 14003910f */ r8 = core::ptr::read((rdi).wrapping_add(0x8_u64) as *const u64);
    /* 140039113 */ let mut t_140039113_0: u64 = (r8).wrapping_sub(rdx);
    /* 140039113 */ r8 = t_140039113_0;
    /* 140039116 */ fn_1402f9230();
    /* 14003911b */ r9 = rbp;
    /* 14003911e */ r8 = rsi;
    /* 140039121 */ rdx = rbx;
    /* 140039124 */ rcx = rdi;
    /* 140039127 */ fn_140037380();
    /* 14003912c */ rbp = core::ptr::read((rsp).wrapping_add(0x38_u64) as *const u64);
    /* fallthrough -> bb1227 */

    // ---- bb1227 @ 0x140039131 ----
    /* 140039131 */ rsi = core::ptr::read((rsp).wrapping_add(0x40_u64) as *const u64);
    /* 140039136 */ rbx = core::ptr::read((rsp).wrapping_add(0x30_u64) as *const u64);
    /* 14003913b */ r14 = core::ptr::read((rsp).wrapping_add(0x20_u64) as *const u64);
    /* fallthrough -> bb1230 */

    // ---- bb1230 @ 0x140039140 ----
    /* 140039140 */ rdi = core::ptr::read((rsp).wrapping_add(0x48_u64) as *const u64);
    /* fallthrough -> bb1231 */

    // ---- bb1231 @ 0x140039145 ----
    /* 140039145 */ let mut t_140039145_0: u64 = (rsp).wrapping_add(0x28_u64);
    /* 140039145 */ rsp = t_140039145_0;
    /* 140039149 */ return;
    // <no successors>

    // ---- bb1233 @ 0x14003914a ----
    /* 14003914a */ rbp = (rcx).wrapping_add((rdx).wrapping_mul(0x1_u64));
    if CF {
        /* -> bb1238 */
    } else {
        /* -> bb1237 */
    }

    // ---- bb1237 @ 0x140039151 ----
    if CF {
        /* -> bb1238 */
    } else {
        /* -> bb1240 */
    }

    // ---- bb1238 @ 0x140039153 ----
    /* 140039153 */ rbp = rsi;
    /* fallthrough -> bb1209 */

    // ---- bb1240 @ 0x140039158 ----
    if (((CF == false) & (rbp != r8)) == false) { /* -> bb1244 */ }
    if (((CF == false) & (rbp != r8)) != 0) { /* -> bb1243 */ }

    // ---- bb1243 @ 0x14003915b ----
    if (((CF == false) & (rbp != r8)) == false) { /* -> bb1244 */ }
    if (((CF == false) & (rbp != r8)) != 0) { /* -> bb1254 */ }

    // ---- bb1244 @ 0x14003915d ----
    /* fallthrough -> bb1209 */

    // ---- bb1245 @ 0x14003915f ----
    /* 14003915f */ let mut t_14003915f_0: u32 = 0x0_u32;
    /* 14003915f */ rdx = (t_14003915f_0 as u64);
    /* 140039161 */ r8 = 0xfffffffffffffff8_u64;
    /* 140039168 */ rcx = rbx;
    /* 14003916b */ fn_1402f98d0();
    /* 140039170 */ rax = (rbx).wrapping_sub(0x8_u64);
    /* 140039174 */ core::ptr::write((rdi).wrapping_add(0x8_u64) as *mut u64, rax);
    /* fallthrough -> bb1227 */

    // ---- bb1252 @ 0x14003917a ----
    /* 14003917a */ fn_14002f0d0();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb1254 */

    // ---- bb1254 @ 0x140039180 ----
    /* 140039180 */ fn_140024090();
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
    /* 140039190 */ rax = rsp;
    /* 140039193 */ core::ptr::write((rax).wrapping_add(0x8_u64) as *mut u64, rcx);
    /* 140039197 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140039197 */ core::ptr::write(rsp as *mut u64, rbp);
    /* 140039198 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140039198 */ core::ptr::write(rsp as *mut u64, rbx);
    /* 140039199 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 140039199 */ core::ptr::write(rsp as *mut u64, rsi);
    /* 14003919a */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003919a */ core::ptr::write(rsp as *mut u64, rdi);
    /* 14003919b */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003919b */ core::ptr::write(rsp as *mut u64, r12);
    /* 14003919d */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003919d */ core::ptr::write(rsp as *mut u64, r13);
    /* 14003919f */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003919f */ core::ptr::write(rsp as *mut u64, r14);
    /* 1400391a1 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 1400391a1 */ core::ptr::write(rsp as *mut u64, r15);
    /* 1400391a3 */ rbp = (rsp).wrapping_sub(0x48_u64);
    /* 1400391a8 */ let mut t_1400391a8_0: u64 = (rsp).wrapping_sub(0x148_u64);
    /* 1400391a8 */ rsp = t_1400391a8_0;
    /* 1400391af */ core::ptr::write((rax).wrapping_sub(0x58_u64) as *mut u128, xmm6);
    /* 1400391b3 */ core::ptr::write((rax).wrapping_sub(0x68_u64) as *mut u128, xmm7);
    /* 1400391b7 */ core::ptr::write((rax).wrapping_sub(0x78_u64) as *mut u128, xmm8);
    /* 1400391bc */ core::ptr::write((rax).wrapping_sub(0x88_u64) as *mut u128, xmm9);
    /* 1400391c4 */ core::ptr::write((rax).wrapping_sub(0x98_u64) as *mut u128, xmm10);
    /* 1400391cc */ core::ptr::write((rax).wrapping_sub(0xa8_u64) as *mut u128, xmm11);
    /* 1400391d4 */ core::ptr::write((rax).wrapping_sub(0xb8_u64) as *mut u128, xmm12);
    /* 1400391dc */ core::ptr::write((rax).wrapping_sub(0xc8_u64) as *mut u128, xmm13);
    /* 1400391e4 */ core::ptr::write((rax).wrapping_sub(0xd8_u64) as *mut u128, xmm14);
    /* 1400391ec */ core::ptr::write((rax).wrapping_sub(0xe8_u64) as *mut u128, xmm15);
    /* 1400391f4 */ rdi = rcx;
    /* 1400391f7 */ let mut t_1400391f7: u32 = core::ptr::read((rcx).wrapping_add(0x250_u64) as *const u32);
    /* 1400391f7 */ core::ptr::write((rcx).wrapping_add(0x250_u64) as *mut u32, (t_1400391f7).wrapping_add(0x1_u32));
    /* 1400391fd */ fn_1400ca670();
    /* 140039202 */ rcx = rdi;
    /* 140039205 */ fn_1400cef70();
    /* 14003920a */ let mut t_14003920a_0: u32 = 0x0_u32;
    /* 14003920a */ r13 = (t_14003920a_0 as u64);
    /* 14003920d */ let mut t_14003920d: u8 = core::ptr::read((0x140039214_u64).wrapping_add(0x3a0367_u64) as *const u8);
    if (t_14003920d != (r13 as u8)) {
        /* -> bb1298 */
    } else {
        /* -> bb1297 */
    }

    // ---- bb1297 @ 0x140039214 ----
    if (t_14003920d != (r13 as u8)) {
        /* -> bb1298 */
    } else {
        /* -> bb1317 */
    }

    // ---- bb1298 @ 0x140039216 ----
    /* 140039216 */ let mut t_140039216: u8 = core::ptr::read((0x14003921d_u64).wrapping_add(0x3b441f_u64) as *const u8);
    if (t_140039216 != (r13 as u8)) {
        /* -> bb1302 */
    } else {
        /* -> bb1301 */
    }

    // ---- bb1301 @ 0x14003921d ----
    if (t_140039216 != (r13 as u8)) {
        /* -> bb1302 */
    } else {
        /* -> bb1317 */
    }

    // ---- bb1302 @ 0x14003921f ----
    /* 14003921f */ rbx = ((r13 as u32) as u64);
    /* fallthrough -> bb1303 */

    // ---- bb1303 @ 0x140039222 ----
    /* 140039222 */ rcx = (0x4_u32 as u64);
    /* 140039227 */ fn_1400c6990();
    /* 14003922c */ core::ptr::write((rdi).wrapping_add(0x225c_u64) as *mut u32, (rax as u32));
    /* 140039232 */ rax = (((rax as u32) as i64) as u64);
    /* 140039234 */ let mut t_140039234: u8 = core::ptr::read(((rax).wrapping_add((rdi).wrapping_mul(0x1_u64))).wrapping_add(0x2258_u64) as *const u8);
    if (t_140039234 == (r13 as u8)) {
        /* -> bb1311 */
    } else {
        /* -> bb1310 */
    }

    // ---- bb1310 @ 0x14003923c ----
    if (t_140039234 == (r13 as u8)) {
        /* -> bb1311 */
    } else {
        /* -> bb1316 */
    }

    // ---- bb1311 @ 0x14003923e ----
    /* 14003923e */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    if (SF == OF) {
        /* -> bb1316 */
    } else {
        /* -> bb1315 */
    }

    // ---- bb1315 @ 0x140039243 ----
    if (SF != OF) {
        /* -> bb1303 */
    } else {
        /* -> bb1316 */
    }

    // ---- bb1316 @ 0x140039245 ----
    /* 140039245 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u32, 0x3d_u32);
    /* fallthrough -> bb1317 */

    // ---- bb1317 @ 0x14003924f ----
    /* 14003924f */ let mut t_14003924f: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    /* 14003924f */ rax = (t_14003924f as u64);
    /* 140039255 */ r15 = (0x28_u32 as u64);
    if (t_140039216 == (r13 as u8)) {
        /* -> bb1323 */
    } else {
        /* -> bb1322 */
    }

    // ---- bb1322 @ 0x14003925d ----
    if (t_140039216 == (r13 as u8)) {
        /* -> bb1323 */
    } else {
        /* -> bb1942 */
    }

    // ---- bb1323 @ 0x140039263 ----
    /* 140039263 */ let mut t_140039263: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140039263 == 0x3c_u32) {
        /* -> bb1327 */
    } else {
        /* -> bb1326 */
    }

    // ---- bb1326 @ 0x14003926a ----
    if (t_140039263 == 0x3c_u32) {
        /* -> bb1327 */
    } else {
        /* -> bb1669 */
    }

    // ---- bb1327 @ 0x140039270 ----
    /* 140039270 */ let mut t_140039270: u8 = core::ptr::read((rdi).wrapping_add(0x223c_u64) as *const u8);
    /* 140039270 */ rcx = ((t_140039270 as u32) as u64);
    if (t_140039263 != 0x3c_u32) {
        /* -> bb1332 */
    } else {
        /* -> bb1331 */
    }

    // ---- bb1331 @ 0x140039279 ----
    if (t_140039263 != 0x3c_u32) {
        /* -> bb1332 */
    } else {
        /* -> bb1369 */
    }

    // ---- bb1332 @ 0x14003927f ----
    /* 14003927f */ let mut t_14003927f: u32 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u32);
    /* 14003927f */ rax = ((t_14003927f as i64) as u64);
    if (SF != OF) {
        /* -> bb1337 */
    } else {
        /* -> bb1336 */
    }

    // ---- bb1336 @ 0x140039289 ----
    if (SF != OF) {
        /* -> bb1337 */
    } else {
        /* -> bb1369 */
    }

    // ---- bb1337 @ 0x14003928b ----
    /* 14003928b */ let mut t_14003928b: u8 = core::ptr::read(((rax).wrapping_add((rdi).wrapping_mul(0x1_u64))).wrapping_add(0x2258_u64) as *const u8);
    if (t_14003928b != (r13 as u8)) {
        /* -> bb1341 */
    } else {
        /* -> bb1340 */
    }

    // ---- bb1340 @ 0x140039293 ----
    if (t_14003928b != (r13 as u8)) {
        /* -> bb1341 */
    } else {
        /* -> bb1369 */
    }

    // ---- bb1341 @ 0x140039295 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140039298 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 14003929d */ xmm1 = core::ptr::read((0x1400392a5_u64).wrapping_add(0x2cae0b_u64) as *const u128);
    /* 1400392a5 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 1400392ab */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1346 */ }
    if DF { /* -> bb1347 */ }

    // ---- bb1346 @ 0x1400392ab ----
    /* 1400392ab */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400392ab */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1348 */

    // ---- bb1347 @ 0x1400392ab ----
    /* 1400392ab */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400392ab */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1348 */

    // ---- bb1348 @ 0x1400392b3 ----
    /* 1400392b3 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1350 */ }
    if DF { /* -> bb1351 */ }

    // ---- bb1350 @ 0x1400392b3 ----
    /* 1400392b3 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400392b3 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1352 */

    // ---- bb1351 @ 0x1400392b3 ----
    /* 1400392b3 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400392b3 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1352 */

    // ---- bb1352 @ 0x1400392b9 ----
    /* 1400392b9 */ let mut t_1400392b9: u32 = core::ptr::read((0x1400392bf_u64).wrapping_add(0x2cb669_u64) as *const u32);
    /* 1400392b9 */ rax = (t_1400392b9 as u64);
    /* 1400392bf */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, (rax as u32));
    /* 1400392c3 */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u8, (r13 as u8));
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2ca488]
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 1400392d6 */ let mut t_1400392d6_0: u32 = 0x0_u32;
    /* 1400392d6 */ r9 = (t_1400392d6_0 as u64);
    /* 1400392d9 */ r8 = (rsp).wrapping_add(0x50_u64);
    /* 1400392de */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 1400392e5 */ rcx = rdi;
    /* 1400392e8 */ fn_1400d1090();
    /* 1400392ee */ rcx = (rsp).wrapping_add(0x50_u64);
    /* 1400392f3 */ fn_140027900();
    /* 1400392f8 */ let mut t_1400392f8: u32 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u32);
    /* 1400392f8 */ rax = (t_1400392f8 as u64);
    /* 1400392fe */ core::ptr::write((rdi).wrapping_add(0x225c_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb1670 */

    // ---- bb1369 @ 0x140039309 ----
    /* 140039309 */ rax = core::ptr::read((rdi).wrapping_add(0x138_u64) as *const u64);
    /* 140039310 */ let mut t_140039310: u64 = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 140039310 */ let mut t_140039310_0: u64 = (rax).wrapping_sub(t_140039310);
    /* 140039310 */ rax = t_140039310_0;
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    if CF {
        /* -> bb1376 */
    } else {
        /* -> bb1375 */
    }

    // ---- bb1375 @ 0x14003931e ----
    if CF {
        /* -> bb1376 */
    } else {
        /* -> bb1431 */
    }

    // ---- bb1376 @ 0x140039324 ----
    /* 140039324 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 14003932c */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 140039332 */ rcx = (0x20_u32 as u64);
    /* 140039337 */ fn_1400285e0();
    /* 14003933c */ rdx = rax;
    /* 14003933f */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u64, rax);
    /* 140039344 */ xmm0 = core::ptr::read((0x14003934c_u64).wrapping_add(0x2cadf4_u64) as *const u128);
    /* 14003934c */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm0);
    /* 140039352 */ xmm0 = core::ptr::read((0x140039359_u64).wrapping_add(0x2cb5d7_u64) as *const u128);
    /* 140039359 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 14003935c */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1388 */ }
    if DF { /* -> bb1389 */ }

    // ---- bb1388 @ 0x14003935c ----
    /* 14003935c */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003935c */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1390 */

    // ---- bb1389 @ 0x14003935c ----
    /* 14003935c */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003935c */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1390 */

    // ---- bb1390 @ 0x140039364 ----
    /* 140039364 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1392 */ }
    if DF { /* -> bb1393 */ }

    // ---- bb1392 @ 0x140039364 ----
    /* 140039364 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140039364 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1394 */

    // ---- bb1393 @ 0x140039364 ----
    /* 140039364 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140039364 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1394 */

    // ---- bb1394 @ 0x140039369 ----
    /* 140039369 */ let mut t_140039369: u32 = core::ptr::read((0x14003936f_u64).wrapping_add(0x2cb5d9_u64) as *const u32);
    /* 140039369 */ rcx = (t_140039369 as u64);
    /* 14003936f */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u32, (rcx as u32));
    /* 140039372 */ let mut t_140039372: u16 = core::ptr::read((0x140039379_u64).wrapping_add(0x2cb5d3_u64) as *const u16);
    /* 140039372 */ rax = ((t_140039372 as u32) as u64);
    /* 140039379 */ core::ptr::write((rdx).wrapping_add(0x1c_u64) as *mut u16, (rax as u16));
    /* 14003937d */ let mut t_14003937d: u8 = core::ptr::read((0x140039384_u64).wrapping_add(0x2cb5ca_u64) as *const u8);
    /* 14003937d */ rax = ((t_14003937d as u32) as u64);
    /* 140039384 */ core::ptr::write((rdx).wrapping_add(0x1e_u64) as *mut u8, (rax as u8));
    /* 140039387 */ core::ptr::write((rdx).wrapping_add(0x1f_u64) as *mut u8, (r13 as u8));
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2ca3c5]
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 140039399 */ let mut t_140039399_0: u32 = 0x0_u32;
    /* 140039399 */ r9 = (t_140039399_0 as u64);
    /* 14003939c */ r8 = (rsp).wrapping_add(0x50_u64);
    /* 1400393a1 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 1400393a8 */ rcx = rdi;
    /* 1400393ab */ fn_1400d1090();
    /* 1400393b1 */ rdx = core::ptr::read((rsp).wrapping_add(0x68_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1415 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1414 */ }

    // ---- bb1414 @ 0x1400393ba ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1415 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1670 */ }

    // ---- bb1415 @ 0x1400393c0 ----
    /* 1400393c0 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400393c3 */ rcx = core::ptr::read((rsp).wrapping_add(0x50_u64) as *const u64);
    /* 1400393c8 */ rax = rcx;
    if (CF == false) { /* -> bb1422 */ }
    if CF { /* -> bb1421 */ }

    // ---- bb1421 @ 0x1400393d2 ----
    if (CF == false) { /* -> bb1422 */ }
    if CF { /* -> bb1477 */ }

    // ---- bb1422 @ 0x1400393d8 ----
    /* 1400393d8 */ let mut t_1400393d8_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 1400393d8 */ rdx = t_1400393d8_0;
    /* 1400393dc */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400393e0 */ let mut t_1400393e0_0: u64 = (rax).wrapping_sub(rcx);
    /* 1400393e0 */ rax = t_1400393e0_0;
    /* 1400393e3 */ let mut t_1400393e3_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 1400393e3 */ rax = t_1400393e3_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1430 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1429 */ }

    // ---- bb1429 @ 0x1400393eb ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1430 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2776 */ }

    // ---- bb1430 @ 0x1400393f1 ----
    /* fallthrough -> bb1477 */

    // ---- bb1431 @ 0x1400393f6 ----
    if (rax != 0x8_u64) {
        /* -> bb1435 */
    } else {
        /* -> bb1434 */
    }

    // ---- bb1434 @ 0x1400393f8 ----
    if (rax != 0x8_u64) {
        /* -> bb1435 */
    } else {
        /* -> bb1479 */
    }

    // ---- bb1435 @ 0x1400393fe ----
    /* 1400393fe */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 140039403 */ xmm1 = core::ptr::read((0x14003940b_u64).wrapping_add(0x2caca5_u64) as *const u128);
    /* 14003940b */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 140039411 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1439 */ }
    if DF { /* -> bb1440 */ }

    // ---- bb1439 @ 0x140039411 ----
    /* 140039411 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140039411 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1441 */

    // ---- bb1440 @ 0x140039411 ----
    /* 140039411 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140039411 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1441 */

    // ---- bb1441 @ 0x140039419 ----
    /* 140039419 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1443 */ }
    if DF { /* -> bb1444 */ }

    // ---- bb1443 @ 0x140039419 ----
    /* 140039419 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140039419 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1445 */

    // ---- bb1444 @ 0x140039419 ----
    /* 140039419 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140039419 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1445 */

    // ---- bb1445 @ 0x14003941f ----
    /* 14003941f */ let mut t_14003941f: u32 = core::ptr::read((0x140039425_u64).wrapping_add(0x2cb503_u64) as *const u32);
    /* 14003941f */ rax = (t_14003941f as u64);
    /* 140039425 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, (rax as u32));
    /* 140039429 */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u8, (r13 as u8));
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2ca322]
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 14003943c */ let mut t_14003943c_0: u32 = 0x0_u32;
    /* 14003943c */ r9 = (t_14003943c_0 as u64);
    /* 14003943f */ r8 = (rsp).wrapping_add(0x50_u64);
    /* 140039444 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 14003944b */ rcx = rdi;
    /* 14003944e */ fn_1400d1090();
    /* 140039454 */ rdx = core::ptr::read((rsp).wrapping_add(0x68_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1462 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1461 */ }

    // ---- bb1461 @ 0x14003945d ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1462 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1670 */ }

    // ---- bb1462 @ 0x140039463 ----
    /* 140039463 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140039466 */ rcx = core::ptr::read((rsp).wrapping_add(0x50_u64) as *const u64);
    /* 14003946b */ rax = rcx;
    if (CF == false) { /* -> bb1469 */ }
    if CF { /* -> bb1468 */ }

    // ---- bb1468 @ 0x140039475 ----
    if (CF == false) { /* -> bb1469 */ }
    if CF { /* -> bb1477 */ }

    // ---- bb1469 @ 0x140039477 ----
    /* 140039477 */ let mut t_140039477_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140039477 */ rdx = t_140039477_0;
    /* 14003947b */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 14003947f */ let mut t_14003947f_0: u64 = (rax).wrapping_sub(rcx);
    /* 14003947f */ rax = t_14003947f_0;
    /* 140039482 */ let mut t_140039482_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140039482 */ rax = t_140039482_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1477 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1476 */ }

    // ---- bb1476 @ 0x14003948a ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1477 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2783 */ }

    // ---- bb1477 @ 0x140039490 ----
    /* 140039490 */ fn_1402c7498();
    /* fallthrough -> bb1670 */

    // ---- bb1479 @ 0x14003949a ----
    /* 14003949a */ let mut t_14003949a: u32 = core::ptr::read((rdi).wrapping_add(0x2240_u64) as *const u32);
    /* 14003949a */ rax = (t_14003949a as u64);
    if (rax == 0x8_u64) {
        /* -> bb1484 */
    } else {
        /* -> bb1483 */
    }

    // ---- bb1483 @ 0x1400394a2 ----
    if (rax == 0x8_u64) {
        /* -> bb1484 */
    } else {
        /* -> bb1511 */
    }

    // ---- bb1484 @ 0x1400394a4 ----
    /* 1400394a4 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 1400394a9 */ xmm1 = core::ptr::read((0x1400394b1_u64).wrapping_add(0x2cac1f_u64) as *const u128);
    /* 1400394b1 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 1400394b7 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1488 */ }
    if DF { /* -> bb1489 */ }

    // ---- bb1488 @ 0x1400394b7 ----
    /* 1400394b7 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400394b7 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1490 */

    // ---- bb1489 @ 0x1400394b7 ----
    /* 1400394b7 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400394b7 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1490 */

    // ---- bb1490 @ 0x1400394bf ----
    /* 1400394bf */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1492 */ }
    if DF { /* -> bb1493 */ }

    // ---- bb1492 @ 0x1400394bf ----
    /* 1400394bf */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400394bf */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1494 */

    // ---- bb1493 @ 0x1400394bf ----
    /* 1400394bf */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400394bf */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1494 */

    // ---- bb1494 @ 0x1400394c5 ----
    /* 1400394c5 */ let mut t_1400394c5: u32 = core::ptr::read((0x1400394cb_u64).wrapping_add(0x2cb48d_u64) as *const u32);
    /* 1400394c5 */ rax = (t_1400394c5 as u64);
    /* 1400394cb */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, (rax as u32));
    /* 1400394cf */ let mut t_1400394cf: u16 = core::ptr::read((0x1400394d6_u64).wrapping_add(0x2cb486_u64) as *const u16);
    /* 1400394cf */ rax = ((t_1400394cf as u32) as u64);
    /* 1400394d6 */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u16, (rax as u16));
    /* 1400394db */ core::ptr::write((rsp).wrapping_add(0x5e_u64) as *mut u8, (r13 as u8));
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2ca270]
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 1400394ee */ let mut t_1400394ee_0: u32 = 0x0_u32;
    /* 1400394ee */ r9 = (t_1400394ee_0 as u64);
    /* 1400394f1 */ r8 = (rsp).wrapping_add(0x50_u64);
    /* 1400394f6 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 1400394fd */ rcx = rdi;
    /* 140039500 */ fn_1400d1090();
    /* 140039506 */ rcx = (rsp).wrapping_add(0x50_u64);
    /* 14003950b */ fn_140027900();
    /* fallthrough -> bb1670 */

    // ---- bb1511 @ 0x140039515 ----
    /* 140039515 */ let mut t_140039515: u32 = core::ptr::read((rdi).wrapping_add(0x258_u64) as *const u32);
    if (t_140039515 == 0x5_u32) {
        /* -> bb1515 */
    } else {
        /* -> bb1514 */
    }

    // ---- bb1514 @ 0x14003951c ----
    if (t_140039515 == 0x5_u32) {
        /* -> bb1515 */
    } else {
        /* -> bb1611 */
    }

    // ---- bb1515 @ 0x140039522 ----
    /* 140039522 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 140039527 */ xmm1 = core::ptr::read((0x14003952f_u64).wrapping_add(0x2cb791_u64) as *const u128);
    /* 14003952f */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 140039535 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1519 */ }
    if DF { /* -> bb1520 */ }

    // ---- bb1519 @ 0x140039535 ----
    /* 140039535 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140039535 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1521 */

    // ---- bb1520 @ 0x140039535 ----
    /* 140039535 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140039535 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1521 */

    // ---- bb1521 @ 0x14003953d ----
    /* 14003953d */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1523 */ }
    if DF { /* -> bb1524 */ }

    // ---- bb1523 @ 0x14003953d ----
    /* 14003953d */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003953d */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1525 */

    // ---- bb1524 @ 0x14003953d ----
    /* 14003953d */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003953d */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1525 */

    // ---- bb1525 @ 0x140039543 ----
    /* 140039543 */ let mut t_140039543: u16 = core::ptr::read((0x14003954a_u64).wrapping_add(0x2cb41e_u64) as *const u16);
    /* 140039543 */ rax = ((t_140039543 as u32) as u64);
    /* 14003954a */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u16, (rax as u16));
    /* 14003954f */ let mut t_14003954f: u8 = core::ptr::read((0x140039556_u64).wrapping_add(0x2cb414_u64) as *const u8);
    /* 14003954f */ rax = ((t_14003954f as u32) as u64);
    /* 140039556 */ core::ptr::write((rsp).wrapping_add(0x5a_u64) as *mut u8, (rax as u8));
    /* 14003955a */ core::ptr::write((rsp).wrapping_add(0x5b_u64) as *mut u8, (r13 as u8));
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2ca1f1]
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 14003956d */ let mut t_14003956d_0: u32 = 0x0_u32;
    /* 14003956d */ r9 = (t_14003956d_0 as u64);
    /* 140039570 */ r8 = (rsp).wrapping_add(0x50_u64);
    /* 140039575 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 14003957c */ rcx = rdi;
    /* 14003957f */ fn_1400d1090();
    /* 140039585 */ rcx = (rsp).wrapping_add(0x50_u64);
    /* 14003958a */ fn_140027900();
    /* 14003958f */ let mut t_14003958f: u32 = core::ptr::read((rdi).wrapping_add(0x2260_u64) as *const u32);
    /* 14003958f */ core::ptr::write((rdi).wrapping_add(0x2260_u64) as *mut u32, (t_14003958f).wrapping_add(0x1_u32));
    /* 140039595 */ let mut t_140039595: u32 = core::ptr::read((rdi).wrapping_add(0x2260_u64) as *const u32);
    /* 140039595 */ rax = (t_140039595 as u64);
    /* 14003959b */ let mut t_14003959b_0: u32 = ((rax as u32) & 0x80000003_u32);
    /* 14003959b */ rax = (t_14003959b_0 as u64);
    if (SF != OF) {
        /* -> bb1547 */
    } else {
        /* -> bb1546 */
    }

    // ---- bb1546 @ 0x1400395a0 ----
    if (SF != OF) {
        /* -> bb1547 */
    } else {
        /* -> bb1550 */
    }

    // ---- bb1547 @ 0x1400395a2 ----
    /* 1400395a2 */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    /* 1400395a4 */ let mut t_1400395a4_0: u32 = ((rax as u32) | 0xfffffffc_u32);
    /* 1400395a4 */ rax = (t_1400395a4_0 as u64);
    /* 1400395a7 */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb1550 */

    // ---- bb1550 @ 0x1400395a9 ----
    if ((rax as u32) == 0x3_u32) {
        /* -> bb1554 */
    } else {
        /* -> bb1553 */
    }

    // ---- bb1553 @ 0x1400395ac ----
    if ((rax as u32) == 0x3_u32) {
        /* -> bb1554 */
    } else {
        /* -> bb1670 */
    }

    // ---- bb1554 @ 0x1400395b2 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400395b5 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 1400395bd */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm1);
    /* 1400395c2 */ rcx = (0x30_u32 as u64);
    /* 1400395c7 */ fn_1400285e0();
    /* 1400395cc */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rax);
    /* 1400395d1 */ xmm0 = core::ptr::read((0x1400395d9_u64).wrapping_add(0x2cb737_u64) as *const u128);
    /* 1400395d9 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm0);
    /* 1400395de */ xmm0 = core::ptr::read((0x1400395e5_u64).wrapping_add(0x2cb38b_u64) as *const u128);
    /* 1400395e5 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400395e8 */ xmm1 = core::ptr::read((0x1400395ef_u64).wrapping_add(0x2cb391_u64) as *const u128);
    /* 1400395ef */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u128, xmm1);
    /* 1400395f3 */ let mut t_1400395f3: u32 = core::ptr::read((0x1400395f9_u64).wrapping_add(0x2cb397_u64) as *const u32);
    /* 1400395f3 */ rcx = (t_1400395f3 as u64);
    /* 1400395f9 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u32, (rcx as u32));
    /* 1400395fc */ core::ptr::write((rax).wrapping_add(0x24_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 140039606 */ let mut t_140039606_0: u32 = 0x0_u32;
    /* 140039606 */ r9 = (t_140039606_0 as u64);
    /* 140039609 */ r8 = (rsp).wrapping_add(0x70_u64);
    /* 14003960e */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140039615 */ rcx = rdi;
    /* 140039618 */ fn_1400d1090();
    /* 14003961e */ rcx = (rsp).wrapping_add(0x70_u64);
    /* 140039623 */ fn_140027900();
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003962b */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 140039633 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm1);
    /* 140039638 */ rcx = (0x20_u32 as u64);
    /* 14003963d */ fn_1400285e0();
    /* 140039642 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rax);
    /* 140039647 */ xmm0 = core::ptr::read((0x14003964f_u64).wrapping_add(0x2cb691_u64) as *const u128);
    /* 14003964f */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm0);
    /* 140039654 */ xmm0 = core::ptr::read((0x14003965b_u64).wrapping_add(0x2cb33d_u64) as *const u128);
    /* 14003965b */ core::ptr::write(rax as *mut u128, xmm0);
    /* 14003965e */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1591 */ }
    if DF { /* -> bb1592 */ }

    // ---- bb1591 @ 0x14003965e ----
    /* 14003965e */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003965e */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1593 */

    // ---- bb1592 @ 0x14003965e ----
    /* 14003965e */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003965e */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1593 */

    // ---- bb1593 @ 0x140039666 ----
    /* 140039666 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1595 */ }
    if DF { /* -> bb1596 */ }

    // ---- bb1595 @ 0x140039666 ----
    /* 140039666 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140039666 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1597 */

    // ---- bb1596 @ 0x140039666 ----
    /* 140039666 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140039666 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1597 */

    // ---- bb1597 @ 0x14003966b ----
    /* 14003966b */ let mut t_14003966b: u16 = core::ptr::read((0x140039672_u64).wrapping_add(0x2cb33e_u64) as *const u16);
    /* 14003966b */ rcx = ((t_14003966b as u32) as u64);
    /* 140039672 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u16, (rcx as u16));
    /* 140039676 */ core::ptr::write((rax).wrapping_add(0x1a_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 140039680 */ let mut t_140039680_0: u32 = 0x0_u32;
    /* 140039680 */ r9 = (t_140039680_0 as u64);
    /* 140039683 */ r8 = (rsp).wrapping_add(0x70_u64);
    /* 140039688 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 14003968f */ rcx = rdi;
    /* 140039692 */ fn_1400d1090();
    /* 140039698 */ rcx = (rsp).wrapping_add(0x70_u64);
    /* 14003969d */ fn_140027900();
    /* fallthrough -> bb1670 */

    // ---- bb1611 @ 0x1400396a7 ----
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 1400396aa */ rcx = (0x20_u32 as u64);
    /* 1400396af */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u128, xmm0);
    /* 1400396b4 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm1);
    if (t_140039515 == 0x5_u32) {
        /* -> bb1619 */
    } else {
        /* -> bb1618 */
    }

    // ---- bb1618 @ 0x1400396bb ----
    if (t_140039515 == 0x5_u32) {
        /* -> bb1619 */
    } else {
        /* -> bb1647 */
    }

    // ---- bb1619 @ 0x1400396bd ----
    /* 1400396bd */ fn_1400285e0();
    /* 1400396c2 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rax);
    /* 1400396c7 */ xmm0 = core::ptr::read((0x1400396cf_u64).wrapping_add(0x2ca091_u64) as *const u128);
    /* 1400396cf */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm0);
    /* 1400396d4 */ xmm0 = core::ptr::read((0x1400396db_u64).wrapping_add(0x2cb2dd_u64) as *const u128);
    /* 1400396db */ core::ptr::write(rax as *mut u128, xmm0);
    /* 1400396de */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1626 */ }
    if DF { /* -> bb1627 */ }

    // ---- bb1626 @ 0x1400396de ----
    /* 1400396de */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400396de */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1628 */

    // ---- bb1627 @ 0x1400396de ----
    /* 1400396de */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400396de */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1628 */

    // ---- bb1628 @ 0x1400396e6 ----
    /* 1400396e6 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1630 */ }
    if DF { /* -> bb1631 */ }

    // ---- bb1630 @ 0x1400396e6 ----
    /* 1400396e6 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400396e6 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1632 */

    // ---- bb1631 @ 0x1400396e6 ----
    /* 1400396e6 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400396e6 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1632 */

    // ---- bb1632 @ 0x1400396eb ----
    /* 1400396eb */ let mut t_1400396eb: u8 = core::ptr::read((0x1400396f2_u64).wrapping_add(0x2cb2de_u64) as *const u8);
    /* 1400396eb */ rcx = ((t_1400396eb as u32) as u64);
    /* 1400396f2 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u8, (rcx as u8));
    /* 1400396f5 */ core::ptr::write((rax).wrapping_add(0x19_u64) as *mut u8, (r13 as u8));
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2ca057]
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 140039707 */ let mut t_140039707_0: u32 = 0x0_u32;
    /* 140039707 */ r9 = (t_140039707_0 as u64);
    /* 14003970a */ r8 = (rsp).wrapping_add(0x70_u64);
    /* 14003970f */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140039716 */ rcx = rdi;
    /* 140039719 */ fn_1400d1090();
    /* 14003971f */ rcx = (rsp).wrapping_add(0x70_u64);
    /* 140039724 */ fn_140027900();
    /* fallthrough -> bb1670 */

    // ---- bb1647 @ 0x14003972b ----
    /* 14003972b */ fn_1400285e0();
    /* 140039730 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rax);
    /* 140039735 */ xmm0 = core::ptr::read((0x14003973d_u64).wrapping_add(0x2ca9c3_u64) as *const u128);
    /* 14003973d */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm0);
    /* 140039742 */ xmm0 = core::ptr::read((0x140039749_u64).wrapping_add(0x2cb28f_u64) as *const u128);
    /* 140039749 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 14003974c */ let mut t_14003974c: u16 = core::ptr::read((0x140039753_u64).wrapping_add(0x2cb295_u64) as *const u16);
    /* 14003974c */ rcx = ((t_14003974c as u32) as u64);
    /* 140039753 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u16, (rcx as u16));
    /* 140039757 */ let mut t_140039757: u8 = core::ptr::read((0x14003975e_u64).wrapping_add(0x2cb28c_u64) as *const u8);
    /* 140039757 */ rcx = ((t_140039757 as u32) as u64);
    /* 14003975e */ core::ptr::write((rax).wrapping_add(0x12_u64) as *mut u8, (rcx as u8));
    /* 140039761 */ core::ptr::write((rax).wrapping_add(0x13_u64) as *mut u8, (r13 as u8));
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2c9feb]
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 140039773 */ let mut t_140039773_0: u32 = 0x0_u32;
    /* 140039773 */ r9 = (t_140039773_0 as u64);
    /* 140039776 */ r8 = (rsp).wrapping_add(0x70_u64);
    /* 14003977b */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140039782 */ rcx = rdi;
    /* 140039785 */ fn_1400d1090();
    /* 14003978b */ rcx = (rsp).wrapping_add(0x70_u64);
    /* 140039790 */ fn_140027900();
    /* fallthrough -> bb1670 */

    // ---- bb1669 @ 0x140039797 ----
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2c9fb9]
    /* fallthrough -> bb1670 */

    // ---- bb1670 @ 0x14003979f ----
    /* 14003979f */ let mut t_14003979f: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_14003979f == 0xb4_u32) {
        /* -> bb1674 */
    } else {
        /* -> bb1673 */
    }

    // ---- bb1673 @ 0x1400397a9 ----
    if (t_14003979f == 0xb4_u32) {
        /* -> bb1674 */
    } else {
        /* -> bb1807 */
    }

    // ---- bb1674 @ 0x1400397af ----
    /* 1400397af */ let mut t_1400397af: u32 = core::ptr::read((rdi).wrapping_add(0x225c_u64) as *const u32);
    if (t_1400397af != 0xffffffff_u32) {
        /* -> bb1678 */
    } else {
        /* -> bb1677 */
    }

    // ---- bb1677 @ 0x1400397b6 ----
    if (t_1400397af != 0xffffffff_u32) {
        /* -> bb1678 */
    } else {
        /* -> bb1807 */
    }

    // ---- bb1678 @ 0x1400397bc ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400397bf */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 1400397c4 */ xmm1 = core::ptr::read((0x1400397cc_u64).wrapping_add(0x2ca8d4_u64) as *const u128);
    /* 1400397cc */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 1400397d2 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1683 */ }
    if DF { /* -> bb1684 */ }

    // ---- bb1683 @ 0x1400397d2 ----
    /* 1400397d2 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400397d2 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1685 */

    // ---- bb1684 @ 0x1400397d2 ----
    /* 1400397d2 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400397d2 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1685 */

    // ---- bb1685 @ 0x1400397da ----
    /* 1400397da */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1687 */ }
    if DF { /* -> bb1688 */ }

    // ---- bb1687 @ 0x1400397da ----
    /* 1400397da */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400397da */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1689 */

    // ---- bb1688 @ 0x1400397da ----
    /* 1400397da */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400397da */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1689 */

    // ---- bb1689 @ 0x1400397e0 ----
    /* 1400397e0 */ let mut t_1400397e0: u8 = core::ptr::read((0x1400397e7_u64).wrapping_add(0x2cb211_u64) as *const u8);
    /* 1400397e0 */ rax = ((t_1400397e0 as u32) as u64);
    /* 1400397e7 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, (rax as u8));
    /* 1400397eb */ core::ptr::write((rsp).wrapping_add(0x59_u64) as *mut u8, 0x0_u8);
    /* 1400397f0 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x3634a7]
    /* 1400397fd */ let mut t_1400397fd_0: u32 = 0x0_u32;
    /* 1400397fd */ r8 = (t_1400397fd_0 as u64);
    /* 140039800 */ rdx = (0x64_u32 as u64);
    /* 140039805 */ rcx = (rsp).wrapping_add(0x50_u64);
    /* 14003980a */ fn_140040b90();
    /* 140039810 */ rdx = core::ptr::read((rsp).wrapping_add(0x68_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1705 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1704 */ }

    // ---- bb1704 @ 0x140039819 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1705 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1721 */ }

    // ---- bb1705 @ 0x14003981b ----
    /* 14003981b */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 14003981e */ rcx = core::ptr::read((rsp).wrapping_add(0x50_u64) as *const u64);
    /* 140039823 */ rax = rcx;
    if (CF == false) { /* -> bb1712 */ }
    if CF { /* -> bb1711 */ }

    // ---- bb1711 @ 0x14003982d ----
    if (CF == false) { /* -> bb1712 */ }
    if CF { /* -> bb1720 */ }

    // ---- bb1712 @ 0x14003982f ----
    /* 14003982f */ let mut t_14003982f_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 14003982f */ rdx = t_14003982f_0;
    /* 140039833 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140039837 */ let mut t_140039837_0: u64 = (rax).wrapping_sub(rcx);
    /* 140039837 */ rax = t_140039837_0;
    /* 14003983a */ let mut t_14003983a_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 14003983a */ rax = t_14003983a_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1720 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1719 */ }

    // ---- bb1719 @ 0x140039842 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1720 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2790 */ }

    // ---- bb1720 @ 0x140039848 ----
    /* 140039848 */ fn_1402c7498();
    /* fallthrough -> bb1721 */

    // ---- bb1721 @ 0x14003984d ----
    /* 14003984d */ let mut t_14003984d: u32 = core::ptr::read((rdi).wrapping_add(0x225c_u64) as *const u32);
    /* 14003984d */ rax = ((t_14003984d as i64) as u64);
    /* 140039854 */ core::ptr::write(((rax).wrapping_add((rdi).wrapping_mul(0x1_u64))).wrapping_add(0x2258_u64) as *mut u8, 0x0_u8);
    /* 14003985c */ core::ptr::write((rdi).wrapping_add(0x225c_u64) as *mut u32, 0xffffffff_u32);
    /* 140039866 */ rax = ((r13 as u32) as u64);
    /* 140039869 */ let mut t_140039869: u8 = core::ptr::read((rdi).wrapping_add(0x2258_u64) as *const u8);
    /* 140039870 */ rax = ((rax & 0xffffffffffffff00_u64) | (((ZF == false) as u8) as u64));
    /* 140039873 */ rcx = (((rax).wrapping_add(0x1_u64) as u32) as u64);
    /* 140039876 */ let mut t_140039876: u8 = core::ptr::read((rdi).wrapping_add(0x2259_u64) as *const u8);
    if (t_140039876 != 0x0_u8) {
        /* -> bb1730 */
    } else {
        /* -> bb1731 */
    }

    // ---- bb1731 @ 0x14003987d ----
    /* 14003987d */ rcx = ((rax as u32) as u64);
    /* fallthrough -> bb1730 */

    // ---- bb1730 @ 0x140039880 ----
    /* 140039880 */ rdx = (((rcx).wrapping_add(0x1_u64) as u32) as u64);
    /* 140039883 */ let mut t_140039883: u8 = core::ptr::read((rdi).wrapping_add(0x225a_u64) as *const u8);
    if (t_140039883 != 0x0_u8) {
        /* -> bb1735 */
    } else {
        /* -> bb1736 */
    }

    // ---- bb1736 @ 0x14003988a ----
    /* 14003988a */ rdx = ((rcx as u32) as u64);
    /* fallthrough -> bb1735 */

    // ---- bb1735 @ 0x14003988d ----
    /* 14003988d */ rax = (((rdx).wrapping_add(0x1_u64) as u32) as u64);
    /* 140039890 */ let mut t_140039890: u8 = core::ptr::read((rdi).wrapping_add(0x225b_u64) as *const u8);
    if (t_140039890 != 0x0_u8) {
        /* -> bb1740 */
    } else {
        /* -> bb1741 */
    }

    // ---- bb1741 @ 0x140039897 ----
    /* 140039897 */ rax = ((rdx as u32) as u64);
    /* fallthrough -> bb1740 */

    // ---- bb1740 @ 0x14003989a ----
    if (t_140039890 == 0x0_u8) {
        /* -> bb1746 */
    } else {
        /* -> bb1745 */
    }

    // ---- bb1745 @ 0x14003989c ----
    if (t_140039890 == 0x0_u8) {
        /* -> bb1746 */
    } else {
        /* -> bb1807 */
    }

    // ---- bb1746 @ 0x1400398a2 ----
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2cb366]
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2cb396]
    // intrinsic: 0f14c100 unpcklps xmm0, xmm1
    /* 1400398b5 */ r8 = (xmm0 as u64);
    /* 1400398ba */ rdx = (0x8_u32 as u64);
    /* 1400398bf */ rcx = rdi;
    /* 1400398c2 */ fn_1400cbcd0();
    /* 1400398c7 */ core::ptr::write((rdi).wrapping_add(0x2258_u64) as *mut u32, 0x1010101_u32);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400398d4 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 1400398dc */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 1400398e2 */ rcx = (0x20_u32 as u64);
    /* 1400398e7 */ fn_1400285e0();
    /* 1400398ec */ rdx = rax;
    /* 1400398ef */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u64, rax);
    /* 1400398f4 */ xmm0 = core::ptr::read((0x1400398fc_u64).wrapping_add(0x2ca834_u64) as *const u128);
    /* 1400398fc */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm0);
    /* 140039902 */ xmm0 = core::ptr::read((0x140039909_u64).wrapping_add(0x2cb0f7_u64) as *const u128);
    /* 140039909 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 14003990c */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb1767 */ }
    if DF { /* -> bb1768 */ }

    // ---- bb1767 @ 0x14003990c ----
    /* 14003990c */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003990c */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb1769 */

    // ---- bb1768 @ 0x14003990c ----
    /* 14003990c */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003990c */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb1769 */

    // ---- bb1769 @ 0x140039914 ----
    /* 140039914 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb1771 */ }
    if DF { /* -> bb1772 */ }

    // ---- bb1771 @ 0x140039914 ----
    /* 140039914 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140039914 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb1773 */

    // ---- bb1772 @ 0x140039914 ----
    /* 140039914 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140039914 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb1773 */

    // ---- bb1773 @ 0x140039919 ----
    /* 140039919 */ let mut t_140039919: u16 = core::ptr::read((0x140039920_u64).wrapping_add(0x2cb0f8_u64) as *const u16);
    /* 140039919 */ rcx = ((t_140039919 as u32) as u64);
    /* 140039920 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u16, (rcx as u16));
    /* 140039924 */ let mut t_140039924: u8 = core::ptr::read((0x14003992b_u64).wrapping_add(0x2cb0ef_u64) as *const u8);
    /* 140039924 */ rax = ((t_140039924 as u32) as u64);
    /* 14003992b */ core::ptr::write((rdx).wrapping_add(0x1a_u64) as *mut u8, (rax as u8));
    /* 14003992e */ core::ptr::write((rdx).wrapping_add(0x1b_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x20], xmm6
    /* 140039938 */ let mut t_140039938_0: u32 = 0x0_u32;
    /* 140039938 */ r9 = (t_140039938_0 as u64);
    /* 14003993b */ r8 = (rsp).wrapping_add(0x50_u64);
    /* 140039940 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 140039947 */ rcx = rdi;
    /* 14003994a */ fn_1400d1090();
    /* 140039950 */ rdx = core::ptr::read((rsp).wrapping_add(0x68_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1791 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1790 */ }

    // ---- bb1790 @ 0x140039959 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1791 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1807 */ }

    // ---- bb1791 @ 0x14003995b ----
    /* 14003995b */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 14003995e */ rcx = core::ptr::read((rsp).wrapping_add(0x50_u64) as *const u64);
    /* 140039963 */ rax = rcx;
    if (CF == false) { /* -> bb1798 */ }
    if CF { /* -> bb1797 */ }

    // ---- bb1797 @ 0x14003996d ----
    if (CF == false) { /* -> bb1798 */ }
    if CF { /* -> bb1806 */ }

    // ---- bb1798 @ 0x14003996f ----
    /* 14003996f */ let mut t_14003996f_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 14003996f */ rdx = t_14003996f_0;
    /* 140039973 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140039977 */ let mut t_140039977_0: u64 = (rax).wrapping_sub(rcx);
    /* 140039977 */ rax = t_140039977_0;
    /* 14003997a */ let mut t_14003997a_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 14003997a */ rax = t_14003997a_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1806 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1805 */ }

    // ---- bb1805 @ 0x140039982 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1806 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2797 */ }

    // ---- bb1806 @ 0x140039988 ----
    /* 140039988 */ fn_1402c7498();
    /* fallthrough -> bb1807 */

    // ---- bb1807 @ 0x14003998d ----
    /* 14003998d */ let mut t_14003998d: u32 = core::ptr::read((rdi).wrapping_add(0x1b0_u64) as *const u32);
    if (t_14003998d == 0x2_u32) {
        /* -> bb1811 */
    } else {
        /* -> bb1810 */
    }

    // ---- bb1810 @ 0x140039994 ----
    if (t_14003998d == 0x2_u32) {
        /* -> bb1811 */
    } else {
        /* -> bb2570 */
    }

    // ---- bb1811 @ 0x14003999a ----
    /* 14003999a */ let mut t_14003999a: u32 = core::ptr::read((rdi).wrapping_add(0x1b4_u64) as *const u32);
    if (t_14003999a == 0x1_u32) {
        /* -> bb1815 */
    } else {
        /* -> bb1814 */
    }

    // ---- bb1814 @ 0x1400399a1 ----
    if (t_14003999a == 0x1_u32) {
        /* -> bb1815 */
    } else {
        /* -> bb2570 */
    }

    // ---- bb1815 @ 0x1400399a7 ----
    /* 1400399a7 */ rbx = core::ptr::read((rdi).wrapping_add(0x268_u64) as *const u64);
    if (t_14003999a != 0x1_u32) {
        /* -> bb1820 */
    } else {
        /* -> bb1819 */
    }

    // ---- bb1819 @ 0x1400399b1 ----
    if (t_14003999a != 0x1_u32) {
        /* -> bb1820 */
    } else {
        /* -> bb1823 */
    }

    // ---- bb1820 @ 0x1400399b3 ----
    /* 1400399b3 */ core::ptr::write((rbp).wrapping_add(0x98_u64) as *mut u64, rbx);
    /* 1400399ba */ core::ptr::write((rdi).wrapping_add(0x268_u64) as *mut u64, r13);
    /* fallthrough -> bb1874 */

    // ---- bb1823 @ 0x1400399c6 ----
    /* 1400399c6 */ rcx = (0x498_u32 as u64);
    /* 1400399cb */ fn_1402c745c();
    /* 1400399d0 */ core::ptr::write((rbp).wrapping_add(0x90_u64) as *mut u64, rax);
    if (t_14003999a != 0x1_u32) {
        /* -> bb1830 */
    } else {
        /* -> bb1829 */
    }

    // ---- bb1829 @ 0x1400399da ----
    if (t_14003999a != 0x1_u32) {
        /* -> bb1830 */
    } else {
        /* -> bb1834 */
    }

    // ---- bb1830 @ 0x1400399dc ----
    /* 1400399dc */ rcx = rax;
    /* 1400399df */ fn_1400aac50();
    /* 1400399e4 */ rbx = rax;
    /* fallthrough -> bb1835 */

    // ---- bb1834 @ 0x1400399e9 ----
    /* 1400399e9 */ rbx = r13;
    /* fallthrough -> bb1835 */

    // ---- bb1835 @ 0x1400399ec ----
    /* 1400399ec */ core::ptr::write((rbp).wrapping_add(0x98_u64) as *mut u64, rbx);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 1400399f6 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 1400399fb */ xmm1 = core::ptr::read((0x140039a03_u64).wrapping_add(0x2ca67d_u64) as *const u128);
    /* 140039a03 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 140039a09 */ let mut t_140039a09: u32 = core::ptr::read((0x140039a0f_u64).wrapping_add(0x2ca121_u64) as *const u32);
    /* 140039a09 */ rax = (t_140039a09 as u64);
    /* 140039a0f */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u32, (rax as u32));
    /* 140039a13 */ let mut t_140039a13: u8 = core::ptr::read((0x140039a1a_u64).wrapping_add(0x2ca11a_u64) as *const u8);
    /* 140039a13 */ rax = ((t_140039a13 as u32) as u64);
    /* 140039a1a */ core::ptr::write((rsp).wrapping_add(0x54_u64) as *mut u8, (rax as u8));
    /* 140039a1e */ core::ptr::write((rsp).wrapping_add(0x55_u64) as *mut u8, 0x0_u8);
    /* 140039a23 */ r9 = (0xffffffff_u32 as u64);
    /* 140039a29 */ r8 = (0x1_u32 as u64);
    /* 140039a2f */ rdx = (rsp).wrapping_add(0x50_u64);
    /* 140039a34 */ rcx = rbx;
    /* 140039a37 */ fn_1400b2ed0();
    /* 140039a3d */ rsi = rbx;
    /* 140039a40 */ r14 = rbx;
    /* 140039a43 */ rdx = core::ptr::read((rsp).wrapping_add(0x68_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1858 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1857 */ }

    // ---- bb1857 @ 0x140039a4c ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1858 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1876 */ }

    // ---- bb1858 @ 0x140039a4e ----
    /* 140039a4e */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140039a51 */ rcx = core::ptr::read((rsp).wrapping_add(0x50_u64) as *const u64);
    /* 140039a56 */ rax = rcx;
    if (CF == false) { /* -> bb1865 */ }
    if CF { /* -> bb1864 */ }

    // ---- bb1864 @ 0x140039a60 ----
    if (CF == false) { /* -> bb1865 */ }
    if CF { /* -> bb1873 */ }

    // ---- bb1865 @ 0x140039a62 ----
    /* 140039a62 */ let mut t_140039a62_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140039a62 */ rdx = t_140039a62_0;
    /* 140039a66 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140039a6a */ let mut t_140039a6a_0: u64 = (rax).wrapping_sub(rcx);
    /* 140039a6a */ rax = t_140039a6a_0;
    /* 140039a6d */ let mut t_140039a6d_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140039a6d */ rax = t_140039a6d_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1873 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1872 */ }

    // ---- bb1872 @ 0x140039a75 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1873 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2804 */ }

    // ---- bb1873 @ 0x140039a7b ----
    /* 140039a7b */ fn_1402c7498();
    /* fallthrough -> bb1874 */

    // ---- bb1874 @ 0x140039a80 ----
    /* 140039a80 */ r14 = rbx;
    /* 140039a83 */ rsi = rbx;
    /* fallthrough -> bb1876 */

    // ---- bb1876 @ 0x140039a86 ----
    /* 140039a86 */ rax = core::ptr::read((rdi).wrapping_add(0x60_u64) as *const u64);
    // intrinsic: f30f1090 movss xmm2, dword ptr [rax + 0x2b0]
    // intrinsic: f30f5915 mulss xmm2, dword ptr [rip + 0x3631fa]
    // intrinsic: f30f5890 addss xmm2, dword ptr [rax + 0x2a8]
    // intrinsic: f30f1088 movss xmm1, dword ptr [rax + 0x2ac]
    // intrinsic: f30f590d mulss xmm1, dword ptr [rip + 0x3631e2]
    // intrinsic: f30f5888 addss xmm1, dword ptr [rax + 0x2a4]
    // intrinsic: f30f590d mulss xmm1, dword ptr [rip + 0x2c9892]
    // intrinsic: f30f118d movss dword ptr [rbp + 0x90], xmm1
    // intrinsic: f30f5915 mulss xmm2, dword ptr [rip + 0x2c9882]
    // intrinsic: f30f1195 movss dword ptr [rbp + 0x94], xmm2
    /* 140039ada */ rdx = (rbp).wrapping_add(0x90_u64);
    /* 140039ae1 */ rcx = rbx;
    /* 140039ae4 */ fn_1400b6600();
    /* 140039ae9 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, 0xffffffff_u32);
    /* 140039af1 */ r9 = (0xffffffff_u32 as u64);
    /* 140039af7 */ let mut t_140039af7_0: u32 = 0x0_u32;
    /* 140039af7 */ r8 = (t_140039af7_0 as u64);
    /* 140039afa */ let mut t_140039afa_0: u32 = 0x0_u32;
    /* 140039afa */ rdx = (t_140039afa_0 as u64);
    /* 140039afc */ let mut t_140039afc_0: u32 = 0x0_u32;
    /* 140039afc */ rcx = (t_140039afc_0 as u64);
    /* 140039afe */ fn_1400c7a10();
    /* 140039b03 */ core::ptr::write((rsi).wrapping_add(0x1f8_u64) as *mut u32, (rax as u32));
    /* 140039b09 */ core::ptr::write((r14).wrapping_add(0x204_u64) as *mut u8, 0x1_u8);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140039b14 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 140039b19 */ xmm1 = core::ptr::read((0x140039b21_u64).wrapping_add(0x2ca55f_u64) as *const u128);
    /* 140039b21 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 140039b27 */ let mut t_140039b27: u32 = core::ptr::read((0x140039b2d_u64).wrapping_add(0x2cade7_u64) as *const u32);
    /* 140039b27 */ rax = (t_140039b27 as u64);
    /* 140039b2d */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u32, (rax as u32));
    /* 140039b31 */ let mut t_140039b31: u8 = core::ptr::read((0x140039b38_u64).wrapping_add(0x2cade0_u64) as *const u8);
    /* 140039b31 */ rax = ((t_140039b31 as u32) as u64);
    /* 140039b38 */ core::ptr::write((rsp).wrapping_add(0x54_u64) as *mut u8, (rax as u8));
    /* 140039b3c */ core::ptr::write((rsp).wrapping_add(0x55_u64) as *mut u8, 0x0_u8);
    /* 140039b41 */ r8 = (rsp).wrapping_add(0x50_u64);
    /* 140039b46 */ rdx = rbx;
    /* 140039b49 */ rcx = rdi;
    /* 140039b4c */ fn_1400cfd60();
    /* 140039b52 */ rdx = core::ptr::read((rsp).wrapping_add(0x68_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1917 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1916 */ }

    // ---- bb1916 @ 0x140039b5b ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1917 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1933 */ }

    // ---- bb1917 @ 0x140039b5d ----
    /* 140039b5d */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140039b60 */ rcx = core::ptr::read((rsp).wrapping_add(0x50_u64) as *const u64);
    /* 140039b65 */ rax = rcx;
    if (CF == false) { /* -> bb1924 */ }
    if CF { /* -> bb1923 */ }

    // ---- bb1923 @ 0x140039b6f ----
    if (CF == false) { /* -> bb1924 */ }
    if CF { /* -> bb1932 */ }

    // ---- bb1924 @ 0x140039b71 ----
    /* 140039b71 */ let mut t_140039b71_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140039b71 */ rdx = t_140039b71_0;
    /* 140039b75 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140039b79 */ let mut t_140039b79_0: u64 = (rax).wrapping_sub(rcx);
    /* 140039b79 */ rax = t_140039b79_0;
    /* 140039b7c */ let mut t_140039b7c_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140039b7c */ rax = t_140039b7c_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1932 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1931 */ }

    // ---- bb1931 @ 0x140039b84 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1932 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2811 */ }

    // ---- bb1932 @ 0x140039b8a ----
    /* 140039b8a */ fn_1402c7498();
    /* fallthrough -> bb1933 */

    // ---- bb1933 @ 0x140039b8f ----
    /* 140039b8f */ rcx = (rdi).wrapping_add(0x130_u64);
    /* 140039b96 */ rdx = (rbp).wrapping_add(0x98_u64);
    /* 140039b9d */ fn_14003e600();
    /* 140039ba2 */ rdx = rbx;
    /* 140039ba5 */ rcx = rdi;
    /* 140039ba8 */ fn_1400ceee0();
    /* 140039bad */ rcx = rbx;
    /* 140039bb0 */ fn_1400b87d0();
    /* fallthrough -> bb2570 */

    // ---- bb1942 @ 0x140039bba ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb1946 */
    } else {
        /* -> bb1945 */
    }

    // ---- bb1945 @ 0x140039bbd ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb1946 */
    } else {
        /* -> bb1993 */
    }

    // ---- bb1946 @ 0x140039bc3 ----
    /* 140039bc3 */ let mut t_140039bc3: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140039bc3 == 0x2d_u32) {
        /* -> bb1950 */
    } else {
        /* -> bb1949 */
    }

    // ---- bb1949 @ 0x140039bca ----
    if (t_140039bc3 == 0x2d_u32) {
        /* -> bb1950 */
    } else {
        /* -> bb1985 */
    }

    // ---- bb1950 @ 0x140039bd0 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140039bd3 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 140039bd8 */ xmm1 = core::ptr::read((0x140039be0_u64).wrapping_add(0x2ca4b0_u64) as *const u128);
    /* 140039be0 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 140039be6 */ rax = 0x6c6c6f726d757244_u64;
    /* 140039bf0 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u64, rax);
    /* 140039bf5 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, (r13 as u8));
    /* 140039bfa */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x36309d]
    /* 140039c07 */ let mut t_140039c07_0: u32 = 0x0_u32;
    /* 140039c07 */ r8 = (t_140039c07_0 as u64);
    /* 140039c0a */ rdx = (0x64_u32 as u64);
    /* 140039c0f */ rcx = (rsp).wrapping_add(0x50_u64);
    /* 140039c14 */ fn_140040b90();
    /* 140039c1a */ rdx = core::ptr::read((rsp).wrapping_add(0x68_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1969 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1968 */ }

    // ---- bb1968 @ 0x140039c23 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb1969 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb1985 */ }

    // ---- bb1969 @ 0x140039c25 ----
    /* 140039c25 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140039c28 */ rcx = core::ptr::read((rsp).wrapping_add(0x50_u64) as *const u64);
    /* 140039c2d */ rax = rcx;
    if (CF == false) { /* -> bb1976 */ }
    if CF { /* -> bb1975 */ }

    // ---- bb1975 @ 0x140039c37 ----
    if (CF == false) { /* -> bb1976 */ }
    if CF { /* -> bb1984 */ }

    // ---- bb1976 @ 0x140039c39 ----
    /* 140039c39 */ let mut t_140039c39_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140039c39 */ rdx = t_140039c39_0;
    /* 140039c3d */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140039c41 */ let mut t_140039c41_0: u64 = (rax).wrapping_sub(rcx);
    /* 140039c41 */ rax = t_140039c41_0;
    /* 140039c44 */ let mut t_140039c44_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140039c44 */ rax = t_140039c44_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1984 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb1983 */ }

    // ---- bb1983 @ 0x140039c4c ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb1984 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2818 */ }

    // ---- bb1984 @ 0x140039c52 ----
    /* 140039c52 */ fn_1402c7498();
    /* fallthrough -> bb1985 */

    // ---- bb1985 @ 0x140039c57 ----
    /* 140039c57 */ let mut t_140039c57: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140039c57 == 0x3c_u32) {
        /* -> bb1989 */
    } else {
        /* -> bb1988 */
    }

    // ---- bb1988 @ 0x140039c5e ----
    if (t_140039c57 == 0x3c_u32) {
        /* -> bb1989 */
    } else {
        /* -> bb2570 */
    }

    // ---- bb1989 @ 0x140039c64 ----
    /* 140039c64 */ core::ptr::write((rdi).wrapping_add(0x1f8_u64) as *mut u32, (r13 as u32));
    /* 140039c6b */ core::ptr::write((rdi).wrapping_add(0x110_u64) as *mut u32, 0xc1400000_u32);
    /* 140039c75 */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, 0x2_u32);
    /* fallthrough -> bb2569 */

    // ---- bb1993 @ 0x140039c84 ----
    if ((rax as u32) == 0x2_u32) {
        /* -> bb1997 */
    } else {
        /* -> bb1996 */
    }

    // ---- bb1996 @ 0x140039c87 ----
    if ((rax as u32) == 0x2_u32) {
        /* -> bb1997 */
    } else {
        /* -> bb2040 */
    }

    // ---- bb1997 @ 0x140039c8d ----
    /* 140039c8d */ let mut t_140039c8d: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140039c8d == 0x3c_u32) {
        /* -> bb2001 */
    } else {
        /* -> bb2000 */
    }

    // ---- bb2000 @ 0x140039c94 ----
    if (t_140039c8d == 0x3c_u32) {
        /* -> bb2001 */
    } else {
        /* -> bb2570 */
    }

    // ---- bb2001 @ 0x140039c9a ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140039c9d */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 140039ca2 */ xmm1 = core::ptr::read((0x140039caa_u64).wrapping_add(0x2ca3e6_u64) as *const u128);
    /* 140039caa */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 140039cb0 */ rax = 0x6e4f73746867694c_u64;
    /* 140039cba */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u64, rax);
    /* 140039cbf */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u8, (r13 as u8));
    /* 140039cc4 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x362fd3]
    /* 140039cd1 */ let mut t_140039cd1_0: u32 = 0x0_u32;
    /* 140039cd1 */ r8 = (t_140039cd1_0 as u64);
    /* 140039cd4 */ rdx = (0x64_u32 as u64);
    /* 140039cd9 */ rcx = (rsp).wrapping_add(0x50_u64);
    /* 140039cde */ fn_140040b90();
    /* 140039ce4 */ rdx = core::ptr::read((rsp).wrapping_add(0x68_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2020 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2019 */ }

    // ---- bb2019 @ 0x140039ced ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2020 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2036 */ }

    // ---- bb2020 @ 0x140039cef ----
    /* 140039cef */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140039cf2 */ rcx = core::ptr::read((rsp).wrapping_add(0x50_u64) as *const u64);
    /* 140039cf7 */ rax = rcx;
    if (CF == false) { /* -> bb2027 */ }
    if CF { /* -> bb2026 */ }

    // ---- bb2026 @ 0x140039d01 ----
    if (CF == false) { /* -> bb2027 */ }
    if CF { /* -> bb2035 */ }

    // ---- bb2027 @ 0x140039d03 ----
    /* 140039d03 */ let mut t_140039d03_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 140039d03 */ rdx = t_140039d03_0;
    /* 140039d07 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140039d0b */ let mut t_140039d0b_0: u64 = (rax).wrapping_sub(rcx);
    /* 140039d0b */ rax = t_140039d0b_0;
    /* 140039d0e */ let mut t_140039d0e_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 140039d0e */ rax = t_140039d0e_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2035 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2034 */ }

    // ---- bb2034 @ 0x140039d16 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2035 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2825 */ }

    // ---- bb2035 @ 0x140039d1c ----
    /* 140039d1c */ fn_1402c7498();
    /* fallthrough -> bb2036 */

    // ---- bb2036 @ 0x140039d21 ----
    /* 140039d21 */ rcx = rdi;
    /* 140039d24 */ fn_14003c8c0();
    /* 140039d29 */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, 0x3_u32);
    /* fallthrough -> bb2569 */

    // ---- bb2040 @ 0x140039d38 ----
    if (SF != OF) {
        /* -> bb2044 */
    } else {
        /* -> bb2043 */
    }

    // ---- bb2043 @ 0x140039d3b ----
    if (SF != OF) {
        /* -> bb2044 */
    } else {
        /* -> bb2047 */
    }

    // ---- bb2044 @ 0x140039d3d ----
    /* 140039d3d */ rcx = rdi;
    /* 140039d40 */ fn_14003d890();
    /* fallthrough -> bb2570 */

    // ---- bb2047 @ 0x140039d4a ----
    if ((rax as u32) == 0x6_u32) {
        /* -> bb2050 */
    } else {
        /* -> bb2049 */
    }

    // ---- bb2049 @ 0x140039d4a ----
    if ((rax as u32) == 0x6_u32) {
        /* -> bb2050 */
    } else {
        /* -> bb2283 */
    }

    // ---- bb2050 @ 0x140039d50 ----
    // intrinsic: f3440f10 movss xmm12, dword ptr [rip + 0x362f4b]
    /* 140039d59 */ let mut t_140039d59: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140039d59 == 0x1_u32) {
        /* -> bb2055 */
    } else {
        /* -> bb2054 */
    }

    // ---- bb2054 @ 0x140039d60 ----
    if (t_140039d59 == 0x1_u32) {
        /* -> bb2055 */
    } else {
        /* -> bb2072 */
    }

    // ---- bb2055 @ 0x140039d62 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140039d65 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u128, xmm0);
    /* 140039d6a */ xmm1 = core::ptr::read((0x140039d72_u64).wrapping_add(0x2ca31e_u64) as *const u128);
    /* 140039d72 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm1);
    /* 140039d77 */ rax = 0x676e697070616c43_u64;
    /* 140039d81 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rax);
    /* 140039d86 */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u8, (r13 as u8));
    /* 140039d8b */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 140039d90 */ xmm3 = xmm12;
    /* 140039d94 */ let mut t_140039d94_0: u32 = 0x0_u32;
    /* 140039d94 */ r8 = (t_140039d94_0 as u64);
    /* 140039d97 */ rdx = (0x64_u32 as u64);
    /* 140039d9c */ rcx = (rsp).wrapping_add(0x70_u64);
    /* 140039da1 */ fn_140040b90();
    /* 140039da7 */ rcx = (rsp).wrapping_add(0x70_u64);
    /* 140039dac */ fn_140027900();
    /* 140039db1 */ fn_14003f5e0();
    /* fallthrough -> bb2072 */

    // ---- bb2072 @ 0x140039db6 ----
    /* 140039db6 */ rcx = (0x140039dbd_u64).wrapping_sub(0x39dbd_u64);
    /* 140039dbd */ let mut t_140039dbd: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_140039dbd == 0x3c_u32) {
        /* -> bb2077 */
    } else {
        /* -> bb2076 */
    }

    // ---- bb2076 @ 0x140039dc4 ----
    if (t_140039dbd == 0x3c_u32) {
        /* -> bb2077 */
    } else {
        /* -> bb2267 */
    }

    // ---- bb2077 @ 0x140039dca ----
    /* 140039dca */ let mut t_140039dca: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 140039dca */ rax = ((t_140039dca as i64) as u64);
    /* 140039dd1 */ let mut t_140039dd1: u32 = core::ptr::read(((rcx).wrapping_add((rax).wrapping_mul(0x4_u64))).wrapping_add(0x304638_u64) as *const u32);
    /* 140039dd1 */ r8 = (t_140039dd1 as u64);
    /* 140039dd9 */ let mut t_140039dd9_0: u32 = ((r8 as u32)).wrapping_add(0xffffff8d_u32);
    /* 140039dd9 */ r8 = (t_140039dd9_0 as u64);
    /* 140039ddd */ rax = (0x51eb851f_u32 as u64);
    /* 140039de2 */ let mut t_140039de2_0: u64 = (((rax as u32) as u64)).wrapping_mul(((r8 as u32) as u64));
    /* 140039de2 */ rdx = (((t_140039de2_0 >> 0x20_u64) as u32) as u64);
    /* 140039de2 */ rax = ((t_140039de2_0 as u32) as u64);
    /* 140039de5 */ rdx = (((((rdx as u32) as i64) >> ((0x4_u8 as u32) as i64)) as u64) as u64);
    /* 140039de8 */ rax = ((rdx as u32) as u64);
    /* 140039dea */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140039ded */ let mut t_140039ded_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 140039ded */ rdx = (t_140039ded_0 as u64);
    /* 140039def */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u32, (rdx as u32));
    /* 140039df3 */ let mut t_140039df3_0: u64 = (((rdx as u32) as u64)).wrapping_mul((0x32_u32 as u64));
    /* 140039df3 */ rax = ((t_140039df3_0 as u32) as u64);
    /* 140039df6 */ let mut t_140039df6_0: u32 = ((r8 as u32)).wrapping_sub((rax as u32));
    /* 140039df6 */ r8 = (t_140039df6_0 as u64);
    /* 140039df9 */ rax = (0x66666667_u32 as u64);
    /* 140039dfe */ let mut t_140039dfe_0: u64 = (((rax as u32) as u64)).wrapping_mul(((r8 as u32) as u64));
    /* 140039dfe */ rdx = (((t_140039dfe_0 >> 0x20_u64) as u32) as u64);
    /* 140039dfe */ rax = ((t_140039dfe_0 as u32) as u64);
    /* 140039e01 */ rdx = (((((rdx as u32) as i64) >> ((0x3_u8 as u32) as i64)) as u64) as u64);
    /* 140039e04 */ rax = ((rdx as u32) as u64);
    /* 140039e06 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140039e09 */ let mut t_140039e09_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 140039e09 */ rdx = (t_140039e09_0 as u64);
    /* 140039e0b */ rax = (((rdx).wrapping_add(0x2_u64) as u32) as u64);
    /* 140039e0e */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, (rax as u32));
    /* 140039e12 */ rax = (((rdx).wrapping_add((rdx).wrapping_mul(0x4_u64)) as u32) as u64);
    /* 140039e15 */ rax = (((rax as u32) << (0x2_u8 as u32)) as u64);
    /* 140039e18 */ let mut t_140039e18_0: u32 = ((r8 as u32)).wrapping_sub((rax as u32));
    /* 140039e18 */ r8 = (t_140039e18_0 as u64);
    /* 140039e1b */ rax = (0x66666667_u32 as u64);
    /* 140039e20 */ let mut t_140039e20_0: u64 = (((rax as u32) as u64)).wrapping_mul(((r8 as u32) as u64));
    /* 140039e20 */ rdx = (((t_140039e20_0 >> 0x20_u64) as u32) as u64);
    /* 140039e20 */ rax = ((t_140039e20_0 as u32) as u64);
    /* 140039e23 */ rdx = (((((rdx as u32) as i64) >> ((0x2_u8 as u32) as i64)) as u64) as u64);
    /* 140039e26 */ rcx = ((rdx as u32) as u64);
    /* 140039e28 */ rcx = (((rcx as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140039e2b */ let mut t_140039e2b_0: u32 = ((rdx as u32)).wrapping_add((rcx as u32));
    /* 140039e2b */ rdx = (t_140039e2b_0 as u64);
    /* 140039e2d */ rcx = (((rdx).wrapping_add(0x5_u64) as u32) as u64);
    /* 140039e30 */ core::ptr::write((rsp).wrapping_add(0x54_u64) as *mut u32, (rcx as u32));
    /* 140039e34 */ rcx = (((rdx).wrapping_add((rdx).wrapping_mul(0x4_u64)) as u32) as u64);
    /* 140039e37 */ let mut t_140039e37_0: u32 = ((rcx as u32)).wrapping_add((rcx as u32));
    /* 140039e37 */ rcx = (t_140039e37_0 as u64);
    /* 140039e39 */ let mut t_140039e39_0: u32 = ((r8 as u32)).wrapping_sub((rcx as u32));
    /* 140039e39 */ r8 = (t_140039e39_0 as u64);
    /* 140039e3c */ rax = (0x66666667_u32 as u64);
    /* 140039e41 */ let mut t_140039e41_0: u64 = (((rax as u32) as u64)).wrapping_mul(((r8 as u32) as u64));
    /* 140039e41 */ rdx = (((t_140039e41_0 >> 0x20_u64) as u32) as u64);
    /* 140039e41 */ rax = ((t_140039e41_0 as u32) as u64);
    /* 140039e44 */ rdx = (((((rdx as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 140039e46 */ rax = ((rdx as u32) as u64);
    /* 140039e48 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140039e4b */ let mut t_140039e4b_0: u32 = ((rdx as u32)).wrapping_add(0x5_u32);
    /* 140039e4b */ rdx = (t_140039e4b_0 as u64);
    /* 140039e4e */ let mut t_140039e4e_0: u32 = ((rax as u32)).wrapping_add((rdx as u32));
    /* 140039e4e */ rax = (t_140039e4e_0 as u64);
    /* 140039e50 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u32, (rax as u32));
    /* 140039e54 */ let mut t_140039e54: u32 = core::ptr::read((0x140039e5a_u64).wrapping_add(0x3c48d6_u64) as *const u32);
    /* 140039e54 */ rcx = (t_140039e54 as u64);
    /* 140039e5a */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 140039e63 */ rdx = (0x4_u32 as u64);
    /* 140039e68 */ rax = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 140039e6c */ let mut t_140039e6c: u32 = core::ptr::read((rdx).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 140039e6c */ rax = (t_140039e6c as u64);
    /* 140039e6f */ let mut t_140039e6f: u32 = core::ptr::read((0x140039e75_u64).wrapping_add(0x3b031f_u64) as *const u32);
    if (((SF == OF) & (t_140039e6f != (rax as u32))) == false) { /* -> bb2128 */ }
    if (((SF == OF) & (t_140039e6f != (rax as u32))) != 0) { /* -> bb2127 */ }

    // ---- bb2127 @ 0x140039e75 ----
    if (((SF == OF) & (t_140039e6f != (rax as u32))) == false) { /* -> bb2128 */ }
    if (((SF == OF) & (t_140039e6f != (rax as u32))) != 0) { /* -> bb2832 */ }

    // ---- bb2128 @ 0x140039e7b ----
    /* 140039e7b */ core::ptr::write((rdi).wrapping_add(0x2234_u64) as *mut u32, 0x3f2aaaab_u32);
    /* 140039e85 */ r15 = ((r13 as u32) as u64);
    /* 140039e88 */ r14 = r13;
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x2c98bc]
    // intrinsic: f3440f10 movss xmm9, dword ptr [rip + 0x2cadff]
    // intrinsic: f3440f10 movss xmm10, dword ptr [rip + 0x2ca13a]
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2cad82]
    // intrinsic: f3440f10 movss xmm13, dword ptr [rip + 0x2c94fd]
    // intrinsic: f3440f10 movss xmm11, dword ptr [rip + 0x2cad6c]
    // intrinsic: f3440f10 movss xmm14, dword ptr [rip + 0x362e17]
    // intrinsic: f3440f10 movss xmm15, dword ptr [rip + 0x2cad7e]
    /* fallthrough -> bb2139 */

    // ---- bb2139 @ 0x140039ed2 ----
    /* 140039ed2 */ let mut t_140039ed2: u32 = core::ptr::read(((rsp).wrapping_add((r14).wrapping_mul(0x4_u64))).wrapping_add(0x50_u64) as *const u32);
    /* 140039ed2 */ r12 = (t_140039ed2 as u64);
    /* 140039ed7 */ rsi = ((r13 as u32) as u64);
    if (((SF != OF) | (r14 == 0x4_u64)) == false) { /* -> bb2145 */ }
    if (((SF != OF) | (r14 == 0x4_u64)) != 0) { /* -> bb2144 */ }

    // ---- bb2144 @ 0x140039edd ----
    if (((SF != OF) | (r14 == 0x4_u64)) == false) { /* -> bb2145 */ }
    if (((SF != OF) | (r14 == 0x4_u64)) != 0) { /* -> bb2215 */ }

    // ---- bb2145 @ 0x140039ee3 ----
    /* 140039ee3 */ r13 = (rdi).wrapping_add(0x2f0_u64);
    /* 140039eea */ rdi = (0x140039ef1_u64).wrapping_add(0x39a4db_u64);
    /* fallthrough -> bb2147 */

    // ---- bb2147 @ 0x140039ef1 ----
    /* 140039ef1 */ xmm1 = xmm8;
    /* 140039ef5 */ xmm0 = xmm9;
    /* 140039ef9 */ fn_1400c6d50();
    /* 140039efe */ xmm1 = xmm0;
    if ((rsi as u32) == (r12 as u32)) {
        /* -> bb2155 */
    } else {
        /* -> bb2154 */
    }

    // ---- bb2154 @ 0x140039f05 ----
    if ((rsi as u32) == (r12 as u32)) {
        /* -> bb2155 */
    } else {
        /* -> bb2159 */
    }

    // ---- bb2155 @ 0x140039f07 ----
    /* 140039f07 */ let mut xmm2: u128 = xmm0;
    // intrinsic: f3410f58 addss xmm2, xmm10
    // intrinsic: f30f58cf addss xmm1, xmm7
    /* fallthrough -> bb2167 */

    // ---- bb2159 @ 0x140039f15 ----
    /* 140039f15 */ let mut t_140039f15: u32 = core::ptr::read((0x140039f1b_u64).wrapping_add(0x2d17b5_u64) as *const u32);
    /* 140039f15 */ rax = (t_140039f15 as u64);
    /* 140039f1b */ let mut t_140039f1b_0: u32 = ((rax as u32)).wrapping_add(0xffffffe8_u32);
    /* 140039f1b */ rax = (t_140039f1b_0 as u64);
    /* 140039f1e */ xmm2 = ((rax as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    // intrinsic: f30f58d1 addss xmm2, xmm1
    /* 140039f29 */ xmm0 = xmm7;
    // intrinsic: f30f5cc1 subss xmm0, xmm1
    /* 140039f30 */ xmm1 = xmm0;
    /* fallthrough -> bb2167 */

    // ---- bb2167 @ 0x140039f33 ----
    // intrinsic: 0f14d100 unpcklps xmm2, xmm1
    /* 140039f36 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb2169 */ }
    if DF { /* -> bb2170 */ }

    // ---- bb2169 @ 0x140039f36 ----
    /* 140039f36 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 140039f36 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb2171 */

    // ---- bb2170 @ 0x140039f36 ----
    /* 140039f36 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 140039f36 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb2171 */

    // ---- bb2171 @ 0x140039f3e ----
    /* 140039f3e */ xmm1 = xmm13;
    /* 140039f42 */ rcx = (rbp).wrapping_add(0xa8_u64);
    /* 140039f49 */ fn_1400c6ec0();
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 4]
    // intrinsic: f3410f5c subss xmm1, xmm11
    /* 140039f58 */ rcx = ((rsi as u32) as u64);
    /* 140039f5a */ rcx = (((rcx as u32) ^ 0xffffffff_u32) as u64);
    /* 140039f5c */ let mut t_140039f5c_0: u32 = ((rcx as u32) & 0x1_u32);
    /* 140039f5c */ rcx = (t_140039f5c_0 as u64);
    /* 140039f5f */ rcx = ((((rcx).wrapping_mul(0x2_u64)).wrapping_sub(0x1_u64) as u32) as u64);
    /* 140039f66 */ xmm0 = ((rcx as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    // intrinsic: f3410f59 mulss xmm0, xmm11
    // intrinsic: f30f5800 addss xmm0, dword ptr [rax]
    // intrinsic: f30f1185 movss dword ptr [rbp + 0x98], xmm0
    // intrinsic: f30f118d movss dword ptr [rbp + 0x9c], xmm1
    /* 140039f86 */ xmm1 = xmm12;
    /* 140039f8a */ xmm0 = xmm14;
    /* 140039f8e */ fn_1400c6d50();
    /* 140039f93 */ xmm6 = xmm0;
    // intrinsic: f3410f59 mulss xmm6, xmm15
    /* 140039f9b */ let mut t_140039f9b: u32 = core::ptr::read((0x140039fa1_u64).wrapping_add(0x3b01ef_u64) as *const u32);
    /* 140039f9b */ rbx = (t_140039f9b as u64);
    /* 140039fa1 */ let mut t_140039fa1_0: u32 = ((rbx as u32)).wrapping_add((r15 as u32));
    /* 140039fa1 */ rbx = (t_140039fa1_0 as u64);
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2caca0]
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 140039faf */ fn_1400c6d50();
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x362cdc]
    // intrinsic: f30f114c movss dword ptr [rsp + 0x40], xmm1
    /* 140039fc2 */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u32, 0xf0_u32);
    /* 140039fca */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rdi);
    // intrinsic: f30f1174 movss dword ptr [rsp + 0x28], xmm6
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 140039fdb */ r9 = (rbp).wrapping_add(0x98_u64);
    /* 140039fe2 */ r8 = (rbp).wrapping_add(0xa0_u64);
    /* 140039fe9 */ rdx = ((rbx as u32) as u64);
    /* 140039feb */ rcx = r13;
    /* 140039fee */ fn_1400c91d0();
    /* 140039ff3 */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    if (SF == OF) {
        /* -> bb2213 */
    } else {
        /* -> bb2212 */
    }

    // ---- bb2212 @ 0x140039ff8 ----
    if (SF != OF) {
        /* -> bb2147 */
    } else {
        /* -> bb2213 */
    }

    // ---- bb2213 @ 0x140039ffe ----
    /* 140039ffe */ rdi = core::ptr::read((rbp).wrapping_add(0x90_u64) as *const u64);
    /* 14003a005 */ let mut t_14003a005_0: u32 = 0x0_u32;
    /* 14003a005 */ r13 = (t_14003a005_0 as u64);
    /* fallthrough -> bb2215 */

    // ---- bb2215 @ 0x14003a008 ----
    /* 14003a008 */ r15 = (((r15 as u32)).wrapping_add(0x1_u32) as u64);
    /* 14003a00b */ r14 = (r14).wrapping_add(0x1_u64);
    if (SF == OF) {
        /* -> bb2221 */
    } else {
        /* -> bb2220 */
    }

    // ---- bb2220 @ 0x14003a012 ----
    if (SF != OF) {
        /* -> bb2139 */
    } else {
        /* -> bb2221 */
    }

    // ---- bb2221 @ 0x14003a018 ----
    /* 14003a018 */ rcx = core::ptr::read((rdi).wrapping_add(0x260_u64) as *const u64);
    /* 14003a01f */ fn_1400b87d0();
    /* 14003a024 */ let mut t_14003a024: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 14003a024 */ rbx = ((t_14003a024 as i64) as u64);
    /* 14003a02b */ rcx = core::ptr::read((rdi).wrapping_add(0x260_u64) as *const u64);
    /* 14003a032 */ let mut t_14003a032: u32 = core::ptr::read((rcx).wrapping_add(0x1f8_u64) as *const u32);
    /* 14003a032 */ rcx = (t_14003a032 as u64);
    /* 14003a038 */ fn_1400c7930();
    /* 14003a03d */ core::ptr::write(((rax).wrapping_add((rbx).wrapping_mul(0x1_u64))).wrapping_add(0x60_u64) as *mut u8, 0x1_u8);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003a045 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 14003a04a */ xmm1 = core::ptr::read((0x14003a052_u64).wrapping_add(0x2c937e_u64) as *const u128);
    /* 14003a052 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 14003a058 */ let mut t_14003a058: u32 = core::ptr::read((0x14003a05e_u64).wrapping_add(0x2ca9be_u64) as *const u32);
    /* 14003a058 */ rax = (t_14003a058 as u64);
    /* 14003a05e */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u32, (rax as u32));
    /* 14003a062 */ let mut t_14003a062: u16 = core::ptr::read((0x14003a069_u64).wrapping_add(0x2ca9b7_u64) as *const u16);
    /* 14003a062 */ rax = ((t_14003a062 as u32) as u64);
    /* 14003a069 */ core::ptr::write((rsp).wrapping_add(0x54_u64) as *mut u16, (rax as u16));
    /* 14003a06e */ core::ptr::write((rsp).wrapping_add(0x56_u64) as *mut u8, 0x0_u8);
    /* 14003a073 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 14003a078 */ xmm3 = xmm12;
    /* 14003a07c */ let mut t_14003a07c_0: u32 = 0x0_u32;
    /* 14003a07c */ r8 = (t_14003a07c_0 as u64);
    /* 14003a07f */ rdx = (0x64_u32 as u64);
    /* 14003a084 */ rcx = (rsp).wrapping_add(0x50_u64);
    /* 14003a089 */ fn_140040b90();
    /* 14003a08f */ rdx = core::ptr::read((rsp).wrapping_add(0x68_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2249 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2248 */ }

    // ---- bb2248 @ 0x14003a098 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2249 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2265 */ }

    // ---- bb2249 @ 0x14003a09a ----
    /* 14003a09a */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 14003a09d */ rcx = core::ptr::read((rsp).wrapping_add(0x50_u64) as *const u64);
    /* 14003a0a2 */ rax = rcx;
    if (CF == false) { /* -> bb2256 */ }
    if CF { /* -> bb2255 */ }

    // ---- bb2255 @ 0x14003a0ac ----
    if (CF == false) { /* -> bb2256 */ }
    if CF { /* -> bb2264 */ }

    // ---- bb2256 @ 0x14003a0ae ----
    /* 14003a0ae */ let mut t_14003a0ae_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 14003a0ae */ rdx = t_14003a0ae_0;
    /* 14003a0b2 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 14003a0b6 */ let mut t_14003a0b6_0: u64 = (rax).wrapping_sub(rcx);
    /* 14003a0b6 */ rax = t_14003a0b6_0;
    /* 14003a0b9 */ let mut t_14003a0b9_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 14003a0b9 */ rax = t_14003a0b9_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2264 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2263 */ }

    // ---- bb2263 @ 0x14003a0c1 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2264 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2850 */ }

    // ---- bb2264 @ 0x14003a0c7 ----
    /* 14003a0c7 */ fn_1402c7498();
    /* fallthrough -> bb2265 */

    // ---- bb2265 @ 0x14003a0cc ----
    /* 14003a0cc */ rcx = (0x14003a0d3_u64).wrapping_sub(0x3a0d3_u64);
    /* 14003a0d3 */ r15 = (0x28_u32 as u64);
    /* fallthrough -> bb2267 */

    // ---- bb2267 @ 0x14003a0d9 ----
    /* 14003a0d9 */ let mut t_14003a0d9: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_14003a0d9 == 0x78_u32) {
        /* -> bb2271 */
    } else {
        /* -> bb2270 */
    }

    // ---- bb2270 @ 0x14003a0e0 ----
    if (t_14003a0d9 == 0x78_u32) {
        /* -> bb2271 */
    } else {
        /* -> bb2276 */
    }

    // ---- bb2271 @ 0x14003a0e2 ----
    /* 14003a0e2 */ let mut t_14003a0e2: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 14003a0e2 */ rdx = ((t_14003a0e2 as i64) as u64);
    /* 14003a0e9 */ let mut t_14003a0e9_0: u32 = 0x0_u32;
    /* 14003a0e9 */ r8 = (t_14003a0e9_0 as u64);
    /* 14003a0ec */ let mut t_14003a0ec: u32 = core::ptr::read(((rcx).wrapping_add((rdx).wrapping_mul(0x4_u64))).wrapping_add(0x304638_u64) as *const u32);
    /* 14003a0ec */ rdx = (t_14003a0ec as u64);
    /* 14003a0f3 */ rcx = core::ptr::read((0x14003a0fa_u64).wrapping_add(0x3c10ee_u64) as *const u64);
    /* 14003a0fa */ fn_140104f20();
    /* fallthrough -> bb2276 */

    // ---- bb2276 @ 0x14003a0ff ----
    /* 14003a0ff */ let mut t_14003a0ff: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_14003a0ff == 0x12c_u32) {
        /* -> bb2280 */
    } else {
        /* -> bb2279 */
    }

    // ---- bb2279 @ 0x14003a109 ----
    if (t_14003a0ff == 0x12c_u32) {
        /* -> bb2280 */
    } else {
        /* -> bb2570 */
    }

    // ---- bb2280 @ 0x14003a10f ----
    /* 14003a10f */ core::ptr::write((rdi).wrapping_add(0x223c_u64) as *mut u8, 0x1_u8);
    /* 14003a116 */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, 0x8_u32);
    /* fallthrough -> bb2569 */

    // ---- bb2283 @ 0x14003a125 ----
    if ((rax as u32) == 0x7_u32) {
        /* -> bb2287 */
    } else {
        /* -> bb2286 */
    }

    // ---- bb2286 @ 0x14003a128 ----
    if ((rax as u32) == 0x7_u32) {
        /* -> bb2287 */
    } else {
        /* -> bb2360 */
    }

    // ---- bb2287 @ 0x14003a12e ----
    /* 14003a12e */ let mut t_14003a12e: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_14003a12e == 0x1_u32) {
        /* -> bb2291 */
    } else {
        /* -> bb2290 */
    }

    // ---- bb2290 @ 0x14003a135 ----
    if (t_14003a12e == 0x1_u32) {
        /* -> bb2291 */
    } else {
        /* -> bb2312 */
    }

    // ---- bb2291 @ 0x14003a137 ----
    /* 14003a137 */ rax = (0x14003a13e_u64).wrapping_add(0x39f3d2_u64);
    /* 14003a13e */ let mut t_14003a13e: u64 = core::ptr::read((0x14003a146_u64).wrapping_add(0x39f3e2_u64) as *const u64);
    if (((CF == false) & (t_14003a13e != 0xf_u64)) == false) { /* -> bb2294 */ }
    if (((CF == false) & (t_14003a13e != 0xf_u64)) != 0) { /* -> bb2295 */ }

    // ---- bb2295 @ 0x14003a146 ----
    /* 14003a146 */ rax = core::ptr::read((0x14003a14e_u64).wrapping_add(0x39f3c2_u64) as *const u64);
    /* fallthrough -> bb2294 */

    // ---- bb2294 @ 0x14003a14e ----
    /* 14003a14e */ let mut t_14003a14e: u64 = core::ptr::read((0x14003a156_u64).wrapping_add(0x39f3ca_u64) as *const u64);
    if (t_14003a14e == 0x6_u64) {
        /* -> bb2300 */
    } else {
        /* -> bb2299 */
    }

    // ---- bb2299 @ 0x14003a156 ----
    if (t_14003a14e == 0x6_u64) {
        /* -> bb2300 */
    } else {
        /* -> bb2311 */
    }

    // ---- bb2300 @ 0x14003a158 ----
    /* 14003a158 */ let mut t_14003a158: u32 = core::ptr::read(rax as *const u32);
    if (t_14003a158 == 0x63726943_u32) {
        /* -> bb2304 */
    } else {
        /* -> bb2303 */
    }

    // ---- bb2303 @ 0x14003a15e ----
    if (t_14003a158 == 0x63726943_u32) {
        /* -> bb2304 */
    } else {
        /* -> bb2311 */
    }

    // ---- bb2304 @ 0x14003a160 ----
    /* 14003a160 */ let mut t_14003a160: u16 = core::ptr::read((rax).wrapping_add(0x4_u64) as *const u16);
    if (t_14003a160 == 0x7375_u16) {
        /* -> bb2308 */
    } else {
        /* -> bb2307 */
    }

    // ---- bb2307 @ 0x14003a166 ----
    if (t_14003a160 == 0x7375_u16) {
        /* -> bb2308 */
    } else {
        /* -> bb2311 */
    }

    // ---- bb2308 @ 0x14003a168 ----
    /* 14003a168 */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, 0x6_u32);
    /* 14003a172 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u32, (r13 as u32));
    /* fallthrough -> bb2312 */

    // ---- bb2311 @ 0x14003a17b ----
    /* 14003a17b */ fn_14003f5e0();
    /* fallthrough -> bb2312 */

    // ---- bb2312 @ 0x14003a180 ----
    /* 14003a180 */ let mut t_14003a180: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_14003a180 == 0xf_u32) {
        /* -> bb2316 */
    } else {
        /* -> bb2315 */
    }

    // ---- bb2315 @ 0x14003a187 ----
    if (t_14003a180 == 0xf_u32) {
        /* -> bb2316 */
    } else {
        /* -> bb2354 */
    }

    // ---- bb2316 @ 0x14003a18d ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003a190 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u128, xmm0);
    /* 14003a195 */ xmm1 = core::ptr::read((0x14003a19d_u64).wrapping_add(0x2cab13_u64) as *const u128);
    /* 14003a19d */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u128, xmm1);
    /* 14003a1a3 */ let mut t_14003a1a3: u32 = core::ptr::read((0x14003a1a9_u64).wrapping_add(0x2ca87b_u64) as *const u32);
    /* 14003a1a3 */ rax = (t_14003a1a3 as u64);
    /* 14003a1a9 */ core::ptr::write((rsp).wrapping_add(0x50_u64) as *mut u16, (rax as u16));
    /* 14003a1ae */ let mut t_14003a1ae: u8 = core::ptr::read((0x14003a1b5_u64).wrapping_add(0x2ca871_u64) as *const u8);
    /* 14003a1ae */ rax = ((t_14003a1ae as u32) as u64);
    /* 14003a1b5 */ core::ptr::write((rsp).wrapping_add(0x52_u64) as *mut u8, (rax as u8));
    /* 14003a1b9 */ core::ptr::write((rsp).wrapping_add(0x53_u64) as *mut u8, (r13 as u8));
    /* 14003a1be */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x362ad9]
    /* 14003a1cb */ let mut t_14003a1cb_0: u32 = 0x0_u32;
    /* 14003a1cb */ r8 = (t_14003a1cb_0 as u64);
    /* 14003a1ce */ rdx = (0x64_u32 as u64);
    /* 14003a1d3 */ rcx = (rsp).wrapping_add(0x50_u64);
    /* 14003a1d8 */ fn_140040b90();
    /* 14003a1de */ r8 = core::ptr::read((rsp).wrapping_add(0x68_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb2337 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb2336 */ }

    // ---- bb2336 @ 0x14003a1e7 ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb2337 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb2340 */ }

    // ---- bb2337 @ 0x14003a1e9 ----
    /* 14003a1e9 */ rdx = core::ptr::read((rsp).wrapping_add(0x50_u64) as *const u64);
    /* 14003a1ee */ rcx = (rsp).wrapping_add(0x50_u64);
    /* 14003a1f3 */ fn_140028310();
    /* fallthrough -> bb2340 */

    // ---- bb2340 @ 0x14003a1f8 ----
    /* 14003a1f8 */ rcx = ((r15 as u32) as u64);
    /* 14003a1fb */ fn_1400c6990();
    if (r8 == 0xf_u64) {
        /* -> bb2346 */
    } else {
        /* -> bb2345 */
    }

    // ---- bb2345 @ 0x14003a202 ----
    if (r8 == 0xf_u64) {
        /* -> bb2346 */
    } else {
        /* -> bb2347 */
    }

    // ---- bb2346 @ 0x14003a204 ----
    /* 14003a204 */ core::ptr::write((rdi).wrapping_add(0x2250_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb2347 */

    // ---- bb2347 @ 0x14003a20b ----
    /* 14003a20b */ rdx = core::ptr::read((rdi).wrapping_add(0x260_u64) as *const u64);
    /* 14003a212 */ rcx = rdi;
    /* 14003a215 */ fn_1400d21e0();
    /* 14003a21a */ rdx = ((rax as u32) as u64);
    /* 14003a21c */ r8 = (0x1c_u32 as u64);
    /* 14003a222 */ rcx = rdi;
    /* 14003a225 */ fn_1400d2220();
    /* fallthrough -> bb2354 */

    // ---- bb2354 @ 0x14003a22a ----
    /* 14003a22a */ let mut t_14003a22a: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (SF == OF) {
        /* -> bb2358 */
    } else {
        /* -> bb2357 */
    }

    // ---- bb2357 @ 0x14003a234 ----
    if (SF == OF) {
        /* -> bb2358 */
    } else {
        /* -> bb2570 */
    }

    // ---- bb2358 @ 0x14003a23a ----
    /* 14003a23a */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, 0x8_u32);
    /* fallthrough -> bb2569 */

    // ---- bb2360 @ 0x14003a249 ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb2364 */
    } else {
        /* -> bb2363 */
    }

    // ---- bb2363 @ 0x14003a24c ----
    if ((rax as u32) == 0x8_u32) {
        /* -> bb2364 */
    } else {
        /* -> bb2570 */
    }

    // ---- bb2364 @ 0x14003a252 ----
    /* 14003a252 */ let mut t_14003a252: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_14003a252 == 0x1_u32) {
        /* -> bb2368 */
    } else {
        /* -> bb2367 */
    }

    // ---- bb2367 @ 0x14003a259 ----
    if (t_14003a252 == 0x1_u32) {
        /* -> bb2368 */
    } else {
        /* -> bb2515 */
    }

    // ---- bb2368 @ 0x14003a25f ----
    /* 14003a25f */ rdx = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u64);
    if (t_14003a252 != 0x1_u32) {
        /* -> bb2373 */
    } else {
        /* -> bb2372 */
    }

    // ---- bb2372 @ 0x14003a269 ----
    if (t_14003a252 != 0x1_u32) {
        /* -> bb2373 */
    } else {
        /* -> bb2375 */
    }

    // ---- bb2373 @ 0x14003a26b ----
    /* 14003a26b */ rcx = core::ptr::read((rdi).wrapping_add(0x98_u64) as *const u64);
    /* 14003a272 */ fn_140005eb0();
    /* fallthrough -> bb2375 */

    // ---- bb2375 @ 0x14003a277 ----
    /* 14003a277 */ core::ptr::write((rdi).wrapping_add(0x298_u64) as *mut u64, r13);
    /* 14003a27e */ rdx = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u64);
    if (t_14003a252 != 0x1_u32) {
        /* -> bb2381 */
    } else {
        /* -> bb2380 */
    }

    // ---- bb2380 @ 0x14003a288 ----
    if (t_14003a252 != 0x1_u32) {
        /* -> bb2381 */
    } else {
        /* -> bb2383 */
    }

    // ---- bb2381 @ 0x14003a28a ----
    /* 14003a28a */ rcx = core::ptr::read((rdi).wrapping_add(0x98_u64) as *const u64);
    /* 14003a291 */ fn_140005eb0();
    /* fallthrough -> bb2383 */

    // ---- bb2383 @ 0x14003a296 ----
    /* 14003a296 */ core::ptr::write((rdi).wrapping_add(0x2a0_u64) as *mut u64, r13);
    /* 14003a29d */ rsi = core::ptr::read((rdi).wrapping_add(0x2b8_u64) as *const u64);
    /* 14003a2a4 */ rbx = core::ptr::read((rdi).wrapping_add(0x2b0_u64) as *const u64);
    if (rbx != rsi) {
        /* -> bb2390 */
    } else {
        /* -> bb2389 */
    }

    // ---- bb2389 @ 0x14003a2ae ----
    if (rbx != rsi) {
        /* -> bb2390 */
    } else {
        /* -> bb2398 */
    }

    // ---- bb2390 @ 0x14003a2b0 ----
    /* 14003a2b0 */ rdx = core::ptr::read(rbx as *const u64);
    /* 14003a2b3 */ rcx = core::ptr::read((rdi).wrapping_add(0x98_u64) as *const u64);
    /* 14003a2ba */ fn_140005eb0();
    /* 14003a2bf */ let mut t_14003a2bf_0: u64 = (rbx).wrapping_add(0x8_u64);
    /* 14003a2bf */ rbx = t_14003a2bf_0;
    if (rbx == rsi) {
        /* -> bb2398 */
    } else {
        /* -> bb2397 */
    }

    // ---- bb2397 @ 0x14003a2c6 ----
    if (rbx != rsi) {
        /* -> bb2390 */
    } else {
        /* -> bb2398 */
    }

    // ---- bb2398 @ 0x14003a2c8 ----
    /* 14003a2c8 */ rax = core::ptr::read((rdi).wrapping_add(0x2b0_u64) as *const u64);
    /* 14003a2cf */ let mut t_14003a2cf: u64 = core::ptr::read((rdi).wrapping_add(0x2b8_u64) as *const u64);
    if (rax != t_14003a2cf) {
        /* -> bb2403 */
    } else {
        /* -> bb2402 */
    }

    // ---- bb2402 @ 0x14003a2d6 ----
    if (rax != t_14003a2cf) {
        /* -> bb2403 */
    } else {
        /* -> bb2404 */
    }

    // ---- bb2403 @ 0x14003a2d8 ----
    /* 14003a2d8 */ core::ptr::write((rdi).wrapping_add(0x2b8_u64) as *mut u64, rax);
    /* fallthrough -> bb2404 */

    // ---- bb2404 @ 0x14003a2df ----
    /* 14003a2df */ rcx = rdi;
    /* 14003a2e2 */ fn_140039010();
    /* 14003a2e7 */ core::ptr::write((rdi).wrapping_add(0x110_u64) as *mut u32, (r13 as u32));
    /* 14003a2ee */ rbx = (rdi).wrapping_add(0x223c_u64);
    // intrinsic: f30f1025 movss xmm4, dword ptr [rip + 0x362997]
    /* 14003a2fd */ rsi = (rdi).wrapping_add(0x254_u64);
    /* 14003a304 */ r14 = (rdi).wrapping_add(0x260_u64);
    /* 14003a30b */ let mut t_14003a30b: u8 = core::ptr::read(rbx as *const u8);
    if (t_14003a30b != (r13 as u8)) {
        /* -> bb2415 */
    } else {
        /* -> bb2414 */
    }

    // ---- bb2414 @ 0x14003a30e ----
    if (t_14003a30b != (r13 as u8)) {
        /* -> bb2415 */
    } else {
        /* -> bb2428 */
    }

    // ---- bb2415 @ 0x14003a310 ----
    /* 14003a310 */ let mut t_14003a310: u32 = core::ptr::read(rsi as *const u32);
    /* 14003a310 */ rcx = ((t_14003a310 as i64) as u64);
    /* 14003a313 */ let mut t_14003a313_0: u64 = (rcx).wrapping_add(rcx);
    /* 14003a313 */ rcx = t_14003a313_0;
    /* 14003a316 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    // intrinsic: f30f1054 movss xmm2, dword ptr [rax + rcx*8 + 8]
    // intrinsic: f30f59d4 mulss xmm2, xmm4
    // intrinsic: f30f5814 addss xmm2, dword ptr [rax + rcx*8]
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    // intrinsic: f30f58d0 addss xmm2, xmm0
    // intrinsic: f30f105c movss xmm3, dword ptr [rax + rcx*8 + 0xc]
    // intrinsic: f30f59dc mulss xmm3, xmm4
    // intrinsic: f30f585c addss xmm3, dword ptr [rax + rcx*8 + 4]
    // intrinsic: f30f581d addss xmm3, dword ptr [rip + 0x362959]
    /* fallthrough -> bb2431 */

    // ---- bb2428 @ 0x14003a34d ----
    /* 14003a34d */ rax = core::ptr::read(r14 as *const u64);
    // intrinsic: f30f1090 movss xmm2, dword ptr [rax + 0x1d4]
    // intrinsic: f30f1098 movss xmm3, dword ptr [rax + 0x1d8]
    /* fallthrough -> bb2431 */

    // ---- bb2431 @ 0x14003a360 ----
    /* 14003a360 */ xmm0 = xmm2;
    // intrinsic: 0f14c300 unpcklps xmm0, xmm3
    /* 14003a366 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb2434 */ }
    if DF { /* -> bb2435 */ }

    // ---- bb2434 @ 0x14003a366 ----
    /* 14003a366 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003a366 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb2436 */

    // ---- bb2435 @ 0x14003a366 ----
    /* 14003a366 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003a366 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb2436 */

    // ---- bb2436 @ 0x14003a36e ----
    /* 14003a36e */ let mut t_14003a36e: u32 = core::ptr::read(rsi as *const u32);
    /* 14003a36e */ rdx = ((t_14003a36e as i64) as u64);
    /* 14003a371 */ let mut t_14003a371_0: u64 = (rdx).wrapping_add(rdx);
    /* 14003a371 */ rdx = t_14003a371_0;
    /* 14003a374 */ rcx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    // intrinsic: f30f104c movss xmm1, dword ptr [rcx + rdx*8 + 0xc]
    // intrinsic: f30f59cc mulss xmm1, xmm4
    // intrinsic: f30f584c addss xmm1, dword ptr [rcx + rdx*8 + 4]
    // intrinsic: f30f5ccb subss xmm1, xmm3
    /* 14003a38f */ rax = core::ptr::read(r14 as *const u64);
    // intrinsic: f30f1044 movss xmm0, dword ptr [rcx + rdx*8 + 8]
    // intrinsic: f30f59c4 mulss xmm0, xmm4
    // intrinsic: f30f5804 addss xmm0, dword ptr [rcx + rdx*8]
    // intrinsic: f30f5cc2 subss xmm0, xmm2
    // intrinsic: f30f1180 movss dword ptr [rax + 0x1e4], xmm0
    // intrinsic: f30f1188 movss dword ptr [rax + 0x1e8], xmm1
    /* 14003a3b5 */ rdx = (rbp).wrapping_add(0x90_u64);
    /* 14003a3bc */ rcx = core::ptr::read(r14 as *const u64);
    /* 14003a3bf */ fn_1400b6600();
    /* 14003a3c4 */ rax = core::ptr::read(r14 as *const u64);
    /* 14003a3c7 */ core::ptr::write((rax).wrapping_add(0x1e1_u64) as *mut u8, 0x1_u8);
    /* 14003a3ce */ r15 = r14;
    /* 14003a3d1 */ let mut t_14003a3d1: u32 = core::ptr::read(rsi as *const u32);
    if (t_14003a3d1 != 0x5_u32) {
        /* -> bb2461 */
    } else {
        /* -> bb2460 */
    }

    // ---- bb2460 @ 0x14003a3d4 ----
    if (t_14003a3d1 != 0x5_u32) {
        /* -> bb2461 */
    } else {
        /* -> bb2493 */
    }

    // ---- bb2461 @ 0x14003a3da ----
    /* 14003a3da */ rax = (0x14003a3e1_u64).wrapping_add(0x39f12f_u64);
    /* 14003a3e1 */ rdx = rsi;
    /* 14003a3e4 */ let mut t_14003a3e4: u64 = core::ptr::read((0x14003a3ec_u64).wrapping_add(0x39f13c_u64) as *const u64);
    if ((CF | (t_14003a3e4 == 0xf_u64)) == false) { /* -> bb2467 */ }
    if ((CF | (t_14003a3e4 == 0xf_u64)) != 0) { /* -> bb2466 */ }

    // ---- bb2466 @ 0x14003a3ec ----
    if ((CF | (t_14003a3e4 == 0xf_u64)) == false) { /* -> bb2467 */ }
    if ((CF | (t_14003a3e4 == 0xf_u64)) != 0) { /* -> bb2471 */ }

    // ---- bb2467 @ 0x14003a3ee ----
    /* 14003a3ee */ rax = core::ptr::read((0x14003a3f5_u64).wrapping_add(0x39f11b_u64) as *const u64);
    /* 14003a3f5 */ rbx = (rdi).wrapping_add(0x223c_u64);
    /* 14003a3fc */ rdx = (rdi).wrapping_add(0x254_u64);
    /* 14003a403 */ r15 = (rdi).wrapping_add(0x260_u64);
    /* fallthrough -> bb2471 */

    // ---- bb2471 @ 0x14003a40a ----
    /* 14003a40a */ r12 = rsi;
    /* 14003a40d */ let mut t_14003a40d: u64 = core::ptr::read((0x14003a415_u64).wrapping_add(0x39f10b_u64) as *const u64);
    if (t_14003a40d == 0x6_u64) {
        /* -> bb2476 */
    } else {
        /* -> bb2475 */
    }

    // ---- bb2475 @ 0x14003a415 ----
    if (t_14003a40d == 0x6_u64) {
        /* -> bb2476 */
    } else {
        /* -> bb2489 */
    }

    // ---- bb2476 @ 0x14003a417 ----
    /* 14003a417 */ let mut t_14003a417: u32 = core::ptr::read(rax as *const u32);
    /* 14003a417 */ rcx = (t_14003a417 as u64);
    /* 14003a419 */ let mut t_14003a419_0: u32 = ((rcx as u32)).wrapping_sub(0x63726943_u32);
    /* 14003a419 */ rcx = (t_14003a419_0 as u64);
    if (t_14003a40d == 0x6_u64) {
        /* -> bb2481 */
    } else {
        /* -> bb2480 */
    }

    // ---- bb2480 @ 0x14003a41f ----
    if (t_14003a40d == 0x6_u64) {
        /* -> bb2481 */
    } else {
        /* -> bb2484 */
    }

    // ---- bb2481 @ 0x14003a421 ----
    /* 14003a421 */ let mut t_14003a421: u16 = core::ptr::read((rax).wrapping_add(0x4_u64) as *const u16);
    /* 14003a421 */ rcx = ((t_14003a421 as u32) as u64);
    /* 14003a425 */ rax = (0x7375_u32 as u64);
    /* 14003a42a */ let mut t_14003a42a_0: u32 = ((rcx as u32)).wrapping_sub((rax as u32));
    /* 14003a42a */ rcx = (t_14003a42a_0 as u64);
    /* fallthrough -> bb2484 */

    // ---- bb2484 @ 0x14003a42c ----
    /* 14003a42c */ r12 = rdx;
    if (t_14003a40d != 0x6_u64) {
        /* -> bb2489 */
    } else {
        /* -> bb2488 */
    }

    // ---- bb2488 @ 0x14003a431 ----
    if (t_14003a40d != 0x6_u64) {
        /* -> bb2489 */
    } else {
        /* -> bb2493 */
    }

    // ---- bb2489 @ 0x14003a433 ----
    /* 14003a433 */ rcx = core::ptr::read(r14 as *const u64);
    /* 14003a436 */ fn_1400b9210();
    /* 14003a43b */ rbx = (rdi).wrapping_add(0x223c_u64);
    /* 14003a442 */ rsi = r12;
    /* fallthrough -> bb2493 */

    // ---- bb2493 @ 0x14003a445 ----
    /* 14003a445 */ r14 = r15;
    /* 14003a448 */ let mut t_14003a448: u8 = core::ptr::read(rbx as *const u8);
    if (t_14003a448 != (r13 as u8)) {
        /* -> bb2498 */
    } else {
        /* -> bb2497 */
    }

    // ---- bb2497 @ 0x14003a44b ----
    if (t_14003a448 != (r13 as u8)) {
        /* -> bb2498 */
    } else {
        /* -> bb2508 */
    }

    // ---- bb2498 @ 0x14003a44d ----
    /* 14003a44d */ let mut t_14003a44d: u32 = core::ptr::read(rsi as *const u32);
    /* 14003a44d */ rdx = (t_14003a44d as u64);
    if (SF != OF) {
        /* -> bb2503 */
    } else {
        /* -> bb2502 */
    }

    // ---- bb2502 @ 0x14003a452 ----
    if (SF != OF) {
        /* -> bb2503 */
    } else {
        /* -> bb2508 */
    }

    // ---- bb2503 @ 0x14003a454 ----
    /* 14003a454 */ let mut t_14003a454_0: u32 = ((rdx as u32)).wrapping_add(0x2b_u32);
    /* 14003a454 */ rdx = (t_14003a454_0 as u64);
    /* 14003a457 */ rcx = core::ptr::read(r15 as *const u64);
    /* 14003a45a */ fn_1400b7760();
    /* 14003a45f */ rsi = (rdi).wrapping_add(0x254_u64);
    /* 14003a466 */ r14 = (rdi).wrapping_add(0x260_u64);
    /* fallthrough -> bb2508 */

    // ---- bb2508 @ 0x14003a46d ----
    /* 14003a46d */ rdx = core::ptr::read(r15 as *const u64);
    /* 14003a470 */ rcx = rdi;
    /* 14003a473 */ fn_1400ceee0();
    /* 14003a478 */ rax = core::ptr::read((rdi).wrapping_add(0x60_u64) as *const u64);
    /* 14003a47c */ core::ptr::write((rax).wrapping_add(0x5d_u64) as *mut u8, 0x1_u8);
    /* 14003a480 */ r15 = (0x28_u32 as u64);
    /* fallthrough -> bb2518 */

    // ---- bb2515 @ 0x14003a488 ----
    /* 14003a488 */ rbx = (rdi).wrapping_add(0x223c_u64);
    /* 14003a48f */ rsi = (rdi).wrapping_add(0x254_u64);
    /* 14003a496 */ r14 = (rdi).wrapping_add(0x260_u64);
    /* fallthrough -> bb2518 */

    // ---- bb2518 @ 0x14003a49d ----
    /* 14003a49d */ let mut t_14003a49d: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    if (t_14003a49d == 0x1e_u32) {
        /* -> bb2522 */
    } else {
        /* -> bb2521 */
    }

    // ---- bb2521 @ 0x14003a4a4 ----
    if (t_14003a49d == 0x1e_u32) {
        /* -> bb2522 */
    } else {
        /* -> bb2570 */
    }

    // ---- bb2522 @ 0x14003a4aa ----
    /* 14003a4aa */ let mut t_14003a4aa: u8 = core::ptr::read(rbx as *const u8);
    if (t_14003a4aa != (r13 as u8)) {
        /* -> bb2526 */
    } else {
        /* -> bb2525 */
    }

    // ---- bb2525 @ 0x14003a4ad ----
    if (t_14003a4aa != (r13 as u8)) {
        /* -> bb2526 */
    } else {
        /* -> bb2563 */
    }

    // ---- bb2526 @ 0x14003a4b3 ----
    /* 14003a4b3 */ let mut t_14003a4b3: u32 = core::ptr::read(rsi as *const u32);
    if (SF != OF) {
        /* -> bb2530 */
    } else {
        /* -> bb2529 */
    }

    // ---- bb2529 @ 0x14003a4b6 ----
    if (SF != OF) {
        /* -> bb2530 */
    } else {
        /* -> bb2563 */
    }

    // ---- bb2530 @ 0x14003a4bc ----
    /* 14003a4bc */ r14 = (rdi).wrapping_add(0x260_u64);
    /* 14003a4c3 */ rdx = core::ptr::read(r14 as *const u64);
    /* 14003a4c6 */ rcx = rdi;
    /* 14003a4c9 */ fn_1400d21e0();
    /* 14003a4ce */ rdx = ((rax as u32) as u64);
    /* 14003a4d0 */ r8 = (0x18_u32 as u64);
    /* 14003a4d6 */ rcx = rdi;
    /* 14003a4d9 */ fn_1400d2220();
    /* 14003a4de */ let mut t_14003a4de: u32 = core::ptr::read(rsi as *const u32);
    /* 14003a4de */ rax = ((t_14003a4de as i64) as u64);
    /* 14003a4e1 */ rbx = (0x14003a4e8_u64).wrapping_sub(0x3a4e8_u64);
    /* 14003a4e8 */ rbx = core::ptr::read(((rbx).wrapping_add((rax).wrapping_mul(0x8_u64))).wrapping_add(0x3d4398_u64) as *const u64);
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003a4f3 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 14003a4fb */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm1);
    /* 14003a500 */ rcx = rbx;
    /* 14003a503 */ fn_1402f9d60();
    /* 14003a508 */ r8 = rax;
    /* 14003a50b */ rdx = rbx;
    /* 14003a50e */ rcx = (rsp).wrapping_add(0x70_u64);
    /* 14003a513 */ fn_140027e30();
    /* 14003a519 */ rcx = (rsp).wrapping_add(0x70_u64);
    /* 14003a51e */ fn_140037710();
    /* 14003a524 */ r8 = core::ptr::read((rbp).wrapping_sub(0x78_u64) as *const u64);
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb2560 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb2559 */ }

    // ---- bb2559 @ 0x14003a52c ----
    if ((CF | (r8 == 0xf_u64)) == false) { /* -> bb2560 */ }
    if ((CF | (r8 == 0xf_u64)) != 0) { /* -> bb2563 */ }

    // ---- bb2560 @ 0x14003a52e ----
    /* 14003a52e */ rdx = core::ptr::read((rsp).wrapping_add(0x70_u64) as *const u64);
    /* 14003a533 */ rcx = (rsp).wrapping_add(0x70_u64);
    /* 14003a538 */ fn_140028310();
    /* fallthrough -> bb2563 */

    // ---- bb2563 @ 0x14003a53d ----
    /* 14003a53d */ rax = core::ptr::read(rdi as *const u64);
    /* 14003a540 */ rcx = rdi;
    /* 14003a543 */ (/* indirect */ core::ptr::read((rax).wrapping_add(0x58_u64) as *const u64))();
    /* 14003a546 */ core::ptr::write(r14 as *mut u64, r13);
    /* 14003a549 */ core::ptr::write(rsi as *mut u32, 0xffffffff_u32);
    /* 14003a54f */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, (r13 as u32));
    /* fallthrough -> bb2569 */

    // ---- bb2569 @ 0x14003a556 ----
    /* 14003a556 */ core::ptr::write((rdi).wrapping_add(0x250_u64) as *mut u32, (r13 as u32));
    /* fallthrough -> bb2570 */

    // ---- bb2570 @ 0x14003a55d ----
    /* 14003a55d */ let mut t_14003a55d: u32 = core::ptr::read((rdi).wrapping_add(0xe0_u64) as *const u32);
    /* 14003a55d */ rax = (t_14003a55d as u64);
    if ((rax as u32) == 0x7_u32) {
        /* -> bb2575 */
    } else {
        /* -> bb2574 */
    }

    // ---- bb2574 @ 0x14003a566 ----
    if ((rax as u32) == 0x7_u32) {
        /* -> bb2575 */
    } else {
        /* -> bb2630 */
    }

    // ---- bb2575 @ 0x14003a56c ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003a56f */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u128, xmm0);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 14003a577 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm1);
    /* 14003a57c */ rcx = (0x20_u32 as u64);
    /* 14003a581 */ fn_1400285e0();
    /* 14003a586 */ rdx = rax;
    /* 14003a589 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, rax);
    /* 14003a58e */ xmm0 = core::ptr::read((0x14003a596_u64).wrapping_add(0x2c9b9a_u64) as *const u128);
    /* 14003a596 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u128, xmm0);
    /* 14003a59b */ xmm0 = core::ptr::read((0x14003a5a2_u64).wrapping_add(0x2ca486_u64) as *const u128);
    /* 14003a5a2 */ core::ptr::write(rax as *mut u128, xmm0);
    /* 14003a5a5 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb2588 */ }
    if DF { /* -> bb2589 */ }

    // ---- bb2588 @ 0x14003a5a5 ----
    /* 14003a5a5 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003a5a5 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb2590 */

    // ---- bb2589 @ 0x14003a5a5 ----
    /* 14003a5a5 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003a5a5 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb2590 */

    // ---- bb2590 @ 0x14003a5ad ----
    /* 14003a5ad */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb2592 */ }
    if DF { /* -> bb2593 */ }

    // ---- bb2592 @ 0x14003a5ad ----
    /* 14003a5ad */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003a5ad */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb2594 */

    // ---- bb2593 @ 0x14003a5ad ----
    /* 14003a5ad */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003a5ad */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb2594 */

    // ---- bb2594 @ 0x14003a5b2 ----
    /* 14003a5b2 */ let mut t_14003a5b2: u16 = core::ptr::read((0x14003a5b9_u64).wrapping_add(0x2ca487_u64) as *const u16);
    /* 14003a5b2 */ rcx = ((t_14003a5b2 as u32) as u64);
    /* 14003a5b9 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u16, (rcx as u16));
    /* 14003a5bd */ let mut t_14003a5bd: u8 = core::ptr::read((0x14003a5c4_u64).wrapping_add(0x2ca47e_u64) as *const u8);
    /* 14003a5bd */ rax = ((t_14003a5bd as u32) as u64);
    /* 14003a5c4 */ core::ptr::write((rdx).wrapping_add(0x1a_u64) as *mut u8, (rax as u8));
    /* 14003a5c7 */ core::ptr::write((rdx).wrapping_add(0x1b_u64) as *mut u8, 0x0_u8);
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2c9185]
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    /* 14003a5d9 */ let mut t_14003a5d9_0: u32 = 0x0_u32;
    /* 14003a5d9 */ r9 = (t_14003a5d9_0 as u64);
    /* 14003a5dc */ r8 = (rsp).wrapping_add(0x70_u64);
    /* 14003a5e1 */ rdx = core::ptr::read((rdi).wrapping_add(0x148_u64) as *const u64);
    /* 14003a5e8 */ rcx = rdi;
    /* 14003a5eb */ fn_1400d1090();
    /* 14003a5f1 */ rdx = core::ptr::read((rbp).wrapping_sub(0x78_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2613 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2612 */ }

    // ---- bb2612 @ 0x14003a5f9 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb2613 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb2636 */ }

    // ---- bb2613 @ 0x14003a5fb ----
    /* 14003a5fb */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 14003a5fe */ rcx = core::ptr::read((rsp).wrapping_add(0x70_u64) as *const u64);
    /* 14003a603 */ rax = rcx;
    if (CF == false) { /* -> bb2620 */ }
    if CF { /* -> bb2619 */ }

    // ---- bb2619 @ 0x14003a60d ----
    if (CF == false) { /* -> bb2620 */ }
    if CF { /* -> bb2628 */ }

    // ---- bb2620 @ 0x14003a60f ----
    /* 14003a60f */ let mut t_14003a60f_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 14003a60f */ rdx = t_14003a60f_0;
    /* 14003a613 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 14003a617 */ let mut t_14003a617_0: u64 = (rax).wrapping_sub(rcx);
    /* 14003a617 */ rax = t_14003a617_0;
    /* 14003a61a */ let mut t_14003a61a_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 14003a61a */ rax = t_14003a61a_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2628 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2627 */ }

    // ---- bb2627 @ 0x14003a622 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb2628 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb2769 */ }

    // ---- bb2628 @ 0x14003a628 ----
    /* 14003a628 */ fn_1402c7498();
    /* fallthrough -> bb2636 */

    // ---- bb2630 @ 0x14003a62f ----
    if ((rax as u32) == 0x7_u32) {
        /* -> bb2634 */
    } else {
        /* -> bb2633 */
    }

    // ---- bb2633 @ 0x14003a631 ----
    if ((rax as u32) == 0x7_u32) {
        /* -> bb2634 */
    } else {
        /* -> bb2636 */
    }

    // ---- bb2634 @ 0x14003a633 ----
    /* 14003a633 */ rcx = rdi;
    /* 14003a636 */ fn_1400cdef0();
    /* fallthrough -> bb2636 */

    // ---- bb2636 @ 0x14003a63b ----
    /* 14003a63b */ rcx = (rdi).wrapping_add(0x2f0_u64);
    /* 14003a642 */ fn_1400c9280();
    /* 14003a647 */ let mut t_14003a647: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    if (t_14003a647 == 0x6_u32) {
        /* -> bb2642 */
    } else {
        /* -> bb2641 */
    }

    // ---- bb2641 @ 0x14003a64e ----
    if (t_14003a647 == 0x6_u32) {
        /* -> bb2642 */
    } else {
        /* -> bb2748 */
    }

    // ---- bb2642 @ 0x14003a654 ----
    /* 14003a654 */ rax = (rdi).wrapping_add(0x348_u64);
    /* 14003a65b */ let mut xmm4: u128 = core::ptr::read((0x14003a663_u64).wrapping_add(0x3626ad_u64) as *const u128);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2ca4c9]
    // intrinsic: f30f102d movss xmm5, dword ptr [rip + 0x2c8ce9]
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x362621]
    /* fallthrough -> bb2648 */

    // ---- bb2648 @ 0x14003a680 ----
    /* 14003a680 */ let mut t_14003a680: u32 = core::ptr::read((rax).wrapping_sub(0x44_u64) as *const u32);
    if (((SF != OF) | (t_14003a680 == 0x0_u32)) == false) { /* -> bb2652 */ }
    if (((SF != OF) | (t_14003a680 == 0x0_u32)) != 0) { /* -> bb2651 */ }

    // ---- bb2651 @ 0x14003a684 ----
    if (((SF != OF) | (t_14003a680 == 0x0_u32)) == false) { /* -> bb2652 */ }
    if (((SF != OF) | (t_14003a680 == 0x0_u32)) != 0) { /* -> bb2667 */ }

    // ---- bb2652 @ 0x14003a686 ----
    // intrinsic: f30f1040 movss xmm0, dword ptr [rax - 0x50]
    // intrinsic: f30f59c2 mulss xmm0, xmm2
    // intrinsic: f30f1140 movss dword ptr [rax - 0x50], xmm0
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax - 0x4c]
    // intrinsic: f30f59ca mulss xmm1, xmm2
    // intrinsic: f30f1148 movss dword ptr [rax - 0x4c], xmm1
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax - 0x48]
    /* 14003a6a7 */ xmm0 = xmm1;
    // intrinsic: 0f54c400 andps xmm0, xmm4
    // intrinsic: 0f2fc500 comiss xmm0, xmm5
    if ((CF | (t_14003a680 == 0x0_u32)) == false) { /* -> bb2665 */ }
    if ((CF | (t_14003a680 == 0x0_u32)) != 0) { /* -> bb2664 */ }

    // ---- bb2664 @ 0x14003a6b0 ----
    if ((CF | (t_14003a680 == 0x0_u32)) == false) { /* -> bb2665 */ }
    if ((CF | (t_14003a680 == 0x0_u32)) != 0) { /* -> bb2667 */ }

    // ---- bb2665 @ 0x14003a6b2 ----
    // intrinsic: f30f59cb mulss xmm1, xmm3
    // intrinsic: f30f1148 movss dword ptr [rax - 0x48], xmm1
    /* fallthrough -> bb2667 */

    // ---- bb2667 @ 0x14003a6bb ----
    /* 14003a6bb */ let mut t_14003a6bb: u32 = core::ptr::read((rax).wrapping_sub(0x1c_u64) as *const u32);
    if (((SF != OF) | (t_14003a6bb == 0x0_u32)) == false) { /* -> bb2671 */ }
    if (((SF != OF) | (t_14003a6bb == 0x0_u32)) != 0) { /* -> bb2670 */ }

    // ---- bb2670 @ 0x14003a6bf ----
    if (((SF != OF) | (t_14003a6bb == 0x0_u32)) == false) { /* -> bb2671 */ }
    if (((SF != OF) | (t_14003a6bb == 0x0_u32)) != 0) { /* -> bb2686 */ }

    // ---- bb2671 @ 0x14003a6c1 ----
    // intrinsic: f30f1040 movss xmm0, dword ptr [rax - 0x28]
    // intrinsic: f30f59c2 mulss xmm0, xmm2
    // intrinsic: f30f1140 movss dword ptr [rax - 0x28], xmm0
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax - 0x24]
    // intrinsic: f30f59ca mulss xmm1, xmm2
    // intrinsic: f30f1148 movss dword ptr [rax - 0x24], xmm1
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax - 0x20]
    /* 14003a6e2 */ xmm0 = xmm1;
    // intrinsic: 0f54c400 andps xmm0, xmm4
    // intrinsic: 0f2fc500 comiss xmm0, xmm5
    if ((CF | (t_14003a6bb == 0x0_u32)) == false) { /* -> bb2684 */ }
    if ((CF | (t_14003a6bb == 0x0_u32)) != 0) { /* -> bb2683 */ }

    // ---- bb2683 @ 0x14003a6eb ----
    if ((CF | (t_14003a6bb == 0x0_u32)) == false) { /* -> bb2684 */ }
    if ((CF | (t_14003a6bb == 0x0_u32)) != 0) { /* -> bb2686 */ }

    // ---- bb2684 @ 0x14003a6ed ----
    // intrinsic: f30f59cb mulss xmm1, xmm3
    // intrinsic: f30f1148 movss dword ptr [rax - 0x20], xmm1
    /* fallthrough -> bb2686 */

    // ---- bb2686 @ 0x14003a6f6 ----
    /* 14003a6f6 */ let mut t_14003a6f6: u32 = core::ptr::read((rax).wrapping_add(0xc_u64) as *const u32);
    if (((SF != OF) | (t_14003a6f6 == 0x0_u32)) == false) { /* -> bb2690 */ }
    if (((SF != OF) | (t_14003a6f6 == 0x0_u32)) != 0) { /* -> bb2689 */ }

    // ---- bb2689 @ 0x14003a6fa ----
    if (((SF != OF) | (t_14003a6f6 == 0x0_u32)) == false) { /* -> bb2690 */ }
    if (((SF != OF) | (t_14003a6f6 == 0x0_u32)) != 0) { /* -> bb2705 */ }

    // ---- bb2690 @ 0x14003a6fc ----
    // intrinsic: f30f1000 movss xmm0, dword ptr [rax]
    // intrinsic: f30f59c2 mulss xmm0, xmm2
    // intrinsic: f30f1100 movss dword ptr [rax], xmm0
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 4]
    // intrinsic: f30f59ca mulss xmm1, xmm2
    // intrinsic: f30f1148 movss dword ptr [rax + 4], xmm1
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 8]
    /* 14003a71b */ xmm0 = xmm1;
    // intrinsic: 0f54c400 andps xmm0, xmm4
    // intrinsic: 0f2fc500 comiss xmm0, xmm5
    if ((CF | (t_14003a6f6 == 0x0_u32)) == false) { /* -> bb2703 */ }
    if ((CF | (t_14003a6f6 == 0x0_u32)) != 0) { /* -> bb2702 */ }

    // ---- bb2702 @ 0x14003a724 ----
    if ((CF | (t_14003a6f6 == 0x0_u32)) == false) { /* -> bb2703 */ }
    if ((CF | (t_14003a6f6 == 0x0_u32)) != 0) { /* -> bb2705 */ }

    // ---- bb2703 @ 0x14003a726 ----
    // intrinsic: f30f59cb mulss xmm1, xmm3
    // intrinsic: f30f1148 movss dword ptr [rax + 8], xmm1
    /* fallthrough -> bb2705 */

    // ---- bb2705 @ 0x14003a72f ----
    /* 14003a72f */ let mut t_14003a72f: u32 = core::ptr::read((rax).wrapping_add(0x34_u64) as *const u32);
    if (((SF != OF) | (t_14003a72f == 0x0_u32)) == false) { /* -> bb2709 */ }
    if (((SF != OF) | (t_14003a72f == 0x0_u32)) != 0) { /* -> bb2708 */ }

    // ---- bb2708 @ 0x14003a733 ----
    if (((SF != OF) | (t_14003a72f == 0x0_u32)) == false) { /* -> bb2709 */ }
    if (((SF != OF) | (t_14003a72f == 0x0_u32)) != 0) { /* -> bb2724 */ }

    // ---- bb2709 @ 0x14003a735 ----
    // intrinsic: f30f1040 movss xmm0, dword ptr [rax + 0x28]
    // intrinsic: f30f59c2 mulss xmm0, xmm2
    // intrinsic: f30f1140 movss dword ptr [rax + 0x28], xmm0
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0x2c]
    // intrinsic: f30f59ca mulss xmm1, xmm2
    // intrinsic: f30f1148 movss dword ptr [rax + 0x2c], xmm1
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0x30]
    /* 14003a756 */ xmm0 = xmm1;
    // intrinsic: 0f54c400 andps xmm0, xmm4
    // intrinsic: 0f2fc500 comiss xmm0, xmm5
    if ((CF | (t_14003a72f == 0x0_u32)) == false) { /* -> bb2722 */ }
    if ((CF | (t_14003a72f == 0x0_u32)) != 0) { /* -> bb2721 */ }

    // ---- bb2721 @ 0x14003a75f ----
    if ((CF | (t_14003a72f == 0x0_u32)) == false) { /* -> bb2722 */ }
    if ((CF | (t_14003a72f == 0x0_u32)) != 0) { /* -> bb2724 */ }

    // ---- bb2722 @ 0x14003a761 ----
    // intrinsic: f30f59cb mulss xmm1, xmm3
    // intrinsic: f30f1148 movss dword ptr [rax + 0x30], xmm1
    /* fallthrough -> bb2724 */

    // ---- bb2724 @ 0x14003a76a ----
    /* 14003a76a */ let mut t_14003a76a: u32 = core::ptr::read((rax).wrapping_add(0x5c_u64) as *const u32);
    if (((SF != OF) | (t_14003a76a == 0x0_u32)) == false) { /* -> bb2728 */ }
    if (((SF != OF) | (t_14003a76a == 0x0_u32)) != 0) { /* -> bb2727 */ }

    // ---- bb2727 @ 0x14003a76e ----
    if (((SF != OF) | (t_14003a76a == 0x0_u32)) == false) { /* -> bb2728 */ }
    if (((SF != OF) | (t_14003a76a == 0x0_u32)) != 0) { /* -> bb2743 */ }

    // ---- bb2728 @ 0x14003a770 ----
    // intrinsic: f30f1040 movss xmm0, dword ptr [rax + 0x50]
    // intrinsic: f30f59c2 mulss xmm0, xmm2
    // intrinsic: f30f1140 movss dword ptr [rax + 0x50], xmm0
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0x54]
    // intrinsic: f30f59ca mulss xmm1, xmm2
    // intrinsic: f30f1148 movss dword ptr [rax + 0x54], xmm1
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0x58]
    /* 14003a791 */ xmm0 = xmm1;
    // intrinsic: 0f54c400 andps xmm0, xmm4
    // intrinsic: 0f2fc500 comiss xmm0, xmm5
    if ((CF | (t_14003a76a == 0x0_u32)) == false) { /* -> bb2741 */ }
    if ((CF | (t_14003a76a == 0x0_u32)) != 0) { /* -> bb2740 */ }

    // ---- bb2740 @ 0x14003a79a ----
    if ((CF | (t_14003a76a == 0x0_u32)) == false) { /* -> bb2741 */ }
    if ((CF | (t_14003a76a == 0x0_u32)) != 0) { /* -> bb2743 */ }

    // ---- bb2741 @ 0x14003a79c ----
    // intrinsic: f30f59cb mulss xmm1, xmm3
    // intrinsic: f30f1148 movss dword ptr [rax + 0x58], xmm1
    /* fallthrough -> bb2743 */

    // ---- bb2743 @ 0x14003a7a5 ----
    /* 14003a7a5 */ let mut t_14003a7a5_0: u64 = (rax).wrapping_add(0xc8_u64);
    /* 14003a7a5 */ rax = t_14003a7a5_0;
    /* 14003a7ab */ let mut t_14003a7ab_0: u64 = (r15).wrapping_sub(0x1_u64);
    /* 14003a7ab */ r15 = t_14003a7ab_0;
    if (t_14003a76a == 0x0_u32) {
        /* -> bb2748 */
    } else {
        /* -> bb2747 */
    }

    // ---- bb2747 @ 0x14003a7af ----
    if (t_14003a76a != 0x0_u32) {
        /* -> bb2648 */
    } else {
        /* -> bb2748 */
    }

    // ---- bb2748 @ 0x14003a7b5 ----
    /* 14003a7b5 */ r11 = (rsp).wrapping_add(0x148_u64);
    /* 14003a7bd */ xmm6 = core::ptr::read((r11).wrapping_sub(0x18_u64) as *const u128);
    /* 14003a7c2 */ xmm7 = core::ptr::read((r11).wrapping_sub(0x28_u64) as *const u128);
    /* 14003a7c7 */ xmm8 = core::ptr::read((r11).wrapping_sub(0x38_u64) as *const u128);
    /* 14003a7cc */ xmm9 = core::ptr::read((r11).wrapping_sub(0x48_u64) as *const u128);
    /* 14003a7d1 */ xmm10 = core::ptr::read((r11).wrapping_sub(0x58_u64) as *const u128);
    /* 14003a7d6 */ xmm11 = core::ptr::read((r11).wrapping_sub(0x68_u64) as *const u128);
    /* 14003a7db */ let mut xmm12: u128 = core::ptr::read((r11).wrapping_sub(0x78_u64) as *const u128);
    /* 14003a7e0 */ let mut xmm13: u128 = core::ptr::read((r11).wrapping_sub(0x88_u64) as *const u128);
    /* 14003a7e8 */ let mut xmm14: u128 = core::ptr::read((r11).wrapping_sub(0x98_u64) as *const u128);
    /* 14003a7f0 */ let mut xmm15: u128 = core::ptr::read((r11).wrapping_sub(0xa8_u64) as *const u128);
    /* 14003a7f8 */ rsp = r11;
    /* 14003a7fb */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003a7fb */ r15 = core::ptr::read(rsp as *const u64);
    /* 14003a7fd */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003a7fd */ r14 = core::ptr::read(rsp as *const u64);
    /* 14003a7ff */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003a7ff */ r13 = core::ptr::read(rsp as *const u64);
    /* 14003a801 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003a801 */ r12 = core::ptr::read(rsp as *const u64);
    /* 14003a803 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003a803 */ rdi = core::ptr::read(rsp as *const u64);
    /* 14003a804 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003a804 */ rsi = core::ptr::read(rsp as *const u64);
    /* 14003a805 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003a805 */ rbx = core::ptr::read(rsp as *const u64);
    /* 14003a806 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003a806 */ rbp = core::ptr::read(rsp as *const u64);
    /* 14003a807 */ return;
    // <no successors>

    // ---- bb2769 @ 0x14003a808 ----
    /* 14003a808 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 14003a80d */ let mut t_14003a80d_0: u32 = 0x0_u32;
    /* 14003a80d */ r9 = (t_14003a80d_0 as u64);
    /* 14003a810 */ let mut t_14003a810_0: u32 = 0x0_u32;
    /* 14003a810 */ r8 = (t_14003a810_0 as u64);
    /* 14003a813 */ let mut t_14003a813_0: u32 = 0x0_u32;
    /* 14003a813 */ rdx = (t_14003a813_0 as u64);
    /* 14003a815 */ let mut t_14003a815_0: u32 = 0x0_u32;
    /* 14003a815 */ rcx = (t_14003a815_0 as u64);
    /* 14003a817 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb2776 */

    // ---- bb2776 @ 0x14003a81d ----
    /* 14003a81d */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 14003a822 */ let mut t_14003a822_0: u32 = 0x0_u32;
    /* 14003a822 */ r9 = (t_14003a822_0 as u64);
    /* 14003a825 */ let mut t_14003a825_0: u32 = 0x0_u32;
    /* 14003a825 */ r8 = (t_14003a825_0 as u64);
    /* 14003a828 */ let mut t_14003a828_0: u32 = 0x0_u32;
    /* 14003a828 */ rdx = (t_14003a828_0 as u64);
    /* 14003a82a */ let mut t_14003a82a_0: u32 = 0x0_u32;
    /* 14003a82a */ rcx = (t_14003a82a_0 as u64);
    /* 14003a82c */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb2783 */

    // ---- bb2783 @ 0x14003a832 ----
    /* 14003a832 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 14003a837 */ let mut t_14003a837_0: u32 = 0x0_u32;
    /* 14003a837 */ r9 = (t_14003a837_0 as u64);
    /* 14003a83a */ let mut t_14003a83a_0: u32 = 0x0_u32;
    /* 14003a83a */ r8 = (t_14003a83a_0 as u64);
    /* 14003a83d */ let mut t_14003a83d_0: u32 = 0x0_u32;
    /* 14003a83d */ rdx = (t_14003a83d_0 as u64);
    /* 14003a83f */ let mut t_14003a83f_0: u32 = 0x0_u32;
    /* 14003a83f */ rcx = (t_14003a83f_0 as u64);
    /* 14003a841 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb2790 */

    // ---- bb2790 @ 0x14003a847 ----
    /* 14003a847 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 14003a84c */ let mut t_14003a84c_0: u32 = 0x0_u32;
    /* 14003a84c */ r9 = (t_14003a84c_0 as u64);
    /* 14003a84f */ let mut t_14003a84f_0: u32 = 0x0_u32;
    /* 14003a84f */ r8 = (t_14003a84f_0 as u64);
    /* 14003a852 */ let mut t_14003a852_0: u32 = 0x0_u32;
    /* 14003a852 */ rdx = (t_14003a852_0 as u64);
    /* 14003a854 */ let mut t_14003a854_0: u32 = 0x0_u32;
    /* 14003a854 */ rcx = (t_14003a854_0 as u64);
    /* 14003a856 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb2797 */

    // ---- bb2797 @ 0x14003a85c ----
    /* 14003a85c */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 14003a861 */ let mut t_14003a861_0: u32 = 0x0_u32;
    /* 14003a861 */ r9 = (t_14003a861_0 as u64);
    /* 14003a864 */ let mut t_14003a864_0: u32 = 0x0_u32;
    /* 14003a864 */ r8 = (t_14003a864_0 as u64);
    /* 14003a867 */ let mut t_14003a867_0: u32 = 0x0_u32;
    /* 14003a867 */ rdx = (t_14003a867_0 as u64);
    /* 14003a869 */ let mut t_14003a869_0: u32 = 0x0_u32;
    /* 14003a869 */ rcx = (t_14003a869_0 as u64);
    /* 14003a86b */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb2804 */

    // ---- bb2804 @ 0x14003a871 ----
    /* 14003a871 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 14003a876 */ let mut t_14003a876_0: u32 = 0x0_u32;
    /* 14003a876 */ r9 = (t_14003a876_0 as u64);
    /* 14003a879 */ let mut t_14003a879_0: u32 = 0x0_u32;
    /* 14003a879 */ r8 = (t_14003a879_0 as u64);
    /* 14003a87c */ let mut t_14003a87c_0: u32 = 0x0_u32;
    /* 14003a87c */ rdx = (t_14003a87c_0 as u64);
    /* 14003a87e */ let mut t_14003a87e_0: u32 = 0x0_u32;
    /* 14003a87e */ rcx = (t_14003a87e_0 as u64);
    /* 14003a880 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb2811 */

    // ---- bb2811 @ 0x14003a886 ----
    /* 14003a886 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 14003a88b */ let mut t_14003a88b_0: u32 = 0x0_u32;
    /* 14003a88b */ r9 = (t_14003a88b_0 as u64);
    /* 14003a88e */ let mut t_14003a88e_0: u32 = 0x0_u32;
    /* 14003a88e */ r8 = (t_14003a88e_0 as u64);
    /* 14003a891 */ let mut t_14003a891_0: u32 = 0x0_u32;
    /* 14003a891 */ rdx = (t_14003a891_0 as u64);
    /* 14003a893 */ let mut t_14003a893_0: u32 = 0x0_u32;
    /* 14003a893 */ rcx = (t_14003a893_0 as u64);
    /* 14003a895 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb2818 */

    // ---- bb2818 @ 0x14003a89b ----
    /* 14003a89b */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 14003a8a0 */ let mut t_14003a8a0_0: u32 = 0x0_u32;
    /* 14003a8a0 */ r9 = (t_14003a8a0_0 as u64);
    /* 14003a8a3 */ let mut t_14003a8a3_0: u32 = 0x0_u32;
    /* 14003a8a3 */ r8 = (t_14003a8a3_0 as u64);
    /* 14003a8a6 */ let mut t_14003a8a6_0: u32 = 0x0_u32;
    /* 14003a8a6 */ rdx = (t_14003a8a6_0 as u64);
    /* 14003a8a8 */ let mut t_14003a8a8_0: u32 = 0x0_u32;
    /* 14003a8a8 */ rcx = (t_14003a8a8_0 as u64);
    /* 14003a8aa */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb2825 */

    // ---- bb2825 @ 0x14003a8b0 ----
    /* 14003a8b0 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 14003a8b5 */ let mut t_14003a8b5_0: u32 = 0x0_u32;
    /* 14003a8b5 */ r9 = (t_14003a8b5_0 as u64);
    /* 14003a8b8 */ let mut t_14003a8b8_0: u32 = 0x0_u32;
    /* 14003a8b8 */ r8 = (t_14003a8b8_0 as u64);
    /* 14003a8bb */ let mut t_14003a8bb_0: u32 = 0x0_u32;
    /* 14003a8bb */ rdx = (t_14003a8bb_0 as u64);
    /* 14003a8bd */ let mut t_14003a8bd_0: u32 = 0x0_u32;
    /* 14003a8bd */ rcx = (t_14003a8bd_0 as u64);
    /* 14003a8bf */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb2832 */

    // ---- bb2832 @ 0x14003a8c5 ----
    /* 14003a8c5 */ rcx = (0x14003a8cc_u64).wrapping_add(0x3af8c8_u64);
    /* 14003a8cc */ fn_1402c7548();
    /* 14003a8d1 */ let mut t_14003a8d1: u32 = core::ptr::read((0x14003a8d8_u64).wrapping_add(0x3af8bc_u64) as *const u32);
    if (t_14003a8d1 == 0xffffffff_u32) {
        /* -> bb2838 */
    } else {
        /* -> bb2837 */
    }

    // ---- bb2837 @ 0x14003a8d8 ----
    if (t_14003a8d1 != 0xffffffff_u32) {
        /* -> bb2128 */
    } else {
        /* -> bb2838 */
    }

    // ---- bb2838 @ 0x14003a8de ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003a8e1 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u128, xmm0);
    /* 14003a8e6 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u64, 0x4_u64);
    /* 14003a8ee */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u64, 0xf_u64);
    /* 14003a8f6 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u32, 0x6c6c6942_u32);
    /* 14003a8fe */ core::ptr::write((rsp).wrapping_add(0x74_u64) as *mut u8, 0x0_u8);
    /* 14003a903 */ rcx = (rsp).wrapping_add(0x70_u64);
    /* 14003a908 */ fn_14006fd40();
    /* 14003a90d */ core::ptr::write((0x14003a913_u64).wrapping_add(0x3af87d_u64) as *mut u32, (rax as u32));
    /* 14003a913 */ rcx = (0x14003a91a_u64).wrapping_add(0x3af87a_u64);
    /* 14003a91a */ fn_1402c74dc();
    /* fallthrough -> bb2128 */

    // ---- bb2850 @ 0x14003a924 ----
    /* 14003a924 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r13);
    /* 14003a929 */ let mut t_14003a929_0: u32 = 0x0_u32;
    /* 14003a929 */ r9 = (t_14003a929_0 as u64);
    /* 14003a92c */ let mut t_14003a92c_0: u32 = 0x0_u32;
    /* 14003a92c */ r8 = (t_14003a92c_0 as u64);
    /* 14003a92f */ let mut t_14003a92f_0: u32 = 0x0_u32;
    /* 14003a92f */ rdx = (t_14003a92f_0 as u64);
    /* 14003a931 */ let mut t_14003a931_0: u32 = 0x0_u32;
    /* 14003a931 */ rcx = (t_14003a931_0 as u64);
    /* 14003a933 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    // intrinsic: cc000000 int3 
    /* 14003a940 */ rax = rsp;
    /* 14003a943 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003a943 */ core::ptr::write(rsp as *mut u64, rbp);
    /* 14003a944 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003a944 */ core::ptr::write(rsp as *mut u64, rbx);
    /* 14003a945 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003a945 */ core::ptr::write(rsp as *mut u64, rsi);
    /* 14003a946 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003a946 */ core::ptr::write(rsp as *mut u64, rdi);
    /* 14003a947 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003a947 */ core::ptr::write(rsp as *mut u64, r12);
    /* 14003a949 */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003a949 */ core::ptr::write(rsp as *mut u64, r13);
    /* 14003a94b */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003a94b */ core::ptr::write(rsp as *mut u64, r14);
    /* 14003a94d */ rsp = (rsp).wrapping_sub(0x8_u64);
    /* 14003a94d */ core::ptr::write(rsp as *mut u64, r15);
    /* 14003a94f */ rbp = (rsp).wrapping_sub(0x48_u64);
    /* 14003a954 */ let mut t_14003a954_0: u64 = (rsp).wrapping_sub(0x148_u64);
    /* 14003a954 */ rsp = t_14003a954_0;
    /* 14003a95b */ core::ptr::write((rax).wrapping_sub(0x58_u64) as *mut u128, xmm6);
    /* 14003a95f */ core::ptr::write((rax).wrapping_sub(0x68_u64) as *mut u128, xmm7);
    /* 14003a963 */ core::ptr::write((rax).wrapping_sub(0x78_u64) as *mut u128, xmm8);
    /* 14003a968 */ core::ptr::write((rax).wrapping_sub(0x88_u64) as *mut u128, xmm9);
    /* 14003a970 */ core::ptr::write((rax).wrapping_sub(0x98_u64) as *mut u128, xmm10);
    /* 14003a978 */ core::ptr::write((rax).wrapping_sub(0xa8_u64) as *mut u128, xmm11);
    /* 14003a980 */ core::ptr::write((rax).wrapping_sub(0xb8_u64) as *mut u128, xmm12);
    /* 14003a988 */ core::ptr::write((rax).wrapping_sub(0xc8_u64) as *mut u128, xmm13);
    /* 14003a990 */ core::ptr::write((rax).wrapping_sub(0xd8_u64) as *mut u128, xmm14);
    /* 14003a998 */ core::ptr::write((rax).wrapping_sub(0xe8_u64) as *mut u128, xmm15);
    /* 14003a9a0 */ rdi = rcx;
    /* 14003a9a3 */ let mut t_14003a9a3: u32 = core::ptr::read((rcx).wrapping_add(0x25c_u64) as *const u32);
    /* 14003a9a3 */ rcx = (t_14003a9a3 as u64);
    /* 14003a9a9 */ rax = (((rcx).wrapping_sub(0x2_u64) as u32) as u64);
    /* 14003a9ac */ r15 = (0x4_u32 as u64);
    /* 14003a9b2 */ let mut t_14003a9b2_0: u32 = 0x0_u32;
    /* 14003a9b2 */ r13 = (t_14003a9b2_0 as u64);
    /* 14003a9b5 */ let mut t_14003a9b5: u32 = core::ptr::read((0x14003a9bc_u64).wrapping_add(0x3c3d74_u64) as *const u32);
    /* 14003a9b5 */ r14 = (t_14003a9b5 as u64);
    // intrinsic: 450f57e4 xorps xmm12, xmm12
    // intrinsic: f3440f10 movss xmm9, dword ptr [rip + 0x3622ef]
    // intrinsic: f3440f10 movss xmm10, dword ptr [rip + 0x3622d2]
    // intrinsic: f3440f10 movss xmm11, dword ptr [rip + 0x362305]
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x2c95ec]
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2c95d0]
    if (((CF == false) & ((rax as u32) != 0x5_u32)) == false) { /* -> bb2901 */ }
    if (((CF == false) & ((rax as u32) != 0x5_u32)) != 0) { /* -> bb2900 */ }

    // ---- bb2900 @ 0x14003a9ef ----
    if (((CF == false) & ((rax as u32) != 0x5_u32)) == false) { /* -> bb2901 */ }
    if (((CF == false) & ((rax as u32) != 0x5_u32)) != 0) { /* -> bb3483 */ }

    // ---- bb2901 @ 0x14003a9f5 ----
    if ((rcx as u32) == 0x2_u32) {
        /* -> bb2905 */
    } else {
        /* -> bb2904 */
    }

    // ---- bb2904 @ 0x14003a9f8 ----
    if ((rcx as u32) == 0x2_u32) {
        /* -> bb2905 */
    } else {
        /* -> bb2909 */
    }

    // ---- bb2905 @ 0x14003a9fa ----
    /* 14003a9fa */ let mut t_14003a9fa: u32 = core::ptr::read((0x14003aa00_u64).wrapping_add(0x3999b8_u64) as *const u32);
    /* 14003a9fa */ rcx = (t_14003a9fa as u64);
    /* 14003aa00 */ fn_140070f40();
    /* fallthrough -> bb2907 */

    // ---- bb2907 @ 0x14003aa05 ----
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x2c897e]
    /* fallthrough -> bb3296 */

    // ---- bb2909 @ 0x14003aa13 ----
    if (((SF != OF) | ((rcx as u32) == 0x2_u32)) == false) { /* -> bb2912 */ }
    if (((SF != OF) | ((rcx as u32) == 0x2_u32)) != 0) { /* -> bb2911 */ }

    // ---- bb2911 @ 0x14003aa13 ----
    if (((SF != OF) | ((rcx as u32) == 0x2_u32)) != 0) { /* -> bb2907 */ }
    if (((SF != OF) | ((rcx as u32) == 0x2_u32)) == false) { /* -> bb2912 */ }

    // ---- bb2912 @ 0x14003aa15 ----
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2c95ff]
    /* 14003aa1d */ let mut t_14003aa1d: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_14003aa1d == 0x5_u32) {
        /* -> bb2917 */
    } else {
        /* -> bb2916 */
    }

    // ---- bb2916 @ 0x14003aa24 ----
    if (t_14003aa1d == 0x5_u32) {
        /* -> bb2917 */
    } else {
        /* -> bb2920 */
    }

    // ---- bb2917 @ 0x14003aa26 ----
    /* 14003aa26 */ let mut t_14003aa26: u32 = core::ptr::read((0x14003aa2c_u64).wrapping_add(0x39998c_u64) as *const u32);
    /* 14003aa26 */ rcx = (t_14003aa26 as u64);
    /* 14003aa2c */ fn_140070f40();
    /* fallthrough -> bb2940 */

    // ---- bb2920 @ 0x14003aa33 ----
    /* 14003aa33 */ let mut t_14003aa33: u32 = core::ptr::read((0x14003aa39_u64).wrapping_add(0x3999e3_u64) as *const u32);
    /* 14003aa33 */ rcx = (t_14003aa33 as u64);
    /* 14003aa39 */ fn_140070f40();
    /* 14003aa3e */ let mut t_14003aa3e: u32 = core::ptr::read((0x14003aa44_u64).wrapping_add(0x2d0c90_u64) as *const u32);
    /* 14003aa3e */ rcx = (t_14003aa3e as u64);
    /* 14003aa44 */ let mut t_14003aa44: u32 = core::ptr::read((0x14003aa4a_u64).wrapping_add(0x3b2fba_u64) as *const u32);
    /* 14003aa44 */ rax = (t_14003aa44 as u64);
    /* 14003aa4a */ let mut t_14003aa4a_0: u32 = ((rax as u32)).wrapping_add(0xffffffc0_u32);
    /* 14003aa4a */ rax = (t_14003aa4a_0 as u64);
    /* 14003aa4d */ let mut t_14003aa4d_0: u32 = ((rcx as u32)).wrapping_add((rax as u32));
    /* 14003aa4d */ rcx = (t_14003aa4d_0 as u64);
    /* 14003aa4f */ xmm3 = ((rcx as u32) as u128);
    // intrinsic: 0f5bdb00 cvtdq2ps xmm3, xmm3
    /* 14003aa56 */ let mut t_14003aa56: u32 = core::ptr::read((0x14003aa5c_u64).wrapping_add(0x2d0c74_u64) as *const u32);
    /* 14003aa56 */ rax = (t_14003aa56 as u64);
    /* 14003aa5c */ let mut t_14003aa5c: u32 = core::ptr::read((0x14003aa62_u64).wrapping_add(0x3b2f9e_u64) as *const u32);
    /* 14003aa5c */ rcx = (t_14003aa5c as u64);
    /* 14003aa62 */ rax = (((rax).wrapping_add((rcx).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 14003aa65 */ xmm2 = ((rax as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 14003aa6c */ let mut t_14003aa6c_0: u32 = (0x0_u32).wrapping_sub((rcx as u32));
    /* 14003aa6c */ rcx = (t_14003aa6c_0 as u64);
    /* 14003aa6e */ xmm0 = ((rcx as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    /* 14003aa75 */ let mut t_14003aa75: u32 = core::ptr::read((0x14003aa7b_u64).wrapping_add(0x399969_u64) as *const u32);
    /* 14003aa75 */ rax = (t_14003aa75 as u64);
    /* 14003aa7b */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 14003aa7f */ xmm1 = xmm6;
    /* 14003aa82 */ fn_140070fb0();
    /* fallthrough -> bb2940 */

    // ---- bb2940 @ 0x14003aa87 ----
    /* 14003aa87 */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14003aa90 */ r12 = core::ptr::read((rax).wrapping_add((r14).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003aa94 */ let mut t_14003aa94: u32 = core::ptr::read((r12).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003aa94 */ rax = (t_14003aa94 as u64);
    /* 14003aa98 */ let mut t_14003aa98: u32 = core::ptr::read((0x14003aa9e_u64).wrapping_add(0x3af6fe_u64) as *const u32);
    if (((SF == OF) & (t_14003aa98 != (rax as u32))) == false) { /* -> bb2947 */ }
    if (((SF == OF) & (t_14003aa98 != (rax as u32))) != 0) { /* -> bb2946 */ }

    // ---- bb2946 @ 0x14003aa9e ----
    if (((SF == OF) & (t_14003aa98 != (rax as u32))) == false) { /* -> bb2947 */ }
    if (((SF == OF) & (t_14003aa98 != (rax as u32))) != 0) { /* -> bb4478 */ }

    // ---- bb2947 @ 0x14003aaa4 ----
    // intrinsic: 0f57d200 xorps xmm2, xmm2
    /* 14003aaa7 */ xmm1 = xmm9;
    /* 14003aaab */ let mut t_14003aaab: u32 = core::ptr::read((0x14003aab1_u64).wrapping_add(0x3af6e7_u64) as *const u32);
    /* 14003aaab */ rcx = (t_14003aaab as u64);
    /* 14003aab1 */ fn_140071cd0();
    /* 14003aab6 */ let mut t_14003aab6: u32 = core::ptr::read((0x14003aabc_u64).wrapping_add(0x2d0c14_u64) as *const u32);
    /* 14003aab6 */ rax = (t_14003aab6 as u64);
    /* 14003aabc */ let mut t_14003aabc_0: u32 = ((rax as u32)).wrapping_add(0xfffffff6_u32);
    /* 14003aabc */ rax = (t_14003aabc_0 as u64);
    /* 14003aabf */ xmm1 = ((rax as u32) as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm10
    /* 14003aacd */ xmm3 = xmm11;
    // intrinsic: 0f57d200 xorps xmm2, xmm2
    /* 14003aad4 */ let mut t_14003aad4: u32 = core::ptr::read((0x14003aada_u64).wrapping_add(0x3af6be_u64) as *const u32);
    /* 14003aad4 */ rcx = (t_14003aad4 as u64);
    /* 14003aada */ fn_140071e80();
    /* 14003aadf */ rcx = (0x40_u32 as u64);
    /* 14003aae4 */ fn_140072700();
    /* 14003aae9 */ let mut t_14003aae9: u32 = core::ptr::read((0x14003aaef_u64).wrapping_add(0x3af6a9_u64) as *const u32);
    /* 14003aae9 */ rcx = (t_14003aae9 as u64);
    /* 14003aaef */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    // intrinsic: 0f57d200 xorps xmm2, xmm2
    /* 14003aaf4 */ xmm1 = xmm9;
    /* 14003aaf8 */ fn_140071cd0();
    /* 14003aafd */ let mut t_14003aafd: u32 = core::ptr::read((0x14003ab03_u64).wrapping_add(0x2d0bcd_u64) as *const u32);
    /* 14003aafd */ rax = (t_14003aafd as u64);
    /* 14003ab03 */ let mut t_14003ab03_0: u32 = ((rax as u32)).wrapping_add(0xfffffff6_u32);
    /* 14003ab03 */ rax = (t_14003ab03_0 as u64);
    /* 14003ab06 */ xmm1 = ((rax as u32) as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    /* 14003ab0d */ let mut t_14003ab0d: u32 = core::ptr::read((0x14003ab13_u64).wrapping_add(0x3af685_u64) as *const u32);
    /* 14003ab0d */ rcx = (t_14003ab0d as u64);
    /* 14003ab13 */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm10
    /* 14003ab1c */ xmm3 = xmm11;
    // intrinsic: 0f57d200 xorps xmm2, xmm2
    /* 14003ab23 */ fn_140071e80();
    /* 14003ab28 */ fn_140072790();
    /* 14003ab2d */ let mut t_14003ab2d: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_14003ab2d != 0x5_u32) {
        /* -> bb2982 */
    } else {
        /* -> bb2981 */
    }

    // ---- bb2981 @ 0x14003ab34 ----
    if (t_14003ab2d != 0x5_u32) {
        /* -> bb2982 */
    } else {
        /* -> bb3281 */
    }

    // ---- bb2982 @ 0x14003ab3a ----
    /* 14003ab3a */ let mut t_14003ab3a: u32 = core::ptr::read((r12).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003ab3a */ rax = (t_14003ab3a as u64);
    /* 14003ab3e */ let mut t_14003ab3e: u32 = core::ptr::read((0x14003ab44_u64).wrapping_add(0x3af660_u64) as *const u32);
    if (((SF == OF) & (t_14003ab3e != (rax as u32))) == false) { /* -> bb2987 */ }
    if (((SF == OF) & (t_14003ab3e != (rax as u32))) != 0) { /* -> bb2986 */ }

    // ---- bb2986 @ 0x14003ab44 ----
    if (((SF == OF) & (t_14003ab3e != (rax as u32))) == false) { /* -> bb2987 */ }
    if (((SF == OF) & (t_14003ab3e != (rax as u32))) != 0) { /* -> bb4505 */ }

    // ---- bb2987 @ 0x14003ab4a ----
    /* 14003ab4a */ let mut t_14003ab4a: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    if (t_14003ab4a == 0x6_u32) {
        /* -> bb2991 */
    } else {
        /* -> bb2990 */
    }

    // ---- bb2990 @ 0x14003ab51 ----
    if (t_14003ab4a == 0x6_u32) {
        /* -> bb2991 */
    } else {
        /* -> bb3007 */
    }

    // ---- bb2991 @ 0x14003ab53 ----
    /* 14003ab53 */ rax = (0x66666667_u32 as u64);
    /* 14003ab58 */ let mut t_14003ab58: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 14003ab58 */ let mut t_14003ab58_0: u64 = (((rax as u32) as u64)).wrapping_mul((t_14003ab58 as u64));
    /* 14003ab58 */ rdx = (((t_14003ab58_0 >> 0x20_u64) as u32) as u64);
    /* 14003ab58 */ rax = ((t_14003ab58_0 as u32) as u64);
    /* 14003ab5e */ rbx = ((rdx as u32) as u64);
    /* 14003ab60 */ rbx = (((((rbx as u32) as i64) >> ((0x2_u8 as u32) as i64)) as u64) as u64);
    /* 14003ab63 */ rax = ((rbx as u32) as u64);
    /* 14003ab65 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 14003ab68 */ let mut t_14003ab68_0: u32 = ((rbx as u32)).wrapping_add((rax as u32));
    /* 14003ab68 */ rbx = (t_14003ab68_0 as u64);
    /* 14003ab6a */ let mut t_14003ab6a_0: u32 = ((rbx as u32) & 0x80000001_u32);
    /* 14003ab6a */ rbx = (t_14003ab6a_0 as u64);
    if (SF != OF) {
        /* -> bb3002 */
    } else {
        /* -> bb3001 */
    }

    // ---- bb3001 @ 0x14003ab70 ----
    if (SF != OF) {
        /* -> bb3002 */
    } else {
        /* -> bb3005 */
    }

    // ---- bb3002 @ 0x14003ab72 ----
    /* 14003ab72 */ rbx = (((rbx as u32)).wrapping_sub(0x1_u32) as u64);
    /* 14003ab74 */ let mut t_14003ab74_0: u32 = ((rbx as u32) | 0xfffffffe_u32);
    /* 14003ab74 */ rbx = (t_14003ab74_0 as u64);
    /* 14003ab77 */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb3005 */

    // ---- bb3005 @ 0x14003ab79 ----
    /* 14003ab79 */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb3008 */

    // ---- bb3007 @ 0x14003ab7d ----
    /* 14003ab7d */ rbx = ((r13 as u32) as u64);
    /* fallthrough -> bb3008 */

    // ---- bb3008 @ 0x14003ab80 ----
    /* 14003ab80 */ let mut t_14003ab80: u32 = core::ptr::read((0x14003ab86_u64).wrapping_add(0x3af61a_u64) as *const u32);
    /* 14003ab80 */ rcx = (t_14003ab80 as u64);
    /* 14003ab86 */ let mut t_14003ab86_0: u32 = ((rcx as u32)).wrapping_add((rbx as u32));
    /* 14003ab86 */ rcx = (t_14003ab86_0 as u64);
    /* 14003ab88 */ xmm2 = xmm6;
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    /* 14003ab8e */ fn_140071cd0();
    /* 14003ab93 */ let mut t_14003ab93: u32 = core::ptr::read((0x14003ab9b_u64).wrapping_add(0x2d0b35_u64) as *const u32);
    /* 14003ab93 */ xmm1 = (t_14003ab93 as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    /* 14003ab9e */ let mut t_14003ab9e: u32 = core::ptr::read((0x14003aba4_u64).wrapping_add(0x3af5fc_u64) as *const u32);
    /* 14003ab9e */ rcx = (t_14003ab9e as u64);
    /* 14003aba4 */ let mut t_14003aba4_0: u32 = ((rcx as u32)).wrapping_add((rbx as u32));
    /* 14003aba4 */ rcx = (t_14003aba4_0 as u64);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm10
    /* 14003abad */ xmm3 = xmm11;
    /* 14003abb1 */ xmm2 = xmm6;
    /* 14003abb4 */ fn_140071e80();
    if (t_14003ab4a == 0x6_u32) {
        /* -> bb3025 */
    } else {
        /* -> bb3024 */
    }

    // ---- bb3024 @ 0x14003abbb ----
    if (t_14003ab4a == 0x6_u32) {
        /* -> bb3025 */
    } else {
        /* -> bb3149 */
    }

    // ---- bb3025 @ 0x14003abc1 ----
    /* 14003abc1 */ rdx = (rbp).wrapping_add(0x90_u64);
    /* 14003abc8 */ rcx = core::ptr::read((rdi).wrapping_add(0x260_u64) as *const u64);
    /* 14003abcf */ fn_1400b4a00();
    // intrinsic: f30f1008 movss xmm1, dword ptr [rax]
    // intrinsic: f3410f59 mulss xmm1, xmm8
    // intrinsic: f30f118d movss dword ptr [rbp + 0x98], xmm1
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 4]
    // intrinsic: f3410f59 mulss xmm2, xmm8
    // intrinsic: f30f1087 movss xmm0, dword ptr [rdi + 0x110]
    // intrinsic: f3410f59 mulss xmm0, xmm8
    // intrinsic: f30f5cd0 subss xmm2, xmm0
    // intrinsic: f30f1195 movss dword ptr [rbp + 0xa0], xmm2
    /* 14003ac08 */ rsi = ((r13 as u32) as u64);
    /* 14003ac0b */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb3039 */ }
    if DF { /* -> bb3040 */ }

    // ---- bb3039 @ 0x14003ac0b ----
    /* 14003ac0b */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003ac0b */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb3041 */

    // ---- bb3040 @ 0x14003ac0b ----
    /* 14003ac0b */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003ac0b */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb3041 */

    // ---- bb3041 @ 0x14003ac14 ----
    /* 14003ac14 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb3043 */ }
    if DF { /* -> bb3044 */ }

    // ---- bb3043 @ 0x14003ac14 ----
    /* 14003ac14 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003ac14 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb3045 */

    // ---- bb3044 @ 0x14003ac14 ----
    /* 14003ac14 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003ac14 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb3045 */

    // ---- bb3045 @ 0x14003ac1d ----
    /* fallthrough -> bb3047 */

    // ---- bb3047 @ 0x14003ac20 ----
    /* 14003ac20 */ xmm8 = ((rsi as u32) as u128);
    // intrinsic: f3450fe6 cvtdq2pd xmm8, xmm8
    /* 14003ac2a */ xmm0 = xmm8;
    // intrinsic: f20f5905 mulsd xmm0, qword ptr [rip + 0x2c9f7a]
    // intrinsic: f20f5805 addsd xmm0, qword ptr [rip + 0x2c9f8a]
    // intrinsic: 660f5ad8 cvtpd2ps xmm3, xmm0
    // intrinsic: f30f119d movss dword ptr [rbp + 0x90], xmm3
    /* 14003ac4a */ rbx = ((r13 as u32) as u64);
    // intrinsic: f2450f58 addsd xmm8, xmm8
    /* 14003ac52 */ xmm9 = xmm2;
    // intrinsic: f3440f5c subss xmm9, xmm3
    /* 14003ac5b */ xmm14 = xmm9;
    // intrinsic: f3450f59 mulss xmm14, xmm9
    /* fallthrough -> bb3060 */

    // ---- bb3060 @ 0x14003ac64 ----
    if CF {
        /* -> bb3064 */
    } else {
        /* -> bb3063 */
    }

    // ---- bb3063 @ 0x14003ac67 ----
    if CF {
        /* -> bb3064 */
    } else {
        /* -> bb3070 */
    }

    // ---- bb3064 @ 0x14003ac69 ----
    /* 14003ac69 */ xmm0 = ((rbx as u32) as u128);
    // intrinsic: f30fe6c0 cvtdq2pd xmm0, xmm0
    // intrinsic: f2410f59 mulsd xmm0, xmm13
    // intrinsic: f20f5805 addsd xmm0, qword ptr [rip + 0x2c9f2a]
    // intrinsic: f2410f58 addsd xmm0, xmm8
    /* fallthrough -> bb3076 */

    // ---- bb3070 @ 0x14003ac85 ----
    /* 14003ac85 */ rax = (((rbx).wrapping_sub(0x11_u64) as u32) as u64);
    /* 14003ac88 */ xmm0 = ((rax as u32) as u128);
    // intrinsic: f30fe6c0 cvtdq2pd xmm0, xmm0
    // intrinsic: f2410f59 mulsd xmm0, xmm13
    // intrinsic: f20f5805 addsd xmm0, qword ptr [rip + 0x2c9f33]
    // intrinsic: f2410f5c subsd xmm0, xmm8
    /* fallthrough -> bb3076 */

    // ---- bb3076 @ 0x14003aca2 ----
    // intrinsic: 66440f5a cvtpd2ps xmm11, xmm0
    /* 14003aca7 */ xmm6 = xmm1;
    // intrinsic: f3410f5c subss xmm6, xmm11
    /* 14003acaf */ xmm1 = xmm6;
    // intrinsic: f30f59ce mulss xmm1, xmm6
    // intrinsic: f3410f58 addss xmm1, xmm14
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    // intrinsic: 0f2ec100 ucomiss xmm0, xmm1
    if (((CF == false) & ((rbx as u32) != 0x11_u32)) == false) { /* -> bb3087 */ }
    if (((CF == false) & ((rbx as u32) != 0x11_u32)) != 0) { /* -> bb3086 */ }

    // ---- bb3086 @ 0x14003acc1 ----
    if (((CF == false) & ((rbx as u32) != 0x11_u32)) == false) { /* -> bb3087 */ }
    if (((CF == false) & ((rbx as u32) != 0x11_u32)) != 0) { /* -> bb3089 */ }

    // ---- bb3087 @ 0x14003acc3 ----
    // intrinsic: f30f51c9 sqrtss xmm1, xmm1
    /* fallthrough -> bb3093 */

    // ---- bb3089 @ 0x14003acc9 ----
    /* 14003acc9 */ xmm0 = xmm1;
    /* 14003accc */ fn_1402ce3b0();
    /* 14003acd1 */ xmm1 = xmm0;
    // intrinsic: f30f109d movss xmm3, dword ptr [rbp + 0x90]
    /* fallthrough -> bb3093 */

    // ---- bb3093 @ 0x14003acdc ----
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x361f6c]
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if ((CF | ((rbx as u32) == 0x11_u32)) == false) { /* -> bb3098 */ }
    if ((CF | ((rbx as u32) == 0x11_u32)) != 0) { /* -> bb3097 */ }

    // ---- bb3097 @ 0x14003ace7 ----
    if ((CF | ((rbx as u32) == 0x11_u32)) == false) { /* -> bb3098 */ }
    if ((CF | ((rbx as u32) == 0x11_u32)) != 0) { /* -> bb3101 */ }

    // ---- bb3098 @ 0x14003ace9 ----
    /* 14003ace9 */ xmm1 = xmm12;
    /* 14003aced */ xmm2 = xmm9;
    /* fallthrough -> bb3105 */

    // ---- bb3101 @ 0x14003acf3 ----
    /* 14003acf3 */ xmm2 = xmm10;
    // intrinsic: f30f5ed1 divss xmm2, xmm1
    // intrinsic: f30f59f2 mulss xmm6, xmm2
    // intrinsic: f3410f59 mulss xmm2, xmm9
    /* fallthrough -> bb3105 */

    // ---- bb3105 @ 0x14003ad04 ----
    // intrinsic: f30f5e0d divss xmm1, dword ptr [rip + 0x2c92d8]
    // intrinsic: f30f5d0d minss xmm1, dword ptr [rip + 0x361f80]
    /* 14003ad14 */ xmm0 = xmm1;
    // intrinsic: f30f59c2 mulss xmm0, xmm2
    // intrinsic: f30f58c3 addss xmm0, xmm3
    // intrinsic: f30f5ac0 cvtss2sd xmm0, xmm0
    // intrinsic: f2410f5c subsd xmm0, xmm15
    // intrinsic: 0f57ff00 xorps xmm7, xmm7
    // intrinsic: f20f5af8 cvtsd2ss xmm7, xmm0
    // intrinsic: f30f59ce mulss xmm1, xmm6
    // intrinsic: f3410f58 addss xmm1, xmm11
    // intrinsic: 0f57f600 xorps xmm6, xmm6
    // intrinsic: f30f5af1 cvtss2sd xmm6, xmm1
    /* 14003ad3f */ xmm0 = xmm6;
    // intrinsic: f20f5c05 subsd xmm0, qword ptr [rip + 0x2c9e4e]
    // intrinsic: 660f5ac0 cvtpd2ps xmm0, xmm0
    /* 14003ad4e */ let mut t_14003ad4e: u32 = core::ptr::read((0x14003ad54_u64).wrapping_add(0x399694_u64) as *const u32);
    /* 14003ad4e */ rax = (t_14003ad4e as u64);
    /* 14003ad54 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 14003ad58 */ xmm3 = xmm10;
    /* 14003ad5c */ xmm2 = xmm10;
    /* 14003ad60 */ xmm1 = xmm7;
    /* 14003ad63 */ fn_140070fb0();
    // intrinsic: f2410f58 addsd xmm6, xmm15
    // intrinsic: 660f5ac6 cvtpd2ps xmm0, xmm6
    /* 14003ad71 */ let mut t_14003ad71: u32 = core::ptr::read((0x14003ad77_u64).wrapping_add(0x399671_u64) as *const u32);
    /* 14003ad71 */ rax = (t_14003ad71 as u64);
    /* 14003ad77 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 14003ad7b */ xmm3 = xmm10;
    /* 14003ad7f */ xmm2 = xmm10;
    /* 14003ad83 */ xmm1 = xmm7;
    /* 14003ad86 */ fn_140070fb0();
    /* 14003ad8b */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    // intrinsic: f30f109d movss xmm3, dword ptr [rbp + 0x90]
    // intrinsic: f30f108d movss xmm1, dword ptr [rbp + 0x98]
    if (SF == OF) {
        /* -> bb3142 */
    } else {
        /* -> bb3141 */
    }

    // ---- bb3141 @ 0x14003ada0 ----
    if (SF != OF) {
        /* -> bb3060 */
    } else {
        /* -> bb3142 */
    }

    // ---- bb3142 @ 0x14003ada6 ----
    /* 14003ada6 */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    // intrinsic: f30f1095 movss xmm2, dword ptr [rbp + 0xa0]
    if (SF == OF) {
        /* -> bb3148 */
    } else {
        /* -> bb3147 */
    }

    // ---- bb3147 @ 0x14003adb3 ----
    if (SF != OF) {
        /* -> bb3047 */
    } else {
        /* -> bb3148 */
    }

    // ---- bb3148 @ 0x14003adb9 ----
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2c91fb]
    /* fallthrough -> bb3149 */

    // ---- bb3149 @ 0x14003adc1 ----
    /* 14003adc1 */ let mut t_14003adc1: u8 = core::ptr::read((rdi).wrapping_add(0x2250_u64) as *const u8);
    if (t_14003adc1 != 0x0_u8) {
        /* -> bb3153 */
    } else {
        /* -> bb3152 */
    }

    // ---- bb3152 @ 0x14003adc8 ----
    if (t_14003adc1 != 0x0_u8) {
        /* -> bb3153 */
    } else {
        /* -> bb3210 */
    }

    // ---- bb3153 @ 0x14003adce ----
    /* 14003adce */ let mut t_14003adce: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    if (t_14003adce == 0x7_u32) {
        /* -> bb3157 */
    } else {
        /* -> bb3156 */
    }

    // ---- bb3156 @ 0x14003add5 ----
    if (t_14003adce == 0x7_u32) {
        /* -> bb3157 */
    } else {
        /* -> bb3210 */
    }

    // ---- bb3157 @ 0x14003addb ----
    /* 14003addb */ let mut t_14003addb: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 14003addb */ rcx = (t_14003addb as u64);
    /* 14003ade1 */ let mut t_14003ade1_0: u32 = ((rcx as u32)).wrapping_sub(0xf_u32);
    /* 14003ade1 */ rcx = (t_14003ade1_0 as u64);
    /* 14003ade4 */ rax = (0x88888889_u32 as u64);
    /* 14003ade9 */ let mut t_14003ade9_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 14003ade9 */ rdx = (((t_14003ade9_0 >> 0x20_u64) as u32) as u64);
    /* 14003ade9 */ rax = ((t_14003ade9_0 as u32) as u64);
    /* 14003adeb */ let mut t_14003adeb_0: u32 = ((rdx as u32)).wrapping_add((rcx as u32));
    /* 14003adeb */ rdx = (t_14003adeb_0 as u64);
    /* 14003aded */ rdx = (((((rdx as u32) as i64) >> ((0x4_u8 as u32) as i64)) as u64) as u64);
    /* 14003adf0 */ rax = ((rdx as u32) as u64);
    /* 14003adf2 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 14003adf5 */ let mut t_14003adf5_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 14003adf5 */ rdx = (t_14003adf5_0 as u64);
    /* 14003adf7 */ let mut t_14003adf7_0: u32 = ((rdx as u32) & 0x80000001_u32);
    /* 14003adf7 */ rdx = (t_14003adf7_0 as u64);
    if (SF != OF) {
        /* -> bb3170 */
    } else {
        /* -> bb3169 */
    }

    // ---- bb3169 @ 0x14003adfd ----
    if (SF != OF) {
        /* -> bb3170 */
    } else {
        /* -> bb3173 */
    }

    // ---- bb3170 @ 0x14003adff ----
    /* 14003adff */ rdx = (((rdx as u32)).wrapping_sub(0x1_u32) as u64);
    /* 14003ae01 */ let mut t_14003ae01_0: u32 = ((rdx as u32) | 0xfffffffe_u32);
    /* 14003ae01 */ rdx = (t_14003ae01_0 as u64);
    /* 14003ae04 */ rdx = (((rdx as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb3173 */

    // ---- bb3173 @ 0x14003ae06 ----
    /* 14003ae06 */ let mut t_14003ae06: u32 = core::ptr::read((0x14003ae0c_u64).wrapping_add(0x3af394_u64) as *const u32);
    /* 14003ae06 */ rcx = (t_14003ae06 as u64);
    /* 14003ae0c */ let mut t_14003ae0c_0: u32 = ((rcx as u32)).wrapping_add(0x3_u32);
    /* 14003ae0c */ rcx = (t_14003ae0c_0 as u64);
    /* 14003ae0f */ let mut t_14003ae0f_0: u32 = ((rcx as u32)).wrapping_add((rdx as u32));
    /* 14003ae0f */ rcx = (t_14003ae0f_0 as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2c9dfb]
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c9e1f]
    /* 14003ae21 */ fn_140071cd0();
    /* 14003ae26 */ let mut t_14003ae26: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 14003ae26 */ rcx = (t_14003ae26 as u64);
    /* 14003ae2c */ let mut t_14003ae2c_0: u32 = ((rcx as u32)).wrapping_sub(0xf_u32);
    /* 14003ae2c */ rcx = (t_14003ae2c_0 as u64);
    /* 14003ae2f */ rax = (0x88888889_u32 as u64);
    /* 14003ae34 */ let mut t_14003ae34_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 14003ae34 */ rdx = (((t_14003ae34_0 >> 0x20_u64) as u32) as u64);
    /* 14003ae34 */ rax = ((t_14003ae34_0 as u32) as u64);
    /* 14003ae36 */ let mut t_14003ae36_0: u32 = ((rdx as u32)).wrapping_add((rcx as u32));
    /* 14003ae36 */ rdx = (t_14003ae36_0 as u64);
    /* 14003ae38 */ rdx = (((((rdx as u32) as i64) >> ((0x5_u8 as u32) as i64)) as u64) as u64);
    /* 14003ae3b */ rax = ((rdx as u32) as u64);
    /* 14003ae3d */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 14003ae40 */ let mut t_14003ae40_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 14003ae40 */ rdx = (t_14003ae40_0 as u64);
    /* 14003ae42 */ let mut t_14003ae42_0: u64 = (((rdx as u32) as u64)).wrapping_mul((0x3c_u32 as u64));
    /* 14003ae42 */ rax = ((t_14003ae42_0 as u32) as u64);
    /* 14003ae45 */ let mut t_14003ae45_0: u32 = ((rcx as u32)).wrapping_sub((rax as u32));
    /* 14003ae45 */ rcx = (t_14003ae45_0 as u64);
    if ((rcx as u32) == 0x1e_u32) {
        /* -> bb3194 */
    } else {
        /* -> bb3193 */
    }

    // ---- bb3193 @ 0x14003ae4a ----
    if ((rcx as u32) == 0x1e_u32) {
        /* -> bb3194 */
    } else {
        /* -> bb3210 */
    }

    // ---- bb3194 @ 0x14003ae4c ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003ae4f */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u128, xmm0);
    /* 14003ae54 */ xmm1 = core::ptr::read((0x14003ae5c_u64).wrapping_add(0x2c9234_u64) as *const u128);
    /* 14003ae5c */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u128, xmm1);
    /* 14003ae61 */ rax = 0x70616c43656e6f4c_u64;
    /* 14003ae6b */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u64, rax);
    /* 14003ae70 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u8, 0x0_u8);
    /* 14003ae74 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 14003ae79 */ xmm3 = xmm10;
    /* 14003ae7d */ let mut t_14003ae7d_0: u32 = 0x0_u32;
    /* 14003ae7d */ r8 = (t_14003ae7d_0 as u64);
    /* 14003ae80 */ rdx = (0x64_u32 as u64);
    /* 14003ae85 */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003ae8a */ fn_140040b90();
    /* 14003ae90 */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003ae95 */ fn_140027900();
    /* fallthrough -> bb3210 */

    // ---- bb3210 @ 0x14003ae9a ----
    /* 14003ae9a */ let mut t_14003ae9a: u32 = core::ptr::read((r12).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003ae9a */ rax = (t_14003ae9a as u64);
    /* 14003ae9e */ let mut t_14003ae9e: u32 = core::ptr::read((0x14003aea4_u64).wrapping_add(0x3af308_u64) as *const u32);
    if (((SF == OF) & (t_14003ae9e != (rax as u32))) == false) { /* -> bb3215 */ }
    if (((SF == OF) & (t_14003ae9e != (rax as u32))) != 0) { /* -> bb3214 */ }

    // ---- bb3214 @ 0x14003aea4 ----
    if (((SF == OF) & (t_14003ae9e != (rax as u32))) == false) { /* -> bb3215 */ }
    if (((SF == OF) & (t_14003ae9e != (rax as u32))) != 0) { /* -> bb4524 */ }

    // ---- bb3215 @ 0x14003aeaa ----
    /* 14003aeaa */ let mut t_14003aeaa: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    if (t_14003aeaa == 0x6_u32) {
        /* -> bb3219 */
    } else {
        /* -> bb3218 */
    }

    // ---- bb3218 @ 0x14003aeb1 ----
    if (t_14003aeaa == 0x6_u32) {
        /* -> bb3219 */
    } else {
        /* -> bb3236 */
    }

    // ---- bb3219 @ 0x14003aeb3 ----
    /* 14003aeb3 */ let mut t_14003aeb3: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 14003aeb3 */ rcx = (t_14003aeb3 as u64);
    /* 14003aeb9 */ rax = (0x88888889_u32 as u64);
    /* 14003aebe */ let mut t_14003aebe_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 14003aebe */ rdx = (((t_14003aebe_0 >> 0x20_u64) as u32) as u64);
    /* 14003aebe */ rax = ((t_14003aebe_0 as u32) as u64);
    /* 14003aec0 */ let mut t_14003aec0_0: u32 = ((rdx as u32)).wrapping_add((rcx as u32));
    /* 14003aec0 */ rdx = (t_14003aec0_0 as u64);
    /* 14003aec2 */ rdx = (((((rdx as u32) as i64) >> ((0x4_u8 as u32) as i64)) as u64) as u64);
    /* 14003aec5 */ rax = ((rdx as u32) as u64);
    /* 14003aec7 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 14003aeca */ let mut t_14003aeca_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 14003aeca */ rdx = (t_14003aeca_0 as u64);
    /* 14003aecc */ let mut t_14003aecc_0: u32 = ((rdx as u32) & 0x80000001_u32);
    /* 14003aecc */ rdx = (t_14003aecc_0 as u64);
    if (SF != OF) {
        /* -> bb3231 */
    } else {
        /* -> bb3230 */
    }

    // ---- bb3230 @ 0x14003aed2 ----
    if (SF != OF) {
        /* -> bb3231 */
    } else {
        /* -> bb3234 */
    }

    // ---- bb3231 @ 0x14003aed4 ----
    /* 14003aed4 */ rdx = (((rdx as u32)).wrapping_sub(0x1_u32) as u64);
    /* 14003aed6 */ let mut t_14003aed6_0: u32 = ((rdx as u32) | 0xfffffffe_u32);
    /* 14003aed6 */ rdx = (t_14003aed6_0 as u64);
    /* 14003aed9 */ rdx = (((rdx as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb3234 */

    // ---- bb3234 @ 0x14003aedb ----
    /* 14003aedb */ rdx = (((rdx as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb3237 */

    // ---- bb3236 @ 0x14003aedf ----
    /* 14003aedf */ rdx = ((r13 as u32) as u64);
    /* fallthrough -> bb3237 */

    // ---- bb3237 @ 0x14003aee2 ----
    /* 14003aee2 */ let mut t_14003aee2: u32 = core::ptr::read((0x14003aee8_u64).wrapping_add(0x3af2c0_u64) as *const u32);
    /* 14003aee2 */ rcx = (t_14003aee2 as u64);
    /* 14003aee8 */ let mut t_14003aee8_0: u32 = ((rcx as u32)).wrapping_add((rdx as u32));
    /* 14003aee8 */ rcx = (t_14003aee8_0 as u64);
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x2c8499]
    /* 14003aef3 */ xmm2 = xmm8;
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c9d29]
    /* 14003aeff */ fn_140071cd0();
    /* 14003af04 */ let mut t_14003af04: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_14003af04 == 0x2_u32) {
        /* -> bb3247 */
    } else {
        /* -> bb3246 */
    }

    // ---- bb3246 @ 0x14003af0b ----
    if (t_14003af04 == 0x2_u32) {
        /* -> bb3247 */
    } else {
        /* -> bb3282 */
    }

    // ---- bb3247 @ 0x14003af0d ----
    /* 14003af0d */ let mut t_14003af0d: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    if (SF != OF) {
        /* -> bb3251 */
    } else {
        /* -> bb3250 */
    }

    // ---- bb3250 @ 0x14003af14 ----
    if (SF != OF) {
        /* -> bb3251 */
    } else {
        /* -> bb3282 */
    }

    // ---- bb3251 @ 0x14003af16 ----
    /* 14003af16 */ let mut t_14003af16: u32 = core::ptr::read((r12).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003af16 */ rax = (t_14003af16 as u64);
    /* 14003af1a */ let mut t_14003af1a: u32 = core::ptr::read((0x14003af20_u64).wrapping_add(0x3af294_u64) as *const u32);
    if (((SF == OF) & (t_14003af1a != (rax as u32))) == false) { /* -> bb3256 */ }
    if (((SF == OF) & (t_14003af1a != (rax as u32))) != 0) { /* -> bb3255 */ }

    // ---- bb3255 @ 0x14003af20 ----
    if (((SF == OF) & (t_14003af1a != (rax as u32))) == false) { /* -> bb3256 */ }
    if (((SF == OF) & (t_14003af1a != (rax as u32))) != 0) { /* -> bb4543 */ }

    // ---- bb3256 @ 0x14003af26 ----
    /* 14003af26 */ let mut t_14003af26: u32 = core::ptr::read((rdi).wrapping_add(0x2238_u64) as *const u32);
    /* 14003af26 */ rax = (t_14003af26 as u64);
    /* 14003af2c */ rax = (((rax as u32)).wrapping_add(0x1_u32) as u64);
    /* 14003af2e */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 14003af2f */ let mut t_14003af2f_0: u32 = ((rax as u32)).wrapping_sub((rdx as u32));
    /* 14003af2f */ rax = (t_14003af2f_0 as u64);
    /* 14003af31 */ rax = (((((rax as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 14003af33 */ r14 = ((rax as u32) as u64);
    /* 14003af36 */ rsi = ((r13 as u32) as u64);
    /* 14003af39 */ rbx = (0x85_u32 as u64);
    /* fallthrough -> bb3265 */

    // ---- bb3265 @ 0x14003af40 ----
    /* 14003af40 */ xmm1 = ((rbx as u32) as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    /* 14003af47 */ rcx = ((r13 as u32) as u64);
    /* 14003af4d */ rcx = ((rcx & 0xffffffffffffff00_u64) | ((((SF == OF) & (ZF == false)) as u8) as u64));
    /* 14003af50 */ let mut t_14003af50: u32 = core::ptr::read((0x14003af56_u64).wrapping_add(0x3af25a_u64) as *const u32);
    /* 14003af50 */ let mut t_14003af50_0: u32 = ((rcx as u32)).wrapping_add(t_14003af50);
    /* 14003af50 */ rcx = (t_14003af50_0 as u64);
    /* 14003af56 */ xmm2 = xmm7;
    /* 14003af59 */ fn_140071cd0();
    /* 14003af5e */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    /* 14003af60 */ let mut t_14003af60_0: u32 = ((rbx as u32)).wrapping_add(0xd_u32);
    /* 14003af60 */ rbx = (t_14003af60_0 as u64);
    if (SF == OF) {
        /* -> bb3279 */
    } else {
        /* -> bb3278 */
    }

    // ---- bb3278 @ 0x14003af69 ----
    if (SF != OF) {
        /* -> bb3265 */
    } else {
        /* -> bb3279 */
    }

    // ---- bb3279 @ 0x14003af6b ----
    /* 14003af6b */ let mut t_14003af6b: u32 = core::ptr::read((0x14003af72_u64).wrapping_add(0x3c37be_u64) as *const u32);
    /* 14003af6b */ r14 = (t_14003af6b as u64);
    /* fallthrough -> bb3282 */

    // ---- bb3281 @ 0x14003af74 ----
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x2c840f]
    /* fallthrough -> bb3282 */

    // ---- bb3282 @ 0x14003af7d ----
    /* 14003af7d */ let mut t_14003af7d: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_14003af7d == 0x5_u32) {
        /* -> bb3286 */
    } else {
        /* -> bb3285 */
    }

    // ---- bb3285 @ 0x14003af84 ----
    if (t_14003af7d == 0x5_u32) {
        /* -> bb3286 */
    } else {
        /* -> bb3295 */
    }

    // ---- bb3286 @ 0x14003af86 ----
    /* 14003af86 */ let mut t_14003af86: u32 = core::ptr::read((r12).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003af86 */ rax = (t_14003af86 as u64);
    /* 14003af8a */ let mut t_14003af8a: u32 = core::ptr::read((0x14003af90_u64).wrapping_add(0x3af22c_u64) as *const u32);
    if (((SF == OF) & (t_14003af8a != (rax as u32))) == false) { /* -> bb3291 */ }
    if (((SF == OF) & (t_14003af8a != (rax as u32))) != 0) { /* -> bb3290 */ }

    // ---- bb3290 @ 0x14003af90 ----
    if (((SF == OF) & (t_14003af8a != (rax as u32))) == false) { /* -> bb3291 */ }
    if (((SF == OF) & (t_14003af8a != (rax as u32))) != 0) { /* -> bb4571 */ }

    // ---- bb3291 @ 0x14003af96 ----
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2c9c7e]
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c841e]
    /* 14003afa6 */ let mut t_14003afa6: u32 = core::ptr::read((0x14003afac_u64).wrapping_add(0x3af20c_u64) as *const u32);
    /* 14003afa6 */ rcx = (t_14003afa6 as u64);
    /* 14003afac */ fn_140071cd0();
    /* fallthrough -> bb3295 */

    // ---- bb3295 @ 0x14003afb1 ----
    /* 14003afb1 */ r15 = (0x4_u32 as u64);
    /* fallthrough -> bb3296 */

    // ---- bb3296 @ 0x14003afb7 ----
    /* 14003afb7 */ let mut t_14003afb7: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    /* 14003afb7 */ rax = (t_14003afb7 as u64);
    if (((SF != OF) | ((rax as u32) == 0x1_u32)) == false) { /* -> bb3301 */ }
    if (((SF != OF) | ((rax as u32) == 0x1_u32)) != 0) { /* -> bb3300 */ }

    // ---- bb3300 @ 0x14003afc0 ----
    if (((SF != OF) | ((rax as u32) == 0x1_u32)) == false) { /* -> bb3301 */ }
    if (((SF != OF) | ((rax as u32) == 0x1_u32)) != 0) { /* -> bb3305 */ }

    // ---- bb3301 @ 0x14003afc2 ----
    if (SF == OF) {
        /* -> bb3305 */
    } else {
        /* -> bb3304 */
    }

    // ---- bb3304 @ 0x14003afc5 ----
    if (SF == OF) {
        /* -> bb3305 */
    } else {
        /* -> bb3381 */
    }

    // ---- bb3305 @ 0x14003afcb ----
    /* 14003afcb */ let mut t_14003afcb: u32 = core::ptr::read((rdi).wrapping_add(0x225c_u64) as *const u32);
    if (t_14003afcb == 0xffffffff_u32) {
        /* -> bb3309 */
    } else {
        /* -> bb3308 */
    }

    // ---- bb3308 @ 0x14003afd2 ----
    if (t_14003afcb == 0xffffffff_u32) {
        /* -> bb3309 */
    } else {
        /* -> bb3381 */
    }

    // ---- bb3309 @ 0x14003afd8 ----
    /* 14003afd8 */ rcx = ((r14 as u32) as u64);
    /* 14003afdb */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14003afe4 */ rax = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003afe8 */ let mut t_14003afe8: u32 = core::ptr::read((r15).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003afe8 */ rax = (t_14003afe8 as u64);
    /* 14003afec */ let mut t_14003afec: u32 = core::ptr::read((0x14003aff2_u64).wrapping_add(0x3af1d2_u64) as *const u32);
    if (((SF == OF) & (t_14003afec != (rax as u32))) == false) { /* -> bb3317 */ }
    if (((SF == OF) & (t_14003afec != (rax as u32))) != 0) { /* -> bb3316 */ }

    // ---- bb3316 @ 0x14003aff2 ----
    if (((SF == OF) & (t_14003afec != (rax as u32))) == false) { /* -> bb3317 */ }
    if (((SF == OF) & (t_14003afec != (rax as u32))) != 0) { /* -> bb4598 */ }

    // ---- bb3317 @ 0x14003aff8 ----
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2c8750]
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c9c18]
    /* 14003b008 */ let mut t_14003b008: u32 = core::ptr::read((0x14003b00e_u64).wrapping_add(0x3af1b2_u64) as *const u32);
    /* 14003b008 */ rcx = (t_14003b008 as u64);
    /* 14003b00e */ fn_140071cd0();
    /* 14003b013 */ rax = (0x66666667_u32 as u64);
    /* 14003b018 */ let mut t_14003b018: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 14003b018 */ let mut t_14003b018_0: u64 = (((rax as u32) as u64)).wrapping_mul((t_14003b018 as u64));
    /* 14003b018 */ rdx = (((t_14003b018_0 >> 0x20_u64) as u32) as u64);
    /* 14003b018 */ rax = ((t_14003b018_0 as u32) as u64);
    /* 14003b01e */ rcx = ((rdx as u32) as u64);
    /* 14003b020 */ rcx = (((((rcx as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 14003b022 */ rax = ((rcx as u32) as u64);
    /* 14003b024 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 14003b027 */ let mut t_14003b027_0: u32 = ((rcx as u32)).wrapping_add((rax as u32));
    /* 14003b027 */ rcx = (t_14003b027_0 as u64);
    /* 14003b029 */ rax = (0x2aaaaaab_u32 as u64);
    /* 14003b02e */ let mut t_14003b02e_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 14003b02e */ rdx = (((t_14003b02e_0 >> 0x20_u64) as u32) as u64);
    /* 14003b02e */ rax = ((t_14003b02e_0 as u32) as u64);
    /* 14003b030 */ rax = ((rdx as u32) as u64);
    /* 14003b032 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 14003b035 */ let mut t_14003b035_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 14003b035 */ rdx = (t_14003b035_0 as u64);
    /* 14003b037 */ rax = (((rdx).wrapping_add((rdx).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 14003b03a */ let mut t_14003b03a_0: u32 = ((rax as u32)).wrapping_add((rax as u32));
    /* 14003b03a */ rax = (t_14003b03a_0 as u64);
    /* 14003b03c */ let mut t_14003b03c_0: u32 = ((rcx as u32)).wrapping_sub((rax as u32));
    /* 14003b03c */ rcx = (t_14003b03c_0 as u64);
    /* 14003b03e */ let mut t_14003b03e_0: u32 = ((rcx as u32)).wrapping_sub(0x3_u32);
    /* 14003b03e */ rcx = (t_14003b03e_0 as u64);
    /* 14003b041 */ rax = ((rcx as u32) as u64);
    /* 14003b043 */ let mut t_14003b043_0: u32 = (0x0_u32).wrapping_sub((rax as u32));
    /* 14003b043 */ rax = (t_14003b043_0 as u64);
    if (SF == false) { /* -> bb3340 */ }
    if SF { /* -> bb3341 */ }

    // ---- bb3341 @ 0x14003b045 ----
    /* 14003b045 */ rax = ((rcx as u32) as u64);
    /* fallthrough -> bb3340 */

    // ---- bb3340 @ 0x14003b048 ----
    /* 14003b048 */ rax = (((rax).wrapping_add((rax).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 14003b04b */ let mut t_14003b04b_0: u32 = ((rax as u32)).wrapping_add((rax as u32));
    /* 14003b04b */ rax = (t_14003b04b_0 as u64);
    /* 14003b04d */ xmm2 = ((rax as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    // intrinsic: f30f58d7 addss xmm2, xmm7
    /* 14003b058 */ let mut t_14003b058: u32 = core::ptr::read((0x14003b05e_u64).wrapping_add(0x3af162_u64) as *const u32);
    /* 14003b058 */ rcx = (t_14003b058 as u64);
    /* 14003b05e */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c9bbc]
    /* 14003b068 */ fn_140071cd0();
    /* 14003b06d */ rax = (0x66666667_u32 as u64);
    /* 14003b072 */ let mut t_14003b072: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 14003b072 */ let mut t_14003b072_0: u64 = (((rax as u32) as u64)).wrapping_mul((t_14003b072 as u64));
    /* 14003b072 */ rdx = (((t_14003b072_0 >> 0x20_u64) as u32) as u64);
    /* 14003b072 */ rax = ((t_14003b072_0 as u32) as u64);
    /* 14003b078 */ rdx = (((((rdx as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 14003b07a */ r8 = ((rdx as u32) as u64);
    /* 14003b07d */ r8 = (((r8 as u32) >> (0x1f_u8 as u32)) as u64);
    /* 14003b081 */ let mut t_14003b081_0: u32 = ((rdx as u32)).wrapping_add(0x3_u32);
    /* 14003b081 */ rdx = (t_14003b081_0 as u64);
    /* 14003b084 */ let mut t_14003b084_0: u32 = ((r8 as u32)).wrapping_add((rdx as u32));
    /* 14003b084 */ r8 = (t_14003b084_0 as u64);
    /* 14003b087 */ rax = (0x2aaaaaab_u32 as u64);
    /* 14003b08c */ let mut t_14003b08c_0: u64 = (((rax as u32) as u64)).wrapping_mul(((r8 as u32) as u64));
    /* 14003b08c */ rdx = (((t_14003b08c_0 >> 0x20_u64) as u32) as u64);
    /* 14003b08c */ rax = ((t_14003b08c_0 as u32) as u64);
    /* 14003b08f */ rax = ((rdx as u32) as u64);
    /* 14003b091 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 14003b094 */ let mut t_14003b094_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 14003b094 */ rdx = (t_14003b094_0 as u64);
    /* 14003b096 */ rax = (((rdx).wrapping_add((rdx).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 14003b099 */ let mut t_14003b099_0: u32 = ((rax as u32)).wrapping_add((rax as u32));
    /* 14003b099 */ rax = (t_14003b099_0 as u64);
    /* 14003b09b */ let mut t_14003b09b_0: u32 = ((r8 as u32)).wrapping_sub((rax as u32));
    /* 14003b09b */ r8 = (t_14003b09b_0 as u64);
    /* 14003b09e */ let mut t_14003b09e_0: u32 = ((r8 as u32)).wrapping_sub(0x3_u32);
    /* 14003b09e */ r8 = (t_14003b09e_0 as u64);
    /* 14003b0a2 */ rax = ((r8 as u32) as u64);
    /* 14003b0a5 */ let mut t_14003b0a5_0: u32 = (0x0_u32).wrapping_sub((rax as u32));
    /* 14003b0a5 */ rax = (t_14003b0a5_0 as u64);
    if (SF == false) { /* -> bb3370 */ }
    if SF { /* -> bb3371 */ }

    // ---- bb3371 @ 0x14003b0a7 ----
    /* 14003b0a7 */ rax = ((r8 as u32) as u64);
    /* fallthrough -> bb3370 */

    // ---- bb3370 @ 0x14003b0ab ----
    /* 14003b0ab */ rax = (((rax).wrapping_add((rax).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 14003b0ae */ let mut t_14003b0ae_0: u32 = ((rax as u32)).wrapping_add((rax as u32));
    /* 14003b0ae */ rax = (t_14003b0ae_0 as u64);
    /* 14003b0b0 */ xmm2 = ((rax as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    // intrinsic: f30f58d7 addss xmm2, xmm7
    /* 14003b0bb */ let mut t_14003b0bb: u32 = core::ptr::read((0x14003b0c1_u64).wrapping_add(0x3af0ff_u64) as *const u32);
    /* 14003b0bb */ rcx = (t_14003b0bb as u64);
    /* 14003b0c1 */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c9b71]
    /* 14003b0cb */ fn_140071cd0();
    /* fallthrough -> bb3381 */

    // ---- bb3381 @ 0x14003b0d0 ----
    // intrinsic: f30f108f movss xmm1, dword ptr [rdi + 0x114]
    /* 14003b0d8 */ xmm3 = xmm1;
    // intrinsic: f3440f10 movss xmm15, dword ptr [rip + 0x361c3c]
    // intrinsic: 410f57df xorps xmm3, xmm15
    /* 14003b0e8 */ xmm2 = xmm3;
    // intrinsic: f30f5997 mulss xmm2, dword ptr [rdi + 0x10c]
    // intrinsic: f30f599f mulss xmm3, dword ptr [rdi + 0x110]
    /* 14003b0fb */ xmm0 = xmm1;
    // intrinsic: 0f14c100 unpcklps xmm0, xmm1
    /* 14003b101 */ r8 = (xmm0 as u64);
    /* 14003b106 */ xmm1 = xmm12;
    // intrinsic: 0f14d300 unpcklps xmm2, xmm3
    /* 14003b10d */ rcx = (xmm2 as u64);
    /* 14003b112 */ fn_140072fa0();
    /* 14003b117 */ let mut t_14003b117: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    /* 14003b117 */ rax = (t_14003b117 as u64);
    /* 14003b11d */ let mut t_14003b11d_0: u32 = ((rax as u32)).wrapping_sub(0x3_u32);
    /* 14003b11d */ rax = (t_14003b11d_0 as u64);
    // intrinsic: f3440f10 movss xmm9, dword ptr [rip + 0x2c822b]
    if (((CF == false) & ((rax as u32) != 0x4_u32)) == false) { /* -> bb3402 */ }
    if (((CF == false) & ((rax as u32) != 0x4_u32)) != 0) { /* -> bb3401 */ }

    // ---- bb3401 @ 0x14003b12c ----
    if (((CF == false) & ((rax as u32) != 0x4_u32)) == false) { /* -> bb3402 */ }
    if (((CF == false) & ((rax as u32) != 0x4_u32)) != 0) { /* -> bb3603 */ }

    // ---- bb3402 @ 0x14003b132 ----
    /* 14003b132 */ let mut t_14003b132: u64 = core::ptr::read((rdi).wrapping_add(0x298_u64) as *const u64);
    if (t_14003b132 != 0x0_u64) {
        /* -> bb3406 */
    } else {
        /* -> bb3405 */
    }

    // ---- bb3405 @ 0x14003b13a ----
    if (t_14003b132 != 0x0_u64) {
        /* -> bb3406 */
    } else {
        /* -> bb3413 */
    }

    // ---- bb3406 @ 0x14003b13c ----
    /* 14003b13c */ let mut t_14003b13c: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_14003b13c != 0x5_u32) {
        /* -> bb3410 */
    } else {
        /* -> bb3409 */
    }

    // ---- bb3409 @ 0x14003b143 ----
    if (t_14003b13c != 0x5_u32) {
        /* -> bb3410 */
    } else {
        /* -> bb3413 */
    }

    // ---- bb3410 @ 0x14003b145 ----
    /* 14003b145 */ let mut t_14003b145: u32 = core::ptr::read((0x14003b14b_u64).wrapping_add(0x3992cd_u64) as *const u32);
    /* 14003b145 */ rdx = (t_14003b145 as u64);
    /* 14003b14b */ rcx = core::ptr::read((rdi).wrapping_add(0x2c8_u64) as *const u64);
    /* 14003b152 */ fn_140084610();
    /* fallthrough -> bb3413 */

    // ---- bb3413 @ 0x14003b157 ----
    /* 14003b157 */ let mut t_14003b157: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 14003b157 */ rax = (t_14003b157 as u64);
    if (t_14003b13c == 0x5_u32) {
        /* -> bb3418 */
    } else {
        /* -> bb3417 */
    }

    // ---- bb3417 @ 0x14003b15f ----
    if (t_14003b13c == 0x5_u32) {
        /* -> bb3418 */
    } else {
        /* -> bb3487 */
    }

    // ---- bb3418 @ 0x14003b165 ----
    /* 14003b165 */ rcx = ((r14 as u32) as u64);
    /* 14003b168 */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14003b171 */ rax = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003b175 */ let mut t_14003b175: u32 = core::ptr::read((r15).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003b175 */ rax = (t_14003b175 as u64);
    /* 14003b179 */ let mut t_14003b179: u32 = core::ptr::read((0x14003b17f_u64).wrapping_add(0x3af04d_u64) as *const u32);
    if (((SF == OF) & (t_14003b179 != (rax as u32))) == false) { /* -> bb3426 */ }
    if (((SF == OF) & (t_14003b179 != (rax as u32))) != 0) { /* -> bb3425 */ }

    // ---- bb3425 @ 0x14003b17f ----
    if (((SF == OF) & (t_14003b179 != (rax as u32))) == false) { /* -> bb3426 */ }
    if (((SF == OF) & (t_14003b179 != (rax as u32))) != 0) { /* -> bb4625 */ }

    // ---- bb3426 @ 0x14003b185 ----
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003b18c */ xmm3 = xmm9;
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2c9b08]
    /* 14003b198 */ xmm2 = xmm7;
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2c81ed]
    /* 14003b1a3 */ xmm1 = xmm6;
    /* 14003b1a6 */ let mut t_14003b1a6: u32 = core::ptr::read((0x14003b1ac_u64).wrapping_add(0x3af01c_u64) as *const u32);
    /* 14003b1a6 */ rcx = (t_14003b1a6 as u64);
    /* 14003b1ac */ fn_140071e80();
    /* 14003b1b1 */ let mut t_14003b1b1: u32 = core::ptr::read((0x14003b1b7_u64).wrapping_add(0x3af011_u64) as *const u32);
    /* 14003b1b1 */ rcx = (t_14003b1b1 as u64);
    /* 14003b1b7 */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003b1c0 */ xmm3 = xmm9;
    /* 14003b1c4 */ xmm2 = xmm7;
    /* 14003b1c7 */ xmm1 = xmm6;
    /* 14003b1ca */ fn_140071e80();
    /* 14003b1cf */ rbx = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u64);
    if (t_14003c436 != 0xffffffff_u32) {
        /* -> bb3446 */
    } else {
        /* -> bb3445 */
    }

    // ---- bb3445 @ 0x14003b1d9 ----
    if (t_14003c436 != 0xffffffff_u32) {
        /* -> bb3446 */
    } else {
        /* -> bb3463 */
    }

    // ---- bb3446 @ 0x14003b1db ----
    /* 14003b1db */ rbx = core::ptr::read((rbx).wrapping_add(0x70_u64) as *const u64);
    if (t_14003c436 != 0xffffffff_u32) {
        /* -> bb3451 */
    } else {
        /* -> bb3450 */
    }

    // ---- bb3450 @ 0x14003b1e2 ----
    if (t_14003c436 != 0xffffffff_u32) {
        /* -> bb3451 */
    } else {
        /* -> bb3463 */
    }

    // ---- bb3451 @ 0x14003b1e4 ----
    /* 14003b1e4 */ let mut t_14003b1e4: u64 = core::ptr::read((rdi).wrapping_add(0x2d8_u64) as *const u64);
    if (rbx != t_14003b1e4) {
        /* -> bb3455 */
    } else {
        /* -> bb3454 */
    }

    // ---- bb3454 @ 0x14003b1eb ----
    if (rbx != t_14003b1e4) {
        /* -> bb3455 */
    } else {
        /* -> bb3458 */
    }

    // ---- bb3455 @ 0x14003b1ed ----
    /* 14003b1ed */ let mut t_14003b1ed: u32 = core::ptr::read((0x14003b1f3_u64).wrapping_add(0x399259_u64) as *const u32);
    /* 14003b1ed */ rdx = (t_14003b1ed as u64);
    /* 14003b1f3 */ rcx = rbx;
    /* 14003b1f6 */ fn_140084610();
    /* fallthrough -> bb3458 */

    // ---- bb3458 @ 0x14003b1fb ----
    /* 14003b1fb */ rbx = core::ptr::read((rbx).wrapping_add(0x8_u64) as *const u64);
    if (rbx == t_14003b1e4) {
        /* -> bb3463 */
    } else {
        /* -> bb3462 */
    }

    // ---- bb3462 @ 0x14003b202 ----
    if (rbx != t_14003b1e4) {
        /* -> bb3451 */
    } else {
        /* -> bb3463 */
    }

    // ---- bb3463 @ 0x14003b204 ----
    /* 14003b204 */ rsi = core::ptr::read((rdi).wrapping_add(0x2b8_u64) as *const u64);
    /* 14003b20b */ rbx = core::ptr::read((rdi).wrapping_add(0x2b0_u64) as *const u64);
    if (rbx != rsi) {
        /* -> bb3469 */
    } else {
        /* -> bb3468 */
    }

    // ---- bb3468 @ 0x14003b215 ----
    if (rbx != rsi) {
        /* -> bb3469 */
    } else {
        /* -> bb3603 */
    }

    // ---- bb3469 @ 0x14003b21b ----
    /* fallthrough -> bb3470 */

    // ---- bb3470 @ 0x14003b220 ----
    /* 14003b220 */ rax = core::ptr::read(rbx as *const u64);
    /* 14003b223 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, 0x8_u32);
    /* 14003b22b */ let mut t_14003b22b: u32 = core::ptr::read((0x14003b232_u64).wrapping_add(0x3991de_u64) as *const u32);
    /* 14003b22b */ r9 = (t_14003b22b as u64);
    /* 14003b232 */ xmm2 = xmm9;
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0x10]
    // intrinsic: f30f1040 movss xmm0, dword ptr [rax + 0xc]
    /* 14003b240 */ fn_140071100();
    /* 14003b245 */ let mut t_14003b245_0: u64 = (rbx).wrapping_add(0x8_u64);
    /* 14003b245 */ rbx = t_14003b245_0;
    if (rbx == rsi) {
        /* -> bb3482 */
    } else {
        /* -> bb3481 */
    }

    // ---- bb3481 @ 0x14003b24c ----
    if (rbx != rsi) {
        /* -> bb3470 */
    } else {
        /* -> bb3482 */
    }

    // ---- bb3482 @ 0x14003b24e ----
    /* fallthrough -> bb3603 */

    // ---- bb3483 @ 0x14003b253 ----
    /* 14003b253 */ let mut t_14003b253: u32 = core::ptr::read((0x14003b259_u64).wrapping_add(0x3991e3_u64) as *const u32);
    /* 14003b253 */ rcx = (t_14003b253 as u64);
    /* 14003b259 */ fn_140070f40();
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x2c8125]
    /* fallthrough -> bb3296 */

    // ---- bb3487 @ 0x14003b26c ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb3491 */
    } else {
        /* -> bb3490 */
    }

    // ---- bb3490 @ 0x14003b26f ----
    if ((rax as u32) == 0x1_u32) {
        /* -> bb3491 */
    } else {
        /* -> bb3525 */
    }

    // ---- bb3491 @ 0x14003b275 ----
    /* 14003b275 */ let mut t_14003b275: u32 = core::ptr::read((0x14003b27b_u64).wrapping_add(0x399151_u64) as *const u32);
    /* 14003b275 */ rdx = (t_14003b275 as u64);
    /* 14003b27b */ rcx = core::ptr::read((rdi).wrapping_add(0x2d0_u64) as *const u64);
    /* 14003b282 */ fn_140084610();
    /* 14003b287 */ let mut t_14003b287: u32 = core::ptr::read((0x14003b28d_u64).wrapping_add(0x39913f_u64) as *const u32);
    /* 14003b287 */ rdx = (t_14003b287 as u64);
    /* 14003b28d */ rcx = core::ptr::read((rdi).wrapping_add(0x2d8_u64) as *const u64);
    /* 14003b294 */ fn_140084610();
    /* 14003b299 */ let mut t_14003b299: u32 = core::ptr::read((0x14003b29f_u64).wrapping_add(0x399165_u64) as *const u32);
    /* 14003b299 */ rcx = (t_14003b299 as u64);
    /* 14003b29f */ fn_1400725f0();
    /* 14003b2a4 */ rcx = ((r14 as u32) as u64);
    /* 14003b2a7 */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14003b2b0 */ rax = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003b2b4 */ let mut t_14003b2b4: u32 = core::ptr::read((r15).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003b2b4 */ rax = (t_14003b2b4 as u64);
    /* 14003b2b8 */ let mut t_14003b2b8: u32 = core::ptr::read((0x14003b2be_u64).wrapping_add(0x3aef16_u64) as *const u32);
    if (((SF == OF) & (t_14003b2b8 != (rax as u32))) == false) { /* -> bb3507 */ }
    if (((SF == OF) & (t_14003b2b8 != (rax as u32))) != 0) { /* -> bb3506 */ }

    // ---- bb3506 @ 0x14003b2be ----
    if (((SF == OF) & (t_14003b2b8 != (rax as u32))) == false) { /* -> bb3507 */ }
    if (((SF == OF) & (t_14003b2b8 != (rax as u32))) != 0) { /* -> bb4644 */ }

    // ---- bb3507 @ 0x14003b2c4 ----
    /* 14003b2c4 */ rbx = (0xe7_u32 as u64);
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2c99ab]
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2c8cdb]
    /* fallthrough -> bb3511 */

    // ---- bb3511 @ 0x14003b2e0 ----
    /* 14003b2e0 */ xmm1 = ((rbx as u32) as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    // intrinsic: f3410f59 mulss xmm1, xmm9
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003b2f3 */ xmm3 = xmm7;
    /* 14003b2f6 */ xmm2 = xmm6;
    /* 14003b2f9 */ let mut t_14003b2f9: u32 = core::ptr::read((0x14003b2ff_u64).wrapping_add(0x3aeed1_u64) as *const u32);
    /* 14003b2f9 */ rcx = (t_14003b2f9 as u64);
    /* 14003b2ff */ fn_140071e80();
    /* 14003b304 */ let mut t_14003b304_0: u32 = ((rbx as u32)).wrapping_add(0x20_u32);
    /* 14003b304 */ rbx = (t_14003b304_0 as u64);
    if (SF == OF) {
        /* -> bb3524 */
    } else {
        /* -> bb3523 */
    }

    // ---- bb3523 @ 0x14003b30d ----
    if (SF != OF) {
        /* -> bb3511 */
    } else {
        /* -> bb3524 */
    }

    // ---- bb3524 @ 0x14003b30f ----
    /* fallthrough -> bb3603 */

    // ---- bb3525 @ 0x14003b314 ----
    if ((rax as u32) == 0x2_u32) {
        /* -> bb3529 */
    } else {
        /* -> bb3528 */
    }

    // ---- bb3528 @ 0x14003b317 ----
    if ((rax as u32) == 0x2_u32) {
        /* -> bb3529 */
    } else {
        /* -> bb3556 */
    }

    // ---- bb3529 @ 0x14003b319 ----
    /* 14003b319 */ rbx = (rdi).wrapping_add(0x2d0_u64);
    /* 14003b320 */ rsi = (0x4_u32 as u64);
    /* fallthrough -> bb3532 */

    // ---- bb3532 @ 0x14003b330 ----
    /* 14003b330 */ let mut t_14003b330: u32 = core::ptr::read((0x14003b336_u64).wrapping_add(0x399096_u64) as *const u32);
    /* 14003b330 */ rdx = (t_14003b330 as u64);
    /* 14003b336 */ rcx = core::ptr::read(rbx as *const u64);
    /* 14003b339 */ fn_140084610();
    /* 14003b33e */ rbx = (rbx).wrapping_add(0x8_u64);
    /* 14003b342 */ let mut t_14003b342_0: u64 = (rsi).wrapping_sub(0x1_u64);
    /* 14003b342 */ rsi = t_14003b342_0;
    if ((rax as u32) == 0x2_u32) {
        /* -> bb3540 */
    } else {
        /* -> bb3539 */
    }

    // ---- bb3539 @ 0x14003b346 ----
    if ((rax as u32) != 0x2_u32) {
        /* -> bb3532 */
    } else {
        /* -> bb3540 */
    }

    // ---- bb3540 @ 0x14003b348 ----
    /* 14003b348 */ rcx = ((r14 as u32) as u64);
    /* 14003b34b */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14003b354 */ rax = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003b358 */ let mut t_14003b358: u32 = core::ptr::read((r15).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003b358 */ rax = (t_14003b358 as u64);
    /* 14003b35c */ let mut t_14003b35c: u32 = core::ptr::read((0x14003b362_u64).wrapping_add(0x3aee7a_u64) as *const u32);
    if (((SF == OF) & (t_14003b35c != (rax as u32))) == false) { /* -> bb3548 */ }
    if (((SF == OF) & (t_14003b35c != (rax as u32))) != 0) { /* -> bb3547 */ }

    // ---- bb3547 @ 0x14003b362 ----
    if (((SF == OF) & (t_14003b35c != (rax as u32))) == false) { /* -> bb3548 */ }
    if (((SF == OF) & (t_14003b35c != (rax as u32))) != 0) { /* -> bb4671 */ }

    // ---- bb3548 @ 0x14003b368 ----
    /* 14003b368 */ rax = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u64);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x2c97a2]
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 0x10]
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0xc]
    /* 14003b388 */ let mut t_14003b388: u32 = core::ptr::read((0x14003b38e_u64).wrapping_add(0x3aee4a_u64) as *const u32);
    /* 14003b388 */ rcx = (t_14003b388 as u64);
    /* 14003b38e */ fn_140071e80();
    /* fallthrough -> bb3603 */

    // ---- bb3556 @ 0x14003b398 ----
    if ((rax as u32) == 0x3_u32) {
        /* -> bb3560 */
    } else {
        /* -> bb3559 */
    }

    // ---- bb3559 @ 0x14003b39b ----
    if ((rax as u32) == 0x3_u32) {
        /* -> bb3560 */
    } else {
        /* -> bb3596 */
    }

    // ---- bb3560 @ 0x14003b3a1 ----
    /* 14003b3a1 */ rcx = ((r14 as u32) as u64);
    /* 14003b3a4 */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14003b3ad */ rsi = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003b3b1 */ let mut t_14003b3b1: u32 = core::ptr::read((rsi).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003b3b1 */ rax = (t_14003b3b1 as u64);
    /* 14003b3b5 */ let mut t_14003b3b5: u32 = core::ptr::read((0x14003b3bb_u64).wrapping_add(0x3aee29_u64) as *const u32);
    if (((SF == OF) & (t_14003b3b5 != (rax as u32))) == false) { /* -> bb3568 */ }
    if (((SF == OF) & (t_14003b3b5 != (rax as u32))) != 0) { /* -> bb3567 */ }

    // ---- bb3567 @ 0x14003b3bb ----
    if (((SF == OF) & (t_14003b3b5 != (rax as u32))) == false) { /* -> bb3568 */ }
    if (((SF == OF) & (t_14003b3b5 != (rax as u32))) != 0) { /* -> bb4693 */ }

    // ---- bb3568 @ 0x14003b3c1 ----
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003b3c8 */ xmm3 = xmm9;
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2c9894]
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c7fc0]
    /* 14003b3dc */ let mut t_14003b3dc: u32 = core::ptr::read((0x14003b3e2_u64).wrapping_add(0x3aedfe_u64) as *const u32);
    /* 14003b3dc */ rcx = (t_14003b3dc as u64);
    /* 14003b3e2 */ fn_140071e80();
    /* 14003b3e7 */ let mut t_14003b3e7: u64 = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u64);
    if (t_14003b3e7 != 0x0_u64) {
        /* -> bb3578 */
    } else {
        /* -> bb3577 */
    }

    // ---- bb3577 @ 0x14003b3ef ----
    if (t_14003b3e7 != 0x0_u64) {
        /* -> bb3578 */
    } else {
        /* -> bb3603 */
    }

    // ---- bb3578 @ 0x14003b3f1 ----
    /* 14003b3f1 */ let mut t_14003b3f1: u32 = core::ptr::read((rsi).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003b3f1 */ rax = (t_14003b3f1 as u64);
    /* 14003b3f5 */ let mut t_14003b3f5: u32 = core::ptr::read((0x14003b3fb_u64).wrapping_add(0x3aedf1_u64) as *const u32);
    if (((SF == OF) & (t_14003b3f5 != (rax as u32))) == false) { /* -> bb3583 */ }
    if (((SF == OF) & (t_14003b3f5 != (rax as u32))) != 0) { /* -> bb3582 */ }

    // ---- bb3582 @ 0x14003b3fb ----
    if (((SF == OF) & (t_14003b3f5 != (rax as u32))) == false) { /* -> bb3583 */ }
    if (((SF == OF) & (t_14003b3f5 != (rax as u32))) != 0) { /* -> bb4720 */ }

    // ---- bb3583 @ 0x14003b401 ----
    /* 14003b401 */ rbx = core::ptr::read((rdi).wrapping_add(0x2a0_u64) as *const u64);
    // intrinsic: f30f104b movss xmm1, dword ptr [rbx + 0x18]
    // intrinsic: f30f1043 movss xmm0, dword ptr [rbx + 0x14]
    /* 14003b412 */ fn_1402cd8d0();
    /* 14003b417 */ xmm3 = xmm0;
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x28], xmm12
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2c96f7]
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    // intrinsic: f30f1053 movss xmm2, dword ptr [rbx + 0x10]
    // intrinsic: f30f104b movss xmm1, dword ptr [rbx + 0xc]
    /* 14003b439 */ let mut t_14003b439: u32 = core::ptr::read((0x14003b43f_u64).wrapping_add(0x3aeda9_u64) as *const u32);
    /* 14003b439 */ rcx = (t_14003b439 as u64);
    /* 14003b43f */ fn_140071eb0();
    /* fallthrough -> bb3603 */

    // ---- bb3596 @ 0x14003b446 ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb3600 */
    } else {
        /* -> bb3599 */
    }

    // ---- bb3599 @ 0x14003b449 ----
    if ((rax as u32) == 0x5_u32) {
        /* -> bb3600 */
    } else {
        /* -> bb3603 */
    }

    // ---- bb3600 @ 0x14003b44b ----
    /* 14003b44b */ let mut t_14003b44b: u32 = core::ptr::read((0x14003b451_u64).wrapping_add(0x398f83_u64) as *const u32);
    /* 14003b44b */ rdx = (t_14003b44b as u64);
    /* 14003b451 */ rcx = core::ptr::read((rdi).wrapping_add(0x2d0_u64) as *const u64);
    /* 14003b458 */ fn_140084610();
    /* fallthrough -> bb3603 */

    // ---- bb3603 @ 0x14003b45d ----
    /* 14003b45d */ let mut t_14003b45d: u32 = core::ptr::read((rdi).wrapping_add(0x225c_u64) as *const u32);
    if (t_14003b45d != 0xffffffff_u32) {
        /* -> bb3607 */
    } else {
        /* -> bb3606 */
    }

    // ---- bb3606 @ 0x14003b464 ----
    if (t_14003b45d != 0xffffffff_u32) {
        /* -> bb3607 */
    } else {
        /* -> bb3616 */
    }

    // ---- bb3607 @ 0x14003b466 ----
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x2c9826]
    /* 14003b46e */ xmm0 = xmm8;
    // intrinsic: 410f14c0 unpcklps xmm0, xmm8
    /* 14003b476 */ r8 = (xmm0 as u64);
    /* 14003b47b */ xmm1 = xmm12;
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2c9825]
    // intrinsic: 0f14d300 unpcklps xmm2, xmm3
    /* 14003b48a */ rcx = (xmm2 as u64);
    /* 14003b48f */ fn_140072fa0();
    /* fallthrough -> bb3616 */

    // ---- bb3616 @ 0x14003b494 ----
    /* 14003b494 */ let mut t_14003b494: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    /* 14003b494 */ rax = (t_14003b494 as u64);
    /* 14003b49a */ r13 = (0x1_u32 as u64);
    if (((SF != OF) | ((rax as u32) == (r13 as u32))) == false) { /* -> bb3622 */ }
    if (((SF != OF) | ((rax as u32) == (r13 as u32))) != 0) { /* -> bb3621 */ }

    // ---- bb3621 @ 0x14003b4a3 ----
    if (((SF != OF) | ((rax as u32) == (r13 as u32))) == false) { /* -> bb3622 */ }
    if (((SF != OF) | ((rax as u32) == (r13 as u32))) != 0) { /* -> bb3626 */ }

    // ---- bb3622 @ 0x14003b4a5 ----
    if (SF == OF) {
        /* -> bb3626 */
    } else {
        /* -> bb3625 */
    }

    // ---- bb3625 @ 0x14003b4a8 ----
    if (SF == OF) {
        /* -> bb3626 */
    } else {
        /* -> bb3851 */
    }

    // ---- bb3626 @ 0x14003b4ae ----
    /* 14003b4ae */ rbx = (0xffffffff_u32 as u64);
    /* 14003b4b3 */ let mut t_14003b4b3: u32 = core::ptr::read((rdi).wrapping_add(0x168_u64) as *const u32);
    /* 14003b4b3 */ rax = ((t_14003b4b3 as i64) as u64);
    if ((rax as u32) != (rbx as u32)) {
        /* -> bb3632 */
    } else {
        /* -> bb3631 */
    }

    // ---- bb3631 @ 0x14003b4bc ----
    if ((rax as u32) != (rbx as u32)) {
        /* -> bb3632 */
    } else {
        /* -> bb3743 */
    }

    // ---- bb3632 @ 0x14003b4c2 ----
    /* 14003b4c2 */ rcx = core::ptr::read((rdi).wrapping_add(0x130_u64) as *const u64);
    /* 14003b4c9 */ rdx = (rbp).wrapping_add(0x90_u64);
    /* 14003b4d0 */ rcx = core::ptr::read((rcx).wrapping_add((rax).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003b4d4 */ fn_1400b4a00();
    /* 14003b4d9 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    // intrinsic: f30f1010 movss xmm2, dword ptr [rax]
    // intrinsic: f30f108d movss xmm1, dword ptr [rbp + 0x94]
    // intrinsic: f30f1085 movss xmm0, dword ptr [rbp + 0x90]
    // intrinsic: 0f2fc200 comiss xmm0, xmm2
    if (CF == false) { /* -> bb3644 */ }
    if CF { /* -> bb3643 */ }

    // ---- bb3643 @ 0x14003b4f7 ----
    if (CF == false) { /* -> bb3644 */ }
    if CF { /* -> bb3660 */ }

    // ---- bb3644 @ 0x14003b4f9 ----
    // intrinsic: f30f5850 addss xmm2, dword ptr [rax + 8]
    // intrinsic: 0f2fd000 comiss xmm2, xmm0
    if ((CF | ((rax as u32) == (rbx as u32))) == false) { /* -> bb3649 */ }
    if ((CF | ((rax as u32) == (rbx as u32))) != 0) { /* -> bb3648 */ }

    // ---- bb3648 @ 0x14003b501 ----
    if ((CF | ((rax as u32) == (rbx as u32))) == false) { /* -> bb3649 */ }
    if ((CF | ((rax as u32) == (rbx as u32))) != 0) { /* -> bb3660 */ }

    // ---- bb3649 @ 0x14003b503 ----
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 4]
    // intrinsic: 0f2fca00 comiss xmm1, xmm2
    if (CF == false) { /* -> bb3654 */ }
    if CF { /* -> bb3653 */ }

    // ---- bb3653 @ 0x14003b50b ----
    if (CF == false) { /* -> bb3654 */ }
    if CF { /* -> bb3660 */ }

    // ---- bb3654 @ 0x14003b50d ----
    // intrinsic: f30f5850 addss xmm2, dword ptr [rax + 0xc]
    // intrinsic: 0f2fd100 comiss xmm2, xmm1
    /* 14003b515 */ rcx = (0x0_u32 as u64);
    if (((CF == false) & ((rax as u32) != (rbx as u32))) == false) { /* -> bb3660 */ }
    if (((CF == false) & ((rax as u32) != (rbx as u32))) != 0) { /* -> bb3659 */ }

    // ---- bb3659 @ 0x14003b51a ----
    /* 14003b51a */ rbx = ((rcx as u32) as u64);
    /* fallthrough -> bb3660 */

    // ---- bb3660 @ 0x14003b51d ----
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 0x10]
    // intrinsic: 0f2fc200 comiss xmm0, xmm2
    if (CF == false) { /* -> bb3665 */ }
    if CF { /* -> bb3664 */ }

    // ---- bb3664 @ 0x14003b525 ----
    if (CF == false) { /* -> bb3665 */ }
    if CF { /* -> bb3680 */ }

    // ---- bb3665 @ 0x14003b527 ----
    // intrinsic: f30f5850 addss xmm2, dword ptr [rax + 0x18]
    // intrinsic: 0f2fd000 comiss xmm2, xmm0
    if ((CF | ((rax as u32) == (rbx as u32))) == false) { /* -> bb3670 */ }
    if ((CF | ((rax as u32) == (rbx as u32))) != 0) { /* -> bb3669 */ }

    // ---- bb3669 @ 0x14003b52f ----
    if ((CF | ((rax as u32) == (rbx as u32))) == false) { /* -> bb3670 */ }
    if ((CF | ((rax as u32) == (rbx as u32))) != 0) { /* -> bb3680 */ }

    // ---- bb3670 @ 0x14003b531 ----
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 0x14]
    // intrinsic: 0f2fca00 comiss xmm1, xmm2
    if (CF == false) { /* -> bb3675 */ }
    if CF { /* -> bb3674 */ }

    // ---- bb3674 @ 0x14003b539 ----
    if (CF == false) { /* -> bb3675 */ }
    if CF { /* -> bb3680 */ }

    // ---- bb3675 @ 0x14003b53b ----
    // intrinsic: f30f5850 addss xmm2, dword ptr [rax + 0x1c]
    // intrinsic: 0f2fd100 comiss xmm2, xmm1
    if (((CF == false) & ((rax as u32) != (rbx as u32))) == false) { /* -> bb3680 */ }
    if (((CF == false) & ((rax as u32) != (rbx as u32))) != 0) { /* -> bb3679 */ }

    // ---- bb3679 @ 0x14003b543 ----
    /* 14003b543 */ rbx = ((r13 as u32) as u64);
    /* fallthrough -> bb3680 */

    // ---- bb3680 @ 0x14003b547 ----
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 0x20]
    // intrinsic: 0f2fc200 comiss xmm0, xmm2
    if (CF == false) { /* -> bb3685 */ }
    if CF { /* -> bb3684 */ }

    // ---- bb3684 @ 0x14003b54f ----
    if (CF == false) { /* -> bb3685 */ }
    if CF { /* -> bb3701 */ }

    // ---- bb3685 @ 0x14003b551 ----
    // intrinsic: f30f5850 addss xmm2, dword ptr [rax + 0x28]
    // intrinsic: 0f2fd000 comiss xmm2, xmm0
    if ((CF | ((rax as u32) == (rbx as u32))) == false) { /* -> bb3690 */ }
    if ((CF | ((rax as u32) == (rbx as u32))) != 0) { /* -> bb3689 */ }

    // ---- bb3689 @ 0x14003b559 ----
    if ((CF | ((rax as u32) == (rbx as u32))) == false) { /* -> bb3690 */ }
    if ((CF | ((rax as u32) == (rbx as u32))) != 0) { /* -> bb3701 */ }

    // ---- bb3690 @ 0x14003b55b ----
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 0x24]
    // intrinsic: 0f2fca00 comiss xmm1, xmm2
    if (CF == false) { /* -> bb3695 */ }
    if CF { /* -> bb3694 */ }

    // ---- bb3694 @ 0x14003b563 ----
    if (CF == false) { /* -> bb3695 */ }
    if CF { /* -> bb3701 */ }

    // ---- bb3695 @ 0x14003b565 ----
    // intrinsic: f30f5850 addss xmm2, dword ptr [rax + 0x2c]
    /* 14003b56a */ rcx = (0x2_u32 as u64);
    // intrinsic: 0f2fd100 comiss xmm2, xmm1
    if (((CF == false) & ((rax as u32) != (rbx as u32))) == false) { /* -> bb3701 */ }
    if (((CF == false) & ((rax as u32) != (rbx as u32))) != 0) { /* -> bb3700 */ }

    // ---- bb3700 @ 0x14003b572 ----
    /* 14003b572 */ rbx = ((rcx as u32) as u64);
    /* fallthrough -> bb3701 */

    // ---- bb3701 @ 0x14003b575 ----
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 0x30]
    // intrinsic: 0f2fc200 comiss xmm0, xmm2
    if (CF == false) { /* -> bb3706 */ }
    if CF { /* -> bb3705 */ }

    // ---- bb3705 @ 0x14003b57d ----
    if (CF == false) { /* -> bb3706 */ }
    if CF { /* -> bb3722 */ }

    // ---- bb3706 @ 0x14003b57f ----
    // intrinsic: f30f5850 addss xmm2, dword ptr [rax + 0x38]
    // intrinsic: 0f2fd000 comiss xmm2, xmm0
    if ((CF | ((rax as u32) == (rbx as u32))) == false) { /* -> bb3711 */ }
    if ((CF | ((rax as u32) == (rbx as u32))) != 0) { /* -> bb3710 */ }

    // ---- bb3710 @ 0x14003b587 ----
    if ((CF | ((rax as u32) == (rbx as u32))) == false) { /* -> bb3711 */ }
    if ((CF | ((rax as u32) == (rbx as u32))) != 0) { /* -> bb3722 */ }

    // ---- bb3711 @ 0x14003b589 ----
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 0x34]
    // intrinsic: 0f2fca00 comiss xmm1, xmm2
    if (CF == false) { /* -> bb3716 */ }
    if CF { /* -> bb3715 */ }

    // ---- bb3715 @ 0x14003b591 ----
    if (CF == false) { /* -> bb3716 */ }
    if CF { /* -> bb3722 */ }

    // ---- bb3716 @ 0x14003b593 ----
    // intrinsic: f30f5850 addss xmm2, dword ptr [rax + 0x3c]
    /* 14003b598 */ rcx = (0x3_u32 as u64);
    // intrinsic: 0f2fd100 comiss xmm2, xmm1
    if (((CF == false) & ((rax as u32) != (rbx as u32))) == false) { /* -> bb3722 */ }
    if (((CF == false) & ((rax as u32) != (rbx as u32))) != 0) { /* -> bb3721 */ }

    // ---- bb3721 @ 0x14003b5a0 ----
    /* 14003b5a0 */ rbx = ((rcx as u32) as u64);
    /* fallthrough -> bb3722 */

    // ---- bb3722 @ 0x14003b5a3 ----
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 0x50]
    // intrinsic: 0f2fc200 comiss xmm0, xmm2
    if (CF == false) { /* -> bb3727 */ }
    if CF { /* -> bb3726 */ }

    // ---- bb3726 @ 0x14003b5ab ----
    if (CF == false) { /* -> bb3727 */ }
    if CF { /* -> bb3743 */ }

    // ---- bb3727 @ 0x14003b5ad ----
    // intrinsic: f30f5850 addss xmm2, dword ptr [rax + 0x58]
    // intrinsic: 0f2fd000 comiss xmm2, xmm0
    if ((CF | ((rax as u32) == (rbx as u32))) == false) { /* -> bb3732 */ }
    if ((CF | ((rax as u32) == (rbx as u32))) != 0) { /* -> bb3731 */ }

    // ---- bb3731 @ 0x14003b5b5 ----
    if ((CF | ((rax as u32) == (rbx as u32))) == false) { /* -> bb3732 */ }
    if ((CF | ((rax as u32) == (rbx as u32))) != 0) { /* -> bb3743 */ }

    // ---- bb3732 @ 0x14003b5b7 ----
    // intrinsic: f30f1040 movss xmm0, dword ptr [rax + 0x54]
    // intrinsic: 0f2fc800 comiss xmm1, xmm0
    if (CF == false) { /* -> bb3737 */ }
    if CF { /* -> bb3736 */ }

    // ---- bb3736 @ 0x14003b5bf ----
    if (CF == false) { /* -> bb3737 */ }
    if CF { /* -> bb3743 */ }

    // ---- bb3737 @ 0x14003b5c1 ----
    // intrinsic: f30f5840 addss xmm0, dword ptr [rax + 0x5c]
    /* 14003b5c6 */ rax = (0x5_u32 as u64);
    // intrinsic: 0f2fc100 comiss xmm0, xmm1
    if (((CF == false) & ((rax as u32) != (rbx as u32))) == false) { /* -> bb3743 */ }
    if (((CF == false) & ((rax as u32) != (rbx as u32))) != 0) { /* -> bb3742 */ }

    // ---- bb3742 @ 0x14003b5ce ----
    /* 14003b5ce */ rbx = ((rax as u32) as u64);
    /* fallthrough -> bb3743 */

    // ---- bb3743 @ 0x14003b5d1 ----
    /* 14003b5d1 */ rcx = ((r14 as u32) as u64);
    /* 14003b5d4 */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14003b5dd */ r12 = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003b5e1 */ let mut t_14003b5e1: u32 = core::ptr::read((r12).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003b5e1 */ rax = (t_14003b5e1 as u64);
    /* 14003b5e5 */ let mut t_14003b5e5: u32 = core::ptr::read((0x14003b5eb_u64).wrapping_add(0x3aec09_u64) as *const u32);
    if (((SF == OF) & (t_14003b5e5 != (rax as u32))) == false) { /* -> bb3751 */ }
    if (((SF == OF) & (t_14003b5e5 != (rax as u32))) != 0) { /* -> bb3750 */ }

    // ---- bb3750 @ 0x14003b5eb ----
    if (((SF == OF) & (t_14003b5e5 != (rax as u32))) == false) { /* -> bb3751 */ }
    if (((SF == OF) & (t_14003b5e5 != (rax as u32))) != 0) { /* -> bb4739 */ }

    // ---- bb3751 @ 0x14003b5f1 ----
    /* 14003b5f1 */ let mut t_14003b5f1_0: u32 = 0x0_u32;
    /* 14003b5f1 */ rax = (t_14003b5f1_0 as u64);
    /* 14003b5f3 */ r14 = ((rax as u32) as u64);
    /* 14003b5f6 */ rsi = ((rax as u32) as u64);
    /* fallthrough -> bb3755 */

    // ---- bb3755 @ 0x14003b600 ----
    /* 14003b600 */ rdx = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 14003b607 */ let mut t_14003b607: u32 = core::ptr::read((0x14003b60d_u64).wrapping_add(0x3aebe3_u64) as *const u32);
    /* 14003b607 */ rcx = (t_14003b607 as u64);
    /* 14003b60d */ let mut t_14003b60d_0: u32 = ((rcx as u32)).wrapping_add(0x2_u32);
    /* 14003b60d */ rcx = (t_14003b60d_0 as u64);
    /* 14003b610 */ let mut t_14003b610_0: u32 = ((rcx as u32)).wrapping_add((r14 as u32));
    /* 14003b610 */ rcx = (t_14003b610_0 as u64);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003b61a */ xmm3 = xmm9;
    // intrinsic: f30f1054 movss xmm2, dword ptr [rdx + rsi + 4]
    // intrinsic: f30f100c movss xmm1, dword ptr [rdx + rsi]
    /* 14003b629 */ fn_140071e80();
    /* 14003b62e */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    /* 14003b631 */ let mut t_14003b631_0: u64 = (rsi).wrapping_add(0x10_u64);
    /* 14003b631 */ rsi = t_14003b631_0;
    if (SF == OF) {
        /* -> bb3770 */
    } else {
        /* -> bb3769 */
    }

    // ---- bb3769 @ 0x14003b639 ----
    if (SF != OF) {
        /* -> bb3755 */
    } else {
        /* -> bb3770 */
    }

    // ---- bb3770 @ 0x14003b63b ----
    if ((rbx as u32) != 0xffffffff_u32) {
        /* -> bb3774 */
    } else {
        /* -> bb3773 */
    }

    // ---- bb3773 @ 0x14003b63e ----
    if ((rbx as u32) != 0xffffffff_u32) {
        /* -> bb3774 */
    } else {
        /* -> bb3784 */
    }

    // ---- bb3774 @ 0x14003b640 ----
    /* 14003b640 */ rdx = (((rbx as u32) as i64) as u64);
    /* 14003b643 */ let mut t_14003b643_0: u64 = (rdx).wrapping_add(rdx);
    /* 14003b643 */ rdx = t_14003b643_0;
    /* 14003b646 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 14003b64d */ let mut t_14003b64d: u32 = core::ptr::read((0x14003b653_u64).wrapping_add(0x3aeb9d_u64) as *const u32);
    /* 14003b64d */ rcx = (t_14003b64d as u64);
    /* 14003b653 */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003b65c */ xmm3 = xmm9;
    // intrinsic: f30f1054 movss xmm2, dword ptr [rax + rdx*8 + 4]
    // intrinsic: f30f100c movss xmm1, dword ptr [rax + rdx*8]
    /* 14003b66b */ fn_140071e80();
    /* fallthrough -> bb3784 */

    // ---- bb3784 @ 0x14003b670 ----
    /* 14003b670 */ let mut t_14003b670: u32 = core::ptr::read((rdi).wrapping_add(0x1b0_u64) as *const u32);
    if (SF == OF) {
        /* -> bb3788 */
    } else {
        /* -> bb3787 */
    }

    // ---- bb3787 @ 0x14003b677 ----
    if (SF == OF) {
        /* -> bb3788 */
    } else {
        /* -> bb3972 */
    }

    // ---- bb3788 @ 0x14003b67d ----
    /* 14003b67d */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003b68b */ xmm3 = xmm9;
    // intrinsic: f30f1050 movss xmm2, dword ptr [rax + 0x44]
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0x40]
    /* 14003b699 */ let mut t_14003b699: u32 = core::ptr::read((0x14003b69f_u64).wrapping_add(0x3aeb51_u64) as *const u32);
    /* 14003b699 */ rcx = (t_14003b699 as u64);
    /* 14003b69f */ fn_140071e80();
    /* 14003b6a4 */ r12 = (rdi).wrapping_add(0x250_u64);
    /* fallthrough -> bb3796 */

    // ---- bb3796 @ 0x14003b6ab ----
    /* 14003b6ab */ rdx = ((rdx & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 14003b6ad */ rcx = rdi;
    /* 14003b6b0 */ fn_1400d61a0();
    /* 14003b6b5 */ let mut t_14003b6b5: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    /* 14003b6b5 */ rdx = ((t_14003b6b5 as i64) as u64);
    if ((rdx as u32) != 0xffffffff_u32) {
        /* -> bb3804 */
    } else {
        /* -> bb3803 */
    }

    // ---- bb3803 @ 0x14003b6bf ----
    if ((rdx as u32) != 0xffffffff_u32) {
        /* -> bb3804 */
    } else {
        /* -> bb3851 */
    }

    // ---- bb3804 @ 0x14003b6c5 ----
    /* 14003b6c5 */ xmm8 = xmm12;
    /* 14003b6c9 */ let mut t_14003b6c9: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    if (t_14003b6c9 == 0x1_u32) {
        /* -> bb3809 */
    } else {
        /* -> bb3808 */
    }

    // ---- bb3808 @ 0x14003b6d0 ----
    if (t_14003b6c9 == 0x1_u32) {
        /* -> bb3809 */
    } else {
        /* -> bb3814 */
    }

    // ---- bb3809 @ 0x14003b6d2 ----
    /* 14003b6d2 */ let mut t_14003b6d2: u32 = core::ptr::read(r12 as *const u32);
    /* 14003b6d2 */ rax = (t_14003b6d2 as u64);
    /* 14003b6d6 */ let mut t_14003b6d6_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rax as u32) as u64));
    /* 14003b6d6 */ rax = ((t_14003b6d6_0 as u32) as u64);
    /* 14003b6d9 */ xmm8 = ((rax as u32) as u128);
    // intrinsic: 450f5bc0 cvtdq2ps xmm8, xmm8
    // intrinsic: f3440f5e divss xmm8, dword ptr [rip + 0x2c9549]
    /* fallthrough -> bb3814 */

    // ---- bb3814 @ 0x14003b6eb ----
    /* 14003b6eb */ rcx = rdx;
    /* 14003b6ee */ let mut t_14003b6ee_0: u64 = (rcx).wrapping_add(rcx);
    /* 14003b6ee */ rcx = t_14003b6ee_0;
    /* 14003b6f1 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    /* 14003b6f8 */ xmm7 = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u128);
    /* 14003b6fc */ xmm1 = xmm7;
    // intrinsic: 0fc6cfaa shufps xmm1, xmm7, 0xaa
    /* 14003b703 */ xmm0 = xmm1;
    // intrinsic: f30f58c7 addss xmm0, xmm7
    // intrinsic: f30f5c05 subss xmm0, dword ptr [rip + 0x3615a6]
    // intrinsic: f30f5905 mulss xmm0, dword ptr [rip + 0x2c7c32]
    // intrinsic: f30f5805 addss xmm0, dword ptr [rip + 0x361572]
    // intrinsic: f3410f59 mulss xmm1, xmm8
    // intrinsic: f30f59c1 mulss xmm0, xmm1
    /* 14003b72b */ xmm6 = xmm7;
    // intrinsic: f30f5cf0 subss xmm6, xmm0
    /* 14003b732 */ xmm0 = xmm7;
    // intrinsic: 0fc6c7ff shufps xmm0, xmm7, 0xff
    // intrinsic: f3410f59 mulss xmm0, xmm8
    // intrinsic: f30f5905 mulss xmm0, dword ptr [rip + 0x2c93ea]
    // intrinsic: 0fc6ff55 shufps xmm7, xmm7, 0x55
    // intrinsic: f30f5cf8 subss xmm7, xmm0
    // intrinsic: f3450f58 addss xmm8, xmm10
    // intrinsic: f3450f59 mulss xmm8, xmm9
    /* 14003b758 */ let mut t_14003b758: u32 = core::ptr::read((0x14003b75e_u64).wrapping_add(0x3aea92_u64) as *const u32);
    /* 14003b758 */ rcx = (t_14003b758 as u64);
    /* 14003b75e */ let mut t_14003b75e_0: u32 = ((rcx as u32)).wrapping_add(0x2_u32);
    /* 14003b75e */ rcx = (t_14003b75e_0 as u64);
    /* 14003b761 */ let mut t_14003b761_0: u32 = ((rcx as u32)).wrapping_add((rdx as u32));
    /* 14003b761 */ rcx = (t_14003b761_0 as u64);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003b76a */ xmm3 = xmm8;
    /* 14003b76e */ xmm2 = xmm7;
    /* 14003b771 */ xmm1 = xmm6;
    /* 14003b774 */ fn_140071e80();
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003b780 */ xmm3 = xmm8;
    /* 14003b784 */ xmm2 = xmm7;
    /* 14003b787 */ xmm1 = xmm6;
    /* 14003b78a */ let mut t_14003b78a: u32 = core::ptr::read((0x14003b790_u64).wrapping_add(0x3aea60_u64) as *const u32);
    /* 14003b78a */ rcx = (t_14003b78a as u64);
    /* 14003b790 */ fn_140071e80();
    /* fallthrough -> bb3851 */

    // ---- bb3851 @ 0x14003b795 ----
    /* 14003b795 */ let mut t_14003b795: u32 = core::ptr::read((rdi).wrapping_add(0x225c_u64) as *const u32);
    if (t_14003b795 != 0xffffffff_u32) {
        /* -> bb3855 */
    } else {
        /* -> bb3854 */
    }

    // ---- bb3854 @ 0x14003b79c ----
    if (t_14003b795 != 0xffffffff_u32) {
        /* -> bb3855 */
    } else {
        /* -> bb3856 */
    }

    // ---- bb3855 @ 0x14003b79e ----
    /* 14003b79e */ fn_1400730b0();
    /* fallthrough -> bb3856 */

    // ---- bb3856 @ 0x14003b7a3 ----
    /* 14003b7a3 */ let mut t_14003b7a3: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    /* 14003b7a3 */ rax = (t_14003b7a3 as u64);
    if (SF == OF) {
        /* -> bb3861 */
    } else {
        /* -> bb3860 */
    }

    // ---- bb3860 @ 0x14003b7ac ----
    if (SF == OF) {
        /* -> bb3861 */
    } else {
        /* -> bb3865 */
    }

    // ---- bb3861 @ 0x14003b7ae ----
    if (((SF != OF) | ((rax as u32) == 0x2_u32)) == false) { /* -> bb3865 */ }
    if (((SF != OF) | ((rax as u32) == 0x2_u32)) != 0) { /* -> bb3864 */ }

    // ---- bb3864 @ 0x14003b7b1 ----
    if (((SF != OF) | ((rax as u32) == 0x2_u32)) == false) { /* -> bb3865 */ }
    if (((SF != OF) | ((rax as u32) == 0x2_u32)) != 0) { /* -> bb3872 */ }

    // ---- bb3865 @ 0x14003b7b3 ----
    /* 14003b7b3 */ let mut t_14003b7b3: u32 = core::ptr::read((rdi).wrapping_add(0x225c_u64) as *const u32);
    if (t_14003b7b3 == 0xffffffff_u32) {
        /* -> bb3869 */
    } else {
        /* -> bb3868 */
    }

    // ---- bb3868 @ 0x14003b7ba ----
    if (t_14003b7b3 == 0xffffffff_u32) {
        /* -> bb3869 */
    } else {
        /* -> bb3872 */
    }

    // ---- bb3869 @ 0x14003b7bc ----
    /* 14003b7bc */ rdx = ((r13 as u32) as u64);
    /* 14003b7bf */ rcx = rdi;
    /* 14003b7c2 */ fn_1400d6400();
    /* fallthrough -> bb3872 */

    // ---- bb3872 @ 0x14003b7c7 ----
    // intrinsic: f3440f10 movss xmm14, dword ptr [rip + 0x2c7b8c]
    /* 14003b7d0 */ let mut t_14003b7d0: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_14003b7d0 == 0x1_u32) {
        /* -> bb3877 */
    } else {
        /* -> bb3876 */
    }

    // ---- bb3876 @ 0x14003b7d7 ----
    if (t_14003b7d0 == 0x1_u32) {
        /* -> bb3877 */
    } else {
        /* -> bb4256 */
    }

    // ---- bb3877 @ 0x14003b7dd ----
    /* 14003b7dd */ let mut t_14003b7dd: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    /* 14003b7dd */ rax = (t_14003b7dd as u64);
    /* 14003b7e3 */ let mut t_14003b7e3_0: u32 = ((rax as u32)).wrapping_sub(0x3_u32);
    /* 14003b7e3 */ rax = (t_14003b7e3_0 as u64);
    if (((CF == false) & ((rax as u32) != 0x4_u32)) == false) { /* -> bb3883 */ }
    if (((CF == false) & ((rax as u32) != 0x4_u32)) != 0) { /* -> bb3882 */ }

    // ---- bb3882 @ 0x14003b7e9 ----
    if (((CF == false) & ((rax as u32) != 0x4_u32)) == false) { /* -> bb3883 */ }
    if (((CF == false) & ((rax as u32) != 0x4_u32)) != 0) { /* -> bb4256 */ }

    // ---- bb3883 @ 0x14003b7ef ----
    /* 14003b7ef */ rax = core::ptr::read((rdi).wrapping_add(0x270_u64) as *const u64);
    // intrinsic: f30f10a0 movss xmm4, dword ptr [rax + 0x12c]
    // intrinsic: f30f5825 addss xmm4, dword ptr [rip + 0x2c9326]
    /* 14003b806 */ rax = core::ptr::read((rax).wrapping_add(0x40_u64) as *const u64);
    /* 14003b80a */ rcx = core::ptr::read((rax).wrapping_add(0x30_u64) as *const u64);
    // intrinsic: f30f1069 movss xmm5, dword ptr [rcx + 0x14]
    // intrinsic: f30f1051 movss xmm2, dword ptr [rcx + 0x18]
    // intrinsic: f30f1059 movss xmm3, dword ptr [rcx + 0x10]
    /* 14003b81d */ xmm1 = xmm2;
    // intrinsic: f30f59cc mulss xmm1, xmm4
    /* 14003b824 */ xmm0 = xmm5;
    // intrinsic: f3440f10 movss xmm15, dword ptr [rip + 0x2c7b28]
    // intrinsic: f3410f59 mulss xmm0, xmm15
    // intrinsic: f30f5cc8 subss xmm1, xmm0
    // intrinsic: f30f5849 addss xmm1, dword ptr [rcx + 0xc]
    // intrinsic: f30f118d movss dword ptr [rbp + 0x90], xmm1
    // intrinsic: f30f59ec mulss xmm5, xmm4
    // intrinsic: f3410f59 mulss xmm2, xmm15
    // intrinsic: f30f58ea addss xmm5, xmm2
    // intrinsic: f30f58eb addss xmm5, xmm3
    // intrinsic: f30f11ad movss dword ptr [rbp + 0x94], xmm5
    /* 14003b85f */ rax = core::ptr::read((rdi).wrapping_add(0x260_u64) as *const u64);
    // intrinsic: f30f10a0 movss xmm4, dword ptr [rax + 0x12c]
    // intrinsic: f3410f5c subss xmm4, xmm9
    /* 14003b873 */ rax = core::ptr::read((rax).wrapping_add(0x40_u64) as *const u64);
    /* 14003b877 */ rcx = core::ptr::read((rax).wrapping_add(0x30_u64) as *const u64);
    // intrinsic: f30f1049 movss xmm1, dword ptr [rcx + 0x14]
    // intrinsic: f30f1051 movss xmm2, dword ptr [rcx + 0x18]
    // intrinsic: f30f1059 movss xmm3, dword ptr [rcx + 0x10]
    /* 14003b88a */ let mut xmm5: u128 = xmm2;
    // intrinsic: f30f59ec mulss xmm5, xmm4
    /* 14003b891 */ xmm0 = xmm1;
    // intrinsic: f3410f59 mulss xmm0, xmm9
    // intrinsic: f30f5ce8 subss xmm5, xmm0
    // intrinsic: f30f5869 addss xmm5, dword ptr [rcx + 0xc]
    // intrinsic: f30f11ad movss dword ptr [rbp + 0x98], xmm5
    // intrinsic: f30f59cc mulss xmm1, xmm4
    // intrinsic: f3410f59 mulss xmm2, xmm9
    // intrinsic: f30f58ca addss xmm1, xmm2
    // intrinsic: f30f58cb addss xmm1, xmm3
    // intrinsic: f30f118d movss dword ptr [rbp + 0x9c], xmm1
    /* 14003b8c3 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, 0x10_u32);
    /* 14003b8cb */ let mut t_14003b8cb: u32 = core::ptr::read((0x14003b8d2_u64).wrapping_add(0x398b4e_u64) as *const u32);
    /* 14003b8cb */ r9 = (t_14003b8cb as u64);
    /* 14003b8d2 */ xmm2 = xmm15;
    /* 14003b8d6 */ xmm0 = xmm5;
    /* 14003b8d9 */ fn_140071100();
    /* 14003b8de */ let mut t_14003b8de: u32 = core::ptr::read((0x14003b8e4_u64).wrapping_add(0x3c2e4c_u64) as *const u32);
    /* 14003b8de */ rbx = (t_14003b8de as u64);
    /* 14003b8e4 */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14003b8ed */ rsi = (0x4_u32 as u64);
    /* 14003b8f2 */ rax = core::ptr::read((rax).wrapping_add((rbx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003b8f6 */ let mut t_14003b8f6: u32 = core::ptr::read((rsi).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003b8f6 */ rax = (t_14003b8f6 as u64);
    /* 14003b8f9 */ let mut t_14003b8f9: u32 = core::ptr::read((0x14003b8ff_u64).wrapping_add(0x3ae905_u64) as *const u32);
    if (((SF == OF) & (t_14003b8f9 != (rax as u32))) == false) { /* -> bb3938 */ }
    if (((SF == OF) & (t_14003b8f9 != (rax as u32))) != 0) { /* -> bb3937 */ }

    // ---- bb3937 @ 0x14003b8ff ----
    if (((SF == OF) & (t_14003b8f9 != (rax as u32))) == false) { /* -> bb3938 */ }
    if (((SF == OF) & (t_14003b8f9 != (rax as u32))) != 0) { /* -> bb4758 */ }

    // ---- bb3938 @ 0x14003b905 ----
    /* 14003b905 */ rax = core::ptr::read((rdi).wrapping_add(0x260_u64) as *const u64);
    /* 14003b90c */ rcx = core::ptr::read((rax).wrapping_add(0x40_u64) as *const u64);
    /* 14003b910 */ rax = core::ptr::read((rcx).wrapping_add(0x30_u64) as *const u64);
    // intrinsic: f30f1048 movss xmm1, dword ptr [rax + 0x18]
    // intrinsic: f30f1040 movss xmm0, dword ptr [rax + 0x14]
    /* 14003b91e */ fn_1402cd8d0();
    /* 14003b923 */ fn_1400c6320();
    /* 14003b928 */ xmm3 = xmm0;
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x28], xmm12
    // intrinsic: f30f1005 movss xmm0, dword ptr [rip + 0x2c867a]
    // intrinsic: f30f1144 movss dword ptr [rsp + 0x20], xmm0
    // intrinsic: f30f1095 movss xmm2, dword ptr [rbp + 0x94]
    // intrinsic: f30f108d movss xmm1, dword ptr [rbp + 0x90]
    /* 14003b950 */ let mut t_14003b950: u32 = core::ptr::read((0x14003b956_u64).wrapping_add(0x3ae8aa_u64) as *const u32);
    /* 14003b950 */ rcx = (t_14003b950 as u64);
    /* 14003b956 */ fn_140071eb0();
    // intrinsic: f30f10b5 movss xmm6, dword ptr [rbp + 0x9c]
    /* 14003b963 */ xmm0 = xmm6;
    // intrinsic: f3440f10 movss xmm11, dword ptr [rbp + 0x94]
    // intrinsic: f3410f5c subss xmm0, xmm11
    // intrinsic: f30f10bd movss xmm7, dword ptr [rbp + 0x98]
    /* 14003b97c */ xmm1 = xmm7;
    // intrinsic: f3440f10 movss xmm9, dword ptr [rbp + 0x90]
    // intrinsic: f3410f5c subss xmm1, xmm9
    // intrinsic: f30f59c9 mulss xmm1, xmm1
    // intrinsic: f30f59c0 mulss xmm0, xmm0
    // intrinsic: f30f58c8 addss xmm1, xmm0
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    // intrinsic: 0f2ec100 ucomiss xmm0, xmm1
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) == false) { /* -> bb3969 */ }
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) != 0) { /* -> bb3968 */ }

    // ---- bb3968 @ 0x14003b99f ----
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) == false) { /* -> bb3969 */ }
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) != 0) { /* -> bb4163 */ }

    // ---- bb3969 @ 0x14003b9a5 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    // intrinsic: f30f51c1 sqrtss xmm0, xmm1
    /* fallthrough -> bb4165 */

    // ---- bb3972 @ 0x14003b9b1 ----
    /* 14003b9b1 */ let mut t_14003b9b1: u32 = core::ptr::read((r12).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003b9b1 */ rax = (t_14003b9b1 as u64);
    /* 14003b9b5 */ let mut t_14003b9b5: u32 = core::ptr::read((0x14003b9bb_u64).wrapping_add(0x3ae841_u64) as *const u32);
    if (((SF == OF) & (t_14003b9b5 != (rax as u32))) == false) { /* -> bb3977 */ }
    if (((SF == OF) & (t_14003b9b5 != (rax as u32))) != 0) { /* -> bb3976 */ }

    // ---- bb3976 @ 0x14003b9bb ----
    if (((SF == OF) & (t_14003b9b5 != (rax as u32))) == false) { /* -> bb3977 */ }
    if (((SF == OF) & (t_14003b9b5 != (rax as u32))) != 0) { /* -> bb4785 */ }

    // ---- bb3977 @ 0x14003b9c1 ----
    /* 14003b9c1 */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    // intrinsic: f3440f10 movss xmm11, dword ptr [rax + 0x40]
    // intrinsic: f3440f58 addss xmm11, dword ptr [rip + 0x2c9161]
    /* 14003b9d7 */ let mut t_14003b9d7_0: u32 = 0x0_u32;
    /* 14003b9d7 */ r15 = (t_14003b9d7_0 as u64);
    /* 14003b9da */ rsi = ((r15 as u32) as u64);
    /* 14003b9dd */ r8 = (rdi).wrapping_add(0x2258_u64);
    /* 14003b9e4 */ core::ptr::write((rbp).wrapping_add(0x98_u64) as *mut u64, r8);
    /* 14003b9eb */ rax = (0xf_u32 as u64);
    /* 14003b9f0 */ core::ptr::write((rbp).wrapping_add(0x90_u64) as *mut u32, (rax as u32));
    /* 14003b9f6 */ r12 = (rdi).wrapping_add(0x250_u64);
    /* 14003b9fd */ xmm14 = core::ptr::read((0x14003ba06_u64).wrapping_add(0x2c79ea_u64) as *const u128);
    // intrinsic: f3440f10 movss xmm13, dword ptr [rip + 0x2c7d4d]
    // intrinsic: f3440f10 movss xmm8, dword ptr [rip + 0x2c797c]
    /* fallthrough -> bb3991 */

    // ---- bb3991 @ 0x14003ba20 ----
    /* 14003ba20 */ xmm6 = ((rax as u32) as u128);
    // intrinsic: 0f5bf600 cvtdq2ps xmm6, xmm6
    // intrinsic: f3410f59 mulss xmm6, xmm9
    /* 14003ba2c */ rax = core::ptr::read((rdi).wrapping_add(0x280_u64) as *const u64);
    // intrinsic: f30f5870 addss xmm6, dword ptr [rax + 0x44]
    /* 14003ba38 */ xmm1 = xmm12;
    /* 14003ba3c */ let mut t_14003ba3c: u8 = core::ptr::read(r8 as *const u8);
    if (t_14003ba3c != 0x0_u8) {
        /* -> bb4001 */
    } else {
        /* -> bb4000 */
    }

    // ---- bb4000 @ 0x14003ba40 ----
    if (t_14003ba3c != 0x0_u8) {
        /* -> bb4001 */
    } else {
        /* -> bb4071 */
    }

    // ---- bb4001 @ 0x14003ba46 ----
    /* 14003ba46 */ let mut t_14003ba46: u32 = core::ptr::read((rdi).wrapping_add(0x225c_u64) as *const u32);
    if (t_14003ba46 == (rsi as u32)) {
        /* -> bb4005 */
    } else {
        /* -> bb4004 */
    }

    // ---- bb4004 @ 0x14003ba4c ----
    if (t_14003ba46 == (rsi as u32)) {
        /* -> bb4005 */
    } else {
        /* -> bb4072 */
    }

    // ---- bb4005 @ 0x14003ba52 ----
    /* 14003ba52 */ let mut t_14003ba52: u32 = core::ptr::read(r12 as *const u32);
    /* 14003ba52 */ rcx = (t_14003ba52 as u64);
    /* 14003ba56 */ rax = (((rcx).wrapping_sub(0x3c_u64) as u32) as u64);
    if (((CF == false) & ((rax as u32) != 0x77_u32)) == false) { /* -> bb4011 */ }
    if (((CF == false) & ((rax as u32) != 0x77_u32)) != 0) { /* -> bb4010 */ }

    // ---- bb4010 @ 0x14003ba5c ----
    if (((CF == false) & ((rax as u32) != 0x77_u32)) == false) { /* -> bb4011 */ }
    if (((CF == false) & ((rax as u32) != 0x77_u32)) != 0) { /* -> bb4072 */ }

    // ---- bb4011 @ 0x14003ba62 ----
    /* 14003ba62 */ rax = (0x66666667_u32 as u64);
    /* 14003ba67 */ let mut t_14003ba67_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 14003ba67 */ rdx = (((t_14003ba67_0 >> 0x20_u64) as u32) as u64);
    /* 14003ba67 */ rax = ((t_14003ba67_0 as u32) as u64);
    /* 14003ba69 */ rdx = (((((rdx as u32) as i64) >> ((0x2_u8 as u32) as i64)) as u64) as u64);
    /* 14003ba6c */ rax = ((rdx as u32) as u64);
    /* 14003ba6e */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 14003ba71 */ let mut t_14003ba71_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 14003ba71 */ rdx = (t_14003ba71_0 as u64);
    /* 14003ba73 */ rax = (((rdx).wrapping_add((rdx).wrapping_mul(0x4_u64)) as u32) as u64);
    /* 14003ba76 */ let mut t_14003ba76_0: u32 = ((rax as u32)).wrapping_add((rax as u32));
    /* 14003ba76 */ rax = (t_14003ba76_0 as u64);
    /* 14003ba78 */ let mut t_14003ba78_0: u32 = ((rcx as u32)).wrapping_sub((rax as u32));
    /* 14003ba78 */ rcx = (t_14003ba78_0 as u64);
    if (SF != OF) {
        /* -> bb4024 */
    } else {
        /* -> bb4023 */
    }

    // ---- bb4023 @ 0x14003ba7d ----
    if (SF != OF) {
        /* -> bb4024 */
    } else {
        /* -> bb4072 */
    }

    // ---- bb4024 @ 0x14003ba83 ----
    if ((rcx as u32) == 0x1_u32) {
        /* -> bb4028 */
    } else {
        /* -> bb4027 */
    }

    // ---- bb4027 @ 0x14003ba86 ----
    if ((rcx as u32) == 0x1_u32) {
        /* -> bb4028 */
    } else {
        /* -> bb4071 */
    }

    // ---- bb4028 @ 0x14003ba8c ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003ba8f */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u128, xmm0);
    /* 14003ba94 */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u128, xmm14);
    /* 14003ba9a */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb4032 */ }
    if DF { /* -> bb4033 */ }

    // ---- bb4032 @ 0x14003ba9a ----
    /* 14003ba9a */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003ba9a */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb4034 */

    // ---- bb4033 @ 0x14003ba9a ----
    /* 14003ba9a */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003ba9a */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb4034 */

    // ---- bb4034 @ 0x14003baa2 ----
    /* 14003baa2 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4036 */ }
    if DF { /* -> bb4037 */ }

    // ---- bb4036 @ 0x14003baa2 ----
    /* 14003baa2 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003baa2 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4038 */

    // ---- bb4037 @ 0x14003baa2 ----
    /* 14003baa2 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003baa2 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4038 */

    // ---- bb4038 @ 0x14003baa8 ----
    /* 14003baa8 */ let mut t_14003baa8: u16 = core::ptr::read((0x14003baaf_u64).wrapping_add(0x2c9009_u64) as *const u16);
    /* 14003baa8 */ rax = ((t_14003baa8 as u32) as u64);
    /* 14003baaf */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u16, (rax as u16));
    /* 14003bab3 */ core::ptr::write((rbp).wrapping_sub(0x7e_u64) as *mut u8, 0x0_u8);
    /* 14003bab7 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 14003babc */ xmm3 = xmm10;
    /* 14003bac0 */ let mut t_14003bac0_0: u32 = 0x0_u32;
    /* 14003bac0 */ r8 = (t_14003bac0_0 as u64);
    /* 14003bac3 */ rdx = (0x64_u32 as u64);
    /* 14003bac8 */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003bacd */ fn_140040b90();
    /* 14003bad3 */ rdx = core::ptr::read((rbp).wrapping_sub(0x70_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb4054 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb4053 */ }

    // ---- bb4053 @ 0x14003badb ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb4054 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb4070 */ }

    // ---- bb4054 @ 0x14003badd ----
    /* 14003badd */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 14003bae0 */ rcx = core::ptr::read((rsp).wrapping_add(0x78_u64) as *const u64);
    /* 14003bae5 */ rax = rcx;
    if (CF == false) { /* -> bb4061 */ }
    if CF { /* -> bb4060 */ }

    // ---- bb4060 @ 0x14003baef ----
    if (CF == false) { /* -> bb4061 */ }
    if CF { /* -> bb4069 */ }

    // ---- bb4061 @ 0x14003baf1 ----
    /* 14003baf1 */ let mut t_14003baf1_0: u64 = (rdx).wrapping_add(0x27_u64);
    /* 14003baf1 */ rdx = t_14003baf1_0;
    /* 14003baf5 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 14003baf9 */ let mut t_14003baf9_0: u64 = (rax).wrapping_sub(rcx);
    /* 14003baf9 */ rax = t_14003baf9_0;
    /* 14003bafc */ let mut t_14003bafc_0: u64 = (rax).wrapping_sub(0x8_u64);
    /* 14003bafc */ rax = t_14003bafc_0;
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb4069 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb4068 */ }

    // ---- bb4068 @ 0x14003bb04 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb4069 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb4804 */ }

    // ---- bb4069 @ 0x14003bb0a ----
    /* 14003bb0a */ fn_1402c7498();
    /* fallthrough -> bb4070 */

    // ---- bb4070 @ 0x14003bb0f ----
    /* 14003bb0f */ r8 = core::ptr::read((rbp).wrapping_add(0x98_u64) as *const u64);
    /* fallthrough -> bb4071 */

    // ---- bb4071 @ 0x14003bb16 ----
    /* 14003bb16 */ xmm1 = xmm13;
    /* fallthrough -> bb4072 */

    // ---- bb4072 @ 0x14003bb1a ----
    /* 14003bb1a */ let mut t_14003bb1a: u8 = core::ptr::read(r8 as *const u8);
    if (t_14003bb1a != 0x0_u8) {
        /* -> bb4076 */
    } else {
        /* -> bb4075 */
    }

    // ---- bb4075 @ 0x14003bb1e ----
    if (t_14003bb1a != 0x0_u8) {
        /* -> bb4076 */
    } else {
        /* -> bb4079 */
    }

    // ---- bb4076 @ 0x14003bb20 ----
    /* 14003bb20 */ rcx = (((rsi).wrapping_add(0x1_u64) as u32) as u64);
    /* 14003bb23 */ rbx = ((rcx as u32) as u64);
    /* fallthrough -> bb4081 */

    // ---- bb4079 @ 0x14003bb27 ----
    /* 14003bb27 */ rcx = ((r15 as u32) as u64);
    /* 14003bb2a */ rbx = (((rsi).wrapping_add(0x1_u64) as u32) as u64);
    /* fallthrough -> bb4081 */

    // ---- bb4081 @ 0x14003bb2d ----
    // intrinsic: f3410f58 addss xmm1, xmm11
    /* 14003bb32 */ let mut t_14003bb32: u32 = core::ptr::read((0x14003bb38_u64).wrapping_add(0x3ae6c0_u64) as *const u32);
    /* 14003bb32 */ let mut t_14003bb32_0: u32 = ((rcx as u32)).wrapping_add(t_14003bb32);
    /* 14003bb32 */ rcx = (t_14003bb32_0 as u64);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003bb3f */ xmm3 = xmm9;
    /* 14003bb43 */ xmm2 = xmm6;
    /* 14003bb46 */ fn_140071e80();
    /* 14003bb4b */ let mut t_14003bb4b: u32 = core::ptr::read(r12 as *const u32);
    if (t_14003bb4b == 0xb2_u32) {
        /* -> bb4091 */
    } else {
        /* -> bb4090 */
    }

    // ---- bb4090 @ 0x14003bb53 ----
    if (t_14003bb4b == 0xb2_u32) {
        /* -> bb4091 */
    } else {
        /* -> bb4151 */
    }

    // ---- bb4091 @ 0x14003bb59 ----
    /* 14003bb59 */ let mut t_14003bb59: u32 = core::ptr::read((rdi).wrapping_add(0x225c_u64) as *const u32);
    if (t_14003bb59 == (rsi as u32)) {
        /* -> bb4095 */
    } else {
        /* -> bb4094 */
    }

    // ---- bb4094 @ 0x14003bb5f ----
    if (t_14003bb59 == (rsi as u32)) {
        /* -> bb4095 */
    } else {
        /* -> bb4151 */
    }

    // ---- bb4095 @ 0x14003bb65 ----
    /* 14003bb65 */ let mut t_14003bb65: u32 = core::ptr::read((0x14003bb6b_u64).wrapping_add(0x398889_u64) as *const u32);
    /* 14003bb65 */ rax = (t_14003bb65 as u64);
    /* 14003bb6b */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, (rax as u32));
    /* 14003bb6f */ let mut t_14003bb6f: u32 = core::ptr::read((0x14003bb75_u64).wrapping_add(0x398887_u64) as *const u32);
    /* 14003bb6f */ rax = (t_14003bb6f as u64);
    /* 14003bb75 */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u32, (rax as u32));
    /* 14003bb79 */ let mut t_14003bb79: u32 = core::ptr::read((0x14003bb7f_u64).wrapping_add(0x398879_u64) as *const u32);
    /* 14003bb79 */ rax = (t_14003bb79 as u64);
    /* 14003bb7f */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u32, (rax as u32));
    /* 14003bb83 */ let mut t_14003bb83: u32 = core::ptr::read((0x14003bb89_u64).wrapping_add(0x3988a3_u64) as *const u32);
    /* 14003bb83 */ rax = (t_14003bb83 as u64);
    /* 14003bb89 */ core::ptr::write((rsp).wrapping_add(0x64_u64) as *mut u32, (rax as u32));
    /* 14003bb8d */ core::ptr::write((rdi).wrapping_add(0x2234_u64) as *mut u32, (r15 as u32));
    /* 14003bb94 */ xmm7 = xmm11;
    // intrinsic: f30f593d mulss xmm7, dword ptr [rip + 0x2c8430]
    // intrinsic: f3440f10 movss xmm15, dword ptr [rip + 0x2c77e3]
    // intrinsic: f3410f58 addss xmm7, xmm15
    // intrinsic: f30f5935 mulss xmm6, dword ptr [rip + 0x2c841a]
    // intrinsic: f3410f58 addss xmm6, xmm8
    /* 14003bbbb */ rax = (((rsi as u32) as i64) as u64);
    /* 14003bbbe */ r15 = (rsp).wrapping_add(0x58_u64);
    /* 14003bbc3 */ r15 = (r15).wrapping_add((rax).wrapping_mul(0x4_u64));
    /* 14003bbc7 */ rbx = (0x14_u32 as u64);
    /* fallthrough -> bb4115 */

    // ---- bb4115 @ 0x14003bbd0 ----
    /* 14003bbd0 */ xmm1 = xmm10;
    /* 14003bbd4 */ rcx = (rbp).wrapping_add(0xa0_u64);
    /* 14003bbdb */ fn_1400c7110();
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c83fc]
    /* 14003bbe8 */ xmm0 = xmm8;
    /* 14003bbec */ fn_1400c6d50();
    /* 14003bbf1 */ xmm1 = xmm0;
    // intrinsic: f30f1095 movss xmm2, dword ptr [rbp + 0xa0]
    // intrinsic: f30f59ca mulss xmm1, xmm2
    // intrinsic: f30f118d movss dword ptr [rbp + 0xa8], xmm1
    // intrinsic: f30f109d movss xmm3, dword ptr [rbp + 0xa4]
    // intrinsic: f30f59c3 mulss xmm0, xmm3
    // intrinsic: f30f1185 movss dword ptr [rbp + 0xac], xmm0
    // intrinsic: f3410f59 mulss xmm2, xmm15
    // intrinsic: f30f58d7 addss xmm2, xmm7
    // intrinsic: f30f1154 movss dword ptr [rsp + 0x50], xmm2
    // intrinsic: f3410f59 mulss xmm3, xmm15
    // intrinsic: f30f58de addss xmm3, xmm6
    // intrinsic: f30f115c movss dword ptr [rsp + 0x54], xmm3
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x40], xmm10
    /* 14003bc41 */ core::ptr::write((rsp).wrapping_add(0x38_u64) as *mut u32, 0x2d_u32);
    /* 14003bc49 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, r15);
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x28], xmm12
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm12
    /* 14003bc5c */ r9 = (rbp).wrapping_add(0xa8_u64);
    /* 14003bc63 */ r8 = (rsp).wrapping_add(0x50_u64);
    /* 14003bc68 */ rdx = (0xffffffff_u32 as u64);
    /* 14003bc6d */ rcx = (rdi).wrapping_add(0x2f0_u64);
    /* 14003bc74 */ fn_1400c91d0();
    /* 14003bc79 */ let mut t_14003bc79_0: u64 = (rbx).wrapping_sub(0x1_u64);
    /* 14003bc79 */ rbx = t_14003bc79_0;
    if (t_14003bb59 == (rsi as u32)) {
        /* -> bb4148 */
    } else {
        /* -> bb4147 */
    }

    // ---- bb4147 @ 0x14003bc7d ----
    if (t_14003bb59 != (rsi as u32)) {
        /* -> bb4115 */
    } else {
        /* -> bb4148 */
    }

    // ---- bb4148 @ 0x14003bc83 ----
    // intrinsic: f3440f10 movss xmm15, dword ptr [rip + 0x361094]
    /* 14003bc8c */ rbx = (((rsi).wrapping_add(0x1_u64) as u32) as u64);
    /* 14003bc8f */ let mut t_14003bc8f_0: u32 = 0x0_u32;
    /* 14003bc8f */ r15 = (t_14003bc8f_0 as u64);
    /* fallthrough -> bb4151 */

    // ---- bb4151 @ 0x14003bc92 ----
    /* 14003bc92 */ rsi = ((rbx as u32) as u64);
    /* 14003bc94 */ let mut t_14003bc94: u32 = core::ptr::read((rbp).wrapping_add(0x90_u64) as *const u32);
    /* 14003bc94 */ rax = (t_14003bc94 as u64);
    /* 14003bc9a */ let mut t_14003bc9a_0: u32 = ((rax as u32)).wrapping_add(0x9_u32);
    /* 14003bc9a */ rax = (t_14003bc9a_0 as u64);
    /* 14003bc9d */ core::ptr::write((rbp).wrapping_add(0x90_u64) as *mut u32, (rax as u32));
    /* 14003bca3 */ r8 = core::ptr::read((rbp).wrapping_add(0x98_u64) as *const u64);
    /* 14003bcaa */ r8 = (r8).wrapping_add(0x1_u64);
    /* 14003bcad */ core::ptr::write((rbp).wrapping_add(0x98_u64) as *mut u64, r8);
    if (SF != OF) {
        /* -> bb4162 */
    } else {
        /* -> bb4161 */
    }

    // ---- bb4161 @ 0x14003bcb7 ----
    if (SF == OF) {
        /* -> bb3796 */
    } else {
        /* -> bb4162 */
    }

    // ---- bb4162 @ 0x14003bcbd ----
    /* fallthrough -> bb3991 */

    // ---- bb4163 @ 0x14003bcc2 ----
    /* 14003bcc2 */ xmm0 = xmm1;
    /* 14003bcc5 */ fn_1402ce3b0();
    /* fallthrough -> bb4165 */

    // ---- bb4165 @ 0x14003bcca ----
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x360f7e]
    // intrinsic: 0f2fc800 comiss xmm1, xmm0
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) == false) { /* -> bb4170 */ }
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) != 0) { /* -> bb4169 */ }

    // ---- bb4169 @ 0x14003bcd5 ----
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) == false) { /* -> bb4170 */ }
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) != 0) { /* -> bb4171 */ }

    // ---- bb4170 @ 0x14003bcd7 ----
    /* 14003bcd7 */ xmm12 = xmm0;
    /* fallthrough -> bb4171 */

    // ---- bb4171 @ 0x14003bcdb ----
    // intrinsic: f30f1087 movss xmm0, dword ptr [rdi + 0x224c]
    // intrinsic: f3440f5e divss xmm12, xmm0
    /* 14003bce8 */ xmm13 = xmm10;
    // intrinsic: f3450f5c subss xmm13, xmm12
    // intrinsic: f30f5905 mulss xmm0, dword ptr [rip + 0x360f9b]
    // intrinsic: f3440f59 mulss xmm13, xmm0
    // intrinsic: f3440f10 movss xmm12, dword ptr [rip + 0x2c8e1d]
    // intrinsic: 450f2fe5 comiss xmm12, xmm13
    if ((CF | (t_14003c6c1 == 0xffffffff_u32)) == false) { /* -> bb4182 */ }
    if ((CF | (t_14003c6c1 == 0xffffffff_u32)) != 0) { /* -> bb4181 */ }

    // ---- bb4181 @ 0x14003bd0b ----
    if ((CF | (t_14003c6c1 == 0xffffffff_u32)) == false) { /* -> bb4182 */ }
    if ((CF | (t_14003c6c1 == 0xffffffff_u32)) != 0) { /* -> bb4189 */ }

    // ---- bb4182 @ 0x14003bd0d ----
    /* 14003bd0d */ r9 = (0x14003bd14_u64).wrapping_add(0x39870c_u64);
    /* 14003bd14 */ xmm2 = xmm12;
    /* 14003bd18 */ rdx = (rbp).wrapping_add(0x90_u64);
    /* 14003bd1f */ rcx = (rbp).wrapping_add(0x98_u64);
    /* 14003bd26 */ fn_140071940();
    /* fallthrough -> bb4187 */

    // ---- bb4187 @ 0x14003bd2b ----
    // intrinsic: f3440f10 movss xmm15, dword ptr [rip + 0x360fec]
    /* fallthrough -> bb4258 */

    // ---- bb4189 @ 0x14003bd39 ----
    /* 14003bd39 */ xmm0 = xmm9;
    // intrinsic: 410f14c3 unpcklps xmm0, xmm11
    /* 14003bd41 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4192 */ }
    if DF { /* -> bb4193 */ }

    // ---- bb4192 @ 0x14003bd41 ----
    /* 14003bd41 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003bd41 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4194 */

    // ---- bb4193 @ 0x14003bd41 ----
    /* 14003bd41 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003bd41 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4194 */

    // ---- bb4194 @ 0x14003bd49 ----
    /* 14003bd49 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4196 */ }
    if DF { /* -> bb4197 */ }

    // ---- bb4196 @ 0x14003bd49 ----
    /* 14003bd49 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003bd49 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4199 */

    // ---- bb4197 @ 0x14003bd49 ----
    /* 14003bd49 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003bd49 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4199 */

    // ---- bb4199 @ 0x14003bd51 ----
    // intrinsic: 450f57c0 xorps xmm8, xmm8
    // intrinsic: f3450f2a cvtsi2ss xmm8, r13d
    // intrinsic: f3450f59 mulss xmm8, xmm15
    // intrinsic: f3410f5c subss xmm7, xmm9
    // intrinsic: f3410f59 mulss xmm7, xmm8
    // intrinsic: f3410f58 addss xmm7, xmm9
    // intrinsic: f30f11bd movss dword ptr [rbp + 0xa0], xmm7
    /* 14003bd76 */ rax = (((r13).wrapping_sub(0x4_u64) as u32) as u64);
    /* 14003bd7a */ rcx = ((rax as u32) as u64);
    /* 14003bd7c */ let mut t_14003bd7c_0: u32 = (0x0_u32).wrapping_sub((rcx as u32));
    /* 14003bd7c */ rcx = (t_14003bd7c_0 as u64);
    if (SF == false) { /* -> bb4210 */ }
    if SF { /* -> bb4211 */ }

    // ---- bb4211 @ 0x14003bd7e ----
    /* 14003bd7e */ rcx = ((rax as u32) as u64);
    /* fallthrough -> bb4210 */

    // ---- bb4210 @ 0x14003bd81 ----
    /* 14003bd81 */ rax = (0x4_u32 as u64);
    /* 14003bd86 */ let mut t_14003bd86_0: u32 = ((rax as u32)).wrapping_sub((rcx as u32));
    /* 14003bd86 */ rax = (t_14003bd86_0 as u64);
    // intrinsic: 0f57c900 xorps xmm1, xmm1
    // intrinsic: f30f2ac8 cvtsi2ss xmm1, eax
    // intrinsic: f3410f59 mulss xmm1, xmm14
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    // intrinsic: 0f2ec100 ucomiss xmm0, xmm1
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) == false) { /* -> bb4222 */ }
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) != 0) { /* -> bb4221 */ }

    // ---- bb4221 @ 0x14003bd9a ----
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) == false) { /* -> bb4222 */ }
    if (((CF == false) & (t_14003c6c1 != 0xffffffff_u32)) != 0) { /* -> bb4225 */ }

    // ---- bb4222 @ 0x14003bd9c ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    // intrinsic: f30f51c1 sqrtss xmm0, xmm1
    /* fallthrough -> bb4227 */

    // ---- bb4225 @ 0x14003bda5 ----
    /* 14003bda5 */ xmm0 = xmm1;
    /* 14003bda8 */ fn_1402ce3b0();
    /* fallthrough -> bb4227 */

    // ---- bb4227 @ 0x14003bdad ----
    // intrinsic: f3410f59 mulss xmm0, xmm13
    // intrinsic: f3410f5c subss xmm6, xmm11
    // intrinsic: f3410f59 mulss xmm6, xmm8
    // intrinsic: f3410f58 addss xmm6, xmm11
    // intrinsic: f30f58c6 addss xmm0, xmm6
    // intrinsic: f30f1185 movss dword ptr [rbp + 0xa4], xmm0
    /* 14003bdcd */ r9 = (0x14003bdd4_u64).wrapping_add(0x39864c_u64);
    /* 14003bdd4 */ xmm2 = xmm12;
    /* 14003bdd8 */ rdx = (rbp).wrapping_add(0xa0_u64);
    /* 14003bddf */ rcx = (rbp).wrapping_add(0xa8_u64);
    /* 14003bde6 */ fn_140071940();
    /* 14003bdeb */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb4239 */ }
    if DF { /* -> bb4240 */ }

    // ---- bb4239 @ 0x14003bdeb ----
    /* 14003bdeb */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003bdeb */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb4241 */

    // ---- bb4240 @ 0x14003bdeb ----
    /* 14003bdeb */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003bdeb */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb4241 */

    // ---- bb4241 @ 0x14003bdf3 ----
    /* 14003bdf3 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4243 */ }
    if DF { /* -> bb4244 */ }

    // ---- bb4243 @ 0x14003bdf3 ----
    /* 14003bdf3 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003bdf3 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4245 */

    // ---- bb4244 @ 0x14003bdf3 ----
    /* 14003bdf3 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003bdf3 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4245 */

    // ---- bb4245 @ 0x14003bdfb ----
    /* 14003bdfb */ r13 = (((r13 as u32)).wrapping_add(0x1_u32) as u64);
    if (((SF == OF) & ((r13 as u32) != 0x8_u32)) == false) { /* -> bb4251 */ }
    if (((SF == OF) & ((r13 as u32) != 0x8_u32)) != 0) { /* -> bb4250 */ }

    // ---- bb4250 @ 0x14003be02 ----
    if (((SF == OF) & ((r13 as u32) != 0x8_u32)) != 0) { /* -> bb4187 */ }
    if (((SF == OF) & ((r13 as u32) != 0x8_u32)) == false) { /* -> bb4251 */ }

    // ---- bb4251 @ 0x14003be08 ----
    // intrinsic: f3440f10 movss xmm11, dword ptr [rbp + 0x94]
    // intrinsic: f3440f10 movss xmm9, dword ptr [rbp + 0x90]
    // intrinsic: f30f10b5 movss xmm6, dword ptr [rbp + 0x9c]
    // intrinsic: f30f10bd movss xmm7, dword ptr [rbp + 0x98]
    /* fallthrough -> bb4199 */

    // ---- bb4256 @ 0x14003be2f ----
    /* 14003be2f */ rsi = (0x4_u32 as u64);
    /* 14003be34 */ let mut t_14003be34: u32 = core::ptr::read((0x14003be3a_u64).wrapping_add(0x3c28f6_u64) as *const u32);
    /* 14003be34 */ rbx = (t_14003be34 as u64);
    /* fallthrough -> bb4258 */

    // ---- bb4258 @ 0x14003be3a ----
    /* 14003be3a */ fn_1400730b0();
    /* 14003be3f */ let mut t_14003be3f: u32 = core::ptr::read((rdi).wrapping_add(0x254_u64) as *const u32);
    if (t_14003be3f == 0x5_u32) {
        /* -> bb4263 */
    } else {
        /* -> bb4262 */
    }

    // ---- bb4262 @ 0x14003be46 ----
    if (t_14003be3f == 0x5_u32) {
        /* -> bb4263 */
    } else {
        /* -> bb4340 */
    }

    // ---- bb4263 @ 0x14003be4c ----
    /* 14003be4c */ let mut t_14003be4c: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    /* 14003be4c */ rax = (t_14003be4c as u64);
    /* 14003be52 */ let mut t_14003be52_0: u32 = ((rax as u32)).wrapping_sub(0x3_u32);
    /* 14003be52 */ rax = (t_14003be52_0 as u64);
    if (((CF == false) & ((rax as u32) != 0x4_u32)) == false) { /* -> bb4269 */ }
    if (((CF == false) & ((rax as u32) != 0x4_u32)) != 0) { /* -> bb4268 */ }

    // ---- bb4268 @ 0x14003be58 ----
    if (((CF == false) & ((rax as u32) != 0x4_u32)) == false) { /* -> bb4269 */ }
    if (((CF == false) & ((rax as u32) != 0x4_u32)) != 0) { /* -> bb4340 */ }

    // ---- bb4269 @ 0x14003be5e ----
    /* 14003be5e */ rcx = ((rbx as u32) as u64);
    /* 14003be60 */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14003be69 */ rdx = ((rsi as u32) as u64);
    /* 14003be6b */ rax = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003be6f */ let mut t_14003be6f: u32 = core::ptr::read((rdx).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003be6f */ rax = (t_14003be6f as u64);
    /* 14003be72 */ let mut t_14003be72: u32 = core::ptr::read((0x14003be78_u64).wrapping_add(0x3ae394_u64) as *const u32);
    if (((SF == OF) & (t_14003be72 != (rax as u32))) == false) { /* -> bb4278 */ }
    if (((SF == OF) & (t_14003be72 != (rax as u32))) != 0) { /* -> bb4277 */ }

    // ---- bb4277 @ 0x14003be78 ----
    if (((SF == OF) & (t_14003be72 != (rax as u32))) == false) { /* -> bb4278 */ }
    if (((SF == OF) & (t_14003be72 != (rax as u32))) != 0) { /* -> bb4811 */ }

    // ---- bb4278 @ 0x14003be7e ----
    /* 14003be7e */ xmm7 = xmm10;
    /* 14003be82 */ let mut t_14003be82: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 14003be82 */ rax = (t_14003be82 as u64);
    /* 14003be88 */ let mut t_14003be88_0: u32 = ((rax as u32)).wrapping_add(0x1e_u32);
    /* 14003be88 */ rax = (t_14003be88_0 as u64);
    /* 14003be8b */ let mut t_14003be8b: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    if (t_14003be8b == 0x3_u32) {
        /* -> bb4285 */
    } else {
        /* -> bb4284 */
    }

    // ---- bb4284 @ 0x14003be92 ----
    if (t_14003be8b == 0x3_u32) {
        /* -> bb4285 */
    } else {
        /* -> bb4321 */
    }

    // ---- bb4285 @ 0x14003be94 ----
    if (SF == OF) {
        /* -> bb4289 */
    } else {
        /* -> bb4288 */
    }

    // ---- bb4288 @ 0x14003be99 ----
    if (SF == OF) {
        /* -> bb4289 */
    } else {
        /* -> bb4321 */
    }

    // ---- bb4289 @ 0x14003be9b ----
    if (SF != OF) {
        /* -> bb4293 */
    } else {
        /* -> bb4292 */
    }

    // ---- bb4292 @ 0x14003bea0 ----
    if (SF != OF) {
        /* -> bb4293 */
    } else {
        /* -> bb4304 */
    }

    // ---- bb4293 @ 0x14003bea2 ----
    /* 14003bea2 */ let mut t_14003bea2_0: u32 = ((rax as u32)).wrapping_add(0xffffff4c_u32);
    /* 14003bea2 */ rax = (t_14003bea2_0 as u64);
    /* 14003bea7 */ xmm1 = ((rax as u32) as u128);
    // intrinsic: f30fe6c9 cvtdq2pd xmm1, xmm1
    // intrinsic: f20f590d mulsd xmm1, qword ptr [rip + 0x2c8cc9]
    // intrinsic: f20f5e0d divsd xmm1, qword ptr [rip + 0x2c8d01]
    /* 14003bebf */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb4299 */ }
    if DF { /* -> bb4300 */ }

    // ---- bb4299 @ 0x14003bebf ----
    /* 14003bebf */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003bebf */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb4301 */

    // ---- bb4300 @ 0x14003bebf ----
    /* 14003bebf */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003bebf */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb4301 */

    // ---- bb4301 @ 0x14003bec7 ----
    // intrinsic: f20f5cc1 subsd xmm0, xmm1
    /* fallthrough -> bb4320 */

    // ---- bb4304 @ 0x14003becd ----
    if (SF != OF) {
        /* -> bb4308 */
    } else {
        /* -> bb4307 */
    }

    // ---- bb4307 @ 0x14003bed2 ----
    if (SF != OF) {
        /* -> bb4308 */
    } else {
        /* -> bb4310 */
    }

    // ---- bb4308 @ 0x14003bed4 ----
    /* 14003bed4 */ xmm7 = xmm14;
    /* fallthrough -> bb4321 */

    // ---- bb4310 @ 0x14003beda ----
    if (SF != OF) {
        /* -> bb4314 */
    } else {
        /* -> bb4313 */
    }

    // ---- bb4313 @ 0x14003bedf ----
    if (SF != OF) {
        /* -> bb4314 */
    } else {
        /* -> bb4321 */
    }

    // ---- bb4314 @ 0x14003bee1 ----
    /* 14003bee1 */ let mut t_14003bee1_0: u32 = ((rax as u32)).wrapping_add(0xfffffe20_u32);
    /* 14003bee1 */ rax = (t_14003bee1_0 as u64);
    /* 14003bee6 */ xmm0 = ((rax as u32) as u128);
    // intrinsic: f30fe6c0 cvtdq2pd xmm0, xmm0
    // intrinsic: f20f5905 mulsd xmm0, qword ptr [rip + 0x2c8c8a]
    // intrinsic: f20f5e05 divsd xmm0, qword ptr [rip + 0x2c8cba]
    // intrinsic: f20f5805 addsd xmm0, qword ptr [rip + 0x2c8c5a]
    /* fallthrough -> bb4320 */

    // ---- bb4320 @ 0x14003bf06 ----
    // intrinsic: 660f5af8 cvtpd2ps xmm7, xmm0
    /* fallthrough -> bb4321 */

    // ---- bb4321 @ 0x14003bf0a ----
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm10
    /* 14003bf11 */ xmm3 = xmm7;
    // intrinsic: f30f1035 movss xmm6, dword ptr [rip + 0x2c80f0]
    /* 14003bf1c */ xmm2 = xmm6;
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c8119]
    /* 14003bf27 */ let mut t_14003bf27: u32 = core::ptr::read((0x14003bf2d_u64).wrapping_add(0x3ae2db_u64) as *const u32);
    /* 14003bf27 */ rcx = (t_14003bf27 as u64);
    /* 14003bf2d */ fn_140071e80();
    // intrinsic: 410f57ff xorps xmm7, xmm15
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm10
    /* 14003bf3d */ xmm3 = xmm7;
    /* 14003bf40 */ xmm2 = xmm6;
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c8cf9]
    /* 14003bf4b */ let mut t_14003bf4b: u32 = core::ptr::read((0x14003bf51_u64).wrapping_add(0x3ae2b7_u64) as *const u32);
    /* 14003bf4b */ rcx = (t_14003bf4b as u64);
    /* 14003bf51 */ fn_140071e80();
    /* 14003bf56 */ let mut t_14003bf56: u32 = core::ptr::read((0x14003bf5c_u64).wrapping_add(0x3ae2ac_u64) as *const u32);
    /* 14003bf56 */ rcx = (t_14003bf56 as u64);
    /* 14003bf5c */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    // intrinsic: f30f1015 movss xmm2, dword ptr [rip + 0x2c8ca6]
    // intrinsic: f30f100d movss xmm1, dword ptr [rip + 0x2c8caa]
    /* 14003bf6e */ fn_140071cd0();
    /* fallthrough -> bb4340 */

    // ---- bb4340 @ 0x14003bf73 ----
    /* 14003bf73 */ let mut t_14003bf73: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    if (t_14003bf73 == 0x6_u32) {
        /* -> bb4344 */
    } else {
        /* -> bb4343 */
    }

    // ---- bb4343 @ 0x14003bf7a ----
    if (t_14003bf73 == 0x6_u32) {
        /* -> bb4344 */
    } else {
        /* -> bb4376 */
    }

    // ---- bb4344 @ 0x14003bf80 ----
    /* 14003bf80 */ rcx = ((rbx as u32) as u64);
    /* 14003bf82 */ rax = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14003bf8b */ rdx = ((rsi as u32) as u64);
    /* 14003bf8d */ rax = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14003bf91 */ let mut t_14003bf91: u32 = core::ptr::read((rdx).wrapping_add((rax).wrapping_mul(0x1_u64)) as *const u32);
    /* 14003bf91 */ rax = (t_14003bf91 as u64);
    /* 14003bf94 */ let mut t_14003bf94: u32 = core::ptr::read((0x14003bf9a_u64).wrapping_add(0x3ae27a_u64) as *const u32);
    if (((SF == OF) & (t_14003bf94 != (rax as u32))) == false) { /* -> bb4353 */ }
    if (((SF == OF) & (t_14003bf94 != (rax as u32))) != 0) { /* -> bb4352 */ }

    // ---- bb4352 @ 0x14003bf9a ----
    if (((SF == OF) & (t_14003bf94 != (rax as u32))) == false) { /* -> bb4353 */ }
    if (((SF == OF) & (t_14003bf94 != (rax as u32))) != 0) { /* -> bb4457 */ }

    // ---- bb4353 @ 0x14003bfa0 ----
    /* 14003bfa0 */ let mut t_14003bfa0: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 14003bfa0 */ rax = (t_14003bfa0 as u64);
    /* 14003bfa6 */ let mut t_14003bfa6_0: u32 = ((rax as u32)).wrapping_add(0xffffffe4_u32);
    /* 14003bfa6 */ rax = (t_14003bfa6_0 as u64);
    /* 14003bfa9 */ rcx = (0x0_u32 as u64);
    if (SF == false) { /* -> bb4357 */ }
    if SF { /* -> bb4358 */ }

    // ---- bb4358 @ 0x14003bfae ----
    /* 14003bfae */ rcx = ((rax as u32) as u64);
    /* fallthrough -> bb4357 */

    // ---- bb4357 @ 0x14003bfb1 ----
    /* 14003bfb1 */ xmm6 = ((rcx as u32) as u128);
    // intrinsic: 0f5bf600 cvtdq2ps xmm6, xmm6
    /* 14003bfb8 */ let mut t_14003bfb8: u32 = core::ptr::read((0x14003bfc0_u64).wrapping_add(0x3b19d4_u64) as *const u32);
    /* 14003bfb8 */ xmm1 = (t_14003bfb8 as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    // intrinsic: f30f58ce addss xmm1, xmm6
    // intrinsic: f30f103d movss xmm7, dword ptr [rip + 0x2c73f5]
    /* 14003bfcf */ xmm2 = xmm7;
    /* 14003bfd2 */ let mut t_14003bfd2: u32 = core::ptr::read((0x14003bfd8_u64).wrapping_add(0x3ae238_u64) as *const u32);
    /* 14003bfd2 */ rcx = (t_14003bfd2 as u64);
    /* 14003bfd8 */ fn_140071cd0();
    /* 14003bfdd */ let mut t_14003bfdd: u32 = core::ptr::read((0x14003bfe5_u64).wrapping_add(0x39de63_u64) as *const u32);
    /* 14003bfdd */ xmm1 = (t_14003bfdd as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    // intrinsic: f30f5cce subss xmm1, xmm6
    // intrinsic: f3440f11 movss dword ptr [rsp + 0x20], xmm10
    // intrinsic: f30f101d movss xmm3, dword ptr [rip + 0x360ce5]
    /* 14003bffb */ xmm2 = xmm7;
    /* 14003bffe */ let mut t_14003bffe: u32 = core::ptr::read((0x14003c004_u64).wrapping_add(0x3ae20c_u64) as *const u32);
    /* 14003bffe */ rcx = (t_14003bffe as u64);
    /* 14003c004 */ fn_140071e80();
    /* fallthrough -> bb4376 */

    // ---- bb4376 @ 0x14003c009 ----
    /* 14003c009 */ rcx = (rdi).wrapping_add(0x2f0_u64);
    /* 14003c010 */ fn_1400c96a0();
    /* 14003c015 */ let mut t_14003c015: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    if (t_14003c015 == 0x7_u32) {
        /* -> bb4382 */
    } else {
        /* -> bb4381 */
    }

    // ---- bb4381 @ 0x14003c01c ----
    if (t_14003c015 == 0x7_u32) {
        /* -> bb4382 */
    } else {
        /* -> bb4412 */
    }

    // ---- bb4382 @ 0x14003c01e ----
    /* 14003c01e */ let mut t_14003c01e: u32 = core::ptr::read((rdi).wrapping_add(0x250_u64) as *const u32);
    /* 14003c01e */ rcx = (t_14003c01e as u64);
    /* 14003c024 */ rcx = (((rcx as u32) << (0x4_u8 as u32)) as u64);
    /* 14003c027 */ core::ptr::write((rbp).wrapping_add(0x90_u64) as *mut u16, 0x0_u16);
    /* 14003c030 */ core::ptr::write((rbp).wrapping_add(0x92_u64) as *mut u8, 0x0_u8);
    /* 14003c037 */ rax = (((rcx as u8) as u32) as u64);
    /* 14003c03a */ rdx = (0xa0_u32 as u64);
    if (((SF == OF) & ((rcx as u32) != (rdx as u32))) == false) { /* -> bb4390 */ }
    if (((SF == OF) & ((rcx as u32) != (rdx as u32))) != 0) { /* -> bb4391 */ }

    // ---- bb4391 @ 0x14003c041 ----
    /* 14003c041 */ rax = ((rdx as u32) as u64);
    /* fallthrough -> bb4390 */

    // ---- bb4390 @ 0x14003c044 ----
    /* 14003c044 */ core::ptr::write((rbp).wrapping_add(0x93_u64) as *mut u8, (rax as u8));
    /* 14003c04a */ let mut t_14003c04a: u32 = core::ptr::read((0x14003c050_u64).wrapping_add(0x2cf684_u64) as *const u32);
    /* 14003c04a */ rax = (t_14003c04a as u64);
    /* 14003c050 */ let mut t_14003c050: u32 = core::ptr::read((0x14003c056_u64).wrapping_add(0x3b19ae_u64) as *const u32);
    /* 14003c050 */ rdx = (t_14003c050 as u64);
    /* 14003c056 */ rax = (((rax).wrapping_add((rdx).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 14003c059 */ xmm3 = ((rax as u32) as u128);
    // intrinsic: 0f5bdb00 cvtdq2ps xmm3, xmm3
    /* 14003c060 */ let mut t_14003c060: u32 = core::ptr::read((0x14003c066_u64).wrapping_add(0x2cf66a_u64) as *const u32);
    /* 14003c060 */ rax = (t_14003c060 as u64);
    /* 14003c066 */ let mut t_14003c066: u32 = core::ptr::read((0x14003c06c_u64).wrapping_add(0x3b1994_u64) as *const u32);
    /* 14003c066 */ rcx = (t_14003c066 as u64);
    /* 14003c06c */ rax = (((rax).wrapping_add((rcx).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 14003c06f */ xmm2 = ((rax as u32) as u128);
    // intrinsic: 0f5bd200 cvtdq2ps xmm2, xmm2
    /* 14003c076 */ let mut t_14003c076_0: u32 = (0x0_u32).wrapping_sub((rdx as u32));
    /* 14003c076 */ rdx = (t_14003c076_0 as u64);
    /* 14003c078 */ xmm1 = ((rdx as u32) as u128);
    // intrinsic: 0f5bc900 cvtdq2ps xmm1, xmm1
    /* 14003c07f */ let mut t_14003c07f_0: u32 = (0x0_u32).wrapping_sub((rcx as u32));
    /* 14003c07f */ rcx = (t_14003c07f_0 as u64);
    /* 14003c081 */ xmm0 = ((rcx as u32) as u128);
    // intrinsic: 0f5bc000 cvtdq2ps xmm0, xmm0
    /* 14003c088 */ let mut t_14003c088: u32 = core::ptr::read((rbp).wrapping_add(0x90_u64) as *const u32);
    /* 14003c088 */ rax = (t_14003c088 as u64);
    /* 14003c08e */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 14003c092 */ fn_140070fb0();
    /* fallthrough -> bb4412 */

    // ---- bb4412 @ 0x14003c097 ----
    /* 14003c097 */ let mut t_14003c097: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    /* 14003c097 */ rax = (t_14003c097 as u64);
    if (SF == OF) {
        /* -> bb4417 */
    } else {
        /* -> bb4416 */
    }

    // ---- bb4416 @ 0x14003c0a0 ----
    if (SF == OF) {
        /* -> bb4417 */
    } else {
        /* -> bb4421 */
    }

    // ---- bb4417 @ 0x14003c0a2 ----
    if (SF == OF) {
        /* -> bb4421 */
    } else {
        /* -> bb4420 */
    }

    // ---- bb4420 @ 0x14003c0a5 ----
    if (SF == OF) {
        /* -> bb4421 */
    } else {
        /* -> bb4430 */
    }

    // ---- bb4421 @ 0x14003c0a7 ----
    /* 14003c0a7 */ let mut t_14003c0a7: u32 = core::ptr::read((rdi).wrapping_add(0x225c_u64) as *const u32);
    if (t_14003c0a7 == 0xffffffff_u32) {
        /* -> bb4425 */
    } else {
        /* -> bb4424 */
    }

    // ---- bb4424 @ 0x14003c0ae ----
    if (t_14003c0a7 == 0xffffffff_u32) {
        /* -> bb4425 */
    } else {
        /* -> bb4430 */
    }

    // ---- bb4425 @ 0x14003c0b0 ----
    /* 14003c0b0 */ r8 = ((r8 & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 14003c0b3 */ rdx = (((r8 as u8) as u32) as u64);
    /* 14003c0b7 */ rcx = rdi;
    /* 14003c0ba */ fn_1400cb0e0();
    /* fallthrough -> bb4436 */

    // ---- bb4430 @ 0x14003c0c1 ----
    if ((rax as u32) == 0x6_u32) {
        /* -> bb4434 */
    } else {
        /* -> bb4433 */
    }

    // ---- bb4433 @ 0x14003c0c4 ----
    if ((rax as u32) == 0x6_u32) {
        /* -> bb4434 */
    } else {
        /* -> bb4436 */
    }

    // ---- bb4434 @ 0x14003c0c6 ----
    /* 14003c0c6 */ rcx = rdi;
    /* 14003c0c9 */ fn_1400d68f0();
    /* fallthrough -> bb4436 */

    // ---- bb4436 @ 0x14003c0ce ----
    /* 14003c0ce */ r11 = (rsp).wrapping_add(0x148_u64);
    /* 14003c0d6 */ xmm6 = core::ptr::read((r11).wrapping_sub(0x18_u64) as *const u128);
    /* 14003c0db */ xmm7 = core::ptr::read((r11).wrapping_sub(0x28_u64) as *const u128);
    /* 14003c0e0 */ xmm8 = core::ptr::read((r11).wrapping_sub(0x38_u64) as *const u128);
    /* 14003c0e5 */ xmm9 = core::ptr::read((r11).wrapping_sub(0x48_u64) as *const u128);
    /* 14003c0ea */ xmm10 = core::ptr::read((r11).wrapping_sub(0x58_u64) as *const u128);
    /* 14003c0ef */ xmm11 = core::ptr::read((r11).wrapping_sub(0x68_u64) as *const u128);
    /* 14003c0f4 */ xmm12 = core::ptr::read((r11).wrapping_sub(0x78_u64) as *const u128);
    /* 14003c0f9 */ xmm13 = core::ptr::read((r11).wrapping_sub(0x88_u64) as *const u128);
    /* 14003c101 */ xmm14 = core::ptr::read((r11).wrapping_sub(0x98_u64) as *const u128);
    /* 14003c109 */ xmm15 = core::ptr::read((r11).wrapping_sub(0xa8_u64) as *const u128);
    /* 14003c111 */ rsp = r11;
    /* 14003c114 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003c114 */ r15 = core::ptr::read(rsp as *const u64);
    /* 14003c116 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003c116 */ r14 = core::ptr::read(rsp as *const u64);
    /* 14003c118 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003c118 */ r13 = core::ptr::read(rsp as *const u64);
    /* 14003c11a */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003c11a */ r12 = core::ptr::read(rsp as *const u64);
    /* 14003c11c */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003c11c */ rdi = core::ptr::read(rsp as *const u64);
    /* 14003c11d */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003c11d */ rsi = core::ptr::read(rsp as *const u64);
    /* 14003c11e */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003c11e */ rbx = core::ptr::read(rsp as *const u64);
    /* 14003c11f */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14003c11f */ rbp = core::ptr::read(rsp as *const u64);
    /* 14003c120 */ return;
    // <no successors>

    // ---- bb4457 @ 0x14003c121 ----
    /* 14003c121 */ rcx = (0x14003c128_u64).wrapping_add(0x3ae0ec_u64);
    /* 14003c128 */ fn_1402c7548();
    /* 14003c12d */ let mut t_14003c12d: u32 = core::ptr::read((0x14003c134_u64).wrapping_add(0x3ae0e0_u64) as *const u32);
    if (t_14003c12d == 0xffffffff_u32) {
        /* -> bb4463 */
    } else {
        /* -> bb4462 */
    }

    // ---- bb4462 @ 0x14003c134 ----
    if (t_14003c12d != 0xffffffff_u32) {
        /* -> bb4353 */
    } else {
        /* -> bb4463 */
    }

    // ---- bb4463 @ 0x14003c13a ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c13d */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u128, xmm0);
    /* 14003c142 */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u64, 0x6_u64);
    /* 14003c14a */ core::ptr::write((rbp).wrapping_sub(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c152 */ let mut t_14003c152: u32 = core::ptr::read((0x14003c158_u64).wrapping_add(0x2c88c4_u64) as *const u32);
    /* 14003c152 */ rax = (t_14003c152 as u64);
    /* 14003c158 */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u32, (rax as u32));
    /* 14003c15c */ let mut t_14003c15c: u16 = core::ptr::read((0x14003c163_u64).wrapping_add(0x2c88bd_u64) as *const u16);
    /* 14003c15c */ rax = ((t_14003c15c as u32) as u64);
    /* 14003c163 */ core::ptr::write((rsp).wrapping_add(0x7c_u64) as *mut u16, (rax as u16));
    /* 14003c168 */ core::ptr::write((rsp).wrapping_add(0x7e_u64) as *mut u8, 0x0_u8);
    /* 14003c16d */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003c172 */ fn_14006fd40();
    /* 14003c177 */ core::ptr::write((0x14003c17d_u64).wrapping_add(0x3ae093_u64) as *mut u32, (rax as u32));
    /* 14003c17d */ rcx = (0x14003c184_u64).wrapping_add(0x3ae090_u64);
    /* 14003c184 */ fn_1402c74dc();
    /* fallthrough -> bb4353 */

    // ---- bb4478 @ 0x14003c18e ----
    /* 14003c18e */ rcx = (0x14003c195_u64).wrapping_add(0x3ae007_u64);
    /* 14003c195 */ fn_1402c7548();
    /* 14003c19a */ let mut t_14003c19a: u32 = core::ptr::read((0x14003c1a1_u64).wrapping_add(0x3adffb_u64) as *const u32);
    if (t_14003c19a == 0xffffffff_u32) {
        /* -> bb4484 */
    } else {
        /* -> bb4483 */
    }

    // ---- bb4483 @ 0x14003c1a1 ----
    if (t_14003c19a != 0xffffffff_u32) {
        /* -> bb2947 */
    } else {
        /* -> bb4484 */
    }

    // ---- bb4484 @ 0x14003c1a7 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c1aa */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 14003c1af */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0x9_u64);
    /* 14003c1b8 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c1c1 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb4489 */ }
    if DF { /* -> bb4490 */ }

    // ---- bb4489 @ 0x14003c1c1 ----
    /* 14003c1c1 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003c1c1 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb4491 */

    // ---- bb4490 @ 0x14003c1c1 ----
    /* 14003c1c1 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003c1c1 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb4491 */

    // ---- bb4491 @ 0x14003c1c9 ----
    /* 14003c1c9 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4493 */ }
    if DF { /* -> bb4494 */ }

    // ---- bb4493 @ 0x14003c1c9 ----
    /* 14003c1c9 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003c1c9 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4495 */

    // ---- bb4494 @ 0x14003c1c9 ----
    /* 14003c1c9 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003c1c9 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4495 */

    // ---- bb4495 @ 0x14003c1cf ----
    /* 14003c1cf */ let mut t_14003c1cf: u8 = core::ptr::read((0x14003c1d6_u64).wrapping_add(0x2c887a_u64) as *const u8);
    /* 14003c1cf */ rax = ((t_14003c1cf as u32) as u64);
    /* 14003c1d6 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u8, (rax as u8));
    /* 14003c1da */ core::ptr::write((rsp).wrapping_add(0x61_u64) as *mut u8, 0x0_u8);
    /* 14003c1df */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14003c1e4 */ fn_14006fd40();
    /* 14003c1e9 */ core::ptr::write((0x14003c1ef_u64).wrapping_add(0x3adfa9_u64) as *mut u32, (rax as u32));
    /* 14003c1ef */ rcx = (0x14003c1f6_u64).wrapping_add(0x3adfa6_u64);
    /* 14003c1f6 */ fn_1402c74dc();
    /* fallthrough -> bb2947 */

    // ---- bb4505 @ 0x14003c200 ----
    /* 14003c200 */ rcx = (0x14003c207_u64).wrapping_add(0x3adf9d_u64);
    /* 14003c207 */ fn_1402c7548();
    /* 14003c20c */ let mut t_14003c20c: u32 = core::ptr::read((0x14003c213_u64).wrapping_add(0x3adf91_u64) as *const u32);
    if (t_14003c20c == 0xffffffff_u32) {
        /* -> bb4511 */
    } else {
        /* -> bb4510 */
    }

    // ---- bb4510 @ 0x14003c213 ----
    if (t_14003c20c != 0xffffffff_u32) {
        /* -> bb2987 */
    } else {
        /* -> bb4511 */
    }

    // ---- bb4511 @ 0x14003c219 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c21c */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u128, xmm0);
    /* 14003c221 */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u64, 0x8_u64);
    /* 14003c229 */ core::ptr::write((rbp).wrapping_sub(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c231 */ rax = 0x65636e6569647541_u64;
    /* 14003c23b */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u64, rax);
    /* 14003c240 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u8, 0x0_u8);
    /* 14003c244 */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003c249 */ fn_14006fd40();
    /* 14003c24e */ core::ptr::write((0x14003c254_u64).wrapping_add(0x3adf4c_u64) as *mut u32, (rax as u32));
    /* 14003c254 */ rcx = (0x14003c25b_u64).wrapping_add(0x3adf49_u64);
    /* 14003c25b */ fn_1402c74dc();
    /* fallthrough -> bb2987 */

    // ---- bb4524 @ 0x14003c265 ----
    /* 14003c265 */ rcx = (0x14003c26c_u64).wrapping_add(0x3adf40_u64);
    /* 14003c26c */ fn_1402c7548();
    /* 14003c271 */ let mut t_14003c271: u32 = core::ptr::read((0x14003c278_u64).wrapping_add(0x3adf34_u64) as *const u32);
    if (t_14003c271 == 0xffffffff_u32) {
        /* -> bb4530 */
    } else {
        /* -> bb4529 */
    }

    // ---- bb4529 @ 0x14003c278 ----
    if (t_14003c271 != 0xffffffff_u32) {
        /* -> bb3215 */
    } else {
        /* -> bb4530 */
    }

    // ---- bb4530 @ 0x14003c27e ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c281 */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u128, xmm0);
    /* 14003c286 */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u64, 0x8_u64);
    /* 14003c28e */ core::ptr::write((rbp).wrapping_sub(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c296 */ rax = 0x657375616c707041_u64;
    /* 14003c2a0 */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u64, rax);
    /* 14003c2a5 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u8, 0x0_u8);
    /* 14003c2a9 */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003c2ae */ fn_14006fd40();
    /* 14003c2b3 */ core::ptr::write((0x14003c2b9_u64).wrapping_add(0x3adeef_u64) as *mut u32, (rax as u32));
    /* 14003c2b9 */ rcx = (0x14003c2c0_u64).wrapping_add(0x3adeec_u64);
    /* 14003c2c0 */ fn_1402c74dc();
    /* fallthrough -> bb3215 */

    // ---- bb4543 @ 0x14003c2ca ----
    /* 14003c2ca */ rcx = (0x14003c2d1_u64).wrapping_add(0x3adee3_u64);
    /* 14003c2d1 */ fn_1402c7548();
    /* 14003c2d6 */ let mut t_14003c2d6: u32 = core::ptr::read((0x14003c2dd_u64).wrapping_add(0x3aded7_u64) as *const u32);
    if (t_14003c2d6 == 0xffffffff_u32) {
        /* -> bb4549 */
    } else {
        /* -> bb4548 */
    }

    // ---- bb4548 @ 0x14003c2dd ----
    if (t_14003c2d6 != 0xffffffff_u32) {
        /* -> bb3256 */
    } else {
        /* -> bb4549 */
    }

    // ---- bb4549 @ 0x14003c2e3 ----
    /* 14003c2e3 */ core::ptr::write((rsp).wrapping_add(0x64_u64) as *mut u32, (r13 as u32));
    /* 14003c2e8 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0xb_u64);
    /* 14003c2f1 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c2fa */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb4553 */ }
    if DF { /* -> bb4554 */ }

    // ---- bb4553 @ 0x14003c2fa ----
    /* 14003c2fa */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003c2fa */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb4555 */

    // ---- bb4554 @ 0x14003c2fa ----
    /* 14003c2fa */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003c2fa */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb4555 */

    // ---- bb4555 @ 0x14003c302 ----
    /* 14003c302 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4557 */ }
    if DF { /* -> bb4558 */ }

    // ---- bb4557 @ 0x14003c302 ----
    /* 14003c302 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003c302 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4559 */

    // ---- bb4558 @ 0x14003c302 ----
    /* 14003c302 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003c302 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4559 */

    // ---- bb4559 @ 0x14003c308 ----
    /* 14003c308 */ let mut t_14003c308: u16 = core::ptr::read((0x14003c30f_u64).wrapping_add(0x2c8751_u64) as *const u16);
    /* 14003c308 */ rax = ((t_14003c308 as u32) as u64);
    /* 14003c30f */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u16, (rax as u16));
    /* 14003c314 */ let mut t_14003c314: u8 = core::ptr::read((0x14003c31b_u64).wrapping_add(0x2c8747_u64) as *const u8);
    /* 14003c314 */ rax = ((t_14003c314 as u32) as u64);
    /* 14003c31b */ core::ptr::write((rsp).wrapping_add(0x62_u64) as *mut u8, (rax as u8));
    /* 14003c31f */ core::ptr::write((rsp).wrapping_add(0x63_u64) as *mut u8, 0x0_u8);
    /* 14003c324 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14003c329 */ fn_14006fd40();
    /* 14003c32e */ core::ptr::write((0x14003c334_u64).wrapping_add(0x3ade7c_u64) as *mut u32, (rax as u32));
    /* 14003c334 */ rcx = (0x14003c33b_u64).wrapping_add(0x3ade79_u64);
    /* 14003c33b */ fn_1402c74dc();
    /* fallthrough -> bb3256 */

    // ---- bb4571 @ 0x14003c345 ----
    /* 14003c345 */ rcx = (0x14003c34c_u64).wrapping_add(0x3ade70_u64);
    /* 14003c34c */ fn_1402c7548();
    /* 14003c351 */ let mut t_14003c351: u32 = core::ptr::read((0x14003c358_u64).wrapping_add(0x3ade64_u64) as *const u32);
    if (t_14003c351 == 0xffffffff_u32) {
        /* -> bb4577 */
    } else {
        /* -> bb4576 */
    }

    // ---- bb4576 @ 0x14003c358 ----
    if (t_14003c351 != 0xffffffff_u32) {
        /* -> bb3291 */
    } else {
        /* -> bb4577 */
    }

    // ---- bb4577 @ 0x14003c35e ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c361 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 14003c366 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0x9_u64);
    /* 14003c36f */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c378 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb4582 */ }
    if DF { /* -> bb4583 */ }

    // ---- bb4582 @ 0x14003c378 ----
    /* 14003c378 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003c378 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb4584 */

    // ---- bb4583 @ 0x14003c378 ----
    /* 14003c378 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003c378 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb4584 */

    // ---- bb4584 @ 0x14003c380 ----
    /* 14003c380 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4586 */ }
    if DF { /* -> bb4587 */ }

    // ---- bb4586 @ 0x14003c380 ----
    /* 14003c380 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003c380 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4588 */

    // ---- bb4587 @ 0x14003c380 ----
    /* 14003c380 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003c380 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4588 */

    // ---- bb4588 @ 0x14003c386 ----
    /* 14003c386 */ let mut t_14003c386: u8 = core::ptr::read((0x14003c38d_u64).wrapping_add(0x2c86e3_u64) as *const u8);
    /* 14003c386 */ rax = ((t_14003c386 as u32) as u64);
    /* 14003c38d */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u8, (rax as u8));
    /* 14003c391 */ core::ptr::write((rsp).wrapping_add(0x61_u64) as *mut u8, 0x0_u8);
    /* 14003c396 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14003c39b */ fn_14006fd40();
    /* 14003c3a0 */ core::ptr::write((0x14003c3a6_u64).wrapping_add(0x3ade12_u64) as *mut u32, (rax as u32));
    /* 14003c3a6 */ rcx = (0x14003c3ad_u64).wrapping_add(0x3ade0f_u64);
    /* 14003c3ad */ fn_1402c74dc();
    /* fallthrough -> bb3291 */

    // ---- bb4598 @ 0x14003c3b7 ----
    /* 14003c3b7 */ rcx = (0x14003c3be_u64).wrapping_add(0x3ade06_u64);
    /* 14003c3be */ fn_1402c7548();
    /* 14003c3c3 */ let mut t_14003c3c3: u32 = core::ptr::read((0x14003c3ca_u64).wrapping_add(0x3addfa_u64) as *const u32);
    if (t_14003c3c3 == 0xffffffff_u32) {
        /* -> bb4604 */
    } else {
        /* -> bb4603 */
    }

    // ---- bb4603 @ 0x14003c3ca ----
    if (t_14003c3c3 != 0xffffffff_u32) {
        /* -> bb3317 */
    } else {
        /* -> bb4604 */
    }

    // ---- bb4604 @ 0x14003c3d0 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c3d3 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 14003c3d8 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0xa_u64);
    /* 14003c3e1 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c3ea */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb4609 */ }
    if DF { /* -> bb4610 */ }

    // ---- bb4609 @ 0x14003c3ea ----
    /* 14003c3ea */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003c3ea */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb4611 */

    // ---- bb4610 @ 0x14003c3ea ----
    /* 14003c3ea */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003c3ea */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb4611 */

    // ---- bb4611 @ 0x14003c3f2 ----
    /* 14003c3f2 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4613 */ }
    if DF { /* -> bb4614 */ }

    // ---- bb4613 @ 0x14003c3f2 ----
    /* 14003c3f2 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003c3f2 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4615 */

    // ---- bb4614 @ 0x14003c3f2 ----
    /* 14003c3f2 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003c3f2 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4615 */

    // ---- bb4615 @ 0x14003c3f8 ----
    /* 14003c3f8 */ let mut t_14003c3f8: u16 = core::ptr::read((0x14003c3ff_u64).wrapping_add(0x2c8681_u64) as *const u16);
    /* 14003c3f8 */ rax = ((t_14003c3f8 as u32) as u64);
    /* 14003c3ff */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u16, (rax as u16));
    /* 14003c404 */ core::ptr::write((rsp).wrapping_add(0x62_u64) as *mut u8, 0x0_u8);
    /* 14003c409 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14003c40e */ fn_14006fd40();
    /* 14003c413 */ core::ptr::write((0x14003c419_u64).wrapping_add(0x3adda7_u64) as *mut u32, (rax as u32));
    /* 14003c419 */ rcx = (0x14003c420_u64).wrapping_add(0x3adda4_u64);
    /* 14003c420 */ fn_1402c74dc();
    /* fallthrough -> bb3317 */

    // ---- bb4625 @ 0x14003c42a ----
    /* 14003c42a */ rcx = (0x14003c431_u64).wrapping_add(0x3add9b_u64);
    /* 14003c431 */ fn_1402c7548();
    /* 14003c436 */ let mut t_14003c436: u32 = core::ptr::read((0x14003c43d_u64).wrapping_add(0x3add8f_u64) as *const u32);
    if (t_14003c436 == 0xffffffff_u32) {
        /* -> bb4631 */
    } else {
        /* -> bb4630 */
    }

    // ---- bb4630 @ 0x14003c43d ----
    if (t_14003c436 != 0xffffffff_u32) {
        /* -> bb3426 */
    } else {
        /* -> bb4631 */
    }

    // ---- bb4631 @ 0x14003c443 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c446 */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u128, xmm0);
    /* 14003c44b */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u64, 0x8_u64);
    /* 14003c453 */ core::ptr::write((rbp).wrapping_sub(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c45b */ rax = 0x74616c5065766944_u64;
    /* 14003c465 */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u64, rax);
    /* 14003c46a */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u8, 0x0_u8);
    /* 14003c46e */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003c473 */ fn_14006fd40();
    /* 14003c478 */ core::ptr::write((0x14003c47e_u64).wrapping_add(0x3add4a_u64) as *mut u32, (rax as u32));
    /* 14003c47e */ rcx = (0x14003c485_u64).wrapping_add(0x3add47_u64);
    /* 14003c485 */ fn_1402c74dc();
    /* fallthrough -> bb3426 */

    // ---- bb4644 @ 0x14003c48f ----
    /* 14003c48f */ rcx = (0x14003c496_u64).wrapping_add(0x3add3e_u64);
    /* 14003c496 */ fn_1402c7548();
    /* 14003c49b */ let mut t_14003c49b: u32 = core::ptr::read((0x14003c4a2_u64).wrapping_add(0x3add32_u64) as *const u32);
    if (t_14003c49b == 0xffffffff_u32) {
        /* -> bb4650 */
    } else {
        /* -> bb4649 */
    }

    // ---- bb4649 @ 0x14003c4a2 ----
    if (t_14003c49b != 0xffffffff_u32) {
        /* -> bb3507 */
    } else {
        /* -> bb4650 */
    }

    // ---- bb4650 @ 0x14003c4a8 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c4ab */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 14003c4b0 */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0x9_u64);
    /* 14003c4b9 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c4c2 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb4655 */ }
    if DF { /* -> bb4656 */ }

    // ---- bb4655 @ 0x14003c4c2 ----
    /* 14003c4c2 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003c4c2 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb4657 */

    // ---- bb4656 @ 0x14003c4c2 ----
    /* 14003c4c2 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003c4c2 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb4657 */

    // ---- bb4657 @ 0x14003c4ca ----
    /* 14003c4ca */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4659 */ }
    if DF { /* -> bb4660 */ }

    // ---- bb4659 @ 0x14003c4ca ----
    /* 14003c4ca */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003c4ca */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4661 */

    // ---- bb4660 @ 0x14003c4ca ----
    /* 14003c4ca */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003c4ca */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4661 */

    // ---- bb4661 @ 0x14003c4d0 ----
    /* 14003c4d0 */ let mut t_14003c4d0: u8 = core::ptr::read((0x14003c4d7_u64).wrapping_add(0x2c85b9_u64) as *const u8);
    /* 14003c4d0 */ rax = ((t_14003c4d0 as u32) as u64);
    /* 14003c4d7 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u8, (rax as u8));
    /* 14003c4db */ core::ptr::write((rsp).wrapping_add(0x61_u64) as *mut u8, 0x0_u8);
    /* 14003c4e0 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14003c4e5 */ fn_14006fd40();
    /* 14003c4ea */ core::ptr::write((0x14003c4f0_u64).wrapping_add(0x3adce0_u64) as *mut u32, (rax as u32));
    /* 14003c4f0 */ rcx = (0x14003c4f7_u64).wrapping_add(0x3adcdd_u64);
    /* 14003c4f7 */ fn_1402c74dc();
    /* fallthrough -> bb3507 */

    // ---- bb4671 @ 0x14003c501 ----
    /* 14003c501 */ rcx = (0x14003c508_u64).wrapping_add(0x3adcd4_u64);
    /* 14003c508 */ fn_1402c7548();
    /* 14003c50d */ let mut t_14003c50d: u32 = core::ptr::read((0x14003c514_u64).wrapping_add(0x3adcc8_u64) as *const u32);
    if (t_14003c50d == 0xffffffff_u32) {
        /* -> bb4677 */
    } else {
        /* -> bb4676 */
    }

    // ---- bb4676 @ 0x14003c514 ----
    if (t_14003c50d != 0xffffffff_u32) {
        /* -> bb3548 */
    } else {
        /* -> bb4677 */
    }

    // ---- bb4677 @ 0x14003c51a ----
    /* 14003c51a */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u64, r13);
    /* 14003c51f */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0x7_u64);
    /* 14003c528 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c531 */ rax = core::ptr::read((0x14003c538_u64).wrapping_add(0x2c8560_u64) as *const u64);
    /* 14003c538 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, (rax as u32));
    /* 14003c53c */ let mut t_14003c53c: u16 = core::ptr::read((0x14003c543_u64).wrapping_add(0x2c8559_u64) as *const u16);
    /* 14003c53c */ rax = ((t_14003c53c as u32) as u64);
    /* 14003c543 */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u16, (rax as u16));
    /* 14003c548 */ let mut t_14003c548: u8 = core::ptr::read((0x14003c54f_u64).wrapping_add(0x2c854f_u64) as *const u8);
    /* 14003c548 */ rax = ((t_14003c548 as u32) as u64);
    /* 14003c54f */ core::ptr::write((rsp).wrapping_add(0x5e_u64) as *mut u8, (rax as u8));
    /* 14003c553 */ core::ptr::write((rsp).wrapping_add(0x5f_u64) as *mut u8, 0x0_u8);
    /* 14003c558 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14003c55d */ fn_14006fd40();
    /* 14003c562 */ core::ptr::write((0x14003c568_u64).wrapping_add(0x3adc70_u64) as *mut u32, (rax as u32));
    /* 14003c568 */ rcx = (0x14003c56f_u64).wrapping_add(0x3adc6d_u64);
    /* 14003c56f */ fn_1402c74dc();
    /* fallthrough -> bb3548 */

    // ---- bb4693 @ 0x14003c579 ----
    /* 14003c579 */ rcx = (0x14003c580_u64).wrapping_add(0x3adc64_u64);
    /* 14003c580 */ fn_1402c7548();
    /* 14003c585 */ let mut t_14003c585: u32 = core::ptr::read((0x14003c58c_u64).wrapping_add(0x3adc58_u64) as *const u32);
    if (t_14003c585 == 0xffffffff_u32) {
        /* -> bb4699 */
    } else {
        /* -> bb4698 */
    }

    // ---- bb4698 @ 0x14003c58c ----
    if (t_14003c585 != 0xffffffff_u32) {
        /* -> bb3568 */
    } else {
        /* -> bb4699 */
    }

    // ---- bb4699 @ 0x14003c592 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c595 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u128, xmm0);
    /* 14003c59a */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0x9_u64);
    /* 14003c5a3 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c5ac */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb4704 */ }
    if DF { /* -> bb4705 */ }

    // ---- bb4704 @ 0x14003c5ac ----
    /* 14003c5ac */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003c5ac */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb4706 */

    // ---- bb4705 @ 0x14003c5ac ----
    /* 14003c5ac */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003c5ac */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb4706 */

    // ---- bb4706 @ 0x14003c5b4 ----
    /* 14003c5b4 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4708 */ }
    if DF { /* -> bb4709 */ }

    // ---- bb4708 @ 0x14003c5b4 ----
    /* 14003c5b4 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003c5b4 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4710 */

    // ---- bb4709 @ 0x14003c5b4 ----
    /* 14003c5b4 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003c5b4 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4710 */

    // ---- bb4710 @ 0x14003c5ba ----
    /* 14003c5ba */ let mut t_14003c5ba: u8 = core::ptr::read((0x14003c5c1_u64).wrapping_add(0x2c84e7_u64) as *const u8);
    /* 14003c5ba */ rax = ((t_14003c5ba as u32) as u64);
    /* 14003c5c1 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u8, (rax as u8));
    /* 14003c5c5 */ core::ptr::write((rsp).wrapping_add(0x61_u64) as *mut u8, 0x0_u8);
    /* 14003c5ca */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14003c5cf */ fn_14006fd40();
    /* 14003c5d4 */ core::ptr::write((0x14003c5da_u64).wrapping_add(0x3adc06_u64) as *mut u32, (rax as u32));
    /* 14003c5da */ rcx = (0x14003c5e1_u64).wrapping_add(0x3adc03_u64);
    /* 14003c5e1 */ fn_1402c74dc();
    /* fallthrough -> bb3568 */

    // ---- bb4720 @ 0x14003c5eb ----
    /* 14003c5eb */ rcx = (0x14003c5f2_u64).wrapping_add(0x3adbfa_u64);
    /* 14003c5f2 */ fn_1402c7548();
    /* 14003c5f7 */ let mut t_14003c5f7: u32 = core::ptr::read((0x14003c5fe_u64).wrapping_add(0x3adbee_u64) as *const u32);
    if (t_14003c5f7 == 0xffffffff_u32) {
        /* -> bb4726 */
    } else {
        /* -> bb4725 */
    }

    // ---- bb4725 @ 0x14003c5fe ----
    if (t_14003c5f7 != 0xffffffff_u32) {
        /* -> bb3583 */
    } else {
        /* -> bb4726 */
    }

    // ---- bb4726 @ 0x14003c604 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c607 */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u128, xmm0);
    /* 14003c60c */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u64, 0x8_u64);
    /* 14003c614 */ core::ptr::write((rbp).wrapping_sub(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c61c */ rax = 0x706f6f486f726341_u64;
    /* 14003c626 */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u64, rax);
    /* 14003c62b */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u8, 0x0_u8);
    /* 14003c62f */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003c634 */ fn_14006fd40();
    /* 14003c639 */ core::ptr::write((0x14003c63f_u64).wrapping_add(0x3adba9_u64) as *mut u32, (rax as u32));
    /* 14003c63f */ rcx = (0x14003c646_u64).wrapping_add(0x3adba6_u64);
    /* 14003c646 */ fn_1402c74dc();
    /* fallthrough -> bb3583 */

    // ---- bb4739 @ 0x14003c650 ----
    /* 14003c650 */ rcx = (0x14003c657_u64).wrapping_add(0x3adb9d_u64);
    /* 14003c657 */ fn_1402c7548();
    /* 14003c65c */ let mut t_14003c65c: u32 = core::ptr::read((0x14003c663_u64).wrapping_add(0x3adb91_u64) as *const u32);
    if (t_14003c65c == 0xffffffff_u32) {
        /* -> bb4745 */
    } else {
        /* -> bb4744 */
    }

    // ---- bb4744 @ 0x14003c663 ----
    if (t_14003c65c != 0xffffffff_u32) {
        /* -> bb3751 */
    } else {
        /* -> bb4745 */
    }

    // ---- bb4745 @ 0x14003c669 ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c66c */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u128, xmm0);
    /* 14003c671 */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u64, 0x8_u64);
    /* 14003c679 */ core::ptr::write((rbp).wrapping_sub(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c681 */ rax = 0x6e65704f746e6554_u64;
    /* 14003c68b */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u64, rax);
    /* 14003c690 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u8, 0x0_u8);
    /* 14003c694 */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003c699 */ fn_14006fd40();
    /* 14003c69e */ core::ptr::write((0x14003c6a4_u64).wrapping_add(0x3adb4c_u64) as *mut u32, (rax as u32));
    /* 14003c6a4 */ rcx = (0x14003c6ab_u64).wrapping_add(0x3adb49_u64);
    /* 14003c6ab */ fn_1402c74dc();
    /* fallthrough -> bb3751 */

    // ---- bb4758 @ 0x14003c6b5 ----
    /* 14003c6b5 */ rcx = (0x14003c6bc_u64).wrapping_add(0x3adb48_u64);
    /* 14003c6bc */ fn_1402c7548();
    /* 14003c6c1 */ let mut t_14003c6c1: u32 = core::ptr::read((0x14003c6c8_u64).wrapping_add(0x3adb3c_u64) as *const u32);
    if (t_14003c6c1 == 0xffffffff_u32) {
        /* -> bb4764 */
    } else {
        /* -> bb4763 */
    }

    // ---- bb4763 @ 0x14003c6c8 ----
    if (t_14003c6c1 != 0xffffffff_u32) {
        /* -> bb3938 */
    } else {
        /* -> bb4764 */
    }

    // ---- bb4764 @ 0x14003c6ce ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c6d1 */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u128, xmm0);
    /* 14003c6d6 */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u64, 0xa_u64);
    /* 14003c6de */ core::ptr::write((rbp).wrapping_sub(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c6e6 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb4769 */ }
    if DF { /* -> bb4770 */ }

    // ---- bb4769 @ 0x14003c6e6 ----
    /* 14003c6e6 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 14003c6e6 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb4771 */

    // ---- bb4770 @ 0x14003c6e6 ----
    /* 14003c6e6 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 14003c6e6 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb4771 */

    // ---- bb4771 @ 0x14003c6ee ----
    /* 14003c6ee */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb4773 */ }
    if DF { /* -> bb4774 */ }

    // ---- bb4773 @ 0x14003c6ee ----
    /* 14003c6ee */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14003c6ee */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb4775 */

    // ---- bb4774 @ 0x14003c6ee ----
    /* 14003c6ee */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14003c6ee */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb4775 */

    // ---- bb4775 @ 0x14003c6f4 ----
    /* 14003c6f4 */ let mut t_14003c6f4: u16 = core::ptr::read((0x14003c6fb_u64).wrapping_add(0x2c83cd_u64) as *const u16);
    /* 14003c6f4 */ rax = ((t_14003c6f4 as u32) as u64);
    /* 14003c6fb */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u16, (rax as u16));
    /* 14003c6ff */ core::ptr::write((rbp).wrapping_sub(0x7e_u64) as *mut u8, 0x0_u8);
    /* 14003c703 */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003c708 */ fn_14006fd40();
    /* 14003c70d */ core::ptr::write((0x14003c713_u64).wrapping_add(0x3adaed_u64) as *mut u32, (rax as u32));
    /* 14003c713 */ rcx = (0x14003c71a_u64).wrapping_add(0x3adaea_u64);
    /* 14003c71a */ fn_1402c74dc();
    /* fallthrough -> bb3938 */

    // ---- bb4785 @ 0x14003c724 ----
    /* 14003c724 */ rcx = (0x14003c72b_u64).wrapping_add(0x3adad1_u64);
    /* 14003c72b */ fn_1402c7548();
    /* 14003c730 */ let mut t_14003c730: u32 = core::ptr::read((0x14003c737_u64).wrapping_add(0x3adac5_u64) as *const u32);
    if (t_14003c730 == 0xffffffff_u32) {
        /* -> bb4791 */
    } else {
        /* -> bb4790 */
    }

    // ---- bb4790 @ 0x14003c737 ----
    if (t_14003c730 != 0xffffffff_u32) {
        /* -> bb3977 */
    } else {
        /* -> bb4791 */
    }

    // ---- bb4791 @ 0x14003c73d ----
    // intrinsic: 0f57c000 xorps xmm0, xmm0
    /* 14003c740 */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u128, xmm0);
    /* 14003c745 */ core::ptr::write((rbp).wrapping_sub(0x78_u64) as *mut u64, 0x8_u64);
    /* 14003c74d */ core::ptr::write((rbp).wrapping_sub(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c755 */ rax = 0x6b636f4c746e6554_u64;
    /* 14003c75f */ core::ptr::write((rsp).wrapping_add(0x78_u64) as *mut u64, rax);
    /* 14003c764 */ core::ptr::write((rbp).wrapping_sub(0x80_u64) as *mut u8, 0x0_u8);
    /* 14003c768 */ rcx = (rsp).wrapping_add(0x78_u64);
    /* 14003c76d */ fn_14006fd40();
    /* 14003c772 */ core::ptr::write((0x14003c778_u64).wrapping_add(0x3ada80_u64) as *mut u32, (rax as u32));
    /* 14003c778 */ rcx = (0x14003c77f_u64).wrapping_add(0x3ada7d_u64);
    /* 14003c77f */ fn_1402c74dc();
    /* fallthrough -> bb3977 */

    // ---- bb4804 @ 0x14003c789 ----
    /* 14003c789 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r15);
    /* 14003c78e */ let mut t_14003c78e_0: u32 = 0x0_u32;
    /* 14003c78e */ r9 = (t_14003c78e_0 as u64);
    /* 14003c791 */ let mut t_14003c791_0: u32 = 0x0_u32;
    /* 14003c791 */ r8 = (t_14003c791_0 as u64);
    /* 14003c794 */ let mut t_14003c794_0: u32 = 0x0_u32;
    /* 14003c794 */ rdx = (t_14003c794_0 as u64);
    /* 14003c796 */ let mut t_14003c796_0: u32 = 0x0_u32;
    /* 14003c796 */ rcx = (t_14003c796_0 as u64);
    /* 14003c798 */ fn_1402cd884();
    // intrinsic: cc000000 int3 
    /* fallthrough -> bb4811 */

    // ---- bb4811 @ 0x14003c79e ----
    /* 14003c79e */ rcx = (0x14003c7a5_u64).wrapping_add(0x3ada67_u64);
    /* 14003c7a5 */ fn_1402c7548();
    /* 14003c7aa */ let mut t_14003c7aa: u32 = core::ptr::read((0x14003c7b1_u64).wrapping_add(0x3ada5b_u64) as *const u32);
    if (t_14003c7aa == 0xffffffff_u32) {
        /* -> bb4817 */
    } else {
        /* -> bb4816 */
    }

    // ---- bb4816 @ 0x14003c7b1 ----
    if (t_14003c7aa != 0xffffffff_u32) {
        /* -> bb4278 */
    } else {
        /* -> bb4817 */
    }

    // ---- bb4817 @ 0x14003c7b7 ----
    /* 14003c7b7 */ let mut t_14003c7b7_0: u32 = 0x0_u32;
    /* 14003c7b7 */ rcx = (t_14003c7b7_0 as u64);
    /* 14003c7b9 */ core::ptr::write((rsp).wrapping_add(0x60_u64) as *mut u64, rcx);
    /* 14003c7be */ core::ptr::write((rsp).wrapping_add(0x68_u64) as *mut u64, 0x7_u64);
    /* 14003c7c7 */ core::ptr::write((rsp).wrapping_add(0x70_u64) as *mut u64, 0xf_u64);
    /* 14003c7d0 */ rax = core::ptr::read((0x14003c7d7_u64).wrapping_add(0x2c82f9_u64) as *const u64);
    /* 14003c7d7 */ core::ptr::write((rsp).wrapping_add(0x58_u64) as *mut u32, (rax as u32));
    /* 14003c7db */ let mut t_14003c7db: u16 = core::ptr::read((0x14003c7e2_u64).wrapping_add(0x2c82f2_u64) as *const u16);
    /* 14003c7db */ rax = ((t_14003c7db as u32) as u64);
    /* 14003c7e2 */ core::ptr::write((rsp).wrapping_add(0x5c_u64) as *mut u16, (rax as u16));
    /* 14003c7e7 */ let mut t_14003c7e7: u8 = core::ptr::read((0x14003c7ee_u64).wrapping_add(0x2c82e8_u64) as *const u8);
    /* 14003c7e7 */ rax = ((t_14003c7e7 as u32) as u64);
    /* 14003c7ee */ core::ptr::write((rsp).wrapping_add(0x5e_u64) as *mut u8, (rax as u8));
    /* 14003c7f2 */ core::ptr::write((rsp).wrapping_add(0x5f_u64) as *mut u8, (rcx as u8));
    /* 14003c7f6 */ rcx = (rsp).wrapping_add(0x58_u64);
    /* 14003c7fb */ fn_14006fd40();
    /* 14003c800 */ core::ptr::write((0x14003c806_u64).wrapping_add(0x3ada02_u64) as *mut u32, (rax as u32));
    /* 14003c806 */ rcx = (0x14003c80d_u64).wrapping_add(0x3ad9ff_u64);
    /* 14003c80d */ fn_1402c74dc();
    /* fallthrough -> bb4278 */
}
