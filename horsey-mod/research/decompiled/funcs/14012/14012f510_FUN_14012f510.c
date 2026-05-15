// Address: 0x14012f510
// Ghidra name: FUN_14012f510
// ============ 0x14012f510 FUN_14012f510 (size=58) ============


char * FUN_14012f510(char *param_1)



{

  char *pcVar1;

  char cVar2;

  

  cVar2 = *param_1;

  pcVar1 = param_1;

  while (cVar2 != '\0') {

    cVar2 = FUN_140190620(cVar2);

    *pcVar1 = cVar2;

    pcVar1 = pcVar1 + 1;

    cVar2 = *pcVar1;

  }

  return param_1;

}




