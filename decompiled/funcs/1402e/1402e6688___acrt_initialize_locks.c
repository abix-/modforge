// Address: 0x1402e6688
// Ghidra name: __acrt_initialize_locks
// ============ 0x1402e6688 __acrt_initialize_locks (size=72) ============


/* Library Function - Single Match

    __acrt_initialize_locks

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined4 __acrt_initialize_locks(void)



{

  BOOL BVar1;

  uint uVar2;

  ulonglong uVar3;

  

  uVar3 = 0;

  do {

    BVar1 = InitializeCriticalSectionEx((LPCRITICAL_SECTION)(&DAT_1403fed60 + uVar3 * 0x28),4000,0);

    if (BVar1 == 0) {

      __acrt_uninitialize_locks(0);

      return 0;

    }

    DAT_1403fefb8 = DAT_1403fefb8 + 1;

    uVar2 = (int)uVar3 + 1;

    uVar3 = (ulonglong)uVar2;

  } while (uVar2 < 0xf);

  return 1;

}




