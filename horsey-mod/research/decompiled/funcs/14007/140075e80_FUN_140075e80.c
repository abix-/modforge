// Address: 0x140075e80
// Ghidra name: FUN_140075e80
// ============ 0x140075e80 FUN_140075e80 (size=65) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_140075e80(undefined1 *param_1)



{

  int iVar1;

  ulonglong uVar2;

  

  uVar2 = (longlong)DAT_1403ead20 - _DAT_1403ead18;

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) < uVar2) {

    *param_1 = 0;

    return uVar2 & 0xffffffffffffff00;

  }

  iVar1 = *DAT_1403ead20;

  DAT_1403ead20 = DAT_1403ead20 + 1;

  *param_1 = iVar1 == 1;

  return (ulonglong)CONCAT31((int3)((uint)iVar1 >> 8),iVar1 == 1);

}




