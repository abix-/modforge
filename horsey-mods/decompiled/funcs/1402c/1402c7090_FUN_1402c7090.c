// Address: 0x1402c7090
// Ghidra name: FUN_1402c7090
// ============ 0x1402c7090 FUN_1402c7090 (size=60) ============


void FUN_1402c7090(undefined4 *param_1)



{

  AcquireSRWLockExclusive((PSRWLOCK)&DAT_1403fe618);

  *param_1 = 0;

  ReleaseSRWLockExclusive((PSRWLOCK)&DAT_1403fe618);

                    /* WARNING: Could not recover jumptable at 0x0001402c70c5. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  WakeAllConditionVariable((PCONDITION_VARIABLE)&DAT_1403fe610);

  return;

}




