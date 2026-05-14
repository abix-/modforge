// Address: 0x1401ff210
// Ghidra name: FUN_1401ff210
// ============ 0x1401ff210 FUN_1401ff210 (size=227) ============


undefined8 FUN_1401ff210(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  char cVar3;

  undefined4 uVar4;

  int local_18;

  int iStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  uVar4 = FUN_1401fa5d0(lVar1);

  cVar3 = FUN_1401fabe0(uVar4);

  if (*(char *)(lVar1 + 0x2901) == '\0') {

    local_18 = *(int *)(lVar1 + 0x2914);

    iStack_14 = *(int *)(lVar1 + 0x2918);

    uStack_10 = *(undefined4 *)(lVar1 + 0x291c);

    uStack_c = *(undefined4 *)(lVar1 + 0x2920);

  }

  else {

    local_18 = *(int *)(lVar1 + 0x2904) + *(int *)(lVar1 + 0x2914);

    iStack_14 = *(int *)(lVar1 + 0x2908) + *(int *)(lVar1 + 0x2918);

    uStack_10 = *(undefined4 *)(lVar1 + 0x290c);

    uStack_c = *(undefined4 *)(lVar1 + 0x2910);

  }

  if (cVar3 != '\0') {

    iVar2 = local_18;

    uVar4 = uStack_10;

    local_18 = iStack_14;

    uStack_10 = uStack_c;

    iStack_14 = iVar2;

    uStack_c = uVar4;

  }

  (*DAT_1403fcf28)(*(undefined8 *)(lVar1 + 0x698),0,1,&local_18);

  *(undefined1 *)(lVar1 + 0x2900) = 0;

  return 1;

}




