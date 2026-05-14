// Address: 0x140211e20
// Ghidra name: FUN_140211e20
// ============ 0x140211e20 FUN_140211e20 (size=408) ============


void FUN_140211e20(longlong param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  uint uVar4;

  float *pfVar5;

  byte *pbVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  

  fVar2 = DAT_1403538f4;

  lVar8 = (longlong)param_3;

  lVar7 = 0;

  if (3 < lVar8) {

    pfVar5 = (float *)(param_2 + 8);

    lVar9 = (lVar8 - 4U >> 2) + 1;

    pbVar6 = (byte *)(param_1 + 2);

    lVar7 = lVar9 * 4;

    do {

      uVar4 = (int)(pfVar5[-2] + fVar2) + 0xb8400000;

      iVar3 = 0x7f - ((int)uVar4 >> 0x1f ^ uVar4);

      pbVar6[-2] = (byte)(iVar3 >> 0x1f) & (byte)iVar3 ^ (byte)uVar4 ^ 0x80;

      uVar4 = (int)(pfVar5[-1] + fVar2) + 0xb8400000;

      iVar3 = 0x7f - ((int)uVar4 >> 0x1f ^ uVar4);

      pbVar6[-1] = (byte)(iVar3 >> 0x1f) & (byte)iVar3 ^ (byte)uVar4 ^ 0x80;

      uVar4 = (int)(*pfVar5 + fVar2) + 0xb8400000;

      iVar3 = 0x7f - ((int)uVar4 >> 0x1f ^ uVar4);

      *pbVar6 = (byte)(iVar3 >> 0x1f) & (byte)iVar3 ^ (byte)uVar4 ^ 0x80;

      pfVar1 = pfVar5 + 1;

      pfVar5 = pfVar5 + 4;

      uVar4 = (int)(*pfVar1 + fVar2) + 0xb8400000;

      iVar3 = 0x7f - ((int)uVar4 >> 0x1f ^ uVar4);

      pbVar6[1] = (byte)(iVar3 >> 0x1f) & (byte)iVar3 ^ (byte)uVar4 ^ 0x80;

      pbVar6 = pbVar6 + 4;

      lVar9 = lVar9 + -1;

    } while (lVar9 != 0);

  }

  for (; lVar7 < lVar8; lVar7 = lVar7 + 1) {

    uVar4 = (int)(*(float *)(param_2 + lVar7 * 4) + fVar2) + 0xb8400000;

    iVar3 = 0x7f - ((int)uVar4 >> 0x1f ^ uVar4);

    *(byte *)(param_1 + lVar7) = (byte)(iVar3 >> 0x1f) & (byte)iVar3 ^ (byte)uVar4 ^ 0x80;

  }

  return;

}




