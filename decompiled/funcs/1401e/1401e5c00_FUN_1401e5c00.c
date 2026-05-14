// Address: 0x1401e5c00
// Ghidra name: FUN_1401e5c00
// ============ 0x1401e5c00 FUN_1401e5c00 (size=232) ============


char FUN_1401e5c00(uint param_1,int param_2)



{

  char cVar1;

  

  if (param_1 < 0x16772005) {

    if (param_1 == 0x16772004) {

      return '\x18';

    }

    if (0x16161804 < param_1) {

      if (param_1 == 0x16362004) {

        cVar1 = 'W';

        if (param_2 == 0x12000500) {

          cVar1 = '[';

        }

        return cVar1;

      }

      if (param_1 != 0x16762004) {

        return '\0';

      }

      return (param_2 == 0x12000500) + '\x1c';

    }

    if (param_1 == 0x16161804) {

      cVar1 = 'X';

      if (param_2 == 0x12000500) {

        cVar1 = ']';

      }

      return cVar1;

    }

    if (param_1 != 0x13000801) {

      if (param_1 == 0x15151002) {

        return 'U';

      }

      cVar1 = '\0';

      if (param_1 == 0x15331002) {

        cVar1 = 'V';

      }

      return cVar1;

    }

  }

  else {

    if (param_1 < 0x3231564f) {

      if (param_1 != 0x3231564e) {

        if (param_1 == 0x1a204008) {

          return '\n';

        }

        if (param_1 == 0x30313050) {

          return 'h';

        }

        if (param_1 != 0x3132564e) {

          return '\0';

        }

      }

      return 'g';

    }

    if (param_1 != 0x32315659) {

      cVar1 = '=';

      if (param_1 != 0x56555949) {

        cVar1 = '\0';

      }

      return cVar1;

    }

  }

  return '=';

}




