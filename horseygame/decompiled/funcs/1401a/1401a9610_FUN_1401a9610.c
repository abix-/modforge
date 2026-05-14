// Address: 0x1401a9610
// Ghidra name: FUN_1401a9610
// ============ 0x1401a9610 FUN_1401a9610 (size=47) ============


int FUN_1401a9610(void)



{

  int iVar1;

  

  iVar1 = CoInitializeEx((LPVOID)0x0,2);

  if (iVar1 == -0x7ffefefa) {

    iVar1 = CoInitializeEx((LPVOID)0x0,0);

  }

  if (iVar1 == 1) {

    iVar1 = 0;

  }

  return iVar1;

}




