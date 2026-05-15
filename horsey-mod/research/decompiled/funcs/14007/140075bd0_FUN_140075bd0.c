// Address: 0x140075bd0
// Ghidra name: FUN_140075bd0
// ============ 0x140075bd0 FUN_140075bd0 (size=68) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_140075bd0(int *param_1)



{

  int iVar1;

  

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) <

      (ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18)) {

    *param_1 = 0;

    return 0;

  }

  iVar1 = *DAT_1403ead20;

  *param_1 = iVar1;

  if (iVar1 + 1U < 5) {

    DAT_1403ead20 = DAT_1403ead20 + 1;

  }

  return *param_1;

}




