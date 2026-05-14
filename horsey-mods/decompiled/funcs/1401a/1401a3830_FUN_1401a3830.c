// Address: 0x1401a3830
// Ghidra name: FUN_1401a3830
// ============ 0x1401a3830 FUN_1401a3830 (size=2176) ============


/* WARNING: Type propagation algorithm not settling */



ulonglong FUN_1401a3830(longlong *param_1,int param_2)



{

  char *pcVar1;

  longlong lVar2;

  undefined1 *puVar3;

  byte bVar4;

  ushort uVar5;

  int iVar6;

  undefined4 uVar7;

  uint uVar8;

  int iVar9;

  byte *pbVar10;

  ulonglong uVar11;

  char cVar12;

  char cVar13;

  char cVar14;

  char cVar15;

  char cVar16;

  char cVar17;

  byte bVar18;

  byte bVar19;

  undefined1 uVar20;

  int iVar21;

  longlong lVar22;

  uint *puVar23;

  longlong lVar24;

  uint local_78 [16];

  

  if (param_2 == 0xc4) {

    iVar6 = FUN_14019f260();

    for (iVar6 = iVar6 + -2; 0 < iVar6; iVar6 = (iVar6 + -0x11) - iVar21) {

      lVar22 = *param_1;

      iVar21 = 0;

      pbVar10 = *(byte **)(lVar22 + 0xc0);

      if (pbVar10 < *(byte **)(lVar22 + 200)) {

        bVar18 = *pbVar10;

        *(byte **)(lVar22 + 0xc0) = pbVar10 + 1;

      }

      else if (*(int *)(lVar22 + 0x30) == 0) {

        bVar18 = 0;

      }

      else {

        FUN_1401a4400(lVar22);

        bVar18 = **(byte **)(lVar22 + 0xc0);

        *(byte **)(lVar22 + 0xc0) = *(byte **)(lVar22 + 0xc0) + 1;

      }

      bVar4 = bVar18 >> 4;

      if ((1 < bVar4) || (3 < (bVar18 & 0xf))) goto LAB_1401a3d20;

      puVar23 = local_78;

      lVar22 = 0x10;

      do {

        lVar24 = *param_1;

        pbVar10 = *(byte **)(lVar24 + 0xc0);

        if (pbVar10 < *(byte **)(lVar24 + 200)) {

          bVar19 = *pbVar10;

          *(byte **)(lVar24 + 0xc0) = pbVar10 + 1;

        }

        else if (*(int *)(lVar24 + 0x30) == 0) {

          bVar19 = 0;

        }

        else {

          FUN_1401a4400(lVar24);

          bVar19 = **(byte **)(lVar24 + 0xc0);

          *(byte **)(lVar24 + 0xc0) = *(byte **)(lVar24 + 0xc0) + 1;

        }

        *puVar23 = (uint)bVar19;

        iVar21 = iVar21 + (uint)bVar19;

        puVar23 = puVar23 + 1;

        lVar22 = lVar22 + -1;

      } while (lVar22 != 0);

      if (0x100 < iVar21) goto LAB_1401a3d20;

      uVar11 = (ulonglong)(bVar18 & 0xf);

      if (bVar4 == 0) {

        iVar9 = FUN_14019cb40(param_1 + uVar11 * 0xd2 + 1,local_78);

        if (iVar9 == 0) {

          return 0;

        }

        lVar22 = uVar11 * 0xd2 + 0x81;

      }

      else {

        iVar9 = FUN_14019cb40(param_1 + uVar11 * 0xd2 + 0x349,local_78);

        if (iVar9 == 0) {

          return 0;

        }

        lVar22 = uVar11 * 0xd2 + 0x3c9;

      }

      lVar24 = 0;

      if (0 < iVar21) {

        do {

          lVar2 = *param_1;

          puVar3 = *(undefined1 **)(lVar2 + 0xc0);

          if (puVar3 < *(undefined1 **)(lVar2 + 200)) {

            uVar20 = *puVar3;

            *(undefined1 **)(lVar2 + 0xc0) = puVar3 + 1;

          }

          else if (*(int *)(lVar2 + 0x30) == 0) {

            uVar20 = 0;

          }

          else {

            FUN_1401a4400(lVar2);

            uVar20 = **(undefined1 **)(lVar2 + 0xc0);

            *(undefined1 **)(lVar2 + 0xc0) = *(undefined1 **)(lVar2 + 0xc0) + 1;

          }

          *(undefined1 *)(lVar24 + (longlong)(param_1 + lVar22)) = uVar20;

          lVar24 = lVar24 + 1;

        } while (lVar24 < iVar21);

      }

      if (bVar4 != 0) {

        FUN_14019ca60(param_1 + uVar11 * 0x80 + 0x6d1,param_1 + uVar11 * 0xd2 + 0x349);

      }

    }

LAB_1401a408e:

    return (ulonglong)(iVar6 == 0);

  }

  if (param_2 == 0xdb) {

    iVar6 = FUN_14019f260();

    for (iVar6 = iVar6 + -2; 0 < iVar6; iVar6 = iVar6 - iVar21) {

      lVar22 = *param_1;

      pbVar10 = *(byte **)(lVar22 + 0xc0);

      if (pbVar10 < *(byte **)(lVar22 + 200)) {

        uVar11 = (ulonglong)*pbVar10;

        *(byte **)(lVar22 + 0xc0) = pbVar10 + 1;

      }

      else if (*(int *)(lVar22 + 0x30) == 0) {

        uVar11 = 0;

      }

      else {

        FUN_1401a4400(lVar22);

        uVar11 = (ulonglong)**(byte **)(lVar22 + 0xc0);

        *(byte **)(lVar22 + 0xc0) = *(byte **)(lVar22 + 0xc0) + 1;

      }

      lVar22 = 0;

      uVar8 = (uint)uVar11 & 0xf;

      uVar11 = uVar11 >> 4;

      if (((uVar11 != 0) && ((int)uVar11 != 1)) || (3 < uVar8)) goto LAB_1401a3d20;

      do {

        lVar24 = *param_1;

        if (uVar11 == 0) {

          pbVar10 = *(byte **)(lVar24 + 0xc0);

          if (pbVar10 < *(byte **)(lVar24 + 200)) {

            bVar18 = *pbVar10;

            *(byte **)(lVar24 + 0xc0) = pbVar10 + 1;

          }

          else if (*(int *)(lVar24 + 0x30) == 0) {

            bVar18 = 0;

          }

          else {

            FUN_1401a4400(lVar24);

            bVar18 = **(byte **)(lVar24 + 0xc0);

            *(byte **)(lVar24 + 0xc0) = *(byte **)(lVar24 + 0xc0) + 1;

          }

          uVar5 = (ushort)bVar18;

        }

        else {

          uVar5 = FUN_14019f260(lVar24);

        }

        pbVar10 = &DAT_14033b3a0 + lVar22;

        lVar22 = lVar22 + 1;

        *(ushort *)

         ((longlong)param_1 + ((ulonglong)*pbVar10 + (ulonglong)uVar8 * 0x40) * 2 + 0x3488) = uVar5;

      } while (lVar22 < 0x40);

      iVar21 = 0x41;

      if (uVar11 != 0) {

        iVar21 = 0x81;

      }

    }

    goto LAB_1401a408e;

  }

  if (param_2 == 0xdd) {

    iVar6 = FUN_14019f260(*param_1);

    if (iVar6 == 4) {

      uVar7 = FUN_14019f260(*param_1);

      *(undefined4 *)(param_1 + 0x90d) = uVar7;

      return 1;

    }

LAB_1401a3d20:

    uVar11 = FUN_14019f050("Corrupt JPEG");

    return uVar11;

  }

  if (((param_2 == 0xff) || ((0xf < param_2 - 0xe0U && (param_2 != 0xfe)))) ||

     (iVar6 = FUN_14019f260(), iVar6 < 2)) goto LAB_1401a3d20;

  iVar21 = iVar6 + -2;

  if (param_2 == 0xe0) {

    if (4 < iVar21) {

      lVar22 = *param_1;

      pcVar1 = *(char **)(lVar22 + 0xc0);

      if (pcVar1 < *(char **)(lVar22 + 200)) {

        cVar12 = *pcVar1;

        *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

      }

      else if (*(int *)(lVar22 + 0x30) == 0) {

        cVar12 = '\0';

      }

      else {

        FUN_1401a4400(lVar22);

        cVar12 = **(char **)(lVar22 + 0xc0);

        *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

      }

      lVar22 = *param_1;

      pcVar1 = *(char **)(lVar22 + 0xc0);

      if (pcVar1 < *(char **)(lVar22 + 200)) {

        cVar13 = *pcVar1;

        *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

      }

      else if (*(int *)(lVar22 + 0x30) == 0) {

        cVar13 = '\0';

      }

      else {

        FUN_1401a4400(lVar22);

        cVar13 = **(char **)(lVar22 + 0xc0);

        *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

      }

      lVar22 = *param_1;

      pcVar1 = *(char **)(lVar22 + 0xc0);

      if (pcVar1 < *(char **)(lVar22 + 200)) {

        cVar14 = *pcVar1;

        *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

      }

      else if (*(int *)(lVar22 + 0x30) == 0) {

        cVar14 = '\0';

      }

      else {

        FUN_1401a4400(lVar22);

        cVar14 = **(char **)(lVar22 + 0xc0);

        *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

      }

      lVar22 = *param_1;

      pcVar1 = *(char **)(lVar22 + 0xc0);

      if (pcVar1 < *(char **)(lVar22 + 200)) {

        cVar15 = *pcVar1;

        *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

      }

      else if (*(int *)(lVar22 + 0x30) == 0) {

        cVar15 = '\0';

      }

      else {

        FUN_1401a4400(lVar22);

        cVar15 = **(char **)(lVar22 + 0xc0);

        *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

      }

      lVar22 = *param_1;

      pcVar1 = *(char **)(lVar22 + 0xc0);

      if (pcVar1 < *(char **)(lVar22 + 200)) {

        cVar16 = *pcVar1;

        *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

      }

      else if (*(int *)(lVar22 + 0x30) == 0) {

        cVar16 = '\0';

      }

      else {

        FUN_1401a4400(lVar22);

        cVar16 = **(char **)(lVar22 + 0xc0);

        *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

      }

      iVar21 = iVar6 + -7;

      if (cVar16 == '\0' && (cVar15 == 'F' && (cVar14 == 'I' && (cVar13 == 'F' && cVar12 == 'J'))))

      {

        *(undefined4 *)(param_1 + 0x909) = 1;

        FUN_1401a4ad0(*param_1,iVar21);

        return 1;

      }

    }

    goto LAB_1401a3d0c;

  }

  if ((param_2 != 0xee) || (iVar21 < 0xc)) goto LAB_1401a3d0c;

  lVar22 = *param_1;

  pcVar1 = *(char **)(lVar22 + 0xc0);

  if (pcVar1 < *(char **)(lVar22 + 200)) {

    cVar12 = *pcVar1;

    *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

  }

  else if (*(int *)(lVar22 + 0x30) == 0) {

    cVar12 = '\0';

  }

  else {

    FUN_1401a4400(lVar22);

    cVar12 = **(char **)(lVar22 + 0xc0);

    *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

  }

  lVar22 = *param_1;

  pcVar1 = *(char **)(lVar22 + 0xc0);

  if (pcVar1 < *(char **)(lVar22 + 200)) {

    cVar13 = *pcVar1;

    *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

  }

  else if (*(int *)(lVar22 + 0x30) == 0) {

    cVar13 = '\0';

  }

  else {

    FUN_1401a4400(lVar22);

    cVar13 = **(char **)(lVar22 + 0xc0);

    *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

  }

  lVar22 = *param_1;

  pcVar1 = *(char **)(lVar22 + 0xc0);

  if (pcVar1 < *(char **)(lVar22 + 200)) {

    cVar14 = *pcVar1;

    *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

  }

  else if (*(int *)(lVar22 + 0x30) == 0) {

    cVar14 = '\0';

  }

  else {

    FUN_1401a4400(lVar22);

    cVar14 = **(char **)(lVar22 + 0xc0);

    *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

  }

  lVar22 = *param_1;

  pcVar1 = *(char **)(lVar22 + 0xc0);

  if (pcVar1 < *(char **)(lVar22 + 200)) {

    cVar15 = *pcVar1;

    *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

  }

  else if (*(int *)(lVar22 + 0x30) == 0) {

    cVar15 = '\0';

  }

  else {

    FUN_1401a4400(lVar22);

    cVar15 = **(char **)(lVar22 + 0xc0);

    *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

  }

  lVar22 = *param_1;

  pcVar1 = *(char **)(lVar22 + 0xc0);

  if (pcVar1 < *(char **)(lVar22 + 200)) {

    cVar16 = *pcVar1;

    *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

  }

  else if (*(int *)(lVar22 + 0x30) == 0) {

    cVar16 = '\0';

  }

  else {

    FUN_1401a4400(lVar22);

    cVar16 = **(char **)(lVar22 + 0xc0);

    *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

  }

  lVar22 = *param_1;

  pcVar1 = *(char **)(lVar22 + 0xc0);

  if (pcVar1 < *(char **)(lVar22 + 200)) {

    cVar17 = *pcVar1;

    *(char **)(lVar22 + 0xc0) = pcVar1 + 1;

  }

  else if (*(int *)(lVar22 + 0x30) == 0) {

    cVar17 = '\0';

  }

  else {

    FUN_1401a4400(lVar22);

    cVar17 = **(char **)(lVar22 + 0xc0);

    *(char **)(lVar22 + 0xc0) = *(char **)(lVar22 + 0xc0) + 1;

  }

  iVar21 = iVar6 + -8;

  if (cVar17 != '\0' ||

      (cVar16 != 'e' || (cVar15 != 'b' || (cVar14 != 'o' || (cVar13 != 'd' || cVar12 != 'A')))))

  goto LAB_1401a3d0c;

  lVar22 = *param_1;

  if (*(ulonglong *)(lVar22 + 0xc0) < *(ulonglong *)(lVar22 + 200)) {

    *(ulonglong *)(lVar22 + 0xc0) = *(ulonglong *)(lVar22 + 0xc0) + 1;

  }

  else if (*(int *)(lVar22 + 0x30) != 0) {

    FUN_1401a4400(lVar22);

    *(longlong *)(lVar22 + 0xc0) = *(longlong *)(lVar22 + 0xc0) + 1;

  }

  FUN_14019f260(*param_1);

  FUN_14019f260();

  lVar22 = *param_1;

  pbVar10 = *(byte **)(lVar22 + 0xc0);

  if (pbVar10 < *(byte **)(lVar22 + 200)) {

LAB_1401a3cef:

    bVar18 = *pbVar10;

    *(byte **)(lVar22 + 0xc0) = pbVar10 + 1;

  }

  else {

    if (*(int *)(lVar22 + 0x30) != 0) {

      FUN_1401a4400(lVar22);

      pbVar10 = *(byte **)(lVar22 + 0xc0);

      goto LAB_1401a3cef;

    }

    bVar18 = 0;

  }

  iVar21 = iVar6 + -0xe;

  *(uint *)((longlong)param_1 + 0x484c) = (uint)bVar18;

LAB_1401a3d0c:

  FUN_1401a4ad0(*param_1,iVar21);

  return 1;

}




