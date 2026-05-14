// Address: 0x140075e30
// Ghidra name: FUN_140075e30
// ============ 0x140075e30 FUN_140075e30 (size=59) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_140075e30(byte *param_1)



{

  ulonglong uVar1;

  

  uVar1 = (longlong)DAT_1403ead20 - _DAT_1403ead18;

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) < uVar1) {

    *param_1 = 0;

    return uVar1 & 0xffffffffffffff00;

  }

  *param_1 = *DAT_1403ead20;

  DAT_1403ead20 = DAT_1403ead20 + 1;

  return (ulonglong)*param_1;

}




