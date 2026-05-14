// Address: 0x140191cf0
// Ghidra name: FUN_140191cf0
// ============ 0x140191cf0 FUN_140191cf0 (size=120) ============


void FUN_140191cf0(undefined8 *param_1)



{

  HMODULE hModule;

  FARPROC pFVar1;

  DWORD local_res8 [8];

  

  hModule = GetModuleHandleW(L"kernel32.dll");

  pFVar1 = GetProcAddress(hModule,"CancelIoEx");

  if (param_1 != (undefined8 *)0x0) {

    if (pFVar1 == (FARPROC)0x0) {

      CancelIo((HANDLE)*param_1);

    }

    else {

      (*pFVar1)((HANDLE)*param_1,0);

    }

    if (*(int *)(param_1 + 7) != 0) {

      local_res8[0] = 0;

      GetOverlappedResult((HANDLE)*param_1,(LPOVERLAPPED)(param_1 + 9),local_res8,1);

    }

    FUN_140192680(param_1);

    return;

  }

  return;

}




