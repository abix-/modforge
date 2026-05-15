// Address: 0x14001a2e0
// Ghidra name: FUN_14001a2e0
// ============ 0x14001a2e0 FUN_14001a2e0 (size=708) ============


void FUN_14001a2e0(longlong param_1,longlong param_2)



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

  uint uVar16;

  longlong lVar17;

  longlong lVar18;

  uint *puVar19;

  longlong lVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float local_c8;

  float local_c4;

  float local_c0;

  undefined1 local_b8 [176];

  

  uVar16 = DAT_14039cac0;

  lVar20 = *(longlong *)(param_2 + 0x20);

  fVar1 = *(float *)(param_1 + 0xd4);

  fVar2 = *(float *)(param_1 + 200);

  fVar3 = *(float *)(param_1 + 0xd0);

  lVar17 = (longlong)*(int *)(param_1 + 0xa0);

  fVar4 = *(float *)(param_1 + 0xcc);

  fVar5 = *(float *)(lVar20 + 8 + lVar17 * 0xc);

  lVar18 = (longlong)*(int *)(param_1 + 0xa4);

  fVar6 = *(float *)(lVar20 + lVar17 * 0xc);

  fVar7 = *(float *)(lVar20 + 4 + lVar17 * 0xc);

  fVar8 = *(float *)(lVar20 + 8 + lVar18 * 0xc);

  fVar9 = *(float *)(lVar20 + lVar18 * 0xc);

  fVar10 = *(float *)(lVar20 + 4 + lVar18 * 0xc);

  local_c8 = ((fVar9 - fVar8 * *(float *)(param_1 + 0xb4)) - fVar6) -

             (float)((uint)fVar5 ^ DAT_14039cac0) * *(float *)(param_1 + 0xac);

  local_c4 = ((fVar8 * *(float *)(param_1 + 0xb0) + fVar10) - fVar7) -

             fVar5 * *(float *)(param_1 + 0xa8);

  local_c0 = fVar8 - fVar5;

  puVar19 = (uint *)FUN_140007a90(param_1 + 0xd8,local_b8,&local_c8);

  fVar21 = (float)(*puVar19 ^ uVar16);

  fVar22 = (float)(puVar19[1] ^ uVar16);

  fVar23 = (float)(puVar19[2] ^ uVar16);

  *(float *)(param_1 + 0x94) = fVar21 + *(float *)(param_1 + 0x94);

  *(float *)(param_1 + 0x98) = fVar22 + *(float *)(param_1 + 0x98);

  *(float *)(param_1 + 0x9c) = fVar23 + *(float *)(param_1 + 0x9c);

  fVar11 = *(float *)(param_1 + 0xac);

  iVar15 = *(int *)(param_1 + 0xa0);

  fVar12 = *(float *)(param_1 + 0xa8);

  fVar13 = *(float *)(param_1 + 0xb0);

  fVar14 = *(float *)(param_1 + 0xb4);

  *(float *)(lVar20 + (longlong)iVar15 * 0xc) = fVar6 - fVar21 * fVar2;

  *(float *)(lVar20 + 4 + (longlong)iVar15 * 0xc) = fVar7 - fVar22 * fVar2;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xa0) * 0xc) =

       fVar5 - (fVar23 + (fVar22 * fVar12 - fVar21 * fVar11)) * fVar3;

  iVar15 = *(int *)(param_1 + 0xa4);

  lVar20 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar20 + (longlong)iVar15 * 0xc) = fVar21 * fVar4 + fVar9;

  *(float *)(lVar20 + 4 + (longlong)iVar15 * 0xc) = fVar22 * fVar4 + fVar10;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xa4) * 0xc) =

       (fVar23 + (fVar22 * fVar13 - fVar21 * fVar14)) * fVar1 + fVar8;

  return;

}




