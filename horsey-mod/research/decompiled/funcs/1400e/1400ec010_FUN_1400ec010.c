// Address: 0x1400ec010
// Ghidra name: FUN_1400ec010
// ============ 0x1400ec010 FUN_1400ec010 (size=157) ============


undefined8 FUN_1400ec010(longlong param_1,longlong param_2)



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

    if (cVar2 != *(char *)(lVar3 + param_2)) break;

    lVar3 = lVar3 + 1;

    if (3 < lVar3) {

      return 1;

    }

  }

  return 0;

}




