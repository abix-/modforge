// Address: 0x1402b2f10
// Ghidra name: FUN_1402b2f10
// ============ 0x1402b2f10 FUN_1402b2f10 (size=1412) ============


void FUN_1402b2f10(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  uint uVar5;

  uint uVar6;

  short sVar7;

  short sVar8;

  short sVar9;

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

  uint uVar23;

  uint uVar24;

  uint uVar25;

  ulonglong uVar26;

  uint *puVar27;

  

  bVar1 = *(byte *)(param_1 + 0x80);

  uVar22 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar26 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar5 = *(uint *)(param_1 + 0x78);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  bVar4 = *(byte *)(param_1 + 0x83);

  uVar11 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar22;

  uVar12 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar26;

  uVar14 = uVar11 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar27 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar22 + -1;

      if ((int)uVar26 != 0) {

        uVar16 = uVar5 & 0x3f0;

        uVar22 = uVar12 >> 1;

        do {

          uVar25 = (int)uVar26 - 1;

          uVar26 = (ulonglong)uVar25;

          uVar23 = *puVar27;

          uVar24 = uVar23 & 0xff;

          uVar6 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar14 >> 0x10) +

                            (uVar22 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar15 = uVar6 >> 0x10 & 0xff;

          uVar18 = uVar6 >> 8 & 0xff;

          uVar17 = uVar6 & 0xff;

          uVar21 = uVar6 >> 0x18;

          uVar10 = uVar23 >> 0x10 & 0xff;

          uVar23 = uVar23 >> 8 & 0xff;

          if ((uVar5 & 1) != 0) {

            uVar19 = (ushort)bVar1 * (short)uVar17 + 1;

            uVar17 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = (ushort)bVar2 * (short)uVar18 + 1;

            uVar18 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = (ushort)bVar3 * (short)uVar15 + 1;

            uVar15 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          }

          if ((uVar5 & 2) != 0) {

            uVar19 = (ushort)bVar4 * (ushort)(byte)(uVar6 >> 0x18) + 1;

            uVar21 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          }

          sVar13 = (short)uVar21;

          if (((uVar5 & 0x50) != 0) && (uVar21 < 0xff)) {

            uVar19 = sVar13 * (short)uVar17 + 1;

            uVar17 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = (short)uVar18 * sVar13 + 1;

            uVar18 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = sVar13 * (short)uVar15 + 1;

            uVar15 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          }

          sVar7 = (short)uVar10;

          sVar8 = (short)uVar23;

          sVar9 = (short)uVar24;

          if (uVar16 < 0x81) {

            if (uVar16 == 0x80) {

LAB_1402b319f:

              uVar10 = uVar10 + uVar17;

              if (0xff < uVar10) {

                uVar10 = 0xff;

              }

              uVar23 = uVar23 + uVar18;

              if (0xff < uVar23) {

                uVar23 = 0xff;

              }

              uVar24 = uVar24 + uVar15;

              if (0xff < uVar24) {

                uVar24 = 0xff;

              }

            }

            else if (uVar16 == 0x10) {

              sVar13 = 0xff - sVar13;

              uVar19 = sVar13 * sVar7 + 1;

              uVar10 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar17;

              uVar19 = sVar13 * sVar8 + 1;

              uVar23 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar18;

              uVar19 = sVar13 * sVar9 + 1;

              uVar24 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar15;

            }

            else if (uVar16 == 0x20) {

              sVar13 = 0xff - sVar13;

              uVar19 = sVar13 * sVar7 + 1;

              uVar10 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar17;

              if (0xff < uVar10) {

                uVar10 = 0xff;

              }

              uVar19 = sVar13 * sVar8 + 1;

              uVar23 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar18;

              if (0xff < uVar23) {

                uVar23 = 0xff;

              }

              uVar19 = sVar9 * sVar13 + 1;

              uVar24 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar15;

              if (0xff < uVar24) {

                uVar24 = 0xff;

              }

            }

            else if (uVar16 == 0x40) goto LAB_1402b319f;

          }

          else if (uVar16 == 0x100) {

            uVar19 = sVar7 * (short)uVar17 + 1;

            uVar10 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = (short)uVar18 * sVar8 + 1;

            uVar23 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

            uVar19 = sVar9 * (short)uVar15 + 1;

            uVar24 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          }

          else if (uVar16 == 0x200) {

            sVar13 = 0xff - sVar13;

            uVar20 = sVar7 * (short)uVar17 + 1;

            uVar19 = sVar13 * sVar7 + 1;

            uVar10 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8) +

                     (uint)((ushort)((uVar20 >> 8) + uVar20) >> 8);

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar19 = sVar8 * (short)uVar18 + 1;

            uVar20 = sVar13 * sVar8 + 1;

            uVar23 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8) +

                     (uint)((ushort)((uVar20 >> 8) + uVar20) >> 8);

            if (0xff < uVar23) {

              uVar23 = 0xff;

            }

            uVar19 = sVar9 * (short)uVar15 + 1;

            uVar20 = sVar13 * sVar9 + 1;

            uVar24 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8) +

                     (uint)((ushort)((uVar20 >> 8) + uVar20) >> 8);

            if (0xff < uVar24) {

              uVar24 = 0xff;

            }

          }

          uVar22 = uVar22 + uVar12;

          *puVar27 = (uVar10 << 8 | uVar23) << 8 | uVar24;

          puVar27 = puVar27 + 1;

        } while (uVar25 != 0);

        uVar26 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar14 = uVar14 + uVar11;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar22 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




