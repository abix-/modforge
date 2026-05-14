// Address: 0x140227370
// Ghidra name: FUN_140227370
// ============ 0x140227370 FUN_140227370 (size=89) ============


void FUN_140227370(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  

  iVar1 = 0;

  if (0 < *(int *)(param_1 + 0x328)) {

    lVar2 = 0;

    do {

      FUN_14021a690(*(undefined8 *)(*(longlong *)(param_1 + 0x330) + lVar2),0x158,0,0);

      iVar1 = iVar1 + 1;

      lVar2 = lVar2 + 8;

    } while (iVar1 < *(int *)(param_1 + 0x328));

  }

  return;

}




