// Address: 0x1402c737c
// Ghidra name: __scrt_release_startup_lock
// ============ 0x1402c737c __scrt_release_startup_lock (size=36) ============


/* Library Function - Single Match

    __scrt_release_startup_lock

   

   Library: Visual Studio 2019 Release */



void __scrt_release_startup_lock(char param_1)



{

  int iVar1;

  

  iVar1 = __scrt_is_ucrt_dll_in_use();

  if ((iVar1 != 0) && (param_1 == '\0')) {

    LOCK();

    DAT_1403fe630 = 0;

    UNLOCK();

  }

  return;

}




