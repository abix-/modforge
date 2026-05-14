// Address: 0x140075d50
// Ghidra name: FUN_140075d50
// ============ 0x140075d50 FUN_140075d50 (size=64) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140075d50(undefined8 *param_1)



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




