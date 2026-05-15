// Address: 0x14020fa10
// Ghidra name: FUN_14020fa10
// ============ 0x14020fa10 FUN_14020fa10 (size=32) ============


undefined8 * FUN_14020fa10(undefined8 *param_1,undefined4 param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  

  lVar2 = FUN_140210760(param_2);

  uVar1 = *(undefined8 *)(lVar2 + 0x60);

  *param_1 = *(undefined8 *)(lVar2 + 0x58);

  param_1[1] = uVar1;

  return param_1;

}




