// Address: 0x140220870
// Ghidra name: FUN_140220870
// ============ 0x140220870 FUN_140220870 (size=159) ============


void FUN_140220870(void)



{

  DAT_1403fdbbc = DAT_1403fdbbc + -1;

  if (DAT_1403fdbbc < 1) {

    FUN_140139010(&DAT_1403fdbe0,0);

    SetEvent(DAT_1403e54a0);

    FUN_140163d80(DAT_1403fdbe8,0);

    DAT_1403fdbe8 = 0;

    if (DAT_1403fdbc0 != (HMODULE)0x0) {

      if ((DAT_1403fdbd8 != 0) && (DAT_1403fdbd0 != (code *)0x0)) {

        (*DAT_1403fdbd0)();

        DAT_1403fdbd8 = 0;

      }

      FreeLibrary(DAT_1403fdbc0);

      DAT_1403fdbc0 = (HMODULE)0x0;

    }

  }

  return;

}




