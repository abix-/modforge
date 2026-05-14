// Address: 0x140275420
// Ghidra name: FUN_140275420
// ============ 0x140275420 FUN_140275420 (size=110) ============


undefined8 FUN_140275420(longlong param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)



{

  int iVar1;

  undefined8 uVar2;

  undefined1 local_res8;

  undefined1 local_res9;

  undefined1 local_resa;

  undefined1 local_resb;

  undefined1 local_resc;

  

  if (**(char **)(param_1 + 0x70) == '\0') {

    uVar2 = FUN_14012e850("That operation is not supported");

    return uVar2;

  }

  local_res9 = (undefined1)param_3;

  local_resa = (undefined1)((ulonglong)param_3 >> 8);

  local_resb = (undefined1)param_4;

  local_res8 = 5;

  local_resc = (undefined1)((ushort)param_4 >> 8);

  iVar1 = FUN_140284590(param_1,&local_res8,5);

  if (iVar1 != 5) {

    uVar2 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar2;

  }

  return 1;

}




