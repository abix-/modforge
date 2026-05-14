// Address: 0x140102530
// Ghidra name: FUN_140102530
// ============ 0x140102530 FUN_140102530 (size=805) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8

FUN_140102530(longlong param_1,int *param_2,undefined4 *param_3,int param_4,int param_5,

             undefined4 param_6)



{

  bool bVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  longlong *plVar8;

  int iVar9;

  ulonglong uVar10;

  int *piVar11;

  int iVar12;

  int iVar13;

  longlong lVar14;

  float fVar15;

  float fVar16;

  

  plVar8 = *(longlong **)(param_1 + 0xb8);

  iVar3 = 0;

  iVar12 = 0;

  uVar10 = *(longlong *)(param_1 + 0xc0) - (longlong)plVar8 >> 3;

  iVar13 = 0;

  if (uVar10 != 0) {

    do {

      if (7 < iVar12) goto LAB_14010261a;

      lVar4 = *plVar8;

      iVar2 = *(int *)(lVar4 + 8);

      iVar5 = 0x18;

      if (iVar2 != 0) {

        iVar5 = 2;

      }

      if (iVar2 == 2) {

        iVar5 = 0x12;

      }

      if (((float)((uint)(*(float *)(lVar4 + 0x28) * DAT_140303fb4 - (float)param_4) &

                  _DAT_14039cab0) < (float)iVar5) &&

         ((float)((uint)(*(float *)(lVar4 + 0x2c) * DAT_140303fb4 - (float)param_5) & _DAT_14039cab0

                 ) < (float)iVar5)) {

        if (iVar2 != 0) {

          return 0;

        }

        iVar12 = iVar12 + 1;

      }

      iVar13 = iVar13 + 1;

      plVar8 = plVar8 + 1;

    } while ((ulonglong)(longlong)iVar13 < uVar10);

    if (7 < iVar12) {

LAB_14010261a:

      iVar12 = -1;

      fVar16 = DAT_14030dc08;

      do {

        iVar13 = *(int *)(param_1 + 0x278);

        lVar4 = (longlong)iVar3;

        iVar2 = ((&DAT_1403f4f38)[lVar4 * 10] + param_5) * iVar13 + (&DAT_1403f4f34)[lVar4 * 10] +

                param_4;

        iVar5 = iVar2 / iVar13;

        iVar6 = iVar2 % iVar13;

        if ((((3 < iVar6) && (iVar6 <= iVar13 + -5)) && (3 < iVar5)) &&

           (iVar5 <= *(int *)(param_1 + 0x27c) + -5)) {

          bVar1 = false;

          iVar9 = -1;

          do {

            lVar14 = 3;

            iVar7 = iVar5 + -1;

            do {

              if (((iVar9 + iVar6 < 0) || (iVar13 <= iVar9 + iVar6)) ||

                 ((iVar7 < 0 || (*(int *)(param_1 + 0x27c) <= iVar7)))) {

                piVar11 = &DAT_1403dc390;

              }

              else {

                piVar11 = (int *)(*(longlong *)(param_1 + 0x270) +

                                 (longlong)(iVar7 * iVar13 + iVar9 + iVar6) * 0x28);

              }

              if (*piVar11 != 0) {

                bVar1 = true;

              }

              iVar7 = iVar7 + 1;

              lVar14 = lVar14 + -1;

            } while (lVar14 != 0);

            iVar9 = iVar9 + 1;

          } while (iVar9 < 2);

          if (!bVar1) {

            iVar13 = (&DAT_1403f4f44)[lVar4 * 10];

            fVar15 = (float)FUN_1400c6940(0);

            if ((float)iVar13 - fVar15 < fVar16) {

              fVar16 = (float)iVar13 - fVar15;

              iVar12 = iVar2;

            }

          }

        }

        iVar3 = FUN_140100a40(param_1,iVar3,param_4,param_5,6,param_6);

      } while (iVar3 != -1);

      if (iVar12 != -1) {

        *param_2 = iVar12 % *(int *)(param_1 + 0x278);

        uVar10 = (longlong)iVar12 / (longlong)*(int *)(param_1 + 0x278);

        *param_3 = (int)uVar10;

        if (DAT_1403d9527 != '\0') {

          FUN_1400c4320("Found site at %d,%d",*param_2,uVar10 & 0xffffffff);

        }

        return 1;

      }

    }

  }

  return 0;

}




