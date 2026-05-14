// Address: 0x140055520
// Ghidra name: FUN_140055520
// ============ 0x140055520 FUN_140055520 (size=1529) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_140055520(longlong param_1,ulonglong param_2,int param_3)



{

  longlong lVar1;

  int *piVar2;

  undefined1 auVar3 [13];

  undefined1 auVar4 [13];

  uint5 uVar5;

  undefined1 auVar6 [13];

  undefined1 auVar7 [13];

  undefined4 *puVar8;

  uint *puVar9;

  uint uVar10;

  ulonglong uVar11;

  int iVar12;

  longlong lVar13;

  int iVar14;

  ulonglong uVar15;

  byte *pbVar16;

  ulonglong uVar17;

  byte *pbVar18;

  int *piVar19;

  uint uVar20;

  uint uVar22;

  ulonglong uVar24;

  ulonglong uVar25;

  int iVar26;

  int iVar27;

  int iVar28;

  int iVar29;

  int iVar30;

  int iVar31;

  int iVar32;

  int iVar33;

  ulonglong uVar21;

  ulonglong uVar23;

  

  uVar15 = 0;

  iVar12 = *(int *)(param_1 + 0x710);

  if (0 < iVar12) {

    puVar8 = (undefined4 *)(param_1 + 0x720);

    uVar11 = uVar15;

    do {

      *puVar8 = 0;

      puVar8 = puVar8 + 5;

      iVar12 = *(int *)(param_1 + 0x710);

      uVar10 = (int)uVar11 + 1;

      uVar11 = (ulonglong)uVar10;

    } while ((int)uVar10 < iVar12);

  }

  uVar11 = (longlong)param_3;

  if (iVar12 < 4) {

    if (param_3 < 4) {

      return 0;

    }

    pbVar18 = (byte *)(param_2 + 1);

    uVar25 = ~param_2;

    uVar10 = param_3 - 3;

    uVar24 = (ulonglong)uVar10;

    uVar17 = uVar15;

    do {

      iVar12 = (int)uVar17;

      if ((pbVar18[-1] == 0x4f) && (*(int *)((longlong)iVar12 + param_2) == _DAT_1403d45d8)) {

        uVar11 = uVar17;

        if ((int)uVar10 <= iVar12 + 0x1a) break;

        uVar22 = (uint)pbVar18[0x19];

        uVar17 = (ulonglong)uVar22;

        if ((int)uVar10 <= (int)(uVar22 + 0x1b + iVar12)) break;

        iVar14 = uVar22 + 0x1b;

        uVar11 = uVar15;

        if (7 < uVar22) {

          iVar30 = 0;

          iVar31 = 0;

          iVar32 = 0;

          iVar33 = 0;

          iVar26 = 0;

          iVar27 = 0;

          iVar28 = 0;

          iVar29 = 0;

          puVar9 = (uint *)(pbVar18 + 0x1e);

          do {

            uVar20 = puVar9[-1];

            uVar11 = uVar11 + 8;

            auVar3[0xc] = (char)(uVar20 >> 0x18);

            auVar3._0_12_ = ZEXT712(0);

            uVar5 = CONCAT32(auVar3._10_3_,(ushort)(byte)(uVar20 >> 0x10));

            auVar6._5_8_ = 0;

            auVar6._0_5_ = uVar5;

            iVar30 = iVar30 + (uVar20 & 0xff);

            iVar31 = iVar31 + (int)CONCAT72(SUB137(auVar6 << 0x40,6),(ushort)(byte)(uVar20 >> 8));

            iVar32 = iVar32 + (int)uVar5;

            iVar33 = iVar33 + (uint)(uint3)(auVar3._10_3_ >> 0x10);

            uVar20 = *puVar9;

            auVar4[0xc] = (char)(uVar20 >> 0x18);

            auVar4._0_12_ = ZEXT712(0);

            uVar5 = CONCAT32(auVar4._10_3_,(ushort)(byte)(uVar20 >> 0x10));

            auVar7._5_8_ = 0;

            auVar7._0_5_ = uVar5;

            iVar26 = iVar26 + (uVar20 & 0xff);

            iVar27 = iVar27 + (int)CONCAT72(SUB137(auVar7 << 0x40,6),(ushort)(byte)(uVar20 >> 8));

            iVar28 = iVar28 + (int)uVar5;

            iVar29 = iVar29 + (uint)(uint3)(auVar4._10_3_ >> 0x10);

            puVar9 = puVar9 + 2;

          } while ((longlong)uVar11 < (longlong)((ulonglong)uVar22 & 0xfffffff8));

          iVar14 = iVar14 + iVar26 + iVar30 + iVar28 + iVar32 + iVar27 + iVar31 + iVar29 + iVar33;

        }

        if ((longlong)uVar11 < (longlong)uVar17) {

          uVar22 = 0;

          uVar20 = 0;

          if (1 < (longlong)(uVar17 - uVar11)) {

            lVar1 = uVar11 + 0x1c;

            lVar13 = ((uVar17 - uVar11) - 2 >> 1) + 1;

            uVar11 = uVar11 + lVar13 * 2;

            pbVar16 = pbVar18 + param_2 + uVar25 + lVar1;

            uVar21 = uVar15;

            uVar23 = uVar15;

            do {

              uVar20 = (int)uVar21 + (uint)pbVar16[-1];

              uVar21 = (ulonglong)uVar20;

              uVar22 = (int)uVar23 + (uint)*pbVar16;

              uVar23 = (ulonglong)uVar22;

              lVar13 = lVar13 + -1;

              pbVar16 = pbVar16 + 2;

            } while (lVar13 != 0);

          }

          if ((longlong)uVar11 < (longlong)uVar17) {

            iVar14 = iVar14 + (uint)pbVar18[param_2 + uVar25 + uVar11 + 0x1b];

          }

          iVar14 = iVar14 + uVar22 + uVar20;

        }

        uVar22 = (&DAT_1403ea2f0)[pbVar18[-1]] << 8 ^

                 (&DAT_1403ea2f0)

                 [(ulonglong)((uint)(&DAT_1403ea2f0)[pbVar18[-1]] >> 0x18) ^ (ulonglong)*pbVar18];

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[1]]

        ;

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[2]]

        ;

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[3]]

        ;

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[4]]

        ;

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[5]]

        ;

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[6]]

        ;

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[7]]

        ;

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[8]]

        ;

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[9]]

        ;

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[10]];

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[0xb]];

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[0xc]];

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[0xd]];

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[0xe]];

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[0xf]];

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[0x10]];

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[0x11]];

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[0x12]];

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[0x13]];

        uVar22 = uVar22 << 8 ^

                 (&DAT_1403ea2f0)[(ulonglong)(uVar22 >> 0x18) ^ (ulonglong)pbVar18[0x14]];

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[uVar22 >> 0x18];

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[uVar22 >> 0x18];

        uVar22 = uVar22 << 8 ^ (&DAT_1403ea2f0)[uVar22 >> 0x18];

        iVar26 = *(int *)(param_1 + 0x710);

        *(int *)(param_1 + 0x710) = iVar26 + 1;

        lVar1 = param_1 + (longlong)iVar26 * 0x14;

        *(int *)(lVar1 + 0x718) = iVar14 + -0x1a;

        *(uint *)(param_1 + 0x71c + (longlong)iVar26 * 0x14) =

             uVar22 << 8 ^ (&DAT_1403ea2f0)[uVar22 >> 0x18];

        *(uint *)(lVar1 + 0x714) =

             (uint)pbVar18[0x18] * 0x1000000 + (uint)pbVar18[0x17] * 0x10000 +

             (uint)pbVar18[0x16] * 0x100 + (uint)pbVar18[0x15];

        if (*(char *)((longlong)(int)((uint)pbVar18[0x19] + iVar12) + 0x1a + param_2) == -1) {

          iVar14 = -1;

        }

        else {

          iVar14 = (uint)pbVar18[7] * 0x10000 + (uint)pbVar18[8] * 0x1000000 +

                   (uint)pbVar18[6] * 0x100 + (uint)pbVar18[5];

        }

        *(int *)(lVar1 + 0x724) = iVar14;

        *(int *)(lVar1 + 0x720) = iVar12 + 0x1a;

        if (*(int *)(param_1 + 0x710) == 4) goto LAB_140055a18;

      }

      pbVar18 = pbVar18 + 1;

      uVar17 = (ulonglong)(iVar12 + 1);

      uVar11 = uVar24;

    } while ((longlong)(pbVar18 + uVar25) < (longlong)((longlong)param_3 - 3U));

  }

  uVar24 = uVar11;

  if (0 < *(int *)(param_1 + 0x710)) {

LAB_140055a18:

    piVar19 = (int *)(param_1 + 0x718);

    uVar11 = uVar15;

    do {

      iVar12 = piVar19[2];

      uVar10 = piVar19[1];

      iVar14 = (int)uVar24 - iVar12;

      if (*piVar19 <= iVar14) {

        iVar14 = *piVar19;

      }

      if (0 < iVar14) {

        uVar17 = uVar15;

        do {

          pbVar18 = (byte *)(uVar17 + param_2 + (longlong)iVar12);

          uVar17 = uVar17 + 1;

          uVar10 = uVar10 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)*pbVar18 ^ (ulonglong)(uVar10 >> 0x18)]

          ;

        } while ((longlong)uVar17 < (longlong)iVar14);

      }

      *piVar19 = *piVar19 - iVar14;

      piVar19[1] = uVar10;

      if (*piVar19 == 0) {

        if (uVar10 == piVar19[-1]) {

          *(undefined4 *)(param_1 + 0x4f8) = 0;

          *(undefined4 *)(param_1 + 0x710) = 0xffffffff;

          *(undefined4 *)(param_1 + 0x6e8) = 0xffffffff;

          iVar26 = *(int *)(param_1 + 0x724 + (longlong)(int)uVar11 * 0x14);

          *(int *)(param_1 + 0x580) = iVar26;

          *(uint *)(param_1 + 0x584) = (uint)(iVar26 != -1);

          return (ulonglong)(uint)(iVar14 + iVar12);

        }

        iVar12 = *(int *)(param_1 + 0x710);

        *(int *)(param_1 + 0x710) = iVar12 + -1;

        piVar2 = (int *)(param_1 + 0x700 + (longlong)iVar12 * 0x14);

        iVar14 = piVar2[1];

        iVar26 = piVar2[2];

        iVar27 = piVar2[3];

        piVar19[-1] = *piVar2;

        *piVar19 = iVar14;

        piVar19[1] = iVar26;

        piVar19[2] = iVar27;

        piVar19[3] = *(int *)(param_1 + 0x710 + (longlong)iVar12 * 0x14);

      }

      else {

        uVar11 = (ulonglong)((int)uVar11 + 1);

        piVar19 = piVar19 + 5;

      }

    } while ((int)uVar11 < *(int *)(param_1 + 0x710));

  }

  return uVar24 & 0xffffffff;

}




