// Address: 0x14014e570
// Ghidra name: FUN_14014e570
// ============ 0x14014e570 FUN_14014e570 (size=71) ============


undefined8 FUN_14014e570(void)



{

  int iVar1;

  longlong lVar2;

  

  lVar2 = FUN_140142960("SDL_RENDER_LINE_METHOD");

  if (lVar2 != 0) {

    iVar1 = thunk_FUN_1402d89dc(lVar2);

    if (iVar1 != 1) {

      if (iVar1 == 2) {

        return 1;

      }

      if (iVar1 == 3) {

        return 2;

      }

    }

  }

  return 0;

}




