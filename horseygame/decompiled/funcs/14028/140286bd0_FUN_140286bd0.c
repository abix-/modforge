// Address: 0x140286bd0
// Ghidra name: FUN_140286bd0
// ============ 0x140286bd0 FUN_140286bd0 (size=62) ============


void FUN_140286bd0(void)



{

  if (DAT_1403fde50 != (longlong *)0x0) {

    (**(code **)(*DAT_1403fde50 + 0x10))();

    DAT_1403fde50 = (longlong *)0x0;

  }

  if (DAT_1403fde48 != '\0') {

    CoUninitialize();

    DAT_1403fde48 = '\0';

  }

  return;

}




