// Address: 0x1401040e0
// Ghidra name: FUN_1401040e0
// ============ 0x1401040e0 FUN_1401040e0 (size=259) ============


void FUN_1401040e0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  undefined *puVar5;

  longlong lVar6;

  int iVar7;

  int iVar8;

  

  iVar8 = 0;

  if (0 < *(int *)(param_1 + 0x27c)) {

    do {

      iVar2 = *(int *)(param_1 + 0x278);

      iVar7 = 0;

      if (0 < iVar2) {

        do {

          lVar6 = (longlong)(iVar2 * iVar8 + iVar7);

          lVar1 = *(longlong *)(param_1 + 0x270) + lVar6 * 0x28;

          lVar6 = (longlong)*(int *)(*(longlong *)(param_1 + 0x270) + lVar6 * 0x28) * 0x1c;

          if (*(int *)(&DAT_1403132d8 + lVar6) != 0) {

            puVar5 = &DAT_1403132e4;

            if (*(int *)(lVar1 + 4) != 0) {

              puVar5 = &DAT_1403132e0;

            }

            iVar2 = *(int *)(puVar5 + lVar6);

            iVar3 = FUN_1400c6580(100);

            if (iVar3 < iVar2) {

              uVar4 = FUN_1400c5c20(*(int *)(&DAT_1403132dc + lVar6) + *(int *)(lVar1 + 4),

                                    *(undefined4 *)(&DAT_1403132d8 + lVar6));

              *(undefined4 *)(lVar1 + 4) = uVar4;

            }

          }

          iVar2 = *(int *)(param_1 + 0x278);

          iVar7 = iVar7 + 1;

        } while (iVar7 < iVar2);

      }

      iVar8 = iVar8 + 1;

    } while (iVar8 < *(int *)(param_1 + 0x27c));

  }

  return;

}




