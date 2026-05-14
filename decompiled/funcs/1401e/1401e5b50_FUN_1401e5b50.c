// Address: 0x1401e5b50
// Ghidra name: FUN_1401e5b50
// ============ 0x1401e5b50 FUN_1401e5b50 (size=164) ============


char FUN_1401e5b50(uint param_1,int param_2)



{

  char cVar1;

  

  if (0x30313050 < param_1) {

    if ((((param_1 != 0x3132564e) && (param_1 != 0x3231564e)) && (param_1 != 0x32315659)) &&

       (param_1 != 0x56555949)) {

      return '\0';

    }

    return '=';

  }

  if (param_1 == 0x30313050) {

    return '8';

  }

  if (param_1 != 0x16161804) {

    if (param_1 == 0x16362004) {

      cVar1 = 'W';

      if (param_2 == 0x12000500) {

        cVar1 = '[';

      }

      return cVar1;

    }

    if (param_1 != 0x16762004) {

      if (param_1 != 0x16772004) {

        cVar1 = '\0';

        if (param_1 == 0x1a204008) {

          cVar1 = '\n';

        }

        return cVar1;

      }

      return '\x18';

    }

    return (param_2 == 0x12000500) + '\x1c';

  }

  cVar1 = 'X';

  if (param_2 == 0x12000500) {

    cVar1 = ']';

  }

  return cVar1;

}




