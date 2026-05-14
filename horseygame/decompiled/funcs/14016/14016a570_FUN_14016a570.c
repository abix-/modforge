// Address: 0x14016a570
// Ghidra name: FUN_14016a570
// ============ 0x14016a570 FUN_14016a570 (size=135) ============


void FUN_14016a570(longlong param_1)



{

  int iVar1;

  int local_18;

  int iStack_14;

  int iStack_10;

  int iStack_c;

  

  local_18 = *(int *)(param_1 + 0x114);

  iStack_14 = *(int *)(param_1 + 0x11c);

  iStack_10 = (*(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x118)) - local_18;

  iStack_c = (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x120)) - iStack_14;

  iVar1 = memcmp(&local_18,(void *)(param_1 + 0x124),0x10);

  if (iVar1 != 0) {

    *(int *)(param_1 + 0x124) = local_18;

    *(int *)(param_1 + 0x128) = iStack_14;

    *(int *)(param_1 + 300) = iStack_10;

    *(int *)(param_1 + 0x130) = iStack_c;

    FUN_1401cda90(param_1,0x215,0,0);

  }

  return;

}




