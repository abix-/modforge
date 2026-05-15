// Address: 0x14001aaa0
// Ghidra name: FUN_14001aaa0
// ============ 0x14001aaa0 FUN_14001aaa0 (size=1438) ============


void FUN_14001aaa0(longlong param_1,float *param_2)



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

  float local_res8;

  float local_res10;

  float local_res18;

  float local_res20;

  

  lVar5 = *(longlong *)(param_1 + 0x68);

  lVar6 = *(longlong *)(param_1 + 0x60);

  lVar7 = (longlong)*(int *)(lVar6 + 8);

  *(int *)(param_1 + 0xa8) = *(int *)(lVar6 + 8);

  lVar8 = (longlong)*(int *)(lVar5 + 8);

  *(int *)(param_1 + 0xac) = *(int *)(lVar5 + 8);

  *(undefined8 *)(param_1 + 200) = *(undefined8 *)(lVar6 + 0x1c);

  *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(lVar5 + 0x1c);

  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(lVar6 + 0x94);

  *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(lVar5 + 0x94);

  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(lVar6 + 0x9c);

  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(lVar5 + 0x9c);

  lVar5 = *(longlong *)(param_2 + 6);

  lVar6 = *(longlong *)(param_2 + 8);

  uVar1 = *(undefined4 *)(lVar5 + 8 + lVar7 * 0xc);

  local_res8 = *(float *)(lVar6 + 4 + lVar7 * 0xc);

  fVar13 = *(float *)(lVar5 + lVar7 * 0xc);

  fVar2 = *(float *)(lVar5 + 4 + lVar7 * 0xc);

  fVar20 = *(float *)(lVar6 + lVar7 * 0xc);

  local_res10 = *(float *)(lVar6 + 8 + lVar7 * 0xc);

  fVar15 = *(float *)(lVar5 + lVar8 * 0xc);

  fVar19 = *(float *)(lVar5 + 4 + lVar8 * 0xc);

  uVar3 = *(undefined4 *)(lVar5 + 8 + lVar8 * 0xc);

  fVar16 = *(float *)(lVar6 + lVar8 * 0xc);

  local_res18 = *(float *)(lVar6 + 4 + lVar8 * 0xc);

  local_res20 = *(float *)(lVar6 + 8 + lVar8 * 0xc);

  fVar9 = (float)FUN_1402cdc50(uVar1);

  fVar10 = (float)FUN_1402cfda0(uVar1);

  fVar11 = (float)FUN_1402cdc50(uVar3);

  fVar12 = (float)FUN_1402cfda0(uVar3);

  fVar18 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xcc);

  fVar14 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 200);

  fVar17 = fVar14 * fVar10 - fVar18 * fVar9;

  fVar10 = fVar18 * fVar10 + fVar14 * fVar9;

  *(float *)(param_1 + 0xb8) = fVar17;

  *(float *)(param_1 + 0xbc) = fVar10;

  fVar9 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xd0);

  fVar18 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xd4);

  fVar14 = fVar9 * fVar12 - fVar18 * fVar11;

  fVar9 = fVar18 * fVar12 + fVar9 * fVar11;

  *(float *)(param_1 + 0xc0) = fVar14;

  *(float *)(param_1 + 0xc4) = fVar9;

  fVar17 = ((fVar14 + fVar15) - fVar13) - fVar17;

  fVar10 = ((fVar9 + fVar19) - fVar2) - fVar10;

  fVar13 = fVar10 * fVar10 + fVar17 * fVar17;

  if (fVar13 < 0.0) {

    fVar13 = (float)FUN_1402cdfa0(fVar13);

  }

  else {

    fVar13 = SQRT(fVar13);

  }

  fVar2 = DAT_14039ca44;

  fVar15 = 0.0;

  if (fVar13 <= DAT_14039ca08) {

    fVar10 = 0.0;

    fVar17 = 0.0;

  }

  else {

    fVar10 = fVar10 * (DAT_14039ca44 / fVar13);

    fVar17 = fVar17 * (DAT_14039ca44 / fVar13);

  }

  *(float *)(param_1 + 0xb0) = fVar17;

  *(float *)(param_1 + 0xb4) = fVar10;

  fVar19 = *(float *)(param_1 + 0xb0);

  fVar9 = *(float *)(param_1 + 0xd8);

  fVar11 = *(float *)(param_1 + 0xdc);

  fVar12 = *(float *)(param_1 + 0xb8) * fVar10 - fVar19 * *(float *)(param_1 + 0xbc);

  fVar10 = *(float *)(param_1 + 0xc0) * fVar10 - fVar19 * *(float *)(param_1 + 0xc4);

  fVar10 = fVar12 * *(float *)(param_1 + 0xe0) * fVar12 + fVar9 + fVar11 +

           fVar10 * *(float *)(param_1 + 0xe4) * fVar10;

  if (fVar10 == 0.0) {

    fVar12 = 0.0;

  }

  else {

    fVar12 = fVar2 / fVar10;

  }

  *(float *)(param_1 + 0xe8) = fVar12;

  if (0.0 < *(float *)(param_1 + 0x80)) {

    fVar17 = *(float *)(param_1 + 0x80) * DAT_14039ca54;

    fVar14 = *param_2;

    fVar18 = fVar12 * fVar17 * fVar17;

    fVar12 = ((fVar12 + fVar12) * *(float *)(param_1 + 0x84) * fVar17 + fVar14 * fVar18) * fVar14;

    if (fVar12 == 0.0) {

      fVar12 = 0.0;

    }

    else {

      fVar12 = fVar2 / fVar12;

    }

    *(float *)(param_1 + 0x9c) = fVar12;

    *(float *)(param_1 + 0x88) = fVar14 * (fVar13 - *(float *)(param_1 + 0xa4)) * fVar18 * fVar12;

    if (fVar12 + fVar10 != 0.0) {

      fVar15 = fVar2 / (fVar12 + fVar10);

    }

    *(float *)(param_1 + 0xe8) = fVar15;

  }

  if (*(char *)(param_2 + 5) == '\0') {

    *(undefined4 *)(param_1 + 0xa0) = 0;

  }

  else {

    fVar13 = param_2[2] * *(float *)(param_1 + 0xa0);

    fVar19 = fVar19 * fVar13;

    *(float *)(param_1 + 0xa0) = fVar13;

    fVar13 = fVar13 * *(float *)(param_1 + 0xb4);

    fVar20 = fVar20 - fVar9 * fVar19;

    local_res8 = local_res8 - fVar13 * fVar9;

    local_res10 = local_res10 -

                  (*(float *)(param_1 + 0xb8) * fVar13 - fVar19 * *(float *)(param_1 + 0xbc)) *

                  *(float *)(param_1 + 0xe0);

    fVar16 = fVar16 + fVar11 * fVar19;

    local_res18 = local_res18 + fVar13 * fVar11;

    local_res20 = local_res20 +

                  (*(float *)(param_1 + 0xc0) * fVar13 - fVar19 * *(float *)(param_1 + 0xc4)) *

                  *(float *)(param_1 + 0xe4);

  }

  iVar4 = *(int *)(param_1 + 0xa8);

  lVar5 = *(longlong *)(param_2 + 8);

  *(float *)(lVar5 + (longlong)iVar4 * 0xc) = fVar20;

  *(float *)(lVar5 + 4 + (longlong)iVar4 * 0xc) = local_res8;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xa8) * 0xc) =

       local_res10;

  iVar4 = *(int *)(param_1 + 0xac);

  lVar5 = *(longlong *)(param_2 + 8);

  *(float *)(lVar5 + (longlong)iVar4 * 0xc) = fVar16;

  *(float *)(lVar5 + 4 + (longlong)iVar4 * 0xc) = local_res18;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xac) * 0xc) =

       local_res20;

  return;

}




