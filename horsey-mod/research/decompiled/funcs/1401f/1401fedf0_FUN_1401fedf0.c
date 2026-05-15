// Address: 0x1401fedf0
// Ghidra name: FUN_1401fedf0
// ============ 0x1401fedf0 FUN_1401fedf0 (size=497) ============


void FUN_1401fedf0(longlong param_1,longlong param_2,int *param_3,float *param_4)



{

  float fVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  byte bVar7;

  float fVar8;

  

  param_4[0] = 0.0;

  param_4[1] = 0.0;

  param_4[2] = 0.0;

  param_4[3] = 0.0;

  param_4[4] = 0.0;

  param_4[5] = 0.0;

  param_4[6] = 0.0;

  param_4[7] = 0.0;

  param_4[8] = 0.0;

  param_4[9] = 0.0;

  param_4[10] = 0.0;

  param_4[0xb] = 0.0;

  bVar7 = FUN_1401538c0();

  *param_4 = (float)bVar7;

  param_4[3] = *(float *)(param_2 + 0x18);

  if (param_3 == (int *)0x0) {

    return;

  }

  iVar2 = *param_3;

  if (iVar2 == 0x30313050) {

LAB_1401feeac:

    param_4[2] = 3.0;

  }

  else if ((((iVar2 == 0x3132564e) || (iVar2 == 0x3231564e)) || (iVar2 == 0x32315659)) ||

          (iVar2 == 0x56555949)) {

    param_4[2] = 1.0;

  }

  else {

    uVar3 = param_3[6];

    if (uVar3 == 0x12000500) {

      param_4[2] = 2.0;

    }

    else {

      if (((uVar3 & 0x7c00) == 0x2400) && ((uVar3 & 0x3e0) == 0x200)) goto LAB_1401feeac;

      param_4[2] = 0.0;

    }

  }

  fVar6 = DAT_14039ca44;

  fVar5 = DAT_140303394;

  fVar1 = DAT_140303390;

  fVar8 = DAT_14030338c;

  iVar2 = *(int *)(param_2 + 0x38);

  if (*param_3 == 0x13000801) {

    if (iVar2 == 0) {

      param_4[1] = 3.0;

    }

    else if (iVar2 == 1) {

      param_4[1] = 4.0;

      fVar8 = fVar1;

    }

    else if (iVar2 == 2) {

      param_4[1] = 5.0;

      fVar8 = fVar5;

    }

    else {

      fVar8 = param_4[1];

    }

    if (((fVar8 != fVar1) && (fVar8 != fVar5)) && (fVar8 != DAT_14030374c)) goto LAB_1401fef74;

  }

  else {

    if (iVar2 != 2) {

      param_4[1] = 1.0;

      goto LAB_1401fef74;

    }

    param_4[1] = 2.0;

  }

  iVar2 = param_3[1];

  param_4[6] = (float)iVar2;

  iVar4 = param_3[2];

  param_4[4] = fVar6 / (float)iVar2;

  param_4[7] = (float)iVar4;

  param_4[5] = fVar6 / (float)iVar4;

LAB_1401fef74:

  param_4[0xb] = (float)param_3[7];

  if (*(longlong *)(param_1 + 0x1f0) == 0) {

    fVar8 = *(float *)(param_1 + 0x210);

  }

  else {

    fVar8 = *(float *)(*(longlong *)(param_1 + 0x1f0) + 0x20);

  }

  if ((fVar8 < (float)param_3[8]) && (0.0 < fVar8)) {

    param_4[8] = 2.0;

    fVar1 = (float)param_3[8];

    param_4[10] = fVar6 / fVar8;

    param_4[9] = fVar8 / (fVar1 * fVar1);

  }

  return;

}




