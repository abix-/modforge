// Address: 0x140214c20
// Ghidra name: FUN_140214c20
// ============ 0x140214c20 FUN_140214c20 (size=230) ============


undefined8 FUN_140214c20(void)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  undefined1 *local_18;

  code *local_10;

  

  local_18 = &LAB_140214910;

  local_10 = FUN_140214920;

  iVar2 = FUN_1401a9610();

  if (iVar2 < 0) {

    uVar3 = FUN_14012e850("CoInitialize() failed");

    return uVar3;

  }

  cVar1 = FUN_140289d20(&local_18);

  if (cVar1 != '\0') {

    DAT_1403fdac0 = 1;

    DAT_1403fdaa8 = LoadLibraryW(L"avrt.dll");

    if (DAT_1403fdaa8 != (HMODULE)0x0) {

      DAT_1403fdab0 = GetProcAddress(DAT_1403fdaa8,"AvSetMmThreadCharacteristicsW");

      DAT_1403fdab8 = GetProcAddress(DAT_1403fdaa8,"AvRevertMmThreadCharacteristics");

    }

    DAT_1403fdad8 = FUN_140179a30();

    if (DAT_1403fdad8 != 0) {

      DAT_1403fdae0 = FUN_140160230();

      if (DAT_1403fdae0 != 0) {

        return 1;

      }

      FUN_140179b30(DAT_1403fdad8);

      DAT_1403fdad8 = 0;

    }

    FUN_140214950();

  }

  return 0;

}




