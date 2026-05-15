// Address: 0x14003f740
// Ghidra name: FUN_14003f740
// ============ 0x14003f740 FUN_14003f740 (size=103) ============


void FUN_14003f740(void)



{

  if (((DAT_1403ea292 == '\0') && (DAT_1403ea293 != '\0')) && (*(int *)(DAT_1403ea2a8 + 0x4c) != 7))

  {

    if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 10) = 1;

    }

    if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 10) = 1;

    }

    *(undefined1 *)(DAT_1403ea2a8 + 0x38) = 1;

    *(undefined4 *)(DAT_1403ea2a8 + 0x50) = *(undefined4 *)(DAT_1403ea2a8 + 0x4c);

    *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 7;

  }

  return;

}




