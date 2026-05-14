// Address: 0x14020f490
// Ghidra name: FUN_14020f490
// ============ 0x14020f490 FUN_14020f490 (size=111) ============


bool FUN_14020f490(void)



{

  DAT_1403fd320 = FUN_140179a30();

  if (DAT_1403fd320 != 0) {

    DAT_1403fd318 = FUN_140160230();

    if (DAT_1403fd318 != 0) {

      DAT_1403fd311 = 0;

      DAT_1403fd328 = FUN_140163260(FUN_14020f2e0,"SDL_joystick",0,FUN_1402cfa08,FUN_1402cfae8);

      return DAT_1403fd328 != 0;

    }

  }

  return false;

}




