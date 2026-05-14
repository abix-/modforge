// Address: 0x140185790
// Ghidra name: FUN_140185790
// ============ 0x140185790 FUN_140185790 (size=267) ============


undefined1 FUN_140185790(int *param_1,int *param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  char cVar7;

  int iVar8;

  int iVar9;

  

  if (param_1 == (int *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403376fc);

    return 0;

  }

  if (param_2 == (int *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403380bc);

    return 0;

  }

  cVar7 = FUN_140185e20();

  if ((cVar7 != '\0') || (cVar7 = FUN_140185e20(param_2), cVar7 != '\0')) {

    FUN_14012e850("Potential rect math overflow");

    return 0;

  }

  if (param_3 == (int *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","result");

    return 0;

  }

  iVar1 = *param_2;

  iVar2 = param_2[2];

  iVar3 = *param_1;

  iVar4 = param_1[2];

  iVar5 = iVar1;

  if (iVar1 <= iVar3) {

    iVar5 = iVar3;

  }

  *param_3 = iVar5;

  iVar8 = iVar2 + iVar1;

  if (iVar4 + iVar3 <= iVar2 + iVar1) {

    iVar8 = iVar4 + iVar3;

  }

  param_3[2] = iVar8 - iVar5;

  iVar1 = param_2[1];

  iVar2 = param_2[3];

  iVar3 = param_1[1];

  iVar4 = param_1[3];

  iVar6 = iVar1;

  if (iVar1 <= iVar3) {

    iVar6 = iVar3;

  }

  param_3[1] = iVar6;

  iVar9 = iVar2 + iVar1;

  if (iVar4 + iVar3 <= iVar2 + iVar1) {

    iVar9 = iVar4 + iVar3;

  }

  param_3[3] = iVar9 - iVar6;

  if (iVar8 - iVar5 < 1) {

    return 0;

  }

  if (iVar9 - iVar6 < 1) {

    return 0;

  }

  return 1;

}




