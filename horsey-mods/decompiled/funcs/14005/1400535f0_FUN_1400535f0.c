// Address: 0x1400535f0
// Ghidra name: FUN_1400535f0
// ============ 0x1400535f0 FUN_1400535f0 (size=318) ============


undefined8 FUN_1400535f0(longlong param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x6e8);

  while( true ) {

    if (iVar3 != -1) {

      *(undefined4 *)(param_1 + 0x6ec) = 0;

      *(undefined8 *)(param_1 + 0x6f8) = 0;

      *(undefined1 *)(param_1 + 0x6e4) = 0;

      return 1;

    }

    pcVar1 = *(char **)(param_1 + 0x40);

    if (pcVar1 == (char *)0x0) break;

    if (*(char **)(param_1 + 0x50) <= pcVar1) goto LAB_140053712;

    cVar2 = *pcVar1;

    *(char **)(param_1 + 0x40) = pcVar1 + 1;

LAB_140053639:

    if (cVar2 != 'O') goto LAB_14005371c;

    pcVar1 = *(char **)(param_1 + 0x40);

    if (pcVar1 == (char *)0x0) {

      iVar3 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

      cVar2 = (char)iVar3;

      if (iVar3 != -1) goto LAB_140053675;

      goto LAB_140053712;

    }

    if (*(char **)(param_1 + 0x50) <= pcVar1) goto LAB_140053712;

    cVar2 = *pcVar1;

    *(char **)(param_1 + 0x40) = pcVar1 + 1;

LAB_140053675:

    if (cVar2 != 'g') goto LAB_14005371c;

    pcVar1 = *(char **)(param_1 + 0x40);

    if (pcVar1 == (char *)0x0) {

      iVar3 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

      cVar2 = (char)iVar3;

      if (iVar3 == -1) goto LAB_140053712;

    }

    else {

      if (*(char **)(param_1 + 0x50) <= pcVar1) goto LAB_140053712;

      cVar2 = *pcVar1;

      *(char **)(param_1 + 0x40) = pcVar1 + 1;

    }

    if ((cVar2 != 'g') || (cVar2 = FUN_14004ca60(param_1), cVar2 != 'S')) goto LAB_14005371c;

    iVar3 = FUN_140053810(param_1);

    if (iVar3 == 0) {

      return 0;

    }

    if ((*(byte *)(param_1 + 0x6e3) & 1) != 0) {

      *(undefined4 *)(param_1 + 0x9c) = 0x20;

      return 0;

    }

    iVar3 = *(int *)(param_1 + 0x6e8);

  }

  iVar3 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

  cVar2 = (char)iVar3;

  if (iVar3 != -1) goto LAB_140053639;

LAB_140053712:

  *(undefined4 *)(param_1 + 0x98) = 1;

LAB_14005371c:

  *(undefined4 *)(param_1 + 0x9c) = 0x1e;

  return 0;

}




