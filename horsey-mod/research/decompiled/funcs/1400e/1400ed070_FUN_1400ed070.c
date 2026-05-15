// Address: 0x1400ed070
// Ghidra name: FUN_1400ed070
// ============ 0x1400ed070 FUN_1400ed070 (size=759) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400ed070(longlong *param_1)



{

  byte bVar1;

  char cVar2;

  int iVar3;

  byte *pbVar4;

  int iVar5;

  uint *puVar6;

  char *pcVar7;

  undefined8 uVar8;

  int iVar9;

  uint uVar10;

  longlong lVar11;

  uint uVar12;

  int *piVar13;

  

  iVar5 = FUN_1400e8ad0(*param_1);

  lVar11 = *param_1;

  pbVar4 = *(byte **)(lVar11 + 0xb8);

  if (pbVar4 < *(byte **)(lVar11 + 0xc0)) {

    bVar1 = *pbVar4;

    *(byte **)(lVar11 + 0xb8) = pbVar4 + 1;

  }

  else {

    if (*(int *)(lVar11 + 0x30) == 0) {

      *(undefined4 *)(param_1 + 0x6da) = 0;

      goto LAB_1400ed347;

    }

    FUN_1400ed820(lVar11);

    bVar1 = **(byte **)(lVar11 + 0xb8);

    *(byte **)(lVar11 + 0xb8) = *(byte **)(lVar11 + 0xb8) + 1;

  }

  *(uint *)(param_1 + 0x6da) = (uint)bVar1;

  if ((3 < bVar1 - 1) || (*(int *)(*param_1 + 8) < (int)(uint)bVar1)) {

LAB_1400ed347:

    _DAT_1403f4c40 = "bad SOS component count";

    return 0;

  }

  if (iVar5 != (uint)bVar1 * 2 + 6) {

    _DAT_1403f4c40 = "bad SOS len";

    return 0;

  }

  iVar5 = 0;

  if (bVar1 != 0) {

    piVar13 = (int *)((longlong)param_1 + 0x36d4);

    do {

      lVar11 = *param_1;

      pbVar4 = *(byte **)(lVar11 + 0xb8);

      if (pbVar4 < *(byte **)(lVar11 + 0xc0)) {

        uVar10 = (uint)*pbVar4;

        *(byte **)(lVar11 + 0xb8) = pbVar4 + 1;

      }

      else if (*(int *)(lVar11 + 0x30) == 0) {

        uVar10 = 0;

      }

      else {

        FUN_1400ed820(lVar11);

        uVar10 = (uint)**(byte **)(lVar11 + 0xb8);

        *(byte **)(lVar11 + 0xb8) = *(byte **)(lVar11 + 0xb8) + 1;

      }

      lVar11 = *param_1;

      pbVar4 = *(byte **)(lVar11 + 0xb8);

      if (pbVar4 < *(byte **)(lVar11 + 0xc0)) {

        uVar12 = (uint)*pbVar4;

        *(byte **)(lVar11 + 0xb8) = pbVar4 + 1;

      }

      else if (*(int *)(lVar11 + 0x30) == 0) {

        uVar12 = 0;

      }

      else {

        FUN_1400ed820(lVar11);

        uVar12 = (uint)**(byte **)(lVar11 + 0xb8);

        *(byte **)(lVar11 + 0xb8) = *(byte **)(lVar11 + 0xb8) + 1;

      }

      iVar9 = 0;

      lVar11 = 0;

      iVar3 = *(int *)(*param_1 + 8);

      if (0 < iVar3) {

        puVar6 = (uint *)(param_1 + 0x6b4);

        do {

          if (*puVar6 == uVar10) goto LAB_1400ed209;

          iVar9 = iVar9 + 1;

          lVar11 = lVar11 + 1;

          puVar6 = puVar6 + 0x12;

        } while (iVar9 < iVar3);

      }

      if (iVar9 == iVar3) goto LAB_1400ed2b4;

LAB_1400ed209:

      *(uint *)(param_1 + lVar11 * 9 + 0x6b6) = uVar12 >> 4;

      if (3 < uVar12 >> 4) {

        _DAT_1403f4c40 = "bad DC huff";

        goto LAB_1400ed2b4;

      }

      *(uint *)((longlong)param_1 + lVar11 * 0x48 + 0x35b4) = uVar12 & 0xf;

      if (3 < (uVar12 & 0xf)) {

        _DAT_1403f4c40 = "bad AC huff";

        goto LAB_1400ed2b4;

      }

      *piVar13 = iVar9;

      iVar5 = iVar5 + 1;

      piVar13 = piVar13 + 1;

    } while (iVar5 < (int)param_1[0x6da]);

  }

  lVar11 = *param_1;

  pcVar7 = *(char **)(lVar11 + 0xb8);

  if (pcVar7 < *(char **)(lVar11 + 0xc0)) {

LAB_1400ed272:

    cVar2 = *pcVar7;

    *(char **)(lVar11 + 0xb8) = pcVar7 + 1;

    if (cVar2 == '\0') goto LAB_1400ed287;

LAB_1400ed327:

    _DAT_1403f4c40 = "bad SOS";

LAB_1400ed2b4:

    uVar8 = 0;

  }

  else {

    if (*(int *)(lVar11 + 0x30) != 0) {

      FUN_1400ed820(lVar11);

      pcVar7 = *(char **)(lVar11 + 0xb8);

      goto LAB_1400ed272;

    }

LAB_1400ed287:

    lVar11 = *param_1;

    if (*(ulonglong *)(lVar11 + 0xb8) < *(ulonglong *)(lVar11 + 0xc0)) {

      *(ulonglong *)(lVar11 + 0xb8) = *(ulonglong *)(lVar11 + 0xb8) + 1;

    }

    else if (*(int *)(lVar11 + 0x30) != 0) {

      FUN_1400ed820(lVar11);

      *(longlong *)(lVar11 + 0xb8) = *(longlong *)(lVar11 + 0xb8) + 1;

    }

    lVar11 = *param_1;

    pcVar7 = *(char **)(lVar11 + 0xb8);

    if (pcVar7 < *(char **)(lVar11 + 0xc0)) {

LAB_1400ed316:

      cVar2 = *pcVar7;

      *(char **)(lVar11 + 0xb8) = pcVar7 + 1;

      if (cVar2 != '\0') goto LAB_1400ed327;

    }

    else if (*(int *)(lVar11 + 0x30) != 0) {

      FUN_1400ed820(lVar11);

      pcVar7 = *(char **)(lVar11 + 0xb8);

      goto LAB_1400ed316;

    }

    uVar8 = 1;

  }

  return uVar8;

}




