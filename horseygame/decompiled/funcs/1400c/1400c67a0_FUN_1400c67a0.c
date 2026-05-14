// Address: 0x1400c67a0
// Ghidra name: FUN_1400c67a0
// ============ 0x1400c67a0 FUN_1400c67a0 (size=167) ============


undefined4

FUN_1400c67a0(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,

             undefined4 param_6,int param_7,undefined4 param_8)



{

  int iVar1;

  ulonglong uVar2;

  

  uVar2 = DAT_1403da740 << 0xd ^ DAT_1403da740;

  uVar2 = uVar2 >> 7 ^ uVar2;

  param_5 = param_5 + param_1 + param_3;

  DAT_1403da740 = uVar2 << 0x11 ^ uVar2;

  iVar1 = (int)(DAT_1403da740 % (ulonglong)(longlong)(param_7 + param_5));

  if (iVar1 < param_1) {

    return param_2;

  }

  if (iVar1 < param_1 + param_3) {

    return param_4;

  }

  if (iVar1 < param_5) {

    param_8 = param_6;

  }

  return param_8;

}




