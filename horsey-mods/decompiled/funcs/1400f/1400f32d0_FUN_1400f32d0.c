// Address: 0x1400f32d0
// Ghidra name: FUN_1400f32d0
// ============ 0x1400f32d0 FUN_1400f32d0 (size=260) ============


void FUN_1400f32d0(undefined8 param_1,float param_2,undefined8 param_3,undefined4 param_4,

                  float param_5,float param_6,undefined4 param_7,undefined4 param_8,

                  undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined8 param_12)



{

  float fVar1;

  undefined8 uVar2;

  longlong lVar3;

  float fVar4;

  undefined8 local_38 [6];

  

  uVar2 = param_12;

  fVar1 = param_6;

  fVar4 = param_6;

  if (param_5 <= param_6) {

    fVar4 = param_5;

  }

  lVar3 = FUN_1400f3730(param_3,param_4,param_2 / fVar4,local_38,&param_6,param_12);

  if (lVar3 != 0) {

    FUN_1400f4560(param_1,lVar3,local_38[0],param_6,param_5,fVar1,param_7,param_8,param_9,param_10,

                  param_11,uVar2);

    thunk_FUN_1402e9a80(local_38[0]);

    thunk_FUN_1402e9a80(lVar3);

  }

  return;

}




