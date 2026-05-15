// Decompiled from Horsey.exe @ 0x1400df280
// Pipeline: r2sleigh (Sleigh lift -> SSA -> structurer) -> our Rust printer

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code, unused_parens)]
pub unsafe fn retirement_branch() {
    fn_1402c7498();
    local_50 = (fn_1400285e0() as *mut anon);
    *rax_5 = fn_140304100;
    *(rax_5 + 16_i64) = (fn_14030fab0 as i32);
    *(rax_5 + 18_i64) = (fn_14030fab2 as i32);
    *(rax_5 + 19_i64) = 0_i64;
    fn_1400d2330();
    fn_140028310();
    r8d_1 = 0_i64;
    fn_140040b90();
    fn_140028310();
    *(r14 + 1121_i64) = 1_i64;
    *(r14 + 1096_i64) = r15;
    r9d_1 = 0_i64;
    r8d_2 = 0_i64;
    *(r14 + 364_i64) = 0xffffffff_u64;
    *(r14 + 504_i64) = 0_i64;
    *(r14 + 592_i64) = 2_i64;
    *rax_15 = r15;
    fn_1400d2220();
    r8d_3 = 0_i64;
    fn_1400b7650();
    fn_1403da901 = 0_i64;
    fn_1400b7fd0();
    fn_1400d2220();
    r9d_2 = 0_i64;
    r8d_4 = 0_i64;
    fn_1402cd884();
    (*callother("userop_16", 3_i64))();
    return;
}

