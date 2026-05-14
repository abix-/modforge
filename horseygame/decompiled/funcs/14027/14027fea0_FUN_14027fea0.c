// Address: 0x14027fea0
// Ghidra name: FUN_14027fea0
// ============ 0x14027fea0 FUN_14027fea0 (size=108) ============


undefined8 FUN_14027fea0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)



{

  int iVar1;

  undefined8 uVar2;

  undefined1 local_res8;

  undefined1 local_res9;

  undefined1 local_resa;

  undefined2 local_resb;

  

  if (*(char *)(*(longlong *)(param_1 + 0x70) + 4) == '\0') {

    uVar2 = FUN_14012e850("That operation is not supported");

    return uVar2;

  }

  local_res9 = (undefined1)((ulonglong)param_3 >> 8);

  local_res8 = 5;

  local_resb = 0;

  local_resa = (undefined1)((ushort)param_4 >> 8);

  iVar1 = FUN_140284590(param_1,&local_res8,5);

  if (iVar1 != 5) {

    uVar2 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar2;

  }

  return 1;

}




