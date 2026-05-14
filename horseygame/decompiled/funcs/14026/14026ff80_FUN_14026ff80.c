// Address: 0x14026ff80
// Ghidra name: FUN_14026ff80
// ============ 0x14026ff80 FUN_14026ff80 (size=70) ============


void FUN_14026ff80(longlong param_1)



{

  longlong lVar1;

  undefined4 local_18;

  undefined2 local_14;

  undefined1 local_12;

  undefined1 local_11;

  undefined1 local_10;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  local_18 = 0x200;

  local_14 = 0xff00;

  local_11 = 0xff;

  local_12 = *(char *)(lVar1 + 0x19) != '\0';

  local_10 = *(undefined1 *)(lVar1 + 0x18);

  FUN_14026eb20(param_1,*(undefined8 *)(lVar1 + 8),&local_18,9);

  return;

}




