// Address: 0x14012da50
// Ghidra name: FUN_14012da50
// ============ 0x14012da50 FUN_14012da50 (size=52) ============


void FUN_14012da50(void)



{

  longlong lVar1;

  

  lVar1 = DAT_1403fb520;

  while (lVar1 != 0) {

    DAT_1403fb520 = *(longlong *)(lVar1 + 8);

    FUN_1401841e0(lVar1);

    lVar1 = DAT_1403fb520;

  }

  DAT_1403fb520 = lVar1;

  return;

}




