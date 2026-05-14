// Address: 0x14022e620
// Ghidra name: FUN_14022e620
// ============ 0x14022e620 FUN_14022e620 (size=288) ============


LPWSTR FUN_14022e620(longlong param_1,undefined8 param_2)



{

  char *pcVar1;

  char cVar2;

  int cchWideChar;

  char *_Str;

  size_t sVar3;

  char *pcVar4;

  LPWSTR lpWideCharStr;

  

  if ((param_1 != 0) &&

     (_Str = (char *)FUN_14022fb40(param_1,param_2,FUN_14022e550,&DAT_14039bcb9,&DAT_14039bcb9,

                                   &DAT_140357e70,&DAT_14039bcb9,&DAT_140357e6c,&DAT_140357e6c,

                                   &DAT_140357e68,&DAT_140357e64,&DAT_14039bcb9),

     _Str != (char *)0x0)) {

    sVar3 = strlen(_Str);

    cVar2 = *_Str;

    pcVar4 = _Str;

    while (cVar2 != '\0') {

      if (cVar2 == '\x01') {

        *pcVar4 = '\0';

      }

      pcVar1 = pcVar4 + 1;

      pcVar4 = pcVar4 + 1;

      cVar2 = *pcVar1;

    }

    cchWideChar = MultiByteToWideChar(0xfde9,0,_Str,(int)sVar3,(LPWSTR)0x0,0);

    lpWideCharStr = (LPWSTR)FUN_1401841f0((longlong)cchWideChar * 2);

    if (lpWideCharStr != (LPWSTR)0x0) {

      MultiByteToWideChar(0xfde9,0,_Str,(int)sVar3,lpWideCharStr,cchWideChar);

      FUN_1401841e0(_Str);

      return lpWideCharStr;

    }

    FUN_1401841e0(_Str);

  }

  return (LPWSTR)0x0;

}




