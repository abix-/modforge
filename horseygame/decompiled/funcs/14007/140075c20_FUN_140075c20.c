// Address: 0x140075c20
// Ghidra name: FUN_140075c20
// ============ 0x140075c20 FUN_140075c20 (size=58) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_140075c20(void)



{

  uint7 uVar1;

  

  uVar1 = (uint7)((ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18) >> 8);

  if (((ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18) <=

       (ulonglong)(DAT_1403ead30 - DAT_1403ead28)) && (*DAT_1403ead20 == -1)) {

    DAT_1403ead20 = DAT_1403ead20 + 1;

    return CONCAT71(uVar1,1);

  }

  return (ulonglong)uVar1 << 8;

}




