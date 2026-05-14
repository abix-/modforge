// Address: 0x1402e71c8
// Ghidra name: FUN_1402e71c8
// ============ 0x1402e71c8 FUN_1402e71c8 (size=445) ============


void FUN_1402e71c8(char *param_1,undefined8 *param_2,char *param_3,longlong *param_4,

                  longlong *param_5)



{

  bool bVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  bool bVar5;

  char *pcVar6;

  

  *param_5 = 0;

  *param_4 = 1;

  if (param_2 != (undefined8 *)0x0) {

    *param_2 = param_3;

    param_2 = param_2 + 1;

  }

  bVar1 = false;

  do {

    if (*param_1 == '\"') {

      bVar1 = !bVar1;

      cVar2 = '\"';

      pcVar6 = param_1 + 1;

    }

    else {

      *param_5 = *param_5 + 1;

      if (param_3 != (char *)0x0) {

        *param_3 = *param_1;

        param_3 = param_3 + 1;

      }

      cVar2 = *param_1;

      pcVar6 = param_1 + 1;

      iVar4 = FUN_1402f47b8((int)cVar2);

      if (iVar4 != 0) {

        *param_5 = *param_5 + 1;

        if (param_3 != (char *)0x0) {

          *param_3 = *pcVar6;

          param_3 = param_3 + 1;

        }

        pcVar6 = param_1 + 2;

      }

      if (cVar2 == '\0') {

        pcVar6 = pcVar6 + -1;

        goto LAB_1402e727a;

      }

    }

    param_1 = pcVar6;

  } while ((bVar1) || ((cVar2 != ' ' && (cVar2 != '\t'))));

  if (param_3 != (char *)0x0) {

    param_3[-1] = '\0';

  }

LAB_1402e727a:

  bVar1 = false;

  while (cVar2 = *pcVar6, cVar2 != '\0') {

    while ((cVar2 == ' ' || (cVar2 == '\t'))) {

      pcVar6 = pcVar6 + 1;

      cVar2 = *pcVar6;

    }

    if (cVar2 == '\0') break;

    if (param_2 != (undefined8 *)0x0) {

      *param_2 = param_3;

      param_2 = param_2 + 1;

    }

    *param_4 = *param_4 + 1;

    while( true ) {

      bVar5 = true;

      uVar3 = 0;

      while( true ) {

        if (*pcVar6 != '\\') break;

        pcVar6 = pcVar6 + 1;

        uVar3 = uVar3 + 1;

      }

      if (*pcVar6 == '\"') {

        if ((uVar3 & 1) == 0) {

          if ((bVar1) && (pcVar6[1] == '\"')) {

            pcVar6 = pcVar6 + 1;

          }

          else {

            bVar5 = false;

            bVar1 = !bVar1;

          }

        }

        uVar3 = uVar3 >> 1;

      }

      while (uVar3 != 0) {

        uVar3 = uVar3 - 1;

        if (param_3 != (char *)0x0) {

          *param_3 = '\\';

          param_3 = param_3 + 1;

        }

        *param_5 = *param_5 + 1;

      }

      cVar2 = *pcVar6;

      if ((cVar2 == '\0') || ((!bVar1 && ((cVar2 == ' ' || (cVar2 == '\t')))))) break;

      if (bVar5) {

        if (param_3 != (char *)0x0) {

          *param_3 = cVar2;

          param_3 = param_3 + 1;

        }

        iVar4 = FUN_1402f47b8((int)*pcVar6);

        if (iVar4 != 0) {

          *param_5 = *param_5 + 1;

          pcVar6 = pcVar6 + 1;

          if (param_3 != (char *)0x0) {

            *param_3 = *pcVar6;

            param_3 = param_3 + 1;

          }

        }

        *param_5 = *param_5 + 1;

      }

      pcVar6 = pcVar6 + 1;

    }

    if (param_3 != (char *)0x0) {

      *param_3 = '\0';

      param_3 = param_3 + 1;

    }

    *param_5 = *param_5 + 1;

  }

  if (param_2 != (undefined8 *)0x0) {

    *param_2 = 0;

  }

  *param_4 = *param_4 + 1;

  return;

}




