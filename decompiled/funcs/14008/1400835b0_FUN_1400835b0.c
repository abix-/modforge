// Address: 0x1400835b0
// Ghidra name: FUN_1400835b0
// ============ 0x1400835b0 FUN_1400835b0 (size=442) ============


void FUN_1400835b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,float param_4,

                  undefined4 param_5,undefined4 param_6)



{

  float fVar1;

  float fVar2;

  undefined4 local_a8;

  undefined4 uStack_a4;

  undefined4 local_a0;

  undefined4 uStack_9c;

  

  uStack_9c = (float)((ulonglong)param_2 >> 0x20);

  local_a0 = (float)param_2;

  fVar2 = local_a0 - param_4;

  local_a8 = (float)param_3;

  fVar1 = param_4 + param_4 + local_a8;

  FUN_140083480(fVar1,CONCAT44(uStack_9c - param_4,fVar2),CONCAT44(param_4,fVar1),0,0,param_5,

                param_6);

  uStack_a4 = (float)((ulonglong)param_3 >> 0x20);

  FUN_140083480(param_1,CONCAT44(uStack_a4 + uStack_9c,fVar2),CONCAT44(param_4,fVar1),0,0,param_5,

                param_6);

  FUN_140083480(param_1,CONCAT44(uStack_9c,fVar2),CONCAT44(uStack_a4,param_4),0,0,param_5,param_6);

  FUN_140083480(param_1,CONCAT44(uStack_9c,local_a0 + local_a8),CONCAT44(uStack_a4,param_4),0,0,

                param_5,param_6);

  return;

}




