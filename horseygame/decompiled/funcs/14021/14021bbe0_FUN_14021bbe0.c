// Address: 0x14021bbe0
// Ghidra name: FUN_14021bbe0
// ============ 0x14021bbe0 FUN_14021bbe0 (size=115) ============


void FUN_14021bbe0(void)



{

  while (0 < DAT_1403fdb90) {

    FUN_14021be60(*(undefined8 *)(DAT_1403fdb98 + 8));

  }

  if (DAT_1403fdb88 != (longlong *)0x0) {

    (**(code **)(*DAT_1403fdb88 + 0x30))(DAT_1403fdb88,0);

    (**(code **)(*DAT_1403fdb88 + 0x10))();

    DAT_1403fdb88 = (longlong *)0x0;

  }

  if (DAT_1403fdb80 == '\0') {

    return;

  }

  CoUninitialize();

  return;

}




