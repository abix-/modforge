// Address: 0x1402eeec4
// Ghidra name: __acrt_update_locale_info
// ============ 0x1402eeec4 __acrt_update_locale_info (size=49) ============


/* Library Function - Single Match

    __acrt_update_locale_info

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __acrt_update_locale_info(longlong param_1,longlong *param_2)



{

  longlong lVar1;

  

  if ((*param_2 != DAT_1403ff150) && ((DAT_1403e8ff0 & *(uint *)(param_1 + 0x3a8)) == 0)) {

    lVar1 = __acrt_update_thread_locale_data();

    *param_2 = lVar1;

  }

  return;

}




