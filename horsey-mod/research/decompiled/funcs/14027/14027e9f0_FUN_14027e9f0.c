// Address: 0x14027e9f0
// Ghidra name: FUN_14027e9f0
// ============ 0x14027e9f0 FUN_14027e9f0 (size=92) ============


void FUN_14027e9f0(longlong param_1,undefined8 param_2,byte param_3,byte param_4,byte param_5)



{

  uint uVar1;

  uint uVar2;

  

  if ((*(short *)(param_1 + 0x22) != -0x3db1) && (*(short *)(param_1 + 0x22) != -0x3d65)) {

    FUN_14012e850("That operation is not supported");

    return;

  }

  uVar2 = (uint)param_4;

  if ((uint)param_4 <= (uint)param_3) {

    uVar2 = (uint)param_3;

  }

  uVar1 = (uint)param_5;

  if (param_5 <= uVar2) {

    uVar1 = uVar2;

  }

  FUN_14027f510(param_1,(uVar1 * 5) / 0xff);

  return;

}




