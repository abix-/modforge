// Decompiled from Horsey.exe @ 0x140066200
// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print
// blocks: 217

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]
pub unsafe fn simulation_paused_status() {

    // ---- bb0 @ 0x140066200 ----
    /* 140066200 */ let mut t_140066200_0: u32 = ((rax as u32)).wrapping_add(0x2a54cf_u32);
    /* 140066205 */ let mut t_140066205: u32 = core::ptr::read((0x14006620b_u64).wrapping_add(0x3877f9_u64) as *const u32);
    /* 140066205 */ let mut rdx: u64 = (t_140066205 as u64);
    /* 14006620b */ let mut rax: u64 = (((rax).wrapping_add((rdx).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 14006620e */ let mut xmm3: u128 = ((rax as u32) as u128);
    /* 140066215 */ let mut t_140066215: u32 = core::ptr::read((0x14006621b_u64).wrapping_add(0x2a54b5_u64) as *const u32);
    /* 14006621b */ let mut t_14006621b: u32 = core::ptr::read((0x140066221_u64).wrapping_add(0x3877df_u64) as *const u32);
    /* 14006621b */ let mut rcx: u64 = (t_14006621b as u64);
    /* 140066221 */ rax = (((rax).wrapping_add((rcx).wrapping_mul(0x2_u64)) as u32) as u64);
    /* 140066224 */ let mut xmm2: u128 = ((rax as u32) as u128);
    /* 14006622b */ let mut t_14006622b_0: u32 = (0x0_u32).wrapping_sub((rdx as u32));
    /* 14006622b */ rdx = (t_14006622b_0 as u64);
    /* 14006622d */ let mut xmm1: u128 = ((rdx as u32) as u128);
    /* 140066234 */ let mut t_140066234_0: u32 = (0x0_u32).wrapping_sub((rcx as u32));
    /* 140066234 */ rcx = (t_140066234_0 as u64);
    /* 140066236 */ let mut xmm0: u128 = ((rcx as u32) as u128);
    /* 14006623d */ let mut t_14006623d: u32 = core::ptr::read((rbp).wrapping_add(0x67_u64) as *const u32);
    /* 14006623d */ rax = (t_14006623d as u64);
    /* 140066240 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 140066244 */ fn_140070fb0();
    /* 140066249 */ xmm1 = xmm6;
    /* 140066254 */ fn_140072e90();
    /* 140066259 */ let mut t_140066259: u32 = core::ptr::read((0x14006625f_u64).wrapping_add(0x370119_u64) as *const u32);
    /* 140066259 */ rax = (t_140066259 as u64);
    /* 14006625f */ xmm3 = xmm7;
    /* 140066265 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 140066269 */ let mut t_140066269: u8 = core::ptr::read((rdi).wrapping_add(0x260_u64) as *const u8);
    if (t_140066269 != (r12 as u8)) {
        /* -> bb30 */
    } else {
        /* -> bb29 */
    }

    // ---- bb29 @ 0x140066270 ----
    if (t_140066269 != (r12 as u8)) {
        /* -> bb30 */
    } else {
        /* -> bb33 */
    }

    // ---- bb30 @ 0x140066272 ----
    /* fallthrough -> bb35 */

    // ---- bb33 @ 0x140066284 ----
    /* 140066284 */ xmm2 = xmm9;
    /* fallthrough -> bb35 */

    // ---- bb35 @ 0x14006628b ----
    /* 14006628b */ fn_140070fb0();
    /* 140066290 */ let mut t_140066290: u32 = core::ptr::read((0x140066296_u64).wrapping_add(0x39849a_u64) as *const u32);
    /* 140066290 */ rcx = (t_140066290 as u64);
    /* 140066296 */ let mut t_140066296: u64 = core::ptr::read((gs_base).wrapping_add(0x58_u64) as *const u64);
    /* 14006629f */ let mut rsi: u64 = (0x4_u32 as u64);
    /* 1400662a4 */ let mut rbx: u64 = core::ptr::read((rax).wrapping_add((rcx).wrapping_mul(0x8_u64)) as *const u64);
    /* 1400662a8 */ let mut t_1400662a8: u32 = core::ptr::read((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u32);
    /* 1400662a8 */ rax = (t_1400662a8 as u64);
    /* 1400662ab */ let mut t_1400662ab: u32 = core::ptr::read((0x1400662b1_u64).wrapping_add(0x384853_u64) as *const u32);
    if (((SF == OF) & (t_1400662ab != (rax as u32))) == false) { /* -> bb45 */ }
    if (((SF == OF) & (t_1400662ab != (rax as u32))) != 0) { /* -> bb44 */ }

    // ---- bb44 @ 0x1400662b1 ----
    if (((SF == OF) & (t_1400662ab != (rax as u32))) == false) { /* -> bb45 */ }
    if (((SF == OF) & (t_1400662ab != (rax as u32))) != 0) { /* -> bb859 */ }

    // ---- bb45 @ 0x1400662b7 ----
    /* 1400662c6 */ xmm3 = xmm6;
    /* 1400662d2 */ xmm2 = xmm9;
    /* 1400662de */ let mut t_1400662de: u32 = core::ptr::read((0x1400662e4_u64).wrapping_add(0x38481c_u64) as *const u32);
    /* 1400662de */ rcx = (t_1400662de as u64);
    /* 1400662e4 */ fn_140071e80();
    /* 1400662e9 */ let mut t_1400662e9: u32 = core::ptr::read((0x1400662ef_u64).wrapping_add(0x384811_u64) as *const u32);
    /* 1400662e9 */ rcx = (t_1400662e9 as u64);
    /* 1400662ef */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    /* 1400662f8 */ xmm3 = xmm6;
    /* 1400662fb */ xmm2 = xmm9;
    /* 140066307 */ fn_140071e80();
    /* 14006630c */ let mut t_14006630c: u8 = core::ptr::read((rdi).wrapping_add(0x260_u64) as *const u8);
    if (t_14006630c != 0x0_u8) {
        /* -> bb64 */
    } else {
        /* -> bb63 */
    }

    // ---- bb63 @ 0x140066313 ----
    if (t_14006630c != 0x0_u8) {
        /* -> bb64 */
    } else {
        /* -> bb111 */
    }

    // ---- bb64 @ 0x140066319 ----
    /* 140066319 */ let mut t_140066319: u32 = core::ptr::read((rbx).wrapping_add((rsi).wrapping_mul(0x1_u64)) as *const u32);
    /* 140066319 */ rax = (t_140066319 as u64);
    /* 14006631c */ let mut t_14006631c: u32 = core::ptr::read((0x140066322_u64).wrapping_add(0x3847ea_u64) as *const u32);
    if (((SF == OF) & (t_14006631c != (rax as u32))) == false) { /* -> bb69 */ }
    if (((SF == OF) & (t_14006631c != (rax as u32))) != 0) { /* -> bb68 */ }

    // ---- bb68 @ 0x140066322 ----
    if (((SF == OF) & (t_14006631c != (rax as u32))) == false) { /* -> bb69 */ }
    if (((SF == OF) & (t_14006631c != (rax as u32))) != 0) { /* -> bb886 */ }

    // ---- bb69 @ 0x140066328 ----
    /* 140066328 */ xmm2 = xmm7;
    /* 14006634a */ let mut t_14006634a: u32 = core::ptr::read((0x140066350_u64).wrapping_add(0x3847b8_u64) as *const u32);
    /* 14006634a */ rcx = (t_14006634a as u64);
    /* 140066350 */ fn_140071e80();
    /* 140066355 */ let mut t_140066355: u32 = core::ptr::read((0x14006635c_u64).wrapping_add(0x38760c_u64) as *const u32);
    if (t_140066355 != 0x0_u32) {
        /* -> bb80 */
    } else {
        /* -> bb79 */
    }

    // ---- bb79 @ 0x14006635c ----
    if (t_140066355 != 0x0_u32) {
        /* -> bb80 */
    } else {
        /* -> bb81 */
    }

    // ---- bb80 @ 0x14006635e ----
    /* 14006635e */ core::ptr::write((rdi).wrapping_add(0x260_u64) as *mut u8, 0x0_u8);
    /* fallthrough -> bb81 */

    // ---- bb81 @ 0x140066365 ----
    /* 140066365 */ xmm2 = xmm7;
    /* 140066370 */ let mut t_140066370: u64 = core::ptr::read((0x140066377_u64).wrapping_add(0x373079_u64) as *const u64);
    /* 140066377 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 14006637c */ let mut t_14006637c: u32 = core::ptr::read((0x140066382_u64).wrapping_add(0x36ffc2_u64) as *const u32);
    /* 14006637c */ rax = (t_14006637c as u64);
    /* 140066382 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    /* 140066394 */ let mut r9: u64 = (0x2_u32 as u64);
    /* 1400663a3 */ xmm1 = xmm8;
    /* 1400663a7 */ rcx = core::ptr::read((0x1400663ae_u64).wrapping_add(0x387a62_u64) as *const u64);
    /* 1400663ae */ fn_14009e2b0();
    /* 1400663b3 */ let mut t_1400663b3: u8 = core::ptr::read((0x1400663ba_u64).wrapping_add(0x38cf9c_u64) as *const u8);
    if (t_1400663b3 != 0x0_u8) {
        /* -> bb98 */
    } else {
        /* -> bb97 */
    }

    // ---- bb97 @ 0x1400663ba ----
    if (t_1400663b3 != 0x0_u8) {
        /* -> bb98 */
    } else {
        /* -> bb109 */
    }

    // ---- bb98 @ 0x1400663bc ----
    /* 1400663cb */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 1400663d0 */ let mut t_1400663d0: u32 = core::ptr::read((0x1400663d6_u64).wrapping_add(0x36ff6e_u64) as *const u32);
    /* 1400663d0 */ rax = (t_1400663d0 as u64);
    /* 1400663d6 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    /* 1400663e0 */ r9 = (0x2_u32 as u64);
    /* 1400663e6 */ xmm2 = xmm7;
    /* 1400663e9 */ xmm1 = xmm8;
    /* 1400663ed */ rcx = core::ptr::read((0x1400663f4_u64).wrapping_add(0x387a1c_u64) as *const u64);
    /* 1400663f4 */ fn_14009e2b0();
    /* fallthrough -> bb109 */

    // ---- bb109 @ 0x1400663f9 ----
    /* 1400663f9 */ fn_1400730b0();
    /* fallthrough -> bb831 */

    // ---- bb111 @ 0x140066403 ----
    /* 140066403 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x41900000_u32);
    /* 14006640a */ xmm0 = xmm7;
    /* 14006641a */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u32, 0x42a80000_u32);
    /* 140066421 */ core::ptr::write((rbp).wrapping_sub(0x3d_u64) as *mut u32, 0x41800000_u32);
    /* 140066428 */ let mut t_140066428: u32 = core::ptr::read((0x14006642f_u64).wrapping_add(0x36ff11_u64) as *const u32);
    /* 140066428 */ r9 = (t_140066428 as u64);
    /* 14006642f */ let mut r8: u64 = (0x140066436_u64).wrapping_add(0x2a1a42_u64);
    /* 140066436 */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 14006643a */ rcx = rdi;
    /* 14006643d */ fn_1400671f0();
    if (t_14006630c == 0x0_u8) {
        /* -> bb126 */
    } else {
        /* -> bb125 */
    }

    // ---- bb125 @ 0x140066444 ----
    if (t_14006630c == 0x0_u8) {
        /* -> bb126 */
    } else {
        /* -> bb130 */
    }

    // ---- bb126 @ 0x140066446 ----
    /* 140066446 */ let mut t_140066446: u8 = core::ptr::read((0x14006644c_u64).wrapping_add(0x38732e_u64) as *const u8);
    if (t_140066446 != (rax as u8)) {
        /* -> bb130 */
    } else {
        /* -> bb129 */
    }

    // ---- bb129 @ 0x14006644c ----
    if (t_140066446 != (rax as u8)) {
        /* -> bb130 */
    } else {
        /* -> bb133 */
    }

    // ---- bb130 @ 0x14006644e ----
    /* 14006644e */ let mut t_14006644e_0: u32 = 0x0_u32;
    /* 14006644e */ rdx = (t_14006644e_0 as u64);
    /* 140066450 */ rcx = core::ptr::read((0x140066457_u64).wrapping_add(0x387bc9_u64) as *const u64);
    /* 140066457 */ fn_14009c760();
    /* fallthrough -> bb133 */

    // ---- bb133 @ 0x14006645c ----
    /* 140066464 */ let mut t_140066464: u8 = core::ptr::read((rdi).wrapping_add(0x262_u64) as *const u8);
    if (t_140066464 == 0x0_u8) {
        /* -> bb138 */
    } else {
        /* -> bb137 */
    }

    // ---- bb137 @ 0x14006646b ----
    if (t_140066464 == 0x0_u8) {
        /* -> bb138 */
    } else {
        /* -> bb232 */
    }

    // ---- bb138 @ 0x140066471 ----
    /* 140066471 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x41900000_u32);
    /* 140066478 */ xmm0 = xmm7;
    /* 140066484 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u32, 0x42a80000_u32);
    /* 14006648b */ core::ptr::write((rbp).wrapping_sub(0x3d_u64) as *mut u32, 0x41800000_u32);
    /* 140066492 */ let mut t_140066492: u32 = core::ptr::read((0x140066499_u64).wrapping_add(0x36fea7_u64) as *const u32);
    /* 140066492 */ r9 = (t_140066492 as u64);
    /* 140066499 */ r8 = (0x1400664a0_u64).wrapping_add(0x2a19e8_u64);
    /* 1400664a0 */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 1400664a4 */ rcx = rdi;
    /* 1400664a7 */ fn_1400671f0();
    if (t_140066464 != 0x0_u8) {
        /* -> bb153 */
    } else {
        /* -> bb152 */
    }

    // ---- bb152 @ 0x1400664ae ----
    if (t_140066464 != 0x0_u8) {
        /* -> bb153 */
    } else {
        /* -> bb232 */
    }

    // ---- bb153 @ 0x1400664b4 ----
    /* 1400664b4 */ core::ptr::write((rdi).wrapping_add(0x262_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb154 */

    // ---- bb154 @ 0x1400664bb ----
    /* 1400664bb */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x41900000_u32);
    /* 1400664c2 */ xmm0 = xmm7;
    /* 1400664d2 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u32, 0x42a80000_u32);
    /* 1400664d9 */ core::ptr::write((rbp).wrapping_sub(0x3d_u64) as *mut u32, 0x41800000_u32);
    /* 1400664e0 */ let mut t_1400664e0: u32 = core::ptr::read((0x1400664e7_u64).wrapping_add(0x36fe59_u64) as *const u32);
    /* 1400664e0 */ r9 = (t_1400664e0 as u64);
    /* 1400664e7 */ r8 = (0x1400664ee_u64).wrapping_add(0x2a19c2_u64);
    /* 1400664ee */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 1400664f2 */ rcx = rdi;
    /* 1400664f5 */ fn_1400671f0();
    if (t_140066632 != 0x0_u8) {
        /* -> bb169 */
    } else {
        /* -> bb168 */
    }

    // ---- bb168 @ 0x1400664fc ----
    if (t_140066632 != 0x0_u8) {
        /* -> bb169 */
    } else {
        /* -> bb170 */
    }

    // ---- bb169 @ 0x1400664fe ----
    /* 1400664fe */ core::ptr::write((rdi).wrapping_add(0x260_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb170 */

    // ---- bb170 @ 0x140066505 ----
    /* 140066505 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x41900000_u32);
    /* 140066519 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u32, 0x42a80000_u32);
    /* 140066520 */ core::ptr::write((rbp).wrapping_sub(0x3d_u64) as *mut u32, 0x41800000_u32);
    /* 140066527 */ rax = core::ptr::read((0x14006652e_u64).wrapping_add(0x394cba_u64) as *const u64);
    /* 14006652e */ rcx = (0x140066535_u64).wrapping_add(0x2a198b_u64);
    /* 140066535 */ r8 = (0x14006653c_u64).wrapping_add(0x2a1994_u64);
    /* 14006653c */ let mut t_14006653c: u32 = core::ptr::read((rax).wrapping_add(0x25c_u64) as *const u32);
    if (t_14006653c != 0xffffffff_u32) {
        /* -> bb180 */
    } else {
        /* -> bb181 */
    }

    // ---- bb181 @ 0x140066543 ----
    /* 140066543 */ r8 = rcx;
    /* fallthrough -> bb180 */

    // ---- bb180 @ 0x140066547 ----
    /* 140066547 */ let mut t_140066547: u32 = core::ptr::read((0x14006654e_u64).wrapping_add(0x36fdf2_u64) as *const u32);
    /* 140066547 */ r9 = (t_140066547 as u64);
    /* 14006654e */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066552 */ rcx = rdi;
    /* 140066555 */ fn_1400671f0();
    if (t_14006653c != 0xffffffff_u32) {
        /* -> bb190 */
    } else {
        /* -> bb189 */
    }

    // ---- bb189 @ 0x14006655c ----
    if (t_14006653c != 0xffffffff_u32) {
        /* -> bb190 */
    } else {
        /* -> bb191 */
    }

    // ---- bb190 @ 0x14006655e ----
    /* 14006655e */ fn_1400c4640();
    /* fallthrough -> bb191 */

    // ---- bb191 @ 0x140066563 ----
    /* 140066563 */ let mut t_140066563: u8 = core::ptr::read((0x14006656a_u64).wrapping_add(0x373011_u64) as *const u8);
    if (t_140066563 != 0x0_u8) {
        /* -> bb195 */
    } else {
        /* -> bb194 */
    }

    // ---- bb194 @ 0x14006656a ----
    if (t_140066563 != 0x0_u8) {
        /* -> bb195 */
    } else {
        /* -> bb494 */
    }

    // ---- bb195 @ 0x140066570 ----
    /* 140066570 */ xmm0 = core::ptr::read((0x140066578_u64).wrapping_add(0x2a1a58_u64) as *const u128);
    /* 140066578 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 14006657c */ r8 = (0x140066583_u64).wrapping_add(0x2a195d_u64);
    /* 140066583 */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066587 */ rcx = rdi;
    /* 14006658a */ fn_140067350();
    if (t_140066563 != 0x0_u8) {
        /* -> bb205 */
    } else {
        /* -> bb204 */
    }

    // ---- bb204 @ 0x140066591 ----
    if (t_140066563 != 0x0_u8) {
        /* -> bb205 */
    } else {
        /* -> bb303 */
    }

    // ---- bb205 @ 0x140066597 ----
    /* 14006659a */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 14006659e */ xmm1 = core::ptr::read((0x1400665a6_u64).wrapping_add(0x29f0da_u64) as *const u128);
    /* 1400665a6 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm1);
    /* 1400665ab */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x676e6f47_u32);
    /* 1400665b2 */ core::ptr::write((rbp).wrapping_sub(0x45_u64) as *mut u8, 0x0_u8);
    /* 1400665b6 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400665c3 */ let mut t_1400665c3_0: u32 = 0x0_u32;
    /* 1400665c3 */ r8 = (t_1400665c3_0 as u64);
    /* 1400665c6 */ rdx = (0x64_u32 as u64);
    /* 1400665cb */ rcx = (rbp).wrapping_sub(0x49_u64);
    /* 1400665cf */ fn_140040b90();
    /* 1400665d5 */ rcx = (rbp).wrapping_sub(0x49_u64);
    /* 1400665d9 */ fn_140027900();
    /* 1400665de */ core::ptr::write((0x1400665e5_u64).wrapping_add(0x372f94_u64) as *mut u8, 0x0_u8);
    /* 1400665e5 */ rdx = (0x1400665ec_u64).wrapping_add(0x2a0d5c_u64);
    /* 1400665ec */ rcx = (0x1400665f3_u64).wrapping_add(0x372f5d_u64);
    /* 1400665f3 */ fn_1400278e0();
    /* 1400665f8 */ core::ptr::write((0x1400665ff_u64).wrapping_add(0x372f7b_u64) as *mut u8, 0x1_u8);
    /* fallthrough -> bb225 */

    // ---- bb225 @ 0x1400665ff ----
    /* 1400665ff */ core::ptr::write((0x140066609_u64).wrapping_add(0x372f67_u64) as *mut u32, 0x3e8_u32);
    /* fallthrough -> bb226 */

    // ---- bb226 @ 0x140066609 ----
    /* 140066609 */ core::ptr::write((0x140066610_u64).wrapping_add(0x372ef2_u64) as *mut u8, 0x0_u8);
    /* 140066610 */ fn_1400730b0();
    /* 140066615 */ rdx = (0xffffffff_u32 as u64);
    /* 14006661a */ rcx = core::ptr::read((0x140066621_u64).wrapping_add(0x3879ff_u64) as *const u64);
    /* 140066621 */ fn_14009c660();
    /* fallthrough -> bb831 */

    // ---- bb232 @ 0x14006662b ----
    /* 14006662b */ rbx = (rdi).wrapping_add(0x262_u64);
    /* 140066632 */ let mut t_140066632: u8 = core::ptr::read((rdi).wrapping_add(0x262_u64) as *const u8);
    if (t_140066632 != 0x0_u8) {
        /* -> bb237 */
    } else {
        /* -> bb236 */
    }

    // ---- bb236 @ 0x140066639 ----
    if (t_140066632 == 0x0_u8) {
        /* -> bb154 */
    } else {
        /* -> bb237 */
    }

    // ---- bb237 @ 0x14006663f ----
    /* 14006663f */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x41900000_u32);
    /* 140066646 */ xmm0 = xmm7;
    /* 140066652 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u32, 0x42a80000_u32);
    /* 140066659 */ core::ptr::write((rbp).wrapping_sub(0x3d_u64) as *mut u32, 0x41800000_u32);
    /* 140066660 */ let mut t_140066660: u32 = core::ptr::read((0x140066667_u64).wrapping_add(0x36fd0d_u64) as *const u32);
    /* 140066660 */ r9 = (t_140066660 as u64);
    /* 140066667 */ r8 = (0x14006666e_u64).wrapping_add(0x2a182a_u64);
    /* 14006666e */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066672 */ rcx = rdi;
    /* 140066675 */ fn_1400671f0();
    if (t_140066632 != 0x0_u8) {
        /* -> bb252 */
    } else {
        /* -> bb251 */
    }

    // ---- bb251 @ 0x14006667c ----
    if (t_140066632 == 0x0_u8) {
        /* -> bb154 */
    } else {
        /* -> bb252 */
    }

    // ---- bb252 @ 0x140066682 ----
    /* 140066685 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 140066689 */ xmm1 = core::ptr::read((0x140066691_u64).wrapping_add(0x29efef_u64) as *const u128);
    /* 140066691 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm1);
    /* 140066696 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x676e6f47_u32);
    /* 14006669d */ core::ptr::write((rbp).wrapping_sub(0x45_u64) as *mut u8, 0x0_u8);
    /* 1400666a1 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400666ae */ let mut t_1400666ae_0: u32 = 0x0_u32;
    /* 1400666ae */ r8 = (t_1400666ae_0 as u64);
    /* 1400666b1 */ rdx = (0x64_u32 as u64);
    /* 1400666b6 */ rcx = (rbp).wrapping_sub(0x49_u64);
    /* 1400666ba */ fn_140040b90();
    /* 1400666c0 */ rdx = core::ptr::read((rbp).wrapping_sub(0x31_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb270 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb269 */ }

    // ---- bb269 @ 0x1400666c8 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb270 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb287 */ }

    // ---- bb270 @ 0x1400666ca ----
    /* 1400666ca */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400666cd */ rcx = core::ptr::read((rbp).wrapping_sub(0x49_u64) as *const u64);
    /* 1400666d1 */ rax = rcx;
    if (CF == false) { /* -> bb277 */ }
    if CF { /* -> bb276 */ }

    // ---- bb276 @ 0x1400666db ----
    if (CF == false) { /* -> bb277 */ }
    if CF { /* -> bb286 */ }

    // ---- bb277 @ 0x1400666dd ----
    /* 1400666dd */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 1400666e1 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400666e5 */ rax = (rax).wrapping_sub(rcx);
    /* 1400666e8 */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb285 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb284 */ }

    // ---- bb284 @ 0x1400666f0 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb285 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb904 */ }

    // ---- bb285 @ 0x1400666f6 ----
    /* 1400666f6 */ rbx = (rdi).wrapping_add(0x262_u64);
    /* fallthrough -> bb286 */

    // ---- bb286 @ 0x1400666fd ----
    /* 1400666fd */ fn_1402c7498();
    /* fallthrough -> bb287 */

    // ---- bb287 @ 0x140066702 ----
    /* 140066702 */ core::ptr::write(rbx as *mut u8, 0x0_u8);
    /* 140066705 */ core::ptr::write((0x14006670c_u64).wrapping_add(0x372e68_u64) as *mut u32, (r12 as u32));
    /* 14006670c */ core::ptr::write((0x140066713_u64).wrapping_add(0x372e66_u64) as *mut u8, 0x1_u8);
    /* 140066713 */ rdx = (0x14006671a_u64).wrapping_add(0x2a178e_u64);
    /* 14006671a */ rcx = (0x140066721_u64).wrapping_add(0x372e2f_u64);
    /* 140066721 */ fn_1400278e0();
    /* 140066726 */ core::ptr::write((0x140066730_u64).wrapping_add(0x372e40_u64) as *mut u32, 0x64_u32);
    /* 140066730 */ core::ptr::write((0x140066737_u64).wrapping_add(0x372e41_u64) as *mut u8, 0x0_u8);
    /* 140066737 */ rdx = (0x14006673e_u64).wrapping_add(0x3357db_u64);
    /* 14006673e */ rcx = (0x140066745_u64).wrapping_add(0x372dcb_u64);
    /* 140066745 */ fn_1400278e0();
    /* 14006674a */ rdx = (0xffffffff_u32 as u64);
    /* 14006674f */ rcx = core::ptr::read((0x140066756_u64).wrapping_add(0x3878ca_u64) as *const u64);
    /* 140066756 */ fn_14009c660();
    /* 14006675b */ fn_1400730b0();
    /* fallthrough -> bb831 */

    // ---- bb303 @ 0x140066765 ----
    /* 140066765 */ xmm0 = core::ptr::read((0x14006676d_u64).wrapping_add(0x2a1873_u64) as *const u128);
    /* 14006676d */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 140066771 */ r8 = (0x140066778_u64).wrapping_add(0x2a1778_u64);
    /* 140066778 */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 14006677c */ rcx = rdi;
    /* 14006677f */ fn_140067350();
    if (t_140066563 != 0x0_u8) {
        /* -> bb313 */
    } else {
        /* -> bb312 */
    }

    // ---- bb312 @ 0x140066786 ----
    if (t_140066563 != 0x0_u8) {
        /* -> bb313 */
    } else {
        /* -> bb355 */
    }

    // ---- bb313 @ 0x14006678c ----
    /* 14006678f */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 140066793 */ xmm1 = core::ptr::read((0x14006679b_u64).wrapping_add(0x29eee5_u64) as *const u128);
    /* 14006679b */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm1);
    /* 1400667a0 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x676e6f47_u32);
    /* 1400667a7 */ core::ptr::write((rbp).wrapping_sub(0x45_u64) as *mut u8, 0x0_u8);
    /* 1400667ab */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 1400667b8 */ let mut t_1400667b8_0: u32 = 0x0_u32;
    /* 1400667b8 */ r8 = (t_1400667b8_0 as u64);
    /* 1400667bb */ rdx = (0x64_u32 as u64);
    /* 1400667c0 */ rcx = (rbp).wrapping_sub(0x49_u64);
    /* 1400667c4 */ fn_140040b90();
    /* 1400667ca */ rdx = core::ptr::read((rbp).wrapping_sub(0x31_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb331 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb330 */ }

    // ---- bb330 @ 0x1400667d2 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb331 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb347 */ }

    // ---- bb331 @ 0x1400667d4 ----
    /* 1400667d4 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400667d7 */ rcx = core::ptr::read((rbp).wrapping_sub(0x49_u64) as *const u64);
    /* 1400667db */ rax = rcx;
    if (CF == false) { /* -> bb338 */ }
    if CF { /* -> bb337 */ }

    // ---- bb337 @ 0x1400667e5 ----
    if (CF == false) { /* -> bb338 */ }
    if CF { /* -> bb346 */ }

    // ---- bb338 @ 0x1400667e7 ----
    /* 1400667e7 */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 1400667eb */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400667ef */ rax = (rax).wrapping_sub(rcx);
    /* 1400667f2 */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb346 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb345 */ }

    // ---- bb345 @ 0x1400667fa ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb346 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb911 */ }

    // ---- bb346 @ 0x140066800 ----
    /* 140066800 */ fn_1402c7498();
    /* fallthrough -> bb347 */

    // ---- bb347 @ 0x140066805 ----
    /* 140066805 */ core::ptr::write((0x14006680f_u64).wrapping_add(0x372d65_u64) as *mut u32, 0x3_u32);
    /* 14006680f */ core::ptr::write((0x140066816_u64).wrapping_add(0x372d63_u64) as *mut u8, 0x0_u8);
    /* 140066816 */ rdx = (0x14006681d_u64).wrapping_add(0x3356fc_u64);
    /* 14006681d */ rcx = (0x140066824_u64).wrapping_add(0x372d2c_u64);
    /* 140066824 */ fn_1400278e0();
    /* 140066829 */ core::ptr::write((0x140066830_u64).wrapping_add(0x372d48_u64) as *mut u8, 0x1_u8);
    /* 140066830 */ core::ptr::write((0x140066837_u64).wrapping_add(0x372d43_u64) as *mut u8, 0x0_u8);
    /* fallthrough -> bb225 */

    // ---- bb355 @ 0x14006683c ----
    /* 14006683c */ xmm0 = core::ptr::read((0x140066844_u64).wrapping_add(0x2a17ac_u64) as *const u128);
    /* 140066844 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 140066848 */ r8 = (0x14006684f_u64).wrapping_add(0x29ca19_u64);
    /* 14006684f */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066853 */ rcx = rdi;
    /* 140066856 */ fn_140067350();
    if (t_140066563 != 0x0_u8) {
        /* -> bb365 */
    } else {
        /* -> bb364 */
    }

    // ---- bb364 @ 0x14006685d ----
    if (t_140066563 != 0x0_u8) {
        /* -> bb365 */
    } else {
        /* -> bb405 */
    }

    // ---- bb365 @ 0x140066863 ----
    /* 140066866 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 14006686a */ xmm1 = core::ptr::read((0x140066872_u64).wrapping_add(0x29ee0e_u64) as *const u128);
    /* 140066872 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u128, xmm1);
    /* 140066877 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x676e6f47_u32);
    /* 14006687e */ core::ptr::write((rbp).wrapping_sub(0x45_u64) as *mut u8, 0x0_u8);
    /* 140066882 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u8, 0x0_u8);
    /* 14006688f */ let mut t_14006688f_0: u32 = 0x0_u32;
    /* 14006688f */ r8 = (t_14006688f_0 as u64);
    /* 140066892 */ rdx = (0x64_u32 as u64);
    /* 140066897 */ rcx = (rbp).wrapping_sub(0x49_u64);
    /* 14006689b */ fn_140040b90();
    /* 1400668a1 */ rdx = core::ptr::read((rbp).wrapping_sub(0x31_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb383 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb382 */ }

    // ---- bb382 @ 0x1400668a9 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb383 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb399 */ }

    // ---- bb383 @ 0x1400668ab ----
    /* 1400668ab */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 1400668ae */ rcx = core::ptr::read((rbp).wrapping_sub(0x49_u64) as *const u64);
    /* 1400668b2 */ rax = rcx;
    if (CF == false) { /* -> bb390 */ }
    if CF { /* -> bb389 */ }

    // ---- bb389 @ 0x1400668bc ----
    if (CF == false) { /* -> bb390 */ }
    if CF { /* -> bb398 */ }

    // ---- bb390 @ 0x1400668be ----
    /* 1400668be */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 1400668c2 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 1400668c6 */ rax = (rax).wrapping_sub(rcx);
    /* 1400668c9 */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb398 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb397 */ }

    // ---- bb397 @ 0x1400668d1 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb398 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb918 */ }

    // ---- bb398 @ 0x1400668d7 ----
    /* 1400668d7 */ fn_1402c7498();
    /* fallthrough -> bb399 */

    // ---- bb399 @ 0x1400668dc ----
    /* 1400668dc */ core::ptr::write((0x1400668e3_u64).wrapping_add(0x372c96_u64) as *mut u8, 0x1_u8);
    /* 1400668e3 */ rdx = (0x1400668ea_u64).wrapping_add(0x2a15be_u64);
    /* 1400668ea */ rcx = (0x1400668f1_u64).wrapping_add(0x372c5f_u64);
    /* 1400668f1 */ fn_1400278e0();
    /* 1400668f6 */ core::ptr::write((0x1400668fd_u64).wrapping_add(0x372c7d_u64) as *mut u8, 0x0_u8);
    /* fallthrough -> bb226 */

    // ---- bb405 @ 0x140066902 ----
    /* 140066902 */ xmm0 = core::ptr::read((0x14006690a_u64).wrapping_add(0x2a16f6_u64) as *const u128);
    /* 14006690a */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 14006690e */ r8 = (0x140066915_u64).wrapping_add(0x2a15e7_u64);
    /* 140066915 */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066919 */ rcx = rdi;
    /* 14006691c */ fn_140067350();
    if (t_140066563 != 0x0_u8) {
        /* -> bb415 */
    } else {
        /* -> bb414 */
    }

    // ---- bb414 @ 0x140066923 ----
    if (t_140066563 != 0x0_u8) {
        /* -> bb415 */
    } else {
        /* -> bb418 */
    }

    // ---- bb415 @ 0x140066925 ----
    /* 140066925 */ rax = core::ptr::read((0x14006692c_u64).wrapping_add(0x3948bc_u64) as *const u64);
    /* 14006692c */ let mut t_14006692c: u32 = core::ptr::read((rax).wrapping_add(0x308_u64) as *const u32);
    /* 14006692c */ core::ptr::write((rax).wrapping_add(0x308_u64) as *mut u32, (t_14006692c).wrapping_add(0x3e8_u32));
    /* fallthrough -> bb494 */

    // ---- bb418 @ 0x14006693b ----
    /* 14006693b */ xmm0 = core::ptr::read((0x140066943_u64).wrapping_add(0x2a16cd_u64) as *const u128);
    /* 140066943 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 140066947 */ r8 = (0x14006694e_u64).wrapping_add(0x2a15b6_u64);
    /* 14006694e */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066952 */ rcx = rdi;
    /* 140066955 */ fn_140067350();
    if (t_140066563 != 0x0_u8) {
        /* -> bb428 */
    } else {
        /* -> bb427 */
    }

    // ---- bb427 @ 0x14006695c ----
    if (t_140066563 != 0x0_u8) {
        /* -> bb428 */
    } else {
        /* -> bb477 */
    }

    // ---- bb428 @ 0x140066962 ----
    /* 140066962 */ rax = core::ptr::read((0x140066969_u64).wrapping_add(0x39487f_u64) as *const u64);
    /* 140066969 */ core::ptr::write((rax).wrapping_add(0x321_u64) as *mut u8, 0x1_u8);
    /* 140066970 */ rax = core::ptr::read((0x140066977_u64).wrapping_add(0x394871_u64) as *const u64);
    /* 140066977 */ core::ptr::write((rax).wrapping_add(0x320_u64) as *mut u8, 0x1_u8);
    /* 14006697e */ rax = core::ptr::read((0x140066985_u64).wrapping_add(0x394863_u64) as *const u64);
    /* 140066985 */ let mut t_140066985: u32 = core::ptr::read((rax).wrapping_add(0x31c_u64) as *const u32);
    /* 140066985 */ let mut t_140066985_0: u32 = (t_140066985).wrapping_add(0x14_u32);
    /* 140066985 */ core::ptr::write((rax).wrapping_add(0x31c_u64) as *mut u32, t_140066985_0);
    /* 14006698c */ rcx = core::ptr::read((0x140066993_u64).wrapping_add(0x394855_u64) as *const u64);
    /* 140066993 */ fn_140104770();
    /* 140066998 */ rax = core::ptr::read((0x14006699f_u64).wrapping_add(0x394849_u64) as *const u64);
    /* 14006699f */ core::ptr::write((rax).wrapping_add(0x329_u64) as *mut u8, 0x1_u8);
    /* 1400669a6 */ rax = core::ptr::read((0x1400669ad_u64).wrapping_add(0x39483b_u64) as *const u64);
    /* 1400669ad */ core::ptr::write((rax).wrapping_add(0x328_u64) as *mut u8, 0x1_u8);
    /* 1400669b4 */ rax = core::ptr::read((0x1400669bb_u64).wrapping_add(0x39482d_u64) as *const u64);
    /* 1400669bb */ let mut t_1400669bb: u32 = core::ptr::read((rax).wrapping_add(0x324_u64) as *const u32);
    /* 1400669bb */ let mut t_1400669bb_0: u32 = (t_1400669bb).wrapping_add(0x14_u32);
    /* 1400669bb */ core::ptr::write((rax).wrapping_add(0x324_u64) as *mut u32, t_1400669bb_0);
    /* 1400669c2 */ rcx = core::ptr::read((0x1400669c9_u64).wrapping_add(0x39481f_u64) as *const u64);
    /* 1400669c9 */ fn_140104770();
    /* 1400669ce */ rax = core::ptr::read((0x1400669d5_u64).wrapping_add(0x394813_u64) as *const u64);
    /* 1400669d5 */ core::ptr::write((rax).wrapping_add(0x331_u64) as *mut u8, 0x1_u8);
    /* 1400669dc */ rax = core::ptr::read((0x1400669e3_u64).wrapping_add(0x394805_u64) as *const u64);
    /* 1400669e3 */ core::ptr::write((rax).wrapping_add(0x330_u64) as *mut u8, 0x1_u8);
    /* 1400669ea */ rax = core::ptr::read((0x1400669f1_u64).wrapping_add(0x3947f7_u64) as *const u64);
    /* 1400669f1 */ let mut t_1400669f1: u32 = core::ptr::read((rax).wrapping_add(0x32c_u64) as *const u32);
    /* 1400669f1 */ let mut t_1400669f1_0: u32 = (t_1400669f1).wrapping_add(0x14_u32);
    /* 1400669f1 */ core::ptr::write((rax).wrapping_add(0x32c_u64) as *mut u32, t_1400669f1_0);
    /* 1400669f8 */ rcx = core::ptr::read((0x1400669ff_u64).wrapping_add(0x3947e9_u64) as *const u64);
    /* 1400669ff */ fn_140104770();
    /* 140066a04 */ rax = core::ptr::read((0x140066a0b_u64).wrapping_add(0x3947dd_u64) as *const u64);
    /* 140066a0b */ core::ptr::write((rax).wrapping_add(0x339_u64) as *mut u8, 0x1_u8);
    /* 140066a12 */ rax = core::ptr::read((0x140066a19_u64).wrapping_add(0x3947cf_u64) as *const u64);
    /* 140066a19 */ core::ptr::write((rax).wrapping_add(0x338_u64) as *mut u8, 0x1_u8);
    /* 140066a20 */ rax = core::ptr::read((0x140066a27_u64).wrapping_add(0x3947c1_u64) as *const u64);
    /* 140066a27 */ let mut t_140066a27: u32 = core::ptr::read((rax).wrapping_add(0x334_u64) as *const u32);
    /* 140066a27 */ let mut t_140066a27_0: u32 = (t_140066a27).wrapping_add(0x14_u32);
    /* 140066a27 */ core::ptr::write((rax).wrapping_add(0x334_u64) as *mut u32, t_140066a27_0);
    /* 140066a2e */ rcx = core::ptr::read((0x140066a35_u64).wrapping_add(0x3947b3_u64) as *const u64);
    /* 140066a35 */ fn_140104770();
    /* 140066a3a */ rax = core::ptr::read((0x140066a41_u64).wrapping_add(0x3947a7_u64) as *const u64);
    /* 140066a41 */ core::ptr::write((rax).wrapping_add(0x341_u64) as *mut u8, 0x1_u8);
    /* 140066a48 */ rax = core::ptr::read((0x140066a4f_u64).wrapping_add(0x394799_u64) as *const u64);
    /* 140066a4f */ core::ptr::write((rax).wrapping_add(0x340_u64) as *mut u8, 0x1_u8);
    /* 140066a56 */ rax = core::ptr::read((0x140066a5d_u64).wrapping_add(0x39478b_u64) as *const u64);
    /* 140066a5d */ let mut t_140066a5d: u32 = core::ptr::read((rax).wrapping_add(0x33c_u64) as *const u32);
    /* 140066a5d */ let mut t_140066a5d_0: u32 = (t_140066a5d).wrapping_add(0x14_u32);
    /* 140066a5d */ core::ptr::write((rax).wrapping_add(0x33c_u64) as *mut u32, t_140066a5d_0);
    /* 140066a64 */ rcx = core::ptr::read((0x140066a6b_u64).wrapping_add(0x39477d_u64) as *const u64);
    /* 140066a6b */ fn_140104770();
    /* 140066a70 */ rax = core::ptr::read((0x140066a77_u64).wrapping_add(0x394771_u64) as *const u64);
    /* 140066a77 */ core::ptr::write((rax).wrapping_add(0x349_u64) as *mut u8, 0x1_u8);
    /* 140066a7e */ rax = core::ptr::read((0x140066a85_u64).wrapping_add(0x394763_u64) as *const u64);
    /* 140066a85 */ core::ptr::write((rax).wrapping_add(0x348_u64) as *mut u8, 0x1_u8);
    /* 140066a8c */ rax = core::ptr::read((0x140066a93_u64).wrapping_add(0x394755_u64) as *const u64);
    /* 140066a93 */ let mut t_140066a93: u32 = core::ptr::read((rax).wrapping_add(0x344_u64) as *const u32);
    /* 140066a93 */ let mut t_140066a93_0: u32 = (t_140066a93).wrapping_add(0x14_u32);
    /* 140066a93 */ core::ptr::write((rax).wrapping_add(0x344_u64) as *mut u32, t_140066a93_0);
    /* 140066a9a */ rcx = core::ptr::read((0x140066aa1_u64).wrapping_add(0x394747_u64) as *const u64);
    /* 140066aa1 */ fn_140104770();
    /* fallthrough -> bb494 */

    // ---- bb477 @ 0x140066aa8 ----
    /* 140066aa8 */ xmm0 = core::ptr::read((0x140066ab0_u64).wrapping_add(0x2a1550_u64) as *const u128);
    /* 140066ab0 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 140066ab4 */ rax = (0x140066abb_u64).wrapping_add(0x2a1455_u64);
    /* 140066abb */ r8 = (0x140066ac2_u64).wrapping_add(0x2a145e_u64);
    /* 140066ac2 */ let mut t_140066ac2: u8 = core::ptr::read((0x140066ac9_u64).wrapping_add(0x372adc_u64) as *const u8);
    if (t_140066ac2 == 0x0_u8) {
        /* -> bb483 */
    } else {
        /* -> bb484 */
    }

    // ---- bb484 @ 0x140066ac9 ----
    /* 140066ac9 */ r8 = rax;
    /* fallthrough -> bb483 */

    // ---- bb483 @ 0x140066acd ----
    /* 140066acd */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066ad1 */ rcx = rdi;
    /* 140066ad4 */ fn_140067350();
    if (t_140066ac2 != 0x0_u8) {
        /* -> bb492 */
    } else {
        /* -> bb491 */
    }

    // ---- bb491 @ 0x140066adb ----
    if (t_140066ac2 != 0x0_u8) {
        /* -> bb492 */
    } else {
        /* -> bb494 */
    }

    // ---- bb492 @ 0x140066add ----
    /* 140066add */ let mut t_140066add: u8 = core::ptr::read((0x140066ae4_u64).wrapping_add(0x372ac1_u64) as *const u8);
    /* 140066ae4 */ core::ptr::write((0x140066aeb_u64).wrapping_add(0x372aba_u64) as *mut u8, ((ZF == true) as u8));
    /* fallthrough -> bb494 */

    // ---- bb494 @ 0x140066aeb ----
    /* 140066aeb */ rax = (0x25_u32 as u64);
    /* 140066af0 */ rcx = (0x39_u32 as u64);
    if (t_140066ac2 == 0x0_u8) {
        /* -> bb498 */
    } else {
        /* -> bb499 */
    }

    // ---- bb499 @ 0x140066af8 ----
    /* 140066af8 */ rax = ((rcx as u32) as u64);
    /* fallthrough -> bb498 */

    // ---- bb498 @ 0x140066afb ----
    /* 140066afb */ let mut xmm6: u128 = ((rax as u32) as u128);
    /* 140066b09 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140066b0e */ let mut t_140066b0e: u32 = core::ptr::read((0x140066b14_u64).wrapping_add(0x36f82c_u64) as *const u32);
    /* 140066b0e */ rax = (t_140066b0e as u64);
    /* 140066b14 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    /* 140066b28 */ let mut t_140066b28_0: u32 = 0x0_u32;
    /* 140066b28 */ r9 = (t_140066b28_0 as u64);
    /* 140066b2b */ xmm2 = xmm6;
    /* 140066b2e */ xmm1 = xmm9;
    /* 140066b32 */ rcx = core::ptr::read((0x140066b39_u64).wrapping_add(0x38731f_u64) as *const u64);
    /* 140066b39 */ fn_140086510();
    /* 140066b3e */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x42680000_u32);
    /* 140066b45 */ xmm1 = xmm6;
    /* 140066b59 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u32, 0x42300000_u32);
    /* 140066b60 */ core::ptr::write((rbp).wrapping_sub(0x3d_u64) as *mut u32, 0x41200000_u32);
    /* 140066b67 */ r9 = (0x64_u32 as u64);
    /* 140066b6d */ r8 = (0x140066b74_u64).wrapping_add(0x372970_u64);
    /* 140066b74 */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066b78 */ rcx = rdi;
    /* 140066b7b */ fn_140067580();
    if (t_140066ac2 != 0x0_u8) {
        /* -> bb529 */
    } else {
        /* -> bb528 */
    }

    // ---- bb528 @ 0x140066b82 ----
    if (t_140066ac2 != 0x0_u8) {
        /* -> bb529 */
    } else {
        /* -> bb531 */
    }

    // ---- bb529 @ 0x140066b84 ----
    /* 140066b84 */ let mut t_140066b84: u32 = core::ptr::read((0x140066b8a_u64).wrapping_add(0x37295a_u64) as *const u32);
    /* 140066b84 */ rcx = (t_140066b84 as u64);
    /* 140066b8a */ fn_14003f290();
    /* fallthrough -> bb531 */

    // ---- bb531 @ 0x140066b8f ----
    /* 140066b9e */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140066ba3 */ let mut t_140066ba3: u32 = core::ptr::read((0x140066ba9_u64).wrapping_add(0x36f797_u64) as *const u32);
    /* 140066ba3 */ rax = (t_140066ba3 as u64);
    /* 140066ba9 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    /* 140066bb4 */ let mut t_140066bb4_0: u32 = 0x0_u32;
    /* 140066bb4 */ r9 = (t_140066bb4_0 as u64);
    /* 140066bb7 */ xmm2 = xmm6;
    /* 140066bba */ xmm1 = xmm9;
    /* 140066bbe */ rcx = core::ptr::read((0x140066bc5_u64).wrapping_add(0x387293_u64) as *const u64);
    /* 140066bc5 */ fn_140086510();
    /* 140066bca */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x42680000_u32);
    /* 140066bda */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u32, 0x42300000_u32);
    /* 140066be1 */ core::ptr::write((rbp).wrapping_sub(0x3d_u64) as *mut u32, 0x41200000_u32);
    /* 140066be8 */ r9 = (0x64_u32 as u64);
    /* 140066bee */ r8 = (0x140066bf5_u64).wrapping_add(0x3728f3_u64);
    /* 140066bf5 */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066bf9 */ rcx = rdi;
    /* 140066bfc */ fn_140067580();
    if (t_140066ac2 != 0x0_u8) {
        /* -> bb556 */
    } else {
        /* -> bb555 */
    }

    // ---- bb555 @ 0x140066c03 ----
    if (t_140066ac2 != 0x0_u8) {
        /* -> bb556 */
    } else {
        /* -> bb558 */
    }

    // ---- bb556 @ 0x140066c05 ----
    /* 140066c05 */ let mut t_140066c05: u32 = core::ptr::read((0x140066c0b_u64).wrapping_add(0x3728dd_u64) as *const u32);
    /* 140066c05 */ rcx = (t_140066c05 as u64);
    /* 140066c0b */ fn_14003f2c0();
    /* fallthrough -> bb558 */

    // ---- bb558 @ 0x140066c10 ----
    if (t_140066ac2 != 0x0_u8) {
        /* -> bb562 */
    } else {
        /* -> bb561 */
    }

    // ---- bb561 @ 0x140066c13 ----
    if (t_140066ac2 != 0x0_u8) {
        /* -> bb562 */
    } else {
        /* -> bb709 */
    }

    // ---- bb562 @ 0x140066c19 ----
    /* 140066c20 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, rax);
    /* 140066c25 */ let mut t_140066c25: u32 = core::ptr::read((0x140066c2b_u64).wrapping_add(0x36f715_u64) as *const u32);
    /* 140066c25 */ rax = (t_140066c25 as u64);
    /* 140066c2b */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    /* 140066c36 */ let mut t_140066c36_0: u32 = 0x0_u32;
    /* 140066c36 */ r9 = (t_140066c36_0 as u64);
    /* 140066c41 */ xmm1 = xmm9;
    /* 140066c45 */ rcx = core::ptr::read((0x140066c4c_u64).wrapping_add(0x38720c_u64) as *const u64);
    /* 140066c4c */ fn_140086510();
    /* 140066c51 */ let mut t_140066c51: u8 = core::ptr::read((0x140066c58_u64).wrapping_add(0x372894_u64) as *const u8);
    if (t_140066c51 == 0x0_u8) {
        /* -> bb576 */
    } else {
        /* -> bb575 */
    }

    // ---- bb575 @ 0x140066c58 ----
    if (t_140066c51 == 0x0_u8) {
        /* -> bb576 */
    } else {
        /* -> bb607 */
    }

    // ---- bb576 @ 0x140066c5a ----
    /* 140066c5f */ let mut t_140066c5f: u32 = core::ptr::read((0x140066c65_u64).wrapping_add(0x3731db_u64) as *const u32);
    /* 140066c5f */ let mut t_140066c5f_0: u64 = (((rax as u32) as u64)).wrapping_mul((t_140066c5f as u64));
    /* 140066c5f */ rdx = (((t_140066c5f_0 >> 0x20_u64) as u32) as u64);
    /* 140066c65 */ r8 = ((rdx as u32) as u64);
    /* 140066c68 */ r8 = (((((r8 as u32) as i64) >> ((0x7_u8 as u32) as i64)) as u64) as u64);
    /* 140066c6c */ rax = ((r8 as u32) as u64);
    /* 140066c6f */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140066c72 */ let mut t_140066c72_0: u32 = ((r8 as u32)).wrapping_add((rax as u32));
    /* 140066c72 */ r8 = (t_140066c72_0 as u64);
    /* 140066c75 */ rax = (((r8).wrapping_add((r8).wrapping_mul(0x4_u64)) as u32) as u64);
    /* 140066c79 */ rax = (((rax as u32) << (0x6_u8 as u32)) as u64);
    /* 140066c7c */ let mut t_140066c7c: u32 = core::ptr::read((0x140066c82_u64).wrapping_add(0x3731be_u64) as *const u32);
    if (t_140066c7c == (rax as u32)) {
        /* -> bb589 */
    } else {
        /* -> bb588 */
    }

    // ---- bb588 @ 0x140066c82 ----
    if (t_140066c7c == (rax as u32)) {
        /* -> bb589 */
    } else {
        /* -> bb607 */
    }

    // ---- bb589 @ 0x140066c84 ----
    /* 140066c84 */ let mut t_140066c84: u32 = core::ptr::read((0x140066c8a_u64).wrapping_add(0x3731ba_u64) as *const u32);
    /* 140066c8f */ let mut t_140066c8f_0: u64 = (((rax as u32) as u64)).wrapping_mul(((rcx as u32) as u64));
    /* 140066c91 */ let mut t_140066c91_0: u32 = ((rdx as u32)).wrapping_add((rcx as u32));
    /* 140066c91 */ rdx = (t_140066c91_0 as u64);
    /* 140066c93 */ rdx = (((((rdx as u32) as i64) >> ((0x7_u8 as u32) as i64)) as u64) as u64);
    /* 140066c96 */ rax = ((rdx as u32) as u64);
    /* 140066c98 */ rax = (((rax as u32) >> (0x1f_u8 as u32)) as u64);
    /* 140066c9b */ let mut t_140066c9b_0: u32 = ((rdx as u32)).wrapping_add((rax as u32));
    /* 140066c9b */ rdx = (t_140066c9b_0 as u64);
    /* 140066c9d */ let mut t_140066c9d_0: u64 = (((rdx as u32) as u64)).wrapping_mul((0xb4_u32 as u64));
    /* 140066c9d */ rax = ((t_140066c9d_0 as u32) as u64);
    if ((rcx as u32) == (rax as u32)) {
        /* -> bb602 */
    } else {
        /* -> bb601 */
    }

    // ---- bb601 @ 0x140066ca5 ----
    if ((rcx as u32) == (rax as u32)) {
        /* -> bb602 */
    } else {
        /* -> bb607 */
    }

    // ---- bb602 @ 0x140066ca7 ----
    /* 140066ca7 */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, (r8 as u32));
    if (((SF != OF) | ((r8 as u32) == 0x6_u32)) == false) { /* -> bb607 */ }
    if (((SF != OF) | ((r8 as u32) == 0x6_u32)) != 0) { /* -> bb606 */ }

    // ---- bb606 @ 0x140066cb2 ----
    if (((SF != OF) | ((r8 as u32) == 0x6_u32)) == false) { /* -> bb607 */ }
    if (((SF != OF) | ((r8 as u32) == 0x6_u32)) != 0) { /* -> bb608 */ }

    // ---- bb607 @ 0x140066cb4 ----
    /* 140066cb4 */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, 0xffffffff_u32);
    /* fallthrough -> bb608 */

    // ---- bb608 @ 0x140066cbe ----
    /* 140066cbe */ rbx = (0x1_u32 as u64);
    /* fallthrough -> bb609 */

    // ---- bb609 @ 0x140066cc3 ----
    if ((rbx as u32) != 0x5_u32) {
        /* -> bb613 */
    } else {
        /* -> bb612 */
    }

    // ---- bb612 @ 0x140066cc6 ----
    if ((rbx as u32) != 0x5_u32) {
        /* -> bb613 */
    } else {
        /* -> bb692 */
    }

    // ---- bb613 @ 0x140066ccc ----
    if ((rbx as u32) == 0x6_u32) {
        /* -> bb617 */
    } else {
        /* -> bb616 */
    }

    // ---- bb616 @ 0x140066ccf ----
    if ((rbx as u32) == 0x6_u32) {
        /* -> bb617 */
    } else {
        /* -> bb619 */
    }

    // ---- bb617 @ 0x140066cd1 ----
    /* 140066cd1 */ rsi = (0x42_u32 as u64);
    /* fallthrough -> bb621 */

    // ---- bb619 @ 0x140066cd8 ----
    /* 140066cd8 */ let mut t_140066cd8_0: u64 = (((rbx as u32) as u64)).wrapping_mul((0xd_u32 as u64));
    /* 140066cd8 */ rsi = ((t_140066cd8_0 as u32) as u64);
    /* 140066cdb */ rsi = (((rsi as u32)).wrapping_add(0x1_u32) as u64);
    /* fallthrough -> bb621 */

    // ---- bb621 @ 0x140066cdd ----
    /* 140066cdd */ let mut t_140066cdd: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    /* 140066cdd */ let mut r15: u64 = (t_140066cdd as u64);
    /* 140066ce4 */ r8 = ((rbx as u32) as u64);
    /* 140066ce7 */ rdx = (0x140066cee_u64).wrapping_add(0x335476_u64);
    /* 140066cee */ rcx = (rbp).wrapping_sub(0x29_u64);
    /* 140066cf2 */ fn_14008d720();
    /* 140066cf8 */ let mut t_140066cf8_0: u32 = ((r14 as u32) | 0x1_u32);
    /* 140066cf8 */ let mut r14: u64 = (t_140066cf8_0 as u64);
    /* 140066cfc */ core::ptr::write((rbp).wrapping_add(0x67_u64) as *mut u32, (r14 as u32));
    /* 140066d00 */ xmm0 = ((rsi as u32) as u128);
    /* 140066d0c */ core::ptr::write((rbp).wrapping_sub(0x45_u64) as *mut u32, 0x42040000_u32);
    /* 140066d13 */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u32, 0x41300000_u32);
    /* 140066d1a */ core::ptr::write((rbp).wrapping_sub(0x3d_u64) as *mut u32, 0x41300000_u32);
    /* 140066d21 */ let mut t_140066d21: u64 = core::ptr::read((rax).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_140066d21 == 0xf_u64)) == false) { /* -> bb639 */ }
    if ((CF | (t_140066d21 == 0xf_u64)) != 0) { /* -> bb638 */ }

    // ---- bb638 @ 0x140066d26 ----
    if ((CF | (t_140066d21 == 0xf_u64)) == false) { /* -> bb639 */ }
    if ((CF | (t_140066d21 == 0xf_u64)) != 0) { /* -> bb640 */ }

    // ---- bb639 @ 0x140066d28 ----
    /* 140066d28 */ rax = core::ptr::read(rax as *const u64);
    /* fallthrough -> bb640 */

    // ---- bb640 @ 0x140066d2b ----
    /* 140066d2e */ r9 = ((r9 & 0xffffffffffffff00_u64) | (((ZF == true) as u8) as u64));
    /* 140066d32 */ r8 = rax;
    /* 140066d35 */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066d39 */ rcx = rdi;
    /* 140066d3c */ fn_140067420();
    if ((rbx as u32) != (r15 as u32)) {
        /* -> bb650 */
    } else {
        /* -> bb649 */
    }

    // ---- bb649 @ 0x140066d43 ----
    if ((rbx as u32) != (r15 as u32)) {
        /* -> bb650 */
    } else {
        /* -> bb656 */
    }

    // ---- bb650 @ 0x140066d45 ----
    /* 140066d45 */ let mut t_140066d45: u32 = core::ptr::read((rdi).wrapping_add(0x25c_u64) as *const u32);
    if ((rbx as u32) != t_140066d45) {
        /* -> bb654 */
    } else {
        /* -> bb653 */
    }

    // ---- bb653 @ 0x140066d4b ----
    if ((rbx as u32) != t_140066d45) {
        /* -> bb654 */
    } else {
        /* -> bb656 */
    }

    // ---- bb654 @ 0x140066d4d ----
    /* 140066d4d */ rsi = ((rsi & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* fallthrough -> bb657 */

    // ---- bb656 @ 0x140066d52 ----
    /* 140066d52 */ let mut t_140066d52_0: u8 = 0x0_u8;
    /* 140066d52 */ rsi = ((rsi & 0xffffffffffffff00_u64) | (t_140066d52_0 as u64));
    /* fallthrough -> bb657 */

    // ---- bb657 @ 0x140066d55 ----
    if ((rbx as u32) != t_140066d45) {
        /* -> bb661 */
    } else {
        /* -> bb660 */
    }

    // ---- bb660 @ 0x140066d59 ----
    if ((rbx as u32) != t_140066d45) {
        /* -> bb661 */
    } else {
        /* -> bb683 */
    }

    // ---- bb661 @ 0x140066d5b ----
    /* 140066d5b */ let mut t_140066d5b_0: u32 = ((r14 as u32) & 0xfffffffe_u32);
    /* 140066d5b */ r14 = (t_140066d5b_0 as u64);
    /* 140066d5f */ rdx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb667 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb666 */ }

    // ---- bb666 @ 0x140066d67 ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb667 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb683 */ }

    // ---- bb667 @ 0x140066d69 ----
    /* 140066d69 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140066d6c */ rcx = core::ptr::read((rbp).wrapping_sub(0x29_u64) as *const u64);
    /* 140066d70 */ rax = rcx;
    if (CF == false) { /* -> bb674 */ }
    if CF { /* -> bb673 */ }

    // ---- bb673 @ 0x140066d7a ----
    if (CF == false) { /* -> bb674 */ }
    if CF { /* -> bb682 */ }

    // ---- bb674 @ 0x140066d7c ----
    /* 140066d7c */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 140066d80 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140066d84 */ rax = (rax).wrapping_sub(rcx);
    /* 140066d87 */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb682 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb681 */ }

    // ---- bb681 @ 0x140066d8f ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb682 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb925 */ }

    // ---- bb682 @ 0x140066d95 ----
    /* 140066d95 */ fn_1402c7498();
    /* fallthrough -> bb683 */

    // ---- bb683 @ 0x140066d9a ----
    if (rdx != 0xf_u64) {
        /* -> bb687 */
    } else {
        /* -> bb686 */
    }

    // ---- bb686 @ 0x140066d9d ----
    if (rdx != 0xf_u64) {
        /* -> bb687 */
    } else {
        /* -> bb692 */
    }

    // ---- bb687 @ 0x140066d9f ----
    /* 140066d9f */ core::ptr::write((rdi).wrapping_add(0x25c_u64) as *mut u32, (rbx as u32));
    /* 140066da5 */ let mut t_140066da5_0: u64 = (((rbx as u32) as u64)).wrapping_mul((0xb4_u32 as u64));
    /* 140066da5 */ rdx = ((t_140066da5_0 as u32) as u64);
    /* 140066dab */ rcx = (((rbx).wrapping_add((rbx).wrapping_mul(0x4_u64)) as u32) as u64);
    /* 140066dae */ rcx = (((rcx as u32) << (0x6_u8 as u32)) as u64);
    /* 140066db1 */ fn_1400c4620();
    /* fallthrough -> bb692 */

    // ---- bb692 @ 0x140066db6 ----
    /* 140066db6 */ rbx = (((rbx as u32)).wrapping_add(0x1_u32) as u64);
    if (((SF != OF) | ((rbx as u32) == 0x6_u32)) == false) { /* -> bb697 */ }
    if (((SF != OF) | ((rbx as u32) == 0x6_u32)) != 0) { /* -> bb696 */ }

    // ---- bb696 @ 0x140066dbb ----
    if (((SF != OF) | ((rbx as u32) == 0x6_u32)) != 0) { /* -> bb609 */ }
    if (((SF != OF) | ((rbx as u32) == 0x6_u32)) == false) { /* -> bb697 */ }

    // ---- bb697 @ 0x140066dc1 ----
    /* 140066dc1 */ xmm0 = core::ptr::read((0x140066dc9_u64).wrapping_add(0x2a1257_u64) as *const u128);
    /* 140066dc9 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 140066dcd */ let mut t_140066dcd: u8 = core::ptr::read((0x140066dd5_u64).wrapping_add(0x372717_u64) as *const u8);
    /* 140066dcd */ r9 = ((t_140066dcd as u32) as u64);
    /* 140066dd5 */ r8 = (0x140066ddc_u64).wrapping_add(0x2a1168_u64);
    /* 140066ddc */ rdx = (rbp).wrapping_sub(0x49_u64);
    /* 140066de0 */ rcx = rdi;
    /* 140066de3 */ fn_140067420();
    if ((rbx as u32) != 0x6_u32) {
        /* -> bb708 */
    } else {
        /* -> bb707 */
    }

    // ---- bb707 @ 0x140066dea ----
    if ((rbx as u32) != 0x6_u32) {
        /* -> bb708 */
    } else {
        /* -> bb709 */
    }

    // ---- bb708 @ 0x140066dec ----
    /* 140066dec */ fn_1400c4610();
    /* fallthrough -> bb709 */

    // ---- bb709 @ 0x140066df1 ----
    /* 140066df1 */ let mut t_140066df1: u32 = core::ptr::read((0x140066df8_u64).wrapping_add(0x383d18_u64) as *const u32);
    /* 140066df1 */ rcx = ((t_140066df1 as i64) as u64);
    if (SF != OF) {
        /* -> bb714 */
    } else {
        /* -> bb713 */
    }

    // ---- bb713 @ 0x140066dfb ----
    if (SF != OF) {
        /* -> bb714 */
    } else {
        /* -> bb728 */
    }

    // ---- bb714 @ 0x140066dfd ----
    /* 140066dfd */ rdx = (0x140066e04_u64).wrapping_sub(0x66e04_u64);
    /* 140066e04 */ let mut t_140066e04: u8 = core::ptr::read(((rcx).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x307f4c_u64) as *const u8);
    /* 140066e04 */ rax = ((t_140066e04 as i64) as u64);
    /* 140066e0d */ let mut t_140066e0d: u8 = core::ptr::read(((rax).wrapping_add((rdx).wrapping_mul(0x1_u64))).wrapping_add(0x3ed5d0_u64) as *const u8);
    if (t_140066e0d != 0x0_u8) {
        /* -> bb720 */
    } else {
        /* -> bb719 */
    }

    // ---- bb719 @ 0x140066e15 ----
    if (t_140066e0d != 0x0_u8) {
        /* -> bb720 */
    } else {
        /* -> bb728 */
    }

    // ---- bb720 @ 0x140066e17 ----
    /* 140066e17 */ rcx = (((rcx as u32)).wrapping_add(0x1_u32) as u64);
    /* 140066e19 */ core::ptr::write((0x140066e1f_u64).wrapping_add(0x383cf1_u64) as *mut u32, (rcx as u32));
    if ((rcx as u32) == 0x5_u32) {
        /* -> bb726 */
    } else {
        /* -> bb725 */
    }

    // ---- bb725 @ 0x140066e22 ----
    if ((rcx as u32) == 0x5_u32) {
        /* -> bb726 */
    } else {
        /* -> bb728 */
    }

    // ---- bb726 @ 0x140066e24 ----
    /* 140066e24 */ core::ptr::write((0x140066e2b_u64).wrapping_add(0x372750_u64) as *mut u8, 0x1_u8);
    /* 140066e2b */ core::ptr::write((0x140066e32_u64).wrapping_add(0x3726d0_u64) as *mut u8, 0x0_u8);
    /* fallthrough -> bb728 */

    // ---- bb728 @ 0x140066e32 ----
    /* 140066e32 */ fn_1400730b0();
    /* 140066e37 */ rcx = (rbp).wrapping_sub(0x29_u64);
    /* 140066e3b */ let mut t_140066e3b: u8 = core::ptr::read((0x140066e42_u64).wrapping_add(0x372739_u64) as *const u8);
    if (t_140066e3b != 0x0_u8) {
        /* -> bb734 */
    } else {
        /* -> bb733 */
    }

    // ---- bb733 @ 0x140066e42 ----
    if (t_140066e3b != 0x0_u8) {
        /* -> bb734 */
    } else {
        /* -> bb784 */
    }

    // ---- bb734 @ 0x140066e48 ----
    /* 140066e48 */ r9 = core::ptr::read((0x140066e4f_u64).wrapping_add(0x394399_u64) as *const u64);
    /* 140066e4f */ let mut t_140066e4f: u32 = core::ptr::read((r9).wrapping_add(0x314_u64) as *const u32);
    /* 140066e4f */ r8 = (t_140066e4f as u64);
    /* 140066e56 */ r8 = (((r8 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140066e59 */ let mut t_140066e59: u32 = core::ptr::read((0x140066e5f_u64).wrapping_add(0x387079_u64) as *const u32);
    /* 140066e59 */ rax = (t_140066e59 as u64);
    /* 140066e5f */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u32, (rax as u32));
    /* 140066e63 */ let mut t_140066e63: u32 = core::ptr::read((r9).wrapping_add(0x318_u64) as *const u32);
    /* 140066e63 */ r9 = (t_140066e63 as u64);
    /* 140066e6a */ rdx = (0x140066e71_u64).wrapping_add(0x2a10e7_u64);
    /* 140066e71 */ fn_14008d720();
    /* 140066e76 */ r8 = rax;
    /* 140066e79 */ let mut t_140066e79: u32 = core::ptr::read((0x140066e7f_u64).wrapping_add(0x2a4851_u64) as *const u32);
    /* 140066e79 */ rax = (t_140066e79 as u64);
    /* 140066e7f */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140066e80 */ let mut t_140066e80_0: u32 = ((rax as u32)).wrapping_sub((rdx as u32));
    /* 140066e80 */ rax = (t_140066e80_0 as u64);
    /* 140066e82 */ rax = (((((rax as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 140066e84 */ xmm1 = ((rax as u32) as u128);
    /* 140066e8b */ let mut t_140066e8b: u64 = core::ptr::read((r8).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_140066e8b == 0xf_u64)) == false) { /* -> bb753 */ }
    if ((CF | (t_140066e8b == 0xf_u64)) != 0) { /* -> bb752 */ }

    // ---- bb752 @ 0x140066e90 ----
    if ((CF | (t_140066e8b == 0xf_u64)) == false) { /* -> bb753 */ }
    if ((CF | (t_140066e8b == 0xf_u64)) != 0) { /* -> bb754 */ }

    // ---- bb753 @ 0x140066e92 ----
    /* 140066e92 */ r8 = core::ptr::read(r8 as *const u64);
    /* fallthrough -> bb754 */

    // ---- bb754 @ 0x140066e95 ----
    /* 140066e95 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, r8);
    /* 140066e9a */ let mut t_140066e9a: u32 = core::ptr::read((0x140066ea0_u64).wrapping_add(0x36f4f4_u64) as *const u32);
    /* 140066e9a */ rax = (t_140066e9a as u64);
    /* 140066ea0 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    /* 140066eab */ r9 = (0x2_u32 as u64);
    /* 140066eb9 */ rcx = core::ptr::read((0x140066ec0_u64).wrapping_add(0x386f80_u64) as *const u64);
    /* 140066ec0 */ fn_140086510();
    /* 140066ec6 */ rdx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb768 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb767 */ }

    // ---- bb767 @ 0x140066ece ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb768 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb831 */ }

    // ---- bb768 @ 0x140066ed4 ----
    /* 140066ed4 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140066ed7 */ rcx = core::ptr::read((rbp).wrapping_sub(0x29_u64) as *const u64);
    /* 140066edb */ rax = rcx;
    if (CF == false) { /* -> bb775 */ }
    if CF { /* -> bb774 */ }

    // ---- bb774 @ 0x140066ee5 ----
    if (CF == false) { /* -> bb775 */ }
    if CF { /* -> bb830 */ }

    // ---- bb775 @ 0x140066eeb ----
    /* 140066eeb */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 140066eef */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140066ef3 */ rax = (rax).wrapping_sub(rcx);
    /* 140066ef6 */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb783 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb782 */ }

    // ---- bb782 @ 0x140066efe ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb783 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb852 */ }

    // ---- bb783 @ 0x140066f04 ----
    /* fallthrough -> bb830 */

    // ---- bb784 @ 0x140066f09 ----
    /* 140066f09 */ rax = core::ptr::read((0x140066f10_u64).wrapping_add(0x3942d8_u64) as *const u64);
    /* 140066f10 */ let mut t_140066f10: u32 = core::ptr::read((rax).wrapping_add(0x314_u64) as *const u32);
    /* 140066f10 */ r8 = (t_140066f10 as u64);
    /* 140066f17 */ r8 = (((r8 as u32)).wrapping_add(0x1_u32) as u64);
    /* 140066f1a */ rdx = (0x140066f21_u64).wrapping_add(0x2a106f_u64);
    /* 140066f21 */ fn_14008d720();
    /* 140066f26 */ r8 = rax;
    /* 140066f29 */ let mut t_140066f29: u32 = core::ptr::read((0x140066f2f_u64).wrapping_add(0x2a47a1_u64) as *const u32);
    /* 140066f29 */ rax = (t_140066f29 as u64);
    /* 140066f2f */ rdx = ((((((rax as u32) >> 0x1f_u32) as bool) as i32) as u32) as u64);
    /* 140066f30 */ let mut t_140066f30_0: u32 = ((rax as u32)).wrapping_sub((rdx as u32));
    /* 140066f30 */ rax = (t_140066f30_0 as u64);
    /* 140066f32 */ rax = (((((rax as u32) as i64) >> (0x1_u32 as i64)) as u64) as u64);
    /* 140066f34 */ xmm1 = ((rax as u32) as u128);
    /* 140066f3b */ let mut t_140066f3b: u64 = core::ptr::read((r8).wrapping_add(0x18_u64) as *const u64);
    if ((CF | (t_140066f3b == 0xf_u64)) == false) { /* -> bb800 */ }
    if ((CF | (t_140066f3b == 0xf_u64)) != 0) { /* -> bb799 */ }

    // ---- bb799 @ 0x140066f40 ----
    if ((CF | (t_140066f3b == 0xf_u64)) == false) { /* -> bb800 */ }
    if ((CF | (t_140066f3b == 0xf_u64)) != 0) { /* -> bb801 */ }

    // ---- bb800 @ 0x140066f42 ----
    /* 140066f42 */ r8 = core::ptr::read(r8 as *const u64);
    /* fallthrough -> bb801 */

    // ---- bb801 @ 0x140066f45 ----
    /* 140066f45 */ core::ptr::write((rsp).wrapping_add(0x30_u64) as *mut u64, r8);
    /* 140066f4a */ let mut t_140066f4a: u32 = core::ptr::read((0x140066f50_u64).wrapping_add(0x36f444_u64) as *const u32);
    /* 140066f4a */ rax = (t_140066f4a as u64);
    /* 140066f50 */ core::ptr::write((rsp).wrapping_add(0x28_u64) as *mut u32, (rax as u32));
    /* 140066f5b */ r9 = (0x2_u32 as u64);
    /* 140066f69 */ rcx = core::ptr::read((0x140066f70_u64).wrapping_add(0x386ed0_u64) as *const u64);
    /* 140066f70 */ fn_140086510();
    /* 140066f76 */ rdx = core::ptr::read((rbp).wrapping_sub(0x11_u64) as *const u64);
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb815 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb814 */ }

    // ---- bb814 @ 0x140066f7e ----
    if ((CF | (rdx == 0xf_u64)) == false) { /* -> bb815 */ }
    if ((CF | (rdx == 0xf_u64)) != 0) { /* -> bb831 */ }

    // ---- bb815 @ 0x140066f80 ----
    /* 140066f80 */ rdx = (rdx).wrapping_add(0x1_u64);
    /* 140066f83 */ rcx = core::ptr::read((rbp).wrapping_sub(0x29_u64) as *const u64);
    /* 140066f87 */ rax = rcx;
    if (CF == false) { /* -> bb822 */ }
    if CF { /* -> bb821 */ }

    // ---- bb821 @ 0x140066f91 ----
    if (CF == false) { /* -> bb822 */ }
    if CF { /* -> bb830 */ }

    // ---- bb822 @ 0x140066f93 ----
    /* 140066f93 */ rdx = (rdx).wrapping_add(0x27_u64);
    /* 140066f97 */ rcx = core::ptr::read((rcx).wrapping_sub(0x8_u64) as *const u64);
    /* 140066f9b */ rax = (rax).wrapping_sub(rcx);
    /* 140066f9e */ rax = (rax).wrapping_sub(0x8_u64);
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb830 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb829 */ }

    // ---- bb829 @ 0x140066fa6 ----
    if (((CF == false) & (rax != 0x1f_u64)) == false) { /* -> bb830 */ }
    if (((CF == false) & (rax != 0x1f_u64)) != 0) { /* -> bb845 */ }

    // ---- bb830 @ 0x140066fa8 ----
    /* 140066fa8 */ fn_1402c7498();
    /* fallthrough -> bb831 */

    // ---- bb831 @ 0x140066fad ----
    /* 140066fad */ let mut r11: u64 = (rsp).wrapping_add(0xc0_u64);
    /* 140066fb5 */ rbx = core::ptr::read((r11).wrapping_add(0x38_u64) as *const u64);
    /* 140066fb9 */ rsi = core::ptr::read((r11).wrapping_add(0x40_u64) as *const u64);
    /* 140066fbd */ xmm6 = core::ptr::read((r11).wrapping_sub(0x10_u64) as *const u128);
    /* 140066fc2 */ let mut xmm7: u128 = core::ptr::read((r11).wrapping_sub(0x20_u64) as *const u128);
    /* 140066fc7 */ let mut xmm8: u128 = core::ptr::read((r11).wrapping_sub(0x30_u64) as *const u128);
    /* 140066fcc */ let mut xmm9: u128 = core::ptr::read((r11).wrapping_sub(0x40_u64) as *const u128);
    /* 140066fd1 */ rsp = r11;
    /* 140066fd4 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140066fd4 */ r15 = core::ptr::read(rsp as *const u64);
    /* 140066fd6 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140066fd6 */ r14 = core::ptr::read(rsp as *const u64);
    /* 140066fd8 */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140066fd8 */ let mut r12: u64 = core::ptr::read(rsp as *const u64);
    /* 140066fda */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140066fda */ let mut rdi: u64 = core::ptr::read(rsp as *const u64);
    /* 140066fdb */ rsp = (rsp).wrapping_add(0x8_u64);
    /* 140066fdb */ let mut rbp: u64 = core::ptr::read(rsp as *const u64);
    /* 140066fdc */ return;
    // <no successors>

    // ---- bb845 @ 0x140066fdd ----
    /* 140066fdd */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 140066fe2 */ let mut t_140066fe2_0: u32 = 0x0_u32;
    /* 140066fe2 */ r9 = (t_140066fe2_0 as u64);
    /* 140066fe5 */ let mut t_140066fe5_0: u32 = 0x0_u32;
    /* 140066fe5 */ r8 = (t_140066fe5_0 as u64);
    /* 140066fe8 */ let mut t_140066fe8_0: u32 = 0x0_u32;
    /* 140066fe8 */ rdx = (t_140066fe8_0 as u64);
    /* 140066fea */ let mut t_140066fea_0: u32 = 0x0_u32;
    /* 140066fea */ rcx = (t_140066fea_0 as u64);
    /* 140066fec */ fn_1402cd884();
    /* fallthrough -> bb852 */

    // ---- bb852 @ 0x140066ff2 ----
    /* 140066ff2 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 140066ff7 */ let mut t_140066ff7_0: u32 = 0x0_u32;
    /* 140066ff7 */ r9 = (t_140066ff7_0 as u64);
    /* 140066ffa */ let mut t_140066ffa_0: u32 = 0x0_u32;
    /* 140066ffa */ r8 = (t_140066ffa_0 as u64);
    /* 140066ffd */ let mut t_140066ffd_0: u32 = 0x0_u32;
    /* 140066ffd */ rdx = (t_140066ffd_0 as u64);
    /* 140066fff */ let mut t_140066fff_0: u32 = 0x0_u32;
    /* 140066fff */ rcx = (t_140066fff_0 as u64);
    /* 140067001 */ fn_1402cd884();
    /* fallthrough -> bb859 */

    // ---- bb859 @ 0x140067007 ----
    /* 140067007 */ rcx = (0x14006700e_u64).wrapping_add(0x383af6_u64);
    /* 14006700e */ fn_1402c7548();
    /* 140067013 */ let mut t_140067013: u32 = core::ptr::read((0x14006701a_u64).wrapping_add(0x383aea_u64) as *const u32);
    if (t_140067013 == 0xffffffff_u32) {
        /* -> bb865 */
    } else {
        /* -> bb864 */
    }

    // ---- bb864 @ 0x14006701a ----
    if (t_140067013 != 0xffffffff_u32) {
        /* -> bb45 */
    } else {
        /* -> bb865 */
    }

    // ---- bb865 @ 0x140067020 ----
    /* 140067023 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 140067027 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u64, 0xa_u64);
    /* 14006702f */ core::ptr::write((rbp).wrapping_sub(0x31_u64) as *mut u64, 0xf_u64);
    /* 140067037 */ core::ptr::write(rdi as *mut u64, core::ptr::read(rsi as *const u64));
    if (DF == false) { /* -> bb870 */ }
    if DF { /* -> bb871 */ }

    // ---- bb870 @ 0x140067037 ----
    /* 140067037 */ rsi = (rsi).wrapping_add(0x8_u64);
    /* 140067037 */ rdi = (rdi).wrapping_add(0x8_u64);
    /* fallthrough -> bb872 */

    // ---- bb871 @ 0x140067037 ----
    /* 140067037 */ rsi = (rsi).wrapping_sub(0x8_u64);
    /* 140067037 */ rdi = (rdi).wrapping_sub(0x8_u64);
    /* fallthrough -> bb872 */

    // ---- bb872 @ 0x14006703f ----
    /* 14006703f */ core::ptr::write(rdi as *mut u128, core::ptr::read(rsi as *const u128));
    if (DF == false) { /* -> bb874 */ }
    if DF { /* -> bb875 */ }

    // ---- bb874 @ 0x14006703f ----
    /* 14006703f */ rsi = (rsi).wrapping_add(0x10_u64);
    /* 14006703f */ rdi = (rdi).wrapping_add(0x10_u64);
    /* fallthrough -> bb876 */

    // ---- bb875 @ 0x14006703f ----
    /* 14006703f */ rsi = (rsi).wrapping_sub(0x10_u64);
    /* 14006703f */ rdi = (rdi).wrapping_sub(0x10_u64);
    /* fallthrough -> bb876 */

    // ---- bb876 @ 0x140067044 ----
    /* 140067044 */ let mut t_140067044: u16 = core::ptr::read((0x14006704b_u64).wrapping_add(0x2a0e1d_u64) as *const u16);
    /* 140067044 */ rax = ((t_140067044 as u32) as u64);
    /* 14006704b */ core::ptr::write((rbp).wrapping_sub(0x41_u64) as *mut u16, (rax as u16));
    /* 14006704f */ core::ptr::write((rbp).wrapping_sub(0x3f_u64) as *mut u8, 0x0_u8);
    /* 140067053 */ rcx = (rbp).wrapping_sub(0x49_u64);
    /* 140067057 */ fn_14006fd40();
    /* 14006705c */ core::ptr::write((0x140067062_u64).wrapping_add(0x383a9e_u64) as *mut u32, (rax as u32));
    /* 140067062 */ rcx = (0x140067069_u64).wrapping_add(0x383a9b_u64);
    /* 140067069 */ fn_1402c74dc();
    /* fallthrough -> bb45 */

    // ---- bb886 @ 0x140067073 ----
    /* 140067073 */ rcx = (0x14006707a_u64).wrapping_add(0x383a92_u64);
    /* 14006707a */ fn_1402c7548();
    /* 14006707f */ let mut t_14006707f: u32 = core::ptr::read((0x140067086_u64).wrapping_add(0x383a86_u64) as *const u32);
    if (t_14006707f == 0xffffffff_u32) {
        /* -> bb892 */
    } else {
        /* -> bb891 */
    }

    // ---- bb891 @ 0x140067086 ----
    if (t_14006707f != 0xffffffff_u32) {
        /* -> bb69 */
    } else {
        /* -> bb892 */
    }

    // ---- bb892 @ 0x14006708c ----
    /* 14006708f */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u128, xmm0);
    /* 140067093 */ core::ptr::write((rbp).wrapping_sub(0x39_u64) as *mut u64, 0x4_u64);
    /* 14006709b */ core::ptr::write((rbp).wrapping_sub(0x31_u64) as *mut u64, 0xf_u64);
    /* 1400670a3 */ core::ptr::write((rbp).wrapping_sub(0x49_u64) as *mut u32, 0x6f666e69_u32);
    /* 1400670aa */ core::ptr::write((rbp).wrapping_sub(0x45_u64) as *mut u8, 0x0_u8);
    /* 1400670ae */ rcx = (rbp).wrapping_sub(0x49_u64);
    /* 1400670b2 */ fn_14006fd40();
    /* 1400670b7 */ core::ptr::write((0x1400670bd_u64).wrapping_add(0x383a4b_u64) as *mut u32, (rax as u32));
    /* 1400670bd */ rcx = (0x1400670c4_u64).wrapping_add(0x383a48_u64);
    /* 1400670c4 */ fn_1402c74dc();
    /* fallthrough -> bb69 */

    // ---- bb904 @ 0x1400670ce ----
    /* 1400670ce */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 1400670d3 */ let mut t_1400670d3_0: u32 = 0x0_u32;
    /* 1400670d3 */ r9 = (t_1400670d3_0 as u64);
    /* 1400670d6 */ let mut t_1400670d6_0: u32 = 0x0_u32;
    /* 1400670d6 */ r8 = (t_1400670d6_0 as u64);
    /* 1400670d9 */ let mut t_1400670d9_0: u32 = 0x0_u32;
    /* 1400670d9 */ rdx = (t_1400670d9_0 as u64);
    /* 1400670db */ let mut t_1400670db_0: u32 = 0x0_u32;
    /* 1400670db */ rcx = (t_1400670db_0 as u64);
    /* 1400670dd */ fn_1402cd884();
    /* fallthrough -> bb911 */

    // ---- bb911 @ 0x1400670e3 ----
    /* 1400670e3 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 1400670e8 */ let mut t_1400670e8_0: u32 = 0x0_u32;
    /* 1400670e8 */ r9 = (t_1400670e8_0 as u64);
    /* 1400670eb */ let mut t_1400670eb_0: u32 = 0x0_u32;
    /* 1400670eb */ r8 = (t_1400670eb_0 as u64);
    /* 1400670ee */ let mut t_1400670ee_0: u32 = 0x0_u32;
    /* 1400670ee */ rdx = (t_1400670ee_0 as u64);
    /* 1400670f0 */ let mut t_1400670f0_0: u32 = 0x0_u32;
    /* 1400670f0 */ rcx = (t_1400670f0_0 as u64);
    /* 1400670f2 */ fn_1402cd884();
    /* fallthrough -> bb918 */

    // ---- bb918 @ 0x1400670f8 ----
    /* 1400670f8 */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 1400670fd */ let mut t_1400670fd_0: u32 = 0x0_u32;
    /* 1400670fd */ r9 = (t_1400670fd_0 as u64);
    /* 140067100 */ let mut t_140067100_0: u32 = 0x0_u32;
    /* 140067100 */ r8 = (t_140067100_0 as u64);
    /* 140067103 */ let mut t_140067103_0: u32 = 0x0_u32;
    /* 140067103 */ rdx = (t_140067103_0 as u64);
    /* 140067105 */ let mut t_140067105_0: u32 = 0x0_u32;
    /* 140067105 */ rcx = (t_140067105_0 as u64);
    /* 140067107 */ fn_1402cd884();
    /* fallthrough -> bb925 */

    // ---- bb925 @ 0x14006710d ----
    /* 14006710d */ core::ptr::write((rsp).wrapping_add(0x20_u64) as *mut u64, r12);
    /* 140067112 */ let mut t_140067112_0: u32 = 0x0_u32;
    /* 140067112 */ r9 = (t_140067112_0 as u64);
    /* 140067115 */ let mut t_140067115_0: u32 = 0x0_u32;
    /* 140067115 */ r8 = (t_140067115_0 as u64);
    /* 140067118 */ let mut t_140067118_0: u32 = 0x0_u32;
    /* 140067118 */ rdx = (t_140067118_0 as u64);
    /* 14006711a */ let mut t_14006711a_0: u32 = 0x0_u32;
    /* 14006711a */ rcx = (t_14006711a_0 as u64);
    /* 14006711c */ fn_1402cd884();
    /* 140067134 */ r9 = rcx;
    if (CF == false) { /* -> bb953 */ }
    if CF { /* -> bb952 */ }

    // ---- bb952 @ 0x140067142 ----
    if (CF == false) { /* -> bb953 */ }
    if CF { /* -> bb972 */ }

    // ---- bb953 @ 0x140067144 ----
    /* 140067144 */ xmm0 = xmm1;
    if ((CF | (rax == 0x1f_u64)) == false) { /* -> bb959 */ }
    if ((CF | (rax == 0x1f_u64)) != 0) { /* -> bb958 */ }

    // ---- bb958 @ 0x14006714f ----
    if ((CF | (rax == 0x1f_u64)) == false) { /* -> bb959 */ }
    if ((CF | (rax == 0x1f_u64)) != 0) { /* -> bb972 */ }

    // ---- bb959 @ 0x140067151 ----
    if (CF == false) { /* -> bb965 */ }
    if CF { /* -> bb964 */ }

    // ---- bb964 @ 0x140067161 ----
    if (CF == false) { /* -> bb965 */ }
    if CF { /* -> bb972 */ }

    // ---- bb965 @ 0x140067163 ----
    if ((CF | (rax == 0x1f_u64)) == false) { /* -> bb970 */ }
    if ((CF | (rax == 0x1f_u64)) != 0) { /* -> bb969 */ }

    // ---- bb969 @ 0x14006716b ----
    if ((CF | (rax == 0x1f_u64)) == false) { /* -> bb970 */ }
    if ((CF | (rax == 0x1f_u64)) != 0) { /* -> bb972 */ }

    // ---- bb970 @ 0x14006716d ----
    /* 14006716d */ r8 = ((r8 & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* fallthrough -> bb973 */

    // ---- bb972 @ 0x140067172 ----
    /* 140067172 */ let mut t_140067172_0: u8 = 0x0_u8;
    /* 140067172 */ r8 = ((r8 & 0xffffffffffffff00_u64) | (t_140067172_0 as u64));
    /* fallthrough -> bb973 */

    // ---- bb973 @ 0x140067175 ----
    /* 140067175 */ let mut t_140067175: u32 = core::ptr::read((0x14006717c_u64).wrapping_add(0x3867dc_u64) as *const u32);
    /* 14006717c */ rax = core::ptr::read((0x140067183_u64).wrapping_add(0x3867e5_u64) as *const u64);
    /* 140067183 */ rcx = (((r8 as u8) as u32) as u64);
    if (t_140067175 == 0x0_u32) {
        /* -> bb979 */
    } else {
        /* -> bb978 */
    }

    // ---- bb978 @ 0x140067187 ----
    if (t_140067175 == 0x0_u32) {
        /* -> bb979 */
    } else {
        /* -> bb983 */
    }

    // ---- bb979 @ 0x140067189 ----
    if (t_140067175 != 0x0_u32) {
        /* -> bb983 */
    } else {
        /* -> bb982 */
    }

    // ---- bb982 @ 0x14006718b ----
    if (t_140067175 != 0x0_u32) {
        /* -> bb983 */
    } else {
        /* -> bb1021 */
    }

    // ---- bb983 @ 0x14006718d ----
    if (CF == false) { /* -> bb988 */ }
    if CF { /* -> bb987 */ }

    // ---- bb987 @ 0x140067199 ----
    if (CF == false) { /* -> bb988 */ }
    if CF { /* -> bb1007 */ }

    // ---- bb988 @ 0x14006719b ----
    if ((CF | (t_140067175 == 0x0_u32)) == false) { /* -> bb993 */ }
    if ((CF | (t_140067175 == 0x0_u32)) != 0) { /* -> bb992 */ }

    // ---- bb992 @ 0x1400671a3 ----
    if ((CF | (t_140067175 == 0x0_u32)) == false) { /* -> bb993 */ }
    if ((CF | (t_140067175 == 0x0_u32)) != 0) { /* -> bb1007 */ }

    // ---- bb993 @ 0x1400671a5 ----
    if (CF == false) { /* -> bb999 */ }
    if CF { /* -> bb998 */ }

    // ---- bb998 @ 0x1400671b6 ----
    if (CF == false) { /* -> bb999 */ }
    if CF { /* -> bb1007 */ }

    // ---- bb999 @ 0x1400671b8 ----
    if ((CF | (t_140067175 == 0x0_u32)) == false) { /* -> bb1004 */ }
    if ((CF | (t_140067175 == 0x0_u32)) != 0) { /* -> bb1003 */ }

    // ---- bb1003 @ 0x1400671c0 ----
    if ((CF | (t_140067175 == 0x0_u32)) == false) { /* -> bb1004 */ }
    if ((CF | (t_140067175 == 0x0_u32)) != 0) { /* -> bb1007 */ }

    // ---- bb1004 @ 0x1400671c2 ----
    /* 1400671c2 */ rdx = ((rdx & 0xffffffffffffff00_u64) | (0x1_u8 as u64));
    /* 1400671c4 */ let mut t_1400671c4_0: u32 = ((rcx as u32) | 0x2_u32);
    /* 1400671c4 */ rcx = (t_1400671c4_0 as u64);
    /* fallthrough -> bb1008 */

    // ---- bb1007 @ 0x1400671c9 ----
    /* 1400671c9 */ let mut t_1400671c9_0: u8 = 0x0_u8;
    /* 1400671c9 */ rdx = ((rdx & 0xffffffffffffff00_u64) | (t_1400671c9_0 as u64));
    /* fallthrough -> bb1008 */

    // ---- bb1008 @ 0x1400671cb ----
    if (t_140067175 != 0x0_u32) {
        /* -> bb1012 */
    } else {
        /* -> bb1011 */
    }

    // ---- bb1011 @ 0x1400671cd ----
    if (t_140067175 != 0x0_u32) {
        /* -> bb1012 */
    } else {
        /* -> bb1021 */
    }

    // ---- bb1012 @ 0x1400671cf ----
    if (t_140067175 != 0x0_u32) {
        /* -> bb1016 */
    } else {
        /* -> bb1015 */
    }

    // ---- bb1015 @ 0x1400671d2 ----
    if (t_140067175 != 0x0_u32) {
        /* -> bb1016 */
    } else {
        /* -> bb1021 */
    }

    // ---- bb1016 @ 0x1400671d4 ----
    if (t_140067175 != 0x0_u32) {
        /* -> bb1020 */
    } else {
        /* -> bb1019 */
    }

    // ---- bb1019 @ 0x1400671d6 ----
    if (t_140067175 != 0x0_u32) {
        /* -> bb1020 */
    } else {
        /* -> bb1021 */
    }

    // ---- bb1020 @ 0x1400671d8 ----
    /* 1400671d8 */ let mut t_1400671d8_0: u32 = ((rcx as u32) | 0x4_u32);
    /* 1400671d8 */ rcx = (t_1400671d8_0 as u64);
    /* fallthrough -> bb1021 */

    // ---- bb1021 @ 0x1400671db ----
    /* 1400671db */ rax = ((rcx as u32) as u64);
    /* 1400671dd */ return;
    // <no successors>
}
