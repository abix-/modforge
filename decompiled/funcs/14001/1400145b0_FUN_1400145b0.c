// Address: 0x1400145b0
// Ghidra name: FUN_1400145b0
// ============ 0x1400145b0 FUN_1400145b0 (size=1515) ============


void FUN_1400145b0(longlong param_1,longlong param_2)



{

  undefined4 uVar1;

  float fVar2;

  undefined4 uVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  float fVar9;

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

  undefined4 local_res8;

  undefined4 local_res10;

  undefined4 local_res18;

  undefined4 local_res20;

  

  lVar5 = *(longlong *)(param_1 + 0x68);

  lVar6 = *(longlong *)(param_1 + 0x60);

  lVar7 = (longlong)*(int *)(lVar6 + 8);

  *(int *)(param_1 + 0xac) = *(int *)(lVar6 + 8);

  lVar8 = (longlong)*(int *)(lVar5 + 8);

  *(int *)(param_1 + 0xb0) = *(int *)(lVar5 + 8);

  *(undefined8 *)(param_1 + 0xd4) = *(undefined8 *)(lVar6 + 0x1c);

  *(undefined8 *)(param_1 + 0xdc) = *(undefined8 *)(lVar5 + 0x1c);

  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(lVar6 + 0x94);

  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(lVar5 + 0x94);

  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(lVar6 + 0x9c);

  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(lVar5 + 0x9c);

  lVar5 = *(longlong *)(param_2 + 0x18);

  lVar6 = *(longlong *)(param_2 + 0x20);

  uVar1 = *(undefined4 *)(lVar5 + 8 + lVar7 * 0xc);

  fVar16 = *(float *)(lVar6 + lVar7 * 0xc);

  fVar13 = *(float *)(lVar5 + lVar7 * 0xc);

  fVar17 = *(float *)(lVar5 + 4 + lVar7 * 0xc);

  local_res8 = *(float *)(lVar6 + 4 + lVar7 * 0xc);

  local_res10 = *(float *)(lVar6 + 8 + lVar7 * 0xc);

  fVar18 = *(float *)(lVar5 + lVar8 * 0xc);

  fVar2 = *(float *)(lVar5 + 4 + lVar8 * 0xc);

  uVar3 = *(undefined4 *)(lVar5 + 8 + lVar8 * 0xc);

  fVar15 = *(float *)(lVar6 + lVar8 * 0xc);

  local_res18 = *(float *)(lVar6 + 4 + lVar8 * 0xc);

  local_res20 = *(float *)(lVar6 + 8 + lVar8 * 0xc);

  fVar9 = (float)FUN_1402cdc50(uVar1);

  fVar10 = (float)FUN_1402cfda0(uVar1);

  fVar11 = (float)FUN_1402cdc50(uVar3);

  fVar12 = (float)FUN_1402cfda0(uVar3);

  fVar19 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xd8);

  fVar14 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xd4);

  fVar20 = fVar14 * fVar10 - fVar19 * fVar9;

  fVar19 = fVar19 * fVar10 + fVar14 * fVar9;

  *(float *)(param_1 + 0xc4) = fVar20;

  *(float *)(param_1 + 200) = fVar19;

  fVar9 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xdc);

  fVar10 = *(float *)(param_1 + 0x9c) - *(float *)(param_1 + 0xe0);

  fVar14 = fVar10 * fVar12 + fVar9 * fVar11;

  fVar9 = fVar9 * fVar12 - fVar10 * fVar11;

  *(float *)(param_1 + 0xd0) = fVar14;

  *(float *)(param_1 + 0xcc) = fVar9;

  fVar11 = (fVar20 + fVar13) - *(float *)(param_1 + 0x80);

  fVar10 = (fVar19 + fVar17) - *(float *)(param_1 + 0x84);

  *(float *)(param_1 + 0xb4) = fVar11;

  *(float *)(param_1 + 0xb8) = fVar10;

  fVar17 = (fVar14 + fVar2) - *(float *)(param_1 + 0x8c);

  fVar18 = (fVar9 + fVar18) - *(float *)(param_1 + 0x88);

  *(float *)(param_1 + 0xc0) = fVar17;

  fVar13 = fVar10 * fVar10 + fVar11 * fVar11;

  if (fVar13 < 0.0) {

    fVar13 = (float)FUN_1402cdfa0(fVar13);

  }

  else {

    fVar13 = SQRT(fVar13);

  }

  fVar17 = fVar17 * fVar17 + fVar18 * fVar18;

  if (fVar17 < 0.0) {

    fVar17 = (float)FUN_1402cdfa0(fVar17);

  }

  else {

    fVar17 = SQRT(fVar17);

  }

  fVar9 = DAT_14039ca44;

  fVar2 = DAT_14039ca18;

  if (fVar13 <= DAT_14039ca18) {

    fVar11 = 0.0;

    fVar10 = 0.0;

  }

  else {

    fVar11 = fVar11 * (DAT_14039ca44 / fVar13);

    fVar10 = fVar10 * (DAT_14039ca44 / fVar13);

  }

  *(float *)(param_1 + 0xb8) = fVar10;

  *(float *)(param_1 + 0xb4) = fVar11;

  if (fVar17 <= fVar2) {

    *(undefined4 *)(param_1 + 0xc0) = 0;

    fVar17 = 0.0;

    fVar18 = 0.0;

  }

  else {

    fVar17 = fVar9 / fVar17;

    fVar18 = fVar18 * fVar17;

    fVar17 = fVar17 * *(float *)(param_1 + 0xc0);

    *(float *)(param_1 + 0xc0) = fVar17;

  }

  *(float *)(param_1 + 0xbc) = fVar18;

  fVar13 = *(float *)(param_1 + 0xbc);

  fVar11 = *(float *)(param_1 + 0xc4) * *(float *)(param_1 + 0xb8) -

           *(float *)(param_1 + 0xb4) * *(float *)(param_1 + 200);

  fVar18 = *(float *)(param_1 + 0xe8);

  fVar2 = *(float *)(param_1 + 0xe4);

  fVar10 = *(float *)(param_1 + 0xa4);

  fVar17 = *(float *)(param_1 + 0xcc) * fVar17 - fVar13 * *(float *)(param_1 + 0xd0);

  fVar17 = (fVar17 * *(float *)(param_1 + 0xf0) * fVar17 + fVar18) * fVar10 * fVar10 +

           fVar11 * *(float *)(param_1 + 0xec) * fVar11 + fVar2;

  *(float *)(param_1 + 0xf4) = fVar17;

  if (0.0 < fVar17) {

    *(float *)(param_1 + 0xf4) = fVar9 / fVar17;

  }

  if (*(char *)(param_2 + 0x14) == '\0') {

    *(undefined4 *)(param_1 + 0xa8) = 0;

  }

  else {

    fVar17 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0xa8);

    fVar10 = (float)((uint)fVar10 ^ DAT_14039cac0) * fVar17;

    fVar9 = (float)((uint)fVar17 ^ DAT_14039cac0);

    fVar11 = *(float *)(param_1 + 0xb4) * fVar9;

    *(float *)(param_1 + 0xa8) = fVar17;

    fVar9 = fVar9 * *(float *)(param_1 + 0xb8);

    fVar13 = fVar13 * fVar10;

    fVar10 = fVar10 * *(float *)(param_1 + 0xc0);

    fVar16 = fVar16 + fVar11 * fVar2;

    local_res8 = local_res8 + fVar9 * fVar2;

    local_res10 = local_res10 +

                  (fVar9 * *(float *)(param_1 + 0xc4) - fVar11 * *(float *)(param_1 + 200)) *

                  *(float *)(param_1 + 0xec);

    fVar15 = fVar15 + fVar13 * fVar18;

    local_res18 = local_res18 + fVar10 * fVar18;

    local_res20 = local_res20 +

                  (fVar10 * *(float *)(param_1 + 0xcc) - fVar13 * *(float *)(param_1 + 0xd0)) *

                  *(float *)(param_1 + 0xf0);

  }

  iVar4 = *(int *)(param_1 + 0xac);

  lVar5 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar5 + (longlong)iVar4 * 0xc) = fVar16;

  *(float *)(lVar5 + 4 + (longlong)iVar4 * 0xc) = local_res8;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xac) * 0xc) =

       local_res10;

  iVar4 = *(int *)(param_1 + 0xb0);

  lVar5 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar5 + (longlong)iVar4 * 0xc) = fVar15;

  *(float *)(lVar5 + 4 + (longlong)iVar4 * 0xc) = local_res18;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xb0) * 0xc) =

       local_res20;

  return;

}




