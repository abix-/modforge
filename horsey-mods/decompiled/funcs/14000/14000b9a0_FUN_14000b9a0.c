// Address: 0x14000b9a0
// Ghidra name: FUN_14000b9a0
// ============ 0x14000b9a0 FUN_14000b9a0 (size=625) ============


void FUN_14000b9a0(longlong param_1,longlong param_2)



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

  float fVar11;

  float fVar12;

  int iVar13;

  longlong lVar14;

  longlong lVar15;

  longlong lVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  

  lVar14 = *(longlong *)(param_2 + 0x20);

  fVar1 = *(float *)(param_1 + 0xac);

  fVar18 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0x90);

  lVar15 = (longlong)*(int *)(param_1 + 0x9c);

  lVar16 = (longlong)*(int *)(param_1 + 0xa0);

  fVar2 = *(float *)(lVar14 + 8 + lVar15 * 0xc);

  fVar3 = *(float *)(lVar14 + 8 + lVar16 * 0xc);

  fVar4 = *(float *)(lVar14 + lVar16 * 0xc);

  fVar5 = *(float *)(lVar14 + lVar15 * 0xc);

  fVar6 = *(float *)(param_1 + 0xb4);

  fVar7 = *(float *)(lVar14 + 4 + lVar15 * 0xc);

  fVar8 = *(float *)(lVar14 + 4 + lVar16 * 0xc);

  fVar19 = ((fVar4 - fVar3 * *(float *)(param_1 + 0xb8)) -

           (fVar5 - fVar2 * *(float *)(param_1 + 0xb0))) * *(float *)(param_1 + 0xa4) +

           ((fVar6 * fVar3 + fVar8) - (fVar1 * fVar2 + fVar7)) * *(float *)(param_1 + 0xa8);

  if (fVar18 < 0.0) {

    fVar19 = fVar19 + fVar18 * *(float *)(param_2 + 4);

  }

  fVar18 = *(float *)(param_1 + 0x98);

  fVar9 = *(float *)(param_1 + 0xcc);

  fVar10 = *(float *)(param_1 + 0xd0);

  fVar17 = (float)(*(uint *)(param_1 + 0xdc) ^ DAT_14039cac0) * fVar19 + fVar18;

  fVar19 = 0.0;

  if (fVar17 <= 0.0) {

    fVar19 = fVar17;

  }

  *(float *)(param_1 + 0x98) = fVar19;

  fVar19 = fVar19 - fVar18;

  lVar14 = *(longlong *)(param_2 + 0x20);

  fVar20 = fVar19 * *(float *)(param_1 + 0xa8);

  fVar19 = fVar19 * *(float *)(param_1 + 0xa4);

  fVar18 = *(float *)(param_1 + 0xb0);

  fVar17 = *(float *)(param_1 + 0xb8);

  fVar11 = *(float *)(param_1 + 0xd4);

  fVar12 = *(float *)(param_1 + 0xd8);

  *(float *)(lVar14 + lVar15 * 0xc) = fVar5 - fVar9 * fVar19;

  *(float *)(lVar14 + 4 + lVar15 * 0xc) = fVar7 - fVar20 * fVar9;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0x9c) * 0xc) =

       fVar2 - (fVar20 * fVar1 - fVar19 * fVar18) * fVar11;

  iVar13 = *(int *)(param_1 + 0xa0);

  lVar14 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar14 + (longlong)iVar13 * 0xc) = fVar10 * fVar19 + fVar4;

  *(float *)(lVar14 + 4 + (longlong)iVar13 * 0xc) = fVar20 * fVar10 + fVar8;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xa0) * 0xc) =

       (fVar20 * fVar6 - fVar19 * fVar17) * fVar12 + fVar3;

  return;

}




