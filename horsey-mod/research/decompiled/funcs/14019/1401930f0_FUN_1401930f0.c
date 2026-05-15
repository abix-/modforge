// Address: 0x1401930f0
// Ghidra name: FUN_1401930f0
// ============ 0x1401930f0 FUN_1401930f0 (size=144) ============


undefined4 FUN_1401930f0(void)



{

  undefined4 uVar1;

  

  if ((DAT_1403fcd08 != 0) && (DAT_1403fcd08 = DAT_1403fcd08 + -1, DAT_1403fcd08 < 1)) {

    DAT_1403fcd08 = 0;

    FUN_1401923f0();

    uVar1 = FUN_140192990();

    FUN_140142b00("SDL_HIDAPI_ENUMERATE_ONLY_CONTROLLERS",FUN_140192660,0);

    FUN_140142b00("SDL_HIDAPI_IGNORE_DEVICES",FUN_140192550,0);

    if (DAT_1403fcd10 != 0) {

      FUN_1401841e0();

      DAT_1403fcd10 = 0;

    }

    return uVar1;

  }

  return 0;

}




