// Address: 0x1402c7ae0
// Ghidra name: __security_check_cookie
// ============ 0x1402c7ae0 __security_check_cookie (size=30) ============


/* WARNING: This is an inlined function */



void __cdecl __security_check_cookie(uintptr_t _StackCookie)



{

  if ((_StackCookie == DAT_1403e8b00) && ((short)(_StackCookie >> 0x30) == 0)) {

    return;

  }

  FUN_1402c803c(_StackCookie);

  return;

}




