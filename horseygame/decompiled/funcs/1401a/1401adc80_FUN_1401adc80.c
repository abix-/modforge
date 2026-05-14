// Address: 0x1401adc80
// Ghidra name: FUN_1401adc80
// ============ 0x1401adc80 FUN_1401adc80 (size=58) ============


int FUN_1401adc80(int param_1,char param_2)



{

  int iVar1;

  

  if (param_1 == 0) {

    iVar1 = 0xc;

    if (param_2 != '\0') {

      iVar1 = 4;

    }

    return iVar1;

  }

  if (param_1 == 1) {

    return 0x35 - (uint)(param_2 != '\0');

  }

  if (param_1 == 2) {

    return 0x1d;

  }

  if (param_1 != 3) {

    return 0;

  }

  return 8;

}




