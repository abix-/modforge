// Address: 0x14000b4a0
// Ghidra name: FUN_14000b4a0
// ============ 0x14000b4a0 FUN_14000b4a0 (size=1273) ============


void FUN_14000b4a0(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  undefined4 uVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  undefined4 uVar7;

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

  float fVar21;

  float local_res8;

  float local_res10;

  float local_res18;

  

  lVar5 = *(longlong *)(param_1 + 0x68);

  lVar6 = *(longlong *)(param_1 + 0x60);

  lVar8 = (longlong)*(int *)(lVar6 + 8);

  *(int *)(param_1 + 0x9c) = *(int *)(lVar6 + 8);

  lVar9 = (longlong)*(int *)(lVar5 + 8);

  *(int *)(param_1 + 0xa0) = *(int *)(lVar5 + 8);

  *(undefined8 *)(param_1 + 0xbc) = *(undefined8 *)(lVar6 + 0x1c);

  *(undefined8 *)(param_1 + 0xc4) = *(undefined8 *)(lVar5 + 0x1c);

  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(lVar6 + 0x94);

  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(lVar5 + 0x94);

  *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(lVar6 + 0x9c);

  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(lVar5 + 0x9c);

  lVar5 = *(longlong *)(param_2 + 0x18);

  lVar6 = *(longlong *)(param_2 + 0x20);

  uVar7 = *(undefined4 *)(lVar5 + 8 + lVar8 * 0xc);

  local_res8 = *(float *)(lVar6 + 8 + lVar8 * 0xc);

  fVar20 = *(float *)(lVar6 + lVar8 * 0xc);

  fVar21 = *(float *)(lVar6 + 4 + lVar8 * 0xc);

  fVar18 = *(float *)(lVar5 + lVar8 * 0xc);

  fVar19 = *(float *)(lVar5 + 4 + lVar8 * 0xc);

  fVar1 = *(float *)(lVar5 + lVar9 * 0xc);

  fVar2 = *(float *)(lVar5 + 4 + lVar9 * 0xc);

  uVar3 = *(undefined4 *)(lVar5 + 8 + lVar9 * 0xc);

  fVar16 = *(float *)(lVar6 + lVar9 * 0xc);

  local_res10 = *(float *)(lVar6 + 4 + lVar9 * 0xc);

  local_res18 = *(float *)(lVar6 + 8 + lVar9 * 0xc);

  fVar10 = (float)FUN_1402cdc50(uVar7);

  fVar11 = (float)FUN_1402cfda0(uVar7);

  fVar12 = (float)FUN_1402cdc50(uVar3);

  fVar13 = (float)FUN_1402cfda0(uVar3);

  fVar14 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xc0);

  fVar15 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xbc);

  fVar17 = fVar11 * fVar15 - fVar10 * fVar14;

  fVar15 = fVar11 * fVar14 + fVar10 * fVar15;

  *(float *)(param_1 + 0xac) = fVar17;

  *(float *)(param_1 + 0xb0) = fVar15;

  fVar11 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xc4);

  fVar10 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 200);

  fVar14 = fVar13 * fVar11 - fVar12 * fVar10;

  fVar10 = fVar13 * fVar10 + fVar12 * fVar11;

  *(float *)(param_1 + 0xb4) = fVar14;

  *(float *)(param_1 + 0xb8) = fVar10;

  fVar17 = ((fVar14 + fVar1) - fVar18) - fVar17;

  fVar18 = ((fVar10 + fVar2) - fVar19) - fVar15;

  *(float *)(param_1 + 0xa8) = fVar18;

  fVar18 = fVar18 * fVar18 + fVar17 * fVar17;

  if (fVar18 < 0.0) {

    fVar18 = (float)FUN_1402cdfa0(fVar18);

  }

  else {

    fVar18 = SQRT(fVar18);

  }

  *(float *)(param_1 + 0x94) = fVar18;

  fVar19 = 0.0;

  uVar7 = 0;

  if (0.0 < fVar18 - *(float *)(param_1 + 0x90)) {

    uVar7 = 2;

  }

  *(undefined4 *)(param_1 + 0xe0) = uVar7;

  fVar1 = DAT_14039ca44;

  if (fVar18 <= DAT_14039ca08) {

    *(undefined8 *)(param_1 + 0xa4) = 0;

    *(undefined4 *)(param_1 + 0xdc) = 0;

    *(undefined4 *)(param_1 + 0x98) = 0;

  }

  else {

    fVar17 = fVar17 * (DAT_14039ca44 / fVar18);

    fVar11 = (DAT_14039ca44 / fVar18) * *(float *)(param_1 + 0xa8);

    *(float *)(param_1 + 0xa4) = fVar17;

    *(float *)(param_1 + 0xa8) = fVar11;

    fVar18 = *(float *)(param_1 + 0xcc);

    fVar2 = *(float *)(param_1 + 0xd0);

    fVar10 = fVar11 * *(float *)(param_1 + 0xac) - fVar17 * fVar15;

    fVar11 = fVar11 * *(float *)(param_1 + 0xb4) - fVar17 * *(float *)(param_1 + 0xb8);

    fVar10 = fVar10 * *(float *)(param_1 + 0xd4) * fVar10 + fVar18 + fVar2 +

             fVar11 * *(float *)(param_1 + 0xd8) * fVar11;

    if (fVar10 != 0.0) {

      fVar19 = fVar1 / fVar10;

    }

    *(float *)(param_1 + 0xdc) = fVar19;

    if (*(char *)(param_2 + 0x14) == '\0') {

      *(undefined4 *)(param_1 + 0x98) = 0;

    }

    else {

      fVar19 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x98);

      fVar17 = fVar17 * fVar19;

      *(float *)(param_1 + 0x98) = fVar19;

      fVar19 = fVar19 * *(float *)(param_1 + 0xa8);

      fVar20 = fVar20 - fVar17 * fVar18;

      fVar21 = fVar21 - fVar19 * fVar18;

      local_res8 = local_res8 -

                   (*(float *)(param_1 + 0xac) * fVar19 - fVar17 * *(float *)(param_1 + 0xb0)) *

                   *(float *)(param_1 + 0xd4);

      fVar16 = fVar16 + fVar17 * fVar2;

      local_res10 = local_res10 + fVar19 * fVar2;

      local_res18 = local_res18 +

                    (*(float *)(param_1 + 0xb4) * fVar19 - fVar17 * *(float *)(param_1 + 0xb8)) *

                    *(float *)(param_1 + 0xd8);

    }

    iVar4 = *(int *)(param_1 + 0x9c);

    lVar5 = *(longlong *)(param_2 + 0x20);

    *(float *)(lVar5 + (longlong)iVar4 * 0xc) = fVar20;

    *(float *)(lVar5 + 4 + (longlong)iVar4 * 0xc) = fVar21;

    *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0x9c) * 0xc) =

         local_res8;

    iVar4 = *(int *)(param_1 + 0xa0);

    lVar5 = *(longlong *)(param_2 + 0x20);

    *(float *)(lVar5 + (longlong)iVar4 * 0xc) = fVar16;

    *(float *)(lVar5 + 4 + (longlong)iVar4 * 0xc) = local_res10;

    *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xa0) * 0xc) =

         local_res18;

  }

  return;

}




