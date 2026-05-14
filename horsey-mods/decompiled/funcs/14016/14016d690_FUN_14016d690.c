// Address: 0x14016d690
// Ghidra name: FUN_14016d690
// ============ 0x14016d690 FUN_14016d690 (size=46) ============


void FUN_14016d690(void)



{

  undefined4 uVar1;

  longlong lVar2;

  

  lVar2 = FUN_14016dd00();

  if (lVar2 == 0) {

    return;

  }

  if (*(int *)(lVar2 + 0x78) == 0) {

    uVar1 = FUN_1401746e0();

    *(undefined4 *)(lVar2 + 0x78) = uVar1;

  }

  return;

}




