// Address: 0x1402e6724
// Ghidra name: __acrt_unlock
// ============ 0x1402e6724 __acrt_unlock (size=25) ============


/* Library Function - Single Match

    __acrt_unlock

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __acrt_unlock(int param_1)



{

                    /* WARNING: Could not recover jumptable at 0x0001402e6736. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_1403fed60 + (longlong)param_1 * 0x28));

  return;

}




