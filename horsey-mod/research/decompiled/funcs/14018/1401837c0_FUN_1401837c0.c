// Address: 0x1401837c0
// Ghidra name: FUN_1401837c0
// ============ 0x1401837c0 FUN_1401837c0 (size=68) ============


void FUN_1401837c0(void)



{

  int iVar1;

  char *pcVar2;

  

  iVar1 = 0;

  pcVar2 = &DAT_1403fc8ea;

  do {

    if (*pcVar2 != '\0') {

      FUN_140183990(0,0,0,iVar1,0);

    }

    iVar1 = iVar1 + 1;

    pcVar2 = pcVar2 + 1;

  } while (iVar1 < 0x200);

  return;

}




