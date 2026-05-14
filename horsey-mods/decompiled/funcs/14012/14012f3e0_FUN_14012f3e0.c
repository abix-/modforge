// Address: 0x14012f3e0
// Ghidra name: FUN_14012f3e0
// ============ 0x14012f3e0 FUN_14012f3e0 (size=38) ============


void FUN_14012f3e0(char *param_1,ulonglong param_2)



{

  char cVar1;

  ulonglong uVar2;

  

  uVar2 = 0;

  if (param_2 != 0) {

    do {

      cVar1 = *param_1;

      param_1 = param_1 + 1;

      if (cVar1 == '\0') {

        return;

      }

      uVar2 = uVar2 + 1;

    } while (uVar2 < param_2);

  }

  return;

}




