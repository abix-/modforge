// Address: 0x1400f40d0
// Ghidra name: FUN_1400f40d0
// ============ 0x1400f40d0 FUN_1400f40d0 (size=101) ============


bool FUN_1400f40d0(char *param_1)



{

  char cVar1;

  

  cVar1 = *param_1;

  if (cVar1 == '1') {

    if (param_1[1] != '\0') {

      return false;

    }

    if (param_1[2] != '\0') {

      return false;

    }

    cVar1 = param_1[3];

  }

  else {

    if (cVar1 != 't') {

      if (cVar1 == 'O') {

        if (param_1[1] != 'T') {

          return false;

        }

        if (param_1[2] == 'T') {

          if (param_1[3] == 'O') {

            return true;

          }

          return false;

        }

        return false;

      }

      if (cVar1 != '\0') {

        return false;

      }

      if (param_1[1] != '\x01') {

        return false;

      }

      if (param_1[2] != '\0') {

        return false;

      }

      return param_1[3] == '\0';

    }

    if (param_1[1] != 'y') {

      return false;

    }

    if (param_1[2] != 'p') {

      return false;

    }

    cVar1 = param_1[3] + -0x31;

  }

  if (cVar1 != '\0') {

    return false;

  }

  return true;

}




