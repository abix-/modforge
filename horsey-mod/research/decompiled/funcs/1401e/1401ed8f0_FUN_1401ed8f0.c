// Address: 0x1401ed8f0
// Ghidra name: FUN_1401ed8f0
// ============ 0x1401ed8f0 FUN_1401ed8f0 (size=301) ============


undefined8 FUN_1401ed8f0(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  float *pfVar1;

  float fVar2;

  float *pfVar3;

  longlong lVar4;

  float *pfVar5;

  longlong lVar6;

  longlong lVar7;

  

  lVar6 = (longlong)param_4;

  pfVar3 = (float *)FUN_14014b940(param_1,(longlong)(param_4 * 2) << 2,0,param_2 + 8);

  fVar2 = DAT_14039ca34;

  if (pfVar3 == (float *)0x0) {

    return 0;

  }

  lVar4 = 0;

  *(longlong *)(param_2 + 0x10) = lVar6;

  if (3 < lVar6) {

    pfVar5 = (float *)(param_3 + 8);

    lVar7 = (lVar6 - 4U >> 2) + 1;

    lVar4 = lVar7 * 4;

    do {

      *pfVar3 = pfVar5[-2] + fVar2;

      pfVar3[1] = pfVar5[-1] + fVar2;

      pfVar3[2] = *pfVar5 + fVar2;

      pfVar3[3] = pfVar5[1] + fVar2;

      pfVar3[4] = pfVar5[2] + fVar2;

      pfVar3[5] = pfVar5[3] + fVar2;

      pfVar3[6] = pfVar5[4] + fVar2;

      pfVar1 = pfVar5 + 5;

      pfVar5 = pfVar5 + 8;

      pfVar3[7] = *pfVar1 + fVar2;

      pfVar3 = pfVar3 + 8;

      lVar7 = lVar7 + -1;

    } while (lVar7 != 0);

  }

  for (; lVar4 < lVar6; lVar4 = lVar4 + 1) {

    *pfVar3 = *(float *)(param_3 + lVar4 * 8) + fVar2;

    pfVar3[1] = *(float *)(param_3 + 4 + lVar4 * 8) + fVar2;

    pfVar3 = pfVar3 + 2;

  }

  return 1;

}




