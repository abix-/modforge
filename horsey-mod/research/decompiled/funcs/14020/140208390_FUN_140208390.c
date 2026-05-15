// Address: 0x140208390
// Ghidra name: FUN_140208390
// ============ 0x140208390 FUN_140208390 (size=38) ============


undefined1 FUN_140208390(longlong param_1)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  

  pcVar3 = *(char **)(param_1 + 0x28);

  if (pcVar3 != (char *)0x0) {

    cVar2 = *pcVar3;

    while (cVar2 != '\0') {

      if (cVar2 != '0') {

        return 0;

      }

      pcVar1 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

      cVar2 = *pcVar1;

    }

  }

  return 1;

}




