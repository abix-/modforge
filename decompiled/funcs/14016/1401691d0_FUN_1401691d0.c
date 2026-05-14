// Address: 0x1401691d0
// Ghidra name: FUN_1401691d0
// ============ 0x1401691d0 FUN_1401691d0 (size=257) ============


char * FUN_1401691d0(longlong param_1,size_t *param_2)



{

  char cVar1;

  longlong lVar2;

  char *_Str;

  size_t sVar3;

  size_t *psVar4;

  size_t local_res18;

  

  lVar2 = FUN_14016dcf0();

  if (lVar2 == 0) {

    FUN_1401730c0();

    return (char *)0x0;

  }

  if (param_1 != 0) {

    psVar4 = &local_res18;

    if (param_2 != (size_t *)0x0) {

      psVar4 = param_2;

    }

    *psVar4 = 0;

    if (*(code **)(lVar2 + 0x2b0) == (code *)0x0) {

      if ((*(longlong *)(lVar2 + 0x2c8) == 0) || (cVar1 = FUN_1401696e0(param_1), cVar1 == '\0')) {

        _Str = (char *)FUN_1401693d0(lVar2,param_1,psVar4);

      }

      else {

        _Str = (char *)(**(code **)(lVar2 + 0x2c8))(lVar2);

        if (_Str != (char *)0x0) {

          if (*_Str == '\0') {

            FUN_1401841e0();

            _Str = (char *)0x0;

          }

          else {

            sVar3 = strlen(_Str);

            *psVar4 = sVar3;

          }

        }

      }

    }

    else {

      _Str = (char *)(**(code **)(lVar2 + 0x2b0))(lVar2,param_1,psVar4);

    }

    return _Str;

  }

  FUN_14012e850("Parameter \'%s\' is invalid","mime_type");

  return (char *)0x0;

}




