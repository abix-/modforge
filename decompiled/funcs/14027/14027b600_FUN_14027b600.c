// Address: 0x14027b600
// Ghidra name: FUN_14027b600
// ============ 0x14027b600 FUN_14027b600 (size=110) ============


undefined8

FUN_14027b600(longlong param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,

             undefined1 param_5)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 local_18;

  undefined2 local_14;

  undefined1 local_12;

  undefined1 local_11;

  undefined1 local_10;

  

  if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x29) == '\0') {

    uVar2 = FUN_14012e850("That operation is not supported");

    return uVar2;

  }

  local_10 = param_5;

  local_18 = 0x500000e;

  local_14 = 0;

  local_12 = param_3;

  local_11 = param_4;

  iVar1 = FUN_140284590(param_1,&local_18,9);

  if (iVar1 != 9) {

    uVar2 = FUN_14012e850("Couldn\'t send LED packet");

    return uVar2;

  }

  return 1;

}




