// Address: 0x14022da90
// Ghidra name: FUN_14022da90
// ============ 0x14022da90 FUN_14022da90 (size=124) ============


void FUN_14022da90(undefined8 param_1,undefined8 param_2)



{

  if ((DAT_1403fdcf8 == (HMODULE)0x0) &&

     (DAT_1403fdcf8 = GetModuleHandleW(L"kernel32.dll"), DAT_1403fdcf8 != (HMODULE)0x0)) {

    DAT_1403fdcf0 = GetProcAddress(DAT_1403fdcf8,"GetUserPreferredUILanguages");

  }

  if (DAT_1403fdcf0 != (FARPROC)0x0) {

    FUN_14022db10(param_1,param_2);

    return;

  }

  FUN_14022dc40();

  return;

}




