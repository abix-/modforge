// Address: 0x14026d740
// Ghidra name: FUN_14026d740
// ============ 0x14026d740 FUN_14026d740 (size=74) ============


undefined1 FUN_14026d740(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  

  puVar1 = *(undefined8 **)(param_1 + 0x70);

  _guard_check_icall();

  *puVar1 = 0;

  puVar1[1] = 0;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[4] = 0;

  puVar1[5] = 0;

  puVar1[6] = 0;

  puVar1[7] = 0;

  *(undefined4 *)(param_2 + 0x70) = 0xc;

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  return 1;

}




