// Address: 0x140153410
// Ghidra name: FUN_140153410
// ============ 0x140153410 FUN_140153410 (size=352) ============


void FUN_140153410(longlong param_1,longlong param_2,longlong param_3,float param_4,float *param_5)



{

  undefined4 uVar1;

  undefined8 local_68;

  float local_60;

  undefined4 local_5c;

  float local_58;

  float local_54;

  undefined4 local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  

  local_68 = 0;

  local_60 = param_5[2] / (param_4 * *(float *)(param_3 + 8));

  local_5c = 0;

  local_50 = 0;

  local_54 = param_5[3] / (param_4 * *(float *)(param_3 + 0xc));

  local_44 = param_5[1];

  local_48 = *param_5;

  local_40 = local_48 + param_5[2];

  local_34 = local_44 + param_5[3];

  uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x138) + 0x90);

  local_58 = local_60;

  local_4c = local_54;

  local_3c = local_44;

  local_38 = local_40;

  local_30 = local_48;

  local_2c = local_34;

  FUN_14014ac90(param_1,uVar1,&local_48,8,param_2 + 0x30,0,&local_68,8,4,&DAT_1403325d0,6,4,uVar1,

                *(undefined4 *)(*(longlong *)(param_1 + 0x138) + 0x94),2,2);

  return;

}




