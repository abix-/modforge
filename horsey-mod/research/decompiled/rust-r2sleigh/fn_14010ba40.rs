// Decompiled from Horsey.exe @ 0x14010ba40
// Pipeline: r2sleigh (Sleigh lift -> SSA -> structurer) -> our Rust printer

#[allow(non_snake_case, unused_assignments, unused_variables, unused_mut, dead_code, unused_parens)]
pub unsafe fn horse_is_deceased_handler() {
    local_39 = (fn_1400285e0() as *mut anon);
    *rax = fn_1403040e0;
    *(rax + 16_i64) = 0_i64;
    tcf000 = fn_14039cd20;
    r8d_1 = 0_i64;
    fn_140040b90();
    fn_1402c7498();
    (*(rbx + 768_i64))[10_i64] = fn_1403ed970 / *(rbx + 276_i64) + *(rbx + 268_i64);
    (*(rbx + 768_i64))[11_i64] = fn_1403ed978 / *(rbx + 276_i64) + *(rbx + 272_i64);
    fn_1400a8880();
    *(rbx + 276_i64) = *(rbx + 276_i64) * fn_14030c2fc;
    *(rbx + 276_i64) = *(r15 + (r14d + 1_i64) * 4_i64 + 3225448_i64);
    (*(rbx + 768_i64))[173_i64] = 0_i64;
    fn_140104770();
    *(rbx + 616_i64) = r14d + 1_i64;
    *(rbx + 612_i64) = 1_i64;
    r8d_2 = 0_i64;
    fn_140040b90();
    fn_1402c7498();
    *(rbx + 276_i64) = (*(rbx + 276_i64) * fn_14030c2fc ^ *(rbx + 276_i64) * fn_14030c2fc) / fn_14030c2fc;
    *(rbx + 276_i64) = *(r15 + (r14d + 1_i64) * 4_i64 + 3225448_i64);
    fn_1400fbdb0();
    fn_14009c760();
    fn_140107a60();
    return eax;
}

