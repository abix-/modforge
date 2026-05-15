// Address: 0x14021ce90
// Ghidra name: FUN_14021ce90
// ============ 0x14021ce90 FUN_14021ce90 (size=628) ============


bool FUN_14021ce90(char *param_1,code *param_2,undefined8 param_3)



{

  undefined1 uVar1;

  DWORD DVar2;

  int iVar3;

  BOOL BVar4;

  size_t sVar5;

  LPCWSTR lpFileName;

  HANDLE hFindFile;

  longlong lVar6;

  int iVar7;

  bool bVar8;

  char *local_res8;

  _WIN32_FIND_DATAW local_268;

  

  iVar3 = 0;

  if (*param_1 == '\0') {

    DVar2 = GetLogicalDrives();

    local_res8 = (char *)CONCAT44(local_res8._4_4_,0x5c3a00);

    iVar7 = 0x41;

    do {

      if (0x5a < iVar7) goto LAB_14021d0f9;

      if ((DVar2 >> (iVar7 - 0x41U & 0x1f) & 1) != 0) {

        local_res8 = (char *)CONCAT71(local_res8._1_7_,(char)iVar7);

        iVar3 = (*param_2)(param_3,&DAT_14039bcb9,&local_res8);

      }

      iVar7 = iVar7 + 1;

    } while (iVar3 == 0);

    bVar8 = iVar3 != 2;

  }

  else {

    local_res8 = (char *)0x0;

    iVar7 = FUN_14012ee40(&local_res8,&DAT_14035583c,param_1);

    if ((iVar7 != -1) && (local_res8 != (char *)0x0)) {

      iVar7 = iVar7 + -1;

      lVar6 = (longlong)iVar7;

      if (0 < iVar7) {

        do {

          if ((local_res8[lVar6] != '\\') && (local_res8[lVar6] != '/')) break;

          local_res8[lVar6] = '\0';

          iVar7 = iVar7 + -1;

          lVar6 = lVar6 + -1;

        } while (0 < lVar6);

      }

      local_res8[(longlong)iVar7 + 1] = '\\';

      lVar6 = (longlong)(iVar7 + 2);

      local_res8[lVar6] = '*';

      local_res8[lVar6 + 1] = '\0';

      sVar5 = strlen(local_res8);

      lpFileName = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,local_res8,sVar5 + 1);

      if (lpFileName != (LPCWSTR)0x0) {

        local_res8[lVar6] = '\0';

        hFindFile = FindFirstFileExW(lpFileName,FindExInfoStandard,&local_268,FindExSearchNameMatch,

                                     (LPVOID)0x0,0);

        FUN_1401841e0(lpFileName);

        if (hFindFile == (HANDLE)0xffffffffffffffff) {

          FUN_1401841e0(local_res8);

          uVar1 = FUN_1401a9ed0("Failed to enumerate directory");

          return (bool)uVar1;

        }

        do {

          if ((local_268.cFileName[0] != L'.') ||

             ((local_268.cFileName[1] != L'\0' &&

              ((local_268.cFileName[1] != L'.' || (local_268.cFileName[2] != L'\0')))))) {

            lVar6 = FUN_14012fd40(local_268.cFileName);

            lVar6 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_268.cFileName,lVar6 * 2 + 2);

            if (lVar6 == 0) {

              iVar3 = 2;

              break;

            }

            iVar3 = (*param_2)(param_3,local_res8,lVar6);

            FUN_1401841e0(lVar6);

            if (iVar3 != 0) break;

          }

          BVar4 = FindNextFileW(hFindFile,&local_268);

        } while (BVar4 != 0);

        FindClose(hFindFile);

        FUN_1401841e0(local_res8);

LAB_14021d0f9:

        return iVar3 != 2;

      }

      FUN_1401841e0(local_res8);

    }

    bVar8 = false;

  }

  return bVar8;

}




