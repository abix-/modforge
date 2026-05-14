// Decompiled from Horsey.exe @ 0x140003b80
// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print
// blocks: 1

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]
pub unsafe fn fn_140003b80() {

    // ---- bb0 @ 0x140003b80 ----
    /* 140003b80 */ let mut t_140003b80_0: u64 = (rsp).wrapping_sub(0x28_u64);
    /* 140003b84 */ let mut rcx: u64 = (0x140003b8b_u64).wrapping_add(0x3e71b5_u64);
    /* 140003b8b */ fn_140025e00();
    /* 140003b90 */ rcx = (0x140003b97_u64).wrapping_add(0x2fce29_u64);
    /* 140003b97 */ rsp = (rsp).wrapping_add(0x28_u64);
    /* 1402c7818 */ let mut t_1402c7818_0: u64 = (rsp).wrapping_sub(0x28_u64);
    /* 1402c781c */ fn_1402c77dc();
    /* 1402c7821 */ let mut t_1402c7821_0: u64 = (0x0_u64).wrapping_sub(rax);
    /* 1402c7824 */ let mut rax: u64 = (((rax as u32)).wrapping_sub(((rax as u32)).wrapping_add((CF as u32))) as u64);
    /* 1402c7826 */ let mut t_1402c7826_0: u32 = (0x0_u32).wrapping_sub((rax as u32));
    /* 1402c7826 */ rax = (t_1402c7826_0 as u64);
    /* 1402c7828 */ rax = (((rax as u32)).wrapping_sub(0x1_u32) as u64);
    /* 1402c782a */ let mut t_1402c782a_0: u64 = (rsp).wrapping_add(0x28_u64);
    /* 1402c782a */ rsp = t_1402c782a_0;
    /* 1402c782e */ return;
    // <no successors>
}
