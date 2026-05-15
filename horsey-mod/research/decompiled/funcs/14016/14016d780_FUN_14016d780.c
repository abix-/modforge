// Address: 0x14016d780
// Ghidra name: FUN_14016d780
// ============ 0x14016d780 FUN_14016d780 (size=189) ============


undefined4 * FUN_14016d780(undefined4 *param_1)



{

  longlong lVar1;

  undefined4 *puVar2;

  int iVar3;

  longlong lVar4;

  undefined4 *puVar5;

  

  if (DAT_1403fc410 == 0) {

    if (param_1 != (undefined4 *)0x0) {

      *param_1 = 0;

    }

    FUN_1401730c0();

    return (undefined4 *)0x0;

  }

  puVar2 = (undefined4 *)FUN_1401841f0((longlong)*(int *)(DAT_1403fc410 + 0x328) * 4 + 4);

  lVar1 = DAT_1403fc410;

  if (puVar2 != (undefined4 *)0x0) {

    if (param_1 != (undefined4 *)0x0) {

      *param_1 = *(undefined4 *)(DAT_1403fc410 + 0x328);

    }

    iVar3 = 0;

    if (0 < *(int *)(lVar1 + 0x328)) {

      lVar4 = 0;

      puVar5 = puVar2;

      do {

        iVar3 = iVar3 + 1;

        *puVar5 = **(undefined4 **)(lVar4 + *(longlong *)(lVar1 + 0x330));

        lVar4 = lVar4 + 8;

        puVar5 = puVar5 + 1;

      } while (iVar3 < *(int *)(lVar1 + 0x328));

    }

    puVar2[iVar3] = 0;

    return puVar2;

  }

  if (param_1 != (undefined4 *)0x0) {

    *param_1 = 0;

  }

  return (undefined4 *)0x0;

}




