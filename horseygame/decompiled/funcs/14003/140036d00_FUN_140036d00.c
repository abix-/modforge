// Address: 0x140036d00
// Ghidra name: FUN_140036d00
// ============ 0x140036d00 FUN_140036d00 (size=1205) ============


void FUN_140036d00(longlong *param_1,longlong *param_2,longlong param_3,undefined1 param_4)



{

  int *piVar1;

  int iVar2;

  ulonglong uVar3;

  longlong *plVar4;

  longlong lVar5;

  longlong lVar6;

  longlong *plVar7;

  longlong *plVar8;

  longlong *plVar9;

  longlong *plVar10;

  longlong lVar11;

  longlong lVar12;

  longlong lVar13;

  

  uVar3 = (longlong)param_2 - (longlong)param_1;

  do {

    if ((longlong)(uVar3 & 0xfffffffffffffff8) < 0x101) {

      plVar8 = param_1;

      if (param_1 != param_2) {

        while (plVar8 = plVar8 + 1, plVar8 != param_2) {

          lVar12 = *plVar8;

          if (*(int *)(lVar12 + 0x228) < *(int *)(*param_1 + 0x228)) {

            FUN_1402f8e20(param_1 + 1,param_1);

            *param_1 = lVar12;

          }

          else {

            lVar11 = plVar8[-1];

            plVar10 = plVar8;

            plVar9 = plVar8;

            if (*(int *)(lVar12 + 0x228) < *(int *)(lVar11 + 0x228)) {

              do {

                plVar10 = plVar9 + -1;

                *plVar9 = lVar11;

                lVar11 = plVar9[-2];

                plVar9 = plVar10;

              } while (*(int *)(lVar12 + 0x228) < *(int *)(lVar11 + 0x228));

            }

            *plVar10 = lVar12;

          }

        }

      }

      return;

    }

    lVar12 = (longlong)param_2 - (longlong)param_1 >> 4;

    if (param_3 < 1) {

      uVar3 = (longlong)param_2 - (longlong)param_1 >> 3;

      if (0 < lVar12) {

        lVar11 = (longlong)(uVar3 - 1) >> 1;

        do {

          lVar13 = param_1[lVar12 + -1];

          lVar12 = lVar12 + -1;

          lVar6 = lVar12;

          while (lVar6 < lVar11) {

            lVar5 = (ulonglong)

                    (*(int *)(param_1[lVar6 * 2 + 1] + 0x228) <=

                    *(int *)(param_1[lVar6 * 2 + 2] + 0x228)) + 1 + lVar6 * 2;

            param_1[lVar6] = param_1[lVar5];

            lVar6 = lVar5;

          }

          if ((lVar6 == lVar11) && ((uVar3 & 1) == 0)) {

            param_1[lVar6] = param_1[uVar3 - 1];

            lVar6 = uVar3 - 1;

          }

          while (lVar12 < lVar6) {

            lVar5 = lVar6 + -1 >> 1;

            if (*(int *)(lVar13 + 0x228) <= *(int *)(param_1[lVar5] + 0x228)) break;

            param_1[lVar6] = param_1[lVar5];

            lVar6 = lVar5;

          }

          param_1[lVar6] = lVar13;

        } while (0 < lVar12);

      }

      if ((longlong)((longlong)param_2 - (longlong)param_1 & 0xfffffffffffffff8U) < 0x10) {

        return;

      }

      param_2 = param_2 + -1;

      do {

        lVar11 = *param_2;

        uVar3 = (longlong)param_2 - (longlong)param_1 >> 3;

        lVar12 = 0;

        *param_2 = *param_1;

        lVar13 = (longlong)(uVar3 - 1) >> 1;

        lVar6 = lVar12;

        if (0 < lVar13) {

          do {

            lVar12 = (ulonglong)

                     (*(int *)(param_1[lVar6 * 2 + 1] + 0x228) <=

                     *(int *)(param_1[lVar6 * 2 + 2] + 0x228)) + 1 + lVar6 * 2;

            param_1[lVar6] = param_1[lVar12];

            lVar6 = lVar12;

          } while (lVar12 < lVar13);

        }

        if ((lVar12 == lVar13) && ((uVar3 & 1) == 0)) {

          param_1[lVar12] = param_1[uVar3 - 1];

          lVar12 = uVar3 - 1;

        }

        while (0 < lVar12) {

          lVar6 = lVar12 + -1 >> 1;

          if (*(int *)(lVar11 + 0x228) <= *(int *)(param_1[lVar6] + 0x228)) break;

          param_1[lVar12] = param_1[lVar6];

          lVar12 = lVar6;

        }

        param_2 = param_2 + -1;

        param_1[lVar12] = lVar11;

        if ((longlong)((8 - (longlong)param_1) + (longlong)param_2 & 0xfffffffffffffff8U) < 0x10) {

          return;

        }

      } while( true );

    }

    plVar10 = param_1 + lVar12;

    FUN_1400369c0(param_1,plVar10,param_2 + -1,param_4);

    plVar8 = plVar10 + 1;

    if (param_1 < plVar10) {

      lVar12 = *plVar10;

      do {

        piVar1 = (int *)(lVar12 + 0x228);

        plVar9 = plVar10 + -1;

        lVar12 = *plVar9;

        if ((*(int *)(lVar12 + 0x228) < *piVar1) || (*piVar1 < *(int *)(lVar12 + 0x228))) break;

        plVar10 = plVar9;

      } while (param_1 < plVar9);

    }

    plVar9 = plVar8;

    plVar7 = plVar10;

    if (plVar8 < param_2) {

      do {

        plVar9 = plVar8;

        if ((*(int *)(*plVar8 + 0x228) < *(int *)(*plVar10 + 0x228)) ||

           (*(int *)(*plVar10 + 0x228) < *(int *)(*plVar8 + 0x228))) break;

        plVar8 = plVar8 + 1;

        plVar9 = plVar8;

      } while (plVar8 < param_2);

    }

joined_r0x000140036dd3:

    plVar4 = plVar10;

    if (plVar8 < param_2) {

      iVar2 = *(int *)(*plVar8 + 0x228);

      if (iVar2 <= *(int *)(*plVar7 + 0x228)) {

        if (iVar2 < *(int *)(*plVar7 + 0x228)) goto joined_r0x000140036e15;

        if (plVar9 != plVar8) {

          lVar12 = *plVar9;

          *plVar9 = *plVar8;

          *plVar8 = lVar12;

        }

        plVar9 = plVar9 + 1;

      }

      plVar8 = plVar8 + 1;

      goto joined_r0x000140036dd3;

    }

joined_r0x000140036e15:

    for (; param_1 < plVar10; plVar10 = plVar10 + -1) {

      plVar4 = plVar4 + -1;

      iVar2 = *(int *)(*plVar4 + 0x228);

      if (*(int *)(*plVar7 + 0x228) <= iVar2) {

        if (*(int *)(*plVar7 + 0x228) < iVar2) break;

        plVar7 = plVar7 + -1;

        if (plVar7 != plVar4) {

          lVar12 = *plVar7;

          *plVar7 = *plVar4;

          *plVar4 = lVar12;

        }

      }

    }

    if (plVar10 != param_1) {

      plVar10 = plVar10 + -1;

      if (plVar8 == param_2) {

        plVar7 = plVar7 + -1;

        if (plVar10 != plVar7) {

          lVar12 = *plVar10;

          *plVar10 = *plVar7;

          *plVar7 = lVar12;

        }

        lVar12 = *plVar7;

        *plVar7 = plVar9[-1];

        plVar9[-1] = lVar12;

        plVar9 = plVar9 + -1;

      }

      else {

        lVar12 = *plVar8;

        *plVar8 = *plVar10;

        plVar8 = plVar8 + 1;

        *plVar10 = lVar12;

      }

      goto joined_r0x000140036dd3;

    }

    if (plVar8 != param_2) {

      if (plVar9 != plVar8) {

        lVar12 = *plVar7;

        *plVar7 = *plVar9;

        *plVar9 = lVar12;

      }

      lVar12 = *plVar7;

      *plVar7 = *plVar8;

      *plVar8 = lVar12;

      plVar8 = plVar8 + 1;

      plVar9 = plVar9 + 1;

      plVar7 = plVar7 + 1;

      goto joined_r0x000140036dd3;

    }

    param_3 = (param_3 >> 1) + (param_3 >> 2);

    if ((longlong)((longlong)plVar7 - (longlong)param_1 & 0xfffffffffffffff8U) <

        (longlong)((longlong)param_2 - (longlong)plVar9 & 0xfffffffffffffff8U)) {

      FUN_140036d00(param_1,plVar7,param_3);

      plVar7 = param_2;

      param_1 = plVar9;

    }

    else {

      FUN_140036d00(plVar9,param_2,param_3);

    }

    uVar3 = (longlong)plVar7 - (longlong)param_1;

    param_2 = plVar7;

  } while( true );

}




