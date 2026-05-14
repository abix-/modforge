// Address: 0x1402f82a0
// Ghidra name: _msize_base
// ============ 0x1402f82a0 _msize_base (size=57) ============


/* Library Function - Single Match

    _msize_base

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined8 _msize_base(longlong param_1)



{

  undefined4 *puVar1;

  undefined8 uVar2;

  

  if (param_1 == 0) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 0x16;

    FUN_1402cd454();

    return 0xffffffffffffffff;

  }

                    /* WARNING: Could not recover jumptable at 0x0001402f82d2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar2 = HeapSize(DAT_1403ff7a0,0,param_1);

  return uVar2;

}




