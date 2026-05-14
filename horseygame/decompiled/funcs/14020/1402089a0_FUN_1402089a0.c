// Address: 0x1402089a0
// Ghidra name: FUN_1402089a0
// ============ 0x1402089a0 FUN_1402089a0 (size=113) ============


void FUN_1402089a0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  

  FUN_140159d30();

  iVar2 = 0;

  if (0 < *(int *)(param_1 + 0x8c)) {

    lVar3 = 0;

    do {

      lVar1 = FUN_1401581c0(*(undefined4 *)(*(longlong *)(param_1 + 0x90) + lVar3));

      if (lVar1 != 0) {

        FUN_140208ab0(param_1,lVar1);

      }

      iVar2 = iVar2 + 1;

      lVar3 = lVar3 + 4;

    } while (iVar2 < *(int *)(param_1 + 0x8c));

  }

  FUN_14015bb10();

  return;

}




