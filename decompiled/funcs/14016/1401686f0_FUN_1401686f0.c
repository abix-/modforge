// Address: 0x1401686f0
// Ghidra name: FUN_1401686f0
// ============ 0x1401686f0 FUN_1401686f0 (size=47) ============


undefined1 FUN_1401686f0(undefined8 *param_1)



{

  undefined1 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  FUN_140179b60(*param_1);

  return 1;

}




