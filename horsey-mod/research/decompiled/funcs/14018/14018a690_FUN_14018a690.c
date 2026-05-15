// Address: 0x14018a690
// Ghidra name: FUN_14018a690
// ============ 0x14018a690 FUN_14018a690 (size=157) ============


undefined8 FUN_14018a690(void)



{

  int iVar1;

  char *_Str1;

  undefined8 uVar2;

  

  _Str1 = (char *)FUN_140142960("SDL_WAVE_TRUNCATION");

  if (_Str1 == (char *)0x0) {

    return 0;

  }

  iVar1 = strcmp(_Str1,"verystrict");

  if (iVar1 == 0) {

    return 1;

  }

  iVar1 = strcmp(_Str1,"strict");

  if (iVar1 == 0) {

    return 2;

  }

  iVar1 = strcmp(_Str1,"dropframe");

  if (iVar1 == 0) {

    return 3;

  }

  iVar1 = strcmp(_Str1,"dropblock");

  uVar2 = 0;

  if (iVar1 == 0) {

    uVar2 = 4;

  }

  return uVar2;

}




