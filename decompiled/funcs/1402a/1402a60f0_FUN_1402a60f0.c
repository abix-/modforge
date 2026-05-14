// Address: 0x1402a60f0
// Ghidra name: FUN_1402a60f0
// ============ 0x1402a60f0 FUN_1402a60f0 (size=1572) ============


void FUN_1402a60f0(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  short sVar8;

  short sVar9;

  short sVar10;

  byte bVar11;

  uint uVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  short sVar15;

  ulonglong uVar16;

  uint uVar17;

  uint uVar18;

  uint uVar19;

  uint uVar20;

  ushort uVar21;

  ushort uVar22;

  uint uVar23;

  ulonglong uVar24;

  ulonglong uVar25;

  uint uVar26;

  uint uVar27;

  uint *puVar28;

  uint uVar29;

  uint uVar30;

  

  bVar1 = *(byte *)(param_1 + 0x80);

  uVar25 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar24 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar5 = *(uint *)(param_1 + 0x78);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  bVar4 = *(byte *)(param_1 + 0x83);

  uVar13 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar25;

  uVar14 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar24;

  uVar16 = uVar13 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar28 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar25 + -1;

      if ((int)uVar24 != 0) {

        uVar30 = uVar5 & 0x3f0;

        uVar25 = uVar14 >> 1;

        do {

          uVar23 = (int)uVar24 - 1;

          uVar6 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar16 >> 0x10) +

                            (uVar25 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar18 = uVar6 >> 0x10 & 0xff;

          uVar29 = uVar6 >> 8 & 0xff;

          uVar7 = *puVar28;

          uVar17 = uVar7 >> 0x10 & 0xff;

          uVar27 = uVar7 & 0xff;

          uVar20 = uVar6 >> 0x18;

          uVar12 = uVar7 >> 0x18;

          uVar19 = uVar6 & 0xff;

          uVar26 = uVar7 >> 8 & 0xff;

          if ((uVar5 & 1) != 0) {

            uVar21 = (ushort)bVar1 * (short)uVar29 + 1;

            uVar29 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8);

            uVar21 = (ushort)bVar2 * (short)uVar18 + 1;

            uVar18 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8);

            uVar21 = (ushort)bVar3 * (ushort)(byte)(uVar6 >> 0x18) + 1;

            uVar20 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8);

          }

          if ((uVar5 & 2) != 0) {

            uVar21 = (ushort)bVar4 * (short)uVar19 + 1;

            uVar19 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8);

          }

          sVar15 = (short)uVar19;

          if (((uVar5 & 0x50) != 0) && (uVar19 < 0xff)) {

            uVar21 = sVar15 * (short)uVar29 + 1;

            uVar29 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8);

            uVar21 = sVar15 * (short)uVar18 + 1;

            uVar18 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8);

            uVar21 = sVar15 * (short)uVar20 + 1;

            uVar20 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8);

          }

          sVar8 = (short)uVar27;

          sVar9 = (short)uVar26;

          sVar10 = (short)uVar17;

          if (uVar30 < 0x81) {

            if (uVar30 == 0x80) {

LAB_1402a63a6:

              uVar27 = uVar27 + uVar29;

              if (0xff < uVar27) {

                uVar27 = 0xff;

              }

              uVar26 = uVar26 + uVar18;

              if (0xff < uVar26) {

                uVar26 = 0xff;

              }

              uVar17 = uVar17 + uVar20;

              if (0xff < uVar17) {

                uVar17 = 0xff;

              }

            }

            else {

              bVar11 = (byte)(uVar7 >> 0x18);

              if (uVar30 == 0x10) {

                sVar15 = 0xff - sVar15;

                uVar21 = sVar8 * sVar15 + 1;

                uVar27 = ((ushort)((uVar21 >> 8) + uVar21) >> 8) + uVar29;

                uVar21 = sVar15 * sVar9 + 1;

                uVar26 = ((ushort)((uVar21 >> 8) + uVar21) >> 8) + uVar18;

                uVar21 = sVar10 * sVar15 + 1;

                uVar17 = ((ushort)((uVar21 >> 8) + uVar21) >> 8) + uVar20;

                uVar21 = sVar15 * (ushort)bVar11 + 1;

                uVar12 = ((ushort)((uVar21 >> 8) + uVar21) >> 8) + uVar19;

              }

              else if (uVar30 == 0x20) {

                sVar15 = 0xff - sVar15;

                uVar21 = sVar8 * sVar15 + 1;

                uVar27 = ((ushort)((uVar21 >> 8) + uVar21) >> 8) + uVar29;

                if (0xff < uVar27) {

                  uVar27 = 0xff;

                }

                uVar21 = sVar15 * sVar9 + 1;

                uVar26 = ((ushort)((uVar21 >> 8) + uVar21) >> 8) + uVar18;

                if (0xff < uVar26) {

                  uVar26 = 0xff;

                }

                uVar21 = sVar15 * sVar10 + 1;

                uVar17 = ((ushort)((uVar21 >> 8) + uVar21) >> 8) + uVar20;

                if (0xff < uVar17) {

                  uVar17 = 0xff;

                }

                uVar21 = sVar15 * (ushort)bVar11 + 1;

                uVar12 = ((ushort)((uVar21 >> 8) + uVar21) >> 8) + uVar19;

                if (0xff < uVar12) {

                  uVar12 = 0xff;

                }

              }

              else if (uVar30 == 0x40) goto LAB_1402a63a6;

            }

          }

          else if (uVar30 == 0x100) {

            uVar21 = sVar8 * (short)uVar29 + 1;

            uVar27 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8);

            uVar21 = sVar9 * (short)uVar18 + 1;

            uVar26 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8);

            uVar21 = sVar10 * (short)uVar20 + 1;

            uVar17 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8);

          }

          else if (uVar30 == 0x200) {

            sVar15 = 0xff - sVar15;

            uVar22 = sVar8 * (short)uVar29 + 1;

            uVar21 = sVar15 * sVar8 + 1;

            uVar27 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8) +

                     (uint)((ushort)((uVar22 >> 8) + uVar22) >> 8);

            if (0xff < uVar27) {

              uVar27 = 0xff;

            }

            uVar22 = sVar9 * (short)uVar18 + 1;

            uVar21 = sVar15 * sVar9 + 1;

            uVar26 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8) +

                     (uint)((ushort)((uVar22 >> 8) + uVar22) >> 8);

            if (0xff < uVar26) {

              uVar26 = 0xff;

            }

            uVar22 = sVar10 * (short)uVar20 + 1;

            uVar21 = sVar15 * sVar10 + 1;

            uVar17 = (uint)((ushort)((uVar21 >> 8) + uVar21) >> 8) +

                     (uint)((ushort)((uVar22 >> 8) + uVar22) >> 8);

            if (0xff < uVar17) {

              uVar17 = 0xff;

            }

          }

          uVar24 = (ulonglong)uVar23;

          *puVar28 = ((uVar12 << 8 | uVar17) << 8 | uVar26) << 8 | uVar27;

          puVar28 = puVar28 + 1;

          uVar25 = uVar25 + uVar14;

        } while (uVar23 != 0);

        uVar24 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar16 = uVar16 + uVar13;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar25 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




