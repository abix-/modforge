// Address: 0x1402a92f0
// Ghidra name: FUN_1402a92f0
// ============ 0x1402a92f0 FUN_1402a92f0 (size=493) ============


void FUN_1402a92f0(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  ushort uVar5;

  uint *puVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  int iVar11;

  uint *puVar12;

  

  iVar3 = *(int *)(param_1 + 0x3c);

  uVar1 = *(uint *)(param_1 + 0x78);

  if (iVar3 == 0) {

    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

    return;

  }

  do {

    iVar11 = *(int *)(param_1 + 0x38);

    puVar12 = *(uint **)(param_1 + 8);

    puVar6 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar3 + -1;

    if (iVar11 != 0) {

      uVar10 = uVar1 & 0x3f0;

      do {

        uVar9 = *puVar6;

        iVar11 = iVar11 + -1;

        uVar2 = *puVar12;

        uVar7 = uVar2 >> 0x10 & 0xff;

        uVar4 = uVar9 >> 0x10 & 0xff;

        uVar8 = uVar9 >> 8 & 0xff;

        uVar9 = uVar9 & 0xff;

        if (uVar10 < 0x81) {

          if (uVar10 == 0x80) {

LAB_1402a93ac:

            uVar4 = uVar4 + uVar7;

            if (0xff < uVar4) {

              uVar4 = 0xff;

            }

            uVar8 = uVar8 + (uVar2 >> 8 & 0xff);

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            uVar9 = uVar9 + (uVar2 & 0xff);

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

          }

          else if ((uVar10 == 0x10) || (uVar10 == 0x20)) {

            uVar8 = uVar2 >> 8 & 0xff;

            uVar9 = uVar2 & 0xff;

            uVar4 = uVar7;

          }

          else if (uVar10 == 0x40) goto LAB_1402a93ac;

        }

        else {

          if (uVar10 == 0x100) {

            uVar5 = (short)uVar7 * (short)uVar4 + 1;

            uVar5 = (uVar5 >> 8) + uVar5;

          }

          else {

            if (uVar10 != 0x200) goto LAB_1402a946c;

            uVar5 = (short)uVar7 * (short)uVar4 + 1;

            uVar5 = (uVar5 >> 8) + uVar5;

          }

          uVar4 = (uint)(uVar5 >> 8);

          uVar5 = ((ushort)(uVar2 >> 8) & 0xff) * (short)uVar8 + 1;

          uVar8 = (uint)((ushort)((uVar5 >> 8) + uVar5) >> 8);

          uVar5 = ((ushort)uVar2 & 0xff) * (short)uVar9 + 1;

          uVar9 = (uint)((ushort)((uVar5 >> 8) + uVar5) >> 8);

        }

LAB_1402a946c:

        puVar12 = puVar12 + 1;

        *puVar6 = (uVar4 << 8 | uVar8) << 8 | uVar9;

        puVar6 = puVar6 + 1;

      } while (iVar11 != 0);

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




