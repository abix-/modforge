// Address: 0x1401991c0
// Ghidra name: FUN_1401991c0
// ============ 0x1401991c0 FUN_1401991c0 (size=83) ============


void FUN_1401991c0(undefined8 param_1,LPCWSTR param_2)



{

  BOOL BVar1;

  HMODULE hInstance;

  tagWNDCLASSEXW local_58;

  

  local_58.hIcon = (HICON)0x0;

  local_58.hIconSm = (HICON)0x0;

  hInstance = GetModuleHandleW((LPCWSTR)0x0);

  BVar1 = GetClassInfoExW(hInstance,param_2,&local_58);

  if (BVar1 != 0) {

    UnregisterClassW(param_2,hInstance);

  }

  return;

}




