// Address: 0x14029fe00
// Ghidra name: FUN_14029fe00
// ============ 0x14029fe00 FUN_14029fe00 (size=310) ============


char FUN_14029fe00(uint param_1)



{

  uint uVar1;

  

  if ((param_1 == 0) || ((param_1 & 0xf0000000) == 0x10000000)) {

    uVar1 = param_1 & 0xff;

LAB_14029fe3c:

    if (4 < uVar1) {

      return '\x04';

    }

    if (param_1 != 0) {

      if ((((param_1 & 0xf0000000) == 0x10000000) && ((param_1 & 0xf000000) == 0x6000000)) &&

         ((param_1 & 0xf0000) == 0x70000)) {

        return '\x03';

      }

      goto LAB_14029fe7b;

    }

LAB_14029fe98:

    if (((param_1 & 0xf000000) == 0x4000000) ||

       (((param_1 & 0xf000000) + 0xfb000000 & 0xfeffffff) == 0)) {

      uVar1 = param_1 & 0xf00000;

      if (uVar1 == 0x300000) {

        return '\x02';

      }

      if (uVar1 == 0x400000) {

        return '\x02';

      }

      if (uVar1 == 0x700000) {

        return '\x02';

      }

      if (uVar1 == 0x800000) {

        return '\x02';

      }

    }

    if (param_1 == 0) goto LAB_14029fee7;

  }

  else {

    if ((((param_1 == 0x32595559) || (param_1 == 0x59565955)) || (param_1 == 0x55595659)) ||

       (param_1 == 0x30313050)) {

      uVar1 = 2;

      goto LAB_14029fe3c;

    }

LAB_14029fe7b:

    if (param_1 == 0x13000801) {

      return '\0';

    }

    if ((param_1 == 0) || ((param_1 & 0xf0000000) == 0x10000000)) goto LAB_14029fe98;

  }

  if ((param_1 & 0xf0000000) != 0x10000000) {

    return '\x01';

  }

LAB_14029fee7:

  if (((param_1 & 0xf000000) != 0x7000000) &&

     (((param_1 & 0xf000000) + 0xf8000000 & 0xfcffffff) != 0)) {

    return '\x01';

  }

  param_1 = param_1 & 0xf00000;

  if ((param_1 != 0x300000) && ((param_1 - 0x200000 & 0xffbfffff) != 0)) {

    return (param_1 == 0x500000) + '\x01';

  }

  return '\x02';

}




