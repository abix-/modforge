// Address: 0x1401efcd0
// Ghidra name: FUN_1401efcd0
// ============ 0x1401efcd0 FUN_1401efcd0 (size=143) ============


undefined1 FUN_1401efcd0(uint param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)



{

  if (0x16762004 < param_1) {

    if ((((param_1 != 0x3132564e) && (param_1 != 0x3231564e)) && (param_1 != 0x32315659)) &&

       (param_1 != 0x56555949)) {

      return 0;

    }

LAB_1401efd48:

    *param_2 = 0x1909;

    *param_3 = 0x1909;

    *param_4 = 0x1401;

    return 1;

  }

  if (param_1 != 0x16762004) {

    if (param_1 == 0x13000801) goto LAB_1401efd48;

    if ((param_1 == 0x16161804) || (param_1 == 0x16362004)) {

      *param_2 = 0x8058;

      *param_3 = 0x80e1;

      *param_4 = 0x1401;

      return 1;

    }

    if (param_1 != 0x16561804) {

      return 0;

    }

  }

  *param_2 = 0x8058;

  *param_3 = 0x1908;

  *param_4 = 0x1401;

  return 1;

}




