// Address: 0x140203be0
// Ghidra name: FUN_140203be0
// ============ 0x140203be0 FUN_140203be0 (size=176) ============


void FUN_140203be0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char *pcVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  pcVar2 = *(char **)(param_2 + 0x138);

  if (*(longlong *)(lVar1 + 0x98) == param_2) {

    *(undefined8 *)(lVar1 + 0x98) = 0;

  }

  if (pcVar2 != (char *)0x0) {

    if (*pcVar2 == '\0') {

      FUN_140137fd0(*(undefined8 *)(lVar1 + 8),*(undefined8 *)(pcVar2 + 8));

    }

    if (pcVar2[0x41] == '\0') {

      FUN_140137fd0(*(undefined8 *)(lVar1 + 8),*(undefined8 *)(pcVar2 + 0x48));

    }

    if (pcVar2[0x42] == '\0') {

      FUN_140137fd0(*(undefined8 *)(lVar1 + 8),*(undefined8 *)(pcVar2 + 0x50));

    }

    if (pcVar2[0x59] == '\0') {

      FUN_140137fd0(*(undefined8 *)(lVar1 + 8),*(undefined8 *)(pcVar2 + 0x60));

    }

    FUN_1401841e0(*(undefined8 *)(pcVar2 + 0x18));

    FUN_1401841e0(pcVar2);

    *(undefined8 *)(param_2 + 0x138) = 0;

  }

  return;

}




