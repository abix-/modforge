// Address: 0x1402aaa00
// Ghidra name: FUN_1402aaa00
// ============ 0x1402aaa00 FUN_1402aaa00 (size=1330) ============


void FUN_1402aaa00(longlong param_1)



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

  ulonglong uVar11;

  ushort uVar12;

  short sVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  ushort uVar18;

  ulonglong uVar19;

  uint uVar20;

  uint uVar21;

  ulonglong uVar22;

  uint uVar23;

  uint *puVar24;

  uint uVar25;

  uint uVar26;

  

  uVar19 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar22 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar1 = *(uint *)(param_1 + 0x78);

  uVar9 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar19;

  uVar10 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar22;

  uVar11 = uVar9 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar24 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar19 + -1;

      if ((int)uVar22 != 0) {

        uVar16 = uVar1 & 0x3f0;

        uVar19 = uVar10 >> 1;

        do {

          uVar20 = (int)uVar22 - 1;

          uVar2 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar11 >> 0x10) +

                            (uVar19 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar15 = uVar2 >> 0x10 & 0xff;

          uVar25 = uVar2 >> 8 & 0xff;

          uVar3 = *puVar24;

          uVar23 = uVar3 >> 0x10 & 0xff;

          uVar17 = uVar3 & 0xff;

          uVar21 = uVar2 >> 0x18;

          uVar8 = uVar3 >> 0x18;

          uVar26 = uVar2 & 0xff;

          uVar14 = uVar3 >> 8 & 0xff;

          sVar13 = (short)uVar26;

          if (((uVar1 & 0x50) != 0) && ((char)uVar2 != -1)) {

            uVar12 = sVar13 * (ushort)(byte)(uVar2 >> 0x18) + 1;

            uVar21 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            uVar12 = sVar13 * (short)uVar15 + 1;

            uVar15 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            uVar12 = sVar13 * (short)uVar25 + 1;

            uVar25 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

          }

          sVar4 = (short)uVar23;

          sVar5 = (short)uVar14;

          sVar6 = (short)uVar17;

          if (uVar16 < 0x81) {

            if (uVar16 == 0x80) {

LAB_1402aabbd:

              uVar23 = uVar23 + uVar21;

              if (0xff < uVar23) {

                uVar23 = 0xff;

              }

              uVar14 = uVar14 + uVar15;

              if (0xff < uVar14) {

                uVar14 = 0xff;

              }

              uVar17 = uVar17 + uVar25;

              if (0xff < uVar17) {

                uVar17 = 0xff;

              }

            }

            else {

              bVar7 = (byte)(uVar3 >> 0x18);

              if (uVar16 == 0x10) {

                sVar13 = 0xff - sVar13;

                uVar12 = sVar13 * sVar4 + 1;

                uVar23 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar21;

                uVar12 = sVar13 * sVar5 + 1;

                uVar14 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar15;

                uVar12 = sVar13 * sVar6 + 1;

                uVar17 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar25;

                uVar12 = sVar13 * (ushort)bVar7 + 1;

                uVar8 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar26;

              }

              else if (uVar16 == 0x20) {

                sVar13 = 0xff - sVar13;

                uVar12 = sVar13 * sVar4 + 1;

                uVar23 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar21;

                if (0xff < uVar23) {

                  uVar23 = 0xff;

                }

                uVar12 = sVar13 * sVar5 + 1;

                uVar14 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar15;

                if (0xff < uVar14) {

                  uVar14 = 0xff;

                }

                uVar12 = sVar6 * sVar13 + 1;

                uVar17 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar25;

                if (0xff < uVar17) {

                  uVar17 = 0xff;

                }

                uVar12 = sVar13 * (ushort)bVar7 + 1;

                uVar8 = ((ushort)((uVar12 >> 8) + uVar12) >> 8) + uVar26;

                if (0xff < uVar8) {

                  uVar8 = 0xff;

                }

              }

              else if (uVar16 == 0x40) goto LAB_1402aabbd;

            }

          }

          else if (uVar16 == 0x100) {

            uVar12 = sVar4 * (short)uVar21 + 1;

            uVar23 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            uVar12 = (short)uVar15 * sVar5 + 1;

            uVar14 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            uVar12 = (short)uVar25 * sVar6 + 1;

            uVar17 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

          }

          else if (uVar16 == 0x200) {

            sVar13 = 0xff - sVar13;

            uVar18 = (short)uVar21 * sVar4 + 1;

            uVar12 = sVar13 * sVar4 + 1;

            uVar23 = (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8) +

                     (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            if (0xff < uVar23) {

              uVar23 = 0xff;

            }

            uVar12 = (short)uVar15 * sVar5 + 1;

            uVar18 = sVar13 * sVar5 + 1;

            uVar14 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8) +

                     (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            uVar12 = (short)uVar25 * sVar6 + 1;

            uVar18 = sVar13 * sVar6 + 1;

            uVar17 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8) +

                     (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

            if (0xff < uVar17) {

              uVar17 = 0xff;

            }

          }

          uVar22 = (ulonglong)uVar20;

          *puVar24 = ((uVar8 << 8 | uVar23) << 8 | uVar14) << 8 | uVar17;

          puVar24 = puVar24 + 1;

          uVar19 = uVar19 + uVar10;

        } while (uVar20 != 0);

        uVar22 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar11 = uVar11 + uVar9;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar19 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




