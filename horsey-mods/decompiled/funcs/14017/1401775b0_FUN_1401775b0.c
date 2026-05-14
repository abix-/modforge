// Address: 0x1401775b0
// Ghidra name: FUN_1401775b0
// ============ 0x1401775b0 FUN_1401775b0 (size=117) ============


void FUN_1401775b0(void)



{

  longlong lVar1;

  

  FUN_140177410();

  lVar1 = DAT_1403fc480;

  while (DAT_1403fc480 = lVar1, lVar1 != 0) {

    *(undefined4 *)(lVar1 + 0x6c) = 1;

    FUN_140176ce0(lVar1);

    lVar1 = DAT_1403fc480;

  }

  (**(code **)(PTR_PTR_1403e2870 + 0x50))();

  FUN_14017e880(0x4000);

  DAT_1403fc478 = 0;

  FUN_140177750();

  return;

}




