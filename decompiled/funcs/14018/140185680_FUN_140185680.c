// Address: 0x140185680
// Ghidra name: FUN_140185680
// ============ 0x140185680 FUN_140185680 (size=269) ============


undefined1 FUN_140185680(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  char cVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  if (param_1 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403376fc);

    return 0;

  }

  if (param_2 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403380bc);

    return 0;

  }

  cVar3 = FUN_140185e60();

  if ((cVar3 != '\0') || (cVar3 = FUN_140185e60(param_2), cVar3 != '\0')) {

    FUN_14012e850("Potential rect math overflow");

    return 0;

  }

  if (param_3 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","result");

    return 0;

  }

  fVar1 = *param_1;

  fVar2 = *param_2;

  fVar5 = param_1[2];

  fVar4 = fVar2;

  if (fVar2 <= fVar1) {

    fVar4 = fVar1;

  }

  fVar7 = param_2[2];

  *param_3 = fVar4;

  fVar6 = fVar2 + fVar7;

  if (fVar1 + fVar5 <= fVar2 + fVar7) {

    fVar6 = fVar1 + fVar5;

  }

  param_3[2] = fVar6 - fVar4;

  fVar1 = param_1[1];

  fVar2 = param_2[1];

  fVar5 = fVar2;

  if (fVar2 <= fVar1) {

    fVar5 = fVar1;

  }

  fVar7 = fVar2 + param_2[3];

  if (fVar1 + param_1[3] <= fVar2 + param_2[3]) {

    fVar7 = fVar1 + param_1[3];

  }

  param_3[1] = fVar5;

  param_3[3] = fVar7 - fVar5;

  if (fVar6 - fVar4 < 0.0) {

    return 0;

  }

  if (fVar7 - fVar5 < 0.0) {

    return 0;

  }

  return 1;

}




