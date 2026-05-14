// Address: 0x140160230
// Ghidra name: FUN_140160230
// ============ 0x140160230 FUN_140160230 (size=288) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140160230(void)



{

  longlong lVar1;

  HMODULE hModule;

  undefined **ppuVar2;

  

  if (DAT_1403fc1c0 == (code *)0x0) {

    if (DAT_1403fc528 == 0) {

      lVar1 = FUN_140179a30();

      if (lVar1 == 0) {

        return;

      }

      FUN_140179b30(lVar1);

    }

    ppuVar2 = &PTR_FUN_140333b48;

    hModule = GetModuleHandleW(L"kernel32.dll");

    if (hModule != (HMODULE)0x0) {

      DAT_1403fc1a0 = GetProcAddress(hModule,"WakeConditionVariable");

      DAT_1403fc1a8 = GetProcAddress(hModule,"WakeAllConditionVariable");

      DAT_1403fc1b0 = GetProcAddress(hModule,"SleepConditionVariableSRW");

      DAT_1403fc1b8 = GetProcAddress(hModule,"SleepConditionVariableCS");

      if ((((DAT_1403fc1a0 != (FARPROC)0x0) && (DAT_1403fc1a8 != (FARPROC)0x0)) &&

          (DAT_1403fc1b0 != (FARPROC)0x0)) &&

         (ppuVar2 = &PTR_LAB_140333b20, DAT_1403fc1b8 == (FARPROC)0x0)) {

        ppuVar2 = &PTR_FUN_140333b48;

      }

    }

    DAT_1403fc1c0 = (code *)*ppuVar2;

    _DAT_1403fc1c8 = ppuVar2[1];

    _DAT_1403fc1d0 = *(undefined4 *)(ppuVar2 + 2);

    uRam00000001403fc1d4 = *(undefined4 *)((longlong)ppuVar2 + 0x14);

    _DAT_1403fc1d8 = *(undefined4 *)(ppuVar2 + 3);

    uRam00000001403fc1dc = *(undefined4 *)((longlong)ppuVar2 + 0x1c);

    _DAT_1403fc1e0 = ppuVar2[4];

  }

                    /* WARNING: Could not recover jumptable at 0x00014016034d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*DAT_1403fc1c0)();

  return;

}




