// Address: 0x1401997c0
// Ghidra name: FUN_1401997c0
// ============ 0x1401997c0 FUN_1401997c0 (size=193) ============


undefined8 FUN_1401997c0(char *param_1)



{

  char cVar1;

  size_t sVar2;

  char *pcVar3;

  char *pcVar4;

  undefined8 uVar5;

  int iVar6;

  

  iVar6 = 0;

  cVar1 = *param_1;

  pcVar3 = param_1;

  while (cVar1 != '\0') {

    pcVar3 = pcVar3 + 1;

    iVar6 = iVar6 + (cVar1 == '&') + 1;

    cVar1 = *pcVar3;

  }

  sVar2 = strlen(param_1);

  pcVar3 = (char *)FUN_1401841f0((longlong)iVar6 + sVar2 + 1);

  if (pcVar3 != (char *)0x0) {

    cVar1 = *param_1;

    pcVar4 = pcVar3;

    while (cVar1 != '\0') {

      if (cVar1 == '&') {

        *pcVar4 = '&';

        pcVar4 = pcVar4 + 1;

      }

      cVar1 = *param_1;

      param_1 = param_1 + 1;

      *pcVar4 = cVar1;

      pcVar4 = pcVar4 + 1;

      cVar1 = *param_1;

    }

    *pcVar4 = '\0';

    sVar2 = strlen(pcVar3);

    uVar5 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,pcVar3,sVar2 + 1);

    FUN_1401841e0(pcVar3);

    return uVar5;

  }

  return 0;

}




