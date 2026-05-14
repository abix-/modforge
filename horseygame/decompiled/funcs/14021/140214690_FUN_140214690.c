// Address: 0x140214690
// Ghidra name: FUN_140214690
// ============ 0x140214690 FUN_140214690 (size=54) ============


float FUN_140214690(longlong param_1,int param_2,int param_3)



{

  float fVar1;

  

  fVar1 = *(float *)(param_1 + (longlong)(param_2 % param_3) * 4);

  if (((longlong)param_2 / (longlong)param_3 & 1U) != 0) {

    fVar1 = (float)((uint)fVar1 ^ DAT_14039cac0);

  }

  return ((float)param_3 * fVar1) / (float)param_2;

}




