// Address: 0x1402c6d5c
// Ghidra name: _Init_locks
// ============ 0x1402c6d5c _Init_locks (size=67) ============


/* Library Function - Single Match

    public: __cdecl std::_Init_locks::_Init_locks(void) __ptr64

   

   Library: Visual Studio 2019 Release */



_Init_locks * __thiscall std::_Init_locks::_Init_locks(_Init_locks *this)



{

  undefined *puVar1;

  

  LOCK();

  DAT_1403e8ab0 = DAT_1403e8ab0 + 1;

  UNLOCK();

  if (DAT_1403e8ab0 == 0) {

    puVar1 = &DAT_1403fe2b0;

    do {

      FUN_1402c6fc8(puVar1);

      puVar1 = puVar1 + 0x28;

    } while (puVar1 != &DAT_1403fe3f0);

  }

  return this;

}




