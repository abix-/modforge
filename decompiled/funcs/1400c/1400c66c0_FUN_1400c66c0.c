// Address: 0x1400c66c0
// Ghidra name: FUN_1400c66c0
// ============ 0x1400c66c0 FUN_1400c66c0 (size=50) ============


ulonglong FUN_1400c66c0(void)



{

  ulonglong uVar1;

  

  uVar1 = DAT_1403da740 << 0xd ^ DAT_1403da740;

  uVar1 = uVar1 >> 7 ^ uVar1;

  DAT_1403da740 = uVar1 << 0x11 ^ uVar1;

  return CONCAT71((int7)(DAT_1403da740 >> 8),~(byte)uVar1) & 0xffffffffffffff01;

}




