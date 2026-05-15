// Address: 0x140149560
// Ghidra name: FUN_140149560
// ============ 0x140149560 FUN_140149560 (size=303) ============


void FUN_140149560(void)



{

  undefined8 uVar1;

  char cVar2;

  

  cVar2 = FUN_140163cb0(&DAT_1403fbf50);

  if (cVar2 == '\0') {

    return;

  }

  FUN_140139010(&DAT_1403fc020,0);

  if (DAT_1403fbf68 != 0) {

    FUN_14017cea0(DAT_1403fc008);

    FUN_140163d80(DAT_1403fbf68,0);

    DAT_1403fbf68 = 0;

  }

  uVar1 = 0;

  if (DAT_1403fc008 != 0) {

    FUN_14017ce80();

    DAT_1403fc008 = 0;

    uVar1 = DAT_1403fc008;

  }

  while (DAT_1403fc008 = uVar1, DAT_1403fc028 != 0) {

    DAT_1403fc028 = *(longlong *)(DAT_1403fc028 + 0x38);

    FUN_1401841e0();

    uVar1 = DAT_1403fc008;

  }

  DAT_1403fc028 = 0;

  while (DAT_1403fc018 != 0) {

    DAT_1403fc018 = *(longlong *)(DAT_1403fc018 + 0x38);

    FUN_1401841e0();

  }

  DAT_1403fc018 = 0;

  while (DAT_1403fbf70 != 0) {

    DAT_1403fbf70 = *(longlong *)(DAT_1403fbf70 + 0x10);

    FUN_1401841e0();

  }

  if (DAT_1403fbf78 != 0) {

    FUN_140179b30();

    DAT_1403fbf78 = 0;

  }

  FUN_140163ab0(&DAT_1403fbf50,0);

  return;

}




