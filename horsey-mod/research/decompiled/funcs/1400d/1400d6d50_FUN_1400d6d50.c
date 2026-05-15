// Address: 0x1400d6d50
// Ghidra name: FUN_1400d6d50
// ============ 0x1400d6d50 FUN_1400d6d50 (size=482) ============


void FUN_1400d6d50(longlong param_1,longlong param_2,longlong param_3)



{

  int iVar1;

  bool bVar2;

  ulonglong uVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  float fVar9;

  float fVar10;

  

  uVar3 = param_2 - param_1 >> 2;

  lVar4 = param_2 - param_1 >> 3;

  if (0 < lVar4) {

    lVar8 = (longlong)(uVar3 - 1) >> 1;

    do {

      iVar1 = *(int *)(param_1 + -4 + lVar4 * 4);

      lVar4 = lVar4 + -1;

      lVar5 = lVar4;

      while (lVar5 < lVar8) {

        lVar7 = (longlong)*(int *)(param_1 + 8 + lVar5 * 8);

        lVar6 = (longlong)*(int *)(param_1 + 4 + lVar5 * 8);

        fVar9 = (float)FUN_1400b6150(*(undefined8 *)(*(longlong *)(param_3 + 0x130) + lVar7 * 8));

        fVar10 = (float)FUN_1400b6150(*(undefined8 *)(*(longlong *)(param_3 + 0x130) + lVar6 * 8));

        if (fVar9 == fVar10) {

          bVar2 = *(int *)(*(longlong *)(*(longlong *)(param_3 + 0x130) + lVar7 * 8) + 0x1d0) <

                  *(int *)(*(longlong *)(*(longlong *)(param_3 + 0x130) + lVar6 * 8) + 0x1d0);

        }

        else {

          bVar2 = fVar9 < fVar10;

        }

        lVar6 = ((ulonglong)bVar2 ^ 1) + 1 + lVar5 * 2;

        *(undefined4 *)(param_1 + lVar5 * 4) = *(undefined4 *)(param_1 + lVar6 * 4);

        lVar5 = lVar6;

      }

      if ((lVar5 == lVar8) && ((uVar3 & 1) == 0)) {

        *(undefined4 *)(param_1 + lVar5 * 4) = *(undefined4 *)(param_1 + -4 + uVar3 * 4);

        lVar5 = uVar3 - 1;

      }

      if (lVar4 < lVar5) {

        do {

          lVar6 = lVar5 + -1 >> 1;

          lVar7 = (longlong)*(int *)(param_1 + lVar6 * 4);

          fVar9 = (float)FUN_1400b6150(*(undefined8 *)(*(longlong *)(param_3 + 0x130) + lVar7 * 8));

          fVar10 = (float)FUN_1400b6150(*(undefined8 *)

                                         (*(longlong *)(param_3 + 0x130) + (longlong)iVar1 * 8));

          if (fVar9 == fVar10) {

            bVar2 = *(int *)(*(longlong *)(*(longlong *)(param_3 + 0x130) + lVar7 * 8) + 0x1d0) <

                    *(int *)(*(longlong *)(*(longlong *)(param_3 + 0x130) + (longlong)iVar1 * 8) +

                            0x1d0);

          }

          else {

            bVar2 = fVar9 < fVar10;

          }

        } while ((bVar2) &&

                (*(undefined4 *)(param_1 + lVar5 * 4) = *(undefined4 *)(param_1 + lVar6 * 4),

                lVar5 = lVar6, lVar4 < lVar6));

      }

      *(int *)(param_1 + lVar5 * 4) = iVar1;

    } while (0 < lVar4);

  }

  return;

}




