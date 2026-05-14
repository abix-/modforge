// Address: 0x1402f80c0
// Ghidra name: FUN_1402f80c0
// ============ 0x1402f80c0 FUN_1402f80c0 (size=289) ============


undefined4 FUN_1402f80c0(char *param_1,longlong param_2,longlong param_3,longlong param_4)



{

  char cVar1;

  undefined4 *puVar2;

  longlong lVar3;

  char *pcVar4;

  longlong lVar5;

  longlong lVar6;

  

  if (param_4 == 0) {

    if (param_1 == (char *)0x0) {

      if (param_2 == 0) {

        return 0;

      }

      goto LAB_1402f8119;

    }

  }

  else if (param_1 == (char *)0x0) goto LAB_1402f8119;

  if (param_2 != 0) {

    if (param_4 == 0) {

      *param_1 = '\0';

      return 0;

    }

    if (param_3 != 0) {

      pcVar4 = param_1;

      lVar5 = param_2;

      lVar3 = param_4;

      if (param_4 == -1) {

        do {

          cVar1 = pcVar4[param_3 - (longlong)param_1];

          *pcVar4 = cVar1;

          if (cVar1 == '\0') {

            return 0;

          }

          lVar5 = lVar5 + -1;

          pcVar4 = pcVar4 + 1;

        } while (lVar5 != 0);

        lVar5 = 0;

      }

      else {

        do {

          lVar6 = lVar3;

          cVar1 = pcVar4[param_3 - (longlong)param_1];

          *pcVar4 = cVar1;

          pcVar4 = pcVar4 + 1;

          if (cVar1 == '\0') {

            return 0;

          }

          lVar5 = lVar5 + -1;

        } while ((lVar5 != 0) && (lVar3 = lVar6 + -1, lVar6 + -1 != 0));

        lVar3 = lVar6 + -1;

        if (lVar5 == 0) {

          lVar3 = lVar6;

        }

        if (lVar3 == 0) {

          *pcVar4 = '\0';

        }

      }

      if (lVar5 != 0) {

        return 0;

      }

      if (param_4 == -1) {

        param_1[param_2 + -1] = '\0';

        return 0x50;

      }

      *param_1 = '\0';

      puVar2 = (undefined4 *)FUN_1402e68b0();

      *puVar2 = 0x22;

      FUN_1402cd454();

      return 0x22;

    }

    *param_1 = '\0';

  }

LAB_1402f8119:

  puVar2 = (undefined4 *)FUN_1402e68b0();

  *puVar2 = 0x16;

  FUN_1402cd454();

  return 0x16;

}




