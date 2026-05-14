// Address: 0x140209230
// Ghidra name: FUN_140209230
// ============ 0x140209230 FUN_140209230 (size=30) ============


undefined8 * FUN_140209230(undefined8 *param_1,undefined4 param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  

  lVar2 = FUN_14020a140(param_2);

  uVar1 = *(undefined8 *)(lVar2 + 0x26);

  *param_1 = *(undefined8 *)(lVar2 + 0x1e);

  param_1[1] = uVar1;

  return param_1;

}




