// Address: 0x140197d40
// Ghidra name: FUN_140197d40
// ============ 0x140197d40 FUN_140197d40 (size=159) ============


char * FUN_140197d40(char *param_1,char *param_2,longlong *param_3)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  

  if ((param_2 != (char *)0x0) && (param_3 != (longlong *)0x0)) {

    if (param_1 == (char *)0x0) {

      param_1 = (char *)*param_3;

      if (param_1 == (char *)0x0) {

        return (char *)0x0;

      }

    }

    else {

      *param_3 = (longlong)param_1;

    }

    cVar1 = *param_2;

    pcVar3 = param_2;

    while ((cVar1 != '\0' && (*param_1 != '\0'))) {

      if (*param_1 == *pcVar3) {

        param_1 = param_1 + 1;

        pcVar3 = param_2;

      }

      else {

        pcVar3 = pcVar3 + 1;

      }

      cVar1 = *pcVar3;

    }

    cVar1 = *param_1;

    *param_3 = (longlong)param_1;

    if (cVar1 != '\0') {

      pcVar3 = param_1;

      if (*param_1 == '\0') {

        return param_1;

      }

      do {

        cVar1 = *param_2;

        if (cVar1 != '\0') {

          pcVar2 = param_2;

          do {

            pcVar2 = pcVar2 + 1;

            if (*pcVar3 == cVar1) {

              *(undefined1 *)*param_3 = 0;

              *param_3 = *param_3 + 1;

              return param_1;

            }

            cVar1 = *pcVar2;

          } while (cVar1 != '\0');

        }

        pcVar3 = (char *)(*param_3 + 1);

        *param_3 = (longlong)pcVar3;

      } while (*pcVar3 != '\0');

      return param_1;

    }

  }

  return (char *)0x0;

}




