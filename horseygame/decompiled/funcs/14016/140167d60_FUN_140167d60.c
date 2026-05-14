// Address: 0x140167d60
// Ghidra name: FUN_140167d60
// ============ 0x140167d60 FUN_140167d60 (size=80) ============


undefined4 FUN_140167d60(undefined8 *param_1)



{

  undefined4 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return 0;

  }

  FUN_140179b40(*param_1);

  if (*(int *)(param_1 + 1) == 0) {

    uVar1 = FUN_1401746e0();

    *(undefined4 *)(param_1 + 1) = uVar1;

  }

  FUN_140179b60(*param_1);

  return *(undefined4 *)(param_1 + 1);

}




