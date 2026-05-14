// Address: 0x140149070
// Ghidra name: thunk_FUN_140149460
// ============ 0x140149070 thunk_FUN_140149460 (size=5) ============


undefined8 thunk_FUN_140149460(void)



{

  char cVar1;

  

  cVar1 = FUN_140163c40(&DAT_1403fbf50);

  if (cVar1 == '\0') {

    return 1;

  }

  DAT_1403fbf78 = FUN_140179a30();

  if ((DAT_1403fbf78 != 0) && (DAT_1403fc008 = FUN_14017cda0(0), DAT_1403fc008 != 0)) {

    FUN_140139010(&DAT_1403fc020,1);

    DAT_1403fbf68 =

         FUN_140163260(FUN_140149810,"SDLTimer",&DAT_1403fbf50,FUN_1402cfa08,FUN_1402cfae8);

    if (DAT_1403fbf68 != 0) {

      FUN_140163ab0(&DAT_1403fbf50,1);

      return 1;

    }

  }

  FUN_140163ab0(&DAT_1403fbf50,1);

  FUN_140149560();

  return 0;

}




