// Address: 0x140226f30
// Ghidra name: FUN_140226f30
// ============ 0x140226f30 FUN_140226f30 (size=282) ============


void FUN_140226f30(longlong param_1)



{

  undefined4 *puVar1;

  int iVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  longlong lVar5;

  uint uVar6;

  ulonglong uVar7;

  

  uVar4 = 0;

  uVar3 = uVar4;

  uVar7 = uVar4;

  if (0 < *(int *)(param_1 + 0x328)) {

    do {

      uVar6 = (int)uVar7 + 1;

      *(undefined4 *)

       (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x330) + -8 + uVar3 + 8) + 0x80) + 0x48)

           = 2;

      uVar3 = uVar3 + 8;

      uVar7 = (ulonglong)uVar6;

    } while ((int)uVar6 < *(int *)(param_1 + 0x328));

  }

  FUN_140226050(param_1);

  iVar2 = *(int *)(param_1 + 0x328) + -1;

  lVar5 = (longlong)iVar2;

  if (-1 < iVar2) {

    do {

      puVar1 = *(undefined4 **)(*(longlong *)(param_1 + 0x330) + lVar5 * 8);

      if (*(int *)(*(longlong *)(puVar1 + 0x20) + 0x48) == 2) {

        FUN_14016b4e0(*puVar1,1);

      }

      lVar5 = lVar5 + -1;

    } while (-1 < lVar5);

  }

  uVar3 = uVar4;

  if (0 < *(int *)(param_1 + 0x328)) {

    do {

      lVar5 = *(longlong *)(uVar3 + *(longlong *)(param_1 + 0x330));

      if (*(int *)(*(longlong *)(lVar5 + 0x80) + 0x48) == 1) {

        FUN_14021a690(lVar5,0x152,0,0);

      }

      uVar6 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar6;

      uVar3 = uVar3 + 8;

    } while ((int)uVar6 < *(int *)(param_1 + 0x328));

  }

  return;

}




