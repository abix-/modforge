// Address: 0x1402dad44
// Ghidra name: FUN_1402dad44
// ============ 0x1402dad44 FUN_1402dad44 (size=211) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_1402dad44(undefined8 param_1)



{

  DWORD DVar1;

  int iVar2;

  BOOL BVar3;

  HANDLE hFile;

  longlong lVar4;

  undefined1 auStackY_4e8 [32];

  DWORD local_4b8 [4];

  short local_4a8 [576];

  ulonglong local_28;

  

  local_28 = DAT_1403e8b00 ^ (ulonglong)auStackY_4e8;

  hFile = GetStdHandle(0xfffffff4);

  if ((longlong)hFile - 1U < 0xfffffffffffffffe) {

    DVar1 = GetFileType(hFile);

    if (DVar1 == 2) {

      iVar2 = FUN_1402daed8(local_4a8,0x240,L"Assertion failed: %Ts, file %Ts, line %d\n",param_1);

      if (-1 < iVar2) {

        lVar4 = -1;

        do {

          lVar4 = lVar4 + 1;

        } while (local_4a8[lVar4] != 0);

        local_4b8[0] = 0;

        BVar3 = WriteConsoleW(hFile,local_4a8,(DWORD)lVar4,local_4b8,(LPVOID)0x0);

        if (BVar3 != 0) {

                    /* WARNING: Subroutine does not return */

          FUN_1402e1bf8();

        }

      }

    }

  }

  return;

}




