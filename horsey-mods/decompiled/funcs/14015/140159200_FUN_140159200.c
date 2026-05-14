// Address: 0x140159200
// Ghidra name: FUN_140159200
// ============ 0x140159200 FUN_140159200 (size=77) ============


bool FUN_140159200(void)



{

  int iVar1;

  int iVar2;

  undefined **ppuVar3;

  uint uVar4;

  

  iVar2 = 0;

  FUN_140159d30();

  uVar4 = 0;

  ppuVar3 = &PTR_PTR_1403e2380;

  do {

    iVar1 = (**(code **)(*ppuVar3 + 8))();

    uVar4 = uVar4 + 1;

    ppuVar3 = ppuVar3 + 1;

    iVar2 = iVar2 + iVar1;

  } while (uVar4 < 6);

  FUN_14015bb10();

  return 0 < iVar2;

}




