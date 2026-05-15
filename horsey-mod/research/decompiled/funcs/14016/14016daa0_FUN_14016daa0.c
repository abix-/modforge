// Address: 0x14016daa0
// Ghidra name: FUN_14016daa0
// ============ 0x14016daa0 FUN_14016daa0 (size=37) ============


int FUN_14016daa0(void)



{

  int iVar1;

  longlong lVar2;

  

  lVar2 = FUN_14016dd00();

  if (lVar2 == 0) {

    return 0;

  }

  iVar1 = 1;

  if (*(int *)(lVar2 + 0x50) != 0) {

    iVar1 = *(int *)(lVar2 + 0x50);

  }

  return iVar1;

}




