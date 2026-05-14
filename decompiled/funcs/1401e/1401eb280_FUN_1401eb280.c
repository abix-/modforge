// Address: 0x1401eb280
// Ghidra name: FUN_1401eb280
// ============ 0x1401eb280 FUN_1401eb280 (size=174) ============


char FUN_1401eb280(uint param_1,int param_2)



{

  char cVar1;

  

  if (param_1 < 0x1a204009) {

    if (param_1 == 0x1a204008) {

      return '\n';

    }

    if (param_1 != 0x13000801) {

      if (param_1 == 0x16161804) {

        cVar1 = 'X';

        if (param_2 == 0x12000500) {

          cVar1 = ']';

        }

        return cVar1;

      }

      if (param_1 != 0x16362004) {

        cVar1 = '\0';

        if (param_1 != 0x16762004) {

          if (param_1 == 0x16772004) {

            cVar1 = '\x18';

          }

          return cVar1;

        }

        return (param_2 == 0x12000500) + '\x1c';

      }

      cVar1 = 'W';

      if (param_2 == 0x12000500) {

        cVar1 = '[';

      }

      return cVar1;

    }

  }

  else {

    if (param_1 == 0x30313050) {

      return '8';

    }

    if ((((param_1 != 0x3132564e) && (param_1 != 0x3231564e)) && (param_1 != 0x32315659)) &&

       (param_1 != 0x56555949)) {

      return '\0';

    }

  }

  return '=';

}




