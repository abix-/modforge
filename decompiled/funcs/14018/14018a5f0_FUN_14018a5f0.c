// Address: 0x14018a5f0
// Ghidra name: FUN_14018a5f0
// ============ 0x14018a5f0 FUN_14018a5f0 (size=157) ============


undefined8 FUN_14018a5f0(void)



{

  int iVar1;

  char *_Str1;

  undefined8 uVar2;

  

  _Str1 = (char *)FUN_140142960("SDL_WAVE_RIFF_CHUNK_SIZE");

  if (_Str1 == (char *)0x0) {

    return 0;

  }

  iVar1 = strcmp(_Str1,"force");

  if (iVar1 == 0) {

    return 1;

  }

  iVar1 = strcmp(_Str1,"ignore");

  if (iVar1 == 0) {

    return 3;

  }

  iVar1 = strcmp(_Str1,"ignorezero");

  if (iVar1 == 0) {

    return 2;

  }

  iVar1 = strcmp(_Str1,"maximum");

  uVar2 = 0;

  if (iVar1 == 0) {

    uVar2 = 4;

  }

  return uVar2;

}




