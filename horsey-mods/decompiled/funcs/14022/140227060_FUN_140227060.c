// Address: 0x140227060
// Ghidra name: FUN_140227060
// ============ 0x140227060 FUN_140227060 (size=252) ============


undefined4 FUN_140227060(undefined8 param_1,longlong param_2,longlong param_3)



{

  DEVMODEW *lpDevMode;

  LPCWSTR lpszDeviceName;

  LONG LVar1;

  undefined4 uVar2;

  DEVMODEW *lpDevMode_00;

  char *pcVar3;

  

  lpDevMode = *(DEVMODEW **)(param_3 + 0x20);

  lpszDeviceName = *(LPCWSTR *)(param_2 + 0x80);

  lpDevMode_00 = lpDevMode;

  if (lpDevMode == *(DEVMODEW **)(param_2 + 0x40)) {

    lpDevMode_00 = (DEVMODEW *)0x0;

  }

  LVar1 = ChangeDisplaySettingsExW(lpszDeviceName,lpDevMode_00,(HWND)0x0,4,(LPVOID)0x0);

  if (LVar1 == 0) {

    EnumDisplaySettingsW(lpszDeviceName,0xffffffff,lpDevMode);

    FUN_140227160(param_1,lpszDeviceName,0xffffffff,param_3);

    return 1;

  }

  pcVar3 = "Unknown reason";

  if (LVar1 == -5) {

    pcVar3 = "DISP_CHANGE_BADPARAM";

  }

  else {

    if (LVar1 == -4) {

      uVar2 = FUN_14012e850("ChangeDisplaySettingsEx() failed: %s","DISP_CHANGE_BADFLAGS");

      return uVar2;

    }

    if (LVar1 == -2) {

      uVar2 = FUN_14012e850("ChangeDisplaySettingsEx() failed: %s","DISP_CHANGE_BADMODE");

      return uVar2;

    }

    if (LVar1 == -1) {

      uVar2 = FUN_14012e850("ChangeDisplaySettingsEx() failed: %s","DISP_CHANGE_FAILED");

      return uVar2;

    }

  }

  uVar2 = FUN_14012e850("ChangeDisplaySettingsEx() failed: %s",pcVar3);

  return uVar2;

}




