// Decompiled from Horsey.exe @ 0x1400a36e0
// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print
// blocks: 176

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]
pub unsafe fn genes_dat_handler() {

    // ---- bb0 @ 0x1400a36e0 ----
    /* 1400a36e0 */ let mut rbp: u64 = (rsp).wrapping_sub(0x27_u64);
    /* 1400a36e5 */ let mut rsp: u64 = (rsp).wrapping_sub(0xa0_u64);
    /* 1400a36ec */ core::ptr::write((rsp).wrapping_add(0x90_u64) as *mut u128, xmm6);
    /* 1400a36f4 */ let mut t_1400a36f4_0: u32 = 0x0_u32;
    /* 1400a36f4 */ let mut r12: u64 = (t_1400a36f4_0 as u64);
    /* 1400a36f7 */ core::ptr::write((rbp).wrapping_add(0x67_u64) as *mut u32, (r12 as u32));
    /* 1400a36fe */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm0);
    /* 1400a3702 */ core::ptr::write((rbp).wrapping_sub(0x29_u64) as *mut u64, 0xa_u64);
    /* 1400a370a */ let mut r13: u64 = (0xf_u32 as u64);
    /* 1400a3710 */ core::ptr::write((rbp).wrapping_sub(0x21_u64) as *mut u64, r13);
    /* 1400a3714 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb11 */ }
    if DF { /* -> bb12 */ }

    // ---- bb11 @ 0x1400a3714 ----
    /* 1400a3714 */ let mut rsi: u64 = (rsi).wrapping_add(0x8_u64);
    /* 1400a3714 */ let mut rdi: u64 = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb13 */

    // ---- bb12 @ 0x1400a3714 ----
    /* 1400a3714 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400a3714 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb13 */

    // ---- bb13 @ 0x1400a371c ----
    /* 1400a371c */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb15 */ }
    if DF { /* -> bb16 */ }

    // ---- bb15 @ 0x1400a371c ----
    /* 1400a371c */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400a371c */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb17 */

    // ---- bb16 @ 0x1400a371c ----
    /* 1400a371c */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400a371c */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb17 */

    // ---- bb17 @ 0x1400a3721 ----
    /* 1400a3721 */ let mut t_1400a3721: u16 = core::ptr::read((0x1400a3728_u64).wrapping_add(0x269600_u64) as *const u16);
    /* 1400a3721 */ let mut rax: u64 = ((t_1400a3721 as u32) as u64);
    /* 1400a3728 */ core::ptr::write((rbp).wrapping_sub(0x31_u64) as *mut u16, (rax as u16));
    /* 1400a372c */ core::ptr::write((rbp).wrapping_sub(0x2f_u64) as *mut u8, (r12 as u8));
    /* 1400a3730 */ let mut rdx: u64 = (rbp).wrapping_add(0x67_u64);
    /* 1400a3734 */ let mut rcx: u64 = (rbp).wrapping_sub(0x39_u64);
    /* 1400a3738 */ fn_1400c4b90();
    /* 1400a373d */ rsi = rax;
    if (ZF == false) { /* -> bb29 */ }
    if ZF { /* -> bb28 */ }

    // ---- bb28 @ 0x1400a3743 ----
    if (ZF == false) { /* -> bb29 */ }
    if ZF { /* -> bb392 */ }

    // ---- bb29 @ 0x1400a3749 ----
    /* 1400a3749 */ let mut r8: u64 = ((r12 as u32) as u64);
    /* 1400a374c */ let mut rbx: u64 = ((r12 as u32) as u64);
    /* 1400a374f */ let mut r15: u64 = ((r12 as u32) as u64);
    /* 1400a3752 */ let mut r14: u64 = ((r12 as u32) as u64);
    /* 1400a3755 */ let mut t_1400a3755: u32 = core::ptr::read((rbp).wrapping_add(0x67_u64) as *const u32);
    /* 1400a3755 */ rdx = (t_1400a3755 as u64);
    if (((SF != OF) | ZF) == false) { /* -> bb38 */ }
    if (((SF != OF) | ZF) != 0) { /* -> bb37 */ }

    // ---- bb37 @ 0x1400a375a ----
    if (((SF != OF) | ZF) == false) { /* -> bb38 */ }
    if (((SF != OF) | ZF) != 0) { /* -> bb131 */ }

    // ---- bb38 @ 0x1400a3760 ----
    /* 1400a3760 */ r12 = 0x800100000002000_u64;
    /* 1400a376a */ r13 = (0x1400a3771_u64).wrapping_add(0x34da2f_u64);
    /* fallthrough -> bb40 */

    // ---- bb40 @ 0x1400a3771 ----
    if (SF != OF) {
        /* -> bb44 */
    } else {
        /* -> bb43 */
    }

    // ---- bb43 @ 0x1400a3778 ----
    if (SF != OF) {
        /* -> bb44 */
    } else {
        /* -> bb130 */
    }

    // ---- bb44 @ 0x1400a377e ----
    if (SF != OF) {
        /* -> bb48 */
    } else {
        /* -> bb47 */
    }

    // ---- bb47 @ 0x1400a3780 ----
    if (SF != OF) {
        /* -> bb48 */
    } else {
        /* -> bb65 */
    }

    // ---- bb48 @ 0x1400a3782 ----
    /* 1400a3785 */ rcx = (rcx).wrapping_add(rsi);
    /* fallthrough -> bb50 */

    // ---- bb50 @ 0x1400a3788 ----
    /* 1400a3788 */ let mut t_1400a3788: u8 = core::ptr::read(rcx as *const u8);
    /* 1400a3788 */ rax = ((t_1400a3788 as i64) as u64);
    if (((CF == false) & ((rax as u8) != 0x3b_u8)) == false) { /* -> bb55 */ }
    if (((CF == false) & ((rax as u8) != 0x3b_u8)) != 0) { /* -> bb54 */ }

    // ---- bb54 @ 0x1400a378e ----
    if (((CF == false) & ((rax as u8) != 0x3b_u8)) == false) { /* -> bb55 */ }
    if (((CF == false) & ((rax as u8) != 0x3b_u8)) != 0) { /* -> bb59 */ }

    // ---- bb55 @ 0x1400a3790 ----
    /* 1400a3790 */ let mut t_1400a3790_0: u64 = (r12 >> rax);
    if (CF == false) { /* -> bb59 */ }
    if CF { /* -> bb58 */ }

    // ---- bb58 @ 0x1400a3794 ----
    if (CF == false) { /* -> bb59 */ }
    if CF { /* -> bb65 */ }

    // ---- bb59 @ 0x1400a3796 ----
    /* 1400a3796 */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400a3798 */ rcx = (rcx).wrapping_add(0x1_u64);
    if (SF == OF) {
        /* -> bb65 */
    } else {
        /* -> bb64 */
    }

    // ---- bb64 @ 0x1400a379d ----
    if (SF != OF) {
        /* -> bb50 */
    } else {
        /* -> bb65 */
    }

    // ---- bb65 @ 0x1400a379f ----
    /* 1400a37a2 */ let mut t_1400a37a2: u8 = core::ptr::read((rcx).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u8);
    /* 1400a37a2 */ let mut r9: u64 = ((t_1400a37a2 as u32) as u64);
    if ((r9 as u8) != 0x3b_u8) {
        /* -> bb71 */
    } else {
        /* -> bb70 */
    }

    // ---- bb70 @ 0x1400a37ab ----
    if ((r9 as u8) != 0x3b_u8) {
        /* -> bb71 */
    } else {
        /* -> bb130 */
    }

    // ---- bb71 @ 0x1400a37b1 ----
    if (((SF != OF) | ((rbx as u32) == (r8 as u32))) == false) { /* -> bb75 */ }
    if (((SF != OF) | ((rbx as u32) == (r8 as u32))) != 0) { /* -> bb74 */ }

    // ---- bb74 @ 0x1400a37b4 ----
    if (((SF != OF) | ((rbx as u32) == (r8 as u32))) == false) { /* -> bb75 */ }
    if (((SF != OF) | ((rbx as u32) == (r8 as u32))) != 0) { /* -> bb82 */ }

    // ---- bb75 @ 0x1400a37b6 ----
    /* 1400a37b6 */ rax = (((r8 as u32) as i64) as u64);
    /* 1400a37b9 */ let mut t_1400a37b9: u8 = core::ptr::read((rax).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u8);
    if (t_1400a37b9 == 0x47_u8) {
        /* -> bb80 */
    } else {
        /* -> bb79 */
    }

    // ---- bb79 @ 0x1400a37bd ----
    if (t_1400a37b9 == 0x47_u8) {
        /* -> bb80 */
    } else {
        /* -> bb82 */
    }

    // ---- bb80 @ 0x1400a37bf ----
    /* 1400a37c3 */ r14 = (r14).wrapping_add(rax);
    /* fallthrough -> bb82 */

    // ---- bb82 @ 0x1400a37c6 ----
    if ((r9 as u8) == 0x2c_u8) {
        /* -> bb86 */
    } else {
        /* -> bb85 */
    }

    // ---- bb85 @ 0x1400a37ca ----
    if ((r9 as u8) == 0x2c_u8) {
        /* -> bb86 */
    } else {
        /* -> bb103 */
    }

    // ---- bb86 @ 0x1400a37cc ----
    /* 1400a37cc */ core::ptr::write((rcx).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *mut u8, 0x0_u8);
    /* 1400a37d0 */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    if ((r9 as u8) != 0x2c_u8) {
        /* -> bb92 */
    } else {
        /* -> bb91 */
    }

    // ---- bb91 @ 0x1400a37d5 ----
    if ((r9 as u8) != 0x2c_u8) {
        /* -> bb92 */
    } else {
        /* -> bb102 */
    }

    // ---- bb92 @ 0x1400a37d7 ----
    /* 1400a37d7 */ rdi = (((r15 as u32) as i64) as u64);
    /* 1400a37da */ rdi = (rdi << (0x5_u8 as u64));
    /* 1400a37de */ rdi = (rdi).wrapping_add(r13);
    /* 1400a37e1 */ r15 = (((r15 as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400a37e4 */ rcx = r14;
    /* 1400a37e7 */ fn_1402f9d60();
    /* 1400a37ec */ r8 = rax;
    /* 1400a37ef */ rdx = r14;
    /* 1400a37f2 */ rcx = rdi;
    /* 1400a37f5 */ fn_140027f50();
    /* fallthrough -> bb102 */

    // ---- bb102 @ 0x1400a37fa ----
    /* 1400a37fa */ let mut t_1400a37fa: u32 = core::ptr::read((rbp).wrapping_add(0x67_u64) as *const u32);
    /* fallthrough -> bb103 */

    // ---- bb103 @ 0x1400a37fd ----
    if (SF != OF) {
        /* -> bb107 */
    } else {
        /* -> bb106 */
    }

    // ---- bb106 @ 0x1400a37ff ----
    if (SF != OF) {
        /* -> bb107 */
    } else {
        /* -> bb119 */
    }

    // ---- bb107 @ 0x1400a3801 ----
    /* 1400a3804 */ rcx = (rcx).wrapping_add(rsi);
    /* fallthrough -> bb109 */

    // ---- bb109 @ 0x1400a3807 ----
    /* 1400a3807 */ let mut t_1400a3807: u8 = core::ptr::read(rcx as *const u8);
    if (t_1400a3807 != 0xd_u8) {
        /* -> bb113 */
    } else {
        /* -> bb112 */
    }

    // ---- bb112 @ 0x1400a380a ----
    if (t_1400a3807 != 0xd_u8) {
        /* -> bb113 */
    } else {
        /* -> bb119 */
    }

    // ---- bb113 @ 0x1400a380c ----
    /* 1400a380c */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400a380e */ rcx = (rcx).wrapping_add(0x1_u64);
    if (SF == OF) {
        /* -> bb119 */
    } else {
        /* -> bb118 */
    }

    // ---- bb118 @ 0x1400a3813 ----
    if (SF != OF) {
        /* -> bb109 */
    } else {
        /* -> bb119 */
    }

    // ---- bb119 @ 0x1400a3815 ----
    /* 1400a3818 */ core::ptr::write((rax).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *mut u8, 0x0_u8);
    /* 1400a381c */ rax = (((rbx as u32) as i64) as u64);
    /* 1400a381f */ core::ptr::write(((rax).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x1_u64) as *mut u8, 0x0_u8);
    /* 1400a3824 */ r8 = (((rbx).wrapping_add(0x2_u64) as u32) as u64);
    /* 1400a3828 */ rbx = ((r8 as u32) as u64);
    /* 1400a382b */ let mut t_1400a382b: u32 = core::ptr::read((rbp).wrapping_add(0x67_u64) as *const u32);
    /* 1400a382b */ rdx = (t_1400a382b as u64);
    if (SF == OF) {
        /* -> bb130 */
    } else {
        /* -> bb129 */
    }

    // ---- bb129 @ 0x1400a3831 ----
    if (SF != OF) {
        /* -> bb40 */
    } else {
        /* -> bb130 */
    }

    // ---- bb130 @ 0x1400a3837 ----
    /* 1400a3837 */ r13 = (0xf_u32 as u64);
    /* fallthrough -> bb131 */

    // ---- bb131 @ 0x1400a383d ----
    /* 1400a383d */ rcx = rsi;
    /* 1400a3840 */ fn_1400c51e0();
    /* 1400a3845 */ let mut t_1400a3845_0: u32 = 0x0_u32;
    /* 1400a3845 */ rbx = (t_1400a3845_0 as u64);
    /* 1400a3847 */ rsi = ((rbx as u32) as u64);
    /* 1400a3849 */ r12 = 0x38e38e38e38e38e_u64;
    /* 1400a3853 */ rdi = (0x1400a385a_u64).wrapping_add(0x34f77e_u64);
    /* 1400a385a */ let mut xmm6: u128 = core::ptr::read((0x1400a3862_u64).wrapping_add(0x2f949e_u64) as *const u128);
    /* fallthrough -> bb140 */

    // ---- bb140 @ 0x1400a3870 ----
    /* 1400a3870 */ rdx = ((rsi as u32) as u64);
    /* 1400a3872 */ rdx = (rdx << (0x5_u8 as u64));
    /* 1400a3876 */ rax = (0x1400a387d_u64).wrapping_add(0x34d923_u64);
    /* 1400a387d */ let mut t_1400a387d_0: u64 = (rdx).wrapping_add(rax);
    /* 1400a387d */ rdx = t_1400a387d_0;
    /* 1400a3880 */ rcx = (rbp).wrapping_sub(0x19_u64);
    /* 1400a3884 */ fn_1400279c0();
    /* 1400a3889 */ core::ptr::write((rbp).wrapping_add(0x7_u64) as *mut u32, (rsi as u32));
    /* 1400a388c */ r15 = core::ptr::read((0x1400a3893_u64).wrapping_add(0x34f745_u64) as *const u64);
    /* 1400a3893 */ r14 = core::ptr::read((r15).wrapping_add(0x8_u64) as *const u64);
    /* 1400a3897 */ rdx = ((rbx as u32) as u64);
    /* 1400a3899 */ rbx = r15;
    /* 1400a389c */ let mut t_1400a389c: u8 = core::ptr::read((r14).wrapping_add(0x19_u64) as *const u8);
    if (t_1400a389c == 0x0_u8) {
        /* -> bb155 */
    } else {
        /* -> bb154 */
    }

    // ---- bb154 @ 0x1400a38a1 ----
    if (t_1400a389c == 0x0_u8) {
        /* -> bb155 */
    } else {
        /* -> bb179 */
    }

    // ---- bb155 @ 0x1400a38a3 ----
    /* 1400a38a3 */ rdi = r14;
    /* fallthrough -> bb157 */

    // ---- bb157 @ 0x1400a38b0 ----
    /* 1400a38b0 */ r14 = rdi;
    /* 1400a38b3 */ rcx = (rdi).wrapping_add(0x20_u64);
    /* 1400a38b7 */ rdx = (rbp).wrapping_sub(0x19_u64);
    /* 1400a38bb */ fn_140046cd0();
    /* 1400a38c0 */ rcx = (((rax as u8) as u32) as u64);
    /* 1400a38c3 */ rdx = ((rcx as u32) as u64);
    /* 1400a38c5 */ let mut t_1400a38c5_0: u32 = ((rdx as u32) ^ 0x1_u32);
    /* 1400a38c5 */ rdx = (t_1400a38c5_0 as u64);
    if (t_1400a38db != 0x0_u8) {
        /* -> bb166 */
    } else {
        /* -> bb167 */
    }

    // ---- bb167 @ 0x1400a38ca ----
    /* 1400a38ca */ rbx = rdi;
    /* fallthrough -> bb166 */

    // ---- bb166 @ 0x1400a38ce ----
    /* 1400a38ce */ rax = (rdi).wrapping_add(0x10_u64);
    if (t_1400a38db != 0x0_u8) {
        /* -> bb171 */
    } else {
        /* -> bb172 */
    }

    // ---- bb172 @ 0x1400a38d4 ----
    /* 1400a38d4 */ rax = rdi;
    /* fallthrough -> bb171 */

    // ---- bb171 @ 0x1400a38d8 ----
    /* 1400a38d8 */ rdi = core::ptr::read(rax as *const u64);
    /* 1400a38db */ let mut t_1400a38db: u8 = core::ptr::read((rdi).wrapping_add(0x19_u64) as *const u8);
    if (t_1400a38db != 0x0_u8) {
        /* -> bb178 */
    } else {
        /* -> bb177 */
    }

    // ---- bb177 @ 0x1400a38df ----
    if (t_1400a38db == 0x0_u8) {
        /* -> bb157 */
    } else {
        /* -> bb178 */
    }

    // ---- bb178 @ 0x1400a38e1 ----
    /* 1400a38e1 */ rdi = (0x1400a38e8_u64).wrapping_add(0x34f6f0_u64);
    /* fallthrough -> bb179 */

    // ---- bb179 @ 0x1400a38e8 ----
    /* 1400a38e8 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u64, r14);
    /* 1400a38ec */ core::ptr::write((rbp).wrapping_sub(0x31_u64) as *mut u32, (rdx as u32));
    /* 1400a38ef */ let mut t_1400a38ef: u32 = core::ptr::read((rbp).wrapping_sub(0x2d_u64) as *const u32);
    /* 1400a38ef */ rax = (t_1400a38ef as u64);
    /* 1400a38f2 */ core::ptr::write((rbp).wrapping_sub(0x2d_u64) as *mut u32, (rax as u32));
    /* 1400a38f5 */ let mut t_1400a38f5: u8 = core::ptr::read((rbx).wrapping_add(0x19_u64) as *const u8);
    if (t_1400a38f5 == 0x0_u8) {
        /* -> bb187 */
    } else {
        /* -> bb186 */
    }

    // ---- bb186 @ 0x1400a38f9 ----
    if (t_1400a38f5 == 0x0_u8) {
        /* -> bb187 */
    } else {
        /* -> bb194 */
    }

    // ---- bb187 @ 0x1400a38fb ----
    /* 1400a38fb */ rdx = (rbx).wrapping_add(0x20_u64);
    /* 1400a38ff */ rcx = (rbp).wrapping_sub(0x19_u64);
    /* 1400a3903 */ fn_140046cd0();
    if (t_1400a38f5 != 0x0_u8) {
        /* -> bb194 */
    } else {
        /* -> bb193 */
    }

    // ---- bb193 @ 0x1400a390a ----
    if (t_1400a38f5 != 0x0_u8) {
        /* -> bb194 */
    } else {
        /* -> bb223 */
    }

    // ---- bb194 @ 0x1400a390c ----
    /* 1400a390c */ let mut t_1400a390c: u64 = core::ptr::read((0x1400a3913_u64).wrapping_add(0x34f6cd_u64) as *const u64);
    if (t_1400a390c != r12) {
        /* -> bb198 */
    } else {
        /* -> bb197 */
    }

    // ---- bb197 @ 0x1400a3913 ----
    if (t_1400a390c != r12) {
        /* -> bb198 */
    } else {
        /* -> bb627 */
    }

    // ---- bb198 @ 0x1400a3919 ----
    /* 1400a3919 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u64, rdi);
    /* 1400a391d */ let mut t_1400a391d_0: u32 = 0x0_u32;
    /* 1400a391d */ rbx = (t_1400a391d_0 as u64);
    /* 1400a391f */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u64, rbx);
    /* 1400a3923 */ rcx = (0x48_u32 as u64);
    /* 1400a3928 */ fn_1402c745c();
    /* 1400a392e */ let mut t_1400a392e: u128 = core::ptr::read((rbp).wrapping_sub(0x19_u64) as *const u128);
    /* 1400a3932 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u128, xmm0);
    /* 1400a3936 */ let mut xmm1: u128 = core::ptr::read((rbp).wrapping_sub(0x9_u64) as *const u128);
    /* 1400a393a */ core::ptr::write((rax).wrapping_add(0x30_u64) as *mut u128, xmm1);
    /* 1400a393e */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u128, xmm6);
    /* 1400a3943 */ core::ptr::write((rbp).wrapping_sub(0x19_u64) as *mut u8, (rbx as u8));
    /* 1400a3946 */ core::ptr::write((rax).wrapping_add(0x40_u64) as *mut u32, (rsi as u32));
    /* 1400a3949 */ core::ptr::write(rax as *mut u64, r15);
    /* 1400a394c */ core::ptr::write((rax).wrapping_add(0x8_u64) as *mut u64, r15);
    /* 1400a3950 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u64, r15);
    /* 1400a3954 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u16, (rbx as u16));
    /* 1400a3958 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u64, rbx);
    /* 1400a395c */ let mut xmm0: u128 = core::ptr::read((rbp).wrapping_sub(0x39_u64) as *const u128);
    /* 1400a3960 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm0);
    /* 1400a3964 */ r8 = rax;
    /* 1400a3967 */ rdx = (rbp).wrapping_sub(0x39_u64);
    /* 1400a396b */ rcx = rdi;
    /* 1400a396e */ fn_140047580();
    /* fallthrough -> bb224 */

    // ---- bb223 @ 0x1400a3975 ----
    /* 1400a3975 */ let mut t_1400a3975_0: u32 = 0x0_u32;
    /* 1400a3975 */ rbx = (t_1400a3975_0 as u64);
    /* fallthrough -> bb224 */

    // ---- bb224 @ 0x1400a3977 ----
    /* 1400a3977 */ rcx = (rbp).wrapping_sub(0x19_u64);
    /* 1400a397b */ fn_140027900();
    /* 1400a3980 */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    if (SF == OF) {
        /* -> bb231 */
    } else {
        /* -> bb230 */
    }

    // ---- bb230 @ 0x1400a3988 ----
    if (SF != OF) {
        /* -> bb140 */
    } else {
        /* -> bb231 */
    }

    // ---- bb231 @ 0x1400a398e ----
    /* 1400a398e */ rcx = (0xffffffff_u32 as u64);
    /* 1400a3993 */ fn_140075540();
    /* 1400a3998 */ rcx = (0xf0_u32 as u64);
    /* 1400a399d */ fn_140075610();
    /* 1400a39a2 */ r12 = ((rbx as u32) as u64);
    /* 1400a39a5 */ rcx = (0x1400a39ac_u64).wrapping_add(0x34d7f4_u64);
    /* 1400a39ac */ r14 = rcx;
    /* 1400a39af */ rax = (0x16_u32 as u64);
    /* 1400a39b4 */ r15 = 0x7fffffffffffffff_u64;
    /* fallthrough -> bb241 */

    // ---- bb241 @ 0x1400a39c0 ----
    /* 1400a39c3 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm0);
    /* 1400a39c7 */ core::ptr::write((rbp).wrapping_sub(0x29_u64) as *mut u64, rbx);
    /* 1400a39cb */ core::ptr::write((rbp).wrapping_sub(0x21_u64) as *mut u64, rbx);
    /* 1400a39cf */ rdi = ((r12 as u32) as u64);
    /* 1400a39d2 */ rdi = (rdi << (0x5_u8 as u64));
    /* 1400a39d6 */ rdi = (rdi).wrapping_add(rcx);
    /* 1400a39d9 */ let mut t_1400a39d9: u64 = core::ptr::read((r14).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_1400a39d9 == 0xf_u64)) == false) { /* -> bb252 */ }
    if ((CF | (t_1400a39d9 == 0xf_u64)) != 0) { /* -> bb251 */ }

    // ---- bb251 @ 0x1400a39de ----
    if ((CF | (t_1400a39d9 == 0xf_u64)) == false) { /* -> bb252 */ }
    if ((CF | (t_1400a39d9 == 0xf_u64)) != 0) { /* -> bb253 */ }

    // ---- bb252 @ 0x1400a39e0 ----
    /* 1400a39e0 */ rdi = core::ptr::read(r14 as *const u64);
    /* fallthrough -> bb253 */

    // ---- bb253 @ 0x1400a39e3 ----
    /* 1400a39e3 */ rsi = core::ptr::read((r14).wrapping_add(0x10_u64) as *const u64);
    if (((CF == false) & (rsi != r15)) == false) { /* -> bb258 */ }
    if (((CF == false) & (rsi != r15)) != 0) { /* -> bb257 */ }

    // ---- bb257 @ 0x1400a39ea ----
    if (((CF == false) & (rsi != r15)) == false) { /* -> bb258 */ }
    if (((CF == false) & (rsi != r15)) != 0) { /* -> bb625 */ }

    // ---- bb258 @ 0x1400a39f0 ----
    if (((CF == false) & (rsi != 0xf_u64)) == false) { /* -> bb262 */ }
    if (((CF == false) & (rsi != 0xf_u64)) != 0) { /* -> bb261 */ }

    // ---- bb261 @ 0x1400a39f4 ----
    if (((CF == false) & (rsi != 0xf_u64)) == false) { /* -> bb262 */ }
    if (((CF == false) & (rsi != 0xf_u64)) != 0) { /* -> bb267 */ }

    // ---- bb262 @ 0x1400a39f6 ----
    /* 1400a39f6 */ core::ptr::write((rbp).wrapping_sub(0x29_u64) as *mut u64, rsi);
    /* 1400a39fa */ core::ptr::write((rbp).wrapping_sub(0x21_u64) as *mut u64, r13);
    /* 1400a39fe */ xmm0 = core::ptr::read(rdi as *const u128);
    /* 1400a3a01 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm0);
    /* fallthrough -> bb289 */

    // ---- bb267 @ 0x1400a3a07 ----
    /* 1400a3a07 */ rbx = rsi;
    /* 1400a3a0a */ rbx = (rbx | 0xf_u64);
    if ((CF | (rbx == r15)) == false) { /* -> bb273 */ }
    if ((CF | (rbx == r15)) != 0) { /* -> bb272 */ }

    // ---- bb272 @ 0x1400a3a11 ----
    if ((CF | (rbx == r15)) == false) { /* -> bb273 */ }
    if ((CF | (rbx == r15)) != 0) { /* -> bb275 */ }

    // ---- bb273 @ 0x1400a3a13 ----
    /* 1400a3a13 */ rbx = r15;
    /* fallthrough -> bb279 */

    // ---- bb275 @ 0x1400a3a18 ----
    if (CF == false) { /* -> bb279 */ }
    if CF { /* -> bb278 */ }

    // ---- bb278 @ 0x1400a3a1c ----
    /* 1400a3a1c */ rbx = rax;
    /* fallthrough -> bb279 */

    // ---- bb279 @ 0x1400a3a20 ----
    /* 1400a3a20 */ rcx = (rbx).wrapping_add(0x1_u64);
    /* 1400a3a24 */ fn_1400285e0();
    /* 1400a3a29 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u64, rax);
    /* 1400a3a2d */ core::ptr::write((rbp).wrapping_sub(0x29_u64) as *mut u64, rsi);
    /* 1400a3a31 */ core::ptr::write((rbp).wrapping_sub(0x21_u64) as *mut u64, rbx);
    /* 1400a3a35 */ r8 = (rsi).wrapping_add(0x1_u64);
    /* 1400a3a39 */ rdx = rdi;
    /* 1400a3a3c */ rcx = rax;
    /* 1400a3a3f */ fn_1402f9230();
    /* 1400a3a44 */ let mut t_1400a3a44_0: u32 = 0x0_u32;
    /* 1400a3a44 */ rbx = (t_1400a3a44_0 as u64);
    /* fallthrough -> bb289 */

    // ---- bb289 @ 0x1400a3a46 ----
    /* 1400a3a46 */ rcx = (rbp).wrapping_sub(0x39_u64);
    /* 1400a3a4a */ fn_1400757f0();
    /* 1400a3a4f */ r12 = (((r12 as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400a3a52 */ r14 = (r14).wrapping_add(0x20_u64);
    /* 1400a3a5d */ rax = (0x16_u32 as u64);
    /* 1400a3a62 */ rcx = (0x1400a3a69_u64).wrapping_add(0x34d737_u64);
    if (SF == OF) {
        /* -> bb299 */
    } else {
        /* -> bb298 */
    }

    // ---- bb298 @ 0x1400a3a69 ----
    if (SF != OF) {
        /* -> bb241 */
    } else {
        /* -> bb299 */
    }

    // ---- bb299 @ 0x1400a3a6f ----
    /* 1400a3a6f */ fn_1400c5200();
    /* 1400a3a74 */ rbx = rax;
    /* 1400a3a77 */ rsi = core::ptr::read((rax).wrapping_add(0x10_u64) as *const u64);
    /* 1400a3a7e */ rax = (rax).wrapping_sub(rsi);
    if (CF == false) { /* -> bb308 */ }
    if CF { /* -> bb307 */ }

    // ---- bb307 @ 0x1400a3a85 ----
    if (CF == false) { /* -> bb308 */ }
    if CF { /* -> bb616 */ }

    // ---- bb308 @ 0x1400a3a8b ----
    /* 1400a3a8b */ let mut t_1400a3a8b: u64 = core::ptr::read((rbx).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_1400a3a8b == 0xf_u64)) == false) { /* -> bb312 */ }
    if ((CF | (t_1400a3a8b == 0xf_u64)) != 0) { /* -> bb311 */ }

    // ---- bb311 @ 0x1400a3a90 ----
    if ((CF | (t_1400a3a8b == 0xf_u64)) == false) { /* -> bb312 */ }
    if ((CF | (t_1400a3a8b == 0xf_u64)) != 0) { /* -> bb313 */ }

    // ---- bb312 @ 0x1400a3a92 ----
    /* 1400a3a92 */ rbx = core::ptr::read(rbx as *const u64);
    /* fallthrough -> bb313 */

    // ---- bb313 @ 0x1400a3a95 ----
    /* 1400a3a98 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm0);
    /* 1400a3a9f */ core::ptr::write((rbp).wrapping_sub(0x29_u64) as *mut u128, xmm1);
    /* 1400a3aa4 */ r14 = (rsi).wrapping_add(0x9_u64);
    /* 1400a3aa8 */ rdi = (rbp).wrapping_sub(0x39_u64);
    if ((CF | (r14 == 0xf_u64)) == false) { /* -> bb323 */ }
    if ((CF | (r14 == 0xf_u64)) != 0) { /* -> bb322 */ }

    // ---- bb322 @ 0x1400a3ab0 ----
    if ((CF | (r14 == 0xf_u64)) == false) { /* -> bb323 */ }
    if ((CF | (r14 == 0xf_u64)) != 0) { /* -> bb340 */ }

    // ---- bb323 @ 0x1400a3ab2 ----
    /* 1400a3ab2 */ r13 = r14;
    /* 1400a3ab5 */ r13 = (r13 | 0xf_u64);
    if ((CF | (r13 == r15)) == false) { /* -> bb329 */ }
    if ((CF | (r13 == r15)) != 0) { /* -> bb328 */ }

    // ---- bb328 @ 0x1400a3abc ----
    if ((CF | (r13 == r15)) == false) { /* -> bb329 */ }
    if ((CF | (r13 == r15)) != 0) { /* -> bb331 */ }

    // ---- bb329 @ 0x1400a3abe ----
    /* 1400a3abe */ r13 = r15;
    /* fallthrough -> bb336 */

    // ---- bb331 @ 0x1400a3ac3 ----
    /* 1400a3ac7 */ rax = (0x16_u32 as u64);
    if (CF == false) { /* -> bb336 */ }
    if CF { /* -> bb335 */ }

    // ---- bb335 @ 0x1400a3acc ----
    /* 1400a3acc */ r13 = rax;
    /* fallthrough -> bb336 */

    // ---- bb336 @ 0x1400a3ad0 ----
    /* 1400a3ad0 */ rcx = (r13).wrapping_add(0x1_u64);
    /* 1400a3ad4 */ fn_1400285e0();
    /* 1400a3ad9 */ rdi = rax;
    /* 1400a3adc */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u64, rax);
    /* fallthrough -> bb340 */

    // ---- bb340 @ 0x1400a3ae0 ----
    /* 1400a3ae0 */ core::ptr::write((rbp).wrapping_sub(0x29_u64) as *mut u64, r14);
    /* 1400a3ae4 */ core::ptr::write((rbp).wrapping_sub(0x21_u64) as *mut u64, r13);
    /* 1400a3ae8 */ r8 = rsi;
    /* 1400a3aeb */ rdx = rbx;
    /* 1400a3aee */ rcx = rdi;
    /* 1400a3af1 */ fn_1402f9230();
    /* 1400a3af6 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb347 */ }
    if DF { /* -> bb348 */ }

    // ---- bb347 @ 0x1400a3af6 ----
    /* 1400a3af6 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400a3af6 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb349 */

    // ---- bb348 @ 0x1400a3af6 ----
    /* 1400a3af6 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400a3af6 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb349 */

    // ---- bb349 @ 0x1400a3afe ----
    /* 1400a3afe */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb351 */ }
    if DF { /* -> bb352 */ }

    // ---- bb351 @ 0x1400a3afe ----
    /* 1400a3afe */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400a3afe */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb353 */

    // ---- bb352 @ 0x1400a3afe ----
    /* 1400a3afe */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400a3afe */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb353 */

    // ---- bb353 @ 0x1400a3b03 ----
    /* 1400a3b03 */ let mut t_1400a3b03: u8 = core::ptr::read((0x1400a3b0a_u64).wrapping_add(0x26922e_u64) as *const u8);
    /* 1400a3b03 */ rax = ((t_1400a3b03 as u32) as u64);
    /* 1400a3b0a */ core::ptr::write(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *mut u8, (rax as u8));
    /* 1400a3b0e */ core::ptr::write((rdi).wrapping_add((r14).wrapping_mul(0x1_u64)) as *mut u8, 0x0_u8);
    /* 1400a3b13 */ rcx = (rbp).wrapping_sub(0x39_u64);
    /* 1400a3b17 */ fn_140075590();
    /* 1400a3b1d */ rdx = core::ptr::read((rbp).wrapping_sub(0x21_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb365 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb364 */ }

    // ---- bb364 @ 0x1400a3b25 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb365 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb381 */ }

    // ---- bb365 @ 0x1400a3b27 ----
    /* 1400a3b27 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400a3b2a */ rcx = core::ptr::read((rbp).wrapping_sub(0x39_u64) as *const u64);
    /* 1400a3b2e */ rax = rcx;
    if (CF == false) { /* -> bb372 */ }
    if CF { /* -> bb371 */ }

    // ---- bb371 @ 0x1400a3b38 ----
    if (CF == false) { /* -> bb372 */ }
    if CF { /* -> bb380 */ }

    // ---- bb372 @ 0x1400a3b3a ----
    /* 1400a3b3a */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 1400a3b3e */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400a3b42 */ rax = (rax).wrapping_sub(rcx);
    /* 1400a3b45 */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb380 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb379 */ }

    // ---- bb379 @ 0x1400a3b4d ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb380 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb618 */ }

    // ---- bb380 @ 0x1400a3b53 ----
    /* 1400a3b53 */ fn_1402c7498();
    /* fallthrough -> bb381 */

    // ---- bb381 @ 0x1400a3b58 ----
    /* 1400a3b58 */ rbx = core::ptr::read((rsp).wrapping_add(0xf0_u64) as *const u64);
    /* 1400a3b60 */ xmm6 = core::ptr::read((rsp).wrapping_add(0x90_u64) as *const u128);
    /* 1400a3b68 */ let mut t_1400a3b68_0: u64 = (rsp).wrapping_add(0xa0_u64);
    /* 1400a3b68 */ rsp = t_1400a3b68_0;
    /* 1400a3b6f */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400a3b6f */ r15 = core::ptr::read(rsp as *const u64);
    /* 1400a3b71 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400a3b71 */ r14 = core::ptr::read(rsp as *const u64);
    /* 1400a3b73 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400a3b73 */ r13 = core::ptr::read(rsp as *const u64);
    /* 1400a3b75 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400a3b75 */ r12 = core::ptr::read(rsp as *const u64);
    /* 1400a3b77 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400a3b77 */ rdi = core::ptr::read(rsp as *const u64);
    /* 1400a3b78 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400a3b78 */ rsi = core::ptr::read(rsp as *const u64);
    /* 1400a3b79 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400a3b79 */ rbp = core::ptr::read(rsp as *const u64);
    /* 1400a3b7a */ return;
    // <no successors>

    // ---- bb392 @ 0x1400a3b7b ----
    /* 1400a3b7b */ fn_1400c5200();
    /* 1400a3b80 */ rbx = rax;
    /* 1400a3b83 */ rsi = core::ptr::read((rax).wrapping_add(0x10_u64) as *const u64);
    /* 1400a3b87 */ r15 = 0x7fffffffffffffff_u64;
    /* 1400a3b94 */ rax = (rax).wrapping_sub(rsi);
    if (CF == false) { /* -> bb402 */ }
    if CF { /* -> bb401 */ }

    // ---- bb401 @ 0x1400a3b9b ----
    if (CF == false) { /* -> bb402 */ }
    if CF { /* -> bb629 */ }

    // ---- bb402 @ 0x1400a3ba1 ----
    /* 1400a3ba1 */ let mut t_1400a3ba1: u64 = core::ptr::read((rbx).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_1400a3ba1 == r13)) == false) { /* -> bb406 */ }
    if ((CF | (t_1400a3ba1 == r13)) != 0) { /* -> bb405 */ }

    // ---- bb405 @ 0x1400a3ba5 ----
    if ((CF | (t_1400a3ba1 == r13)) == false) { /* -> bb406 */ }
    if ((CF | (t_1400a3ba1 == r13)) != 0) { /* -> bb407 */ }

    // ---- bb406 @ 0x1400a3ba7 ----
    /* 1400a3ba7 */ rbx = core::ptr::read(rbx as *const u64);
    /* fallthrough -> bb407 */

    // ---- bb407 @ 0x1400a3baa ----
    /* 1400a3bad */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm0);
    /* 1400a3bb4 */ core::ptr::write((rbp).wrapping_sub(0x29_u64) as *mut u128, xmm1);
    /* 1400a3bb9 */ r14 = (rsi).wrapping_add(0x9_u64);
    /* 1400a3bbd */ rdi = (rbp).wrapping_sub(0x39_u64);
    if ((CF | (r14 == r13)) == false) { /* -> bb417 */ }
    if ((CF | (r14 == r13)) != 0) { /* -> bb416 */ }

    // ---- bb416 @ 0x1400a3bc4 ----
    if ((CF | (r14 == r13)) == false) { /* -> bb417 */ }
    if ((CF | (r14 == r13)) != 0) { /* -> bb434 */ }

    // ---- bb417 @ 0x1400a3bc6 ----
    /* 1400a3bc6 */ r13 = r14;
    /* 1400a3bc9 */ r13 = (r13 | 0xf_u64);
    if ((CF | (r13 == r15)) == false) { /* -> bb423 */ }
    if ((CF | (r13 == r15)) != 0) { /* -> bb422 */ }

    // ---- bb422 @ 0x1400a3bd0 ----
    if ((CF | (r13 == r15)) == false) { /* -> bb423 */ }
    if ((CF | (r13 == r15)) != 0) { /* -> bb425 */ }

    // ---- bb423 @ 0x1400a3bd2 ----
    /* 1400a3bd2 */ r13 = r15;
    /* fallthrough -> bb430 */

    // ---- bb425 @ 0x1400a3bd7 ----
    /* 1400a3bd7 */ rax = (0x16_u32 as u64);
    if (CF == false) { /* -> bb430 */ }
    if CF { /* -> bb429 */ }

    // ---- bb429 @ 0x1400a3bdf ----
    /* 1400a3bdf */ r13 = rax;
    /* fallthrough -> bb430 */

    // ---- bb430 @ 0x1400a3be3 ----
    /* 1400a3be3 */ rcx = (r13).wrapping_add(0x1_u64);
    /* 1400a3be7 */ fn_1400285e0();
    /* 1400a3bec */ rdi = rax;
    /* 1400a3bef */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u64, rax);
    /* fallthrough -> bb434 */

    // ---- bb434 @ 0x1400a3bf3 ----
    /* 1400a3bf3 */ core::ptr::write((rbp).wrapping_sub(0x29_u64) as *mut u64, r14);
    /* 1400a3bf7 */ core::ptr::write((rbp).wrapping_sub(0x21_u64) as *mut u64, r13);
    /* 1400a3bfb */ r8 = rsi;
    /* 1400a3bfe */ rdx = rbx;
    /* 1400a3c01 */ rcx = rdi;
    /* 1400a3c04 */ fn_1402f9230();
    /* 1400a3c09 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb441 */ }
    if DF { /* -> bb442 */ }

    // ---- bb441 @ 0x1400a3c09 ----
    /* 1400a3c09 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 1400a3c09 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb443 */

    // ---- bb442 @ 0x1400a3c09 ----
    /* 1400a3c09 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 1400a3c09 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb443 */

    // ---- bb443 @ 0x1400a3c11 ----
    /* 1400a3c11 */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb445 */ }
    if DF { /* -> bb446 */ }

    // ---- bb445 @ 0x1400a3c11 ----
    /* 1400a3c11 */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 1400a3c11 */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb447 */

    // ---- bb446 @ 0x1400a3c11 ----
    /* 1400a3c11 */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 1400a3c11 */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb447 */

    // ---- bb447 @ 0x1400a3c16 ----
    /* 1400a3c16 */ let mut t_1400a3c16: u8 = core::ptr::read((0x1400a3c1d_u64).wrapping_add(0x26911b_u64) as *const u8);
    /* 1400a3c16 */ rax = ((t_1400a3c16 as u32) as u64);
    /* 1400a3c1d */ core::ptr::write(((rdi).wrapping_add((rsi).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *mut u8, (rax as u8));
    /* 1400a3c21 */ core::ptr::write((rdi).wrapping_add((r14).wrapping_mul(0x1_u64)) as *mut u8, (r12 as u8));
    /* 1400a3c25 */ rdx = (rbp).wrapping_sub(0x39_u64);
    /* 1400a3c29 */ let mut t_1400a3c29_0: u32 = 0x0_u32;
    /* 1400a3c29 */ rcx = (t_1400a3c29_0 as u64);
    /* 1400a3c2b */ fn_140075390();
    /* 1400a3c30 */ rbx = (((rax as u8) as u32) as u64);
    /* 1400a3c33 */ rdx = core::ptr::read((rbp).wrapping_sub(0x21_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb460 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb459 */ }

    // ---- bb459 @ 0x1400a3c3b ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb460 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb477 */ }

    // ---- bb460 @ 0x1400a3c3d ----
    /* 1400a3c3d */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400a3c40 */ r8 = core::ptr::read((rbp).wrapping_sub(0x39_u64) as *const u64);
    if (CF == false) { /* -> bb467 */ }
    if CF { /* -> bb466 */ }

    // ---- bb466 @ 0x1400a3c4e ----
    if (CF == false) { /* -> bb467 */ }
    if CF { /* -> bb475 */ }

    // ---- bb467 @ 0x1400a3c50 ----
    /* 1400a3c50 */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 1400a3c54 */ r8 = core::ptr::read((r8).wrapping_sub(0x8_u64) as *const u64);
    /* 1400a3c58 */ rcx = (rcx).wrapping_sub(r8);
    /* 1400a3c5b */ rcx = (rcx).wrapping_sub(0x8_u64);
    if (((CF == false) & (rcx != 0x1f_u64)) == false) { /* -> bb475 */ }
    if (((CF == false) & (rcx != 0x1f_u64)) != 0) { /* -> bb474 */ }

    // ---- bb474 @ 0x1400a3c63 ----
    if (((CF == false) & (rcx != 0x1f_u64)) == false) { /* -> bb475 */ }
    if (((CF == false) & (rcx != 0x1f_u64)) != 0) { /* -> bb631 */ }

    // ---- bb475 @ 0x1400a3c69 ----
    /* 1400a3c69 */ rcx = r8;
    /* 1400a3c6c */ fn_1402c7498();
    /* fallthrough -> bb477 */

    // ---- bb477 @ 0x1400a3c71 ----
    if (rdx != 0xf_u64) {
        /* -> bb481 */
    } else {
        /* -> bb480 */
    }

    // ---- bb480 @ 0x1400a3c73 ----
    if (rdx == 0xf_u64) {
        /* -> bb381 */
    } else {
        /* -> bb481 */
    }

    // ---- bb481 @ 0x1400a3c79 ----
    /* 1400a3c79 */ fn_140075d40();
    /* 1400a3c7e */ r12 = ((rax as u32) as u64);
    /* 1400a3c81 */ let mut t_1400a3c81_0: u32 = 0x0_u32;
    /* 1400a3c81 */ rsi = (t_1400a3c81_0 as u64);
    if (((SF != OF) | (rdx == 0xf_u64)) == false) { /* -> bb488 */ }
    if (((SF != OF) | (rdx == 0xf_u64)) != 0) { /* -> bb487 */ }

    // ---- bb487 @ 0x1400a3c85 ----
    if (((SF != OF) | (rdx == 0xf_u64)) != 0) { /* -> bb381 */ }
    if (((SF != OF) | (rdx == 0xf_u64)) == false) { /* -> bb488 */ }

    // ---- bb488 @ 0x1400a3c8b ----
    /* 1400a3c8b */ rdi = 0x38e38e38e38e38e_u64;
    /* 1400a3c95 */ r13 = (0x1400a3c9c_u64).wrapping_add(0x34f33c_u64);
    /* 1400a3c9c */ xmm6 = core::ptr::read((0x1400a3ca4_u64).wrapping_add(0x2f905c_u64) as *const u128);
    /* fallthrough -> bb491 */

    // ---- bb491 @ 0x1400a3ca4 ----
    /* 1400a3ca4 */ rax = (0x1400a3cab_u64).wrapping_add(0x34d4f5_u64);
    /* 1400a3cab */ rbx = (((rsi as u32) as i64) as u64);
    /* 1400a3cae */ rbx = (rbx << (0x5_u8 as u64));
    /* 1400a3cb2 */ let mut t_1400a3cb2_0: u64 = (rbx).wrapping_add(rax);
    /* 1400a3cb2 */ rbx = t_1400a3cb2_0;
    /* 1400a3cb5 */ rdx = rbx;
    /* 1400a3cb8 */ rcx = (rbp).wrapping_sub(0x39_u64);
    /* 1400a3cbc */ fn_140076090();
    /* 1400a3cc1 */ rdx = core::ptr::read((rbp).wrapping_sub(0x21_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb503 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb502 */ }

    // ---- bb502 @ 0x1400a3cc9 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb503 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb519 */ }

    // ---- bb503 @ 0x1400a3ccb ----
    /* 1400a3ccb */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400a3cce */ rcx = core::ptr::read((rbp).wrapping_sub(0x39_u64) as *const u64);
    /* 1400a3cd2 */ rax = rcx;
    if (CF == false) { /* -> bb510 */ }
    if CF { /* -> bb509 */ }

    // ---- bb509 @ 0x1400a3cdc ----
    if (CF == false) { /* -> bb510 */ }
    if CF { /* -> bb518 */ }

    // ---- bb510 @ 0x1400a3cde ----
    /* 1400a3cde */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 1400a3ce2 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400a3ce6 */ rax = (rax).wrapping_sub(rcx);
    /* 1400a3ce9 */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb518 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb517 */ }

    // ---- bb517 @ 0x1400a3cf1 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb518 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb607 */ }

    // ---- bb518 @ 0x1400a3cf7 ----
    /* 1400a3cf7 */ fn_1402c7498();
    /* fallthrough -> bb519 */

    // ---- bb519 @ 0x1400a3cfc ----
    /* 1400a3cfc */ rdx = rbx;
    /* 1400a3cff */ rcx = (rbp).wrapping_sub(0x19_u64);
    /* 1400a3d03 */ fn_1400279c0();
    /* 1400a3d08 */ core::ptr::write((rbp).wrapping_add(0x7_u64) as *mut u32, (rsi as u32));
    /* 1400a3d0b */ r15 = core::ptr::read((0x1400a3d12_u64).wrapping_add(0x34f2c6_u64) as *const u64);
    /* 1400a3d12 */ r14 = core::ptr::read((r15).wrapping_add(0x8_u64) as *const u64);
    /* 1400a3d16 */ let mut t_1400a3d16_0: u32 = 0x0_u32;
    /* 1400a3d16 */ rdx = (t_1400a3d16_0 as u64);
    /* 1400a3d18 */ rbx = r15;
    /* 1400a3d1b */ let mut t_1400a3d1b: u8 = core::ptr::read((r14).wrapping_add(0x19_u64) as *const u8);
    if (t_1400a3d1b == (rdx as u8)) {
        /* -> bb531 */
    } else {
        /* -> bb530 */
    }

    // ---- bb530 @ 0x1400a3d1f ----
    if (t_1400a3d1b == (rdx as u8)) {
        /* -> bb531 */
    } else {
        /* -> bb556 */
    }

    // ---- bb531 @ 0x1400a3d21 ----
    /* 1400a3d21 */ rdi = r14;
    /* fallthrough -> bb534 */

    // ---- bb534 @ 0x1400a3d30 ----
    /* 1400a3d30 */ r14 = rdi;
    /* 1400a3d33 */ rcx = (rdi).wrapping_add(0x20_u64);
    /* 1400a3d37 */ rdx = (rbp).wrapping_sub(0x19_u64);
    /* 1400a3d3b */ fn_140046cd0();
    /* 1400a3d40 */ rcx = (((rax as u8) as u32) as u64);
    /* 1400a3d43 */ rdx = ((rcx as u32) as u64);
    /* 1400a3d45 */ let mut t_1400a3d45_0: u32 = ((rdx as u32) ^ 0x1_u32);
    /* 1400a3d45 */ rdx = (t_1400a3d45_0 as u64);
    if (t_1400a3d5b != 0x0_u8) {
        /* -> bb543 */
    } else {
        /* -> bb544 */
    }

    // ---- bb544 @ 0x1400a3d4a ----
    /* 1400a3d4a */ rbx = rdi;
    /* fallthrough -> bb543 */

    // ---- bb543 @ 0x1400a3d4e ----
    /* 1400a3d4e */ rax = (rdi).wrapping_add(0x10_u64);
    if (t_1400a3d5b != 0x0_u8) {
        /* -> bb548 */
    } else {
        /* -> bb549 */
    }

    // ---- bb549 @ 0x1400a3d54 ----
    /* 1400a3d54 */ rax = rdi;
    /* fallthrough -> bb548 */

    // ---- bb548 @ 0x1400a3d58 ----
    /* 1400a3d58 */ rdi = core::ptr::read(rax as *const u64);
    /* 1400a3d5b */ let mut t_1400a3d5b: u8 = core::ptr::read((rdi).wrapping_add(0x19_u64) as *const u8);
    if (t_1400a3d5b != 0x0_u8) {
        /* -> bb555 */
    } else {
        /* -> bb554 */
    }

    // ---- bb554 @ 0x1400a3d5f ----
    if (t_1400a3d5b == 0x0_u8) {
        /* -> bb534 */
    } else {
        /* -> bb555 */
    }

    // ---- bb555 @ 0x1400a3d61 ----
    /* 1400a3d61 */ rdi = 0x38e38e38e38e38e_u64;
    /* fallthrough -> bb556 */

    // ---- bb556 @ 0x1400a3d6b ----
    /* 1400a3d6b */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u64, r14);
    /* 1400a3d6f */ core::ptr::write((rbp).wrapping_sub(0x31_u64) as *mut u32, (rdx as u32));
    /* 1400a3d72 */ let mut t_1400a3d72: u32 = core::ptr::read((rbp).wrapping_sub(0x2d_u64) as *const u32);
    /* 1400a3d72 */ rax = (t_1400a3d72 as u64);
    /* 1400a3d75 */ core::ptr::write((rbp).wrapping_sub(0x2d_u64) as *mut u32, (rax as u32));
    /* 1400a3d78 */ let mut t_1400a3d78: u8 = core::ptr::read((rbx).wrapping_add(0x19_u64) as *const u8);
    if (t_1400a3d78 == 0x0_u8) {
        /* -> bb564 */
    } else {
        /* -> bb563 */
    }

    // ---- bb563 @ 0x1400a3d7c ----
    if (t_1400a3d78 == 0x0_u8) {
        /* -> bb564 */
    } else {
        /* -> bb571 */
    }

    // ---- bb564 @ 0x1400a3d7e ----
    /* 1400a3d7e */ rdx = (rbx).wrapping_add(0x20_u64);
    /* 1400a3d82 */ rcx = (rbp).wrapping_sub(0x19_u64);
    /* 1400a3d86 */ fn_140046cd0();
    if (t_1400a3d78 != 0x0_u8) {
        /* -> bb571 */
    } else {
        /* -> bb570 */
    }

    // ---- bb570 @ 0x1400a3d8d ----
    if (t_1400a3d78 != 0x0_u8) {
        /* -> bb571 */
    } else {
        /* -> bb599 */
    }

    // ---- bb571 @ 0x1400a3d8f ----
    /* 1400a3d8f */ let mut t_1400a3d8f: u64 = core::ptr::read((0x1400a3d96_u64).wrapping_add(0x34f24a_u64) as *const u64);
    if (t_1400a3d8f != rdi) {
        /* -> bb575 */
    } else {
        /* -> bb574 */
    }

    // ---- bb574 @ 0x1400a3d96 ----
    if (t_1400a3d8f != rdi) {
        /* -> bb575 */
    } else {
        /* -> bb614 */
    }

    // ---- bb575 @ 0x1400a3d9c ----
    /* 1400a3d9c */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u64, r13);
    /* 1400a3da0 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u64, 0x0_u64);
    /* 1400a3da8 */ rcx = (0x48_u32 as u64);
    /* 1400a3dad */ fn_1402c745c();
    /* 1400a3db3 */ let mut t_1400a3db3: u128 = core::ptr::read((rbp).wrapping_sub(0x19_u64) as *const u128);
    /* 1400a3db7 */ core::ptr::write((rax).wrapping_add(0x20_u64) as *mut u128, xmm0);
    /* 1400a3dbb */ xmm1 = core::ptr::read((rbp).wrapping_sub(0x9_u64) as *const u128);
    /* 1400a3dbf */ core::ptr::write((rax).wrapping_add(0x30_u64) as *mut u128, xmm1);
    /* 1400a3dc3 */ core::ptr::write((rbp).wrapping_sub(0x9_u64) as *mut u128, xmm6);
    /* 1400a3dc8 */ core::ptr::write((rbp).wrapping_sub(0x19_u64) as *mut u8, 0x0_u8);
    /* 1400a3dcc */ core::ptr::write((rax).wrapping_add(0x40_u64) as *mut u32, (rsi as u32));
    /* 1400a3dcf */ core::ptr::write(rax as *mut u64, r15);
    /* 1400a3dd2 */ core::ptr::write((rax).wrapping_add(0x8_u64) as *mut u64, r15);
    /* 1400a3dd6 */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u64, r15);
    /* 1400a3dda */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u16, 0x0_u16);
    /* 1400a3de0 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u64, 0x0_u64);
    /* 1400a3de8 */ xmm0 = core::ptr::read((rbp).wrapping_sub(0x39_u64) as *const u128);
    /* 1400a3dec */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm0);
    /* 1400a3df0 */ r8 = rax;
    /* 1400a3df3 */ rdx = (rbp).wrapping_sub(0x39_u64);
    /* 1400a3df7 */ rcx = r13;
    /* 1400a3dfa */ fn_140047580();
    /* fallthrough -> bb599 */

    // ---- bb599 @ 0x1400a3e00 ----
    /* 1400a3e00 */ rcx = (rbp).wrapping_sub(0x19_u64);
    /* 1400a3e04 */ fn_140027900();
    /* 1400a3e09 */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    if (SF != OF) {
        /* -> bb606 */
    } else {
        /* -> bb605 */
    }

    // ---- bb605 @ 0x1400a3e0e ----
    if (SF == OF) {
        /* -> bb381 */
    } else {
        /* -> bb606 */
    }

    // ---- bb606 @ 0x1400a3e14 ----
    /* fallthrough -> bb491 */

    // ---- bb607 @ 0x1400a3e19 ----
    /* 1400a3e19 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 1400a3e22 */ let mut t_1400a3e22_0: u32 = 0x0_u32;
    /* 1400a3e22 */ r9 = (t_1400a3e22_0 as u64);
    /* 1400a3e25 */ let mut t_1400a3e25_0: u32 = 0x0_u32;
    /* 1400a3e25 */ r8 = (t_1400a3e25_0 as u64);
    /* 1400a3e28 */ let mut t_1400a3e28_0: u32 = 0x0_u32;
    /* 1400a3e28 */ rdx = (t_1400a3e28_0 as u64);
    /* 1400a3e2a */ let mut t_1400a3e2a_0: u32 = 0x0_u32;
    /* 1400a3e2a */ rcx = (t_1400a3e2a_0 as u64);
    /* 1400a3e2c */ fn_1402cd884();
    /* fallthrough -> bb614 */

    // ---- bb614 @ 0x1400a3e32 ----
    /* 1400a3e32 */ fn_1400477e0();
    /* fallthrough -> bb616 */

    // ---- bb616 @ 0x1400a3e38 ----
    /* 1400a3e38 */ fn_140024130();
    /* fallthrough -> bb618 */

    // ---- bb618 @ 0x1400a3e3e ----
    /* 1400a3e3e */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, 0x0_u64);
    /* 1400a3e47 */ let mut t_1400a3e47_0: u32 = 0x0_u32;
    /* 1400a3e47 */ r9 = (t_1400a3e47_0 as u64);
    /* 1400a3e4a */ let mut t_1400a3e4a_0: u32 = 0x0_u32;
    /* 1400a3e4a */ r8 = (t_1400a3e4a_0 as u64);
    /* 1400a3e4d */ let mut t_1400a3e4d_0: u32 = 0x0_u32;
    /* 1400a3e4d */ rdx = (t_1400a3e4d_0 as u64);
    /* 1400a3e4f */ let mut t_1400a3e4f_0: u32 = 0x0_u32;
    /* 1400a3e4f */ rcx = (t_1400a3e4f_0 as u64);
    /* 1400a3e51 */ fn_1402cd884();
    /* fallthrough -> bb625 */

    // ---- bb625 @ 0x1400a3e57 ----
    /* 1400a3e57 */ fn_140024130();
    /* fallthrough -> bb627 */

    // ---- bb627 @ 0x1400a3e5d ----
    /* 1400a3e5d */ fn_1400477e0();
    /* fallthrough -> bb629 */

    // ---- bb629 @ 0x1400a3e63 ----
    /* 1400a3e63 */ fn_140024130();
    /* fallthrough -> bb631 */

    // ---- bb631 @ 0x1400a3e69 ----
    /* 1400a3e69 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 1400a3e6e */ let mut t_1400a3e6e_0: u32 = 0x0_u32;
    /* 1400a3e6e */ r9 = (t_1400a3e6e_0 as u64);
    /* 1400a3e71 */ let mut t_1400a3e71_0: u32 = 0x0_u32;
    /* 1400a3e71 */ r8 = (t_1400a3e71_0 as u64);
    /* 1400a3e74 */ let mut t_1400a3e74_0: u32 = 0x0_u32;
    /* 1400a3e74 */ rdx = (t_1400a3e74_0 as u64);
    /* 1400a3e76 */ let mut t_1400a3e76_0: u32 = 0x0_u32;
    /* 1400a3e76 */ rcx = (t_1400a3e76_0 as u64);
    /* 1400a3e78 */ fn_1402cd884();
    /* 1400a3e90 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 1400a3e90 */ rsp = (rsp).wrapping_add(0x0_u64);
    /* 1400a3e90 */ /* branch */ goto(core::ptr::read(rsp as *const u64));
    // <no successors>
}
