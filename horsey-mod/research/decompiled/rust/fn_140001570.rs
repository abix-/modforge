// Decompiled from Horsey.exe @ 0x140001570
// Pipeline: Falcon lift -> dce -> fold -> flag-recog -> call/ret-recov -> Rust print
// blocks: 1

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code)]
pub unsafe fn fn_140001570() {

    // ---- bb0 @ 0x140001570 ----
    /* 140001570 */ let mut t_140001570_0: u64 = (rsp).wrapping_sub(0x28_u64);
    /* 140001574 */ let mut rcx: u64 = (0x60_u32 as u64);
    /* 140001579 */ fn_1402c745c();
    /* 14000157e */ rcx = (0x140001585_u64).wrapping_add(0x2ff0db_u64);
    /* 140001585 */ core::ptr::write(rax as *mut u64, rax);
    /* 140001588 */ core::ptr::write((rax).wrapping_add(0x8_u64) as *mut u64, rax);
    /* 14000158c */ core::ptr::write((rax).wrapping_add(0x10_u64) as *mut u64, rax);
    /* 140001590 */ core::ptr::write((rax).wrapping_add(0x18_u64) as *mut u16, 0x101_u16);
    /* 140001596 */ core::ptr::write((0x14000159d_u64).wrapping_add(0x3e8d13_u64) as *mut u64, rax);
    /* 14000159d */ rsp = (rsp).wrapping_add(0x28_u64);
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
