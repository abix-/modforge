// Address: 0x14013f2b0
// Ghidra name: FUN_14013f2b0
// ============ 0x14013f2b0 FUN_14013f2b0 (size=92) ============


undefined4 FUN_14013f2b0(undefined8 param_1,int param_2)



{

  longlong lVar1;

  undefined4 uVar2;

  

  FUN_140159d30();

  lVar1 = FUN_14013e670(param_1);

  uVar2 = 0;

  if (((lVar1 != 0) && (uVar2 = 0, -1 < param_2)) && (param_2 < *(int *)(lVar1 + 0x80))) {

    uVar2 = *(undefined4 *)(*(longlong *)(lVar1 + 0x88) + (longlong)param_2 * 0x10);

  }

  FUN_14015bb10();

  return uVar2;

}




