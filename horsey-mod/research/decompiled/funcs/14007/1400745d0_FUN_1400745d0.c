// Address: 0x1400745d0
// Ghidra name: FUN_1400745d0
// ============ 0x1400745d0 FUN_1400745d0 (size=81) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400745d0(float *param_1)



{

  float fVar1;

  

  fVar1 = param_1[1] * _DAT_1403d94dc + *param_1 * _DAT_1403d94d8 + _DAT_1403d94e0;

  param_1[1] = param_1[1] * _DAT_1403d94e8 + *param_1 * _DAT_1403d94e4 + _DAT_1403d94ec;

  *param_1 = fVar1;

  return;

}




