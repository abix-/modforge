// Address: 0x1401d6200
// Ghidra name: FUN_1401d6200
// ============ 0x1401d6200 FUN_1401d6200 (size=361) ============


undefined8

FUN_1401d6200(int param_1,int param_2,longlong param_3,int param_4,longlong param_5,int param_6)



{

  longlong lVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  

  uVar2 = (param_2 + 1) / 2;

  uVar8 = (ulonglong)uVar2;

  param_3 = param_2 * param_4 + param_3;

  param_5 = param_5 + param_2 * param_6;

  iVar3 = (param_6 + 1) / 2;

  lVar6 = (longlong)((param_1 + 1) / 2);

  lVar5 = param_5 + (int)(iVar3 * uVar2);

  if (param_3 == param_5) {

    lVar5 = FUN_1401841f0(lVar6);

    if (lVar5 == 0) {

      return 0;

    }

    if (0 < (int)uVar2) {

      do {

        FUN_1402f8e20(lVar5,param_5,lVar6);

        lVar1 = param_5 + (int)(iVar3 * uVar2);

        FUN_1402f8e20(param_5,lVar1,lVar6);

        FUN_1402f8e20(lVar1,lVar5,lVar6);

        param_5 = param_5 + iVar3;

        uVar8 = uVar8 - 1;

      } while (uVar8 != 0);

    }

    FUN_1401841e0(lVar5);

  }

  else {

    iVar4 = (param_4 + 1) / 2;

    if (0 < (int)uVar2) {

      uVar7 = uVar8;

      do {

        FUN_1402f8e20(lVar5,param_3,lVar6);

        param_3 = param_3 + iVar4;

        lVar5 = lVar5 + iVar3;

        uVar7 = uVar7 - 1;

      } while (uVar7 != 0);

      do {

        FUN_1402f8e20(param_5,param_3,lVar6);

        param_3 = param_3 + iVar4;

        param_5 = param_5 + iVar3;

        uVar8 = uVar8 - 1;

      } while (uVar8 != 0);

    }

  }

  return 1;

}




