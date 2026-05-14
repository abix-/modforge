// Address: 0x14019cd20
// Ghidra name: FUN_14019cd20
// ============ 0x14019cd20 FUN_14019cd20 (size=163) ============


undefined8 FUN_14019cd20(longlong param_1)



{

  char *pcVar1;

  undefined8 uVar2;

  char cVar3;

  longlong lVar4;

  

  lVar4 = 0;

  while( true ) {

    pcVar1 = *(char **)(param_1 + 0xc0);

    if (pcVar1 < *(char **)(param_1 + 200)) {

      cVar3 = *pcVar1;

      *(char **)(param_1 + 0xc0) = pcVar1 + 1;

    }

    else if (*(int *)(param_1 + 0x30) == 0) {

      cVar3 = '\0';

    }

    else {

      FUN_1401a4400(param_1);

      cVar3 = **(char **)(param_1 + 0xc0);

      *(char **)(param_1 + 0xc0) = *(char **)(param_1 + 0xc0) + 1;

    }

    if (cVar3 != (&DAT_14033b608)[lVar4]) break;

    lVar4 = lVar4 + 1;

    if (7 < lVar4) {

      return 1;

    }

  }

  uVar2 = FUN_14019f050("Not a PNG");

  return uVar2;

}




