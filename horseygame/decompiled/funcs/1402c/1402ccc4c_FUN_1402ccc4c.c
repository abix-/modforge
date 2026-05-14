// Address: 0x1402ccc4c
// Ghidra name: FUN_1402ccc4c
// ============ 0x1402ccc4c FUN_1402ccc4c (size=343) ============


FARPROC FUN_1402ccc4c(uint param_1,LPCSTR param_2,uint *param_3,uint *param_4)



{

  longlong lVar1;

  wchar_t *lpLibFileName;

  DWORD DVar2;

  int iVar3;

  HMODULE hLibModule;

  FARPROC pFVar4;

  longlong *plVar5;

  ulonglong uVar6;

  

  uVar6 = (ulonglong)param_1;

  pFVar4 = *(FARPROC *)(&DAT_1403fece0 + uVar6 * 8);

  if (pFVar4 != (FARPROC)0xffffffffffffffff) {

    if (pFVar4 != (FARPROC)0x0) {

      return pFVar4;

    }

    for (; param_3 != param_4; param_3 = param_3 + 1) {

      plVar5 = (longlong *)(&DAT_1403fecc8 + (ulonglong)*param_3 * 8);

      hLibModule = (HMODULE)*plVar5;

      if (hLibModule == (HMODULE)0x0) {

        lpLibFileName = (wchar_t *)(&PTR_u_api_ms_win_core_fibers_l1_1_1_1403881f8)[*param_3];

        hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0x800);

        if ((hLibModule != (HMODULE)0x0) ||

           (((DVar2 = GetLastError(), DVar2 == 0x57 &&

             (iVar3 = wcsncmp(lpLibFileName,L"api-ms-",7), iVar3 != 0)) &&

            (hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0), hLibModule != (HMODULE)0x0)))

           ) {

          LOCK();

          lVar1 = *plVar5;

          *plVar5 = (longlong)hLibModule;

          UNLOCK();

          if (lVar1 != 0) {

            FreeLibrary(hLibModule);

          }

          goto LAB_1402ccd7e;

        }

        LOCK();

        *plVar5 = -1;

        UNLOCK();

      }

      else if (hLibModule != (HMODULE)0xffffffffffffffff) {

LAB_1402ccd7e:

        pFVar4 = GetProcAddress(hLibModule,param_2);

        if (pFVar4 != (FARPROC)0x0) {

          LOCK();

          *(FARPROC *)(&DAT_1403fece0 + uVar6 * 8) = pFVar4;

          UNLOCK();

          return pFVar4;

        }

        break;

      }

    }

    LOCK();

    *(undefined8 *)(&DAT_1403fece0 + uVar6 * 8) = 0xffffffffffffffff;

    UNLOCK();

  }

  return (FARPROC)0x0;

}




