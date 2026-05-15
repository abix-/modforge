// Address: 0x1402c8bd4
// Ghidra name: FUN_1402c8bd4
// ============ 0x1402c8bd4 FUN_1402c8bd4 (size=489) ============


void FUN_1402c8bd4(longlong param_1,longlong param_2)



{

  byte bVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  undefined4 uVar5;

  ulonglong uVar6;

  byte *pbVar7;

  longlong lVar8;

  byte *pbVar9;

  

  pbVar9 = *(byte **)(param_1 + 0x10);

  *(byte **)(param_1 + 8) = pbVar9;

  pbVar7 = pbVar9 + -(longlong)(char)(&DAT_1403872c0)[*pbVar9 & 0xf];

  *(uint *)(param_1 + 0x18) = *(uint *)(pbVar7 + -4) >> ((&DAT_1403872d0)[*pbVar9 & 0xf] & 0x1f);

  *(byte **)(param_1 + 8) = pbVar7;

  bVar1 = (&DAT_1403872d0)[*pbVar7 & 0xf];

  pbVar7 = pbVar7 + -(longlong)(char)(&DAT_1403872c0)[*pbVar7 & 0xf];

  uVar3 = *(uint *)(pbVar7 + -4);

  *(byte **)(param_1 + 8) = pbVar7;

  *(uint *)(param_1 + 0x1c) = uVar3 >> (bVar1 & 0x1f);

  bVar1 = (&DAT_1403872d0)[*pbVar7 & 0xf];

  pbVar7 = pbVar7 + -(longlong)(char)(&DAT_1403872c0)[*pbVar7 & 0xf];

  uVar3 = *(uint *)(pbVar7 + -4);

  pbVar9 = pbVar7 + 4;

  *(byte **)(param_1 + 8) = pbVar7;

  iVar4 = *(int *)(param_2 + 8);

  *(uint *)(param_1 + 0x20) = uVar3 >> (bVar1 & 0x1f);

  uVar5 = *(undefined4 *)pbVar7;

  *(byte **)(param_1 + 8) = pbVar9;

  *(undefined4 *)(param_1 + 0x24) = uVar5;

  if (iVar4 != 0) {

    uVar6 = (ulonglong)*(uint *)(param_2 + 8);

    do {

      lVar8 = (longlong)(char)(&DAT_1403872c0)[*pbVar9 & 0xf];

      bVar1 = (&DAT_1403872d0)[*pbVar9 & 0xf];

      pbVar7 = pbVar9 + -lVar8;

      uVar3 = *(uint *)(pbVar7 + -4);

      *(byte **)(param_1 + 8) = pbVar7;

      *(uint *)(param_1 + 0x18) = uVar3 >> (bVar1 & 0x1f);

      cVar2 = (&DAT_1403872c0)[*pbVar7 & 0xf];

      bVar1 = (&DAT_1403872d0)[*pbVar7 & 0xf];

      pbVar7 = pbVar9 + (-lVar8 - (longlong)cVar2);

      uVar3 = *(uint *)(pbVar7 + -4);

      *(byte **)(param_1 + 8) = pbVar7;

      *(uint *)(param_1 + 0x1c) = uVar3 >> (bVar1 & 0x1f);

      bVar1 = (&DAT_1403872d0)[*pbVar7 & 0xf];

      pbVar9 = pbVar9 + ((-(longlong)cVar2 - (longlong)(char)(&DAT_1403872c0)[*pbVar7 & 0xf]) -

                        lVar8);

      uVar3 = *(uint *)(pbVar9 + -4);

      *(byte **)(param_1 + 8) = pbVar9;

      *(uint *)(param_1 + 0x20) = uVar3 >> (bVar1 & 0x1f);

      uVar5 = *(undefined4 *)pbVar9;

      pbVar9 = pbVar9 + 4;

      *(byte **)(param_1 + 8) = pbVar9;

      *(undefined4 *)(param_1 + 0x24) = uVar5;

      lVar8 = (longlong)(char)(&DAT_1403872c0)[*pbVar9 & 0xf];

      bVar1 = (&DAT_1403872d0)[*pbVar9 & 0xf];

      pbVar7 = pbVar9 + -lVar8;

      uVar3 = *(uint *)(pbVar7 + -4);

      *(byte **)(param_1 + 8) = pbVar7;

      *(uint *)(param_1 + 0x18) = uVar3 >> (bVar1 & 0x1f);

      cVar2 = (&DAT_1403872c0)[*pbVar7 & 0xf];

      bVar1 = (&DAT_1403872d0)[*pbVar7 & 0xf];

      pbVar7 = pbVar9 + (-lVar8 - (longlong)cVar2);

      uVar3 = *(uint *)(pbVar7 + -4);

      *(byte **)(param_1 + 8) = pbVar7;

      *(uint *)(param_1 + 0x1c) = uVar3 >> (bVar1 & 0x1f);

      bVar1 = (&DAT_1403872d0)[*pbVar7 & 0xf];

      pbVar9 = pbVar9 + ((-(longlong)cVar2 - (longlong)(char)(&DAT_1403872c0)[*pbVar7 & 0xf]) -

                        lVar8);

      uVar3 = *(uint *)(pbVar9 + -4);

      *(byte **)(param_1 + 8) = pbVar9;

      *(uint *)(param_1 + 0x20) = uVar3 >> (bVar1 & 0x1f);

      uVar5 = *(undefined4 *)pbVar9;

      pbVar9 = pbVar9 + 4;

      *(byte **)(param_1 + 8) = pbVar9;

      *(undefined4 *)(param_1 + 0x24) = uVar5;

      uVar6 = uVar6 - 1;

    } while (uVar6 != 0);

  }

  return;

}




