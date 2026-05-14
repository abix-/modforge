// Address: 0x14004cf80
// Ghidra name: FUN_14004cf80
// ============ 0x14004cf80 FUN_14004cf80 (size=452) ============


void FUN_14004cf80(int param_1,longlong param_2,int param_3,int param_4,float *param_5,int param_6)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  longlong lVar5;

  float fVar6;

  float fVar7;

  

  param_1 = param_1 >> 2;

  pfVar4 = (float *)(param_2 + (longlong)param_3 * 4);

  pfVar3 = pfVar4 + param_4;

  if (0 < param_1) {

    lVar5 = (longlong)param_6;

    do {

      fVar7 = *pfVar4 - *pfVar3;

      fVar6 = pfVar4[-1] - pfVar3[-1];

      *pfVar4 = *pfVar3 + *pfVar4;

      pfVar4[-1] = pfVar4[-1] + pfVar3[-1];

      *pfVar3 = fVar7 * *param_5 - fVar6 * param_5[1];

      pfVar1 = param_5 + lVar5;

      pfVar3[-1] = fVar6 * *param_5 + fVar7 * param_5[1];

      fVar7 = pfVar4[-2] - pfVar3[-2];

      fVar6 = pfVar4[-3] - pfVar3[-3];

      pfVar4[-2] = pfVar4[-2] + pfVar3[-2];

      pfVar4[-3] = pfVar4[-3] + pfVar3[-3];

      pfVar3[-2] = fVar7 * *pfVar1 - fVar6 * pfVar1[1];

      pfVar2 = pfVar1 + lVar5;

      pfVar3[-3] = fVar7 * pfVar1[1] + fVar6 * *pfVar1;

      fVar7 = pfVar4[-4] - pfVar3[-4];

      fVar6 = pfVar4[-5] - pfVar3[-5];

      pfVar4[-4] = pfVar3[-4] + pfVar4[-4];

      pfVar4[-5] = pfVar4[-5] + pfVar3[-5];

      pfVar3[-4] = fVar7 * *pfVar2 - fVar6 * pfVar2[1];

      pfVar1 = pfVar2 + lVar5;

      pfVar3[-5] = fVar7 * pfVar2[1] + fVar6 * *pfVar2;

      fVar6 = pfVar4[-7] - pfVar3[-7];

      fVar7 = pfVar4[-6] - pfVar3[-6];

      pfVar4[-6] = pfVar3[-6] + pfVar4[-6];

      pfVar4[-7] = pfVar4[-7] + pfVar3[-7];

      pfVar3[-6] = fVar7 * *pfVar1 - fVar6 * pfVar1[1];

      pfVar4 = pfVar4 + -8;

      param_1 = param_1 + -1;

      param_5 = pfVar1 + lVar5;

      pfVar3[-7] = fVar7 * pfVar1[1] + fVar6 * *pfVar1;

      pfVar3 = pfVar3 + -8;

    } while (0 < param_1);

  }

  return;

}




