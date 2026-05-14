// Address: 0x1402cce7c
// Ghidra name: __vcrt_FlsSetValue
// ============ 0x1402cce7c __vcrt_FlsSetValue (size=81) ============


/* Library Function - Single Match

    __vcrt_FlsSetValue

   

   Library: Visual Studio 2019 Release */



void __vcrt_FlsSetValue(DWORD param_1,LPVOID param_2)



{

  longlong lVar1;

  

  lVar1 = FUN_1402ccc4c(3,"FlsSetValue",&DAT_1403882f8,"FlsSetValue");

  if (lVar1 == 0) {

    TlsSetValue(param_1,param_2);

  }

  else {

    (*(code *)PTR__guard_dispatch_icall_140302c68)();

  }

  return;

}




