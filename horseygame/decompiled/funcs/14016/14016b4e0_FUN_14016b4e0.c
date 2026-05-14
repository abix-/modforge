// Address: 0x14016b4e0
// Ghidra name: FUN_14016b4e0
// ============ 0x14016b4e0 FUN_14016b4e0 (size=247) ============


void FUN_14016b4e0(undefined8 param_1,char param_2)



{

  longlong lVar1;

  uint uVar2;

  

  uVar2 = FUN_14016d5f0();

  if (-1 < (int)uVar2) {

    lVar1 = *(longlong *)((longlong)(int)uVar2 * 8 + *(longlong *)(DAT_1403fc410 + 0x330));

    if (param_2 != '\0') {

      FUN_14021a690(lVar1,0x153,0,0);

    }

    FUN_1401747e0(*(undefined4 *)(lVar1 + 0x78));

    FUN_1401841e0(*(undefined8 *)(lVar1 + 8));

    FUN_1401700f0(lVar1);

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x40));

    *(undefined8 *)(lVar1 + 0x40) = 0;

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x80));

    *(undefined8 *)(lVar1 + 0x80) = 0;

    FUN_1401841e0(lVar1);

    lVar1 = DAT_1403fc410;

    if ((int)uVar2 < *(int *)(DAT_1403fc410 + 0x328) + -1) {

      FUN_1402f8e20(*(longlong *)(DAT_1403fc410 + 0x330) + (longlong)(int)uVar2 * 8,

                    *(longlong *)(DAT_1403fc410 + 0x330) + (longlong)(int)(uVar2 + 1) * 8,

                    (longlong)(int)(~uVar2 + *(int *)(DAT_1403fc410 + 0x328)) << 3);

    }

    *(int *)(lVar1 + 0x328) = *(int *)(lVar1 + 0x328) + -1;

    FUN_1401730d0();

  }

  return;

}




