// Address: 0x14001df50
// Ghidra name: FUN_14001df50
// ============ 0x14001df50 FUN_14001df50 (size=284) ============


void FUN_14001df50(longlong param_1,undefined8 *param_2,float *param_3,float *param_4)



{

  longlong lVar1;

  longlong lVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x68) + 0x18);

  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 0x18);

  *(undefined4 *)((longlong)param_2 + 0x3c) = 0;

  fVar3 = *(float *)(lVar2 + 0xc) + *(float *)(lVar1 + 0xc);

  fVar4 = ((*(float *)(lVar1 + 0x10) * param_4[3] - *(float *)(lVar1 + 0x14) * param_4[2]) +

          *param_4) -

          ((*(float *)(lVar2 + 0x10) * param_3[3] - *(float *)(lVar2 + 0x14) * param_3[2]) +

          *param_3);

  fVar5 = (*(float *)(lVar1 + 0x14) * param_4[3] + *(float *)(lVar1 + 0x10) * param_4[2] +

          param_4[1]) -

          (*(float *)(lVar2 + 0x14) * param_3[3] + *(float *)(lVar2 + 0x10) * param_3[2] +

          param_3[1]);

  if (fVar5 * fVar5 + fVar4 * fVar4 <= fVar3 * fVar3) {

    *(undefined4 *)(param_2 + 7) = 0;

    param_2[6] = *(undefined8 *)(lVar2 + 0x10);

    param_2[5] = 0;

    *(undefined4 *)((longlong)param_2 + 0x3c) = 1;

    *param_2 = *(undefined8 *)(lVar1 + 0x10);

    *(undefined4 *)(param_2 + 2) = 0;

  }

  return;

}




