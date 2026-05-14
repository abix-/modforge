// Address: 0x1402b39e0
// Ghidra name: FUN_1402b39e0
// ============ 0x1402b39e0 FUN_1402b39e0 (size=1040) ============


void FUN_1402b39e0(longlong param_1)



{

  uint uVar1;

  int iVar2;

  short sVar3;

  short sVar4;

  short sVar5;

  byte bVar6;

  uint uVar7;

  uint uVar8;

  short sVar9;

  ushort uVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  ushort uVar15;

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

      uVar11 = uVar1 & 0x3f0;

      do {

        uVar8 = *puVar19;

        iVar18 = iVar18 + -1;

        uVar17 = *puVar20;

        uVar14 = uVar8 >> 0x10 & 0xff;

        uVar13 = uVar8 >> 8 & 0xff;

        uVar12 = uVar8 & 0xff;

        uVar7 = uVar17 >> 0x10 & 0xff;

        uVar16 = uVar17 >> 8 & 0xff;

        uVar17 = uVar17 & 0xff;

        uVar21 = 0xff;

        bVar6 = (byte)(uVar8 >> 0x18);

        if (((uVar1 & 0x50) != 0) && (uVar8 >> 0x18 < 0xff)) {

          uVar10 = (ushort)bVar6 * (short)uVar12 + 1;

          uVar12 = (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8);

          uVar10 = (ushort)bVar6 * (short)uVar13 + 1;

          uVar13 = (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8);

          uVar10 = (ushort)bVar6 * (short)uVar14 + 1;

          uVar14 = (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8);

        }

        uVar10 = (ushort)bVar6;

        sVar3 = (short)uVar17;

        sVar4 = (short)uVar16;

        sVar5 = (short)uVar7;

        uVar8 = uVar7;

        if (uVar11 < 0x81) {

          if (uVar11 == 0x80) {

LAB_1402b3b16:

            uVar17 = uVar17 + uVar12;

            if (0xff < uVar17) {

              uVar17 = uVar21;

            }

            uVar16 = uVar16 + uVar13;

            if (0xff < uVar16) {

              uVar16 = uVar21;

            }

            uVar8 = uVar7 + uVar14;

            if (0xff < uVar7 + uVar14) {

              uVar8 = 0xff;

            }

          }

          else if (uVar11 == 0x10) {

            sVar9 = 0xff - uVar10;

            uVar10 = sVar9 * sVar3 + 1;

            uVar17 = ((ushort)((uVar10 >> 8) + uVar10) >> 8) + uVar12;

            uVar10 = sVar9 * sVar4 + 1;

            uVar16 = ((ushort)((uVar10 >> 8) + uVar10) >> 8) + uVar13;

            uVar10 = sVar9 * sVar5 + 1;

            uVar8 = ((ushort)((uVar10 >> 8) + uVar10) >> 8) + uVar14;

          }

          else if (uVar11 == 0x20) {

            sVar9 = 0xff - uVar10;

            uVar10 = sVar3 * sVar9 + 1;

            uVar17 = ((ushort)((uVar10 >> 8) + uVar10) >> 8) + uVar12;

            if (0xff < uVar17) {

              uVar17 = uVar21;

            }

            uVar10 = sVar9 * sVar4 + 1;

            uVar16 = ((ushort)((uVar10 >> 8) + uVar10) >> 8) + uVar13;

            if (0xff < uVar16) {

              uVar16 = uVar21;

            }

            uVar10 = sVar9 * sVar5 + 1;

            uVar8 = ((ushort)((uVar10 >> 8) + uVar10) >> 8) + uVar14;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

          }

          else if (uVar11 == 0x40) goto LAB_1402b3b16;

        }

        else if (uVar11 == 0x100) {

          uVar10 = (short)uVar12 * sVar3 + 1;

          uVar17 = (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8);

          uVar10 = (short)uVar13 * sVar4 + 1;

          uVar16 = (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8);

          uVar10 = sVar5 * (short)uVar14 + 1;

          uVar8 = (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8);

        }

        else if (uVar11 == 0x200) {

          sVar9 = 0xff - uVar10;

          uVar15 = sVar3 * (short)uVar12 + 1;

          uVar10 = sVar3 * sVar9 + 1;

          uVar17 = (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8) +

                   (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          if (0xff < uVar17) {

            uVar17 = uVar21;

          }

          uVar15 = sVar4 * (short)uVar13 + 1;

          uVar10 = sVar4 * sVar9 + 1;

          uVar16 = (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8) +

                   (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          if (0xff < uVar16) {

            uVar16 = uVar21;

          }

          uVar15 = sVar5 * (short)uVar14 + 1;

          uVar10 = sVar5 * sVar9 + 1;

          uVar8 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8) +

                  (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8);

          if (0xff < uVar8) {

            uVar8 = uVar21;

          }

        }

        puVar19 = puVar19 + 1;

        *puVar20 = (uVar8 << 8 | uVar16) << 8 | uVar17;

        puVar20 = puVar20 + 1;

      } while (iVar18 != 0);

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar2 = *(int *)(param_1 + 0x3c);

  } while( true );

}




