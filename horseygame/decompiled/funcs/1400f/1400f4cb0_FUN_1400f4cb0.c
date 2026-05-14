// Address: 0x1400f4cb0
// Ghidra name: FUN_1400f4cb0
// ============ 0x1400f4cb0 FUN_1400f4cb0 (size=488) ============


undefined8

FUN_1400f4cb0(longlong param_1,int *param_2,float param_3,float param_4,float param_5,float param_6,

             float param_7,float param_8,float param_9,int param_10)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  fVar2 = DAT_14039ca34;

  fVar5 = (param_5 + param_5 + param_3 + param_7) * DAT_14030335c;

  fVar6 = (param_6 + param_6 + param_4 + param_8) * DAT_14030335c;

  fVar4 = (param_3 + param_7) * DAT_14039ca34 - fVar5;

  fVar3 = (param_4 + param_8) * DAT_14039ca34 - fVar6;

  if (param_10 < 0x11) {

    if (fVar3 * fVar3 + fVar4 * fVar4 <= param_9) {

      if (param_1 != 0) {

        iVar1 = *param_2;

        *(float *)(param_1 + (longlong)iVar1 * 8) = param_7;

        *(float *)(param_1 + 4 + (longlong)iVar1 * 8) = param_8;

      }

      *param_2 = *param_2 + 1;

    }

    else {

      FUN_1400f4cb0();

      FUN_1400f4cb0(param_1,param_2,fVar5,fVar6,(param_5 + param_7) * fVar2,

                    (param_6 + param_8) * fVar2,param_7,param_8,param_9,param_10 + 1);

    }

  }

  return 1;

}




