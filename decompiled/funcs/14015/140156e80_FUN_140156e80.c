// Address: 0x140156e80
// Ghidra name: FUN_140156e80
// ============ 0x140156e80 FUN_140156e80 (size=171) ============


void FUN_140156e80(undefined8 param_1,int *param_2)



{

  int iVar1;

  float fVar2;

  

  fVar2 = (float)thunk_FUN_1402d0350((float)param_2[2] * (float)param_2[0x24] + (float)param_2[0x22]

                                    );

  param_2[6] = (int)fVar2;

  fVar2 = (float)thunk_FUN_1402d0350((float)param_2[3] * (float)param_2[0x25] + (float)param_2[0x23]

                                    );

  param_2[7] = (int)fVar2;

  if (param_2[4] < 0) {

    iVar1 = *param_2;

  }

  else {

    fVar2 = (float)thunk_FUN_1402e33f0((float)param_2[4] * (float)param_2[0x24]);

    iVar1 = (int)fVar2;

  }

  param_2[8] = iVar1;

  if (-1 < param_2[5]) {

    fVar2 = (float)thunk_FUN_1402e33f0((float)param_2[5] * (float)param_2[0x25]);

    param_2[9] = (int)fVar2;

    return;

  }

  param_2[9] = param_2[1];

  return;

}




