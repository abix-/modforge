// Address: 0x140184830
// Ghidra name: FUN_140184830
// ============ 0x140184830 FUN_140184830 (size=77) ============


uint FUN_140184830(int *param_1,int param_2,int param_3)



{

  uint uVar1;

  

  if (param_3 < param_1[1]) {

    uVar1 = 2;

  }

  else {

    uVar1 = 0;

    if (param_1[1] + param_1[3] + -1 < param_3) {

      uVar1 = 1;

    }

  }

  if (param_2 < *param_1) {

    return uVar1 | 4;

  }

  if (*param_1 + -1 + param_1[2] < param_2) {

    uVar1 = uVar1 | 8;

  }

  return uVar1;

}




