// Address: 0x1401cb150
// Ghidra name: FUN_1401cb150
// ============ 0x1401cb150 FUN_1401cb150 (size=125) ============


void FUN_1401cb150(longlong param_1,longlong param_2)



{

  uint *puVar1;

  uint uVar2;

  longlong lVar3;

  undefined8 uVar4;

  

  if (param_2 != 0) {

    lVar3 = (longlong)*(int *)(param_2 + 8) + 0x10;

    *(undefined4 *)(param_2 + 0x2c) = 0;

    puVar1 = (uint *)(param_1 + lVar3 * 0x18);

    FUN_140179b40(*(undefined8 *)(param_1 + 0x10 + lVar3 * 0x18));

    if (*puVar1 <= puVar1[1]) {

      uVar2 = *puVar1 * 2;

      *puVar1 = uVar2;

      uVar4 = FUN_140184230(*(undefined8 *)(puVar1 + 2),(ulonglong)uVar2 << 3);

      *(undefined8 *)(puVar1 + 2) = uVar4;

    }

    *(longlong *)(*(longlong *)(puVar1 + 2) + (ulonglong)puVar1[1] * 8) = param_2;

    puVar1[1] = puVar1[1] + 1;

    FUN_140179b60(*(undefined8 *)(puVar1 + 4));

  }

  return;

}




