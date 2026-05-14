// Address: 0x1402dbe18
// Ghidra name: FUN_1402dbe18
// ============ 0x1402dbe18 FUN_1402dbe18 (size=56) ============


undefined8 FUN_1402dbe18(undefined8 *param_1)



{

  if (*(char *)(param_1 + 1) != '\0') {

    return *param_1;

  }

                    /* WARNING: Subroutine does not return */

  _invoke_watson(L"_is_double",L"__crt_strtox::floating_point_value::as_double",

                 L"minkernel\\crts\\ucrt\\inc\\corecrt_internal_strtox.h",0x1db,0);

}




