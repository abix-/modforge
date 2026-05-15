// Decompiled from Horsey.exe @ 0x1400e0aa0
// Pipeline: r2sleigh (Sleigh lift -> SSA -> structurer) -> our Rust printer

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code, unused_parens)]
pub unsafe fn none_of_horses_are_tired(arg1: *mut anon) {
    arg2 = (&arg2 as *mut /* ? */ u64);
    arg2 = &arg2;
    local_30 = rbx + 8_i64;
    t68a80_1 = 3_i64 & 63_i64;
    arg2 = (((local_30 - local_38) as i64) >> ((3_i64 & 63_i64) as i64)) + 1_i64;
    t68a80_2 = 3_i64 & 63_i64;
    fn_1400285e0(local_30, local_30 - local_38, ((arg2 - local_38) as i64) >> ((3_i64 & 63_i64) as i64), (((*tmp_11f80 - local_38) as i64) >> (t68a80_1 as i64)) + 1_i64, 0x1fffffffffffffff_u64);
    fn_1402f9230();
    arg2 = (0x1fffffffffffffff_u64 + (((((arg2 - local_38) as i64) >> (t68a80_2 as i64)) as u64) >> (1_i64 as u64)) * 1_i64) * 8_i64 + rax * 1_i64;
    local_18 = rbx + 8_i64;
    arg2 = (((local_18 - rsi) as i64) >> ((3_i64 & 63_i64) as i64)) + 1_i64;
    fn_1400285e0(local_18);
    fn_1402f9230();
    fn_1402f9230();
    fn_1402c7498();
    r12d = stack + 1_i64;
    &stack + 2_i64 = r12d;
    rbx_2 = ((rsi as *mut /* ? */ u64))[fn_1400c6990()];
    rcx_42 = fn_1400c6990() - local_38;
    rcx_43 = fn_1400c6990() - local_38 >> (3_i64 & 63_i64);
    fn_1402c7498();
    local_38 = xmm0;
    fn_1402c7498();
    return local_38[fn_1400c6990()];
}

