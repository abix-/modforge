// Address: 0x140075b80
// Ghidra name: FUN_140075b80
// ============ 0x140075b80 FUN_140075b80 (size=61) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 FUN_140075b80(undefined4 *param_1)



{

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) <

      (ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18)) {

    *param_1 = 0;

    return 0;

  }

  *param_1 = *DAT_1403ead20;

  DAT_1403ead20 = DAT_1403ead20 + 1;

  return *param_1;

}




