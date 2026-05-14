// Address: 0x1400c57a0
// Ghidra name: FUN_1400c57a0
// ============ 0x1400c57a0 FUN_1400c57a0 (size=277) ============


/* WARNING: Removing unreachable block (ram,0x0001400c5834) */

/* WARNING: Removing unreachable block (ram,0x0001400c5882) */



float * FUN_1400c57a0(float *param_1,float *param_2,float param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  float fVar6;

  float fVar7;

  

  fVar3 = DAT_1403053bc;

  fVar1 = param_2[1];

  uVar5 = DAT_1403da740 << 0xd ^ DAT_1403da740;

  fVar6 = fVar1 + param_3;

  uVar5 = uVar5 >> 7 ^ uVar5;

  fVar7 = *param_2 + param_3;

  uVar5 = uVar5 << 0x11 ^ uVar5;

  uVar4 = uVar5 << 0xd ^ uVar5;

  uVar4 = uVar4 >> 7 ^ uVar4;

  DAT_1403da740 = uVar4 << 0x11 ^ uVar4;

  fVar2 = param_2[3];

  *param_1 = (((*param_2 + param_2[2]) - param_3) - fVar7) *

             (float)(DAT_1403da740 & 0xffff) * DAT_1403053bc + fVar7;

  param_1[1] = (((fVar1 + fVar2) - param_3) - fVar6) * (float)(uVar5 & 0xffff) * fVar3 + fVar6;

  return param_1;

}




