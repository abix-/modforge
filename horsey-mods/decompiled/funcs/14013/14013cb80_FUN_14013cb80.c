// Address: 0x14013cb80
// Ghidra name: FUN_14013cb80
// ============ 0x14013cb80 FUN_14013cb80 (size=181) ============


longlong FUN_14013cb80(char *param_1)



{

  char *_Str;

  size_t sVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  

  sVar1 = strlen(param_1);

  lVar2 = FUN_1401841f0(sVar1 + 2);

  if (lVar2 != 0) {

    FUN_14012f1a0(lVar2,param_1,sVar1 + 2);

    lVar3 = thunk_FUN_1402c9340(lVar2,&DAT_140331adc);

    lVar4 = thunk_FUN_1402c9340(lVar2,&DAT_140331ae0);

    lVar5 = thunk_FUN_1402c9340(lVar2,"hint:SDL_GAMECONTROLLER_USE_GAMECUBE_LABELS");

    if (lVar3 != 0) {

      *(undefined1 *)(lVar3 + 1) = 0x78;

    }

    if (lVar4 != 0) {

      *(undefined1 *)(lVar4 + 1) = 0x62;

    }

    if (lVar5 != 0) {

      _Str = (char *)(lVar5 + 5);

      sVar1 = strlen(_Str);

      FUN_1402f8e20(lVar5 + 6,_Str,sVar1 + 1);

      *_Str = '!';

    }

  }

  return lVar2;

}




