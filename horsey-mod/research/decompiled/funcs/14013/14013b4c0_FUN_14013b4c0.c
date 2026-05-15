// Address: 0x14013b4c0
// Ghidra name: FUN_14013b4c0
// ============ 0x14013b4c0 FUN_14013b4c0 (size=123) ============


void FUN_14013b4c0(undefined4 param_1)



{

  char cVar1;

  undefined4 local_88 [2];

  undefined8 local_80;

  

  cVar1 = FUN_140139420();

  if (cVar1 != '\0') {

    local_80 = 0;

    local_88[0] = param_1;

    switch(param_1) {

    case 0x101:

    case 0x102:

    case 0x103:

    case 0x104:

    case 0x105:

    case 0x106:

      if (0 < DAT_1403fbed0) {

        FUN_14013ad50(local_88);

      }

      FUN_140139220(local_88);

      return;

    default:

      FUN_14013b140(local_88);

    }

  }

  return;

}




