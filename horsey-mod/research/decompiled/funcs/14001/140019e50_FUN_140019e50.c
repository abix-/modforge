// Address: 0x140019e50
// Ghidra name: FUN_140019e50
// ============ 0x140019e50 FUN_140019e50 (size=1160) ============


void FUN_140019e50(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  int iVar7;

  longlong lVar8;

  longlong lVar9;

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

  

  lVar8 = *(longlong *)(param_1 + 0x60);

  lVar10 = (longlong)*(int *)(lVar8 + 8);

  *(int *)(param_1 + 0xa0) = *(int *)(lVar8 + 8);

  lVar9 = *(longlong *)(param_1 + 0x68);

  lVar11 = (longlong)*(int *)(lVar9 + 8);

  *(int *)(param_1 + 0xa4) = *(int *)(lVar9 + 8);

  *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(lVar8 + 0x1c);

  *(undefined8 *)(param_1 + 0xc0) = *(undefined8 *)(lVar9 + 0x1c);

  fVar1 = *(float *)(lVar8 + 0x94);

  *(float *)(param_1 + 200) = fVar1;

  fVar2 = *(float *)(lVar9 + 0x94);

  *(float *)(param_1 + 0xcc) = fVar2;

  fVar3 = *(float *)(lVar8 + 0x9c);

  *(float *)(param_1 + 0xd0) = fVar3;

  fVar4 = *(float *)(lVar9 + 0x9c);

  *(float *)(param_1 + 0xd4) = fVar4;

  lVar8 = *(longlong *)(param_2 + 0x20);

  fVar19 = *(float *)(lVar8 + lVar10 * 0xc);

  uVar5 = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 8 + lVar10 * 0xc);

  fVar20 = *(float *)(lVar8 + 4 + lVar10 * 0xc);

  fVar21 = *(float *)(lVar8 + 8 + lVar10 * 0xc);

  uVar6 = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 8 + lVar11 * 0xc);

  fVar22 = *(float *)(lVar8 + lVar11 * 0xc);

  fVar23 = *(float *)(lVar8 + 4 + lVar11 * 0xc);

  fVar24 = *(float *)(lVar8 + 8 + lVar11 * 0xc);

  fVar12 = (float)FUN_1402cdc50(uVar5);

  fVar13 = (float)FUN_1402cfda0(uVar5);

  fVar14 = (float)FUN_1402cdc50(uVar6);

  fVar15 = (float)FUN_1402cfda0(uVar6);

  fVar16 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xbc);

  fVar17 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xb8);

  fVar18 = fVar13 * fVar17 - fVar12 * fVar16;

  *(float *)(param_1 + 0xa8) = fVar18;

  *(float *)(param_1 + 0xac) = fVar13 * fVar16 + fVar12 * fVar17;

  fVar13 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xc0);

  fVar12 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xc4);

  fVar16 = fVar15 * fVar13 - fVar14 * fVar12;

  *(float *)(param_1 + 0xb0) = fVar16;

  fVar13 = fVar15 * fVar12 + fVar14 * fVar13;

  *(float *)(param_1 + 0xb4) = fVar13;

  fVar12 = *(float *)(param_1 + 0xac);

  fVar14 = (float)((uint)fVar12 ^ DAT_14039cac0);

  *(float *)(param_1 + 0xd8) = fVar12 * fVar12 * fVar3 + fVar2 + fVar1 + fVar13 * fVar13 * fVar4;

  fVar12 = fVar14 * fVar18 * fVar3 - fVar13 * fVar16 * fVar4;

  fVar13 = fVar14 * fVar3 - fVar13 * fVar4;

  *(float *)(param_1 + 0xe4) = fVar12;

  *(float *)(param_1 + 0xdc) = fVar12;

  *(float *)(param_1 + 0xf0) = fVar13;

  *(float *)(param_1 + 0xe0) = fVar13;

  fVar12 = fVar16 * fVar4 + fVar18 * fVar3;

  *(float *)(param_1 + 0xf4) = fVar12;

  *(float *)(param_1 + 0xec) = fVar12;

  *(float *)(param_1 + 0xe8) = fVar18 * fVar18 * fVar3 + fVar2 + fVar1 + fVar16 * fVar16 * fVar4;

  *(float *)(param_1 + 0xf8) = fVar4 + fVar3;

  if (*(char *)(param_2 + 0x14) == '\0') {

    *(undefined8 *)(param_1 + 0x94) = 0;

    *(undefined4 *)(param_1 + 0x9c) = 0;

  }

  else {

    fVar12 = *(float *)(param_2 + 8);

    fVar14 = fVar12 * *(float *)(param_1 + 0x98);

    fVar13 = fVar12 * *(float *)(param_1 + 0x94);

    fVar12 = fVar12 * *(float *)(param_1 + 0x9c);

    *(float *)(param_1 + 0x98) = fVar14;

    *(float *)(param_1 + 0x94) = fVar13;

    *(float *)(param_1 + 0x9c) = fVar12;

    fVar19 = fVar19 - fVar1 * fVar13;

    fVar20 = fVar20 - fVar14 * fVar1;

    fVar23 = fVar23 + fVar14 * fVar2;

    fVar22 = fVar22 + fVar2 * fVar13;

    fVar21 = fVar21 - ((fVar14 * *(float *)(param_1 + 0xa8) - fVar13 * *(float *)(param_1 + 0xac)) +

                      fVar12) * fVar3;

    fVar24 = fVar24 + ((fVar14 * *(float *)(param_1 + 0xb0) - fVar13 * *(float *)(param_1 + 0xb4)) +

                      fVar12) * fVar4;

  }

  iVar7 = *(int *)(param_1 + 0xa0);

  lVar8 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar8 + (longlong)iVar7 * 0xc) = fVar19;

  *(float *)(lVar8 + 4 + (longlong)iVar7 * 0xc) = fVar20;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xa0) * 0xc) = fVar21;

  iVar7 = *(int *)(param_1 + 0xa4);

  lVar8 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar8 + (longlong)iVar7 * 0xc) = fVar22;

  *(float *)(lVar8 + 4 + (longlong)iVar7 * 0xc) = fVar23;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xa4) * 0xc) = fVar24;

  return;

}




