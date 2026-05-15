// Address: 0x1402f5360
// Ghidra name: __acrt_free_locale
// ============ 0x1402f5360 __acrt_free_locale (size=374) ============


/* Library Function - Single Match

    __acrt_free_locale

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __acrt_free_locale(longlong param_1)



{

  longlong lVar1;

  undefined8 *puVar2;

  undefined8 *puVar3;

  

  if ((((*(undefined ***)(param_1 + 0xf8) != (undefined **)0x0) &&

       (*(undefined ***)(param_1 + 0xf8) != &PTR_DAT_1403e8c80)) &&

      (*(int **)(param_1 + 0xe0) != (int *)0x0)) && (**(int **)(param_1 + 0xe0) == 0)) {

    if ((*(int **)(param_1 + 0xf0) != (int *)0x0) && (**(int **)(param_1 + 0xf0) == 0)) {

      FUN_1402e9a80();

      __acrt_locale_free_monetary(*(undefined8 *)(param_1 + 0xf8));

    }

    if ((*(int **)(param_1 + 0xe8) != (int *)0x0) && (**(int **)(param_1 + 0xe8) == 0)) {

      FUN_1402e9a80();

      __acrt_locale_free_numeric(*(undefined8 *)(param_1 + 0xf8));

    }

    FUN_1402e9a80(*(undefined8 *)(param_1 + 0xe0));

    FUN_1402e9a80(*(undefined8 *)(param_1 + 0xf8));

  }

  if ((*(int **)(param_1 + 0x100) != (int *)0x0) && (**(int **)(param_1 + 0x100) == 0)) {

    FUN_1402e9a80(*(longlong *)(param_1 + 0x108) + -0xfe);

    FUN_1402e9a80(*(longlong *)(param_1 + 0x110) + -0x80);

    FUN_1402e9a80(*(longlong *)(param_1 + 0x118) + -0x80);

    FUN_1402e9a80(*(undefined8 *)(param_1 + 0x100));

  }

  __acrt_locale_free_lc_time_if_unreferenced(*(undefined8 *)(param_1 + 0x120));

  puVar2 = (undefined8 *)(param_1 + 0x128);

  lVar1 = 6;

  puVar3 = (undefined8 *)(param_1 + 0x38);

  do {

    if ((((undefined *)puVar3[-2] != &DAT_1403e8e98) && ((int *)*puVar3 != (int *)0x0)) &&

       (*(int *)*puVar3 == 0)) {

      FUN_1402e9a80();

      FUN_1402e9a80(*puVar2);

    }

    if (((puVar3[-3] != 0) && ((int *)puVar3[-1] != (int *)0x0)) && (*(int *)puVar3[-1] == 0)) {

      FUN_1402e9a80();

    }

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 4;

    lVar1 = lVar1 + -1;

  } while (lVar1 != 0);

  FUN_1402e9a80(param_1);

  return;

}




