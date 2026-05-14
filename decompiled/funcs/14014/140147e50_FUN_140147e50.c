// Address: 0x140147e50
// Ghidra name: FUN_140147e50
// ============ 0x140147e50 FUN_140147e50 (size=112) ============


void FUN_140147e50(longlong param_1)



{

  char cVar1;

  longlong lVar2;

  int iVar3;

  

  cVar1 = FUN_1401489c0();

  if ((cVar1 != '\0') && (0 < *(int *)(param_1 + 0x50))) {

    iVar3 = 0;

    lVar2 = 0;

    do {

      FUN_140146010(*(undefined8 *)(*(longlong *)(param_1 + 0x58) + lVar2));

      iVar3 = iVar3 + 1;

      lVar2 = lVar2 + 8;

    } while (iVar3 < *(int *)(param_1 + 0x50));

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x58));

    *(undefined8 *)(param_1 + 0x58) = 0;

    *(undefined4 *)(param_1 + 0x50) = 0;

  }

  return;

}




