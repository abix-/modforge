// Address: 0x140214800
// Ghidra name: FUN_140214800
// ============ 0x140214800 FUN_140214800 (size=202) ============


undefined1 FUN_140214800(undefined8 *param_1)



{

  char cVar1;

  

  cVar1 = FUN_140214a40();

  if (cVar1 == '\0') {

    return 0;

  }

  *(undefined1 *)((longlong)param_1 + 0x71) = 1;

  param_1[4] = FUN_1402155b0;

  *param_1 = FUN_140214f80;

  param_1[7] = FUN_1402155b0;

  param_1[2] = FUN_140215530;

  param_1[3] = FUN_1402154d0;

  param_1[1] = FUN_140215160;

  param_1[5] = FUN_1402151a0;

  param_1[6] = FUN_1402150d0;

  param_1[8] = FUN_1402153b0;

  param_1[9] = FUN_140214ff0;

  param_1[10] = FUN_140214f00;

  param_1[0xc] = FUN_140214f60;

  param_1[0xd] = &LAB_140214f50;

  param_1[0xb] = FUN_1402150b0;

  DAT_1403fdac1 = FUN_140142940("SDL_AUDIO_INCLUDE_MONITORS",0);

  return 1;

}




