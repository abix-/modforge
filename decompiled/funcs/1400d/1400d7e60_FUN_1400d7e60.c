// Address: 0x1400d7e60
// Ghidra name: FUN_1400d7e60
// ============ 0x1400d7e60 FUN_1400d7e60 (size=382) ============


void FUN_1400d7e60(longlong param_1,longlong param_2,ulonglong param_3,longlong *param_4)



{

  bool bVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  float fVar6;

  float fVar7;

  

  lVar5 = (longlong)(param_3 - 1) >> 1;

  lVar4 = param_2;

  while (lVar4 < lVar5) {

    lVar2 = *(longlong *)(param_1 + 0x10 + lVar4 * 0x10);

    lVar3 = *(longlong *)(param_1 + 8 + lVar4 * 0x10);

    fVar6 = (float)FUN_1400b6150(lVar2);

    fVar7 = (float)FUN_1400b6150(lVar3);

    if (fVar6 == fVar7) {

      bVar1 = *(int *)(lVar2 + 0x1d0) < *(int *)(lVar3 + 0x1d0);

    }

    else {

      fVar6 = (float)FUN_1400b6150(lVar2);

      fVar7 = (float)FUN_1400b6150(lVar3);

      bVar1 = fVar6 < fVar7;

    }

    lVar2 = ((ulonglong)bVar1 ^ 1) + 1 + lVar4 * 2;

    *(undefined8 *)(param_1 + lVar4 * 8) = *(undefined8 *)(param_1 + lVar2 * 8);

    lVar4 = lVar2;

  }

  if ((lVar4 == lVar5) && ((param_3 & 1) == 0)) {

    *(undefined8 *)(param_1 + lVar4 * 8) = *(undefined8 *)(param_1 + -8 + param_3 * 8);

    lVar4 = param_3 - 1;

  }

  if (param_2 < lVar4) {

    do {

      lVar5 = *param_4;

      lVar3 = lVar4 + -1 >> 1;

      lVar2 = *(longlong *)(param_1 + lVar3 * 8);

      fVar6 = (float)FUN_1400b6150(lVar2);

      fVar7 = (float)FUN_1400b6150(lVar5);

      if (fVar6 == fVar7) {

        bVar1 = *(int *)(lVar2 + 0x1d0) < *(int *)(lVar5 + 0x1d0);

      }

      else {

        fVar6 = (float)FUN_1400b6150(lVar2);

        fVar7 = (float)FUN_1400b6150(lVar5);

        bVar1 = fVar6 < fVar7;

      }

      if (!bVar1) goto LAB_1400d7fc2;

      *(undefined8 *)(param_1 + lVar4 * 8) = *(undefined8 *)(param_1 + lVar3 * 8);

      lVar4 = lVar3;

    } while (param_2 < lVar3);

    *(longlong *)(param_1 + lVar3 * 8) = *param_4;

  }

  else {

LAB_1400d7fc2:

    *(longlong *)(param_1 + lVar4 * 8) = *param_4;

  }

  return;

}




