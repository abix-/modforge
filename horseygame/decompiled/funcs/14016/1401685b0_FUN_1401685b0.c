// Address: 0x1401685b0
// Ghidra name: FUN_1401685b0
// ============ 0x1401685b0 FUN_1401685b0 (size=105) ============


undefined1 FUN_1401685b0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)



{

  undefined1 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  FUN_140179b40(*param_1);

  param_1[2] = param_2;

  param_1[3] = param_3;

  FUN_140179b60(*param_1);

  return 1;

}




