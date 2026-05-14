// Address: 0x14020f500
// Ghidra name: FUN_14020f500
// ============ 0x14020f500 FUN_14020f500 (size=184) ============


void FUN_14020f500(void)



{

  DWORD idThread;

  

  if (DAT_1403fd328 != 0) {

    FUN_140179b40(DAT_1403fd320);

    DAT_1403fd311 = 1;

    FUN_140160220(DAT_1403fd318);

    FUN_140179b60(DAT_1403fd320);

    idThread = FUN_140163930(DAT_1403fd328);

    PostThreadMessageW(idThread,0x12,0,0);

    _guard_check_icall();

    FUN_14015bb10();

    FUN_140163d80(DAT_1403fd328,0);

    FUN_140159d30();

    FUN_140160350(DAT_1403fd318);

    DAT_1403fd318 = 0;

    FUN_140179b30(DAT_1403fd320);

    DAT_1403fd320 = 0;

    DAT_1403fd328 = 0;

  }

  return;

}




