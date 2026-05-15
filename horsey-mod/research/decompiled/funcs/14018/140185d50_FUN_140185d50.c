// Address: 0x140185d50
// Ghidra name: FUN_140185d50
// ============ 0x140185d50 FUN_140185d50 (size=197) ============


bool FUN_140185d50(int *param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  

  if (param_1 == (int *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403376fc);

    return false;

  }

  if (param_2 == (int *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403380bc);

    return false;

  }

  piVar5 = param_2;

  cVar1 = FUN_140185e20();

  if ((cVar1 != '\0') || (cVar1 = FUN_140185e20(piVar5), cVar1 != '\0')) {

    FUN_14012e850("Potential rect math overflow");

    return false;

  }

  iVar3 = *param_2;

  iVar4 = *param_1;

  iVar2 = param_2[2] + iVar3;

  if (param_1[2] + iVar4 <= param_2[2] + iVar3) {

    iVar2 = param_1[2] + iVar4;

  }

  if (iVar3 <= iVar4) {

    iVar3 = iVar4;

  }

  if (iVar2 + -1 < iVar3) {

    return false;

  }

  iVar3 = param_1[1];

  iVar4 = piVar5[1];

  iVar2 = piVar5[3] + iVar4;

  if (param_1[3] + iVar3 <= piVar5[3] + iVar4) {

    iVar2 = param_1[3] + iVar3;

  }

  if (iVar4 <= iVar3) {

    iVar4 = iVar3;

  }

  return iVar4 <= iVar2 + -1;

}




