// Address: 0x1402f8670
// Ghidra name: FUN_1402f8670
// ============ 0x1402f8670 FUN_1402f8670 (size=111) ============


undefined8 FUN_1402f8670(undefined4 *param_1,uint param_2,uint param_3)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  

  param_3 = param_3 & 0xfff7ffff;

  if ((param_2 & param_3 & 0xfcf0fce0) != 0) {

    if (param_1 != (undefined4 *)0x0) {

      uVar1 = thunk_FUN_1402f8850(0,0);

      *param_1 = uVar1;

    }

    puVar2 = (undefined4 *)FUN_1402e68b0();

    *puVar2 = 0x16;

    FUN_1402cd454();

    return 0x16;

  }

  if (param_1 != (undefined4 *)0x0) {

    uVar1 = thunk_FUN_1402f8850(param_2,param_3);

    *param_1 = uVar1;

    return 0;

  }

  thunk_FUN_1402f8850(param_2,param_3);

  return 0;

}




