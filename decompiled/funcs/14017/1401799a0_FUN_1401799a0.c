// Address: 0x1401799a0
// Ghidra name: FUN_1401799a0
// ============ 0x1401799a0 FUN_1401799a0 (size=47) ============


LPCRITICAL_SECTION FUN_1401799a0(void)



{

  LPCRITICAL_SECTION lpCriticalSection;

  

  lpCriticalSection = (LPCRITICAL_SECTION)FUN_1401841f0(0x28);

  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {

    InitializeCriticalSectionAndSpinCount(lpCriticalSection,2000);

  }

  return lpCriticalSection;

}




