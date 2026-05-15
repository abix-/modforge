// Address: 0x14000c610
// Ghidra name: FUN_14000c610
// ============ 0x14000c610 FUN_14000c610 (size=447) ============


undefined8 FUN_14000c610(longlong param_1,float *param_2,float *param_3,float *param_4)



{

  float extraout_XMM0_Da;

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  fVar6 = param_3[2] - *param_3;

  fVar7 = param_3[3] - param_3[1];

  fVar4 = *param_3 -

          ((param_4[3] * *(float *)(param_1 + 0x10) - param_4[2] * *(float *)(param_1 + 0x14)) +

          *param_4);

  fVar5 = param_3[1] -

          (*(float *)(param_1 + 0x10) * param_4[2] + param_4[3] * *(float *)(param_1 + 0x14) +

          param_4[1]);

  fVar3 = fVar7 * fVar5 + fVar6 * fVar4;

  fVar2 = fVar7 * fVar7 + fVar6 * fVar6;

  fVar1 = fVar3 * fVar3 -

          ((fVar5 * fVar5 + fVar4 * fVar4) - *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0xc))

          * fVar2;

  if ((0.0 <= fVar1) && (DAT_14039c9f0 <= fVar2)) {

    if (fVar1 < 0.0) {

      FUN_1402cdfa0(fVar1);

      fVar1 = extraout_XMM0_Da;

    }

    else {

      fVar1 = SQRT(fVar1);

    }

    fVar1 = (float)((uint)(fVar1 + fVar3) ^ DAT_14039cac0);

    if ((0.0 <= fVar1) && (fVar1 <= fVar2 * param_3[4])) {

      fVar1 = fVar1 / fVar2;

      param_2[2] = fVar1;

      *param_2 = fVar1 * fVar6 + fVar4;

      param_2[1] = fVar1 * fVar7 + fVar5;

      FUN_1400058e0(param_2);

      return 1;

    }

  }

  return 0;

}




