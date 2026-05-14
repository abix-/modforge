// Address: 0x140142bb0
// Ghidra name: FUN_140142bb0
// ============ 0x140142bb0 FUN_140142bb0 (size=269) ============


ulonglong FUN_140142bb0(char *param_1)



{

  char *_Str2;

  undefined8 *puVar1;

  undefined8 *puVar2;

  int iVar3;

  char *_Str1;

  ulonglong uVar4;

  undefined8 *puVar5;

  ulonglong uVar6;

  

  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140304430);

    return uVar4;

  }

  _Str1 = (char *)FUN_140142630();

  uVar4 = FUN_1401426c0(0);

  if ((int)uVar4 == 0) {

    return uVar4;

  }

  uVar6 = 0;

  FUN_140175050(uVar4 & 0xffffffff);

  puVar5 = (undefined8 *)FUN_140174d30(uVar4 & 0xffffffff,param_1,0);

  if (puVar5 == (undefined8 *)0x0) goto LAB_140142c80;

  _Str2 = (char *)*puVar5;

  if (_Str1 == (char *)0x0) {

    if (_Str2 != (char *)0x0) {

LAB_140142c45:

      puVar2 = (undefined8 *)puVar5[2];

      while (puVar2 != (undefined8 *)0x0) {

        puVar1 = (undefined8 *)puVar2[2];

        (*(code *)*puVar2)(puVar2[1],param_1,*puVar5,_Str1);

        puVar2 = puVar1;

      }

    }

  }

  else if ((_Str2 == (char *)0x0) || (iVar3 = strcmp(_Str1,_Str2), iVar3 != 0)) goto LAB_140142c45;

  FUN_1401841e0(*puVar5);

  uVar6 = 1;

  *puVar5 = 0;

  *(undefined4 *)(puVar5 + 1) = 0;

LAB_140142c80:

  FUN_1401755c0(uVar4 & 0xffffffff);

  return uVar6;

}




