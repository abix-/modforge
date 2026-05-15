// Address: 0x1400f0a00
// Ghidra name: FUN_1400f0a00
// ============ 0x1400f0a00 FUN_1400f0a00 (size=434) ============


void FUN_1400f0a00(longlong param_1,int param_2,int param_3,int param_4,float *param_5,

                  float *param_6,float *param_7,int param_8)



{

  longlong lVar1;

  double dVar2;

  double dVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  fVar6 = DAT_14030b668;

  if (param_8 != 0) {

    fVar6 = 0.0;

  }

  lVar1 = (longlong)param_4;

  fVar4 = DAT_14039ca44 / (float)param_2;

  fVar5 = DAT_14039ca44 / (float)param_3;

  dVar2 = (double)FUN_1402d0290((double)(*(float *)(param_1 + 8 + lVar1 * 0x14) + *param_5) +

                                DAT_140304b70);

  dVar3 = (double)FUN_1402d0290((double)(*(float *)(param_1 + 0xc + lVar1 * 0x14) + *param_6) +

                                DAT_140304b70);

  *param_7 = (float)(int)dVar2 + fVar6;

  param_7[1] = (float)(int)dVar3 + fVar6;

  param_7[4] = (float)(int)(((uint)*(ushort *)(param_1 + 4 + lVar1 * 0x14) -

                            (uint)*(ushort *)(param_1 + lVar1 * 0x14)) + (int)dVar2) + fVar6;

  param_7[5] = (float)(int)(((uint)*(ushort *)(param_1 + 6 + lVar1 * 0x14) -

                            (uint)*(ushort *)(param_1 + 2 + lVar1 * 0x14)) + (int)dVar3) + fVar6;

  param_7[2] = (float)*(ushort *)(param_1 + lVar1 * 0x14) * fVar4;

  param_7[3] = (float)*(ushort *)(param_1 + 2 + lVar1 * 0x14) * fVar5;

  param_7[6] = (float)*(ushort *)(param_1 + 4 + lVar1 * 0x14) * fVar4;

  param_7[7] = (float)*(ushort *)(param_1 + 6 + lVar1 * 0x14) * fVar5;

  *param_5 = *(float *)(param_1 + 0x10 + lVar1 * 0x14) + *param_5;

  return;

}




