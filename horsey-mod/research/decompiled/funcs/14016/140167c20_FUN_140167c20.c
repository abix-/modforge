// Address: 0x140167c20
// Ghidra name: FUN_140167c20
// ============ 0x140167c20 FUN_140167c20 (size=87) ============


undefined4 FUN_140167c20(undefined8 *param_1)



{

  undefined4 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return DAT_14039ca80;

  }

  FUN_140179b40(*param_1);

  uVar1 = *(undefined4 *)((longlong)param_1 + 0x5c);

  FUN_140179b60(*param_1);

  return uVar1;

}




