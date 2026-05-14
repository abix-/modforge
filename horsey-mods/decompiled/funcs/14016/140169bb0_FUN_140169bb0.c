// Address: 0x140169bb0
// Ghidra name: FUN_140169bb0
// ============ 0x140169bb0 FUN_140169bb0 (size=103) ============


bool FUN_140169bb0(void)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  

  lVar3 = FUN_140142960("SDL_ENABLE_SCREEN_KEYBOARD");

  if (lVar3 == 0) {

    lVar3 = FUN_140142960("SteamDeck");

    if (lVar3 != 0) goto LAB_140169bde;

  }

  else {

LAB_140169bde:

    iVar2 = FUN_14012ef60(lVar3,&DAT_1403350d4);

    if (iVar2 != 0) goto LAB_140169c02;

  }

  cVar1 = FUN_140183470();

  if (cVar1 == '\0') {

    return true;

  }

LAB_140169c02:

  cVar1 = FUN_1401429e0(lVar3,0);

  return cVar1 != '\0';

}




