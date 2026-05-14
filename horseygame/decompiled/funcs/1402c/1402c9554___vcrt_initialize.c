// Address: 0x1402c9554
// Ghidra name: __vcrt_initialize
// ============ 0x1402c9554 __vcrt_initialize (size=40) ============


/* Library Function - Single Match

    __vcrt_initialize

   

   Library: Visual Studio 2019 Release */



undefined1 __vcrt_initialize(void)



{

  char cVar1;

  

  cVar1 = __vcrt_initialize_locks();

  if (cVar1 != '\0') {

    cVar1 = __vcrt_initialize_ptd();

    if (cVar1 != '\0') {

      return 1;

    }

    __vcrt_uninitialize_locks();

  }

  return 0;

}




