// Address: 0x140230ca0
// Ghidra name: FUN_140230ca0
// ============ 0x140230ca0 FUN_140230ca0 (size=25) ============


uint FUN_140230ca0(int param_1)



{

  uint uVar1;

  

  uVar1 = param_1 >> 6;

  if ((int)uVar1 < 0) {

    return 0;

  }

  if (0x3ff < (int)uVar1) {

    uVar1 = 0x3ff;

  }

  return uVar1 & 0xffff;

}




