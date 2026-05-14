// Address: 0x140224900
// Ghidra name: FUN_140224900
// ============ 0x140224900 FUN_140224900 (size=412) ============


undefined8 FUN_140224900(longlong param_1,longlong param_2)



{

  HWND pHVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 uVar4;

  HIMC pHVar5;

  

  pHVar1 = *(HWND *)(*(longlong *)(param_2 + 0x188) + 8);

  if (*(char *)(param_1 + 0x140) == '\0') {

    lVar2 = FUN_140142960("SDL_IME_IMPLEMENTED_UI");

    if (lVar2 != 0) {

      lVar3 = thunk_FUN_1402c9340(lVar2,"composition");

      if (lVar3 != 0) {

        *(undefined1 *)(param_1 + 0x143) = 1;

      }

      lVar2 = thunk_FUN_1402c9340(lVar2,"candidates");

      if (lVar2 != 0) {

        *(undefined1 *)(param_1 + 0x144) = 1;

      }

    }

    *(HWND *)(param_1 + 0x148) = pHVar1;

    *(undefined1 *)(param_1 + 0x140) = 1;

    lVar2 = FUN_1401885b0("imm32.dll");

    *(longlong *)(param_1 + 0x250) = lVar2;

    if (lVar2 == 0) {

      *(undefined1 *)(param_1 + 0x142) = 0;

      FUN_14012e710();

      return 1;

    }

    uVar4 = FUN_140188550(lVar2,"ImmLockIMC");

    *(undefined8 *)(param_1 + 0x268) = uVar4;

    uVar4 = FUN_140188550(*(undefined8 *)(param_1 + 0x250),"ImmUnlockIMC");

    *(undefined8 *)(param_1 + 0x270) = uVar4;

    uVar4 = FUN_140188550(*(undefined8 *)(param_1 + 0x250),"ImmLockIMCC");

    *(undefined8 *)(param_1 + 0x278) = uVar4;

    uVar4 = FUN_140188550(*(undefined8 *)(param_1 + 0x250),"ImmUnlockIMCC");

    *(undefined8 *)(param_1 + 0x280) = uVar4;

    FUN_140224fe0(param_1,param_2);

    pHVar5 = ImmGetContext(pHVar1);

    *(HIMC *)(param_1 + 0x160) = pHVar5;

    ImmReleaseContext(pHVar1,pHVar5);

    if (*(longlong *)(param_1 + 0x160) == 0) {

      *(undefined1 *)(param_1 + 0x142) = 0;

    }

    else {

      *(undefined1 *)(param_1 + 0x142) = 1;

      FUN_140225110(param_1);

      FUN_140225040(param_1);

      FUN_140225110(param_1);

    }

    FUN_140223f00(param_1,pHVar1);

  }

  return 1;

}




