// Address: 0x14000c9b0
// Ghidra name: FUN_14000c9b0
// ============ 0x14000c9b0 FUN_14000c9b0 (size=620) ============


undefined8 FUN_14000c9b0(longlong param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  

  fVar3 = param_4[3];

  fVar8 = param_4[2];

  fVar1 = *(float *)(param_1 + 0x10);

  fVar2 = *(float *)(param_1 + 0x14);

  fVar11 = *(float *)(param_1 + 0x18) - fVar1;

  fVar10 = *(float *)(param_1 + 0x1c) - fVar2;

  fVar12 = fVar8 * (param_3[1] - param_4[1]) + fVar3 * (*param_3 - *param_4);

  fVar13 = fVar3 * (param_3[1] - param_4[1]) - fVar8 * (*param_3 - *param_4);

  fVar7 = (float)((uint)fVar11 ^ DAT_14039cac0);

  fVar9 = ((param_3[3] - param_4[1]) * fVar3 - (param_3[2] - *param_4) * fVar8) - fVar13;

  fVar8 = ((param_3[2] - *param_4) * fVar3 + (param_3[3] - param_4[1]) * fVar8) - fVar12;

  fVar3 = fVar7 * fVar7 + fVar10 * fVar10;

  if (fVar3 < 0.0) {

    fVar3 = (float)FUN_1402cdfa0(fVar3);

  }

  else {

    fVar3 = SQRT(fVar3);

  }

  fVar5 = fVar10;

  if (DAT_14039c9f0 <= fVar3) {

    fVar7 = (DAT_14039ca44 / fVar3) * fVar7;

    fVar5 = (DAT_14039ca44 / fVar3) * fVar10;

  }

  fVar4 = (fVar1 - fVar12) * fVar5 + (fVar2 - fVar13) * fVar7;

  fVar3 = fVar8 * fVar5 + fVar9 * fVar7;

  if (((fVar3 != 0.0) && (fVar3 = fVar4 / fVar3, 0.0 <= fVar3)) &&

     (fVar3 < param_3[4] || fVar3 == param_3[4])) {

    fVar6 = fVar11 * fVar11 + fVar10 * fVar10;

    if (((fVar6 != 0.0) &&

        (fVar6 = (((fVar8 * fVar3 + fVar12) - fVar1) * fVar11 +

                 ((fVar9 * fVar3 + fVar13) - fVar2) * fVar10) / fVar6, 0.0 <= fVar6)) &&

       (fVar6 <= DAT_14039ca44)) {

      param_2[2] = fVar3;

      if (0.0 < fVar4) {

        fVar7 = (float)((uint)fVar7 ^ DAT_14039cac0);

        fVar5 = (float)((uint)fVar5 ^ DAT_14039cac0);

      }

      *param_2 = fVar5;

      param_2[1] = fVar7;

      return 1;

    }

  }

  return 0;

}




