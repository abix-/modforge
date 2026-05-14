// Address: 0x1401a1c70
// Ghidra name: FUN_1401a1c70
// ============ 0x1401a1c70 FUN_1401a1c70 (size=38) ============


int FUN_1401a1c70(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = (param_3 * 3 - param_1) - param_2;

  iVar1 = param_1;

  if (param_1 < param_2) {

    iVar1 = param_2;

    param_2 = param_1;

  }

  if (iVar1 <= iVar2) {

    param_3 = param_2;

  }

  if (iVar2 <= param_2) {

    param_3 = iVar1;

  }

  return param_3;

}




