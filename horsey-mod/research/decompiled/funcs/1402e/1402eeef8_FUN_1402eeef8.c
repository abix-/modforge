// Address: 0x1402eeef8
// Ghidra name: FUN_1402eeef8
// ============ 0x1402eeef8 FUN_1402eeef8 (size=53) ============


void FUN_1402eeef8(longlong param_1,longlong *param_2,longlong param_3)



{

  longlong lVar1;

  

  if ((*param_2 != (&DAT_1403ff150)[param_3]) && ((DAT_1403e8ff0 & *(uint *)(param_1 + 0x3a8)) == 0)

     ) {

    lVar1 = __acrt_update_thread_locale_data();

    *param_2 = lVar1;

  }

  return;

}




