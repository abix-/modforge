// Address: 0x1401527c0
// Ghidra name: FUN_1401527c0
// ============ 0x1401527c0 FUN_1401527c0 (size=498) ============


void FUN_1401527c0(longlong param_1,longlong param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  

  fVar1 = *(float *)(*(longlong *)(param_1 + 0x138) + 0x90);

  fVar2 = *(float *)(*(longlong *)(param_1 + 0x138) + 0x94);

  if (*(longlong *)(param_1 + 0x48) == 0) {

    local_68 = *param_4;

    local_84 = param_3[1] / (float)*(int *)(param_2 + 8);

    local_74 = (param_3[1] + param_3[3]) / (float)*(int *)(param_2 + 8);

    local_60 = local_68 + param_4[2];

    local_88 = *param_3 / (float)*(int *)(param_2 + 4);

    local_80 = (*param_3 + param_3[2]) / (float)*(int *)(param_2 + 4);

    local_64 = param_4[1];

    local_54 = local_64 + param_4[3];

    local_7c = local_84;

    local_78 = local_80;

    local_70 = local_88;

    local_6c = local_74;

    local_5c = local_64;

    local_58 = local_60;

    local_50 = local_68;

    local_4c = local_54;

    FUN_14014ac90(param_1,local_60,&local_68,8,param_2 + 0x30,0,&local_88,8,4,&DAT_1403325d0,6,4,

                  fVar1,fVar2,1,1);

  }

  else {

    local_88 = fVar1 * *param_4;

    local_84 = fVar2 * param_4[1];

    local_80 = fVar1 * param_4[2];

    local_7c = fVar2 * param_4[3];

    FUN_14014a590(local_88,local_84,param_3,&local_88);

  }

  return;

}




