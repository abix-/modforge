// Address: 0x1401800c0
// Ghidra name: FUN_1401800c0
// ============ 0x1401800c0 FUN_1401800c0 (size=330) ============


void FUN_1401800c0(char *param_1)



{

  HMODULE hModule;

  size_t sVar1;

  longlong lVar2;

  HANDLE pvVar3;

  PVOID Handle;

  ULONG_PTR local_28;

  char *local_20;

  undefined4 local_18;

  undefined4 local_14;

  

  if (param_1 == (char *)0x0) {

    return;

  }

  if (DAT_1403fc6c8 == (HMODULE)0x0) {

    DAT_1403fc6c8 = GetModuleHandleW(L"kernel32.dll");

    if (DAT_1403fc6c8 != (HMODULE)0x0) {

      DAT_1403fc6c0 = GetProcAddress(DAT_1403fc6c8,"SetThreadDescription");

    }

    if ((DAT_1403fc6c8 == (HMODULE)0x0) || (DAT_1403fc6c0 == (FARPROC)0x0)) {

      hModule = GetModuleHandleW(L"KernelBase.dll");

      if (hModule != (HMODULE)0x0) {

        DAT_1403fc6c0 = GetProcAddress(hModule,"SetThreadDescription");

      }

      goto LAB_14018015f;

    }

  }

  else {

LAB_14018015f:

    if (DAT_1403fc6c0 == (FARPROC)0x0) goto LAB_1401801a8;

  }

  sVar1 = strlen(param_1);

  lVar2 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar1 + 1);

  if (lVar2 != 0) {

    pvVar3 = GetCurrentThread();

    (*DAT_1403fc6c0)(pvVar3,lVar2);

    FUN_1401841e0(lVar2);

  }

LAB_1401801a8:

  Handle = AddVectoredExceptionHandler(1,(PVECTORED_EXCEPTION_HANDLER)&LAB_14017ff60);

  if (Handle != (PVOID)0x0) {

    local_28 = 0x1000;

    local_14 = 0;

    local_18 = 0xffffffff;

    local_20 = param_1;

    RaiseException(0x406d1388,0,3,&local_28);

    RemoveVectoredExceptionHandler(Handle);

  }

  return;

}




