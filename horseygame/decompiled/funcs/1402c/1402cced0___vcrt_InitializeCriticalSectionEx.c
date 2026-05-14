// Address: 0x1402cced0
// Ghidra name: __vcrt_InitializeCriticalSectionEx
// ============ 0x1402cced0 __vcrt_InitializeCriticalSectionEx (size=97) ============


/* Library Function - Single Match

    __vcrt_InitializeCriticalSectionEx

   

   Library: Visual Studio 2017 Release */



void __vcrt_InitializeCriticalSectionEx(LPCRITICAL_SECTION param_1,DWORD param_2,undefined4 param_3)



{

  longlong lVar1;

  

  lVar1 = FUN_1402ccc4c(4,"InitializeCriticalSectionEx",&DAT_140388310,"InitializeCriticalSectionEx"

                       );

  if (lVar1 == 0) {

    InitializeCriticalSectionAndSpinCount(param_1,param_2);

  }

  else {

    (*(code *)PTR__guard_dispatch_icall_140302c68)(param_1,param_2,param_3);

  }

  return;

}




