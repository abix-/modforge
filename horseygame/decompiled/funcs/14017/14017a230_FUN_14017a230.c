// Address: 0x14017a230
// Ghidra name: FUN_14017a230
// ============ 0x14017a230 FUN_14017a230 (size=197) ============


uint FUN_14017a230(int *param_1,byte param_2,byte param_3,byte param_4,byte param_5)



{

  longlong lVar1;

  byte bVar2;

  uint uVar3;

  uint uVar4;

  longlong lVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  

  bVar2 = 0;

  uVar3 = 0;

  uVar7 = 0xffffffff;

  if (0 < *param_1) {

    lVar1 = *(longlong *)(param_1 + 2);

    do {

      lVar5 = (longlong)(int)uVar3;

      iVar6 = (uint)*(byte *)(lVar1 + 2 + lVar5 * 4) - (uint)param_4;

      iVar8 = (uint)*(byte *)(lVar1 + 3 + lVar5 * 4) - (uint)param_5;

      iVar9 = (uint)*(byte *)(lVar1 + 1 + lVar5 * 4) - (uint)param_3;

      iVar10 = (uint)*(byte *)(lVar1 + lVar5 * 4) - (uint)param_2;

      uVar4 = iVar6 * iVar6 + iVar8 * iVar8 + iVar9 * iVar9 + iVar10 * iVar10;

      if ((uVar4 < uVar7) && (bVar2 = (byte)uVar3, uVar7 = uVar4, uVar4 == 0)) {

        return uVar3;

      }

      uVar3 = uVar3 + 1;

    } while ((int)uVar3 < *param_1);

    uVar3 = (uint)bVar2;

  }

  return uVar3;

}




