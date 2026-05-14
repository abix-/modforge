// Address: 0x14017e170
// Ghidra name: FUN_14017e170
// ============ 0x14017e170 FUN_14017e170 (size=46) ============


void FUN_14017e170(uint param_1)



{

  int iVar1;

  char *pcVar2;

  

  iVar1 = 0x1f;

  if (param_1 != 0) {

    for (; param_1 >> iVar1 == 0; iVar1 = iVar1 + -1) {

    }

  }

  if ((param_1 != 0) && (-1 < iVar1)) {

    pcVar2 = &DAT_1403fc648 + iVar1;

    if (*pcVar2 != '\0') {

      if (DAT_1403fc640 != '\0') {

        *pcVar2 = '\0';

        return;

      }

      *pcVar2 = *pcVar2 + -1;

    }

  }

  return;

}




