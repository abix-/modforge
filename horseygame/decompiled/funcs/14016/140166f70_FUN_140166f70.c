// Address: 0x140166f70
// Ghidra name: FUN_140166f70
// ============ 0x140166f70 FUN_140166f70 (size=169) ============


void FUN_140166f70(longlong param_1,longlong param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float *pfVar7;

  undefined4 *puVar8;

  

  fVar6 = DAT_140334588;

  fVar5 = DAT_140334578;

  fVar4 = DAT_140334534;

  if (param_3 != 0) {

    pfVar7 = (float *)(param_2 + 0xc);

    puVar8 = (undefined4 *)(param_1 + 8);

    do {

      fVar1 = pfVar7[-1];

      fVar2 = *pfVar7;

      puVar8[-2] = pfVar7[-3] * fVar6 + fVar1 * fVar5 + fVar2 * fVar4;

      fVar3 = pfVar7[-2];

      pfVar7 = pfVar7 + 4;

      *puVar8 = 0;

      puVar8[-1] = fVar3 * fVar6 + fVar1 * fVar4 + fVar2 * fVar5;

      puVar8 = puVar8 + 3;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




