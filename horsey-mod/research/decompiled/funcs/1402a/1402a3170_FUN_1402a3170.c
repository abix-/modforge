// Address: 0x1402a3170
// Ghidra name: FUN_1402a3170
// ============ 0x1402a3170 FUN_1402a3170 (size=1171) ============


void FUN_1402a3170(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  byte bVar7;

  uint uVar8;

  short sVar9;

  uint *puVar10;

  ushort uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  ushort uVar16;

  uint uVar17;

  uint uVar18;

  uint *puVar19;

  int iVar20;

  uint uVar21;

  uint uVar22;

  

  iVar20 = *(int *)(param_1 + 0x3c);

  uVar1 = *(uint *)(param_1 + 0x78);

  if (iVar20 == 0) {

    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

    return;

  }

  do {

    puVar10 = *(uint **)(param_1 + 8);

    puVar19 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar20 + -1;

    iVar20 = *(int *)(param_1 + 0x38);

    if (iVar20 != 0) {

      uVar14 = uVar1 & 0x3f0;

      do {

        uVar2 = *puVar10;

        iVar20 = iVar20 + -1;

        uVar22 = uVar2 & 0xff;

        uVar13 = uVar2 >> 0x10 & 0xff;

        uVar21 = uVar2 >> 8 & 0xff;

        uVar3 = *puVar19;

        uVar12 = uVar3 >> 0x10 & 0xff;

        uVar18 = uVar3 & 0xff;

        uVar15 = uVar2 >> 0x18;

        uVar8 = uVar3 >> 0x18;

        uVar17 = uVar3 >> 8 & 0xff;

        bVar7 = (byte)(uVar2 >> 0x18);

        if (((uVar1 & 0x50) != 0) && (uVar15 < 0xff)) {

          uVar11 = (ushort)bVar7 * (short)uVar13 + 1;

          uVar13 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

          uVar11 = (ushort)bVar7 * (short)uVar21 + 1;

          uVar21 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

          uVar11 = (short)uVar22 * (ushort)bVar7 + 1;

          uVar22 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

        }

        uVar11 = (ushort)bVar7;

        sVar4 = (short)uVar18;

        sVar5 = (short)uVar17;

        sVar6 = (short)uVar12;

        if (uVar14 < 0x81) {

          if (uVar14 == 0x80) {

LAB_1402a32be:

            uVar18 = uVar18 + uVar13;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            uVar17 = uVar17 + uVar21;

            if (0xff < uVar17) {

              uVar17 = 0xff;

            }

            uVar12 = uVar12 + uVar22;

            if (0xff < uVar12) {

              uVar12 = 0xff;

            }

          }

          else {

            bVar7 = (byte)(uVar3 >> 0x18);

            if (uVar14 == 0x10) {

              sVar9 = 0xff - uVar11;

              uVar11 = sVar4 * sVar9 + 1;

              uVar18 = ((ushort)((uVar11 >> 8) + uVar11) >> 8) + uVar13;

              uVar11 = sVar5 * sVar9 + 1;

              uVar17 = ((ushort)((uVar11 >> 8) + uVar11) >> 8) + uVar21;

              uVar11 = sVar9 * sVar6 + 1;

              uVar12 = ((ushort)((uVar11 >> 8) + uVar11) >> 8) + uVar22;

              uVar11 = sVar9 * (ushort)bVar7 + 1;

              uVar8 = ((ushort)((uVar11 >> 8) + uVar11) >> 8) + uVar15;

            }

            else if (uVar14 == 0x20) {

              sVar9 = 0xff - uVar11;

              uVar11 = sVar4 * sVar9 + 1;

              uVar18 = ((ushort)((uVar11 >> 8) + uVar11) >> 8) + uVar13;

              if (0xff < uVar18) {

                uVar18 = 0xff;

              }

              uVar11 = sVar9 * sVar5 + 1;

              uVar17 = ((ushort)((uVar11 >> 8) + uVar11) >> 8) + uVar21;

              if (0xff < uVar17) {

                uVar17 = 0xff;

              }

              uVar11 = sVar9 * sVar6 + 1;

              uVar12 = ((ushort)((uVar11 >> 8) + uVar11) >> 8) + uVar22;

              if (0xff < uVar12) {

                uVar12 = 0xff;

              }

              uVar11 = sVar9 * (ushort)bVar7 + 1;

              uVar8 = ((ushort)((uVar11 >> 8) + uVar11) >> 8) + uVar15;

              if (0xff < uVar8) {

                uVar8 = 0xff;

              }

            }

            else if (uVar14 == 0x40) goto LAB_1402a32be;

          }

        }

        else if (uVar14 == 0x100) {

          uVar11 = sVar4 * (short)uVar13 + 1;

          uVar18 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

          uVar11 = sVar5 * (short)uVar21 + 1;

          uVar17 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

          uVar11 = (short)uVar22 * sVar6 + 1;

          uVar12 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

        }

        else if (uVar14 == 0x200) {

          sVar9 = 0xff - uVar11;

          uVar11 = (short)uVar13 * sVar4 + 1;

          uVar16 = sVar9 * sVar4 + 1;

          uVar18 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8) +

                   (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

          if (0xff < uVar18) {

            uVar18 = 0xff;

          }

          uVar11 = (short)uVar21 * sVar5 + 1;

          uVar16 = sVar9 * sVar5 + 1;

          uVar17 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8) +

                   (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

          if (0xff < uVar17) {

            uVar17 = 0xff;

          }

          uVar11 = (short)uVar22 * sVar6 + 1;

          uVar16 = sVar9 * sVar6 + 1;

          uVar12 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8) +

                   (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

          if (0xff < uVar12) {

            uVar12 = 0xff;

          }

        }

        puVar10 = puVar10 + 1;

        *puVar19 = ((uVar8 << 8 | uVar12) << 8 | uVar17) << 8 | uVar18;

        puVar19 = puVar19 + 1;

      } while (iVar20 != 0);

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar20 = *(int *)(param_1 + 0x3c);

    if (iVar20 == 0) {

      *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

      return;

    }

  } while( true );

}




