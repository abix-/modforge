// Address: 0x1402f5500
// Ghidra name: __acrt_locale_free_lc_time_if_unreferenced
// ============ 0x1402f5500 __acrt_locale_free_lc_time_if_unreferenced (size=55) ============


/* Library Function - Single Match

    __acrt_locale_free_lc_time_if_unreferenced

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



void __acrt_locale_free_lc_time_if_unreferenced(undefined **param_1)



{

  if (((param_1 != (undefined **)0x0) && (param_1 != &PTR_DAT_14038d1d0)) &&

     (*(int *)((longlong)param_1 + 0x15c) == 0)) {

    __acrt_locale_free_time();

    FUN_1402e9a80(param_1);

  }

  return;

}




