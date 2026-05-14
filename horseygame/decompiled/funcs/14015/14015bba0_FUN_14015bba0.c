// Address: 0x14015bba0
// Ghidra name: FUN_14015bba0
// ============ 0x14015bba0 FUN_14015bba0 (size=257) ============


char * FUN_14015bba0(undefined4 param_1)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  char *pcVar4;

  undefined4 local_res10 [2];

  char *local_res18;

  longlong local_res20;

  

  pcVar4 = (char *)0x0;

  lVar3 = FUN_140158f10();

  if (lVar3 == 0) {

    cVar1 = FUN_140157a10(param_1,&local_res20,local_res10);

    if (cVar1 != '\0') {

      pcVar4 = (char *)(**(code **)(local_res20 + 0x20))(local_res10[0]);

    }

  }

  else {

    pcVar4 = *(char **)(lVar3 + 8);

  }

  if (DAT_1403fc080 == 0) {

    pcVar4 = (char *)FUN_1401aa890(pcVar4);

    return pcVar4;

  }

  local_res18 = (char *)0x0;

  cVar1 = FUN_1401aaff0(DAT_1403fc080,param_1,&local_res18);

  if (pcVar4 == (char *)0x0) {

    if (cVar1 == '\0') {

      FUN_14012e850("Joystick %u not found",param_1);

      return (char *)0x0;

    }

    if (local_res18 == (char *)0x0) {

      FUN_14012e770();

      return (char *)0x0;

    }

  }

  else {

    if ((local_res18 != (char *)0x0) && (iVar2 = strcmp(local_res18,pcVar4), iVar2 == 0)) {

      return local_res18;

    }

    local_res18 = (char *)FUN_14012f0d0(pcVar4);

    FUN_1401ab100(DAT_1403fc080,param_1,local_res18,1);

  }

  return local_res18;

}




