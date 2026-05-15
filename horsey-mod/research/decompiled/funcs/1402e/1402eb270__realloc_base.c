// Address: 0x1402eb270
// Ghidra name: _realloc_base
// ============ 0x1402eb270 _realloc_base (size=122) ============


/* Library Function - Single Match

    _realloc_base

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



LPVOID _realloc_base(LPVOID param_1,ulonglong param_2)



{

  int iVar1;

  LPVOID pvVar2;

  undefined4 *puVar3;

  

  if (param_1 == (LPVOID)0x0) {

    pvVar2 = (LPVOID)_malloc_base(param_2);

  }

  else {

    if (param_2 == 0) {

      FUN_1402e9a80();

    }

    else {

      if (param_2 < 0xffffffffffffffe1) {

        do {

          pvVar2 = HeapReAlloc(DAT_1403ff7a0,0,param_1,param_2);

          if (pvVar2 != (LPVOID)0x0) {

            return pvVar2;

          }

          iVar1 = FUN_1402e8130();

        } while ((iVar1 != 0) && (iVar1 = FUN_1402e6f60(param_2), iVar1 != 0));

      }

      puVar3 = (undefined4 *)FUN_1402e68b0();

      *puVar3 = 0xc;

    }

    pvVar2 = (LPVOID)0x0;

  }

  return pvVar2;

}




