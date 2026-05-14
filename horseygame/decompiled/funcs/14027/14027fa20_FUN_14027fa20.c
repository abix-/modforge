// Address: 0x14027fa20
// Ghidra name: FUN_14027fa20
// ============ 0x14027fa20 FUN_14027fa20 (size=85) ============


int FUN_14027fa20(undefined8 param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  longlong lVar2;

  

  lVar2 = FUN_140179690();

  if (lVar2 == 0) {

    return param_4;

  }

  iVar1 = thunk_FUN_1402d89dc(lVar2);

  if (iVar1 < param_2) {

    iVar1 = param_2;

  }

  if (param_3 < iVar1) {

    iVar1 = param_3;

  }

  return iVar1;

}




