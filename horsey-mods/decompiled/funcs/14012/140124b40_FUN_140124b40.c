// Address: 0x140124b40
// Ghidra name: FUN_140124b40
// ============ 0x140124b40 FUN_140124b40 (size=308) ============


void FUN_140124b40(void)



{

  code *pcVar1;

  DWORD DVar2;

  int iVar3;

  LPCSTR lpLibFileName;

  HMODULE hModule;

  FARPROC pFVar4;

  INT_PTR IVar5;

  char *pcVar6;

  char cVar7;

  LPCSTR pCVar8;

  bool bVar9;

  char local_208;

  char local_207 [511];

  

  DVar2 = GetEnvironmentVariableA("SDL3_DYNAMIC_API",&local_208,0x200);

  if (0x1fe < DVar2 - 1) goto LAB_140124c29;

  pFVar4 = (FARPROC)0x0;

  lpLibFileName = &local_208;

  if (local_208 == '\0') {

LAB_140124c1d:

    pcVar6 = 

    "Couldn\'t load an overriding SDL library. Please fix or remove the SDL3_DYNAMIC_API environment variable. Using the default SDL."

    ;

  }

  else {

    do {

      if (pFVar4 != (FARPROC)0x0) goto LAB_140124bfc;

      cVar7 = *lpLibFileName;

      pCVar8 = lpLibFileName;

      while ((cVar7 != ',' && (bVar9 = cVar7 != '\0', cVar7 = '\0', bVar9))) {

        pcVar6 = pCVar8 + 1;

        pCVar8 = pCVar8 + 1;

        cVar7 = *pcVar6;

      }

      *pCVar8 = '\0';

      hModule = LoadLibraryA(lpLibFileName);

      pFVar4 = (FARPROC)0x0;

      if ((hModule != (HMODULE)0x0) &&

         (pFVar4 = GetProcAddress(hModule,"SDL_DYNAPI_entry"), pFVar4 == (FARPROC)0x0)) {

        FreeLibrary(hModule);

      }

      *pCVar8 = cVar7;

    } while ((cVar7 != '\0') && (lpLibFileName = pCVar8 + 1, pCVar8[1] != '\0'));

    if (pFVar4 == (FARPROC)0x0) goto LAB_140124c1d;

LAB_140124bfc:

    IVar5 = (*pFVar4)(2,&PTR_FUN_1403dc480,0x27b0);

    if (-1 < (int)IVar5) {

      return;

    }

    pcVar6 = 

    "Couldn\'t override SDL library. Using a newer SDL build might help. Please fix or remove the SDL3_DYNAMIC_API environment variable. Using the default SDL."

    ;

  }

  FUN_140127770(pcVar6);

LAB_140124c29:

  iVar3 = FUN_140127790(2,&PTR_FUN_1403dc480,0x27b0);

  if (-1 < iVar3) {

    return;

  }

  FUN_140127770(

               "Failed to initialize internal SDL dynapi. As this would otherwise crash, we have to abort now."

               );

  FUN_14017e1a0(0x56);

  pcVar1 = (code *)swi(3);

  (*pcVar1)();

  return;

}




