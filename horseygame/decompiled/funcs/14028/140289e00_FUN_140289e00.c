// Address: 0x140289e00
// Ghidra name: FUN_140289e00
// ============ 0x140289e00 FUN_140289e00 (size=79) ============


void FUN_140289e00(void)



{

  if (DAT_1403fde80 != (longlong *)0x0) {

    (**(code **)(*DAT_1403fde80 + 0x38))(DAT_1403fde80,&PTR_PTR_1403e79a0);

    (**(code **)(*DAT_1403fde80 + 0x10))();

    DAT_1403fde80 = (longlong *)0x0;

  }

  DAT_1403fde88 = 0;

  DAT_1403fde90 = 0;

  CoUninitialize();

  return;

}




