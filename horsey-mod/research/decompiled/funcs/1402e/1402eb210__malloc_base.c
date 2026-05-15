// Address: 0x1402eb210
// Ghidra name: _malloc_base
// ============ 0x1402eb210 _malloc_base (size=94) ============


/* Library Function - Single Match

    _malloc_base

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



LPVOID _malloc_base(ulonglong param_1)



{

  int iVar1;

  LPVOID pvVar2;

  undefined4 *puVar3;

  

  if (param_1 < 0xffffffffffffffe1) {

    if (param_1 == 0) {

      param_1 = 1;

    }

    do {

      pvVar2 = HeapAlloc(DAT_1403ff7a0,0,param_1);

      if (pvVar2 != (LPVOID)0x0) {

        return pvVar2;

      }

      iVar1 = FUN_1402e8130();

    } while ((iVar1 != 0) && (iVar1 = FUN_1402e6f60(param_1), iVar1 != 0));

  }

  puVar3 = (undefined4 *)FUN_1402e68b0();

  *puVar3 = 0xc;

  return (LPVOID)0x0;

}




