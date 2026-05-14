// Address: 0x140142630
// Ghidra name: FUN_140142630
// ============ 0x140142630 FUN_140142630 (size=131) ============


longlong FUN_140142630(char *param_1)



{

  int iVar1;

  longlong lVar2;

  

  lVar2 = FUN_140179690();

  if (((lVar2 == 0) && (param_1 != (char *)0x0)) && (*param_1 != '\0')) {

    iVar1 = strcmp(param_1,"SDL_VIDEO_DRIVER");

    if (iVar1 == 0) {

      lVar2 = FUN_140179690("SDL_VIDEODRIVER");

      return lVar2;

    }

    iVar1 = strcmp(param_1,"SDL_AUDIO_DRIVER");

    if (iVar1 == 0) {

      lVar2 = FUN_140179690("SDL_AUDIODRIVER");

      return lVar2;

    }

  }

  return lVar2;

}




