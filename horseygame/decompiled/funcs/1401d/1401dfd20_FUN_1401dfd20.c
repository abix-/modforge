// Address: 0x1401dfd20
// Ghidra name: FUN_1401dfd20
// ============ 0x1401dfd20 FUN_1401dfd20 (size=407) ============


undefined1

FUN_1401dfd20(undefined8 param_1,undefined1 *param_2,int param_3,int param_4,int param_5,

             uint param_6,longlong param_7,int param_8)



{

  char cVar1;

  undefined1 uVar2;

  int iVar3;

  uint uVar4;

  ulonglong uVar5;

  longlong lVar6;

  bool bVar7;

  int local_38;

  int local_34;

  int local_30;

  int local_2c;

  int local_28 [2];

  longlong local_20;

  

  cVar1 = FUN_1401dcfe0();

  if (cVar1 == '\0') {

    return 0;

  }

  uVar5 = (ulonglong)param_6;

  local_30 = param_3 + param_5;

  local_2c = param_4 + param_6;

  local_38 = param_3;

  local_34 = param_4;

  iVar3 = (**(code **)(**(longlong **)(param_2 + 0x20) + 0x98))

                    (*(longlong **)(param_2 + 0x20),0,local_28,&local_38,0);

  if (iVar3 < 0) {

    uVar2 = FUN_1401df290("LockRect()",iVar3);

    return uVar2;

  }

  uVar4 = *(uint *)(param_2 + 0x10);

  if ((uVar4 == 0) || ((uVar4 & 0xf0000000) == 0x10000000)) {

    uVar4 = uVar4 & 0xff;

  }

  else if ((((uVar4 == 0x32595559) || (uVar4 == 0x59565955)) || (uVar4 == 0x55595659)) ||

          (uVar4 == 0x30313050)) {

    uVar4 = 2;

  }

  else {

    uVar4 = 1;

  }

  param_5 = uVar4 * param_5;

  if (param_5 == param_8) {

    iVar3 = param_5 - local_28[0];

    bVar7 = false;

    if (param_5 == local_28[0]) {

      FUN_1402f8e20(local_20,param_7,(longlong)param_5 * (longlong)(int)param_6);

      goto LAB_1401dfe77;

    }

  }

  else {

    if (param_8 <= param_5) {

      param_5 = param_8;

    }

    iVar3 = param_5 - local_28[0];

    bVar7 = param_5 == local_28[0];

  }

  if (!bVar7 && SBORROW4(param_5,local_28[0]) == iVar3 < 0) {

    param_5 = local_28[0];

  }

  if (0 < (int)param_6) {

    lVar6 = local_20;

    do {

      FUN_1402f8e20(lVar6,param_7,(longlong)param_5);

      param_7 = param_7 + param_8;

      lVar6 = lVar6 + local_28[0];

      uVar5 = uVar5 - 1;

    } while (uVar5 != 0);

  }

LAB_1401dfe77:

  iVar3 = (**(code **)(**(longlong **)(param_2 + 0x20) + 0xa0))(*(longlong **)(param_2 + 0x20),0);

  if (iVar3 < 0) {

    uVar2 = FUN_1401df290("UnlockRect()",iVar3);

  }

  else {

    *param_2 = 1;

    uVar2 = 1;

  }

  return uVar2;

}




