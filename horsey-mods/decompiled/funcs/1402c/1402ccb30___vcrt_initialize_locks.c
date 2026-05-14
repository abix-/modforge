// Address: 0x1402ccb30
// Ghidra name: __vcrt_initialize_locks
// ============ 0x1402ccb30 __vcrt_initialize_locks (size=70) ============


/* Library Function - Single Match

    __vcrt_initialize_locks

   

   Library: Visual Studio 2017 Release */



undefined4 __vcrt_initialize_locks(void)



{

  int iVar1;

  uint uVar2;

  ulonglong uVar3;

  

  uVar3 = 0;

  do {

    iVar1 = __vcrt_InitializeCriticalSectionEx(&DAT_1403fec98 + uVar3 * 0x28,4000,0);

    if (iVar1 == 0) {

      __vcrt_uninitialize_locks();

      return 0;

    }

    DAT_1403fecc0 = DAT_1403fecc0 + 1;

    uVar2 = (int)uVar3 + 1;

    uVar3 = (ulonglong)uVar2;

  } while (uVar2 == 0);

  return 1;

}




