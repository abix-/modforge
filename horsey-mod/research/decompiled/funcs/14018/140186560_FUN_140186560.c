// Address: 0x140186560
// Ghidra name: FUN_140186560
// ============ 0x140186560 FUN_140186560 (size=110) ============


void FUN_140186560(void)



{

  longlong lVar1;

  

  FUN_140186540();

  lVar1 = (longlong)DAT_1403fcb5c;

  while (lVar1 != 0) {

    lVar1 = lVar1 + -1;

    FUN_140186110(**(undefined8 **)(DAT_1403fcb60 + lVar1 * 8));

  }

  FUN_1401841e0(DAT_1403fcb60);

  DAT_1403fcb60 = 0;

  FUN_140186c50();

  FUN_140179b30(DAT_1403fcb50);

  DAT_1403fcb50 = 0;

  return;

}




