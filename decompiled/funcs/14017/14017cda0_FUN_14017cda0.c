// Address: 0x14017cda0
// Ghidra name: FUN_14017cda0
// ============ 0x14017cda0 FUN_14017cda0 (size=212) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14017cda0(undefined4 param_1)



{

  char cVar1;

  HMODULE hModule;

  undefined **ppuVar2;

  

  if (DAT_1403fc5f0 == (code *)0x0) {

    ppuVar2 = &PTR_FUN_140336e98;

    cVar1 = FUN_140142940("SDL_WINDOWS_FORCE_SEMAPHORE_KERNEL",0);

    if ((cVar1 == '\0') &&

       (hModule = GetModuleHandleW(L"api-ms-win-core-synch-l1-2-0.dll"), hModule != (HMODULE)0x0)) {

      DAT_1403fc5e0 = GetProcAddress(hModule,"WaitOnAddress");

      _DAT_1403fc5e8 = GetProcAddress(hModule,"WakeByAddressSingle");

      if ((DAT_1403fc5e0 != (FARPROC)0x0) &&

         (ppuVar2 = &PTR_FUN_140336e70, _DAT_1403fc5e8 == (FARPROC)0x0)) {

        ppuVar2 = &PTR_FUN_140336e98;

      }

    }

    DAT_1403fc5f0 = (code *)*ppuVar2;

    _DAT_1403fc5f8 = ppuVar2[1];

    _DAT_1403fc600 = *(undefined4 *)(ppuVar2 + 2);

    uRam00000001403fc604 = *(undefined4 *)((longlong)ppuVar2 + 0x14);

    uRam00000001403fc608 = *(undefined4 *)(ppuVar2 + 3);

    uRam00000001403fc60c = *(undefined4 *)((longlong)ppuVar2 + 0x1c);

    _DAT_1403fc610 = ppuVar2[4];

  }

                    /* WARNING: Could not recover jumptable at 0x00014017ce71. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*DAT_1403fc5f0)(param_1);

  return;

}




