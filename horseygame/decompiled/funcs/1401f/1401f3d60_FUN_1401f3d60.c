// Address: 0x1401f3d60
// Ghidra name: FUN_1401f3d60
// ============ 0x1401f3d60 FUN_1401f3d60 (size=337) ============


undefined8

FUN_1401f3d60(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,

             uint param_6,undefined4 param_7,undefined4 param_8,longlong param_9,int param_10,

             int param_11)



{

  longlong lVar1;

  ulonglong uVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  

  if (((param_5 != 0) && (uVar2 = (ulonglong)param_6, param_6 != 0)) && (param_11 != 0)) {

    lVar4 = (longlong)param_5 * (longlong)param_11;

    lVar1 = param_9;

    lVar5 = 0;

    if (param_10 != lVar4) {

      lVar1 = FUN_1401841f0((int)param_6 * lVar4);

      if (lVar1 == 0) {

        return 0;

      }

      lVar3 = lVar1;

      lVar5 = lVar1;

      if (0 < (int)param_6) {

        do {

          FUN_1402f8e20(lVar3,param_9,lVar4);

          param_9 = param_9 + param_10;

          uVar2 = uVar2 - 1;

          lVar3 = lVar3 + lVar4;

        } while (uVar2 != 0);

      }

    }

    (**(code **)(param_1 + 0x138))(param_2,0,param_3,param_4,param_5,param_6,param_7,param_8,lVar1);

    FUN_1401841e0(lVar5);

    return 1;

  }

  return 1;

}




