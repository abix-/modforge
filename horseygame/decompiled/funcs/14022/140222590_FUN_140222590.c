// Address: 0x140222590
// Ghidra name: FUN_140222590
// ============ 0x140222590 FUN_140222590 (size=156) ============


ulonglong FUN_140222590(char *param_1,char *param_2)



{

  ulonglong uVar1;

  char *pcVar2;

  size_t sVar3;

  char *pcVar4;

  

  uVar1 = thunk_FUN_1402c9190(param_1,0x20);

  if (((uVar1 == 0) && (*param_1 != '\0')) && (param_2 != (char *)0x0)) {

    pcVar2 = (char *)thunk_FUN_1402c9340(param_2,param_1);

    while (uVar1 = 0, pcVar2 != (char *)0x0) {

      sVar3 = strlen(param_1);

      pcVar4 = pcVar2 + sVar3;

      if (((pcVar2 == param_2) || (pcVar2[-1] == ' ')) && ((*pcVar4 == ' ' || (*pcVar4 == '\0')))) {

        return CONCAT71((int7)((ulonglong)pcVar4 >> 8),1);

      }

      pcVar2 = (char *)thunk_FUN_1402c9340(pcVar4,param_1);

      param_2 = pcVar4;

    }

  }

  return uVar1 & 0xffffffffffffff00;

}




