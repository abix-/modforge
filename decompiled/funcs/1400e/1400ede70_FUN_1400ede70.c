// Address: 0x1400ede70
// Ghidra name: FUN_1400ede70
// ============ 0x1400ede70 FUN_1400ede70 (size=1431) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1400ede70(longlong param_1,int *param_2,undefined8 param_3,uint param_4)



{

  char *pcVar1;

  byte *pbVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  longlong lVar9;

  longlong lVar10;

  char cVar11;

  byte bVar12;

  undefined1 *puVar13;

  char *pcVar14;

  byte *pbVar15;

  int *piVar16;

  ulonglong uVar17;

  uint uVar18;

  ulonglong uVar19;

  ulonglong uVar20;

  

  lVar9 = *(longlong *)(param_2 + 2);

  uVar20 = 0;

  if (lVar9 == 0) {

    iVar3 = FUN_1400eda80();

    if (iVar3 == 0) {

      return 0;

    }

    lVar9 = _malloc_base((longlong)(*param_2 * param_2[1] * 4));

    *(longlong *)(param_2 + 2) = lVar9;

    if (lVar9 == 0) {

LAB_1400edf63:

      _DAT_1403f4c40 = "outofmem";

      return 0;

    }

    iVar3 = param_2[5];

    uVar17 = uVar20;

    uVar19 = uVar20;

    if (0 < param_2[1] * *param_2 * 4) {

      do {

        uVar18 = (int)uVar19 + 4;

        puVar13 = (undefined1 *)(*(longlong *)(param_2 + 2) + uVar17);

        *puVar13 = *(undefined1 *)((longlong)param_2 + (longlong)iVar3 * 4 + 0x26);

        puVar13[1] = *(undefined1 *)((longlong)param_2 + (longlong)iVar3 * 4 + 0x25);

        puVar13[2] = (char)param_2[(longlong)iVar3 + 9];

        puVar13[3] = *(undefined1 *)((longlong)param_2 + (longlong)iVar3 * 4 + 0x27);

        uVar17 = uVar17 + 4;

        uVar19 = (ulonglong)uVar18;

      } while ((int)uVar18 < param_2[1] * *param_2 * 4);

    }

  }

  else if (((byte)param_2[8] & 0x1c) == 0xc) {

    lVar10 = _malloc_base((longlong)(*param_2 * param_2[1] * 4));

    *(longlong *)(param_2 + 2) = lVar10;

    if (lVar10 == 0) goto LAB_1400edf63;

    FUN_1402f8e20(lVar10,lVar9,(longlong)(param_2[1] * *param_2 * 4));

  }

LAB_1400edf90:

  pcVar1 = *(char **)(param_1 + 0xb8);

  if (pcVar1 < *(char **)(param_1 + 0xc0)) {

    cVar11 = *pcVar1;

  }

  else {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400ee3da;

    FUN_1400ed820(param_1);

    pcVar1 = *(char **)(param_1 + 0xb8);

    cVar11 = *pcVar1;

  }

  piVar16 = (int *)(param_1 + 0x30);

  pcVar14 = pcVar1 + 1;

  *(char **)(param_1 + 0xb8) = pcVar14;

  if (cVar11 == '!') {

    if (pcVar14 < *(char **)(param_1 + 0xc0)) {

      cVar11 = *pcVar14;

      pbVar15 = (byte *)(pcVar1 + 2);

    }

    else {

      if (*piVar16 == 0) goto LAB_1400ee110;

      FUN_1400ed820(param_1);

      cVar11 = **(char **)(param_1 + 0xb8);

      pbVar15 = (byte *)(*(char **)(param_1 + 0xb8) + 1);

    }

    *(byte **)(param_1 + 0xb8) = pbVar15;

    if (cVar11 != -7) goto LAB_1400ee110;

    uVar18 = 0;

    if (pbVar15 < *(byte **)(param_1 + 0xc0)) {

      bVar12 = *pbVar15;

      pbVar2 = pbVar15;

LAB_1400ee056:

      pbVar15 = pbVar2 + 1;

      *(byte **)(param_1 + 0xb8) = pbVar15;

      uVar4 = (uint)bVar12;

      if (bVar12 == 4) {

        if (pbVar15 < *(byte **)(param_1 + 0xc0)) {

          bVar12 = *pbVar15;

          *(byte **)(param_1 + 0xb8) = pbVar2 + 2;

          uVar4 = (uint)bVar12;

        }

        else {

          uVar4 = 0;

          if (*(int *)(param_1 + 0x30) != 0) {

            FUN_1400ed820(param_1);

            bVar12 = **(byte **)(param_1 + 0xb8);

            *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

            uVar4 = (uint)bVar12;

          }

        }

        param_2[8] = uVar4;

        FUN_1400e8b80(param_1);

        pbVar15 = *(byte **)(param_1 + 0xb8);

        if (pbVar15 < *(byte **)(param_1 + 0xc0)) {

          bVar12 = *pbVar15;

          *(byte **)(param_1 + 0xb8) = pbVar15 + 1;

          uVar18 = (uint)bVar12;

        }

        else if (*(int *)(param_1 + 0x30) != 0) {

          FUN_1400ed820(param_1);

          bVar12 = **(byte **)(param_1 + 0xb8);

          *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

          uVar18 = (uint)bVar12;

        }

        param_2[7] = uVar18;

LAB_1400ee110:

        pbVar15 = *(byte **)(param_1 + 0xb8);

        if (pbVar15 < *(byte **)(param_1 + 0xc0)) {

          bVar12 = *pbVar15;

        }

        else {

          if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400edf90;

          FUN_1400ed820(param_1);

          pbVar15 = *(byte **)(param_1 + 0xb8);

          bVar12 = *pbVar15;

        }

        pbVar15 = pbVar15 + 1;

        *(byte **)(param_1 + 0xb8) = pbVar15;

        if (bVar12 == 0) goto LAB_1400edf90;

        if (*(longlong *)(param_1 + 0x10) == 0) {

LAB_1400ee1df:

          *(byte **)(param_1 + 0xb8) = pbVar15 + bVar12;

        }

        else {

          iVar3 = *(int *)(param_1 + 0xc0) - (int)pbVar15;

          if ((int)(uint)bVar12 <= iVar3) goto LAB_1400ee1df;

          *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 0xc0);

          (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),(uint)bVar12 - iVar3);

        }

        goto LAB_1400ee110;

      }

    }

    else {

      uVar4 = uVar18;

      if (*piVar16 != 0) {

        FUN_1400ed820(param_1);

        pbVar2 = *(byte **)(param_1 + 0xb8);

        bVar12 = *pbVar2;

        goto LAB_1400ee056;

      }

    }

    if ((*(longlong *)(param_1 + 0x10) == 0) ||

       (iVar3 = *(int *)(param_1 + 0xc0) - (int)pbVar15, (int)uVar4 <= iVar3)) {

      *(byte **)(param_1 + 0xb8) = pbVar15 + uVar4;

    }

    else {

      *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 0xc0);

      (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),uVar4 - iVar3);

    }

    goto LAB_1400edf90;

  }

  if (cVar11 != ',') {

    if (cVar11 == ';') {

      return 1;

    }

LAB_1400ee3da:

    _DAT_1403f4c40 = "unknown code";

    return 0;

  }

  iVar5 = FUN_1400e8b80(param_1);

  iVar6 = FUN_1400e8b80(param_1);

  iVar7 = FUN_1400e8b80(param_1);

  iVar8 = FUN_1400e8b80(param_1);

  iVar3 = *param_2;

  if ((iVar3 < iVar7 + iVar5) || (param_2[1] < iVar8 + iVar6)) {

    _DAT_1403f4c40 = "bad Image Descriptor";

    return 0;

  }

  param_2[0x1215] = iVar3 * 4;

  param_2[0x120f] = iVar5 * 4;

  param_2[0x1211] = (iVar7 + iVar5) * 4;

  param_2[0x1213] = iVar5 * 4;

  iVar5 = iVar3 * iVar6 * 4;

  param_2[0x1210] = iVar5;

  param_2[0x1214] = iVar5;

  param_2[0x1212] = iVar3 * (iVar8 + iVar6) * 4;

  pbVar15 = *(byte **)(param_1 + 0xb8);

  if (*(byte **)(param_1 + 0xc0) <= pbVar15) {

    if (*piVar16 == 0) goto LAB_1400ee2d8;

    FUN_1400ed820(param_1);

    pbVar15 = *(byte **)(param_1 + 0xb8);

  }

  uVar20 = (ulonglong)*pbVar15;

  *(byte **)(param_1 + 0xb8) = pbVar15 + 1;

LAB_1400ee2d8:

  param_2[0x120e] = (int)uVar20;

  iVar3 = param_2[0x1215] * 8;

  if ((uVar20 & 0x40) == 0) {

    iVar3 = param_2[0x1215];

  }

  param_2[0x120d] = iVar3;

  param_2[0x120c] = -(uint)((uVar20 & 0x40) != 0) & 3;

  if ((char)(byte)uVar20 < '\0') {

    if ((*(byte *)(param_2 + 8) & 1) == 0) {

      iVar3 = -1;

    }

    else {

      iVar3 = param_2[7];

    }

    piVar16 = param_2 + 0x109;

    FUN_1400ee410(param_1,piVar16,2 << ((byte)uVar20 & 7),iVar3);

  }

  else {

    if ((*(byte *)(param_2 + 4) & 0x80) == 0) {

      _DAT_1403f4c40 = "missing color table";

      return 0;

    }

    puVar13 = (undefined1 *)((longlong)param_2 + 0x27);

    lVar9 = 0x100;

    do {

      *puVar13 = 0xff;

      puVar13 = puVar13 + 4;

      lVar9 = lVar9 + -1;

    } while (lVar9 != 0);

    if ((-1 < param_2[7]) && ((*(byte *)(param_2 + 8) & 1) != 0)) {

      *(undefined1 *)((longlong)param_2 + (longlong)param_2[7] * 4 + 0x27) = 0;

    }

    piVar16 = param_2 + 9;

  }

  *(int **)(param_2 + 0x120a) = piVar16;

  lVar9 = FUN_1400ef4c0(param_1,param_2);

  if (lVar9 == 0) {

    return 0;

  }

  if ((param_4 & 0xfffffffb) != 0) {

    lVar9 = FUN_1400e6f80(lVar9,4,param_4,*param_2,param_2[1]);

    return lVar9;

  }

  return lVar9;

}




