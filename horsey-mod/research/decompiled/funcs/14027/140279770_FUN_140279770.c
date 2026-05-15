// Address: 0x140279770
// Ghidra name: FUN_140279770
// ============ 0x140279770 FUN_140279770 (size=402) ============


void FUN_140279770(undefined8 param_1,undefined8 param_2,longlong param_3,byte *param_4,int param_5,

                  char param_6,char param_7)



{

  char cVar1;

  char *pcVar2;

  longlong lVar3;

  

  lVar3 = (longlong)param_5;

  if (0 < lVar3) {

    pcVar2 = (char *)(param_3 + 2);

    do {

      if (pcVar2[-2] != -1) {

        cVar1 = param_6;

        if ((*param_4 & 1) == 0) {

          cVar1 = param_7;

        }

        FUN_14015ad00(param_1,param_2,pcVar2[-2],cVar1 != '\0');

      }

      if (pcVar2[-1] != -1) {

        cVar1 = param_6;

        if ((*param_4 & 2) == 0) {

          cVar1 = param_7;

        }

        FUN_14015ad00(param_1,param_2,pcVar2[-1],cVar1 != '\0');

      }

      if (*pcVar2 != -1) {

        cVar1 = param_6;

        if ((*param_4 & 4) == 0) {

          cVar1 = param_7;

        }

        FUN_14015ad00(param_1,param_2,*pcVar2,cVar1 != '\0');

      }

      if (pcVar2[1] != -1) {

        cVar1 = param_6;

        if ((*param_4 & 8) == 0) {

          cVar1 = param_7;

        }

        FUN_14015ad00(param_1,param_2,pcVar2[1],cVar1 != '\0');

      }

      if (pcVar2[2] != -1) {

        cVar1 = param_6;

        if ((*param_4 & 0x10) == 0) {

          cVar1 = param_7;

        }

        FUN_14015ad00(param_1,param_2,pcVar2[2],cVar1 != '\0');

      }

      if (pcVar2[3] != -1) {

        cVar1 = param_6;

        if ((*param_4 & 0x20) == 0) {

          cVar1 = param_7;

        }

        FUN_14015ad00(param_1,param_2,pcVar2[3],cVar1 != '\0');

      }

      if (pcVar2[4] != -1) {

        cVar1 = param_6;

        if ((*param_4 & 0x40) == 0) {

          cVar1 = param_7;

        }

        FUN_14015ad00(param_1,param_2,pcVar2[4],cVar1 != '\0');

      }

      if (pcVar2[5] != -1) {

        cVar1 = param_6;

        if (-1 < (char)*param_4) {

          cVar1 = param_7;

        }

        FUN_14015ad00(param_1,param_2,pcVar2[5],cVar1 != '\0');

      }

      pcVar2 = pcVar2 + 8;

      param_4 = param_4 + 1;

      lVar3 = lVar3 + -1;

    } while (lVar3 != 0);

  }

  return;

}




