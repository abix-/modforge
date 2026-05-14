// Address: 0x1401a1bf0
// Ghidra name: FUN_1401a1bf0
// ============ 0x1401a1bf0 FUN_1401a1bf0 (size=80) ============


bool FUN_1401a1bf0(uint param_1,uint param_2)



{

  int iVar1;

  

  if (param_2 + 1 < 2) {

    return true;

  }

  if ((int)(~param_1 ^ ~param_2) < 0) {

    iVar1 = -0x8000 / (int)param_2;

    if (-1 < (int)param_2) {

      return iVar1 <= (int)param_1;

    }

  }

  else {

    iVar1 = (int)(0x7fff / (longlong)(int)param_2);

  }

  return (int)param_1 <= iVar1;

}




