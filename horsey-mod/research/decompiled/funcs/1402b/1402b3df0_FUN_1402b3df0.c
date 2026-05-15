// Address: 0x1402b3df0
// Ghidra name: FUN_1402b3df0
// ============ 0x1402b3df0 FUN_1402b3df0 (size=1238) ============


void FUN_1402b3df0(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  uint uVar4;

  int iVar5;

  short sVar6;

  short sVar7;

  short sVar8;

  uint uVar9;

  short sVar10;

  uint uVar11;

  ushort uVar12;

  uint uVar13;

  uint uVar14;

  ushort uVar15;

  ushort uVar16;

  uint uVar17;

  uint uVar18;

  uint uVar19;

  int iVar20;

  uint *puVar21;

  uint *puVar22;

  

  uVar4 = *(uint *)(param_1 + 0x78);

  bVar1 = *(byte *)(param_1 + 0x80);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  uVar12 = 0xff;

  if ((uVar4 & 2) != 0) {

    uVar12 = (ushort)*(byte *)(param_1 + 0x83);

  }

  iVar5 = *(int *)(param_1 + 0x3c);

  do {

    if (iVar5 == 0) {

      *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

      return;

    }

    iVar20 = *(int *)(param_1 + 0x38);

    puVar21 = *(uint **)(param_1 + 8);

    puVar22 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar5 + -1;

    if (iVar20 != 0) {

      uVar13 = uVar4 & 0x3f0;

      do {

        uVar17 = *puVar21;

        iVar20 = iVar20 + -1;

        uVar19 = *puVar22;

        uVar11 = uVar17 >> 0x10 & 0xff;

        uVar14 = uVar17 >> 8 & 0xff;

        uVar17 = uVar17 & 0xff;

        uVar9 = uVar19 >> 0x10 & 0xff;

        uVar18 = uVar19 >> 8 & 0xff;

        uVar19 = uVar19 & 0xff;

        if ((uVar4 & 1) != 0) {

          uVar15 = (ushort)bVar1 * (short)uVar17 + 1;

          uVar17 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          uVar15 = (ushort)bVar2 * (short)uVar14 + 1;

          uVar14 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          uVar15 = (ushort)bVar3 * (short)uVar11 + 1;

          uVar11 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

        }

        if (((uVar4 & 0x50) != 0) && (uVar12 < 0xff)) {

          uVar15 = (short)uVar17 * uVar12 + 1;

          uVar17 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          uVar15 = (short)uVar14 * uVar12 + 1;

          uVar14 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          uVar15 = (short)uVar11 * uVar12 + 1;

          uVar11 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

        }

        sVar6 = (short)uVar9;

        sVar7 = (short)uVar18;

        sVar8 = (short)uVar19;

        if (uVar13 < 0x81) {

          if (uVar13 == 0x80) {

LAB_1402b3fd9:

            uVar9 = uVar9 + uVar17;

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

            uVar18 = uVar18 + uVar14;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            uVar19 = uVar19 + uVar11;

            if (0xff < uVar19) {

              uVar19 = 0xff;

            }

          }

          else if (uVar13 == 0x10) {

            sVar10 = 0xff - uVar12;

            uVar15 = sVar6 * sVar10 + 1;

            uVar9 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar17;

            uVar15 = sVar7 * sVar10 + 1;

            uVar18 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar14;

            uVar15 = sVar8 * sVar10 + 1;

            uVar19 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar11;

          }

          else if (uVar13 == 0x20) {

            sVar10 = 0xff - uVar12;

            uVar15 = sVar10 * sVar6 + 1;

            uVar9 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar17;

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

            uVar15 = sVar10 * sVar7 + 1;

            uVar18 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar14;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            uVar15 = sVar8 * sVar10 + 1;

            uVar19 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar11;

            if (0xff < uVar19) {

              uVar19 = 0xff;

            }

          }

          else if (uVar13 == 0x40) goto LAB_1402b3fd9;

        }

        else if (uVar13 == 0x100) {

          uVar15 = (short)uVar17 * sVar6 + 1;

          uVar9 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          uVar15 = sVar7 * (short)uVar14 + 1;

          uVar18 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          uVar15 = (short)uVar11 * sVar8 + 1;

          uVar19 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

        }

        else if (uVar13 == 0x200) {

          sVar10 = 0xff - uVar12;

          uVar16 = (short)uVar17 * sVar6 + 1;

          uVar15 = sVar10 * sVar6 + 1;

          uVar9 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8) +

                  (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

          if (0xff < uVar9) {

            uVar9 = 0xff;

          }

          uVar16 = sVar10 * sVar7 + 1;

          uVar15 = (short)uVar14 * sVar7 + 1;

          uVar18 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8) +

                   (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

          if (0xff < uVar18) {

            uVar18 = 0xff;

          }

          uVar15 = (short)uVar11 * sVar8 + 1;

          uVar16 = sVar10 * sVar8 + 1;

          uVar19 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8) +

                   (uint)((ushort)((uVar16 >> 8) + uVar16) >> 8);

          if (0xff < uVar19) {

            uVar19 = 0xff;

          }

        }

        puVar21 = puVar21 + 1;

        *puVar22 = (uVar9 << 8 | uVar18) << 8 | uVar19;

        puVar22 = puVar22 + 1;

      } while (iVar20 != 0);

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar5 = *(int *)(param_1 + 0x3c);

  } while( true );

}




