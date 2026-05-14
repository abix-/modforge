// Address: 0x14016e0b0
// Ghidra name: FUN_14016e0b0
// ============ 0x14016e0b0 FUN_14016e0b0 (size=127) ============


ulonglong FUN_14016e0b0(ulonglong param_1)



{

  char cVar1;

  ulonglong uVar2;

  undefined **ppuVar3;

  longlong lVar4;

  

  uVar2 = FUN_140174c40(param_1,"SDL.window.create.flags",0);

  ppuVar3 = &PTR_s_SDL_window_create_always_on_top_1403e26c0;

  lVar4 = 0x12;

  do {

    if (*(char *)(ppuVar3 + 2) == '\0') {

      cVar1 = FUN_1401749e0(param_1 & 0xffffffff,*ppuVar3,0);

      if (cVar1 != '\0') goto LAB_14016e109;

    }

    else {

      cVar1 = FUN_1401749e0(param_1 & 0xffffffff,*ppuVar3,1);

      if (cVar1 == '\0') {

LAB_14016e109:

        uVar2 = uVar2 | (ulonglong)ppuVar3[1];

      }

    }

    ppuVar3 = ppuVar3 + 3;

    lVar4 = lVar4 + -1;

    if (lVar4 == 0) {

      return uVar2;

    }

  } while( true );

}




