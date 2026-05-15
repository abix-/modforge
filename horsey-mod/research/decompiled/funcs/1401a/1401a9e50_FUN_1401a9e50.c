// Address: 0x1401a9e50
// Ghidra name: FUN_1401a9e50
// ============ 0x1401a9e50 FUN_1401a9e50 (size=69) ============


int FUN_1401a9e50(void)



{

  int iVar1;

  code *pcVar2;

  

  pcVar2 = (code *)FUN_1401a9aa0("RoInitialize");

  if (pcVar2 != (code *)0x0) {

    iVar1 = (*pcVar2)(0);

    if (iVar1 == -0x7ffefefa) {

      iVar1 = (*pcVar2)(1);

    }

    if (iVar1 == 1) {

      iVar1 = 0;

    }

    return iVar1;

  }

  return -0x7fffbffe;

}




