// Address: 0x140216d80
// Ghidra name: FUN_140216d80
// ============ 0x140216d80 FUN_140216d80 (size=54) ============


char * FUN_140216d80(void)



{

  int iVar1;

  char *_Str1;

  char *pcVar2;

  

  _Str1 = (char *)FUN_14015e4b0();

  iVar1 = strncmp(_Str1,"SDL_AUDIO_",10);

  pcVar2 = _Str1 + 10;

  if (iVar1 != 0) {

    pcVar2 = _Str1;

  }

  return pcVar2;

}




