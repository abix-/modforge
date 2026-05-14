// Address: 0x1402f4d6c
// Ghidra name: __acrt_lowio_unlock_fh
// ============ 0x1402f4d6c __acrt_lowio_unlock_fh (size=39) ============


/* Library Function - Single Match

    __acrt_lowio_unlock_fh

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __acrt_lowio_unlock_fh(uint param_1)



{

                    /* WARNING: Could not recover jumptable at 0x0001402f4d8c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  LeaveCriticalSection

            ((LPCRITICAL_SECTION)

             ((&DAT_1403ff160)[(longlong)(int)param_1 >> 6] + (ulonglong)(param_1 & 0x3f) * 0x48));

  return;

}




