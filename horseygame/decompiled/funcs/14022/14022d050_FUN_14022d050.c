// Address: 0x14022d050
// Ghidra name: FUN_14022d050
// ============ 0x14022d050 FUN_14022d050 (size=125) ============


void FUN_14022d050(undefined1 *param_1)



{

  if (*(longlong *)(param_1 + 0x18) != -1) {

    *param_1 = 1;

    SetEvent(*(HANDLE *)(param_1 + 0x10));

    WaitForSingleObject(*(HANDLE *)(param_1 + 0x18),3000);

    CloseHandle(*(HANDLE *)(param_1 + 0x18));

    *(undefined8 *)(param_1 + 0x18) = 0xffffffffffffffff;

  }

  if (*(HANDLE *)(param_1 + 8) != (HANDLE)0xffffffffffffffff) {

    CloseHandle(*(HANDLE *)(param_1 + 8));

    *(undefined8 *)(param_1 + 8) = 0xffffffffffffffff;

  }

  if (*(HANDLE *)(param_1 + 0x10) != (HANDLE)0xffffffffffffffff) {

    CloseHandle(*(HANDLE *)(param_1 + 0x10));

    *(undefined8 *)(param_1 + 0x10) = 0xffffffffffffffff;

  }

  return;

}




