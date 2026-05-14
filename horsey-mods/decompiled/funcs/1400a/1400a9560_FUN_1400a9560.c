// Address: 0x1400a9560
// Ghidra name: FUN_1400a9560
// ============ 0x1400a9560 FUN_1400a9560 (size=486) ============


void FUN_1400a9560(undefined8 param_1,undefined8 param_2,float param_3,float param_4,float param_5,

                  float param_6,float param_7,int param_8,int param_9,int param_10,float param_11)



{

  float fVar1;

  

  if (param_5 * param_6 * param_11 < DAT_14039ca0c) {

    param_11 = DAT_14039ca0c / (param_5 * param_6);

  }

  if (((param_9 == param_10) || (param_7 < DAT_14039ca0c)) || (DAT_14030d98c < param_7)) {

    FUN_1400a9360();

  }

  else {

    fVar1 = DAT_14039ca44 - param_7;

    if (param_8 == 0) {

      FUN_1400a9360();

      param_4 = param_6 * param_7 + param_4;

      param_6 = fVar1 * param_6;

    }

    else {

      FUN_1400a9360();

      param_3 = param_5 * param_7 + param_3;

      param_5 = fVar1 * param_5;

    }

    FUN_1400a9360(param_1,param_2,param_3,param_4,param_5,param_6,param_10,param_11);

  }

  return;

}




