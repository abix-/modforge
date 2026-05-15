// Address: 0x1402f5608
// Ghidra name: __acrt_update_thread_locale_data
// ============ 0x1402f5608 __acrt_update_thread_locale_data (size=109) ============


/* Library Function - Single Match

    __acrt_update_thread_locale_data

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



longlong __acrt_update_thread_locale_data(void)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = FUN_1402e8664();

  if (((DAT_1403e8ff0 & *(uint *)(lVar1 + 0x3a8)) == 0) ||

     (lVar2 = *(longlong *)(lVar1 + 0x90), lVar2 == 0)) {

    __acrt_lock(4);

    lVar2 = _updatetlocinfoEx_nolock((longlong *)(lVar1 + 0x90),DAT_1403ff150);

    __acrt_unlock(4);

    if (lVar2 == 0) {

                    /* WARNING: Subroutine does not return */

      FUN_1402e1bf8();

    }

  }

  return lVar2;

}




