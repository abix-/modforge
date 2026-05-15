// Address: 0x140218490
// Ghidra name: FUN_140218490
// ============ 0x140218490 FUN_140218490 (size=55) ============


bool FUN_140218490(undefined8 param_1)



{

  longlong lVar1;

  

  lVar1 = FUN_140142960("SDL_VIDEO_DRIVER");

  if (lVar1 != 0) {

    lVar1 = thunk_FUN_1402c9340(lVar1,param_1);

    return lVar1 != 0;

  }

  return false;

}




