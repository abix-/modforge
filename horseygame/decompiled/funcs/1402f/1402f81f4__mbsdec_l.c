// Address: 0x1402f81f4
// Ghidra name: _mbsdec_l
// ============ 0x1402f81f4 _mbsdec_l (size=148) ============


/* Library Function - Single Match

    _mbsdec_l

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



uchar * __cdecl _mbsdec_l(uchar *_Start,uchar *_Pos,_locale_t _Locale)



{

  undefined4 *puVar1;

  byte *pbVar2;

  longlong local_28 [2];

  longlong local_18;

  char local_10;

  

  if ((_Start == (uchar *)0x0) || (_Pos == (uchar *)0x0)) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 0x16;

    FUN_1402cd454();

  }

  else if (_Start < _Pos) {

    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_28,(__crt_locale_pointers *)_Locale);

    pbVar2 = _Pos + -1;

    if (*(int *)(local_18 + 8) != 0) {

      do {

        pbVar2 = pbVar2 + -1;

        if (pbVar2 < _Start) break;

      } while ((*(byte *)((ulonglong)*pbVar2 + 0x19 + local_18) & 4) != 0);

      pbVar2 = _Pos + (-1 - (ulonglong)((int)_Pos - (int)pbVar2 & 1));

    }

    if (local_10 == '\0') {

      return pbVar2;

    }

    *(uint *)(local_28[0] + 0x3a8) = *(uint *)(local_28[0] + 0x3a8) & 0xfffffffd;

    return pbVar2;

  }

  return (uchar *)0x0;

}




