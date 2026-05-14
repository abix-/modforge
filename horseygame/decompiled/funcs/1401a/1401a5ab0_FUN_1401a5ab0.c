// Address: 0x1401a5ab0
// Ghidra name: FUN_1401a5ab0
// ============ 0x1401a5ab0 FUN_1401a5ab0 (size=2304) ============


uint FUN_1401a5ab0(longlong param_1)



{

  uint *puVar1;

  int *piVar2;

  byte *pbVar3;

  char *pcVar4;

  short *psVar5;

  byte bVar6;

  char cVar7;

  ushort uVar8;

  int iVar9;

  short sVar10;

  longlong lVar11;

  uint uVar12;

  uint uVar13;

  ulonglong uVar14;

  char cVar15;

  ulonglong uVar16;

  uint uVar17;

  int iVar18;

  uint uVar19;

  ulonglong uVar20;

  char *pcVar21;

  uint uVar22;

  uint uVar23;

  uint uVar24;

  char *pcVar25;

  char cVar26;

  uint uVar27;

  byte *pbVar28;

  uint local_res8;

  ulonglong local_70;

  byte *local_68;

  

  pbVar28 = *(byte **)(param_1 + 0xb0);

  puVar1 = (uint *)(param_1 + 0x28);

  uVar16 = *(ulonglong *)(param_1 + 0xb8);

  iVar9 = *(int *)(param_1 + 0xa8);

  local_70 = uVar16;

  local_68 = pbVar28;

  do {

    if ((uVar16 == 0) && ((iVar9 == 0 || (*puVar1 == 0)))) {

LAB_1401a6385:

      *(byte **)(param_1 + 0xb0) = pbVar28;

      *(ulonglong *)(param_1 + 0xb8) = uVar16;

      return 1;

    }

    uVar17 = *puVar1;

    uVar24 = *(uint *)(param_1 + 0x2c);

    if (uVar24 + uVar17 < 2) {

      while ((uVar16 != 0 && (local_70 = uVar16, local_68 = pbVar28, uVar17 < 0x102))) {

        uVar16 = uVar16 - 1;

        bVar6 = *pbVar28;

        uVar24 = uVar17 + *(int *)(param_1 + 0x24) & 0x7fff;

        pbVar28 = pbVar28 + 1;

        *(byte *)((ulonglong)uVar24 + 200 + param_1) = bVar6;

        if (uVar24 < 0x101) {

          *(byte *)((ulonglong)(uVar24 + 0x8000) + 200 + param_1) = bVar6;

        }

        uVar24 = *(uint *)(param_1 + 0x2c);

        uVar17 = *puVar1 + 1;

        *puVar1 = uVar17;

        local_70 = uVar16;

        local_68 = pbVar28;

        if (2 < uVar24 + uVar17) {

          uVar17 = *(int *)(param_1 + 0x24) + -3 + uVar17;

          uVar14 = (ulonglong)

                   (((uint)*(byte *)((ulonglong)(uVar17 + 1 & 0x7fff) + 200 + param_1) ^

                    (uint)*(byte *)((ulonglong)(uVar17 & 0x7fff) + 200 + param_1) << 5) & 0x3ff) <<

                   5 ^ (ulonglong)bVar6;

          *(undefined2 *)(param_1 + 0x192aa + (ulonglong)(uVar17 & 0x7fff) * 2) =

               *(undefined2 *)(param_1 + 0x292aa + uVar14 * 2);

          *(short *)(param_1 + 0x292aa + uVar14 * 2) = (short)uVar17;

          uVar17 = *puVar1;

          uVar24 = *(uint *)(param_1 + 0x2c);

        }

      }

    }

    else {

      uVar12 = *(int *)(param_1 + 0x24) + uVar17;

      uVar22 = uVar12 - 2;

      uVar20 = (ulonglong)

               ((uint)*(byte *)((ulonglong)(uVar22 & 0x7fff) + 200 + param_1) << 5 ^

               (uint)*(byte *)((ulonglong)(uVar12 - 1 & 0x7fff) + 200 + param_1));

      uVar14 = (ulonglong)(0x102 - uVar17);

      if (uVar16 < uVar14) {

        uVar14 = uVar16 & 0xffffffff;

      }

      uVar17 = uVar17 + (int)uVar14;

      uVar16 = uVar16 - uVar14;

      *(uint *)(param_1 + 0x28) = uVar17;

      local_70 = uVar16;

      if ((pbVar28 != (byte *)0x0) && (pbVar3 = pbVar28 + uVar14, pbVar28 != pbVar3)) {

        do {

          uVar12 = uVar12 & 0x7fff;

          bVar6 = *pbVar28;

          pbVar28 = pbVar28 + 1;

          *(byte *)((ulonglong)uVar12 + 200 + param_1) = bVar6;

          if (uVar12 < 0x101) {

            *(byte *)((ulonglong)(uVar12 + 0x8000) + 200 + param_1) = bVar6;

          }

          uVar20 = (ulonglong)(((int)uVar20 << 5 ^ (uint)bVar6) & 0x7fff);

          uVar12 = uVar12 + 1;

          lVar11 = param_1 + uVar20 * 2;

          *(undefined2 *)(param_1 + 0x192aa + (ulonglong)(uVar22 & 0x7fff) * 2) =

               *(undefined2 *)(lVar11 + 0x292aa);

          *(short *)(lVar11 + 0x292aa) = (short)uVar22;

          uVar22 = uVar22 + 1;

        } while (pbVar28 != pbVar3);

        uVar24 = *(uint *)(param_1 + 0x2c);

        uVar17 = *(uint *)(param_1 + 0x28);

        local_68 = pbVar28;

      }

    }

    uVar22 = 0x8000 - uVar17;

    if (uVar24 <= 0x8000 - uVar17) {

      uVar22 = uVar24;

    }

    *(uint *)(param_1 + 0x2c) = uVar22;

    if ((iVar9 == 0) && (uVar17 < 0x102)) goto LAB_1401a6385;

    uVar24 = 0;

    local_res8 = 0;

    uVar12 = 2;

    if (*(uint *)(param_1 + 0x68) != 0) {

      uVar12 = *(uint *)(param_1 + 0x68);

    }

    uVar19 = *(uint *)(param_1 + 0x24) & 0x7fff;

    uVar14 = (ulonglong)uVar19;

    uVar23 = uVar24;

    uVar27 = uVar12;

    if ((*(uint *)(param_1 + 0x10) & 0x90000) == 0) {

      lVar11 = 0x14;

      if (0x1f < uVar12) {

        lVar11 = 0x18;

      }

      cVar26 = *(char *)((ulonglong)(uVar19 + uVar12) + 200 + param_1);

      pcVar25 = (char *)((ulonglong)uVar19 + 200 + param_1);

      iVar18 = *(int *)(lVar11 + param_1);

      cVar15 = *(char *)((ulonglong)((uVar19 + uVar12) - 1) + 200 + param_1);

      uVar16 = local_70;

      pbVar28 = local_68;

      if (uVar12 < uVar17) {

LAB_1401a5e10:

        iVar18 = iVar18 + -1;

        uVar23 = local_res8;

        if ((iVar18 != 0) && (uVar8 = *(ushort *)(param_1 + 0x192aa + uVar14 * 2), uVar8 != 0)) {

          sVar10 = (short)*(uint *)(param_1 + 0x24);

          uVar24 = (uint)(ushort)(sVar10 - uVar8);

          if (uVar24 <= uVar22) {

            uVar14 = (ulonglong)(uVar8 & 0x7fff);

            uVar13 = (uVar8 & 0x7fff) + uVar12;

            if ((*(char *)((ulonglong)uVar13 + 200 + param_1) == cVar26) &&

               (*(char *)((ulonglong)(uVar13 - 1) + 200 + param_1) == cVar15)) goto LAB_1401a5f0b;

            uVar8 = *(ushort *)(param_1 + 0x192aa + uVar14 * 2);

            if ((uVar8 != 0) && (uVar24 = (uint)(ushort)(sVar10 - uVar8), uVar24 <= uVar22)) {

              uVar14 = (ulonglong)(uVar8 & 0x7fff);

              uVar13 = (uVar8 & 0x7fff) + uVar12;

              if ((*(char *)((ulonglong)uVar13 + 200 + param_1) == cVar26) &&

                 (*(char *)((ulonglong)(uVar13 - 1) + 200 + param_1) == cVar15)) goto LAB_1401a5f0b;

              uVar8 = *(ushort *)(param_1 + 0x192aa + uVar14 * 2);

              if ((uVar8 != 0) && (uVar24 = (uint)(ushort)(sVar10 - uVar8), uVar24 <= uVar22))

              break;

            }

          }

        }

      }

      goto LAB_1401a5fb7;

    }

    if ((uVar22 == 0) || (uVar23 = 0, (*(uint *)(param_1 + 0x10) >> 0x13 & 1) != 0)) {

LAB_1401a5fb7:

      uVar24 = uVar23;

      if ((uVar27 != 3) || (uVar23 < 0x2000)) goto LAB_1401a5fc6;

LAB_1401a5fda:

      uVar27 = 0;

      uVar24 = 0;

    }

    else {

      uVar27 = 0;

      if (uVar17 != 0) {

        do {

          if (*(char *)((ulonglong)(uVar19 + uVar27) + 200 + param_1) !=

              *(char *)((ulonglong)(uVar19 - 1 & 0x7fff) + 200 + param_1)) break;

          uVar27 = uVar27 + 1;

        } while (uVar27 < uVar17);

        if (2 < uVar27) {

          uVar23 = 1;

          goto LAB_1401a5fb7;

        }

      }

      uVar27 = 0;

LAB_1401a5fc6:

      if ((uVar19 == uVar24) || (((*(uint *)(param_1 + 0x10) & 0x20000) != 0 && (uVar27 < 6))))

      goto LAB_1401a5fda;

    }

    uVar22 = 1;

    uVar14 = (ulonglong)uVar19;

    uVar17 = *(uint *)(param_1 + 0x68);

    if (uVar17 == 0) {

      if (uVar24 == 0) {

        bVar6 = *(byte *)(uVar14 + 200 + param_1);

        *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;

        **(byte **)(param_1 + 0x30) = bVar6;

        *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x30) + 1;

        **(byte **)(param_1 + 0x38) = **(byte **)(param_1 + 0x38) >> 1;

        piVar2 = (int *)(param_1 + 0x50);

        *piVar2 = *piVar2 + -1;

        if (*piVar2 == 0) {

          *(longlong *)(param_1 + 0x38) = *(longlong *)(param_1 + 0x30);

          *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x30) + 1;

          *(undefined4 *)(param_1 + 0x50) = 8;

        }

        psVar5 = (short *)(param_1 + 0x81ca + (ulonglong)bVar6 * 2);

        *psVar5 = *psVar5 + 1;

        uVar27 = uVar22;

      }

      else if (((*(int *)(param_1 + 0x1c) == 0) && ((*(uint *)(param_1 + 0x10) & 0x10000) == 0)) &&

              (uVar27 < 0x80)) {

        *(uint *)(param_1 + 0x6c) = (uint)*(byte *)(uVar14 + 200 + param_1);

        *(uint *)(param_1 + 100) = uVar24;

        *(uint *)(param_1 + 0x68) = uVar27;

        uVar27 = uVar22;

      }

      else {

        *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + uVar27;

        uVar24 = uVar24 - 1;

        **(char **)(param_1 + 0x30) = (char)uVar27 + -3;

        *(char *)(*(longlong *)(param_1 + 0x30) + 1) = (char)uVar24;

        *(char *)(*(longlong *)(param_1 + 0x30) + 2) = (char)(uVar24 >> 8);

        *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x30) + 3;

        **(byte **)(param_1 + 0x38) = **(byte **)(param_1 + 0x38) >> 1 | 0x80;

        piVar2 = (int *)(param_1 + 0x50);

        *piVar2 = *piVar2 + -1;

        if (*piVar2 == 0) {

          *(longlong *)(param_1 + 0x38) = *(longlong *)(param_1 + 0x30);

          *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x30) + 1;

          *(undefined4 *)(param_1 + 0x50) = 8;

        }

        bVar6 = (&DAT_14033bd60)[uVar24 >> 8 & 0x7f];

        if (uVar24 < 0x200) {

          bVar6 = (&DAT_14033b960)[uVar24 & 0x1ff];

        }

        psVar5 = (short *)(param_1 + 0x840a + (ulonglong)bVar6 * 2);

        *psVar5 = *psVar5 + 1;

        if (2 < uVar27) {

          psVar5 = (short *)(param_1 + 0x81ca +

                            (ulonglong)*(ushort *)(&DAT_14033b660 + (ulonglong)(uVar27 - 3) * 2) * 2

                            );

          *psVar5 = *psVar5 + 1;

        }

      }

    }

    else if (uVar17 < uVar27) {

      bVar6 = *(byte *)(param_1 + 0x6c);

      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;

      **(byte **)(param_1 + 0x30) = bVar6;

      *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x30) + 1;

      **(byte **)(param_1 + 0x38) = **(byte **)(param_1 + 0x38) >> 1;

      piVar2 = (int *)(param_1 + 0x50);

      *piVar2 = *piVar2 + -1;

      if (*piVar2 == 0) {

        *(longlong *)(param_1 + 0x38) = *(longlong *)(param_1 + 0x30);

        *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x30) + 1;

        *(undefined4 *)(param_1 + 0x50) = 8;

      }

      psVar5 = (short *)(param_1 + 0x81ca + (ulonglong)bVar6 * 2);

      *psVar5 = *psVar5 + 1;

      if (uVar27 < 0x80) {

        *(uint *)(param_1 + 0x6c) = (uint)*(byte *)(uVar14 + 200 + param_1);

        *(uint *)(param_1 + 100) = uVar24;

        *(uint *)(param_1 + 0x68) = uVar27;

        uVar27 = uVar22;

      }

      else {

        *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + uVar27;

        uVar24 = uVar24 - 1;

        **(char **)(param_1 + 0x30) = (char)uVar27 + -3;

        *(char *)(*(longlong *)(param_1 + 0x30) + 1) = (char)uVar24;

        *(char *)(*(longlong *)(param_1 + 0x30) + 2) = (char)(uVar24 >> 8);

        *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x30) + 3;

        **(byte **)(param_1 + 0x38) = **(byte **)(param_1 + 0x38) >> 1 | 0x80;

        piVar2 = (int *)(param_1 + 0x50);

        *piVar2 = *piVar2 + -1;

        if (*piVar2 == 0) {

          *(longlong *)(param_1 + 0x38) = *(longlong *)(param_1 + 0x30);

          *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x30) + 1;

          *(undefined4 *)(param_1 + 0x50) = 8;

        }

        bVar6 = (&DAT_14033bd60)[uVar24 >> 8 & 0x7f];

        if (uVar24 < 0x200) {

          bVar6 = (&DAT_14033b960)[uVar24 & 0x1ff];

        }

        psVar5 = (short *)(param_1 + 0x840a + (ulonglong)bVar6 * 2);

        *psVar5 = *psVar5 + 1;

        psVar5 = (short *)(param_1 + 0x81ca +

                          (ulonglong)*(ushort *)(&DAT_14033b660 + (ulonglong)(uVar27 - 3) * 2) * 2);

        *psVar5 = *psVar5 + 1;

        *(undefined4 *)(param_1 + 0x68) = 0;

      }

    }

    else {

      *(uint *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + uVar17;

      uVar24 = *(int *)(param_1 + 100) - 1;

      **(byte **)(param_1 + 0x30) = (char)uVar17 - 3;

      *(char *)(*(longlong *)(param_1 + 0x30) + 1) = (char)uVar24;

      *(char *)(*(longlong *)(param_1 + 0x30) + 2) = (char)(uVar24 >> 8);

      *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x30) + 3;

      **(byte **)(param_1 + 0x38) = **(byte **)(param_1 + 0x38) >> 1 | 0x80;

      piVar2 = (int *)(param_1 + 0x50);

      *piVar2 = *piVar2 + -1;

      if (*piVar2 == 0) {

        *(longlong *)(param_1 + 0x38) = *(longlong *)(param_1 + 0x30);

        *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x30) + 1;

        *(undefined4 *)(param_1 + 0x50) = 8;

      }

      bVar6 = (&DAT_14033bd60)[uVar24 >> 8 & 0x7f];

      if (uVar24 < 0x200) {

        bVar6 = (&DAT_14033b960)[uVar24 & 0x1ff];

      }

      psVar5 = (short *)(param_1 + 0x840a + (ulonglong)bVar6 * 2);

      *psVar5 = *psVar5 + 1;

      if (2 < uVar17) {

        psVar5 = (short *)(param_1 + 0x81ca +

                          (ulonglong)*(ushort *)(&DAT_14033b660 + (ulonglong)(uVar17 - 3) * 2) * 2);

        *psVar5 = *psVar5 + 1;

      }

      iVar18 = *(int *)(param_1 + 0x68);

      *(undefined4 *)(param_1 + 0x68) = 0;

      uVar27 = iVar18 - 1;

    }

    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + uVar27;

    uVar17 = *(int *)(param_1 + 0x2c) + uVar27;

    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - uVar27;

    uVar24 = 0x8000;

    if (uVar17 < 0x8000) {

      uVar24 = uVar17;

    }

    *(uint *)(param_1 + 0x2c) = uVar24;

    if ((param_1 + 0x192a2U < *(ulonglong *)(param_1 + 0x30)) ||

       ((0x7c00 < *(uint *)(param_1 + 0x54) &&

        ((*(uint *)(param_1 + 0x54) <=

          ((int)*(ulonglong *)(param_1 + 0x30) - (int)param_1) * 0x73 - 0x41e25eU >> 7 ||

         ((*(uint *)(param_1 + 0x10) & 0x80000) != 0)))))) {

      *(byte **)(param_1 + 0xb0) = pbVar28;

      *(ulonglong *)(param_1 + 0xb8) = uVar16;

      uVar24 = FUN_1401a63b0(param_1,0);

      if (uVar24 != 0) {

        return ~uVar24 >> 0x1f;

      }

    }

  } while( true );

  uVar14 = (ulonglong)(uVar8 & 0x7fff);

  uVar13 = (uVar8 & 0x7fff) + uVar12;

  if ((*(char *)((ulonglong)uVar13 + 200 + param_1) == cVar26) &&

     (*(char *)((ulonglong)(uVar13 - 1) + 200 + param_1) == cVar15)) {

LAB_1401a5f0b:

    if (uVar24 == 0) goto LAB_1401a5fb7;

    uVar13 = 0;

    if (uVar17 != 0) {

      pcVar21 = pcVar25;

      do {

        cVar7 = *pcVar21;

        pcVar4 = pcVar21 + (uVar14 - (longlong)pcVar25) + param_1 + 200;

        pcVar21 = pcVar21 + 1;

        if (cVar7 != *pcVar4) break;

        uVar13 = uVar13 + 1;

      } while (uVar13 < uVar17);

      if (uVar12 < uVar13) {

        uVar23 = uVar24;

        uVar27 = uVar13;

        if (uVar13 == uVar17) goto LAB_1401a5fb7;

        cVar26 = *(char *)((ulonglong)(uVar19 + uVar13) + 200 + param_1);

        cVar15 = *(char *)((ulonglong)((uVar19 + uVar13) - 1) + 200 + param_1);

        uVar12 = uVar13;

        local_res8 = uVar24;

      }

    }

  }

  goto LAB_1401a5e10;

}




