// Address: 0x14015a190
// Ghidra name: FUN_14015a190
// ============ 0x14015a190 FUN_14015a190 (size=134) ============


void FUN_14015a190(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  undefined8 *puVar1;

  int iVar2;

  longlong lVar3;

  longlong lVar4;

  

  iVar2 = *(int *)(param_1 + 0x90);

  lVar3 = (longlong)iVar2;

  lVar4 = FUN_140184230(*(undefined8 *)(param_1 + 0x98),lVar3 * 0x18 + 0x18);

  if (lVar4 != 0) {

    puVar1 = (undefined8 *)(lVar4 + lVar3 * 0x18);

    *puVar1 = 0;

    puVar1[1] = 0;

    *(undefined8 *)(lVar4 + 0x10 + lVar3 * 0x18) = 0;

    *(undefined4 *)(lVar4 + 8 + lVar3 * 0x18) = param_3;

    *(undefined4 *)(lVar4 + lVar3 * 0x18) = param_2;

    *(int *)(param_1 + 0x90) = iVar2 + 1;

    *(longlong *)(param_1 + 0x98) = lVar4;

  }

  return;

}




