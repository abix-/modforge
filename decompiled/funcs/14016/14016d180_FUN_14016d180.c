// Address: 0x14016d180
// Ghidra name: FUN_14016d180
// ============ 0x14016d180 FUN_14016d180 (size=68) ============


void FUN_14016d180(int *param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *param_1;

  iVar2 = param_1[1] + -1 + param_1[3];

  iVar3 = param_1[2] + -1 + iVar1;

  if (*param_2 < iVar1) {

    *param_2 = iVar1;

  }

  else if (iVar3 < *param_2) {

    *param_2 = iVar3;

  }

  if (param_2[1] < param_1[1]) {

    param_2[1] = param_1[1];

    return;

  }

  if (iVar2 < param_2[1]) {

    param_2[1] = iVar2;

  }

  return;

}




