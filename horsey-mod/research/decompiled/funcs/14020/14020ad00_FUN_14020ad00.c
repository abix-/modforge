// Address: 0x14020ad00
// Ghidra name: FUN_14020ad00
// ============ 0x14020ad00 FUN_14020ad00 (size=127) ============


undefined8 FUN_14020ad00(void)



{

  BOOL BVar1;

  undefined8 uVar2;

  RAWINPUTDEVICE local_18;

  

  if (DAT_1403fd1b0 != '\0') {

    local_18.usUsage = DAT_14034ffd0;

    local_18.usUsagePage = 1;

    local_18.dwFlags = 1;

    local_18.hwndTarget = (HWND)0x0;

    BVar1 = RegisterRawInputDevices(&local_18,1,0x10);

    if (BVar1 == 0) {

      uVar2 = FUN_14012e850("Couldn\'t unregister for raw input events");

      return uVar2;

    }

  }

  return 1;

}




