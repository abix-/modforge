// Address: 0x140142410
// Ghidra name: FUN_140142410
// ============ 0x140142410 FUN_140142410 (size=284) ============


char * FUN_140142410(undefined4 param_1)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  char *pcVar4;

  char *local_res10;

  

  pcVar4 = (char *)0x0;

  _guard_check_icall();

  lVar3 = FUN_140140710(param_1,1);

  if (lVar3 != 0) {

    iVar2 = strcmp(*(char **)(lVar3 + 0x10),"*");

    if (iVar2 == 0) {

      pcVar4 = (char *)FUN_140158780(param_1);

    }

    else {

      pcVar4 = *(char **)(lVar3 + 0x10);

    }

  }

  if (DAT_1403fbf00 == 0) {

    pcVar4 = (char *)FUN_1401aa890(pcVar4);

    return pcVar4;

  }

  local_res10 = (char *)0x0;

  cVar1 = FUN_1401aaff0(DAT_1403fbf00,param_1,&local_res10);

  if (pcVar4 == (char *)0x0) {

    if (cVar1 == '\0') {

      FUN_14012e850("Gamepad %u not found",param_1);

      return (char *)0x0;

    }

    if (local_res10 == (char *)0x0) {

      FUN_14012e770();

      return (char *)0x0;

    }

  }

  else {

    if ((local_res10 != (char *)0x0) && (iVar2 = strcmp(local_res10,pcVar4), iVar2 == 0)) {

      return local_res10;

    }

    local_res10 = (char *)FUN_14012f0d0(pcVar4);

    FUN_1401ab100(DAT_1403fbf00,param_1,local_res10,1);

  }

  return local_res10;

}




