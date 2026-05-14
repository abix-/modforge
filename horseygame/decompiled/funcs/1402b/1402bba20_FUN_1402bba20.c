// Address: 0x1402bba20
// Ghidra name: FUN_1402bba20
// ============ 0x1402bba20 FUN_1402bba20 (size=1486) ============


void FUN_1402bba20(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  uint uVar4;

  uint uVar5;

  short sVar6;

  short sVar7;

  short sVar8;

  byte bVar9;

  uint uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  short sVar13;

  ulonglong uVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  uint uVar18;

  ushort uVar19;

  ushort uVar20;

  uint uVar21;

  ulonglong uVar22;

  ulonglong uVar23;

  uint uVar24;

  uint uVar25;

  uint *puVar26;

  uint uVar27;

  uint uVar28;

  

  bVar1 = *(byte *)(param_1 + 0x80);

  uVar4 = *(uint *)(param_1 + 0x78);

  uVar23 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar22 = (ulonglong)*(int *)(param_1 + 0x38);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  uVar28 = 0xff;

  if ((uVar4 & 2) != 0) {

    uVar28 = (uint)*(byte *)(param_1 + 0x83);

  }

  uVar11 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar23;

  uVar12 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar22;

  uVar14 = uVar11 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar26 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar23 + -1;

      if ((int)uVar22 != 0) {

        uVar27 = uVar4 & 0x3f0;

        uVar23 = uVar12 >> 1;

        do {

          uVar21 = (int)uVar22 - 1;

          uVar16 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar14 >> 0x10) +

                             (uVar23 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar18 = uVar16 >> 0x10 & 0xff;

          uVar17 = uVar16 >> 8 & 0xff;

          uVar5 = *puVar26;

          uVar15 = uVar5 >> 0x10 & 0xff;

          uVar25 = uVar5 & 0xff;

          uVar10 = uVar5 >> 0x18;

          uVar16 = uVar16 & 0xff;

          uVar24 = uVar5 >> 8 & 0xff;

          if ((uVar4 & 1) != 0) {

            uVar19 = (ushort)bVar1 * (short)uVar16 + 1;

            uVar16 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = (ushort)bVar2 * (short)uVar17 + 1;

            uVar17 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = (ushort)bVar3 * (short)uVar18 + 1;

            uVar18 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          }

          sVar13 = (short)uVar28;

          if (((uVar4 & 0x50) != 0) && (uVar28 < 0xff)) {

            uVar19 = sVar13 * (short)uVar16 + 1;

            uVar16 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = sVar13 * (short)uVar17 + 1;

            uVar17 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = sVar13 * (short)uVar18 + 1;

            uVar18 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          }

          sVar6 = (short)uVar25;

          sVar7 = (short)uVar24;

          sVar8 = (short)uVar15;

          if (uVar27 < 0x81) {

            if (uVar27 == 0x80) {

LAB_1402bbc8d:

              uVar25 = uVar25 + uVar16;

              if (0xff < uVar25) {

                uVar25 = 0xff;

              }

              uVar24 = uVar24 + uVar17;

              if (0xff < uVar24) {

                uVar24 = 0xff;

              }

              uVar15 = uVar15 + uVar18;

              if (0xff < uVar15) {

                uVar15 = 0xff;

              }

            }

            else {

              bVar9 = (byte)(uVar5 >> 0x18);

              if (uVar27 == 0x10) {

                sVar13 = 0xff - sVar13;

                uVar19 = sVar13 * sVar6 + 1;

                uVar25 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar16;

                uVar19 = sVar13 * sVar7 + 1;

                uVar24 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar17;

                uVar19 = sVar13 * sVar8 + 1;

                uVar15 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar18;

                uVar19 = sVar13 * (ushort)bVar9 + 1;

                uVar10 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar28;

              }

              else if (uVar27 == 0x20) {

                sVar13 = 0xff - sVar13;

                uVar19 = sVar6 * sVar13 + 1;

                uVar25 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar16;

                if (0xff < uVar25) {

                  uVar25 = 0xff;

                }

                uVar19 = sVar13 * sVar7 + 1;

                uVar24 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar17;

                if (0xff < uVar24) {

                  uVar24 = 0xff;

                }

                uVar19 = sVar13 * sVar8 + 1;

                uVar15 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar18;

                if (0xff < uVar15) {

                  uVar15 = 0xff;

                }

                uVar19 = sVar13 * (ushort)bVar9 + 1;

                uVar10 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar28;

                if (0xff < uVar10) {

                  uVar10 = 0xff;

                }

              }

              else if (uVar27 == 0x40) goto LAB_1402bbc8d;

            }

          }

          else if (uVar27 == 0x100) {

            uVar19 = sVar6 * (short)uVar16 + 1;

            uVar25 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = sVar7 * (short)uVar17 + 1;

            uVar24 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = (short)uVar18 * sVar8 + 1;

            uVar15 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          }

          else if (uVar27 == 0x200) {

            sVar13 = 0xff - sVar13;

            uVar19 = sVar6 * (short)uVar16 + 1;

            uVar20 = sVar13 * sVar6 + 1;

            uVar25 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8) +

                     (uint)((ushort)((uVar20 >> 8) + uVar20) >> 8);

            if (0xff < uVar25) {

              uVar25 = 0xff;

            }

            uVar19 = sVar7 * (short)uVar17 + 1;

            uVar20 = sVar13 * sVar7 + 1;

            uVar24 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8) +

                     (uint)((ushort)((uVar20 >> 8) + uVar20) >> 8);

            if (0xff < uVar24) {

              uVar24 = 0xff;

            }

            uVar19 = sVar8 * (short)uVar18 + 1;

            uVar20 = sVar13 * sVar8 + 1;

            uVar15 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8) +

                     (uint)((ushort)((uVar20 >> 8) + uVar20) >> 8);

            if (0xff < uVar15) {

              uVar15 = 0xff;

            }

          }

          uVar22 = (ulonglong)uVar21;

          *puVar26 = ((uVar10 << 8 | uVar15) << 8 | uVar24) << 8 | uVar25;

          puVar26 = puVar26 + 1;

          uVar23 = uVar23 + uVar12;

        } while (uVar21 != 0);

        uVar22 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar14 = uVar14 + uVar11;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar23 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




