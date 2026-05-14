// Address: 0x140167760
// Ghidra name: FUN_140167760
// ============ 0x140167760 FUN_140167760 (size=71) ============


undefined1 FUN_140167760(undefined8 *param_1)



{

  undefined1 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  FUN_140179b40(*param_1);

  FUN_140217d30(param_1[0xc]);

  FUN_140179b60(*param_1);

  return 1;

}




