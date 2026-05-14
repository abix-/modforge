// Address: 0x1402b9c80
// Ghidra name: FUN_1402b9c80
// ============ 0x1402b9c80 FUN_1402b9c80 (size=516) ============


void FUN_1402b9c80(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  ushort uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint *puVar11;

  uint *puVar12;

  int iVar13;

  

  iVar3 = *(int *)(param_1 + 0x3c);

  uVar1 = *(uint *)(param_1 + 0x78);

  if (iVar3 == 0) {

    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

    return;

  }

  do {

    iVar13 = *(int *)(param_1 + 0x38);

    puVar11 = *(uint **)(param_1 + 8);

    puVar12 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar3 + -1;

    if (iVar13 != 0) {

      uVar7 = uVar1 & 0x3f0;

      do {

        uVar2 = *puVar11;

        iVar13 = iVar13 + -1;

        uVar6 = uVar2 & 0xff;

        uVar8 = *puVar12;

        uVar10 = uVar8 >> 0x10 & 0xff;

        uVar9 = uVar8 & 0xff;

        uVar4 = uVar8 >> 0x18;

        uVar8 = uVar8 >> 8 & 0xff;

        if (uVar7 < 0x81) {

          if (uVar7 == 0x80) {

LAB_1402b9d3d:

            uVar9 = uVar9 + uVar6;

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

            uVar8 = uVar8 + (uVar2 >> 8 & 0xff);

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            uVar10 = uVar10 + (uVar2 >> 0x10 & 0xff);

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

          }

          else if ((uVar7 == 0x10) || (uVar7 == 0x20)) {

            uVar8 = uVar2 >> 8 & 0xff;

            uVar10 = uVar2 >> 0x10 & 0xff;

            uVar4 = 0xff;

            uVar9 = uVar6;

          }

          else if (uVar7 == 0x40) goto LAB_1402b9d3d;

        }

        else {

          if (uVar7 == 0x100) {

            uVar5 = (short)uVar6 * (short)uVar9 + 1;

            uVar5 = (uVar5 >> 8) + uVar5;

          }

          else {

            if (uVar7 != 0x200) goto LAB_1402b9e0c;

            uVar5 = (short)uVar9 * (short)uVar6 + 1;

            uVar5 = (uVar5 >> 8) + uVar5;

          }

          uVar9 = (uint)(uVar5 >> 8);

          uVar5 = ((ushort)(uVar2 >> 8) & 0xff) * (short)uVar8 + 1;

          uVar8 = (uint)((ushort)((uVar5 >> 8) + uVar5) >> 8);

          uVar5 = ((ushort)(uVar2 >> 0x10) & 0xff) * (short)uVar10 + 1;

          uVar10 = (uint)((ushort)((uVar5 >> 8) + uVar5) >> 8);

        }

LAB_1402b9e0c:

        puVar11 = puVar11 + 1;

        *puVar12 = ((uVar4 << 8 | uVar10) << 8 | uVar8) << 8 | uVar9;

        puVar12 = puVar12 + 1;

      } while (iVar13 != 0);

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar3 = *(int *)(param_1 + 0x3c);

    if (iVar3 == 0) {

      *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

      return;

    }

  } while( true );

}




