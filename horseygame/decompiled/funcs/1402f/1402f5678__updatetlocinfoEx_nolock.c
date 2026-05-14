// Address: 0x1402f5678
// Ghidra name: _updatetlocinfoEx_nolock
// ============ 0x1402f5678 _updatetlocinfoEx_nolock (size=101) ============


/* Library Function - Single Match

    _updatetlocinfoEx_nolock

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined ** _updatetlocinfoEx_nolock(longlong *param_1,undefined **param_2)



{

  undefined **ppuVar1;

  

  if ((param_2 == (undefined **)0x0) || (param_1 == (longlong *)0x0)) {

    param_2 = (undefined **)0x0;

  }

  else {

    ppuVar1 = (undefined **)*param_1;

    if (ppuVar1 != param_2) {

      *param_1 = (longlong)param_2;

      __acrt_add_locale_ref(param_2);

      if (((ppuVar1 != (undefined **)0x0) &&

          (__acrt_release_locale_ref(ppuVar1), *(int *)(ppuVar1 + 2) == 0)) &&

         (ppuVar1 != &PTR_DAT_1403e8d30)) {

        __acrt_free_locale(ppuVar1);

      }

    }

  }

  return param_2;

}




