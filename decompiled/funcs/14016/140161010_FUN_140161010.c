// Address: 0x140161010
// Ghidra name: FUN_140161010
// ============ 0x140161010 FUN_140161010 (size=47) ============


uint FUN_140161010(void)



{

  uint uVar1;

  longlong lVar2;

  uint uVar3;

  

  lVar2 = FUN_140142960("SDL_MOUSE_DEFAULT_SYSTEM_CURSOR");

  uVar3 = 0;

  if (lVar2 != 0) {

    uVar1 = thunk_FUN_1402d89dc(lVar2);

    if (uVar1 < 0x14) {

      uVar3 = uVar1;

    }

  }

  return uVar3;

}




