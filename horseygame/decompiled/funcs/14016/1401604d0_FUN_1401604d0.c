// Address: 0x1401604d0
// Ghidra name: FUN_1401604d0
// ============ 0x1401604d0 FUN_1401604d0 (size=142) ============


longlong FUN_1401604d0(longlong param_1,byte param_2)



{

  undefined8 *puVar1;

  int iVar2;

  longlong lVar3;

  longlong lVar4;

  ulonglong uVar5;

  uint uVar6;

  

  if (*(int *)(param_1 + 8) <= (int)(uint)param_2) {

    uVar6 = param_2 + 1;

    lVar4 = FUN_140184230(*(undefined8 *)(param_1 + 0x10),(ulonglong)uVar6 << 5);

    if (lVar4 == 0) {

      return 0;

    }

    iVar2 = *(int *)(param_1 + 8);

    *(longlong *)(param_1 + 0x10) = lVar4;

    if (iVar2 < (int)uVar6) {

      uVar5 = (ulonglong)(uVar6 - iVar2);

      lVar4 = (longlong)iVar2 << 5;

      do {

        lVar3 = *(longlong *)(param_1 + 0x10);

        puVar1 = (undefined8 *)(lVar4 + lVar3);

        *puVar1 = 0;

        puVar1[1] = 0;

        puVar1 = (undefined8 *)(lVar4 + 0x10 + lVar3);

        *puVar1 = 0;

        puVar1[1] = 0;

        uVar5 = uVar5 - 1;

        lVar4 = lVar4 + 0x20;

      } while (uVar5 != 0);

    }

    *(uint *)(param_1 + 8) = uVar6;

  }

  return (ulonglong)param_2 * 0x20 + *(longlong *)(param_1 + 0x10);

}




