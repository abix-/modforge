// Address: 0x1400c62d0
// Ghidra name: FUN_1400c62d0
// ============ 0x1400c62d0 FUN_1400c62d0 (size=166) ============


float FUN_1400c62d0(int param_1,int param_2,int param_3,int param_4,int param_5,float param_6,

                   float param_7)



{

  float fVar1;

  

  if ((param_2 <= param_1) && (param_1 <= param_5)) {

    if (param_1 < param_3) {

      fVar1 = (float)(param_1 - param_2) / (float)(param_3 - param_2);

    }

    else {

      if (param_1 <= param_4) {

        return param_7;

      }

      fVar1 = DAT_14039ca44 - (float)(param_1 - param_4) / (float)(param_5 - param_4);

    }

    fVar1 = (float)FUN_1402cdc50(fVar1 * DAT_14039ca50 * DAT_14039ca34);

    return fVar1 * (param_7 - param_6) + param_6;

  }

  return param_6;

}




