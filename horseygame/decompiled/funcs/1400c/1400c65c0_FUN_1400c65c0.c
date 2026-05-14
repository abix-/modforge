// Address: 0x1400c65c0
// Ghidra name: FUN_1400c65c0
// ============ 0x1400c65c0 FUN_1400c65c0 (size=65) ============


int FUN_1400c65c0(int param_1,int param_2)



{

  ulonglong uVar1;

  

  uVar1 = DAT_1403da740 << 0xd ^ DAT_1403da740;

  uVar1 = uVar1 >> 7 ^ uVar1;

  DAT_1403da740 = uVar1 << 0x11 ^ uVar1;

  return param_1 + (int)(DAT_1403da740 % (ulonglong)(longlong)((param_2 - param_1) + 1));

}




