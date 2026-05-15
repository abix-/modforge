// Address: 0x140169e80
// Ghidra name: FUN_140169e80
// ============ 0x140169e80 FUN_140169e80 (size=90) ============


undefined8 FUN_140169e80(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  

  lVar2 = FUN_140142960("SDL_DISPLAY_USABLE_BOUNDS");

  if (lVar2 != 0) {

    iVar1 = FUN_14012ef30(lVar2,"%d,%d,%d,%d",param_1,param_1 + 4,param_1 + 8,param_1 + 0xc);

    if (iVar1 == 4) {

      return 1;

    }

  }

  return 0;

}




