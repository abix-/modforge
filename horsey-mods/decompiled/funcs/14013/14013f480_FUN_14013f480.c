// Address: 0x14013f480
// Ghidra name: FUN_14013f480
// ============ 0x14013f480 FUN_14013f480 (size=152) ============


undefined8 FUN_14013f480(void)



{

  char cVar1;

  undefined *puVar2;

  undefined **ppuVar3;

  undefined1 local_408 [1024];

  

  _guard_check_icall();

  FUN_14013c7b0();

  if (PTR_s_xinput___a_b0_b_b1_back_b6_dpdow_1403e11a0 != (undefined *)0x0) {

    ppuVar3 = &PTR_s_xinput___a_b0_b_b1_back_b6_dpdow_1403e11a0;

    puVar2 = PTR_s_xinput___a_b0_b_b1_back_b6_dpdow_1403e11a0;

    do {

      FUN_14013f8f0(puVar2,0);

      puVar2 = ppuVar3[1];

      ppuVar3 = ppuVar3 + 1;

    } while (puVar2 != (undefined *)0x0);

  }

  cVar1 = FUN_14013e6e0(local_408,0x400);

  if (cVar1 != '\0') {

    FUN_14013c960(local_408);

  }

  FUN_14013f6a0();

  FUN_140159aa0(&PTR_s_SDL_GAMECONTROLLER_IGNORE_DEVICE_1403e1b60);

  FUN_140159aa0(&PTR_s_SDL_GAMECONTROLLER_IGNORE_DEVICE_1403e1bb0);

  FUN_14013c640();

  return 1;

}




