// Address: 0x1402c9ab4
// Ghidra name: FUN_1402c9ab4
// ============ 0x1402c9ab4 FUN_1402c9ab4 (size=237) ============


int FUN_1402c9ab4(longlong param_1,longlong param_2,ulonglong param_3)



{

  uint *puVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  byte *pbVar6;

  byte *pbVar7;

  

  if (*(int *)(param_1 + 0x10) != 0) {

    uVar4 = 0;

    pbVar6 = (byte *)((longlong)*(int *)(param_1 + 0x10) + *(longlong *)(param_2 + 8));

    uVar5 = 0;

    iVar3 = -1;

    uVar2 = *pbVar6 & 0xf;

    pbVar6 = pbVar6 + -(longlong)(char)(&DAT_1403872c0)[uVar2];

    puVar1 = (uint *)(pbVar6 + -4);

    if (*puVar1 >> ((&DAT_1403872d0)[uVar2] & 0x1f) != 0) {

      do {

        pbVar7 = pbVar6 + -(longlong)(char)(&DAT_1403872c0)[*pbVar6 & 0xf];

        uVar4 = uVar4 + (*(uint *)(pbVar7 + -4) >> ((&DAT_1403872d0)[*pbVar6 & 0xf] & 0x1f));

        if (param_3 < (ulonglong)uVar4 + (ulonglong)**(uint **)(param_2 + 0x10) +

                      *(longlong *)(param_2 + 8)) break;

        uVar5 = uVar5 + 1;

        pbVar6 = pbVar7 + -(longlong)(char)(&DAT_1403872c0)[*pbVar7 & 0xf];

        iVar3 = (*(uint *)(pbVar6 + -4) >> ((&DAT_1403872d0)[*pbVar7 & 0xf] & 0x1f)) - 1;

      } while (uVar5 < *puVar1 >> ((&DAT_1403872d0)[uVar2] & 0x1f));

      if (uVar5 != 0) {

        return iVar3;

      }

      return -1;

    }

  }

  return -1;

}




