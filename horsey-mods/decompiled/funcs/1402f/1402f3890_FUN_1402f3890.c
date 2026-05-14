// Address: 0x1402f3890
// Ghidra name: FUN_1402f3890
// ============ 0x1402f3890 FUN_1402f3890 (size=862) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



ulonglong FUN_1402f3890(char *param_1,char *param_2,longlong *param_3)



{

  byte bVar1;

  char *pcVar2;

  int iVar3;

  uint uVar4;

  BOOL BVar5;

  ulonglong uVar6;

  HANDLE hFindFile;

  LPCWSTR pWVar7;

  char *pcVar8;

  longlong lVar9;

  longlong lVar10;

  byte bVar11;

  undefined8 uVar12;

  LPCWSTR pWVar13;

  undefined1 auStackY_378 [32];

  undefined1 local_348 [8];

  ulonglong local_340;

  undefined8 local_338;

  undefined8 local_330;

  LPCWSTR local_328;

  undefined8 local_320;

  undefined8 local_318;

  char local_310;

  longlong local_308;

  longlong local_300;

  char local_2f0;

  longlong local_2e8;

  longlong local_2e0;

  char local_2d0;

  undefined8 local_2c8;

  undefined8 local_2c0;

  char *local_2b8;

  undefined8 local_2b0;

  undefined8 local_2a8;

  char local_2a0;

  _WIN32_FIND_DATAW local_298;

  ulonglong local_48;

  

  local_48 = DAT_1403e8b00 ^ (ulonglong)auStackY_378;

  while ((param_2 != param_1 &&

         ((0x2d < (byte)(*param_2 - 0x2fU) ||

          ((0x200000000801U >> ((longlong)(char)(*param_2 - 0x2fU) & 0x3fU) & 1) == 0))))) {

    param_2 = (char *)FUN_1402f81ec(param_1);

  }

  if ((*param_2 == ':') && (param_2 != param_1 + 1)) {

    uVar6 = FUN_1402f370c(param_1,0,0,param_3);

  }

  else {

    bVar11 = *param_2 - 0x2f;

    pWVar13 = (LPCWSTR)0x0;

    if ((0x2d < bVar11) ||

       (bVar1 = 1, (0x200000000801U >> ((longlong)(char)bVar11 & 0x3fU) & 1) == 0)) {

      bVar1 = 0;

    }

    uVar6 = -(ulonglong)bVar1 & (ulonglong)(param_2 + (1 - (longlong)param_1));

    local_340 = uVar6;

    FUN_1402f94c0(&local_298,0,0x250);

    local_338 = 0;

    local_330 = 0;

    local_328 = (LPCWSTR)0x0;

    local_320 = 0;

    local_318 = 0;

    local_310 = '\0';

    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_308,(__crt_locale_pointers *)0x0);

    if (*(int *)(local_300 + 0xc) == 0xfde9) {

      if (local_2f0 != '\0') {

        *(uint *)(local_308 + 0x3a8) = *(uint *)(local_308 + 0x3a8) & 0xfffffffd;

      }

      pWVar7 = (LPCWSTR)0xfde9;

    }

    else {

      iVar3 = FUN_1402ec34c();

      if (iVar3 == 0) {

        if (local_2f0 != '\0') {

          *(uint *)(local_308 + 0x3a8) = *(uint *)(local_308 + 0x3a8) & 0xfffffffd;

        }

        pWVar7 = (LPCWSTR)0x1;

      }

      else {

        pWVar7 = pWVar13;

        if (local_2f0 != '\0') {

          *(uint *)(local_308 + 0x3a8) = *(uint *)(local_308 + 0x3a8) & 0xfffffffd;

        }

      }

    }

    iVar3 = FUN_1402e68f8(param_1,&local_338,local_348,pWVar7);

    pWVar7 = local_328;

    if (iVar3 != 0) {

      pWVar7 = pWVar13;

    }

    hFindFile = FindFirstFileExW(pWVar7,FindExInfoStandard,&local_298,FindExSearchNameMatch,

                                 (LPVOID)0x0,0);

    if (hFindFile == (HANDLE)0xffffffffffffffff) {

      uVar4 = FUN_1402f370c(param_1,0,0,param_3);

      uVar6 = (ulonglong)uVar4;

      if (local_310 != '\0') {

        FUN_1402e9a80(local_328);

      }

    }

    else {

      lVar10 = param_3[1] - *param_3 >> 3;

      do {

        uVar12 = 0;

        local_2c8 = 0;

        local_2c0 = 0;

        local_2b8 = (char *)0x0;

        local_2b0 = 0;

        local_2a8 = 0;

        local_2a0 = '\0';

        _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_2e8,(__crt_locale_pointers *)0x0);

        if (*(int *)(local_2e0 + 0xc) == 0xfde9) {

          if (local_2d0 != '\0') {

            *(uint *)(local_2e8 + 0x3a8) = *(uint *)(local_2e8 + 0x3a8) & 0xfffffffd;

          }

          uVar12 = 0xfde9;

        }

        else {

          iVar3 = FUN_1402ec34c();

          if (iVar3 == 0) {

            if (local_2d0 != '\0') {

              *(uint *)(local_2e8 + 0x3a8) = *(uint *)(local_2e8 + 0x3a8) & 0xfffffffd;

            }

            uVar12 = 1;

          }

          else if (local_2d0 != '\0') {

            *(uint *)(local_2e8 + 0x3a8) = *(uint *)(local_2e8 + 0x3a8) & 0xfffffffd;

          }

        }

        iVar3 = FUN_1402f3324(local_298.cFileName,&local_2c8,local_348,uVar12);

        pcVar2 = local_2b8;

        pcVar8 = local_2b8;

        if (iVar3 != 0) {

          pcVar8 = (char *)0x0;

        }

        if ((*pcVar8 == '.') && ((pcVar8[1] == '\0' || ((pcVar8[1] == '.' && (pcVar8[2] == '\0')))))

           ) {

          if (local_2a0 != '\0') {

            FUN_1402e9a80(local_2b8);

          }

        }

        else {

          uVar4 = FUN_1402f370c(pcVar8,param_1,uVar6,param_3);

          if (uVar4 != 0) {

            if (local_2a0 != '\0') {

              FUN_1402e9a80(pcVar2);

            }

            FindClose(hFindFile);

            if (local_310 == '\0') {

              return (ulonglong)uVar4;

            }

            FUN_1402e9a80(local_328);

            return (ulonglong)uVar4;

          }

          uVar6 = local_340;

          if (local_2a0 != '\0') {

            FUN_1402e9a80(pcVar2);

            uVar6 = local_340;

          }

        }

        BVar5 = FindNextFileW(hFindFile,&local_298);

      } while (BVar5 != 0);

      lVar9 = param_3[1] - *param_3 >> 3;

      if (lVar10 != lVar9) {

        FUN_1402cf520(*param_3 + lVar10 * 8,lVar9 - lVar10,8,&LAB_1402f3310);

      }

      FindClose(hFindFile);

      if (local_310 != '\0') {

        FUN_1402e9a80(local_328);

      }

      uVar6 = 0;

    }

  }

  return uVar6;

}




