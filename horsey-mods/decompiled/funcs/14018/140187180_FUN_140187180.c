// Address: 0x140187180
// Ghidra name: FUN_140187180
// ============ 0x140187180 FUN_140187180 (size=61) ============


void FUN_140187180(longlong param_1)



{

  char *pcVar1;

  char *pcVar2;

  char *pcVar3;

  

  pcVar1 = (char *)(*(longlong *)(param_1 + 0x18) + 3);

  pcVar2 = pcVar1 + *(int *)(param_1 + 0x10) * *(int *)(param_1 + 0xc);

  pcVar3 = pcVar1;

  if (pcVar1 < pcVar2) {

    do {

      if (*pcVar3 != '\0') {

        return;

      }

      pcVar3 = pcVar3 + 4;

    } while (pcVar3 < pcVar2);

    do {

      *pcVar1 = -1;

      pcVar1 = pcVar1 + 4;

    } while (pcVar1 < pcVar2);

  }

  return;

}




