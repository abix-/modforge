// Address: 0x140184880
// Ghidra name: FUN_140184880
// ============ 0x140184880 FUN_140184880 (size=73) ============


uint FUN_140184880(float *param_1,float param_2,float param_3)



{

  uint uVar1;

  

  uVar1 = 0;

  if (param_1[1] <= param_3) {

    if ((param_1[1] + param_1[3]) - 0.0 < param_3) {

      uVar1 = 1;

    }

  }

  else {

    uVar1 = 2;

  }

  if (param_2 < *param_1) {

    return uVar1 | 4;

  }

  if ((*param_1 + param_1[2]) - 0.0 < param_2) {

    uVar1 = uVar1 | 8;

  }

  return uVar1;

}




