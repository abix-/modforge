// Address: 0x140130200
// Ghidra name: FUN_140130200
// ============ 0x140130200 FUN_140130200 (size=43) ============


undefined8 FUN_140130200(char param_1)



{

  undefined8 uVar1;

  

  if ((byte)(param_1 + 0x40U) < 0x20) {

    return 1;

  }

  if ((byte)(param_1 + 0x20U) < 0x10) {

    return 2;

  }

  uVar1 = 0;

  if ((byte)(param_1 + 0x10U) < 5) {

    uVar1 = 3;

  }

  return uVar1;

}




