// Address: 0x14022fb40
// Ghidra name: FUN_14022fb40
// ============ 0x14022fb40 FUN_14022fb40 (size=523) ============


longlong FUN_14022fb40(undefined4 *param_1,int param_2,undefined8 param_3,undefined8 param_4,

                      char *param_5,char *param_6,undefined8 param_7,undefined8 param_8,

                      undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12

                      )



{

  char *_Str;

  char *_Str_00;

  size_t sVar1;

  size_t sVar2;

  size_t sVar3;

  char *_Str_01;

  int iVar4;

  char *_Str_02;

  longlong lVar5;

  longlong lVar6;

  undefined4 local_48;

  undefined4 uStack_44;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  

  if (param_1 == (undefined4 *)0x0) {

    FUN_14012e850("Called convert_filters() with NULL filters (SDL bug)");

    return 0;

  }

  _Str = (char *)FUN_14012f0d0(param_4);

  if (_Str == (char *)0x0) {

    return 0;

  }

  if (0 < param_2) {

    lVar5 = 0;

    iVar4 = 1;

    _Str_01 = _Str;

    do {

      local_48 = *param_1;

      uStack_44 = param_1[1];

      uStack_40 = param_1[2];

      uStack_3c = param_1[3];

      _Str_00 = (char *)FUN_14022fa00(&local_48,param_3,param_7,param_8,param_9,param_10,param_11,

                                      param_12);

      if (_Str_00 == (char *)0x0) goto LAB_14022fd3f;

      _Str_02 = param_6;

      if (iVar4 < param_2) {

        _Str_02 = param_5;

      }

      sVar1 = strlen(_Str_02);

      sVar2 = strlen(_Str_00);

      sVar3 = strlen(_Str_01);

      lVar6 = sVar1 + sVar2 + sVar3 + 1;

      _Str = (char *)FUN_140184230(_Str_01,lVar6);

      if (_Str == (char *)0x0) {

        FUN_1401841e0(_Str_00);

        goto LAB_14022fd3f;

      }

      FUN_14012f120(_Str,_Str_00,lVar6);

      FUN_14012f120(_Str,_Str_02,lVar6);

      FUN_1401841e0(_Str_00);

      iVar4 = iVar4 + 1;

      lVar5 = lVar5 + 1;

      param_1 = param_1 + 4;

      _Str_01 = _Str;

    } while (lVar5 < param_2);

  }

  sVar1 = strlen(_Str);

  sVar2 = strlen(param_6);

  lVar5 = FUN_140184230(_Str,sVar1 + sVar2 + 1);

  _Str_01 = _Str;

  if (lVar5 == 0) {

LAB_14022fd3f:

    FUN_1401841e0(_Str_01);

    lVar5 = 0;

  }

  else {

    FUN_14012f120(lVar5,param_6,sVar1 + sVar2 + 1);

  }

  return lVar5;

}




