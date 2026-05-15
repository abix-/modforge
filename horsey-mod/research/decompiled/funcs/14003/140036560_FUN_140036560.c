// Address: 0x140036560
// Ghidra name: FUN_140036560
// ============ 0x140036560 FUN_140036560 (size=174) ============


void FUN_140036560(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  FUN_140075670(*(undefined4 *)(param_1 + 0x250));

  FUN_140075670(*(undefined4 *)(param_1 + 0x698));

  FUN_140075670(*(undefined4 *)(param_1 + 0x69c));

  FUN_140075670(*(undefined4 *)(param_1 + 0x6a0));

  FUN_140075670(*(undefined4 *)(param_1 + 0x6a4));

  FUN_140075750(*(undefined1 *)(param_1 + 0x6b1));

  FUN_140075670(*(undefined4 *)(param_1 + 0x690));

  FUN_140075750(*(undefined1 *)(param_1 + 0x6b0));

  param_1 = param_1 + 0x2b8;

  lVar2 = 0xf0;

  do {

    lVar1 = 0;

    do {

      FUN_140075750(*(undefined1 *)(param_1 + lVar1));

      lVar1 = lVar1 + 1;

    } while (lVar1 < 4);

    param_1 = param_1 + 4;

    lVar2 = lVar2 + -1;

  } while (lVar2 != 0);

  return;

}




