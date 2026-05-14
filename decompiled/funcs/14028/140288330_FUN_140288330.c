// Address: 0x140288330
// Ghidra name: FUN_140288330
// ============ 0x140288330 FUN_140288330 (size=62) ============


void FUN_140288330(void)



{

  if (DAT_1403fde60 != (longlong *)0x0) {

    (**(code **)(*DAT_1403fde60 + 0x10))();

    DAT_1403fde60 = (longlong *)0x0;

  }

  if (DAT_1403fde58 != '\0') {

    CoUninitialize();

    DAT_1403fde58 = '\0';

  }

  return;

}




