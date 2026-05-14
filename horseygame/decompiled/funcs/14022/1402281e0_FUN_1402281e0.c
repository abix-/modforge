// Address: 0x1402281e0
// Ghidra name: FUN_1402281e0
// ============ 0x1402281e0 FUN_1402281e0 (size=170) ============


void FUN_1402281e0(longlong param_1)



{

  undefined8 *puVar1;

  longlong lVar2;

  undefined8 *puVar3;

  int iVar4;

  

  puVar1 = *(undefined8 **)(param_1 + 8);

  iVar4 = 0;

  if (0 < *(int *)(puVar1 + 3)) {

    puVar3 = puVar1 + 4;

    do {

      FUN_140146010(*puVar3);

      iVar4 = iVar4 + 1;

      puVar3 = puVar3 + 2;

    } while (iVar4 < *(int *)(puVar1 + 3));

  }

  lVar2 = puVar1[1];

  while (lVar2 != 0) {

    puVar1[1] = *(undefined8 *)(lVar2 + 0x10);

    if (*(HCURSOR *)(lVar2 + 8) != (HCURSOR)0x0) {

      DestroyCursor(*(HCURSOR *)(lVar2 + 8));

    }

    FUN_1401841e0(lVar2);

    lVar2 = puVar1[1];

  }

  if ((HCURSOR)*puVar1 != (HCURSOR)0x0) {

    DestroyCursor((HCURSOR)*puVar1);

  }

  FUN_1401841e0(puVar1);

  FUN_1401841e0(param_1);

  return;

}




