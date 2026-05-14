// Address: 0x140200940
// Ghidra name: FUN_140200940
// ============ 0x140200940 FUN_140200940 (size=203) ============


undefined8

FUN_140200940(undefined8 param_1,longlong param_2,undefined8 param_3,float *param_4,float *param_5,

             undefined8 param_6,undefined8 *param_7,int param_8,int param_9,int param_10)



{

  undefined8 uVar1;

  int *piVar2;

  

  piVar2 = (int *)FUN_14014b940(param_1,0x40,0,param_2 + 8);

  if (piVar2 == (int *)0x0) {

    return 0;

  }

  *(undefined8 *)(param_2 + 0x10) = 1;

  *piVar2 = (int)*param_4;

  piVar2[1] = (int)param_4[1];

  piVar2[2] = (int)param_4[2];

  piVar2[3] = (int)param_4[3];

  piVar2[4] = (int)*param_5;

  piVar2[5] = (int)param_5[1];

  piVar2[6] = (int)param_5[2];

  piVar2[7] = (int)param_5[3];

  *(undefined8 *)(piVar2 + 8) = param_6;

  uVar1 = *param_7;

  piVar2[0xc] = param_8;

  piVar2[0xd] = param_9;

  piVar2[0xe] = param_10;

  *(undefined8 *)(piVar2 + 10) = uVar1;

  return CONCAT71((uint7)(uint3)((uint)param_8 >> 8),1);

}




