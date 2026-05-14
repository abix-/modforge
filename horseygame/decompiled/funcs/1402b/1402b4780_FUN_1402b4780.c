// Address: 0x1402b4780
// Ghidra name: FUN_1402b4780
// ============ 0x1402b4780 FUN_1402b4780 (size=1383) ============


void FUN_1402b4780(longlong param_1)



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

  ushort uVar16;

  ushort uVar17;

  ulonglong uVar18;

  uint uVar19;

  uint uVar20;

  uint uVar21;

  uint uVar22;

  ulonglong uVar23;

  ushort uVar24;

  uint *puVar25;

  

  bVar1 = *(byte *)(param_1 + 0x80);

  uVar4 = *(uint *)(param_1 + 0x78);

  uVar18 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar23 = (ulonglong)*(int *)(param_1 + 0x38);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  uVar24 = 0xff;

  if ((uVar4 & 2) != 0) {

    uVar24 = (ushort)*(byte *)(param_1 + 0x83);

  }

  uVar9 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar18;

  uVar10 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar23;

  uVar12 = uVar9 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar25 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar18 + -1;

      if ((int)uVar23 != 0) {

        uVar14 = uVar4 & 0x3f0;

        uVar18 = uVar10 >> 1;

        do {

          uVar22 = (int)uVar23 - 1;

          uVar23 = (ulonglong)uVar22;

          uVar19 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar12 >> 0x10) +

                             (uVar18 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar13 = uVar19 >> 0x10 & 0xff;

          uVar15 = uVar19 >> 8 & 0xff;

          uVar19 = uVar19 & 0xff;

          uVar21 = *puVar25;

          uVar8 = uVar21 >> 0x10 & 0xff;

          uVar20 = uVar21 >> 8 & 0xff;

          uVar21 = uVar21 & 0xff;

          if ((uVar4 & 1) != 0) {

            uVar16 = (ushort)bVar1 * (short)uVar19 + 1;

            uVar19 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

            uVar16 = (ushort)bVar2 * (short)uVar15 + 1;

            uVar15 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

            uVar16 = (ushort)bVar3 * (short)uVar13 + 1;

            uVar13 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

          }

          if (((uVar4 & 0x50) != 0) && (uVar24 < 0xff)) {

            uVar16 = (short)uVar19 * uVar24 + 1;

            uVar19 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

            uVar16 = (short)uVar15 * uVar24 + 1;

            uVar15 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

            uVar16 = (short)uVar13 * uVar24 + 1;

            uVar13 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

          }

          sVar5 = (short)uVar8;

          sVar6 = (short)uVar20;

          sVar7 = (short)uVar21;

          if (uVar14 < 0x81) {

            if (uVar14 == 0x80) {

LAB_1402b49e1:

              uVar8 = uVar8 + uVar19;

              if (0xff < uVar8) {

                uVar8 = 0xff;

              }

              uVar20 = uVar20 + uVar15;

              if (0xff < uVar20) {

                uVar20 = 0xff;

              }

              uVar21 = uVar21 + uVar13;

              if (0xff < uVar21) {

                uVar21 = 0xff;

              }

            }

            else if (uVar14 == 0x10) {

              sVar11 = 0xff - uVar24;

              uVar16 = sVar11 * sVar5 + 1;

              uVar8 = ((ushort)((uVar16 >> 8) + uVar16) >> 8) + uVar19;

              uVar16 = sVar11 * sVar6 + 1;

              uVar20 = ((ushort)((uVar16 >> 8) + uVar16) >> 8) + uVar15;

              uVar16 = sVar11 * sVar7 + 1;

              uVar21 = ((ushort)((uVar16 >> 8) + uVar16) >> 8) + uVar13;

            }

            else if (uVar14 == 0x20) {

              sVar11 = 0xff - uVar24;

              uVar16 = sVar11 * sVar5 + 1;

              uVar8 = ((ushort)((uVar16 >> 8) + uVar16) >> 8) + uVar19;

              if (0xff < uVar8) {

                uVar8 = 0xff;

              }

              uVar16 = sVar11 * sVar6 + 1;

              uVar20 = ((ushort)((uVar16 >> 8) + uVar16) >> 8) + uVar15;

              if (0xff < uVar20) {

                uVar20 = 0xff;

              }

              uVar16 = sVar7 * sVar11 + 1;

              uVar21 = ((ushort)((uVar16 >> 8) + uVar16) >> 8) + uVar13;

              if (0xff < uVar21) {

                uVar21 = 0xff;

              }

            }

            else if (uVar14 == 0x40) goto LAB_1402b49e1;

          }

          else if (uVar14 == 0x100) {

            uVar16 = (short)uVar19 * sVar5 + 1;

            uVar8 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

            uVar16 = sVar6 * (short)uVar15 + 1;

            uVar20 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

            uVar16 = (short)uVar13 * sVar7 + 1;

            uVar21 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

          }

          else if (uVar14 == 0x200) {

            sVar11 = 0xff - uVar24;

            uVar17 = sVar5 * (short)uVar19 + 1;

            uVar16 = sVar11 * sVar5 + 1;

            uVar8 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8) +

                    (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            uVar17 = sVar11 * sVar6 + 1;

            uVar16 = sVar6 * (short)uVar15 + 1;

            uVar20 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8) +

                     (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            if (0xff < uVar20) {

              uVar20 = 0xff;

            }

            uVar17 = sVar11 * sVar7 + 1;

            uVar16 = sVar7 * (short)uVar13 + 1;

            uVar21 = (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8) +

                     (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

            if (0xff < uVar21) {

              uVar21 = 0xff;

            }

          }

          uVar18 = uVar18 + uVar10;

          *puVar25 = (uVar8 << 8 | uVar20) << 8 | uVar21;

          puVar25 = puVar25 + 1;

        } while (uVar22 != 0);

        uVar23 = (ulonglong)*(uint *)(param_1 + 0x38);

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




