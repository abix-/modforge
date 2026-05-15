// Address: 0x1402cd13c
// Ghidra name: FUN_1402cd13c
// ============ 0x1402cd13c FUN_1402cd13c (size=76) ============


longlong FUN_1402cd13c(longlong param_1,longlong param_2)



{

  DWORD dwErrCode;

  longlong lVar1;

  

  lVar1 = 0;

  if (*(char *)(param_2 + 0x10) == '\0') {

    dwErrCode = GetLastError();

    *(undefined8 *)(param_2 + 8) = 0;

    *(undefined1 *)(param_2 + 0x10) = 1;

    SetLastError(dwErrCode);

  }

  else {

    lVar1 = *(longlong *)(param_2 + 8);

  }

  return param_1 + lVar1 * 8;

}




