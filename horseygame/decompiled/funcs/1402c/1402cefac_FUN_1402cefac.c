// Address: 0x1402cefac
// Ghidra name: FUN_1402cefac
// ============ 0x1402cefac FUN_1402cefac (size=85) ============


longlong FUN_1402cefac(short *param_1,short *param_2,char param_3)



{

  longlong lVar1;

  longlong lVar2;

  

  if (1 < (byte)(param_3 - 1U)) {

    lVar2 = 0;

    for (; param_1 != param_2; param_1 = (short *)((longlong)param_1 + 1)) {

      lVar1 = lVar2 + 1;

      if ((char)*param_1 != '\n') {

        lVar1 = lVar2;

      }

      lVar2 = lVar1;

    }

    return lVar2;

  }

  lVar2 = 0;

  for (; param_1 != param_2; param_1 = param_1 + 1) {

    lVar1 = lVar2 + 1;

    if (*param_1 != 10) {

      lVar1 = lVar2;

    }

    lVar2 = lVar1;

  }

  return lVar2 * 2;

}




