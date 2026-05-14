// Address: 0x1402ec3c4
// Ghidra name: InitializeCriticalSectionEx
// ============ 0x1402ec3c4 InitializeCriticalSectionEx (size=7) ============


BOOL __stdcall

InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount,DWORD Flags)



{

  BOOL BVar1;

  

                    /* WARNING: Could not recover jumptable at 0x0001402ec3c4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  BVar1 = InitializeCriticalSectionEx(lpCriticalSection,dwSpinCount,Flags);

  return BVar1;

}




