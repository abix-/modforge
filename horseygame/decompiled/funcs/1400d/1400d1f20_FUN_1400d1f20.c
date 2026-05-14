// Address: 0x1400d1f20
// Ghidra name: FUN_1400d1f20
// ============ 0x1400d1f20 FUN_1400d1f20 (size=350) ============


void FUN_1400d1f20(longlong param_1,float param_2,float param_3,float param_4,undefined8 *param_5)



{

  undefined8 uVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  undefined4 uVar5;

  undefined1 local_58 [24];

  undefined1 local_40 [56];

  

  if (0xf < (ulonglong)param_5[3]) {

    param_5 = (undefined8 *)*param_5;

  }

  uVar1 = FUN_140086910(DAT_1403ede50,local_58,param_4 * DAT_140303fd0,DAT_14039ca44,DAT_1403da858,

                        param_5);

  uVar5 = (undefined4)((ulonglong)param_5 >> 0x20);

  FUN_1400d8c00(param_1 + 0x1c8,uVar1);

  FUN_140087ec0(local_40);

  *(float *)(param_1 + 0x1cc) = param_3;

  fVar2 = *(float *)(param_1 + 0x1d0) * DAT_140303354;

  *(undefined8 *)(param_1 + 0x1fc) = 0;

  fVar3 = *(float *)(param_1 + 0x1d0) + DAT_140303750;

  fVar2 = fVar2 * DAT_14039ca34;

  *(undefined4 *)(param_1 + 0x1f8) = 0xb4;

  param_2 = param_2 - fVar2;

  fVar2 = *(float *)(param_1 + 0x1d4) + DAT_14039ca58;

  fVar4 = (param_3 - *(float *)(param_1 + 0x110)) * DAT_140303fd0 - DAT_140303390;

  *(float *)(param_1 + 0x1c8) = param_2;

  FUN_1400c9c30(param_1,1,

                (int)((param_2 - *(float *)(param_1 + 0x10c)) * DAT_140303fd0 - DAT_140303390),

                (int)fVar4,(int)fVar3,CONCAT44(uVar5,(int)fVar2),1);

  return;

}




