// Address: 0x1400cca50
// Ghidra name: FUN_1400cca50
// ============ 0x1400cca50 FUN_1400cca50 (size=182) ============


void FUN_1400cca50(longlong param_1,undefined4 param_2,char param_3)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  longlong *plVar4;

  float fVar5;

  float fVar6;

  

  pfVar3 = *(float **)(param_1 + 0x78);

  fVar1 = pfVar3[1];

  fVar5 = (float)FUN_1400c6940(DAT_14039ca34,DAT_14030338c);

  fVar2 = *pfVar3;

  fVar6 = (float)FUN_1400c6940(DAT_14039ca34,pfVar3[2] - DAT_14039ca44);

  plVar4 = (longlong *)FUN_1400cc9d0(param_1,param_2,fVar6 + fVar2,fVar5 + fVar1);

  if (param_3 == '\0') {

    (**(code **)(*plVar4 + 8))(plVar4,0);

  }

  return;

}




