// Address: 0x14004ec60
// Ghidra name: FUN_14004ec60
// ============ 0x14004ec60 FUN_14004ec60 (size=328) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14004ec60(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  uint uVar3;

  int *piVar4;

  bool bVar5;

  byte *pbVar6;

  int *piVar7;

  int *piVar8;

  uint uVar9;

  ulonglong uVar10;

  longlong lVar11;

  

  uVar9 = *(uint *)(param_1 + 0x6e8);

  uVar10 = (ulonglong)(int)uVar9;

  piVar7 = *(int **)(param_1 + 0x40);

  bVar5 = true;

  if (uVar9 != 0xffffffff) {

    uVar3 = *(uint *)(param_1 + 0x5e0);

    if ((int)uVar9 < (int)uVar3) {

      pbVar6 = (byte *)(uVar10 + 0x5e4 + param_1);

      do {

        uVar9 = (uint)uVar10;

        piVar7 = (int *)((longlong)piVar7 + (ulonglong)*pbVar6);

        if (*pbVar6 != 0xff) goto LAB_14004ecc9;

        uVar9 = uVar9 + 1;

        uVar10 = (ulonglong)uVar9;

        pbVar6 = pbVar6 + 1;

      } while ((int)uVar9 < (int)uVar3);

    }

    if (uVar9 == uVar3) {

      uVar9 = 0xffffffff;

    }

LAB_14004ecc9:

    if (*(int **)(param_1 + 0x50) < piVar7) goto LAB_14004ed87;

    bVar5 = false;

    if (uVar9 != 0xffffffff) {

      return 1;

    }

  }

  piVar4 = *(int **)(param_1 + 0x50);

  while ((int *)((longlong)piVar7 + 0x1aU) < piVar4) {

    if ((*piVar7 != _DAT_1403d45d8) || ((char)piVar7[1] != '\0')) {

LAB_14004ed1b:

      *(undefined4 *)(param_1 + 0x9c) = 0x15;

      return 0;

    }

    if (bVar5) {

      if ((*(int *)(param_1 + 0x4f8) != 0) && ((*(byte *)((longlong)piVar7 + 5) & 1) != 0))

      goto LAB_14004ed1b;

    }

    else if ((*(byte *)((longlong)piVar7 + 5) & 1) == 0) goto LAB_14004ed1b;

    bVar1 = *(byte *)((longlong)piVar7 + 0x1a);

    piVar8 = (int *)((longlong)piVar7 + (ulonglong)bVar1 + 0x1b);

    if (piVar4 < piVar8) break;

    uVar9 = 0;

    lVar11 = 0;

    if (bVar1 != 0) {

      do {

        bVar2 = *(byte *)((longlong)piVar7 + lVar11 + 0x1b);

        piVar8 = (int *)((longlong)piVar8 + (ulonglong)bVar2);

        if (bVar2 != 0xff) break;

        uVar9 = uVar9 + 1;

        lVar11 = lVar11 + 1;

      } while (lVar11 < (longlong)(ulonglong)bVar1);

    }

    if (uVar9 == bVar1) {

      uVar9 = 0xffffffff;

    }

    if (piVar4 < piVar8) break;

    bVar5 = false;

    piVar7 = piVar8;

    if (uVar9 != 0xffffffff) {

      return 1;

    }

  }

LAB_14004ed87:

  *(undefined4 *)(param_1 + 0x9c) = 1;

  return 0;

}




