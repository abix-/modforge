// Address: 0x140167e20
// Ghidra name: FUN_140167e20
// ============ 0x140167e20 FUN_140167e20 (size=60) ============


undefined1 FUN_140167e20(int param_1)



{

  bool bVar1;

  

  if (param_1 < 0x8121) {

    if (param_1 == 0x8120) {

      return 1;

    }

    if (param_1 == 8) {

      return 1;

    }

    if (param_1 == 0x8008) {

      return 1;

    }

    if (param_1 == 0x8010) {

      return 1;

    }

    bVar1 = param_1 == 0x8020;

  }

  else {

    if (param_1 == 0x9010) {

      return 1;

    }

    if (param_1 == 0x9020) {

      return 1;

    }

    bVar1 = param_1 == 0x9120;

  }

  if (bVar1) {

    return 1;

  }

  return 0;

}




