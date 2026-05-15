// Address: 0x1402df140
// Ghidra name: FUN_1402df140
// ============ 0x1402df140 FUN_1402df140 (size=610) ============


int FUN_1402df140(char *param_1,longlong *param_2,longlong param_3)



{

  longlong lVar1;

  longlong *plVar2;

  char *pcVar3;

  char cVar4;

  char cVar5;

  longlong lVar6;

  longlong local_res18 [2];

  longlong *local_28;

  char *local_20;

  longlong *local_18;

  

  local_18 = local_res18;

  lVar6 = 0;

  do {

    local_28 = param_2;

    local_20 = param_1;

    if ((*param_1 != (&DAT_14038ab90)[lVar6]) && (*param_1 != (&DAT_14038ab94)[lVar6])) {

      local_res18[0] = param_3;

      FUN_1402dfef4(&local_28);

      return 7;

    }

    lVar1 = param_2[2];

    param_2[2] = lVar1 + 1U;

    if ((param_2[1] == 0) || (lVar1 + 1U <= (ulonglong)param_2[1])) {

      lVar1 = *param_2;

      pcVar3 = *(char **)(lVar1 + 0x10);

      if (pcVar3 == *(char **)(lVar1 + 8)) goto LAB_1402df1a1;

      cVar4 = *pcVar3;

      *(char **)(lVar1 + 0x10) = pcVar3 + 1;

    }

    else {

LAB_1402df1a1:

      cVar4 = '\0';

    }

    lVar6 = lVar6 + 1;

    *param_1 = cVar4;

  } while (lVar6 != 3);

  lVar6 = param_2[2];

  param_2[2] = lVar6 - 1U;

  if (((param_2[1] == 0) || (lVar6 - 1U <= (ulonglong)param_2[1])) && (1 < (byte)(cVar4 + 1U))) {

    plVar2 = (longlong *)*param_2;

    if (plVar2[2] != *plVar2) {

      plVar2[2] = plVar2[2] + -1;

    }

  }

  local_res18[0] = param_2[2];

  param_2[2] = local_res18[0] + 1U;

  if ((param_2[1] == 0) || (local_res18[0] + 1U <= (ulonglong)param_2[1])) {

    lVar6 = *param_2;

    pcVar3 = *(char **)(lVar6 + 0x10);

    if (pcVar3 != *(char **)(lVar6 + 8)) {

      cVar4 = *pcVar3;

      *(char **)(lVar6 + 0x10) = pcVar3 + 1;

      *param_1 = cVar4;

      if (cVar4 != '(') goto LAB_1402df24b;

      lVar6 = param_2[2];

      param_2[2] = lVar6 + 1U;

      if ((param_2[1] == 0) || (lVar6 + 1U <= (ulonglong)param_2[1])) {

        lVar6 = *param_2;

        pcVar3 = *(char **)(lVar6 + 0x10);

        if (pcVar3 == *(char **)(lVar6 + 8)) goto LAB_1402df27c;

        cVar4 = *pcVar3;

        *(char **)(lVar6 + 0x10) = pcVar3 + 1;

      }

      else {

LAB_1402df27c:

        cVar4 = '\0';

      }

      *param_1 = cVar4;

      cVar4 = FUN_1402df420(param_1,param_2);

      if (cVar4 != '\0') {

        lVar6 = param_2[2];

        cVar4 = *param_1;

        param_2[2] = lVar6 - 1U;

        if (((param_2[1] == 0) || (lVar6 - 1U <= (ulonglong)param_2[1])) && (1 < (byte)(cVar4 + 1U))

           ) {

          param_2 = (longlong *)*param_2;

          if (param_2[2] != *param_2) {

            param_2[2] = param_2[2] + -1;

          }

        }

        return 5;

      }

      cVar5 = FUN_1402df3a4(param_1,param_2);

      cVar4 = *param_1;

      if (cVar5 != '\0') {

        lVar6 = param_2[2];

        param_2[2] = lVar6 - 1U;

        if (((param_2[1] == 0) || (lVar6 - 1U <= (ulonglong)param_2[1])) && (1 < (byte)(cVar4 + 1U))

           ) {

          param_2 = (longlong *)*param_2;

          if (param_2[2] != *param_2) {

            param_2[2] = param_2[2] + -1;

          }

        }

        return 6;

      }

      while( true ) {

        if (cVar4 == ')') {

          return 4;

        }

        if ((cVar4 == '\0') ||

           ((((9 < (byte)(cVar4 - 0x30U) && (0x19 < (byte)(cVar4 + 0x9fU))) &&

             (0x19 < (byte)(cVar4 + 0xbfU))) && (cVar4 != '_')))) break;

        lVar6 = param_2[2];

        param_2[2] = lVar6 + 1U;

        if ((param_2[1] == 0) || (lVar6 + 1U <= (ulonglong)param_2[1])) {

          lVar6 = *param_2;

          pcVar3 = *(char **)(lVar6 + 0x10);

          if (pcVar3 == *(char **)(lVar6 + 8)) goto LAB_1402df371;

          cVar4 = *pcVar3;

          *(char **)(lVar6 + 0x10) = pcVar3 + 1;

        }

        else {

LAB_1402df371:

          cVar4 = '\0';

        }

        *param_1 = cVar4;

      }

      goto LAB_1402df24b;

    }

  }

  *param_1 = '\0';

LAB_1402df24b:

  cVar4 = FUN_1402dfef4(&local_28);

  return (-(uint)(cVar4 != '\0') & 0xfffffffd) + 7;

}




