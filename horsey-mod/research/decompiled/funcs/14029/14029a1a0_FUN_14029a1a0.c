// Address: 0x14029a1a0
// Ghidra name: FUN_14029a1a0
// ============ 0x14029a1a0 FUN_14029a1a0 (size=751) ============


void FUN_14029a1a0(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  ushort *puVar6;

  uint *puVar7;

  int iVar8;

  int iVar9;

  

  uVar1 = *(uint *)(param_1 + 0x38);

  puVar7 = *(uint **)(param_1 + 8);

  puVar6 = *(ushort **)(param_1 + 0x30);

  iVar8 = *(int *)(param_1 + 0x1c) >> 2;

  iVar9 = *(int *)(param_1 + 0x44) >> 1;

  iVar4 = *(int *)(param_1 + 0x3c);

  while (iVar4 != 0) {

    iVar5 = uVar1 + 3;

    iVar5 = (int)((iVar5 >> 0x1f & 3U) + iVar5) >> 2;

    uVar3 = uVar1 & 3;

    if (uVar3 == 0) goto LAB_14029a23b;

    if (uVar3 == 1) goto LAB_14029a3d0;

    if (uVar3 == 2) goto LAB_14029a349;

    if (uVar3 == 3) {

      while( true ) {

        uVar3 = *puVar7;

        if (uVar3 >> 0x1b != 0) {

          if (uVar3 >> 0x1b == 0x1f) {

            *puVar6 = ((ushort)(uVar3 >> 6) & 0x3e0) + ((ushort)(uVar3 >> 9) & 0x7c00) +

                      ((ushort)(uVar3 >> 3) & (ushort)(uVar3 >> 0x1b));

          }

          else {

            uVar2 = CONCAT22(*puVar6,*puVar6) & 0x3e07c1f;

            uVar3 = ((((uVar3 & 0xf800) * 0x400 + (uVar3 >> 3 & 0x1f) + (uVar3 >> 9 & 0x7c00)) -

                     uVar2) * (uVar3 >> 0x1b) >> 5) + uVar2 & 0x3e07c1f;

            *puVar6 = (ushort)(uVar3 >> 0x10) | (ushort)uVar3;

          }

        }

        puVar7 = puVar7 + 1;

        puVar6 = puVar6 + 1;

LAB_14029a349:

        uVar3 = *puVar7;

        if (uVar3 >> 0x1b != 0) {

          if (uVar3 >> 0x1b == 0x1f) {

            *puVar6 = ((ushort)(uVar3 >> 6) & 0x3e0) +

                      ((ushort)(uVar3 >> 3) & (ushort)(uVar3 >> 0x1b)) +

                      ((ushort)(uVar3 >> 9) & 0x7c00);

          }

          else {

            uVar2 = CONCAT22(*puVar6,*puVar6) & 0x3e07c1f;

            uVar3 = ((((uVar3 & 0xf800) * 0x400 + (uVar3 >> 3 & 0x1f) + (uVar3 >> 9 & 0x7c00)) -

                     uVar2) * (uVar3 >> 0x1b) >> 5) + uVar2 & 0x3e07c1f;

            *puVar6 = (ushort)(uVar3 >> 0x10) | (ushort)uVar3;

          }

        }

        puVar7 = puVar7 + 1;

        puVar6 = puVar6 + 1;

LAB_14029a3d0:

        uVar3 = *puVar7;

        if (uVar3 >> 0x1b != 0) {

          if (uVar3 >> 0x1b == 0x1f) {

            *puVar6 = ((ushort)(uVar3 >> 6) & 0x3e0) +

                      ((ushort)(uVar3 >> 3) & (ushort)(uVar3 >> 0x1b)) +

                      ((ushort)(uVar3 >> 9) & 0x7c00);

          }

          else {

            uVar2 = CONCAT22(*puVar6,*puVar6) & 0x3e07c1f;

            uVar3 = ((((uVar3 & 0xf800) * 0x400 + (uVar3 >> 3 & 0x1f) + (uVar3 >> 9 & 0x7c00)) -

                     uVar2) * (uVar3 >> 0x1b) >> 5) + uVar2 & 0x3e07c1f;

            *puVar6 = (ushort)(uVar3 >> 0x10) | (ushort)uVar3;

          }

        }

        puVar7 = puVar7 + 1;

        puVar6 = puVar6 + 1;

        iVar5 = iVar5 + -1;

        if (iVar5 < 1) break;

LAB_14029a23b:

        uVar3 = *puVar7;

        if (uVar3 >> 0x1b != 0) {

          if (uVar3 >> 0x1b == 0x1f) {

            *puVar6 = ((ushort)(uVar3 >> 6) & 0x3e0) +

                      ((ushort)(uVar3 >> 3) & (ushort)(uVar3 >> 0x1b)) +

                      ((ushort)(uVar3 >> 9) & 0x7c00);

          }

          else {

            uVar2 = CONCAT22(*puVar6,*puVar6) & 0x3e07c1f;

            uVar3 = ((((uVar3 & 0xf800) * 0x400 + (uVar3 >> 3 & 0x1f) + (uVar3 >> 9 & 0x7c00)) -

                     uVar2) * (uVar3 >> 0x1b) >> 5) + uVar2 & 0x3e07c1f;

            *puVar6 = (ushort)(uVar3 >> 0x10) | (ushort)uVar3;

          }

        }

        puVar7 = puVar7 + 1;

        puVar6 = puVar6 + 1;

      }

      puVar7 = puVar7 + iVar8;

      puVar6 = puVar6 + iVar9;

      iVar4 = iVar4 + -1;

    }

    else {

      puVar7 = puVar7 + iVar8;

      puVar6 = puVar6 + iVar9;

      iVar4 = iVar4 + -1;

    }

  }

  return;

}




