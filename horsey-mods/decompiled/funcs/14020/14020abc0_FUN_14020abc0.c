// Address: 0x14020abc0
// Ghidra name: FUN_14020abc0
// ============ 0x14020abc0 FUN_14020abc0 (size=119) ============


undefined8 FUN_14020abc0(HWND param_1)



{

  BOOL BVar1;

  undefined8 uVar2;

  RAWINPUTDEVICE local_18;

  

  if (DAT_1403fd1b0 != '\0') {

    local_18.usUsage = DAT_14034ffd0;

    local_18.usUsagePage = 1;

    local_18.dwFlags = 0x2100;

    local_18.hwndTarget = param_1;

    BVar1 = RegisterRawInputDevices(&local_18,1,0x10);

    if (BVar1 == 0) {

      uVar2 = FUN_14012e850("Couldn\'t register for raw input events");

      return uVar2;

    }

  }

  return 1;

}




