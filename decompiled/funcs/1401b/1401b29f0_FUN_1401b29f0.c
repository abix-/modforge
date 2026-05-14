// Address: 0x1401b29f0
// Ghidra name: FUN_1401b29f0
// ============ 0x1401b29f0 FUN_1401b29f0 (size=228) ============


void FUN_1401b29f0(ulonglong *param_1,ulonglong *param_2,ulonglong *param_3)



{

  ulonglong *puVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  uVar5 = 1;

  uVar4 = (ulonglong)((longlong)param_2 + (4 - (longlong)param_1)) >> 2;

  if (param_2 < param_1) {

    uVar4 = 0;

  }

  if ((uVar4 != 0) && (0xf < uVar4)) {

    if (((uint *)((longlong)param_3 + uVar4 * 4) < (uint *)((longlong)param_1 + 4U)) ||

       ((uint *)((longlong)param_1 + uVar4 * 4) < (uint *)((longlong)param_3 + 4U))) {

      do {

        uVar5 = uVar5 + 0x10;

        uVar2 = param_3[1];

        *param_1 = *param_1 | *param_3;

        param_1[1] = param_1[1] | uVar2;

        uVar2 = param_3[3];

        param_1[2] = param_3[2] | param_1[2];

        param_1[3] = uVar2 | param_1[3];

        uVar2 = param_3[5];

        param_1[4] = param_3[4] | param_1[4];

        param_1[5] = uVar2 | param_1[5];

        puVar1 = param_3 + 6;

        uVar2 = param_3[7];

        param_3 = param_3 + 8;

        param_1[6] = *puVar1 | param_1[6];

        param_1[7] = uVar2 | param_1[7];

        param_1 = param_1 + 8;

      } while (uVar5 <= (uVar4 & 0xfffffffffffffff0));

    }

  }

  if (param_1 <= param_2) {

    lVar3 = (longlong)param_3 - (longlong)param_1;

    do {

      *(uint *)param_1 = (uint)*param_1 | *(uint *)(lVar3 + (longlong)param_1);

      param_1 = (ulonglong *)((longlong)param_1 + 4);

    } while (param_1 <= param_2);

  }

  return;

}




