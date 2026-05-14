// Address: 0x140140640
// Ghidra name: FUN_140140640
// ============ 0x140140640 FUN_140140640 (size=206) ============


char * FUN_140140640(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  char *_Str;

  size_t sVar3;

  

  lVar2 = thunk_FUN_1402c9190(param_1,0x2c);

  if (lVar2 != 0) {

    _Str = (char *)FUN_1401841f0((lVar2 - param_1) + 1);

    if (_Str != (char *)0x0) {

      FUN_1402f8e20(_Str,param_1,lVar2 - param_1);

      _Str[lVar2 - param_1] = '\0';

      sVar3 = strlen(_Str);

      if (sVar3 != 0x20) {

        return _Str;

      }

      iVar1 = memcmp(_Str + 0x14,"504944564944",0xc);

      if (iVar1 != 0) {

        return _Str;

      }

      *(undefined8 *)(_Str + 0x14) = s_000000000000_140331a18._0_8_;

      *(undefined4 *)(_Str + 0x1c) = s_000000000000_140331a18._8_4_;

      *(undefined4 *)(_Str + 0x10) = *(undefined4 *)(_Str + 4);

      *(undefined4 *)(_Str + 8) = *(undefined4 *)_Str;

      _Str[0] = '0';

      _Str[1] = '3';

      _Str[2] = '0';

      _Str[3] = '0';

      _Str[4] = '0';

      _Str[5] = '0';

      _Str[6] = '0';

      _Str[7] = '0';

      return _Str;

    }

  }

  return (char *)0x0;

}




