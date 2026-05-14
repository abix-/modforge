// Address: 0x1400378f0
// Ghidra name: FUN_1400378f0
// ============ 0x1400378f0 FUN_1400378f0 (size=179) ============


int FUN_1400378f0(undefined8 *param_1)



{

  ulonglong uVar1;

  size_t _Size;

  char *_Str;

  int iVar2;

  size_t sVar3;

  undefined8 *_Buf1;

  undefined **ppuVar4;

  int iVar5;

  

  uVar1 = param_1[3];

  ppuVar4 = &PTR_DAT_1403d41e0;

  _Size = param_1[2];

  iVar5 = 0;

  while( true ) {

    _Str = *ppuVar4;

    sVar3 = strlen(_Str);

    _Buf1 = param_1;

    if (0xf < uVar1) {

      _Buf1 = (undefined8 *)*param_1;

    }

    if ((_Size == sVar3) && ((_Size == 0 || (iVar2 = memcmp(_Buf1,_Str,_Size), iVar2 == 0)))) break;

    iVar5 = iVar5 + 1;

    ppuVar4 = ppuVar4 + 2;

    if (0x1403d437f < (longlong)ppuVar4) {

      FUN_140027900(param_1);

      return -1;

    }

  }

  FUN_140027900(param_1);

  return iVar5;

}




