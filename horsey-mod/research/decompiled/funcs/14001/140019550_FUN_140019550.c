// Address: 0x140019550
// Ghidra name: FUN_140019550
// ============ 0x140019550 FUN_140019550 (size=1025) ============


void FUN_140019550(longlong param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  longlong lVar6;

  uint uVar7;

  longlong lVar8;

  longlong lVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  

  uVar7 = DAT_14039cac0;

  lVar6 = *(longlong *)(param_2 + 8);

  lVar8 = (longlong)*(int *)(param_1 + 0xc0);

  fVar1 = *(float *)(param_1 + 0xe0);

  fVar2 = *(float *)(param_1 + 0xdc);

  lVar9 = (longlong)*(int *)(param_1 + 0xc4);

  fVar3 = *(float *)(param_1 + 0xe4);

  fVar15 = *(float *)(lVar6 + 8 + lVar8 * 0xc);

  fVar4 = *(float *)(param_1 + 0xd8);

  fVar16 = *(float *)(lVar6 + lVar9 * 0xc);

  fVar18 = *(float *)(lVar6 + 4 + lVar9 * 0xc);

  fVar19 = *(float *)(lVar6 + lVar8 * 0xc);

  fVar20 = *(float *)(lVar6 + 4 + lVar8 * 0xc);

  fVar14 = *(float *)(lVar6 + 8 + lVar9 * 0xc);

  fVar13 = ((((fVar18 - fVar20) * *(float *)(param_1 + 0xec) +

              (fVar16 - fVar19) * *(float *)(param_1 + 0xe8) + fVar14 * *(float *)(param_1 + 0xfc))

            - fVar15 * *(float *)(param_1 + 0xf8)) + *(float *)(param_1 + 0x114) +

           *(float *)(param_1 + 0xb0) * *(float *)(param_1 + 0x118)) *

           (float)(*(uint *)(param_1 + 0x110) ^ DAT_14039cac0);

  fVar10 = fVar13 * *(float *)(param_1 + 0xe8);

  *(float *)(param_1 + 0xb0) = fVar13 + *(float *)(param_1 + 0xb0);

  fVar17 = fVar13 * *(float *)(param_1 + 0xec);

  fVar19 = fVar19 - fVar4 * fVar10;

  fVar20 = fVar20 - fVar17 * fVar4;

  fVar15 = fVar15 - fVar13 * *(float *)(param_1 + 0xf8) * fVar1;

  fVar18 = fVar17 * fVar2 + fVar18;

  fVar16 = fVar2 * fVar10 + fVar16;

  fVar10 = *(float *)(param_1 + 0xac);

  fVar14 = fVar13 * *(float *)(param_1 + 0xfc) * fVar3 + fVar14;

  fVar11 = *(float *)(param_1 + 0xb4) * *param_2;

  fVar13 = *(float *)(param_1 + 0x104);

  fVar17 = ((fVar14 - fVar15) - *(float *)(param_1 + 0xb8)) *

           (float)(*(uint *)(param_1 + 0x10c) ^ uVar7) + fVar10;

  if (fVar11 <= fVar17) {

    fVar17 = fVar11;

  }

  fVar12 = (float)((uint)fVar11 ^ uVar7);

  if ((float)((uint)fVar11 ^ uVar7) <= fVar17) {

    fVar12 = fVar17;

  }

  *(float *)(param_1 + 0xac) = fVar12;

  fVar12 = fVar12 - fVar10;

  fVar15 = fVar15 - fVar1 * fVar12;

  fVar14 = fVar3 * fVar12 + fVar14;

  fVar10 = *(float *)(param_1 + 0x100);

  fVar12 = (((fVar18 - fVar20) * *(float *)(param_1 + 0xf4) +

             (fVar16 - fVar19) * *(float *)(param_1 + 0xf0) + fVar13 * fVar14) - fVar10 * fVar15) *

           (float)(*(uint *)(param_1 + 0x108) ^ uVar7);

  fVar17 = fVar12 * *(float *)(param_1 + 0xf0);

  *(float *)(param_1 + 0xa8) = fVar12 + *(float *)(param_1 + 0xa8);

  fVar11 = fVar12 * *(float *)(param_1 + 0xf4);

  lVar6 = *(longlong *)(param_2 + 8);

  *(float *)(lVar6 + lVar8 * 0xc) = fVar19 - fVar4 * fVar17;

  *(float *)(lVar6 + 4 + lVar8 * 0xc) = fVar20 - fVar11 * fVar4;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xc0) * 0xc) =

       fVar15 - fVar12 * fVar10 * fVar1;

  iVar5 = *(int *)(param_1 + 0xc4);

  lVar6 = *(longlong *)(param_2 + 8);

  *(float *)(lVar6 + (longlong)iVar5 * 0xc) = fVar2 * fVar17 + fVar16;

  *(float *)(lVar6 + 4 + (longlong)iVar5 * 0xc) = fVar11 * fVar2 + fVar18;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xc4) * 0xc) =

       fVar12 * fVar13 * fVar3 + fVar14;

  return;

}




