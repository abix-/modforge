// Address: 0x1400c6ab0
// Ghidra name: FUN_1400c6ab0
// ============ 0x1400c6ab0 FUN_1400c6ab0 (size=274) ============


/* WARNING: Removing unreachable block (ram,0x0001400c6afb) */

/* WARNING: Removing unreachable block (ram,0x0001400c6b62) */



float * FUN_1400c6ab0(float *param_1,float param_2)



{

  ulonglong uVar1;

  ulonglong uVar2;

  float fVar3;

  uint uVar4;

  float fVar5;

  float fVar6;

  

  uVar2 = DAT_1403da740 << 0xd ^ DAT_1403da740;

  uVar2 = uVar2 >> 7 ^ uVar2;

  uVar2 = uVar2 << 0x11 ^ uVar2;

  uVar1 = uVar2 << 0xd ^ uVar2;

  uVar1 = uVar1 >> 7 ^ uVar1;

  DAT_1403da740 = uVar1 << 0x11 ^ uVar1;

  fVar6 = (float)(uVar2 & 0xffff) * DAT_1403053bc * DAT_14039ca54 + 0.0;

  fVar5 = (float)(DAT_1403da740 & 0xffff) * DAT_1403053bc * (param_2 - 0.0) + 0.0;

  fVar3 = (float)FUN_1402cfda0(fVar6);

  *param_1 = fVar3 * fVar5;

  uVar4 = FUN_1402cdc50(fVar6);

  param_1[1] = (float)(uVar4 ^ DAT_14039cac0) * fVar5;

  return param_1;

}




