// Address: 0x140224b10
// Ghidra name: FUN_140224b10
// ============ 0x140224b10 FUN_140224b10 (size=204) ============


void FUN_140224b10(longlong param_1)



{

  undefined8 *puVar1;

  int iVar2;

  

  if (*(char *)(param_1 + 0x140) != '\0') {

    if (*(HWND *)(param_1 + 0x148) != (HWND)0x0) {

      ImmAssociateContext(*(HWND *)(param_1 + 0x148),*(HIMC *)(param_1 + 0x160));

    }

    iVar2 = 0;

    *(undefined8 *)(param_1 + 0x148) = 0;

    *(undefined8 *)(param_1 + 0x160) = 0;

    if (*(longlong *)(param_1 + 0x250) != 0) {

      FUN_140188670();

      *(undefined8 *)(param_1 + 0x250) = 0;

    }

    if (0 < *(int *)(param_1 + 0x1f8)) {

      puVar1 = (undefined8 *)(param_1 + 0x1a8);

      do {

        FUN_1401841e0(*puVar1);

        *puVar1 = 0;

        puVar1 = puVar1 + 1;

        iVar2 = iVar2 + 1;

      } while (iVar2 < *(int *)(param_1 + 0x1f8));

    }

    *(undefined1 *)(param_1 + 0x140) = 0;

  }

  return;

}




