// Address: 0x14015bf20
// Ghidra name: FUN_14015bf20
// ============ 0x14015bf20 FUN_14015bf20 (size=91) ============


ulonglong FUN_14015bf20(int param_1,ushort param_2,longlong param_3)



{

  int iVar1;

  uint *puVar2;

  longlong lVar3;

  longlong lVar4;

  uint uVar5;

  

  lVar3 = 0;

  uVar5 = param_1 << 0x10 | (uint)param_2;

  if (0 < *(int *)(param_3 + 0x20)) {

    puVar2 = *(uint **)(param_3 + 0x28);

    lVar4 = lVar3;

    do {

      if (uVar5 == *puVar2) goto LAB_14015bf75;

      lVar4 = lVar4 + 1;

      puVar2 = puVar2 + 1;

    } while (lVar4 < *(int *)(param_3 + 0x20));

  }

  iVar1 = *(int *)(param_3 + 8);

  puVar2 = (uint *)(longlong)iVar1;

  if (0 < iVar1) {

    puVar2 = *(uint **)(param_3 + 0x10);

    do {

      if (uVar5 == *puVar2) {

        return CONCAT71((int7)((ulonglong)puVar2 >> 8),1);

      }

      lVar3 = lVar3 + 1;

      puVar2 = puVar2 + 1;

    } while (lVar3 < iVar1);

  }

LAB_14015bf75:

  return (ulonglong)puVar2 & 0xffffffffffffff00;

}




