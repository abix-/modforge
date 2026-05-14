// Address: 0x14017fcf0
// Ghidra name: FUN_14017fcf0
// ============ 0x14017fcf0 FUN_14017fcf0 (size=68) ============


ulonglong FUN_14017fcf0(void)



{

  BOOL BVar1;

  _MEMORYSTATUSEX local_48;

  

  if (DAT_1403fc6ac == 0) {

    local_48.dwLength = 0x40;

    BVar1 = GlobalMemoryStatusEx(&local_48);

    if (BVar1 != 0) {

      DAT_1403fc6ac = (int)(local_48.ullTotalPhys >> 0x14);

      return local_48.ullTotalPhys >> 0x14;

    }

  }

  return (ulonglong)DAT_1403fc6ac;

}




