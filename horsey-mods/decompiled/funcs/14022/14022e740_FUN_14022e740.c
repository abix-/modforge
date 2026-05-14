// Address: 0x14022e740
// Ghidra name: FUN_14022e740
// ============ 0x14022e740 FUN_14022e740 (size=1672) ============


void FUN_14022e740(char *param_1)



{

  char cVar1;

  code *pcVar2;

  LPWSTR lpWideCharStr;

  char cVar3;

  undefined4 uVar4;

  int iVar5;

  HMODULE hModule;

  FARPROC pFVar6;

  FARPROC pFVar7;

  WCHAR *pWVar8;

  LPWSTR lpWideCharStr_00;

  size_t sVar9;

  WCHAR *pWVar10;

  INT_PTR IVar11;

  longlong lVar12;

  undefined8 uVar13;

  longlong *plVar14;

  longlong *plVar15;

  ulonglong uVar16;

  char *pcVar17;

  char *lpProcName;

  WCHAR *pWVar18;

  undefined8 uVar19;

  LPCWSTR lpWideCharStr_01;

  ulonglong local_res8;

  undefined8 local_res10;

  LPWSTR local_res18;

  char *local_res20;

  undefined8 local_530;

  undefined8 local_528;

  undefined4 local_518 [2];

  WCHAR *local_510;

  undefined8 local_508;

  undefined8 local_500;

  undefined8 local_4f8;

  undefined8 local_4f0;

  LPWSTR local_4e8;

  undefined4 local_4e0;

  undefined8 local_4d8;

  WCHAR *local_4c8;

  WCHAR *local_4c0;

  uint local_4b8;

  undefined4 local_4b4;

  undefined8 local_4b0;

  undefined8 local_4a8;

  undefined8 local_4a0;

  undefined8 local_498;

  undefined4 local_484;

  CHAR local_478 [272];

  CHAR local_368 [272];

  WCHAR local_258;

  undefined1 local_256 [534];

  

  local_530 = *(undefined8 *)(param_1 + 8);

  pWVar18 = (WCHAR *)0x0;

  local_res20 = *(char **)(param_1 + 0x40);

  uVar19 = *(undefined8 *)(param_1 + 0x38);

  cVar1 = *param_1;

  pcVar17 = *(char **)(param_1 + 0x18);

  lVar12 = *(longlong *)(param_1 + 0x20);

  pcVar2 = *(code **)(param_1 + 0x30);

  local_res8 = CONCAT44(local_res8._4_4_,*(undefined4 *)(param_1 + 0x28));

  local_res10 = uVar19;

  cVar3 = FUN_14022efc0(cVar1 != '\0',pcVar17,lVar12,param_1[0x2c],pcVar2,uVar19,local_res20,

                        *(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x50),local_530,

                        *(undefined4 *)(param_1 + 0x10));

  if (cVar3 != '\0') {

    return;

  }

  hModule = LoadLibraryW(L"Comdlg32.dll");

  if (hModule == (HMODULE)0x0) {

    pcVar17 = "Couldn\'t load Comdlg32.dll";

  }

  else {

    lpProcName = "GetOpenFileNameW";

    if (cVar1 != '\0') {

      lpProcName = "GetSaveFileNameW";

    }

    pFVar6 = GetProcAddress(hModule,lpProcName);

    pFVar7 = GetProcAddress(hModule,"CommDlgExtendedError");

    if (pFVar6 == (FARPROC)0x0) {

      pcVar17 = "Couldn\'t load GetOpenFileName/GetSaveFileName from library";

    }

    else {

      if (pFVar7 != (FARPROC)0x0) {

        pWVar8 = pWVar18;

        if (lVar12 != 0) {

          uVar4 = FUN_14016ea50(lVar12);

          pWVar8 = (WCHAR *)FUN_140174d30(uVar4,"SDL.window.win32.hwnd",0);

        }

        local_258 = L'\0';

        FUN_1402f94c0(local_256,0,0x206);

        lpWideCharStr_00 = (LPWSTR)FUN_1401841f0(0x20000);

        local_res18 = lpWideCharStr_00;

        FUN_1402f94c0(lpWideCharStr_00,0,0x20000);

        if (pcVar17 != (char *)0x0) {

          sVar9 = strlen(pcVar17);

          if ((pcVar17[sVar9 - 1] == '\\') || (pcVar17[sVar9 - 1] == '/')) {

            MultiByteToWideChar(0xfde9,8,pcVar17,-1,&local_258,0x104);

          }

          else {

            MultiByteToWideChar(0xfde9,8,pcVar17,-1,lpWideCharStr_00,0x104);

            pWVar10 = pWVar18;

            do {

              if (lpWideCharStr_00[(longlong)pWVar10] == L'/') {

                lpWideCharStr_00[(longlong)pWVar10] = L'\\';

              }

              pWVar10 = (WCHAR *)((longlong)pWVar10 + 1);

            } while ((longlong)pWVar10 < 0x10000);

          }

        }

        pWVar10 = pWVar18;

        if (local_res20 != (char *)0x0) {

          sVar9 = strlen(local_res20);

          pWVar10 = (WCHAR *)FUN_140197820("UTF-16LE",&DAT_14039c6f0,local_res20,sVar9 + 1);

          if (pWVar10 == (WCHAR *)0x0) {

            FUN_1401841e0(lpWideCharStr_00);

            goto LAB_14022ed9f;

          }

        }

        local_500 = local_530;

        local_4c8 = &local_258;

        if (local_258 == L'\0') {

          local_4c8 = pWVar18;

        }

        local_518[0] = 0x98;

        local_4b8 = (uint)local_res8 | 0x8000c;

        local_508 = 0;

        local_4f8 = 0;

        local_4f0 = 0;

        local_4e0 = 0x10000;

        local_4d8 = 0;

        local_4b4 = 0;

        local_4b0 = 0;

        local_4a8 = 0;

        local_4a0 = 0;

        local_498 = 0;

        local_484 = 0;

        local_510 = pWVar8;

        local_4e8 = lpWideCharStr_00;

        local_4c0 = pWVar10;

        IVar11 = (*pFVar6)(local_518);

        FUN_1401841e0(pWVar10);

        lpWideCharStr = local_4e8;

        if ((int)IVar11 == 0) {

          IVar11 = (*pFVar7)();

          if ((int)IVar11 == 0) {

            local_res8 = 0;

            uVar4 = FUN_14022e610(local_4f0._4_4_);

            (*pcVar2)(uVar19,&local_res8,uVar4);

            FUN_1401841e0(lpWideCharStr_00);

            return;

          }

          uVar16 = (*pFVar7)();

          FUN_14012e850("Windows error, CommDlgExtendedError: %ld",uVar16 & 0xffffffff);

        }

        else {

          if ((local_res8 & 0x200) == 0) {

            lVar12 = FUN_14012fd40(local_4e8);

            uVar13 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_4e8,lVar12 * 2 + 2);

            local_528 = 0;

            local_530 = uVar13;

            uVar4 = FUN_14022e610(local_4f0._4_4_);

            (*pcVar2)(uVar19,&local_530,uVar4);

            FUN_1401841e0(uVar13);

            FUN_1401841e0(lpWideCharStr_00);

            return;

          }

          plVar14 = (longlong *)FUN_1401841f0(8);

          if (plVar14 == (longlong *)0x0) goto LAB_14022ed7b;

          *plVar14 = 0;

          iVar5 = WideCharToMultiByte(0xfde9,0,lpWideCharStr,-1,local_368,0x104,(LPCSTR)0x0,

                                      (LPBOOL)0x0);

          if (iVar5 == 0) {

            FUN_14012e850("Path too long or invalid character in path");

          }

          else {

            local_res8 = strlen(local_368);

            FUN_14012f1a0(local_478,local_368,0x104);

            local_478[local_res8] = '\\';

            lVar12 = FUN_14012fd40(lpWideCharStr);

            lpWideCharStr_01 = lpWideCharStr + lVar12 + 1;

            pWVar8 = pWVar18;

            if (*lpWideCharStr_01 != L'\0') {

              do {

                pWVar10 = (WCHAR *)((longlong)pWVar8 + 1);

                plVar15 = (longlong *)FUN_140184230(plVar14,(longlong)pWVar10 * 8 + 8);

                if (plVar15 == (longlong *)0x0) {

                  plVar15 = plVar14;

                  if (pWVar8 != (WCHAR *)0x0) {

                    do {

                      FUN_1401841e0(plVar14[(longlong)pWVar18]);

                      pWVar18 = (WCHAR *)((longlong)pWVar18 + 1);

                    } while (pWVar18 < pWVar8);

                  }

                  goto LAB_14022ecc4;

                }

                iVar5 = (int)local_res8 + 1;

                plVar15[(longlong)pWVar10] = 0;

                iVar5 = WideCharToMultiByte(0xfde9,0,lpWideCharStr_01,-1,local_478 + iVar5,

                                            0x104 - iVar5,(LPCSTR)0x0,(LPBOOL)0x0);

                if (iVar5 == 0) {

                  FUN_14012e850("Path too long or invalid character in path");

                  if (pWVar8 != (WCHAR *)0x0) {

                    do {

                      FUN_1401841e0(plVar15[(longlong)pWVar18]);

                      pWVar18 = (WCHAR *)((longlong)pWVar18 + 1);

                    } while (pWVar18 < pWVar8);

                  }

LAB_14022ecc4:

                  FUN_1401841e0(plVar15);

                  (*pcVar2)(local_res10,0,0xffffffff);

                  FUN_1401841e0(local_res18);

                  return;

                }

                lVar12 = FUN_14012fd40(lpWideCharStr_01);

                lpWideCharStr_01 = lpWideCharStr_01 + lVar12 + 1;

                lVar12 = FUN_14012f0d0(local_478);

                plVar15[(longlong)pWVar8] = lVar12;

                if (lVar12 == 0) {

                  if (pWVar8 != (WCHAR *)0x0) {

                    do {

                      FUN_1401841e0(plVar15[(longlong)pWVar18]);

                      pWVar18 = (WCHAR *)((longlong)pWVar18 + 1);

                    } while (pWVar18 < pWVar8);

                  }

                  goto LAB_14022ecc4;

                }

                plVar14 = plVar15;

                pWVar8 = pWVar10;

              } while (*lpWideCharStr_01 != L'\0');

              uVar19 = local_res10;

              lpWideCharStr_00 = local_res18;

              if (pWVar10 != (WCHAR *)0x0) goto LAB_14022ecec;

            }

            pWVar10 = (WCHAR *)0x1;

            plVar15 = (longlong *)FUN_140184230(plVar14,0x10);

            if (plVar15 != (longlong *)0x0) {

              plVar15[1] = 0;

              lVar12 = FUN_14012f0d0(local_368);

              *plVar15 = lVar12;

              if (lVar12 != 0) {

LAB_14022ecec:

                uVar4 = FUN_14022e610(local_4f0._4_4_);

                (*pcVar2)(local_res10,plVar15,uVar4);

                if (pWVar10 != (WCHAR *)0x0) {

                  do {

                    FUN_1401841e0(plVar15[(longlong)pWVar18]);

                    pWVar18 = (WCHAR *)((longlong)pWVar18 + 1);

                  } while (pWVar18 < pWVar10);

                }

                FUN_1401841e0(plVar15);

                FUN_1401841e0(local_res18);

                return;

              }

              FUN_1401841e0(plVar15);

              goto LAB_14022ed7b;

            }

          }

          FUN_1401841e0(plVar14);

        }

LAB_14022ed7b:

        (*pcVar2)(uVar19,0,0xffffffff);

        FUN_1401841e0(lpWideCharStr_00);

        return;

      }

      pcVar17 = "Couldn\'t load CommDlgExtendedError from library";

    }

  }

  FUN_14012e850(pcVar17);

LAB_14022ed9f:

  (*pcVar2)(uVar19,0,0xffffffff);

  return;

}




