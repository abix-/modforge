// Address: 0x140228e80
// Ghidra name: FUN_140228e80
// ============ 0x140228e80 FUN_140228e80 (size=27) ============


int FUN_140228e80(longlong param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 8) + -1;

  *(int *)(param_1 + 8) = iVar1;

  if (iVar1 == 0) {

    FUN_1401841e0();

    iVar1 = 0;

  }

  return iVar1;

}




