// Address: 0x14001bb70
// Ghidra name: FUN_14001bb70
// ============ 0x14001bb70 FUN_14001bb70 (size=2248) ============


void FUN_14001bb70(longlong param_1,longlong param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  longlong lVar10;

  longlong lVar11;

  int iVar12;

  longlong lVar13;

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

  float fVar27;

  float fVar28;

  float fVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  float fVar33;

  float fVar34;

  float fVar35;

  float fVar36;

  float fVar37;

  float fVar38;

  undefined4 local_res10;

  undefined4 local_res18;

  undefined4 local_res20;

  undefined4 local_108;

  undefined4 local_104;

  

  lVar5 = *(longlong *)(param_1 + 0x88);

  lVar6 = *(longlong *)(param_1 + 0x60);

  lVar7 = *(longlong *)(param_1 + 0x68);

  iVar12 = *(int *)(lVar6 + 8);

  lVar13 = (longlong)iVar12;

  *(int *)(param_1 + 0xdc) = iVar12;

  lVar11 = (longlong)*(int *)(lVar7 + 8);

  *(int *)(param_1 + 0xe0) = *(int *)(lVar7 + 8);

  lVar9 = (longlong)*(int *)(lVar5 + 8);

  *(int *)(param_1 + 0xe4) = *(int *)(lVar5 + 8);

  lVar8 = *(longlong *)(param_1 + 0x90);

  lVar10 = (longlong)*(int *)(lVar8 + 8);

  *(int *)(param_1 + 0xe8) = *(int *)(lVar8 + 8);

  *(undefined8 *)(param_1 + 0xec) = *(undefined8 *)(lVar6 + 0x1c);

  *(undefined8 *)(param_1 + 0xf4) = *(undefined8 *)(lVar7 + 0x1c);

  *(undefined8 *)(param_1 + 0xfc) = *(undefined8 *)(lVar5 + 0x1c);

  *(undefined8 *)(param_1 + 0x104) = *(undefined8 *)(lVar8 + 0x1c);

  fVar34 = *(float *)(lVar6 + 0x94);

  *(float *)(param_1 + 0x10c) = fVar34;

  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(lVar7 + 0x94);

  fVar22 = *(float *)(lVar5 + 0x94);

  *(float *)(param_1 + 0x114) = fVar22;

  *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(lVar8 + 0x94);

  fVar36 = *(float *)(lVar6 + 0x9c);

  *(float *)(param_1 + 0x11c) = fVar36;

  *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(lVar7 + 0x9c);

  fVar33 = *(float *)(lVar5 + 0x9c);

  *(float *)(param_1 + 0x124) = fVar33;

  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(lVar8 + 0x9c);

  lVar5 = *(longlong *)(param_2 + 0x20);

  lVar6 = *(longlong *)(param_2 + 0x18);

  local_res10 = *(float *)(lVar5 + 4 + lVar13 * 0xc);

  uVar1 = *(undefined4 *)(lVar6 + 8 + lVar13 * 0xc);

  fVar38 = *(float *)(lVar5 + lVar13 * 0xc);

  fVar35 = *(float *)(lVar5 + 8 + lVar13 * 0xc);

  uVar2 = *(undefined4 *)(lVar6 + 8 + lVar11 * 0xc);

  fVar37 = *(float *)(lVar5 + lVar11 * 0xc);

  local_res18 = *(float *)(lVar5 + 4 + lVar11 * 0xc);

  fVar23 = *(float *)(lVar5 + 8 + lVar11 * 0xc);

  uVar3 = *(undefined4 *)(lVar6 + 8 + lVar9 * 0xc);

  fVar27 = *(float *)(lVar5 + lVar9 * 0xc);

  local_res20 = *(float *)(lVar5 + 4 + lVar9 * 0xc);

  fVar30 = *(float *)(lVar5 + 8 + lVar9 * 0xc);

  uVar4 = *(undefined4 *)(lVar6 + 8 + lVar10 * 0xc);

  fVar25 = *(float *)(lVar5 + lVar10 * 0xc);

  local_108 = *(float *)(lVar5 + 4 + lVar10 * 0xc);

  local_104 = *(float *)(lVar5 + 8 + lVar10 * 0xc);

  fVar14 = (float)FUN_1402cdc50(uVar1);

  fVar15 = (float)FUN_1402cfda0(uVar1);

  fVar16 = (float)FUN_1402cdc50(uVar2);

  fVar17 = (float)FUN_1402cfda0(uVar2);

  fVar18 = (float)FUN_1402cdc50(uVar3);

  fVar19 = (float)FUN_1402cfda0(uVar3);

  fVar20 = (float)FUN_1402cdc50(uVar4);

  fVar21 = (float)FUN_1402cfda0(uVar4);

  *(undefined4 *)(param_1 + 0x14c) = 0;

  if (*(int *)(param_1 + 0x80) == 1) {

    *(undefined8 *)(param_1 + 300) = 0;

    *(undefined4 *)(param_1 + 0x13c) = 0x3f800000;

    *(undefined4 *)(param_1 + 0x144) = 0x3f800000;

    fVar34 = fVar33 + fVar36 + *(float *)(param_1 + 0x14c);

  }

  else {

    fVar32 = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0xfc);

    fVar26 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xec);

    fVar24 = *(float *)(param_1 + 0x9c) - *(float *)(param_1 + 0xf0);

    fVar31 = fVar19 * *(float *)(param_1 + 0xb8) - *(float *)(param_1 + 0xbc) * fVar18;

    fVar29 = *(float *)(param_1 + 0xac) - *(float *)(param_1 + 0x100);

    fVar28 = *(float *)(param_1 + 0xb8) * fVar18 + fVar19 * *(float *)(param_1 + 0xbc);

    *(float *)(param_1 + 300) = fVar31;

    *(float *)(param_1 + 0x130) = fVar28;

    fVar18 = (fVar19 * fVar32 - fVar29 * fVar18) * fVar28 -

             (fVar32 * fVar18 + fVar19 * fVar29) * fVar31;

    *(float *)(param_1 + 0x144) = fVar18;

    fVar14 = (fVar15 * fVar26 - fVar14 * fVar24) * fVar28 -

             (fVar15 * fVar24 + fVar14 * fVar26) * fVar31;

    *(float *)(param_1 + 0x13c) = fVar14;

    fVar34 = fVar33 * fVar18 * fVar18 + fVar22 + fVar34 + fVar36 * fVar14 * fVar14 + 0.0;

  }

  *(float *)(param_1 + 0x14c) = fVar34;

  if (*(int *)(param_1 + 0x84) == 1) {

    *(undefined8 *)(param_1 + 0x134) = 0;

    fVar22 = *(float *)(param_1 + 0xd4);

    fVar36 = *(float *)(param_1 + 0x128);

    fVar33 = *(float *)(param_1 + 0x120);

    iVar12 = *(int *)(param_1 + 0xdc);

    *(float *)(param_1 + 0x148) = fVar22;

    fVar34 = (fVar36 + fVar33) * fVar22 * fVar22 + *(float *)(param_1 + 0x14c);

    fVar15 = fVar22;

  }

  else {

    fVar18 = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xf8);

    fVar15 = *(float *)(param_1 + 0xb0) - *(float *)(param_1 + 0x104);

    fVar19 = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0xf4);

    fVar14 = *(float *)(param_1 + 0xd4);

    fVar32 = fVar21 * *(float *)(param_1 + 0xc0) - *(float *)(param_1 + 0xc4) * fVar20;

    fVar29 = fVar21 * *(float *)(param_1 + 0xc4) + *(float *)(param_1 + 0xc0) * fVar20;

    fVar22 = *(float *)(param_1 + 0xb4) - *(float *)(param_1 + 0x108);

    *(float *)(param_1 + 0x134) = fVar14 * fVar32;

    *(float *)(param_1 + 0x138) = fVar14 * fVar29;

    fVar33 = *(float *)(param_1 + 0x120);

    fVar36 = *(float *)(param_1 + 0x128);

    fVar15 = ((fVar21 * fVar15 - fVar22 * fVar20) * fVar29 -

             (fVar21 * fVar22 + fVar15 * fVar20) * fVar32) * fVar14;

    *(float *)(param_1 + 0x148) = fVar15;

    fVar22 = ((fVar17 * fVar19 - fVar18 * fVar16) * fVar29 -

             (fVar17 * fVar18 + fVar19 * fVar16) * fVar32) * fVar14;

    fVar34 = (*(float *)(param_1 + 0x118) + *(float *)(param_1 + 0x110)) * fVar14 * fVar14 +

             fVar15 * fVar36 * fVar15 + fVar22 * fVar33 * fVar22 + fVar34;

  }

  *(float *)(param_1 + 0x140) = fVar22;

  if (fVar34 <= 0.0) {

    fVar34 = 0.0;

  }

  else {

    fVar34 = DAT_14039ca44 / fVar34;

  }

  *(float *)(param_1 + 0x14c) = fVar34;

  if (*(char *)(param_2 + 0x14) == '\0') {

    *(undefined4 *)(param_1 + 0xd8) = 0;

  }

  else {

    fVar34 = *(float *)(param_1 + 0xd8);

    fVar14 = fVar34 * *(float *)(param_1 + 0x10c);

    fVar16 = fVar34 * *(float *)(param_1 + 0x110);

    fVar38 = fVar38 + *(float *)(param_1 + 300) * fVar14;

    local_res10 = local_res10 + *(float *)(param_1 + 0x130) * fVar14;

    fVar35 = fVar35 + fVar34 * *(float *)(param_1 + 0x11c) * *(float *)(param_1 + 0x13c);

    fVar37 = fVar37 + *(float *)(param_1 + 0x134) * fVar16;

    local_res18 = local_res18 + *(float *)(param_1 + 0x138) * fVar16;

    fVar14 = fVar34 * *(float *)(param_1 + 0x114);

    fVar23 = fVar23 + fVar34 * fVar33 * fVar22;

    fVar27 = fVar27 - fVar14 * *(float *)(param_1 + 300);

    local_res20 = local_res20 - fVar14 * *(float *)(param_1 + 0x130);

    fVar22 = fVar34 * *(float *)(param_1 + 0x118);

    fVar30 = fVar30 - fVar34 * *(float *)(param_1 + 0x124) * *(float *)(param_1 + 0x144);

    fVar25 = fVar25 - fVar22 * *(float *)(param_1 + 0x134);

    local_108 = local_108 - fVar22 * *(float *)(param_1 + 0x138);

    local_104 = local_104 - fVar34 * fVar36 * fVar15;

  }

  lVar5 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar5 + (longlong)iVar12 * 0xc) = fVar38;

  *(float *)(lVar5 + 4 + (longlong)iVar12 * 0xc) = local_res10;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xdc) * 0xc) = fVar35;

  iVar12 = *(int *)(param_1 + 0xe0);

  lVar5 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar5 + (longlong)iVar12 * 0xc) = fVar37;

  *(float *)(lVar5 + 4 + (longlong)iVar12 * 0xc) = local_res18;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xe0) * 0xc) = fVar23;

  iVar12 = *(int *)(param_1 + 0xe4);

  lVar5 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar5 + (longlong)iVar12 * 0xc) = fVar27;

  *(float *)(lVar5 + 4 + (longlong)iVar12 * 0xc) = local_res20;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xe4) * 0xc) = fVar30;

  iVar12 = *(int *)(param_1 + 0xe8);

  lVar5 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar5 + (longlong)iVar12 * 0xc) = fVar25;

  *(float *)(lVar5 + 4 + (longlong)iVar12 * 0xc) = local_108;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xe8) * 0xc) =

       local_104;

  return;

}




