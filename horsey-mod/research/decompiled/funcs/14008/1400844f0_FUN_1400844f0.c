// Address: 0x1400844f0
// Ghidra name: FUN_1400844f0
// ============ 0x1400844f0 FUN_1400844f0 (size=119) ============


undefined8 FUN_1400844f0(undefined8 param_1,undefined8 param_2,float param_3,undefined4 param_4)



{

  float local_38;

  float fStack_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  undefined **local_20;

  undefined8 local_18;

  undefined4 local_10;

  

  local_20 = &PTR_FUN_14030ad70;

  local_18 = 0;

  local_38 = (float)param_2;

  local_30 = local_38 - param_3;

  fStack_34 = (float)((ulonglong)param_2 >> 0x20);

  local_2c = fStack_34 - param_3;

  local_28 = local_38 + param_3;

  local_24 = fStack_34 + param_3;

  local_10 = param_4;

  FUN_140007790(local_30,&local_20,&local_30);

  return local_18;

}




