// Address: 0x1402836c0
// Ghidra name: FUN_1402836c0
// ============ 0x1402836c0 FUN_1402836c0 (size=84) ============


undefined4

FUN_1402836c0(undefined8 param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 local_18;

  undefined1 local_14;

  undefined1 local_13;

  undefined2 local_12;

  

  local_14 = (undefined1)((ushort)param_3 >> 8);

  local_18 = 0;

  local_12 = 0;

  local_13 = (undefined1)((ushort)param_4 >> 8);

  iVar1 = FUN_140284590(param_1,&local_18,8);

  if (iVar1 != 8) {

    uVar2 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar2;

  }

  return 1;

}




