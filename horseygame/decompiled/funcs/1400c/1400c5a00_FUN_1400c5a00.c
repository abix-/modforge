// Address: 0x1400c5a00
// Ghidra name: FUN_1400c5a00
// ============ 0x1400c5a00 FUN_1400c5a00 (size=425) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400c5a00(int *param_1)



{

  int iVar1;

  bool bVar2;

  float fVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  

  fVar3 = DAT_14039ca44;

  iVar4 = *param_1;

  if (iVar4 == -1) {

    return;

  }

  fVar5 = (float)param_1[8] + (float)param_1[7];

  bVar2 = DAT_14039ca44 <= fVar5;

  param_1[7] = (int)fVar5;

  if (bVar2) {

    if ((char)param_1[1] == '\0') {

      if ((float)param_1[6] == DAT_14039ca80) {

        param_1[7] = 0x3f800000;

        fVar5 = fVar3;

        goto LAB_1400c5a8f;

      }

      param_1[2] = param_1[3];

      iVar4 = (int)(float)param_1[6];

      param_1[3] = param_1[4];

      param_1[8] = param_1[5];

      *param_1 = iVar4;

    }

    else {

      iVar1 = param_1[2];

      param_1[2] = param_1[3];

      param_1[3] = iVar1;

    }

    param_1[7] = (int)(fVar5 - fVar3);

    fVar5 = fVar5 - fVar3;

  }

LAB_1400c5a8f:

  if (iVar4 == 1) {

    fVar6 = fVar5 * fVar5;

  }

  else if (iVar4 == 2) {

    fVar6 = fVar3 - (fVar3 - fVar5) * (fVar3 - fVar5);

  }

  else if (iVar4 == 3) {

    fVar5 = (float)FUN_1402cfda0(fVar5 * DAT_14039ca50);

    fVar6 = (fVar3 - fVar5) * DAT_14039ca34;

  }

  else if (iVar4 == 4) {

    fVar6 = fVar3;

    if (fVar5 < DAT_14030d098) {

      fVar6 = 0.0;

    }

  }

  else {

    fVar6 = fVar5;

    if (iVar4 == 5) {

      if (DAT_140303360 <= fVar5) {

        fVar5 = (float)FUN_1402cfda0(((fVar3 - fVar5) / DAT_14030d948) * DAT_14039ca50);

        fVar6 = (fVar3 - fVar5) * DAT_14039ca34 * _DAT_14030e11c + fVar3;

      }

      else {

        fVar5 = (float)FUN_1402cfda0((fVar5 / DAT_140303360) * DAT_14039ca50);

        fVar6 = (fVar3 - fVar5) * DAT_14039ca34 * _DAT_14030e120;

      }

    }

  }

  param_1[9] = (int)(((float)param_1[3] - (float)param_1[2]) * (fVar6 - 0.0) + (float)param_1[2]);

  return;

}




