// Address: 0x140206820
// Ghidra name: FUN_140206820
// ============ 0x140206820 FUN_140206820 (size=180) ============


undefined8 FUN_140206820(void)



{

  int iVar1;

  undefined8 uVar2;

  uint uVar3;

  undefined **ppuVar4;

  

  if (DAT_1403fd194 == '\0') {

    iVar1 = FUN_140193620();

    if (iVar1 < 0) {

      uVar2 = FUN_14012e850("Couldn\'t initialize hidapi");

      return uVar2;

    }

    uVar3 = 0;

    ppuVar4 = &PTR_PTR_1403e4d40;

    do {

      (**(code **)(*ppuVar4 + 0x10))(FUN_140208ce0);

      uVar3 = uVar3 + 1;

      ppuVar4 = ppuVar4 + 1;

    } while (uVar3 < 0x1a);

    FUN_1401427d0("SDL_JOYSTICK_HIDAPI_COMBINE_JOY_CONS",FUN_140208ce0,0);

    FUN_1401427d0("SDL_JOYSTICK_HIDAPI",FUN_140208ce0,0);

    DAT_1403fd190 = FUN_140192fe0();

    FUN_1402087d0();

    FUN_140208a20();

    DAT_1403fd194 = '\x01';

  }

  return 1;

}




