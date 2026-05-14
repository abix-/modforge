// Address: 0x14000c590
// Ghidra name: FUN_14000c590
// ============ 0x14000c590 FUN_14000c590 (size=119) ============


bool FUN_14000c590(longlong param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  

  fVar2 = *param_3 -

          ((param_2[3] * *(float *)(param_1 + 0x10) - param_2[2] * *(float *)(param_1 + 0x14)) +

          *param_2);

  fVar1 = param_3[1] -

          (*(float *)(param_1 + 0x10) * param_2[2] + param_2[3] * *(float *)(param_1 + 0x14) +

          param_2[1]);

  return fVar1 * fVar1 + fVar2 * fVar2 <= *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0xc);

}




