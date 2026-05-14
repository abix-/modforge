// Address: 0x140289f10
// Ghidra name: FUN_140289f10
// ============ 0x140289f10 FUN_140289f10 (size=176) ============


undefined8 FUN_140289f10(undefined8 param_1,undefined8 param_2)



{

  char cVar1;

  undefined4 uVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined1 local_88 [128];

  

  uVar2 = FUN_14016ea50(param_2);

  lVar3 = FUN_140174d30(uVar2,"SDL.internal.window.surface",0);

  if (lVar3 == 0) {

    uVar4 = FUN_14012e850("Couldn\'t find dummy surface for window");

    return uVar4;

  }

  cVar1 = FUN_140142940("SDL_VIDEO_DUMMY_SAVE_FRAMES",0);

  if (cVar1 != '\0') {

    DAT_1403fde98 = DAT_1403fde98 + 1;

    uVar2 = FUN_14016e2d0(param_2);

    FUN_14012ef10(local_88,0x80,"SDL_window%u-%8.8d.bmp",uVar2,DAT_1403fde98);

    FUN_140188300(lVar3,local_88);

  }

  return 1;

}




