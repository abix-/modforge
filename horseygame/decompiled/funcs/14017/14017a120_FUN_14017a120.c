// Address: 0x14017a120
// Ghidra name: FUN_14017a120
// ============ 0x14017a120 FUN_14017a120 (size=90) ============


void FUN_14017a120(int *param_1,undefined1 *param_2,undefined1 *param_3)



{

  int iVar1;

  char *pcVar2;

  char *pcVar3;

  longlong lVar4;

  longlong lVar5;

  

  iVar1 = *param_1;

  if (0 < iVar1) {

    lVar4 = 0;

    pcVar2 = (char *)(*(longlong *)(param_1 + 2) + 3);

    pcVar3 = pcVar2;

    lVar5 = lVar4;

    do {

      if (*pcVar3 != -1) {

        do {

          if (*pcVar2 != '\0') {

            *param_2 = 0;

            *param_3 = 1;

            return;

          }

          lVar4 = lVar4 + 1;

          pcVar2 = pcVar2 + 4;

        } while (lVar4 < iVar1);

        *param_2 = 1;

        *param_3 = 0;

        return;

      }

      lVar5 = lVar5 + 1;

      pcVar3 = pcVar3 + 4;

    } while (lVar5 < iVar1);

  }

  *param_2 = 1;

  *param_3 = 1;

  return;

}




