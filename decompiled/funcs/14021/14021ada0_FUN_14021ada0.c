// Address: 0x14021ada0
// Ghidra name: FUN_14021ada0
// ============ 0x14021ada0 FUN_14021ada0 (size=102) ============


void FUN_14021ada0(void)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar2 = DAT_1403fdb58;

  while (lVar2 != 0) {

    lVar1 = *(longlong *)(lVar2 + 0x490);

    FUN_1401841e0(*(undefined8 *)(lVar2 + 8));

    FUN_1401841e0(lVar2);

    lVar2 = lVar1;

  }

  FUN_140288330();

  DAT_1403fdb68 = 0;

  DAT_1403fdb58 = 0;

  DAT_1403fdb60 = 0;

  return;

}




