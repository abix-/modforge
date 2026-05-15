// Address: 0x140289330
// Ghidra name: FUN_140289330
// ============ 0x140289330 FUN_140289330 (size=75) ============


void FUN_140289330(void)



{

  DAT_1403fde78 = DAT_1403fde78 + -1;

  if (DAT_1403fde78 == 0) {

    if (DAT_1403fde70 != (longlong *)0x0) {

      (**(code **)(*DAT_1403fde70 + 0x10))();

      DAT_1403fde70 = (longlong *)0x0;

    }

    if (DAT_1403fde68 != 0) {

      FUN_140188670();

      DAT_1403fde68 = 0;

    }

  }

  return;

}




