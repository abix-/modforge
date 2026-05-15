// Address: 0x1401650c0
// Ghidra name: FUN_1401650c0
// ============ 0x1401650c0 FUN_1401650c0 (size=91) ============


undefined8 FUN_1401650c0(undefined8 *param_1)



{

  undefined8 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  FUN_140179b40(*param_1);

  FUN_140217b40(param_1[0xc]);

  param_1[0xd] = 0;

  *(undefined4 *)(param_1 + 0xe) = 0;

  param_1[0xf] = 0;

  param_1[0x14] = 0;

  FUN_140179b60(*param_1);

  return 1;

}




