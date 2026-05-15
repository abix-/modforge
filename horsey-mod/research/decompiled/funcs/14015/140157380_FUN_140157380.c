// Address: 0x140157380
// Ghidra name: FUN_140157380
// ============ 0x140157380 FUN_140157380 (size=132) ============


void FUN_140157380(longlong param_1)



{

  if (*(int *)(param_1 + 0xf4) == 0) {

    if (*(int *)(param_1 + 0x100) == 0) {

      return;

    }

  }

  else {

    if (*(longlong *)(param_1 + 0xf8) != 0) {

      FUN_140176ce0();

      *(undefined8 *)(param_1 + 0xf8) = 0;

    }

    *(undefined4 *)(param_1 + 0xf4) = 0;

    FUN_14017e880(0x8000);

  }

  if (*(int *)(param_1 + 0x100) != 0) {

    if (*(longlong *)(param_1 + 0x108) != 0) {

      FUN_140176ce0();

      *(undefined8 *)(param_1 + 0x108) = 0;

    }

    *(undefined4 *)(param_1 + 0x100) = 0;

    FUN_14017e880(0x8000);

  }

  return;

}




