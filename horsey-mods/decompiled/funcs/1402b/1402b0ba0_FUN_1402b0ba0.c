// Address: 0x1402b0ba0
// Ghidra name: FUN_1402b0ba0
// ============ 0x1402b0ba0 FUN_1402b0ba0 (size=1043) ============


void FUN_1402b0ba0(longlong param_1)



{

  uint uVar1;

  int iVar2;

  short sVar3;

  short sVar4;

  short sVar5;

  byte bVar6;

  uint uVar7;

  short sVar8;

  ushort uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  ushort uVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  int iVar18;

  uint *puVar19;

  uint *puVar20;

  uint uVar21;

  

  uVar1 = *(uint *)(param_1 + 0x78);

  iVar2 = *(int *)(param_1 + 0x3c);

  do {

    if (iVar2 == 0) {

      *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

      return;

    }

    iVar18 = *(int *)(param_1 + 0x38);

    puVar19 = *(uint **)(param_1 + 8);

    puVar20 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar2 + -1;

    if (iVar18 != 0) {

      uVar10 = uVar1 & 0x3f0;

      do {

        uVar17 = *puVar19;

        iVar18 = iVar18 + -1;

        uVar16 = *puVar20;

        uVar13 = uVar17 >> 0x10 & 0xff;

        uVar12 = uVar17 >> 8 & 0xff;

        uVar11 = uVar17 & 0xff;

        uVar7 = uVar16 >> 0x10 & 0xff;

        uVar15 = uVar16 >> 8 & 0xff;

        uVar16 = uVar16 & 0xff;

        uVar21 = 0xff;

        bVar6 = (byte)(uVar17 >> 0x18);

        if (((uVar1 & 0x50) != 0) && (uVar17 >> 0x18 < 0xff)) {

          uVar9 = (ushort)bVar6 * (short)uVar11 + 1;

          uVar11 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

          uVar9 = (ushort)bVar6 * (short)uVar12 + 1;

          uVar12 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

          uVar9 = (ushort)bVar6 * (short)uVar13 + 1;

          uVar13 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

        }

        uVar9 = (ushort)bVar6;

        sVar3 = (short)uVar7;

        sVar4 = (short)uVar15;

        sVar5 = (short)uVar16;

        uVar17 = uVar16;

        if (uVar10 < 0x81) {

          if (uVar10 == 0x80) {

LAB_1402b0cd6:

            uVar7 = uVar7 + uVar11;

            if (0xff < uVar7) {

              uVar7 = uVar21;

            }

            uVar15 = uVar15 + uVar12;

            if (0xff < uVar15) {

              uVar15 = uVar21;

            }

            uVar17 = uVar16 + uVar13;

            if (0xff < uVar16 + uVar13) {

              uVar17 = 0xff;

            }

          }

          else if (uVar10 == 0x10) {

            sVar8 = 0xff - uVar9;

            uVar9 = sVar8 * sVar3 + 1;

            uVar7 = ((ushort)((uVar9 >> 8) + uVar9) >> 8) + uVar11;

            uVar9 = sVar8 * sVar4 + 1;

            uVar15 = ((ushort)((uVar9 >> 8) + uVar9) >> 8) + uVar12;

            uVar9 = sVar8 * sVar5 + 1;

            uVar17 = ((ushort)((uVar9 >> 8) + uVar9) >> 8) + uVar13;

          }

          else if (uVar10 == 0x20) {

            sVar8 = 0xff - uVar9;

            uVar9 = sVar8 * sVar3 + 1;

            uVar7 = ((ushort)((uVar9 >> 8) + uVar9) >> 8) + uVar11;

            if (0xff < uVar7) {

              uVar7 = uVar21;

            }

            uVar9 = sVar8 * sVar4 + 1;

            uVar15 = ((ushort)((uVar9 >> 8) + uVar9) >> 8) + uVar12;

            if (0xff < uVar15) {

              uVar15 = uVar21;

            }

            uVar9 = sVar5 * sVar8 + 1;

            uVar17 = ((ushort)((uVar9 >> 8) + uVar9) >> 8) + uVar13;

            if (0xff < uVar17) {

              uVar17 = 0xff;

            }

          }

          else if (uVar10 == 0x40) goto LAB_1402b0cd6;

        }

        else if (uVar10 == 0x100) {

          uVar9 = (short)uVar11 * sVar3 + 1;

          uVar7 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

          uVar9 = (short)uVar12 * sVar4 + 1;

          uVar15 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

          uVar9 = sVar5 * (short)uVar13 + 1;

          uVar17 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

        }

        else if (uVar10 == 0x200) {

          sVar8 = 0xff - uVar9;

          uVar14 = sVar3 * (short)uVar11 + 1;

          uVar9 = sVar3 * sVar8 + 1;

          uVar7 = (uint)((ushort)((uVar14 >> 8) + uVar14) >> 8) +

                  (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

          if (0xff < uVar7) {

            uVar7 = uVar21;

          }

          uVar14 = sVar4 * (short)uVar12 + 1;

          uVar9 = sVar4 * sVar8 + 1;

          uVar15 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8) +

                   (uint)((ushort)((uVar14 >> 8) + uVar14) >> 8);

          if (0xff < uVar15) {

            uVar15 = uVar21;

          }

          uVar14 = sVar5 * (short)uVar13 + 1;

          uVar9 = sVar5 * sVar8 + 1;

          uVar17 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8) +

                   (uint)((ushort)((uVar14 >> 8) + uVar14) >> 8);

          if (0xff < uVar17) {

            uVar17 = uVar21;

          }

        }

        puVar19 = puVar19 + 1;

        *puVar20 = (uVar7 << 8 | uVar15) << 8 | uVar17;

        puVar20 = puVar20 + 1;

      } while (iVar18 != 0);

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar2 = *(int *)(param_1 + 0x3c);

  } while( true );

}




