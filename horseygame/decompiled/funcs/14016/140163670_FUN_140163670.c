// Address: 0x140163670
// Ghidra name: FUN_140163670
// ============ 0x140163670 FUN_140163670 (size=143) ============


void FUN_140163670(void)



{

  longlong lVar1;

  longlong lVar2;

  

  if (DAT_1403fc350 != 0) {

    FUN_140179b40(DAT_1403fc348);

    lVar2 = DAT_1403fc350;

    while (lVar2 != 0) {

      lVar1 = *(longlong *)(lVar2 + 0x10);

      FUN_1401841e0(*(undefined8 *)(lVar2 + 8));

      FUN_1401841e0(lVar2);

      lVar2 = lVar1;

    }

    DAT_1403fc350 = 0;

    FUN_140179b60(DAT_1403fc348);

  }

  if (DAT_1403fc348 != 0) {

    FUN_140179b30();

    DAT_1403fc348 = 0;

  }

  return;

}




