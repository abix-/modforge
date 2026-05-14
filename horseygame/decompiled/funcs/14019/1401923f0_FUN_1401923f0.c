// Address: 0x1401923f0
// Ghidra name: FUN_1401923f0
// ============ 0x1401923f0 FUN_1401923f0 (size=81) ============


void FUN_1401923f0(void)



{

  if (DAT_1403fcbc0 != '\0') {

    if (DAT_1403fcc38 != (HDEVNOTIFY)0x0) {

      UnregisterDeviceNotification(DAT_1403fcc38);

    }

    if (DAT_1403fcc30 != (HWND)0x0) {

      DestroyWindow(DAT_1403fcc30);

    }

    UnregisterClassA(DAT_1403fcc20,DAT_1403fcbf8);

    DAT_1403fcbc0 = '\0';

  }

  return;

}




