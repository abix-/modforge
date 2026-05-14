// Address: 0x14016d200
// Ghidra name: FUN_14016d200
// ============ 0x14016d200 FUN_14016d200 (size=37) ============


int FUN_14016d200(void)



{

  int iVar1;

  longlong lVar2;

  

  lVar2 = FUN_14016dd00();

  if (lVar2 == 0) {

    return 0;

  }

  iVar1 = 1;

  if (*(int *)(lVar2 + 0x54) != 0) {

    iVar1 = *(int *)(lVar2 + 0x54);

  }

  return iVar1;

}




