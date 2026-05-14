// Address: 0x140167e70
// Ghidra name: FUN_140167e70
// ============ 0x140167e70 FUN_140167e70 (size=47) ============


undefined1 FUN_140167e70(undefined8 *param_1)



{

  undefined1 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  FUN_140179b40(*param_1);

  return 1;

}




