// Address: 0x140014ba0
// Ghidra name: FUN_140014ba0
// ============ 0x140014ba0 FUN_140014ba0 (size=648) ============


void FUN_140014ba0(longlong param_1,longlong param_2)



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

  float fVar13;

  int iVar14;

  longlong lVar15;

  longlong lVar16;

  longlong lVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  

  lVar15 = *(longlong *)(param_2 + 0x20);

  fVar1 = *(float *)(param_1 + 0xc4);

  lVar16 = (longlong)*(int *)(param_1 + 0xac);

  fVar2 = *(float *)(lVar15 + 8 + lVar16 * 0xc);

  fVar3 = *(float *)(param_1 + 0xcc);

  lVar17 = (longlong)*(int *)(param_1 + 0xb0);

  fVar4 = *(float *)(lVar15 + lVar16 * 0xc);

  fVar5 = *(float *)(lVar15 + 4 + lVar16 * 0xc);

  fVar6 = *(float *)(lVar15 + 8 + lVar17 * 0xc);

  fVar7 = *(float *)(lVar15 + lVar17 * 0xc);

  fVar8 = *(float *)(lVar15 + 4 + lVar17 * 0xc);

  fVar9 = *(float *)(param_1 + 0xe4);

  fVar19 = ((float)((uint)((fVar1 * fVar2 + fVar5) * *(float *)(param_1 + 0xb8) +

                          (fVar4 - fVar2 * *(float *)(param_1 + 200)) * *(float *)(param_1 + 0xb4))

                   ^ DAT_14039cac0) -

           ((fVar7 - fVar6 * *(float *)(param_1 + 0xd0)) * *(float *)(param_1 + 0xbc) +

           (fVar3 * fVar6 + fVar8) * *(float *)(param_1 + 0xc0)) * *(float *)(param_1 + 0xa4)) *

           (float)(*(uint *)(param_1 + 0xf4) ^ DAT_14039cac0);

  fVar21 = (float)((uint)*(float *)(param_1 + 0xa4) ^ DAT_14039cac0) * fVar19;

  fVar18 = (float)((uint)fVar19 ^ DAT_14039cac0);

  fVar10 = *(float *)(param_1 + 0xe8);

  fVar20 = *(float *)(param_1 + 0xb4) * fVar18;

  *(float *)(param_1 + 0xa8) = fVar19 + *(float *)(param_1 + 0xa8);

  fVar18 = fVar18 * *(float *)(param_1 + 0xb8);

  fVar22 = fVar21 * *(float *)(param_1 + 0xc0);

  fVar19 = *(float *)(param_1 + 200);

  fVar21 = fVar21 * *(float *)(param_1 + 0xbc);

  fVar11 = *(float *)(param_1 + 0xd0);

  fVar12 = *(float *)(param_1 + 0xec);

  fVar13 = *(float *)(param_1 + 0xf0);

  lVar15 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar15 + lVar16 * 0xc) = fVar20 * fVar9 + fVar4;

  *(float *)(lVar15 + 4 + lVar16 * 0xc) = fVar9 * fVar18 + fVar5;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xac) * 0xc) =

       (fVar1 * fVar18 - fVar20 * fVar19) * fVar12 + fVar2;

  iVar14 = *(int *)(param_1 + 0xb0);

  lVar15 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar15 + (longlong)iVar14 * 0xc) = fVar21 * fVar10 + fVar7;

  *(float *)(lVar15 + 4 + (longlong)iVar14 * 0xc) = fVar10 * fVar22 + fVar8;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xb0) * 0xc) =

       (fVar3 * fVar22 - fVar21 * fVar11) * fVar13 + fVar6;

  return;

}




