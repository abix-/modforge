// Address: 0x1402bf540
// Ghidra name: FUN_1402bf540
// ============ 0x1402bf540 FUN_1402bf540 (size=1058) ============


void FUN_1402bf540(longlong param_1)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  uint uVar7;

  ushort uVar8;

  ushort uVar9;

  short sVar10;

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

      uVar14 = uVar1 & 0x3f0;

      do {

        uVar3 = *puVar19;

        iVar18 = iVar18 + -1;

        uVar17 = *puVar20;

        uVar13 = uVar3 >> 0x10 & 0xff;

        uVar12 = uVar3 >> 8 & 0xff;

        uVar11 = uVar3 >> 0x18;

        uVar7 = uVar17 >> 0x10 & 0xff;

        uVar16 = uVar17 >> 8 & 0xff;

        uVar17 = uVar17 & 0xff;

        uVar15 = (ushort)uVar3;

        if (((uVar1 & 0x50) != 0) && ((char)uVar3 != -1)) {

          uVar9 = uVar15 & 0xff;

          uVar8 = uVar9 * (short)uVar12 + 1;

          uVar12 = (uint)((ushort)((uVar8 >> 8) + uVar8) >> 8);

          uVar8 = uVar9 * (short)uVar13 + 1;

          uVar13 = (uint)((ushort)((uVar8 >> 8) + uVar8) >> 8);

          uVar9 = uVar9 * (byte)(uVar3 >> 0x18) + 1;

          uVar11 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

        }

        sVar4 = (short)uVar17;

        sVar5 = (short)uVar16;

        sVar6 = (short)uVar7;

        if (uVar14 < 0x81) {

          if (uVar14 == 0x80) {

LAB_1402bf67f:

            uVar17 = uVar17 + uVar12;

            if (0xff < uVar17) {

              uVar17 = 0xff;

            }

            uVar16 = uVar16 + uVar13;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar7 = uVar7 + uVar11;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

          }

          else if (uVar14 == 0x10) {

            sVar10 = 0xff - (uVar15 & 0xff);

            uVar15 = sVar10 * sVar4 + 1;

            uVar17 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar12;

            uVar15 = sVar10 * sVar5 + 1;

            uVar16 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar13;

            uVar15 = sVar10 * sVar6 + 1;

            uVar7 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar11;

          }

          else if (uVar14 == 0x20) {

            sVar10 = 0xff - (uVar15 & 0xff);

            uVar15 = sVar4 * sVar10 + 1;

            uVar17 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar12;

            if (0xff < uVar17) {

              uVar17 = 0xff;

            }

            uVar15 = sVar10 * sVar5 + 1;

            uVar16 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar13;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar15 = sVar10 * sVar6 + 1;

            uVar7 = ((ushort)((uVar15 >> 8) + uVar15) >> 8) + uVar11;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

          }

          else if (uVar14 == 0x40) goto LAB_1402bf67f;

        }

        else if (uVar14 == 0x100) {

          uVar15 = (short)uVar12 * sVar4 + 1;

          uVar17 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          uVar15 = sVar5 * (short)uVar13 + 1;

          uVar16 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          uVar15 = (short)uVar11 * sVar6 + 1;

          uVar7 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

        }

        else if (uVar14 == 0x200) {

          sVar10 = 0xff - (uVar15 & 0xff);

          uVar9 = (short)uVar12 * sVar4 + 1;

          uVar15 = sVar10 * sVar4 + 1;

          uVar17 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8) +

                   (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

          if (0xff < uVar17) {

            uVar17 = 0xff;

          }

          uVar9 = sVar5 * (short)uVar13 + 1;

          uVar15 = sVar5 * sVar10 + 1;

          uVar16 = (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8) +

                   (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

          if (0xff < uVar16) {

            uVar16 = 0xff;

          }

          uVar9 = sVar6 * (short)uVar11 + 1;

          uVar15 = sVar6 * sVar10 + 1;

          uVar7 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8) +

                  (uint)((ushort)((uVar15 >> 8) + uVar15) >> 8);

          if (0xff < uVar7) {

            uVar7 = 0xff;

          }

        }

        puVar19 = puVar19 + 1;

        *puVar20 = (uVar7 << 8 | uVar16) << 8 | uVar17;

        puVar20 = puVar20 + 1;

      } while (iVar18 != 0);

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar2 = *(int *)(param_1 + 0x3c);

  } while( true );

}




