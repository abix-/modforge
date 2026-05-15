// Address: 0x14009bb10
// Ghidra name: FUN_14009bb10
// ============ 0x14009bb10 FUN_14009bb10 (size=145) ============


void FUN_14009bb10(longlong *param_1,longlong *param_2,longlong *param_3)



{

  longlong lVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  longlong *plVar4;

  

  if (*param_3 != 0) {

    uVar3 = ((longlong)param_2 - (longlong)param_1) + 7U >> 3;

    if (param_2 < param_1) {

      uVar3 = 0;

    }

    if ((uVar3 != 0) && (1 < uVar3)) {

      lVar1 = *param_3;

      if ((param_3 < param_1) || (param_1 + (uVar3 - 1) < param_3)) {

        plVar4 = param_1;

        for (uVar2 = uVar3 & 0x1ffffffffffffffe; uVar2 != 0; uVar2 = uVar2 - 1) {

          *plVar4 = lVar1;

          plVar4 = plVar4 + 1;

        }

        param_1 = param_1 + (uVar3 & 0xfffffffffffffffe);

      }

    }

    for (; param_1 != param_2; param_1 = param_1 + 1) {

      *param_1 = *param_3;

    }

    return;

  }

  FUN_1402f94c0(param_1,0,(longlong)param_2 - (longlong)param_1 & 0xfffffffffffffff8);

  return;

}




