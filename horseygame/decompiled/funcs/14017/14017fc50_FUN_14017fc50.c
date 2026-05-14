// Address: 0x14017fc50
// Ghidra name: FUN_14017fc50
// ============ 0x14017fc50 FUN_14017fc50 (size=59) ============


DWORD FUN_14017fc50(void)



{

  _SYSTEM_INFO local_38;

  

  if (DAT_1403fc6a8 == 0) {

    GetSystemInfo(&local_38);

    DAT_1403fc6a8 = local_38.dwNumberOfProcessors;

    if ((int)local_38.dwNumberOfProcessors < 1) {

      DAT_1403fc6a8 = 1;

    }

  }

  return DAT_1403fc6a8;

}




