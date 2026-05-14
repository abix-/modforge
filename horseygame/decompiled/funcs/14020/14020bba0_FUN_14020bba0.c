// Address: 0x14020bba0
// Ghidra name: FUN_14020bba0
// ============ 0x14020bba0 FUN_14020bba0 (size=52) ============


undefined8 * FUN_14020bba0(undefined8 *param_1,undefined4 param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  

  lVar2 = FUN_14020d2c0(param_2);

  if (lVar2 == 0) {

    *param_1 = 0;

    param_1[1] = 0;

    return param_1;

  }

  uVar1 = *(undefined8 *)(lVar2 + 0x1c);

  *param_1 = *(undefined8 *)(lVar2 + 0x14);

  param_1[1] = uVar1;

  return param_1;

}




