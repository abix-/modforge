// Address: 0x1401dd9b0
// Ghidra name: FUN_1401dd9b0
// ============ 0x1401dd9b0 FUN_1401dd9b0 (size=413) ============


undefined8

FUN_1401dd9b0(longlong param_1,uint *param_2,int *param_3,longlong *param_4,undefined4 *param_5)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  char cVar4;

  int iVar5;

  undefined8 uVar6;

  longlong lVar7;

  uint uVar8;

  int local_28;

  int local_24;

  int local_20;

  int local_1c;

  undefined4 local_18 [2];

  longlong local_10;

  

  lVar1 = *(longlong *)(param_2 + 0x4e);

  uVar6 = *(undefined8 *)(*(longlong *)(param_1 + 0x2e0) + 0x10);

  if (lVar1 == 0) {

    uVar6 = FUN_14012e850("Texture is not currently available");

    return uVar6;

  }

  iVar5 = param_3[1];

  iVar2 = param_3[2];

  iVar3 = param_3[3];

  *(int *)(lVar1 + 0xac) = *param_3;

  *(int *)(lVar1 + 0xb0) = iVar5;

  *(int *)(lVar1 + 0xb4) = iVar2;

  *(int *)(lVar1 + 0xb8) = iVar3;

  if (*(char *)(lVar1 + 0x48) == '\0') {

    cVar4 = FUN_1401dcfe0(uVar6,lVar1);

    if (cVar4 == '\0') {

      return 0;

    }

    local_28 = *param_3;

    local_20 = local_28 + param_3[2];

    local_24 = param_3[1];

    local_1c = local_24 + param_3[3];

    iVar5 = (**(code **)(**(longlong **)(lVar1 + 0x20) + 0x98))

                      (*(longlong **)(lVar1 + 0x20),0,local_18,&local_28,0);

    if (iVar5 < 0) {

      uVar6 = FUN_1401df290("LockRect()",iVar5);

      return uVar6;

    }

    *param_4 = local_10;

    *param_5 = local_18[0];

  }

  else {

    lVar7 = *(longlong *)(lVar1 + 0xa0);

    if (lVar7 == 0) {

      uVar8 = param_2[1];

      *(uint *)(lVar1 + 0xa8) = uVar8;

      lVar7 = FUN_1401841f0((longlong)((int)(uVar8 * param_2[2] * 3) / 2));

      *(longlong *)(lVar1 + 0xa0) = lVar7;

      if (lVar7 == 0) {

        return 0;

      }

    }

    uVar8 = *param_2;

    if ((uVar8 == 0) || ((uVar8 & 0xf0000000) == 0x10000000)) {

      uVar8 = uVar8 & 0xff;

    }

    else if ((((uVar8 == 0x32595559) || (uVar8 == 0x59565955)) || (uVar8 == 0x55595659)) ||

            (uVar8 == 0x30313050)) {

      uVar8 = 2;

    }

    else {

      uVar8 = 1;

    }

    *param_4 = (longlong)(int)(uVar8 * *param_3) + param_3[1] * *(int *)(lVar1 + 0xa8) + lVar7;

    *param_5 = *(undefined4 *)(lVar1 + 0xa8);

  }

  return 1;

}




