// Address: 0x1401835c0
// Ghidra name: FUN_1401835c0
// ============ 0x1401835c0 FUN_1401835c0 (size=162) ============


void FUN_1401835c0(void)



{

  longlong lVar1;

  

  lVar1 = (longlong)DAT_1403fcb08;

  DAT_1403fcb0c = 1;

  while (lVar1 != 0) {

    lVar1 = lVar1 + -1;

    FUN_140183700(*(undefined4 *)(DAT_1403fcb10 + lVar1 * 4));

  }

  FUN_1401841e0(DAT_1403fcb10);

  DAT_1403fcb10 = 0;

  FUN_1401aafa0(DAT_1403fcb18);

  DAT_1403fcb18 = 0;

  if ((DAT_1403fcaf0 != 0) && (*(char *)(DAT_1403fcaf0 + 0x14) != '\0')) {

    FUN_1401819c0();

    DAT_1403fcaf0 = 0;

  }

  FUN_140142b00("SDL_KEYCODE_OPTIONS",FUN_1401834f0,&DAT_1403fc6e0);

  DAT_1403fcb0c = 0;

  return;

}




