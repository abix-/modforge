// Address: 0x14000a0a0
// Ghidra name: FUN_14000a0a0
// ============ 0x14000a0a0 FUN_14000a0a0 (size=1515) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14000a0a0(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

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

  *(int *)(param_1 + 0xbc) = *(int *)(lVar6 + 8);

  lVar8 = (longlong)*(int *)(lVar5 + 8);

  *(int *)(param_1 + 0xc0) = *(int *)(lVar5 + 8);

  *(undefined8 *)(param_1 + 0xd4) = *(undefined8 *)(lVar6 + 0x1c);

  *(undefined8 *)(param_1 + 0xdc) = *(undefined8 *)(lVar5 + 0x1c);

  fVar17 = *(float *)(lVar6 + 0x94);

  *(float *)(param_1 + 0xe4) = fVar17;

  fVar1 = *(float *)(lVar5 + 0x94);

  *(float *)(param_1 + 0xe8) = fVar1;

  fVar2 = *(float *)(lVar6 + 0x9c);

  *(float *)(param_1 + 0xec) = fVar2;

  fVar3 = *(float *)(lVar5 + 0x9c);

  *(float *)(param_1 + 0xf0) = fVar3;

  lVar5 = *(longlong *)(param_2 + 0x20);

  local_res8 = *(float *)(lVar5 + 4 + lVar7 * 0xc);

  fVar18 = *(float *)(*(longlong *)(param_2 + 0x18) + 8 + lVar7 * 0xc);

  fVar20 = *(float *)(lVar5 + lVar7 * 0xc);

  local_res10 = *(float *)(lVar5 + 8 + lVar7 * 0xc);

  fVar13 = *(float *)(*(longlong *)(param_2 + 0x18) + 8 + lVar8 * 0xc);

  fVar14 = *(float *)(lVar5 + lVar8 * 0xc);

  local_res18 = *(float *)(lVar5 + 4 + lVar8 * 0xc);

  local_res20 = *(float *)(lVar5 + 8 + lVar8 * 0xc);

  fVar9 = (float)FUN_1402cdc50(fVar18);

  fVar10 = (float)FUN_1402cfda0(fVar18);

  fVar11 = (float)FUN_1402cdc50(fVar13);

  fVar12 = (float)FUN_1402cfda0(fVar13);

  fVar16 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xd4);

  fVar15 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xd8);

  fVar19 = fVar16 * fVar10 - fVar15 * fVar9;

  *(float *)(param_1 + 0xc4) = fVar19;

  *(float *)(param_1 + 200) = fVar15 * fVar10 + fVar16 * fVar9;

  fVar10 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xdc);

  fVar9 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xe0);

  fVar15 = fVar3 + fVar2;

  fVar16 = fVar10 * fVar12 - fVar9 * fVar11;

  fVar10 = fVar9 * fVar12 + fVar10 * fVar11;

  *(float *)(param_1 + 0xcc) = fVar16;

  *(float *)(param_1 + 0xd0) = fVar10;

  fVar9 = *(float *)(param_1 + 200);

  *(float *)(param_1 + 0x114) = fVar15;

  fVar11 = (float)((uint)fVar9 ^ DAT_14039cac0);

  *(float *)(param_1 + 0x118) = fVar15;

  *(float *)(param_1 + 0xf4) = fVar9 * fVar9 * fVar2 + fVar17 + fVar1 + fVar10 * fVar10 * fVar3;

  fVar9 = fVar11 * fVar19 * fVar2 - fVar16 * fVar10 * fVar3;

  *(float *)(param_1 + 0x100) = fVar9;

  fVar10 = fVar11 * fVar2 - fVar3 * fVar10;

  *(float *)(param_1 + 0xf8) = fVar9;

  *(float *)(param_1 + 0x10c) = fVar10;

  *(float *)(param_1 + 0xfc) = fVar10;

  *(float *)(param_1 + 0x104) = fVar19 * fVar19 * fVar2 + fVar17 + fVar1 + fVar16 * fVar16 * fVar3;

  fVar9 = fVar3 * fVar16 + fVar2 * fVar19;

  *(float *)(param_1 + 0x110) = fVar9;

  *(float *)(param_1 + 0x108) = fVar9;

  if (0.0 < fVar15) {

    *(float *)(param_1 + 0x118) = DAT_14039ca44 / fVar15;

  }

  if ((*(char *)(param_1 + 0xa0) == '\0') || (fVar15 == 0.0)) {

    *(undefined4 *)(param_1 + 0x9c) = 0;

  }

  if ((*(char *)(param_1 + 0xac) != '\0') && (fVar15 != 0.0)) {

    fVar18 = (fVar13 - fVar18) - *(float *)(param_1 + 0xb0);

    if ((float)((uint)(*(float *)(param_1 + 0xb8) - *(float *)(param_1 + 0xb4)) & _DAT_14039cab0) <

        DAT_14039ca1c) {

      *(undefined4 *)(param_1 + 0x11c) = 3;

      goto LAB_14000a48c;

    }

    if (fVar18 <= *(float *)(param_1 + 0xb4)) {

      if (*(int *)(param_1 + 0x11c) != 1) {

        *(undefined4 *)(param_1 + 0x98) = 0;

      }

      *(undefined4 *)(param_1 + 0x11c) = 1;

      goto LAB_14000a48c;

    }

    if (*(float *)(param_1 + 0xb8) <= fVar18) {

      if (*(int *)(param_1 + 0x11c) != 2) {

        *(undefined4 *)(param_1 + 0x98) = 0;

      }

      *(undefined4 *)(param_1 + 0x11c) = 2;

      goto LAB_14000a48c;

    }

    *(undefined4 *)(param_1 + 0x98) = 0;

  }

  *(undefined4 *)(param_1 + 0x11c) = 0;

LAB_14000a48c:

  if (*(char *)(param_2 + 0x14) == '\0') {

    *(undefined8 *)(param_1 + 0x90) = 0;

    *(undefined8 *)(param_1 + 0x98) = 0;

  }

  else {

    fVar18 = *(float *)(param_2 + 8);

    fVar13 = fVar18 * *(float *)(param_1 + 0x90);

    fVar9 = fVar18 * *(float *)(param_1 + 0x94);

    fVar18 = fVar18 * *(float *)(param_1 + 0x98);

    *(float *)(param_1 + 0x90) = fVar13;

    *(float *)(param_1 + 0x94) = fVar9;

    fVar20 = fVar20 - fVar17 * fVar13;

    local_res8 = local_res8 - fVar17 * fVar9;

    *(float *)(param_1 + 0x98) = fVar18;

    fVar17 = *(float *)(param_1 + 0x9c) * *(float *)(param_2 + 8);

    *(float *)(param_1 + 0x9c) = fVar17;

    local_res10 = local_res10 -

                  ((fVar9 * fVar19 - fVar13 * *(float *)(param_1 + 200)) + fVar17 + fVar18) * fVar2;

    fVar14 = fVar14 + fVar1 * fVar13;

    local_res18 = local_res18 + fVar1 * fVar9;

    local_res20 = local_res20 +

                  ((fVar9 * fVar16 - fVar13 * *(float *)(param_1 + 0xd0)) + fVar17 + fVar18) * fVar3

    ;

  }

  iVar4 = *(int *)(param_1 + 0xbc);

  lVar5 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar5 + (longlong)iVar4 * 0xc) = fVar20;

  *(float *)(lVar5 + 4 + (longlong)iVar4 * 0xc) = local_res8;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xbc) * 0xc) =

       local_res10;

  iVar4 = *(int *)(param_1 + 0xc0);

  lVar5 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar5 + (longlong)iVar4 * 0xc) = fVar14;

  *(float *)(lVar5 + 4 + (longlong)iVar4 * 0xc) = local_res18;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xc0) * 0xc) =

       local_res20;

  return;

}




