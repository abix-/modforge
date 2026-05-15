// Address: 0x140178950
// Ghidra name: FUN_140178950
// ============ 0x140178950 FUN_140178950 (size=258) ============


ulonglong FUN_140178950(char *param_1)



{

  char *pcVar1;

  char cVar2;

  byte bVar3;

  char cVar4;

  ulonglong uVar5;

  char *_Str;

  size_t sVar6;

  char *pcVar7;

  

  if (param_1 == (char *)0x0) {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140335b8c);

    return uVar5;

  }

  bVar3 = FUN_14021cde0();

  if ((bVar3 != 0) || (*param_1 == '\0')) goto LAB_140178a3f;

  _Str = (char *)FUN_14012f0d0(param_1);

  if (_Str == (char *)0x0) {

    return 0;

  }

  sVar6 = strlen(_Str);

  if ((_Str[sVar6 - 1] == '/') || (_Str[sVar6 - 1] == '\\')) {

    _Str[sVar6 - 1] = '\0';

    bVar3 = FUN_14021cde0(_Str);

    if (bVar3 == 0) goto LAB_1401789e4;

  }

  else {

LAB_1401789e4:

    cVar2 = *_Str;

    pcVar7 = _Str;

    while (cVar2 != '\0') {

      if (((cVar2 == '/') || (cVar2 == '\\')) &&

         (((longlong)pcVar7 - (longlong)_Str != 2 || (_Str[1] != ':')))) {

        *pcVar7 = '\0';

        cVar4 = FUN_14021cde0(_Str);

        if (cVar4 == '\0') break;

        *pcVar7 = cVar2;

      }

      pcVar1 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

      cVar2 = *pcVar1;

    }

    bVar3 = FUN_14021cde0(_Str);

  }

  FUN_1401841e0(_Str);

LAB_140178a3f:

  return (ulonglong)bVar3;

}




