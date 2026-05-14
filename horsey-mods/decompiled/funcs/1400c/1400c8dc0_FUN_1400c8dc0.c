// Address: 0x1400c8dc0
// Ghidra name: FUN_1400c8dc0
// ============ 0x1400c8dc0 FUN_1400c8dc0 (size=157) ============


void FUN_1400c8dc0(longlong param_1,undefined4 param_2,undefined8 *param_3,float *param_4,

                  undefined4 param_5,float param_6,undefined4 *param_7,undefined4 param_8,

                  undefined4 param_9)



{

  int *piVar1;

  float fVar2;

  undefined8 uVar3;

  undefined4 uVar4;

  float fVar5;

  longlong lVar6;

  

  fVar5 = DAT_1403053c8;

  lVar6 = (longlong)*(int *)(param_1 + 8000);

  uVar3 = *param_3;

  *(undefined4 *)(param_1 + 0x24 + lVar6 * 0x28) = param_5;

  *(undefined8 *)(param_1 + lVar6 * 0x28) = uVar3;

  fVar2 = param_4[1];

  *(float *)(param_1 + 8 + lVar6 * 0x28) = *param_4 * fVar5;

  *(float *)(param_1 + 0xc + lVar6 * 0x28) = fVar2 * fVar5;

  *(float *)(param_1 + 0x10 + lVar6 * 0x28) = param_6 * fVar5;

  uVar4 = *param_7;

  *(undefined4 *)(param_1 + 0x1c + lVar6 * 0x28) = param_9;

  *(undefined4 *)(param_1 + 0x14 + lVar6 * 0x28) = param_8;

  *(undefined4 *)(param_1 + 0x20 + lVar6 * 0x28) = uVar4;

  *(undefined4 *)(param_1 + 0x18 + lVar6 * 0x28) = param_2;

  piVar1 = (int *)(param_1 + 8000);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    *(undefined4 *)(param_1 + 8000) = 199;

  }

  return;

}




