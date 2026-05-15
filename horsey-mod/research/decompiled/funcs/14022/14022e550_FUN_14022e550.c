// Address: 0x14022e550
// Ghidra name: FUN_14022e550
// ============ 0x14022e550 FUN_14022e550 (size=43) ============


void FUN_14022e550(void)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  

  pcVar3 = (char *)FUN_14012f0d0();

  cVar2 = *pcVar3;

  while (cVar2 != '\0') {

    if (cVar2 == '\x01') {

      *pcVar3 = ' ';

    }

    pcVar1 = pcVar3 + 1;

    pcVar3 = pcVar3 + 1;

    cVar2 = *pcVar1;

  }

  return;

}




