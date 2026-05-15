// Address: 0x14027b910
// Ghidra name: FUN_14027b910
// ============ 0x14027b910 FUN_14027b910 (size=101) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_14027b910(char *param_1)



{

  char cVar1;

  longlong lVar2;

  int iVar3;

  double dVar4;

  

  iVar3 = 0x14;

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    lVar2 = thunk_FUN_1402c9190(param_1,0x2e);

    if (lVar2 != 0) {

      dVar4 = (double)thunk_FUN_1402de5ec();

      return (int)(dVar4 * _DAT_14037fd40);

    }

    cVar1 = FUN_1401429e0(param_1,1);

    iVar3 = 0x14;

    if (cVar1 == '\0') {

      iVar3 = 0;

    }

  }

  return iVar3;

}




