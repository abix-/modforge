// Address: 0x140223f00
// Ghidra name: FUN_140223f00
// ============ 0x140223f00 FUN_140223f00 (size=69) ============


void FUN_140223f00(longlong param_1)



{

  if ((*(char *)(param_1 + 0x140) != '\0') && (*(longlong *)(param_1 + 0x150) != 0)) {

    FUN_140223dd0();

    if (*(HWND *)(param_1 + 0x150) == *(HWND *)(param_1 + 0x148)) {

      ImmAssociateContext(*(HWND *)(param_1 + 0x150),(HIMC)0x0);

    }

    *(undefined1 *)(param_1 + 0x141) = 0;

  }

  return;

}




