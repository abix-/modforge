// Address: 0x140221f30
// Ghidra name: FUN_140221f30
// ============ 0x140221f30 FUN_140221f30 (size=45) ============


undefined4 FUN_140221f30(uint *param_1)



{

  byte bVar1;

  

  bVar1 = (byte)*param_1 | 0x80;

  if ((*param_1 & 0xff00) != 0xe000) {

    bVar1 = (byte)*param_1;

  }

  return *(undefined4 *)(&DAT_140355f00 + (ulonglong)bVar1 * 4);

}




