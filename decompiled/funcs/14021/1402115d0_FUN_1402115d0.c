// Address: 0x1402115d0
// Ghidra name: FUN_1402115d0
// ============ 0x1402115d0 FUN_1402115d0 (size=418) ============


void FUN_1402115d0(longlong param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  uint uVar4;

  float *pfVar5;

  ushort *puVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  

  fVar2 = DAT_1403053ec;

  lVar8 = (longlong)param_3;

  lVar7 = 0;

  if (3 < lVar8) {

    pfVar5 = (float *)(param_2 + 8);

    lVar9 = (lVar8 - 4U >> 2) + 1;

    puVar6 = (ushort *)(param_1 + 4);

    lVar7 = lVar9 * 4;

    do {

      uVar4 = (int)(pfVar5[-2] + fVar2) + 0xbc400000;

      iVar3 = 0x7fff - ((int)uVar4 >> 0x1f ^ uVar4);

      puVar6[-2] = (ushort)(iVar3 >> 0x1f) & (ushort)iVar3 ^ (ushort)uVar4;

      uVar4 = (int)(pfVar5[-1] + fVar2) + 0xbc400000;

      iVar3 = 0x7fff - ((int)uVar4 >> 0x1f ^ uVar4);

      puVar6[-1] = (ushort)(iVar3 >> 0x1f) & (ushort)iVar3 ^ (ushort)uVar4;

      uVar4 = (int)(*pfVar5 + fVar2) + 0xbc400000;

      iVar3 = 0x7fff - ((int)uVar4 >> 0x1f ^ uVar4);

      *puVar6 = (ushort)(iVar3 >> 0x1f) & (ushort)iVar3 ^ (ushort)uVar4;

      pfVar1 = pfVar5 + 1;

      pfVar5 = pfVar5 + 4;

      uVar4 = (int)(*pfVar1 + fVar2) + 0xbc400000;

      iVar3 = 0x7fff - ((int)uVar4 >> 0x1f ^ uVar4);

      puVar6[1] = (ushort)(iVar3 >> 0x1f) & (ushort)iVar3 ^ (ushort)uVar4;

      puVar6 = puVar6 + 4;

      lVar9 = lVar9 + -1;

    } while (lVar9 != 0);

  }

  for (; lVar7 < lVar8; lVar7 = lVar7 + 1) {

    uVar4 = (int)(*(float *)(param_2 + lVar7 * 4) + fVar2) + 0xbc400000;

    iVar3 = 0x7fff - ((int)uVar4 >> 0x1f ^ uVar4);

    *(ushort *)(param_1 + lVar7 * 2) = (ushort)(iVar3 >> 0x1f) & (ushort)iVar3 ^ (ushort)uVar4;

  }

  return;

}




