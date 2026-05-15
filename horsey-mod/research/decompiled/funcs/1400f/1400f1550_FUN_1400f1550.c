// Address: 0x1400f1550
// Ghidra name: FUN_1400f1550
// ============ 0x1400f1550 FUN_1400f1550 (size=328) ============


int FUN_1400f1550(longlong param_1,undefined8 param_2,undefined4 param_3)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  longlong lVar4;

  int iVar5;

  longlong lVar6;

  uint uVar7;

  

  iVar3 = *(int *)(param_1 + 0x2c);

  if (iVar3 == 0) {

    return 0;

  }

  iVar1 = FUN_1400f0eb0();

  lVar4 = (longlong)iVar3 + *(longlong *)(param_1 + 8);

  if (((ushort)((ushort)*(byte *)(lVar4 + 2) * 0x100 + (ushort)*(byte *)(lVar4 + 3)) != 0) &&

     ((ushort)((ushort)*(byte *)(lVar4 + 9) + (ushort)*(byte *)(lVar4 + 8) * 0x100) == 1)) {

    iVar3 = (uint)*(byte *)(lVar4 + 10) * 0x100 + (*(byte *)(lVar4 + 0xb) - 1);

    iVar5 = 0;

    uVar2 = FUN_1400f0eb0(param_1,param_3);

    uVar2 = uVar2 | iVar1 << 0x10;

    if (-1 < iVar3) {

      do {

        iVar1 = iVar3 + iVar5 >> 1;

        lVar6 = iVar1 * 6 + lVar4;

        uVar7 = (uint)*(byte *)(lVar6 + 0x13) * 0x10000 + (uint)*(byte *)(lVar6 + 0x14) * 0x100 +

                (uint)*(byte *)(lVar6 + 0x12) * 0x1000000 + (uint)*(byte *)(lVar6 + 0x15);

        if (uVar2 < uVar7) {

          iVar3 = iVar1 + -1;

        }

        else {

          if (uVar2 <= uVar7) {

            return (int)(short)((ushort)*(byte *)(lVar6 + 0x16) * 0x100 +

                               (ushort)*(byte *)(lVar6 + 0x17));

          }

          iVar5 = iVar1 + 1;

        }

      } while (iVar5 <= iVar3);

    }

  }

  return 0;

}




