// Address: 0x140053730
// Ghidra name: FUN_140053730
// ============ 0x140053730 FUN_140053730 (size=218) ============


undefined8 FUN_140053730(longlong param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  

  pcVar1 = *(char **)(param_1 + 0x40);

  if (pcVar1 == (char *)0x0) {

    iVar3 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

    cVar2 = (char)iVar3;

    if (iVar3 != -1) goto LAB_14005376c;

  }

  else if (pcVar1 < *(char **)(param_1 + 0x50)) {

    cVar2 = *pcVar1;

    *(char **)(param_1 + 0x40) = pcVar1 + 1;

LAB_14005376c:

    if (cVar2 != 'O') goto LAB_1400537f8;

    pcVar1 = *(char **)(param_1 + 0x40);

    if (pcVar1 == (char *)0x0) {

      iVar3 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

      cVar2 = (char)iVar3;

      if (iVar3 != -1) goto LAB_1400537a0;

    }

    else if (pcVar1 < *(char **)(param_1 + 0x50)) {

      cVar2 = *pcVar1;

      *(char **)(param_1 + 0x40) = pcVar1 + 1;

LAB_1400537a0:

      if (cVar2 != 'g') goto LAB_1400537f8;

      pcVar1 = *(char **)(param_1 + 0x40);

      if (pcVar1 == (char *)0x0) {

        iVar3 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

        cVar2 = (char)iVar3;

        if (iVar3 == -1) goto LAB_1400537ee;

      }

      else {

        if (*(char **)(param_1 + 0x50) <= pcVar1) goto LAB_1400537ee;

        cVar2 = *pcVar1;

        *(char **)(param_1 + 0x40) = pcVar1 + 1;

      }

      if (cVar2 == 'g') {

        cVar2 = FUN_14004ca60(param_1);

        if (cVar2 == 'S') {

          uVar4 = FUN_140053810(param_1);

          return uVar4;

        }

      }

      goto LAB_1400537f8;

    }

  }

LAB_1400537ee:

  *(undefined4 *)(param_1 + 0x98) = 1;

LAB_1400537f8:

  *(undefined4 *)(param_1 + 0x9c) = 0x1e;

  return 0;

}




