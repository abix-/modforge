// Address: 0x140214950
// Ghidra name: FUN_140214950
// ============ 0x140214950 FUN_140214950 (size=69) ============


void FUN_140214950(void)



{

  if (DAT_1403fdaa8 != (HMODULE)0x0) {

    FreeLibrary(DAT_1403fdaa8);

    DAT_1403fdaa8 = (HMODULE)0x0;

  }

  DAT_1403fdab0 = 0;

  DAT_1403fdab8 = 0;

  FUN_140214ee0();

  CoUninitialize();

  return;

}




