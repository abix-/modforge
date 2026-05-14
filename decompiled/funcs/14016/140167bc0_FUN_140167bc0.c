// Address: 0x140167bc0
// Ghidra name: FUN_140167bc0
// ============ 0x140167bc0 FUN_140167bc0 (size=82) ============


undefined4 FUN_140167bc0(undefined8 *param_1)



{

  undefined4 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return 0;

  }

  FUN_140179b40(*param_1);

  uVar1 = *(undefined4 *)(param_1 + 0xb);

  FUN_140179b60(*param_1);

  return uVar1;

}




