// Address: 0x1402154d0
// Ghidra name: FUN_1402154d0
// ============ 0x1402154d0 FUN_1402154d0 (size=89) ============


void FUN_1402154d0(longlong param_1)



{

  if ((*(longlong *)(*(longlong *)(param_1 + 200) + 0x30) != 0) && (DAT_1403fdab8 != (code *)0x0)) {

    (*DAT_1403fdab8)();

    *(undefined8 *)(*(longlong *)(param_1 + 200) + 0x30) = 0;

  }

  if (*(char *)(*(longlong *)(param_1 + 200) + 0x38) != '\0') {

    CoUninitialize();

    *(undefined1 *)(*(longlong *)(param_1 + 200) + 0x38) = 0;

  }

  return;

}




