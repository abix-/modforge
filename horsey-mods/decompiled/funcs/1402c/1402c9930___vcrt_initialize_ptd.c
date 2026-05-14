// Address: 0x1402c9930
// Ghidra name: __vcrt_initialize_ptd
// ============ 0x1402c9930 __vcrt_initialize_ptd (size=71) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* Library Function - Single Match

    __vcrt_initialize_ptd

   

   Library: Visual Studio 2019 Release */



undefined4 __vcrt_initialize_ptd(void)



{

  int iVar1;

  

  DAT_1403e8b50 = __vcrt_FlsAlloc(FUN_1402c97d8);

  if (DAT_1403e8b50 != -1) {

    iVar1 = __vcrt_FlsSetValue(DAT_1403e8b50,&DAT_1403fec10);

    if (iVar1 != 0) {

      _DAT_1403fec88 = 0xfffffffe;

      return 1;

    }

    FUN_1402c9978();

  }

  return 0;

}




