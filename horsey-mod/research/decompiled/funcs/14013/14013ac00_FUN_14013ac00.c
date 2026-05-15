// Address: 0x14013ac00
// Ghidra name: FUN_14013ac00
// ============ 0x14013ac00 FUN_14013ac00 (size=147) ============


undefined1 FUN_14013ac00(void)



{

  char cVar1;

  

  FUN_1401427d0("SDL_AUTO_UPDATE_JOYSTICKS",FUN_1401391e0,0);

  FUN_1401427d0("SDL_AUTO_UPDATE_SENSORS",FUN_140139200,0);

  FUN_1401427d0("SDL_EVENT_LOGGING",FUN_140139460,0);

  FUN_1401427d0("SDL_POLL_SENTINEL",FUN_14013b010,0);

  FUN_14013aca0();

  cVar1 = FUN_14013b810();

  if (cVar1 == '\0') {

    FUN_140142b00("SDL_EVENT_LOGGING",FUN_140139460,0);

    return 0;

  }

  FUN_1401ce050();

  return 1;

}




