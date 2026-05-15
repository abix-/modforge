// Address: 0x14001e5e0
// Ghidra name: FUN_14001e5e0
// ============ 0x14001e5e0 FUN_14001e5e0 (size=1229) ============


undefined4 * FUN_14001e5e0(undefined4 *param_1,undefined4 *param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  undefined4 uVar6;

  undefined8 uVar7;

  float *pfVar8;

  float *pfVar9;

  float *pfVar10;

  char *pcVar11;

  longlong lVar12;

  longlong lVar13;

  undefined8 *puVar14;

  longlong lVar15;

  longlong lVar16;

  longlong lVar17;

  float fVar18;

  int local_res8;

  longlong local_res10;

  longlong local_res18;

  longlong local_res20;

  

  uVar1 = param_2[1];

  uVar2 = param_2[2];

  uVar6 = param_2[3];

  *param_1 = *param_2;

  param_1[1] = uVar1;

  param_1[2] = uVar2;

  param_1[3] = uVar6;

  *(undefined8 *)(param_1 + 4) = *(undefined8 *)(param_2 + 4);

  uVar7 = *(undefined8 *)(param_2 + 0xe);

  *(undefined8 *)(param_1 + 10) = uVar7;

  iVar3 = param_2[8];

  param_1[0x12] = iVar3;

  uVar7 = FUN_1400128b0(uVar7,iVar3 * 0x58);

  *(undefined8 *)(param_1 + 0xc) = uVar7;

  uVar7 = FUN_1400128b0(*(undefined8 *)(param_1 + 10),param_1[0x12] * 0x98);

  *(undefined8 *)(param_1 + 0xe) = uVar7;

  *(undefined8 *)(param_1 + 6) = *(undefined8 *)(param_2 + 10);

  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 0xc);

  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_2 + 6);

  local_res8 = 0;

  if (0 < (int)param_1[0x12]) {

    local_res10 = 0;

    local_res20 = 0;

    local_res18 = 0;

    do {

      pcVar11 = (char *)(param_1 + 5);

      lVar4 = *(longlong *)(local_res10 + *(longlong *)(param_1 + 0x10));

      iVar3 = *(int *)(lVar4 + 0xb4);

      lVar13 = (longlong)iVar3;

      lVar15 = *(longlong *)(*(longlong *)(lVar4 + 0x60) + 0x10);

      lVar5 = *(longlong *)(*(longlong *)(lVar4 + 0x68) + 0x10);

      uVar1 = *(undefined4 *)(*(longlong *)(*(longlong *)(lVar4 + 0x60) + 0x18) + 0xc);

      uVar2 = *(undefined4 *)(*(longlong *)(*(longlong *)(lVar4 + 0x68) + 0x18) + 0xc);

      if (iVar3 < 1) {

        FID_conflict__assert

                  (L"pointCount > 0",

                   L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Contacts\\b2ContactSolver.cpp",0x47);

      }

      lVar17 = local_res18 + *(longlong *)(param_1 + 0xe);

      *(undefined4 *)(lVar17 + 0x88) = *(undefined4 *)(lVar4 + 0xc0);

      *(undefined4 *)(lVar17 + 0x8c) = *(undefined4 *)(lVar4 + 0xc4);

      *(undefined4 *)(lVar17 + 0x70) = *(undefined4 *)(lVar15 + 8);

      *(undefined4 *)(lVar17 + 0x74) = *(undefined4 *)(lVar5 + 8);

      *(undefined4 *)(lVar17 + 0x78) = *(undefined4 *)(lVar15 + 0x94);

      *(undefined4 *)(lVar17 + 0x7c) = *(undefined4 *)(lVar5 + 0x94);

      *(undefined4 *)(lVar17 + 0x80) = *(undefined4 *)(lVar15 + 0x9c);

      *(undefined4 *)(lVar17 + 0x84) = *(undefined4 *)(lVar5 + 0x9c);

      *(undefined8 *)(lVar17 + 0x60) = 0;

      *(undefined8 *)(lVar17 + 0x68) = 0;

      *(undefined8 *)(lVar17 + 0x50) = 0;

      *(undefined8 *)(lVar17 + 0x58) = 0;

      *(int *)(lVar17 + 0x94) = local_res8;

      *(int *)(lVar17 + 0x90) = iVar3;

      lVar16 = local_res20 + *(longlong *)(param_1 + 0xc);

      *(undefined4 *)(lVar16 + 0x20) = *(undefined4 *)(lVar15 + 8);

      puVar14 = (undefined8 *)(lVar16 + 0x10);

      *(undefined4 *)(lVar16 + 0x24) = *(undefined4 *)(lVar5 + 8);

      *(undefined4 *)(lVar16 + 0x28) = *(undefined4 *)(lVar15 + 0x94);

      *(undefined4 *)(lVar16 + 0x2c) = *(undefined4 *)(lVar5 + 0x94);

      *(undefined8 *)(lVar16 + 0x30) = *(undefined8 *)(lVar15 + 0x1c);

      *(undefined8 *)(lVar16 + 0x38) = *(undefined8 *)(lVar5 + 0x1c);

      lVar12 = 0;

      *(undefined4 *)(lVar16 + 0x40) = *(undefined4 *)(lVar15 + 0x9c);

      *(undefined4 *)(lVar16 + 0x44) = *(undefined4 *)(lVar5 + 0x9c);

      *puVar14 = *(undefined8 *)(lVar4 + 0xa0);

      *(undefined8 *)(lVar16 + 0x18) = *(undefined8 *)(lVar4 + 0xa8);

      *(undefined4 *)(lVar16 + 0x4c) = uVar1;

      *(undefined4 *)(lVar16 + 0x50) = uVar2;

      *(int *)(lVar16 + 0x54) = iVar3;

      *(undefined4 *)(lVar16 + 0x48) = *(undefined4 *)(lVar4 + 0xb0);

      if (3 < lVar13) {

        pfVar9 = (float *)(lVar4 + 0x98);

        lVar15 = (lVar13 - 4U >> 2) + 1;

        pfVar8 = (float *)(lVar17 + 0x34);

        lVar12 = lVar15 * 4;

        do {

          pfVar10 = (float *)(param_1 + 2);

          if (*pcVar11 == '\0') {

            pfVar8[-9] = 0.0;

            fVar18 = 0.0;

          }

          else {

            pfVar8[-9] = pfVar9[-6] * *pfVar10;

            fVar18 = pfVar9[-5] * *pfVar10;

          }

          pfVar8[-8] = fVar18;

          pfVar8[-0xd] = 0.0;

          pfVar8[-0xc] = 0.0;

          pfVar8[-0xb] = 0.0;

          pfVar8[-10] = 0.0;

          pfVar8[-7] = 0.0;

          pfVar8[-6] = 0.0;

          pfVar8[-5] = 0.0;

          puVar14[-2] = *(undefined8 *)(pfVar9 + -8);

          if (*pcVar11 == '\0') {

            *pfVar8 = 0.0;

            fVar18 = 0.0;

          }

          else {

            *pfVar8 = pfVar9[-1] * *pfVar10;

            fVar18 = *pfVar10 * *pfVar9;

          }

          pfVar8[1] = fVar18;

          pfVar8[-4] = 0.0;

          pfVar8[-3] = 0.0;

          pfVar8[-2] = 0.0;

          pfVar8[-1] = 0.0;

          pfVar8[2] = 0.0;

          pfVar8[3] = 0.0;

          pfVar8[4] = 0.0;

          puVar14[-1] = *(undefined8 *)(pfVar9 + -3);

          if (*pcVar11 == '\0') {

            pfVar8[9] = 0.0;

            fVar18 = 0.0;

          }

          else {

            pfVar8[9] = pfVar9[4] * *pfVar10;

            fVar18 = pfVar9[5] * *pfVar10;

          }

          pfVar8[10] = fVar18;

          pfVar8[5] = 0.0;

          pfVar8[6] = 0.0;

          pfVar8[7] = 0.0;

          pfVar8[8] = 0.0;

          pfVar8[0xb] = 0.0;

          pfVar8[0xc] = 0.0;

          pfVar8[0xd] = 0.0;

          *puVar14 = *(undefined8 *)(pfVar9 + 2);

          if (*pcVar11 == '\0') {

            pfVar8[0x12] = 0.0;

            fVar18 = 0.0;

          }

          else {

            pfVar8[0x12] = pfVar9[9] * (float)param_1[2];

            fVar18 = pfVar9[10] * (float)param_1[2];

          }

          pfVar8[0x13] = fVar18;

          pfVar8[0xe] = 0.0;

          pfVar8[0xf] = 0.0;

          pfVar8[0x10] = 0.0;

          pfVar8[0x11] = 0.0;

          pfVar8[0x14] = 0.0;

          pfVar8[0x15] = 0.0;

          pfVar8[0x16] = 0.0;

          pfVar8 = pfVar8 + 0x24;

          pfVar10 = pfVar9 + 7;

          pfVar9 = pfVar9 + 0x14;

          puVar14[1] = *(undefined8 *)pfVar10;

          puVar14 = puVar14 + 4;

          lVar15 = lVar15 + -1;

        } while (lVar15 != 0);

      }

      if (lVar12 < lVar13) {

        puVar14 = (undefined8 *)(lVar16 + lVar12 * 8);

        pfVar8 = (float *)(lVar4 + (lVar12 * 5 + 0x21) * 4);

        pfVar9 = (float *)(lVar12 * 0x24 + 0x10 + lVar17);

        lVar13 = lVar13 - lVar12;

        do {

          if (*(char *)(param_1 + 5) == '\0') {

            *pfVar9 = 0.0;

            fVar18 = 0.0;

          }

          else {

            *pfVar9 = pfVar8[-1] * (float)param_1[2];

            fVar18 = (float)param_1[2] * *pfVar8;

          }

          pfVar9[1] = fVar18;

          pfVar9[-4] = 0.0;

          pfVar9[-3] = 0.0;

          pfVar9[-2] = 0.0;

          pfVar9[-1] = 0.0;

          pfVar9[2] = 0.0;

          pfVar9[3] = 0.0;

          pfVar9[4] = 0.0;

          pfVar9 = pfVar9 + 9;

          pfVar10 = pfVar8 + -3;

          pfVar8 = pfVar8 + 5;

          *puVar14 = *(undefined8 *)pfVar10;

          puVar14 = puVar14 + 1;

          lVar13 = lVar13 + -1;

        } while (lVar13 != 0);

      }

      local_res8 = local_res8 + 1;

      local_res10 = local_res10 + 8;

      local_res18 = local_res18 + 0x98;

      local_res20 = local_res20 + 0x58;

    } while (local_res8 < (int)param_1[0x12]);

  }

  return param_1;

}




