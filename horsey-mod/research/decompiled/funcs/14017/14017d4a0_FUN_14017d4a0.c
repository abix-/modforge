// Address: 0x14017d4a0
// Ghidra name: FUN_14017d4a0
// ============ 0x14017d4a0 FUN_14017d4a0 (size=67) ============


void FUN_14017d4a0(longlong param_1,undefined4 *param_2,undefined4 *param_3)



{

  longlong lVar1;

  

  param_1 = SUB168(SEXT816(-0x5c28f5c28f5c28f5) * SEXT816(param_1),8) + param_1;

  lVar1 = ((param_1 >> 6) + 0x19db1ded53e8000) - (param_1 >> 0x3f);

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = (int)lVar1;

  }

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = (int)((ulonglong)lVar1 >> 0x20);

  }

  return;

}




