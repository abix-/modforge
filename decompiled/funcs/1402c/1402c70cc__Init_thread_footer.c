// Address: 0x1402c70cc
// Ghidra name: _Init_thread_footer
// ============ 0x1402c70cc _Init_thread_footer (size=105) ============


/* Library Function - Single Match

    _Init_thread_footer

   

   Library: Visual Studio 2019 Release */



void _Init_thread_footer(int *param_1)



{

  ulonglong uVar1;

  

  AcquireSRWLockExclusive((PSRWLOCK)&DAT_1403fe618);

  uVar1 = (ulonglong)_tls_index;

  DAT_1403e8ac0 = DAT_1403e8ac0 + 1;

  *param_1 = DAT_1403e8ac0;

  *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar1 * 8) + 4) = DAT_1403e8ac0;

  ReleaseSRWLockExclusive((PSRWLOCK)&DAT_1403fe618);

                    /* WARNING: Could not recover jumptable at 0x0001402c712e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  WakeAllConditionVariable((PCONDITION_VARIABLE)&DAT_1403fe610);

  return;

}




