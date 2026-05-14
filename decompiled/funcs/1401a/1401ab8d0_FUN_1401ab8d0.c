// Address: 0x1401ab8d0
// Ghidra name: FUN_1401ab8d0
// ============ 0x1401ab8d0 FUN_1401ab8d0 (size=570) ============


ulonglong FUN_1401ab8d0(undefined8 *param_1)



{

  BOOL BVar1;

  HMODULE hModule;

  HMODULE hModule_00;

  undefined4 extraout_var;

  HMODULE hModule_01;

  INT_PTR IVar2;

  undefined4 extraout_var_00;

  

  hModule = LoadLibraryW(L"Mf.dll");

  if (hModule == (HMODULE)0x0) {

    return 0;

  }

  hModule_00 = LoadLibraryW(L"Mfplat.dll");

  if (hModule_00 != (HMODULE)0x0) {

    hModule_01 = LoadLibraryW(L"Mfreadwrite.dll");

    if (hModule_01 != (HMODULE)0x0) {

      DAT_1403fcdc0 = GetProcAddress(hModule,"MFEnumDeviceSources");

      if ((((((DAT_1403fcdc0 != (FARPROC)0x0) &&

             (DAT_1403fcdc8 = GetProcAddress(hModule,"MFCreateDeviceSource"),

             DAT_1403fcdc8 != (FARPROC)0x0)) &&

            (DAT_1403fcdd8 = GetProcAddress(hModule_00,"MFStartup"), DAT_1403fcdd8 != (FARPROC)0x0))

           && ((DAT_1403fcde0 = GetProcAddress(hModule_00,"MFShutdown"),

               DAT_1403fcde0 != (FARPROC)0x0 &&

               (DAT_1403fcde8 = GetProcAddress(hModule_00,"MFCreateAttributes"),

               DAT_1403fcde8 != (FARPROC)0x0)))) &&

          ((DAT_1403fcdf0 = GetProcAddress(hModule_00,"MFCreateMediaType"),

           DAT_1403fcdf0 != (FARPROC)0x0 &&

           ((DAT_1403fcdf8 = GetProcAddress(hModule_00,"MFGetStrideForBitmapInfoHeader"),

            DAT_1403fcdf8 != (FARPROC)0x0 &&

            (DAT_1403fce08 = GetProcAddress(hModule_01,"MFCreateSourceReaderFromMediaSource"),

            DAT_1403fce08 != (FARPROC)0x0)))))) &&

         (IVar2 = (*DAT_1403fcdd8)(0x20070,1), -1 < (int)IVar2)) {

        DAT_1403fcdb8 = hModule;

        *param_1 = FUN_1401ac630;

        param_1[1] = FUN_1401ac730;

        param_1[2] = FUN_1401ac4c0;

        param_1[3] = FUN_1401aca90;

        param_1[4] = FUN_1401ac230;

        param_1[5] = &LAB_1401aca80;

        param_1[6] = &LAB_1401ac720;

        param_1[7] = FUN_1401ac5a0;

        DAT_1403fcdd0 = hModule_00;

        DAT_1403fce00 = hModule_01;

        return 0x1401ac501;

      }

      FreeLibrary(hModule_01);

    }

    FreeLibrary(hModule_00);

    BVar1 = FreeLibrary(hModule);

    return CONCAT44(extraout_var_00,BVar1) & 0xffffffffffffff00;

  }

  BVar1 = FreeLibrary(hModule);

  return CONCAT44(extraout_var,BVar1) & 0xffffffffffffff00;

}




