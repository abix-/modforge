// Address: 0x14020f120
// Ghidra name: FUN_14020f120
// ============ 0x14020f120 FUN_14020f120 (size=79) ============


void FUN_14020f120(int *param_1)



{

  FUN_14020ad00();

  if (*(HDEVNOTIFY *)(param_1 + 0x18) != (HDEVNOTIFY)0x0) {

    UnregisterDeviceNotification(*(HDEVNOTIFY *)(param_1 + 0x18));

  }

  if (*(HWND *)(param_1 + 0x16) != (HWND)0x0) {

    DestroyWindow(*(HWND *)(param_1 + 0x16));

  }

  UnregisterClassW(*(LPCWSTR *)(param_1 + 0x12),*(HINSTANCE *)(param_1 + 8));

  if (*param_1 == 0) {

    CoUninitialize();

    return;

  }

  return;

}




