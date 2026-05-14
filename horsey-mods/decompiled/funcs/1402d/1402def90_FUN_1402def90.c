// Address: 0x1402def90
// Ghidra name: FUN_1402def90
// ============ 0x1402def90 FUN_1402def90 (size=430) ============


int FUN_1402def90(char *param_1,longlong *param_2,longlong param_3)



{

  longlong lVar1;

  longlong *plVar2;

  char *pcVar3;

  byte bVar4;

  char cVar5;

  longlong lVar6;

  longlong lVar7;

  longlong local_res18 [2];

  longlong *local_28;

  char *local_20;

  longlong *local_18;

  

  local_18 = local_res18;

  lVar7 = 0;

  lVar6 = lVar7;

  do {

    local_28 = param_2;

    local_20 = param_1;

    if ((*param_1 != (&DAT_14038ab78)[lVar6]) && (*param_1 != (&DAT_14038ab7c)[lVar6])) {

      local_res18[0] = param_3;

      FUN_1402dfef4(&local_28);

      return 7;

    }

    lVar1 = param_2[2];

    param_2[2] = lVar1 + 1U;

    if ((param_2[1] == 0) || (lVar1 + 1U <= (ulonglong)param_2[1])) {

      lVar1 = *param_2;

      pcVar3 = *(char **)(lVar1 + 0x10);

      if (pcVar3 == *(char **)(lVar1 + 8)) goto LAB_1402defee;

      cVar5 = *pcVar3;

      *(char **)(lVar1 + 0x10) = pcVar3 + 1;

    }

    else {

LAB_1402defee:

      cVar5 = '\0';

    }

    lVar6 = lVar6 + 1;

    *param_1 = cVar5;

  } while (lVar6 != 3);

  lVar6 = param_2[2];

  param_2[2] = lVar6 - 1U;

  if (((param_2[1] == 0) || (lVar6 - 1U <= (ulonglong)param_2[1])) && (1 < (byte)(cVar5 + 1U))) {

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

      cVar5 = *pcVar3;

      *(char **)(lVar6 + 0x10) = pcVar3 + 1;

      goto LAB_1402df091;

    }

  }

  cVar5 = '\0';

LAB_1402df091:

  *param_1 = cVar5;

  do {

    if ((cVar5 != "INITY"[lVar7]) && (cVar5 != "inity"[lVar7])) {

      bVar4 = FUN_1402dfef4(&local_28);

      return (bVar4 ^ 1) * 4 + 3;

    }

    lVar6 = param_2[2];

    param_2[2] = lVar6 + 1U;

    cVar5 = '\0';

    if ((param_2[1] == 0) || (lVar6 + 1U <= (ulonglong)param_2[1])) {

      lVar6 = *param_2;

      pcVar3 = *(char **)(lVar6 + 0x10);

      if (pcVar3 != *(char **)(lVar6 + 8)) {

        cVar5 = *pcVar3;

        *(char **)(lVar6 + 0x10) = pcVar3 + 1;

      }

    }

    lVar7 = lVar7 + 1;

    *param_1 = cVar5;

  } while (lVar7 != 5);

  lVar6 = param_2[2];

  param_2[2] = lVar6 - 1U;

  if (((param_2[1] == 0) || (lVar6 - 1U <= (ulonglong)param_2[1])) && (1 < (byte)(cVar5 + 1U))) {

    param_2 = (longlong *)*param_2;

    if (param_2[2] != *param_2) {

      param_2[2] = param_2[2] + -1;

    }

  }

  return 3;

}




