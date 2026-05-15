// Address: 0x1401858a0
// Ghidra name: FUN_1401858a0
// ============ 0x1401858a0 FUN_1401858a0 (size=324) ============


undefined1 FUN_1401858a0(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  undefined8 uVar2;

  undefined1 uVar3;

  char cVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  

  if (param_1 == (float *)0x0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403376fc);

    return uVar3;

  }

  if (param_2 == (float *)0x0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403380bc);

    return uVar3;

  }

  cVar4 = FUN_140185e60();

  if (cVar4 == '\0') {

    cVar4 = FUN_140185e60(param_2);

    if (cVar4 == '\0') {

      if (param_3 == (float *)0x0) {

        uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","result");

        return uVar3;

      }

      fVar5 = 0.0;

      fVar6 = 0.0;

      fVar7 = 0.0;

      fVar8 = 0.0;

      if ((0.0 <= param_1[2]) && (0.0 < param_1[3] || param_1[3] == 0.0)) {

        if ((0.0 <= param_2[2]) && (0.0 < param_2[3] || param_2[3] == 0.0)) {

          fVar5 = *param_2;

          fVar6 = *param_1;

          fVar7 = fVar5;

          if (fVar6 <= fVar5) {

            fVar7 = fVar6;

          }

          fVar5 = fVar5 + param_2[2];

          fVar6 = fVar6 + param_1[2];

          *param_3 = fVar7;

          if (fVar5 <= fVar6) {

            fVar5 = fVar6;

          }

          param_3[2] = fVar5 - fVar7;

          fVar5 = param_1[1];

          fVar6 = param_2[1];

          fVar7 = param_1[3];

          fVar8 = fVar6;

          if (fVar5 <= fVar6) {

            fVar8 = fVar5;

          }

          fVar1 = param_2[3];

          param_3[1] = fVar8;

          fVar9 = fVar6 + fVar1;

          if (fVar6 + fVar1 <= fVar5 + fVar7) {

            fVar9 = fVar5 + fVar7;

          }

          param_3[3] = fVar9 - fVar8;

          return 1;

        }

        uVar2 = *(undefined8 *)(param_1 + 2);

        *(undefined8 *)param_3 = *(undefined8 *)param_1;

        *(undefined8 *)(param_3 + 2) = uVar2;

        return 1;

      }

      if ((0.0 < param_2[2] || param_2[2] == 0.0) && (0.0 < param_2[3] || param_2[3] == 0.0)) {

        fVar5 = *param_2;

        fVar6 = param_2[1];

        fVar7 = param_2[2];

        fVar8 = param_2[3];

      }

      *param_3 = fVar5;

      param_3[1] = fVar6;

      param_3[2] = fVar7;

      param_3[3] = fVar8;

      return 1;

    }

  }

  uVar3 = FUN_14012e850("Potential rect math overflow");

  return uVar3;

}




