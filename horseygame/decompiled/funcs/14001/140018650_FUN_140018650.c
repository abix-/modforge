// Address: 0x140018650
// Ghidra name: FUN_140018650
// ============ 0x140018650 FUN_140018650 (size=1188) ============


void FUN_140018650(longlong param_1,longlong param_2)



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

  float fVar25;

  

  lVar8 = *(longlong *)(param_1 + 0x60);

  lVar10 = (longlong)*(int *)(lVar8 + 8);

  *(int *)(param_1 + 0xa4) = *(int *)(lVar8 + 8);

  lVar9 = *(longlong *)(param_1 + 0x68);

  lVar11 = (longlong)*(int *)(lVar9 + 8);

  *(int *)(param_1 + 0xa8) = *(int *)(lVar9 + 8);

  *(undefined8 *)(param_1 + 0xbc) = *(undefined8 *)(lVar8 + 0x1c);

  *(undefined8 *)(param_1 + 0xc4) = *(undefined8 *)(lVar9 + 0x1c);

  fVar1 = *(float *)(lVar8 + 0x94);

  *(float *)(param_1 + 0xcc) = fVar1;

  fVar2 = *(float *)(lVar9 + 0x94);

  *(float *)(param_1 + 0xd0) = fVar2;

  fVar3 = *(float *)(lVar8 + 0x9c);

  *(float *)(param_1 + 0xd4) = fVar3;

  fVar4 = *(float *)(lVar9 + 0x9c);

  *(float *)(param_1 + 0xd8) = fVar4;

  lVar8 = *(longlong *)(param_2 + 0x20);

  fVar20 = *(float *)(lVar8 + lVar10 * 0xc);

  uVar5 = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 8 + lVar10 * 0xc);

  fVar21 = *(float *)(lVar8 + 4 + lVar10 * 0xc);

  fVar22 = *(float *)(lVar8 + 8 + lVar10 * 0xc);

  uVar6 = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 8 + lVar11 * 0xc);

  fVar23 = *(float *)(lVar8 + lVar11 * 0xc);

  fVar24 = *(float *)(lVar8 + 4 + lVar11 * 0xc);

  fVar25 = *(float *)(lVar8 + 8 + lVar11 * 0xc);

  fVar12 = (float)FUN_1402cdc50(uVar5);

  fVar13 = (float)FUN_1402cfda0(uVar5);

  fVar14 = (float)FUN_1402cdc50(uVar6);

  fVar15 = (float)FUN_1402cfda0(uVar6);

  fVar16 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xc0);

  fVar17 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xbc);

  fVar18 = fVar13 * fVar17 - fVar12 * fVar16;

  fVar17 = fVar13 * fVar16 + fVar12 * fVar17;

  *(float *)(param_1 + 0xac) = fVar18;

  *(float *)(param_1 + 0xb0) = fVar17;

  fVar13 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xc4);

  fVar12 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 200);

  fVar16 = fVar15 * fVar13 - fVar14 * fVar12;

  fVar13 = fVar15 * fVar12 + fVar14 * fVar13;

  *(float *)(param_1 + 0xb4) = fVar16;

  *(float *)(param_1 + 0xb8) = fVar13;

  fVar12 = DAT_14039ca44;

  fVar19 = fVar17 * fVar3 * fVar17 + fVar2 + fVar1 + fVar13 * fVar4 * fVar13;

  fVar14 = (float)((uint)fVar3 ^ DAT_14039cac0) * fVar18 * fVar17 - fVar13 * fVar16 * fVar4;

  fVar15 = fVar18 * fVar3 * fVar18 + fVar2 + fVar1 + fVar16 * fVar4 * fVar16;

  fVar13 = fVar15 * fVar19 - fVar14 * fVar14;

  if (fVar13 != 0.0) {

    fVar13 = DAT_14039ca44 / fVar13;

  }

  fVar14 = (float)((uint)fVar13 ^ DAT_14039cac0) * fVar14;

  *(float *)(param_1 + 0xdc) = fVar15 * fVar13;

  *(float *)(param_1 + 0xe0) = fVar14;

  *(float *)(param_1 + 0xe4) = fVar14;

  fVar14 = fVar4 + fVar3;

  *(float *)(param_1 + 0xe8) = fVar19 * fVar13;

  *(float *)(param_1 + 0xec) = fVar14;

  if (0.0 < fVar14) {

    *(float *)(param_1 + 0xec) = fVar12 / fVar14;

  }

  if (*(char *)(param_2 + 0x14) == '\0') {

    *(undefined8 *)(param_1 + 0x90) = 0;

    *(undefined4 *)(param_1 + 0x98) = 0;

  }

  else {

    fVar12 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x94);

    fVar14 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x90);

    *(float *)(param_1 + 0x94) = fVar12;

    *(float *)(param_1 + 0x90) = fVar14;

    fVar21 = fVar21 - fVar12 * fVar1;

    fVar13 = *(float *)(param_1 + 0x98) * *(float *)(param_2 + 8);

    fVar20 = fVar20 - fVar14 * fVar1;

    *(float *)(param_1 + 0x98) = fVar13;

    fVar24 = fVar24 + fVar12 * fVar2;

    fVar23 = fVar23 + fVar14 * fVar2;

    fVar22 = fVar22 - ((fVar12 * fVar18 - fVar14 * *(float *)(param_1 + 0xb0)) + fVar13) * fVar3;

    fVar25 = fVar25 + ((fVar12 * *(float *)(param_1 + 0xb4) - fVar14 * *(float *)(param_1 + 0xb8)) +

                      fVar13) * fVar4;

  }

  iVar7 = *(int *)(param_1 + 0xa4);

  lVar8 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar8 + (longlong)iVar7 * 0xc) = fVar20;

  *(float *)(lVar8 + 4 + (longlong)iVar7 * 0xc) = fVar21;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xa4) * 0xc) = fVar22;

  iVar7 = *(int *)(param_1 + 0xa8);

  lVar8 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar8 + (longlong)iVar7 * 0xc) = fVar23;

  *(float *)(lVar8 + 4 + (longlong)iVar7 * 0xc) = fVar24;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xa8) * 0xc) = fVar25;

  return;

}




