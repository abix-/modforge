// Address: 0x14013cc40
// Ghidra name: FUN_14013cc40
// ============ 0x14013cc40 FUN_14013cc40 (size=260) ============


longlong FUN_14013cc40(char *param_1)



{

  char *_Str;

  size_t sVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  

  sVar1 = strlen(param_1);

  lVar2 = FUN_1401841f0(sVar1 + 2);

  if (lVar2 != 0) {

    FUN_14012f1a0(lVar2,param_1,sVar1 + 2);

    lVar3 = thunk_FUN_1402c9340(lVar2,&DAT_140331b14);

    lVar4 = thunk_FUN_1402c9340(lVar2,&DAT_140331adc);

    lVar5 = thunk_FUN_1402c9340(lVar2,&DAT_140331ae0);

    lVar6 = thunk_FUN_1402c9340(lVar2,&DAT_140331b18);

    lVar7 = thunk_FUN_1402c9340(lVar2,"hint:SDL_GAMECONTROLLER_USE_BUTTON_LABELS");

    if (lVar3 != 0) {

      *(undefined1 *)(lVar3 + 1) = 0x62;

    }

    if (lVar4 != 0) {

      *(undefined1 *)(lVar4 + 1) = 0x61;

    }

    if (lVar5 != 0) {

      *(undefined1 *)(lVar5 + 1) = 0x79;

    }

    if (lVar6 != 0) {

      *(undefined1 *)(lVar6 + 1) = 0x78;

    }

    if (lVar7 != 0) {

      _Str = (char *)(lVar7 + 5);

      sVar1 = strlen(_Str);

      FUN_1402f8e20(lVar7 + 6,_Str,sVar1 + 1);

      *_Str = '!';

    }

  }

  return lVar2;

}




