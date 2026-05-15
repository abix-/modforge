// Address: 0x140049f80
// Ghidra name: FUN_140049f80
// ============ 0x140049f80 FUN_140049f80 (size=411) ============


void FUN_140049f80(longlong param_1,longlong param_2,int param_3)



{

  float fVar1;

  int iVar2;

  undefined2 *puVar3;

  longlong lVar4;

  float *pfVar5;

  longlong lVar6;

  longlong lVar7;

  float fVar8;

  

  fVar1 = DAT_1403053ec;

  lVar7 = (longlong)param_3;

  lVar4 = 0;

  if (3 < lVar7) {

    puVar3 = (undefined2 *)(param_1 + 4);

    lVar6 = (lVar7 - 4U >> 2) + 1;

    pfVar5 = (float *)(param_2 + 8);

    lVar4 = lVar6 * 4;

    do {

      iVar2 = (int)(pfVar5[-2] + fVar1) + -0x43c00000;

      if (0xffff < (int)(pfVar5[-2] + fVar1) + 0xbc408000U) {

        iVar2 = (iVar2 >> 0x1f & 0xffff0001U) + 0x7fff;

      }

      puVar3[-2] = (short)iVar2;

      iVar2 = (int)(pfVar5[-1] + fVar1) + -0x43c00000;

      if (0xffff < (int)(pfVar5[-1] + fVar1) + 0xbc408000U) {

        iVar2 = (iVar2 >> 0x1f & 0xffff0001U) + 0x7fff;

      }

      puVar3[-1] = (short)iVar2;

      iVar2 = (int)(*pfVar5 + fVar1) + -0x43c00000;

      if (0xffff < (int)(*pfVar5 + fVar1) + 0xbc408000U) {

        iVar2 = (iVar2 >> 0x1f & 0xffff0001U) + 0x7fff;

      }

      *puVar3 = (short)iVar2;

      iVar2 = (int)(pfVar5[1] + fVar1) + -0x43c00000;

      if (0xffff < (int)(pfVar5[1] + fVar1) + 0xbc408000U) {

        iVar2 = (iVar2 >> 0x1f & 0xffff0001U) + 0x7fff;

      }

      puVar3[1] = (short)iVar2;

      pfVar5 = pfVar5 + 4;

      puVar3 = puVar3 + 4;

      lVar6 = lVar6 + -1;

    } while (lVar6 != 0);

  }

  for (; lVar4 < lVar7; lVar4 = lVar4 + 1) {

    fVar8 = *(float *)(param_2 + lVar4 * 4) + fVar1;

    iVar2 = (int)fVar8 + -0x43c00000;

    if (0xffff < (int)fVar8 + 0xbc408000U) {

      iVar2 = (iVar2 >> 0x1f & 0xffff0001U) + 0x7fff;

    }

    *(short *)(param_1 + lVar4 * 2) = (short)iVar2;

  }

  return;

}




