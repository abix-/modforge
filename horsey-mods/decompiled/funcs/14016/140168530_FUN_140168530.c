// Address: 0x140168530
// Ghidra name: FUN_140168530
// ============ 0x140168530 FUN_140168530 (size=122) ============


undefined1 FUN_140168530(undefined8 *param_1,float param_2)



{

  undefined1 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  if (param_2 < 0.0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403338ec);

    return uVar1;

  }

  FUN_140179b40(*param_1);

  *(float *)((longlong)param_1 + 0x5c) = param_2;

  FUN_140179b60(*param_1);

  return 1;

}




