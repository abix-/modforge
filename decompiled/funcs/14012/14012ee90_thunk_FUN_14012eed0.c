// Address: 0x14012ee90
// Ghidra name: thunk_FUN_14012eed0
// ============ 0x14012ee90 thunk_FUN_14012eed0 (size=5) ============


undefined1 * thunk_FUN_14012eed0(ulonglong param_1,undefined1 *param_2)



{

  undefined1 *puVar1;

  

  puVar1 = param_2;

  if ((int)param_1 < 0) {

    param_1 = (ulonglong)(uint)-(int)param_1;

    *param_2 = 0x2d;

    puVar1 = param_2 + 1;

  }

  FUN_14012f5e0(param_1,puVar1);

  return param_2;

}




