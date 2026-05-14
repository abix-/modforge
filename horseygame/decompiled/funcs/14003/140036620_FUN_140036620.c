// Address: 0x140036620
// Ghidra name: FUN_140036620
// ============ 0x140036620 FUN_140036620 (size=188) ============


void FUN_140036620(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  FUN_140075b80(param_1 + 0x250);

  FUN_140075b80(param_1 + 0x698);

  FUN_140075b80(param_1 + 0x69c);

  FUN_140075b80(param_1 + 0x6a0);

  FUN_140075b80(param_1 + 0x6a4);

  FUN_140075e80(param_1 + 0x6b1);

  FUN_140075b80(param_1 + 0x690);

  if (6 < DAT_1403fb0e0) {

    FUN_140075e80(param_1 + 0x6b0);

  }

  param_1 = param_1 + 0x2b8;

  lVar1 = 0xf0;

  do {

    lVar2 = 4;

    do {

      FUN_140075e80(param_1);

      param_1 = param_1 + 1;

      lVar2 = lVar2 + -1;

    } while (lVar2 != 0);

    lVar1 = lVar1 + -1;

  } while (lVar1 != 0);

  return;

}




