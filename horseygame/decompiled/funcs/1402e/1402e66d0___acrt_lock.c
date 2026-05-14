// Address: 0x1402e66d0
// Ghidra name: __acrt_lock
// ============ 0x1402e66d0 __acrt_lock (size=25) ============


/* Library Function - Multiple Matches With Different Base Names

    __acrt_lock

    __acrt_unlock

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __acrt_lock(int param_1)



{

                    /* WARNING: Could not recover jumptable at 0x0001402e66e2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_1403fed60 + (longlong)param_1 * 0x28));

  return;

}




