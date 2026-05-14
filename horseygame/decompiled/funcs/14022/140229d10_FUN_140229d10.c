// Address: 0x140229d10
// Ghidra name: FUN_140229d10
// ============ 0x140229d10 FUN_140229d10 (size=146) ============


undefined8 FUN_140229d10(void)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  lVar1 = FUN_140142960("SDL_WINDOWS_ERASE_BACKGROUND_MODE");

  if (lVar1 != 0) {

    lVar2 = thunk_FUN_1402c9340(lVar1,"never");

    if (lVar2 != 0) {

      return 0;

    }

    lVar2 = thunk_FUN_1402c9340(lVar1,"initial");

    if (lVar2 == 0) {

      lVar2 = thunk_FUN_1402c9340(lVar1,"always");

      if (lVar2 != 0) {

        return 2;

      }

      uVar3 = FUN_140142a20(lVar1,1);

      if ((uint)uVar3 < 3) {

        return uVar3;

      }

      FUN_14012e310(

                   "GetEraseBackgroundModeHint: invalid value for SDL_HINT_WINDOWS_ERASE_BACKGROUND_MODE. Fallback to default"

                   );

    }

  }

  return 1;

}




