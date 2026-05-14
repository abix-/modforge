// Address: 0x1400c6700
// Ghidra name: FUN_1400c6700
// ============ 0x1400c6700 FUN_1400c6700 (size=53) ============


undefined4 FUN_1400c6700(undefined4 param_1,undefined4 param_2)



{

  ulonglong uVar1;

  

  uVar1 = DAT_1403da740 << 0xd ^ DAT_1403da740;

  uVar1 = uVar1 >> 7 ^ uVar1;

  DAT_1403da740 = uVar1 << 0x11 ^ uVar1;

  if ((DAT_1403da740 & 1) == 0) {

    param_2 = param_1;

  }

  return param_2;

}




