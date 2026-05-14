// Address: 0x1400325b0
// Ghidra name: FUN_1400325b0
// ============ 0x1400325b0 FUN_1400325b0 (size=86) ============


void FUN_1400325b0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  

  lVar4 = 2;

  do {

    lVar3 = 0;

    lVar1 = 0x2b8;

    do {

      if ((*(char *)(param_2 + lVar3) != -1) &&

         (lVar2 = *(char *)(param_2 + lVar3) + lVar1, *(char *)(lVar2 + param_1) == '\0')) {

        *(undefined1 *)(lVar2 + param_1) = 1;

      }

      lVar3 = lVar3 + 1;

      lVar1 = lVar1 + 4;

    } while (lVar1 < 0x678);

    param_2 = param_2 + 0xf0;

    lVar4 = lVar4 + -1;

  } while (lVar4 != 0);

  return;

}




