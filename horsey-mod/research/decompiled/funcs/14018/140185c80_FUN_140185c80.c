// Address: 0x140185c80
// Ghidra name: FUN_140185c80
// ============ 0x140185c80 FUN_140185c80 (size=206) ============


bool FUN_140185c80(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  char cVar3;

  float fVar4;

  float fVar5;

  

  if (param_1 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403376fc);

    return false;

  }

  if (param_2 == (float *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403380bc);

    return false;

  }

  cVar3 = FUN_140185e60();

  if ((cVar3 != '\0') || (cVar3 = FUN_140185e60(param_2), cVar3 != '\0')) {

    FUN_14012e850("Potential rect math overflow");

    return false;

  }

  fVar1 = *param_1;

  fVar2 = *param_2;

  fVar5 = fVar2;

  if (fVar2 <= fVar1) {

    fVar5 = fVar1;

  }

  fVar4 = fVar2 + param_2[2];

  if (fVar1 + param_1[2] <= fVar2 + param_2[2]) {

    fVar4 = fVar1 + param_1[2];

  }

  if (fVar4 - 0.0 < fVar5) {

    return false;

  }

  fVar1 = param_1[1];

  fVar2 = param_2[1];

  fVar5 = fVar2;

  if (fVar2 <= fVar1) {

    fVar5 = fVar1;

  }

  fVar4 = fVar2 + param_2[3];

  if (fVar1 + param_1[3] <= fVar2 + param_2[3]) {

    fVar4 = fVar1 + param_1[3];

  }

  return fVar5 <= fVar4 - 0.0;

}




