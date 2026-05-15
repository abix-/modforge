// Address: 0x14025bec0
// Ghidra name: FUN_14025bec0
// ============ 0x14025bec0 FUN_14025bec0 (size=113) ============


code * FUN_14025bec0(longlong param_1)



{

  code *pcVar1;

  

  if (*(char *)(param_1 + 5) == '\x02') {

    if (*(int *)(param_1 + 8) == 0x7c00) {

      return FUN_140252800;

    }

    pcVar1 = FUN_14024cf80;

    if (*(int *)(param_1 + 8) == 0xf800) {

      pcVar1 = FUN_140254890;

    }

    return pcVar1;

  }

  if (*(char *)(param_1 + 5) != '\x04') {

    return (code *)0x0;

  }

  if (*(int *)(param_1 + 8) == 0xff0000) {

    pcVar1 = FUN_14025a0c0;

    if (*(int *)(param_1 + 0x14) != 0) {

      pcVar1 = FUN_14024b130;

    }

    return pcVar1;

  }

  pcVar1 = FUN_14024fc30;

  if (*(int *)(param_1 + 0x14) != 0) {

    pcVar1 = FUN_140256a70;

  }

  return pcVar1;

}




