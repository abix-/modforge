// Address: 0x1402ad410
// Ghidra name: FUN_1402ad410
// ============ 0x1402ad410 FUN_1402ad410 (size=1362) ============


void FUN_1402ad410(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  uint uVar4;

  short sVar5;

  short sVar6;

  short sVar7;

  uint uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  short sVar11;

  ulonglong uVar12;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  ushort uVar17;

  ulonglong uVar18;

  ushort uVar19;

  uint uVar20;

  uint uVar21;

  uint *puVar22;

  uint uVar23;

  ulonglong uVar24;

  ushort uVar25;

  

  bVar1 = *(byte *)(param_1 + 0x80);

  uVar4 = *(uint *)(param_1 + 0x78);

  uVar18 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar24 = (ulonglong)*(int *)(param_1 + 0x38);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  uVar25 = 0xff;

  if ((uVar4 & 2) != 0) {

    uVar25 = (ushort)*(byte *)(param_1 + 0x83);

  }

  uVar9 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar18;

  uVar10 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar24;

  uVar12 = uVar9 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar22 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar18 + -1;

      if ((int)uVar24 != 0) {

        uVar14 = uVar4 & 0x3f0;

        uVar18 = uVar10 >> 1;

        do {

          uVar23 = (int)uVar24 - 1;

          uVar24 = (ulonglong)uVar23;

          uVar15 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar12 >> 0x10) +

                             (uVar18 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar13 = uVar15 >> 0x10 & 0xff;

          uVar16 = uVar15 >> 8 & 0xff;

          uVar15 = uVar15 & 0xff;

          uVar21 = *puVar22;

          uVar8 = uVar21 >> 0x10 & 0xff;

          uVar20 = uVar21 >> 8 & 0xff;

          uVar21 = uVar21 & 0xff;

          if ((uVar4 & 1) != 0) {

            uVar17 = (ushort)bVar1 * (short)uVar13 + 1;

            uVar19 = (ushort)bVar3 * (short)uVar15 + 1;

            uVar13 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            uVar17 = (ushort)bVar2 * (short)uVar16 + 1;

            uVar16 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            uVar15 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          }

          if (((uVar4 & 0x50) != 0) && (uVar25 < 0xff)) {

            uVar17 = (short)uVar13 * uVar25 + 1;

            uVar13 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            uVar17 = (short)uVar16 * uVar25 + 1;

            uVar16 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            uVar17 = uVar25 * (short)uVar15 + 1;

            uVar15 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          }

          sVar5 = (short)uVar21;

          sVar6 = (short)uVar20;

          sVar7 = (short)uVar8;

          if (uVar14 < 0x81) {

            if (uVar14 == 0x80) {

LAB_1402ad669:

              uVar21 = uVar21 + uVar13;

              if (0xff < uVar21) {

                uVar21 = 0xff;

              }

              uVar20 = uVar20 + uVar16;

              if (0xff < uVar20) {

                uVar20 = 0xff;

              }

              uVar8 = uVar8 + uVar15;

              if (0xff < uVar8) {

                uVar8 = 0xff;

              }

            }

            else if (uVar14 == 0x10) {

              sVar11 = 0xff - uVar25;

              uVar17 = sVar11 * sVar5 + 1;

              uVar21 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar13;

              uVar17 = sVar11 * sVar6 + 1;

              uVar20 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar16;

              uVar17 = sVar11 * sVar7 + 1;

              uVar8 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar15;

            }

            else if (uVar14 == 0x20) {

              sVar11 = 0xff - uVar25;

              uVar17 = sVar5 * sVar11 + 1;

              uVar21 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar13;

              if (0xff < uVar21) {

                uVar21 = 0xff;

              }

              uVar17 = sVar11 * sVar6 + 1;

              uVar20 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar16;

              if (0xff < uVar20) {

                uVar20 = 0xff;

              }

              uVar17 = sVar11 * sVar7 + 1;

              uVar8 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar15;

              if (0xff < uVar8) {

                uVar8 = 0xff;

              }

            }

            else if (uVar14 == 0x40) goto LAB_1402ad669;

          }

          else if (uVar14 == 0x100) {

            uVar17 = (short)uVar13 * sVar5 + 1;

            uVar21 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            uVar17 = sVar6 * (short)uVar16 + 1;

            uVar20 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            uVar17 = sVar7 * (short)uVar15 + 1;

            uVar8 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          }

          else if (uVar14 == 0x200) {

            sVar11 = 0xff - uVar25;

            uVar17 = sVar5 * (short)uVar13 + 1;

            uVar19 = sVar11 * sVar5 + 1;

            uVar21 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8) +

                     (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            if (0xff < uVar21) {

              uVar21 = 0xff;

            }

            uVar17 = sVar6 * (short)uVar16 + 1;

            uVar19 = sVar11 * sVar6 + 1;

            uVar20 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8) +

                     (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            if (0xff < uVar20) {

              uVar20 = 0xff;

            }

            uVar17 = sVar11 * sVar7 + 1;

            uVar19 = sVar7 * (short)uVar15 + 1;

            uVar8 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8) +

                    (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

          }

          *puVar22 = (uVar8 << 8 | uVar20) << 8 | uVar21;

          puVar22 = puVar22 + 1;

          uVar18 = uVar18 + uVar10;

        } while (uVar23 != 0);

        uVar24 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar12 = uVar12 + uVar9;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar18 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




