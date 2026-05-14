// Address: 0x14017a400
// Ghidra name: FUN_14017a400
// ============ 0x14017a400 FUN_14017a400 (size=163) ============


undefined * FUN_14017a400(int param_1,int param_2)



{

  if (param_2 == 1) {

    if ((param_1 == 6) || (param_1 == 7)) {

      return &DAT_140336220;

    }

    if (param_1 == 9) {

      return &DAT_1403362e8;

    }

    if (param_1 == 0xb) {

      return &DAT_140336310;

    }

    if (param_1 == 0xc) {

      return &DAT_140336360;

    }

  }

  else if ((param_2 == 6) || (param_2 == 7)) {

    if (param_1 == 1) {

      return &DAT_140336270;

    }

    if (param_1 == 9) {

      return &DAT_1403362c0;

    }

  }

  else if (param_2 == 9) {

    if (param_1 == 1) {

      return &DAT_140336298;

    }

    if ((param_1 == 6) || (param_1 == 7)) {

      return &DAT_140336248;

    }

    if (param_1 == 0xb) {

      return &DAT_140336338;

    }

    if (param_1 == 0xc) {

      return &DAT_140336388;

    }

  }

  return (undefined *)0x0;

}




