// Address: 0x1401ab2f0
// Ghidra name: FUN_1401ab2f0
// ============ 0x1401ab2f0 FUN_1401ab2f0 (size=65) ============


bool FUN_1401ab2f0(undefined8 param_1,char *param_2,char *param_3)



{

  int iVar1;

  

  if (param_2 == param_3) {

    return true;

  }

  if (((param_2 != (char *)0x0) && (param_3 != (char *)0x0)) && (*param_2 == *param_3)) {

    iVar1 = strcmp(param_2,param_3);

    return iVar1 == 0;

  }

  return false;

}




