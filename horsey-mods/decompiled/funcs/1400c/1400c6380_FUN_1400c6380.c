// Address: 0x1400c6380
// Ghidra name: FUN_1400c6380
// ============ 0x1400c6380 FUN_1400c6380 (size=146) ============


float FUN_1400c6380(int param_1,int param_2,int param_3,int param_4,int param_5,float param_6,

                   float param_7)



{

  if ((param_1 < param_2) || (param_5 < param_1)) {

    return param_6;

  }

  if (param_1 < param_3) {

    return ((float)(param_1 - param_2) / (float)(param_3 - param_2)) * (param_7 - param_6) + param_6

    ;

  }

  if (param_4 < param_1) {

    return (DAT_14039ca44 - (float)(param_1 - param_4) / (float)(param_5 - param_4)) *

           (param_7 - param_6) + param_6;

  }

  return param_7;

}




