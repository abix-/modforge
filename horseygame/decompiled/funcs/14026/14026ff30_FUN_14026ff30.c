// Address: 0x14026ff30
// Ghidra name: FUN_14026ff30
// ============ 0x14026ff30 FUN_14026ff30 (size=72) ============


void FUN_14026ff30(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  undefined8 local_18;

  undefined1 local_10;

  

  lVar2 = *(longlong *)(param_1 + 0x70);

  local_18 = 0x100;

  local_10 = 0;

  iVar1 = *(int *)(lVar2 + 0x14);

  if (iVar1 < 4) {

    *(undefined1 *)((longlong)&local_18 + (longlong)(8 - iVar1)) = 1;

  }

  FUN_14026eb20(param_1,*(undefined8 *)(lVar2 + 8),&local_18,9);

  return;

}




