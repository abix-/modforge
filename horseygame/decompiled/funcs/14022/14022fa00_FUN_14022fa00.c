// Address: 0x14022fa00
// Ghidra name: FUN_14022fa00
// ============ 0x14022fa00 FUN_14022fa00 (size=313) ============


longlong FUN_14022fa00(undefined8 *param_1,code *param_2,char *param_3,char *param_4,char *param_5,

                      undefined8 param_6,undefined8 param_7,undefined8 param_8)



{

  char *_Str;

  char *_Str_00;

  size_t sVar1;

  size_t sVar2;

  size_t sVar3;

  size_t sVar4;

  size_t sVar5;

  longlong lVar6;

  longlong lVar7;

  

  _Str = (char *)FUN_14022f850(param_1[1],param_6,param_7,param_8);

  if (_Str != (char *)0x0) {

    if (param_2 == (code *)0x0) {

      _Str_00 = (char *)FUN_14012f0d0(*param_1);

    }

    else {

      _Str_00 = (char *)(*param_2)();

    }

    if (_Str_00 != (char *)0x0) {

      sVar1 = strlen(_Str_00);

      sVar2 = strlen(_Str);

      sVar3 = strlen(param_3);

      sVar4 = strlen(param_4);

      sVar5 = strlen(param_5);

      lVar7 = sVar1 + sVar2 + sVar3 + sVar4 + sVar5;

      lVar6 = FUN_1401841f0(lVar7 + 1);

      if (lVar6 == 0) {

        FUN_1401841e0(_Str);

        FUN_1401841e0(_Str_00);

        return 0;

      }

      FUN_14012ef10(lVar6,lVar7 + 1,"%s%s%s%s%s",param_3,_Str_00,param_4,_Str,param_5);

      FUN_1401841e0(_Str);

      FUN_1401841e0(_Str_00);

      return lVar6;

    }

    FUN_1401841e0(_Str);

  }

  return 0;

}




