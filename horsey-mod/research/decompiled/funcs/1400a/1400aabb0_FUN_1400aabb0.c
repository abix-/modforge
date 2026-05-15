// Address: 0x1400aabb0
// Ghidra name: FUN_1400aabb0
// ============ 0x1400aabb0 FUN_1400aabb0 (size=159) ============


void FUN_1400aabb0(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  undefined3 uVar3;

  int iVar4;

  

  iVar4 = *(int *)(param_1 + 0xa8);

  if (0 < iVar4) {

    iVar4 = iVar4 + -1;

    *(int *)(param_1 + 0xa8) = iVar4;

  }

  lVar2 = *(longlong *)(param_1 + 0x38);

  if ((lVar2 != 0) && (*(longlong *)(param_1 + 0x30) != 0)) {

    iVar1 = *(int *)(param_1 + 0xa4);

    uVar3 = (undefined3)((uint)iVar4 >> 8);

    if (iVar1 == 1) {

      FUN_140084060(lVar2,*(undefined4 *)(param_1 + 0xac),CONCAT31(uVar3,iVar4 == 0),

                    *(undefined1 *)(param_1 + 0x84));

      return;

    }

    if (iVar1 == 2) {

      FUN_140084370(lVar2,*(undefined4 *)(param_1 + 0xac));

      return;

    }

    if (iVar1 == 3) {

      FUN_140084300(lVar2,*(undefined4 *)(param_1 + 0xac),CONCAT31(uVar3,iVar4 == 0),

                    *(undefined1 *)(param_1 + 0x84));

      return;

    }

    if (iVar1 == 4) {

      FUN_1400844c0(lVar2,*(undefined4 *)(param_1 + 0xac));

      return;

    }

  }

  return;

}




