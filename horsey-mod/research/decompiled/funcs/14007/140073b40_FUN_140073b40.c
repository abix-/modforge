// Address: 0x140073b40
// Ghidra name: FUN_140073b40
// ============ 0x140073b40 FUN_140073b40 (size=224) ============


void FUN_140073b40(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6,undefined4 param_7,uint param_8)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar1 = DAT_14030a2d0;

  param_1[1] = param_3;

  *param_1 = param_2;

  fVar4 = (float)(param_8 & 0xff) / fVar1;

  param_1[4] = fVar4;

  fVar3 = (float)(param_8 >> 8 & 0xff) / fVar1;

  param_1[5] = fVar3;

  fVar2 = (float)(param_8 >> 0x10 & 0xff) / fVar1;

  param_1[6] = fVar2;

  fVar1 = (float)(param_8 >> 0x18) / fVar1;

  param_1[7] = fVar1;

  param_1[9] = param_5;

  param_1[8] = param_4;

  param_1[0xc] = fVar4;

  param_1[0xd] = fVar3;

  param_1[0xe] = fVar2;

  param_1[0xf] = fVar1;

  param_1[0x10] = param_6;

  param_1[0x11] = param_7;

  param_1[0x14] = fVar4;

  param_1[0x15] = fVar3;

  param_1[0x16] = fVar2;

  param_1[0x17] = fVar1;

  return;

}




