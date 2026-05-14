// Address: 0x1401989b0
// Ghidra name: FUN_1401989b0
// ============ 0x1401989b0 FUN_1401989b0 (size=66) ============


longlong FUN_1401989b0(longlong param_1)



{

  longlong lVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","entry");

    return 0;

  }

  lVar1 = *(longlong *)(param_1 + 0x1028);

  if (lVar1 == 0) {

    FUN_14012e850("Cannot create submenu for entry not created with SDL_TRAYENTRY_SUBMENU");

    lVar1 = 0;

  }

  return lVar1;

}




