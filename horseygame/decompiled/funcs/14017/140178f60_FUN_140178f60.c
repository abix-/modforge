// Address: 0x140178f60
// Ghidra name: FUN_140178f60
// ============ 0x140178f60 FUN_140178f60 (size=249) ============


bool FUN_140178f60(char *param_1,char *param_2,undefined1 *param_3)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  char cVar4;

  char cVar5;

  char cVar6;

  char *pcVar7;

  char *pcVar8;

  char *pcVar9;

  

  pcVar9 = (char *)0x0;

  cVar2 = *param_1;

  pcVar7 = (char *)0x0;

  cVar4 = '\0';

  cVar5 = *param_2;

  do {

    pcVar8 = pcVar7;

    if (cVar5 == '\0') {

      while (cVar2 == '*') {

        pcVar7 = param_1 + 1;

        param_1 = param_1 + 1;

        cVar2 = *pcVar7;

      }

      *param_3 = cVar2 == '/';

      return cVar2 == '\0';

    }

    while( true ) {

      if (cVar2 == '*') {

        param_1 = param_1 + 1;

        pcVar7 = param_1;

        pcVar9 = param_2;

        cVar6 = cVar5;

        cVar4 = cVar5;

      }

      else {

        pcVar7 = pcVar8;

        if (cVar2 == cVar5) {

          pcVar1 = param_2 + 1;

          param_1 = param_1 + 1;

          param_2 = param_2 + 1;

          pcVar3 = (char *)0x0;

          if (cVar2 != '/') {

            pcVar3 = pcVar9;

          }

          pcVar7 = (char *)0x0;

          pcVar9 = pcVar3;

          cVar6 = *pcVar1;

          if (cVar2 != '/') {

            pcVar7 = pcVar8;

          }

        }

        else if ((cVar2 == '?') && (cVar5 != '/')) {

          pcVar8 = param_2 + 1;

          param_2 = param_2 + 1;

          param_1 = param_1 + 1;

          cVar6 = *pcVar8;

        }

        else {

          if ((pcVar8 == (char *)0x0) || (cVar4 == '/')) {

            *param_3 = 0;

            return false;

          }

          param_2 = pcVar9 + 1;

          cVar6 = *param_2;

          param_1 = pcVar8;

          pcVar9 = param_2;

          cVar4 = cVar5;

        }

      }

      cVar2 = *param_1;

      cVar5 = cVar6;

      if (cVar6 != '\\') break;

      cVar5 = '/';

      pcVar8 = pcVar7;

    }

  } while( true );

}




