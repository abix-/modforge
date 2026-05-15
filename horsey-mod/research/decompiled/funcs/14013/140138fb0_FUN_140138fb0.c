// Address: 0x140138fb0
// Ghidra name: FUN_140138fb0
// ============ 0x140138fb0 FUN_140138fb0 (size=7) ============


int FUN_140138fb0(int *param_1,int param_2)



{

  int iVar1;

  

  LOCK();

  iVar1 = *param_1;

  *param_1 = *param_1 + param_2;

  UNLOCK();

  return iVar1;

}




