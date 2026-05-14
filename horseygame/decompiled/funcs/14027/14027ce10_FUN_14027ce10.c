// Address: 0x14027ce10
// Ghidra name: FUN_14027ce10
// ============ 0x14027ce10 FUN_14027ce10 (size=69) ============


undefined1 FUN_14027ce10(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  

  FUN_14027cef0();

  lVar1 = FUN_1401841f0(param_2);

  *(longlong *)(param_1 + 0xa0) = lVar1;

  if (lVar1 != 0) {

    *(undefined4 *)(param_1 + 0xa8) = param_2;

    return 1;

  }

  return 0;

}




