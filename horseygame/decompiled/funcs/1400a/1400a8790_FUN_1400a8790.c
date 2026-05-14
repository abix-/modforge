// Address: 0x1400a8790
// Ghidra name: FUN_1400a8790
// ============ 0x1400a8790 FUN_1400a8790 (size=192) ============


undefined1 FUN_1400a8790(longlong param_1,longlong param_2,float param_3)



{

  float fVar1;

  float fVar2;

  

  fVar2 = *(float *)(param_1 + 0x30) * DAT_14039ca34;

  fVar1 = *(float *)(param_2 + 0x30) * DAT_14039ca34;

  if ((*(float *)(param_2 + 0x28) - fVar1 < fVar2 + *(float *)(param_1 + 0x28) + param_3) &&

     ((*(float *)(param_1 + 0x28) - fVar2) - param_3 < *(float *)(param_2 + 0x28) + fVar1)) {

    fVar2 = *(float *)(param_1 + 0x34) * DAT_14039ca34;

    fVar1 = *(float *)(param_2 + 0x34) * DAT_14039ca34;

    if ((*(float *)(param_2 + 0x2c) - fVar1 < fVar2 + *(float *)(param_1 + 0x2c) + param_3) &&

       ((*(float *)(param_1 + 0x2c) - fVar2) - param_3 < *(float *)(param_2 + 0x2c) + fVar1)) {

      return 1;

    }

  }

  return 0;

}




