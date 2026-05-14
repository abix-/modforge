// Address: 0x140083e10
// Ghidra name: FUN_140083e10
// ============ 0x140083e10 FUN_140083e10 (size=364) ============


void FUN_140083e10(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,

                  float param_5)



{

  float fVar1;

  float fVar2;

  float local_res8;

  float fStackX_c;

  float local_res10;

  float fStackX_14;

  undefined4 local_98 [2];

  undefined8 local_90;

  longlong local_88;

  longlong local_80;

  undefined1 local_78;

  undefined8 local_70;

  undefined8 local_68;

  float local_60;

  

  fStackX_c = (float)((ulonglong)param_3 >> 0x20);

  local_res8 = (float)param_3;

  local_90 = 0;

  local_78 = 0;

  local_res10 = (float)param_4;

  local_98[0] = 10;

  fStackX_14 = (float)((ulonglong)param_4 >> 0x20);

  fVar1 = ((*(float *)(param_1 + 0x18) * local_res8 - *(float *)(param_1 + 0x14) * fStackX_c) +

          *(float *)(param_1 + 0xc)) -

          ((*(float *)(param_2 + 0x18) * local_res10 - *(float *)(param_2 + 0x14) * fStackX_14) +

          *(float *)(param_2 + 0xc));

  fVar2 = (*(float *)(param_1 + 0x18) * fStackX_c + *(float *)(param_1 + 0x14) * local_res8 +

          *(float *)(param_1 + 0x10)) -

          (*(float *)(param_2 + 0x18) * fStackX_14 + *(float *)(param_2 + 0x14) * local_res10 +

          *(float *)(param_2 + 0x10));

  fVar1 = fVar2 * fVar2 + fVar1 * fVar1;

  local_88 = param_1;

  local_80 = param_2;

  local_70 = param_3;

  local_68 = param_4;

  if (fVar1 < 0.0) {

    fVar1 = (float)FUN_1402cdfa0(fVar1);

  }

  else {

    fVar1 = SQRT(fVar1);

  }

  local_60 = fVar1 + param_5;

  FUN_1400060e0(*(undefined8 *)(param_1 + 0x58),local_98);

  return;

}




