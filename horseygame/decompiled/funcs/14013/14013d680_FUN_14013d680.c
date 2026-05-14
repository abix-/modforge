// Address: 0x14013d680
// Ghidra name: FUN_14013d680
// ============ 0x14013d680 FUN_14013d680 (size=226) ============


void FUN_14013d680(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  int *piVar3;

  uint uVar4;

  ulonglong uVar6;

  ulonglong uVar5;

  

  _guard_check_icall();

  uVar6 = 0;

  if (0 < *(int *)(param_1 + 0x28)) {

    piVar3 = *(int **)(param_1 + 0x30);

    uVar5 = uVar6;

    while ((piVar3[4] != 1 || (piVar3[5] < 0xb))) {

      uVar4 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar4;

      piVar3 = piVar3 + 8;

      if (*(int *)(param_1 + 0x28) <= (int)uVar4) {

        return;

      }

    }

    if ((*piVar3 == 1) && (uVar5 = uVar6, piVar3[1] == piVar3[5])) {

      do {

        lVar2 = *(longlong *)(param_1 + 0x30);

        if ((*(int *)(lVar2 + uVar5) == 1) && (*(int *)(lVar2 + 0x10 + uVar5) == 1)) {

          iVar1 = *(int *)(lVar2 + 0x14 + uVar5);

          if (iVar1 == 0xb) {

            *(undefined4 *)(lVar2 + 8 + uVar5) = 1;

          }

          else if (iVar1 == 0xc) {

            *(undefined4 *)(lVar2 + 8 + uVar5) = 4;

          }

          else if (iVar1 == 0xd) {

            *(undefined4 *)(lVar2 + 8 + uVar5) = 8;

          }

          else {

            if (iVar1 != 0xe) {

              if (0xe < iVar1) {

                piVar3 = (int *)(lVar2 + 4 + uVar5);

                *piVar3 = *piVar3 + -4;

              }

              goto LAB_14013d74f;

            }

            *(undefined4 *)(lVar2 + 8 + uVar5) = 2;

          }

          *(undefined8 *)(lVar2 + uVar5) = 3;

        }

LAB_14013d74f:

        uVar4 = (int)uVar6 + 1;

        uVar6 = (ulonglong)uVar4;

        uVar5 = uVar5 + 0x20;

      } while ((int)uVar4 < *(int *)(param_1 + 0x28));

    }

  }

  return;

}




