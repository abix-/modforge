// Address: 0x14022d320
// Ghidra name: FUN_14022d320
// ============ 0x14022d320 FUN_14022d320 (size=285) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14022d320(undefined8 param_1,int param_2)



{

  DWORD DVar1;

  char *pcVar2;

  HANDLE local_18;

  HANDLE local_10;

  

  FUN_14022d050(&DAT_1403e5510);

  if (param_2 == 0) {

    return 1;

  }

  _DAT_1403e5514 = param_2;

  DAT_1403e5518 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);

  if (DAT_1403e5518 != (HANDLE)0xffffffffffffffff) {

    DAT_1403e5510 = 0;

    _DAT_1403e5520 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);

    if (_DAT_1403e5520 != (HANDLE)0xffffffffffffffff) {

      _DAT_1403e5528 =

           CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_14022d0d0,&DAT_1403e5510,0,(LPDWORD)0x0);

      if (_DAT_1403e5528 != (HANDLE)0xffffffffffffffff) {

        local_18 = DAT_1403e5518;

        local_10 = _DAT_1403e5528;

        DVar1 = WaitForMultipleObjects(2,&local_18,0,0xffffffff);

        if (DVar1 == 0) {

          return 1;

        }

        FUN_14012e850("Couldn\'t set up raw input handling");

        FUN_14022d050(&DAT_1403e5510);

        return 0;

      }

      pcVar2 = "CreateThread";

      _DAT_1403e5528 = (HANDLE)0xffffffffffffffff;

      goto LAB_14022d41c;

    }

  }

  pcVar2 = "CreateEvent";

LAB_14022d41c:

  FUN_1401a9ed0(pcVar2);

  FUN_14022d050(&DAT_1403e5510);

  return 0;

}




