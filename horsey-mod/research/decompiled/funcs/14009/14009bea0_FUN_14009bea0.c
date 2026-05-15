// Address: 0x14009bea0
// Ghidra name: FUN_14009bea0
// ============ 0x14009bea0 FUN_14009bea0 (size=543) ============


void FUN_14009bea0(ulonglong *param_1,ulonglong param_2,longlong *param_3)



{

  longlong *plVar1;

  longlong *plVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  longlong lVar5;

  longlong *plVar6;

  ulonglong uVar7;

  

  plVar2 = (longlong *)*param_1;

  uVar7 = (longlong)(param_1[2] - (longlong)plVar2) >> 3;

  if (uVar7 < param_2) {

    if (0x1fffffffffffffff < param_2) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    if (0x1fffffffffffffff - (uVar7 >> 1) < uVar7) {

      uVar7 = 0x1fffffffffffffff;

    }

    else {

      uVar7 = uVar7 + (uVar7 >> 1);

      if (uVar7 < param_2) {

        uVar7 = param_2;

      }

    }

    if (plVar2 != (longlong *)0x0) {

      FUN_14009c330(param_1,plVar2);

      *param_1 = 0;

      param_1[1] = 0;

      param_1[2] = 0;

    }

    if (0x1fffffffffffffff < uVar7) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

    plVar2 = (longlong *)FUN_1400285e0(uVar7 * 8);

    *param_1 = (ulonglong)plVar2;

    param_1[1] = (ulonglong)plVar2;

    param_1[2] = (ulonglong)(plVar2 + uVar7);

    if (*param_3 == 0) {

      FUN_1402f94c0(plVar2,0,param_2 * 8);

      param_1[1] = (ulonglong)(plVar2 + param_2);

      return;

    }

    if (param_2 != 0) {

      do {

        *plVar2 = *param_3;

        plVar2 = plVar2 + 1;

        param_2 = param_2 - 1;

      } while (param_2 != 0);

      param_1[1] = (ulonglong)plVar2;

      return;

    }

  }

  else {

    plVar1 = (longlong *)param_1[1];

    uVar7 = (longlong)plVar1 - (longlong)plVar2 >> 3;

    if (param_2 <= uVar7) {

      FUN_14009bb10(plVar2,plVar2 + param_2,param_3);

      param_1[1] = (ulonglong)(plVar2 + param_2);

      return;

    }

    if (*param_3 == 0) {

      FUN_1402f94c0(plVar2,0,uVar7 * 8);

    }

    else {

      uVar4 = ((longlong)plVar1 - (longlong)plVar2) + 7U >> 3;

      if (plVar1 < plVar2) {

        uVar4 = 0;

      }

      if ((uVar4 != 0) && (1 < uVar4)) {

        lVar5 = *param_3;

        if ((param_3 < plVar2) || (plVar2 + (uVar4 - 1) < param_3)) {

          plVar6 = plVar2;

          for (uVar3 = uVar4 & 0x1ffffffffffffffe; uVar3 != 0; uVar3 = uVar3 - 1) {

            *plVar6 = lVar5;

            plVar6 = plVar6 + 1;

          }

          plVar2 = plVar2 + (uVar4 & 0xfffffffffffffffe);

        }

      }

      for (; plVar2 != plVar1; plVar2 = plVar2 + 1) {

        *plVar2 = *param_3;

      }

    }

    lVar5 = param_2 - uVar7;

    plVar2 = (longlong *)param_1[1];

    if (*param_3 == 0) {

      FUN_1402f94c0(plVar2,0,lVar5 * 8);

      param_1[1] = (ulonglong)(plVar2 + lVar5);

      return;

    }

    for (; lVar5 != 0; lVar5 = lVar5 + -1) {

      *plVar2 = *param_3;

      plVar2 = plVar2 + 1;

    }

  }

  param_1[1] = (ulonglong)plVar2;

  return;

}




