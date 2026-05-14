// Address: 0x14017e880
// Ghidra name: FUN_14017e880
// ============ 0x14017e880 FUN_14017e880 (size=374) ============


void FUN_14017e880(uint param_1)



{

  char cVar1;

  

  if ((param_1 >> 0x10 & 1) != 0) {

    cVar1 = FUN_14017eb70(0x10000);

    if (cVar1 != '\0') {

      FUN_140132210();

      FUN_14017e880(0x4000);

    }

    FUN_14017e170(0x10000);

  }

  if ((param_1 >> 0xf & 1) != 0) {

    cVar1 = FUN_14017eb70(0x8000);

    if (cVar1 != '\0') {

      FUN_1401775b0();

    }

    FUN_14017e170(0x8000);

  }

  if ((param_1 >> 0xd & 1) != 0) {

    cVar1 = FUN_14017eb70(0x2000);

    if (cVar1 != '\0') {

      FUN_140141200();

      FUN_14017e880(0x200);

    }

    FUN_14017e170(0x2000);

  }

  if ((param_1 >> 9 & 1) != 0) {

    cVar1 = FUN_14017eb70(0x200);

    if (cVar1 != '\0') {

      FUN_14015a670();

      FUN_14017e880(0x4000);

    }

    FUN_14017e170(0x200);

  }

  if ((param_1 >> 0xc & 1) != 0) {

    cVar1 = FUN_14017eb70(0x1000);

    if (cVar1 != '\0') {

      FUN_1401766b0();

    }

    FUN_14017e170(0x1000);

  }

  if ((param_1 & 0x10) != 0) {

    cVar1 = FUN_14017eb70(0x10);

    if (cVar1 != '\0') {

      FUN_14015f4a0();

      FUN_14017e880(0x4000);

    }

    FUN_14017e170(0x10);

  }

  if ((param_1 & 0x20) != 0) {

    cVar1 = FUN_14017eb70(0x20);

    if (cVar1 != '\0') {

      FUN_14014fa50();

      FUN_140173d30();

      DAT_1403fc638 = 0;

      FUN_14017e880(0x4000);

    }

    FUN_14017e170(0x20);

  }

  if ((param_1 >> 0xe & 1) != 0) {

    cVar1 = FUN_14017eb70(0x4000);

    if (cVar1 != '\0') {

      FUN_14013b1a0();

      DAT_1403fc630 = 0;

    }

    FUN_14017e170(0x4000);

    return;

  }

  return;

}




