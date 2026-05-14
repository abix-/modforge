// Address: 0x14027e8f0
// Ghidra name: FUN_14027e8f0
// ============ 0x14027e8f0 FUN_14027e8f0 (size=123) ============


undefined8 FUN_14027e8f0(longlong param_1,longlong param_2)



{

  undefined4 uVar1;

  

  _guard_check_icall();

  *(undefined4 *)(param_2 + 0x60) = 1;

  uVar1 = FUN_14027eb10(*(undefined2 *)(param_1 + 0x22));

  *(undefined4 *)(param_2 + 0x70) = uVar1;

  switch(*(ushort *)(param_1 + 0x22) - 0xc24f) {

  case 0:

  case 0x45:

  case 0x4a:

  case 0x4c:

    *(undefined4 *)(param_2 + 0x44) = 4;

    return 1;

  case 0x49:

  case 0x4b:

    *(undefined4 *)(param_2 + 0x44) = 3;

  }

  return 1;

}




