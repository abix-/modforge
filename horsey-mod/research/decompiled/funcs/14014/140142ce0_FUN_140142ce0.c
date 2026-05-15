// Address: 0x140142ce0
// Ghidra name: FUN_140142ce0
// ============ 0x140142ce0 FUN_140142ce0 (size=429) ============


ulonglong FUN_140142ce0(char *param_1,char *param_2,int param_3)



{

  char *_Str1;

  undefined8 *puVar1;

  undefined8 *puVar2;

  byte bVar3;

  int iVar4;

  longlong lVar5;

  ulonglong uVar6;

  undefined8 *puVar7;

  undefined8 uVar8;

  undefined8 uVar9;

  ulonglong uVar10;

  

  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

    uVar6 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140304430);

    return uVar6;

  }

  lVar5 = FUN_140142630();

  if ((lVar5 != 0) && (param_3 < 2)) {

    uVar6 = FUN_14012e850("An environment variable is taking priority");

    return uVar6;

  }

  uVar6 = FUN_1401426c0(1);

  if ((int)uVar6 == 0) {

    return uVar6;

  }

  uVar10 = 0;

  FUN_140175050(uVar6 & 0xffffffff);

  puVar7 = (undefined8 *)FUN_140174d30(uVar6 & 0xffffffff,param_1,0);

  if (puVar7 == (undefined8 *)0x0) {

    puVar7 = (undefined8 *)FUN_1401841f0(0x18);

    if (puVar7 != (undefined8 *)0x0) {

      uVar9 = 0;

      if (param_2 != (char *)0x0) {

        uVar9 = FUN_14012f0d0(param_2);

      }

      *puVar7 = uVar9;

      *(int *)(puVar7 + 1) = param_3;

      puVar7[2] = 0;

      bVar3 = FUN_1401753d0(uVar6 & 0xffffffff,param_1,puVar7,FUN_1401425e0,0);

      uVar10 = (ulonglong)bVar3;

    }

  }

  else if (*(int *)(puVar7 + 1) <= param_3) {

    _Str1 = (char *)*puVar7;

    if ((_Str1 != param_2) &&

       (((param_2 == (char *)0x0 || (_Str1 == (char *)0x0)) ||

        (iVar4 = strcmp(_Str1,param_2), iVar4 != 0)))) {

      uVar9 = *puVar7;

      if (param_2 == (char *)0x0) {

        uVar8 = 0;

      }

      else {

        uVar8 = FUN_14012f0d0(param_2);

      }

      *puVar7 = uVar8;

      puVar2 = (undefined8 *)puVar7[2];

      while (puVar2 != (undefined8 *)0x0) {

        puVar1 = (undefined8 *)puVar2[2];

        (*(code *)*puVar2)(puVar2[1],param_1,uVar9,param_2);

        puVar2 = puVar1;

      }

      FUN_1401841e0(uVar9);

    }

    *(int *)(puVar7 + 1) = param_3;

    uVar10 = 1;

  }

  FUN_1401755c0(uVar6 & 0xffffffff);

  return uVar10;

}




