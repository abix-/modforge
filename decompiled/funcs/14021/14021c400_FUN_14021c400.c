// Address: 0x14021c400
// Ghidra name: FUN_14021c400
// ============ 0x14021c400 FUN_14021c400 (size=149) ============


undefined4 FUN_14021c400(longlong *param_1,longlong param_2,undefined8 param_3)



{

  undefined4 uVar1;

  size_t sVar2;

  char *_Str;

  char *pcVar3;

  

  _Str = (char *)(param_2 + *param_1);

  sVar2 = strlen(_Str);

  pcVar3 = (char *)0x0;

  if ((sVar2 != 0) && (_Str[sVar2 - 1] == '\\')) {

    _Str = (char *)FUN_14012f0d0(_Str);

    if (_Str == (char *)0x0) {

      return 2;

    }

    _Str[sVar2 - 1] = '/';

    pcVar3 = _Str;

  }

  uVar1 = (*(code *)param_1[1])(param_1[2],_Str,param_3);

  FUN_1401841e0(pcVar3);

  return uVar1;

}




