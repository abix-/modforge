// Address: 0x1402ea15c
// Ghidra name: __acrt_initialize_lowio
// ============ 0x1402ea15c __acrt_initialize_lowio (size=59) ============


/* Library Function - Single Match

    __acrt_initialize_lowio

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



bool __acrt_initialize_lowio(void)



{

  int iVar1;

  

  __acrt_lock(7);

  iVar1 = __acrt_lowio_ensure_fh_exists(0);

  if (iVar1 == 0) {

    FUN_1402e9f54();

    FUN_1402ea054();

  }

  __acrt_unlock(7);

  return iVar1 == 0;

}




