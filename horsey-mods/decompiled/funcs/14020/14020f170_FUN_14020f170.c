// Address: 0x14020f170
// Ghidra name: FUN_14020f170
// ============ 0x14020f170 FUN_14020f170 (size=368) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14020f170(undefined8 *param_1)



{

  ATOM AVar1;

  undefined4 uVar2;

  HMODULE pHVar3;

  HWND hRecipient;

  undefined8 uVar4;

  HDEVNOTIFY pvVar5;

  undefined4 local_28;

  undefined8 local_24;

  undefined4 local_1c;

  undefined4 uStack_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 local_c;

  

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  uVar2 = FUN_1401a9610();

  *(undefined4 *)param_1 = uVar2;

  pHVar3 = GetModuleHandleW((LPCWSTR)0x0);

  param_1[4] = pHVar3;

  ((WNDCLASSEXW *)(param_1 + 1))->cbSize = 0x50;

  param_1[2] = FUN_14020f3e0;

  param_1[9] = L"Message";

  AVar1 = RegisterClassExW((WNDCLASSEXW *)(param_1 + 1));

  if (AVar1 == 0) {

    FUN_1401a9ed0("Failed to create register class for joystick autodetect");

    FUN_14020f120(param_1);

    return 0;

  }

  hRecipient = CreateWindowExW(0,L"Message",(LPCWSTR)0x0,0,0,0,0,0,(HWND)0xfffffffffffffffd,

                               (HMENU)0x0,(HINSTANCE)0x0,(LPVOID)0x0);

  param_1[0xb] = hRecipient;

  if (hRecipient == (HWND)0x0) {

    FUN_1401a9ed0("Failed to create message window for joystick autodetect");

    FUN_14020f120(param_1);

    uVar4 = 0;

  }

  else {

    local_24 = 5;

    local_c = 0;

    local_28 = 0x20;

    local_1c = _DAT_1403e5198;

    uStack_18 = uRam00000001403e519c;

    uStack_14 = uRam00000001403e51a0;

    uStack_10 = uRam00000001403e51a4;

    pvVar5 = RegisterDeviceNotificationW(hRecipient,&local_28,0);

    param_1[0xc] = pvVar5;

    if (pvVar5 == (HDEVNOTIFY)0x0) {

      FUN_1401a9ed0("Failed to create notify device for joystick autodetect");

      FUN_14020f120(param_1);

      uVar4 = 0;

    }

    else {

      FUN_14020abc0(param_1[0xb]);

      uVar4 = 1;

    }

  }

  return uVar4;

}




