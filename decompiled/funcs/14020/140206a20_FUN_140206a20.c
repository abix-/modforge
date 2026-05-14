// Address: 0x140206a20
// Ghidra name: FUN_140206a20
// ============ 0x140206a20 FUN_140206a20 (size=56) ============


undefined8 * FUN_140206a20(undefined8 *param_1,undefined4 param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  

  lVar2 = FUN_140207ae0(param_2,0);

  if (lVar2 != 0) {

    uVar1 = *(undefined8 *)(lVar2 + 0x38);

    *param_1 = *(undefined8 *)(lVar2 + 0x30);

    param_1[1] = uVar1;

    return param_1;

  }

  *param_1 = 0;

  param_1[1] = 0;

  return param_1;

}




