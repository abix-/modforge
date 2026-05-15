// Decompiled from Horsey.exe @ 0x140033a10
// Pipeline: r2sleigh (Sleigh lift -> SSA -> structurer) -> our Rust printer

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code, unused_parens)]
pub unsafe fn price_or_score_formula(arg1: i64, arg2: i64) {
    rbx = fn_1400285e0();
    fn_1400ca670();
    fn_1400cef70();
    ecx = *(fn_1400285e0() + 596_i64);
    *(fn_1400285e0() + 596_i64) = *(rcx + 596_i64) + 1_i64;
    r12d = 0_i64;
    t3e900 = *(fn_1400285e0() + 592_i64);
    fn_14003f5e0(rdi_2);
    t3ef00_1 = *(fn_1400285e0() + 592_i64);
    *(fn_1400285e0() + 592_i64) = rdi_4;
    *(fn_1400285e0() + 596_i64) = 0_i64;
    ecx = *(fn_1400285e0() + 592_i64);
    fn_1400d1060();
    r8d = (r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d ^ r12d) + 1_i64;
    eax = *(fn_1400285e0() + 596_i64);
    r9d = 0_i64;
    fn_1400d1090();
    fn_1402c7498();
    rcx = fn_1400285e0();
    local_11 = (fn_1400285e0() as *mut anon);
    *rax_21 = fn_1403041d0;
    *(rax_21 + 16_i64) = fn_140303400;
    *(rax_21 + 32_i64) = fn_1403041d0;
    *(rax_21 + 48_i64) = fn_140303c88;
    *(rax_21 + 52_i64) = (fn_140303c8c as i32);
    *(rax_21 + 54_i64) = (fn_140303c8e as i32);
    *(rax_21 + 55_i64) = 0_i64;
    r9d = 0_i64;
    *(fn_1400285e0() + 592_i64) = rdi_9;
    local_11 = (fn_1400285e0() as *mut anon);
    *rax_30 = fn_140304120;
    *(rax_30 + 16_i64) = fn_140303ca0;
    r9d = 0_i64;
    fn_14003f5e0();
    local_11 = 0x65766f4d68737542_u64;
    fn_140040b90();
    rcx = local_11[-1_i64];
    t3ef00_2 = *(fn_1400285e0() + 596_i64);
    t3f000 = *(rcx + 596_i64) - fn_1402c7498();
}

