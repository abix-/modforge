// Address: 0x140215160
// Ghidra name: FUN_140215160
// ============ 0x140215160 FUN_140215160 (size=61) ============


bool FUN_140215160(longlong param_1)



{

  char cVar1;

  longlong lVar2;

  

  lVar2 = FUN_1401841a0(1,0x48);

  *(longlong *)(param_1 + 200) = lVar2;

  if (lVar2 != 0) {

    cVar1 = FUN_1402148d0(param_1);

    return cVar1 != '\0';

  }

  return false;

}




