// Address: 0x1402e66ec
// Ghidra name: __acrt_uninitialize_locks
// ============ 0x1402e66ec __acrt_uninitialize_locks (size=55) ============


/* Library Function - Single Match

    __acrt_uninitialize_locks

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined8 __acrt_uninitialize_locks(void)



{

  ulonglong uVar1;

  

  uVar1 = (ulonglong)DAT_1403fefb8;

  while ((int)uVar1 != 0) {

    uVar1 = (ulonglong)((int)uVar1 - 1);

    DeleteCriticalSection((LPCRITICAL_SECTION)(&DAT_1403fed60 + uVar1 * 0x28));

    DAT_1403fefb8 = DAT_1403fefb8 - 1;

  }

  return 1;

}




