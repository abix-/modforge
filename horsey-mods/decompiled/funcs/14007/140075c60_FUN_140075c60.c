// Address: 0x140075c60
// Ghidra name: FUN_140075c60
// ============ 0x140075c60 FUN_140075c60 (size=62) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_140075c60(int *param_1)



{

  char cVar1;

  

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) <

      (ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18)) {

    *param_1 = 0;

    return 0;

  }

  cVar1 = *DAT_1403ead20;

  DAT_1403ead20 = DAT_1403ead20 + 1;

  *param_1 = (int)cVar1;

  return (int)cVar1;

}




