// Address: 0x1402e76f0
// Ghidra name: free_environment<>
// ============ 0x1402e76f0 free_environment<> (size=65) ============


/* Library Function - Multiple Matches With Same Base Name

    void __cdecl free_environment<char>(char * __ptr64 * __ptr64 const)

    void __cdecl free_environment<wchar_t>(wchar_t * __ptr64 * __ptr64 const)

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



void free_environment<>(longlong *param_1)



{

  longlong lVar1;

  longlong *plVar2;

  

  if (param_1 != (longlong *)0x0) {

    lVar1 = *param_1;

    plVar2 = param_1;

    while (lVar1 != 0) {

      FUN_1402e9a80(lVar1);

      plVar2 = plVar2 + 1;

      lVar1 = *plVar2;

    }

    FUN_1402e9a80(param_1);

  }

  return;

}




