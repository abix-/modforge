// Address: 0x140241090
// Ghidra name: FUN_140241090
// ============ 0x140241090 FUN_140241090 (size=125) ============


int FUN_140241090(void)



{

  int iVar1;

  char *_Str1;

  

  _Str1 = (char *)FUN_140142960("SDL_RENDER_OPENGLES2_TEXCOORD_PRECISION");

  if (_Str1 == (char *)0x0) {

    return 1;

  }

  iVar1 = strcmp(_Str1,"undefined");

  if (iVar1 == 0) {

    return 4;

  }

  iVar1 = strcmp(_Str1,"high");

  if (iVar1 == 0) {

    return 3;

  }

  iVar1 = strcmp(_Str1,"medium");

  return 2 - (uint)(iVar1 != 0);

}




