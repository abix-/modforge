// Address: 0x140203a80
// Ghidra name: FUN_140203a80
// ============ 0x140203a80 FUN_140203a80 (size=337) ============


void FUN_140203a80(longlong param_1)



{

  char *pcVar1;

  

  pcVar1 = *(char **)(param_1 + 0x2e0);

  if (pcVar1 != (char *)0x0) {

    if (*(longlong *)(pcVar1 + 0xa0) != 0) {

      FUN_1401341d0();

      pcVar1[0xa0] = '\0';

      pcVar1[0xa1] = '\0';

      pcVar1[0xa2] = '\0';

      pcVar1[0xa3] = '\0';

      pcVar1[0xa4] = '\0';

      pcVar1[0xa5] = '\0';

      pcVar1[0xa6] = '\0';

      pcVar1[0xa7] = '\0';

    }

    if (*(longlong *)(pcVar1 + 0x118) != 0) {

      FUN_140137f70(*(undefined8 *)(pcVar1 + 8));

    }

    if (*(longlong *)(pcVar1 + 0x120) != 0) {

      FUN_140137f70(*(undefined8 *)(pcVar1 + 8));

    }

    if (*(longlong *)(pcVar1 + 0x128) != 0) {

      FUN_140137f70(*(undefined8 *)(pcVar1 + 8));

    }

    if (*(longlong *)(pcVar1 + 0x130) != 0) {

      FUN_140137f70(*(undefined8 *)(pcVar1 + 8));

    }

    if (*(longlong *)(pcVar1 + 0x138) != 0) {

      FUN_140137f70(*(undefined8 *)(pcVar1 + 8));

    }

    if (*(longlong *)(pcVar1 + 0x140) != 0) {

      FUN_140137f70(*(undefined8 *)(pcVar1 + 8));

    }

    if (*(longlong *)(pcVar1 + 0x148) != 0) {

      FUN_140137f70(*(undefined8 *)(pcVar1 + 8));

    }

    if (*(longlong *)(pcVar1 + 0x150) != 0) {

      FUN_140137f70(*(undefined8 *)(pcVar1 + 8));

    }

    if (*(longlong *)(pcVar1 + 0x58) != 0) {

      FUN_140137fd0(*(undefined8 *)(pcVar1 + 8));

    }

    if ((*(longlong *)(param_1 + 0x118) != 0) && (*(longlong *)(pcVar1 + 8) != 0)) {

      FUN_140138030();

    }

    FUN_1402057a0(pcVar1);

    FUN_1402634b0(pcVar1 + 0x50);

    if (*(longlong *)(pcVar1 + 8) != 0) {

      FUN_1402633f0(pcVar1 + 0x10);

      if (*pcVar1 == '\0') {

        FUN_140135da0(*(undefined8 *)(pcVar1 + 8));

      }

    }

    FUN_1401841e0(pcVar1);

  }

  return;

}




