// Address: 0x1402ccda4
// Ghidra name: __vcrt_FlsAlloc
// ============ 0x1402ccda4 __vcrt_FlsAlloc (size=69) ============


/* Library Function - Single Match

    __vcrt_FlsAlloc

   

   Library: Visual Studio 2019 Release */



void __vcrt_FlsAlloc(undefined8 param_1)



{

  longlong lVar1;

  

  lVar1 = FUN_1402ccc4c(0,"FlsAlloc",&DAT_1403882b8,"FlsAlloc");

  if (lVar1 != 0) {

    (*(code *)PTR__guard_dispatch_icall_140302c68)(param_1);

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x0001402ccde2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  TlsAlloc();

  return;

}




