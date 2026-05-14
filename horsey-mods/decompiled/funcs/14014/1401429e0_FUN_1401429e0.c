// Address: 0x1401429e0
// Ghidra name: FUN_1401429e0
// ============ 0x1401429e0 FUN_1401429e0 (size=57) ============


bool FUN_1401429e0(char *param_1,undefined1 param_2)



{

  int iVar1;

  

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    if (*param_1 != '0') {

      iVar1 = FUN_14012ef60(param_1,"false");

      return iVar1 != 0;

    }

    return false;

  }

  return (bool)param_2;

}




