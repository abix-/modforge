// Address: 0x1401a4d10
// Ghidra name: FUN_1401a4d10
// ============ 0x1401a4d10 FUN_1401a4d10 (size=237) ============


void FUN_1401a4d10(longlong param_1,int param_2,int param_3,int param_4)



{

  ulonglong uVar1;

  longlong lVar2;

  longlong lVar3;

  ulonglong uVar4;

  longlong lVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  undefined1 local_828 [2048];

  

  uVar7 = (longlong)param_2 * (longlong)param_4;

  if (0 < param_3 >> 1) {

    lVar2 = (longlong)(param_3 + -1) * uVar7 + param_1;

    uVar6 = (ulonglong)(uint)(param_3 >> 1);

    uVar1 = uVar7;

    lVar5 = param_1;

    lVar3 = lVar2;

    do {

      for (; uVar1 != 0; uVar1 = uVar1 - uVar4) {

        uVar4 = 0x800;

        if (uVar1 < 0x800) {

          uVar4 = uVar1;

        }

        FUN_1402f8e20(local_828,param_1,uVar4);

        FUN_1402f8e20(param_1,lVar2,uVar4);

        FUN_1402f8e20(lVar2,local_828,uVar4);

        param_1 = param_1 + uVar4;

        lVar2 = lVar2 + uVar4;

      }

      param_1 = lVar5 + uVar7;

      lVar2 = lVar3 - uVar7;

      uVar6 = uVar6 - 1;

      uVar1 = uVar7;

      lVar5 = param_1;

      lVar3 = lVar2;

    } while (uVar6 != 0);

  }

  return;

}




