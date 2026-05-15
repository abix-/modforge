// Address: 0x140014e30
// Ghidra name: FUN_140014e30
// ============ 0x140014e30 FUN_140014e30 (size=1202) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140014e30(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  int iVar11;

  longlong lVar12;

  longlong lVar13;

  longlong lVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  

  lVar12 = *(longlong *)(param_2 + 0x18);

  lVar13 = (longlong)*(int *)(param_1 + 0xac);

  lVar14 = (longlong)*(int *)(param_1 + 0xb0);

  fVar1 = *(float *)(lVar12 + 8 + lVar13 * 0xc);

  fVar2 = *(float *)(lVar12 + 4 + lVar13 * 0xc);

  fVar3 = *(float *)(lVar12 + lVar14 * 0xc);

  fVar4 = *(float *)(lVar12 + 4 + lVar14 * 0xc);

  fVar5 = *(float *)(lVar12 + 8 + lVar14 * 0xc);

  fVar15 = (float)FUN_1402cdc50(fVar1);

  fVar16 = (float)FUN_1402cfda0(fVar1);

  fVar17 = (float)FUN_1402cdc50(fVar5);

  fVar18 = (float)FUN_1402cfda0(fVar5);

  fVar24 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xd4);

  fVar21 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xd8);

  fVar25 = fVar24 * fVar16 - fVar15 * fVar21;

  fVar19 = *(float *)(param_1 + 0x9c) - *(float *)(param_1 + 0xe0);

  fVar22 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xdc);

  fVar26 = fVar16 * fVar21 + fVar24 * fVar15;

  fVar24 = (*(float *)(lVar12 + lVar13 * 0xc) + fVar25) - *(float *)(param_1 + 0x80);

  fVar21 = fVar18 * fVar19 + fVar17 * fVar22;

  fVar17 = fVar18 * fVar22 - fVar17 * fVar19;

  fVar15 = (fVar2 + fVar26) - *(float *)(param_1 + 0x84);

  fVar18 = (fVar4 + fVar21) - *(float *)(param_1 + 0x8c);

  fVar19 = (fVar3 + fVar17) - *(float *)(param_1 + 0x88);

  fVar16 = fVar15 * fVar15 + fVar24 * fVar24;

  if (fVar16 < 0.0) {

    fVar16 = (float)FUN_1402cdfa0(fVar16);

  }

  else {

    fVar16 = SQRT(fVar16);

  }

  fVar22 = fVar18 * fVar18 + fVar19 * fVar19;

  if (fVar22 < 0.0) {

    fVar22 = (float)FUN_1402cdfa0();

  }

  else {

    fVar22 = SQRT(fVar22);

  }

  if (fVar16 <= DAT_14039ca18) {

    fVar24 = 0.0;

    fVar15 = 0.0;

  }

  else {

    fVar15 = (DAT_14039ca44 / fVar16) * fVar15;

    fVar24 = (DAT_14039ca44 / fVar16) * fVar24;

  }

  if (fVar22 <= DAT_14039ca18) {

    fVar19 = 0.0;

    fVar18 = 0.0;

  }

  else {

    fVar18 = (DAT_14039ca44 / fVar22) * fVar18;

    fVar19 = (DAT_14039ca44 / fVar22) * fVar19;

  }

  fVar6 = *(float *)(param_1 + 0xa4);

  fVar7 = *(float *)(param_1 + 0xe4);

  fVar8 = *(float *)(param_1 + 0xe8);

  fVar23 = fVar25 * fVar15 - fVar24 * fVar26;

  fVar20 = fVar17 * fVar18 - fVar21 * fVar19;

  fVar9 = *(float *)(param_1 + 0xec);

  fVar10 = *(float *)(param_1 + 0xf0);

  fVar20 = (fVar10 * fVar20 * fVar20 + fVar8) * fVar6 * fVar6 + fVar9 * fVar23 * fVar23 + fVar7;

  if (0.0 < fVar20) {

    fVar20 = DAT_14039ca44 / fVar20;

  }

  fVar23 = (*(float *)(param_1 + 0xa0) - fVar16) - fVar6 * fVar22;

  fVar16 = (float)((uint)fVar20 ^ DAT_14039cac0) * fVar23;

  fVar23 = (float)((uint)fVar23 & _DAT_14039cab0);

  fVar22 = (float)((uint)fVar6 ^ DAT_14039cac0) * fVar16;

  fVar16 = (float)((uint)fVar16 ^ DAT_14039cac0);

  fVar15 = fVar16 * fVar15;

  fVar16 = fVar16 * fVar24;

  fVar18 = fVar22 * fVar18;

  fVar22 = fVar22 * fVar19;

  *(float *)(lVar12 + lVar13 * 0xc) = fVar7 * fVar16 + *(float *)(lVar12 + lVar13 * 0xc);

  *(float *)(lVar12 + 4 + lVar13 * 0xc) = fVar7 * fVar15 + fVar2;

  *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xac) * 0xc) =

       (fVar25 * fVar15 - fVar26 * fVar16) * fVar9 + fVar1;

  iVar11 = *(int *)(param_1 + 0xb0);

  lVar12 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar12 + (longlong)iVar11 * 0xc) = fVar22 * fVar8 + fVar3;

  fVar1 = DAT_14039ca08;

  *(float *)(lVar12 + 4 + (longlong)iVar11 * 0xc) = fVar18 * fVar8 + fVar4;

  lVar12 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar12 + 8 + (longlong)*(int *)(param_1 + 0xb0) * 0xc) =

       (fVar18 * fVar17 - fVar22 * fVar21) * fVar10 + fVar5;

  return CONCAT71((int7)((ulonglong)lVar12 >> 8),fVar23 < fVar1);

}




