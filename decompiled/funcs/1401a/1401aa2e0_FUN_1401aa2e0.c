// Address: 0x1401aa2e0
// Ghidra name: FUN_1401aa2e0
// ============ 0x1401aa2e0 FUN_1401aa2e0 (size=183) ============


int FUN_1401aa2e0(char *param_1,char *param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  

  iVar4 = 0;

  iVar2 = strncmp(param_1,"HORI ",5);

  if ((iVar2 == 0) && (iVar2 = strncmp(param_2,"HORl ",5), iVar2 == 0)) {

    return 5;

  }

  if (*param_1 != '\0') {

    lVar5 = (longlong)param_2 - (longlong)param_1;

    while (param_1[lVar5] != '\0') {

      cVar1 = *param_1;

      iVar2 = FUN_140190610(param_1[lVar5]);

      iVar3 = FUN_140190610(cVar1);

      param_1 = param_1 + 1;

      if (iVar3 != iVar2) {

        return iVar4;

      }

      iVar4 = iVar4 + 1;

      if (*param_1 == '\0') {

        return iVar4;

      }

    }

  }

  return iVar4;

}




