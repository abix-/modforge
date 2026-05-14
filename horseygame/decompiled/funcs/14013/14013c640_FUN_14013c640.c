// Address: 0x14013c640
// Ghidra name: FUN_14013c640
// ============ 0x14013c640 FUN_14013c640 (size=360) ============


void FUN_14013c640(void)



{

  int iVar1;

  undefined4 uVar2;

  int *piVar3;

  char cVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  int *piVar8;

  longlong lVar9;

  

  _guard_check_icall();

  piVar3 = DAT_1403fbf30;

  *DAT_1403fbf30 = *DAT_1403fbf30 + -1;

  if (*piVar3 < 1) {

    piVar8 = *(int **)(piVar3 + 2);

    lVar9 = 0;

    DAT_1403fbf30 = (int *)0x0;

    if ((piVar8 != (int *)0x0) && (*(longlong *)(piVar3 + 4) != 0)) {

      iVar1 = *piVar8;

      lVar5 = lVar9;

      while (iVar1 != 0) {

        uVar2 = *(undefined4 *)(lVar5 + (longlong)piVar8);

        lVar5 = FUN_14013e580(uVar2);

        lVar6 = FUN_140140710(uVar2,0);

        if (lVar5 == 0) {

          lVar7 = *(longlong *)(*(longlong *)(piVar3 + 4) + lVar9 * 8);

        }

        else {

          lVar7 = *(longlong *)(lVar5 + 0x20);

        }

        if (lVar6 == 0) {

          if (lVar7 == 0) {

LAB_14013c705:

            cVar4 = FUN_14013c5c0(piVar3);

            if (cVar4 != '\0') goto LAB_14013c714;

          }

          else {

            if (DAT_1403fbf38 != 0) {

              FUN_1401ab100(DAT_1403fbf38,uVar2,0,1);

            }

            FUN_1401400c0(uVar2);

          }

        }

        else if (lVar7 == 0) {

          if (DAT_1403fbf38 != 0) {

            FUN_1401ab100(DAT_1403fbf38,uVar2,1,1);

          }

          FUN_140140020(uVar2);

        }

        else {

          if (lVar7 == lVar6) goto LAB_14013c705;

LAB_14013c714:

          if (lVar5 != 0) {

            FUN_140140b10(lVar5);

          }

          FUN_140140070(uVar2);

        }

        piVar8 = *(int **)(piVar3 + 2);

        lVar9 = lVar9 + 1;

        lVar5 = lVar9 * 4;

        iVar1 = piVar8[lVar9];

      }

    }

    FUN_1401841e0(piVar8);

    FUN_1401841e0(*(undefined8 *)(piVar3 + 4));

    FUN_1401841e0(*(undefined8 *)(piVar3 + 8));

    FUN_1401841e0(piVar3);

  }

  return;

}




