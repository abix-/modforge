// Address: 0x140168490
// Ghidra name: FUN_140168490
// ============ 0x140168490 FUN_140168490 (size=151) ============


undefined1 FUN_140168490(undefined8 *param_1,float param_2)



{

  undefined1 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  if (param_2 < DAT_14039ca0c) {

    uVar1 = FUN_14012e850("Frequency ratio is too low");

    return uVar1;

  }

  if (DAT_14039ca5c < param_2) {

    uVar1 = FUN_14012e850("Frequency ratio is too high");

    return uVar1;

  }

  FUN_140179b40(*param_1);

  *(float *)(param_1 + 0xb) = param_2;

  FUN_140179b60(*param_1);

  return 1;

}




