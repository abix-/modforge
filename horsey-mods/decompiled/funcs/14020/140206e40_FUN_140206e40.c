// Address: 0x140206e40
// Ghidra name: FUN_140206e40
// ============ 0x140206e40 FUN_140206e40 (size=275) ============


void FUN_140206e40(void)



{

  longlong lVar1;

  uint uVar2;

  longlong lVar3;

  int iVar4;

  longlong lVar5;

  undefined **ppuVar6;

  

  _guard_check_icall();

  DAT_1403fd195 = 1;

  FUN_140284440();

  while (DAT_1403fd198 != 0) {

    lVar1 = *(longlong *)(DAT_1403fd198 + 0xa0);

    lVar3 = DAT_1403fd198;

    if ((lVar1 != 0) && (iVar4 = 0, lVar3 = lVar1, 0 < *(int *)(lVar1 + 0xa8))) {

      lVar5 = 0;

      do {

        FUN_140207680(*(undefined8 *)(*(longlong *)(lVar1 + 0xb0) + lVar5));

        iVar4 = iVar4 + 1;

        lVar5 = lVar5 + 8;

      } while (iVar4 < *(int *)(lVar1 + 0xa8));

    }

    FUN_140207680(lVar3);

  }

  uVar2 = 0;

  ppuVar6 = &PTR_PTR_1403e4d40;

  DAT_1403fd198 = 0;

  do {

    (**(code **)(*ppuVar6 + 0x18))(FUN_140208ce0);

    uVar2 = uVar2 + 1;

    ppuVar6 = ppuVar6 + 1;

  } while (uVar2 < 0x1a);

  FUN_140142b00("SDL_JOYSTICK_HIDAPI_COMBINE_JOY_CONS",FUN_140208ce0,0);

  FUN_140142b00("SDL_JOYSTICK_HIDAPI",FUN_140208ce0,0);

  FUN_1401930f0();

  DAT_1403fd190 = 0;

  DAT_1403fd195 = 0;

  DAT_1403fd194 = 0;

  return;

}




