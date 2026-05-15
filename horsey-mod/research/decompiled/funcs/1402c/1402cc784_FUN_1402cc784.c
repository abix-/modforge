// Address: 0x1402cc784
// Ghidra name: FUN_1402cc784
// ============ 0x1402cc784 FUN_1402cc784 (size=230) ============


undefined1 FUN_1402cc784(longlong param_1,int *param_2)



{

  int iVar1;

  undefined8 uVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  int iVar6;

  int *piVar7;

  undefined1 uVar8;

  undefined1 uVar9;

  int iVar10;

  

  if (param_2 == (int *)0x0) {

                    /* WARNING: Subroutine does not return */

    FUN_1402e1bf8();

  }

  uVar8 = 0;

  iVar6 = 0;

  uVar9 = 0;

  if (0 < *param_2) {

    do {

      iVar10 = *(int *)(*(longlong *)(param_1 + 0x30) + 0xc);

      lVar4 = FUN_1402c8e64();

      piVar7 = (int *)((longlong)iVar10 + lVar4 + 4);

      iVar10 = *(int *)(*(longlong *)(param_1 + 0x30) + 0xc);

      lVar4 = FUN_1402c8e64();

      iVar10 = *(int *)(lVar4 + iVar10);

      uVar8 = uVar9;

      if (0 < iVar10) {

        do {

          iVar3 = *piVar7;

          lVar4 = FUN_1402c8e64();

          iVar1 = param_2[1];

          uVar2 = *(undefined8 *)(param_1 + 0x30);

          lVar5 = FUN_1402c8e50();

          iVar3 = FUN_1402cb260(lVar5 + (longlong)iVar6 * 0x14 + (longlong)iVar1,iVar3 + lVar4,uVar2

                               );

          if (iVar3 != 0) {

            uVar8 = 1;

            break;

          }

          iVar10 = iVar10 + -1;

          piVar7 = piVar7 + 1;

        } while (0 < iVar10);

      }

      iVar6 = iVar6 + 1;

      uVar9 = uVar8;

    } while (iVar6 < *param_2);

  }

  return uVar8;

}




