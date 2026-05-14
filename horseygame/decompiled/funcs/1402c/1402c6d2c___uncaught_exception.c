// Address: 0x1402c6d2c
// Ghidra name: __uncaught_exception
// ============ 0x1402c6d2c __uncaught_exception (size=5) ============


bool __uncaught_exception(void)



{

  bool bVar1;

  longlong lVar2;

  

  lVar2 = __vcrt_getptd_noinit();

  bVar1 = false;

  if (lVar2 != 0) {

    bVar1 = 0 < *(int *)(lVar2 + 0x30);

  }

  return bVar1;

}




