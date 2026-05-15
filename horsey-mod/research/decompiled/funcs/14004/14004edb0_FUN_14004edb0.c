// Address: 0x14004edb0
// Ghidra name: FUN_14004edb0
// ============ 0x14004edb0 FUN_14004edb0 (size=244) ============


undefined8 FUN_14004edb0(longlong param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  

  if (*(int *)(param_1 + 0x6e8) != -1) goto LAB_14004ee97;

  pcVar1 = *(char **)(param_1 + 0x40);

  if (pcVar1 == (char *)0x0) {

    iVar3 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

    cVar2 = (char)iVar3;

    if (iVar3 == -1) {

      *(undefined4 *)(param_1 + 0x98) = 1;

      goto LAB_14004ee07;

    }

  }

  else if (pcVar1 < *(char **)(param_1 + 0x50)) {

    cVar2 = *pcVar1;

    *(char **)(param_1 + 0x40) = pcVar1 + 1;

  }

  else {

    *(undefined4 *)(param_1 + 0x98) = 1;

LAB_14004ee07:

    cVar2 = '\0';

  }

  if (*(int *)(param_1 + 0x98) != 0) {

    return 0;

  }

  if (cVar2 != 'O') {

    *(undefined4 *)(param_1 + 0x9c) = 0x1e;

    return 0;

  }

  cVar2 = FUN_14004ca60(param_1);

  if (((cVar2 != 'g') || (cVar2 = FUN_14004ca60(param_1), cVar2 != 'g')) ||

     (cVar2 = FUN_14004ca60(param_1), cVar2 != 'S')) {

    *(undefined4 *)(param_1 + 0x9c) = 0x1e;

    return 0;

  }

  iVar3 = FUN_140053810(param_1);

  if (iVar3 == 0) {

    return 0;

  }

  if ((*(byte *)(param_1 + 0x6e3) & 1) != 0) {

    *(undefined4 *)(param_1 + 0x6ec) = 0;

    *(undefined1 *)(param_1 + 0x6e4) = 0;

    *(undefined4 *)(param_1 + 0x9c) = 0x20;

    return 0;

  }

LAB_14004ee97:

  uVar4 = FUN_1400535f0(param_1);

  return uVar4;

}




