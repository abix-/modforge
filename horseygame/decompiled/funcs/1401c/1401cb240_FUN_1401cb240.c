// Address: 0x1401cb240
// Ghidra name: FUN_1401cb240
// ============ 0x1401cb240 FUN_1401cb240 (size=285) ============


void FUN_1401cb240(longlong param_1,undefined8 param_2,DWORD param_3)



{

  char cVar1;

  DWORD DVar2;

  uint uVar3;

  ulonglong uVar4;

  CHAR local_418 [1040];

  

  if ((param_3 == 0x887a0005) && (*(longlong **)(param_1 + 0x70) != (longlong *)0x0)) {

    param_3 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x128))();

  }

  DVar2 = FormatMessageA(0x1200,(LPCVOID)0x0,param_3,0,local_418,0x400,(va_list *)0x0);

  if (DVar2 == 0) {

    if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s! Error Code: (0x%08lX)",param_2,param_3);

    }

    FUN_14012e850("%s! Error Code: (0x%08lX)",param_2,param_3);

  }

  else {

    uVar4 = 0x400;

    if (DVar2 < 0x400) {

      uVar4 = (ulonglong)DVar2;

    }

    do {

      uVar3 = (int)uVar4 - 1;

      if (' ' < local_418[uVar3]) break;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 != 0);

    cVar1 = *(char *)(param_1 + 0x98);

    local_418[uVar4] = '\0';

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s! Error Code: %s (0x%08lX)",param_2,local_418,param_3);

    }

    FUN_14012e850("%s! Error Code: %s (0x%08lX)",param_2,local_418,param_3);

  }

  return;

}




