// Address: 0x14028b4b0
// Ghidra name: FUN_14028b4b0
// ============ 0x14028b4b0 FUN_14028b4b0 (size=143) ============


undefined8 FUN_14028b4b0(longlong param_1,int param_2,int param_3)



{

  uint *puVar1;

  undefined8 uVar2;

  uint uVar3;

  longlong lVar4;

  

  uVar2 = FUN_140149350();

  lVar4 = (longlong)param_2 * 0x98;

  uVar3 = *(uint *)(lVar4 + 0x68 + param_1) & 1;

  if (0 < param_3) {

    if (uVar3 == 0) {

      *(int *)(param_1 + 0xa48) = *(int *)(param_1 + 0xa48) + 1;

    }

    else {

      *(undefined4 *)(lVar4 + 0x68 + param_1) = 0;

    }

    puVar1 = (uint *)(lVar4 + 0x68 + param_1);

    *puVar1 = *puVar1 | 1;

    *(undefined8 *)(lVar4 + 0x50 + param_1) = uVar2;

    *(int *)(lVar4 + 0x88 + param_1) = param_3;

    return 0;

  }

  if (uVar3 != 0) {

    *(undefined4 *)(lVar4 + 0x68 + param_1) = 0;

    *(int *)(param_1 + 0xa48) = *(int *)(param_1 + 0xa48) + -1;

  }

  return 0;

}




