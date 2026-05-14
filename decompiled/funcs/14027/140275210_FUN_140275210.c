// Address: 0x140275210
// Ghidra name: FUN_140275210
// ============ 0x140275210 FUN_140275210 (size=102) ============


undefined8 FUN_140275210(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined1 local_res8;

  undefined1 local_res9;

  undefined1 local_resa;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(char *)(lVar1 + 0x11) == '\0') {

    return 1;

  }

  local_res9 = *(undefined1 *)(lVar1 + 0x12);

  local_resa = *(undefined1 *)(lVar1 + 0x13);

  local_res8 = 1;

  *(undefined1 *)(lVar1 + 0x11) = 0;

  uVar2 = FUN_140149350();

  *(undefined8 *)(lVar1 + 0x18) = uVar2;

  uVar2 = FUN_140275130(param_1,0x39,&local_res8,3);

  return uVar2;

}




