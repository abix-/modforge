// Address: 0x1402e7eec
// Ghidra name: _set_fmode
// ============ 0x1402e7eec _set_fmode (size=61) ============


/* Library Function - Single Match

    _set_fmode

   

   Library: Visual Studio 2012 Release */



errno_t __cdecl _set_fmode(int _Mode)



{

  errno_t eVar1;

  undefined4 *puVar2;

  

  if (((_Mode - 0x4000U & 0xffff3fff) == 0) && (_Mode != 0xc000)) {

    LOCK();

    UNLOCK();

    eVar1 = 0;

    DAT_1403ff7a8 = _Mode;

  }

  else {

    puVar2 = (undefined4 *)FUN_1402e68b0();

    *puVar2 = 0x16;

    FUN_1402cd454();

    eVar1 = 0x16;

  }

  return eVar1;

}




