// Address: 0x1400c6940
// Ghidra name: FUN_1400c6940
// ============ 0x1400c6940 FUN_1400c6940 (size=108) ============


/* WARNING: Removing unreachable block (ram,0x0001400c6982) */



float FUN_1400c6940(float param_1,float param_2)



{

  ulonglong uVar1;

  

  uVar1 = DAT_1403da740 << 0xd ^ DAT_1403da740;

  uVar1 = uVar1 >> 7 ^ uVar1;

  DAT_1403da740 = uVar1 << 0x11 ^ uVar1;

  return (float)(DAT_1403da740 & 0xffff) * DAT_1403053bc * (param_2 - param_1) + param_1;

}




