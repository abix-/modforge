// Address: 0x14012e360
// Ghidra name: FUN_14012e360
// ============ 0x14012e360 FUN_14012e360 (size=131) ============


void FUN_14012e360(void)



{

  char cVar1;

  

  cVar1 = FUN_140163cb0(&DAT_1403fb4f8);

  if (cVar1 != '\0') {

    FUN_140142b00("SDL_LOGGING",&LAB_14012e350,0);

    FUN_14012da50();

    FUN_14012d980();

    if (DAT_1403fb510 != 0) {

      FUN_140179b30();

      DAT_1403fb510 = 0;

    }

    if (DAT_1403fb518 != 0) {

      FUN_140179b30();

      DAT_1403fb518 = 0;

    }

    FUN_140163ab0(&DAT_1403fb4f8,0);

    return;

  }

  return;

}




