// Address: 0x1401694d0
// Ghidra name: FUN_1401694d0
// ============ 0x1401694d0 FUN_1401694d0 (size=30) ============


undefined ** FUN_1401694d0(longlong param_1,undefined8 *param_2)



{

  undefined **ppuVar1;

  

  if (*(code **)(param_1 + 0x2a0) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x0001401694dc. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    ppuVar1 = (undefined **)(**(code **)(param_1 + 0x2a0))();

    return ppuVar1;

  }

  *param_2 = 1;

  return &PTR_s_text_plain_charset_utf_8_1403345ef_1_1403e2680;

}




