// Address: 0x140140990
// Ghidra name: FUN_140140990
// ============ 0x140140990 FUN_140140990 (size=158) ============


char * FUN_140140990(undefined8 param_1)



{

  int iVar1;

  longlong lVar2;

  char *pcVar3;

  size_t sVar4;

  

  lVar2 = thunk_FUN_1402c9190(param_1,0x2c);

  if ((lVar2 != 0) && (lVar2 = thunk_FUN_1402c9190(lVar2 + 1,0x2c), lVar2 != 0)) {

    iVar1 = FUN_140190430((int)*(char *)(lVar2 + 1));

    while (iVar1 != 0) {

      pcVar3 = (char *)(lVar2 + 2);

      lVar2 = lVar2 + 1;

      iVar1 = FUN_140190430((int)*pcVar3);

    }

    pcVar3 = (char *)FUN_14012f0d0(lVar2 + 1);

    sVar4 = strlen(pcVar3);

    while ((sVar4 != 0 && (iVar1 = FUN_140190430((int)pcVar3[sVar4 - 1]), iVar1 != 0))) {

      sVar4 = sVar4 - 1;

    }

    pcVar3[sVar4] = '\0';

    return pcVar3;

  }

  return (char *)0x0;

}




