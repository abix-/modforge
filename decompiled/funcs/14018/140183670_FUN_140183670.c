// Address: 0x140183670
// Ghidra name: FUN_140183670
// ============ 0x140183670 FUN_140183670 (size=135) ============


void FUN_140183670(void)



{

  longlong lVar1;

  ulonglong uVar2;

  int iVar3;

  char *pcVar4;

  

  if (DAT_1403fcafc != '\0') {

    iVar3 = 0;

    pcVar4 = &DAT_1403fc6ea;

    do {

      if (*pcVar4 == '\x04') {

        FUN_1401839c0(0,4,0,0,iVar3,0);

      }

      iVar3 = iVar3 + 1;

      pcVar4 = pcVar4 + 1;

    } while (iVar3 < 0x200);

    DAT_1403fcafc = '\0';

  }

  lVar1 = DAT_1403fcb00;

  if (DAT_1403fcb00 != 0) {

    uVar2 = FUN_140149350();

    if (lVar1 + 0xfaU <= uVar2) {

      DAT_1403fcb00 = 0;

    }

  }

  return;

}




