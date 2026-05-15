// Address: 0x140018b00
// Ghidra name: FUN_140018b00
// ============ 0x140018b00 FUN_140018b00 (size=859) ============


void FUN_140018b00(longlong param_1,float *param_2)



{

  float *pfVar1;

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

  uint uVar13;

  longlong lVar14;

  longlong lVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  

  uVar13 = DAT_14039cac0;

  lVar12 = *(longlong *)(param_2 + 8);

  fVar2 = *(float *)(param_1 + 0x98);

  pfVar1 = (float *)(param_1 + 0x90);

  fVar3 = *(float *)(param_1 + 0xd8);

  fVar20 = *param_2;

  fVar17 = fVar20 * *(float *)(param_1 + 0xa0);

  lVar14 = (longlong)*(int *)(param_1 + 0xa4);

  fVar4 = *(float *)(param_1 + 0xd4);

  fVar5 = *(float *)(param_1 + 0xcc);

  fVar6 = *(float *)(param_1 + 0xd0);

  fVar21 = *(float *)(lVar12 + 8 + lVar14 * 0xc);

  lVar15 = (longlong)*(int *)(param_1 + 0xa8);

  fVar7 = *(float *)(lVar12 + lVar14 * 0xc);

  fVar8 = *(float *)(lVar12 + 4 + lVar14 * 0xc);

  fVar22 = *(float *)(lVar12 + 8 + lVar15 * 0xc);

  fVar9 = *(float *)(lVar12 + lVar15 * 0xc);

  fVar10 = *(float *)(lVar12 + 4 + lVar15 * 0xc);

  fVar16 = (fVar22 - fVar21) * (float)(*(uint *)(param_1 + 0xec) ^ DAT_14039cac0) + fVar2;

  if (fVar17 <= fVar16) {

    fVar16 = fVar17;

  }

  fVar18 = (float)((uint)fVar17 ^ DAT_14039cac0);

  if ((float)((uint)fVar17 ^ DAT_14039cac0) <= fVar16) {

    fVar18 = fVar16;

  }

  *(float *)(param_1 + 0x98) = fVar18;

  fVar18 = fVar18 - fVar2;

  fVar21 = fVar21 - fVar4 * fVar18;

  fVar22 = fVar3 * fVar18 + fVar22;

  fVar17 = ((fVar9 - fVar22 * *(float *)(param_1 + 0xb8)) - fVar7) -

           (float)((uint)fVar21 ^ uVar13) * *(float *)(param_1 + 0xb0);

  fVar18 = ((fVar22 * *(float *)(param_1 + 0xb4) + fVar10) - fVar8) -

           fVar21 * *(float *)(param_1 + 0xac);

  fVar2 = *(float *)(param_1 + 0x94);

  fVar16 = *pfVar1;

  fVar19 = (float)((uint)(fVar18 * *(float *)(param_1 + 0xe8) + fVar17 * *(float *)(param_1 + 0xe0))

                  ^ uVar13) + *(float *)(param_1 + 0x94);

  fVar20 = fVar20 * *(float *)(param_1 + 0x9c);

  fVar17 = fVar16 - (fVar18 * *(float *)(param_1 + 0xe4) + fVar17 * *(float *)(param_1 + 0xdc));

  *(float *)(param_1 + 0x94) = fVar19;

  *pfVar1 = fVar17;

  if (fVar20 * fVar20 < fVar17 * fVar17 + fVar19 * fVar19) {

    FUN_1400058e0(pfVar1);

    fVar19 = fVar20 * *(float *)(param_1 + 0x94);

    *pfVar1 = fVar20 * *pfVar1;

    *(float *)(param_1 + 0x94) = fVar19;

  }

  iVar11 = *(int *)(param_1 + 0xa4);

  fVar16 = *pfVar1 - fVar16;

  fVar19 = fVar19 - fVar2;

  lVar12 = *(longlong *)(param_2 + 8);

  fVar2 = *(float *)(param_1 + 0xb0);

  fVar20 = *(float *)(param_1 + 0xac);

  fVar17 = *(float *)(param_1 + 0xb4);

  fVar18 = *(float *)(param_1 + 0xb8);

  *(float *)(lVar12 + (longlong)iVar11 * 0xc) = fVar7 - fVar16 * fVar5;

  *(float *)(lVar12 + 4 + (longlong)iVar11 * 0xc) = fVar8 - fVar19 * fVar5;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xa4) * 0xc) =

       fVar21 - (fVar19 * fVar20 - fVar16 * fVar2) * fVar4;

  iVar11 = *(int *)(param_1 + 0xa8);

  lVar12 = *(longlong *)(param_2 + 8);

  *(float *)(lVar12 + (longlong)iVar11 * 0xc) = fVar16 * fVar6 + fVar9;

  *(float *)(lVar12 + 4 + (longlong)iVar11 * 0xc) = fVar19 * fVar6 + fVar10;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xa8) * 0xc) =

       (fVar19 * fVar17 - fVar16 * fVar18) * fVar3 + fVar22;

  return;

}




