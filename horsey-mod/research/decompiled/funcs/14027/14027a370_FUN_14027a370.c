// Address: 0x14027a370
// Ghidra name: FUN_14027a370
// ============ 0x14027a370 FUN_14027a370 (size=89) ============


undefined8

FUN_14027a370(undefined8 param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4)



{

  int iVar1;

  undefined8 uVar2;

  undefined2 local_18;

  undefined1 local_16;

  undefined1 local_15;

  undefined1 local_14;

  undefined2 local_13;

  undefined1 local_11;

  

  local_15 = (undefined1)((ushort)param_3 >> 8);

  local_18 = 0x800;

  local_16 = 0;

  local_13 = 0;

  local_11 = 0;

  local_14 = (undefined1)((ushort)param_4 >> 8);

  iVar1 = FUN_140284590(param_1,&local_18,8);

  if (iVar1 != 8) {

    uVar2 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar2;

  }

  return 1;

}




