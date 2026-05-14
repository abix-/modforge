// Address: 0x1400a5c90
// Ghidra name: FUN_1400a5c90
// ============ 0x1400a5c90 FUN_1400a5c90 (size=126) ============


void FUN_1400a5c90(char *param_1,longlong param_2,longlong param_3)



{

  char *pcVar1;

  char *pcVar2;

  longlong lVar3;

  

  param_2 = param_2 - (longlong)param_1;

  param_3 = param_3 - (longlong)param_1;

  lVar3 = 0xf0;

  pcVar1 = param_1 + 0xf0;

  do {

    pcVar2 = param_1;

    if (*pcVar1 <= pcVar1[-0xf0]) {

      pcVar2 = param_1 + 0xf0;

    }

    pcVar1[param_2 + -0xf0] = *pcVar2;

    pcVar2 = param_1 + 0xf0;

    if (*pcVar1 <= pcVar1[-0xf0]) {

      pcVar2 = param_1;

    }

    param_1 = param_1 + 1;

    (pcVar1 + 1)[param_3 + -0xf1] = *pcVar2;

    lVar3 = lVar3 + -1;

    pcVar1 = pcVar1 + 1;

  } while (lVar3 != 0);

  return;

}




