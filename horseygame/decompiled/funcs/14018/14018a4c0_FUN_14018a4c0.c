// Address: 0x14018a4c0
// Ghidra name: FUN_14018a4c0
// ============ 0x14018a4c0 FUN_14018a4c0 (size=157) ============


undefined8 FUN_14018a4c0(void)



{

  int iVar1;

  char *_Str1;

  undefined8 uVar2;

  

  _Str1 = (char *)FUN_140142960("SDL_WAVE_FACT_CHUNK");

  if (_Str1 == (char *)0x0) {

    return 0;

  }

  iVar1 = strcmp(_Str1,"truncate");

  if (iVar1 == 0) {

    return 1;

  }

  iVar1 = strcmp(_Str1,"strict");

  if (iVar1 == 0) {

    return 2;

  }

  iVar1 = strcmp(_Str1,"ignorezero");

  if (iVar1 == 0) {

    return 3;

  }

  iVar1 = strcmp(_Str1,"ignore");

  uVar2 = 0;

  if (iVar1 == 0) {

    uVar2 = 4;

  }

  return uVar2;

}




