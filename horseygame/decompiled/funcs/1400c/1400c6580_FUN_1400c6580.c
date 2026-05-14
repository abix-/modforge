// Address: 0x1400c6580
// Ghidra name: FUN_1400c6580
// ============ 0x1400c6580 FUN_1400c6580 (size=56) ============


ulonglong FUN_1400c6580(int param_1)



{

  ulonglong uVar1;

  

  uVar1 = DAT_1403da740 << 0xd ^ DAT_1403da740;

  uVar1 = uVar1 >> 7 ^ uVar1;

  DAT_1403da740 = uVar1 << 0x11 ^ uVar1;

  return DAT_1403da740 % (ulonglong)(longlong)param_1 & 0xffffffff;

}




