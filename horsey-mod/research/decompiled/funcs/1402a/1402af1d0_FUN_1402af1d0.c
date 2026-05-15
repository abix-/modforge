// Address: 0x1402af1d0
// Ghidra name: FUN_1402af1d0
// ============ 0x1402af1d0 FUN_1402af1d0 (size=1348) ============


void FUN_1402af1d0(longlong param_1)



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

  short sVar11;

  uint *puVar12;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  ushort uVar17;

  ushort uVar18;

  uint uVar19;

  uint uVar20;

  uint *puVar21;

  int iVar22;

  uint uVar23;

  uint uVar24;

  

  bVar1 = *(byte *)(param_1 + 0x81);

  uVar4 = *(uint *)(param_1 + 0x78);

  bVar2 = *(byte *)(param_1 + 0x80);

  bVar3 = *(byte *)(param_1 + 0x82);

  uVar24 = 0xff;

  if ((uVar4 & 2) != 0) {

    uVar24 = (uint)*(byte *)(param_1 + 0x83);

  }

  iVar22 = *(int *)(param_1 + 0x3c);

  if (iVar22 == 0) {

    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

    return;

  }

  do {

    puVar12 = *(uint **)(param_1 + 8);

    puVar21 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar22 + -1;

    iVar22 = *(int *)(param_1 + 0x38);

    if (iVar22 != 0) {

      uVar23 = uVar4 & 0x3f0;

      do {

        uVar5 = *puVar12;

        iVar22 = iVar22 + -1;

        uVar14 = uVar5 & 0xff;

        uVar16 = uVar5 >> 0x10 & 0xff;

        uVar15 = uVar5 >> 8 & 0xff;

        uVar5 = *puVar21;

        uVar19 = uVar5 >> 0x10 & 0xff;

        uVar13 = uVar5 & 0xff;

        uVar10 = uVar5 >> 0x18;

        uVar20 = uVar5 >> 8 & 0xff;

        if ((uVar4 & 1) != 0) {

          uVar17 = (ushort)bVar2 * (short)uVar16 + 1;

          uVar18 = (ushort)bVar3 * (short)uVar14 + 1;

          uVar16 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar17 = (ushort)bVar1 * (short)uVar15 + 1;

          uVar15 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar14 = (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

        }

        sVar11 = (short)uVar24;

        if (((uVar4 & 0x50) != 0) && (uVar24 < 0xff)) {

          uVar17 = sVar11 * (short)uVar16 + 1;

          uVar16 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar17 = (short)uVar15 * sVar11 + 1;

          uVar15 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar17 = (short)uVar14 * sVar11 + 1;

          uVar14 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

        }

        sVar6 = (short)uVar19;

        sVar7 = (short)uVar20;

        sVar8 = (short)uVar13;

        if (uVar23 < 0x81) {

          if (uVar23 == 0x80) {

LAB_1402af3d2:

            uVar19 = uVar19 + uVar16;

            if (0xff < uVar19) {

              uVar19 = 0xff;

            }

            uVar20 = uVar20 + uVar15;

            if (0xff < uVar20) {

              uVar20 = 0xff;

            }

            uVar13 = uVar13 + uVar14;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

          }

          else {

            bVar9 = (byte)(uVar5 >> 0x18);

            if (uVar23 == 0x10) {

              sVar11 = 0xff - sVar11;

              uVar17 = sVar11 * sVar6 + 1;

              uVar19 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar16;

              uVar17 = sVar11 * sVar7 + 1;

              uVar20 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar15;

              uVar17 = sVar11 * sVar8 + 1;

              uVar13 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar14;

              uVar17 = sVar11 * (ushort)bVar9 + 1;

              uVar10 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar24;

            }

            else if (uVar23 == 0x20) {

              sVar11 = 0xff - sVar11;

              uVar17 = sVar11 * sVar6 + 1;

              uVar19 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar16;

              if (0xff < uVar19) {

                uVar19 = 0xff;

              }

              uVar17 = sVar11 * sVar7 + 1;

              uVar20 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar15;

              if (0xff < uVar20) {

                uVar20 = 0xff;

              }

              uVar17 = sVar8 * sVar11 + 1;

              uVar13 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar14;

              if (0xff < uVar13) {

                uVar13 = 0xff;

              }

              uVar17 = sVar11 * (ushort)bVar9 + 1;

              uVar10 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar24;

              if (0xff < uVar10) {

                uVar10 = 0xff;

              }

            }

            else if (uVar23 == 0x40) goto LAB_1402af3d2;

          }

        }

        else if (uVar23 == 0x100) {

          uVar17 = sVar6 * (short)uVar16 + 1;

          uVar19 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar17 = sVar7 * (short)uVar15 + 1;

          uVar20 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar17 = (short)uVar14 * sVar8 + 1;

          uVar13 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

        }

        else if (uVar23 == 0x200) {

          sVar11 = 0xff - sVar11;

          uVar17 = sVar6 * (short)uVar16 + 1;

          uVar18 = sVar11 * sVar6 + 1;

          uVar19 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8) +

                   (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

          if (0xff < uVar19) {

            uVar19 = 0xff;

          }

          uVar17 = sVar7 * (short)uVar15 + 1;

          uVar18 = sVar11 * sVar7 + 1;

          uVar20 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8) +

                   (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

          if (0xff < uVar20) {

            uVar20 = 0xff;

          }

          uVar17 = sVar8 * (short)uVar14 + 1;

          uVar18 = sVar11 * sVar8 + 1;

          uVar13 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8) +

                   (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

          if (0xff < uVar13) {

            uVar13 = 0xff;

          }

        }

        puVar12 = puVar12 + 1;

        *puVar21 = ((uVar10 << 8 | uVar19) << 8 | uVar20) << 8 | uVar13;

        puVar21 = puVar21 + 1;

      } while (iVar22 != 0);

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar22 = *(int *)(param_1 + 0x3c);

    if (iVar22 == 0) {

      *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

      return;

    }

  } while( true );

}




