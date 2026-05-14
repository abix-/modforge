// Address: 0x1402a6c40
// Ghidra name: FUN_1402a6c40
// ============ 0x1402a6c40 FUN_1402a6c40 (size=1196) ============


void FUN_1402a6c40(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  short sVar3;

  short sVar4;

  short sVar5;

  uint uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  ushort uVar10;

  ushort uVar11;

  short sVar12;

  ushort uVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  ulonglong uVar18;

  uint uVar19;

  uint uVar20;

  uint uVar21;

  ulonglong uVar22;

  uint *puVar23;

  

  uVar18 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar22 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar1 = *(uint *)(param_1 + 0x78);

  uVar7 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar18;

  uVar8 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar22;

  uVar9 = uVar7 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar23 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar18 + -1;

      if ((int)uVar22 != 0) {

        uVar14 = uVar1 & 0x3f0;

        uVar18 = uVar8 >> 1;

        do {

          uVar19 = *puVar23;

          uVar21 = (int)uVar22 - 1;

          uVar22 = (ulonglong)uVar21;

          uVar20 = uVar19 & 0xff;

          uVar2 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar9 >> 0x10) +

                            (uVar18 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar16 = uVar2 >> 0x10 & 0xff;

          uVar15 = uVar2 >> 8 & 0xff;

          uVar17 = uVar2 >> 0x18;

          uVar6 = uVar19 >> 0x10 & 0xff;

          uVar19 = uVar19 >> 8 & 0xff;

          uVar13 = (ushort)uVar2;

          if (((uVar1 & 0x50) != 0) && ((char)uVar2 != -1)) {

            uVar11 = uVar13 & 0xff;

            uVar10 = uVar11 * (byte)(uVar2 >> 0x18) + 1;

            uVar17 = (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8);

            uVar10 = uVar11 * (short)uVar16 + 1;

            uVar16 = (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8);

            uVar11 = uVar11 * (short)uVar15 + 1;

            uVar15 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

          }

          sVar3 = (short)uVar6;

          sVar4 = (short)uVar19;

          sVar5 = (short)uVar20;

          if (uVar14 < 0x81) {

            if (uVar14 == 0x80) {

LAB_1402a6de1:

              uVar6 = uVar6 + uVar17;

              if (0xff < uVar6) {

                uVar6 = 0xff;

              }

              uVar19 = uVar19 + uVar16;

              if (0xff < uVar19) {

                uVar19 = 0xff;

              }

              uVar20 = uVar20 + uVar15;

              if (0xff < uVar20) {

                uVar20 = 0xff;

              }

            }

            else if (uVar14 == 0x10) {

              sVar12 = 0xff - (uVar13 & 0xff);

              uVar13 = sVar3 * sVar12 + 1;

              uVar6 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar17;

              uVar13 = sVar4 * sVar12 + 1;

              uVar19 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar16;

              uVar13 = sVar5 * sVar12 + 1;

              uVar20 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar15;

            }

            else if (uVar14 == 0x20) {

              sVar12 = 0xff - (uVar13 & 0xff);

              uVar13 = sVar12 * sVar3 + 1;

              uVar6 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar17;

              if (0xff < uVar6) {

                uVar6 = 0xff;

              }

              uVar13 = sVar12 * sVar4 + 1;

              uVar19 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar16;

              if (0xff < uVar19) {

                uVar19 = 0xff;

              }

              uVar13 = sVar5 * sVar12 + 1;

              uVar20 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar15;

              if (0xff < uVar20) {

                uVar20 = 0xff;

              }

            }

            else if (uVar14 == 0x40) goto LAB_1402a6de1;

          }

          else if (uVar14 == 0x100) {

            uVar13 = (short)uVar17 * sVar3 + 1;

            uVar6 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

            uVar13 = (short)uVar16 * sVar4 + 1;

            uVar19 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

            uVar13 = (short)uVar15 * sVar5 + 1;

            uVar20 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

          }

          else if (uVar14 == 0x200) {

            sVar12 = 0xff - (uVar13 & 0xff);

            uVar11 = (short)uVar17 * sVar3 + 1;

            uVar13 = sVar12 * sVar3 + 1;

            uVar6 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8) +

                    (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar13 = sVar12 * sVar4 + 1;

            uVar11 = (short)uVar16 * sVar4 + 1;

            uVar19 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8) +

                     (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

            if (0xff < uVar19) {

              uVar19 = 0xff;

            }

            uVar13 = sVar12 * sVar5 + 1;

            uVar11 = (short)uVar15 * sVar5 + 1;

            uVar20 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8) +

                     (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

            if (0xff < uVar20) {

              uVar20 = 0xff;

            }

          }

          uVar18 = uVar18 + uVar8;

          *puVar23 = (uVar6 << 8 | uVar19) << 8 | uVar20;

          puVar23 = puVar23 + 1;

        } while (uVar21 != 0);

        uVar22 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar9 = uVar9 + uVar7;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar18 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




