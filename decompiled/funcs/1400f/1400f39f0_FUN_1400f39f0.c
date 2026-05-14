// Address: 0x1400f39f0
// Ghidra name: FUN_1400f39f0
// ============ 0x1400f39f0 FUN_1400f39f0 (size=635) ============


int FUN_1400f39f0(longlong param_1,int param_2,byte *param_3,int param_4)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  int iVar4;

  int iVar5;

  ushort uVar6;

  uint uVar7;

  int iVar8;

  

  iVar1 = 0;

  if (param_4 != 0) {

    iVar4 = 3;

    iVar5 = 1;

    iVar8 = 2;

    do {

      uVar6 = (ushort)*param_3 * 0x100 + (ushort)param_3[1];

      if (uVar6 < 0x80) {

        if (param_2 <= iVar1) {

          return -1;

        }

        lVar3 = (longlong)iVar1;

        iVar5 = iVar5 + 1;

        iVar1 = iVar1 + 1;

        iVar4 = iVar4 + 1;

        iVar8 = iVar8 + 1;

        if (*(byte *)(lVar3 + param_1) != uVar6) {

          return -1;

        }

      }

      else if (uVar6 < 0x800) {

        if (param_2 <= iVar5) {

          return -1;

        }

        iVar2 = iVar1 + 1;

        if ((ushort)*(byte *)(iVar1 + param_1) != (ushort)((uVar6 >> 6) + 0xc0)) {

          return -1;

        }

        iVar1 = iVar1 + 2;

        iVar5 = iVar5 + 2;

        iVar4 = iVar4 + 2;

        iVar8 = iVar8 + 2;

        if ((ushort)*(byte *)(iVar2 + param_1) != (ushort)((uVar6 & 0x3f) + 0x80)) {

          return -1;

        }

      }

      else {

        if (0xd7ff < uVar6) {

          if (uVar6 < 0xdc00) {

            if (param_2 <= iVar4) {

              return -1;

            }

            uVar7 = (uint)param_3[3] + (uint)uVar6 * 0x400 + (uint)param_3[2] * 0x100 + -0x35fdc00;

            if ((uint)*(byte *)(iVar1 + param_1) != (uVar7 >> 0x12) + 0xf0) {

              return -1;

            }

            if ((uint)*(byte *)((iVar1 + 1) + param_1) != (uVar7 >> 0xc & 0x3f) + 0x80) {

              return -1;

            }

            iVar2 = iVar1 + 3;

            if ((uint)*(byte *)((iVar1 + 2) + param_1) != (uVar7 >> 6 & 0x3f) + 0x80) {

              return -1;

            }

            iVar1 = iVar1 + 4;

            iVar5 = iVar5 + 4;

            iVar4 = iVar4 + 4;

            iVar8 = iVar8 + 4;

            if ((uint)*(byte *)(iVar2 + param_1) != (uVar7 & 0x3f) + 0x80) {

              return -1;

            }

            param_3 = param_3 + 2;

            param_4 = param_4 + -2;

            goto LAB_1400f3c59;

          }

          if (uVar6 < 0xe000) {

            return -1;

          }

        }

        if (((param_2 <= iVar8) ||

            ((ushort)*(byte *)(iVar1 + param_1) != (ushort)((uVar6 >> 0xc) + 0xe0))) ||

           (iVar2 = iVar1 + 2,

           (ushort)*(byte *)((iVar1 + 1) + param_1) != (ushort)((uVar6 >> 6 & 0x3f) + 0x80))) {

          return -1;

        }

        iVar1 = iVar1 + 3;

        iVar5 = iVar5 + 3;

        iVar4 = iVar4 + 3;

        iVar8 = iVar8 + 3;

        if ((ushort)*(byte *)(iVar2 + param_1) != (ushort)((uVar6 & 0x3f) + 0x80)) {

          return -1;

        }

      }

LAB_1400f3c59:

      param_3 = param_3 + 2;

      param_4 = param_4 + -2;

    } while (param_4 != 0);

  }

  return iVar1;

}




