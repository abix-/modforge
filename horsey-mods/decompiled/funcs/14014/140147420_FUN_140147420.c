// Address: 0x140147420
// Ghidra name: FUN_140147420
// ============ 0x140147420 FUN_140147420 (size=141) ============


void FUN_140147420(int param_1,int param_2,float *param_3,int param_4,float *param_5,int param_6)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float *pfVar5;

  float *pfVar6;

  int iVar7;

  

  if (param_2 != 0) {

    do {

      param_2 = param_2 + -1;

      pfVar5 = param_5;

      pfVar6 = param_3;

      for (iVar7 = param_1; iVar7 != 0; iVar7 = iVar7 + -1) {

        fVar1 = *pfVar6;

        fVar2 = pfVar6[1];

        fVar3 = pfVar6[2];

        fVar4 = pfVar6[3];

        pfVar6 = pfVar6 + 4;

        *pfVar5 = fVar1;

        pfVar5[1] = fVar2 * fVar1;

        pfVar5[2] = fVar3 * fVar1;

        pfVar5[3] = fVar4 * fVar1;

        pfVar5 = pfVar5 + 4;

      }

      param_3 = (float *)((longlong)param_3 + (longlong)param_4);

      param_5 = (float *)((longlong)param_5 + (longlong)param_6);

    } while (param_2 != 0);

  }

  return;

}




