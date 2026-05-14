// Address: 0x1401814d0
// Ghidra name: FUN_1401814d0
// ============ 0x1401814d0 FUN_1401814d0 (size=186) ============


void FUN_1401814d0(undefined8 param_1)



{

  int iVar1;

  char *_Str1;

  

  _Str1 = (char *)FUN_140142960("SDL_WINDOWS_DPI_AWARENESS");

  if ((_Str1 == (char *)0x0) || (iVar1 = strcmp(_Str1,"permonitorv2"), iVar1 == 0)) {

    FUN_140181290(param_1);

    return;

  }

  iVar1 = strcmp(_Str1,"permonitor");

  if (iVar1 == 0) {

    FUN_140181240(param_1);

    return;

  }

  iVar1 = strcmp(_Str1,"system");

  if (iVar1 != 0) {

    iVar1 = strcmp(_Str1,"unaware");

    if (iVar1 != 0) {

      return;

    }

    FUN_140181340(param_1);

    return;

  }

  FUN_1401812e0(param_1);

  return;

}




