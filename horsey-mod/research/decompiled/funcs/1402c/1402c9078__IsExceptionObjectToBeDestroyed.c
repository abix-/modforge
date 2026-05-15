// Address: 0x1402c9078
// Ghidra name: _IsExceptionObjectToBeDestroyed
// ============ 0x1402c9078 _IsExceptionObjectToBeDestroyed (size=47) ============


/* Library Function - Single Match

    _IsExceptionObjectToBeDestroyed

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined4 _IsExceptionObjectToBeDestroyed(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  

  lVar1 = FUN_1402c97f8();

  plVar2 = *(longlong **)(lVar1 + 0x58);

  while( true ) {

    if (plVar2 == (longlong *)0x0) {

      return 1;

    }

    if (*plVar2 == param_1) break;

    plVar2 = (longlong *)plVar2[1];

  }

  return 0;

}




