// Address: 0x140193620
// Ghidra name: FUN_140193620
// ============ 0x140193620 FUN_140193620 (size=145) ============


undefined8 FUN_140193620(void)



{

  int iVar1;

  

  if (0 < DAT_1403fcd08) {

    DAT_1403fcd08 = DAT_1403fcd08 + 1;

    return 0;

  }

  FUN_1401427d0("SDL_HIDAPI_ENUMERATE_ONLY_CONTROLLERS",FUN_140192660,0);

  FUN_1401427d0("SDL_HIDAPI_IGNORE_DEVICES",FUN_140192550,0);

  DAT_1403e3a5c = FUN_140142940("SDL_HIDAPI_LIBUSB_WHITELIST",1);

  DAT_1403e3a5d = FUN_140142940("SDL_HIDAPI_LIBUSB_GAMECUBE",1);

  iVar1 = FUN_140192a10();

  if (iVar1 != 0) {

    return 0xffffffff;

  }

  DAT_1403fcd08 = DAT_1403fcd08 + 1;

  return 0;

}




