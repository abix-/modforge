// Address: 0x140138fc0
// Ghidra name: FUN_140138fc0
// ============ 0x140138fc0 FUN_140138fc0 (size=11) ============


bool FUN_140138fc0(int *param_1,int param_2,int param_3)



{

  int iVar1;

  

  LOCK();

  iVar1 = *param_1;

  if (param_2 == iVar1) {

    *param_1 = param_3;

  }

  UNLOCK();

  return param_2 == iVar1;

}




