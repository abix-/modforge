// Address: 0x1402c2500
// Ghidra name: FUN_1402c2500
// ============ 0x1402c2500 FUN_1402c2500 (size=1323) ============


void FUN_1402c2500(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  byte bVar7;

  uint uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  short sVar11;

  ulonglong uVar12;

  ushort uVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  ushort uVar18;

  uint uVar19;

  ulonglong uVar20;

  ulonglong uVar21;

  uint uVar22;

  uint uVar23;

  uint *puVar24;

  uint uVar25;

  uint uVar26;

  

  uVar21 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar20 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar1 = *(uint *)(param_1 + 0x78);

  uVar9 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar21;

  uVar10 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar20;

  uVar12 = uVar9 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar24 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar21 + -1;

      if ((int)uVar20 != 0) {

        uVar16 = uVar1 & 0x3f0;

        uVar21 = uVar10 >> 1;

        do {

          uVar19 = (int)uVar20 - 1;

          uVar2 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar12 >> 0x10) +

                            (uVar21 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar15 = uVar2 >> 0x10 & 0xff;

          uVar25 = uVar2 >> 8 & 0xff;

          uVar3 = *puVar24;

          uVar22 = uVar3 >> 0x10 & 0xff;

          uVar26 = uVar2 & 0xff;

          uVar14 = uVar3 & 0xff;

          uVar17 = uVar2 >> 0x18;

          uVar8 = uVar3 >> 0x18;

          uVar23 = uVar3 >> 8 & 0xff;

          bVar7 = (byte)(uVar2 >> 0x18);

          if (((uVar1 & 0x50) != 0) && (uVar17 < 0xff)) {

            uVar13 = (short)uVar15 * (ushort)bVar7 + 1;

            uVar15 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

            uVar13 = (short)uVar25 * (ushort)bVar7 + 1;

            uVar25 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

            uVar13 = (short)uVar26 * (ushort)bVar7 + 1;

            uVar26 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

          }

          uVar13 = (ushort)bVar7;

          sVar4 = (short)uVar22;

          sVar5 = (short)uVar23;

          sVar6 = (short)uVar14;

          if (uVar16 < 0x81) {

            if (uVar16 == 0x80) {

LAB_1402c26c1:

              uVar22 = uVar22 + uVar15;

              if (0xff < uVar22) {

                uVar22 = 0xff;

              }

              uVar23 = uVar23 + uVar25;

              if (0xff < uVar23) {

                uVar23 = 0xff;

              }

              uVar14 = uVar14 + uVar26;

              if (0xff < uVar14) {

                uVar14 = 0xff;

              }

            }

            else {

              bVar7 = (byte)(uVar3 >> 0x18);

              if (uVar16 == 0x10) {

                sVar11 = 0xff - uVar13;

                uVar13 = sVar4 * sVar11 + 1;

                uVar22 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar15;

                uVar13 = sVar11 * sVar5 + 1;

                uVar23 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar25;

                uVar13 = sVar6 * sVar11 + 1;

                uVar14 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar26;

                uVar13 = sVar11 * (ushort)bVar7 + 1;

                uVar8 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar17;

              }

              else if (uVar16 == 0x20) {

                sVar11 = 0xff - uVar13;

                uVar13 = sVar11 * sVar4 + 1;

                uVar22 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar15;

                if (0xff < uVar22) {

                  uVar22 = 0xff;

                }

                uVar13 = sVar11 * sVar5 + 1;

                uVar23 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar25;

                if (0xff < uVar23) {

                  uVar23 = 0xff;

                }

                uVar13 = sVar6 * sVar11 + 1;

                uVar14 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar26;

                if (0xff < uVar14) {

                  uVar14 = 0xff;

                }

                uVar13 = sVar11 * (ushort)bVar7 + 1;

                uVar8 = ((ushort)((uVar13 >> 8) + uVar13) >> 8) + uVar17;

                if (0xff < uVar8) {

                  uVar8 = 0xff;

                }

              }

              else if (uVar16 == 0x40) goto LAB_1402c26c1;

            }

          }

          else if (uVar16 == 0x100) {

            uVar13 = sVar4 * (short)uVar15 + 1;

            uVar22 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

            uVar13 = (short)uVar25 * sVar5 + 1;

            uVar23 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

            uVar13 = (short)uVar26 * sVar6 + 1;

            uVar14 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

          }

          else if (uVar16 == 0x200) {

            sVar11 = 0xff - uVar13;

            uVar13 = (short)uVar15 * sVar4 + 1;

            uVar18 = sVar11 * sVar4 + 1;

            uVar22 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8) +

                     (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

            if (0xff < uVar22) {

              uVar22 = 0xff;

            }

            uVar13 = (short)uVar25 * sVar5 + 1;

            uVar18 = sVar11 * sVar5 + 1;

            uVar23 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8) +

                     (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

            if (0xff < uVar23) {

              uVar23 = 0xff;

            }

            uVar13 = (short)uVar26 * sVar6 + 1;

            uVar18 = sVar11 * sVar6 + 1;

            uVar14 = (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8) +

                     (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

          }

          uVar20 = (ulonglong)uVar19;

          *puVar24 = ((uVar8 << 8 | uVar22) << 8 | uVar23) << 8 | uVar14;

          puVar24 = puVar24 + 1;

          uVar21 = uVar21 + uVar10;

        } while (uVar19 != 0);

        uVar20 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar12 = uVar12 + uVar9;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar21 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




