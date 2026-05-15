// Address: 0x1402bd980
// Ghidra name: FUN_1402bd980
// ============ 0x1402bd980 FUN_1402bd980 (size=1295) ============


void FUN_1402bd980(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  short sVar8;

  short sVar9;

  short sVar10;

  uint uVar11;

  short sVar12;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  ushort uVar17;

  ushort uVar18;

  uint uVar19;

  uint uVar20;

  int iVar21;

  uint *puVar22;

  uint uVar23;

  uint *puVar24;

  

  uVar5 = *(uint *)(param_1 + 0x78);

  bVar1 = *(byte *)(param_1 + 0x80);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  bVar4 = *(byte *)(param_1 + 0x83);

  iVar6 = *(int *)(param_1 + 0x3c);

  do {

    if (iVar6 == 0) {

      *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

      return;

    }

    iVar21 = *(int *)(param_1 + 0x38);

    puVar24 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar6 + -1;

    puVar22 = *(uint **)(param_1 + 8);

    if (iVar21 != 0) {

      uVar23 = uVar5 & 0x3f0;

      do {

        uVar7 = *puVar22;

        iVar21 = iVar21 + -1;

        uVar20 = *puVar24;

        uVar16 = uVar7 >> 0x10 & 0xff;

        uVar15 = uVar7 >> 8 & 0xff;

        uVar14 = uVar7 & 0xff;

        uVar13 = uVar7 >> 0x18;

        uVar11 = uVar20 >> 0x10 & 0xff;

        uVar19 = uVar20 >> 8 & 0xff;

        uVar20 = uVar20 & 0xff;

        if ((uVar5 & 1) != 0) {

          uVar17 = (ushort)bVar1 * (short)uVar16 + 1;

          uVar18 = (ushort)bVar3 * (short)uVar14 + 1;

          uVar16 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar17 = (ushort)bVar2 * (short)uVar15 + 1;

          uVar15 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar14 = (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

        }

        if ((uVar5 & 2) != 0) {

          uVar17 = (ushort)bVar4 * (ushort)(byte)(uVar7 >> 0x18) + 1;

          uVar13 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

        }

        sVar12 = (short)uVar13;

        if (((uVar5 & 0x50) != 0) && (uVar13 < 0xff)) {

          uVar17 = sVar12 * (short)uVar16 + 1;

          uVar16 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar17 = (short)uVar15 * sVar12 + 1;

          uVar15 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar17 = (short)uVar14 * sVar12 + 1;

          uVar14 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

        }

        sVar8 = (short)uVar11;

        sVar9 = (short)uVar19;

        sVar10 = (short)uVar20;

        if (uVar23 < 0x81) {

          if (uVar23 == 0x80) {

LAB_1402bdbae:

            uVar11 = uVar11 + uVar16;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar19 = uVar19 + uVar15;

            if (0xff < uVar19) {

              uVar19 = 0xff;

            }

            uVar20 = uVar20 + uVar14;

            if (0xff < uVar20) {

              uVar20 = 0xff;

            }

          }

          else if (uVar23 == 0x10) {

            sVar12 = 0xff - sVar12;

            uVar17 = sVar12 * sVar8 + 1;

            uVar11 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar16;

            uVar17 = sVar12 * sVar9 + 1;

            uVar19 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar15;

            uVar17 = sVar12 * sVar10 + 1;

            uVar20 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar14;

          }

          else if (uVar23 == 0x20) {

            sVar12 = 0xff - sVar12;

            uVar17 = sVar12 * sVar8 + 1;

            uVar11 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar16;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar17 = sVar12 * sVar9 + 1;

            uVar19 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar15;

            if (0xff < uVar19) {

              uVar19 = 0xff;

            }

            uVar17 = sVar10 * sVar12 + 1;

            uVar20 = ((ushort)((uVar17 >> 8) + uVar17) >> 8) + uVar14;

            if (0xff < uVar20) {

              uVar20 = 0xff;

            }

          }

          else if (uVar23 == 0x40) goto LAB_1402bdbae;

        }

        else if (uVar23 == 0x100) {

          uVar17 = sVar8 * (short)uVar16 + 1;

          uVar11 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar17 = (short)uVar15 * sVar9 + 1;

          uVar19 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

          uVar17 = sVar10 * (short)uVar14 + 1;

          uVar20 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8);

        }

        else if (uVar23 == 0x200) {

          sVar12 = 0xff - sVar12;

          uVar18 = sVar8 * (short)uVar16 + 1;

          uVar17 = sVar12 * sVar8 + 1;

          uVar11 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8) +

                   (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

          if (0xff < uVar11) {

            uVar11 = 0xff;

          }

          uVar17 = (short)uVar15 * sVar9 + 1;

          uVar18 = sVar12 * sVar9 + 1;

          uVar19 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8) +

                   (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

          if (0xff < uVar19) {

            uVar19 = 0xff;

          }

          uVar17 = sVar10 * (short)uVar14 + 1;

          uVar18 = sVar12 * sVar10 + 1;

          uVar20 = (uint)((ushort)((uVar17 >> 8) + uVar17) >> 8) +

                   (uint)((ushort)((uVar18 >> 8) + uVar18) >> 8);

          if (0xff < uVar20) {

            uVar20 = 0xff;

          }

        }

        puVar22 = puVar22 + 1;

        *puVar24 = (uVar11 << 8 | uVar19) << 8 | uVar20;

        puVar24 = puVar24 + 1;

      } while (iVar21 != 0);

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar6 = *(int *)(param_1 + 0x3c);

  } while( true );

}




