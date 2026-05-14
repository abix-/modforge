// Address: 0x14000bc20
// Ghidra name: FUN_14000bc20
// ============ 0x14000bc20 FUN_14000bc20 (size=870) ============


undefined8 FUN_14000bc20(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  undefined4 uVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  int iVar9;

  longlong lVar10;

  longlong lVar11;

  longlong lVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  

  lVar10 = *(longlong *)(param_2 + 0x18);

  lVar11 = (longlong)*(int *)(param_1 + 0x9c);

  lVar12 = (longlong)*(int *)(param_1 + 0xa0);

  fVar1 = *(float *)(lVar10 + 8 + lVar11 * 0xc);

  fVar2 = *(float *)(lVar10 + lVar11 * 0xc);

  fVar3 = *(float *)(lVar10 + 4 + lVar11 * 0xc);

  fVar4 = *(float *)(lVar10 + lVar12 * 0xc);

  uVar5 = *(undefined4 *)(lVar10 + 8 + lVar12 * 0xc);

  fVar6 = *(float *)(lVar10 + 4 + lVar12 * 0xc);

  fVar13 = (float)FUN_1402cdc50(fVar1);

  fVar14 = (float)FUN_1402cfda0(fVar1);

  fVar15 = (float)FUN_1402cdc50(uVar5);

  fVar16 = (float)FUN_1402cfda0(uVar5);

  fVar22 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 200);

  fVar20 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xc0);

  fVar18 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xbc);

  fVar21 = fVar20 * fVar14 + fVar18 * fVar13;

  fVar20 = fVar18 * fVar14 - fVar20 * fVar13;

  fVar13 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xc4);

  fVar18 = fVar22 * fVar16 + fVar13 * fVar15;

  fVar16 = fVar13 * fVar16 - fVar22 * fVar15;

  fVar15 = ((fVar18 + fVar6) - fVar3) - fVar21;

  fVar14 = ((fVar16 + fVar4) - fVar2) - fVar20;

  fVar13 = fVar15 * fVar15 + fVar14 * fVar14;

  if (fVar13 < 0.0) {

    fVar13 = (float)FUN_1402cdfa0(fVar13);

  }

  else {

    fVar13 = SQRT(fVar13);

  }

  if (DAT_14039c9f0 <= fVar13) {

    fVar15 = (DAT_14039ca44 / fVar13) * fVar15;

    fVar14 = (DAT_14039ca44 / fVar13) * fVar14;

  }

  else {

    fVar13 = 0.0;

  }

  fVar22 = *(float *)(param_1 + 0xcc);

  fVar7 = *(float *)(param_1 + 0xd0);

  fVar17 = fVar13 - *(float *)(param_1 + 0x90);

  if (DAT_14039ca2c <= fVar17) {

    fVar17 = DAT_14039ca2c;

  }

  fVar19 = 0.0;

  if (0.0 <= fVar17) {

    fVar19 = fVar17;

  }

  fVar19 = fVar19 * (float)(*(uint *)(param_1 + 0xdc) ^ DAT_14039cac0);

  fVar15 = fVar19 * fVar15;

  fVar19 = fVar19 * fVar14;

  fVar14 = *(float *)(param_1 + 0xd4);

  fVar17 = *(float *)(param_1 + 0xd8);

  fVar8 = *(float *)(lVar10 + 8 + lVar12 * 0xc);

  *(float *)(lVar10 + lVar11 * 0xc) = fVar2 - fVar22 * fVar19;

  *(float *)(lVar10 + 4 + lVar11 * 0xc) = fVar3 - fVar22 * fVar15;

  *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0x9c) * 0xc) =

       fVar1 - (fVar15 * fVar20 - fVar19 * fVar21) * fVar14;

  iVar9 = *(int *)(param_1 + 0xa0);

  lVar10 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar10 + (longlong)iVar9 * 0xc) = fVar7 * fVar19 + fVar4;

  fVar1 = DAT_14039ca08;

  *(float *)(lVar10 + 4 + (longlong)iVar9 * 0xc) = fVar7 * fVar15 + fVar6;

  lVar10 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar10 + 8 + (longlong)*(int *)(param_1 + 0xa0) * 0xc) =

       (fVar15 * fVar16 - fVar19 * fVar18) * fVar17 + fVar8;

  return CONCAT71((int7)((ulonglong)lVar10 >> 8),fVar13 - *(float *)(param_1 + 0x90) < fVar1);

}




