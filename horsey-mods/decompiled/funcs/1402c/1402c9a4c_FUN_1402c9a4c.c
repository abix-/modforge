// Address: 0x1402c9a4c
// Ghidra name: FUN_1402c9a4c
// ============ 0x1402c9a4c FUN_1402c9a4c (size=101) ============


undefined4 FUN_1402c9a4c(longlong param_1,longlong param_2,ulonglong param_3)



{

  longlong lVar1;

  uint uVar2;

  ulonglong uVar3;

  longlong lVar4;

  

  if (param_1 != 0) {

    lVar4 = (longlong)*(int *)(param_1 + 0x18);

    lVar1 = *(longlong *)(param_2 + 8);

    if (lVar1 + lVar4 != 0) {

      uVar3 = 0;

      if (*(uint *)(param_1 + 0x14) != 0) {

        do {

          if (param_3 < (ulonglong)(*(int *)(lVar4 + uVar3 * 8 + lVar1) + lVar1)) break;

          uVar2 = (int)uVar3 + 1;

          uVar3 = (ulonglong)uVar2;

        } while (uVar2 < *(uint *)(param_1 + 0x14));

        if ((int)uVar3 != 0) {

          return *(undefined4 *)(lVar1 + (ulonglong)((int)uVar3 - 1) * 8 + 4 + lVar4);

        }

      }

      return 0xffffffff;

    }

  }

                    /* WARNING: Subroutine does not return */

  FUN_1402e1bf8();

}




