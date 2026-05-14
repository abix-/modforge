// Address: 0x140213c90
// Ghidra name: FUN_140213c90
// ============ 0x140213c90 FUN_140213c90 (size=685) ============


void FUN_140213c90(float *param_1,float *param_2,float *param_3,float param_4)



{

  float fVar1;

  float fVar2;

  

  fVar1 = param_4 * param_4;

  fVar2 = fVar1 * param_4;

  *param_2 = (param_4 * param_3[5] + param_3[4] + fVar1 * param_3[6] + fVar2 * param_3[7]) *

             param_1[1] +

             (param_4 * param_3[1] + *param_3 + fVar1 * param_3[2] + fVar2 * param_3[3]) * *param_1

             + 0.0 + (param_4 * param_3[9] + param_3[8] + fVar1 * param_3[10] + fVar2 * param_3[0xb]

                     ) * param_1[2] +

             (param_4 * param_3[0xd] + param_3[0xc] + fVar1 * param_3[0xe] + fVar2 * param_3[0xf]) *

             param_1[3] +

             (param_4 * param_3[0x11] + param_3[0x10] + fVar1 * param_3[0x12] +

             fVar2 * param_3[0x13]) * param_1[4] +

             (param_4 * param_3[0x15] + param_3[0x14] + fVar1 * param_3[0x16] +

             fVar2 * param_3[0x17]) * param_1[5] +

             (param_4 * param_3[0x19] + param_3[0x18] + fVar1 * param_3[0x1a] +

             fVar2 * param_3[0x1b]) * param_1[6] +

             (param_4 * param_3[0x1d] + param_3[0x1c] + fVar1 * param_3[0x1e] +

             fVar2 * param_3[0x1f]) * param_1[7] +

             (param_4 * param_3[0x21] + param_3[0x20] + fVar1 * param_3[0x22] +

             fVar2 * param_3[0x23]) * param_1[8] +

             (param_4 * param_3[0x25] + param_3[0x24] + fVar1 * param_3[0x26] +

             fVar2 * param_3[0x27]) * param_1[9] +

             (param_4 * param_3[0x29] + param_3[0x28] + fVar1 * param_3[0x2a] +

             fVar2 * param_3[0x2b]) * param_1[10] +

             (param_4 * param_3[0x2d] + param_3[0x2c] + fVar1 * param_3[0x2e] +

             fVar2 * param_3[0x2f]) * param_1[0xb];

  return;

}




