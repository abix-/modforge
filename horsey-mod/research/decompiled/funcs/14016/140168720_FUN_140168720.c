// Address: 0x140168720
// Ghidra name: FUN_140168720
// ============ 0x140168720 FUN_140168720 (size=287) ============


ulonglong FUN_140168720(undefined8 *param_1,longlong param_2,longlong *param_3,void *param_4,

                       int param_5)



{

  byte bVar1;

  char cVar2;

  int iVar3;

  ulonglong uVar4;

  longlong lVar5;

  void *pvVar6;

  bool bVar7;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar4;

  }

  bVar1 = 1;

  FUN_140179b40(*param_1);

  if (param_5 != *(int *)(param_2 + 4)) {

    bVar1 = FUN_14012e850("Wrong number of channels");

    goto LAB_14016881a;

  }

  if ((void *)*param_3 == (void *)0x0) {

    bVar7 = param_4 == (void *)0x0;

LAB_1401687b7:

    if (bVar7) goto LAB_14016881a;

  }

  else if (param_4 != (void *)0x0) {

    iVar3 = memcmp((void *)*param_3,param_4,(longlong)param_5 << 2);

    bVar7 = iVar3 == 0;

    goto LAB_1401687b7;

  }

  cVar2 = FUN_140165060(param_4,param_5);

  if (cVar2 == '\0') {

    cVar2 = FUN_140165090(param_4,param_5);

    pvVar6 = (void *)0x0;

    if (cVar2 == '\0') {

      pvVar6 = param_4;

    }

    if (pvVar6 == (void *)0x0) {

      FUN_1401841e0(*param_3);

      *param_3 = 0;

      goto LAB_14016881a;

    }

    lVar5 = FUN_14015dd70(pvVar6,param_5);

    if (lVar5 != 0) {

      FUN_1401841e0(*param_3);

      *param_3 = lVar5;

      goto LAB_14016881a;

    }

  }

  bVar1 = FUN_14012e850("Invalid channel mapping");

LAB_14016881a:

  FUN_140179b60(*param_1);

  return (ulonglong)bVar1;

}




