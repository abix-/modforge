// Address: 0x1401a93d0
// Ghidra name: FUN_1401a93d0
// ============ 0x1401a93d0 FUN_1401a93d0 (size=568) ============


char * FUN_1401a93d0(int *param_1,longlong *param_2,undefined8 *param_3)



{

  int iVar1;

  int iVar2;

  LPWSTR lpWideCharStr;

  char *pcVar3;

  LPWSTR *hMem;

  HANDLE pvVar4;

  undefined8 *lpMem;

  int iVar5;

  undefined8 *puVar6;

  LPSTR lpMultiByteStr;

  int iVar7;

  int iVar8;

  int local_res20 [2];

  

  iVar8 = 0;

  *param_3 = 0;

  if (*param_2 != 0) {

    return (char *)0x0;

  }

  lpWideCharStr = GetCommandLineW();

  iVar1 = WideCharToMultiByte(0xfde9,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);

  if (iVar1 == 0) {

    pcVar3 = "Error processing command line arguments - aborting";

  }

  else {

    local_res20[0] = -1;

    hMem = CommandLineToArgvW(lpWideCharStr,local_res20);

    if ((hMem == (LPWSTR *)0x0) || (local_res20[0] < 0)) {

      pcVar3 = "Out of memory - aborting";

    }

    else {

      iVar5 = local_res20[0] + 1;

      pvVar4 = GetProcessHeap();

      lpMem = HeapAlloc(pvVar4,8,(longlong)iVar5 * 8 + (longlong)iVar1);

      if (lpMem == (undefined8 *)0x0) {

        LocalFree(hMem);

        pcVar3 = "Out of memory - aborting";

      }

      else {

        iVar7 = 0;

        iVar5 = local_res20[0] + 1;

        if (0 < local_res20[0]) {

          puVar6 = lpMem;

          do {

            lpMultiByteStr = (LPSTR)((longlong)lpMem + (longlong)iVar8 + (longlong)iVar5 * 8);

            iVar2 = WideCharToMultiByte(0xfde9,0,*(LPCWSTR *)

                                                  ((longlong)puVar6 +

                                                  ((longlong)hMem - (longlong)lpMem)),-1,

                                        lpMultiByteStr,iVar1 - iVar8,(LPCSTR)0x0,(LPBOOL)0x0);

            if (iVar2 == 0) {

              pvVar4 = GetProcessHeap();

              HeapFree(pvVar4,0,lpMem);

              LocalFree(hMem);

              return "Error processing command line arguments - aborting";

            }

            iVar8 = iVar8 + iVar2;

            *puVar6 = lpMultiByteStr;

            iVar7 = iVar7 + 1;

            puVar6 = puVar6 + 1;

          } while (iVar7 < local_res20[0]);

        }

        lpMem[local_res20[0]] = 0;

        LocalFree(hMem);

        *param_1 = local_res20[0];

        *param_3 = lpMem;

        *param_2 = (longlong)lpMem;

        pcVar3 = (char *)0x0;

      }

    }

  }

  return pcVar3;

}




