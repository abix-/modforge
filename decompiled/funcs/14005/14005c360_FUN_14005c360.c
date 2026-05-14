// Address: 0x14005c360
// Ghidra name: FUN_14005c360
// ============ 0x14005c360 FUN_14005c360 (size=103) ============


undefined8 FUN_14005c360(longlong param_1)



{

  FUN_1400cd5a0(param_1,1);

  FUN_1400d0a00(param_1,0);

  if (*(longlong *)(param_1 + 0x148) != 0) {

    FUN_1400b6820(*(longlong *)(param_1 + 0x148),DAT_1403065c0,DAT_1403065c4);

  }

  *(undefined4 *)(param_1 + 0x158) = DAT_1403d4d90;

  FUN_1400ce540(param_1,0,0);

  *(undefined4 *)(param_1 + 0x250) = 0;

  return 1;

}




