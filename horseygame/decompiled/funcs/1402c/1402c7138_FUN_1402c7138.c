// Address: 0x1402c7138
// Ghidra name: FUN_1402c7138
// ============ 0x1402c7138 FUN_1402c7138 (size=123) ============


void FUN_1402c7138(int *param_1)



{

  AcquireSRWLockExclusive((PSRWLOCK)&DAT_1403fe618);

  do {

    if (*param_1 == 0) {

      *param_1 = -1;

LAB_1402c71a0:

                    /* WARNING: Could not recover jumptable at 0x0001402c71ac. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      ReleaseSRWLockExclusive((PSRWLOCK)&DAT_1403fe618);

      return;

    }

    if (*param_1 != -1) {

      *(undefined4 *)

       (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) =

           DAT_1403e8ac0;

      goto LAB_1402c71a0;

    }

    SleepConditionVariableSRW

              ((PCONDITION_VARIABLE)&DAT_1403fe610,(PSRWLOCK)&DAT_1403fe618,0xffffffff,0);

  } while( true );

}




