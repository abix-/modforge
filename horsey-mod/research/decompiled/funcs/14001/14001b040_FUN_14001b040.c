// Address: 0x14001b040
// Ghidra name: FUN_14001b040
// ============ 0x14001b040 FUN_14001b040 (size=576) ============


void FUN_14001b040(longlong param_1,longlong param_2)



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

  float fVar14;

  int iVar15;

  longlong lVar16;

  longlong lVar17;

  longlong lVar18;

  float fVar19;

  float fVar20;

  

  lVar16 = *(longlong *)(param_2 + 0x20);

  fVar1 = *(float *)(param_1 + 0xb8);

  lVar17 = (longlong)*(int *)(param_1 + 0xa8);

  fVar2 = *(float *)(param_1 + 0xc0);

  lVar18 = (longlong)*(int *)(param_1 + 0xac);

  fVar3 = *(float *)(lVar16 + 8 + lVar17 * 0xc);

  fVar4 = *(float *)(lVar16 + lVar17 * 0xc);

  fVar5 = *(float *)(lVar16 + 4 + lVar17 * 0xc);

  fVar6 = *(float *)(lVar16 + 8 + lVar18 * 0xc);

  fVar7 = *(float *)(lVar16 + lVar18 * 0xc);

  fVar8 = *(float *)(lVar16 + 4 + lVar18 * 0xc);

  fVar20 = (((fVar7 - fVar6 * *(float *)(param_1 + 0xc4)) -

            (fVar4 - fVar3 * *(float *)(param_1 + 0xbc))) * *(float *)(param_1 + 0xb0) +

            ((fVar2 * fVar6 + fVar8) - (fVar1 * fVar3 + fVar5)) * *(float *)(param_1 + 0xb4) +

            *(float *)(param_1 + 0x88) + *(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0x9c)) *

           (float)(*(uint *)(param_1 + 0xe8) ^ DAT_14039cac0);

  fVar9 = *(float *)(param_1 + 0xd8);

  fVar19 = fVar20 * *(float *)(param_1 + 0xb0);

  fVar10 = *(float *)(param_1 + 0xdc);

  *(float *)(param_1 + 0xa0) = fVar20 + *(float *)(param_1 + 0xa0);

  fVar11 = *(float *)(param_1 + 0xbc);

  lVar16 = *(longlong *)(param_2 + 0x20);

  fVar20 = fVar20 * *(float *)(param_1 + 0xb4);

  fVar12 = *(float *)(param_1 + 0xc4);

  fVar13 = *(float *)(param_1 + 0xe0);

  fVar14 = *(float *)(param_1 + 0xe4);

  *(float *)(lVar16 + lVar17 * 0xc) = fVar4 - fVar19 * fVar9;

  *(float *)(lVar16 + 4 + lVar17 * 0xc) = fVar5 - fVar9 * fVar20;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xa8) * 0xc) =

       fVar3 - (fVar1 * fVar20 - fVar19 * fVar11) * fVar13;

  iVar15 = *(int *)(param_1 + 0xac);

  lVar16 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar16 + (longlong)iVar15 * 0xc) = fVar19 * fVar10 + fVar7;

  *(float *)(lVar16 + 4 + (longlong)iVar15 * 0xc) = fVar10 * fVar20 + fVar8;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xac) * 0xc) =

       (fVar2 * fVar20 - fVar19 * fVar12) * fVar14 + fVar6;

  return;

}




