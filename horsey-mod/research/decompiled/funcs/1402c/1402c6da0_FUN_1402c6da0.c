// Address: 0x1402c6da0
// Ghidra name: FUN_1402c6da0
// ============ 0x1402c6da0 FUN_1402c6da0 (size=59) ============


void FUN_1402c6da0(void)



{

  int iVar1;

  int iVar2;

  LPCRITICAL_SECTION lpCriticalSection;

  

  LOCK();

  iVar2 = DAT_1403e8ab0 + -1;

  UNLOCK();

  iVar1 = DAT_1403e8ab0 + -1;

  DAT_1403e8ab0 = iVar2;

  if (iVar1 < 0) {

    lpCriticalSection = (LPCRITICAL_SECTION)&DAT_1403fe2b0;

    do {

      DeleteCriticalSection(lpCriticalSection);

      lpCriticalSection = lpCriticalSection + 1;

    } while (lpCriticalSection != (LPCRITICAL_SECTION)&DAT_1403fe3f0);

  }

  return;

}




