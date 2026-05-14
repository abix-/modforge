// Address: 0x1401bb750
// Ghidra name: FUN_1401bb750
// ============ 0x1401bb750 FUN_1401bb750 (size=255) ============


void FUN_1401bb750(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  longlong lVar4;

  longlong lVar5;

  uint uVar6;

  ulonglong uVar7;

  longlong lVar8;

  

  lVar4 = 0;

  lVar8 = 0x20;

  do {

    uVar7 = 0;

    lVar5 = *(longlong *)(param_1 + 0x598) + lVar4;

    if (*(int *)(lVar5 + 0x10) != 0) {

      do {

        lVar1 = uVar7 * 8;

        lVar2 = *(longlong *)(lVar1 + *(longlong *)(lVar5 + 8));

        if ((*(char *)(lVar2 + 0x38) == '\x01') && (1 < *(uint *)(lVar2 + 0x30))) {

          if (*(uint *)(param_1 + 0x934) <= *(int *)(param_1 + 0x930) + 1U) {

            uVar6 = *(uint *)(param_1 + 0x934) * 2;

            *(uint *)(param_1 + 0x934) = uVar6;

            uVar3 = FUN_140184230(*(undefined8 *)(param_1 + 0x928),(ulonglong)uVar6 << 3);

            *(undefined8 *)(param_1 + 0x928) = uVar3;

          }

          *(undefined8 *)

           (*(longlong *)(param_1 + 0x928) + (ulonglong)*(uint *)(param_1 + 0x930) * 8) =

               *(undefined8 *)(lVar1 + *(longlong *)(lVar5 + 8));

          *(int *)(param_1 + 0x930) = *(int *)(param_1 + 0x930) + 1;

          FUN_1401bb6b0(*(undefined8 *)(lVar1 + *(longlong *)(lVar5 + 8)));

        }

        uVar6 = (int)uVar7 + 1;

        uVar7 = (ulonglong)uVar6;

      } while (uVar6 < *(uint *)(lVar5 + 0x10));

    }

    lVar4 = lVar4 + 0x28;

    lVar8 = lVar8 + -1;

  } while (lVar8 != 0);

  return;

}




