// Address: 0x14027aaf0
// Ghidra name: FUN_14027aaf0
// ============ 0x14027aaf0 FUN_14027aaf0 (size=91) ============


undefined8

FUN_14027aaf0(undefined8 param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 local_18;

  undefined1 local_14;

  undefined1 local_13;

  undefined1 local_12;

  undefined4 local_11;

  undefined1 local_d;

  

  local_13 = (undefined1)((ushort)param_3 >> 8);

  local_18 = 0xc00f0100;

  local_14 = 0;

  local_11 = 0;

  local_d = 0;

  local_12 = (undefined1)((ushort)param_4 >> 8);

  iVar1 = FUN_140284590(param_1,&local_18,0xc);

  if (iVar1 != 0xc) {

    uVar2 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar2;

  }

  return 1;

}




