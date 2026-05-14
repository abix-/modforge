// Address: 0x1402cf940
// Ghidra name: common_end_thread
// ============ 0x1402cf940 common_end_thread (size=95) ============


/* Library Function - Single Match

    void __cdecl common_end_thread(unsigned int)

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __cdecl common_end_thread(uint param_1)



{

  longlong lVar1;

  

  lVar1 = FUN_1402e86c4();

  if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x3c0), lVar1 != 0)) {

    if (*(char *)(lVar1 + 0x20) != '\0') {

      FUN_1402ec5f4();

    }

    if ((longlong)*(HANDLE *)(lVar1 + 0x10) - 1U < 0xfffffffffffffffe) {

      CloseHandle(*(HANDLE *)(lVar1 + 0x10));

    }

    if ((undefined1 *)((longlong)&(*(HMODULE *)(lVar1 + 0x18))[-1].unused + 3U) <

        (undefined1 *)0xfffffffffffffffe) {

                    /* WARNING: Subroutine does not return */

      FreeLibraryAndExitThread(*(HMODULE *)(lVar1 + 0x18),param_1);

    }

  }

                    /* WARNING: Subroutine does not return */

  ExitThread(param_1);

}




