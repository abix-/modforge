// Address: 0x140184320
// Ghidra name: FUN_140184320
// ============ 0x140184320 FUN_140184320 (size=339) ============


longlong FUN_140184320(void)



{

  HMODULE hModule;

  longlong lVar1;

  

  if (DAT_1403fcb24 == '\0') {

    hModule = GetModuleHandleW(L"kernel32.dll");

    if (hModule != (HMODULE)0x0) {

      DAT_1403fcb28 = GetProcAddress(hModule,"CreateWaitableTimerExW");

      if (DAT_1403fcb28 == (FARPROC)0x0) {

        DAT_1403fcb38 = GetProcAddress(hModule,"CreateWaitableTimerW");

      }

      DAT_1403fcb30 = GetProcAddress(hModule,"SetWaitableTimerEx");

      if (DAT_1403fcb30 == (FARPROC)0x0) {

        DAT_1403fcb40 = GetProcAddress(hModule,"SetWaitableTimer");

      }

      if (((DAT_1403fcb28 == (FARPROC)0x0) && (DAT_1403fcb38 == (FARPROC)0x0)) ||

         ((DAT_1403fcb30 == (FARPROC)0x0 && (DAT_1403fcb40 == (FARPROC)0x0)))) {

        DAT_1403fcb24 = '\0';

      }

      else {

        DAT_1403fcb24 = '\x01';

      }

    }

    if (DAT_1403fcb24 == '\0') {

      return 0;

    }

  }

  lVar1 = FUN_1401638b0(&DAT_1403fcb48);

  if (lVar1 == 0) {

    if (DAT_1403fcb28 == (FARPROC)0x0) {

      lVar1 = (*DAT_1403fcb38)(0,1,0);

    }

    else {

      lVar1 = (*DAT_1403fcb28)(0,0,2,0x1f0003);

    }

    if (lVar1 != 0) {

      FUN_140163ac0(&DAT_1403fcb48,lVar1,&DAT_140184270);

    }

  }

  return lVar1;

}




