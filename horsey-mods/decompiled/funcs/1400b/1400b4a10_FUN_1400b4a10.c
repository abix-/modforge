// Address: 0x1400b4a10
// Ghidra name: FUN_1400b4a10
// ============ 0x1400b4a10 FUN_1400b4a10 (size=216) ============


float * FUN_1400b4a10(longlong param_1,float *param_2)



{

  longlong *plVar1;

  float fVar2;

  float fVar3;

  undefined4 uVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  plVar1 = (longlong *)(param_1 + 0x40);

  if ((*(char *)(param_1 + 0x1a) == '\0') || (*(longlong *)(*plVar1 + 0x30) == 0)) {

    fVar7 = *(float *)(param_1 + 0x124);

  }

  else {

    fVar7 = (float)(*(uint *)(param_1 + 0x124) ^ DAT_14039cac0);

  }

  fVar2 = *(float *)(param_1 + 0x128);

  uVar4 = FUN_1400c5f10(*(undefined4 *)(*plVar1 + 0x48));

  fVar5 = (float)FUN_1402cdc50();

  fVar6 = (float)FUN_1402cfda0(uVar4);

  fVar3 = *(float *)(*plVar1 + 0x40);

  param_2[1] = fVar6 * fVar2 + fVar5 * fVar7 + *(float *)(*plVar1 + 0x44);

  *param_2 = (fVar6 * fVar7 - fVar5 * fVar2) + fVar3;

  return param_2;

}




