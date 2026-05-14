// Address: 0x1402e61a8
// Ghidra name: get_global_action_nolock
// ============ 0x1402e61a8 get_global_action_nolock (size=60) ============


/* Library Function - Single Match

    void (__cdecl** __ptr64 __cdecl get_global_action_nolock(int))(int)

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



_func_void_int ** __cdecl get_global_action_nolock(int param_1)



{

  if (param_1 == 2) {

    return (_func_void_int **)&DAT_1403fed40;

  }

  if (param_1 != 6) {

    if (param_1 == 0xf) {

      return (_func_void_int **)&DAT_1403fed58;

    }

    if (param_1 == 0x15) {

      return (_func_void_int **)&DAT_1403fed48;

    }

    if (param_1 != 0x16) {

      return (_func_void_int **)0x0;

    }

  }

  return (_func_void_int **)&DAT_1403fed50;

}




