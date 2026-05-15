// Address: 0x1402cce34
// Ghidra name: __vcrt_FlsGetValue
// ============ 0x1402cce34 __vcrt_FlsGetValue (size=70) ============


/* Library Function - Single Match

    __vcrt_FlsGetValue

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __vcrt_FlsGetValue(undefined4 param_1)



{

  longlong lVar1;

  

  lVar1 = FUN_1402ccc4c(2,"FlsGetValue",&DAT_1403882e0,"FlsGetValue");

  if (lVar1 != 0) {

    (*(code *)PTR__guard_dispatch_icall_140302c68)();

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x0001402cce73. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  TlsGetValue(param_1);

  return;

}




