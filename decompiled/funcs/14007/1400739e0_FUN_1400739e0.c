// Address: 0x1400739e0
// Ghidra name: FUN_1400739e0
// ============ 0x1400739e0 FUN_1400739e0 (size=344) ============


void FUN_1400739e0(float *param_1,float param_2,float param_3,float param_4,float param_5,

                  uint param_6)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar1 = DAT_14030a2d0;

  *param_1 = param_2;

  param_1[1] = param_3;

  fVar4 = (float)(param_6 & 0xff) / fVar1;

  param_1[4] = fVar4;

  fVar3 = (float)(param_6 >> 8 & 0xff) / fVar1;

  param_1[5] = fVar3;

  fVar2 = (float)(param_6 >> 0x10 & 0xff) / fVar1;

  fVar1 = (float)(param_6 >> 0x18) / fVar1;

  param_1[6] = fVar2;

  param_1[7] = fVar1;

  param_1[9] = param_3;

  param_1[8] = param_2 + param_4;

  param_1[0xc] = fVar4;

  param_1[0xd] = fVar3;

  param_1[0xe] = fVar2;

  param_1[0xf] = fVar1;

  param_1[0x11] = param_3 + param_5;

  param_1[0x10] = param_2;

  param_1[0x14] = fVar4;

  param_1[0x15] = fVar3;

  param_1[0x16] = fVar2;

  param_1[0x17] = fVar1;

  *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(param_1 + 8);

  *(undefined8 *)(param_1 + 0x1a) = *(undefined8 *)(param_1 + 10);

  *(undefined8 *)(param_1 + 0x1c) = *(undefined8 *)(param_1 + 0xc);

  *(undefined8 *)(param_1 + 0x1e) = *(undefined8 *)(param_1 + 0xe);

  *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(param_1 + 0x10);

  *(undefined8 *)(param_1 + 0x22) = *(undefined8 *)(param_1 + 0x12);

  param_1[0x29] = param_3 + param_5;

  *(undefined8 *)(param_1 + 0x24) = *(undefined8 *)(param_1 + 0x14);

  *(undefined8 *)(param_1 + 0x26) = *(undefined8 *)(param_1 + 0x16);

  param_1[0x28] = param_2 + param_4;

  param_1[0x2c] = fVar4;

  param_1[0x2d] = fVar3;

  param_1[0x2e] = fVar2;

  param_1[0x2f] = fVar1;

  return;

}




