// Address: 0x1400c6180
// Ghidra name: FUN_1400c6180
// ============ 0x1400c6180 FUN_1400c6180 (size=73) ============


undefined8 FUN_1400c6180(float param_1,float param_2,float param_3,undefined8 param_4,float param_5)



{

  float fVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  float fVar4;

  

  uVar2 = (undefined4)((ulonglong)param_4 >> 0x20);

  fVar1 = (float)param_4;

  fVar4 = ((param_1 - param_2) * (param_5 - fVar1)) / (param_3 - param_2) + fVar1;

  if (param_5 <= fVar1) {

    uVar3 = 0;

    if ((param_5 <= fVar4) && (param_5 = fVar1, uVar3 = uVar2, fVar4 <= fVar1)) {

      param_5 = fVar4;

    }

    return CONCAT44(uVar3,param_5);

  }

  if (fVar1 <= fVar4) {

    fVar1 = param_5;

    if (fVar4 <= param_5) {

      fVar1 = fVar4;

    }

    uVar2 = 0;

  }

  return CONCAT44(uVar2,fVar1);

}




