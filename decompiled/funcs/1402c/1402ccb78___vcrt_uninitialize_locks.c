// Address: 0x1402ccb78
// Ghidra name: __vcrt_uninitialize_locks
// ============ 0x1402ccb78 __vcrt_uninitialize_locks (size=55) ============


/* Library Function - Single Match

    __vcrt_uninitialize_locks

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release */



undefined8 __vcrt_uninitialize_locks(void)



{

  ulonglong uVar1;

  

  uVar1 = (ulonglong)DAT_1403fecc0;

  while ((int)uVar1 != 0) {

    uVar1 = (ulonglong)((int)uVar1 - 1);

    DeleteCriticalSection((LPCRITICAL_SECTION)(&DAT_1403fec98 + uVar1 * 0x28));

    DAT_1403fecc0 = DAT_1403fecc0 - 1;

  }

  return 1;

}




