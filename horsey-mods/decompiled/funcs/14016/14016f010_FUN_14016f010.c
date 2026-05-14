// Address: 0x14016f010
// Ghidra name: FUN_14016f010
// ============ 0x14016f010 FUN_14016f010 (size=223) ============


longlong FUN_14016f010(int *param_1)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  longlong lVar4;

  int iVar5;

  

  if (param_1 != (int *)0x0) {

    *param_1 = 0;

  }

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  iVar3 = 0;

  iVar5 = 0;

  for (lVar1 = *(longlong *)(DAT_1403fc410 + 0x348); lVar1 != 0;

      lVar1 = *(longlong *)(lVar1 + 0x1a0)) {

    iVar3 = iVar3 + 1;

  }

  lVar1 = FUN_1401841f0((longlong)iVar3 * 8 + 8);

  if (lVar1 == 0) {

    return 0;

  }

  lVar4 = *(longlong *)(DAT_1403fc410 + 0x348);

  if (lVar4 != 0) {

    lVar2 = 0;

    do {

      *(longlong *)(lVar1 + lVar2 * 8) = lVar4;

      iVar5 = iVar5 + 1;

      lVar2 = lVar2 + 1;

      if (lVar2 == iVar3) break;

      lVar4 = *(longlong *)(lVar4 + 0x1a0);

    } while (lVar4 != 0);

  }

  *(undefined8 *)(lVar1 + (longlong)iVar5 * 8) = 0;

  if (param_1 != (int *)0x0) {

    *param_1 = iVar5;

  }

  return lVar1;

}




