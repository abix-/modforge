// Address: 0x1402b42d0
// Ghidra name: FUN_1402b42d0
// ============ 0x1402b42d0 FUN_1402b42d0 (size=1187) ============


void FUN_1402b42d0(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  short sVar3;

  short sVar4;

  short sVar5;

  byte bVar6;

  uint uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  short sVar10;

  ulonglong uVar11;

  ushort uVar12;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  ushort uVar17;

  ulonglong uVar18;

  uint uVar19;

  uint uVar20;

  uint uVar21;

  ulonglong uVar22;

  uint *puVar23;

  

  uVar18 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar22 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar1 = *(uint *)(param_1 + 0x78);

  uVar8 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar18;

  uVar9 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar22;

  uVar11 = uVar8 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar23 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar18 + -1;

      if ((int)uVar22 != 0) {

        uVar13 = uVar1 & 0x3f0;

        uVar18 = uVar9 >> 1;

        do {

          uVar7 = *puVar23;

          uVar21 = (int)uVar22 - 1;

          uVar22 = (ulonglong)uVar21;

          uVar20 = uVar7 & 0xff;

          uVar2 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar11 >> 0x10) +

                            (uVar18 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar16 = uVar2 >> 0x10 & 0xff;

          uVar15 = uVar2 >> 8 & 0xff;

          uVar14 = uVar2 & 0xff;

          uVar19 = uVar7 >> 8 & 0xff;

          uVar7 = uVar7 >> 0x10 & 0xff;

          bVar6 = (byte)(uVar2 >> 0x18);

          if (((uVar1 & 0x50) != 0) && (uVar2 >> 0x18 < 0xff)) {

            uVar12 = (ushort)bVar6 * (short)uVar14 + 1;

            uVar14 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            uVar12 = (ushort)bVar6 * (short)uVar15 + 1;

            uVar15 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            uVar12 = (ushort)bVar6 * (short)uVar16 + 1;

            uVar16 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

          }

          uVar12 = (ushort)bVar6;

          sVar3 = (short)uVar20;

          sVar4 = (short)uVar19;

          sVar5 = (short)uVar7;

          if (uVar13 < 0x81) {

            if (uVar13 == 0x80) {

LAB_1402b4477:

              uVar20 = uVar20 + uVar14;

              if (0xff < uVar20) {

                uVar20 = 0xff;

              }

              uVar19 = uVar19 + uVar15;

              if (0xff < uVar19) {

                uVar19 = 0xff;

              }

              uVar7 = uVar7 + uVar16;

              if (0xff < uVar7) {

                uVar7 = 0xff;

              }

            }

            else if (uVar13 == 0x10) {

              sVar10 = 0xff - uVar12;

              uVar12 = sVar10 * sVar3 + 1;

              uVar20 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar14;

              uVar12 = sVar10 * sVar4 + 1;

              uVar19 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar15;

              uVar12 = sVar10 * sVar5 + 1;

              uVar7 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar16;

            }

            else if (uVar13 == 0x20) {

              sVar10 = 0xff - uVar12;

              uVar12 = sVar3 * sVar10 + 1;

              uVar20 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar14;

              if (0xff < uVar20) {

                uVar20 = 0xff;

              }

              uVar12 = sVar10 * sVar4 + 1;

              uVar19 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar15;

              if (0xff < uVar19) {

                uVar19 = 0xff;

              }

              uVar12 = sVar10 * sVar5 + 1;

              uVar7 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar16;

              if (0xff < uVar7) {

                uVar7 = 0xff;

              }

            }

            else if (uVar13 == 0x40) goto LAB_1402b4477;

          }

          else if (uVar13 == 0x100) {

            uVar12 = (short)uVar14 * sVar3 + 1;

            uVar20 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            uVar12 = (short)uVar15 * sVar4 + 1;

            uVar19 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            uVar12 = sVar5 * (short)uVar16 + 1;

            uVar7 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

          }

          else if (uVar13 == 0x200) {

            sVar10 = 0xff - uVar12;

            uVar17 = sVar3 * (short)uVar14 + 1;

            uVar12 = sVar3 * sVar10 + 1;

            uVar20 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8) +

                     (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            if (0xff < uVar20) {

              uVar20 = 0xff;

            }

            uVar17 = sVar4 * (short)uVar15 + 1;

            uVar12 = sVar4 * sVar10 + 1;

            uVar19 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8) +

                     (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            if (0xff < uVar19) {

              uVar19 = 0xff;

            }

            uVar17 = sVar5 * (short)uVar16 + 1;

            uVar12 = sVar5 * sVar10 + 1;

            uVar7 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8) +

                    (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

          }

          uVar18 = uVar18 + uVar9;

          *puVar23 = (uVar7 << 8 | uVar19) << 8 | uVar20;

          puVar23 = puVar23 + 1;

        } while (uVar21 != 0);

        uVar22 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar11 = uVar11 + uVar8;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar18 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




