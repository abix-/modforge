// Address: 0x1402f4348
// Ghidra name: update_thread_multibyte_data_internal
// ============ 0x1402f4348 update_thread_multibyte_data_internal (size=183) ============


/* Library Function - Single Match

    struct __crt_multibyte_data * __ptr64 __cdecl update_thread_multibyte_data_internal(struct

   __acrt_ptd * __ptr64 const,struct __crt_multibyte_data * __ptr64 * __ptr64 const)

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



__crt_multibyte_data * __cdecl

update_thread_multibyte_data_internal(__acrt_ptd *param_1,__crt_multibyte_data **param_2)



{

  int iVar1;

  __crt_multibyte_data *p_Var2;

  

  if (((*(uint *)(param_1 + 0x3a8) & DAT_1403e8ff0) == 0) || (*(longlong *)(param_1 + 0x90) == 0)) {

    __acrt_lock(5);

    p_Var2 = *(__crt_multibyte_data **)(param_1 + 0x88);

    if (p_Var2 != *param_2) {

      if (p_Var2 != (__crt_multibyte_data *)0x0) {

        LOCK();

        iVar1 = *(int *)p_Var2;

        *(int *)p_Var2 = *(int *)p_Var2 + -1;

        UNLOCK();

        if ((iVar1 == 1) && (p_Var2 != (__crt_multibyte_data *)&DAT_1403e91a0)) {

          FUN_1402e9a80();

        }

      }

      p_Var2 = *param_2;

      *(__crt_multibyte_data **)(param_1 + 0x88) = p_Var2;

      LOCK();

      *(int *)p_Var2 = *(int *)p_Var2 + 1;

      UNLOCK();

    }

    __acrt_unlock(5);

  }

  else {

    p_Var2 = *(__crt_multibyte_data **)(param_1 + 0x88);

  }

  if (p_Var2 != (__crt_multibyte_data *)0x0) {

    return p_Var2;

  }

                    /* WARNING: Subroutine does not return */

  FUN_1402e1bf8();

}




