// Address: 0x1402205c0
// Ghidra name: FUN_1402205c0
// ============ 0x1402205c0 FUN_1402205c0 (size=307) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402205c0(void)



{

  FARPROC pFVar1;

  undefined4 local_1a8 [2];

  undefined4 local_1a0;

  undefined4 local_198;

  undefined4 uStack_194;

  undefined4 uStack_190;

  undefined4 uStack_18c;

  

  DAT_1403fdbbc = DAT_1403fdbbc + 1;

  if (DAT_1403fdbbc < 2) {

    FUN_140139010();

    DAT_1403e54a0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);

    DAT_1403fdbe8 = FUN_140163260(FUN_140220530,"DeviceHotplugThread",0,FUN_1402cfa08,FUN_1402cfae8)

    ;

    DAT_1403fdbc0 = LoadLibraryA("cfgmgr32.dll");

    if (DAT_1403fdbc0 != (HMODULE)0x0) {

      DAT_1403fdbc8 = GetProcAddress(DAT_1403fdbc0,"CM_Register_Notification");

      DAT_1403fdbd0 = GetProcAddress(DAT_1403fdbc0,"CM_Unregister_Notification");

      pFVar1 = DAT_1403fdbc8;

      if ((DAT_1403fdbc8 != (FARPROC)0x0) && (DAT_1403fdbd0 != (FARPROC)0x0)) {

        FUN_1402f94c0(local_1a8,0,0x1a0);

        local_1a8[0] = 0x1a0;

        local_1a0 = 0;

        local_198 = _DAT_1403e5488;

        uStack_194 = uRam00000001403e548c;

        uStack_190 = uRam00000001403e5490;

        uStack_18c = uRam00000001403e5494;

        (*pFVar1)(local_1a8,0,FUN_140220580,&DAT_1403fdbd8);

      }

    }

  }

  return;

}




