// Address: 0x140168680
// Ghidra name: FUN_140168680
// ============ 0x140168680 FUN_140168680 (size=105) ============


undefined1 FUN_140168680(undefined8 *param_1,undefined8 param_2,undefined8 param_3)



{

  undefined1 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  FUN_140179b40(*param_1);

  param_1[4] = param_2;

  param_1[5] = param_3;

  FUN_140179b60(*param_1);

  return 1;

}




