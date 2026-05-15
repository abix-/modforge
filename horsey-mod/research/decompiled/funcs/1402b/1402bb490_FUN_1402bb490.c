// Address: 0x1402bb490
// Ghidra name: FUN_1402bb490
// ============ 0x1402bb490 FUN_1402bb490 (size=1410) ============


void FUN_1402bb490(longlong param_1)



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

  short sVar13;

  uint *puVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  uint uVar18;

  ushort uVar19;

  ushort uVar20;

  uint uVar21;

  uint uVar22;

  uint *puVar23;

  int iVar24;

  uint uVar25;

  uint uVar26;

  

  bVar1 = *(byte *)(param_1 + 0x80);

  uVar5 = *(uint *)(param_1 + 0x78);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  bVar4 = *(byte *)(param_1 + 0x83);

  iVar24 = *(int *)(param_1 + 0x3c);

  if (iVar24 == 0) {

    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

    return;

  }

  do {

    puVar14 = *(uint **)(param_1 + 8);

    puVar23 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar24 + -1;

    iVar24 = *(int *)(param_1 + 0x38);

    if (iVar24 != 0) {

      uVar26 = uVar5 & 0x3f0;

      do {

        uVar6 = *puVar14;

        iVar24 = iVar24 + -1;

        uVar25 = uVar6 & 0xff;

        uVar17 = uVar6 >> 0x10 & 0xff;

        uVar16 = uVar6 >> 8 & 0xff;

        uVar7 = *puVar23;

        uVar18 = uVar7 >> 0x10 & 0xff;

        uVar22 = uVar7 & 0xff;

        uVar15 = uVar6 >> 0x18;

        uVar12 = uVar7 >> 0x18;

        uVar21 = uVar7 >> 8 & 0xff;

        if ((uVar5 & 1) != 0) {

          uVar19 = (ushort)bVar1 * (short)uVar25 + 1;

          uVar25 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          uVar19 = (ushort)bVar2 * (short)uVar16 + 1;

          uVar16 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          uVar19 = (ushort)bVar3 * (short)uVar17 + 1;

          uVar17 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

        }

        if ((uVar5 & 2) != 0) {

          uVar19 = (ushort)bVar4 * (ushort)(byte)(uVar6 >> 0x18) + 1;

          uVar15 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

        }

        sVar13 = (short)uVar15;

        if (((uVar5 & 0x50) != 0) && (uVar15 < 0xff)) {

          uVar19 = sVar13 * (short)uVar25 + 1;

          uVar25 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          uVar19 = sVar13 * (short)uVar16 + 1;

          uVar16 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          uVar19 = sVar13 * (short)uVar17 + 1;

          uVar17 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

        }

        sVar8 = (short)uVar22;

        sVar9 = (short)uVar21;

        sVar10 = (short)uVar18;

        if (uVar26 < 0x81) {

          if (uVar26 == 0x80) {

LAB_1402bb6c0:

            uVar22 = uVar22 + uVar25;

            if (0xff < uVar22) {

              uVar22 = 0xff;

            }

            uVar21 = uVar21 + uVar16;

            if (0xff < uVar21) {

              uVar21 = 0xff;

            }

            uVar18 = uVar18 + uVar17;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

          }

          else {

            bVar11 = (byte)(uVar7 >> 0x18);

            if (uVar26 == 0x10) {

              sVar13 = 0xff - sVar13;

              uVar19 = sVar13 * sVar8 + 1;

              uVar22 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar25;

              uVar19 = sVar13 * sVar9 + 1;

              uVar21 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar16;

              uVar19 = sVar13 * sVar10 + 1;

              uVar18 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar17;

              uVar19 = sVar13 * (ushort)bVar11 + 1;

              uVar12 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar15;

            }

            else if (uVar26 == 0x20) {

              sVar13 = 0xff - sVar13;

              uVar19 = sVar8 * sVar13 + 1;

              uVar22 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar25;

              if (0xff < uVar22) {

                uVar22 = 0xff;

              }

              uVar19 = sVar13 * sVar9 + 1;

              uVar21 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar16;

              if (0xff < uVar21) {

                uVar21 = 0xff;

              }

              uVar19 = sVar13 * sVar10 + 1;

              uVar18 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar17;

              if (0xff < uVar18) {

                uVar18 = 0xff;

              }

              uVar19 = sVar13 * (ushort)bVar11 + 1;

              uVar12 = ((ushort)((uVar19 >> 8) + uVar19) >> 8) + uVar15;

              if (0xff < uVar12) {

                uVar12 = 0xff;

              }

            }

            else if (uVar26 == 0x40) goto LAB_1402bb6c0;

          }

        }

        else if (uVar26 == 0x100) {

          uVar19 = sVar8 * (short)uVar25 + 1;

          uVar22 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          uVar19 = sVar9 * (short)uVar16 + 1;

          uVar21 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

          uVar19 = sVar10 * (short)uVar17 + 1;

          uVar18 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8);

        }

        else if (uVar26 == 0x200) {

          sVar13 = 0xff - sVar13;

          uVar19 = sVar8 * (short)uVar25 + 1;

          uVar20 = sVar13 * sVar8 + 1;

          uVar22 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8) +

                   (uint)((ushort)((uVar20 >> 8) + uVar20) >> 8);

          if (0xff < uVar22) {

            uVar22 = 0xff;

          }

          uVar19 = sVar9 * (short)uVar16 + 1;

          uVar20 = sVar13 * sVar9 + 1;

          uVar21 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8) +

                   (uint)((ushort)((uVar20 >> 8) + uVar20) >> 8);

          if (0xff < uVar21) {

            uVar21 = 0xff;

          }

          uVar19 = sVar10 * (short)uVar17 + 1;

          uVar20 = sVar13 * sVar10 + 1;

          uVar18 = (uint)((ushort)((uVar19 >> 8) + uVar19) >> 8) +

                   (uint)((ushort)((uVar20 >> 8) + uVar20) >> 8);

          if (0xff < uVar18) {

            uVar18 = 0xff;

          }

        }

        puVar14 = puVar14 + 1;

        *puVar23 = ((uVar12 << 8 | uVar18) << 8 | uVar21) << 8 | uVar22;

        puVar23 = puVar23 + 1;

      } while (iVar24 != 0);

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar24 = *(int *)(param_1 + 0x3c);

    if (iVar24 == 0) {

      *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

      return;

    }

  } while( true );

}




