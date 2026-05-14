// Address: 0x1402c8390
// Ghidra name: FUN_1402c8390
// ============ 0x1402c8390 FUN_1402c8390 (size=98) ============


longlong FUN_1402c8390(longlong param_1,int param_2)



{

  uint uVar1;

  longlong lVar2;

  

  uVar1 = *(uint *)(param_1 + 0xc);

  do {

    if (uVar1 == 0) {

      return 0;

    }

    uVar1 = uVar1 - 1;

    lVar2 = FUN_1402c97f8();

    lVar2 = (longlong)*(int *)(param_1 + 0x10) +

            *(longlong *)(lVar2 + 0x60) + (ulonglong)uVar1 * 0x14;

  } while ((param_2 <= *(int *)(lVar2 + 4)) || (*(int *)(lVar2 + 8) < param_2));

  return lVar2;

}




