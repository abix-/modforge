// Address: 0x140019960
// Ghidra name: FUN_140019960
// ============ 0x140019960 FUN_140019960 (size=909) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140019960(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  longlong lVar8;

  bool bVar9;

  longlong lVar10;

  longlong lVar11;

  float fVar12;

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

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  

  lVar8 = *(longlong *)(param_2 + 0x18);

  lVar10 = (longlong)*(int *)(param_1 + 0xc0);

  lVar11 = (longlong)*(int *)(param_1 + 0xc4);

  fVar1 = *(float *)(lVar8 + 8 + lVar10 * 0xc);

  fVar2 = *(float *)(lVar8 + lVar10 * 0xc);

  fVar3 = *(float *)(lVar8 + 4 + lVar10 * 0xc);

  fVar4 = *(float *)(lVar8 + 4 + lVar11 * 0xc);

  fVar5 = *(float *)(lVar8 + lVar11 * 0xc);

  fVar6 = *(float *)(lVar8 + 8 + lVar11 * 0xc);

  fVar12 = (float)FUN_1402cdc50(fVar1);

  fVar13 = (float)FUN_1402cfda0(fVar1);

  fVar14 = (float)FUN_1402cdc50(fVar6);

  fVar15 = (float)FUN_1402cfda0(fVar6);

  fVar17 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 200);

  fVar22 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xcc);

  fVar19 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xd4);

  fVar24 = fVar17 * fVar13 - fVar22 * fVar12;

  fVar16 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xd0);

  fVar23 = fVar22 * fVar13 + fVar17 * fVar12;

  fVar20 = fVar19 * fVar15 + fVar16 * fVar14;

  fVar22 = fVar16 * fVar15 - fVar19 * fVar14;

  fVar26 = *(float *)(param_1 + 0xa0) * fVar13 - *(float *)(param_1 + 0xa4) * fVar12;

  fVar16 = ((fVar4 - fVar3) + fVar20) - fVar23;

  fVar21 = *(float *)(param_1 + 0xa0) * fVar12 + *(float *)(param_1 + 0xa4) * fVar13;

  fVar19 = ((fVar5 - fVar2) + fVar22) - fVar24;

  fVar12 = *(float *)(param_1 + 0xe0);

  fVar13 = *(float *)(param_1 + 0xe4);

  fVar14 = *(float *)(param_1 + 0xdc);

  fVar15 = *(float *)(param_1 + 0xd8);

  fVar18 = fVar21 * fVar16 + fVar26 * fVar19;

  fVar17 = 0.0;

  fVar25 = fVar12 * *(float *)(param_1 + 0x100) * *(float *)(param_1 + 0x100) + fVar14 + fVar15 +

           fVar13 * *(float *)(param_1 + 0x104) * *(float *)(param_1 + 0x104);

  if (fVar25 != 0.0) {

    fVar17 = (float)((uint)fVar18 ^ DAT_14039cac0) / fVar25;

  }

  bVar9 = (float)((uint)fVar18 & _DAT_14039cab0) <= DAT_14039ca08;

  *(float *)(lVar8 + lVar10 * 0xc) = fVar2 - fVar26 * fVar17 * fVar15;

  *(float *)(lVar8 + 4 + lVar10 * 0xc) = fVar3 - fVar21 * fVar17 * fVar15;

  *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xc0) * 0xc) =

       fVar1 - ((fVar19 + fVar24) * fVar21 - (fVar16 + fVar23) * fVar26) * fVar17 * fVar12;

  iVar7 = *(int *)(param_1 + 0xc4);

  lVar8 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar8 + (longlong)iVar7 * 0xc) = fVar26 * fVar17 * fVar14 + fVar5;

  *(float *)(lVar8 + 4 + (longlong)iVar7 * 0xc) = fVar21 * fVar17 * fVar14 + fVar4;

  lVar8 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar8 + 8 + (longlong)*(int *)(param_1 + 0xc4) * 0xc) =

       (fVar21 * fVar22 - fVar26 * fVar20) * fVar17 * fVar13 + fVar6;

  return CONCAT71((int7)((ulonglong)lVar8 >> 8),bVar9);

}




