// Address: 0x1402ccdec
// Ghidra name: __vcrt_FlsFree
// ============ 0x1402ccdec __vcrt_FlsFree (size=70) ============


/* Library Function - Single Match

    __vcrt_FlsFree

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __vcrt_FlsFree(DWORD param_1)



{

  longlong lVar1;

  

  lVar1 = FUN_1402ccc4c(1,"FlsFree",&DAT_1403882d0,"FlsFree");

  if (lVar1 != 0) {

    (*(code *)PTR__guard_dispatch_icall_140302c68)();

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x0001402cce2b. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  TlsFree(param_1);

  return;

}




