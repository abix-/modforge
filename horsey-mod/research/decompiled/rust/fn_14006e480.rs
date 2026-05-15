// Decompiled from Horsey.exe @ 0x14006e480
// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print
// blocks: 119

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]
pub unsafe fn save_path_writer_1() {

    // ---- bb0 @ 0x14006e480 ----
    if ((CF | ZF) == false) { /* -> bb3 */ }
    if ((CF | ZF) != 0) { /* -> bb2 */ }

    // ---- bb2 @ 0x14006e480 ----
    if ((CF | ZF) == false) { /* -> bb3 */ }

    // ---- bb3 @ 0x14006e482 ----
    /* 14006e482 */ let mut t_14006e482: u8 = core::ptr::read((rax).wrapping_sub(0x73_u64) as *const u8);
    /* 14006e482 */ core::ptr::write((rax).wrapping_sub(0x73_u64) as *mut u8, (t_14006e482).wrapping_add((rcx as u8)));
    /* 14006e485 */ let mut cs_base: u64 = core::ptr::read(rax as *const u16);
    /* 14006e487 */ let mut t_14006e487: u32 = core::ptr::read(rax as *const u32);
    /* 14006e487 */ let mut t_14006e487_0: u32 = ((rax as u32)).wrapping_add(t_14006e487);
    /* 14006e489 */ let mut t_14006e489_0: u8 = ((rax as u8)).wrapping_add(((rcx >> 0x8_u64) as u8));
    /* 14006e489 */ let mut rax: u64 = ((rax & 0xffffffffffffff00_u64) | (t_14006e489_0 as u64));
    /* 14006e48b */ let mut t_14006e48b_0: u32 = (rcx as u32);
    /* 14006e48b */ let mut rcx: u64 = ((rax as u32) as u64);
    /* 14006e48b */ rax = (t_14006e48b_0 as u64);
    if ((CF | ZF) == false) { /* -> bb11 */ }
    if ((CF | ZF) != 0) { /* -> bb10 */ }

    // ---- bb10 @ 0x14006e48c ----
    if ((CF | ZF) == false) { /* -> bb11 */ }

    // ---- bb11 @ 0x14006e48e ----
    /* 14006e48e */ let mut t_14006e48e: u8 = core::ptr::read((rax).wrapping_sub(0x73_u64) as *const u8);
    /* 14006e48e */ core::ptr::write((rax).wrapping_sub(0x73_u64) as *mut u8, (t_14006e48e).wrapping_add((rcx as u8)));
    /* 14006e491 */ let mut es_base: u64 = core::ptr::read((rax).wrapping_add(0x4_u64) as *const u16);
    /* 14006e494 */ let mut t_14006e494: u8 = core::ptr::read(rax as *const u8);
    /* 14006e494 */ let mut t_14006e494_0: u8 = (t_14006e494).wrapping_add((rax as u8));
    /* 14006e494 */ core::ptr::write(rax as *mut u8, t_14006e494_0);
    /* 14006e496 */ fn_140075b20();
    /* 14006e49b */ rcx = (rsi).wrapping_add(0x414_u64);
    /* 14006e4a2 */ fn_140075e20();
    /* 14006e4a7 */ rcx = (rsi).wrapping_add(0x415_u64);
    /* 14006e4ae */ fn_140075e20();
    /* 14006e4b3 */ rcx = (rsi).wrapping_add(0x37c_u64);
    /* 14006e4ba */ fn_140075b20();
    /* 14006e4bf */ core::ptr::write((rbp).wrapping_add(0x58_u64) as *mut u8, 0x0_u8);
    /* 14006e4c3 */ rcx = (rbp).wrapping_add(0x58_u64);
    /* 14006e4c7 */ fn_140075e20();
    /* 14006e4cc */ rcx = (rsi).wrapping_add(0x418_u64);
    /* 14006e4d3 */ fn_140075b20();
    /* 14006e4d8 */ rcx = (rsi).wrapping_add(0x41c_u64);
    /* 14006e4df */ fn_140075e20();
    /* 14006e4e4 */ let mut rdx: u64 = (rsi).wrapping_add(0x39c_u64);
    /* 14006e4eb */ rcx = (rbp).wrapping_add(0x50_u64);
    /* 14006e4ef */ fn_140075ec0();
    /* 14006e4f4 */ rcx = (rsi).wrapping_add(0x410_u64);
    /* 14006e4fb */ fn_140075b20();
    /* 14006e500 */ let mut rbx: u64 = (rsi).wrapping_add(0x31c_u64);
    /* 14006e507 */ let mut rdi: u64 = (0x6_u32 as u64);
    /* fallthrough -> bb36 */

    // ---- bb36 @ 0x14006e510 ----
    /* 14006e510 */ rcx = (rbx).wrapping_add(0x5_u64);
    /* 14006e514 */ fn_140075e20();
    /* 14006e519 */ rcx = rbx;
    /* 14006e51c */ fn_140075b20();
    /* 14006e521 */ rcx = (rbx).wrapping_add(0x4_u64);
    /* 14006e525 */ fn_140075e20();
    /* 14006e52a */ rbx = (rbx).wrapping_add(0x8_u64);
    /* 14006e52e */ let mut t_14006e52e_0: u64 = (rdi).wrapping_sub(0x1_u64);
    /* 14006e52e */ rdi = t_14006e52e_0;
    if ZF {
        /* -> bb47 */
    } else {
        /* -> bb46 */
    }

    // ---- bb46 @ 0x14006e532 ----
    if (ZF == false) {
        /* -> bb36 */
    } else {
        /* -> bb47 */
    }

    // ---- bb47 @ 0x14006e534 ----
    /* 14006e534 */ rbx = (rsi).wrapping_add(0x2cc_u64);
    /* 14006e53b */ rdi = (0xd_u32 as u64);
    /* fallthrough -> bb49 */

    // ---- bb49 @ 0x14006e540 ----
    /* 14006e540 */ rcx = (rbx).wrapping_sub(0x34_u64);
    /* 14006e544 */ fn_140075b20();
    /* 14006e549 */ rcx = rbx;
    /* 14006e54c */ fn_140075b20();
    /* 14006e551 */ rbx = (rbx).wrapping_add(0x4_u64);
    /* 14006e555 */ let mut t_14006e555_0: u64 = (rdi).wrapping_sub(0x1_u64);
    /* 14006e555 */ rdi = t_14006e555_0;
    if ZF {
        /* -> bb58 */
    } else {
        /* -> bb57 */
    }

    // ---- bb57 @ 0x14006e559 ----
    if (ZF == false) {
        /* -> bb49 */
    } else {
        /* -> bb58 */
    }

    // ---- bb58 @ 0x14006e55b ----
    /* 14006e55b */ rbx = (rsi).wrapping_add(0x280_u64);
    /* 14006e562 */ rax = core::ptr::read(rbx as *const u64);
    /* 14006e565 */ let mut t_14006e565: u64 = core::ptr::read((rbx).wrapping_add(0x8_u64) as *const u64);
    if (rax != t_14006e565) {
        /* -> bb64 */
    } else {
        /* -> bb63 */
    }

    // ---- bb63 @ 0x14006e569 ----
    if (rax != t_14006e565) {
        /* -> bb64 */
    } else {
        /* -> bb65 */
    }

    // ---- bb64 @ 0x14006e56b ----
    /* 14006e56b */ core::ptr::write((rbx).wrapping_add(0x8_u64) as *mut u64, rax);
    /* fallthrough -> bb65 */

    // ---- bb65 @ 0x14006e56f ----
    /* 14006e56f */ fn_140075d40();
    /* 14006e574 */ let mut r9: u64 = (((rax as u32) as i64) as u64);
    /* 14006e577 */ let mut r10: u64 = core::ptr::read(rbx as *const u64);
    /* 14006e57a */ let mut r11: u64 = core::ptr::read((rbx).wrapping_add(0x8_u64) as *const u64);
    /* 14006e581 */ let mut t_14006e581_0: u64 = (rcx).wrapping_sub(r10);
    /* 14006e584 */ let mut r12: u64 = 0xe38e38e38e38e39_u64;
    /* 14006e591 */ let mut t_14006e591_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 14006e591 */ rdx = ((t_14006e591_0 >> 0x40_u128) as u64);
    /* 14006e594 */ let mut r8: u64 = rdx;
    /* 14006e597 */ r8 = (((r8 as i64) >> (0x1_u64 as i64)) as u64);
    /* 14006e59a */ rax = r8;
    /* 14006e59d */ rax = (rax >> (0x3f_u8 as u64));
    /* 14006e5a1 */ r8 = (r8).wrapping_add(rax);
    if CF {
        /* -> bb83 */
    } else {
        /* -> bb82 */
    }

    // ---- bb82 @ 0x14006e5a7 ----
    if CF {
        /* -> bb83 */
    } else {
        /* -> bb87 */
    }

    // ---- bb83 @ 0x14006e5a9 ----
    /* 14006e5b1 */ core::ptr::write((rbx).wrapping_add(0x8_u64) as *mut u64, rcx);
    /* fallthrough -> bb113 */

    // ---- bb87 @ 0x14006e5b7 ----
    if ((CF | (r9 == r8)) == false) { /* -> bb90 */ }
    if ((CF | (r9 == r8)) != 0) { /* -> bb89 */ }

    // ---- bb89 @ 0x14006e5b7 ----
    if ((CF | (r9 == r8)) == false) { /* -> bb90 */ }
    if ((CF | (r9 == r8)) != 0) { /* -> bb113 */ }

    // ---- bb90 @ 0x14006e5b9 ----
    /* 14006e5b9 */ let mut t_14006e5b9: u64 = core::ptr::read((rbx).wrapping_add(0x10_u64) as *const u64);
    /* 14006e5bd */ let mut t_14006e5bd_0: u64 = (rcx).wrapping_sub(r10);
    /* 14006e5c3 */ let mut t_14006e5c3_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 14006e5c3 */ rdx = ((t_14006e5c3_0 >> 0x40_u128) as u64);
    /* 14006e5c6 */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 14006e5c9 */ rax = rdx;
    /* 14006e5cc */ rax = (rax >> (0x3f_u8 as u64));
    /* 14006e5d0 */ let mut t_14006e5d0_0: u64 = (rdx).wrapping_add(rax);
    if ((CF | (r9 == rdx)) == false) { /* -> bb102 */ }
    if ((CF | (r9 == rdx)) != 0) { /* -> bb101 */ }

    // ---- bb101 @ 0x14006e5d6 ----
    if ((CF | (r9 == rdx)) == false) { /* -> bb102 */ }
    if ((CF | (r9 == rdx)) != 0) { /* -> bb107 */ }

    // ---- bb102 @ 0x14006e5d8 ----
    /* 14006e5d8 */ r8 = (rbp).wrapping_add(0x50_u64);
    /* 14006e5dc */ rdx = r9;
    /* 14006e5df */ rcx = rbx;
    /* 14006e5e2 */ fn_14006fa50();
    /* fallthrough -> bb113 */

    // ---- bb107 @ 0x14006e5e9 ----
    /* 14006e5e9 */ let mut t_14006e5e9_0: u64 = (r9).wrapping_sub(r8);
    /* 14006e5e9 */ r9 = t_14006e5e9_0;
    /* 14006e5ec */ r8 = rbx;
    /* 14006e5ef */ rdx = r9;
    /* 14006e5f2 */ rcx = r11;
    /* 14006e5f5 */ fn_14006fbf0();
    /* 14006e5fa */ core::ptr::write((rbx).wrapping_add(0x8_u64) as *mut u64, rax);
    /* fallthrough -> bb113 */

    // ---- bb113 @ 0x14006e5fe ----
    /* 14006e5fe */ let mut t_14006e5fe_0: u32 = 0x0_u32;
    /* 14006e5fe */ rdi = (t_14006e5fe_0 as u64);
    /* 14006e600 */ let mut r15: u64 = ((rdi as u32) as u64);
    /* 14006e603 */ r9 = core::ptr::read(rbx as *const u64);
    /* 14006e606 */ let mut t_14006e606: u64 = core::ptr::read((rbx).wrapping_add(0x8_u64) as *const u64);
    /* 14006e60a */ let mut t_14006e60a_0: u64 = (rcx).wrapping_sub(r9);
    /* 14006e610 */ let mut t_14006e610_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 14006e610 */ rdx = ((t_14006e610_0 >> 0x40_u128) as u64);
    /* 14006e613 */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 14006e616 */ rax = rdx;
    /* 14006e619 */ rax = (rax >> (0x3f_u8 as u64));
    /* 14006e61d */ let mut t_14006e61d_0: u64 = (rdx).wrapping_add(rax);
    /* 14006e61d */ rdx = t_14006e61d_0;
    if (r9 != r8) {
        /* -> bb127 */
    } else {
        /* -> bb126 */
    }

    // ---- bb126 @ 0x14006e620 ----
    if (r9 != r8) {
        /* -> bb127 */
    } else {
        /* -> bb164 */
    }

    // ---- bb127 @ 0x14006e626 ----
    /* 14006e626 */ r8 = ((rdi as u32) as u64);
    /* fallthrough -> bb129 */

    // ---- bb129 @ 0x14006e630 ----
    /* 14006e630 */ let mut r14: u64 = (r8).wrapping_add((r8).wrapping_mul(0x8_u64));
    /* 14006e638 */ rcx = (rcx).wrapping_add((r14).wrapping_mul(0x4_u64));
    /* 14006e63c */ fn_140075c50();
    /* 14006e641 */ rcx = core::ptr::read(rbx as *const u64);
    /* 14006e644 */ let mut t_14006e644_0: u64 = (rcx).wrapping_add(0x8_u64);
    /* 14006e648 */ rcx = (rcx).wrapping_add((r14).wrapping_mul(0x4_u64));
    /* 14006e64c */ fn_140075c50();
    /* 14006e651 */ let mut t_14006e651: u32 = core::ptr::read((0x14006e658_u64).wrapping_add(0x38cb98_u64) as *const u32);
    if (SF == OF) {
        /* -> bb141 */
    } else {
        /* -> bb140 */
    }

    // ---- bb140 @ 0x14006e658 ----
    if (SF == OF) {
        /* -> bb141 */
    } else {
        /* -> bb145 */
    }

    // ---- bb141 @ 0x14006e65a ----
    /* 14006e65a */ rcx = core::ptr::read(rbx as *const u64);
    /* 14006e65d */ let mut t_14006e65d_0: u64 = (rcx).wrapping_add(0xc_u64);
    /* 14006e661 */ rcx = (rcx).wrapping_add((r14).wrapping_mul(0x4_u64));
    /* 14006e665 */ fn_140075c50();
    /* fallthrough -> bb145 */

    // ---- bb145 @ 0x14006e66a ----
    /* 14006e66a */ rcx = core::ptr::read(rbx as *const u64);
    /* 14006e66d */ let mut t_14006e66d_0: u64 = (rcx).wrapping_add(0x10_u64);
    /* 14006e671 */ rcx = (rcx).wrapping_add((r14).wrapping_mul(0x4_u64));
    /* 14006e675 */ fn_140075c50();
    /* 14006e67a */ r15 = (((r15 as u32)).wrapping_add(0x1_u32) as u64);
    /* 14006e67d */ r9 = core::ptr::read(rbx as *const u64);
    /* 14006e680 */ r8 = (((r15 as u32) as i64) as u64);
    /* 14006e683 */ let mut t_14006e683: u64 = core::ptr::read((rbx).wrapping_add(0x8_u64) as *const u64);
    /* 14006e687 */ let mut t_14006e687_0: u64 = (rcx).wrapping_sub(r9);
    /* 14006e68d */ let mut t_14006e68d_0: u128 = ((rax as u128)).wrapping_mul((rcx as u128));
    /* 14006e68d */ rdx = ((t_14006e68d_0 >> 0x40_u128) as u64);
    /* 14006e690 */ rdx = (((rdx as i64) >> (0x1_u64 as i64)) as u64);
    /* 14006e693 */ rax = rdx;
    /* 14006e696 */ rax = (rax >> (0x3f_u8 as u64));
    /* 14006e69a */ rdx = (rdx).wrapping_add(rax);
    if (CF == false) { /* -> bb164 */ }
    if CF { /* -> bb163 */ }

    // ---- bb163 @ 0x14006e6a0 ----
    if CF { /* -> bb129 */ }
    if (CF == false) { /* -> bb164 */ }

    // ---- bb164 @ 0x14006e6a2 ----
    /* 14006e6a2 */ rcx = (rsi).wrapping_add(0x278_u64);
    /* 14006e6a9 */ fn_140075b20();
    /* 14006e6ae */ rcx = (rsi).wrapping_add(0x27c_u64);
    /* 14006e6b5 */ fn_140075b20();
    /* 14006e6ba */ let mut t_14006e6ba: u32 = core::ptr::read((0x14006e6c0_u64).wrapping_add(0x390070_u64) as *const u32);
    /* 14006e6c0 */ let mut t_14006e6c0: u64 = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14006e6c9 */ r15 = (0x4_u32 as u64);
    /* 14006e6cf */ rbx = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14006e6d3 */ let mut t_14006e6d3: u32 = core::ptr::read((rbx).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14006e6d3 */ rax = (t_14006e6d3 as u64);
    /* 14006e6d7 */ let mut t_14006e6d7: u32 = core::ptr::read((0x14006e6dd_u64).wrapping_add(0x37c5e7_u64) as *const u32);
    if (((SF == OF) & (t_14006e6d7 != (rax as u32))) == false) { /* -> bb177 */ }
    if (((SF == OF) & (t_14006e6d7 != (rax as u32))) != 0) { /* -> bb176 */ }

    // ---- bb176 @ 0x14006e6dd ----
    if (((SF == OF) & (t_14006e6d7 != (rax as u32))) == false) { /* -> bb177 */ }
    if (((SF == OF) & (t_14006e6d7 != (rax as u32))) != 0) { /* -> bb530 */ }

    // ---- bb177 @ 0x14006e6e3 ----
    /* 14006e6e3 */ let mut t_14006e6e3: u32 = core::ptr::read((rbx).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14006e6e3 */ rax = (t_14006e6e3 as u64);
    /* 14006e6e7 */ let mut t_14006e6e7: u32 = core::ptr::read((0x14006e6ed_u64).wrapping_add(0x37c5df_u64) as *const u32);
    if (((SF == OF) & (t_14006e6e7 != (rax as u32))) == false) { /* -> bb182 */ }
    if (((SF == OF) & (t_14006e6e7 != (rax as u32))) != 0) { /* -> bb181 */ }

    // ---- bb181 @ 0x14006e6ed ----
    if (((SF == OF) & (t_14006e6e7 != (rax as u32))) == false) { /* -> bb182 */ }
    if (((SF == OF) & (t_14006e6e7 != (rax as u32))) != 0) { /* -> bb551 */ }

    // ---- bb182 @ 0x14006e6f3 ----
    /* 14006e6f3 */ let mut t_14006e6f3: u32 = core::ptr::read((rbx).wrapping_add((r15).wrapping_mul(0x1_u64)) as *const u32);
    /* 14006e6f3 */ rax = (t_14006e6f3 as u64);
    /* 14006e6f7 */ let mut t_14006e6f7: u32 = core::ptr::read((0x14006e6fd_u64).wrapping_add(0x37c5d7_u64) as *const u32);
    if (((SF == OF) & (t_14006e6f7 != (rax as u32))) == false) { /* -> bb187 */ }
    if (((SF == OF) & (t_14006e6f7 != (rax as u32))) != 0) { /* -> bb186 */ }

    // ---- bb186 @ 0x14006e6fd ----
    if (((SF == OF) & (t_14006e6f7 != (rax as u32))) == false) { /* -> bb187 */ }
    if (((SF == OF) & (t_14006e6f7 != (rax as u32))) != 0) { /* -> bb512 */ }

    // ---- bb187 @ 0x14006e703 ----
    /* 14006e703 */ let mut t_14006e703: u32 = core::ptr::read((rsi).wrapping_add(0x278_u64) as *const u32);
    /* 14006e709 */ let mut t_14006e709: u32 = core::ptr::read((rsi).wrapping_add(0x27c_u64) as *const u32);
    /* 14006e709 */ let mut t_14006e709_0: u64 = (((rax as u32) as u64)).wrapping_mul((t_14006e709 as u64));
    /* 14006e709 */ rax = ((t_14006e709_0 as u32) as u64);
    /* 14006e710 */ rbx = (((rax as u32) as i64) as u64);
    /* 14006e713 */ core::ptr::write((rbp).wrapping_add(0x50_u64) as *mut u64, rbx);
    /* 14006e71c */ let mut t_14006e71c_0: u128 = ((rax as u128)).wrapping_mul((rbx as u128));
    /* 14006e71c */ rdx = ((t_14006e71c_0 >> 0x40_u128) as u64);
    /* 14006e71c */ rax = (t_14006e71c_0 as u64);
    /* 14006e71f */ r15 = 0xffffffffffffffff_u64;
    if (CF == false) { /* -> bb195 */ }
    if CF { /* -> bb196 */ }

    // ---- bb196 @ 0x14006e726 ----
    /* 14006e726 */ rax = r15;
    /* fallthrough -> bb195 */

    // ---- bb195 @ 0x14006e72a ----
    /* 14006e72a */ rcx = rax;
    /* 14006e72d */ fn_1402c7c60();
    /* 14006e732 */ core::ptr::write((rbp).wrapping_add(0x50_u64) as *mut u64, rax);
    if (t_14006eb94 != 0xffffffff_u32) {
        /* -> bb204 */
    } else {
        /* -> bb203 */
    }

    // ---- bb203 @ 0x14006e739 ----
    if (t_14006eb94 != 0xffffffff_u32) {
        /* -> bb204 */
    } else {
        /* -> bb223 */
    }

    // ---- bb204 @ 0x14006e73b ----
    if (t_14006eb94 != 0xffffffff_u32) {
        /* -> bb208 */
    } else {
        /* -> bb207 */
    }

    // ---- bb207 @ 0x14006e73e ----
    if (t_14006eb94 != 0xffffffff_u32) {
        /* -> bb208 */
    } else {
        /* -> bb224 */
    }

    // ---- bb208 @ 0x14006e740 ----
    /* 14006e740 */ rcx = (rax).wrapping_add(0x8_u64);
    /* fallthrough -> bb211 */

    // ---- bb211 @ 0x14006e750 ----
    /* 14006e750 */ core::ptr::write((rcx).wrapping_sub(0x8_u64) as *mut u64, rdi);
    /* 14006e754 */ core::ptr::write(rcx as *mut u32, (r15 as u32));
    /* 14006e757 */ core::ptr::write((rcx).wrapping_add(0x4_u64) as *mut u16, 0x0_u16);
    /* 14006e75d */ core::ptr::write((rcx).wrapping_add(0x8_u64) as *mut u64, rdi);
    /* 14006e761 */ core::ptr::write((rcx).wrapping_add(0x10_u64) as *mut u64, rdi);
    /* 14006e765 */ core::ptr::write((rcx).wrapping_add(0x18_u64) as *mut u64, rdi);
    /* 14006e769 */ rcx = (rcx).wrapping_add(0x28_u64);
    /* 14006e76d */ let mut t_14006e76d_0: u64 = (rbx).wrapping_sub(0x1_u64);
    /* 14006e76d */ rbx = t_14006e76d_0;
    if (t_14006eb94 == 0xffffffff_u32) {
        /* -> bb222 */
    } else {
        /* -> bb221 */
    }

    // ---- bb221 @ 0x14006e771 ----
    if (t_14006eb94 != 0xffffffff_u32) {
        /* -> bb211 */
    } else {
        /* -> bb222 */
    }

    // ---- bb222 @ 0x14006e773 ----
    /* fallthrough -> bb224 */

    // ---- bb223 @ 0x14006e775 ----
    /* fallthrough -> bb224 */

    // ---- bb224 @ 0x14006e778 ----
    /* 14006e778 */ core::ptr::write((rsi).wrapping_add(0x270_u64) as *mut u64, rax);
    /* 14006e77f */ r15 = ((rdi as u32) as u64);
    /* 14006e782 */ r12 = ((rdi as u32) as u64);
    /* 14006e785 */ let mut t_14006e785: u32 = core::ptr::read((rsi).wrapping_add(0x278_u64) as *const u32);
    /* 14006e78b */ let mut t_14006e78b: u32 = core::ptr::read((rsi).wrapping_add(0x27c_u64) as *const u32);
    /* 14006e78b */ let mut t_14006e78b_0: u64 = (((rax as u32) as u64)).wrapping_mul((t_14006e78b as u64));
    /* 14006e78b */ rax = ((t_14006e78b_0 as u32) as u64);
    if (((SF != OF) | (t_14006eb94 == 0xffffffff_u32)) == false) { /* -> bb233 */ }
    if (((SF != OF) | (t_14006eb94 == 0xffffffff_u32)) != 0) { /* -> bb232 */ }

    // ---- bb232 @ 0x14006e794 ----
    if (((SF != OF) | (t_14006eb94 == 0xffffffff_u32)) == false) { /* -> bb233 */ }
    if (((SF != OF) | (t_14006eb94 == 0xffffffff_u32)) != 0) { /* -> bb312 */ }

    // ---- bb233 @ 0x14006e79a ----
    /* 14006e79a */ rbx = rdi;
    /* fallthrough -> bb235 */

    // ---- bb235 @ 0x14006e7a0 ----
    /* 14006e7a0 */ r14 = core::ptr::read((rsi).wrapping_add(0x270_u64) as *const u64);
    if (((SF != OF) | ((r12 as u32) == (rax as u32))) == false) { /* -> bb240 */ }
    if (((SF != OF) | ((r12 as u32) == (rax as u32))) != 0) { /* -> bb239 */ }

    // ---- bb239 @ 0x14006e7aa ----
    if (((SF != OF) | ((r12 as u32) == (rax as u32))) == false) { /* -> bb240 */ }
    if (((SF != OF) | ((r12 as u32) == (rax as u32))) != 0) { /* -> bb245 */ }

    // ---- bb240 @ 0x14006e7ac ----
    /* 14006e7ac */ core::ptr::write((r14).wrapping_add((rbx).wrapping_mul(0x1_u64)) as *mut u32, 0x6_u32);
    /* 14006e7b4 */ let mut t_14006e7b4: u32 = core::ptr::read((0x14006e7ba_u64).wrapping_add(0x37c506_u64) as *const u32);
    /* 14006e7ba */ core::ptr::write(((r14).wrapping_add((rbx).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *mut u32, (rax as u32));
    /* 14006e7bf */ r15 = (((r15 as u32)).wrapping_sub(0x1_u32) as u64);
    /* fallthrough -> bb304 */

    // ---- bb245 @ 0x14006e7c7 ----
    /* 14006e7c7 */ rcx = (rbp).wrapping_add(0x50_u64);
    /* 14006e7cb */ fn_140075dd0();
    /* 14006e7d0 */ let mut t_14006e7d0: u8 = core::ptr::read((rbp).wrapping_add(0x50_u64) as *const u8);
    /* 14006e7d0 */ rcx = ((t_14006e7d0 as u32) as u64);
    if ((rcx as u8) == 0x3f_u8) {
        /* -> bb252 */
    } else {
        /* -> bb251 */
    }

    // ---- bb251 @ 0x14006e7d7 ----
    if ((rcx as u8) == 0x3f_u8) {
        /* -> bb252 */
    } else {
        /* -> bb260 */
    }

    // ---- bb252 @ 0x14006e7d9 ----
    /* 14006e7d9 */ rcx = (rbp).wrapping_add(0x50_u64);
    /* 14006e7dd */ fn_140075dd0();
    /* 14006e7e2 */ let mut t_14006e7e2: u8 = core::ptr::read((rbp).wrapping_add(0x50_u64) as *const u8);
    /* 14006e7e2 */ r15 = ((t_14006e7e2 as u32) as u64);
    /* 14006e7e7 */ r15 = (((r15 as u32)).wrapping_sub(0x1_u32) as u64);
    /* 14006e7ea */ core::ptr::write((r14).wrapping_add((rbx).wrapping_mul(0x1_u64)) as *mut u32, 0x6_u32);
    /* 14006e7f2 */ let mut t_14006e7f2: u32 = core::ptr::read((0x14006e7f8_u64).wrapping_add(0x37c4c8_u64) as *const u32);
    /* 14006e7f8 */ core::ptr::write(((r14).wrapping_add((rbx).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb304 */

    // ---- bb260 @ 0x14006e802 ----
    /* 14006e802 */ rax = (((rcx).wrapping_sub(0x3b_u64) as u32) as u64);
    if (((CF == false) & ((rax as u8) != 0x3_u8)) == false) { /* -> bb265 */ }
    if (((CF == false) & ((rax as u8) != 0x3_u8)) != 0) { /* -> bb264 */ }

    // ---- bb264 @ 0x14006e807 ----
    if (((CF == false) & ((rax as u8) != 0x3_u8)) == false) { /* -> bb265 */ }
    if (((CF == false) & ((rax as u8) != 0x3_u8)) != 0) { /* -> bb271 */ }

    // ---- bb265 @ 0x14006e809 ----
    /* 14006e809 */ core::ptr::write((r14).wrapping_add((rbx).wrapping_mul(0x1_u64)) as *mut u32, (rdi as u32));
    /* 14006e80d */ let mut t_14006e80d: u8 = core::ptr::read((rbp).wrapping_add(0x50_u64) as *const u8);
    /* 14006e80d */ rcx = ((t_14006e80d as u32) as u64);
    /* 14006e811 */ let mut t_14006e811_0: u32 = ((rcx as u32)).wrapping_add(0xffffffc5_u32);
    /* 14006e814 */ let mut t_14006e814: u32 = core::ptr::read((0x14006e81a_u64).wrapping_add(0x37c4ae_u64) as *const u32);
    /* 14006e814 */ let mut t_14006e814_0: u32 = ((rcx as u32)).wrapping_add(t_14006e814);
    /* 14006e81a */ core::ptr::write(((r14).wrapping_add((rbx).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *mut u32, (rcx as u32));
    /* fallthrough -> bb304 */

    // ---- bb271 @ 0x14006e821 ----
    /* 14006e821 */ rax = ((rcx as u32) as u64);
    /* 14006e823 */ let mut t_14006e823_0: u32 = ((rax as u32) & 0x3f_u32);
    /* 14006e826 */ core::ptr::write((r14).wrapping_add((rbx).wrapping_mul(0x1_u64)) as *mut u32, (rax as u32));
    /* 14006e82a */ let mut t_14006e82a: u8 = core::ptr::read((rbp).wrapping_add(0x50_u64) as *const u8);
    /* 14006e82a */ rax = ((t_14006e82a as u32) as u64);
    /* 14006e82e */ rax = ((rax & 0xffffffffffffff00_u64) | (((rax as u8) >> 0x6_u8) as u64));
    /* 14006e831 */ let mut t_14006e831_0: u8 = ((rax as u8) & 0x1_u8);
    /* 14006e833 */ core::ptr::write(((r14).wrapping_add((rbx).wrapping_mul(0x1_u64))).wrapping_add(0xc_u64) as *mut u8, (rax as u8));
    /* 14006e838 */ let mut t_14006e838: u8 = core::ptr::read((rbp).wrapping_add(0x50_u64) as *const u8);
    /* 14006e838 */ rax = ((t_14006e838 as u32) as u64);
    /* 14006e83c */ rax = ((rax & 0xffffffffffffff00_u64) | (((rax as u8) >> 0x7_u8) as u64));
    /* 14006e83f */ core::ptr::write(((r14).wrapping_add((rbx).wrapping_mul(0x1_u64))).wrapping_add(0xd_u64) as *mut u8, (rax as u8));
    /* 14006e844 */ rcx = (rbp).wrapping_add(0x50_u64);
    /* 14006e848 */ fn_140075dd0();
    /* 14006e84d */ let mut t_14006e84d: u8 = core::ptr::read((rbp).wrapping_add(0x50_u64) as *const u8);
    /* 14006e84d */ rax = ((t_14006e84d as u32) as u64);
    /* 14006e851 */ core::ptr::write(((r14).wrapping_add((rbx).wrapping_mul(0x1_u64))).wrapping_add(0x8_u64) as *mut u32, (rax as u32));
    /* 14006e856 */ let mut t_14006e856: u32 = core::ptr::read((0x14006e85d_u64).wrapping_add(0x38c993_u64) as *const u32);
    if (((SF == OF) & (t_14006e856 != 0xb_u32)) == false) { /* -> bb289 */ }
    if (((SF == OF) & (t_14006e856 != 0xb_u32)) != 0) { /* -> bb288 */ }

    // ---- bb288 @ 0x14006e85d ----
    if (((SF == OF) & (t_14006e856 != 0xb_u32)) == false) { /* -> bb289 */ }
    if (((SF == OF) & (t_14006e856 != 0xb_u32)) != 0) { /* -> bb294 */ }

    // ---- bb289 @ 0x14006e85f ----
    /* 14006e85f */ let mut t_14006e85f: u32 = core::ptr::read((0x14006e865_u64).wrapping_add(0x37c46b_u64) as *const u32);
    if ((rax as u32) == t_14006e85f) {
        /* -> bb293 */
    } else {
        /* -> bb292 */
    }

    // ---- bb292 @ 0x14006e865 ----
    if ((rax as u32) == t_14006e85f) {
        /* -> bb293 */
    } else {
        /* -> bb294 */
    }

    // ---- bb293 @ 0x14006e867 ----
    /* 14006e867 */ core::ptr::write((r14).wrapping_add((rbx).wrapping_mul(0x1_u64)) as *mut u32, 0x14_u32);
    /* fallthrough -> bb294 */

    // ---- bb294 @ 0x14006e86f ----
    /* 14006e86f */ let mut t_14006e86f: u32 = core::ptr::read((r14).wrapping_add((rbx).wrapping_mul(0x1_u64)) as *const u32);
    /* 14006e86f */ rcx = (t_14006e86f as u64);
    /* 14006e873 */ fn_140110b60();
    if (((SF != OF) | ((rax as u32) == t_14006e85f)) == false) { /* -> bb300 */ }
    if (((SF != OF) | ((rax as u32) == t_14006e85f)) != 0) { /* -> bb299 */ }

    // ---- bb299 @ 0x14006e87a ----
    if (((SF != OF) | ((rax as u32) == t_14006e85f)) == false) { /* -> bb300 */ }
    if (((SF != OF) | ((rax as u32) == t_14006e85f)) != 0) { /* -> bb304 */ }

    // ---- bb300 @ 0x14006e87c ----
    /* 14006e87c */ rcx = (rbp).wrapping_add(0x50_u64);
    /* 14006e880 */ fn_140075dd0();
    /* 14006e885 */ let mut t_14006e885: u8 = core::ptr::read((rbp).wrapping_add(0x50_u64) as *const u8);
    /* 14006e889 */ core::ptr::write(((r14).wrapping_add((rbx).wrapping_mul(0x1_u64))).wrapping_add(0x4_u64) as *mut u32, (rax as u32));
    /* fallthrough -> bb304 */

    // ---- bb304 @ 0x14006e88e ----
    /* 14006e88e */ r12 = (((r12 as u32)).wrapping_add(0x1_u32) as u64);
    /* 14006e891 */ rbx = (rbx).wrapping_add(0x28_u64);
    /* 14006e895 */ let mut t_14006e895: u32 = core::ptr::read((rsi).wrapping_add(0x278_u64) as *const u32);
    /* 14006e89b */ let mut t_14006e89b: u32 = core::ptr::read((rsi).wrapping_add(0x27c_u64) as *const u32);
    /* 14006e89b */ let mut t_14006e89b_0: u64 = (((rax as u32) as u64)).wrapping_mul((t_14006e89b as u64));
    /* 14006e89b */ rax = ((t_14006e89b_0 as u32) as u64);
    if (SF == OF) {
        /* -> bb312 */
    } else {
        /* -> bb311 */
    }

    // ---- bb311 @ 0x14006e8a5 ----
    if (SF != OF) {
        /* -> bb235 */
    } else {
        /* -> bb312 */
    }

    // ---- bb312 @ 0x14006e8ab ----
    /* 14006e8ab */ rdx = ((rdx & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 14006e8ad */ rcx = rsi;
    /* 14006e8b0 */ fn_1401007e0();
    /* 14006e8b5 */ rbx = (rsi).wrapping_add(0x420_u64);
    /* 14006e8bc */ rax = core::ptr::read(rbx as *const u64);
    /* 14006e8bf */ let mut t_14006e8bf: u64 = core::ptr::read((rbx).wrapping_add(0x8_u64) as *const u64);
    if (rax != t_14006e8bf) {
        /* -> bb321 */
    } else {
        /* -> bb320 */
    }

    // ---- bb320 @ 0x14006e8c3 ----
    if (rax != t_14006e8bf) {
        /* -> bb321 */
    } else {
        /* -> bb322 */
    }

    // ---- bb321 @ 0x14006e8c5 ----
    /* 14006e8c5 */ core::ptr::write((rbx).wrapping_add(0x8_u64) as *mut u64, rax);
    /* fallthrough -> bb322 */

    // ---- bb322 @ 0x14006e8c9 ----
    /* 14006e8c9 */ fn_140075d40();
    /* 14006e8ce */ rdx = (((rax as u32) as i64) as u64);
    /* 14006e8d1 */ r8 = (rbp).wrapping_add(0x50_u64);
    /* 14006e8d5 */ rcx = rbx;
    /* 14006e8d8 */ fn_14006f8c0();
    /* 14006e8dd */ r15 = ((rdi as u32) as u64);
    /* 14006e8e0 */ let mut t_14006e8e0: u64 = core::ptr::read(rbx as *const u64);
    /* 14006e8e3 */ let mut t_14006e8e3: u64 = core::ptr::read((rbx).wrapping_add(0x8_u64) as *const u64);
    /* 14006e8e7 */ rax = (rax).wrapping_sub(rcx);
    /* 14006e8ea */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (rax != t_14006e8bf) {
        /* -> bb336 */
    } else {
        /* -> bb335 */
    }

    // ---- bb335 @ 0x14006e8f1 ----
    if (rax != t_14006e8bf) {
        /* -> bb336 */
    } else {
        /* -> bb353 */
    }

    // ---- bb336 @ 0x14006e8f3 ----
    /* 14006e8f3 */ r14 = rdi;
    /* fallthrough -> bb337 */

    // ---- bb337 @ 0x14006e8f6 ----
    /* 14006e8f6 */ rcx = (rcx).wrapping_add((r14).wrapping_mul(0x8_u64));
    /* 14006e8fa */ fn_140075b20();
    /* 14006e8ff */ rcx = core::ptr::read(rbx as *const u64);
    /* 14006e902 */ let mut t_14006e902_0: u64 = (rcx).wrapping_add(0x4_u64);
    /* 14006e906 */ rcx = (rcx).wrapping_add((r14).wrapping_mul(0x8_u64));
    /* 14006e90a */ fn_140075b20();
    /* 14006e90f */ r15 = (((r15 as u32)).wrapping_add(0x1_u32) as u64);
    /* 14006e912 */ let mut t_14006e912: u64 = core::ptr::read(rbx as *const u64);
    /* 14006e915 */ r14 = (((r15 as u32) as i64) as u64);
    /* 14006e918 */ let mut t_14006e918: u64 = core::ptr::read((rbx).wrapping_add(0x8_u64) as *const u64);
    /* 14006e91c */ rax = (rax).wrapping_sub(rcx);
    /* 14006e91f */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (CF == false) { /* -> bb353 */ }
    if CF { /* -> bb352 */ }

    // ---- bb352 @ 0x14006e926 ----
    if CF { /* -> bb337 */ }
    if (CF == false) { /* -> bb353 */ }

    // ---- bb353 @ 0x14006e928 ----
    /* 14006e928 */ rcx = rsi;
    /* 14006e92b */ fn_14006d670();
    /* 14006e930 */ r8 = ((rdi as u32) as u64);
    /* 14006e933 */ r9 = core::ptr::read((rsi).wrapping_add(0xb8_u64) as *const u64);
    /* 14006e93a */ let mut t_14006e93a: u64 = core::ptr::read((rsi).wrapping_add(0xc0_u64) as *const u64);
    /* 14006e941 */ rax = (rax).wrapping_sub(r9);
    /* 14006e944 */ rax = (((rax as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (r14 != rax) {
        /* -> bb364 */
    } else {
        /* -> bb363 */
    }

    // ---- bb363 @ 0x14006e94b ----
    if (r14 != rax) {
        /* -> bb364 */
    } else {
        /* -> bb381 */
    }

    // ---- bb364 @ 0x14006e94d ----
    /* 14006e94d */ rdx = rdi;
    /* fallthrough -> bb365 */

    // ---- bb365 @ 0x14006e950 ----
    /* 14006e950 */ rax = core::ptr::read((r9).wrapping_add((rdx).wrapping_mul(0x1_u64)) as *const u64);
    /* 14006e954 */ let mut t_14006e954: u32 = core::ptr::read((rax).wrapping_add(0x8_u64) as *const u32);
    if (t_14006e954 == 0x1_u32) {
        /* -> bb370 */
    } else {
        /* -> bb369 */
    }

    // ---- bb369 @ 0x14006e958 ----
    if (t_14006e954 == 0x1_u32) {
        /* -> bb370 */
    } else {
        /* -> bb371 */
    }

    // ---- bb370 @ 0x14006e95a ----
    /* 14006e95a */ core::ptr::write((rsi).wrapping_add(0x300_u64) as *mut u64, rax);
    /* fallthrough -> bb371 */

    // ---- bb371 @ 0x14006e961 ----
    /* 14006e961 */ r8 = (((r8 as u32)).wrapping_add(0x1_u32) as u64);
    /* 14006e964 */ rdx = (rdx).wrapping_add(0x8_u64);
    /* 14006e968 */ let mut t_14006e968: u64 = core::ptr::read((rsi).wrapping_add(0xc0_u64) as *const u64);
    /* 14006e96f */ rcx = (rcx).wrapping_sub(r9);
    /* 14006e972 */ rcx = (((rcx as i64) >> ((0x3_u8 as u64) as i64)) as u64);
    if (CF == false) { /* -> bb381 */ }
    if CF { /* -> bb380 */ }

    // ---- bb380 @ 0x14006e97c ----
    if CF { /* -> bb365 */ }
    if (CF == false) { /* -> bb381 */ }

    // ---- bb381 @ 0x14006e97e ----
    /* 14006e97e */ r14 = ((rdi as u32) as u64);
    /* 14006e981 */ rax = (0x26_u32 as u64);
    /* 14006e986 */ r15 = (0x30_u32 as u64);
    /* 14006e98c */ let mut t_14006e98c: u32 = core::ptr::read((0x14006e993_u64).wrapping_add(0x38c85d_u64) as *const u32);
    if (((SF != OF) | (t_14006e98c == 0xa_u32)) == false) { /* -> bb386 */ }
    if (((SF != OF) | (t_14006e98c == 0xa_u32)) != 0) { /* -> bb387 */ }

    // ---- bb387 @ 0x14006e993 ----
    /* 14006e993 */ r15 = ((rax as u32) as u64);
    /* fallthrough -> bb386 */

    // ---- bb386 @ 0x14006e997 ----
    /* 14006e997 */ rbx = rdi;
    /* fallthrough -> bb390 */

    // ---- bb390 @ 0x14006e9a0 ----
    /* 14006e9a0 */ rcx = (rbp).wrapping_add(0x50_u64);
    /* 14006e9a4 */ fn_140075e20();
    /* 14006e9a9 */ let mut t_14006e9a9: u8 = core::ptr::read((rbp).wrapping_add(0x50_u64) as *const u8);
    if (t_14006e9a9 != 0x0_u8) {
        /* -> bb396 */
    } else {
        /* -> bb395 */
    }

    // ---- bb395 @ 0x14006e9ad ----
    if (t_14006e9a9 != 0x0_u8) {
        /* -> bb396 */
    } else {
        /* -> bb408 */
    }

    // ---- bb396 @ 0x14006e9af ----
    /* 14006e9af */ rdx = ((r14 as u32) as u64);
    /* 14006e9b2 */ rcx = rsi;
    /* 14006e9b5 */ fn_1400fe2e0();
    /* 14006e9ba */ let mut t_14006e9ba: u64 = core::ptr::read((rsi).wrapping_add(0x438_u64) as *const u64);
    /* 14006e9c1 */ core::ptr::write((rcx).wrapping_add((rbx).wrapping_mul(0x8_u64)) as *mut u64, rax);
    /* 14006e9c5 */ let mut t_14006e9c5: u64 = core::ptr::read((rsi).wrapping_add(0x438_u64) as *const u64);
    /* 14006e9cc */ rcx = core::ptr::read((rcx).wrapping_add((rbx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14006e9d0 */ fn_14006d670();
    /* 14006e9d5 */ let mut t_14006e9d5: u64 = core::ptr::read((rsi).wrapping_add(0x438_u64) as *const u64);
    /* 14006e9dc */ rcx = core::ptr::read((rax).wrapping_add((rbx).wrapping_mul(0x8_u64)) as *const u64);
    /* 14006e9e0 */ rax = core::ptr::read(rcx as *const u64);
    /* 14006e9e3 */ (/* indirect */ core::ptr::read((rax).wrapping_add(0xb8_u64) as *const u64))();
    /* fallthrough -> bb408 */

    // ---- bb408 @ 0x14006e9e9 ----
    /* 14006e9e9 */ r14 = (((r14 as u32)).wrapping_add(0x1_u32) as u64);
    /* 14006e9ec */ rbx = (rbx).wrapping_add(0x1_u64);
    if (SF == OF) {
        /* -> bb414 */
    } else {
        /* -> bb413 */
    }

    // ---- bb413 @ 0x14006e9f2 ----
    if (SF != OF) {
        /* -> bb390 */
    } else {
        /* -> bb414 */
    }

    // ---- bb414 @ 0x14006e9f4 ----
    /* 14006e9f4 */ let mut t_14006e9f4: u32 = core::ptr::read((0x14006e9fb_u64).wrapping_add(0x38c7f5_u64) as *const u32);
    if (((SF == OF) & (t_14006e9f4 != 0xa_u32)) == false) { /* -> bb418 */ }
    if (((SF == OF) & (t_14006e9f4 != 0xa_u32)) != 0) { /* -> bb417 */ }

    // ---- bb417 @ 0x14006e9fb ----
    if (((SF == OF) & (t_14006e9f4 != 0xa_u32)) == false) { /* -> bb418 */ }
    if (((SF == OF) & (t_14006e9f4 != 0xa_u32)) != 0) { /* -> bb451 */ }

    // ---- bb418 @ 0x14006ea01 ----
    /* 14006ea01 */ rbx = core::ptr::read((rsi).wrapping_add(0x438_u64) as *const u64);
    /* 14006ea08 */ rdx = (0x25_u32 as u64);
    /* 14006ea0d */ rcx = rsi;
    /* 14006ea10 */ fn_1400fe2e0();
    /* 14006ea15 */ core::ptr::write((rbx).wrapping_add(0x128_u64) as *mut u64, rax);
    /* 14006ea1c */ rcx = (0x70_u32 as u64);
    /* 14006ea21 */ fn_1402c745c();
    /* 14006ea26 */ core::ptr::write((rbp).wrapping_add(0x50_u64) as *mut u64, rax);
    if (t_14006e9f4 != 0xa_u32) {
        /* -> bb430 */
    } else {
        /* -> bb429 */
    }

    // ---- bb429 @ 0x14006ea2d ----
    if (t_14006e9f4 != 0xa_u32) {
        /* -> bb430 */
    } else {
        /* -> bb434 */
    }

    // ---- bb430 @ 0x14006ea2f ----
    /* 14006ea2f */ rdx = (0x2_u32 as u64);
    /* 14006ea34 */ rcx = rax;
    /* 14006ea37 */ fn_1400a8600();
    /* 14006ea3c */ rdi = rax;
    /* fallthrough -> bb434 */

    // ---- bb434 @ 0x14006ea3f ----
    /* 14006ea3f */ core::ptr::write((rdi).wrapping_add(0xc_u64) as *mut u32, 0x25_u32);
    /* 14006ea46 */ r9 = (0x7d_u32 as u64);
    /* 14006ea4c */ r8 = (0x84_u32 as u64);
    /* 14006ea52 */ rdx = (rbp).wrapping_add(0x50_u64);
    /* 14006ea56 */ rcx = rsi;
    /* 14006ea59 */ fn_1401016c0();
    /* 14006ea63 */ rcx = core::ptr::read((rsi).wrapping_add(0x438_u64) as *const u64);
    /* 14006ea6a */ rdx = core::ptr::read((rcx).wrapping_add(0x128_u64) as *const u64);
    /* 14006ea71 */ let mut t_14006ea71: u32 = core::ptr::read(rax as *const u32);
    /* 14006ea71 */ rax = (t_14006ea71 as u64);
    /* 14006ea73 */ core::ptr::write((rdx).wrapping_add(0xc_u64) as *mut u32, (rax as u32));
    /* 14006ea7b */ r9 = (0x7d_u32 as u64);
    /* 14006ea81 */ r8 = (0x84_u32 as u64);
    /* 14006ea87 */ rdx = rdi;
    /* 14006ea8a */ rcx = rsi;
    /* 14006ea8d */ fn_140101090();
    /* fallthrough -> bb451 */

    // ---- bb451 @ 0x14006ea92 ----
    /* 14006ea92 */ rcx = core::ptr::read((0x14006ea99_u64).wrapping_add(0x386477_u64) as *const u64);
    /* 14006ea99 */ fn_14006d670();
    /* 14006ea9e */ rcx = core::ptr::read((0x14006eaa5_u64).wrapping_add(0x38646b_u64) as *const u64);
    /* 14006eaa5 */ rax = core::ptr::read(rcx as *const u64);
    /* 14006eaa8 */ (/* indirect */ core::ptr::read((rax).wrapping_add(0xb8_u64) as *const u64))();
    /* 14006eaae */ rcx = rsi;
    /* 14006eab1 */ fn_140104770();
    /* 14006eab6 */ rax = core::ptr::read((rsi).wrapping_add(0x300_u64) as *const u64);
    /* 14006eabd */ let mut t_14006eabd: u8 = core::ptr::read((rax).wrapping_add(0xac_u64) as *const u8);
    if (t_14006eabd != 0x0_u8) {
        /* -> bb463 */
    } else {
        /* -> bb462 */
    }

    // ---- bb462 @ 0x14006eac4 ----
    if (t_14006eabd != 0x0_u8) {
        /* -> bb463 */
    } else {
        /* -> bb495 */
    }

    // ---- bb463 @ 0x14006eaca ----
    /* 14006eaca */ rax = core::ptr::read((rsi).wrapping_add(0x438_u64) as *const u64);
    /* 14006ead1 */ rbx = core::ptr::read((rax).wrapping_add(0x80_u64) as *const u64);
    if (t_14006eabd != 0x0_u8) {
        /* -> bb469 */
    } else {
        /* -> bb468 */
    }

    // ---- bb468 @ 0x14006eadb ----
    if (t_14006eabd != 0x0_u8) {
        /* -> bb469 */
    } else {
        /* -> bb495 */
    }

    // ---- bb469 @ 0x14006eadd ----
    /* 14006eb07 */ rax = core::ptr::read(rbx as *const u64);
    /* 14006eb0a */ rcx = rbx;
    /* 14006eb0d */ (/* indirect */ core::ptr::read((rax).wrapping_add(0x18_u64) as *const u64))();
    if (t_14006eabd != 0x0_u8) {
        /* -> bb482 */
    } else {
        /* -> bb481 */
    }

    // ---- bb481 @ 0x14006eb12 ----
    if (t_14006eabd != 0x0_u8) {
        /* -> bb482 */
    } else {
        /* -> bb485 */
    }

    // ---- bb482 @ 0x14006eb14 ----
    /* 14006eb14 */ core::ptr::write((rsi).wrapping_add(0x25c_u64) as *mut u32, 0x10_u32);
    /* 14006eb1e */ rdx = rbx;
    /* fallthrough -> bb499 */

    // ---- bb485 @ 0x14006eb23 ----
    /* 14006eb23 */ let mut t_14006eb23: u64 = core::ptr::read((rsi).wrapping_add(0x300_u64) as *const u64);
    /* 14006eb2a */ let mut t_14006eb2a: u32 = core::ptr::read((rsi).wrapping_add(0x394_u64) as *const u32);
    /* 14006eb30 */ core::ptr::write((rcx).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    /* 14006eb33 */ let mut t_14006eb33: u64 = core::ptr::read((rsi).wrapping_add(0x300_u64) as *const u64);
    /* 14006eb3a */ let mut t_14006eb3a: u32 = core::ptr::read((rsi).wrapping_add(0x398_u64) as *const u32);
    /* 14006eb40 */ core::ptr::write((rcx).wrapping_add(0x2c_u64) as *mut u32, (rax as u32));
    /* 14006eb43 */ rax = core::ptr::read((rsi).wrapping_add(0x300_u64) as *const u64);
    /* 14006eb4a */ core::ptr::write((rax).wrapping_add(0xac_u64) as *mut u8, 0x0_u8);
    /* 14006eb51 */ let mut t_14006eb51_0: u32 = 0x0_u32;
    /* 14006eb51 */ rdx = (t_14006eb51_0 as u64);
    /* fallthrough -> bb496 */

    // ---- bb495 @ 0x14006eb55 ----
    /* 14006eb55 */ rdx = ((rdx & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* fallthrough -> bb496 */

    // ---- bb496 @ 0x14006eb57 ----
    /* 14006eb57 */ rcx = rsi;
    /* 14006eb5a */ fn_1401045f0();
    /* 14006eb5f */ rdx = rsi;
    /* fallthrough -> bb499 */

    // ---- bb499 @ 0x14006eb62 ----
    /* 14006eb62 */ rcx = core::ptr::read((0x14006eb69_u64).wrapping_add(0x37f4b7_u64) as *const u64);
    /* 14006eb69 */ fn_14009c740();
    /* 14006eb6e */ rax = ((rax & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 14006eb70 */ rbx = core::ptr::read((rsp).wrapping_add(0xb0_u64) as *const u64);
    /* 14006eb78 */ let mut t_14006eb78_0: u64 = (rsp).wrapping_add(0x70_u64);
    /* 14006eb78 */ rsp = t_14006eb78_0;
    /* 14006eb7c */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14006eb7c */ r15 = core::ptr::read(rsp as *const u64);
    /* 14006eb7e */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14006eb7e */ r14 = core::ptr::read(rsp as *const u64);
    /* 14006eb80 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14006eb80 */ let mut r13: u64 = core::ptr::read(rsp as *const u64);
    /* 14006eb82 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14006eb82 */ r12 = core::ptr::read(rsp as *const u64);
    /* 14006eb84 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14006eb84 */ rdi = core::ptr::read(rsp as *const u64);
    /* 14006eb85 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14006eb85 */ let mut rsi: u64 = core::ptr::read(rsp as *const u64);
    /* 14006eb86 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 14006eb86 */ let mut rbp: u64 = core::ptr::read(rsp as *const u64);
    /* 14006eb87 */ return;
    // <no successors>

    // ---- bb512 @ 0x14006eb88 ----
    /* 14006eb88 */ rcx = (0x14006eb8f_u64).wrapping_add(0x37c145_u64);
    /* 14006eb8f */ fn_1402c7548();
    /* 14006eb94 */ let mut t_14006eb94: u32 = core::ptr::read((0x14006eb9b_u64).wrapping_add(0x37c139_u64) as *const u32);
    if (t_14006eb94 == 0xffffffff_u32) {
        /* -> bb518 */
    } else {
        /* -> bb517 */
    }

    // ---- bb517 @ 0x14006eb9b ----
    if (t_14006eb94 != 0xffffffff_u32) {
        /* -> bb187 */
    } else {
        /* -> bb518 */
    }

    // ---- bb518 @ 0x14006eba1 ----
    /* 14006eba4 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm0);
    /* 14006eba8 */ core::ptr::write((rbp).wrapping_sub(0x30_u64) as *mut u64, 0x4_u64);
    /* 14006ebb0 */ core::ptr::write((rbp).wrapping_sub(0x28_u64) as *mut u64, 0xf_u64);
    /* 14006ebb8 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u32, 0x646e6f50_u32);
    /* 14006ebbf */ core::ptr::write((rbp).wrapping_sub(0x3c_u64) as *mut u8, 0x0_u8);
    /* 14006ebc3 */ rcx = (rbp).wrapping_sub(0x40_u64);
    /* 14006ebc7 */ fn_14006fd40();
    /* 14006ebcc */ core::ptr::write((0x14006ebd2_u64).wrapping_add(0x37c0fe_u64) as *mut u32, (rax as u32));
    /* 14006ebd2 */ rcx = (0x14006ebd9_u64).wrapping_add(0x37c0fb_u64);
    /* 14006ebd9 */ fn_1402c74dc();
    /* fallthrough -> bb187 */

    // ---- bb530 @ 0x14006ec11 ----
    /* 14006ec11 */ rcx = (0x14006ec18_u64).wrapping_add(0x37c0ac_u64);
    /* 14006ec18 */ fn_1402c7548();
    /* 14006ec1d */ let mut t_14006ec1d: u32 = core::ptr::read((0x14006ec24_u64).wrapping_add(0x37c0a0_u64) as *const u32);
    if (t_14006ec1d == 0xffffffff_u32) {
        /* -> bb536 */
    } else {
        /* -> bb535 */
    }

    // ---- bb535 @ 0x14006ec24 ----
    if (t_14006ec1d != 0xffffffff_u32) {
        /* -> bb177 */
    } else {
        /* -> bb536 */
    }

    // ---- bb536 @ 0x14006ec2a ----
    /* 14006ec2d */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm0);
    /* 14006ec31 */ core::ptr::write((rbp).wrapping_sub(0x30_u64) as *mut u64, 0x5_u64);
    /* 14006ec39 */ core::ptr::write((rbp).wrapping_sub(0x28_u64) as *mut u64, 0xf_u64);
    /* 14006ec41 */ let mut t_14006ec41: u32 = core::ptr::read((0x14006ec47_u64).wrapping_add(0x29b60d_u64) as *const u32);
    /* 14006ec47 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u32, (rax as u32));
    /* 14006ec4a */ let mut t_14006ec4a: u8 = core::ptr::read((0x14006ec51_u64).wrapping_add(0x29b607_u64) as *const u8);
    /* 14006ec4a */ rax = ((t_14006ec4a as u32) as u64);
    /* 14006ec51 */ core::ptr::write((rbp).wrapping_sub(0x3c_u64) as *mut u8, (rax as u8));
    /* 14006ec54 */ core::ptr::write((rbp).wrapping_sub(0x3b_u64) as *mut u8, 0x0_u8);
    /* 14006ec58 */ rcx = (rbp).wrapping_sub(0x40_u64);
    /* 14006ec5c */ fn_14006fd40();
    /* 14006ec61 */ core::ptr::write((0x14006ec67_u64).wrapping_add(0x37c059_u64) as *mut u32, (rax as u32));
    /* 14006ec67 */ rcx = (0x14006ec6e_u64).wrapping_add(0x37c056_u64);
    /* 14006ec6e */ fn_1402c74dc();
    /* fallthrough -> bb177 */

    // ---- bb551 @ 0x14006ec78 ----
    /* 14006ec78 */ rcx = (0x14006ec7f_u64).wrapping_add(0x37c04d_u64);
    /* 14006ec7f */ fn_1402c7548();
    /* 14006ec84 */ let mut t_14006ec84: u32 = core::ptr::read((0x14006ec8b_u64).wrapping_add(0x37c041_u64) as *const u32);
    if (t_14006ec84 == 0xffffffff_u32) {
        /* -> bb557 */
    } else {
        /* -> bb556 */
    }

    // ---- bb556 @ 0x14006ec8b ----
    if (t_14006ec84 != 0xffffffff_u32) {
        /* -> bb182 */
    } else {
        /* -> bb557 */
    }

    // ---- bb557 @ 0x14006ec91 ----
    /* 14006ec94 */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u128, xmm0);
    /* 14006ec98 */ core::ptr::write((rbp).wrapping_sub(0x30_u64) as *mut u64, 0x5_u64);
    /* 14006eca0 */ core::ptr::write((rbp).wrapping_sub(0x28_u64) as *mut u64, 0xf_u64);
    /* 14006eca8 */ let mut t_14006eca8: u32 = core::ptr::read((0x14006ecae_u64).wrapping_add(0x29b5ae_u64) as *const u32);
    /* 14006ecae */ core::ptr::write((rbp).wrapping_sub(0x40_u64) as *mut u32, (rax as u32));
    /* 14006ecb1 */ let mut t_14006ecb1: u8 = core::ptr::read((0x14006ecb8_u64).wrapping_add(0x29b5a8_u64) as *const u8);
    /* 14006ecb1 */ rax = ((t_14006ecb1 as u32) as u64);
    /* 14006ecb8 */ core::ptr::write((rbp).wrapping_sub(0x3c_u64) as *mut u8, (rax as u8));
    /* 14006ecbb */ core::ptr::write((rbp).wrapping_sub(0x3b_u64) as *mut u8, 0x0_u8);
    /* 14006ecbf */ rcx = (rbp).wrapping_sub(0x40_u64);
    /* 14006ecc3 */ fn_14006fd40();
    /* 14006ecc8 */ core::ptr::write((0x14006ecce_u64).wrapping_add(0x37bffa_u64) as *mut u32, (rax as u32));
    /* 14006ecce */ rcx = (0x14006ecd5_u64).wrapping_add(0x37bff7_u64);
    /* 14006ecd5 */ fn_1402c74dc();
    /* fallthrough -> bb182 */
}
