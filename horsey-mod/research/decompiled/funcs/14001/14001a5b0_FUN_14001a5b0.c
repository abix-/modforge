// Address: 0x14001a5b0
// Ghidra name: FUN_14001a5b0
// ============ 0x14001a5b0 FUN_14001a5b0 (size=1216) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14001a5b0(longlong param_1,longlong param_2)



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

  uint uVar10;

  int iVar11;

  longlong lVar12;

  uint uVar13;

  longlong lVar14;

  longlong lVar15;

  uint *puVar16;

  undefined8 uVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float extraout_XMM0_Da;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  float local_d8;

  float local_d4;

  float local_d0;

  undefined1 local_c8 [176];

  

  lVar12 = *(longlong *)(param_2 + 0x18);

  lVar14 = (longlong)*(int *)(param_1 + 0xa0);

  lVar15 = (longlong)*(int *)(param_1 + 0xa4);

  fVar26 = *(float *)(lVar12 + 4 + lVar14 * 0xc);

  fVar1 = *(float *)(lVar12 + 8 + lVar14 * 0xc);

  fVar2 = *(float *)(lVar12 + lVar14 * 0xc);

  fVar3 = *(float *)(lVar12 + 4 + lVar15 * 0xc);

  fVar4 = *(float *)(lVar12 + lVar15 * 0xc);

  fVar5 = *(float *)(lVar12 + 8 + lVar15 * 0xc);

  fVar18 = (float)FUN_1402cdc50(fVar1);

  fVar19 = (float)FUN_1402cfda0(fVar1);

  fVar20 = (float)FUN_1402cdc50(fVar5);

  fVar21 = (float)FUN_1402cfda0(fVar5);

  uVar13 = DAT_14039cac0;

  fVar24 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xb8);

  fVar22 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xbc);

  fVar6 = *(float *)(param_1 + 200);

  fVar7 = *(float *)(param_1 + 0xcc);

  fVar8 = *(float *)(param_1 + 0xd0);

  fVar9 = *(float *)(param_1 + 0xd4);

  fVar27 = fVar24 * fVar19 - fVar18 * fVar22;

  fVar23 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xc4);

  fVar24 = fVar19 * fVar22 + fVar24 * fVar18;

  fVar18 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xc0);

  fVar22 = fVar21 * fVar23 + fVar20 * fVar18;

  fVar21 = fVar21 * fVar18 - fVar20 * fVar23;

  fVar20 = ((fVar4 + fVar21) - fVar2) - fVar27;

  fVar19 = ((fVar3 + fVar22) - fVar26) - fVar24;

  for (fVar18 = (fVar5 - fVar1) - *(float *)(param_1 + 0x90); DAT_14039ca50 < fVar18;

      fVar18 = fVar18 + DAT_14039ca88) {

  }

  for (; fVar18 < DAT_14039ca84; fVar18 = fVar18 + DAT_14039ca54) {

  }

  fVar25 = (float)((uint)fVar24 ^ DAT_14039cac0);

  *(float *)(param_1 + 0xd8) = fVar24 * fVar24 * fVar8 + fVar7 + fVar6 + fVar22 * fVar22 * fVar9;

  fVar23 = fVar25 * fVar27 * fVar8 - fVar22 * fVar21 * fVar9;

  fVar25 = fVar25 * fVar8 - fVar22 * fVar9;

  *(float *)(param_1 + 0xe4) = fVar23;

  *(float *)(param_1 + 0xdc) = fVar23;

  *(float *)(param_1 + 0xf0) = fVar25;

  *(float *)(param_1 + 0xe0) = fVar25;

  *(float *)(param_1 + 0xe8) = fVar27 * fVar27 * fVar8 + fVar7 + fVar6 + fVar21 * fVar21 * fVar9;

  fVar23 = fVar21 * fVar9 + fVar27 * fVar8;

  *(float *)(param_1 + 0xf4) = fVar23;

  *(float *)(param_1 + 0xf8) = fVar9 + fVar8;

  *(float *)(param_1 + 0xec) = fVar23;

  local_d8 = fVar20;

  local_d4 = fVar19;

  local_d0 = fVar18;

  puVar16 = (uint *)FUN_140007a90((float *)(param_1 + 0xd8),local_c8,&local_d8);

  fVar23 = (float)(*puVar16 ^ uVar13);

  uVar10 = puVar16[2];

  fVar25 = (float)(puVar16[1] ^ uVar13);

  lVar12 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar12 + lVar14 * 0xc) = fVar2 - fVar23 * fVar6;

  *(float *)(lVar12 + 4 + lVar14 * 0xc) = fVar26 - fVar25 * fVar6;

  *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xa0) * 0xc) =

       fVar1 - ((fVar25 * fVar27 - fVar23 * fVar24) + (float)(uVar10 ^ uVar13)) * fVar8;

  iVar11 = *(int *)(param_1 + 0xa4);

  lVar12 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar12 + (longlong)iVar11 * 0xc) = fVar23 * fVar7 + fVar4;

  *(float *)(lVar12 + 4 + (longlong)iVar11 * 0xc) = fVar25 * fVar7 + fVar3;

  fVar26 = fVar19 * fVar19 + fVar20 * fVar20;

  *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xa4) * 0xc) =

       ((fVar25 * fVar21 - fVar23 * fVar22) + (float)(uVar10 ^ uVar13)) * fVar9 + fVar5;

  if (fVar26 < 0.0) {

    FUN_1402cdfa0(fVar26);

    fVar26 = extraout_XMM0_Da;

  }

  else {

    fVar26 = SQRT(fVar26);

  }

  if ((DAT_14039ca08 < fVar26) || (DAT_14039ca14 < (float)((uint)fVar18 & _DAT_14039cab0))) {

    uVar17 = 0;

  }

  else {

    uVar17 = 1;

  }

  return uVar17;

}




