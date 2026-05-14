// Address: 0x1401aae20
// Ghidra name: FUN_1401aae20
// ============ 0x1401aae20 FUN_1401aae20 (size=50) ============


int FUN_1401aae20(int param_1)



{

  uint uVar1;

  

  if (param_1 < 1) {

    return 1;

  }

  uVar1 = (int)(param_1 - 1U) >> 1 | param_1 - 1U;

  uVar1 = (int)uVar1 >> 2 | uVar1;

  uVar1 = (int)uVar1 >> 4 | uVar1;

  uVar1 = (int)uVar1 >> 8 | uVar1;

  return ((int)uVar1 >> 0x10 | uVar1) + 1;

}




