// Address: 0x14017fcb0
// Ghidra name: FUN_14017fcb0
// ============ 0x14017fcb0 FUN_14017fcb0 (size=57) ============


DWORD FUN_14017fcb0(void)



{

  _SYSTEM_INFO local_38;

  

  if (DAT_1403e2900 == 0xffffffff) {

    GetSystemInfo(&local_38);

    DAT_1403e2900 = local_38.dwPageSize;

    if ((int)local_38.dwPageSize < 0) {

      DAT_1403e2900 = 0;

    }

  }

  return DAT_1403e2900;

}




