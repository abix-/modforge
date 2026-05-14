// Address: 0x140206400
// Ghidra name: FUN_140206400
// ============ 0x140206400 FUN_140206400 (size=562) ============


undefined8

FUN_140206400(int *param_1,int *param_2,longlong param_3,int param_4,longlong param_5,int param_6,

             longlong param_7,int param_8)



{

  int iVar1;

  longlong lVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  

  iVar5 = param_1[3];

  iVar8 = 0;

  iVar1 = param_2[1];

  iVar6 = *param_2;

  iVar4 = param_2[2];

  iVar3 = param_2[3];

  iVar7 = 0;

  lVar2 = (longlong)(iVar5 * iVar1) + (longlong)iVar6 + *(longlong *)(param_1 + 6);

  if (0 < iVar3) {

    do {

      FUN_1402f8e20(lVar2,param_3,(longlong)iVar4);

      iVar5 = param_1[3];

      param_3 = param_3 + param_4;

      iVar3 = param_2[3];

      lVar2 = lVar2 + iVar5;

      iVar7 = iVar7 + 1;

    } while (iVar7 < iVar3);

    iVar6 = *param_2;

    iVar1 = param_2[1];

    iVar4 = param_2[2];

  }

  lVar2 = (longlong)(param_1[4] * iVar5);

  if (*param_1 != 0x56555949) {

    lVar2 = lVar2 + ((param_1[4] + 1) / 2) * ((iVar5 + 1) / 2);

  }

  lVar2 = (longlong)((iVar1 / 2) * ((iVar5 + 1) / 2) + iVar6 / 2) + *(longlong *)(param_1 + 6) +

          lVar2;

  iVar7 = 0;

  if (0 < (iVar3 + 1) / 2) {

    do {

      FUN_1402f8e20(lVar2,param_5,(longlong)((iVar4 + 1) / 2));

      iVar5 = param_1[3];

      param_5 = param_5 + param_6;

      iVar3 = param_2[3];

      iVar7 = iVar7 + 1;

      lVar2 = lVar2 + (iVar5 + 1) / 2;

    } while (iVar7 < (iVar3 + 1) / 2);

    iVar6 = *param_2;

    iVar1 = param_2[1];

    iVar4 = param_2[2];

  }

  lVar2 = (longlong)(param_1[4] * iVar5);

  if (*param_1 != 0x32315659) {

    lVar2 = lVar2 + ((param_1[4] + 1) / 2) * ((iVar5 + 1) / 2);

  }

  lVar2 = (longlong)(((iVar5 + 1) / 2) * (iVar1 / 2) + iVar6 / 2) + *(longlong *)(param_1 + 6) +

          lVar2;

  iVar1 = (iVar3 + 1) / 2;

  if (0 < iVar1) {

    do {

      FUN_1402f8e20(lVar2,param_7,(longlong)((iVar4 + 1) / 2));

      param_7 = param_7 + param_8;

      iVar8 = iVar8 + 1;

      lVar2 = lVar2 + (param_1[3] + 1) / 2;

      iVar1 = (param_2[3] + 1) / 2;

    } while (iVar8 < iVar1);

  }

  return CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1);

}




