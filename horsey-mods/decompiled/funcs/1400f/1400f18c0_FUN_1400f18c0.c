// Address: 0x1400f18c0
// Ghidra name: FUN_1400f18c0
// ============ 0x1400f18c0 FUN_1400f18c0 (size=242) ============


int FUN_1400f18c0(longlong param_1,int param_2,uint param_3)



{

  uint uVar1;

  int iVar2;

  longlong lVar3;

  int iVar4;

  int iVar5;

  longlong lVar6;

  

  lVar6 = (longlong)*(int *)(param_1 + 0x2c) + *(longlong *)(param_1 + 8);

  if (((*(int *)(param_1 + 0x2c) != 0) &&

      ((ushort)((ushort)*(byte *)(lVar6 + 3) + (ushort)*(byte *)(lVar6 + 2) * 0x100) != 0)) &&

     ((ushort)((ushort)*(byte *)(lVar6 + 9) + (ushort)*(byte *)(lVar6 + 8) * 0x100) == 1)) {

    iVar5 = 0;

    param_3 = param_2 << 0x10 | param_3;

    iVar4 = (*(byte *)(lVar6 + 0xb) - 1) + (uint)*(byte *)(lVar6 + 10) * 0x100;

    if (-1 < iVar4) {

      do {

        iVar2 = iVar4 + iVar5 >> 1;

        lVar3 = iVar2 * 6 + lVar6;

        uVar1 = (uint)*(byte *)(lVar3 + 0x15) +

                (uint)*(byte *)(lVar3 + 0x13) * 0x10000 + (uint)*(byte *)(lVar3 + 0x14) * 0x100 +

                (uint)*(byte *)(lVar3 + 0x12) * 0x1000000;

        if (param_3 < uVar1) {

          iVar4 = iVar2 + -1;

        }

        else {

          if (param_3 <= uVar1) {

            return (int)(short)((ushort)*(byte *)(lVar3 + 0x16) * 0x100 +

                               (ushort)*(byte *)(lVar3 + 0x17));

          }

          iVar5 = iVar2 + 1;

        }

      } while (iVar5 <= iVar4);

    }

  }

  return 0;

}




