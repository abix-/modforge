// Address: 0x1402e7734
// Ghidra name: uninitialize_environment_internal<>
// ============ 0x1402e7734 uninitialize_environment_internal<> (size=26) ============


/* Library Function - Multiple Matches With Same Base Name

    void __cdecl uninitialize_environment_internal<char>(char * __ptr64 * __ptr64 & __ptr64)

    void __cdecl uninitialize_environment_internal<wchar_t>(wchar_t * __ptr64 * __ptr64 & __ptr64)

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



void uninitialize_environment_internal<>(longlong *param_1)



{

  if (*param_1 != DAT_1403ff0f0) {

    free_environment<>();

  }

  return;

}




