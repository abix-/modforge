// Address: 0x1400e6900
// Ghidra name: FUN_1400e6900
// ============ 0x1400e6900 FUN_1400e6900 (size=168) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400e6900(longlong param_1)



{

  char *pcVar1;

  char cVar2;

  longlong lVar3;

  

  lVar3 = 0;

  while( true ) {

    pcVar1 = *(char **)(param_1 + 0xb8);

    if (pcVar1 < *(char **)(param_1 + 0xc0)) {

      cVar2 = *pcVar1;

      *(char **)(param_1 + 0xb8) = pcVar1 + 1;

    }

    else if (*(int *)(param_1 + 0x30) == 0) {

      cVar2 = '\0';

    }

    else {

      FUN_1400ed820(param_1);

      cVar2 = **(char **)(param_1 + 0xb8);

      *(char **)(param_1 + 0xb8) = *(char **)(param_1 + 0xb8) + 1;

    }

    if (cVar2 != (&DAT_1403db0c8)[lVar3]) break;

    lVar3 = lVar3 + 1;

    if (7 < lVar3) {

      return 1;

    }

  }

  _DAT_1403f4c40 = "bad png sig";

  return 0;

}




